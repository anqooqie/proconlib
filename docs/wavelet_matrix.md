---
title: Wavelet matrix
documentation_of: //tools/wavelet_matrix.hpp
---

It is a non-negative integer sequence $(a_0, a_1, \ldots, a_{n - 1})$.
It processes the following queries in $O(\log \max(a_i))$ time.

- Calculating the $k$-th ($0$-indexed) smallest number in `a[l, r)`.
- Calculating the $k$-th ($0$-indexed) largest number in `a[l, r)`.
- Calculating $\|\\{i \in \mathbb{N} \mid l \leq i < r \land b \leq a_i < t \\}\|$.
- Calculating the maximum $a_i$ such that $l \leq i < r$ and $a_i < t$.
- Calculating the minimum $a_i$ such that $l \leq i < r$ and $b \leq a_i$.

### License
- CC0 1.0 Universal

### Author
- Nyaan

## Constructor
```cpp
(1) wavelet_matrix<T> a(std::uint32_t n)
(2) wavelet_matrix<T> a(std::vector<T> v);
```

- (1)
    - It creates a non-negative integer sequence of length $n$ filled with $0$.
- (2)
    - It creates a non-negative integer sequence initialized with `v`.
    - After construction, `a.built()` gets automatically called.

### Constraints
- (2)
    - `std::all_of(v.begin(), v.end(), [](T v_i) { return v_i >= 0; })`

### Time Complexity
- (1)
    - $O(n)$
- (2)
    - $O(n \log \max(a_i))$

## set
```cpp
void a.set(std::uint32_t i, T x);
```

It updates $a_i$ to $x$.

### Constraints
- $0 \leq i < n$
- $x \geq 0$

### Time Complexity
- $O(1)$

## build
```cpp
void a.build();
```

It internally creates the the data structure called as wavelet matrix.

### Constraints
- None

### Time Complexity
- $O(n \log \max(a_i))$

## access
```cpp
T a.access(std::uint32_t i);
```

It returns $a_i$.

### Constraints
- $0 \leq i < n$

### Time Complexity
- $O(\log \max(a_i))$

## kth_smallest
```cpp
T a.kth_smallest(std::uint32_t l, std::uint32_t r, std::uint32_t k);
```

It returns the $k$-th ($0$-indexed) smallest number in `a[l, r)`.

### Constraints
- $0 \leq l \leq r \leq n$
- $0 \leq k < r - l$

### Time Complexity
- $O(\log \max(a_i))$

## kth_largest
```cpp
T a.kth_largest(std::uint32_t l, std::uint32_t r, std::uint32_t k);
```

It returns the $k$-th ($0$-indexed) largest number in `a[l, r)`.

### Constraints
- $0 \leq l \leq r \leq n$
- $0 \leq k < r - l$

### Time Complexity
- $O(\log \max(a_i))$

## range_freq
```cpp
(1) T a.range_freq(int l, int r, T t);
(2) T a.range_freq(int l, int r, T b, T t);
```

- (1)
    - It returns $\|\\{i \in \mathbb{N} \mid l \leq i < r \land a_i < t \\}\|$.
- (2)
    - It returns $\|\\{i \in \mathbb{N} \mid l \leq i < r \land b \leq a_i < t \\}\|$.

### Constraints
- (1)
    - $0 \leq l \leq r \leq n$
    - $t \geq 0$
- (2)
    - $0 \leq l \leq r \leq n$
    - $0 \leq b \leq t$

### Time Complexity
- $O(\log \max(a_i))$

## prev_value
```cpp
T a.prev_value(int l, int r, T t);
```

It returns the maximum $a_i$ such that $l \leq i < r$ and $a_i < t$.
If such the $a_i$ does not exist, it returns $-1$.

### Constraints
- $0 \leq l \leq r \leq n$
- $t \geq 0$

### Time Complexity
- $O(\log \max(a_i))$

## next_value
```cpp
T a.next_value(int l, int r, T b);
```

It returns the minimum $a_i$ such that $l \leq i < r$ and $b \leq a_i$.
If such the $a_i$ does not exist, it returns $-1$.

### Constraints
- $0 \leq l \leq r \leq n$
- $b \geq 0$

### Time Complexity
- $O(\log \max(a_i))$
