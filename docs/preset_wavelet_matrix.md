---
title: Preset wavelet matrix
documentation_of: //tools/preset_wavelet_matrix.hpp
---

It is a pair of a wavelet matrix and auxiliary data structures, preconfigured for commonly used operations.
Given $n$ weighted points $(x_0, y_0, w_0), (x_1, y_1, w_1), \ldots, (x_{n - 1}, y_{n - 1}, w_{n - 1})$ on a two-dimensional plane, it can update $w_i$ for any $i$ and answer the sum of $w_i$ such that $l \leq x_i < r$ and $d \leq y_i < u$ hold.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
(1) preset_wavelet_matrix<T, U, Updatable> wm();
(2) preset_wavelet_matrix<T, G, Updatable> wm();
```

- (1)
    - It is identical to `preset_wavelet_matrix<T, tools::group::plus<U>, Updatable> wm();`
- (2)
    - It creates a two-dimensional plane with $0$ weighted points.
    - The weight of each point is on a given commutative group $G$.
    - If `Updatable` is `true`, the weights can be updated even after `wm.build()` has been called in exchange for worse time complexity.

### Constraints
- (1)
    - `tools::is_group_v<U>` does not hold.
- (2)
    - `tools::is_group_v<G>` holds.
    - For all $x$ in `typename G::T` and $y$ in `typename G::T`, `G::op(x, y)` $=$ `G::op(y, x)`.
    - For all $x$ in `typename G::T`, $y$ in `typename G::T` and $z$ in `typename G::T`, `G::op(G::op(x, y), z)` $=$ `G::op(x, G::op(y, z))`.
    - For all $x$ in `typename G::T`, `G::op(x, G::e())` $= x$.
    - For all $x$ in `typename G::T`, `G::op(x, G::inv(x))` $=$ `G::e()`.

### Time Complexity
- $O(1)$

## size
```cpp
int wm.size();
```

It returns the number of weighted points on the plane.

### Constraints
- None

### Time Complexity
- $O(1)$

## add_point
```cpp
int wm.add_point(T x, T y, typename G::T w);
```

It adds a weighted point $(x, y, w)$ to the plane.
It returns an integer $i$ such that this is the $i$-th ($0$ indexed) weighted point that is added.

### Constraints
- `wm.build()` has not been called ever.

### Time Complexity
- $O(1)$ amortized

## get_point
```cpp
std::tuple<T, T, typename G::T> wm.get_point(int i);
```

It returns the $i$-th ($0$ indexed) weighted point.

### Constraints
- $0 \leq i < n$ where $n$ is `wm.size()`

### Time Complexity
- $O(1)$

## points
```cpp
std::vector<std::tuple<T, T, typename G::T>> wm.points();
```

It returns all the weighted points on the plane.
The weighted points are ordered in the same order as added by `add_point`.

### Constraints
- None

### Time Complexity
- $O(n)$

## build
```cpp
void wm.build();
```

It internally creates the data structure called as wavelet matrix.

### Constraints
- `wm.build()` has not been called ever.

### Time Complexity
- $O(n \log n)$

## set_weight
```cpp
void wm.set_weight(int i, typename G::T w);
```

It updates the weight of the $i$-th ($0$ indexed) weighted point to $w$.

### Constraints
- `<Updatable>` is `true`.
- $0 \leq i < n$

### Time Complexity
- (Before `wm.build()` has been called): $O(1)$
- (After `wm.build()` has been called): $O\left((\log n)^2\right)$

## kth_smallest
```cpp
int wm.kth_smallest(T l, T r, int k);
```

It returns $i$ such that $l \leq x_i < r$ and $\|\\{j \mid l \leq x_j < r \land (y_j, j) < (y_i, i)) \\}\| = k$.

### Constraints
- `wm.build()` has been called ever.
- $l \leq r$
- $0 \leq k < \|\\{i \mid l \leq x_i < r\\}\|$

### Time Complexity
- $O(\log n)$

## kth_largest
```cpp
int wm.kth_largest(T l, T r, int k);
```

It returns $i$ such that $l \leq x_i < r$ and $\|\\{j \mid l \leq x_j < r \land (y_i, i) < (y_j, j)) \\}\| = k$.

### Constraints
- `wm.build()` has been called ever.
- $l \leq r$
- $0 \leq k < \|\\{i \mid l \leq x_i < r\\}\|$

### Time Complexity
- $O(\log n)$

## range_sum
```cpp
(1) typename G::T wm.range_sum(T l, T r, T u);
(2) typename G::T wm.range_sum(T l, T r, T d, T u);
```

- (1)
    - It returns the sum of $w_i$ such that $l \leq x_i < r$ and $y_i < u$.
- (2)
    - It returns the sum of $w_i$ such that $l \leq x_i < r$ and $d \leq y_i < u$.

Note that the addition is defined by the commutative group $G$.

### Constraints
- (1)
    - `wm.build()` has been called ever.
    - $l \leq r$
- (2)
    - `wm.build()` has been called ever.
    - $l \leq r$
    - $d \leq u$

### Time Complexity
- (`<Updatable>` is `true`): $O\left((\log n)^2\right)$
- (`<Updatable>` is `false`): $O(\log n)$

## range_freq
```cpp
(1) int wm.range_freq(T l, T r);
(2) int wm.range_freq(T l, T r, T u);
(3) int wm.range_freq(T l, T r, T d, T u);
```

- (1)
    - It returns $\|\\{i \mid l \leq x_i < r \\}\|$.
- (2)
    - It returns $\|\\{i \mid l \leq x_i < r \land y_i < u \\}\|$.
- (3)
    - It returns $\|\\{i \mid l \leq x_i < r \land d \leq y_i < u \\}\|$.

### Constraints
- (1), (2)
    - `wm.build()` has been called ever.
    - $l \leq r$
- (3)
    - `wm.build()` has been called ever.
    - $l \leq r$
    - $d \leq u$

### Time Complexity
- $O(\log n)$

## prev_value
```cpp
std::optional<T> wm.prev_value(T l, T r, T u);
```

It returns the maximum $y_i$ such that $l \leq x_i < r$ and $y_i < u$.
If such the $y_i$ does not exist, it returns `std::nullopt`.

### Constraints
- `wm.build()` has been called ever.
- $l \leq r$

### Time Complexity
- $O(\log n)$

## next_value
```cpp
std::optional<T> wm.next_value(T l, T r, T d);
```

It returns the minimum $y_i$ such that $l \leq x_i < r$ and $d \leq y_i$.
If such the $y_i$ does not exist, it returns `std::nullopt`.

### Constraints
- `wm.build()` has been called ever.
- $l \leq r$

### Time Complexity
- $O(\log n)$

## prev_points
```cpp
std::ranges::subrange<std::vector<int>::const_iterator> prev_points(T l, T r, T u)
```

It returns $\\{i \mid l \leq x_i < r \land y_i = y\\}$ sorted in ascending order, where $y$ is `wm.prev_value(l, r, u)`.

### Constraints
- `wm.build()` has been called ever.
- $l \leq r$

### Time Complexity
- $O(\log n)$

## next_points
```cpp
std::ranges::subrange<std::vector<int>::const_iterator> next_points(T l, T r, T d)
```

It returns $\\{i \mid l \leq x_i < r \land y_i = y\\}$ sorted in ascending order, where $y$ is `wm.next_value(l, r, d)`.

### Constraints
- `wm.build()` has been called ever.
- $l \leq r$

### Time Complexity
- $O(\log n)$
