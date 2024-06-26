---
title: 128 bit unsigned integer
documentation_of: //tools/uint128_t.hpp
---

```cpp
using uint128_t = unsigned __int128;

std::istream& operator>>(std::istream& is, uint128_t& x);
std::ostream& operator<<(std::ostream& is, uint128_t x);
uint128_t tools::abs(uint128_t x);

constexpr inline uint128_t UINT128_MAX;
```

It is an alias for `unsigned __int128`.
Also, this header file adds some functions for `unsigned __int128`.

### Constraints
- It requires GCC or clang.

### Time Complexity
- Not applicable

### License
- CC0

### Author
- anqooqie
