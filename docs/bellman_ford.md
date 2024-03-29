---
title: Bellman-Ford algorithm
documentation_of: //tools/bellman_ford.hpp
---

It solves the single source shortest path problem on a given graph which is not necessarily simple.
The graph can have negative cycles.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
bellman_ford<T> graph(std::size_t n);
```

It creates a graph with $n$ vertices and $0$ edges.
The type parameter `<T>` represents the type of the cost.

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
std::size_t graph.add_edge(std::size_t u, std::size_t v, T w);
```

It adds an edge oriented from $u$ to $v$ with cost `w`.
It returns an integer $k$ such that this is the $k$-th ($0$ indexed) edge that is added.

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
const edge& graph.get_edge(std::size_t k);
```

It returns the $k$-th ($0$ indexed) edge.

### Constraints
- None

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
std::pair<std::vector<T>, std::vector<std::size_t>> graph.query(std::size_t s);
```

It solves the single source shortest path problem on the graph.
It returns two vectors `dist` and `prev`.
`dist[t]` represents the smallest value as the sum of the costs of the edges that make up the path from $s$ to $t$.
`prev[t]` represents the index of the edge from the parent of $t$ to $t$ in the shortest path tree rooted at $s$.
If $t = s$ or $t$ is unrechable from $s$, `prev[t]` is `std::numeric_limits<std::size_t>::max()`.

### Constraints
- $0 \leq s < n$

### Time Complexity
- $O(n\|E\|)$ where $\|E\|$ is the number of edges
