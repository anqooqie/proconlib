---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/zero_one_bfs.test.cpp
    title: tests/zero_one_bfs.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/zero_one_bfs.hpp\"\n\n\n\n#include <cstddef>\n#include\
    \ <vector>\n#include <limits>\n#include <cassert>\n#include <deque>\n\nnamespace\
    \ tools {\n\n  template <typename T>\n  class zero_one_bfs {\n  private:\n   \
    \ class edge {\n    public:\n      ::std::size_t from;\n      ::std::size_t to;\n\
    \      T distance;\n      edge(const ::std::size_t from, const ::std::size_t to,\
    \ const T distance) :\n        from(from),\n        to(to),\n        distance(distance)\
    \ {\n      }\n    };\n\n    ::std::vector<::std::vector<edge>> edges;\n\n  public:\n\
    \    static constexpr T INF = ::std::numeric_limits<T>::max();\n    static constexpr\
    \ ::std::size_t NONE = ::std::numeric_limits<::std::size_t>::max();\n\n    class\
    \ result {\n    public:\n      ::std::vector<T> distances;\n      ::std::vector<::std::size_t>\
    \ prev_nodes;\n      result(const ::std::size_t& node_count, const ::std::size_t&\
    \ start_node) :\n        distances(node_count, INF),\n        prev_nodes(node_count,\
    \ NONE) {\n        this->distances[start_node] = 0;\n      }\n    };\n\n    zero_one_bfs(const\
    \ ::std::size_t& node_count) :\n      edges(node_count) {\n    }\n\n    ::std::size_t\
    \ node_count() const {\n      return this->edges.size();\n    }\n\n    void add_edge(const\
    \ ::std::size_t& from, const ::std::size_t& to, const T& distance) {\n      assert(distance\
    \ == 0 || distance == 1);\n\n      this->edges[from].emplace_back(from, to, distance);\n\
    \    }\n\n    result query(const ::std::size_t& start_node) const {\n      assert(start_node\
    \ < this->node_count());\n\n      result result(this->node_count(), start_node);\n\
    \      ::std::vector<bool> visited(this->node_count(), false);\n      ::std::deque<::std::size_t>\
    \ deque;\n      deque.push_front(start_node);\n\n      while (!deque.empty())\
    \ {\n        const ::std::size_t vertex = deque.front();\n        deque.pop_front();\n\
    \        if (visited[vertex]) continue;\n        visited[vertex] = true;\n   \
    \     for (const edge& edge : this->edges[vertex]) {\n          const T new_distance\
    \ = result.distances[vertex] + edge.distance;\n          if (new_distance < result.distances[edge.to])\
    \ {\n            result.distances[edge.to] = new_distance;\n            result.prev_nodes[edge.to]\
    \ = edge.from;\n            if (edge.distance == 0) {\n              deque.push_front(edge.to);\n\
    \            } else {\n              deque.push_back(edge.to);\n            }\n\
    \          }\n        }\n      }\n\n      return result;\n    }\n  };\n}\n\n\n"
  code: "#ifndef TOOLS_ZERO_ONE_BFS_HPP\n#define TOOLS_ZERO_ONE_BFS_HPP\n\n#include\
    \ <cstddef>\n#include <vector>\n#include <limits>\n#include <cassert>\n#include\
    \ <deque>\n\nnamespace tools {\n\n  template <typename T>\n  class zero_one_bfs\
    \ {\n  private:\n    class edge {\n    public:\n      ::std::size_t from;\n  \
    \    ::std::size_t to;\n      T distance;\n      edge(const ::std::size_t from,\
    \ const ::std::size_t to, const T distance) :\n        from(from),\n        to(to),\n\
    \        distance(distance) {\n      }\n    };\n\n    ::std::vector<::std::vector<edge>>\
    \ edges;\n\n  public:\n    static constexpr T INF = ::std::numeric_limits<T>::max();\n\
    \    static constexpr ::std::size_t NONE = ::std::numeric_limits<::std::size_t>::max();\n\
    \n    class result {\n    public:\n      ::std::vector<T> distances;\n      ::std::vector<::std::size_t>\
    \ prev_nodes;\n      result(const ::std::size_t& node_count, const ::std::size_t&\
    \ start_node) :\n        distances(node_count, INF),\n        prev_nodes(node_count,\
    \ NONE) {\n        this->distances[start_node] = 0;\n      }\n    };\n\n    zero_one_bfs(const\
    \ ::std::size_t& node_count) :\n      edges(node_count) {\n    }\n\n    ::std::size_t\
    \ node_count() const {\n      return this->edges.size();\n    }\n\n    void add_edge(const\
    \ ::std::size_t& from, const ::std::size_t& to, const T& distance) {\n      assert(distance\
    \ == 0 || distance == 1);\n\n      this->edges[from].emplace_back(from, to, distance);\n\
    \    }\n\n    result query(const ::std::size_t& start_node) const {\n      assert(start_node\
    \ < this->node_count());\n\n      result result(this->node_count(), start_node);\n\
    \      ::std::vector<bool> visited(this->node_count(), false);\n      ::std::deque<::std::size_t>\
    \ deque;\n      deque.push_front(start_node);\n\n      while (!deque.empty())\
    \ {\n        const ::std::size_t vertex = deque.front();\n        deque.pop_front();\n\
    \        if (visited[vertex]) continue;\n        visited[vertex] = true;\n   \
    \     for (const edge& edge : this->edges[vertex]) {\n          const T new_distance\
    \ = result.distances[vertex] + edge.distance;\n          if (new_distance < result.distances[edge.to])\
    \ {\n            result.distances[edge.to] = new_distance;\n            result.prev_nodes[edge.to]\
    \ = edge.from;\n            if (edge.distance == 0) {\n              deque.push_front(edge.to);\n\
    \            } else {\n              deque.push_back(edge.to);\n            }\n\
    \          }\n        }\n      }\n\n      return result;\n    }\n  };\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/zero_one_bfs.hpp
  requiredBy: []
  timestamp: '2021-03-29 00:30:01+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/zero_one_bfs.test.cpp
