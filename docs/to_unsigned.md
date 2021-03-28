---
title: To unsigned value
documentation_of: //tools/to_unsigned.hpp
---

```cpp
template <typename T>
constexpr typename ::std::make_unsigned<T>::type to_unsigned(T x) noexcept;
```

It converts a signed integer into unsigned one.

## Usage
```cpp
std::int_fast64_t i;
decltype(tools::to_unsigned(i)) //=> std::uint_fast64_t
```

## License
- CC0

## Author
- anqooqie
