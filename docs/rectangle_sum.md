---
title: Rectangle sum
documentation_of: //tools/rectangle_sum.hpp
---

Given $n$ weighted points on two-dimensional plane, it processes the following queries in offline.

- Adding a new point with weight $w$ at $(x, y)$ in $O\left((\log n)^2\right)$ time. If there is another point at the same coordinates, add as a distinct point.
- Finding the sum of weight of points such that $l \leq x < r, d \leq y < u$ is satisfied in $O\left((\log n)^2\right)$ time.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
rectangle_sum<T> rs();
```

It creates an empty two-dimensional plane.

### Constraints
- None

### Time Complexity
- $O(1)$

## register_point
```cpp
void rs.register_point(T x, T y);
```

It asserts that $(x, y)$ will be added.

### Constraints
- `rs.build()` has not been called ever.

### Time Complexity
- $O(1)$ amortized

## build
```cpp
void a.build();
```

It internally creates the the data structure.

### Constraints
- `rs.build()` has not been called ever.

### Time Complexity
- $O(n \log n)$

## add
```cpp
void a.add(T x, T y, T w);
```

It adds a new point with weight $w$ at $(x, y)$.
If there is another point at the same coordinates, add as a distinct point.

### Constraints
- `rs.build()` has been called ever.
- `rs.register_point(x, y)` has been called ever.

### Time Complexity
- $O\left((\log n)^2\right)$

## sum
```cpp
T rs.sum(T l, T r, T d, T u);
```

It returns the sum of weight of points such that $l \leq x < r, d \leq y < u$ is satisfied.

### Constraints
- `rs.build()` has been called ever.

### Time Complexity
- $O\left((\log n)^2\right)$
