---
title: Lowlink
documentation_of: //tools/lowlink.hpp
---

Given an undirected graph, it creates a data structure that allows enumeration of bridges and articulation points in linear time.
The graph may contain self-loops or multiple edges and need not be connected.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
lowlink graph(std::size_t n);
```

It creates an undirected graph with $n$ vertices and $0$ edges.

### Constraints
- $n \geq 0$

### Time Complexity
- $O(n)$

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

It adds an undirected edge connecting vertex $u$ and vertex $v$ to the graph, and returns the number of edges that existed before the undirected edge was added.

### Constraints
- `graph.build()` has not been called ever.
- $0 \leq u < n$
- $0 \leq v < n$

### Time Complexity
- $O(1)$ amortized

## get_edge
```cpp
struct edge {
  std::size_t id;
  std::size_t from;
  std::size_t to;
};
const edge& graph.get_edge(std::size_t k);
```

It returns information about the $k$-th edge in $0$-indexed.
The information means that the `id`-th edge added to this graph is the undirected edge connecting vertex `from` and vertex `to`.
Of course, as this is an undirected graph, the `from` and `to` orientations are meaningless.
In an undirected graph such as this graph, the vertex numbers are always sorted so that `from` $\leq$ `to`.

### Constraints
- $0 \leq k < \|E\|$ where $\|E\|$ is the number of edges

### Time Complexity
- $O(1)$

## edges (1)
```cpp
const std::vector<edge>& graph.edges();
```

It returns all the edges in the graph.
The edges are ordered in the same order as added by `add_edge`.

### Constraints
- None

### Time Complexity
- $O(1)$

## neighbors
```cpp
struct neighbors_iterable {
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
neighbors_iterable graph.neighbors(std::size_t v);
```

It returns an iterator that enumerates the vertices adjacent to vertex $v$.
The enumeration order is undefined, except that each element appears exactly once.

### Constraints
- $0 \leq v < n$

### Time Complexity
- $O(1)$

### edges (2)
```cpp
struct edges_iterable {
  struct iterator {
    const edge& operator*();
    iterator& operator++();
    iterator operator++(int):
    friend bool operator==(iterator lhs, iterator rhs);
    friend bool operator!=(iterator lhs, iterator rhs);
  };
  iterator begin();
  iterator end();
};
edges_iterable graph.edges(std::size_t v);
```

It returns an iterator that enumerates the edges adjacent to vertex $v$.
The enumeration order is undefined, except that each element appears exactly once.

### Constraints
- $0 \leq v < n$

### Time Complexity
- $O(1)$

## build
```cpp
void graph.build();
```

It creates a data structure that allows bridges and articulation points to be enumerated in linear time.
The key elements are values called $\mathrm{ord}(v)$ and $\mathrm{low}(v)$ assigned to each vertex $v$, which are defined as follows.

We first repeat the process of creating a spanning tree for each connected component of the graph by a depth-first search, choosing the roots as appropriate.
We call this spanning tree a DFS tree, and the edges belonging to the DFS tree are called tree edges.
We regard a tree edge as a directed edge from the root side to the leaf side.

We also refer to edges that do not belong to the DFS tree as back edges.
Back edges are known to have both endpoints always in an ancestor-descendant relationship.
We regard a back edge as a directed edge from the leaf side to the root side.

We define $\mathrm{ord}(v)$ and $\mathrm{low}(v)$ as values determined for each vertex $v$ of the spanning tree.
The definition of $\mathrm{ord}(v)$ is the pre-ordered vertex number of the DFS tree.
The $\mathrm{ord}(r)$ of root $r$ is $0$.
The definition of $\mathrm{low}(v)$ is $\displaystyle \min_{s \in S}\left(\mathrm{ord}\left(s\right)\right)$, where $S$ is the set of vertices reachable from vertex $v$ using zero or more tree edges and one or less back edges.

Note that there are as many vertices $v$ such that $\mathrm{ord}(v) = 0$ as there are connected components.

### Constraints
- `graph.build()` has not been called ever.

### Time Complexity
- $O(n + \|E\|)$ where $\|E\|$ is the number of edges

## vparent
```cpp
std::size_t graph.vparent(std::size_t v);
```

It returns $u$ such that the parent of vertex $v$ in the DFS tree is vertex $u$.

### Constraints
- `graph.build()` has been called ever.
- $0 \leq v < n$
- $\mathrm{ord}(v) > 0$

### Time Complexity
- $O(1)$

## eparent
```cpp
const edge& graph.eparent(std::size_t v);
```

It returns the tree edge towards vertex $v$.

### Constraints
- `graph.build()` has been called ever.
- $0 \leq v < n$
- $\mathrm{ord}(v) > 0$

### Time Complexity
- $O(1)$

## vchildren
```cpp
struct vchildren_iterable {
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
vchildren_iterable graph.vchildren(std::size_t v);
```

It returns $u$ such that the parent of vertex $u$ in the DFS tree is vertex $v$.

### Constraints
- `graph.build()` has been called ever.
- $0 \leq v < n$

### Time Complexity
- $O(\|E\|)$ worst where $\|E\|$ is the number of edges
- $\displaystyle O\left( \frac{\|E\|}{n} \right)$ amortized

## echildren
```cpp
struct echildren_iterable {
  struct iterator {
    const edge& operator*();
    iterator& operator++();
    iterator operator++(int):
    friend bool operator==(iterator lhs, iterator rhs);
    friend bool operator!=(iterator lhs, iterator rhs);
  };
  iterator begin();
  iterator end();
};
echildren_iterable graph.echildren(std::size_t v);
```

It returns the tree edges from $v$.

### Constraints
- `graph.build()` has been called ever.
- $0 \leq v < n$

### Time Complexity
- $O(\|E\|)$ worst where $\|E\|$ is the number of edges
- $\displaystyle O\left( \frac{\|E\|}{n} \right)$ amortized

## ord
```cpp
std::size_t graph.ord(std::size_t v);
```

It returns $\mathrm{ord}(v)$.

### Constraints
- `graph.build()` has been called ever.
- $0 \leq v < n$

### Time Complexity
- $O(1)$

## low
```cpp
std::size_t graph.low(std::size_t v);
```

It returns $\mathrm{low}(v)$.

### Constraints
- `graph.build()` has been called ever.
- $0 \leq v < n$

### Time Complexity
- $O(1)$

## ncc
```cpp
std::size_t graph.ncc();
```

It returns the number of connected components of the graph.

### Constraints
- `graph.build()` has been called ever.

### Time Complexity
- $O(1)$

## ncc_without_vertex
```cpp
std::size_t graph.ncc_without_vertex(std::size_t v);
```

It returns the number of connected components of the graph without vertex $v$.

### Constraints
- `graph.build()` has been called ever.
- $0 \leq v < n$

### Time Complexity
- $O(1)$

## is_articulation_point
```cpp
bool graph.is_articulation_point(std::size_t v);
```

It returns whether vertex $v$ is an articulation point or not.

### Constraints
- `graph.build()` has been called ever.
- $0 \leq v < n$

### Time Complexity
- $O(1)$

## is_bridge
```cpp
bool graph.is_bridge(std::size_t k);
```

It returns whether the $k$-th edge is a bridge or not.

### Constraints
- `graph.build()` has been called ever.
- $0 \leq k < \|E\|$ where $\|E\|$ is the number of edges

### Time Complexity
- $O(1)$

## biconnected_component
```cpp
std::vector<std::vector<std::size_t>> graph.biconnected_component();
```

It divides the graph into biconnected components and returns the list of them.

More precisely, it returns the list of the "list of the vertices in a biconnected component".
Both of the orders of the biconnected components and the vertices are undefined.

### Constraints
- `graph.build()` has been called ever.

### Time Complexity
- $O(n + \|E\|)$ where $\|E\|$ is the number of edges
