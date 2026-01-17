#ifndef TOOLS_PERSISTENT_ARRAY_HPP
#define TOOLS_PERSISTENT_ARRAY_HPP

#include <algorithm>
#include <array>
#include <cassert>
#include <compare>
#include <concepts>
#include <functional>
#include <initializer_list>
#include <iterator>
#include <memory>
#include <ranges>
#include <stack>
#include <utility>
#include <vector>
#include "tools/countr_zero.hpp"
#include "tools/getter_result.hpp"
#include "tools/fix.hpp"
#include "tools/floor_log2.hpp"
#include "tools/pow2.hpp"

namespace tools {
  template <typename T>
  class persistent_array {
    struct node {
      T data;
      std::array<int, 2> children;
      int refcnt;
    };

    static inline std::vector<node> s_nodes;
    static inline std::vector<int> s_free_ids;
    static constexpr int NONE = -1;

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

    int m_root;
    int m_size;

    void wipe() const {
      if (!this->empty()) {
        tools::fix([&](auto&& dfs, const int id) -> void {
          assert(0 <= id && id < std::ssize(s_nodes));
          assert(s_nodes[id].refcnt > 0);
          assert(s_nodes[id].children[0] != NONE || s_nodes[id].children[1] == NONE);
          --s_nodes[id].refcnt;
          if (s_nodes[id].refcnt == 0) {
            if (s_nodes[id].children[0] != NONE) {
              dfs(s_nodes[id].children[0]);
              if (s_nodes[id].children[1] != NONE) {
                dfs(s_nodes[id].children[1]);
              }
            }
            free(id);
          }
        })(this->m_root);
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

    persistent_array() : m_root(NONE), m_size(0) {
    }
    persistent_array(const int n) : persistent_array(n, T{}) {
    }
    persistent_array(const int n, const T& x) {
      assert(n >= 0);
      if (n == 0) {
        this->m_root = NONE;
        this->m_size = 0;
        return;
      }

      const auto log2_n = tools::floor_log2(n);
      std::vector<int> perfect_binary_trees(n == tools::pow2(log2_n + 1) - 1 ? log2_n + 1 : n >= 3 * tools::pow2(log2_n - 1) - 1 ? log2_n : log2_n - 1);
      perfect_binary_trees[0] = malloc();
      s_nodes[perfect_binary_trees[0]].data = x;
      s_nodes[perfect_binary_trees[0]].children = {NONE, NONE};
      s_nodes[perfect_binary_trees[0]].refcnt = 0;
      for (int h = 1; h < std::ssize(perfect_binary_trees); ++h) {
        perfect_binary_trees[h] = malloc();
        s_nodes[perfect_binary_trees[h]].data = x;
        s_nodes[perfect_binary_trees[h]].children = {perfect_binary_trees[h - 1], perfect_binary_trees[h - 1]};
        s_nodes[perfect_binary_trees[h]].refcnt = 0;
        s_nodes[perfect_binary_trees[h - 1]].refcnt += 2;
      }

      this->m_root = perfect_binary_trees.back();
      for (int h = tools::countr_zero(n + 1) + 1; h <= log2_n; ++h) {
        const auto i = n >> h;
        assert((i << h) <= n && n < (i << h) + (1 << h) - 1);

        const auto id = malloc();
        s_nodes[id].data = x;
        s_nodes[id].refcnt = 0;

        const auto comp = n <=> (i << h) + (1 << (h - 1)) - 1;
        if (comp < 0) {
          assert(h >= 2);
          assert(this->m_root != perfect_binary_trees.back());
          s_nodes[id].children = {this->m_root, perfect_binary_trees[h - 2]};
        } else if (comp == 0) {
          s_nodes[id].children = {perfect_binary_trees[h - 1], h >= 2 ? perfect_binary_trees[h - 2] : NONE};
        } else {
          assert(this->m_root != perfect_binary_trees.back());
          s_nodes[id].children = {perfect_binary_trees[h - 1], this->m_root};
        }

        for (const auto child : s_nodes[id].children) {
          if (child != NONE) {
            ++s_nodes[child].refcnt;
          }
        }

        this->m_root = id;
      }

      ++s_nodes[this->m_root].refcnt;
      this->m_size = n;
    }
    template <std::ranges::input_range R>
    requires std::assignable_from<T&, std::ranges::range_reference_t<R>>
    persistent_array(R&& r) {
      std::vector<int> ids;
      for (auto&& x : r) {
        ids.push_back(malloc());
        s_nodes[ids.back()].data = std::forward<decltype(x)>(x);
        s_nodes[ids.back()].refcnt = 1;
      }
      this->m_root = ids.empty() ? NONE : ids.front();
      this->m_size = ids.size();
      for (int i = 1; i <= this->m_size; ++i) {
        s_nodes[ids[i - 1]].children[0] = i * 2 - 1 < this->m_size ? ids[i * 2 - 1] : NONE;
        s_nodes[ids[i - 1]].children[1] = i * 2 < this->m_size ? ids[i * 2] : NONE;
      }
    }
    persistent_array(std::initializer_list<T> il) : persistent_array(std::views::all(il)) {
    }
    persistent_array(const tools::persistent_array<T>& other) : m_root(other.m_root), m_size(other.m_size) {
      if (!this->empty()) {
        ++s_nodes[this->m_root].refcnt;
      }
    }
    persistent_array(tools::persistent_array<T>&& other) noexcept : m_root(other.m_root), m_size(other.m_size) {
      other.m_root = NONE;
      other.m_size = 0;
    }
    ~persistent_array() {
      this->wipe();
    }
    tools::persistent_array<T>& operator=(const tools::persistent_array<T>& other) {
      if (this != std::addressof(other)) {
        this->wipe();
        this->m_root = other.m_root;
        this->m_size = other.m_size;
        if (!this->empty()) {
          ++s_nodes[this->m_root].refcnt;
        }
      }
      return *this;
    }
    tools::persistent_array<T>& operator=(tools::persistent_array<T>&& other) noexcept {
      if (this != std::addressof(other)) {
        this->wipe();
        this->m_root = other.m_root;
        this->m_size = other.m_size;
        other.m_root = NONE;
        other.m_size = 0;
      }
      return *this;
    }

    bool empty() const {
      return this->m_size == 0;
    }
    int size() const {
      return this->m_size;
    }

    auto operator[](this auto&& self, int i) -> tools::getter_result_t<decltype(self), T> {
      assert(0 <= i && i < self.size());
      ++i;
      auto id = self.m_root;
      for (auto s = tools::floor_log2(i); s > 0; --s, id = s_nodes[id].children[(i >> s) & 1]);
      return std::forward_like<decltype(self)>(s_nodes[id].data);
    }

    template <typename U>
    requires std::assignable_from<T&, U>
    tools::persistent_array<T> set(int i, U&& x) const {
      assert(0 <= i && i < this->size());
      ++i;

      const auto log2_i = tools::floor_log2(i);
      std::stack<int> path;
      path.push(this->m_root);
      for (auto s = log2_i; s > 0; --s, path.push(s_nodes[path.top()].children[(i >> s) & 1]));

      auto new_child_id = malloc();
      s_nodes[new_child_id].data = std::forward<U>(x);
      s_nodes[new_child_id].children = s_nodes[path.top()].children;
      s_nodes[new_child_id].refcnt = 1;
      if (s_nodes[new_child_id].children[0] != NONE) {
        ++s_nodes[s_nodes[new_child_id].children[0]].refcnt;
      }
      if (s_nodes[new_child_id].children[1] != NONE) {
        ++s_nodes[s_nodes[new_child_id].children[1]].refcnt;
      }
      path.pop();

      for (int s = 0; s < log2_i; ++s) {
        const auto old_id = path.top();
        path.pop();

        const auto new_id = malloc();
        s_nodes[new_id].data = s_nodes[old_id].data;
        s_nodes[new_id].children[(i >> s) & 1] = new_child_id;
        s_nodes[new_id].children[((i >> s) & 1) ^ 1] = s_nodes[old_id].children[((i >> s) & 1) ^ 1];
        s_nodes[new_id].refcnt = 1;
        if (s_nodes[new_id].children[((i >> s) & 1) ^ 1] != NONE) {
          ++s_nodes[s_nodes[new_id].children[((i >> s) & 1) ^ 1]].refcnt;
        }

        new_child_id = new_id;
      }

      tools::persistent_array<T> res;
      res.m_root = new_child_id;
      res.m_size = this->m_size;
      return res;
    }

    template <typename U>
    requires std::assignable_from<T&, U>
    tools::persistent_array<T> push_back(U&& x) const {
      const auto n = this->size() + 1;
      const auto log2_n = tools::floor_log2(n);
      std::stack<int> path;
      path.push(this->m_root);
      for (auto s = log2_n; s > 0; --s, path.push(s_nodes[path.top()].children[(n >> s) & 1]));

      auto new_child_id = malloc();
      s_nodes[new_child_id].data = std::forward<U>(x);
      s_nodes[new_child_id].children = {NONE, NONE};
      s_nodes[new_child_id].refcnt = 1;
      path.pop();

      for (int s = 0; s < log2_n; ++s) {
        const auto old_id = path.top();
        path.pop();

        const auto new_id = malloc();
        s_nodes[new_id].data = s_nodes[old_id].data;
        s_nodes[new_id].children[(n >> s) & 1] = new_child_id;
        s_nodes[new_id].children[((n >> s) & 1) ^ 1] = s_nodes[old_id].children[((n >> s) & 1) ^ 1];
        s_nodes[new_id].refcnt = 1;
        if (s_nodes[new_id].children[((n >> s) & 1) ^ 1] != NONE) {
          ++s_nodes[s_nodes[new_id].children[((n >> s) & 1) ^ 1]].refcnt;
        }

        new_child_id = new_id;
      }

      tools::persistent_array<T> res;
      res.m_root = new_child_id;
      res.m_size = n;
      return res;
    }

    tools::persistent_array<T> pop_back() const {
      assert(!this->empty());

      const auto n = this->size();
      const auto log2_n = tools::floor_log2(n);
      std::stack<int> path;
      path.push(this->m_root);
      for (auto s = log2_n; s > 0; --s, path.push(s_nodes[path.top()].children[(n >> s) & 1]));

      auto new_child_id = NONE;
      path.pop();

      for (int s = 0; s < log2_n; ++s) {
        const auto old_id = path.top();
        path.pop();

        const auto new_id = malloc();
        s_nodes[new_id].data = s_nodes[old_id].data;
        s_nodes[new_id].children[(n >> s) & 1] = new_child_id;
        s_nodes[new_id].children[((n >> s) & 1) ^ 1] = s_nodes[old_id].children[((n >> s) & 1) ^ 1];
        s_nodes[new_id].refcnt = 1;
        if (s_nodes[new_id].children[((n >> s) & 1) ^ 1] != NONE) {
          ++s_nodes[s_nodes[new_id].children[((n >> s) & 1) ^ 1]].refcnt;
        }

        new_child_id = new_id;
      }

      tools::persistent_array<T> res;
      res.m_root = new_child_id;
      res.m_size = n - 1;
      return res;
    }

    explicit operator std::vector<T>() const {
      std::vector<T> res(this->size());
      if (!this->empty()) {
        tools::fix([&](auto&& dfs, const int id, const int i) -> void {
          if (s_nodes[id].children[0] != NONE) {
            dfs(s_nodes[id].children[0], i * 2);
            if (s_nodes[id].children[1] != NONE) {
              dfs(s_nodes[id].children[1], i * 2 + 1);
            }
          }
          res[i - 1] = s_nodes[id].data;
        })(this->m_root, 1);
      }
      return res;
    }
  };
}

#endif
