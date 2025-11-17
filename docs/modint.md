---
title: Concept for atcoder::static_modint and atcoder::dynamic_modint
documentation_of: //tools/modint.hpp
---

```cpp
template <typename T>
concept modint = tools::modint_compatible<T>
  && requires(T a) {
    { T::mod() } -> std::same_as<int>;
    { a.val() } -> std::same_as<int>;
  };
```

It is a concept that represents `atcoder::static_modint` and `atcoder::dynamic_modint`.

### Constraints
- None

### Time Complexity
- Not applicable

### License
- CC0

### Author
- anqooqie
