---
title: Dynamic programming on a tree with rerooting technique
documentation_of: //tools/rerooting_dp.hpp
---

It is an abstract framework for dynamic programming on a tree with rerooting technique.

### Example
It calculates the diameter of a given tree.

```cpp
struct monoid {
  using T = int;
  static T op(const T x, const T y) {
    return std::max(x, y);
  }
  static T e() {
    return 0;
  }
};

int main() {
  int n;
  std::cin >> n;

  std::vector<int> costs;
  const auto f_ve = [&](const int dist, const std::size_t edge_id) {
    return dist + costs[edge_id];
  };
  const auto f_ev = [](const int dist, std::size_t) {
    return dist;
  };

  tools::rerooting_dp<int, monoid, decltype(f_ve), decltype(f_ev)> graph(n, f_ve, f_ev);
  for (int i = 0; i < n - 1; ++i) {
    int s, t, w;
    std::cin >> s >> t >> w;
    graph.add_edge(s, t);
    costs.push_back(w);
  }

  const std::vector<int> result = graph.query();
  std::cout << *std::max_element(result.begin(), result.end()) << '\n';
  return 0;
}
```

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
rerooting_dp<R, M, F_VE, F_EV> graph(std::size_t n, F_VE f_ve, F_EV f_ev);
```

It creates a graph with $n$ vertices and $0$ edges.
The meaning of each the type parameter is as follows.

- `R`
    - the type of aggregated vertex attributes representing the vertex and the subtree far from that
- `M`
    - the commutative monoid on the type of aggregated edge attributes representing the edge and the subtree far from that
- `f_ve`
    - the function which accepts an aggregated vertex attribute and the index of the edge adjacent to the subtree, and returns the aggregated edge attribute
- `f_ev`
    - the function which accepts the product of aggregated edge attributes and the index of the vertex adjacent to the subtrees, and returns the aggregated vertex attribute

### Constraints
- `tools::commutative_monoid<M>` holds.
- `f_ve` is invocable.
- `f_ve` accepts two arguments, `R` and `std::size_t`.
- `f_ve` returns `typename M::T`.
- `f_ev` is invocable.
- `f_ev` accepts two arguments, `typename M::T` and `std::size_t`.
- `f_ev` returns `R`.

### Time Complexity
- $O(1)$

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

It adds an undirected edge between $u$ and $v$ to the graph.
It returns an integer $k$ such that this is the $k$-th edge that is added.

### Constraints
- $0 \leq u < n$
- $0 \leq v < n$

### Time Complexity
- $O(1)$ amortized

## query
```cpp
std::vector<R> graph.query();
```

It returns aggregated vertex attributes.
The $i$-th element of the return value represents the rooted tree whose root is the vertex $i$.

### Constraints
- The graph is a tree.

### Time Complexity
- $O(n)$
