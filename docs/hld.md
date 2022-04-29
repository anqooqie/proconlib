---
title: Heavy-light decomposition
documentation_of: //tools/hld.hpp
---

It takes a tree with $n$ vertices as input.
As a preprecessing, it remaps its vertex indices to dfs-ordered ones and its edge indices to dfs-ordered ones.
Given a path from $u$ to $v$, it returns some intervals of the dfs-ordered vertex indices, or some intervals of the dfs-ordered edge indices representing the path.
It is guaranteed that the number of the intervals is $O(\log n)$.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
hld hld(std::size_t n);
```

It creates a graph with $n$ vertices and $0$ edges.

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

## add_edge
```cpp
void hld.add_edge(std::size_t u, std::size_t v);
```

It adds an undirected edge connecting $u$ and $v$ to the graph.

### Constraints
- Neither `hld.build()` nor `hld.build(std::size_t)` has not been called ever.
- $0 \leq u < n$
- $0 \leq v < n$

### Time Complexity
- $O(1)$ amortized

## build
```cpp
void hld.build(std::size_t r = 0);
```

It remaps the vertex indices in the tree to dfs-ordered ones and the edge indices in the tree to dfs-ordered ones.
In DFS, the root is $r$.

### Constraints
- Neither `hld.build()` nor `hld.build(std::size_t)` has not been called ever.
- The graph is a tree.
- $0 \leq r < n$

### Time Complexity
- $O(n)$

## vid2dfs
```cpp
const std::vector<std::size_t>& hld.vid2dfs();
```

It returns the mapping from the original vertex indices to the dfs-ordered vertex indices.

### Constraints
- Either `hld.build()` or `hld.build(std::size_t)` has been called ever.

### Time Complexity
- $O(1)$

## dfs2vid
```cpp
const std::vector<std::size_t>& hld.dfs2vid();
```

It returns the mapping from the dfs-ordered vertex indices to the original vertex indices.

### Constraints
- Either `hld.build()` or `hld.build(std::size_t)` has been called ever.

### Time Complexity
- $O(1)$

## eid2dfs
```cpp
const std::vector<std::size_t>& hld.eid2dfs();
```

It returns the mapping from the original edge indices to the dfs-ordered edge indices.

### Constraints
- Either `hld.build()` or `hld.build(std::size_t)` has been called ever.

### Time Complexity
- $O(1)$

## dfs2eid
```cpp
const std::vector<std::size_t>& hld.dfs2eid();
```

It returns the mapping from the dfs-ordered edge indices to the original edge indices.

### Constraints
- Either `hld.build()` or `hld.build(std::size_t)` has been called ever.

### Time Complexity
- $O(1)$

## vquery
```cpp
std::vector<std::pair<std::size_t, std::size_t>> hld.vquery(std::size_t u, std::size_t v);
```

Given a path from $u$ to $v$, it returns some intervals of the dfs-ordered vertex indices representing the path.
It is guaranteed that the number of the intervals is $O(\log n)$.

### Constraints
- Either `hld.build()` or `hld.build(std::size_t)` has been called ever.
- $0 \leq u < n$
- $0 \leq v < n$

### Time Complexity
- $O(\log n)$

## equery
```cpp
std::vector<std::pair<std::size_t, std::size_t>> hld.equery(std::size_t u, std::size_t v);
```

Given a path from $u$ to $v$, it returns some intervals of the dfs-ordered edge indices representing the path.
It is guaranteed that the number of the intervals is $O(\log n)$.

### Constraints
- Either `hld.build()` or `hld.build(std::size_t)` has been called ever.
- $0 \leq u < n$
- $0 \leq v < n$

### Time Complexity
- $O(\log n)$
