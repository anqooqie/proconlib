---
title: Area of union of rectangles
documentation_of: //tools/rectangle_union_area.hpp
---

Given $N$ rectangles, it returns the area of the union set of the rectangles in $O(N \log N)$ time.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
rectangle_union_area<T> rs();
```

It creates an empty list of rectangles.

### Constraints
- None

### Time Complexity
- $O(1)$

## size
```cpp
std::size_t rs.size();
```

It returns the number of rectangles in the list.

### Constraints
- None

### Time Complexity
- $O(1)$

## add_rectangle
```cpp
std::size_t rs.add_rectangle(T l, T r, T d, T u);
```

It adds a rectangle represented by $\\{(x, y) \mid l \leq x \leq y \land d \leq y \leq u \\}$.
It returns an integer $k$ such that this is the $k$-th rectangle that is added.

### Constraints
- None

### Time Complexity
- $O(1)$ amortized

## get_rectangle
```cpp
std::tuple<T, T, T, T> rs.get_rectangle(std::size_t k);
```

It returns $(l, r, d, u)$ such that the $k$-th rectangle is represented by $\\{(x, y) \mid l \leq x \leq y \land d \leq y \leq u \\}$.

### Constraints
- $0 \leq k < N$ where $N$ is the number of rectangles

### Time Complexity
- $O(1)$

## rectangles
```cpp
const std::vector<std::tuple<T, T, T, T>>& rs.rectangles();
```

It returns all the rectangles in the list.
The rectangles are ordered in the same order as added by `add_rectangle`.

### Constraints
- None

### Time Complexity
- $O(1)$

## query
```cpp
T rs.query();
```

It returns the area of the union set of the rectangles.

### Constraints
- None

### Time Complexity
- $O(N \log N)$ where $N$ is the number of rectangles
