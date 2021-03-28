---
title: std::greater by second
documentation_of: //tools/greater_by_second.hpp
---

It is almost equivalent to `std::greater` except that it compares pairs by the second element.

## Usage
```cpp
std::vector<std::pair<int, int>> a;
std::sort(a.begin(), a.end(), tools::greater_by_second());
```

## License
- CC0

## Author
- anqooqie
