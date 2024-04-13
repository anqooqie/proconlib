---
title: std::abs(x) extended for my library
documentation_of: //tools/abs.hpp
---

```cpp
constexpr float abs(float x);
constexpr double abs(double x);
constexpr long double abs(long double x);
constexpr int abs(int x);
constexpr long abs(long x);
constexpr long long abs(long long x);
constexpr unsigned int abs(unsigned int x);
constexpr unsigned long abs(unsigned long x);
constexpr unsigned long long abs(unsigned long long x);
```

It returns $\|x\|$.

`tools::abs(x)` will be extended by other header files in my library.
For example, `tools::abs(tools::bigint)` gets available if you include `tools/bigint.hpp`.

### Constraints
- See the standard or the explanation of the corresponding header file.

### Time Complexity
- See the standard or the explanation of the corresponding header file.

### License
- CC0

### Author
- anqooqie
