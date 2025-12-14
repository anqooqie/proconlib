---
title: Return type of read-only getter
documentation_of: //tools/getter_result.hpp
---

```cpp
template <typename T, typename U>
struct getter_result {
  using type = std::conditional_t<std::is_lvalue_reference_v<T>, const U&, U>;
};

template <typename T, typename U>
using getter_result_t = typename getter_result<T, U>::type;
```

`tools::getter_result` is a small type trait that helps you choose an appropriate return type for "getter"-like functions depending on whether the object (`this`) is an lvalue or an rvalue.

It is especially useful in C++23-style explicit object parameter member functions, e.g.:

```cpp
auto edges(this auto&& self) -> tools::getter_result_t<decltype(self), std::vector<edge>> {
  return std::forward_like<decltype(self)>(self.m_edges);
}
```

With `tools::getter_result`, you can write a single getter that:

- returns `const U&` when called on an **lvalue** object, and
- returns `U` **by value** when called on an **rvalue** object.

This allows efficient move (or copy) of the member from temporary objects, while preventing modification through getters on lvalues.

### Constraints
- None

### Time Complexity
- Not applicable

### License
- CC0

### Author
- anqooqie
