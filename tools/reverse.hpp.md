---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/floor_log2.hpp
    title: $\left\lfloor \log_2(x) \right\rfloor$
  - icon: ':heavy_check_mark:'
    path: tools/popcount.hpp
    title: Popcount
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/reverse.test.cpp
    title: tests/reverse.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/reverse.hpp\"\n\n\n\n#include <type_traits>\n#include\
    \ <limits>\n#include <cstddef>\n#include <cassert>\n#include <cstdint>\n#line\
    \ 1 \"tools/floor_log2.hpp\"\n\n\n\n#line 1 \"tools/popcount.hpp\"\n\n\n\n#line\
    \ 8 \"tools/popcount.hpp\"\n\nnamespace tools {\n\n  template <typename T>\n \
    \ T popcount(T x) {\n    static_assert(::std::is_integral_v<T>);\n    assert(x\
    \ >= 0);\n    if constexpr (::std::is_signed_v<T>) {\n      return static_cast<T>(::tools::popcount<::std::make_unsigned_t<T>>(x));\n\
    \    } else {\n      const auto log2 = [](const int w) {\n        if (w == 8)\
    \ return 3;\n        if (w == 16) return 4;\n        if (w == 32) return 5;\n\
    \        if (w == 64) return 6;\n        return -1;\n      };\n      static_assert(log2(::std::numeric_limits<T>::digits)\
    \ >= 0);\n\n      if constexpr (::std::numeric_limits<T>::digits == 8) {\n   \
    \     x = (x & UINT8_C(0x55)) + (x >> 1 & UINT8_C(0x55));\n        x = (x & UINT8_C(0x33))\
    \ + (x >> 2 & UINT8_C(0x33));\n        x = (x & UINT8_C(0x0f)) + (x >> 4 & UINT8_C(0x0f));\n\
    \      } else if constexpr (::std::numeric_limits<T>::digits == 16) {\n      \
    \  x = (x & UINT16_C(0x5555)) + (x >> 1 & UINT16_C(0x5555));\n        x = (x &\
    \ UINT16_C(0x3333)) + (x >> 2 & UINT16_C(0x3333));\n        x = (x & UINT16_C(0x0f0f))\
    \ + (x >> 4 & UINT16_C(0x0f0f));\n        x = (x & UINT16_C(0x00ff)) + (x >> 8\
    \ & UINT16_C(0x00ff));\n      } else if constexpr (::std::numeric_limits<T>::digits\
    \ == 32) {\n        x = (x & UINT32_C(0x55555555)) + (x >> 1 & UINT32_C(0x55555555));\n\
    \        x = (x & UINT32_C(0x33333333)) + (x >> 2 & UINT32_C(0x33333333));\n \
    \       x = (x & UINT32_C(0x0f0f0f0f)) + (x >> 4 & UINT32_C(0x0f0f0f0f));\n  \
    \      x = (x & UINT32_C(0x00ff00ff)) + (x >> 8 & UINT32_C(0x00ff00ff));\n   \
    \     x = (x & UINT32_C(0x0000ffff)) + (x >> 16 & UINT32_C(0x0000ffff));\n   \
    \   } else if constexpr (::std::numeric_limits<T>::digits == 64) {\n        x\
    \ = (x & UINT64_C(0x5555555555555555)) + (x >> 1 & UINT64_C(0x5555555555555555));\n\
    \        x = (x & UINT64_C(0x3333333333333333)) + (x >> 2 & UINT64_C(0x3333333333333333));\n\
    \        x = (x & UINT64_C(0x0f0f0f0f0f0f0f0f)) + (x >> 4 & UINT64_C(0x0f0f0f0f0f0f0f0f));\n\
    \        x = (x & UINT64_C(0x00ff00ff00ff00ff)) + (x >> 8 & UINT64_C(0x00ff00ff00ff00ff));\n\
    \        x = (x & UINT64_C(0x0000ffff0000ffff)) + (x >> 16 & UINT64_C(0x0000ffff0000ffff));\n\
    \        x = (x & UINT64_C(0x00000000ffffffff)) + (x >> 32 & UINT64_C(0x00000000ffffffff));\n\
    \      }\n\n      return x;\n    }\n  }\n}\n\n\n#line 8 \"tools/floor_log2.hpp\"\
    \n\nnamespace tools {\n\n  template <typename T>\n  T floor_log2(T x) {\n    static_assert(::std::is_integral_v<T>);\n\
    \    assert(x > 0);\n    if constexpr (::std::is_signed_v<T>) {\n      return\
    \ static_cast<T>(::tools::floor_log2<::std::make_unsigned_t<T>>(x));\n    } else\
    \ {\n      const auto log2 = [](const int w) {\n        if (w == 8) return 3;\n\
    \        if (w == 16) return 4;\n        if (w == 32) return 5;\n        if (w\
    \ == 64) return 6;\n        return -1;\n      };\n      static_assert(log2(::std::numeric_limits<T>::digits)\
    \ >= 0);\n\n      x |= (x >> 1);\n      x |= (x >> 2);\n      x |= (x >> 4);\n\
    \      if constexpr (::std::numeric_limits<T>::digits > 8) x |= (x >> 8);\n  \
    \    if constexpr (::std::numeric_limits<T>::digits > 16) x |= (x >> 16);\n  \
    \    if constexpr (::std::numeric_limits<T>::digits > 32) x |= (x >> 32);\n  \
    \    return ::tools::popcount(x) - static_cast<T>(1);\n    }\n  }\n}\n\n\n#line\
    \ 10 \"tools/reverse.hpp\"\n\nnamespace tools {\n  template <typename T>\n  ::std::enable_if_t<::std::is_integral_v<T>\
    \ && !::std::is_signed_v<T> && ::std::numeric_limits<T>::digits == 1, T> reverse(const\
    \ T x, const ::std::size_t n) {\n    assert(n <= ::std::numeric_limits<T>::digits);\n\
    \    assert(!x || n == 1);\n    return x;\n  }\n  template <typename T>\n  ::std::enable_if_t<::std::is_integral_v<T>\
    \ && !::std::is_signed_v<T> && ::std::numeric_limits<T>::digits == 8, T> reverse(T\
    \ x, const ::std::size_t n) {\n    assert(n <= ::std::numeric_limits<T>::digits);\n\
    \    assert(x == 0 || ::tools::floor_log2(x) < n);\n    x = ((x & UINT8_C(0x55))\
    \ << 1) | ((x & UINT8_C(0xAA)) >> 1);\n    x = ((x & UINT8_C(0x33)) << 2) | ((x\
    \ & UINT8_C(0xCC)) >> 2);\n    x = ((x & UINT8_C(0x0F)) << 4) | ((x & UINT8_C(0xF0))\
    \ >> 4);\n    x >>= (::std::numeric_limits<T>::digits - n) & (::std::numeric_limits<T>::digits\
    \ - 1);\n    return x;\n  }\n  template <typename T>\n  ::std::enable_if_t<::std::is_integral_v<T>\
    \ && !::std::is_signed_v<T> && ::std::numeric_limits<T>::digits == 16, T> reverse(T\
    \ x, const ::std::size_t n) {\n    assert(n <= ::std::numeric_limits<T>::digits);\n\
    \    assert(x == 0 || ::tools::floor_log2(x) < n);\n    x = ((x & UINT16_C(0x5555))\
    \ << 1) | ((x & UINT16_C(0xAAAA)) >> 1);\n    x = ((x & UINT16_C(0x3333)) << 2)\
    \ | ((x & UINT16_C(0xCCCC)) >> 2);\n    x = ((x & UINT16_C(0x0F0F)) << 4) | ((x\
    \ & UINT16_C(0xF0F0)) >> 4);\n    x = ((x & UINT16_C(0x00FF)) << 8) | ((x & UINT16_C(0xFF00))\
    \ >> 8);\n    x >>= (::std::numeric_limits<T>::digits - n) & (::std::numeric_limits<T>::digits\
    \ - 1);\n    return x;\n  }\n  template <typename T>\n  ::std::enable_if_t<::std::is_integral_v<T>\
    \ && !::std::is_signed_v<T> && ::std::numeric_limits<T>::digits == 32, T> reverse(T\
    \ x, const ::std::size_t n) {\n    assert(n <= ::std::numeric_limits<T>::digits);\n\
    \    assert(x == 0 || ::tools::floor_log2(x) < n);\n    x = ((x & UINT32_C(0x55555555))\
    \ << 1) | ((x & UINT32_C(0xAAAAAAAA)) >> 1);\n    x = ((x & UINT32_C(0x33333333))\
    \ << 2) | ((x & UINT32_C(0xCCCCCCCC)) >> 2);\n    x = ((x & UINT32_C(0x0F0F0F0F))\
    \ << 4) | ((x & UINT32_C(0xF0F0F0F0)) >> 4);\n    x = ((x & UINT32_C(0x00FF00FF))\
    \ << 8) | ((x & UINT32_C(0xFF00FF00)) >> 8);\n    x = ((x & UINT32_C(0x0000FFFF))\
    \ << 16) | ((x & UINT32_C(0xFFFF0000)) >> 16);\n    x >>= (::std::numeric_limits<T>::digits\
    \ - n) & (::std::numeric_limits<T>::digits - 1);\n    return x;\n  }\n  template\
    \ <typename T>\n  ::std::enable_if_t<::std::is_integral_v<T> && !::std::is_signed_v<T>\
    \ && ::std::numeric_limits<T>::digits == 64, T> reverse(T x, const ::std::size_t\
    \ n) {\n    assert(n <= ::std::numeric_limits<T>::digits);\n    assert(x == 0\
    \ || ::tools::floor_log2(x) < n);\n    x = ((x & UINT64_C(0x5555555555555555))\
    \ << 1) | ((x & UINT64_C(0xAAAAAAAAAAAAAAAA)) >> 1);\n    x = ((x & UINT64_C(0x3333333333333333))\
    \ << 2) | ((x & UINT64_C(0xCCCCCCCCCCCCCCCC)) >> 2);\n    x = ((x & UINT64_C(0x0F0F0F0F0F0F0F0F))\
    \ << 4) | ((x & UINT64_C(0xF0F0F0F0F0F0F0F0)) >> 4);\n    x = ((x & UINT64_C(0x00FF00FF00FF00FF))\
    \ << 8) | ((x & UINT64_C(0xFF00FF00FF00FF00)) >> 8);\n    x = ((x & UINT64_C(0x0000FFFF0000FFFF))\
    \ << 16) | ((x & UINT64_C(0xFFFF0000FFFF0000)) >> 16);\n    x = ((x & UINT64_C(0x00000000FFFFFFFF))\
    \ << 32) | ((x & UINT64_C(0xFFFFFFFF00000000)) >> 32);\n    x >>= (::std::numeric_limits<T>::digits\
    \ - n) & (::std::numeric_limits<T>::digits - 1);\n    return x;\n  }\n  template\
    \ <typename T>\n  ::std::enable_if_t<::std::is_integral_v<T> && ::std::is_signed_v<T>,\
    \ T> reverse(const T x, const ::std::size_t n) {\n    assert(x >= 0);\n    return\
    \ ::tools::reverse(static_cast<::std::make_unsigned_t<T>>(x), n);\n  }\n}\n\n\n"
  code: "#ifndef TOOLS_REVERSE_HPP\n#define TOOLS_REVERSE_HPP\n\n#include <type_traits>\n\
    #include <limits>\n#include <cstddef>\n#include <cassert>\n#include <cstdint>\n\
    #include \"tools/floor_log2.hpp\"\n\nnamespace tools {\n  template <typename T>\n\
    \  ::std::enable_if_t<::std::is_integral_v<T> && !::std::is_signed_v<T> && ::std::numeric_limits<T>::digits\
    \ == 1, T> reverse(const T x, const ::std::size_t n) {\n    assert(n <= ::std::numeric_limits<T>::digits);\n\
    \    assert(!x || n == 1);\n    return x;\n  }\n  template <typename T>\n  ::std::enable_if_t<::std::is_integral_v<T>\
    \ && !::std::is_signed_v<T> && ::std::numeric_limits<T>::digits == 8, T> reverse(T\
    \ x, const ::std::size_t n) {\n    assert(n <= ::std::numeric_limits<T>::digits);\n\
    \    assert(x == 0 || ::tools::floor_log2(x) < n);\n    x = ((x & UINT8_C(0x55))\
    \ << 1) | ((x & UINT8_C(0xAA)) >> 1);\n    x = ((x & UINT8_C(0x33)) << 2) | ((x\
    \ & UINT8_C(0xCC)) >> 2);\n    x = ((x & UINT8_C(0x0F)) << 4) | ((x & UINT8_C(0xF0))\
    \ >> 4);\n    x >>= (::std::numeric_limits<T>::digits - n) & (::std::numeric_limits<T>::digits\
    \ - 1);\n    return x;\n  }\n  template <typename T>\n  ::std::enable_if_t<::std::is_integral_v<T>\
    \ && !::std::is_signed_v<T> && ::std::numeric_limits<T>::digits == 16, T> reverse(T\
    \ x, const ::std::size_t n) {\n    assert(n <= ::std::numeric_limits<T>::digits);\n\
    \    assert(x == 0 || ::tools::floor_log2(x) < n);\n    x = ((x & UINT16_C(0x5555))\
    \ << 1) | ((x & UINT16_C(0xAAAA)) >> 1);\n    x = ((x & UINT16_C(0x3333)) << 2)\
    \ | ((x & UINT16_C(0xCCCC)) >> 2);\n    x = ((x & UINT16_C(0x0F0F)) << 4) | ((x\
    \ & UINT16_C(0xF0F0)) >> 4);\n    x = ((x & UINT16_C(0x00FF)) << 8) | ((x & UINT16_C(0xFF00))\
    \ >> 8);\n    x >>= (::std::numeric_limits<T>::digits - n) & (::std::numeric_limits<T>::digits\
    \ - 1);\n    return x;\n  }\n  template <typename T>\n  ::std::enable_if_t<::std::is_integral_v<T>\
    \ && !::std::is_signed_v<T> && ::std::numeric_limits<T>::digits == 32, T> reverse(T\
    \ x, const ::std::size_t n) {\n    assert(n <= ::std::numeric_limits<T>::digits);\n\
    \    assert(x == 0 || ::tools::floor_log2(x) < n);\n    x = ((x & UINT32_C(0x55555555))\
    \ << 1) | ((x & UINT32_C(0xAAAAAAAA)) >> 1);\n    x = ((x & UINT32_C(0x33333333))\
    \ << 2) | ((x & UINT32_C(0xCCCCCCCC)) >> 2);\n    x = ((x & UINT32_C(0x0F0F0F0F))\
    \ << 4) | ((x & UINT32_C(0xF0F0F0F0)) >> 4);\n    x = ((x & UINT32_C(0x00FF00FF))\
    \ << 8) | ((x & UINT32_C(0xFF00FF00)) >> 8);\n    x = ((x & UINT32_C(0x0000FFFF))\
    \ << 16) | ((x & UINT32_C(0xFFFF0000)) >> 16);\n    x >>= (::std::numeric_limits<T>::digits\
    \ - n) & (::std::numeric_limits<T>::digits - 1);\n    return x;\n  }\n  template\
    \ <typename T>\n  ::std::enable_if_t<::std::is_integral_v<T> && !::std::is_signed_v<T>\
    \ && ::std::numeric_limits<T>::digits == 64, T> reverse(T x, const ::std::size_t\
    \ n) {\n    assert(n <= ::std::numeric_limits<T>::digits);\n    assert(x == 0\
    \ || ::tools::floor_log2(x) < n);\n    x = ((x & UINT64_C(0x5555555555555555))\
    \ << 1) | ((x & UINT64_C(0xAAAAAAAAAAAAAAAA)) >> 1);\n    x = ((x & UINT64_C(0x3333333333333333))\
    \ << 2) | ((x & UINT64_C(0xCCCCCCCCCCCCCCCC)) >> 2);\n    x = ((x & UINT64_C(0x0F0F0F0F0F0F0F0F))\
    \ << 4) | ((x & UINT64_C(0xF0F0F0F0F0F0F0F0)) >> 4);\n    x = ((x & UINT64_C(0x00FF00FF00FF00FF))\
    \ << 8) | ((x & UINT64_C(0xFF00FF00FF00FF00)) >> 8);\n    x = ((x & UINT64_C(0x0000FFFF0000FFFF))\
    \ << 16) | ((x & UINT64_C(0xFFFF0000FFFF0000)) >> 16);\n    x = ((x & UINT64_C(0x00000000FFFFFFFF))\
    \ << 32) | ((x & UINT64_C(0xFFFFFFFF00000000)) >> 32);\n    x >>= (::std::numeric_limits<T>::digits\
    \ - n) & (::std::numeric_limits<T>::digits - 1);\n    return x;\n  }\n  template\
    \ <typename T>\n  ::std::enable_if_t<::std::is_integral_v<T> && ::std::is_signed_v<T>,\
    \ T> reverse(const T x, const ::std::size_t n) {\n    assert(x >= 0);\n    return\
    \ ::tools::reverse(static_cast<::std::make_unsigned_t<T>>(x), n);\n  }\n}\n\n\
    #endif\n"
  dependsOn:
  - tools/floor_log2.hpp
  - tools/popcount.hpp
  isVerificationFile: false
  path: tools/reverse.hpp
  requiredBy: []
  timestamp: '2024-11-22 20:21:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/reverse.test.cpp
documentation_of: tools/reverse.hpp
layout: document
title: Bit reverse
---

```cpp
template <typename T>
T reverse(T x, std::size_t n);
```

It returns $r$ which satisfies the followings.
- $0 \leq r < 2^n$
- For all $i$ such that $0 \leq i < n$, the $i$-th bit of $r$ is equal to the $(n - 1 - i)$-th bit of $x$.

### Constraints
- `<T>` is an integral type
- $n \leq$ `std::numeric_limits<T>::digits`
- $0 \leq x < 2^n$

### Time Complexity
- $O(\log n)$

### License
- CC0

### Author
- anqooqie
