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
bipartite_matching graph(int n1, int n2);
```

It creates an bipartite graph with $0$ edges.
Vertices of the graph can be divided into two disjoint and independent sets $U$ and $V$.
$U$ consists of $n_1$ vertices and $V$ consists of $n_2$ vertices.

### Constraints
- $n_1 \geq 0$
- $n_2 \geq 0$

### Time Complexity
- $O(n_1 + n_2)$

## size1
```cpp
int graph.size1();
```

It returns $n_1$.

### Constraints
- None

### Time Complexity
- $O(1)$

## size2
```cpp
int graph.size2();
```

It returns $n_2$.

### Constraints
- None

### Time Complexity
- $O(1)$

## add_edge
```cpp
int graph.add_edge(int a, int b);
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
  int from;
  int to;
};
edge graph.get_edge(int k);
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
(1) int graph.query();
(2) int graph.query<false>();
(3) std::vector<int> graph.query<true>();
```

- (1), (2)
    - It returns the number of edges which can reach the maximum matching.
- (3)
    - It returns the indices of the edges which can reach the maximum matching.

### Constraints
- None

### Time Complexity
- $O\left((n_1 + n_2)^\frac{3}{2} + \min\left((n_1 + n_2)^\frac{2}{3} m, m^\frac{3}{2}\right)\right)$ where $m$ is the number of edges
