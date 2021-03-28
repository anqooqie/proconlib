---
title: std::less by second
documentation_of: //tools/less_by_second.hpp
---

It is almost equivalent to `std::less` except that it compares pairs by the second element.

## Usage
```cpp
std::vector<std::pair<int, int>> a;
std::sort(a.begin(), a.end(), tools::less_by_second());
```

## License
- CC0

## Author
- anqooqie
