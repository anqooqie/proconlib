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
(1)
template <typename T>
circle_2d<T> c(tools::vector2<T> o, T r);

(2)
template <typename T, bool HasRadius>
circle_2d<T, true> c(tools::vector2<T> o, T r);

(3)
template <typename T, bool HasRadius>
circle_2d<T, false> c(tools::vector2<T> o, T r2);
```

- (1)
    - It is same as (2).
- (2)
    - It creates a circle with center $o$ and radius $r$.
- (3)
    - It creates a circle with center $o$ and radius $\sqrt{r^2}$.

### Constraints
- (1), (2)
    - $r > 0$
- (3)
    - $r^2 > 0$

### Time Complexity
- $O(1)$ if `<T>` is a built-in numerical type

## area
```cpp
std::conditional<std::is_floating_point_v<T>, T, double> c.area();
```

It returns the area of $c$.

### Constraints
- None

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
bool c.squared_radius();
```

It returns $r^2$.

### Constraints
- None

### Time Complexity
- $O(1)$ if `<T>` is a built-in numerical type

## where
```cpp
std::pair<int, int> c1.where(circle_2d<T, HasRadius> c2);
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

## operator==
```cpp
bool operator==(circle_2d<T, HasRadius> c1, circle_2d<T, HasRadius> c2);
```

It returns whether $c_1$ is identical to $c_2$ or not.

### Constraints
- None

### Time Complexity
- $O(1)$ if `<T>` is a built-in numerical type

## operator!=
```cpp
bool operator!=(circle_2d<T, HasRadius> c1, circle_2d<T, HasRadius> c2);
```

It returns `!(c1 == c2)`.

### Constraints
- None

### Time Complexity
- $O(1)$ if `<T>` is a built-in numerical type
