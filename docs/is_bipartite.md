---
title: Check whether a given graph is bipartite
documentation_of: //tools/is_bipartite.hpp
---

It checks whether a given undirected graph is bipartite.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
is_bipartite graph(std::size_t n);
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

It adds an undirected edge between $u$ and $v$.
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
};
const edge& graph.get_edge(std::size_t k);
```

It returns the $k$-th ($0$ indexed) edge.

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
bool graph.query();
```

If the graph is bipartite, it returns `true`.
Otherwise, it returns `false`.

### Constraints
- None

### Time Complexity
- $O(n + \|E\|)$ where $\|E\|$ is the number of edges
