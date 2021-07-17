---
title: $\left\lfloor \log_b(x) \right\rfloor$
documentation_of: //tools/floor_log.hpp
---

```cpp
template <typename M, typename N>
std::common_type_t<M, N> floor_log(M b, N x);
```

It returns $\left\lfloor \log_b(x) \right\rfloor$.

## Constraints
- $2 \leq b \leq 10^{18}$
- $1 \leq x \leq 10^{18}$

## Time Complexity
- $O(\log x)$

## License
- CC0

## Author
- anqooqie
