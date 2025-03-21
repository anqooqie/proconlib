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
hld hld(int n);
```

It creates a graph with $n$ vertices and $0$ edges.

### Constraints
- $n \geq 1$

### Time Complexity
- $O(n)$

## size
```cpp
int hld.size();
```

It returns $n$.

### Constraints
- None

### Time Complexity
- $O(1)$

## add_edge
```cpp
void hld.add_edge(int u, int v);
```

It adds an undirected edge connecting $u$ and $v$ to the graph.

### Constraints
- `hld.build(int)` has not been called ever.
- $0 \leq u < n$
- $0 \leq v < n$

### Time Complexity
- $O(1)$ amortized

## build
```cpp
void hld.build(int r);
```

It remaps the vertex indices in the tree to dfs-ordered ones and the edge indices in the tree to dfs-ordered ones.
In DFS, the root is $r$.

### Constraints
- `hld.build(int)` has not been called ever.
- The graph is a tree.
- $0 \leq r < n$

### Time Complexity
- $O(n)$

## depth
```cpp
int hld.depth(int v);
```

Given a vertex $v$ by the original vertex index, it returns the depth of the vertex.

### Constraints
- `hld.build(int)` has been called ever.
- $0 \leq v < n$

### Time Complexity
- $O(1)$

## vparent
```cpp
int hld.vparent(int v);
```

Given a vertex $v$ by the original vertex index, it returns the original vertex index of the parent of the vertex.

### Constraints
- `hld.build(int)` has been called ever.
- $0 \leq v < n$
- $v$ is not the root.

### Time Complexity
- $O(1)$

## eparent
```cpp
int hld.eparent(int v);
```

Given a vertex $v$ by the original vertex index, it returns the original edge index of the edge between the vertex and the parent of the vertex.

### Constraints
- `hld.build(int)` has been called ever.
- $0 \leq v < n$
- $v$ is not the root.

### Time Complexity
- $O(1)$

## vancestor
```cpp
int hld.vancestor(int v, int k);
```

Given a vertex $v$ by the original vertex index, it returns the original vertex index of the $k$-th ancestor of the vertex.

### Constraints
- `hld.build(int)` has been called ever.
- $0 \leq v < n$
- $0 \leq k \leq $ `hld.depth(v)`

### Time Complexity
- (first call): $O(n \log n)$
- (second or later call): $O(\log k)$

## vchildren
```cpp
struct {
  struct iterator {
    int operator*();
    iterator& operator++();
    iterator operator++(int):
    friend bool operator==(iterator lhs, iterator rhs);
    friend bool operator!=(iterator lhs, iterator rhs);
  };
  iterator begin();
  iterator end();
} hld.vchildren(int v);
```

Given a vertex $v$ by the original vertex index, it returns the original vertex indices of the children of the vertex.

### Constraints
- `hld.build(int)` has been called ever.
- $0 \leq v < n$

### Time Complexity
- $O(1)$

## echildren
```cpp
const std::vector<int>& hld.echildren(int v);
```

Given a vertex $v$ by the original vertex index, it returns the original edge indices of the edges between the vertex and the children of the vertex.

### Constraints
- `hld.build(int)` has been called ever.
- $0 \leq v < n$

### Time Complexity
- $O(1)$

## vid2dfs
```cpp
int hld.vid2dfs(int v);
```

Given a vertex $v$ by the original vertex index, it returns the dfs-ordered vertex index of the vertex.

### Constraints
- `hld.build(int)` has been called ever.
- $0 \leq v < n$

### Time Complexity
- $O(1)$

## dfs2vid
```cpp
int hld.dfs2vid(int i);
```

Given a vertex $i$ by the dfs-ordered vertex index, it returns the original vertex index of the vertex.

### Constraints
- `hld.build(int)` has been called ever.
- $0 \leq i < n$

### Time Complexity
- $O(1)$

## eid2dfs
```cpp
int hld.eid2dfs(int e);
```

Given an edge $e$ by the original edge index, it returns the dfs-ordered edge index of the edge.

### Constraints
- `hld.build(int)` has been called ever.
- $0 \leq e < n$

### Time Complexity
- $O(1)$

## dfs2eid
```cpp
int hld.dfs2eid(int i);
```

Given an edge $i$ by the dfs-ordered edge index, it returns the original edge index of the edge.

### Constraints
- `hld.build(int)` has been called ever.
- $0 \leq i < n$

### Time Complexity
- $O(1)$

## lca
```cpp
int hld.lca(int u, int v);
```

Given a vertex $u$ and a vertex $v$ by the original vertex indices, it returns the original vertex index of the lowest common ancestor of the vertices.

### Constraints
- `hld.build(int)` has been called ever.
- $0 \leq u < n$
- $0 \leq v < n$

### Time Complexity
- $O(\log n)$

## vsubtree
```cpp
std::pair<int, int> hld.vsubtree(int v);
```

Given a vertex $v$ by the original vertex index, it returns the interval of the dfs-ordered vertex indices representing the subtree rooted at the vertex.

### Constraints
- `hld.build(int)` has been called ever.
- $0 \leq v < n$

### Time Complexity
- $O(1)$

## esubtree
```cpp
std::pair<int, int> hld.esubtree(int v);
```

Given a vertex $v$ by the original vertex index, it returns the interval of the dfs-ordered edge indices representing the edges in the subtree rooted at the vertex.

### Constraints
- `hld.build(int)` has been called ever.
- $0 \leq v < n$

### Time Complexity
- $O(1)$

## vpath
```cpp
std::vector<std::pair<int, int>> hld.vpath(int u, int v);
```

Given a path from $u$ to $v$ by the original vertex indices, it returns some intervals of the dfs-ordered vertex indices representing the path.
It is guaranteed that the number of the intervals is $O(\log n)$.

### Constraints
- `hld.build(int)` has been called ever.
- $0 \leq u < n$
- $0 \leq v < n$

### Time Complexity
- $O(\log n)$

## epath
```cpp
std::vector<std::pair<int, int>> hld.epath(int u, int v);
```

Given a path from $u$ to $v$ by the original vertex indices, it returns some intervals of the dfs-ordered edge indices representing the path.
It is guaranteed that the number of the intervals is $O(\log n)$.

### Constraints
- `hld.build(int)` has been called ever.
- $0 \leq u < n$
- $0 \leq v < n$

### Time Complexity
- $O(\log n)$
