---
title: Traveling salesman problem
documentation_of: //tools/tsp.hpp
---

It solves the traveling salesman problem.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
template <bool Directed, tools::integral T>
tsp<Directed, T> graph(int n);
```

It creates a graph which is not necessarily simple with $n$ vertices and $0$ edges.
If `Directed` is `true`, the graph is directed.
If `Directed` is `false`, the graph is undirected.

### Constraints
- $n \geq 2$

### Time Complexity
- $O(n^2)$

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

If `Directed` is `true`, it adds a directed edge oriented from $u$ to $v$ with cost $w$.
If `Directed` is `false`, it adds an undirected edge between $u$ and $v$ with cost $w$.
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
  T cost;
};
const edge& graph.get_edge(int k);
```

It returns the $k$-th edge.

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
(1) std::optional<T> graph.query();
(2) std::optional<T> graph.query<false>();
(3) std::optional<std::tuple<T, std::vector<int>, std::vector<int>>> graph.query<true>();
```

It finds the shortest Hamilton cycle.
If such the cycle does not exist, it returns `std::nullopt`.
If such the cycle exists, let $v_0, v_1, \ldots, v_{n-1}$ be the vertices and $e_0, e_1, \ldots, e_{n-1}$ be the edges of the cycle such that $e_i$ connects $v_i$ and $v_{(i+1) \bmod n}$ (or is oriented from $v_i$ to $v_{(i+1) \bmod n}$ if the graph is directed).
It returns:

- (1), (2)
    - the total cost of the cycle
- (3)
    - the total cost of the cycle
    - $(v_0, v_1, \ldots, v_{n-1})$
    - $(e_0, e_1, \ldots, e_{n-1})$

### Constraints
- None

### Time Complexity
- $O(2^n n^2)$
