---
title: Bit reverse
documentation_of: //tools/reverse.hpp
---

```cpp
template <typename T>
T reverse(T x, std::size_t n);
```

It returns $r$ which satisfies the followings.
- $0 \leq r < 2^n$
- For all $i$ such that $0 \leq i < n$, the $i$-th bit of $r$ is equal to the $(n - 1 - i)$-th bit of $x$.

### Constraints
- `<T>` is an integral type
- $n \leq$ `std::numeric_limits<T>::digits`
- $0 \leq x < 2^n$

### Time Complexity
- $O(\log n)$

### License
- CC0

### Author
- anqooqie
