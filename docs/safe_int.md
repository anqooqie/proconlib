---
title: Integer type with $\infty$ and $-\infty$
documentation_of: //tools/safe_int.hpp
---

It is the integer type which has two special behaviors.

1. It regards `std::numeric_limits<T>::max()` as $\infty$ and `std::numeric_limits<T>::min()` as $-\infty$.
1. It returns $\infty$ or $-\infty$ when it detects overflow.

## Usage
```cpp
// ∞ - 1 = ∞
assert((tools::safe_int<int>(std::numeric_limits<int>::max()) - tools::safe_int<int>(1)).val() == std::numeric_limits<int>::max());

// It returns ∞ since 1000000000 + 2000000000 causes overflow.
assert((tools::safe_int<int>(1000000000) + tools::safe_int<int>(2000000000)).val() == std::numeric_limits<int>::max());
```

## License
- CC0

## Author
- anqooqie
