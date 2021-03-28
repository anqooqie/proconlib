---
title: std::greater by first
documentation_of: //tools/greater_by_first.hpp
---

It is almost equivalent to `std::greater` except that it compares pairs by the first element.

## Usage
```cpp
std::vector<std::pair<int, int>> a;
std::sort(a.begin(), a.end(), tools::greater_by_first());
```

## License
- CC0

## Author
- anqooqie
