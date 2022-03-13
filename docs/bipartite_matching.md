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
bipartite_matching<E> graph(std::size_t n1, std::size_t n2);
```

It creates an bipartite graph with $0$ edges.
Vertices of the graph can be divided into two disjoint and independent sets $U$ and $V$.
$U$ consists of $n_1$ vertices and $V$ consists of $n_2$ vertices.

The type parameter `<E>` represents the type of the attribute of edges.

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
void graph.add_edge(std::size_t a, std::size_t b, E e);
```

It adds an edge connecting $a \in U$ and $b \in V$ with the attribute `e`.

### Constraints
- $0 \leq a < n_1$
- $0 \leq b < n_2$

### Time Complexity
- amortized $O(1)$

## query
```cpp
std::vector<struct {
  std::size_t from;
  std::size_t to;
  E attribute;
}> graph.query();
```

It returns the edges which can reach the maximum matching. 

### Constraints
- None

### Time Complexity
- $O\left((n_1 + n_2)^\frac{3}{2} + \min\left((n_1 + n_2)^\frac{2}{3} m, m^\frac{3}{2}\right)\right)$ where $m$ is the number of edges
