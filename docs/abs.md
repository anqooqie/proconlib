---
title: Unified interface for std::abs(x) and x.abs()
documentation_of: //tools/abs.hpp
---

```cpp
(1)
template <typename T>
auto abs(T x) -> decltype(std::abs(x));

(2)
template <typename T>
auto abs(T x) -> decltype(x.abs());
```

It returns `std::abs(x)` if `std::abs(x)` is available.
In addition, it returns `x.abs()` if `x.abs()` is available.

## Constraints
- `std::abs(x)` or `x.abs()` is available

## Time Complexity
- (1)
    - $O(1)$
- (2)
    - Same as `x.abs()`

## License
- CC0

## Author
- anqooqie
