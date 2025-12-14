---
title: std::gcd(m, n) extended for my library
documentation_of: //tools/gcd.hpp
---

```cpp
template <typename M, typename N>
constexpr std::common_type_t<M, N> gcd(M m, N n);
```

If `std::gcd(m, n)` is available, it returns `std::gcd(m, n)`.

`tools::gcd(m, n)` will be extended by other header files in my library.
For example, `tools::gcd(tools::bigint, tools::bigint)` gets available if you include `tools/bigint.hpp`.

### Constraints
- See the standard or the documentation page for each arguments.

### Time Complexity
- See the standard or the documentation page for each arguments.

### License
- CC0

### Author
- anqooqie
