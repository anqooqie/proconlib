---
title: std::make_signed extended for tools::int128_t and tools::uint128_t
documentation_of: //tools/make_signed.hpp
---

```cpp
template <typename T>
struct make_signed {
  using type = ...;
};

template <typename T>
using make_signed_t = typename make_signed<T>::type;
```

`tools::make_signed` is guaranteed to satisfy the following properties.

- If `std::make_signed_t<T>` is defined, `tools::make_signed_t<T>` is `std::make_signed_t<T>`.
- `tools::make_signed_t<tools::int128_t>` is `tools::int128_t`.
- `tools::make_signed_t<tools::uint128_t>` is `tools::int128_t`.
- `tools::make_signed_t<const tools::int128_t>` is `const tools::int128_t`.
- `tools::make_signed_t<const tools::uint128_t>` is `const tools::int128_t`.
- `tools::make_signed_t<volatile tools::int128_t>` is `volatile tools::int128_t`.
- `tools::make_signed_t<volatile tools::uint128_t>` is `volatile tools::int128_t`.
- `tools::make_signed_t<const volatile tools::int128_t>` is `const volatile tools::int128_t`.
- `tools::make_signed_t<const volatile tools::uint128_t>` is `const volatile tools::int128_t`.

When using libstdc++ with `-std=c++...` option, `std::make_signed_t<tools::uint128_t>` cannot be compiled, but with `tools::make_signed`, it can be compiled.

### Constraints
- None

### Time Complexity
- Not applicable

### License
- CC0

### Author
- anqooqie
