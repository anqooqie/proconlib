---
title: Disjoint set union, but allows range parallel union
documentation_of: //tools/range_parallel_dsu.hpp
---

Given an undirected graph, it processes the following queries.

- Adding an edge $(a + i, b + i)$ for each $i = 0, 1, \ldots, k - 1$
- Deciding whether given two vertices are in the same connected component

Each connected component internally has a representative vertex.

When two connected components are merged by edge addition, the representative of the larger connected component becomes the representative of the new connected component.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
range_parallel_dsu d(int n);
```

It creates an undirected graph with $n$ vertices and $0$ edges.

### Constraints
- $n \geq 0$

### Time Complexity
- $O(n \log n)$

## merge (two parameters)
```cpp
int d.merge(int a, int b);
```

It adds an edge $(a, b)$.

If the vertices $a$ and $b$ were in the same connected component, it returns the representative of the connected component.
Otherwise, the representative of the larger (or former when the two have the same size) connected component becomes the representative of the new connected component, and it returns the new representative.

### Constraints
- $0 \leq a < n$
- $0 \leq b < n$

### Time Complexity
- $O(\alpha(n))$ amortized
- $O(\log n)$ worst

## merge (three parameters)
```cpp
std::vector<std::pair<int, int>> d.merge(int a, int b, int k);
```

It adds an edge $(a + i, b + i)$ for each $i = 0, 1, \ldots, k - 1$.

Suppose that $m$ merges between different connected components occur as a result of calling this method.
Let $s_j$ be the representative with the greater number of elements at the $j$-th merge, and let $t_j$ be the representative with the smaller number of elements.
It returns $((s_0, t_0), (s_1, t_1), \ldots, (s_{m - 1}, t_{m - 1}))$.

### Constraints
- $0 \leq a \leq a + k \leq n$
- $0 \leq b \leq b + k \leq n$

### Time Complexity
- $O(k \log n)$ worst per query
- $O((n \log n + Q) \alpha(n))$ in total for $Q$ queries

## same
```cpp
bool d.same(int a, int b);
```

It returns whether the vertices $a$ and $b$ are in the same connected component.

### Constraints
- $0 \leq a < n$
- $0 \leq b < n$

### Time Complexity
- $O(\alpha(n))$ amortized
- $O(\log n)$ worst

## leader
```cpp
int d.leader(int a);
```

It returns the representative of the connected component that contains the vertex $a$.

### Constraints
- $0 \leq a < n$

### Time Complexity
- $O(\alpha(n))$ amortized
- $O(\log n)$ worst

## size (zero parameters)
```cpp
int d.size();
```

It returns $n$.

### Constraints
- None

### Time Complexity
- $O(1)$

## size (one parameter)
```cpp
int d.size(int a);
```

It returns the size of the connected component that contains the vertex $a$.

### Constraints
- $0 \leq a < n$

### Time Complexity
- $O(\alpha(n))$ amortized
- $O(\log n)$ worst

## groups
```cpp
std::vector<std::vector<int>> d.groups();
```

It divides the graph into connected components and returns the list of them.

More precisely, it returns the list of the "list of the vertices in a connected component".
Both of the orders of the connected components and the vertices are undefined.

### Constraints
- None

### Time Complexity
- $O(n)$

## ncc
```cpp
int d.ncc();
```

It returns the number of connected components.

### Constraints
- None

### Time Complexity
- $O(1)$
