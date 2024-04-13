---
title: Cycle detection on a graph
documentation_of: //tools/cycle_detection.hpp
---

It reports one of the cycles in a given graph if it exists.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
cycle_detection<DIRECTED> graph(std::size_t n);
```

It creates a graph with $n$ vertices and $0$ edges.
If `DIRECTED` is `true`, the graph is directed.
If `DIRECTED` is `false`, the graph is undirected.

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

If `DIRECTED` is `true`, it adds a directed edge oriented from $u$ to $v$.
If `DIRECTED` is `false`, it adds an undirected edge between $u$ and $v$.
It returns an integer $k$ such that this is the $k$-th edge that is added.

### Constraints
- $0 \leq u < n$
- $0 \leq v < n$

### Time Complexity
- $O(1)$ amortized

## query
```cpp
std::optional<std::pair<std::vector<std::size_t>, std::vector<std::size_t>>> graph.query();
```

It finds one of the cycles in a given graph.
If such the cycle does not exist, it returns `std::nullopt`.
If such the cycle exists, it returns the indices of the vertices which are contained in the cycle and the indices of the edges which are contained in the cycle.

### Constraints
- None

### Time Complexity
- $O(n)$
