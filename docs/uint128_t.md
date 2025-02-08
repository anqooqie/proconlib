---
title: 128-bit unsigned integer
documentation_of: //tools/uint128_t.hpp
---

```cpp
using uint128_t = unsigned __int128;
```

It is an alias for `unsigned __int128`.
In addition, several additional utilities for `uint128_t` are available by including this header file.

### Note
When libstdc++ is used with `-std=c++...` option, the following points should be noted.

- `std::is_integral_v<uint128_t>` is `false`.
- `std::is_unsigned_v<uint128_t>` is `false`.
- `std::make_signed_t<uint128_t>` cannot be compiled.

### License
- CC0

### Author
- anqooqie

## UINT128_C
```cpp
UINT128_C(x)
```

It is a compile-time constant, a 128-bit unsigned integer whose value is $x$.
For example, you can write `UINT128_C(340282366920938463463374607431768211455)`.

### Constraints
- `x` is represented by regular expression `\+?([0-9]+|0[Xx][0-9A-Fa-f]+)`.
- $0 \leq x \leq 2^{128} - 1$

### Time Complexity
- $O(1)$

## operator&gt;&gt;
```cpp
std::istream& operator>>(std::istream& is, uint128_t& x);
```

It parses the input as an unsigned integer and stores its value in $x$.

### Constraints
- The input is represented by regular expression `\+?[0-9]+`.
- $0 \leq n \leq 2^{128} - 1$ where $n$ is the integer value represented by the input.

### Time Complexity
- $O(\log n)$

## operator&lt;&lt;
```cpp
std::ostream& operator<<(std::ostream& os, uint128_t x);
```

It prints $x$ to `os`.

### Constraints
- None

### Time Complexity
- $O(\log x)$

## tools::abs
```cpp
constexpr uint128_t tools::abs(uint128_t x);
```

It returns $x$.

### Constraints
- None

### Time Complexity
- $O(1)$

## std::hash&lt;uint128_t&gt;
```cpp
namespace std {
  template <>
  struct hash<uint128_t> {
    std::size_t operator()(uint128_t x) const;
  };
}
```

It is `std::hash` specialized for `uint128_t`.

### Constraints
- None

### Time Complexity
- $O(1)$
