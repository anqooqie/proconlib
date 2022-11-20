---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: tools/popcount.hpp
    title: Popcount
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: tools/chromatic_number.hpp
    title: Chromatic number
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/chromatic_number.test.cpp
    title: tests/chromatic_number.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/ntz.hpp\"\n\n\n\n#include <type_traits>\n#include\
    \ <cassert>\n#line 1 \"tools/popcount.hpp\"\n\n\n\n#line 6 \"tools/popcount.hpp\"\
    \n#include <limits>\n#include <cstdint>\n\nnamespace tools {\n\n  template <typename\
    \ T>\n  T popcount(T x) {\n    static_assert(::std::is_integral_v<T>);\n    assert(x\
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
    \      }\n\n      return x;\n    }\n  }\n}\n\n\n#line 7 \"tools/ntz.hpp\"\n\n\
    namespace tools {\n\n  template <typename T>\n  T ntz(T x) {\n    static_assert(::std::is_integral_v<T>);\n\
    \    assert(x > 0);\n    if constexpr (::std::is_signed_v<T>) {\n      return\
    \ static_cast<T>(::tools::ntz<::std::make_unsigned_t<T>>(x));\n    } else {\n\
    \      return ::tools::popcount((x & -x) - static_cast<T>(1));\n    }\n  }\n}\n\
    \n\n"
  code: "#ifndef TOOLS_NTZ_HPP\n#define TOOLS_NTZ_HPP\n\n#include <type_traits>\n\
    #include <cassert>\n#include \"tools/popcount.hpp\"\n\nnamespace tools {\n\n \
    \ template <typename T>\n  T ntz(T x) {\n    static_assert(::std::is_integral_v<T>);\n\
    \    assert(x > 0);\n    if constexpr (::std::is_signed_v<T>) {\n      return\
    \ static_cast<T>(::tools::ntz<::std::make_unsigned_t<T>>(x));\n    } else {\n\
    \      return ::tools::popcount((x & -x) - static_cast<T>(1));\n    }\n  }\n}\n\
    \n#endif\n"
  dependsOn:
  - tools/popcount.hpp
  isVerificationFile: false
  path: tools/ntz.hpp
  requiredBy:
  - tools/chromatic_number.hpp
  timestamp: '2022-10-08 19:22:04+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/chromatic_number.test.cpp
documentation_of: tools/ntz.hpp
layout: document
title: Number of trailing zeros
---

```cpp
template <typename T>
T ntz(T x);
```

It returns the number of trailing zeros. (e.g., ntz(0b10100) = 2)

## Constraints
- $x > 0$
- `std::numeric_limits<T>::digits` is $8$, $16$, $32$ or $64$.

## Time Complexity
- $O(\log\log x)$

## License
- CC0

## Author
- anqooqie
