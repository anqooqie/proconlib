---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: tools/assert_that.hpp
    title: Assertion macro
  - icon: ':heavy_check_mark:'
    path: tools/floor_log2.hpp
    title: $\left\lfloor \log_2(x) \right\rfloor$
  - icon: ':question:'
    path: tools/popcount.hpp
    title: Popcount
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A
  bundledCode: "#line 1 \"tests/floor_log2.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\"\
    \n\n#include <iostream>\n#include <cstdint>\n#line 1 \"tools/assert_that.hpp\"\
    \n\n\n\n#line 5 \"tools/assert_that.hpp\"\n#include <cstdlib>\n\n#define assert_that(cond)\
    \ do {\\\n  if (!(cond)) {\\\n    ::std::cerr << __FILE__ << ':' << __LINE__ <<\
    \ \": \" << __func__ << \": Assertion `\" << #cond << \"' failed.\" << '\\n';\\\
    \n    ::std::exit(EXIT_FAILURE);\\\n  }\\\n} while (false)\n\n\n#line 1 \"tools/floor_log2.hpp\"\
    \n\n\n\n#include <type_traits>\n#include <cassert>\n#include <limits>\n#line 1\
    \ \"tools/popcount.hpp\"\n\n\n\n#line 8 \"tools/popcount.hpp\"\n\nnamespace tools\
    \ {\n\n  template <typename T>\n  T popcount(T x) {\n    static_assert(::std::is_integral_v<T>);\n\
    \    assert(x >= 0);\n    if constexpr (::std::is_signed_v<T>) {\n      return\
    \ static_cast<T>(::tools::popcount<::std::make_unsigned_t<T>>(x));\n    } else\
    \ {\n      const auto log2 = [](const int w) {\n        if (w == 8) return 3;\n\
    \        if (w == 16) return 4;\n        if (w == 32) return 5;\n        if (w\
    \ == 64) return 6;\n        return -1;\n      };\n      static_assert(log2(::std::numeric_limits<T>::digits)\
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
    \ 7 \"tests/floor_log2.test.cpp\"\n\nint main() {\n  std::cin.tie(nullptr);\n\
    \  std::ios_base::sync_with_stdio(false);\n\n  assert_that(tools::floor_log2(INT32_C(1))\
    \ == 0);\n  assert_that(tools::floor_log2(INT32_C(2)) == 1);\n  assert_that(tools::floor_log2(INT32_C(3))\
    \ == 1);\n  assert_that(tools::floor_log2(INT32_C(4)) == 2);\n  assert_that(tools::floor_log2(INT32_C(5))\
    \ == 2);\n  assert_that(tools::floor_log2(INT32_C(6)) == 2);\n  assert_that(tools::floor_log2(INT32_C(7))\
    \ == 2);\n  assert_that(tools::floor_log2(INT32_C(8)) == 3);\n  assert_that(tools::floor_log2(INT32_C(9))\
    \ == 3);\n  assert_that(tools::floor_log2(INT32_C(1073741823)) == 29);\n  assert_that(tools::floor_log2(INT32_C(1073741824))\
    \ == 30);\n  assert_that(tools::floor_log2(INT32_C(1073741825)) == 30);\n  assert_that(tools::floor_log2(INT32_C(2147483647))\
    \ == 30);\n\n  assert_that(tools::floor_log2(UINT32_C(1)) == 0);\n  assert_that(tools::floor_log2(UINT32_C(2))\
    \ == 1);\n  assert_that(tools::floor_log2(UINT32_C(3)) == 1);\n  assert_that(tools::floor_log2(UINT32_C(4))\
    \ == 2);\n  assert_that(tools::floor_log2(UINT32_C(5)) == 2);\n  assert_that(tools::floor_log2(UINT32_C(6))\
    \ == 2);\n  assert_that(tools::floor_log2(UINT32_C(7)) == 2);\n  assert_that(tools::floor_log2(UINT32_C(8))\
    \ == 3);\n  assert_that(tools::floor_log2(UINT32_C(9)) == 3);\n  assert_that(tools::floor_log2(UINT32_C(2147483647))\
    \ == 30);\n  assert_that(tools::floor_log2(UINT32_C(2147483648)) == 31);\n  assert_that(tools::floor_log2(UINT32_C(2147483649))\
    \ == 31);\n  assert_that(tools::floor_log2(UINT32_C(4294967295)) == 31);\n\n \
    \ assert_that(tools::floor_log2(INT64_C(1)) == 0);\n  assert_that(tools::floor_log2(INT64_C(2))\
    \ == 1);\n  assert_that(tools::floor_log2(INT64_C(3)) == 1);\n  assert_that(tools::floor_log2(INT64_C(4))\
    \ == 2);\n  assert_that(tools::floor_log2(INT64_C(5)) == 2);\n  assert_that(tools::floor_log2(INT64_C(6))\
    \ == 2);\n  assert_that(tools::floor_log2(INT64_C(7)) == 2);\n  assert_that(tools::floor_log2(INT64_C(8))\
    \ == 3);\n  assert_that(tools::floor_log2(INT64_C(9)) == 3);\n  assert_that(tools::floor_log2(INT64_C(4611686018427387903))\
    \ == 61);\n  assert_that(tools::floor_log2(INT64_C(4611686018427387904)) == 62);\n\
    \  assert_that(tools::floor_log2(INT64_C(4611686018427387905)) == 62);\n  assert_that(tools::floor_log2(INT64_C(9223372036854775807))\
    \ == 62);\n\n  assert_that(tools::floor_log2(UINT64_C(1)) == 0);\n  assert_that(tools::floor_log2(UINT64_C(2))\
    \ == 1);\n  assert_that(tools::floor_log2(UINT64_C(3)) == 1);\n  assert_that(tools::floor_log2(UINT64_C(4))\
    \ == 2);\n  assert_that(tools::floor_log2(UINT64_C(5)) == 2);\n  assert_that(tools::floor_log2(UINT64_C(6))\
    \ == 2);\n  assert_that(tools::floor_log2(UINT64_C(7)) == 2);\n  assert_that(tools::floor_log2(UINT64_C(8))\
    \ == 3);\n  assert_that(tools::floor_log2(UINT64_C(9)) == 3);\n  assert_that(tools::floor_log2(UINT64_C(9223372036854775807))\
    \ == 62);\n  assert_that(tools::floor_log2(UINT64_C(9223372036854775808)) == 63);\n\
    \  assert_that(tools::floor_log2(UINT64_C(9223372036854775809)) == 63);\n  assert_that(tools::floor_log2(UINT64_C(18446744073709551615))\
    \ == 63);\n\n  std::cout << \"Hello World\" << '\\n';\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\"\n\n\
    #include <iostream>\n#include <cstdint>\n#include \"tools/assert_that.hpp\"\n\
    #include \"tools/floor_log2.hpp\"\n\nint main() {\n  std::cin.tie(nullptr);\n\
    \  std::ios_base::sync_with_stdio(false);\n\n  assert_that(tools::floor_log2(INT32_C(1))\
    \ == 0);\n  assert_that(tools::floor_log2(INT32_C(2)) == 1);\n  assert_that(tools::floor_log2(INT32_C(3))\
    \ == 1);\n  assert_that(tools::floor_log2(INT32_C(4)) == 2);\n  assert_that(tools::floor_log2(INT32_C(5))\
    \ == 2);\n  assert_that(tools::floor_log2(INT32_C(6)) == 2);\n  assert_that(tools::floor_log2(INT32_C(7))\
    \ == 2);\n  assert_that(tools::floor_log2(INT32_C(8)) == 3);\n  assert_that(tools::floor_log2(INT32_C(9))\
    \ == 3);\n  assert_that(tools::floor_log2(INT32_C(1073741823)) == 29);\n  assert_that(tools::floor_log2(INT32_C(1073741824))\
    \ == 30);\n  assert_that(tools::floor_log2(INT32_C(1073741825)) == 30);\n  assert_that(tools::floor_log2(INT32_C(2147483647))\
    \ == 30);\n\n  assert_that(tools::floor_log2(UINT32_C(1)) == 0);\n  assert_that(tools::floor_log2(UINT32_C(2))\
    \ == 1);\n  assert_that(tools::floor_log2(UINT32_C(3)) == 1);\n  assert_that(tools::floor_log2(UINT32_C(4))\
    \ == 2);\n  assert_that(tools::floor_log2(UINT32_C(5)) == 2);\n  assert_that(tools::floor_log2(UINT32_C(6))\
    \ == 2);\n  assert_that(tools::floor_log2(UINT32_C(7)) == 2);\n  assert_that(tools::floor_log2(UINT32_C(8))\
    \ == 3);\n  assert_that(tools::floor_log2(UINT32_C(9)) == 3);\n  assert_that(tools::floor_log2(UINT32_C(2147483647))\
    \ == 30);\n  assert_that(tools::floor_log2(UINT32_C(2147483648)) == 31);\n  assert_that(tools::floor_log2(UINT32_C(2147483649))\
    \ == 31);\n  assert_that(tools::floor_log2(UINT32_C(4294967295)) == 31);\n\n \
    \ assert_that(tools::floor_log2(INT64_C(1)) == 0);\n  assert_that(tools::floor_log2(INT64_C(2))\
    \ == 1);\n  assert_that(tools::floor_log2(INT64_C(3)) == 1);\n  assert_that(tools::floor_log2(INT64_C(4))\
    \ == 2);\n  assert_that(tools::floor_log2(INT64_C(5)) == 2);\n  assert_that(tools::floor_log2(INT64_C(6))\
    \ == 2);\n  assert_that(tools::floor_log2(INT64_C(7)) == 2);\n  assert_that(tools::floor_log2(INT64_C(8))\
    \ == 3);\n  assert_that(tools::floor_log2(INT64_C(9)) == 3);\n  assert_that(tools::floor_log2(INT64_C(4611686018427387903))\
    \ == 61);\n  assert_that(tools::floor_log2(INT64_C(4611686018427387904)) == 62);\n\
    \  assert_that(tools::floor_log2(INT64_C(4611686018427387905)) == 62);\n  assert_that(tools::floor_log2(INT64_C(9223372036854775807))\
    \ == 62);\n\n  assert_that(tools::floor_log2(UINT64_C(1)) == 0);\n  assert_that(tools::floor_log2(UINT64_C(2))\
    \ == 1);\n  assert_that(tools::floor_log2(UINT64_C(3)) == 1);\n  assert_that(tools::floor_log2(UINT64_C(4))\
    \ == 2);\n  assert_that(tools::floor_log2(UINT64_C(5)) == 2);\n  assert_that(tools::floor_log2(UINT64_C(6))\
    \ == 2);\n  assert_that(tools::floor_log2(UINT64_C(7)) == 2);\n  assert_that(tools::floor_log2(UINT64_C(8))\
    \ == 3);\n  assert_that(tools::floor_log2(UINT64_C(9)) == 3);\n  assert_that(tools::floor_log2(UINT64_C(9223372036854775807))\
    \ == 62);\n  assert_that(tools::floor_log2(UINT64_C(9223372036854775808)) == 63);\n\
    \  assert_that(tools::floor_log2(UINT64_C(9223372036854775809)) == 63);\n  assert_that(tools::floor_log2(UINT64_C(18446744073709551615))\
    \ == 63);\n\n  std::cout << \"Hello World\" << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - tools/assert_that.hpp
  - tools/floor_log2.hpp
  - tools/popcount.hpp
  isVerificationFile: true
  path: tests/floor_log2.test.cpp
  requiredBy: []
  timestamp: '2022-10-08 19:22:04+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/floor_log2.test.cpp
layout: document
redirect_from:
- /verify/tests/floor_log2.test.cpp
- /verify/tests/floor_log2.test.cpp.html
title: tests/floor_log2.test.cpp
---
