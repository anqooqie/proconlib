---
title: 128 bit signed integer
documentation_of: //tools/int128_t.hpp
---

```cpp
using int128_t = __int128;

std::istream& operator>>(std::istream& is, int128_t& x);
std::ostream& operator<<(std::ostream& is, int128_t x);
int128_t tools::abs(int128_t x);
```

It is an alias for `__int128`.
Also, this header file adds some functions for `__int128`.

### Constraints
- It requires GCC or clang.

### Time Complexity
- Not applicable

### License
- CC0

### Author
- anqooqie
