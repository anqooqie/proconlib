---
title: 2D cumulative sum
documentation_of: //tools/cumsum2d.hpp
---

It handles two-dimensional cumulative sum.

## Usage
```cpp
// Assume that the value on (x, y) can be obtained as a[y][x].
std::vector<std::vector<int>> a;

// Builds the cumulative sum of a.
const tools::cumsum2d<tools::group::plus<int>> cumsum(a.begin(), a.end());

// Queries sum of a[y][x], for x1 <= x < x2 and y1 <= y < y2.
cumsum.query(x1, y1, x2, y2);
```

## License
- CC0

## Author
- anqooqie
