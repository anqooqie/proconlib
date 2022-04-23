---
title: Heavy-light decomposition
documentation_of: //tools/hld.hpp
---

As a preprecessing, it takes a tree with $n$ vertices as input, and assigns a dfs-ordered index to each vertex in the tree.
Given a path from $u$ to $v$, it can return some intervals of the dfs-ordered indices.
It is guaranteed that the number of the intervals is $O(\log n)$.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
hld hld(std::size_t n);
```

It creates a buffer for a tree with $n$ vertices.

### Constraints
- $n \geq 1$

### Time Complexity
- $O(n)$

## size
```cpp
std::size_t hld.size();
```

It returns $n$.

### Constraints
- None

### Time Complexity
- $O(1)$

## idx2dfs
```cpp
const std::vector<std::size_t>& hld.idx2dfs();
```

It returns the mapping from vertex indices to dfs-ordered indices.

### Constraints
- None

### Time Complexity
- $O(1)$

## dfs2idx
```cpp
const std::vector<std::size_t>& hld.dfs2idx();
```

It returns the mapping from dfs-ordered indices to vertex indices.

### Constraints
- None

### Time Complexity
- $O(1)$

## add_edge
```cpp
void hld.add_edge(std::size_t u, std::size_t v);
```

It adds an undirected edge connecting $u$ and $v$ to the tree.

### Constraints
- $0 \leq u < n$
- $0 \leq v < n$

### Time Complexity
- $O(1)$ amortized

## build
```cpp
void hld.build(std::size_t r = 0);
```

It assigns a dfs-ordered index to each vertex in the tree.
The root is $r$.

### Constraints
- $0 \leq r < n$

### Time Complexity
- $O(n)$

## query
```cpp
std::vector<std::pair<std::size_t, std::size_t>> hld.query(std::size_t u, std::size_t v);
```

Given a path from $u$ to $v$, it returns some intervals of the dfs-ordered indices.
It is guaranteed that the number of the intervals is $O(\log n)$.

### Constraints
- $0 \leq u < n$
- $0 \leq v < n$

### Time Complexity
- $O(\log n)$
