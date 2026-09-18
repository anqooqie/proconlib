---
title: Preset segment tree beats
documentation_of: //tools/preset_segtree_beats.hpp
---

It is a segment tree beats preconfigured for the most frequent case.
Given a sequence $a$ of $n$ elements, it processes range chmin, range chmax and range add, and answers range minimum, range maximum and range sum.

It is an instantiation of `tools::segtree_beats`, and its interface follows `atcoder::lazy_segtree`.

In this document, $n$ is the number of elements and $q$ is the number of operations.
The time complexity of each operation is amortized: the total time of $q$ operations is $O\left((n + q) \log^2 n\right)$, and $O((n + q) \log n)$ if `add` is never called.

### References
- [A simple introduction to "Segment tree beats" - Codeforces](https://codeforces.com/blog/entry/57319)
- [The Time Complexity Lower Bound for Segment Tree Beats is log^2 - Codeforces](https://codeforces.com/blog/entry/149516)

### License
- MIT

### Author
- hitonanode

## Constructor
```cpp
(1) preset_segtree_beats<T> a(int n);
(2) preset_segtree_beats<T> a(std::vector<T> v);
```

- (1)
    - It creates a sequence `a` of length $n$. All the elements are the identity.
    - It is kept only for the compatibility with `atcoder::lazy_segtree`. There is no situation where it is useful, so use (2) instead.
- (2)
    - It creates a sequence `a` of length $n$ = `v.size()`, initialized to `v`.

### Constraints
- `<T>` is a signed integer type.
- Every element and the sum of every interval always lie strictly between `std::numeric_limits<T>::min()` and `std::numeric_limits<T>::max()`, since both of them are used as the sentinels meaning that there is no such value.
- (1)
    - $n \geq 0$

### Time Complexity
- $O(n)$

## set
```cpp
void a.set(int p, T x);
```

`a[p] = x`

### Constraints
- $0 \leq p < n$

### Time Complexity
- $O\left(\log^2 n\right)$ amortized
- $O(\log n)$ amortized if `add` is never called

## get
```cpp
T a.get(int p);
```

It returns `a[p]`.

### Constraints
- $0 \leq p < n$

### Time Complexity
- $O\left(\log^2 n\right)$ amortized
- $O(\log n)$ amortized if `add` is never called

## min
```cpp
T a.min(int l, int r);
```

It returns `min(a[l], ..., a[r - 1])`.
It returns `std::numeric_limits<T>::max()` if $l = r$.

### Constraints
- $0 \leq l \leq r \leq n$

### Time Complexity
- $O\left(\log^2 n\right)$ amortized
- $O(\log n)$ amortized if `add` is never called

## max
```cpp
T a.max(int l, int r);
```

It returns `max(a[l], ..., a[r - 1])`.
It returns `std::numeric_limits<T>::min()` if $l = r$.

### Constraints
- $0 \leq l \leq r \leq n$

### Time Complexity
- $O\left(\log^2 n\right)$ amortized
- $O(\log n)$ amortized if `add` is never called

## sum
```cpp
T a.sum(int l, int r);
```

It returns `a[l] + ... + a[r - 1]`.
It returns $0$ if $l = r$.

### Constraints
- $0 \leq l \leq r \leq n$

### Time Complexity
- $O\left(\log^2 n\right)$ amortized
- $O(\log n)$ amortized if `add` is never called

## all_min
```cpp
T a.all_min();
```

It returns the same value as `a.min(0, n)`, but in constant time.

### Constraints
- None

### Time Complexity
- $O(1)$

## all_max
```cpp
T a.all_max();
```

It returns the same value as `a.max(0, n)`, but in constant time.

### Constraints
- None

### Time Complexity
- $O(1)$

## all_sum
```cpp
T a.all_sum();
```

It returns the same value as `a.sum(0, n)`, but in constant time.

### Constraints
- None

### Time Complexity
- $O(1)$

## chmin
```cpp
(1) void a.chmin(int p, T x);
(2) void a.chmin(int l, int r, T x);
```

- (1)
    - It applies `a[p] = min(a[p], x)`.
- (2)
    - It applies `a[i] = min(a[i], x)` for all `i = l..r-1`.

### Constraints
- (1)
    - $0 \leq p < n$
- (2)
    - $0 \leq l \leq r \leq n$

### Time Complexity
- $O\left(\log^2 n\right)$ amortized
- $O(\log n)$ amortized if `add` is never called

## chmax
```cpp
(1) void a.chmax(int p, T x);
(2) void a.chmax(int l, int r, T x);
```

- (1)
    - It applies `a[p] = max(a[p], x)`.
- (2)
    - It applies `a[i] = max(a[i], x)` for all `i = l..r-1`.

### Constraints
- (1)
    - $0 \leq p < n$
- (2)
    - $0 \leq l \leq r \leq n$

### Time Complexity
- $O\left(\log^2 n\right)$ amortized
- $O(\log n)$ amortized if `add` is never called

## add
```cpp
(1) void a.add(int p, T x);
(2) void a.add(int l, int r, T x);
```

- (1)
    - It applies `a[p] = a[p] + x`.
- (2)
    - It applies `a[i] = a[i] + x` for all `i = l..r-1`.

### Constraints
- (1)
    - $0 \leq p < n$
- (2)
    - $0 \leq l \leq r \leq n$

### Time Complexity
- $O\left(\log^2 n\right)$ amortized

## max_right
```cpp
struct S {
  T lo, hi, lo2, hi2, sum, sz, nlo, nhi;
  bool fail;
};
int a.max_right<G>(int l, G g);
```

`S`, which is `preset_segtree_beats<T>::S`, summarizes an interval of the sequence.

- `lo`, `hi`: the minimum and the maximum of the interval, or `std::numeric_limits<T>::max()` and `std::numeric_limits<T>::min()` if the interval is empty
- `lo2`, `hi2`: the strict second minimum and the strict second maximum of the interval, or `std::numeric_limits<T>::max()` and `std::numeric_limits<T>::min()` if they do not exist
- `sum`: the sum of the interval
- `sz`: the number of the elements
- `nlo`, `nhi`: the number of the elements which are equal to `lo` and `hi`
- `fail`: the flag for `tools::segtree_beats`, which is always `false` in the value passed to `g`

Let $\mathrm{summary}(l, r)$ be the value of `S` which summarizes $[l, r)$.
It returns an index `r` that satisfies both of the followings.

- `r = l` or `g(summary(l, r)) = true`
- `r = n` or `g(summary(l, r + 1)) = false`

If `g` is monotone, this is the maximum `r` that satisfies `g(summary(l, r)) = true`.

### Constraints
- The function object that takes `S` as the argument and returns `bool` should be defined.
- if `g` is called with the same argument, it returns the same value, i.e., `g` has no side effect.
- `g(summary(l, l)) = true`
- $0 \leq l \leq n$

### Time Complexity
- $O\left(\log^2 n\right)$ amortized
- $O(\log n)$ amortized if `add` is never called

## min_left
```cpp
int a.min_left<G>(int r, G g);
```

`G` takes `S`, which is described in `max_right`.
It returns an index `l` that satisfies both of the followings.

- `l = r` or `g(summary(l, r)) = true`
- `l = 0` or `g(summary(l - 1, r)) = false`

If `g` is monotone, this is the minimum `l` that satisfies `g(summary(l, r)) = true`.

### Constraints
- The function object that takes `S` as the argument and returns `bool` should be defined.
- if `g` is called with the same argument, it returns the same value, i.e., `g` has no side effect.
- `g(summary(r, r)) = true`
- $0 \leq r \leq n$

### Time Complexity
- $O\left(\log^2 n\right)$ amortized
- $O(\log n)$ amortized if `add` is never called
