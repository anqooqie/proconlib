---
title: Circular shift to the left
documentation_of: //tools/rotl.hpp
---

## (1)

```cpp
template <typename T, typename U>
T rotl(T x, int n, U s);
```

It returns $r$ which satisfies the followings.
- $0 \leq r < 2^n$
- For all $i$ such that $0 \leq i < n$, the $(((i + s) \bmod n) + 1)$-th least bit of $r$ is equal to the $(i + 1)$-th least bit of $x$.

### Constraints
- `<T>` is a built-in integral type
- `<U>` is a built-in integral type
- $0 \leq n \leq$ `std::numeric_limits<T>::digits`
- $0 \leq x < 2^n$

### Time Complexity
- $O(1)$

### License
- CC0

### Author
- anqooqie

## (2)

```cpp
template <typename T, typename U>
T rotl(T x, U s);
```

It returns $r$ which satisfies the followings.
- `r.size() == x.size()`
- Let $n$ be `x.size()`. For all $i$ such that $0 \leq i < n$, the $(((i + s) \bmod n) + 1)$-th least bit of $r$ is equal to the $(i + 1)$-th least bit of $x$.

### Constraints
- `<T>` is `std::bitset` or `tools::dynamic_bitset`
- `<U>` is a built-in integral type

### Time Complexity
- $O(\|x\|)$

### License
- CC0

### Author
- anqooqie
