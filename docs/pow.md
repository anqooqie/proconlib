---
title: $b^n$ under the given monoid
documentation_of: //tools/pow.hpp
---

```cpp
template <typename M>
typename M::T pow(typename M::T b, std::size_t n);

template <typename T>
T pow(T b, ::std::size_t n);
```

It returns $b^n$ under the given monoid.
The default monoid is $(\mathbb{Z}, \times)$.

## License
- CC0

## Author
- anqooqie
