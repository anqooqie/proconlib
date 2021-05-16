---
title: $\min(\max(x \cdot y, \text{lower_bound}), \text{upper_bound})$ without overflow
documentation_of: //tools/multiplies_clamp.hpp
---

```cpp
template <typename T>
T multiplies_clamp(T x, T y, T lower_bound = std::numeric_limits<T>::min(), T upper_bound = std::numeric_limits<T>::max());
```

It returns $\min(\max(x \cdot y, \text{lower_bound}), \text{upper_bound})$ without overflow.

## License
- CC0

## Author
- anqooqie
