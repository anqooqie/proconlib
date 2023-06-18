#ifndef TOOLS_AVL_TREE_HPP
#define TOOLS_AVL_TREE_HPP

#include <type_traits>
#include <functional>
#include <vector>
#include <algorithm>
#include <cassert>
#include <utility>
#include <cmath>
#include "tools/fix.hpp"

namespace tools {
  template <typename SM, typename FM, auto mapping>
  class avl_tree {
  private:
    using S = typename SM::T;
    using F = typename FM::T;
    static_assert(
      ::std::is_convertible_v<decltype(mapping), ::std::function<S(F, S)>>,
      "mapping must work as S(F, S)");

    struct node {
      int id;
      int l_id;
      int r_id;
      int height;
      int size;
      S prod;
      S rprod;
      bool rev;
      F lazy;
    };
    static inline auto m_nodes = ::std::vector<node>{{0, 0, 0, 0, 0, SM::e(), SM::e(), false, FM::e()}};
    int m_root_id;

    static void fetch(const int id) {
      auto& node = m_nodes[id];
      const auto& l_node = m_nodes[node.l_id];
      const auto& r_node = m_nodes[node.r_id];

      node.height = 1 + ::std::max(l_node.height, r_node.height);
      node.size = l_node.size + r_node.size;
      node.prod = SM::op(l_node.prod, r_node.prod);
      node.rprod = SM::op(r_node.rprod, l_node.rprod);
    }
    static void propagate(const int id) {
      auto& node = m_nodes[id];
      auto& l_node = m_nodes[node.l_id];
      auto& r_node = m_nodes[node.r_id];

      assert(!(node.size == 0) || (node.id == 0 && node.l_id == 0 && node.r_id == 0));
      assert(!(node.size == 1) || (node.id > 0 && node.l_id == 0 && node.r_id == 0));
      assert(!(node.size > 1) || (node.id > 0 && node.l_id > 0 && node.r_id > 0));

      if (node.rev) {
        if (node.size > 1) {
          l_node.rev = !l_node.rev;
          r_node.rev = !r_node.rev;
          ::std::swap(node.l_id, node.r_id);
          ::std::swap(node.prod, node.rprod);
        }
        node.rev = false;
      }
      if (node.lazy != FM::e()) {
        if (node.size > 1) {
          l_node.lazy = FM::op(node.lazy, l_node.lazy);
          r_node.lazy = FM::op(node.lazy, r_node.lazy);
        }
        node.prod = mapping(node.lazy, node.prod);
        node.rprod = mapping(node.lazy, node.rprod);
        node.lazy = FM::e();
      }
    }

    static int add_node(const S& x) {
      const int id = m_nodes.size();
      m_nodes.push_back(node{id, 0, 0, 1, 1, x, x, false, FM::e()});
      return id;
    }
    static int add_node(const int l_id, const int r_id) {
      const int id = m_nodes.size();
      m_nodes.push_back(node{id, l_id, r_id, 0, 0, SM::e(), SM::e(), false, FM::e()});
      fetch(id);
      return id;
    }

    static int rotate_l(const int id) {
      auto& node = m_nodes[id];
      auto& r_node = m_nodes[node.r_id];

      assert(node.size > 1);
      assert(node.id > 0);
      assert(node.l_id > 0);
      assert(node.r_id > 0);
      assert(r_node.size > 1);
      assert(r_node.id > 0);
      assert(r_node.l_id > 0);
      assert(r_node.r_id > 0);

      propagate(id);
      propagate(node.l_id);
      propagate(node.r_id);
      propagate(r_node.l_id);
      propagate(r_node.r_id);

      node.r_id = r_node.l_id;
      r_node.l_id = node.id;

      fetch(id);
      fetch(r_node.id);

      return r_node.id;
    }
    static int rotate_r(const int id) {
      auto& node = m_nodes[id];
      auto& l_node = m_nodes[node.l_id];

      assert(node.size > 1);
      assert(node.id > 0);
      assert(node.l_id > 0);
      assert(node.r_id > 0);
      assert(l_node.size > 1);
      assert(l_node.id > 0);
      assert(l_node.l_id > 0);
      assert(l_node.r_id > 0);

      propagate(id);
      propagate(node.l_id);
      propagate(node.r_id);
      propagate(l_node.l_id);
      propagate(l_node.r_id);

      node.l_id = l_node.r_id;
      l_node.r_id = node.id;

      fetch(id);
      fetch(l_node.id);

      return l_node.id;
    }
    static int height_diff(const int id) {
      const auto& node = m_nodes[id];
      const auto& l_node = m_nodes[node.l_id];
      const auto& r_node = m_nodes[node.r_id];

      return l_node.height - r_node.height;
    }
    static int balance(const int id) {
      auto& node = m_nodes[id];

      const auto diff = height_diff(id);
      assert(::std::abs(diff) <= 2);

      if (diff == 2) {
        if (height_diff(node.l_id) < 0) node.l_id = rotate_l(node.l_id);
        return rotate_r(id);
      } else if (diff == -2) {
        if (height_diff(node.r_id) > 0) node.r_id = rotate_r(node.r_id);
        return rotate_l(id);
      } else {
        return id;
      }
    }

