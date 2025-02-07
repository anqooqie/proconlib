---
title: 128-bit signed integer
documentation_of: //tools/int128_t.hpp
---

```cpp
using int128_t = __int128;
```

It is an alias for `__int128`.
In addition, several additional utilities for `int128_t` are available by including this header file.

### Note
When libstdc++ is used with `-std=c++...` option, the following points should be noted.

- `std::is_integral_v<int128_t>` is `false`.
- `std::is_signed_v<int128_t>` is `false`.
- `std::make_unsigned_t<int128_t>` cannot be compiled.

### License
- CC0

### Author
- anqooqie

## INT128_C
```cpp
INT128_C(x)
```

It is a compile-time constant, a 128-bit signed integer whose value is $x$.
For example, you can write `INT128_C(-170141183460469231731687303715884105728)`.

### Constraints
- `x` is represented by regular expression `[+\-]?[0-9]+`.
- $-2^{127} \leq x \leq 2^{127} - 1$

### Time Complexity
- $O(1)$

## operator&gt;&gt;
```cpp
std::istream& operator>>(std::istream& is, int128_t& x);
```

It parses the input as a signed integer and stores its value in $x$.

### Constraints
- The input is represented by regular expression `[+\-]?[0-9]+`.
- $-2^{127} \leq n \leq 2^{127} - 1$ where $n$ is the integer value represented by the input.

### Time Complexity
- $O(\log \|n\|)$

## operator&lt;&lt;
```cpp
std::ostream& operator<<(std::ostream& os, int128_t x);
```

It prints $x$ to `os`.

### Constraints
- None

### Time Complexity
- $O(\log \|x\|)$

## tools::abs
```cpp
constexpr int128_t tools::abs(int128_t x);
```

It returns $\|x\|$.

### Constraints
- None

### Time Complexity
- $O(1)$

## std::hash&lt;int128_t&gt;
```cpp
namespace std {
  template <>
  struct hash<int128_t> {
    std::size_t operator()(int128_t x) const;
  };
}
```

It is `std::hash` specialized for `int128_t`.

### Constraints
- None

### Time Complexity
- $O(1)$
