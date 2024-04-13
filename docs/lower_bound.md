---
title: std::lower_bound, but returns index
documentation_of: //tools/lower_bound.hpp
---

```cpp
template <class ForwardIterator, class T>
typename ::std::iterator_traits<ForwardIterator>::difference_type lower_bound(ForwardIterator first, ForwardIterator last, T value);
```

It is identical to `std::distance(first, std::lower_bound(first, last, value))`.

### Constraints
- None

### Time Complexity
- Same as that of `std::distance(first, std::lower_bound(first, last, value))`.

### License
- CC0

### Author
- anqooqie
