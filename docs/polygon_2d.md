---
title: Two-dimensional polygon
documentation_of: //tools/polygon_2d.hpp
---

It is a polygon which consists of $n$ points $p_0, p_1, \ldots, p_{n - 1}$.

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
polygon_2d<T, Filled> s(R&& p);

(2)
template <typename T, bool Filled>
polygon_2d<T, Filled> s(std::initializer_list<tools::vector2<T>> p);
```

It creates a polygon.
If `Filled` is `true`, it consists of both the boundary and the interior.
If `Filled` is `false`, it consists only of the boundary.

### Constraints
- $n \geq 3$

### Time Complexity
- $O(n)$ if `<T>` is a built-in numerical type

## area
```cpp
T s.area();
```

It returns the area of $s$.

### Constraints
- `<T>` is `tools::rational` or a built-in floating point type.
- `<Filled>` is `true`.

### Time Complexity
- $O(n)$ if `<T>` is a built-in numerical type

## doubled_area
```cpp
T s.doubled_area();
```

It returns the doubled area of $s$.

### Constraints
- `<Filled>` is `true`.

### Time Complexity
- $O(n)$ if `<T>` is a built-in numerical type

## is_counterclockwise
```cpp
bool s.is_counterclockwise();
```

It returns whether $s$ is counterclockwise or not.

### Constraints
- None

### Time Complexity
- $O(n)$ if `<T>` is a built-in numerical type

## minimum_bounding_circle
```cpp
tools::circumcircle_2d<T, Filled> s.minimum_bounding_circle();
```

It returns the minimum bounding circle of $s$.

### Constraints
- None

### Time Complexity
- $O(n)$ expected if `<T>` is a built-in numerical type

## points
```cpp
std::vector<tools::vector2<T>> s.points();
```

It returns $p$.

### Constraints
- None

### Time Complexity
- $O(1)$

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
- $O(n)$ if `<T>` is a built-in numerical type
