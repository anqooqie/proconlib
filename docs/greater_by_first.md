---
title: std::greater by first
documentation_of: //tools/greater_by_first.hpp
---

It compares two pairs by the first element.

### Usage
```cpp
std::vector<std::pair<int, int>> a;
std::sort(a.begin(), a.end(), tools::greater_by_first());
```

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
tools::greater_by_first comp();
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

It returns `true` if `x.first > y.first`.
Otherwise, it returns `false`.

### Constraints
- None

### Time Complexity
- $O(1)$
