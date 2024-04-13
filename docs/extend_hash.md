---
title: Extend std::hash
documentation_of: //tools/extend_hash.hpp
---

```cpp
namespace std {
  template <class T1, class T2>
  struct hash<std::pair<T1, T2>> {
    std::size_t operator()(const std::pair<T1, T2>& key) const;
  };

  template <class... Args>
  struct hash<std::tuple<Args...>> {
    std::size_t operator()(const std::tuple<Args...>& key) const;
  };
}
```

It adds some specializations of `std::hash`.
Hereby, it gets possible to compile `std::hash<std::pair<T1, T2>>` and `std::hash<std::tuple<Args...>>`.

### Warning
This file adds partial specializations for classes in std namespace, for convenience.
Strictly speaking, it is not allowed in C++.
It makes the program ill-formed to include this file, and may cause undefined behavior.

### Constraints
- None

### Time Complexity
- Not applicable

### License
- CC0

### Author
- anqooqie
