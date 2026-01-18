#ifndef TOOLS_PERSISTENT_ARRAY_HPP
#define TOOLS_PERSISTENT_ARRAY_HPP

#include <algorithm>
#include <array>
#include <cassert>
#include <concepts>
#include <functional>
#include <initializer_list>
#include <iterator>
#include <memory>
#include <ranges>
#include <stack>
#include <utility>
#include <vector>
#include "tools/ceil_log2.hpp"
#include "tools/countr_zero.hpp"
#include "tools/fix.hpp"
#include "tools/floor_log2.hpp"
#include "tools/pow2.hpp"

namespace tools {
  template <typename T>
  class persistent_array {
    struct inner_node {
      std::array<int, 2> children;
      int refcnt;
    };
    struct leaf_node {
      T data;
      int refcnt;
    };

    static inline std::vector<inner_node> s_inner_nodes;
    static inline std::vector<int> s_free_inner_ids;
    static inline std::vector<leaf_node> s_leaf_nodes;
    static inline std::vector<int> s_free_leaf_ids;

    static int malloc_inner() {
      if (s_free_inner_ids.empty()) {
        s_inner_nodes.emplace_back();
        return s_inner_nodes.size() - 1;
      } else {
        const auto id = s_free_inner_ids.back();
        s_free_inner_ids.pop_back();
        return id;
      }
    }
    static void free_inner(const int id) {
      assert(0 <= id && id < std::ssize(s_inner_nodes));
      assert(s_inner_nodes[id].refcnt == 0);
      s_free_inner_ids.push_back(id);
    }
    static int malloc_leaf() {
      if (s_free_leaf_ids.empty()) {
        s_leaf_nodes.emplace_back();
        return s_leaf_nodes.size() - 1;
      } else {
        const auto id = s_free_leaf_ids.back();
        s_free_leaf_ids.pop_back();
        return id;
      }
    }
    static void free_leaf(const int id) {
      assert(0 <= id && id < std::ssize(s_leaf_nodes));
      assert(s_leaf_nodes[id].refcnt == 0);
      s_free_leaf_ids.push_back(id);
    }
    static void increment_refcnt(int id) {
      if (id >= 0) {
        assert(0 <= id && id < std::ssize(s_inner_nodes));
        ++s_inner_nodes[id].refcnt;
      } else {
        id = ~id;
        assert(0 <= id && id < std::ssize(s_leaf_nodes));
        ++s_leaf_nodes[id].refcnt;
      }
    }
    static void increment_refcnt(const std::array<int, 2>& children) {
      increment_refcnt(children[0]);
      increment_refcnt(children[1]);
    }

    int m_size;
    int m_root;

    void wipe() const {
      if (!this->empty()) {
        tools::fix([&](auto&& dfs, int id) -> void {
          if (id >= 0) {
            assert(0 <= id && id < std::ssize(s_inner_nodes));
            assert(s_inner_nodes[id].refcnt > 0);
            --s_inner_nodes[id].refcnt;
            if (s_inner_nodes[id].refcnt == 0) {
              dfs(s_inner_nodes[id].children[0]);
              dfs(s_inner_nodes[id].children[1]);
              free_inner(id);
            }
          } else {
            id = ~id;
            assert(0 <= id && id < std::ssize(s_leaf_nodes));
            assert(s_leaf_nodes[id].refcnt > 0);
            --s_leaf_nodes[id].refcnt;
            if (s_leaf_nodes[id].refcnt == 0) {
              free_leaf(id);
            }
          }
        })(this->m_root);
      }
    }

  public:
    // For testing purposes.
    static bool fully_released() {
      std::vector<bool> released_inner(s_inner_nodes.size(), false);
      for (const auto id : s_free_inner_ids) {
        assert(!released_inner[id]);
        released_inner[id] = true;
      }
      std::vector<bool> released_leaf(s_leaf_nodes.size(), false);
      for (const auto id : s_free_leaf_ids) {
        assert(!released_leaf[id]);
        released_leaf[id] = true;
      }
      return std::ranges::all_of(released_inner, std::identity{}) && std::ranges::all_of(released_leaf, std::identity{});
    }

