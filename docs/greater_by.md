---
title: std::greater by key
documentation_of: //tools/greater_by.hpp
---

It is almost equivalent to `std::greater` except that it compares values by the given key selector.

## Usage
```cpp
std::sort(a.begin(), a.end(), tools::greater_by([](int a_i) { return std::abs(x); }));
```

## License
- CC0

## Author
- anqooqie
