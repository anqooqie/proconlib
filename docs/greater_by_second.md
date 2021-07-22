---
title: std::greater by second
documentation_of: //tools/greater_by_second.hpp
---

It compares two pairs by the second element.

### Usage
```cpp
std::vector<std::pair<int, int>> a;
std::sort(a.begin(), a.end(), tools::greater_by_second());
```

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
tools::greater_by_second comp();
```

It creates a comparator.

### Constraints
- None

### Time Complexity
- $O(1)$

## operator()
```cpp
template <typename T1, typename T2>
bool comp(std::pair<T1, T2> x, std::pair<T1, T2> y);
```

It returns `true` if `x.second > y.second`.
Otherwise, it returns `false`.

### Constraints
- None

### Time Complexity
- $O(1)$
