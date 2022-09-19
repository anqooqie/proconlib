---
title: Disjoint set union
documentation_of: //tools/dsu.hpp
---

Given an undirected graph, it processes the following queries in $O(\alpha(n))$ time (amortized).

- Edge addition
- Deciding whether given two vertices are in the same connected component

Each connected component internally has a representative vertex.

When two connected components are merged by edge addition, the representative of the larger connected component becomes the representative of the new connected component.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
dsu d(int n);
```

It creates an undirected graph with $n$ vertices and $0$ edges.

### Constraints
- $n \geq 0$

### Time Complexity
- $O(n)$

## merge
```cpp
int d.merge(int a, int b);
```

It adds an edge $(a, b)$.

If the vertices $a$ and $b$ were in the same connected component, it returns the representative of this connected component.
Otherwise, the representative of the larger (or former when the two have the same size) connected component becomes the representative of the new connected component, and it returns the new representative.

### Constraints
- $0 \leq a < n$
- $0 \leq b < n$

### Time Complexity
- $O(\alpha(n))$ amortized

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

## leader
```cpp
int d.leader(int a);
```

It returns the representative of the connected component that contains the vertex $a$.

### Constraints
- $0 \leq a < n$

### Time Complexity
- $O(\alpha(n))$ amortized

## size
```cpp
int d.size(int a);
```

It returns the size of the connected component that contains the vertex $a$.

### Constraints
- $0 \leq a < n$

### Time Complexity
- $O(\alpha(n))$ amortized

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
