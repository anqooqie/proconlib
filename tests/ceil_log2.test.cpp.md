---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/assert_that.hpp
    title: Assertion macro
  - icon: ':heavy_check_mark:'
    path: tools/ceil_log2.hpp
    title: $\left\lceil \log_2(x) \right\rceil$
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
  bundledCode: "#line 1 \"tests/ceil_log2.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\"\
    \n\n#include <cstdlib>\n#include <iostream>\n#include <cstdint>\n#line 1 \"tools/assert_that.hpp\"\
    \n\n\n\n#line 6 \"tools/assert_that.hpp\"\n\n#define assert_that(cond) do {\\\n\
    \  if (!(cond)) {\\\n    ::std::cerr << __FILE__ << ':' << __LINE__ << \": \"\
    \ << __func__ << \": Assertion `\" << #cond << \"' failed.\" << '\\n';\\\n   \
    \ ::std::exit(EXIT_FAILURE);\\\n  }\\\n} while (false)\n\n\n#line 1 \"tools/ceil_log2.hpp\"\
    \n\n\n\n#include <type_traits>\n#include <cassert>\n#include <limits>\n#include\
    \ <tuple>\n#include <array>\n#line 10 \"tools/ceil_log2.hpp\"\n\n// Source: https://stackoverflow.com/questions/3272424/compute-fast-log-base-2-ceiling/15327567#15327567\n\
    // License: CC BY-SA 3.0\n// Author: dgobbi\n\nnamespace tools {\n\n  template\
    \ <typename T>\n  T ceil_log2(T x) {\n    static_assert(::std::is_integral_v<T>);\n\
    \    assert(x > 0);\n    if constexpr (::std::is_signed_v<T>) {\n      return\
    \ static_cast<T>(::tools::ceil_log2<::std::make_unsigned_t<T>>(x));\n    } else\
    \ {\n      const auto log2 = [](const int w) {\n        if (w == 8) return 3;\n\
    \        if (w == 16) return 4;\n        if (w == 32) return 5;\n        if (w\
    \ == 64) return 6;\n        return -1;\n      };\n      static_assert(log2(::std::numeric_limits<T>::digits)\
    \ >= 0);\n\n      constexpr auto t = ::std::make_tuple(\n        ::std::array<::std::uint8_t,\
    \ 3>({\n          UINT8_C(0xf0),\n          UINT8_C(0x0c),\n          UINT8_C(0x02)\n\
    \        }),\n        ::std::array<::std::uint16_t, 4>({\n          UINT16_C(0xff00),\n\
    \          UINT16_C(0x00f0),\n          UINT16_C(0x000c),\n          UINT16_C(0x0002)\n\
    \        }),\n        ::std::array<::std::uint32_t, 5>({\n          UINT32_C(0xffff0000),\n\
    \          UINT32_C(0x0000ff00),\n          UINT32_C(0x000000f0),\n          UINT32_C(0x0000000c),\n\
    \          UINT32_C(0x00000002)\n        }),\n        ::std::array<::std::uint64_t,\
    \ 6>({\n          UINT64_C(0xffffffff00000000),\n          UINT64_C(0x00000000ffff0000),\n\
    \          UINT64_C(0x000000000000ff00),\n          UINT64_C(0x00000000000000f0),\n\
    \          UINT64_C(0x000000000000000c),\n          UINT64_C(0x0000000000000002)\n\
    \        })\n      );\n\n      T y = (((x & (x - 1)) == 0) ? 0 : 1);\n      T\
    \ j = ::std::numeric_limits<T>::digits / 2;\n\n      for (const auto t_i : ::std::get<log2(::std::numeric_limits<T>::digits)\
    \ - 3>(t)) {\n        T k = (((x & t_i) == 0) ? 0 : j);\n        y += k;\n   \
    \     x >>= k;\n        j >>= 1;\n      }\n\n      return y;\n    }\n  }\n}\n\n\
    \n#line 8 \"tests/ceil_log2.test.cpp\"\n\nint main() {\n  std::cin.tie(nullptr);\n\
    \  std::ios_base::sync_with_stdio(false);\n\n  assert_that(tools::ceil_log2(INT32_C(1))\
    \ == 0);\n  assert_that(tools::ceil_log2(INT32_C(2)) == 1);\n  assert_that(tools::ceil_log2(INT32_C(3))\
    \ == 2);\n  assert_that(tools::ceil_log2(INT32_C(4)) == 2);\n  assert_that(tools::ceil_log2(INT32_C(5))\
    \ == 3);\n  assert_that(tools::ceil_log2(INT32_C(6)) == 3);\n  assert_that(tools::ceil_log2(INT32_C(7))\
    \ == 3);\n  assert_that(tools::ceil_log2(INT32_C(8)) == 3);\n  assert_that(tools::ceil_log2(INT32_C(9))\
    \ == 4);\n  assert_that(tools::ceil_log2(INT32_C(1073741823)) == 30);\n  assert_that(tools::ceil_log2(INT32_C(1073741824))\
    \ == 30);\n  assert_that(tools::ceil_log2(INT32_C(1073741825)) == 31);\n  assert_that(tools::ceil_log2(INT32_C(2147483647))\
    \ == 31);\n\n  assert_that(tools::ceil_log2(UINT32_C(1)) == 0);\n  assert_that(tools::ceil_log2(UINT32_C(2))\
    \ == 1);\n  assert_that(tools::ceil_log2(UINT32_C(3)) == 2);\n  assert_that(tools::ceil_log2(UINT32_C(4))\
    \ == 2);\n  assert_that(tools::ceil_log2(UINT32_C(5)) == 3);\n  assert_that(tools::ceil_log2(UINT32_C(6))\
    \ == 3);\n  assert_that(tools::ceil_log2(UINT32_C(7)) == 3);\n  assert_that(tools::ceil_log2(UINT32_C(8))\
    \ == 3);\n  assert_that(tools::ceil_log2(UINT32_C(9)) == 4);\n  assert_that(tools::ceil_log2(UINT32_C(2147483647))\
    \ == 31);\n  assert_that(tools::ceil_log2(UINT32_C(2147483648)) == 31);\n  assert_that(tools::ceil_log2(UINT32_C(2147483649))\
    \ == 32);\n  assert_that(tools::ceil_log2(UINT32_C(4294967295)) == 32);\n\n  assert_that(tools::ceil_log2(INT64_C(1))\
    \ == 0);\n  assert_that(tools::ceil_log2(INT64_C(2)) == 1);\n  assert_that(tools::ceil_log2(INT64_C(3))\
    \ == 2);\n  assert_that(tools::ceil_log2(INT64_C(4)) == 2);\n  assert_that(tools::ceil_log2(INT64_C(5))\
    \ == 3);\n  assert_that(tools::ceil_log2(INT64_C(6)) == 3);\n  assert_that(tools::ceil_log2(INT64_C(7))\
    \ == 3);\n  assert_that(tools::ceil_log2(INT64_C(8)) == 3);\n  assert_that(tools::ceil_log2(INT64_C(9))\
    \ == 4);\n  assert_that(tools::ceil_log2(INT64_C(4611686018427387903)) == 62);\n\
    \  assert_that(tools::ceil_log2(INT64_C(4611686018427387904)) == 62);\n  assert_that(tools::ceil_log2(INT64_C(4611686018427387905))\
    \ == 63);\n  assert_that(tools::ceil_log2(INT64_C(9223372036854775807)) == 63);\n\
    \n  assert_that(tools::ceil_log2(UINT64_C(1)) == 0);\n  assert_that(tools::ceil_log2(UINT64_C(2))\
    \ == 1);\n  assert_that(tools::ceil_log2(UINT64_C(3)) == 2);\n  assert_that(tools::ceil_log2(UINT64_C(4))\
    \ == 2);\n  assert_that(tools::ceil_log2(UINT64_C(5)) == 3);\n  assert_that(tools::ceil_log2(UINT64_C(6))\
    \ == 3);\n  assert_that(tools::ceil_log2(UINT64_C(7)) == 3);\n  assert_that(tools::ceil_log2(UINT64_C(8))\
    \ == 3);\n  assert_that(tools::ceil_log2(UINT64_C(9)) == 4);\n  assert_that(tools::ceil_log2(UINT64_C(9223372036854775807))\
    \ == 63);\n  assert_that(tools::ceil_log2(UINT64_C(9223372036854775808)) == 63);\n\
    \  assert_that(tools::ceil_log2(UINT64_C(9223372036854775809)) == 64);\n  assert_that(tools::ceil_log2(UINT64_C(18446744073709551615))\
    \ == 64);\n\n  std::cout << \"Hello World\" << '\\n';\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\"\n\n\
    #include <cstdlib>\n#include <iostream>\n#include <cstdint>\n#include \"tools/assert_that.hpp\"\
    \n#include \"tools/ceil_log2.hpp\"\n\nint main() {\n  std::cin.tie(nullptr);\n\
    \  std::ios_base::sync_with_stdio(false);\n\n  assert_that(tools::ceil_log2(INT32_C(1))\
    \ == 0);\n  assert_that(tools::ceil_log2(INT32_C(2)) == 1);\n  assert_that(tools::ceil_log2(INT32_C(3))\
    \ == 2);\n  assert_that(tools::ceil_log2(INT32_C(4)) == 2);\n  assert_that(tools::ceil_log2(INT32_C(5))\
    \ == 3);\n  assert_that(tools::ceil_log2(INT32_C(6)) == 3);\n  assert_that(tools::ceil_log2(INT32_C(7))\
    \ == 3);\n  assert_that(tools::ceil_log2(INT32_C(8)) == 3);\n  assert_that(tools::ceil_log2(INT32_C(9))\
    \ == 4);\n  assert_that(tools::ceil_log2(INT32_C(1073741823)) == 30);\n  assert_that(tools::ceil_log2(INT32_C(1073741824))\
    \ == 30);\n  assert_that(tools::ceil_log2(INT32_C(1073741825)) == 31);\n  assert_that(tools::ceil_log2(INT32_C(2147483647))\
    \ == 31);\n\n  assert_that(tools::ceil_log2(UINT32_C(1)) == 0);\n  assert_that(tools::ceil_log2(UINT32_C(2))\
    \ == 1);\n  assert_that(tools::ceil_log2(UINT32_C(3)) == 2);\n  assert_that(tools::ceil_log2(UINT32_C(4))\
    \ == 2);\n  assert_that(tools::ceil_log2(UINT32_C(5)) == 3);\n  assert_that(tools::ceil_log2(UINT32_C(6))\
    \ == 3);\n  assert_that(tools::ceil_log2(UINT32_C(7)) == 3);\n  assert_that(tools::ceil_log2(UINT32_C(8))\
    \ == 3);\n  assert_that(tools::ceil_log2(UINT32_C(9)) == 4);\n  assert_that(tools::ceil_log2(UINT32_C(2147483647))\
    \ == 31);\n  assert_that(tools::ceil_log2(UINT32_C(2147483648)) == 31);\n  assert_that(tools::ceil_log2(UINT32_C(2147483649))\
    \ == 32);\n  assert_that(tools::ceil_log2(UINT32_C(4294967295)) == 32);\n\n  assert_that(tools::ceil_log2(INT64_C(1))\
    \ == 0);\n  assert_that(tools::ceil_log2(INT64_C(2)) == 1);\n  assert_that(tools::ceil_log2(INT64_C(3))\
    \ == 2);\n  assert_that(tools::ceil_log2(INT64_C(4)) == 2);\n  assert_that(tools::ceil_log2(INT64_C(5))\
    \ == 3);\n  assert_that(tools::ceil_log2(INT64_C(6)) == 3);\n  assert_that(tools::ceil_log2(INT64_C(7))\
    \ == 3);\n  assert_that(tools::ceil_log2(INT64_C(8)) == 3);\n  assert_that(tools::ceil_log2(INT64_C(9))\
    \ == 4);\n  assert_that(tools::ceil_log2(INT64_C(4611686018427387903)) == 62);\n\
    \  assert_that(tools::ceil_log2(INT64_C(4611686018427387904)) == 62);\n  assert_that(tools::ceil_log2(INT64_C(4611686018427387905))\
    \ == 63);\n  assert_that(tools::ceil_log2(INT64_C(9223372036854775807)) == 63);\n\
    \n  assert_that(tools::ceil_log2(UINT64_C(1)) == 0);\n  assert_that(tools::ceil_log2(UINT64_C(2))\
    \ == 1);\n  assert_that(tools::ceil_log2(UINT64_C(3)) == 2);\n  assert_that(tools::ceil_log2(UINT64_C(4))\
    \ == 2);\n  assert_that(tools::ceil_log2(UINT64_C(5)) == 3);\n  assert_that(tools::ceil_log2(UINT64_C(6))\
    \ == 3);\n  assert_that(tools::ceil_log2(UINT64_C(7)) == 3);\n  assert_that(tools::ceil_log2(UINT64_C(8))\
    \ == 3);\n  assert_that(tools::ceil_log2(UINT64_C(9)) == 4);\n  assert_that(tools::ceil_log2(UINT64_C(9223372036854775807))\
    \ == 63);\n  assert_that(tools::ceil_log2(UINT64_C(9223372036854775808)) == 63);\n\
    \  assert_that(tools::ceil_log2(UINT64_C(9223372036854775809)) == 64);\n  assert_that(tools::ceil_log2(UINT64_C(18446744073709551615))\
    \ == 64);\n\n  std::cout << \"Hello World\" << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - tools/assert_that.hpp
  - tools/ceil_log2.hpp
  isVerificationFile: true
  path: tests/ceil_log2.test.cpp
  requiredBy: []
  timestamp: '2022-10-08 19:22:04+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/ceil_log2.test.cpp
layout: document
redirect_from:
- /verify/tests/ceil_log2.test.cpp
- /verify/tests/ceil_log2.test.cpp.html
title: tests/ceil_log2.test.cpp
---
