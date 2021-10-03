---
title: 2D vector
documentation_of: //tools/vector2.hpp
---

It is a two-dimensional vector.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
(1) vector2<T> v();
(2) vector2<T> v(T x, T y);
```

- (1)
    - It creates a vector $(0, 0)$.
- (2)
    - It creates a vector whose coordinates are the specified values.

The type parameter `<T>` represents the type of the coordinates.

### Constraints
- None

### Time Complexity
- $O(1)$

## x
```cpp
T v.x;
```

It is the x-coordinate of the vector.

## y
```cpp
T v.y;
```

It is the y-coordinate of the vector.

## norm
```cpp
double v.norm();
```

It returns $\left\|\overrightarrow{v}\right\| = \sqrt{x^2 + y^2}$.

### Constraints
- None

### Time Complexity
- $O(1)$

## squared_norm
```cpp
T v.squared_norm();
```

It returns $\overrightarrow{v} \cdot \overrightarrow{v} = x^2 + y^2$.

### Constraints
- None

### Time Complexity
- $O(1)$

## normalized
```cpp
tools::vector2<double> v.normalized();
```

It returns $\frac{\overrightarrow{v}}{\left\|\overrightarrow{v}\right\|}$.

### Constraints
- `<T>` is `double`

### Time Complexity
- $O(1)$

## inner_product
```cpp
T v.inner_product(tools::vector2<T> u);
```

It returns $\overrightarrow{v} \cdot \overrightarrow{u}$.

### Constraints
- None

### Time Complexity
- $O(1)$

## outer_product
```cpp
T v.outer_product(tools::vector2<T> u);
```

It returns $\left\|\overrightarrow{v} \times \overrightarrow{u}\right\|$.

### Constraints
- None

### Time Complexity
- $O(1)$

## Arithmetic operations
```cpp
(1) tools::vector2<T> +v;
(2) tools::vector2<T> -v;
(3) tools::vector2<T> v + u;
(4) tools::vector2<T> v - u;
(5) tools::vector2<T> v * c;
(6) tools::vector2<T> c * v;
(7) tools::vector2<T> v / c;
(8) tools::vector2<T>& v += u;
(9) tools::vector2<T>& v -= u;
(10) tools::vector2<T>& v *= c;
(11) tools::vector2<T>& v /= c;
(12) bool v == u;
(13) bool v != u;
```

It supports basic arithmetic operations on vectors where $\overrightarrow{u}$ is another vector and $c$ is a scholar value.

### Constraints
- (7), (11)
    - $c \neq 0$

### Time Complexity
- $O(1)$

## four_directions
```cpp
std::array<vector2<T>, 4> vector2<T>::four_directions();
```

It returns vectors $\left(\cos\left(\frac{i}{2}\pi\right), \sin\left(\frac{i}{2}\pi\right)\right)$ for $0 \leq i < 4$.

### Constraints
- None

### Time Complexity
- $O(1)$

## eight_directions
```cpp
std::array<vector2<T>, 8> vector2<T>::eight_directions();
```

It returns vectors $\left(\mathrm{RI}\left(\cos\left(\frac{i}{4}\pi\right)\right), \mathrm{RI}\left(\sin\left(\frac{i}{4}\pi\right)\right)\right)$ for $0 \leq i < 8$ where $\mathrm{RI}(x)$ rounds $x$ towards infinity.

### Constraints
- None

### Time Complexity
- $O(1)$
