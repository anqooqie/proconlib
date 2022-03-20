---
title: std::greater by std::get
documentation_of: //tools/greater_by_get.hpp
---

It compares two values by `std::get`.

### Usage
```cpp
std::vector<std::tuple<int, int, int>> a;
std::sort(a.begin(), a.end(), tools::greater_by_get<2>());
```

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
template <std::size_t I>
tools::greater_by_get<I> comp();
```

It creates a comparator.

### Constraints
- None

### Time Complexity
- $O(1)$

## operator()
```cpp
template <typename T>
bool comp.operator()(T x, T y);
```

It returns `true` if `std::get<I>(x) > std::get<I>(y)`.
Otherwise, it returns `false`.

### Constraints
- None

### Time Complexity
- $O(1)$
