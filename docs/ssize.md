---
title: Polyfill of std::ssize
documentation_of: //tools/ssize.hpp
---

```cpp
template <typename C>
constexpr auto ssize(const C& c) -> std::common_type_t<std::ptrdiff_t, std::make_signed_t<decltype(c.size())>>;
```

It is a compatible alternative of `std::ssize` in C++20.

### Constraints
- `c.size()` is defined.

### Time Complexity
- Same as that of `c.size()`.

### License
- CC0

### Author
- anqooqie
