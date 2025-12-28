---
title: Partially persistent disjoint set union
documentation_of: //tools/partially_persistent_dsu.hpp
---

Given an undirected graph, it processes the following queries in $O(\log(n))$ time.

- Edge addition
- Deciding whether given two vertices were in the same connected component at the specified time

Each connected component internally has a representative vertex.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
partially_persistent_dsu d(int n);
```

It creates an undirected graph with $n$ vertices and $0$ edges.

### Constraints
- $n \geq 0$

### Time Complexity
- $O(n)$

## now
```cpp
int d.now();
```

It returns the number of times that `d.merge` has been called so far.

### Constraints
- None

### Time Complexity
- $O(1)$

## merge
```cpp
int d.merge(int a, int b);
```

It adds an edge $(a, b)$.

If the vertices $a$ and $b$ were in the same connected component, it returns the representative of this connected component.
Otherwise, it returns the representative of the new connected component.

### Constraints
- $0 \leq a < n$
- $0 \leq b < n$

### Time Complexity
- $O(\log n)$

## same
```cpp
bool d.same(int t, int a, int b);
```

It returns whether the vertices $a$ and $b$ were in the same connected component at the time when `d.now() == t`.

### Constraints
- $0 \leq t \leq$ `d.now()`
- $0 \leq a < n$
- $0 \leq b < n$

### Time Complexity
- $O(\log n)$

## leader
```cpp
int d.leader(int t, int a);
```

It returns the representative of the connected component that contained the vertex $a$ at the time when `d.now() == t`.

### Constraints
- $0 \leq t \leq$ `d.now()`
- $0 \leq a < n$

### Time Complexity
- $O(\log n)$

## size
```cpp
int d.size(int t, int a);
```

It returns the size of the connected component that contained the vertex $a$ at the time when `d.now() == t`.

### Constraints
- $0 \leq t \leq$ `d.now()`
- $0 \leq a < n$

### Time Complexity
- $O(\log n)$

## groups
```cpp
std::vector<std::vector<int>> d.groups(int t);
```

It divides the graph at the time when `d.now() == t` into connected components and returns the list of them.

More precisely, it returns the list of the "list of the vertices in a connected component".
Both of the orders of the connected components and the vertices are undefined.

### Constraints
- $0 \leq t \leq$ `d.now()`

### Time Complexity
- $O(n)$

## when_connected
```cpp
int d.when_connected(int a, int b);
```

It returns the minimum integer $t$ such that the vertices $a$ and $b$ were in the same connected component if `d.now()` is greater than or equal to $t$.
If such the integer does not exist, it returns `std::numeric_limits<int>::max()`.

### Constraints
- $0 \leq a < n$
- $0 \leq b < n$

### Time Complexity
- $O(\log n)$
