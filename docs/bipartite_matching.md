---
title: Matching on bipartite graph
documentation_of: //tools/bipartite_matching.hpp
---

It calculates the maximum matching on a given bipartite graph.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
bipartite_matching graph(std::size_t n1, std::size_t n2);
```

It creates an bipartite graph with $0$ edges.
Vertices of the graph can be divided into two disjoint and independent sets $U$ and $V$.
$U$ consists of $n_1$ vertices and $V$ consists of $n_2$ vertices.

### Constraints
- None

### Time Complexity
- $O(n_1 + n_2)$

## size1
```cpp
std::size_t graph.size1();
```

It returns $n_1$.

### Constraints
- None

### Time Complexity
- $O(1)$

## size2
```cpp
std::size_t graph.size2();
```

It returns $n_2$.

### Constraints
- None

### Time Complexity
- $O(1)$

## add_edge
```cpp
std::size_t graph.add_edge(std::size_t a, std::size_t b);
```

It adds an edge between $a \in U$ and $b \in V$.
It returns an integer $k$ such that this is the $k$-th edge that is added.

### Constraints
- $0 \leq a < n_1$
- $0 \leq b < n_2$

### Time Complexity
- $O(1)$ amortized

## get_edge
```cpp
struct edge {
  std::size_t id;
  std::size_t from;
  std::size_t to;
};
edge graph.get_edge(std::size_t k);
```

It returns the $k$-th edge.

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
std::vector<std::size_t> graph.query();
```

It returns the indices of the edges which can reach the maximum matching.

### Constraints
- None

### Time Complexity
- $O\left((n_1 + n_2)^\frac{3}{2} + \min\left((n_1 + n_2)^\frac{2}{3} m, m^\frac{3}{2}\right)\right)$ where $m$ is the number of edges
