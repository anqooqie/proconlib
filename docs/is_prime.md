---
title: Miller-Rabin primality test
documentation_of: //tools/is_prime.hpp
---

```cpp
constexpr bool is_prime(unsigned long long n);
```

It returns `true` if $n$ is a prime, and `false` if $n$ is not a prime.
It implements a deterministic variant of Miller-Rabin primality test.

### Constraints
- $0 \leq n < 2^{64}$

### Time Complexity
- $O(\log n)$

### References
- [ミラー-ラビン素数判定法 - Wikipedia](https://ja.wikipedia.org/wiki/%E3%83%9F%E3%83%A9%E3%83%BC%E2%80%93%E3%83%A9%E3%83%93%E3%83%B3%E7%B4%A0%E6%95%B0%E5%88%A4%E5%AE%9A%E6%B3%95)
- [Deterministic variants of the Miller-Rabin primality test. Miller-Rabin SPRP bases records](http://miller-rabin.appspot.com/)

### License
- CC0

### Author
- anqooqie
