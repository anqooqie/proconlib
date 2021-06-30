---
title: Set of closed intervals
documentation_of: //tools/interval_set.hpp
---

It is a set of closed intervals.

## Usage
```cpp
tools::interval_set<int, false> set;

// It adds [1, 6] to the set.
// The set is now {[1, 6]}.
set.insert(1, 6);

// It removes [4, 5] from the set.
// The set is now {[1, 3], [6, 6]}.
set.erase(4, 5);

// It returns the iterator referring to the interval which contains 2, that is [1, 2].
set.find(2);

// It adds [4, 6] to the set.
// The set is now {[1, 3], [4, 6]}.
set.insert(4, 6);

// The second type parameter allows you to merge two adjacent intervals.
tools::interval_set<int, true> set2;

// The set is now {[1, 3], [6, 6]}.
set2.insert(1, 3);
set2.insert(6, 6);

// It adds [4, 5] to the set.
// The set is now {[1, 6]} because [1, 3], [4, 5] and [6, 6] are adjacent and regarded as mergeable intervals.
set2.insert(4, 5);
```

## License
- CC0

## Author
- anqooqie
