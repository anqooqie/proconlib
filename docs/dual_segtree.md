---
title: Dual segment tree
documentation_of: //tools/dual_segtree.hpp
---

It is dual segment tree.

## Usage
```cpp
// range-add dual segment tree with 6 elements
tools::dual_segtree<tools::group::plus<int>> dual_segtree(6);

// adds 30 to [0, 3)
dual_segtree.apply(0, 3, 30);

// obtains operator at 2, that is 30
std::cout << dual_segtree.get(2) << std::endl;
```

## License
- CC0

## Author
- anqooqie
