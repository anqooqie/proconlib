---
title: Strongly connected component decomposition
documentation_of: //tools/scc_graph.hpp
---

It takes a directed graph with $n$ vertices as input, and decomposes the graph into strongly connected components.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
scc_graph graph(std::size_t n);
```

It creates a directed graph with $n$ vertices and $0$ edges.

### Constraints
- $n \geq 0$

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

It adds a directed edge from $u$ to $v$ to the graph, and returns the index of the added edge.

### Constraints
- `graph.build()` has not been called ever.
- $0 \leq u < n$
- $0 \leq v < n$

### Time Complexity
- $O(1)$ amortized

## edge
```cpp
std::pair<std::size_t, std::size_t> graph.edge(std::size_t i);
```

It returns the source and destination of the $i$-th edge of the graph.

### Constraints
- $0 \leq i < m$ where $m$ is the number of edges

### Time Complexity
- $O(1)$

## edges_from
```cpp
const std::vector<std::size_t>& graph.edges_from(std::size_t v);
```

It returns the indices of the edges from the vertex $v$.

### Constraints
- $0 \leq v < n$

### Time Complexity
- $O(1)$

## edges_to
```cpp
const std::vector<std::size_t>& graph.edges_to(std::size_t v);
```

It returns the indices of the edges to the vertex $v$.

### Constraints
- $0 \leq v < n$

### Time Complexity
- $O(1)$

## build
```cpp
void graph.build();
```

It decomposes the graph into strongly connected components.

### Constraints
- `graph.build()` has not been called ever.

### Time Complexity
- $O(n + m \log m)$ where $m$ is the number of edges

## scc_id
```cpp
std::size_t graph.scc_id(std::size_t v);
```

It returns the index of the strongly connected components which contains the vertex $v$.

### Constraints
- `graph.build()` has been called ever.
- $0 \leq v < n$

### Time Complexity
- $O(1)$

## sccs
```cpp
const std::vector<std::vector<std::size_t>>& graph.sccs();
```

It returns the list of the "list of the vertices" that satisfies the following.

- Each vertex is in exactly one "list of the vertices".
- Each "list of the vertices" corresponds to the vertex set of a strongly connected component. The order of the vertices in the list is undefined.
- The list of "list of the vertices" are sorted in topological order, i.e., for two vertices $u, v$ in different strongly connected components, if there is a directed path from $u$ to $v$, the list contains $u$ appears earlier than the list contains $v$.

### Constraints
- `graph.build()` has been called ever.

### Time Complexity
- $O(1)$

## edges_in_scc
```cpp
const std::vector<std::size_t>& graph.edges_in_scc(std::size_t x);
```

Let $E$ be the edges whose source is a vertex in the $x$-th strongly connected component and destination is a vertex in the $x$-th strongly connected component.
It returns $E$.

### Constraints
- `graph.build()` has been called ever.
- $0 \leq x < $ `graph.sccs().size()`

### Time Complexity
- $O(1)$

## edges_from_scc
```cpp
const std::vector<std::pair<std::size_t, std::vector<std::size_t>>>& graph.edges_from_scc(std::size_t x);
```

Let $E$ be the edges whose source is a vertex in the $x$-th strongly connected component and destination is a vertex not in the $x$-th strongly connected component.
It groups $E$ by the strongly connected component which contains the destination, and returns the list of the groups.

### Constraints
- `graph.build()` has been called ever.
- $0 \leq x < $ `graph.sccs().size()`

### Time Complexity
- $O(1)$

## edges_to_scc
```cpp
const std::vector<std::pair<std::size_t, std::vector<std::size_t>>>& graph.edges_to_scc(std::size_t x);
```

Let $E$ be the edges whose source is a vertex not in the $x$-th strongly connected component and destination is a vertex in the $x$-th strongly connected component.
It groups $E$ by the strongly connected component which contains the source, and returns the list of the groups.

### Constraints
- `graph.build()` has been called ever.
- $0 \leq x < $ `graph.sccs().size()`

### Time Complexity
- $O(1)$
