---
title: $\left\lfloor \log_2(x) \right\rfloor$
documentation_of: //tools/floor_log2.hpp
---

```cpp
template <typename T>
T floor_log2(T x);
```

It returns $\left\lfloor \log_2(x) \right\rfloor$.

## Constraints
- $x > 0$
- `std::numeric_limits<T>::digits` is $8$, $16$, $32$ or $64$.

## Time Complexity
- $O(\log\log x)$

## License
- CC0

## Author
- anqooqie
