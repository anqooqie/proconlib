---
title: std::abs(x) extended for my library
documentation_of: //tools/abs.hpp
---

```cpp
constexpr auto abs(auto&& x) -> decltype(std::abs(x));
```

If `std::abs(x)` is available, it returns `std::abs(x)`.

`tools::abs(x)` will be extended by other header files in my library.
For example, `tools::abs(tools::bigint)` gets available if you include `tools/bigint.hpp`.

### Constraints
- See the standard or the documentation page for each arguments.

### Time Complexity
- See the standard or the documentation page for each arguments.

### License
- CC0

### Author
- anqooqie
