---
title: Matching on weighted bipartite graph
documentation_of: //tools/weighted_bipartite_matching.hpp
---

It calculates the maximum or minimum matching on a given weighted bipartite graph.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
weighted_bipartite_matching<W> graph(std::size_t n1, std::size_t n2, bool maximize);
```

It creates a weighted bipartite graph with $0$ edges.
Vertices of the graph can be divided into two disjoint and independent sets $U$ and $V$.
$U$ consists of $n_1$ vertices and $V$ consists of $n_2$ vertices.

If `maximize` is `true`, it will maximize the number of matched edges, and then, maximize the sum of weights of the matched edges.
If `maximize` is `false`, it will maximize the number of matched edges, and then, minimize the sum of weights of the matched edges.

The type parameter `<W>` represents the type of weights.

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
std::size_t graph.add_edge(std::size_t a, std::size_t b, W w);
```

It adds an edge connecting $a \in U$ and $b \in V$ with the weight `w` and the attribute `e`, and returns the index of the added edge.

### Constraints
- $0 \leq a < n_1$
- $0 \leq b < n_2$

### Time Complexity
- amortized $O(1)$

## query
```cpp
std::pair<W, std::vector<struct {
  std::size_t id;
  std::size_t from;
  std::size_t to;
  W weight;
}>> graph.query();
```

If `maximize` was `true`, it returns the matched edges which can maximize the number of matched edges, and then maximize the sum of weights of the matched edges, as the second element.
Also, it returns the sum of weights of the matched edges as the first element.

If `maximize` was `false`, it returns the matched edges which can maximize the number of matched edges, and then minimize the sum of weights of the matched edges, as the second element.
Also, it returns the sum of weights of the matched edges as the first element.

### Constraints
- None

### Time Complexity
- $O(\min(n_1, n_2) (n_1 + n_2 + m) \log (n_1 + n_2))$ where $m$ is the number of edges
