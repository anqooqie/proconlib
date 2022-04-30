---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/cycle_detection.test.cpp
    title: tests/cycle_detection.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/cycle_detection.hpp\"\n\n\n\n#include <vector>\n#include\
    \ <cstddef>\n#include <utility>\n#include <cassert>\n#include <optional>\n#include\
    \ <stack>\n#include <tuple>\n#include <limits>\n#include <algorithm>\n\nnamespace\
    \ tools {\n  class cycle_detection {\n  private:\n    ::std::vector<::std::vector<::std::size_t>>\
    \ m_graph;\n    ::std::vector<::std::pair<::std::size_t, ::std::size_t>> m_edges;\n\
    \n  public:\n    cycle_detection() = default;\n    cycle_detection(const ::tools::cycle_detection&)\
    \ = default;\n    cycle_detection(::tools::cycle_detection&&) = default;\n   \
    \ ~cycle_detection() = default;\n    ::tools::cycle_detection& operator=(const\
    \ ::tools::cycle_detection&) = default;\n    ::tools::cycle_detection& operator=(::tools::cycle_detection&&)\
    \ = default;\n\n    explicit cycle_detection(const ::std::size_t n) :\n      m_graph(n)\
    \ {\n    }\n\n    ::std::size_t size() const {\n      return this->m_graph.size();\n\
    \    }\n\n    ::std::size_t add_edge(const ::std::size_t u, const ::std::size_t\
    \ v) {\n      assert(u < this->size());\n      assert(v < this->size());\n\n \
    \     this->m_graph[u].push_back(this->m_edges.size());\n      this->m_edges.emplace_back(u,\
    \ v);\n      return this->m_edges.size() - 1;\n    }\n\n    ::std::optional<::std::pair<::std::vector<::std::size_t>,\
    \ ::std::vector<::std::size_t>>> query() const {\n      ::std::stack<std::tuple<bool,\
    \ ::std::size_t, ::std::size_t>> stack;\n      for (::std::size_t v = 0; v < this->size();\
    \ ++v) {\n        stack.emplace(false, v, ::std::numeric_limits<::std::size_t>::max());\n\
    \        stack.emplace(true, v, ::std::numeric_limits<::std::size_t>::max());\n\
    \      }\n      ::std::vector<bool> pre(this->size(), false);\n      ::std::vector<bool>\
    \ post(this->size(), false);\n      ::std::vector<::std::size_t> prev(this->size(),\
    \ ::std::numeric_limits<::std::size_t>::max());\n      while (!stack.empty())\
    \ {\n        const auto [is_pre, here, from] = stack.top();\n        stack.pop();\n\
    \        if (post[here]) continue;\n\n        if (is_pre) {\n          prev[here]\
    \ = from;\n          if (pre[here]) {\n            ::std::vector<::std::size_t>\
    \ vids, eids({from});\n            for (::std::size_t v = this->m_edges[from].first;\
    \ v != here; v = this->m_edges[prev[v]].first) {\n              vids.push_back(v);\n\
    \              eids.push_back(prev[v]);\n            }\n            vids.push_back(here);\n\
    \            ::std::reverse(vids.begin(), vids.end());\n            ::std::reverse(eids.begin(),\
    \ eids.end());\n            return ::std::make_optional(::std::make_pair(vids,\
    \ eids));\n          }\n          pre[here] = true;\n          for (const auto\
    \ eid : this->m_graph[here]) {\n            stack.emplace(false, this->m_edges[eid].second,\
    \ eid);\n            stack.emplace(true, this->m_edges[eid].second, eid);\n  \
    \        }\n        } else {\n          post[here] = true;\n        }\n      }\n\
    \n      return ::std::nullopt;\n    }\n  };\n}\n\n\n"
  code: "#ifndef TOOLS_CYCLE_DETECTION_HPP\n#define TOOLS_CYCLE_DETECTION_HPP\n\n\
    #include <vector>\n#include <cstddef>\n#include <utility>\n#include <cassert>\n\
    #include <optional>\n#include <stack>\n#include <tuple>\n#include <limits>\n#include\
    \ <algorithm>\n\nnamespace tools {\n  class cycle_detection {\n  private:\n  \
    \  ::std::vector<::std::vector<::std::size_t>> m_graph;\n    ::std::vector<::std::pair<::std::size_t,\
    \ ::std::size_t>> m_edges;\n\n  public:\n    cycle_detection() = default;\n  \
    \  cycle_detection(const ::tools::cycle_detection&) = default;\n    cycle_detection(::tools::cycle_detection&&)\
    \ = default;\n    ~cycle_detection() = default;\n    ::tools::cycle_detection&\
    \ operator=(const ::tools::cycle_detection&) = default;\n    ::tools::cycle_detection&\
    \ operator=(::tools::cycle_detection&&) = default;\n\n    explicit cycle_detection(const\
    \ ::std::size_t n) :\n      m_graph(n) {\n    }\n\n    ::std::size_t size() const\
    \ {\n      return this->m_graph.size();\n    }\n\n    ::std::size_t add_edge(const\
    \ ::std::size_t u, const ::std::size_t v) {\n      assert(u < this->size());\n\
    \      assert(v < this->size());\n\n      this->m_graph[u].push_back(this->m_edges.size());\n\
    \      this->m_edges.emplace_back(u, v);\n      return this->m_edges.size() -\
    \ 1;\n    }\n\n    ::std::optional<::std::pair<::std::vector<::std::size_t>, ::std::vector<::std::size_t>>>\
    \ query() const {\n      ::std::stack<std::tuple<bool, ::std::size_t, ::std::size_t>>\
    \ stack;\n      for (::std::size_t v = 0; v < this->size(); ++v) {\n        stack.emplace(false,\
    \ v, ::std::numeric_limits<::std::size_t>::max());\n        stack.emplace(true,\
    \ v, ::std::numeric_limits<::std::size_t>::max());\n      }\n      ::std::vector<bool>\
    \ pre(this->size(), false);\n      ::std::vector<bool> post(this->size(), false);\n\
    \      ::std::vector<::std::size_t> prev(this->size(), ::std::numeric_limits<::std::size_t>::max());\n\
    \      while (!stack.empty()) {\n        const auto [is_pre, here, from] = stack.top();\n\
    \        stack.pop();\n        if (post[here]) continue;\n\n        if (is_pre)\
    \ {\n          prev[here] = from;\n          if (pre[here]) {\n            ::std::vector<::std::size_t>\
    \ vids, eids({from});\n            for (::std::size_t v = this->m_edges[from].first;\
    \ v != here; v = this->m_edges[prev[v]].first) {\n              vids.push_back(v);\n\
    \              eids.push_back(prev[v]);\n            }\n            vids.push_back(here);\n\
    \            ::std::reverse(vids.begin(), vids.end());\n            ::std::reverse(eids.begin(),\
    \ eids.end());\n            return ::std::make_optional(::std::make_pair(vids,\
    \ eids));\n          }\n          pre[here] = true;\n          for (const auto\
    \ eid : this->m_graph[here]) {\n            stack.emplace(false, this->m_edges[eid].second,\
    \ eid);\n            stack.emplace(true, this->m_edges[eid].second, eid);\n  \
    \        }\n        } else {\n          post[here] = true;\n        }\n      }\n\
    \n      return ::std::nullopt;\n    }\n  };\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/cycle_detection.hpp
  requiredBy: []
  timestamp: '2022-04-30 13:07:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/cycle_detection.test.cpp
documentation_of: tools/cycle_detection.hpp
layout: document
title: Cycle detection on a directed graph
---

It reports one of the cycles in a given directed graph if it exists.

## License
- CC0

## Author
- anqooqie

## Constructor
```cpp
cycle_detection graph(std::size_t n);
```

It creates a directed graph with $n$ vertices and $0$ edges.

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

It adds a directed edge from $u$ to $v$ to the graph, and returns the index of the added edge.

### Constraints
- $0 \leq u < n$
- $0 \leq v < n$

### Time Complexity
- $O(1)$ amortized

## query
```cpp
std::optional<std::pair<std::vector<std::size_t>, std::vector<std::size_t>>> graph.query();
```

It finds one of the cycles in a given directed graph.
If such the cycle does not exist, it returns `std::nullopt`.
If such the cycle exists, it returns the indices of the vertices which are contained in the cycle and the indices of the edges which are contained in the cycle.

### Constraints
- None

### Time Complexity
- $O(n)$
