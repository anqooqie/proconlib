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
    path: tools/less_by.hpp
    title: std::less by key
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/lowlink/biconnected_components.test.cpp
    title: tests/lowlink/biconnected_components.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/lowlink/is_bridge.test.cpp
    title: tests/lowlink/is_bridge.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/lowlink/ncc_without_vertex.test.cpp
    title: tests/lowlink/ncc_without_vertex.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/lowlink.hpp\"\n\n\n\n#include <cstddef>\n#include\
    \ <vector>\n#include <iterator>\n#include <cassert>\n#include <tuple>\n#include\
    \ <algorithm>\n#include <limits>\n#include <stack>\n#include <utility>\n#include\
    \ <initializer_list>\n#line 1 \"tools/chmin.hpp\"\n\n\n\n#include <type_traits>\n\
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
    }\n\n\n"
  code: "#ifndef TOOLS_LOWLINK_HPP\n#define TOOLS_LOWLINK_HPP\n\n#include <cstddef>\n\
    #include <vector>\n#include <iterator>\n#include <cassert>\n#include <tuple>\n\
    #include <algorithm>\n#include <limits>\n#include <stack>\n#include <utility>\n\
    #include <initializer_list>\n#include \"tools/chmin.hpp\"\n#include \"tools/less_by.hpp\"\
    \n#include \"tools/fix.hpp\"\n\nnamespace tools {\n  class lowlink {\n  public:\n\
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
    }\n\n#endif\n"
  dependsOn:
  - tools/chmin.hpp
  - tools/cmp_less.hpp
  - tools/less_by.hpp
  - tools/fix.hpp
  isVerificationFile: false
  path: tools/lowlink.hpp
  requiredBy: []
  timestamp: '2024-08-27 00:30:38+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/lowlink/ncc_without_vertex.test.cpp
  - tests/lowlink/biconnected_components.test.cpp
  - tests/lowlink/is_bridge.test.cpp
documentation_of: tools/lowlink.hpp
layout: document
title: Lowlink
---

