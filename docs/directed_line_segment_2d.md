---
title: Two-dimensional directed line segment
documentation_of: //tools/directed_line_segment_2d.hpp
---

It is a directed line segment from a point $p_1$ to another point $p_2$.
It is available on not only built-in numerical types but also `tools::bigint` and `tools::rational`.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
directed_line_segment_2d<T> s(tools::vector2<T> p1, tools::vector2<T> p2);
```

It creates a directed line segment from a point $p_1$ to another point $p_2$.

### Constraints
- $p_1 \neq p_2$

### Time Complexity
- $O(1)$ if `<T>` is a built-in numerical type

## contains
```cpp
bool s.contains(tools::vector2<T> p);
```

It returns whether $p$ is in $s$ or not.

### Constraints
- None

### Time Complexity
- $O(1)$ if `<T>` is a built-in numerical type

## length
```cpp
std::conditional_t<std::is_floating_point_v<T>, T, double> s.length();
```

It returns the length of $s$.

### Constraints
- None

### Time Complexity
- $O(1)$ if `<T>` is a built-in numerical type

## cross_point
```cpp
std::optional<tools::vector2<T>> s.cross_point(directed_line_segment_2d<T> t);
std::optional<tools::vector2<T>> s.cross_point(tools::half_line_2d<T> t);
std::optional<tools::vector2<T>> s.cross_point(tools::line_2d<T> t);
```

If $s$ and $t$ intersects at one point, it returns the point.
Otherwise, it returns `std::nullopt`.

### Constraints
- `<T>` is `tools::rational` or a built-in floating point type.

### Time Complexity
- $O(1)$ if `<T>` is a built-in numerical type

## midpoint
```cpp
tools::vector2<T> s.midpoint();
```

It returns the midpoint of $s$.

### Constraints
- `<T>` is `tools::rational` or a built-in floating point type.

### Time Complexity
- $O(1)$ if `<T>` is a built-in numerical type

## p1
```cpp
tools::vector2<T> s.p1();
```

It returns $p_1$.

### Constraints
- None

### Time Complexity
- $O(1)$ if `<T>` is a built-in numerical type

## p2
```cpp
tools::vector2<T> s.p2();
```

It returns $p_2$.

### Constraints
- None

### Time Complexity
- $O(1)$ if `<T>` is a built-in numerical type

## squared_distance
```cpp
T s.squared_distance(directed_line_segment_2d<T> t);
T s.squared_distance(tools::vector2<T> t);
```

It returns the squared distance of $s$ and $t$.

### Constraints
- `<T>` is `tools::rational` or a built-in floating point type.

### Time Complexity
- $O(1)$ if `<T>` is a built-in numerical type

## squared_length
```cpp
T s.squared_length();
```

It returns the squared length of $s$.

### Constraints
- None

### Time Complexity
- $O(1)$ if `<T>` is a built-in numerical type

## to_half_line
```cpp
tools::half_line_2d<T> s.to_half_line();
```

It returns the half line from $p1$ through $p2$.

### Constraints
- None

### Time Complexity
- $O(1)$ if `<T>` is a built-in numerical type

## to_line
```cpp
tools::line_2d<T> s.to_line();
```

It returns the line through $p1$ and $p2$.

### Constraints
- None

### Time Complexity
- $O(1)$ if `<T>` is a built-in numerical type

## to_vector
```cpp
tools::vector2<T> s.to_vector();
```

It returns $p2 - p1$.

### Constraints
- None

### Time Complexity
- $O(1)$ if `<T>` is a built-in numerical type

## operator+
```cpp
directed_line_segment_2d<T> s.operator+();
```

It returns $s$.

### Constraints
- None

### Time Complexity
- $O(1)$ if `<T>` is a built-in numerical type

## operator-
```cpp
directed_line_segment_2d<T> s.operator-();
```

It returns the directed line segment from $p_2$ to $p_1$.

### Constraints
- None

### Time Complexity
- $O(1)$ if `<T>` is a built-in numerical type

## operator&
```cpp
std::optional<std::variant<tools::vector2<T>, directed_line_segment_2d<T>>> operator&(directed_line_segment_2d<T> s, directed_line_segment_2d<T> t);
std::optional<std::variant<tools::vector2<T>, directed_line_segment_2d<T>>> operator&(directed_line_segment_2d<T> s, tools::half_line_2d<T> t);
std::optional<std::variant<tools::vector2<T>, directed_line_segment_2d<T>>> operator&(directed_line_segment_2d<T> s, tools::line_2d<T> t);
```

If there is an intersection of $s$ and $t$, it returns the intersection.
Otherwise, it returns `std::nullopt`.

### Constraints
- `<T>` is `tools::rational` or a built-in floating point type.

### Time Complexity
- $O(1)$ if `<T>` is a built-in numerical type

## operator==
```cpp
bool operator==(directed_line_segment_2d<T> s, directed_line_segment_2d<T> t);
```

It returns whether $s$ is identical to $t$ including their directions or not.

### Constraints
- None

### Time Complexity
- $O(1)$ if `<T>` is a built-in numerical type

## operator!=
```cpp
bool operator!=(directed_line_segment_2d<T> s, directed_line_segment_2d<T> t);
```

It returns `!(s == t)`.

### Constraints
- None

### Time Complexity
- $O(1)$ if `<T>` is a built-in numerical type
