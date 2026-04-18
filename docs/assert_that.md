---
title: Assertion macro
documentation_of: //tools/assert_that.hpp
---

```cpp
#define assert_that(expr) implementation-defined
```

It asserts that `expr` is `true`.
If `expr` is `false`, it outputs the debug information to `std::cerr` and terminates the program by calling `std::abort()`.

The macro is always enabled regardless of `NDEBUG` unlike `assert`.

### Constraints
- `expr` is the expression contextually convertible to `bool`.

### Time Complexity
- $O(1)$

### License
- CC0

### Author
- anqooqie
