---
title: Median solver
documentation_of: //tools/median_solver.hpp
---

It calculates the median of an array.
It also allows you to dynamically add values to the array.

## Usage
```cpp
tools::median_solver<int> median;
median.push(5);
median.push(3);
median.push(7);
median.push(6);
median.query(); // => 5
```

## License
- CC0

## Author
- anqooqie
