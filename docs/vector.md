---
title: Vector
documentation_of: //tools/vector.hpp
---

It is a $n$-dimensional vector.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
(1) vector<T> v(std::size_t n);
(2) vector<T> v(std::size_t n, T x);
```

- (1)
    - It creates a $n$-dimensional vector.
- (2)
    - It creates a $n$-dimensional vector, of which all the elements $x$.

The type parameter `<T>` represents the type of the elements.

### Constraints
- None

### Time Complexity
- $O(n)$

## operator[]
```cpp
T& v[std::size_t i];
```

It is the $i$-th element of the vector.

### Constraints
- $0 \leq i < n$

### Time Complexity
- $O(1)$

## dim
```cpp
std::size_t v.dim();
```

It returns the dimension of the vector.

### Constraints
- None

### Time Complexity
- $O(1)$

## l1_norm
```cpp
T v.l1_norm();
```

It returns $\left\\|\overrightarrow{v}\right\\|_1$.

### Constraints
- None

### Time Complexity
- $O(n)$

## l2_norm
```cpp
std::is_conditional_t<std::is_floating_point_v<T>, T, double> v.l2_norm();
```

It returns $\left\\|\overrightarrow{v}\right\\|_2$.

### Constraints
- None

### Time Complexity
- $O(n)$

## squared_l2_norm
```cpp
T v.squared_l2_norm();
```

It returns $\left\\|\overrightarrow{v}\right\\|_2^2 = \overrightarrow{v} \cdot \overrightarrow{v}$.

### Constraints
- None

### Time Complexity
- $O(n)$

## normalized
```cpp
vector<T> v.normalized();
```

It returns $\frac{\overrightarrow{v}}{\left\\|\overrightarrow{v}\right\\|_2}$.

### Constraints
- `std::is_floating_point_v<T>` is `true`

### Time Complexity
- $O(n)$

## inner_product
```cpp
T v.inner_product(vector<T> u);
```

It returns $\overrightarrow{v} \cdot \overrightarrow{u}$.

### Constraints
- The dimension of $\overrightarrow{u}$ is equal to the dimension of $\overrightarrow{v}$.

### Time Complexity
- $O(n)$

## Arithmetic operations
```cpp
(1) vector<T> +v;
(2) vector<T> -v;
(3) vector<T> v + u;
(4) vector<T> v - u;
(5) vector<T> v * c;
(6) vector<T> c * v;
(7) vector<T> v / c;
(8) vector<T>& v += u;
(9) vector<T>& v -= u;
(10) vector<T>& v *= c;
(11) vector<T>& v /= c;
(12) bool v == u;
(13) bool v != u;
```

It supports basic arithmetic operations on vectors where $\overrightarrow{u}$ is another $n$-dimensional vector and $c$ is a scholar value.

### Constraints
- (3), (4), (8), (9), (12), (13)
    - The dimension of $\overrightarrow{u}$ is equal to the dimension of $\overrightarrow{v}$.
- (7), (11)
    - $c \neq 0$

### Time Complexity
- $O(n)$
