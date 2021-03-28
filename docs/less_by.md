---
title: std::less by key
documentation_of: //tools/less_by.hpp
---

It is almost equivalent to `std::less` except that it compares values by the given key selector.

## Usage
```cpp
std::sort(a.begin(), a.end(), tools::less_by([](int a_i) { return std::abs(x); }));
```

## License
- CC0

## Author
- anqooqie
