---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: tests/tsort.test.cpp
    title: tests/tsort.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/tsort.hpp\"\n\n\n\n#include <vector>\n#include <cstddef>\n\
    #line 7 \"tools/tsort.hpp\"\n#include <queue>\n\nnamespace tools {\n\n  class\
    \ tsort {\n  private:\n    ::std::vector<::std::vector<::std::size_t>> edges;\n\
    \n  public:\n    explicit tsort(const ::std::size_t node_count) : edges(node_count)\
    \ {\n    }\n\n    ::std::size_t node_count() const noexcept {\n      return this->edges.size();\n\
    \    }\n\n    void add_edge(const ::std::size_t s, const ::std::size_t t) {\n\
    \      this->edges[s].push_back(t);\n    }\n\n    template <typename OutputIterator>\n\
    \    void query(OutputIterator result) const {\n\n      ::std::vector<::std::size_t>\
    \ indegs(this->node_count(), 0);\n      for (::std::size_t s = 0; s < this->node_count();\
    \ ++s) {\n        for (const ::std::size_t t : this->edges[s]) {\n          ++indegs[t];\n\
    \        }\n      }\n\n      ::std::queue<::std::size_t> queue;\n      for (::std::size_t\
    \ v = 0; v < this->node_count(); ++v) {\n        if (indegs[v] == 0) {\n     \
    \     queue.push(v);\n        }\n      }\n\n      while (!queue.empty()) {\n \
    \       const ::std::size_t s = queue.front();\n        queue.pop();\n       \
    \ *result = s;\n        ++result;\n        for (const ::std::size_t t : edges[s])\
    \ {\n          --indegs[t];\n          if (indegs[t] == 0) {\n            queue.push(t);\n\
    \          }\n        }\n      }\n    }\n  };\n}\n\n\n"
  code: "#ifndef TOOLS_TSORT_HPP\n#define TOOLS_TSORT_HPP\n\n#include <vector>\n#include\
    \ <cstddef>\n#include <vector>\n#include <queue>\n\nnamespace tools {\n\n  class\
    \ tsort {\n  private:\n    ::std::vector<::std::vector<::std::size_t>> edges;\n\
    \n  public:\n    explicit tsort(const ::std::size_t node_count) : edges(node_count)\
    \ {\n    }\n\n    ::std::size_t node_count() const noexcept {\n      return this->edges.size();\n\
    \    }\n\n    void add_edge(const ::std::size_t s, const ::std::size_t t) {\n\
    \      this->edges[s].push_back(t);\n    }\n\n    template <typename OutputIterator>\n\
    \    void query(OutputIterator result) const {\n\n      ::std::vector<::std::size_t>\
    \ indegs(this->node_count(), 0);\n      for (::std::size_t s = 0; s < this->node_count();\
    \ ++s) {\n        for (const ::std::size_t t : this->edges[s]) {\n          ++indegs[t];\n\
    \        }\n      }\n\n      ::std::queue<::std::size_t> queue;\n      for (::std::size_t\
    \ v = 0; v < this->node_count(); ++v) {\n        if (indegs[v] == 0) {\n     \
    \     queue.push(v);\n        }\n      }\n\n      while (!queue.empty()) {\n \
    \       const ::std::size_t s = queue.front();\n        queue.pop();\n       \
    \ *result = s;\n        ++result;\n        for (const ::std::size_t t : edges[s])\
    \ {\n          --indegs[t];\n          if (indegs[t] == 0) {\n            queue.push(t);\n\
    \          }\n        }\n      }\n    }\n  };\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/tsort.hpp
  requiredBy: []
  timestamp: '2021-04-11 14:15:07+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - tests/tsort.test.cpp
documentation_of: tools/tsort.hpp
layout: document
title: Topological sorting
---

It is topological sorting.

## Usage
```cpp
tools::tsort tsort(node_count);
tsort.add_edge(from_node, to_node);
std::vector<i64> result;
tsort.query(std::back_inserter(result));
```

## License
- CC0

## Author
- anqooqie
