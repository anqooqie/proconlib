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
    path: tools/pow2.hpp
    title: $2^x$
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/tsp.test.cpp
    title: tests/tsp.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/tsp.hpp\"\n\n\n\n#include <cstddef>\n#include <vector>\n\
    #include <limits>\n#include <cassert>\n#include <utility>\n#include <algorithm>\n\
    #include <optional>\n#include <tuple>\n#line 1 \"tools/pow2.hpp\"\n\n\n\n#include\
    \ <type_traits>\n#line 6 \"tools/pow2.hpp\"\n\nnamespace tools {\n\n  template\
    \ <typename T, typename ::std::enable_if<::std::is_unsigned<T>::value, ::std::nullptr_t>::type\
    \ = nullptr>\n  constexpr T pow2(const T x) {\n    return static_cast<T>(1) <<\
    \ x;\n  }\n\n  template <typename T, typename ::std::enable_if<::std::is_signed<T>::value,\
    \ ::std::nullptr_t>::type = nullptr>\n  constexpr T pow2(const T x) {\n    return\
    \ static_cast<T>(static_cast<typename ::std::make_unsigned<T>::type>(1) << static_cast<typename\
    \ ::std::make_unsigned<T>::type>(x));\n  }\n}\n\n\n#line 1 \"tools/chmin.hpp\"\
    \n\n\n\n#line 1 \"tools/cmp_less.hpp\"\n\n\n\n#line 5 \"tools/cmp_less.hpp\"\n\
    \nnamespace tools {\n  template <typename T, typename U>\n  constexpr bool cmp_less(const\
    \ T t, const U u) noexcept {\n    using UT = ::std::make_unsigned_t<T>;\n    using\
    \ UU = ::std::make_unsigned_t<U>;\n    if constexpr (::std::is_signed_v<T> ==\
    \ ::std::is_signed_v<U>) {\n      return t < u;\n    } else if constexpr (::std::is_signed_v<T>)\
    \ {\n      return t < 0 ? true : UT(t) < u;\n    } else {\n      return u < 0\
    \ ? false : t < UU(u);\n    }\n  }\n}\n\n\n#line 5 \"tools/chmin.hpp\"\n\nnamespace\
    \ tools {\n\n  template <typename M, typename N>\n  bool chmin(M& lhs, const N&\
    \ rhs) {\n    bool updated;\n    if constexpr (::std::is_integral_v<M> && ::std::is_integral_v<N>)\
    \ {\n      updated = ::tools::cmp_less(rhs, lhs);\n    } else {\n      updated\
    \ = rhs < lhs;\n    }\n    if (updated) lhs = rhs;\n    return updated;\n  }\n\
    }\n\n\n#line 14 \"tools/tsp.hpp\"\n\nnamespace tools {\n\n  template <bool Directed,\
    \ typename T>\n  class tsp {\n  public:\n    struct edge {\n      ::std::size_t\
    \ id;\n      ::std::size_t from;\n      ::std::size_t to;\n      T cost;\n   \
    \ };\n\n  private:\n    ::std::vector<edge> m_edges;\n    ::std::vector<::std::vector<::std::size_t>>\
    \ m_graph;\n\n  public:\n    tsp() = default;\n    tsp(const ::tools::tsp<Directed,\
    \ T>&) = default;\n    tsp(::tools::tsp<Directed, T>&&) = default;\n    ~tsp()\
    \ = default;\n    ::tools::tsp<Directed, T>& operator=(const ::tools::tsp<Directed,\
    \ T>&) = default;\n    ::tools::tsp<Directed, T>& operator=(::tools::tsp<Directed,\
    \ T>&&) = default;\n\n    explicit tsp(const ::std::size_t n) : m_graph(n, ::std::vector<::std::size_t>(n,\
    \ ::std::numeric_limits<::std::size_t>::max())) {\n      assert(n >= 2);\n   \
    \ }\n\n    ::std::size_t size() const {\n      return this->m_graph.size();\n\
    \    }\n\n    ::std::size_t add_edge(::std::size_t u, ::std::size_t v, const T&\
    \ w) {\n      assert(u < this->size());\n      assert(v < this->size());\n   \
    \   if constexpr (!Directed) {\n        ::std::tie(u, v) = ::std::minmax({u, v});\n\
    \      }\n      this->m_edges.push_back(edge({this->m_edges.size(), u, v, w}));\n\
    \      if (this->m_graph[u][v] == ::std::numeric_limits<::std::size_t>::max()\
    \ || w < this->m_edges[this->m_graph[u][v]].cost) {\n        this->m_graph[u][v]\
    \ = this->m_edges.size() - 1;\n      }\n      if constexpr (!Directed) {\n   \
    \     if (this->m_graph[v][u] == ::std::numeric_limits<::std::size_t>::max() ||\
    \ w < this->m_edges[this->m_graph[v][u]].cost) {\n          this->m_graph[v][u]\
    \ = this->m_edges.size() - 1;\n        }\n      }\n      return this->m_edges.size()\
    \ - 1;\n    }\n\n    const edge& get_edge(const ::std::size_t k) const {\n   \
    \   assert(k < this->m_edges.size());\n      return this->m_edges[k];\n    }\n\
    \n    const ::std::vector<edge>& edges() const {\n      return this->m_edges;\n\
    \    }\n\n    ::std::optional<::std::tuple<T, ::std::vector<::std::size_t>, ::std::vector<::std::size_t>>>\
    \ query() const {\n      auto dp = ::std::vector(::tools::pow2(this->size()),\
    \ ::std::vector(this->size(), ::std::numeric_limits<T>::max()));\n      dp[0][0]\
    \ = 0;\n      for (::std::size_t state = 1; state < ::tools::pow2(this->size());\
    \ ++state) {\n        for (::std::size_t v = 0; v < this->size(); ++v) {\n   \
    \       if ((static_cast<::std::size_t>(1) << v) & state) {\n            const\
    \ auto prev_state = state & ~(static_cast<::std::size_t>(1) << v);\n         \
    \   for (::std::size_t u = 0; u < this->size(); ++u) {\n              if (this->m_graph[u][v]\
    \ < ::std::numeric_limits<::std::size_t>::max()) {\n                if (dp[prev_state][u]\
    \ < ::std::numeric_limits<T>::max()) {\n                  ::tools::chmin(dp[state][v],\
    \ dp[prev_state][u] + this->m_edges[this->m_graph[u][v]].cost);\n            \
    \    }\n              }\n            }\n          }\n        }\n      }\n\n  \
    \    ::std::tuple<T, ::std::vector<::std::size_t>, ::std::vector<::std::size_t>>\
    \ res;\n      auto& [total_cost, vids, eids] = res;\n\n      total_cost = dp[::tools::pow2(this->size())\
    \ - 1][0];\n      if (total_cost == ::std::numeric_limits<T>::max()) return ::std::nullopt;\n\
    \n      ::std::size_t state = ::tools::pow2(this->size()) - 1;\n      ::std::size_t\
    \ v = 0;\n      while (state > 0) {\n        const auto prev_state = state & ~(static_cast<::std::size_t>(1)\
    \ << v);\n        for (::std::size_t u = 0; u < this->size(); ++u) {\n       \
    \   if (this->m_graph[u][v] < ::std::numeric_limits<::std::size_t>::max()) {\n\
    \            if (dp[prev_state][u] < ::std::numeric_limits<T>::max() && dp[state][v]\
    \ == dp[prev_state][u] + this->m_edges[this->m_graph[u][v]].cost) {\n        \
    \      vids.push_back(u);\n              eids.push_back(this->m_graph[u][v]);\n\
    \              state = prev_state;\n              v = u;\n              break;\n\
    \            }\n          }\n        }\n      }\n\n      ::std::reverse(vids.begin(),\
    \ vids.end());\n      ::std::reverse(eids.begin(), eids.end());\n\n      return\
    \ res;\n    }\n  };\n}\n\n\n"
  code: "#ifndef TOOLS_TSP_HPP\n#define TOOLS_TSP_HPP\n\n#include <cstddef>\n#include\
    \ <vector>\n#include <limits>\n#include <cassert>\n#include <utility>\n#include\
    \ <algorithm>\n#include <optional>\n#include <tuple>\n#include \"tools/pow2.hpp\"\
    \n#include \"tools/chmin.hpp\"\n\nnamespace tools {\n\n  template <bool Directed,\
    \ typename T>\n  class tsp {\n  public:\n    struct edge {\n      ::std::size_t\
    \ id;\n      ::std::size_t from;\n      ::std::size_t to;\n      T cost;\n   \
    \ };\n\n  private:\n    ::std::vector<edge> m_edges;\n    ::std::vector<::std::vector<::std::size_t>>\
    \ m_graph;\n\n  public:\n    tsp() = default;\n    tsp(const ::tools::tsp<Directed,\
    \ T>&) = default;\n    tsp(::tools::tsp<Directed, T>&&) = default;\n    ~tsp()\
    \ = default;\n    ::tools::tsp<Directed, T>& operator=(const ::tools::tsp<Directed,\
    \ T>&) = default;\n    ::tools::tsp<Directed, T>& operator=(::tools::tsp<Directed,\
    \ T>&&) = default;\n\n    explicit tsp(const ::std::size_t n) : m_graph(n, ::std::vector<::std::size_t>(n,\
    \ ::std::numeric_limits<::std::size_t>::max())) {\n      assert(n >= 2);\n   \
    \ }\n\n    ::std::size_t size() const {\n      return this->m_graph.size();\n\
    \    }\n\n    ::std::size_t add_edge(::std::size_t u, ::std::size_t v, const T&\
    \ w) {\n      assert(u < this->size());\n      assert(v < this->size());\n   \
    \   if constexpr (!Directed) {\n        ::std::tie(u, v) = ::std::minmax({u, v});\n\
    \      }\n      this->m_edges.push_back(edge({this->m_edges.size(), u, v, w}));\n\
    \      if (this->m_graph[u][v] == ::std::numeric_limits<::std::size_t>::max()\
    \ || w < this->m_edges[this->m_graph[u][v]].cost) {\n        this->m_graph[u][v]\
    \ = this->m_edges.size() - 1;\n      }\n      if constexpr (!Directed) {\n   \
    \     if (this->m_graph[v][u] == ::std::numeric_limits<::std::size_t>::max() ||\
    \ w < this->m_edges[this->m_graph[v][u]].cost) {\n          this->m_graph[v][u]\
    \ = this->m_edges.size() - 1;\n        }\n      }\n      return this->m_edges.size()\
    \ - 1;\n    }\n\n    const edge& get_edge(const ::std::size_t k) const {\n   \
    \   assert(k < this->m_edges.size());\n      return this->m_edges[k];\n    }\n\
    \n    const ::std::vector<edge>& edges() const {\n      return this->m_edges;\n\
    \    }\n\n    ::std::optional<::std::tuple<T, ::std::vector<::std::size_t>, ::std::vector<::std::size_t>>>\
    \ query() const {\n      auto dp = ::std::vector(::tools::pow2(this->size()),\
    \ ::std::vector(this->size(), ::std::numeric_limits<T>::max()));\n      dp[0][0]\
    \ = 0;\n      for (::std::size_t state = 1; state < ::tools::pow2(this->size());\
    \ ++state) {\n        for (::std::size_t v = 0; v < this->size(); ++v) {\n   \
    \       if ((static_cast<::std::size_t>(1) << v) & state) {\n            const\
    \ auto prev_state = state & ~(static_cast<::std::size_t>(1) << v);\n         \
    \   for (::std::size_t u = 0; u < this->size(); ++u) {\n              if (this->m_graph[u][v]\
    \ < ::std::numeric_limits<::std::size_t>::max()) {\n                if (dp[prev_state][u]\
    \ < ::std::numeric_limits<T>::max()) {\n                  ::tools::chmin(dp[state][v],\
    \ dp[prev_state][u] + this->m_edges[this->m_graph[u][v]].cost);\n            \
    \    }\n              }\n            }\n          }\n        }\n      }\n\n  \
    \    ::std::tuple<T, ::std::vector<::std::size_t>, ::std::vector<::std::size_t>>\
    \ res;\n      auto& [total_cost, vids, eids] = res;\n\n      total_cost = dp[::tools::pow2(this->size())\
    \ - 1][0];\n      if (total_cost == ::std::numeric_limits<T>::max()) return ::std::nullopt;\n\
    \n      ::std::size_t state = ::tools::pow2(this->size()) - 1;\n      ::std::size_t\
    \ v = 0;\n      while (state > 0) {\n        const auto prev_state = state & ~(static_cast<::std::size_t>(1)\
    \ << v);\n        for (::std::size_t u = 0; u < this->size(); ++u) {\n       \
    \   if (this->m_graph[u][v] < ::std::numeric_limits<::std::size_t>::max()) {\n\
    \            if (dp[prev_state][u] < ::std::numeric_limits<T>::max() && dp[state][v]\
    \ == dp[prev_state][u] + this->m_edges[this->m_graph[u][v]].cost) {\n        \
    \      vids.push_back(u);\n              eids.push_back(this->m_graph[u][v]);\n\
    \              state = prev_state;\n              v = u;\n              break;\n\
    \            }\n          }\n        }\n      }\n\n      ::std::reverse(vids.begin(),\
    \ vids.end());\n      ::std::reverse(eids.begin(), eids.end());\n\n      return\
    \ res;\n    }\n  };\n}\n\n#endif\n"
  dependsOn:
  - tools/pow2.hpp
  - tools/chmin.hpp
  - tools/cmp_less.hpp
  isVerificationFile: false
  path: tools/tsp.hpp
  requiredBy: []
  timestamp: '2024-03-24 18:38:48+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/tsp.test.cpp
