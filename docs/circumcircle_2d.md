---
title: Two-dimensional circumcircle
documentation_of: //tools/circumcircle_2d.hpp
---

It is a circle with line segment $p_0 p_1$ as its diameter, or the circumcircle of triangle $p_0 p_1 p_2$.

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
circumcircle_2d<T, Filled> c(R&& p);

(2)
template <typename T, bool Filled>
circumcircle_2d<T, Filled> c(std::initializer_list<tools::vector2<T>> p);
```

If $\|p\| = 2$, it creates a circle with line segment $p_0 p_1$ as its diameter.
If $\|p\| = 3$, it creates the circumcircle of triangle $p_0 p_1 p_2$.

If `Filled` is `true`, it consists of both the boundary and the interior.
If `Filled` is `false`, it consists only of the boundary.

### Constraints
- $\|p\| \in \{2, 3\}$
- $i \neq j \Rightarrow p_i \neq p_j$
- If $\|p\| = 3$, $p_0$, $p_1$ and $p_2$ are not on the same line.

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
- $O(1)$

## center
```cpp
tools::vector2<T> c.center();
```

It returns the center of $c$.

### Constraints
- `<T>` is a built-in floating point type or `tools::rational`.

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

## points
```cpp
std::vector<tools::vector2<T>> c.points();
```

It returns $p$.

### Constraints
- None

### Time Complexity
- $O(1)$

## radius
```cpp
T c.radius();
```

It returns the radius of $c$.

### Constraints
- `<T>` is a built-in floating point type.

### Time Complexity
- $O(1)$

## squared_radius
```cpp
T c.squared_radius();
```

It returns the squared radius of $c$.

### Constraints
- `<T>` is a built-in floating point type or `tools::rational`.

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
