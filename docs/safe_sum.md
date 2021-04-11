---
title: $x + y$ but not causing overflow
documentation_of: //tools/safe_sum.hpp
---

```cpp
template <typename T>
T safe_sum(T x, T y);
```

It returns $x + y$ when we regard `std::numeric_limits<T>::max()` as $\infty$ and `std::numeric_limits<T>::min()` as $-\infty$.

## License
- CC0

## Author
- anqooqie
