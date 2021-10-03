---
title: DP with rerooting
documentation_of: //tools/dp_with_rerooting.hpp
---

It is a dynamic programming on a tree with rerooting.

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

int f_ve(const int vertex, const int edge_weight) {
  return vertex + edge_weight;
}
int f_ev(const int edge, std::monostate) {
  return edge;
}

int main() {
  int n;
  std::cin >> n;

  tools::dp_with_rerooting<std::monostate, int, int, monoid, f_ve, f_ev> dp;
  for (int i = 0; i < n; ++i) {
    dp.add_vertex(std::monostate());
  }
  for (int i = 0; i < n - 1; ++i) {
    int s, t, w;
    std::cin >> s >> t >> w;
    dp.add_edge(s, t, w);
  }

  const std::vector<int> result = dp.query();
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
dp_with_rerooting<V, E, R, M, f_ve, f_ev> dp();
```

It creates an empty tree.
The meaning of each the type parameter is as follows.

- `V`
    - the type of vertex attributes
- `E`
    - the type of edge attributes
- `R`
    - the type of aggregated vertex attributes representing the vertex and the subtree far from that
- `M`
    - the commutative monoid on the type of aggregated edge attributes representing the edge and the subtree far from that
- `f_ve`
    - the function which convertes an aggregated vertex attribute and a edge attribute into an aggregated edge attribute
- `f_ev`
    - the function which converts an aggregated edge attribute and a vertex attribute into an aggregated vertex attribute

### Constraints
- For all $a$ in `typename M::T` and $b$ in `typename M::T`, `M::op(a, b)` $=$ `M::op(b, a)`.
- For all $a$ in `typename M::T`, $b$ in `typename M::T` and $c$ in `typename M::T`, `M::op(M::op(a, b), c)` $=$ `M::op(a, M::op(b, c))`.
- For all $a$ in `typename M::T`, `M::op(M::e(), a)` $=$ `M::op(a, M::e())` $=$ `M::e()`.
- `f_ve` is invocable.
- `f_ve` accepts two arguments, `R` and `E`.
- `f_ve` returns `typename M::T`.
- `f_ev` is invocable.
- `f_ev` accepts two arguments, `typename M::T` and `V`.
- `f_ev` returns `R`.

### Time Complexity
- $O(1)$

## add_vertex
```cpp
void dp.add_vertex(V v);
```

It adds a vertex whose attribute is $v$ to the tree.

### Constraints
- None

### Time Complexity
- Amortized $O(1)$

## add_edge
```cpp
void dp.add_edge(std::size_t s, std::size_t t, E e);
```

It adds an edge from $s$ to $t$ whose attribute is $e$ to the tree.

### Constraints
- $0 \leq s < N$ where $N$ is the number of vertices
- $0 \leq t < N$ where $N$ is the number of vertices

### Time Complexity
- Amortized $O(1)$

## size
```cpp
std::size_t dp.size();
```

It returns the number of vertices.

### Constraints
- None

### Time Complexity
- $O(1)$

## query
```cpp
std::vector<R> dp.query();
```

It returns aggregated vertex attributes.
The $i$-th element of the return value represents the rooted tree whose root is the vertex $i$.

### Constraints
- None

### Time Complexity
- $O(N)$ where $N$ is the number of vertices
