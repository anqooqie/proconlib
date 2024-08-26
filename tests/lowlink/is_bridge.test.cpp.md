---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/chmin.hpp
    title: chmin function
  - icon: ':heavy_check_mark:'
    path: tools/cmp_less.hpp
    title: Polyfill of std::cmp_less
  - icon: ':heavy_check_mark:'
    path: tools/fix.hpp
    title: Fixed point combinator
  - icon: ':heavy_check_mark:'
    path: tools/join.hpp
    title: Join elements with delimiter
  - icon: ':heavy_check_mark:'
    path: tools/less_by.hpp
    title: std::less by key
  - icon: ':heavy_check_mark:'
    path: tools/lowlink.hpp
    title: Lowlink
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/two_edge_connected_components
    links:
    - https://judge.yosupo.jp/problem/two_edge_connected_components
  bundledCode: "#line 1 \"tests/lowlink/is_bridge.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/two_edge_connected_components\"\
    \n\n#include <iostream>\n#line 1 \"lib/ac-library/atcoder/dsu.hpp\"\n\n\n\n#include\
    \ <algorithm>\n#include <cassert>\n#include <vector>\n\nnamespace atcoder {\n\n\
    // Implement (union by size) + (path compression)\n// Reference:\n// Zvi Galil\
    \ and Giuseppe F. Italiano,\n// Data structures and algorithms for disjoint set\
    \ union problems\nstruct dsu {\n  public:\n    dsu() : _n(0) {}\n    explicit\
    \ dsu(int n) : _n(n), parent_or_size(n, -1) {}\n\n    int merge(int a, int b)\
    \ {\n        assert(0 <= a && a < _n);\n        assert(0 <= b && b < _n);\n  \
    \      int x = leader(a), y = leader(b);\n        if (x == y) return x;\n    \
    \    if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);\n        parent_or_size[x]\
    \ += parent_or_size[y];\n        parent_or_size[y] = x;\n        return x;\n \
    \   }\n\n    bool same(int a, int b) {\n        assert(0 <= a && a < _n);\n  \
    \      assert(0 <= b && b < _n);\n        return leader(a) == leader(b);\n   \
    \ }\n\n    int leader(int a) {\n        assert(0 <= a && a < _n);\n        if\
    \ (parent_or_size[a] < 0) return a;\n        return parent_or_size[a] = leader(parent_or_size[a]);\n\
    \    }\n\n    int size(int a) {\n        assert(0 <= a && a < _n);\n        return\
    \ -parent_or_size[leader(a)];\n    }\n\n    std::vector<std::vector<int>> groups()\
    \ {\n        std::vector<int> leader_buf(_n), group_size(_n);\n        for (int\
    \ i = 0; i < _n; i++) {\n            leader_buf[i] = leader(i);\n            group_size[leader_buf[i]]++;\n\
    \        }\n        std::vector<std::vector<int>> result(_n);\n        for (int\
    \ i = 0; i < _n; i++) {\n            result[i].reserve(group_size[i]);\n     \
    \   }\n        for (int i = 0; i < _n; i++) {\n            result[leader_buf[i]].push_back(i);\n\
    \        }\n        result.erase(\n            std::remove_if(result.begin(),\
    \ result.end(),\n                           [&](const std::vector<int>& v) { return\
    \ v.empty(); }),\n            result.end());\n        return result;\n    }\n\n\
    \  private:\n    int _n;\n    // root node: -1 * component size\n    // otherwise:\
    \ parent\n    std::vector<int> parent_or_size;\n};\n\n}  // namespace atcoder\n\
    \n\n#line 1 \"tools/lowlink.hpp\"\n\n\n\n#include <cstddef>\n#line 6 \"tools/lowlink.hpp\"\
    \n#include <iterator>\n#line 8 \"tools/lowlink.hpp\"\n#include <tuple>\n#line\
    \ 10 \"tools/lowlink.hpp\"\n#include <limits>\n#include <stack>\n#include <utility>\n\
    #include <initializer_list>\n#line 1 \"tools/chmin.hpp\"\n\n\n\n#include <type_traits>\n\
    #line 1 \"tools/cmp_less.hpp\"\n\n\n\n#line 5 \"tools/cmp_less.hpp\"\n\nnamespace\
    \ tools {\n  template <typename T, typename U>\n  constexpr bool cmp_less(const\
    \ T t, const U u) noexcept {\n    using UT = ::std::make_unsigned_t<T>;\n    using\
    \ UU = ::std::make_unsigned_t<U>;\n    if constexpr (::std::is_signed_v<T> ==\
    \ ::std::is_signed_v<U>) {\n      return t < u;\n    } else if constexpr (::std::is_signed_v<T>)\
    \ {\n      return t < 0 ? true : UT(t) < u;\n    } else {\n      return u < 0\
    \ ? false : t < UU(u);\n    }\n  }\n}\n\n\n#line 6 \"tools/chmin.hpp\"\n\nnamespace\
    \ tools {\n\n  template <typename M, typename N>\n  bool chmin(M& lhs, const N&\
    \ rhs) {\n    bool updated;\n    if constexpr (::std::is_integral_v<M> && ::std::is_integral_v<N>)\
    \ {\n      updated = ::tools::cmp_less(rhs, lhs);\n    } else {\n      updated\
    \ = rhs < lhs;\n    }\n    if (updated) lhs = rhs;\n    return updated;\n  }\n\
    }\n\n\n#line 1 \"tools/less_by.hpp\"\n\n\n\nnamespace tools {\n\n  template <class\
    \ F>\n  class less_by {\n  private:\n    F selector;\n\n  public:\n    less_by(const\
    \ F& selector) : selector(selector) {\n    }\n\n    template <class T>\n    bool\
    \ operator()(const T& x, const T& y) const {\n      return selector(x) < selector(y);\n\
    \    }\n  };\n}\n\n\n#line 1 \"tools/fix.hpp\"\n\n\n\n#line 6 \"tools/fix.hpp\"\
    \n\nnamespace tools {\n  template <typename F>\n  struct fix : F {\n    template\
    \ <typename G>\n    fix(G&& g) : F({::std::forward<G>(g)}) {\n    }\n\n    template\
    \ <typename... Args>\n    decltype(auto) operator()(Args&&... args) const {\n\
    \      return F::operator()(*this, ::std::forward<Args>(args)...);\n    }\n  };\n\
    \n  template <typename F>\n  fix(F&&) -> fix<::std::decay_t<F>>;\n}\n\n\n#line\
    \ 17 \"tools/lowlink.hpp\"\n\nnamespace tools {\n  class lowlink {\n  public:\n\
    \    struct edge {\n      ::std::size_t id;\n      ::std::size_t from;\n     \
    \ ::std::size_t to;\n    };\n\n  private:\n    ::std::vector<edge> m_edges;\n\
    \    ::std::vector<::std::vector<::std::size_t>> m_graph;\n    bool m_built;\n\
    \    ::std::vector<::std::size_t> m_from;\n    ::std::vector<::std::size_t> m_ord;\n\
    \    ::std::vector<::std::size_t> m_low;\n    ::std::size_t m_ncc;\n    ::std::vector<::std::size_t>\
    \ m_ncc_without_vertex;\n\n  public:\n    class neighbors_iterable {\n    private:\n\
    \      ::tools::lowlink const *m_parent;\n      ::std::size_t m_v;\n\n    public:\n\
    \      class iterator {\n      private:\n        ::tools::lowlink const *m_parent;\n\
    \        ::std::size_t m_v;\n        ::std::size_t m_i;\n\n      public:\n   \
    \     using difference_type = ::std::ptrdiff_t;\n        using value_type = ::std::size_t;\n\
    \        using reference = const ::std::size_t&;\n        using pointer = const\
    \ ::std::size_t*;\n        using iterator_category = ::std::input_iterator_tag;\n\
    \n        iterator() = default;\n        iterator(::tools::lowlink const * const\
    \ parent, const ::std::size_t v, const ::std::size_t i) : m_parent(parent), m_v(v),\
    \ m_i(i) {\n        }\n\n        value_type operator*() const {\n          const\
    \ auto& edge = this->m_parent->m_edges[this->m_parent->m_graph[this->m_v][this->m_i]];\n\
    \          return edge.from ^ edge.to ^ this->m_v;\n        }\n        iterator&\
    \ operator++() {\n          ++this->m_i;\n          return *this;\n        }\n\
    \        iterator operator++(int) {\n          const auto self = *this;\n    \
    \      ++*this;\n          return self;\n        }\n        friend bool operator==(const\
    \ iterator& lhs, const iterator& rhs) {\n          assert(lhs.m_parent == rhs.m_parent);\n\
    \          assert(lhs.m_v == rhs.m_v);\n          return lhs.m_i == rhs.m_i;\n\
    \        }\n        friend bool operator!=(const iterator& lhs, const iterator&\
    \ rhs) {\n          return !(lhs == rhs);\n        }\n      };\n\n      neighbors_iterable()\
    \ = default;\n      neighbors_iterable(::tools::lowlink const * const parent,\
    \ const ::std::size_t v) : m_parent(parent), m_v(v) {\n      }\n\n      iterator\
    \ begin() const {\n        return iterator(this->m_parent, this->m_v, 0);\n  \
    \    };\n      iterator end() const {\n        return iterator(this->m_parent,\
    \ this->m_v, this->m_parent->m_graph[this->m_v].size());\n      }\n    };\n\n\
    \    class edges_iterable {\n    private:\n      ::tools::lowlink const *m_parent;\n\
    \      ::std::size_t m_v;\n\n    public:\n      class iterator {\n      private:\n\
    \        ::tools::lowlink const *m_parent;\n        ::std::size_t m_v;\n     \
    \   ::std::size_t m_i;\n\n      public:\n        using difference_type = ::std::ptrdiff_t;\n\
    \        using value_type = edge;\n        using reference = const edge&;\n  \
    \      using pointer = const edge*;\n        using iterator_category = ::std::input_iterator_tag;\n\
    \n        iterator() = default;\n        iterator(::tools::lowlink const * const\
    \ parent, const ::std::size_t v, const ::std::size_t i) : m_parent(parent), m_v(v),\
    \ m_i(i) {\n        }\n\n        reference operator*() const {\n          return\
    \ this->m_parent->m_edges[this->m_parent->m_graph[this->m_v][this->m_i]];\n  \
    \      }\n        iterator& operator++() {\n          ++this->m_i;\n         \
    \ return *this;\n        }\n        iterator operator++(int) {\n          const\
    \ auto self = *this;\n          ++*this;\n          return self;\n        }\n\
    \        friend bool operator==(const iterator& lhs, const iterator& rhs) {\n\
    \          assert(lhs.m_parent == rhs.m_parent);\n          assert(lhs.m_v ==\
    \ rhs.m_v);\n          return lhs.m_i == rhs.m_i;\n        }\n        friend bool\
    \ operator!=(const iterator& lhs, const iterator& rhs) {\n          return !(lhs\
    \ == rhs);\n        }\n      };\n\n      edges_iterable() = default;\n      edges_iterable(::tools::lowlink\
    \ const * const parent, const ::std::size_t v) : m_parent(parent), m_v(v) {\n\
    \      }\n\n      iterator begin() const {\n        return iterator(this->m_parent,\
    \ this->m_v, 0);\n      };\n      iterator end() const {\n        return iterator(this->m_parent,\
    \ this->m_v, this->m_parent->m_graph[this->m_v].size());\n      }\n    };\n\n\
    \    class vchildren_iterable {\n    private:\n      ::tools::lowlink const *m_parent;\n\
    \      ::std::size_t m_v;\n\n    public:\n      class iterator {\n      private:\n\
    \        ::tools::lowlink const *m_parent;\n        ::std::size_t m_v;\n     \
    \   ::std::size_t m_i;\n\n      public:\n        using difference_type = ::std::ptrdiff_t;\n\
    \        using value_type = ::std::size_t;\n        using reference = const ::std::size_t&;\n\
    \        using pointer = const ::std::size_t*;\n        using iterator_category\
    \ = ::std::input_iterator_tag;\n\n        iterator() = default;\n        iterator(::tools::lowlink\
    \ const * const parent, const ::std::size_t v, const ::std::size_t i) : m_parent(parent),\
    \ m_v(v), m_i(i) {\n          const auto& eids = this->m_parent->m_graph[this->m_v];\n\
    \          for (; this->m_i < eids.size() && [&]() {\n            const auto eid\
    \ = eids[this->m_i];\n            const auto& edge = this->m_parent->m_edges[eid];\n\
    \            return this->m_parent->m_from[edge.from ^ edge.to ^ this->m_v] !=\
    \ eid;\n          }(); ++this->m_i);\n        }\n\n        value_type operator*()\
    \ const {\n          const auto& edge = this->m_parent->m_edges[this->m_parent->m_graph[this->m_v][this->m_i]];\n\
    \          return edge.from ^ edge.to ^ this->m_v;\n        }\n        iterator&\
    \ operator++() {\n          const auto& eids = this->m_parent->m_graph[this->m_v];\n\
    \          assert(this->m_i < eids.size());\n\n          for (++this->m_i; this->m_i\
    \ < eids.size() && [&]() {\n            const auto eid = eids[this->m_i];\n  \
    \          const auto& edge = this->m_parent->m_edges[eid];\n            return\
    \ this->m_parent->m_from[edge.from ^ edge.to ^ this->m_v] != eid;\n          }();\
    \ ++this->m_i);\n\n          return *this;\n        }\n        iterator operator++(int)\
    \ {\n          const auto self = *this;\n          ++*this;\n          return\
    \ self;\n        }\n        friend bool operator==(const iterator& lhs, const\
    \ iterator& rhs) {\n          assert(lhs.m_parent == rhs.m_parent);\n        \
    \  assert(lhs.m_v == rhs.m_v);\n          return lhs.m_i == rhs.m_i;\n       \
    \ }\n        friend bool operator!=(const iterator& lhs, const iterator& rhs)\
    \ {\n          return !(lhs == rhs);\n        }\n      };\n\n      vchildren_iterable()\
    \ = default;\n      vchildren_iterable(::tools::lowlink const * const parent,\
    \ const ::std::size_t v) : m_parent(parent), m_v(v) {\n      }\n\n      iterator\
    \ begin() const {\n        return iterator(this->m_parent, this->m_v, 0);\n  \
    \    };\n      iterator end() const {\n        return iterator(this->m_parent,\
    \ this->m_v, this->m_parent->m_graph[this->m_v].size());\n      }\n    };\n\n\
    \    class echildren_iterable {\n    private:\n      ::tools::lowlink const *m_parent;\n\
    \      ::std::size_t m_v;\n\n    public:\n      class iterator {\n      private:\n\
    \        ::tools::lowlink const *m_parent;\n        ::std::size_t m_v;\n     \
    \   ::std::size_t m_i;\n\n      public:\n        using difference_type = ::std::ptrdiff_t;\n\
    \        using value_type = edge;\n        using reference = const edge&;\n  \
    \      using pointer = const edge*;\n        using iterator_category = ::std::input_iterator_tag;\n\
    \n        iterator() = default;\n        iterator(::tools::lowlink const * const\
    \ parent, const ::std::size_t v, const ::std::size_t i) : m_parent(parent), m_v(v),\
    \ m_i(i) {\n          const auto& eids = this->m_parent->m_graph[this->m_v];\n\
    \          for (; this->m_i < eids.size() && [&]() {\n            const auto eid\
    \ = eids[this->m_i];\n            const auto& edge = this->m_parent->m_edges[eid];\n\
    \            return this->m_parent->m_from[edge.from ^ edge.to ^ this->m_v] !=\
    \ eid;\n          }(); ++this->m_i);\n        }\n\n        reference operator*()\
    \ const {\n          return this->m_parent->m_edges[this->m_parent->m_graph[this->m_v][this->m_i]];\n\
    \        }\n        iterator& operator++() {\n          const auto& eids = this->m_parent->m_graph[this->m_v];\n\
    \          assert(this->m_i < eids.size());\n\n          for (++this->m_i; this->m_i\
    \ < eids.size() && [&]() {\n            const auto eid = eids[this->m_i];\n  \
    \          const auto& edge = this->m_parent->m_edges[eid];\n            return\
    \ this->m_parent->m_from[edge.from ^ edge.to ^ this->m_v] != eid;\n          }();\
    \ ++this->m_i);\n\n          return *this;\n        }\n        iterator operator++(int)\
    \ {\n          const auto self = *this;\n          ++*this;\n          return\
    \ self;\n        }\n        friend bool operator==(const iterator& lhs, const\
    \ iterator& rhs) {\n          assert(lhs.m_parent == rhs.m_parent);\n        \
    \  assert(lhs.m_v == rhs.m_v);\n          return lhs.m_i == rhs.m_i;\n       \
    \ }\n        friend bool operator!=(const iterator& lhs, const iterator& rhs)\
    \ {\n          return !(lhs == rhs);\n        }\n      };\n\n      echildren_iterable()\
    \ = default;\n      echildren_iterable(::tools::lowlink const * const parent,\
    \ const ::std::size_t v) : m_parent(parent), m_v(v) {\n      }\n\n      iterator\
    \ begin() const {\n        return iterator(this->m_parent, this->m_v, 0);\n  \
    \    };\n      iterator end() const {\n        return iterator(this->m_parent,\
    \ this->m_v, this->m_parent->m_graph[this->m_v].size());\n      }\n    };\n\n\
    \    lowlink() = default;\n    explicit lowlink(const ::std::size_t n) : m_graph(n),\
    \ m_built(false) {\n    }\n\n    ::std::size_t size() const {\n      return this->m_graph.size();\n\
    \    }\n\n    ::std::size_t add_edge(::std::size_t u, ::std::size_t v) {\n   \
    \   assert(!this->m_built);\n      assert(u < this->size());\n      assert(v <\
    \ this->size());\n      ::std::tie(u, v) = ::std::minmax({u, v});\n      this->m_edges.push_back(edge{this->m_edges.size(),\
    \ u, v});\n      this->m_graph[u].push_back(this->m_edges.size() - 1);\n     \
    \ this->m_graph[v].push_back(this->m_edges.size() - 1);\n      return this->m_edges.size()\
    \ - 1;\n    }\n\n    const edge& get_edge(const ::std::size_t k) const {\n   \
    \   assert(k < this->m_edges.size());\n      return this->m_edges[k];\n    }\n\
    \n    const ::std::vector<edge>& edges() const {\n      return this->m_edges;\n\
    \    }\n\n    neighbors_iterable neighbors(const ::std::size_t v) const {\n  \
    \    assert(v < this->size());\n      return neighbors_iterable(this, v);\n  \
    \  }\n\n    edges_iterable edges(const ::std::size_t v) const {\n      assert(v\
    \ < this->size());\n      return edges_iterable(this, v);\n    }\n\n    void build()\
    \ {\n      assert(!this->m_built);\n      this->m_built = true;\n\n      const\
    \ auto N_A = ::std::numeric_limits<::std::size_t>::max();\n\n      this->m_from.assign(this->size(),\
    \ N_A);\n      this->m_ord.assign(this->size(), N_A);\n      this->m_low.assign(this->size(),\
    \ N_A);\n      this->m_ncc = 0;\n\n      for (::std::size_t r = 0; r < this->size();\
    \ ++r) {\n        if (this->m_ord[r] != N_A) continue;\n\n        ++this->m_ncc;\n\
    \        ::std::size_t next_ord = 0;\n\n        ::std::stack<::std::pair<::std::size_t,\
    \ ::std::size_t>> stack;\n        stack.emplace(r, N_A);\n        stack.emplace(r,\
    \ N_A - 1);\n        while (!stack.empty()) {\n          const auto [v, from]\
    \ = stack.top();\n          stack.pop();\n\n          if (from != N_A) {\n   \
    \         if (this->m_ord[v] != N_A) continue;\n\n            this->m_from[v]\
    \ = from;\n            this->m_ord[v] = next_ord++;\n\n            for (const\
    \ auto eid : this->m_graph[v]) {\n              const auto& edge = this->m_edges[eid];\n\
    \              const auto u = edge.from ^ edge.to ^ v;\n              if (this->m_ord[u]\
    \ != N_A) continue;\n\n              stack.emplace(u, N_A);\n              stack.emplace(u,\
    \ eid);\n            }\n          } else {\n            if (this->m_low[v] !=\
    \ N_A) continue;\n\n            this->m_low[v] = this->m_ord[v];\n           \
    \ for (const auto eid : this->m_graph[v]) {\n              const auto& edge =\
    \ this->m_edges[eid];\n              const auto u = edge.from ^ edge.to ^ v;\n\
    \              if (this->m_ord[u] < this->m_ord[v] && eid != this->m_from[v])\
    \ {\n                ::tools::chmin(this->m_low[v], this->m_ord[u]);\n       \
    \       } else if (this->m_ord[u] > this->m_ord[v] && eid == this->m_from[u])\
    \ {\n                ::tools::chmin(this->m_low[v], this->m_low[u]);\n       \
    \       }\n            }\n          }\n        }\n\n        this->m_from[r] =\
    \ N_A;\n      }\n\n      this->m_ncc_without_vertex.assign(this->size(), this->m_ncc);\n\
    \      for (::std::size_t v = 0; v < this->size(); ++v) {\n        if (this->m_ord[v]\
    \ == 0) {\n          this->m_ncc_without_vertex[v] += ::std::distance(this->echildren(v).begin(),\
    \ this->echildren(v).end());\n          --this->m_ncc_without_vertex[v];\n   \
    \     } else {\n          for (const auto& edge : this->echildren(v)) {\n    \
    \        const auto u = edge.from ^ edge.to ^ v;\n            if (this->m_ord[v]\
    \ <= this->m_low[u]) {\n              ++this->m_ncc_without_vertex[v];\n     \
    \       }\n          }\n        }\n      }\n    }\n\n    ::std::size_t vparent(const\
    \ ::std::size_t v) const {\n      assert(this->m_built);\n      assert(v < this->size());\n\
    \      assert(this->m_ord[v] > 0);\n\n      const auto& edge = this->m_edges[this->m_from[v]];\n\
    \      return edge.from ^ edge.to ^ v;\n    }\n\n    const edge& eparent(const\
    \ ::std::size_t v) const {\n      assert(this->m_built);\n      assert(v < this->size());\n\
    \      assert(this->m_ord[v] > 0);\n\n      return this->m_edges[this->m_from[v]];\n\
    \    }\n\n    vchildren_iterable vchildren(const ::std::size_t v) const {\n  \
    \    assert(this->m_built);\n      assert(v < this->size());\n\n      return vchildren_iterable(this,\
    \ v);\n    }\n\n    echildren_iterable echildren(const ::std::size_t v) const\
    \ {\n      assert(this->m_built);\n      assert(v < this->size());\n\n      return\
    \ echildren_iterable(this, v);\n    }\n\n    ::std::size_t ord(const ::std::size_t\
    \ v) const {\n      assert(this->m_built);\n      assert(v < this->size());\n\n\
    \      return this->m_ord[v];\n    }\n\n    ::std::size_t low(const ::std::size_t\
    \ v) const {\n      assert(this->m_built);\n      assert(v < this->size());\n\n\
    \      return this->m_low[v];\n    }\n\n    ::std::size_t ncc() const {\n    \
    \  assert(this->m_built);\n\n      return this->m_ncc;\n    }\n\n    ::std::size_t\
    \ ncc_without_vertex(const ::std::size_t v) const {\n      assert(this->m_built);\n\
    \      assert(v < this->size());\n\n      return this->m_ncc_without_vertex[v];\n\
    \    }\n\n    bool is_articulation_point(const ::std::size_t v) const {\n    \
    \  assert(this->m_built);\n      assert(v < this->size());\n\n      return this->m_ncc_without_vertex[v]\
    \ > this->m_ncc;\n    }\n\n    bool is_bridge(const ::std::size_t k) const {\n\
    \      assert(this->m_built);\n      assert(k < this->m_edges.size());\n\n   \
    \   const auto [u, v] = ::std::minmax({this->m_edges[k].from, this->m_edges[k].to},\
    \ ::tools::less_by([&](const auto w) { return this->m_ord[w]; }));\n      return\
    \ this->m_ord[u] < this->m_low[v];\n    }\n\n    ::std::vector<::std::vector<::std::size_t>>\
    \ biconnected_components() const {\n      assert(this->m_built);\n\n      ::std::vector<::std::vector<::std::size_t>>\
    \ groups;\n\n      for (::std::size_t r = 0; r < this->size(); ++r) {\n      \
    \  if (this->ord(r) == 0) {\n          if (this->m_ncc_without_vertex[r] < this->m_ncc)\
    \ {\n            groups.emplace_back(::std::initializer_list<::std::size_t>{r});\n\
    \          } else {\n            ::tools::fix([&](auto&& dfs, const auto g, const\
    \ auto v) -> void {\n              for (const auto u : this->vchildren(v)) {\n\
    \                if (this->ord(v) <= this->low(u)) {\n                  groups.emplace_back(::std::initializer_list<::std::size_t>{v,\
    \ u});\n                  dfs(groups.size() - 1, u);\n                } else {\n\
    \                  groups[g].push_back(u);\n                  dfs(g, u);\n   \
    \             }\n              }\n            })(::std::numeric_limits<::std::size_t>::max(),\
    \ r);\n          }\n        }\n      }\n\n      return groups;\n    }\n  };\n\
    }\n\n\n#line 1 \"tools/join.hpp\"\n\n\n\n#include <string>\n#include <sstream>\n\
    #line 7 \"tools/join.hpp\"\n\nnamespace tools {\n\n  template <typename Iterator>\n\
    \  ::std::string join(const Iterator begin, const Iterator end, const ::std::string&\
    \ delimiter) {\n    ::std::ostringstream ss;\n    if (begin != end) {\n      ss\
    \ << *begin;\n      for (auto it = ::std::next(begin); it != end; ++it) {\n  \
    \      ss << delimiter << *it;\n      }\n    }\n    return ss.str();\n  }\n\n\
    \  template <typename Iterator, typename F>\n  ::std::string join(const Iterator\
    \ begin, const Iterator end, const F& mapper, const ::std::string& delimiter)\
    \ {\n    ::std::ostringstream ss;\n    if (begin != end) {\n      ss << mapper(*begin);\n\
    \      for (auto it = ::std::next(begin); it != end; ++it) {\n        ss << delimiter\
    \ << mapper(*it);\n      }\n    }\n    return ss.str();\n  }\n}\n\n\n#line 8 \"\
    tests/lowlink/is_bridge.test.cpp\"\n\nint main() {\n  std::cin.tie(nullptr);\n\
    \  std::ios_base::sync_with_stdio(false);\n\n  int N, M;\n  std::cin >> N >> M;\n\
    \  tools::lowlink graph(N);\n  for (int i = 0; i < M; ++i) {\n    int a, b;\n\
    \    std::cin >> a >> b;\n    graph.add_edge(a, b);\n  }\n\n  graph.build();\n\
    \n  atcoder::dsu dsu(N);\n  for (int k = 0; tools::cmp_less(k, graph.edges().size());\
    \ ++k) {\n    if (!graph.is_bridge(k)) {\n      const auto& edge = graph.get_edge(k);\n\
    \      dsu.merge(edge.from, edge.to);\n    }\n  }\n\n  const auto groups = dsu.groups();\n\
    \  std::cout << groups.size() << '\\n';\n  for (const auto& group : groups) {\n\
    \    std::cout << group.size() << ' ' << tools::join(group.begin(), group.end(),\
    \ \" \") << '\\n';\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/two_edge_connected_components\"\
    \n\n#include <iostream>\n#include \"atcoder/dsu.hpp\"\n#include \"tools/lowlink.hpp\"\
    \n#include \"tools/cmp_less.hpp\"\n#include \"tools/join.hpp\"\n\nint main() {\n\
    \  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\n  int N,\
    \ M;\n  std::cin >> N >> M;\n  tools::lowlink graph(N);\n  for (int i = 0; i <\
    \ M; ++i) {\n    int a, b;\n    std::cin >> a >> b;\n    graph.add_edge(a, b);\n\
    \  }\n\n  graph.build();\n\n  atcoder::dsu dsu(N);\n  for (int k = 0; tools::cmp_less(k,\
    \ graph.edges().size()); ++k) {\n    if (!graph.is_bridge(k)) {\n      const auto&\
    \ edge = graph.get_edge(k);\n      dsu.merge(edge.from, edge.to);\n    }\n  }\n\
    \n  const auto groups = dsu.groups();\n  std::cout << groups.size() << '\\n';\n\
    \  for (const auto& group : groups) {\n    std::cout << group.size() << ' ' <<\
    \ tools::join(group.begin(), group.end(), \" \") << '\\n';\n  }\n\n  return 0;\n\
    }\n"
  dependsOn:
  - tools/lowlink.hpp
  - tools/chmin.hpp
  - tools/cmp_less.hpp
  - tools/less_by.hpp
  - tools/fix.hpp
  - tools/join.hpp
  isVerificationFile: true
  path: tests/lowlink/is_bridge.test.cpp
  requiredBy: []
  timestamp: '2024-08-27 00:30:38+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/lowlink/is_bridge.test.cpp
layout: document
redirect_from:
- /verify/tests/lowlink/is_bridge.test.cpp
- /verify/tests/lowlink/is_bridge.test.cpp.html
title: tests/lowlink/is_bridge.test.cpp
---
