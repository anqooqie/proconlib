---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/avl_tree.hpp
    title: Lazy reversible self-balancing binary search tree based on AVL tree
  - icon: ':heavy_check_mark:'
    path: tools/fix.hpp
    title: Fixed point combinator
  - icon: ':question:'
    path: tools/less_by_get.hpp
    title: std::less by std::get
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc281/tasks/abc281_e
    links:
    - https://atcoder.jp/contests/abc281/tasks/abc281_e
  bundledCode: "#line 1 \"tests/avl_tree/binary_search.test.cpp\"\n#define PROBLEM\
    \ \"https://atcoder.jp/contests/abc281/tasks/abc281_e\"\n\n#include <tuple>\n\
    #include <algorithm>\n#include <limits>\n#include <variant>\n#include <iostream>\n\
    #include <vector>\n#line 1 \"tools/avl_tree.hpp\"\n\n\n\n#include <type_traits>\n\
    #include <functional>\n#line 8 \"tools/avl_tree.hpp\"\n#include <cassert>\n#include\
    \ <utility>\n#include <cmath>\n#line 1 \"tools/fix.hpp\"\n\n\n\n#line 6 \"tools/fix.hpp\"\
    \n\nnamespace tools {\n  template <typename F>\n  struct fix : F {\n    template\
    \ <typename G>\n    fix(G&& g) : F({::std::forward<G>(g)}) {\n    }\n\n    template\
    \ <typename... Args>\n    decltype(auto) operator()(Args&&... args) const {\n\
    \      return F::operator()(*this, ::std::forward<Args>(args)...);\n    }\n  };\n\
    \n  template <typename F>\n  fix(F&&) -> fix<::std::decay_t<F>>;\n}\n\n\n#line\
    \ 12 \"tools/avl_tree.hpp\"\n\nnamespace tools {\n  template <typename SM, typename\
    \ FM, auto mapping>\n  class avl_tree {\n  private:\n    using S = typename SM::T;\n\
    \    using F = typename FM::T;\n    static_assert(\n      ::std::is_convertible_v<decltype(mapping),\
    \ ::std::function<S(F, S)>>,\n      \"mapping must work as S(F, S)\");\n\n   \
    \ struct node {\n      int id;\n      int l_id;\n      int r_id;\n      int height;\n\
    \      int size;\n      S prod;\n      S rprod;\n      bool rev;\n      F lazy;\n\
    \    };\n    static inline auto m_nodes = ::std::vector<node>{{0, 0, 0, 0, 0,\
    \ SM::e(), SM::e(), false, FM::e()}};\n    int m_root_id;\n\n    static void fetch(const\
    \ int id) {\n      auto& node = m_nodes[id];\n      const auto& l_node = m_nodes[node.l_id];\n\
    \      const auto& r_node = m_nodes[node.r_id];\n\n      node.height = 1 + ::std::max(l_node.height,\
    \ r_node.height);\n      node.size = l_node.size + r_node.size;\n      node.prod\
    \ = SM::op(l_node.prod, r_node.prod);\n      node.rprod = SM::op(r_node.rprod,\
    \ l_node.rprod);\n    }\n    static void propagate(const int id) {\n      auto&\
    \ node = m_nodes[id];\n      auto& l_node = m_nodes[node.l_id];\n      auto& r_node\
    \ = m_nodes[node.r_id];\n\n      assert(!(node.size == 0) || (node.id == 0 &&\
    \ node.l_id == 0 && node.r_id == 0));\n      assert(!(node.size == 1) || (node.id\
    \ > 0 && node.l_id == 0 && node.r_id == 0));\n      assert(!(node.size > 1) ||\
    \ (node.id > 0 && node.l_id > 0 && node.r_id > 0));\n\n      if (node.rev) {\n\
    \        if (node.size > 1) {\n          l_node.rev = !l_node.rev;\n         \
    \ r_node.rev = !r_node.rev;\n          ::std::swap(node.l_id, node.r_id);\n  \
    \        ::std::swap(node.prod, node.rprod);\n        }\n        node.rev = false;\n\
    \      }\n      if (node.lazy != FM::e()) {\n        if (node.size > 1) {\n  \
    \        l_node.lazy = FM::op(node.lazy, l_node.lazy);\n          r_node.lazy\
    \ = FM::op(node.lazy, r_node.lazy);\n        }\n        node.prod = mapping(node.lazy,\
    \ node.prod);\n        node.rprod = mapping(node.lazy, node.rprod);\n        node.lazy\
    \ = FM::e();\n      }\n    }\n\n    static int add_node(const S& x) {\n      const\
    \ int id = m_nodes.size();\n      m_nodes.push_back(node{id, 0, 0, 1, 1, x, x,\
    \ false, FM::e()});\n      return id;\n    }\n    static int add_node(const int\
    \ l_id, const int r_id) {\n      const int id = m_nodes.size();\n      m_nodes.push_back(node{id,\
    \ l_id, r_id, 0, 0, SM::e(), SM::e(), false, FM::e()});\n      fetch(id);\n  \
    \    return id;\n    }\n\n    static int rotate_l(const int id) {\n      auto&\
    \ node = m_nodes[id];\n      auto& r_node = m_nodes[node.r_id];\n\n      assert(node.size\
    \ > 1);\n      assert(node.id > 0);\n      assert(node.l_id > 0);\n      assert(node.r_id\
    \ > 0);\n      assert(r_node.size > 1);\n      assert(r_node.id > 0);\n      assert(r_node.l_id\
    \ > 0);\n      assert(r_node.r_id > 0);\n\n      propagate(id);\n      propagate(node.l_id);\n\
    \      propagate(node.r_id);\n      propagate(r_node.l_id);\n      propagate(r_node.r_id);\n\
    \n      node.r_id = r_node.l_id;\n      r_node.l_id = node.id;\n\n      fetch(id);\n\
    \      fetch(r_node.id);\n\n      return r_node.id;\n    }\n    static int rotate_r(const\
    \ int id) {\n      auto& node = m_nodes[id];\n      auto& l_node = m_nodes[node.l_id];\n\
    \n      assert(node.size > 1);\n      assert(node.id > 0);\n      assert(node.l_id\
    \ > 0);\n      assert(node.r_id > 0);\n      assert(l_node.size > 1);\n      assert(l_node.id\
    \ > 0);\n      assert(l_node.l_id > 0);\n      assert(l_node.r_id > 0);\n\n  \
    \    propagate(id);\n      propagate(node.l_id);\n      propagate(node.r_id);\n\
    \      propagate(l_node.l_id);\n      propagate(l_node.r_id);\n\n      node.l_id\
    \ = l_node.r_id;\n      l_node.r_id = node.id;\n\n      fetch(id);\n      fetch(l_node.id);\n\
    \n      return l_node.id;\n    }\n    static int height_diff(const int id) {\n\
    \      const auto& node = m_nodes[id];\n      const auto& l_node = m_nodes[node.l_id];\n\
    \      const auto& r_node = m_nodes[node.r_id];\n\n      return l_node.height\
    \ - r_node.height;\n    }\n    static int balance(const int id) {\n      auto&\
    \ node = m_nodes[id];\n\n      const auto diff = height_diff(id);\n      assert(::std::abs(diff)\
    \ <= 2);\n\n      if (diff == 2) {\n        if (height_diff(node.l_id) < 0) node.l_id\
    \ = rotate_l(node.l_id);\n        return rotate_r(id);\n      } else if (diff\
    \ == -2) {\n        if (height_diff(node.r_id) > 0) node.r_id = rotate_r(node.r_id);\n\
    \        return rotate_l(id);\n      } else {\n        return id;\n      }\n \
    \   }\n\n    static void set(const int id, const int p, const S& x) {\n      auto&\
    \ node = m_nodes[id];\n\n      assert(0 <= p && p < node.size);\n\n      propagate(id);\n\
    \      if (node.size == 1) {\n        node.prod = x;\n      } else {\n       \
    \ const auto half = m_nodes[node.l_id].size;\n\n        if (p < half) {\n    \
    \      set(node.l_id, p, x);\n          propagate(node.r_id);\n        } else\
    \ {\n          propagate(node.l_id);\n          set(node.r_id, p - half, x);\n\
    \        }\n        fetch(id);\n      }\n    }\n    static S prod(const int id,\
    \ const int l, const int r) {\n      auto& node = m_nodes[id];\n\n      assert(0\
    \ <= l && l <= r && r <= node.size);\n\n      if (l == r) return SM::e();\n\n\
    \      propagate(id);\n      if (l == 0 && r == node.size) {\n        return node.prod;\n\
    \      } else {\n        const auto half = m_nodes[node.l_id].size;\n\n      \
    \  auto res = SM::e();\n        if (l < half) res = SM::op(res, prod(node.l_id,\
    \ l, ::std::min(r, half)));\n        if (half < r) res = SM::op(res, prod(node.r_id,\
    \ ::std::max(0, l - half), r - half));\n        return res;\n      }\n    }\n\
    \    static void apply(const int id, const int l, const int r, const F& f) {\n\
    \      auto& node = m_nodes[id];\n\n      assert(0 <= l && l <= r && r <= node.size);\n\
    \n      if (l == r) return;\n\n      if (l == 0 && r == node.size) {\n       \
    \ node.lazy = FM::op(f, node.lazy);\n        propagate(id);\n      } else {\n\
    \        propagate(id);\n\n        const auto half = m_nodes[node.l_id].size;\n\
    \        if (l < half) {\n          apply(node.l_id, l, ::std::min(r, half), f);\n\
    \        } else {\n          propagate(node.l_id);\n        }\n        if (half\
    \ < r) {\n          apply(node.r_id, ::std::max(0, l - half), r - half, f);\n\
    \        } else {\n          propagate(node.r_id);\n        }\n        fetch(id);\n\
    \      }\n    }\n    static int insert(const int id, const int p, const S& x)\
    \ {\n      auto& node = m_nodes[id];\n\n      assert(0 <= p && p <= node.size);\n\
    \n      propagate(id);\n      if (node.size == 0) {\n        return add_node(x);\n\
    \      } else if (node.size == 1) {\n        if (p == 0) {\n          return add_node(add_node(x),\
    \ id);\n        } else {\n          return add_node(id, add_node(x));\n      \
    \  }\n      } else {\n        const auto half = m_nodes[node.l_id].size;\n\n \
    \       if (p < half) {\n          propagate(node.r_id);\n          const auto\
    \ l_id = insert(node.l_id, p, x);\n          m_nodes[id].l_id = l_id;\n      \
    \  } else {\n          propagate(node.l_id);\n          const auto r_id = insert(node.r_id,\
    \ p - half, x);\n          m_nodes[id].r_id = r_id;\n        }\n        fetch(id);\n\
    \        return balance(id);\n      }\n    }\n    static int erase(const int id,\
    \ const int p) {\n      auto& node = m_nodes[id];\n\n      assert(0 <= p && p\
    \ < node.size);\n\n      propagate(id);\n      if (node.size == 1) {\n       \
    \ return 0;\n      } else {\n        const auto half = m_nodes[node.l_id].size;\n\
    \n        if (p < half) {\n          propagate(node.r_id);\n          node.l_id\
    \ = erase(node.l_id, p);\n          if (node.l_id == 0) return node.r_id;\n  \
    \      } else {\n          propagate(node.l_id);\n          node.r_id = erase(node.r_id,\
    \ p - half);\n          if (node.r_id == 0) return node.l_id;\n        }\n   \
    \     fetch(id);\n        return balance(id);\n      }\n    }\n\n    static int\
    \ merge(const int l_id, const int r_id, const int free_id) {\n      if (l_id ==\
    \ 0) {\n        propagate(r_id);\n        return r_id;\n      }\n      if (r_id\
    \ == 0) {\n        propagate(l_id);\n        return l_id;\n      }\n\n      auto&\
    \ l_node = m_nodes[l_id];\n      auto& r_node = m_nodes[r_id];\n      const auto\
    \ diff = l_node.height - r_node.height;\n      if (diff >= 2) {\n        propagate(l_id);\n\
    \        propagate(l_node.l_id);\n        const auto merged_id = merge(l_node.r_id,\
    \ r_id, free_id);\n        m_nodes[l_id].r_id = merged_id;\n        fetch(l_id);\n\
    \        return balance(l_id);\n      } else if (diff <= -2) {\n        propagate(r_id);\n\
    \        propagate(r_node.r_id);\n        const auto merged_id = merge(l_id, r_node.l_id,\
    \ free_id);\n        m_nodes[r_id].l_id = merged_id;\n        fetch(r_id);\n \
    \       return balance(r_id);\n      } else {\n        propagate(l_id);\n    \
    \    propagate(r_id);\n        if (free_id == 0) {\n          return add_node(l_id,\
    \ r_id);\n        } else {\n          auto& node = m_nodes[free_id];\n       \
    \   node.l_id = l_id;\n          node.r_id = r_id;\n          node.rev = false;\n\
    \          node.lazy = FM::e();\n          fetch(free_id);\n          return free_id;\n\
    \        }\n      }\n    }\n    static ::std::pair<int, int> split(const int id,\
    \ const int i) {\n      auto& node = m_nodes[id];\n\n      assert(0 <= i && i\
    \ <= node.size);\n\n      if (i == 0) return ::std::make_pair(0, id);\n      if\
    \ (i == node.size) return ::std::make_pair(id, 0);\n\n      propagate(id);\n \
    \     const auto half = m_nodes[node.l_id].size;\n      if (i < half) {\n    \
    \    const auto [l_id, r_id] = split(node.l_id, i);\n        return ::std::make_pair(l_id,\
    \ merge(r_id, m_nodes[id].r_id, m_nodes[id].l_id));\n      } else if (i > half)\
    \ {\n        const auto [l_id, r_id] = split(node.r_id, i - half);\n        return\
    \ ::std::make_pair(merge(m_nodes[id].l_id, l_id, m_nodes[id].r_id), r_id);\n \
    \     } else {\n        return ::std::make_pair(node.l_id, node.r_id);\n     \
    \ }\n    }\n\n    template <typename G>\n    static ::std::pair<int, S> max_right(const\
    \ int id, const int l, const G& g, S carry) {\n      const auto& node = m_nodes[id];\n\
    \n      assert(0 <= l && l <= node.size);\n\n      propagate(id);\n      if (node.size\
    \ == 0) {\n        return ::std::make_pair(0, carry);\n      } else if (node.size\
    \ == 1) {\n        if (l == 0) {\n          const auto whole = SM::op(carry, node.prod);\n\
    \          if (g(whole)) return ::std::make_pair(1, whole);\n          return\
    \ ::std::make_pair(0, carry);\n        } else {\n          assert(carry == SM::e());\n\
    \          return ::std::make_pair(1, carry);\n        }\n      } else {\n   \
    \     const auto half = m_nodes[node.l_id].size;\n        int r;\n        if (l\
    \ == 0) {\n          const auto whole = SM::op(carry, node.prod);\n          if\
    \ (g(whole)) return ::std::make_pair(node.size, whole);\n\n          ::std::tie(r,\
    \ carry) = max_right(node.l_id, 0, g, carry);\n          if (r < half) return\
    \ ::std::make_pair(r, carry);\n\n          ::std::tie(r, carry) = max_right(node.r_id,\
    \ 0, g, carry);\n          r += half;\n          return ::std::make_pair(r, carry);\n\
    \        } else {\n          assert(carry == SM::e());\n          if (l < half)\
    \ {\n            ::std::tie(r, carry) = max_right(node.l_id, l, g, carry);\n \
    \           if (r < half) return ::std::make_pair(r, carry);\n          }\n  \
    \        ::std::tie(r, carry) = max_right(node.r_id, ::std::max(0, l - half),\
    \ g, carry);\n          r += half;\n          return ::std::make_pair(r, carry);\n\
    \        }\n      }\n    }\n    template <typename G>\n    static ::std::pair<int,\
    \ S> min_left(const int id, const int r, const G& g, S carry) {\n      const auto&\
    \ node = m_nodes[id];\n\n      assert(0 <= r && r <= node.size);\n\n      propagate(id);\n\
    \      if (node.size == 0) {\n        return ::std::make_pair(0, carry);\n   \
    \   } else if (node.size == 1) {\n        if (r == node.size) {\n          const\
    \ auto whole = SM::op(node.prod, carry);\n          if (g(whole)) return ::std::make_pair(0,\
    \ whole);\n          return ::std::make_pair(1, carry);\n        } else {\n  \
    \        assert(carry == SM::e());\n          return ::std::make_pair(0, carry);\n\
    \        }\n      } else {\n        const auto half = m_nodes[node.l_id].size;\n\
    \        int l;\n        if (r == node.size) {\n          const auto whole = SM::op(node.prod,\
    \ carry);\n          if (g(whole)) return ::std::make_pair(0, whole);\n\n    \
    \      ::std::tie(l, carry) = min_left(node.r_id, node.size - half, g, carry);\n\
    \          l += half;\n          if (half < l) return ::std::make_pair(l, carry);\n\
    \n          ::std::tie(l, carry) = min_left(node.l_id, half, g, carry);\n    \
    \      return ::std::make_pair(l, carry);\n        } else {\n          assert(carry\
    \ == SM::e());\n          if (half < r) {\n            ::std::tie(l, carry) =\
    \ min_left(node.r_id, r - half, g, carry);\n            l += half;\n         \
    \   if (half < l) return ::std::make_pair(l, carry);\n          }\n          ::std::tie(l,\
    \ carry) = min_left(node.l_id, ::std::min(half, r), g, carry);\n          return\
    \ ::std::make_pair(l, carry);\n        }\n      }\n    }\n\n  public:\n    explicit\
    \ operator ::std::vector<S>() const {\n      ::std::vector<S> v;\n      if (!this->empty())\
    \ {\n        ::tools::fix([&](auto&& dfs, const int id) -> void {\n          auto&\
    \ node = m_nodes[id];\n          propagate(id);\n          if (node.size == 1)\
    \ {\n            v.push_back(node.prod);\n          } else {\n            dfs(node.l_id);\n\
    \            dfs(node.r_id);\n          }\n        })(this->m_root_id);\n    \
    \  }\n      return v;\n    }\n\n    avl_tree() : m_root_id(0) {\n    }\n    avl_tree(const\
    \ ::std::vector<S>& v) {\n      this->m_root_id = v.empty() ? 0 : ::tools::fix([&](auto&&\
    \ dfs, const int l, const int r) -> int {\n        if (r - l == 1) {\n       \
    \   return add_node(v[l]);\n        } else {\n          return add_node(dfs(l,\
    \ (l + r) / 2), dfs((l + r) / 2, r));\n        }\n      })(0, v.size());\n   \
    \ }\n    avl_tree(const int n) : avl_tree(::std::vector<S>(n, SM::e())) {\n  \
    \  }\n    avl_tree(const ::tools::avl_tree<SM, FM, mapping>& other) : avl_tree(static_cast<::std::vector<S>>(other))\
    \ {\n    }\n    avl_tree(::tools::avl_tree<SM, FM, mapping>&& other) : m_root_id(other.m_root_id)\
    \ {\n    }\n    ~avl_tree() = default;\n    ::tools::avl_tree<SM, FM, mapping>&\
    \ operator=(const ::tools::avl_tree<SM, FM, mapping>& other) {\n      this->m_root_id\
    \ = ::tools::avl_tree<SM, FM, mapping>(other).m_root_id;\n    }\n    ::tools::avl_tree<SM,\
    \ FM, mapping>& operator=(::tools::avl_tree<SM, FM, mapping>&& other) {\n    \
    \  this->m_root_id = other.m_root_id;\n    }\n\n    int size() const {\n     \
    \ return m_nodes[this->m_root_id].size;\n    }\n    bool empty() const {\n   \
    \   return this->m_root_id == 0;\n    }\n\n    void set(const int p, const S&\
    \ x) {\n      set(this->m_root_id, p, x);\n    }\n    S get(const int p) {\n \
    \     return prod(this->m_root_id, p, p + 1);\n    }\n    S prod(const int l,\
    \ const int r) {\n      return prod(this->m_root_id, l, r);\n    }\n    S all_prod()\
    \ {\n      return prod(this->m_root_id, 0, this->size());\n    }\n    void apply(const\
    \ int p, const F& f) {\n      apply(this->m_root_id, p, p + 1, f);\n    }\n  \
    \  void apply(const int l, const int r, const F& f) {\n      apply(this->m_root_id,\
    \ l, r, f);\n    }\n    void insert(const int p, const S& x) {\n      this->m_root_id\
    \ = insert(this->m_root_id, p, x);\n    }\n    void erase(const int p) {\n   \
    \   this->m_root_id = erase(this->m_root_id, p);\n    }\n    void merge(::tools::avl_tree<SM,\
    \ FM, mapping>& other) {\n      this->m_root_id = merge(this->m_root_id, other.m_root_id,\
    \ 0);\n    }\n    ::std::pair<::tools::avl_tree<SM, FM, mapping>, ::tools::avl_tree<SM,\
    \ FM, mapping>> split(const int i) {\n      ::tools::avl_tree<SM, FM, mapping>\
    \ l, r;\n      ::std::tie(l.m_root_id, r.m_root_id) = split(this->m_root_id, i);\n\
    \      return ::std::make_pair(l, r);\n    }\n    void reverse(const int l, const\
    \ int r) {\n      assert(0 <= l && l <= r && r <= this->size());\n\n      if (l\
    \ == r) return;\n\n      if (l == 0) {\n        if (r == this->size()) {\n   \
    \       m_nodes[this->m_root_id].rev = !m_nodes[this->m_root_id].rev;\n      \
    \  } else {\n          const auto [l_id, r_id] = split(this->m_root_id, r);\n\
    \          m_nodes[l_id].rev = !m_nodes[l_id].rev;\n          this->m_root_id\
    \ = merge(l_id, r_id, this->m_root_id);\n        }\n      } else {\n        if\
    \ (r == this->size()) {\n          const auto [l_id, r_id] = split(this->m_root_id,\
    \ l);\n          m_nodes[r_id].rev = !m_nodes[r_id].rev;\n          this->m_root_id\
    \ = merge(l_id, r_id, this->m_root_id);\n        } else {\n          const auto\
    \ [lm_id, r_id] = split(this->m_root_id, r);\n          const auto [l_id, m_id]\
    \ = split(lm_id, l);\n          m_nodes[m_id].rev = !m_nodes[m_id].rev;\n    \
    \      this->m_root_id = merge(merge(l_id, m_id, lm_id), r_id, this->m_root_id);\n\
    \        }\n      }\n    }\n    template <typename G>\n    int max_right(const\
    \ int l, const G& g) {\n      return max_right(this->m_root_id, l, g, SM::e()).first;\n\
    \    }\n    template <typename G>\n    int min_left(const int r, const G& g) {\n\
    \      return min_left(this->m_root_id, r, g, SM::e()).first;\n    }\n  };\n}\n\
    \n\n#line 1 \"tools/less_by_get.hpp\"\n\n\n\n#include <cstddef>\n#line 6 \"tools/less_by_get.hpp\"\
    \n\nnamespace tools {\n\n  template <::std::size_t I>\n  struct less_by_get {\n\
    \    template <class T>\n    bool operator()(const T& x, const T& y) const {\n\
    \      return ::std::get<I>(x) < ::std::get<I>(y);\n    }\n  };\n}\n\n\n#line\
    \ 11 \"tests/avl_tree/binary_search.test.cpp\"\n\nusing ll = long long;\n\nusing\
    \ S = std::tuple<ll, ll, ll>;\nstruct SM {\n  using T = S;\n  static T op(const\
    \ T& x, const T& y) {\n    return T(std::max(std::get<0>(x), std::get<0>(y)),\
    \ std::min(::std::get<1>(x), std::get<1>(y)), std::get<2>(x) + std::get<2>(y));\n\
    \  }\n  static T e() {\n    return T(std::numeric_limits<ll>::min(), std::numeric_limits<ll>::max(),\
    \ 0LL);\n  }\n};\nusing F = std::monostate;\nstruct FM {\n  using T = F;\n  static\
    \ T op(const T& f, const T&) {\n    return f;\n  }\n  static T e() {\n    return\
    \ std::monostate{};\n  }\n};\nS mapping(const F&, const S& x) {\n  return x;\n\
    }\n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  int N, M, K;\n  std::cin >> N >> M >> K;\n  std::vector<ll> A(N);\n  for (auto&\
    \ A_i : A) std::cin >> A_i;\n\n  std::vector<S> init;\n  init.reserve(M);\n  for\
    \ (int i = 0; i < M; ++i) {\n    init.emplace_back(A[i], A[i], A[i]);\n  }\n \
    \ std::sort(init.begin(), init.end(), tools::less_by_get<0>());\n\n  tools::avl_tree<SM,\
    \ FM, mapping> avl_tree(init);\n  std::cout << std::get<2>(avl_tree.prod(0, K));\n\
    \  for (int i = 1; i + M <= N; ++i) {\n    avl_tree.insert(avl_tree.max_right(0,\
    \ [&](const S& x) { return std::get<0>(x) < A[i + M - 1]; }), S(A[i + M - 1],\
    \ A[i + M - 1], A[i + M - 1]));\n    avl_tree.erase(avl_tree.min_left(M + 1, [&](const\
    \ S& x) { return std::get<1>(x) >= A[i - 1]; }));\n    std::cout << ' ' << std::get<2>(avl_tree.prod(0,\
    \ K));\n  }\n  std::cout << '\\n';\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc281/tasks/abc281_e\"\n\n\
    #include <tuple>\n#include <algorithm>\n#include <limits>\n#include <variant>\n\
    #include <iostream>\n#include <vector>\n#include \"tools/avl_tree.hpp\"\n#include\
    \ \"tools/less_by_get.hpp\"\n\nusing ll = long long;\n\nusing S = std::tuple<ll,\
    \ ll, ll>;\nstruct SM {\n  using T = S;\n  static T op(const T& x, const T& y)\
    \ {\n    return T(std::max(std::get<0>(x), std::get<0>(y)), std::min(::std::get<1>(x),\
    \ std::get<1>(y)), std::get<2>(x) + std::get<2>(y));\n  }\n  static T e() {\n\
    \    return T(std::numeric_limits<ll>::min(), std::numeric_limits<ll>::max(),\
    \ 0LL);\n  }\n};\nusing F = std::monostate;\nstruct FM {\n  using T = F;\n  static\
    \ T op(const T& f, const T&) {\n    return f;\n  }\n  static T e() {\n    return\
    \ std::monostate{};\n  }\n};\nS mapping(const F&, const S& x) {\n  return x;\n\
    }\n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  int N, M, K;\n  std::cin >> N >> M >> K;\n  std::vector<ll> A(N);\n  for (auto&\
    \ A_i : A) std::cin >> A_i;\n\n  std::vector<S> init;\n  init.reserve(M);\n  for\
    \ (int i = 0; i < M; ++i) {\n    init.emplace_back(A[i], A[i], A[i]);\n  }\n \
    \ std::sort(init.begin(), init.end(), tools::less_by_get<0>());\n\n  tools::avl_tree<SM,\
    \ FM, mapping> avl_tree(init);\n  std::cout << std::get<2>(avl_tree.prod(0, K));\n\
    \  for (int i = 1; i + M <= N; ++i) {\n    avl_tree.insert(avl_tree.max_right(0,\
    \ [&](const S& x) { return std::get<0>(x) < A[i + M - 1]; }), S(A[i + M - 1],\
    \ A[i + M - 1], A[i + M - 1]));\n    avl_tree.erase(avl_tree.min_left(M + 1, [&](const\
    \ S& x) { return std::get<1>(x) >= A[i - 1]; }));\n    std::cout << ' ' << std::get<2>(avl_tree.prod(0,\
    \ K));\n  }\n  std::cout << '\\n';\n\n  return 0;\n}\n"
  dependsOn:
  - tools/avl_tree.hpp
  - tools/fix.hpp
  - tools/less_by_get.hpp
  isVerificationFile: true
  path: tests/avl_tree/binary_search.test.cpp
  requiredBy: []
  timestamp: '2023-06-18 15:00:55+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/avl_tree/binary_search.test.cpp
layout: document
redirect_from:
- /verify/tests/avl_tree/binary_search.test.cpp
- /verify/tests/avl_tree/binary_search.test.cpp.html
title: tests/avl_tree/binary_search.test.cpp
---
