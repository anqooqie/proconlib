---
title: Number of trailing zeros
documentation_of: //tools/ntz.hpp
---

```cpp
std::int32_t ntz(std::int32_t x);
std::uint32_t ntz(std::uint32_t x);
std::int64_t ntz(std::int64_t x);
std::uint64_t ntz(std::uint64_t x);
```

It returns the number of trailing zeros. (e.g., ntz(0b10100) = 2)

## Constraints
- $x > 0$

## Time Complexity
- $O(\log\log x)$

## License
- CC0

## Author
- anqooqie
