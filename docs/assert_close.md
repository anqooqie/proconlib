---
title: Assertion for floating-point proximity
documentation_of: //tools/assert_close.hpp
---

```cpp
template <std::floating_point T>
constexpr void assert_close(T expected, T actual, T tolerance);
```

It asserts that the absolute or relative error between `expected` and `actual` is within `tolerance`, namely:

$$|\mathrm{expected} - \mathrm{actual}| \leq \mathrm{tolerance} \cdot \max(1, |\mathrm{expected}|, |\mathrm{actual}|)$$

If the condition is violated, it outputs the debug information to `std::cerr` and terminates the program by calling `std::abort()`.

The function is always enabled regardless of `NDEBUG` unlike `assert`.

### Constraints
- `tolerance` is non-negative.

### Time Complexity
- $O(1)$

### License
- CC0

### Author
- anqooqie
