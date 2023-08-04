---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/fix.hpp
    title: Fixed point combinator
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/avl_tree/binary_search.test.cpp
    title: tests/avl_tree/binary_search.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/avl_tree/main_features.test.cpp
    title: tests/avl_tree/main_features.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/avl_tree/set.test.cpp
    title: tests/avl_tree/set.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/avl_tree.hpp\"\n\n\n\n#include <type_traits>\n#include\
    \ <functional>\n#include <vector>\n#include <algorithm>\n#include <cassert>\n\
    #include <utility>\n#include <cmath>\n#line 1 \"tools/fix.hpp\"\n\n\n\n#line 6\
    \ \"tools/fix.hpp\"\n\nnamespace tools {\n  template <typename F>\n  struct fix\
    \ : F {\n    template <typename G>\n    fix(G&& g) : F({::std::forward<G>(g)})\
    \ {\n    }\n\n    template <typename... Args>\n    decltype(auto) operator()(Args&&...\
    \ args) const {\n      return F::operator()(*this, ::std::forward<Args>(args)...);\n\
    \    }\n  };\n\n  template <typename F>\n  fix(F&&) -> fix<::std::decay_t<F>>;\n\
    }\n\n\n#line 12 \"tools/avl_tree.hpp\"\n\nnamespace tools {\n  template <typename\
    \ SM, typename FM, auto mapping>\n  class avl_tree {\n  private:\n    using S\
    \ = typename SM::T;\n    using F = typename FM::T;\n    static_assert(\n     \
    \ ::std::is_convertible_v<decltype(mapping), ::std::function<S(F, S)>>,\n    \
    \  \"mapping must work as S(F, S)\");\n\n    struct node {\n      int id;\n  \
    \    int l_id;\n      int r_id;\n      int height;\n      int size;\n      S prod;\n\
    \      S rprod;\n      bool rev;\n      F lazy;\n    };\n    static inline auto\
    \ m_nodes = ::std::vector<node>{{0, 0, 0, 0, 0, SM::e(), SM::e(), false, FM::e()}};\n\
    \    int m_root_id;\n\n    static void fetch(const int id) {\n      auto& node\
    \ = m_nodes[id];\n      const auto& l_node = m_nodes[node.l_id];\n      const\
    \ auto& r_node = m_nodes[node.r_id];\n\n      node.height = 1 + ::std::max(l_node.height,\
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
    \n\n"
  code: "#ifndef TOOLS_AVL_TREE_HPP\n#define TOOLS_AVL_TREE_HPP\n\n#include <type_traits>\n\
    #include <functional>\n#include <vector>\n#include <algorithm>\n#include <cassert>\n\
    #include <utility>\n#include <cmath>\n#include \"tools/fix.hpp\"\n\nnamespace\
    \ tools {\n  template <typename SM, typename FM, auto mapping>\n  class avl_tree\
    \ {\n  private:\n    using S = typename SM::T;\n    using F = typename FM::T;\n\
    \    static_assert(\n      ::std::is_convertible_v<decltype(mapping), ::std::function<S(F,\
    \ S)>>,\n      \"mapping must work as S(F, S)\");\n\n    struct node {\n     \
    \ int id;\n      int l_id;\n      int r_id;\n      int height;\n      int size;\n\
    \      S prod;\n      S rprod;\n      bool rev;\n      F lazy;\n    };\n    static\
    \ inline auto m_nodes = ::std::vector<node>{{0, 0, 0, 0, 0, SM::e(), SM::e(),\
    \ false, FM::e()}};\n    int m_root_id;\n\n    static void fetch(const int id)\
    \ {\n      auto& node = m_nodes[id];\n      const auto& l_node = m_nodes[node.l_id];\n\
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
    \n#endif\n"
  dependsOn:
  - tools/fix.hpp
  isVerificationFile: false
  path: tools/avl_tree.hpp
  requiredBy: []
  timestamp: '2023-06-18 15:00:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/avl_tree/set.test.cpp
  - tests/avl_tree/binary_search.test.cpp
  - tests/avl_tree/main_features.test.cpp
