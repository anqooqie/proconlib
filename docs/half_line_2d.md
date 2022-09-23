---
title: Two-dimensional half line
documentation_of: //tools/half_line_2d.hpp
---

It is a half line from a point $a$ in a direction $d$.
It is available on not only built-in numerical types but also `tools::bigint` and `tools::rational`.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
half_line_2d<T> s(tools::vector2<T> a, tools::vector2<T> d);
```

It creates a half line from a point $a$ in a direction $d$.

### Constraints
- $d \neq (0, 0)$

### Time Complexity
- $O(1)$ if `<T>` is a built-in numerical type

## a
```cpp
tools::vector2<T> s.a();
```

It returns $a$.

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
std::optional<tools::vector2<T>> s.cross_point(half_line_2d<T> t);
std::optional<tools::vector2<T>> s.cross_point(tools::line_2d<T> t);
```

If $s$ and $t$ intersects at one point, it returns the point.
Otherwise, it returns `std::nullopt`.

### Constraints
- `<T>` is `tools::rational` or a built-in floating point type.

### Time Complexity
- $O(1)$ if `<T>` is a built-in numerical type

## d
```cpp
tools::vector2<T> s.d();
```

It returns $d$.

### Constraints
- None

### Time Complexity
- $O(1)$ if `<T>` is a built-in numerical type

## squared_distance
```cpp
T s.squared_distance(tools::directed_line_segment_2d<T> t);
T s.squared_distance(half_line_2d<T> t);
T s.squared_distance(tools::line_2d<T> t);
T s.squared_distance(tools::vector2<T> t);
```

It returns the squared distance between $s$ and $t$.

### Constraints
- `<T>` is `tools::rational` or a built-in floating point type.

### Time Complexity
- $O(1)$ if `<T>` is a built-in numerical type

## to_line
```cpp
tools::line_2d<T> s.to_line();
```

It returns the line through $a$ and $a + d$.

### Constraints
- None

### Time Complexity
- $O(1)$ if `<T>` is a built-in numerical type

## operator&
```cpp
std::optional<std::variant<tools::vector2<T>, tools::directed_line_segment_2d<T>>> operator&(half_line_2d<T> s, tools::directed_line_segment_2d<T> t);
std::optional<std::variant<tools::vector2<T>, tools::directed_line_segment_2d<T>, half_line_2d<T>>> operator&(half_line_2d<T> s, half_line_2d<T> t);
std::optional<std::variant<tools::vector2<T>, half_line_2d<T>>> operator&(half_line_2d<T> s, tools::line_2d<T> t);
```

If there is an intersection of $s$ and $t$, it returns the intersection.
Otherwise, it returns `std::nullopt`.

### Constraints
- `<T>` is `tools::rational` or a built-in floating point type.

### Time Complexity
- $O(1)$ if `<T>` is a built-in numerical type

## operator==
```cpp
bool operator==(half_line_2d<T> s, half_line_2d<T> t);
```

It returns whether $s$ is identical to $t$ or not.

### Constraints
- None

### Time Complexity
- $O(1)$ if `<T>` is a built-in numerical type

## operator!=
```cpp
bool operator!=(half_line_2d<T> s, half_line_2d<T> t);
```

It returns `!(s == t)`.

### Constraints
- None

### Time Complexity
- $O(1)$ if `<T>` is a built-in numerical type
