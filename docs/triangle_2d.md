---
title: Two-dimensional triangle
documentation_of: //tools/triangle_2d.hpp
---

It is a triangle which consists of 3 points $p_0, p_1, p_2$.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
(1)
template <typename T> template <typename InputIterator>
triangle_2d<T> s(InputIterator begin, InputIterator end);

(2)
template <typename T>
triangle_2d<T> s(std::initializer_list<tools::vector2<T>> init);
```

It creates a triangle.

### Constraints
- (1)
    - $\mathrm{end} - \mathrm{begin} = 3$
- (2)
    - `init.size()` $= 3$

### Time Complexity
- $O(1)$ if `<T>` is a built-in numerical type

## area
```cpp
T s.area();
```

It returns the area of $s$.

### Constraints
- `<T>` is `tools::rational` or a built-in floating point type.

### Time Complexity
- $O(1)$ if `<T>` is a built-in numerical type

## circumcircle
```cpp
std::pair<tools::vector2<T>, T> s.circumcircle();
```

It returns the center and the squared radius of the circumcircle of $s$.

### Constraints
- `<T>` is `tools::rational` or a built-in floating point type.

### Time Complexity
- $O(1)$ if `<T>` is a built-in numerical type

## doubled_area
```cpp
T s.doubled_area();
```

It returns the doubled area of $s$.

### Constraints
- None

### Time Complexity
- $O(1)$ if `<T>` is a built-in numerical type

## is_counterclockwise
```cpp
bool s.is_counterclockwise();
```

It returns whether $s$ is counterclockwise or not.

### Constraints
- None

### Time Complexity
- $O(1)$ if `<T>` is a built-in numerical type

## minimum_bounding_circle
```cpp
std::pair<tools::vector2<T>, T> s.minimum_bounding_circle();
```

It returns the center and the squared radius of the minimum bounding circle of $s$.

### Constraints
- `<T>` is `tools::rational` or a built-in floating point type.

### Time Complexity
- $O(1)$ if `<T>` is a built-in numerical type

## type
```cpp
int s.type();
```

It returns

$$\begin{align*}
\left\{\begin{array}{ll}
0 & \text{(if $s$ is acute)}\\
1 & \text{(if $s$ is right)}\\
2 & \text{(if $s$ is obtuse)}
\end{array}\right.&
\end{align*}$$

### Constraints
- None

### Time Complexity
- $O(1)$ if `<T>` is a built-in numerical type

## where
```cpp
int s.where(tools::vector2<T> p);
```

It returns

$$\begin{align*}
\left\{\begin{array}{ll}
0 & \text{(if $p$ is on the outside of $s$)}\\
1 & \text{(if $p$ is on the edge of $s$)}\\
2 & \text{(if $p$ is on the inside of $s$)}
\end{array}\right.&
\end{align*}$$

### Constraints
- None

### Time Complexity
- $O(1)$ if `<T>` is a built-in numerical type
