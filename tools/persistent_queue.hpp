#ifndef TOOLS_PERSISTENT_QUEUE_HPP
#define TOOLS_PERSISTENT_QUEUE_HPP

#include <algorithm>
#include <cassert>
#include <cstddef>
#include <functional>
#include <iterator>
#include <limits>
#include <memory>
#include <utility>
#include <vector>

namespace tools {
  template <typename T>
  class persistent_queue {
    struct value_node {
      T value;
      int next;
      int refcnt;
    };

    struct thunk_node {
      int rot_f;
      int rot_r;
      int rot_a;
      T value;
      int next;
      bool forced;
      int refcnt;
    };

    static inline std::vector<value_node> s_value_nodes;
    static inline std::vector<int> s_free_value_ids;
    static inline std::vector<thunk_node> s_thunk_nodes;
    static inline std::vector<int> s_free_thunk_ids;

    static constexpr int EMPTY = std::numeric_limits<int>::min();

    static int malloc_value() {
      if (s_free_value_ids.empty()) {
        s_value_nodes.emplace_back();
        return s_value_nodes.size() - 1;
      } else {
        const auto id = s_free_value_ids.back();
        s_free_value_ids.pop_back();
        return id;
      }
    }
    static void free_value(const int id) {
      assert(0 <= id && id < std::ssize(s_value_nodes));
      assert(s_value_nodes[id].refcnt == 0);
      s_free_value_ids.push_back(id);
    }
    static int malloc_thunk() {
      if (s_free_thunk_ids.empty()) {
        s_thunk_nodes.emplace_back();
        return s_thunk_nodes.size() - 1;
      } else {
        const auto id = s_free_thunk_ids.back();
        s_free_thunk_ids.pop_back();
        return id;
      }
    }
    static void free_thunk(const int id) {
      assert(0 <= id && id < std::ssize(s_thunk_nodes));
      assert(s_thunk_nodes[id].refcnt == 0);
      s_free_thunk_ids.push_back(id);
    }

    static void increment_refcnt(const int id) {
      if (id == EMPTY) return;
      if (id >= 0) {
        ++s_value_nodes[id].refcnt;
      } else {
        ++s_thunk_nodes[~id].refcnt;
      }
    }

    static const T& node_value(const int id) {
      assert(id != EMPTY);
      if (id >= 0) {
        return s_value_nodes[id].value;
      } else {
        assert(s_thunk_nodes[~id].forced);
        return s_thunk_nodes[~id].value;
      }
    }

    static int node_next(const int id) {
      assert(id != EMPTY);
      if (id >= 0) {
        return s_value_nodes[id].next;
      } else {
        assert(s_thunk_nodes[~id].forced);
        return s_thunk_nodes[~id].next;
      }
    }

    static void force(const int id) {
      if (id == EMPTY || id >= 0) return;
      const int ti = ~id;
      if (s_thunk_nodes[ti].forced) return;

      force(s_thunk_nodes[ti].rot_f);

      if (s_thunk_nodes[ti].rot_f != EMPTY) {
        // Recursive case: rotate(x:f, y:r, a) = Cons(x, rotate(tail(f), tail(r), Cons(y, a)))
        const T head_f = node_value(s_thunk_nodes[ti].rot_f);
        const T head_r = node_value(s_thunk_nodes[ti].rot_r);
        const int tail_f = node_next(s_thunk_nodes[ti].rot_f);
        const int tail_r = node_next(s_thunk_nodes[ti].rot_r);
        const int rot_a = s_thunk_nodes[ti].rot_a;

        const int new_a = malloc_value();
        s_value_nodes[new_a].value = head_r;
        s_value_nodes[new_a].next = rot_a;
        increment_refcnt(rot_a);
        s_value_nodes[new_a].refcnt = 0;

        const int new_thunk = malloc_thunk();
        s_thunk_nodes[new_thunk].rot_f = tail_f;
        increment_refcnt(tail_f);
        s_thunk_nodes[new_thunk].rot_r = tail_r;
        increment_refcnt(tail_r);
        s_thunk_nodes[new_thunk].rot_a = new_a;
        increment_refcnt(new_a);
        s_thunk_nodes[new_thunk].forced = false;
        s_thunk_nodes[new_thunk].refcnt = 0;

        s_thunk_nodes[ti].value = head_f;
        s_thunk_nodes[ti].next = ~new_thunk;
        increment_refcnt(s_thunk_nodes[ti].next);
      } else {
        // Base case: rotate([], [y], a) = Cons(y, a)
        s_thunk_nodes[ti].value = node_value(s_thunk_nodes[ti].rot_r);
        s_thunk_nodes[ti].next = s_thunk_nodes[ti].rot_a;
        increment_refcnt(s_thunk_nodes[ti].rot_a);
      }

      s_thunk_nodes[ti].forced = true;
    }

