---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/prim.hpp\"\n\n\n\n#include <cstddef>\n#include <vector>\n\
    #include <queue>\n#include <functional>\n#include <limits>\n\nnamespace tools\
    \ {\n\n  template <typename T>\n  class prim {\n  public:\n    class edge {\n\
    \    private:\n      ::std::size_t m_from;\n      ::std::size_t m_to;\n      T\
    \ m_distance;\n\n    public:\n      edge(const ::std::size_t& from, const ::std::size_t&\
    \ to, const T& distance) :\n        m_from(from),\n        m_to(to),\n       \
    \ m_distance(distance) {\n      }\n\n      ::std::size_t from() const {\n    \
    \    return this->m_from;\n      }\n      ::std::size_t to() const {\n       \
    \ return this->m_to;\n      }\n      T distance() const {\n        return this->m_distance;\n\
    \      }\n    };\n\n    class result {\n    public:\n      T total_distance;\n\
    \      ::std::vector<edge> edges;\n      result() :\n        total_distance(0),\
    \ edges() {\n      }\n    };\n\n    ::std::vector<::std::vector<edge>> edges;\n\
    \n    prim(const ::std::size_t& node_count) :\n      edges(node_count) {\n   \
    \ }\n\n    ::std::size_t node_count() const {\n      return this->edges.size();\n\
    \    }\n\n    void add_edge(const ::std::size_t& v1, const ::std::size_t& v2,\
    \ const T& distance) {\n      this->edges[v1].emplace_back(v1, v2, distance);\n\
    \      this->edges[v2].emplace_back(v2, v1, distance);\n    }\n\n    result query()\
    \ const {\n      result result;\n      ::std::vector<bool> visited(this->node_count(),\
    \ false);\n      const auto greater_by_distance = [](const edge& x, const edge&\
    \ y) {\n        return x.distance() > y.distance();\n      };\n      ::std::priority_queue<edge,\
    \ ::std::vector<edge>, decltype(greater_by_distance)> tasks(greater_by_distance);\n\
    \      tasks.emplace(::std::numeric_limits<::std::size_t>::max(), 0, 0);\n   \
    \   bool is_first_task = true;\n\n      while (!tasks.empty()) {\n        const\
    \ edge task = tasks.top();\n        tasks.pop();\n        if (visited[task.to()])\
    \ continue;\n        if (is_first_task) {\n          is_first_task = false;\n\
    \        } else {\n          result.total_distance += task.distance();\n     \
    \     result.edges.push_back(task);\n        }\n        visited[task.to()] = true;\n\
    \        for (const edge& edge : this->edges[task.to()]) {\n          if (!visited[edge.to()])\
    \ {\n            tasks.push(edge);\n          }\n        }\n      }\n\n      return\
    \ result;\n    }\n  };\n}\n\n\n"
  code: "#ifndef TOOLS_PRIM_HPP\n#define TOOLS_PRIM_HPP\n\n#include <cstddef>\n#include\
    \ <vector>\n#include <queue>\n#include <functional>\n#include <limits>\n\nnamespace\
    \ tools {\n\n  template <typename T>\n  class prim {\n  public:\n    class edge\
    \ {\n    private:\n      ::std::size_t m_from;\n      ::std::size_t m_to;\n  \
    \    T m_distance;\n\n    public:\n      edge(const ::std::size_t& from, const\
    \ ::std::size_t& to, const T& distance) :\n        m_from(from),\n        m_to(to),\n\
    \        m_distance(distance) {\n      }\n\n      ::std::size_t from() const {\n\
    \        return this->m_from;\n      }\n      ::std::size_t to() const {\n   \
    \     return this->m_to;\n      }\n      T distance() const {\n        return\
    \ this->m_distance;\n      }\n    };\n\n    class result {\n    public:\n    \
    \  T total_distance;\n      ::std::vector<edge> edges;\n      result() :\n   \
    \     total_distance(0), edges() {\n      }\n    };\n\n    ::std::vector<::std::vector<edge>>\
    \ edges;\n\n    prim(const ::std::size_t& node_count) :\n      edges(node_count)\
    \ {\n    }\n\n    ::std::size_t node_count() const {\n      return this->edges.size();\n\
    \    }\n\n    void add_edge(const ::std::size_t& v1, const ::std::size_t& v2,\
    \ const T& distance) {\n      this->edges[v1].emplace_back(v1, v2, distance);\n\
    \      this->edges[v2].emplace_back(v2, v1, distance);\n    }\n\n    result query()\
    \ const {\n      result result;\n      ::std::vector<bool> visited(this->node_count(),\
    \ false);\n      const auto greater_by_distance = [](const edge& x, const edge&\
    \ y) {\n        return x.distance() > y.distance();\n      };\n      ::std::priority_queue<edge,\
    \ ::std::vector<edge>, decltype(greater_by_distance)> tasks(greater_by_distance);\n\
    \      tasks.emplace(::std::numeric_limits<::std::size_t>::max(), 0, 0);\n   \
    \   bool is_first_task = true;\n\n      while (!tasks.empty()) {\n        const\
    \ edge task = tasks.top();\n        tasks.pop();\n        if (visited[task.to()])\
    \ continue;\n        if (is_first_task) {\n          is_first_task = false;\n\
    \        } else {\n          result.total_distance += task.distance();\n     \
    \     result.edges.push_back(task);\n        }\n        visited[task.to()] = true;\n\
    \        for (const edge& edge : this->edges[task.to()]) {\n          if (!visited[edge.to()])\
    \ {\n            tasks.push(edge);\n          }\n        }\n      }\n\n      return\
    \ result;\n    }\n  };\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/prim.hpp
  requiredBy: []
  timestamp: '2021-03-29 00:30:01+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tools/prim.hpp
layout: document
title: Prim's algorithm
---

It is Prim's algorithm.

## Usage
```cpp
tools::prim<int> prim(node_count);
prim.add_edge(from_node, to_node, cost);
const tools::prim<int>::result result = prim.query();
result.total_distance;
```

The type parameter `<T>` is the type of weight of edges.

## License
- CC0

## Author
- anqooqie
