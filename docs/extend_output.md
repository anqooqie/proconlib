---
title: Extend operator<<
documentation_of: //tools/extend_output.hpp
---

```cpp
namespace std {
  template <class T, ::std::size_t N>
  std::ostream& operator<<(std::ostream& os, const std::array<T, N>& array);

  template <class Key, class T, class Compare, class Allocator>
  std::ostream& operator<<(std::ostream& os, const std::map<Key, T, Compare, Allocator>& map);

  template <typename T>
  std::ostream& operator<<(std::ostream& os, const std::optional<T>& optional);

  template <class T1, class T2>
  std::ostream& operator<<(std::ostream& os, const std::pair<T1, T2>& pair);

  template <class T, class Container>
  std::ostream& operator<<(std::ostream& os, std::queue<T, Container>& queue);

  template <class Key, class Compare, class Allocator>
  std::ostream& operator<<(std::ostream& os, const std::set<Key, Compare, Allocator>& set);

  template <class T, class Container>
  std::ostream& operator<<(std::ostream& os, std::stack<T, Container>& stack);

  template <typename... Args>
  std::ostream& operator<<(std::ostream& os, const std::tuple<Args...>& tuple);

  template <class Key, class T, class Hash, class Pred, class Allocator>
  std::ostream& operator<<(std::ostream& os, const std::unordered_map<Key, T, Hash, Pred, Allocator>& unordered_map);

  template <class Key, class Hash, class Pred, class Allocator>
  std::ostream& operator<<(std::ostream& os, const std::unordered_set<Key, Hash, Pred, Allocator>& unordered_set);

  template <class T, class Allocator>
  std::ostream& operator<<(std::ostream& os, const std::vector<T, Allocator>& vector);

  template <typename T>
  std::enable_if_t<tools::has_mod_v<T>, std::ostream&> operator<<(std::ostream& os, const T& x);
}
```

It adds some overloads of `operator<<`.
Hereby, it gets possible to print a container directly.

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
