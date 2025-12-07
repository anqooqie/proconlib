---
title: std::abs(x) extended for my library
documentation_of: //tools/abs.hpp
---

```cpp
constexpr unsigned int abs(unsigned int x);
constexpr unsigned long abs(unsigned long x);
constexpr unsigned long long abs(unsigned long long x);
```

It returns $\|x\|$.

`tools::abs(x)` will be extended by other header files in my library.
For example, `tools::abs(tools::bigint)` gets available if you include `tools/bigint.hpp`.

### Constraints
- See the documentation page for each arguments.

### Time Complexity
- See the documentation page for each arguments.

### License
- CC0

### Author
- anqooqie
