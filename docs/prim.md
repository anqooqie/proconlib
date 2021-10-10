---
title: Prim's algorithm
documentation_of: //tools/prim.hpp
---

It constructs a minimum spanning tree on a given undirected graph which is not necessarily simple based on Prim's algorithm.

### Usage
```cpp
tools::prim<int> prim(node_count);
prim.add_edge(from_node, to_node, cost);
const tools::prim<int>::result result = prim.query();
std::cout << result.total_distance << std::endl;
```

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
prim<T> prim(std::size_t n);
```

It creates an undirected graph with $n$ vertices and $0$ edges.
The type parameter `<T>` represents the type of the weight of edges.

### Constraints
- $n \geq 1$

### Time Complexity
- $O(n)$

## add_edge
```cpp
void prim.add_edge(std::size_t s, std::size_t t, T w);
```

It adds an undirected edge connecting $s$ and $t$ with the weight `w`.

### Constraints
- $0 \leq s < n$
- $0 \leq t < n$

### Time Complexity
- amortized $O(1)$

## query
```cpp
struct {
  T total_distance;
  std::vector<struct {
    std::size_t from();
    std::size_t to();
    T distance();
  }> edges;
} prim.query();
```

It constructs a minimum spanning tree on the graph.
`total_distance` represents the sum of weights of the minimum spanning tree.
`edges` represent the edges on the minimum spanning tree.

### Constraints
- The graph is connected

### Time Complexity
- $O((n + \|E\|) \log n)$ where $\|E\|$ is the number of edges
