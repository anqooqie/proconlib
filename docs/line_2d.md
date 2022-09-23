---
title: Two-dimensional line
documentation_of: //tools/line_2d.hpp
---

It is a line $ax + by + c = 0$.
It is available on not only built-in numerical types but also `tools::bigint` and `tools::rational`.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
line_2d<T> s(tools::vector2<T> a, tools::vector2<T> b, tools::vector2<T> c);
```

It creates a line $ax + by + c = 0$.

### Constraints
- $(a, b) \neq (0, 0)$

### Time Complexity
- $O(1)$ if `<T>` is a built-in numerical type

## a
```cpp
T s.a();
```

It returns $a$.

### Constraints
- None

### Time Complexity
- $O(1)$ if `<T>` is a built-in numerical type

## b
```cpp
T s.b();
```

It returns $b$.

### Constraints
- None

### Time Complexity
- $O(1)$ if `<T>` is a built-in numerical type

## c
```cpp
T s.c();
```

It returns $c$.

### Constraints
- None

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

## cross_point
```cpp
std::optional<tools::vector2<T>> s.cross_point(tools::directed_line_segment_2d<T> t);
std::optional<tools::vector2<T>> s.cross_point(tools::half_line_2d<T> t);
std::optional<tools::vector2<T>> s.cross_point(line_2d<T> t);
```

If $s$ and $t$ intersects at one point, it returns the point.
Otherwise, it returns `std::nullopt`.

### Constraints
- `<T>` is `tools::rational` or a built-in floating point type.

### Time Complexity
- $O(1)$ if `<T>` is a built-in numerical type

## crosses
```cpp
bool s.crosses(line_2d<T> t);
```

It returns whether $s$ and $t$ intersects at one point or not.

### Constraints
- None

### Time Complexity
- $O(1)$ if `<T>` is a built-in numerical type

## is_parallel_to
```cpp
bool s.is_parallel_to(line_2d<T> t);
```

It returns whether $s$ is parallel to $t$ or not.
Note that it returns `true` if $s$ is identical to $t$.

### Constraints
- None

### Time Complexity
- $O(1)$ if `<T>` is a built-in numerical type

## normal
```cpp
tools::vector2<T> s.normal();
```

It returns $(a, b)$.

### Constraints
- None

### Time Complexity
- $O(1)$ if `<T>` is a built-in numerical type

## projection
```cpp
tools::vector2<T> s.projection(tools::vector2<T> p);
```

It returns the projection point of $p$ onto $s$.

### Constraints
- `<T>` is `tools::rational` or a built-in floating point type.

### Time Complexity
- $O(1)$ if `<T>` is a built-in numerical type

## squared_distance
```cpp
T s.squared_distance(tools::directed_line_segment_2d<T> t);
T s.squared_distance(tools::half_line_2d<T> t);
T s.squared_distance(line_2d<T> t);
T s.squared_distance(tools::vector2<T> t);
```

It returns the squared distance between $s$ and $t$.

### Constraints
- `<T>` is `tools::rational` or a built-in floating point type.

### Time Complexity
- $O(1)$ if `<T>` is a built-in numerical type

## operator&
```cpp
std::optional<std::variant<tools::vector2<T>, tools::directed_line_segment_2d<T>>> operator&(line_2d<T> s, tools::directed_line_segment_2d<T> t);
std::optional<std::variant<tools::vector2<T>, tools::half_line_2d<T>>> operator&(line_2d<T> s, tools::half_line_2d<T> t);
std::optional<std::variant<tools::vector2<T>, line_2d<T>>> operator&(line_2d<T> s, line_2d<T> t);
```

If there is an intersection of $s$ and $t$, it returns the intersection.
Otherwise, it returns `std::nullopt`.

### Constraints
- `<T>` is `tools::rational` or a built-in floating point type.

### Time Complexity
- $O(1)$ if `<T>` is a built-in numerical type

## operator==
```cpp
bool operator==(line_2d<T> s, line_2d<T> t);
```

It returns whether $s$ is identical to $t$ or not.

### Constraints
- None

### Time Complexity
- $O(1)$ if `<T>` is a built-in numerical type

## operator!=
```cpp
bool operator!=(line_2d<T> s, line_2d<T> t);
```

It returns `!(s == t)`.

### Constraints
- None

### Time Complexity
- $O(1)$ if `<T>` is a built-in numerical type

## through
```cpp
line_2d<T> line_2d<T>::through(tools::vector2<T> p1, tools::vector2<T> p2);
```

It returns the line through $p_1$ and $p_2$.

### Constraints
- $p_1 \neq p_2$

### Time Complexity
- $O(1)$ if `<T>` is a built-in numerical type
