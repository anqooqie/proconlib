---
title: Minimum Steiner tree
documentation_of: //tools/minimum_steiner_tree.hpp
---

It returns one of the minimum Steiner trees in $O(3^k n + 2^k (n + m) \log n)$ time given an undirected graph $G = (V, E)$ consisting of $n$ vertices and $m$ edges with non-negative edge weights, and a subset $S$ of $V$ consisting of $k$ vertices.
The minimum Steiner tree is the Steiner tree with the smallest sum of edge weights.
A Steiner tree is a tree $T = (V', E')$ that satisfies $S \subseteq V' \subseteq V$ and $E' \subseteq E$.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
minimum_steiner_tree<Cost> graph(int n);
```

It creates an undirected graph with $n$ vertices and $0$ edges.
The type parameter `<Cost>` represents the type of the edge weights.

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
int graph.add_edge(int u, int v, Cost w);
```

It adds an undirected edge between $u$ and $v$ with cost $w$.
It returns the total number of edges at the point just before calling the `add_edge` function.

### Constraints
- $0 \leq u < n$
- $0 \leq v < n$
- $w \geq 0$

### Time Complexity
- $O(1)$ amortized

## get_edge
```cpp
struct edge {
  int from;
  int to;
  Cost cost;
};
const edge& graph.get_edge(int i);
```

It returns information about the edge for which the return value of the `add_edge` function was $i$.

### Constraints
- $0 \leq i < m$ where $m$ is the current number of edges

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
(1)
Cost graph.query(std::ranges::range S);

(2)
Cost graph.query<false>(std::ranges::range S);

(3)
struct query_result {
  Cost cost;
  std::vector<int> vertices;
  std::vector<int> edge_ids;
};
query_result graph.query<true>(std::ranges::range S);
```

Given a subset $S$ of $V$ consisting of $k$ vertices, it returns one of the minimum Steiner trees $T = (V', E')$ if it exists.

- (1)
    - If $k > 0$ and a minimum Steiner tree exists, it returns the sum of the edge weights of $E'$.
    - If $k > 0$ and no minimum Steiner tree exists, it returns `std::numeric_limits<Cost>::max()`.
    - If $k = 0$, it returns $0$.
- (2)
    - It is identical to (1).
- (3)
    - `cost` is the same as the return value of (1).
    - If $k > 0$ and a minimum Steiner tree exists:
        - `vertices` is $V'$.
        - `edge_ids` is $E'$. Each element is an integer that identifies an edge and can be passed as an argument to `get_edge`.
    - Otherwise:
        - `vertices` is empty.
        - `edge_ids` is empty.

### Constraints
- $S$ is a set of integers.
- $S \subseteq V$

### Time Complexity
- $O(3^k n + 2^k (n + m) \log n)$
