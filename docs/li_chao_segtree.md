---
title: Li Chao segment tree
documentation_of: //tools/li_chao_segtree.hpp
---

It is a data structure which supports the following operations.

- Add a straight line $y = ax + b$.
- Add a line segment $y = ax + b\,(l \leq x \leq r)$.
- Find the maximal or minimal $y$ at given $x$.

It is required to give a predefined list of possible $x$s to a constructor.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
template <typename Iterator>
li_chao_segtree<T> segtree(Iterator begin, Iterator end, bool maximal);
```

It creates an empty set of straight lines and line segments.
The elements from `begin` to `end` represent possible $x$s.
If `maximal` is `true`, it will calculate the maximal $y$ at given $x$.
If `maximal` is `false`, it will calculate the minimal $y$ at given $x$.

### Constraints
- $\mathrm{end} - \mathrm{begin} \geq 1$
- The elements from `begin` to `end` are sorted.

### Time Complexity
- $O(n)$ where $n$ is $\mathrm{end} - \mathrm{begin}$

## add
```cpp
(1) void segtree.add(T a, T b);
(2) void segtree.add(T a, T b, T l, T r);
```

- (1) It adds a straight line $y = ax + b$ to the set.
- (2) It adds a line segment $y = ax + b\,(l \leq x \leq r)$ to the set.

### Constraints
- None

### Time Complexity
- (1): $O(\log n)$ where $n$ is $\mathrm{end} - \mathrm{begin}$
- (2): $O((\log n)^2)$ where $n$ is $\mathrm{end} - \mathrm{begin}$

## query
```cpp
T segtree.query(T x);
```

If `maximal` was `true`, it returns

$$\begin{align*}
\left\{\begin{array}{ll}
\text{the maximal $y$ at given $x$} & \text{(if the maximal exists.)}\\
\mathrm{std::numeric\_limits<T>::min()} & \text{(if the maximal does not exist.)}
\end{array}\right.&
\end{align*}$$

If `maximal` was `false`, it returns

$$\begin{align*}
\left\{\begin{array}{ll}
\text{the minimal $y$ at given $x$} & \text{(if the minimal exists.)}\\
\mathrm{std::numeric\_limits<T>::max()} & \text{(if the minimal does not exist.)}
\end{array}\right.&
\end{align*}$$

### Constraints
- $x$ is in the predefined list of possible $x$s.

### Time Complexity
- $O(\log n)$ where $n$ is $\mathrm{end} - \mathrm{begin}$
