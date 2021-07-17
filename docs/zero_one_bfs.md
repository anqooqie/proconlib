---
title: 01-BFS
documentation_of: //tools/zero_one_bfs.hpp
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