    static void set(const int id, const int p, const S& x) {
      auto& node = m_nodes[id];

      assert(0 <= p && p < node.size);

      propagate(id);
      if (node.size == 1) {
        node.prod = x;
      } else {
        const auto half = m_nodes[node.l_id].size;

        if (p < half) {
          set(node.l_id, p, x);
          propagate(node.r_id);
        } else {
          propagate(node.l_id);
          set(node.r_id, p - half, x);
        }
        fetch(id);
      }
    }
    static S prod(const int id, const int l, const int r) {
      auto& node = m_nodes[id];

      assert(0 <= l && l <= r && r <= node.size);

      if (l == r) return SM::e();

      propagate(id);
      if (l == 0 && r == node.size) {
        return node.prod;
      } else {
        const auto half = m_nodes[node.l_id].size;

        auto res = SM::e();
        if (l < half) res = SM::op(res, prod(node.l_id, l, ::std::min(r, half)));
        if (half < r) res = SM::op(res, prod(node.r_id, ::std::max(0, l - half), r - half));
        return res;
      }
    }
    static void apply(const int id, const int l, const int r, const F& f) {
      auto& node = m_nodes[id];

      assert(0 <= l && l <= r && r <= node.size);

      if (l == r) return;

      if (l == 0 && r == node.size) {
        node.lazy = FM::op(f, node.lazy);
        propagate(id);
      } else {
        propagate(id);

        const auto half = m_nodes[node.l_id].size;
        if (l < half) {
          apply(node.l_id, l, ::std::min(r, half), f);
        } else {
          propagate(node.l_id);
        }
        if (half < r) {
          apply(node.r_id, ::std::max(0, l - half), r - half, f);
        } else {
          propagate(node.r_id);
        }
        fetch(id);
      }
    }
    static int insert(const int id, const int p, const S& x) {
      auto& node = m_nodes[id];

      assert(0 <= p && p <= node.size);

      propagate(id);
      if (node.size == 0) {
        return add_node(x);
      } else if (node.size == 1) {
        if (p == 0) {
          return add_node(add_node(x), id);
        } else {
          return add_node(id, add_node(x));
        }
      } else {
        const auto half = m_nodes[node.l_id].size;

        if (p < half) {
          propagate(node.r_id);
          const auto l_id = insert(node.l_id, p, x);
          m_nodes[id].l_id = l_id;
        } else {
          propagate(node.l_id);
          const auto r_id = insert(node.r_id, p - half, x);
          m_nodes[id].r_id = r_id;
        }
        fetch(id);
        return balance(id);
      }
    }
    static int erase(const int id, const int p) {
      auto& node = m_nodes[id];

      assert(0 <= p && p < node.size);

      propagate(id);
      if (node.size == 1) {
        return 0;
      } else {
        const auto half = m_nodes[node.l_id].size;

        if (p < half) {
          propagate(node.r_id);
          node.l_id = erase(node.l_id, p);
          if (node.l_id == 0) return node.r_id;
        } else {
          propagate(node.l_id);
          node.r_id = erase(node.r_id, p - half);
          if (node.r_id == 0) return node.l_id;
        }
        fetch(id);
        return balance(id);
      }
    }

