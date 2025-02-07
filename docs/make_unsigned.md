---
title: std::make_unsigned extended for tools::int128_t and tools::uint128_t
documentation_of: //tools/make_unsigned.hpp
---

```cpp
template <typename T>
struct make_unsigned {
  using type = ...;
};

template <typename T>
using make_unsigned_t = typename make_unsigned<T>::type;
```

`tools::make_unsigned` is guaranteed to satisfy the following properties.

- If `std::make_unsigned_t<T>` is defined, `tools::make_unsigned_t<T>` is `std::make_unsigned_t<T>`.
- `tools::make_unsigned_t<tools::int128_t>` is `tools::uint128_t`.
- `tools::make_unsigned_t<tools::uint128_t>` is `tools::uint128_t`.
- `tools::make_unsigned_t<const tools::int128_t>` is `const tools::uint128_t`.
- `tools::make_unsigned_t<const tools::uint128_t>` is `const tools::uint128_t`.
- `tools::make_unsigned_t<volatile tools::int128_t>` is `volatile tools::uint128_t`.
- `tools::make_unsigned_t<volatile tools::uint128_t>` is `volatile tools::uint128_t`.
- `tools::make_unsigned_t<const volatile tools::int128_t>` is `const volatile tools::uint128_t`.
- `tools::make_unsigned_t<const volatile tools::uint128_t>` is `const volatile tools::uint128_t`.

When using libstdc++ with `-std=c++...` option, `std::make_unsigned_t<tools::int128_t>` cannot be compiled, but with `tools::make_unsigned`, it can be compiled.

### Constraints
- None

### Time Complexity
- Not applicable

### License
- CC0

### Author
- anqooqie
