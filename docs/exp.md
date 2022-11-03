---
title: std::exp(x) extended for my library
documentation_of: //tools/exp.hpp
---

```cpp
template <typename T>
auto exp(T x) -> decltype(std::exp(x));
```

If `std::exp(x)` is available, it returns `std::exp(x)`.

`tools::exp(x)` will be extended by other header files in my library.
For example, `tools::exp(tools::quaternion<T>)` gets available if you include `tools/quaternion.hpp`.

## Constraints
- See the standard or the explanation of the corresponding header file.

## Time Complexity
- See the standard or the explanation of the corresponding header file.

## License
- CC0

## Author
- anqooqie
