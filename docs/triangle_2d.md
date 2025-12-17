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
template <typename T, bool Filled>
template <std::ranges::input_range R>
requires std::assignable_from<tools::vector2<T>&, std::ranges::range_reference_t<R>>
triangle_2d<T, Filled> s(R&& p);

(2)
template <typename T, bool Filled>
triangle_2d<T, Filled> s(std::initializer_list<tools::vector2<T>> p);
```

It creates a triangle.
If `Filled` is `true`, it consists of both the boundary and the interior.
If `Filled` is `false`, it consists only of the boundary.

### Constraints
- $\|p\| = 3$
- $p_0$, $p_1$ and $p_2$ are distinct.
- $p_0$, $p_1$ and $p_2$ are not on the same line.

### Time Complexity
- $O(1)$ if `<T>` is a built-in numerical type

## area
```cpp
T s.area();
```

It returns the area of $s$.

### Constraints
- `<T>` is `tools::rational` or a built-in floating point type.
- `<Filled>` is `true`.

### Time Complexity
- $O(1)$ if `<T>` is a built-in numerical type

## circumcircle
```cpp
tools::circumcircle_2d<T, Filled> s.circumcircle();
```

It returns the circumcircle of $s$.

### Constraints
- None

### Time Complexity
- $O(1)$ if `<T>` is a built-in numerical type

## doubled_area
```cpp
T s.doubled_area();
```

It returns the doubled area of $s$.

### Constraints
- `<Filled>` is `true`.

### Time Complexity
- $O(1)$ if `<T>` is a built-in numerical type

## incircle
```cpp
tools::circle_2d<T, Filled> s.incircle();
```

It returns the incircle of $s$.

### Constraints
- `<T>` is a built-in floating point type.

### Time Complexity
- $O(1)$

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
tools::circumcircle_2d<T, Filled> s.minimum_bounding_circle();
```

It returns the minimum bounding circle of $s$.

### Constraints
- None

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
-1 & \text{(if $p$ is on the outside of $s$)}\\
0 & \text{(if $p$ is on the edge of $s$)}\\
1 & \text{(if $p$ is on the inside of $s$)}
\end{array}\right.&
\end{align*}$$

### Constraints
- None

### Time Complexity
- $O(1)$ if `<T>` is a built-in numerical type