    static void release(int id) {
      while (id != EMPTY) {
        if (id >= 0) {
          assert(s_value_nodes[id].refcnt > 0);
          --s_value_nodes[id].refcnt;
          if (s_value_nodes[id].refcnt > 0) break;
          const int next = s_value_nodes[id].next;
          free_value(id);
          id = next;
        } else {
          const int ti = ~id;
          assert(s_thunk_nodes[ti].refcnt > 0);
          --s_thunk_nodes[ti].refcnt;
          if (s_thunk_nodes[ti].refcnt > 0) break;
          if (s_thunk_nodes[ti].forced) {
            release(s_thunk_nodes[ti].rot_f);
            release(s_thunk_nodes[ti].rot_r);
            release(s_thunk_nodes[ti].rot_a);
            const int next = s_thunk_nodes[ti].next;
            free_thunk(ti);
            id = next;
          } else {
            release(s_thunk_nodes[ti].rot_f);
            release(s_thunk_nodes[ti].rot_r);
            const int rot_a = s_thunk_nodes[ti].rot_a;
            free_thunk(ti);
            id = rot_a;
          }
        }
      }
    }

    int m_front;
    int m_rear;
    int m_schedule;
    int m_back;
    int m_size;

    void wipe() const {
      release(this->m_front);
      release(this->m_rear);
      release(this->m_schedule);
      release(this->m_back);
    }

  public:
    // For testing purposes.
    static bool fully_released() {
      std::vector<bool> released_value(s_value_nodes.size(), false);
      for (const auto id : s_free_value_ids) {
        assert(!released_value[id]);
        released_value[id] = true;
      }
      std::vector<bool> released_thunk(s_thunk_nodes.size(), false);
      for (const auto id : s_free_thunk_ids) {
        assert(!released_thunk[id]);
        released_thunk[id] = true;
      }
      return std::ranges::all_of(released_value, std::identity{}) && std::ranges::all_of(released_thunk, std::identity{});
    }

    persistent_queue() : m_front(EMPTY), m_rear(EMPTY), m_schedule(EMPTY), m_back(EMPTY), m_size(0) {
    }
    persistent_queue(const tools::persistent_queue<T>& other)
      : m_front(other.m_front), m_rear(other.m_rear), m_schedule(other.m_schedule),
        m_back(other.m_back), m_size(other.m_size) {
      increment_refcnt(this->m_front);
      increment_refcnt(this->m_rear);
      increment_refcnt(this->m_schedule);
      increment_refcnt(this->m_back);
    }
    persistent_queue(tools::persistent_queue<T>&& other) noexcept
      : m_front(other.m_front), m_rear(other.m_rear), m_schedule(other.m_schedule),
        m_back(other.m_back), m_size(other.m_size) {
      other.m_front = EMPTY;
      other.m_rear = EMPTY;
      other.m_schedule = EMPTY;
      other.m_back = EMPTY;
      other.m_size = 0;
    }
    ~persistent_queue() {
      this->wipe();
    }
    tools::persistent_queue<T>& operator=(const tools::persistent_queue<T>& other) {
      if (this != std::addressof(other)) {
        this->wipe();
        this->m_front = other.m_front;
        this->m_rear = other.m_rear;
        this->m_schedule = other.m_schedule;
        this->m_back = other.m_back;
        this->m_size = other.m_size;
        increment_refcnt(this->m_front);
        increment_refcnt(this->m_rear);
        increment_refcnt(this->m_schedule);
        increment_refcnt(this->m_back);
      }
      return *this;
    }
    tools::persistent_queue<T>& operator=(tools::persistent_queue<T>&& other) noexcept {
      if (this != std::addressof(other)) {
        this->wipe();
        this->m_front = other.m_front;
        this->m_rear = other.m_rear;
        this->m_schedule = other.m_schedule;
        this->m_back = other.m_back;
        this->m_size = other.m_size;
        other.m_front = EMPTY;
        other.m_rear = EMPTY;
        other.m_schedule = EMPTY;
        other.m_back = EMPTY;
        other.m_size = 0;
      }
      return *this;
    }