documentation_of: tools/tsp.hpp
layout: document
title: Traveling salesman problem
---

It solves the traveling salesman problem.

## License
- CC0

## Author
- anqooqie

## Constructor
```cpp
tsp<Directed> graph(std::size_t n);
```

It creates a graph which is not necessarily simple with $n$ vertices and $0$ edges.
If `Directed` is `true`, the graph is directed.
If `Directed` is `false`, the graph is undirected.

### Constraints
- $n \geq 2$

### Time Complexity
- $O(n^2)$

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
std::size_t graph.add_edge(std::size_t u, std::size_t v, T w);
```

If `Directed` is `true`, it adds a directed edge oriented from $u$ to $v$ with cost $w$.
If `Directed` is `false`, it adds an undirected edge between $u$ and $v$ with cost $w$.
It returns an integer $k$ such that this is the $k$-th edge that is added.

### Constraints
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
  T cost;
};
edge graph.get_edge(std::size_t k);
```

It returns the $k$-th edge.

### Constraints
- $0 \leq k < \|E\|$ where $\|E\|$ is the number of edges

### Time Complexity
- $O(1)$

## edges
```cpp
const std::vector<edge>& graph.edges();
```

It returns all the edges in the graph.
The edges are ordered in the same order as added by `add_edge`.

### Constraints
- None

### Time Complexity
- $O(1)$

## query
```cpp
std::optional<std::tuple<T, std::vector<std::size_t>, std::vector<::std::size_t>>> graph.query();
```

It finds the shortest Hamilton cycle.
If such the cycle does not exist, it returns `std::nullopt`.
If such the cycle exists, it returns the total cost of the cycle, the indices of the vertices which are contained in the cycle and the indices of the edges which are contained in the cycle.

### Constraints
- None

### Time Complexity
- $O(2^n n^2)$
