#ifndef TOOLS_PERSISTENT_STACK_HPP
#define TOOLS_PERSISTENT_STACK_HPP

#include <algorithm>
#include <cassert>
#include <cstddef>
#include <functional>
#include <iterator>
#include <memory>
#include <utility>
#include <vector>

namespace tools {
  template <typename T>
  class persistent_stack {
    struct node {
      int parent;
      int depth;
      T value;
      int refcnt;
    };

    static inline std::vector<node> s_nodes;
    static inline std::vector<int> s_free_ids;

    static int malloc() {
      if (s_free_ids.empty()) {
        s_nodes.emplace_back();
        return s_nodes.size() - 1;
      } else {
        const auto id = s_free_ids.back();
        s_free_ids.pop_back();
        return id;
      }
    }
    static void free(const int id) {
      assert(0 <= id && id < std::ssize(s_nodes));
      assert(s_nodes[id].refcnt == 0);
      s_free_ids.push_back(id);
    }

    static constexpr int EMPTY = -1;
    int m_top;

    void wipe() const {
      auto id = this->m_top;
      while (id != EMPTY) {
        --s_nodes[id].refcnt;
        if (s_nodes[id].refcnt > 0) break;
        const auto parent_id = s_nodes[id].parent;
        free(id);
        id = parent_id;
      }
    }

  public:
    // For testing purposes.
    static bool fully_released() {
      std::vector<bool> released(s_nodes.size(), false);
      for (const auto id : s_free_ids) {
        assert(!released[id]);
        released[id] = true;
      }
      return std::ranges::all_of(released, std::identity{});
    }

    persistent_stack() : m_top(EMPTY) {
    }
    persistent_stack(const tools::persistent_stack<T>& other) : m_top(other.m_top) {
      if (!this->empty()) {
        ++s_nodes[this->m_top].refcnt;
      }
    }
    persistent_stack(tools::persistent_stack<T>&& other) noexcept : m_top(other.m_top) {
      other.m_top = EMPTY;
    }
    ~persistent_stack() {
      this->wipe();
    }
    tools::persistent_stack<T>& operator=(const tools::persistent_stack<T>& other) {
      if (this != std::addressof(other)) {
        this->wipe();
        this->m_top = other.m_top;
        if (!this->empty()) {
          ++s_nodes[this->m_top].refcnt;
        }
      }
      return *this;
    }
    tools::persistent_stack<T>& operator=(tools::persistent_stack<T>&& other) noexcept {
      if (this != std::addressof(other)) {
        this->wipe();
        this->m_top = other.m_top;
        other.m_top = EMPTY;
      }
      return *this;
    }

    bool empty() const {
      return this->m_top == EMPTY;
    }

    std::size_t size() const {
      return this->empty() ? 0 : s_nodes[this->m_top].depth + 1;
    }

    const T& top() const {
      assert(!this->empty());
      return s_nodes[this->m_top].value;
    }

    tools::persistent_stack<T> push(const T& x) const {
      tools::persistent_stack<T> res{};
      res.m_top = malloc();
      s_nodes[res.m_top].parent = this->m_top;
      s_nodes[res.m_top].value = x;
      s_nodes[res.m_top].refcnt = 1;
      if (this->empty()) {
        s_nodes[res.m_top].depth = 0;
      } else {
        s_nodes[res.m_top].depth = s_nodes[this->m_top].depth + 1;
        ++s_nodes[this->m_top].refcnt;
      }
      return res;
    }

    tools::persistent_stack<T> pop() const {
      assert(!this->empty());
      tools::persistent_stack<T> res{};
      res.m_top = s_nodes[this->m_top].parent;
      if (!res.empty()) {
        ++s_nodes[res.m_top].refcnt;
      }
      return res;
    }

    template <typename... Args>
    tools::persistent_stack<T> emplace(Args&&... args) const {
      return this->push(T(std::forward<Args>(args)...));
    }
  };
}

#endif
