---
title: Persistent array
documentation_of: //tools/persistent_array.hpp
---

It is a persistent array.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
(1) persistent_array<T> a();
(2) persistent_array<T> a(int n);
(3) persistent_array<T> a(int n, T x);
(4) persistent_array<T> a(std::ranges::input_range auto&& r);
(5) persistent_array<T> a(std::initializer_list<T> il);
```

- (1)
    - It creates an empty array.
- (2)
    - It creates an array of length $n$ filled with `T{}`.
- (3)
    - It creates an array of length $n$ filled with $x$.
- (4)
    - It creates an array from `r`.
- (5)
    - It creates an array from `il`.

### Constraints
- (2), (3)
    - $n \geq 0$

### Time Complexity
- (1)
    - $O(1)$
- (2), (3)
    - $O(\log n)$
- (4), (5)
    - $O(n)$

## empty
```cpp
bool a.empty();
```

It returns whether $a$ is empty.

### Constraints
- None

### Time Complexity
- $O(1)$

## size
```cpp
int a.size();
```

It returns $\|a\|$.

### Constraints
- None

### Time Complexity
- $O(1)$

## operator[]
```cpp
T a.operator[](int i);
```

It returns $a_i$.

### Constraints
- $0 \leq i < \|a\|$

### Time Complexity
- $O(\log \|a\|)$

## set
```cpp
persistent_array<T> a.set(int p, T x);
```

It returns another array $b$ of length $\|a\|$ where

$$\begin{align*}
b_i &= \left\{\begin{array}{ll}
x & \text{(if $i = p$)}\\
a_i & \text{(if $i \neq p$)}
\end{array}\right.
\end{align*}$$

### Constraints
- $0 \leq p < \|a\|$

### Time Complexity
- $O(\log \|a\|)$

## push_back
```cpp
persistent_array<T> a.push_back(T x);
```

It returns another array $b$ of length $\|a\| + 1$ where

$$\begin{align*}
b_i &= \left\{\begin{array}{ll}
a_i & \text{(if $i < |a|$)}\\
x & \text{(if $i = |a|$)}
\end{array}\right.
\end{align*}$$

### Constraints
- None

### Time Complexity
- $O(\log \|a\|)$

## pop_back
```cpp
persistent_array<T> a.pop_back();
```

It returns another array $b$ of length $\|a\| - 1$ where

$$\begin{align*}
b_i &= a_i
\end{align*}$$

### Constraints
- $\|a\| \geq 1$

### Time Complexity
- $O(\log \|a\|)$

## operator std::vector<T>
```cpp
static_cast<std::vector<T>>(a);
```

It returns $a$ as `std::vector<T>`.

### Constraints
- None

### Time Complexity
- $O(\|a\|)$
