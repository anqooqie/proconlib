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
cycle_detection<Directed> graph(int n);
```

It creates a graph with $n$ vertices and $0$ edges.
If `Directed` is `true`, the graph is directed.
If `Directed` is `false`, the graph is undirected.

### Constraints
- $n \geq 0$

### Time Complexity
- $O(n)$

## size
```cpp
int graph.size();
```

It returns $n$.

### Constraints
- None

### Time Complexity
- $O(1)$

## add_edge
```cpp
int graph.add_edge(int u, int v);
```

If `Directed` is `true`, it adds a directed edge oriented from $u$ to $v$.
If `Directed` is `false`, it adds an undirected edge between $u$ and $v$.
It returns an integer $k$ such that this is the $k$-th edge that is added.

### Constraints
- $0 \leq u < n$
- $0 \leq v < n$

### Time Complexity
- $O(1)$ amortized

## get_edge
```cpp
struct edge {
  int from;
  int to;
};
edge graph.get_edge(int k);
```

It returns the $k$-th ($0$ indexed) edge.

### Constraints
- $0 \leq k < \|E\|$ where $\|E\|$ is the number of edges

### Time Complexity
- $O(1)$

## edges
```cpp
std::vector<edge> graph.edges();
```

It returns all the edges in the graph.
The edges are ordered in the same order as added by `add_edge`.

### Constraints
- None

### Time Complexity
- $O(1)$

## query
```cpp
(1) bool graph.query();
(2) bool graph.query<false>();
(3) std::optional<std::pair<std::vector<int>, std::vector<int>>> graph.query<true>();
```

- (1), (2)
    - It returns whether any cycles exist in a given graph.
- (3)
    - It finds one of the cycles in a given graph.
    - If such the cycle does not exist, it returns `std::nullopt`.
    - If such the cycle exists, it returns the indices of the vertices which are contained in the cycle and the indices of the edges which are contained in the cycle.

### Constraints
- None

### Time Complexity
- $O(n)$
