---
title: $A - B$ but not causing overflow
documentation_of: //tools/safe_diff.hpp
---

```cpp
template <typename T>
T safe_diff(T x, T y);
```

It returns $x - y$ when we regard `std::numeric_limits<T>::max()` as $\infty$ and `std::numeric_limits<T>::min()` as $-\infty$.

## License
- CC0

## Author
- anqooqie
