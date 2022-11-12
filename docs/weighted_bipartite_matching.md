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

If `maximize` is `true`, it will maximize the sum of weights of the matched edges.
If `maximize` is `false`, it will minimize the sum of weights of the matched edges.

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
  std::size_t id;
  std::size_t from;
  std::size_t to;
  W weight;
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
(1)
std::optional<std::pair<W, std::vector<std::size_t>>> graph.query(std::size_t k);

(2)
std::pair<W, std::vector<std::size_t>> graph.query();
```

- (1)
    - If `maximize` was `true`, it returns the followings when the number of matched edges is exactly $k$.
        - the maximum sum of weights of the matched edges
        - the matched edges which can reach the maxium sum of weights
    - If `maximize` was `false`, it returns the followings when the number of matched edges is exactly $k$.
        - the minimum sum of weights of the matched edges
        - the matched edges which can reach the minium sum of weights
    - Regardless of `maximize`, it returns `std::nullopt` if no matchings exist when the number of matched edges is exactly $k$.
- (2)
    - If `maximize` was `true`, it returns the followings. (No limitations on the number of matched edges)
        - the maximum sum of weights of the matched edges
        - the matched edges which can reach the maxium sum of weights
    - If `maximize` was `false`, it returns the followings. (No limitations on the number of matched edges)
        - the minimum sum of weights of the matched edges
        - the matched edges which can reach the minium sum of weights

### Constraints
- (1)
    - If you call it multiple times, `k` is greater than or equal to `k` in the last call of `query`.
- (2)
    - You can't call it multiple times.

### Time Complexity
- (1)
    - (First call): $O(\min(n_1, n_2, k) (n_1 + n_2 + m) \log (n_1 + n_2))$ where $m$ is the number of edges
    - (Second or later call): $O((\min(n_1, n_2, k) - k') (n_1 + n_2 + m) \log (n_1 + n_2))$ where $k'$ is `k` in the last call of `query` and $m$ is the number of edges
- (2)
    - $O(\min(n_1, n_2) (n_1 + n_2 + m) \log (n_1 + n_2))$ where $m$ is the number of edges
