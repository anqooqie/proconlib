---
title: std::upper_bound, but returns index
documentation_of: //tools/upper_bound.hpp
---

```cpp
template <class ForwardIterator, class T>
typename ::std::iterator_traits<ForwardIterator>::difference_type upper_bound(ForwardIterator first, ForwardIterator last, T value);
```

It returns `std::distance(first, std::upper_bound(first, last, value))`;

## License
- CC0

## Author
- anqooqie
