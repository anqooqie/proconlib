---
title: Bellman-Ford algorithm
documentation_of: //tools/bellman_ford.hpp
---

It solves the single source shortest path problem on a given directed graph which is not necessarily simple.
The graph can have negative cycles.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
bellman_ford<T> graph(int n);
```

It creates a directed graph with $n$ vertices and $0$ edges.
The type parameter `<T>` represents the type of the cost.

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
int graph.add_edge(int u, int v, T w);
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
  int from;
  int to;
  T cost;
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
(1) std::vector<T> graph.query(int s);
(2) std::vector<T> graph.query<false>(int s);
(3) tools::shortest_path_tree<T, (anonymous type)> graph.query<true>(int s);
```

- (1), (2)
    - It is identical to `graph.query<true>(s).dist()`.
- (3)
    - It returns the answer to the single source shortest path problem from a source vertex $s$.

### Constraints
- $0 \leq s < n$

### Time Complexity
- $O(n\|E\|)$ where $\|E\|$ is the number of edges
