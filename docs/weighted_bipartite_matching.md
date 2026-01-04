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
template <bool Maximize, typename W>
requires std::same_as<W, int> || std::same_as<W, long long>
weighted_bipartite_matching<W> graph(int n1, int n2);
```

It creates a weighted bipartite graph with $0$ edges.
Vertices of the graph can be divided into two disjoint and independent sets $U$ and $V$.
$U$ consists of $n_1$ vertices and $V$ consists of $n_2$ vertices.

If `Maximize` is `true`, it will maximize the sum of weights of the matched edges.
If `Maximize` is `false`, it will minimize the sum of weights of the matched edges.

The type parameter `<W>` represents the type of weights.

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
int graph.add_edge(int a, int b, W w);
```

It adds an edge connecting $a \in U$ and $b \in V$ with the weight `w`.
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
  W weight;
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
(1) std::optional<W> graph.query(int k);
(2) std::optional<W> graph.query<false>(int k);
(3) std::optional<std::vector<int>> graph.query<true>(int k);
(4) W graph.query();
(5) W graph.query<false>();
(6) std::vector<int> graph.query<true>();
```

- (1), (2)
    - If `Maximize` is `true`, it returns the maximum sum of weights of the matched edges when the number of matched edges is exactly $k$.
    - If `Maximize` is `false`, it returns the minimum sum of weights of the matched edges when the number of matched edges is exactly $k$.
    - Regardless of `Maximize`, it returns `std::nullopt` if no matchings exist when the number of matched edges is exactly $k$.
- (3)
    - If `Maximize` is `true`, it returns the matched edges which can reach the maximum sum of weights when the number of matched edges is exactly $k$.
    - If `Maximize` is `false`, it returns the matched edges which can reach the minimum sum of weights when the number of matched edges is exactly $k$.
    - Regardless of `Maximize`, it returns `std::nullopt` if no matchings exist when the number of matched edges is exactly $k$.
- (4), (5)
    - If `Maximize` is `true`, it returns the maximum sum of weights of the matched edges. (No limitations on the number of matched edges)
    - If `Maximize` is `false`, it returns the minimum sum of weights of the matched edges. (No limitations on the number of matched edges)
- (6)
    - If `Maximize` is `true`, it returns the matched edges which can reach the maximum sum of weights. (No limitations on the number of matched edges)
    - If `Maximize` is `false`, it returns the matched edges which can reach the minimum sum of weights. (No limitations on the number of matched edges)

### Constraints
- (1), (2), (3)
    - If you call it multiple times, `k` is greater than or equal to `k` in the last call of `query`.
- (4), (5), (6)
    - You can't call it multiple times.

### Time Complexity
- (1), (2), (3)
    - (First call): $O(\min(n_1, n_2, k) (n_1 + n_2 + m) \log (n_1 + n_2))$ where $m$ is the number of edges
    - (Second or later call): $O((\min(n_1, n_2, k) - k') (n_1 + n_2 + m) \log (n_1 + n_2))$ where $k'$ is `k` in the last call of `query` and $m$ is the number of edges
- (4), (5), (6)
    - $O(\min(n_1, n_2) (n_1 + n_2 + m) \log (n_1 + n_2))$ where $m$ is the number of edges
