---
title: std::log(x) extended for my library
documentation_of: //tools/log.hpp
---

```cpp
auto log(auto&& x) -> decltype(std::log(x));
```

If `std::log(x)` is available, it returns `std::log(x)`.

`tools::log(x)` will be extended by other header files in my library.
For example, `tools::log(tools::quaternion<T>)` gets available if you include `tools/quaternion.hpp`.

### Constraints
- See the standard or the documentation page for each arguments.

### Time Complexity
- See the standard or the documentation page for each arguments.

### License
- CC0

### Author
- anqooqie
