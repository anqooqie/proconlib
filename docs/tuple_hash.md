---
title: Hash of std::tuple
documentation_of: //tools/tuple_hash.hpp
---

```cpp
template <typename... Ts>
struct tuple_hash {
  std::size_t operator()(std::tuple<Ts...> key);
};
```

It is a class for calculating the hash value of `std::tuple<Ts...>`.

## License
- CC0

## Author
- anqooqie
