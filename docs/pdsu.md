---
title: Potentialized disjoint set union
documentation_of: //tools/pdsu.hpp
---

Given an unknown integer sequence $a_0, a_1, \ldots, a_{n - 1}$ and an abelian group $G$, it processes the following queries in $O(\alpha(n))$ time (amortized).

- Receiving the information $a_y - a_x = w$ under the abelian group $G$
- Reporting $a_y - a_x$ under the abelian group $G$

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
template <typename G = tools::group::plus<long long>>
pdsu<G> d(int n);
```

It creates an unknown integer sequence $a_0, a_1, \ldots, a_{n - 1}$.

### Constraints
- $n \geq 0$
- For all $a$ in `typename G::T` and $b$ in `typename G::T`, `G::op(a, b)` $=$ `G::op(b, a)`.
- For all $a$ in `typename G::T`, $b$ in `typename G::T` and $c$ in `typename G::T`, `G::op(G::op(a, b), c)` $=$ `G::op(a, G::op(b, c))`.
- For all $a$ in `typename G::T`, `G::op(G::e(), a)` $=$ `G::op(a, G::e())` $=$ `a`.
- For all $a$ in `typename G::T`, `G::op(G::inv(a), a)` $=$ `G::op(a, G::inv(a))` $=$ `G::e()`.

### Time Complexity
- $O(n)$

## merge
```cpp
int d.merge(int x, int y, typename G::T w);
```

It receives the information $a_y - a_x = w$.

### Constraints
- $0 \leq x < n$
- $0 \leq y < n$
- Before calling the function, $a_y - a_x$ is unknown

### Time Complexity
- amortized $O(\alpha(n))$

## diff
```cpp
typename G::T d.diff(int x, int y);
```

It returns $a_y - a_x$.

### Constraints
- $0 \leq x < n$
- $0 \leq y < n$
- $a_y - a_x$ is known

### Time Complexity
- amortized $O(\alpha(n))$

## same
```cpp
bool d.same(int x, int y);
```

It returns whether $a_y - a_x$ is known or not.

### Constraints
- $0 \leq x < n$
- $0 \leq y < n$

### Time Complexity
- amortized $O(\alpha(n))$

## leader
```cpp
int d.leader(int x);
```

If an undirected graph with $n$ vertices is given and we connect the vertices $y$ and $z$ if and only if $a_z - a_y$ is known, the graph can be divided into some connected components.
It returns the reprensative vertex of the connected component which contains $x$.

### Constraints
- $0 \leq x < n$

### Time Complexity
- amortized $O(\alpha(n))$

## size
```cpp
int d.size(int x);
```

If an undirected graph with $n$ vertices is given and we connect the vertices $y$ and $z$ if and only if $a_z - a_y$ is known, the graph can be divided into some connected components.
It returns the size of the connected component which contains $x$.

### Constraints
- $0 \leq x < n$

### Time Complexity
- amortized $O(\alpha(n))$

## groups
```cpp
std::vector<std::vector<int>> d.groups();
```

If an undirected graph with $n$ vertices is given and we connect the vertices $y$ and $z$ if and only if $a_z - a_y$ is known, the graph can be divided into some connected components.
It returns the list of the connected components.

### Constraints
- None

### Time Complexity
- $O(n)$
