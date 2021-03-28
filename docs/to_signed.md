---
title: To signed value
documentation_of: //tools/to_signed.hpp
---

```cpp
template <typename T>
constexpr typename ::std::make_signed<T>::type to_signed(T x) noexcept;
```

It converts an unsigned integer into signed one.

## Usage
```cpp
std::uint_fast64_t i;
decltype(tools::to_signed(i)) //=> std::int_fast64_t
```

## License
- CC0

## Author
- anqooqie
