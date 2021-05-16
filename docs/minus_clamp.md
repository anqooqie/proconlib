---
title: $\min(\max(x - y, \text{lower_bound}), \text{upper_bound})$ without overflow
documentation_of: //tools/minus_clamp.hpp
---

```cpp
template <typename T>
T minus_clamp(T x, T y, T lower_bound = std::numeric_limits<T>::min(), T upper_bound = std::numeric_limits<T>::max());
```

It returns $\min(\max(x - y, \text{lower_bound}), \text{upper_bound})$ without overflow.

## License
- CC0

## Author
- anqooqie