    persistent_array() : m_size(0) {
    }
    persistent_array(const int n) : persistent_array(n, T{}) {
    }
    template <typename U>
    requires std::assignable_from<T&, U>
    persistent_array(const int n, U&& x) {
      assert(n >= 0);
      if (n == 0) {
        this->m_size = 0;
        return;
      }

      const auto floor_log2_n = tools::floor_log2(n);
      const auto ceil_log2_n = tools::ceil_log2(n);
      const auto v2_n = tools::countr_zero(n);

      std::vector<int> perfect_binary_trees(floor_log2_n + 1);
      perfect_binary_trees[0] = ~malloc_leaf();
      s_leaf_nodes[~perfect_binary_trees[0]].data = std::forward<U>(x);
      s_leaf_nodes[~perfect_binary_trees[0]].refcnt = 0;
      for (int h = 1; h < std::ssize(perfect_binary_trees); ++h) {
        perfect_binary_trees[h] = malloc_inner();
        s_inner_nodes[perfect_binary_trees[h]].children = {perfect_binary_trees[h - 1], perfect_binary_trees[h - 1]};
        increment_refcnt(s_inner_nodes[perfect_binary_trees[h]].children);
        s_inner_nodes[perfect_binary_trees[h]].refcnt = 0;
      }

      auto right_id = perfect_binary_trees[v2_n];
      for (auto h = v2_n + 2; h <= ceil_log2_n; ++h) {
        if ((n >> (h - 1)) & 1) {
          const auto id = malloc_inner();
          s_inner_nodes[id].children = {perfect_binary_trees[h - 1], right_id};
          increment_refcnt(s_inner_nodes[id].children);
          s_inner_nodes[id].refcnt = 0;
          right_id = id;
        }
      }

      this->m_size = n;
      this->m_root = right_id;
      increment_refcnt(this->m_root);
    }
    template <std::ranges::input_range R>
    requires (!std::ranges::random_access_range<R> && std::assignable_from<T&, std::ranges::range_reference_t<R>>)
    persistent_array(R&& v) : persistent_array(std::forward<R>(v) | std::ranges::to<std::vector>()) {
    }
    template <std::ranges::random_access_range R>
    requires std::assignable_from<T&, std::ranges::range_reference_t<R>>
    persistent_array(R&& v) {
      this->m_size = std::ranges::distance(v);
      if (!this->empty()) {
        this->m_root = tools::fix([&](auto&& dfs, const int l, const int r, const int h) -> int {
          assert(0 <= l && l < r && r <= this->m_size);
          assert(h >= 0);
          assert(r - l <= tools::pow2(h));

          if (r - l == 1) {
            const auto id = malloc_leaf();
            s_leaf_nodes[id].data = std::ranges::begin(v)[l];
            s_leaf_nodes[id].refcnt = 0;
            return ~id;
          }

          const auto m = l + tools::pow2(h - 1);
          if (this->m_size <= m) {
            return dfs(l, r, h - 1);
          }

          const auto id = malloc_inner();
          const auto left_id = dfs(l, m, h - 1);
          const auto right_id = dfs(m, r, h - 1);
          s_inner_nodes[id].children = {left_id, right_id};
          increment_refcnt(s_inner_nodes[id].children);
          s_inner_nodes[id].refcnt = 0;
          return id;
        })(0, this->m_size, tools::ceil_log2(this->m_size));
        increment_refcnt(this->m_root);
      }
    }
    persistent_array(std::initializer_list<T> il) : persistent_array(std::views::all(il)) {
    }
    persistent_array(const tools::persistent_array<T>& other) : m_size(other.m_size) {
      if (!this->empty()) {
        this->m_root = other.m_root;
        increment_refcnt(this->m_root);
      }
    }
    persistent_array(tools::persistent_array<T>&& other) noexcept : m_size(other.m_size), m_root(other.m_root) {
      other.m_size = 0;
    }
    ~persistent_array() {
      this->wipe();
    }
    tools::persistent_array<T>& operator=(const tools::persistent_array<T>& other) {
      if (this != std::addressof(other)) {
        this->wipe();
        this->m_size = other.m_size;
        if (!this->empty()) {
          this->m_root = other.m_root;
          increment_refcnt(this->m_root);
        }
      }
      return *this;
    }
    tools::persistent_array<T>& operator=(tools::persistent_array<T>&& other) noexcept {
      if (this != std::addressof(other)) {
        this->wipe();
        this->m_size = other.m_size;
        this->m_root = other.m_root;
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

    const T& operator[](const int i) const {
      assert(0 <= i && i < this->m_size);
      auto id = this->m_root;
      int l = 0;
      int r = this->m_size;
      int h = tools::ceil_log2(this->m_size);
      while (id >= 0) {
        assert(0 <= l && l + 2 <= r && r <= this->m_size);
        assert(h >= 1);
        assert(r - l <= tools::pow2(h));

        const auto m = l + tools::pow2(h - 1);
        if (m < this->m_size) {
          if (i < m) {
            r = m;
            id = s_inner_nodes[id].children[0];
          } else {
            l = m;
            id = s_inner_nodes[id].children[1];
          }
        }
        --h;
      }

      id = ~id;
      return s_leaf_nodes[id].data;
    }

    template <typename U>
    requires std::assignable_from<T&, U>
    tools::persistent_array<T> set(const int i, U&& x) const {
      assert(0 <= i && i < this->m_size);

      tools::persistent_array<T> res;
      res.m_size = this->m_size;
      res.m_root = tools::fix([&](auto&& dfs, const int id, const int l, const int r, const int h) -> int {
        assert(0 <= l && l < r && r <= this->m_size);
        assert(h >= 0);
        assert(r - l <= tools::pow2(h));

        if (id < 0) {
          assert(r - l == 1);
          const auto new_id = malloc_leaf();
          s_leaf_nodes[new_id].data = std::forward<U>(x);
          s_leaf_nodes[new_id].refcnt = 0;
          return ~new_id;
        }

        assert(r - l >= 2);
        assert(h >= 1);
        const auto m = l + tools::pow2(h - 1);
        if (this->m_size <= m) {
          return dfs(id, l, r, h - 1);
        }

        const auto new_id = malloc_inner();
        int left_id, right_id;
        if (i < m) {
          left_id = dfs(s_inner_nodes[id].children[0], l, m, h - 1);
          right_id = s_inner_nodes[id].children[1];
        } else {
          left_id = s_inner_nodes[id].children[0];
          right_id = dfs(s_inner_nodes[id].children[1], m, r, h - 1);
        }
        s_inner_nodes[new_id].children = {left_id, right_id};
        increment_refcnt(s_inner_nodes[new_id].children);
        s_inner_nodes[new_id].refcnt = 0;
        return new_id;
      })(this->m_root, 0, this->m_size, tools::ceil_log2(this->m_size));
      increment_refcnt(res.m_root);
      return res;
    }

    template <typename U>
    requires std::assignable_from<T&, U>
    tools::persistent_array<T> push_back(U&& x) const {
      tools::persistent_array<T> res;
      res.m_size = this->m_size + 1;
      if (this->empty()) {
        const auto new_id = malloc_leaf();
        s_leaf_nodes[new_id].data = std::forward<U>(x);
        s_leaf_nodes[new_id].refcnt = 0;
        res.m_root = ~new_id;
        increment_refcnt(res.m_root);
      } else {
        res.m_root = tools::fix([&](auto&& dfs, const int id, const int l, const int h) -> int {
          assert(0 <= l && l < this->m_size);
          assert(h >= 0);
          assert(this->m_size - l <= tools::pow2(h));

          if (this->m_size - l == tools::pow2(h)) {
            const auto new_leaf_id = malloc_leaf();
            s_leaf_nodes[new_leaf_id].data = std::forward<U>(x);
            s_leaf_nodes[new_leaf_id].refcnt = 0;
            const auto new_inner_id = malloc_inner();
            s_inner_nodes[new_inner_id].children = {id, ~new_leaf_id};
            increment_refcnt(s_inner_nodes[new_inner_id].children);
            s_inner_nodes[new_inner_id].refcnt = 0;
            return new_inner_id;
          }

          assert(h >= 1);
          const auto m = l + tools::pow2(h - 1);
          if (this->m_size <= m) {
            return dfs(id, l, h - 1);
          }

          assert(this->m_size - l >= 2);
          const auto new_id = malloc_inner();
          const auto right_id = dfs(s_inner_nodes[id].children[1], m, h - 1);
          s_inner_nodes[new_id].children = {s_inner_nodes[id].children[0], right_id};
          increment_refcnt(s_inner_nodes[new_id].children);
          s_inner_nodes[new_id].refcnt = 0;
          return new_id;
        })(this->m_root, 0, tools::ceil_log2(this->m_size));
        increment_refcnt(res.m_root);
      }
      return res;
    }

    tools::persistent_array<T> pop_back() const {
      assert(!this->empty());
      tools::persistent_array<T> res;
      res.m_size = this->m_size - 1;
      if (!res.empty()) {
        res.m_root = tools::fix([&](auto&& dfs, const int id, const int l, const int h) -> int {
          assert(0 <= l && l + 2 <= this->m_size);
          assert(h >= 1);
          assert(this->m_size - l <= tools::pow2(h));

          if (this->m_size - l == tools::pow2(h - 1) + 1) {
            return s_inner_nodes[id].children[0];
          }

          assert(h >= 2);
          const auto m = l + tools::pow2(h - 1);
          if (this->m_size <= m) {
            return dfs(id, l, h - 1);
          }

          assert(this->m_size - l >= 3);
          const auto new_id = malloc_inner();
          const auto right_id = dfs(s_inner_nodes[id].children[1], m, h - 1);
          s_inner_nodes[new_id].children = {s_inner_nodes[id].children[0], right_id};
          increment_refcnt(s_inner_nodes[new_id].children);
          s_inner_nodes[new_id].refcnt = 0;
          return new_id;
        })(this->m_root, 0, tools::ceil_log2(this->m_size));
        increment_refcnt(res.m_root);
      }
      return res;
    }

    explicit operator std::vector<T>() const {
      std::vector<T> res(this->m_size);
      if (!this->empty()) {
        tools::fix([&](auto&& dfs, const int id, const int l, const int r, const int h) -> void {
          assert(0 <= l && l < r && r <= this->m_size);
          assert(h >= 0);
          assert(r - l <= tools::pow2(h));

          if (id < 0) {
            assert(r - l == 1);
            res[l] = s_leaf_nodes[~id].data;
            return;
          }

          assert(r - l >= 2);
          assert(h >= 1);
          const auto m = l + tools::pow2(h - 1);
          if (this->m_size <= m) {
            dfs(id, l, r, h - 1);
            return;
          }

          dfs(s_inner_nodes[id].children[0], l, m, h - 1);
          dfs(s_inner_nodes[id].children[1], m, r, h - 1);
        })(this->m_root, 0, this->m_size, tools::ceil_log2(this->m_size));
      }
      return res;
    }
  };
}

#endif
