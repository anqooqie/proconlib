---
title: Two-dimensional circle
documentation_of: //tools/circle_2d.hpp
---

It is a circle.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
template <typename T, bool Filled, bool HasRadius = true>
circle_2d<T, Filled, HasRadius> c(tools::vector2<T> o, T x);
```

It creates a circle with center $o$.
If `Filled` is `true`, it consists of both the boundary and the interior.
If `Filled` is `false`, it consists only of the boundary.
If `HasRadius` is `true`, the radius of it is $x$.
If `HasRadius` is `false`, the radius of it is $\sqrt{x}$.

### Constraints
- $x > 0$

### Time Complexity
- $O(1)$ if `<T>` is a built-in numerical type

## area
```cpp
T c.area();
```

It returns the area of $c$.

### Constraints
- `<T>` is a built-in floating point type.
- `<Filled>` is `true`.

### Time Complexity
- $O(1)$ if `<T>` is a built-in numerical type

## center
```cpp
tools::vector2<T> c.center();
```

It returns $o$.

### Constraints
- None

### Time Complexity
- $O(1)$ if `<T>` is a built-in numerical type

## contains
```cpp
bool c.contains(tools::vector2<T> p);
```

If `Filled` is `true`, it returns whether $p$ is on the boundary of $c$ or in the interior of $c$.
If `Filled` is `false`, it returns whether $p$ is on the boundary of $c$.

### Constraints
- None

### Time Complexity
- $O(1)$ if `<T>` is a built-in numerical type

## radius
```cpp
T c.radius();
```

It returns $r$.

### Constraints
- `HasRadius` is `true`.

### Time Complexity
- $O(1)$ if `<T>` is a built-in numerical type

## squared_radius
```cpp
T c.squared_radius();
```

It returns $r^2$.

### Constraints
- None

### Time Complexity
- $O(1)$ if `<T>` is a built-in numerical type

## where
```cpp
std::pair<int, int> c1.where(circle_2d<T, Filled, HasRadius> c2);
```

It returns the number of common tangent lines between $c_1$ and $c_2$ and the sign of $r_1 - r_2$.
In other words, it returns

$$\begin{align*}
\left\{\begin{array}{ll}
(0, -1) & \text{(if $c_2$ includes $c_1$)}\\
(0, 1) & \text{(if $c_1$ includes $c_2$)}\\
(1, -1) & \text{(if $c_1$ is inscribed in $c_2$)}\\
(1, 1) & \text{(if $c_2$ is inscribed in $c_1$)}\\
(2, -1) & \text{(if $c_1$ and $c_2$ intersects and $r_1 < r_2$)}\\
(2, 0) & \text{(if $c_1$ and $c_2$ intersects and $r_1 = r_2$)}\\
(2, 1) & \text{(if $c_1$ and $c_2$ intersects and $r_1 > r_2$)}\\
(3, -1) & \text{(if $c_1$ and $c_2$ are cicumscribed and $r_1 < r_2$)}\\
(3, 0) & \text{(if $c_1$ and $c_2$ are cicumscribed and $r_1 = r_2$)}\\
(3, 1) & \text{(if $c_1$ and $c_2$ are cicumscribed and $r_1 > r_2$)}\\
(4, -1) & \text{(if $c_1$ and $c_2$ do not cross and $r_1 < r_2$)}\\
(4, 0) & \text{(if $c_1$ and $c_2$ do not cross and $r_1 = r_2$)}\\
(4, 1) & \text{(if $c_1$ and $c_2$ do not cross and $r_1 > r_2$)}\\
(\infty, 0) & \text{(if $c_1$ is identical to $c_2$)}
\end{array}\right.&
\end{align*}$$

### Constraints
- None

### Time Complexity
- $O(1)$ if `<T>` is a built-in numerical type

## where
```cpp
int c.where(tools::vector2<T> p);
```

It returns

$$\begin{align*}
\left\{\begin{array}{ll}
-1 & \text{(if $p$ is on the outside of $c$)}\\
0 & \text{(if $p$ is on the edge of $c$)}\\
1 & \text{(if $p$ is on the inside of $c$)}
\end{array}\right.&
\end{align*}$$

### Constraints
- None

### Time Complexity
- $O(1)$ if `<T>` is a built-in numerical type

## operator&
```cpp
(1) std::optional<std::variant<circle_2d<T, false, HasRadius>, std::vector<tools::vector2<T>>>> operator&(circle_2d<T, false, HasRadius> s, circle_2d<T, false, HasRadius> t);
(2) std::vector<tools::vector2<T>> operator&(circle_2d<T, false> s, tools::line_2d<T> t);
(3) std::optional<std::variant<tools::vector2<T>, tools::directed_line_segment_2d<T>>> operator&(circle_2d<T, true> s, tools::line_2d<T> t);
```

- (1)
    - If there are intersections of $s$ and $t$, it returns the intersections. Otherwise, it returns `std::nullopt`.
- (2)
    - It returns the intersections of $s$ and $t$.
- (3)
    - If there is an intersection of $s$ and $t$, it returns the intersection. Otherwise, it returns `std::nullopt`.

### Constraints
- `<T>` is a built-in floating point type.

### Time Complexity
- $O(1)$ if `<T>` is a built-in numerical type

## operator==
```cpp
bool operator==(circle_2d<T, Filled, HasRadius> c1, circle_2d<T, Filled, HasRadius> c2);
```

It returns whether $c_1$ is identical to $c_2$ or not.

### Constraints
- None

### Time Complexity
- $O(1)$ if `<T>` is a built-in numerical type

## operator!=
```cpp
bool operator!=(circle_2d<T, Filled, HasRadius> c1, circle_2d<T, Filled, HasRadius> c2);
```

It returns `!(c1 == c2)`.

### Constraints
- None

### Time Complexity
- $O(1)$ if `<T>` is a built-in numerical type
