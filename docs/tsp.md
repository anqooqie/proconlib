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
tsp<Directed> graph(std::size_t n);
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
  std::size_t id;
  std::size_t from;
  std::size_t to;
  T cost;
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
std::optional<std::tuple<T, std::vector<std::size_t>, std::vector<::std::size_t>>> graph.query();
```

It finds the shortest Hamilton cycle.
If such the cycle does not exist, it returns `std::nullopt`.
If such the cycle exists, it returns the total cost of the cycle, the indices of the vertices which are contained in the cycle and the indices of the edges which are contained in the cycle.

### Constraints
- None

### Time Complexity
- $O(2^n n^2)$
