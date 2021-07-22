---
title: std::less by argument
documentation_of: //tools/less_by_arg.hpp
---

It compares two points by the argument.

### References
- [How do you polar sort? - Codeforces](https://codeforces.com/blog/entry/72815)

### License
- unknown

### Author
- Alpha_Q

## Constructor
```cpp
tools::less_by_arg comp();
```

It creates a comparator.

### Constraints
- None

### Time Complexity
- $O(1)$

## operator()
```cpp
template <typename T>
bool comp(tools::vector2<T> a, tools::vector2<T> b);
```

It returns `true` if `atan2(a.y, a.x) < atan2(b.y, b.x)`.
Otherwise, it returns `false`.

### Constraints
- None

### Time Complexity
- $O(1)$
