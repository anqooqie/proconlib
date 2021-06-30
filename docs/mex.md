---
title: Minimum excluded value
documentation_of: //tools/mex.hpp
---

It is a set.
It can answer the minimum value more than or equal to a given value and not in the set.

## Usage
```cpp
tools::mex<int> mex;

// It adds [1, 3] to the set.
mex.insert(1, 3);

// It adds 5 to the set.
mex.insert(5);

// It returns 4 because 4 >= 2 and 4 is not in {1, 2, 3, 5}.
mex.query(2);

// It returns 4 because 4 >= 4 and 4 is not in {1, 2, 3, 5}.
mex.query(4);
```

## License
- CC0

## Author
- anqooqie
