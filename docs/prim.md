---
title: Prim's algorithm
documentation_of: //tools/prim.hpp
---

It constructs a minimum spanning forest on a given undirected graph which is not necessarily simple based on Prim's algorithm.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
prim<T> graph(std::size_t n);
```

It creates an undirected graph with $n$ vertices and $0$ edges.
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
void graph.add_edge(std::size_t u, std::size_t v, T w);
```

It adds an undirected edge between $u$ and $v$ with cost `w`.
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
const edge& graph.get_edge(std::size_t k);
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
std::pair<std::vector<std::pair<T, std::vector<std::size_t>>>, std::vector<std::size_t>> graph.query();
```

It constructs a minimum spanning forest on the graph, and returns the information about the minimum spanning forest in the following layout.

```
(
  [
    (
      total cost of the 0th MST,
      [
        index of an edge in the 0th MST,
        index of another edge in the 0th MST,
        ...
      ]
    ),
    (
      total cost of the 1st MST,
      [
        index of an edge in the 1st MST,
        index of another edge in the 1st MST,
        ...
      ]
    ),
    (
      total cost of the 2nd MST,
      [
        index of an edge in the 2nd MST,
        index of another edge in the 2nd MST,
        ...
      ]
    ),
    ...
  ],
  [
    index of the MST which contains the 0th vertex,
    index of the MST which contains the 1st vertex,
    index of the MST which contains the 2nd vertex,
    ...
  ]
)
```

### Constraints
- None

### Time Complexity
- $O((n + \|E\|) \log n)$ where $\|E\|$ is the number of edges