Given an undirected graph, it creates a data structure that allows enumeration of bridges and articulation points in linear time.
The graph may contain self-loops or multiple edges and need not be connected.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
lowlink graph(std::size_t n);
```

It creates an undirected graph with $n$ vertices and $0$ edges.

### Constraints
- None

### Time Complexity
- $O(n)$

## size
```cpp
std::size_t graph.size();
```

It returns $n$.

### Constraints
- None

### Time Complexity
- $O(1)$

## add_edge
```cpp
std::size_t graph.add_edge(std::size_t u, std::size_t v);
```

It adds an undirected edge connecting vertex $u$ and vertex $v$ to the graph, and returns the number of edges that existed before the undirected edge was added.

### Constraints
- `graph.build()` has not been called ever.
- $0 \leq u < n$
- $0 \leq v < n$

### Time Complexity
- $O(1)$ amortized

## get_edge
```cpp
struct edge {
  std::size_t id;
  std::size_t from;
  std::size_t to;
};
const edge& graph.get_edge(std::size_t k);
```

It returns information about the $k$-th edge in $0$-indexed.
The information means that the `id`-th edge added to this graph is the undirected edge connecting vertex `from` and vertex `to`.
Of course, as this is an undirected graph, the `from` and `to` orientations are meaningless.
In an undirected graph such as this graph, the vertex numbers are always sorted so that `from` $\leq$ `to`.

### Constraints
- $0 \leq k < \|E\|$ where $\|E\|$ is the number of edges

### Time Complexity
- $O(1)$

## edges
### (1)
```cpp
const std::vector<edge>& graph.edges();
```

It returns all the edges in the graph.
The edges are ordered in the same order as added by `add_edge`.

#### Constraints
- None

#### Time Complexity
- $O(1)$

### (2)
```cpp
struct edges_iterable {
  struct iterator {
    const edge& operator*();
    iterator& operator++();
    iterator operator++(int):
    friend bool operator==(iterator lhs, iterator rhs);
    friend bool operator!=(iterator lhs, iterator rhs);
  };
  iterator begin();
  iterator end();
};
edges_iterable graph.edges(std::size_t v);
```

It returns an iterator that enumerates the edges adjacent to vertex $v$.
The enumeration order is undefined, except that each element appears exactly once.

#### Constraints
- $0 \leq v < n$

#### Time Complexity
- $O(1)$

## neighbors
```cpp
struct neighbors_iterable {
  struct iterator {
    std::size_t operator*();
    iterator& operator++();
    iterator operator++(int):
    friend bool operator==(iterator lhs, iterator rhs);
    friend bool operator!=(iterator lhs, iterator rhs);
  };
  iterator begin();
  iterator end();
};
neighbors_iterable graph.neighbors(std::size_t v);
```

It returns an iterator that enumerates the vertices adjacent to vertex $v$.
The enumeration order is undefined.
If the graph contains multiple edges, a vertex may appear more than once.
Also, if the graph contains self-loops, vertex $v$ itself may appear in the enumeration.

### Constraints
- $0 \leq v < n$

### Time Complexity
- $O(1)$

## build
```cpp
void graph.build();
```

It creates a data structure that allows bridges and articulation points to be enumerated in linear time.
The key elements are values called $\mathrm{ord}(v)$ and $\mathrm{low}(v)$ assigned to each vertex $v$, which are defined as follows.

We first repeat the process of creating a spanning tree for each connected component of the graph by a depth-first search, choosing the roots as appropriate.
We call this spanning tree a DFS tree, and the edges belonging to the DFS tree are called tree edges.
We regard a tree edge as a directed edge from the root side to the leaf side.

We also refer to edges that do not belong to the DFS tree as back edges.
Back edges are known to have both endpoints always in an ancestor-descendant relationship.
We regard a back edge as a directed edge from the leaf side to the root side.

We define $\mathrm{ord}(v)$ and $\mathrm{low}(v)$ as values determined for each vertex $v$ of the spanning tree.
The definition of $\mathrm{ord}(v)$ is the pre-ordered vertex number of the DFS tree.
The $\mathrm{ord}(r)$ of root $r$ is $0$.
The definition of $\mathrm{low}(v)$ is $\displaystyle \min_{s \in S}\left(\mathrm{ord}\left(s\right)\right)$, where $S$ is the set of vertices reachable from vertex $v$ using zero or more tree edges and one or less back edges.

Note that there are as many vertices $v$ such that $\mathrm{ord}(v) = 0$ as there are connected components.

### Constraints
- `graph.build()` has not been called ever.

### Time Complexity
- $O(n + \|E\|)$ where $\|E\|$ is the number of edges

## vparent
```cpp
std::size_t graph.vparent(std::size_t v);
```

It returns $u$ such that the parent of vertex $v$ in the DFS tree is vertex $u$.

### Constraints
- `graph.build()` has been called ever.
- $0 \leq v < n$
- $\mathrm{ord}(v) > 0$

### Time Complexity
- $O(1)$

## eparent
```cpp
const edge& graph.eparent(std::size_t v);
```

It returns the tree edge towards vertex $v$.

### Constraints
- `graph.build()` has been called ever.
- $0 \leq v < n$
- $\mathrm{ord}(v) > 0$

### Time Complexity
- $O(1)$

## vchildren
```cpp
struct vchildren_iterable {
  struct iterator {
    std::size_t operator*();
    iterator& operator++();
    iterator operator++(int):
    friend bool operator==(iterator lhs, iterator rhs);
    friend bool operator!=(iterator lhs, iterator rhs);
  };
  iterator begin();
  iterator end();
};
vchildren_iterable graph.vchildren(std::size_t v);
```

It returns $u$ such that the parent of vertex $u$ in the DFS tree is vertex $v$.

### Constraints
- `graph.build()` has been called ever.
- $0 \leq v < n$

### Time Complexity
- $O(1)$

## echildren
```cpp
struct echildren_iterable {
  struct iterator {
    const edge& operator*();
    iterator& operator++();
    iterator operator++(int):
    friend bool operator==(iterator lhs, iterator rhs);
    friend bool operator!=(iterator lhs, iterator rhs);
  };
  iterator begin();
  iterator end();
};
echildren_iterable graph.echildren(std::size_t v);
```

It returns the tree edges outward from vertex $v$.

### Constraints
- `graph.build()` has been called ever.
- $0 \leq v < n$

### Time Complexity
- $O(1)$

## ord
```cpp
std::size_t graph.ord(std::size_t v);
```

It returns $\mathrm{ord}(v)$.

### Constraints
- `graph.build()` has been called ever.
- $0 \leq v < n$

### Time Complexity
- $O(1)$

## low
```cpp
std::size_t graph.low(std::size_t v);
```

It returns $\mathrm{low}(v)$.

### Constraints
- `graph.build()` has been called ever.
- $0 \leq v < n$

### Time Complexity
- $O(1)$

## ncc
```cpp
std::size_t graph.ncc();
```

It returns the number of connected components of the graph.

### Constraints
- `graph.build()` has been called ever.

### Time Complexity
- $O(1)$

## ncc_without_vertex
```cpp
std::size_t graph.ncc_without_vertex(std::size_t v);
```

It returns the number of connected components of the graph without vertex $v$.

### Constraints
- `graph.build()` has been called ever.
- $0 \leq v < n$

### Time Complexity
- $O(1)$

## is_articulation_point
```cpp
bool graph.is_articulation_point(std::size_t v);
```

It returns whether vertex $v$ is an articulation point or not.

### Constraints
- `graph.build()` has been called ever.
- $0 \leq v < n$

### Time Complexity
- $O(1)$

## is_bridge
```cpp
bool graph.is_bridge(std::size_t k);
```

It returns whether the $k$-th edge is a bridge or not.

### Constraints
- `graph.build()` has been called ever.
- $0 \leq k < \|E\|$ where $\|E\|$ is the number of edges

### Time Complexity
- $O(1)$

## biconnected_components
```cpp
std::vector<std::vector<std::size_t>> graph.biconnected_components();
```

It divides the graph into biconnected components and returns the list of them.

More precisely, it returns the list of the "list of the vertices in a biconnected component".
Both of the orders of the biconnected components and the vertices are undefined.

### Constraints
- `graph.build()` has been called ever.

### Time Complexity
- $O(n + \|E\|)$ where $\|E\|$ is the number of edges