documentation_of: tools/zero_one_bfs.hpp
layout: document
title: 01-BFS
---

It solves the single source shortest path problem on a given graph which is not necessarily simple.
All the edges must have $0$ or $1$ weight.

### Usage
```cpp
tools::zero_one_bfs<int> bfs(node_count);
bfs.add_edge(from_node, to_node, cost);
const tools::zero_one_bfs<int>::result result = bfs.query(start_node);
for (const int& distance : result.distances) {
  // ...
}
```

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
zero_one_bfs<T> bfs(::std::size_t n);
```

It creates a graph with $n$ vertices and $0$ edges.
The type parameter `<T>` represents the type of the weight of edges.

### Constraints
- $n \geq 1$

### Time Complexity
- $O(n)$

## add_edge
```cpp
void bfs.add_edge(::std::size_t s, ::std::size_t t, T w);
```

It adds a edge from $s$ to $t$ with the weight `w`.

### Constraints
- $0 \leq s < n$
- $0 \leq t < n$
- $w \in \\{0, 1\\}$

### Time Complexity
- amortized $O(1)$

## query
```cpp
struct {
  ::std::vector<T> distances;
  ::std::vector<::std::size_t> prev_nodes;
} bfs.query(::std::size_t s);
```

It solves the single source shortest path problem on the graph.
`distances[t]` represents the distance from $s$ to $t$.
`prev_nodes[t]` represents the previous vertex on the shortest path from $s$ to $t$.
`prev_nodes[s]` will be `std::numeric_limits<std::size_t>::max()` instead of the previous vertex since the previous vertex of $s$ does not exist.

### Constraints
- $0 \leq s < n$

### Time Complexity
- $O(n + \|E\|)$ where $\|E\|$ is the number of edges
