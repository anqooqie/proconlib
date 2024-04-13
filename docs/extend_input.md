---
title: Extend operator>>
documentation_of: //tools/extend_input.hpp
---

```cpp
namespace std {
  template <class T, std::size_t N>
  std::istream& operator>>(std::istream& is, std::array<T, N>& array);

  template <class T1, class T2>
  std::istream& operator>>(std::istream& is, std::pair<T1, T2>& pair);

  template <typename... Args>
  std::istream& operator>>(std::istream& is, std::tuple<Args...>& tuple);

  template <class T, class Allocator>
  std::istream& operator>>(std::istream& is, std::vector<T, Allocator>& vector);

  template <typename T>
  std::enable_if_t<tools::has_mod_v<T>, std::istream&> operator>>(std::istream& is, T& x);
}
```

It adds some overloads of `operator>>`.
Hereby, it gets possible to store values to a container directly.

### Warning
This file adds functions to std namespace for convenience.
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
