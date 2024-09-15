---
title: Auxiliary tree
documentation_of: //tools/auxiliary_tree.hpp
---

It is an auxiliary tree obtained by compressing a tree so that LCA relations of specified vertices are preserved.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
auxiliary_tree graph(std::size_t n);
```

It creates a graph with $n$ vertices and $0$ edges.

### Constraints
- $n \geq 1$

### Time Complexity
- $O(n)$

## add_edge
```cpp
void graph.add_edge(std::size_t u, std::size_t v);
```

It adds an undirected edge connecting $u$ and $v$ to the graph.

### Constraints
- `graph.build()` has not been called ever.
- $0 \leq u < n$
- $0 \leq v < n$
- $u \neq v$

### Time Complexity
- $O(1)$ amortized

## build
```cpp
void graph.build(std::size_t r);
```

It asserts that the graph is a rooted tree with root $r$.

### Constraints
- `graph.build()` has not been called ever.
- The graph is a tree.
- $0 \leq r < n$

### Time Complexity
- $O(n)$

## depth
```cpp
std::size_t graph.depth(std::size_t v);
```

It returns the number of edges between $r$ and $v$.

### Constraints
- `graph.build()` has been called ever.
- $0 \leq v < n$

### Time Complexity
- $O(1)$

## lca
```cpp
std::size_t graph.lca(std::size_t u, std::size_t v);
```

It returns the lowest common ancestor of two vertices $u$ and $v$.

### Constraints
- `graph.build()` has been called ever.
- $0 \leq u < n$
- $0 \leq v < n$

### Time Complexity
- $O(1)$

## query
```cpp
template <typename InputIterator>
query_result graph.query(InputIterator begin, InputIterator end);

template <typename Z>
query_result graph.query(std::vector<Z> X);
```

For a given rooted tree $T = (V, E; r)$ and a subset of its vertices $X \subseteq V$, it returns an auxiliary rooted tree $T'$ that can be obtained by compressing $T$ so that no descendant/ancestor relationship or least common ancestor relationship is lost between the vertices in $X$.
More precisely, for each vertex pair $(x, y) \in X^2$, we consider its least common ancestor $z = \mathrm{lca}(x, y)$.
The rooted tree $T' = (V', E'; r')$ is the one formed by edging such vertices $V' = \\{\mathrm{lca}(x, y) \mid (x, y) \in X^2\\}$ with descendant relations in the original tree $T$.

### Constraints
- `graph.build()` has been called ever.
- $X$ is a set of integers.
- $X \subseteq V$
- $X \neq \varnothing$

### Time Complexity
- $O(\|X\| \log \|X\|)$

## query_result::size
```cpp
std::size_t qr.size();
```

It returns $\|X'\|$.

### Constraints
- None

### Time Complexity
- $O(1)$

## query_result::vertices
```cpp
struct vertices_iterable {
  struct iterator {
    std::size_t operator*();
    iterator& operator++();
    iterator operator++(int):
    friend bool operator==(iterator lhs, iterator rhs);
    friend bool operator!=(iterator lhs, iterator rhs);
  };
  iterator begin();
  iterator end();
};
vertices_iterable qr.vertices();
```

It returns $X'$.

### Constraints
- None

### Time Complexity
- $O(1)$

## query_result::root
```cpp
std::size_t qr.root();
```

It returns $r'$.

### Constraints
- None

### Time Complexity
- $O(1)$

## query_result::parent
```cpp
std::size_t qr.parent(std::size_t v);
```

It returns the parent of $v$ in $T'$.

### Constraints
- $v \in X'$
- $v \neq r'$

### Time Complexity
- $O(\log \|X\|)$

## query_result::children
```cpp
const std::vector<std::size_t>& qr.children(std::size_t v);
```

It returns the children of $v$ in $T'$.

### Constraints
- $v \in X'$

### Time Complexity
- $O(\log \|X\|)$
