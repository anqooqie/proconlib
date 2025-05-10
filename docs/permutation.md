---
title: Permutation
documentation_of: //tools/permutation.hpp
---

It is a permutation of $n$ elements.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
(1) permutation<T> p(int n);
(2) permutation<T> p(std::ranges::range v);
```

It creates an identity permutation of $n$ elements.
The type parameter `<T>` represents the type of the elements.

### Constraints
- (1)
    - None
- (2)
    - All elements of $v$ are unique.
    - All elements of $v$ are $0$ or more.
    - All elements of $v$ are less than $n$ where $n = \|v\|$.

### Time Complexity
- $O(n)$

## size
```cpp
int p.size();
```

It returns $n$.

### Constraints
- None

### Time Complexity
- $O(1)$

## operator[]
```cpp
T p.operator[](int i);
```

It returns the position to which the $i$-th element mapped by the permutation.
In other words, the permutation maps the $i$-th element to the `p[i]`-th element.

### Constraints
- $0 \leq i < n$

### Time Complexity
- $O(1)$

## begin
```cpp
permutation<T>::iterator p.begin();
```

It returns the iterator pointing to the first element.
Note that `permutation<T>::iterator` is the read-only random access iterator referring to `T`.

### Constraints
- None

### Time Complexity
- $O(1)$

## end
```cpp
permutation<T>::iterator p.end();
```

It returns the iterator pointing to the element which would follow the last element.

### Constraints
- None

### Time Complexity
- $O(1)$

## swap_from_left
```cpp
permutation<T>& p.swap_from_left(int x, int y);
```

Let $p^\ast$ be $p$ just before the function call.
Let $q$ be the following permutation of $n$ elements.

$$\begin{align*}
q(i) &= \left\{\begin{array}{ll}
p^\ast(y) & \text{(if $i = x$)}\\
p^\ast(x) & \text{(if $i = y$)}\\
p^\ast(i) & \text{(otherwise)}
\end{array}\right.
\end{align*}$$

It updates $p$ to $q$, and returns the updated $p$.

### Constraints
- $0 \leq x < n$
- $0 \leq y < n$

### Time Complexity
- $O(1)$

## swap_from_right
```cpp
permutation<T>& p.swap_from_right(int x, int y);
```

Let $p^\ast$ be $p$ just before the function call.
Let $q$ be the following permutation of $n$ elements.

$$\begin{align*}
q(i) &= \left\{\begin{array}{ll}
y & \text{(if $p^\ast(i) = x$)}\\
x & \text{(if $p^\ast(i) = y$)}\\
p^\ast(i) & \text{(otherwise)}
\end{array}\right.
\end{align*}$$

It updates $p$ to $q$, and returns the updated $p$.

### Constraints
- $0 \leq x < n$
- $0 \leq y < n$

### Time Complexity
- $O(1)$

## id
```cpp
long long p.id();
```

It returns the number of permutations of $n$ elements less than $p$ in lexicographical order.

### Constraints
- None

### Time Complexity
- $O(n^2)$

## from
```cpp
permutation<T> permutation<T>::from(int n, long long id);
```

It returns the permutation of $n$ elements $p$, such that `p.id() == id`.

### Constraints
- $0 \leq \mathrm{id} < n!$

### Time Complexity
- $O(n^2)$

## inv
```cpp
(1) tools::permutation<T> p.inv();
(2) tools::permutation<T> p.inv(int i);
```

- (1)
    - It returns $p^{-1}$.
    - $p^{-1}$ maps the `p[i]`-th element to the $i$-th element.
- (2)
    - It returns the position that the permutation maps to the $i$-th element.
    - In other words, the permutation maps the `p.inv(i)`-th element to the $i$-th element.

### Constraints
- (1)
    - None
- (2)
    - $0 \leq i < n$

### Time Complexity
- (1)
    - $O(n)$
- (2)
    - $O(1)$

## inv_inplace
```cpp
tools::permutation<T>& p.inv_inplace();
```

It updates $p$ to $p^{-1}$, and returns the updated $p$.

### Constraints
- None

### Time Complexity
- $O(1)$

## operator*
```cpp
tools::permutation<T> operator*(permutation<T> p1, permutation<T> p2);
```

It returns the merged permutation $p_3 = p_1 \circ p_2$.
$p_3$ maps the $i$-th element to the `p2[p1[i]]`-th element.

### Constraints
- `p1.size() == p2.size()`

### Time Complexity
- $O(n)$

## operator*=
```cpp
tools::permutation<T>& p1.operator*=(permutation<T> p2);
```

It updates $p_1$ to $p_1 \circ p_2$, and returns the updated $p_1$.

### Constraints
- `p1.size() == p2.size()`

### Time Complexity
- $O(n)$
