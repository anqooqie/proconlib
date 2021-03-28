---
title: $\left\lceil \log_b(x) \right\rceil$
documentation_of: //tools/ceil_log.hpp
---

```cpp
template <typename M, typename N>
std::common_type_t<M, N> ceil_log(M b, N x);
```

It returns $\left\lceil \log_b(x) \right\rceil$.

## Constraints
- $2 \leq b \leq 10^{18}$
- $1 \leq x \leq 10^{18}$

## License
- CC0

## Author
- anqooqie
