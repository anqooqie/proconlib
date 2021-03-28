---
title: std::less by first
documentation_of: //tools/less_by_first.hpp
---

It is almost equivalent to `std::less` except that it compares pairs by the first element.

## Usage
```cpp
std::vector<std::pair<int, int>> a;
std::sort(a.begin(), a.end(), tools::less_by_first());
```

## License
- CC0

## Author
- anqooqie