documentation_of: tools/avl_tree.hpp
layout: document
title: Lazy reversible self-balancing binary search tree based on AVL tree
---

It is the data structure for the pair of a [monoid](https://en.wikipedia.org/wiki/Monoid) $(S, \cdot: S \times S \to S, e \in S)$ and a set $F$ of $S \to S$ mappings that satisfies the following properties.

- $F$ contains the identity map $\mathrm{id}$, where the identity map is the map that satisfies $\mathrm{id}(x) = x$ for all $x \in S$.
- $F$ is closed under composition, i.e., $f \circ g \in F$ holds for all $f, g \in F$.
- $f(x \cdot y) = f(x) \cdot f(y)$ holds for all $f \in F$ and $x, y \in S$.

Given an array $S$ of length $N$, it processes the following queries in $O(\log N)$ time.

- Acting the map $f\in F$ (cf. $x = f(x)$) on all the elements of an interval
- Calculating the product of the elements of an interval
- Inserting an element $x \in S$ to the array
- Removing an element from the array
- Spliting the array into the two subarrays
- Merging the two arrays into one array
- Reversing the elements of an interval

For simplicity, in this document, we assume that the oracles `op`, `e`, `mapping`, `composition`, and `id` work in constant time. If these oracles work in $O(T)$ time, each time complexity appear in this document is multipled by $O(T)$.

### References
- [AVL木(split/merge) - Qiita](https://qiita.com/QCFium/items/3cf26a6dc2d49ef490d7)

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
(1) avl_tree<SM, FM, mapping> avl_tree();
(2) avl_tree<SM, FM, mapping> avl_tree(int n);
(3) avl_tree<SM, FM, mapping> avl_tree(std::vector<S> v);
```

It defines $S$ as `typename SM::T`, $\mathrm{op}$ as `S SM::op(S x, S y)`, $\mathrm{e}$ as `S SM::e()`, $F$ as `typename FM::T`, $\mathrm{composition}$ as `F FM::op(F f, F g)`, $\mathrm{id}$ as `F FM::e()` and $\mathrm{mapping}$ as `S mapping(F f, S x)`.

- (1)
    - It creates an empty array `a`.
- (2)
    - It creates an array `a` of length `n`. All the elements are initialized to `e()`.
- (3)
    - It creates an array `a` of length `n = v.size()`, initialized to `v`.

### Constraints
- $\forall x \in S. \forall y \in S. \forall z \in S. \mathrm{op}(\mathrm{op}(x, y), z) = \mathrm{op}(x, \mathrm{op}(y, z))$
- $\forall x \in S. \mathrm{op}(\mathrm{e}(), x) = \mathrm{op}(x, \mathrm{e}()) = x$
- $\forall f \in F. \forall g \in F. \forall h \in F. \mathrm{composition}(\mathrm{composition}(f, g), h) = \mathrm{composition}(f, \mathrm{composition}(g, h))$
- $\forall f \in F. \mathrm{composition}(\mathrm{id}(), f) = \mathrm{composition}(f, \mathrm{id}()) = f$
- $\forall f \in F. \forall x \in S. \forall y \in S. \mathrm{mapping}(f, \mathrm{op}(x, y)) = \mathrm{op}(f(x), f(y))$
- $n \geq 0$

### Time Complexity
- $O(n)$

## empty
```cpp
bool avl_tree.empty();
```

It returns whether $\|a\| = 0$ or not.

### Constraints
- None

### Time Complexity
- $O(1)$

## size
```cpp
int avl_tree.size();
```

It returns $\|a\|$.

### Constraints
- None

### Time Complexity
- $O(1)$

## set
```cpp
void avl_tree.set(int p, S x);
```

`a[p] = x`

### Constraints
- $0 \leq p < \|a\|$

### Time Complexity
- $O(\log \|a\|)$

## get
```cpp
S avl_tree.get(int p);
```

It returns `a[p]`.

### Constraints
- $0 \leq p < \|a\|$

### Time Complexity
- $O(\log \|a\|)$

## prod
```cpp
S avl_tree.prod(int l, int r);
```

It returns `op(a[l], ..., a[r - 1])`, assuming the properties of the monoid.
It returns `e()` if $l = r$.

### Constraints
- $0 \leq l \leq r \leq \|a\|$

### Time Complexity
- $O(\log \|a\|)$

## all_prod
```cpp
S avl_tree.all_prod();
```

It returns `op(a[0], ..., a[a.size() - 1])`, assuming the properties of the monoid.
It returns `e()` if $\|a\| = 0$.

### Constraints
- None

### Time Complexity
- $O(1)$

## apply
```cpp
(1) void avl_tree.apply(int p, F f);
(2) void avl_tree.apply(int l, int r, F f);
```

- (1)
    - It applies `a[p] = f(a[p])`.
- (2)
    - It applies `a[i] = f(a[i])` for all `i = l..r-1`.

### Constraints
- (1)
    - $0 \leq p < \|a\|$
- (2)
    - $0 \leq l \leq r \leq \|a\|$

### Time Complexity
- $O(\log \|a\|)$

## insert
```cpp
void avl_tree.insert(int p, S x);
```

If $p < \|a\|$, it inserts $x$ immediately before `a[i]`.
If $p = \|a\|$, it inserts $x$ to the end of `a`.

### Constraints
- $0 \leq p \leq \|a\|$

### Time Complexity
- $O(\log \|a\|)$

## erase
```cpp
void avl_tree.erase(int p);
```

It removes `a[i]`. (remaining elements will be concatenated)

### Constraints
- $0 \leq p < \|a\|$

### Time Complexity
- $O(\log \|a\|)$

## merge
```cpp
void avl_tree.merge(avl_tree<SM, FM, mapping> other);
```

It appends the sequence represented by `other` to the end of `a`.
`other` gets unavailable after call of this function.

### Constraints
- None

### Time Complexity
- $O(\log \|a\| + \log \|b\|)$ where $\|b\|$ is `other.size()`

## split
```cpp
std::pair<avl_tree<SM, FM, mapping>, avl_tree<SM, FM, mapping>> avl_tree.split(int i);
```

It splits `a` into the two sequences `a[0], a[1], ..., a[i - 1]` and `a[i], a[i + 1], ..., a[a.size() - 1]`.

### Constraints
- $0 \leq i \leq \|a\|$

### Time Complexity
- $O(\log \|a\|)$

## reverse
```cpp
void avl_tree.reverse(int l, int r);
```

It reverses `a[l], a[l + 1], ..., a[r - 1]`.

### Constraints
- $0 \leq l \leq r \leq \|a\|$

### Time Complexity
- $O(\log \|a\|)$

## max_right
```cpp
int avl_tree.max_right<G>(int l, G g)
```
It returns an index `r` that satisfies both of the followings.

- `r = l` or `g(op(a[l], a[l + 1], ..., a[r - 1])) = true`
- `r = a.size()` or `g(op(a[l], a[l + 1], ..., a[r])) = false`

If `g` is monotone, this is the maximum `r` that satisfies `g(op(a[l], a[l + 1], ..., a[r - 1])) = true`.

### Constraints
- The function object that takes `S` as the argument and returns `bool` should be defined.
- if `g` is called with the same argument, it returns the same value, i.e., `g` has no side effect.
- `g(e()) = true`
- $0 \leq l \leq \|a\|$

### Time Complexity
- $O(\log \|a\|)$

## min_left
```cpp
int avl_tree.min_left<G>(int l, G g)
```
It returns an index `l` that satisfies both of the followings.

- `l = r` or `g(op(a[l], a[l + 1], ..., a[r - 1])) = true`
- `l = 0` or `g(op(a[l - 1], a[l], ..., a[r - 1])) = false`

If `g` is monotone, this is the minimum `l` that satisfies `g(op(a[l], a[l + 1], ..., a[r - 1])) = true`.

### Constraints
- The function object that takes `S` as the argument and returns `bool` should be defined.
- if `g` is called with the same argument, it returns the same value, i.e., `g` has no side effect.
- `g(e()) = true`
- $0 \leq r \leq \|a\|$

### Time Complexity
- $O(\log \|a\|)$
