---
title: Second-order difference array
documentation_of: //tools/second_order_imos.hpp
---

It is an array with an auxiliary second-order difference array for executing queries that add arithmetic sequences.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
template <tools::non_bool_integral T>
second_order_imos<T> a(int n = 0);
```

It creates an array of type `T` and length $n$ filled with $0$.
You can get $a_i$ in the order $i = 0, 1, \ldots, {n - 1}$.
Once $a_i$ is got, it is fixed and cannot be updated thereafter.

### Constraints
- $n \geq 0$

### Time Complexity
- $O(n)$

## size
```cpp
int a.size();
```

It returns $n$.

### Constraints
- None

### Time Complexity
- $O(1)$

## operator[]
```cpp
const T& a.operator[](int i);
```

It returns the const reference to $a_i$.

### Constraints
- $0 \leq i < n$

### Time Complexity
- $O(1)$ amortized

## add
```cpp
void a.add(int l, int r, T x, T d);
```

It performs a query that $a_i \leftarrow a_i + x + (i - l) d$ for each $i$ such that $l \leq i < r$.

### Constraints
- $0 \leq l \leq r \leq n$
- $i^\ast < l$ where $i^\ast$ is the largest $i$ in `a[i]` called so far or $-1$ (if you have not called it so far).

### Time Complexity
- $O(1)$
