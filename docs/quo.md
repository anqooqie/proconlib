---
title: Quotient as integer division
documentation_of: //tools/quo.hpp
---

```cpp
template <typename M, typename N>
constexpr std::common_type_t<M, N> quo(M a, N b);
```

It returns $q$, which satisfies $a = qb + r \land 0 \leq r < \|b\|$.

## License
- CC0

## Author
- anqooqie