    static int merge(const int l_id, const int r_id, const int free_id) {
      if (l_id == 0) {
        propagate(r_id);
        return r_id;
      }
      if (r_id == 0) {
        propagate(l_id);
        return l_id;
      }

      auto& l_node = m_nodes[l_id];
      auto& r_node = m_nodes[r_id];
      const auto diff = l_node.height - r_node.height;
      if (diff >= 2) {
        propagate(l_id);
        propagate(l_node.l_id);
        const auto merged_id = merge(l_node.r_id, r_id, free_id);
        m_nodes[l_id].r_id = merged_id;
        fetch(l_id);
        return balance(l_id);
      } else if (diff <= -2) {
        propagate(r_id);
        propagate(r_node.r_id);
        const auto merged_id = merge(l_id, r_node.l_id, free_id);
        m_nodes[r_id].l_id = merged_id;
        fetch(r_id);
        return balance(r_id);
      } else {
        propagate(l_id);
        propagate(r_id);
        if (free_id == 0) {
          return add_node(l_id, r_id);
        } else {
          auto& node = m_nodes[free_id];
          node.l_id = l_id;
          node.r_id = r_id;
          node.rev = false;
          node.lazy = FM::e();
          fetch(free_id);
          return free_id;
        }
      }
    }
    static ::std::pair<int, int> split(const int id, const int i) {
      auto& node = m_nodes[id];

      assert(0 <= i && i <= node.size);

      if (i == 0) return ::std::make_pair(0, id);
      if (i == node.size) return ::std::make_pair(id, 0);

      propagate(id);
      const auto half = m_nodes[node.l_id].size;
      if (i < half) {
        const auto [l_id, r_id] = split(node.l_id, i);
        return ::std::make_pair(l_id, merge(r_id, m_nodes[id].r_id, m_nodes[id].l_id));
      } else if (i > half) {
        const auto [l_id, r_id] = split(node.r_id, i - half);
        return ::std::make_pair(merge(m_nodes[id].l_id, l_id, m_nodes[id].r_id), r_id);
      } else {
        return ::std::make_pair(node.l_id, node.r_id);
      }
    }

    template <typename G>
    static ::std::pair<int, S> max_right(const int id, const int l, const G& g, S carry) {
      const auto& node = m_nodes[id];

      assert(0 <= l && l <= node.size);

      propagate(id);
      if (node.size == 0) {
        return ::std::make_pair(0, carry);
      } else if (node.size == 1) {
        if (l == 0) {
          const auto whole = SM::op(carry, node.prod);
          if (g(whole)) return ::std::make_pair(1, whole);
          return ::std::make_pair(0, carry);
        } else {
          assert(carry == SM::e());
          return ::std::make_pair(1, carry);
        }
      } else {
        const auto half = m_nodes[node.l_id].size;
        int r;
        if (l == 0) {
          const auto whole = SM::op(carry, node.prod);
          if (g(whole)) return ::std::make_pair(node.size, whole);

          ::std::tie(r, carry) = max_right(node.l_id, 0, g, carry);
          if (r < half) return ::std::make_pair(r, carry);

          ::std::tie(r, carry) = max_right(node.r_id, 0, g, carry);
          r += half;
          return ::std::make_pair(r, carry);
        } else {
          assert(carry == SM::e());
          if (l < half) {
            ::std::tie(r, carry) = max_right(node.l_id, l, g, carry);
            if (r < half) return ::std::make_pair(r, carry);
          }
          ::std::tie(r, carry) = max_right(node.r_id, ::std::max(0, l - half), g, carry);
          r += half;
          return ::std::make_pair(r, carry);
        }
      }
    }
    template <typename G>
    static ::std::pair<int, S> min_left(const int id, const int r, const G& g, S carry) {
      const auto& node = m_nodes[id];

      assert(0 <= r && r <= node.size);

      propagate(id);
      if (node.size == 0) {
        return ::std::make_pair(0, carry);
      } else if (node.size == 1) {
        if (r == node.size) {
          const auto whole = SM::op(node.prod, carry);
          if (g(whole)) return ::std::make_pair(0, whole);
          return ::std::make_pair(1, carry);
        } else {
          assert(carry == SM::e());
          return ::std::make_pair(0, carry);
        }
      } else {
        const auto half = m_nodes[node.l_id].size;
        int l;
        if (r == node.size) {
          const auto whole = SM::op(node.prod, carry);
          if (g(whole)) return ::std::make_pair(0, whole);

          ::std::tie(l, carry) = min_left(node.r_id, node.size - half, g, carry);
          l += half;
          if (half < l) return ::std::make_pair(l, carry);

          ::std::tie(l, carry) = min_left(node.l_id, half, g, carry);
          return ::std::make_pair(l, carry);
        } else {
          assert(carry == SM::e());
          if (half < r) {
            ::std::tie(l, carry) = min_left(node.r_id, r - half, g, carry);
            l += half;
            if (half < l) return ::std::make_pair(l, carry);
          }
          ::std::tie(l, carry) = min_left(node.l_id, ::std::min(half, r), g, carry);
          return ::std::make_pair(l, carry);
        }
      }
    }

