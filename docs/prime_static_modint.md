---
title: Concept for atcoder::static_modint such that its modulo is a prime
documentation_of: //tools/prime_static_modint.hpp
---

```cpp
template <typename T>
using prime_static_modint = atcoder::internal::is_static_modint<T>::value && tools::is_prime(T::mod());
```

It is a concept that represents `atcoder::static_modint<M>` such that `M` is a prime.

### Constraints
- None

### Time Complexity
- Not applicable

### License
- CC0

### Author
- anqooqie
