---
title: Lowest common ancestor
documentation_of: //tools/lca.hpp
---

It is a data structure which can return the lowest common ancestor of two vertices in a given tree.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
lca lca(std::size_t n);
```

It creates a graph with $n$ vertices and $0$ edges.

### Constraints
- $n \geq 1$

### Time Complexity
- $O(n)$

## add_edge
```cpp
void lca.add_edge(std::size_t u, std::size_t v);
```

It adds an undirected edge connecting $u$ and $v$ to the graph.

### Constraints
- `lca.build()` has not been called ever.
- $0 \leq u < n$
- $0 \leq v < n$
- $u \neq v$

### Time Complexity
- $O(1)$ amortized

## build
```cpp
void lca.build(std::size_t r);
```

It internally creates a data structure which can return the lowest common ancestor of two vertices in the rooted tree whose root is $r$.

### Constraints
- `lca.build()` has not been called ever.
- The graph is a tree.
- $0 \leq r < n$

### Time Complexity
- $O(n)$

## depth
```cpp
std::size_t lca.depth(std::size_t v);
```

It returns the number of edges between $r$ and $v$.

### Constraints
- `lca.build()` has been called ever.
- $0 \leq v < n$

### Time Complexity
- $O(1)$

## query
```cpp
std::size_t lca.query(std::size_t u, std::size_t v);
```

It returns the lowest common ancestor of two vertices $u$ and $v$.

### Constraints
- `lca.build()` has been called ever.
- $0 \leq u < n$
- $0 \leq v < n$

### Time Complexity
- $O(1)$
