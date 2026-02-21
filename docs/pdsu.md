---
title: Potentialized disjoint set union
documentation_of: //tools/pdsu.hpp
---

Given a group $(G, \cdot)$ and an unknown sequence $(a_0, a_1, \ldots, a_{n - 1}) \in G^n$, it processes the following queries in $O(\alpha(n))$ time (amortized).

- Accepting the information $a_x = a_y \cdot w$
- Reporting $a_y^{-1} \cdot a_x$

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
template <typename G = tools::groups::plus<long long>>
pdsu<G> d(int n);
```

It creates an unknown sequence $(a_0, a_1, \ldots, a_{n - 1}) \in G^n$.

### Constraints
- $n \geq 0$
- $\forall a \in G. \forall b \in G. \forall c \in G. (a \cdot b) \cdot c = a \cdot (b \cdot c)$
- $\forall a \in G. e \cdot a = a \cdot e = a$ where $e$ is `G::e()`
- $\forall a \in G. a^{-1} \cdot a = a \cdot a^{-1} = e$ where $e$ is `G::e()`

### Time Complexity
- $O(n)$

## merge
```cpp
std::optional<std::pair<int, int>> d.merge(int x, int y, typename G::T w);
```

It accepts the information $a_x = a_y \cdot w$.

If an undirected graph with $n$ vertices is given and we connect the vertices $u$ and $v$ if and only if `same(u, v)` holds, the graph can be divided into some connected components.
If $x$ and $y$ are already in the same connected component, it returns `std::nullopt`.
Otherwise, it returns $(r_1, r_2)$.
Here, $r_1$ is the representative of the larger component (or $x$'s component if both are the same size), which becomes the new representative of the merged component.
$r_2$ is the former representative of the other component.

### Constraints
- $0 \leq x < n$
- $0 \leq y < n$

### Time Complexity
- $O(\alpha(n))$ amortized

## diff
```cpp
enum class pdsu_diff {
  known,
  unknown,
  inconsistent
};
std::pair<tools::pdsu_diff, typename G::T> d.diff(int x, int y);
```

If $a_y^{-1} \cdot a_x$ can be calculated consistently, it returns $(\mathrm{known}, a_y^{-1} \cdot a_x)$.
If $a_y^{-1} \cdot a_x$ is still unknown under the information accepted so far, it returns $(\mathrm{unknown}, e)$ where $e$ is `G::e()`.
If it turns out that the consistent value of $a_y^{-1} \cdot a_x$ cannot be obtained, it returns $(\mathrm{inconsistent}, e)$ where $e$ is `G::e()`.

### Constraints
- $0 \leq x < n$
- $0 \leq y < n$

### Time Complexity
- $O(\alpha(n))$ amortized

## same
```cpp
bool d.same(int x, int y);
```

If $a_y^{-1} \cdot a_x$ is still unknown under the information accepted so far, it returns `false`.
Otherwise, it returns `true`.

### Constraints
- $0 \leq x < n$
- $0 \leq y < n$

### Time Complexity
- $O(\alpha(n))$ amortized

## leader
```cpp
int d.leader(int x);
```

If an undirected graph with $n$ vertices is given and we connect the vertices $u$ and $v$ if and only if `same(u, v)` holds, the graph can be divided into some connected components.
It returns the reprensative vertex of the connected component which contains $x$.

### Constraints
- $0 \leq x < n$

### Time Complexity
- $O(\alpha(n))$ amortized

## size (zero parameters)
```cpp
int d.size();
```

If returns $n$.

### Constraints
- None

### Time Complexity
- $O(1)$

## size (one parameter)
```cpp
int d.size(int x);
```

If an undirected graph with $n$ vertices is given and we connect the vertices $u$ and $v$ if and only if `same(u, v)` holds, the graph can be divided into some connected components.
It returns the size of the connected component which contains $x$.

### Constraints
- $0 \leq x < n$

### Time Complexity
- $O(\alpha(n))$ amortized

## groups
```cpp
std::vector<std::vector<int>> d.groups();
```

If an undirected graph with $n$ vertices is given and we connect the vertices $u$ and $v$ if and only if `same(u, v)` holds, the graph can be divided into some connected components.
It returns the list of the connected components.

### Constraints
- None

### Time Complexity
- $O(n)$

## ncc
```cpp
int d.ncc();
```

If an undirected graph with $n$ vertices is given and we connect the vertices $u$ and $v$ if and only if `same(u, v)` holds, the graph can be divided into some connected components.
It returns the number of connected components.

### Constraints
- None

### Time Complexity
- $O(1)$
