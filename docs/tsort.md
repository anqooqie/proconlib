---
title: Topological sorting
documentation_of: //tools/tsort.hpp
---

It is a class about topological sorting.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
tsort graph(int n);
```

It creates a directed graph with $n$ vertices and $0$ edges.

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

It adds a directed edge oriented from $u$ to $v$.
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
std::vector<int> graph.query();
```

Topological sorting is a linear ordering of vertices such that for every directed edge from $u$ to $v$, vertex $u$ comes before $v$ in the ordering.
It returns one of the topological sortings for the graph.

### Constraints
- The graph is a DAG.

### Time Complexity
- $O(n)$

## count
```cpp
template <typename R = long long>
R graph.count();
```

It returns the number of the topological sortings for the graph.

### Constraints
- $n < 32$

### Time Complexity
- $O(2^n n)$
