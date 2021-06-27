---
title: Minimum excluded value
documentation_of: //tools/mex.hpp
---

It is a set and can answer the minimum value more than or equal to a given value and not in the set.

## Usage
```cpp
tools::mex<int> mex;

// adds [1, 4) to the set
mex.add(1, 4);

// adds 5 to the set
mex.add(5);

// returns 4 because 4 >= 2 and 4 is not in {1, 2, 3, 5}.
mex.query(2);

// returns 4 because 4 >= 4 and 4 is not in {1, 2, 3, 5}.
mex.query(4);
```

## License
- CC0

## Author
- anqooqie