    bool empty() const {
      return this->m_size == 0;
    }

    std::size_t size() const {
      return this->m_size;
    }

    const T& front() const {
      assert(!this->empty());
      force(this->m_front);
      return node_value(this->m_front);
    }

    const T& back() const {
      assert(!this->empty());
      return s_value_nodes[this->m_back].value;
    }

    tools::persistent_queue<T> push(const T& x) const {
      const int new_rear = malloc_value();
      s_value_nodes[new_rear].value = x;
      s_value_nodes[new_rear].next = this->m_rear;
      increment_refcnt(this->m_rear);
      s_value_nodes[new_rear].refcnt = 0;

      tools::persistent_queue<T> res{};
      res.m_size = this->m_size + 1;
      res.m_back = new_rear;
      increment_refcnt(new_rear);

      if (this->m_schedule != EMPTY) {
        force(this->m_schedule);
        res.m_front = this->m_front;
        increment_refcnt(res.m_front);
        res.m_rear = new_rear;
        increment_refcnt(new_rear);
        res.m_schedule = node_next(this->m_schedule);
        increment_refcnt(res.m_schedule);
      } else {
        const int thunk_id = malloc_thunk();
        s_thunk_nodes[thunk_id].rot_f = this->m_front;
        increment_refcnt(this->m_front);
        s_thunk_nodes[thunk_id].rot_r = new_rear;
        increment_refcnt(new_rear);
        s_thunk_nodes[thunk_id].rot_a = EMPTY;
        s_thunk_nodes[thunk_id].forced = false;
        s_thunk_nodes[thunk_id].refcnt = 0;

        res.m_front = ~thunk_id;
        increment_refcnt(res.m_front);
        res.m_rear = EMPTY;
        res.m_schedule = res.m_front;
        increment_refcnt(res.m_schedule);
      }

      return res;
    }

    tools::persistent_queue<T> pop() const {
      assert(!this->empty());
      force(this->m_front);

      tools::persistent_queue<T> res{};
      res.m_size = this->m_size - 1;

      if (res.m_size == 0) {
        return res;
      }

      res.m_back = this->m_back;
      increment_refcnt(res.m_back);

      const int new_front = node_next(this->m_front);

      if (this->m_schedule != EMPTY) {
        force(this->m_schedule);
        res.m_front = new_front;
        increment_refcnt(res.m_front);
        res.m_rear = this->m_rear;
        increment_refcnt(res.m_rear);
        res.m_schedule = node_next(this->m_schedule);
        increment_refcnt(res.m_schedule);
      } else {
        const int thunk_id = malloc_thunk();
        s_thunk_nodes[thunk_id].rot_f = new_front;
        increment_refcnt(new_front);
        s_thunk_nodes[thunk_id].rot_r = this->m_rear;
        increment_refcnt(this->m_rear);
        s_thunk_nodes[thunk_id].rot_a = EMPTY;
        s_thunk_nodes[thunk_id].forced = false;
        s_thunk_nodes[thunk_id].refcnt = 0;

        res.m_front = ~thunk_id;
        increment_refcnt(res.m_front);
        res.m_rear = EMPTY;
        res.m_schedule = res.m_front;
        increment_refcnt(res.m_schedule);
      }

      return res;
    }

    template <typename... Args>
    tools::persistent_queue<T> emplace(Args&&... args) const {
      return this->push(T(std::forward<Args>(args)...));
    }
  };
}

#endif
