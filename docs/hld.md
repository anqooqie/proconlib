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

## vparent
```cpp
::std::size_t hld.vparent(std::size_t v);
```

Given a vertex $v$ by the original vertex index, it returns the original vertex index of the parent of the vertex.

### Constraints
- Either `hld.build()` or `hld.build(std::size_t)` has been called ever.
- $0 \leq v < n$
- $v$ is not the root.

### Time Complexity
- $O(1)$

## eparent
```cpp
::std::size_t hld.eparent(std::size_t v);
```

Given a vertex $v$ by the original vertex index, it returns the original edge index of the edge between the vertex and the parent of the vertex.

### Constraints
- Either `hld.build()` or `hld.build(std::size_t)` has been called ever.
- $0 \leq v < n$
- $v$ is not the root.

### Time Complexity
- $O(1)$

## vchildren
```cpp
struct {
  struct iterator {
    std::size_t operator*();
    iterator& operator++();
    iterator operator++(int):
    friend bool operator==(iterator lhs, iterator rhs);
    friend bool operator!=(iterator lhs, iterator rhs);
  };
  iterator begin();
  iterator end();
} hld.vchildren(std::size_t v);
```

Given a vertex $v$ by the original vertex index, it returns the original vertex indices of the children of the vertex.

### Constraints
- Either `hld.build()` or `hld.build(std::size_t)` has been called ever.
- $0 \leq v < n$

### Time Complexity
- $O(1)$

## echildren
```cpp
const std::vector<std::size_t>& hld.echildren(std::size_t v);
```

Given a vertex $v$ by the original vertex index, it returns the original edge indices of the edges between the vertex and the children of the vertex.

### Constraints
- Either `hld.build()` or `hld.build(std::size_t)` has been called ever.
- $0 \leq v < n$

### Time Complexity
- $O(1)$

## vid2dfs
```cpp
std::size_t hld.vid2dfs(std::size_t v);
```

Given a vertex $v$ by the original vertex index, it returns the dfs-ordered vertex index of the vertex.

### Constraints
- Either `hld.build()` or `hld.build(std::size_t)` has been called ever.
- $0 \leq v < n$

### Time Complexity
- $O(1)$

## dfs2vid
```cpp
std::size_t hld.dfs2vid(std::size_t i);
```

Given a vertex $i$ by the dfs-ordered vertex index, it returns the original vertex index of the vertex.

### Constraints
- Either `hld.build()` or `hld.build(std::size_t)` has been called ever.
- $0 \leq i < n$

### Time Complexity
- $O(1)$

## eid2dfs
```cpp
std::size_t hld.eid2dfs(std::size_t e);
```

Given an edge $e$ by the original edge index, it returns the dfs-ordered edge index of the edge.

### Constraints
- Either `hld.build()` or `hld.build(std::size_t)` has been called ever.
- $0 \leq e < n$

### Time Complexity
- $O(1)$

## dfs2eid
```cpp
std::size_t hld.dfs2eid(std::size_t i);
```

Given an edge $i$ by the dfs-ordered edge index, it returns the original edge index of the edge.

### Constraints
- Either `hld.build()` or `hld.build(std::size_t)` has been called ever.
- $0 \leq i < n$

### Time Complexity
- $O(1)$

## lca
```cpp
std::size_t hld.lca(std::size_t u, std::size_t v);
```

Given a vertex $u$ and a vertex $v$ by the original vertex indices, it returns the original vertex index of the lowest common ancestor of the vertices.

### Constraints
- Either `hld.build()` or `hld.build(std::size_t)` has been called ever.
- $0 \leq u < n$
- $0 \leq v < n$

### Time Complexity
- $O(\log n)$

## vsubtree
```cpp
std::pair<std::size_t, std::size_t> hld.vsubtree(std::size_t v);
```

Given a vertex $v$ by the original vertex index, it returns the interval of the dfs-ordered vertex indices representing the subtree rooted at the vertex.

### Constraints
- Either `hld.build()` or `hld.build(std::size_t)` has been called ever.
- $0 \leq v < n$

### Time Complexity
- $O(1)$

## esubtree
```cpp
std::pair<std::size_t, std::size_t> hld.esubtree(std::size_t v);
```

Given a vertex $v$ by the original vertex index, it returns the interval of the dfs-ordered edge indices representing the edges in the subtree rooted at the vertex.

### Constraints
- Either `hld.build()` or `hld.build(std::size_t)` has been called ever.
- $0 \leq v < n$

### Time Complexity
- $O(1)$

## vpath
```cpp
std::vector<std::pair<std::size_t, std::size_t>> hld.vpath(std::size_t u, std::size_t v);
```

Given a path from $u$ to $v$ by the original vertex indices, it returns some intervals of the dfs-ordered vertex indices representing the path.
It is guaranteed that the number of the intervals is $O(\log n)$.

### Constraints
- Either `hld.build()` or `hld.build(std::size_t)` has been called ever.
- $0 \leq u < n$
- $0 \leq v < n$

### Time Complexity
- $O(\log n)$

## epath
```cpp
std::vector<std::pair<std::size_t, std::size_t>> hld.epath(std::size_t u, std::size_t v);
```

Given a path from $u$ to $v$ by the original vertex indices, it returns some intervals of the dfs-ordered edge indices representing the path.
It is guaranteed that the number of the intervals is $O(\log n)$.

### Constraints
- Either `hld.build()` or `hld.build(std::size_t)` has been called ever.
- $0 \leq u < n$
- $0 \leq v < n$

### Time Complexity
- $O(\log n)$