  public:
    explicit operator ::std::vector<S>() const {
      ::std::vector<S> v;
      if (!this->empty()) {
        ::tools::fix([&](auto&& dfs, const int id) -> void {
          auto& node = m_nodes[id];
          propagate(id);
          if (node.size == 1) {
            v.push_back(node.prod);
          } else {
            dfs(node.l_id);
            dfs(node.r_id);
          }
        })(this->m_root_id);
      }
      return v;
    }

    avl_tree() : m_root_id(0) {
    }
    avl_tree(const ::std::vector<S>& v) {
      this->m_root_id = v.empty() ? 0 : ::tools::fix([&](auto&& dfs, const int l, const int r) -> int {
        if (r - l == 1) {
          return add_node(v[l]);
        } else {
          return add_node(dfs(l, (l + r) / 2), dfs((l + r) / 2, r));
        }
      })(0, v.size());
    }
    avl_tree(const int n) : avl_tree(::std::vector<S>(n, SM::e())) {
    }
    avl_tree(const ::tools::avl_tree<SM, FM, mapping>& other) : avl_tree(static_cast<::std::vector<S>>(other)) {
    }
    avl_tree(::tools::avl_tree<SM, FM, mapping>&& other) : m_root_id(other.m_root_id) {
    }
    ~avl_tree() = default;
    ::tools::avl_tree<SM, FM, mapping>& operator=(const ::tools::avl_tree<SM, FM, mapping>& other) {
      this->m_root_id = ::tools::avl_tree<SM, FM, mapping>(other).m_root_id;
    }
    ::tools::avl_tree<SM, FM, mapping>& operator=(::tools::avl_tree<SM, FM, mapping>&& other) {
      this->m_root_id = other.m_root_id;
    }

    int size() const {
      return m_nodes[this->m_root_id].size;
    }
    bool empty() const {
      return this->m_root_id == 0;
    }

    void set(const int p, const S& x) {
      set(this->m_root_id, p, x);
    }
    S get(const int p) {
      return prod(this->m_root_id, p, p + 1);
    }
    S prod(const int l, const int r) {
      return prod(this->m_root_id, l, r);
    }
    S all_prod() {
      return prod(this->m_root_id, 0, this->size());
    }
    void apply(const int p, const F& f) {
      apply(this->m_root_id, p, p + 1, f);
    }
    void apply(const int l, const int r, const F& f) {
      apply(this->m_root_id, l, r, f);
    }
    void insert(const int p, const S& x) {
      this->m_root_id = insert(this->m_root_id, p, x);
    }
    void erase(const int p) {
      this->m_root_id = erase(this->m_root_id, p);
    }
    void merge(::tools::avl_tree<SM, FM, mapping>& other) {
      this->m_root_id = merge(this->m_root_id, other.m_root_id, 0);
    }
    ::std::pair<::tools::avl_tree<SM, FM, mapping>, ::tools::avl_tree<SM, FM, mapping>> split(const int i) {
      ::tools::avl_tree<SM, FM, mapping> l, r;
      ::std::tie(l.m_root_id, r.m_root_id) = split(this->m_root_id, i);
      return ::std::make_pair(l, r);
    }
    void reverse(const int l, const int r) {
      assert(0 <= l && l <= r && r <= this->size());

      if (l == r) return;

      if (l == 0) {
        if (r == this->size()) {
          m_nodes[this->m_root_id].rev = !m_nodes[this->m_root_id].rev;
        } else {
          const auto [l_id, r_id] = split(this->m_root_id, r);
          m_nodes[l_id].rev = !m_nodes[l_id].rev;
          this->m_root_id = merge(l_id, r_id, this->m_root_id);
        }
      } else {
        if (r == this->size()) {
          const auto [l_id, r_id] = split(this->m_root_id, l);
          m_nodes[r_id].rev = !m_nodes[r_id].rev;
          this->m_root_id = merge(l_id, r_id, this->m_root_id);
        } else {
          const auto [lm_id, r_id] = split(this->m_root_id, r);
          const auto [l_id, m_id] = split(lm_id, l);
          m_nodes[m_id].rev = !m_nodes[m_id].rev;
          this->m_root_id = merge(merge(l_id, m_id, lm_id), r_id, this->m_root_id);
        }
      }
    }
    template <typename G>
    int max_right(const int l, const G& g) {
      return max_right(this->m_root_id, l, g, SM::e()).first;
    }
    template <typename G>
    int min_left(const int r, const G& g) {
      return min_left(this->m_root_id, r, g, SM::e()).first;
    }
  };
}

#endif
