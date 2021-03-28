---
title: chmax function
documentation_of: //tools/chmax.hpp
---

```cpp
template <typename M, typename N>
bool chmax(M& lhs, N rhs);
```

It runs `lhs = std::max(lhs, rhs);`.
It returns `true` if `lhs` has been updated, `false` otherwise.

## License
- CC0

## Author
- anqooqie
