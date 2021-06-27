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
    \n\n#include <cstdlib>\n#include <iostream>\n#include <cstdint>\n#line 1 \"tools/floor_log2.hpp\"\
    \n\n\n\n#line 1 \"tools/popcount.hpp\"\n\n\n\n#line 5 \"tools/popcount.hpp\"\n\
    \nnamespace tools {\n\n  inline ::std::uint32_t popcount(::std::uint32_t x) {\n\
    \    x = (x & static_cast<::std::uint32_t>(0x55555555ull)) + (x >> static_cast<::std::uint32_t>(1)\
    \ & static_cast<::std::uint32_t>(0x55555555ull));\n    x = (x & static_cast<::std::uint32_t>(0x33333333ull))\
    \ + (x >> static_cast<::std::uint32_t>(2) & static_cast<::std::uint32_t>(0x33333333ull));\n\
    \    x = (x & static_cast<::std::uint32_t>(0x0f0f0f0full)) + (x >> static_cast<::std::uint32_t>(4)\
    \ & static_cast<::std::uint32_t>(0x0f0f0f0full));\n    x = (x & static_cast<::std::uint32_t>(0x00ff00ffull))\
    \ + (x >> static_cast<::std::uint32_t>(8) & static_cast<::std::uint32_t>(0x00ff00ffull));\n\
    \    return (x & static_cast<::std::uint32_t>(0x0000ffffull)) + (x >> static_cast<::std::uint32_t>(16)\
    \ & static_cast<::std::uint32_t>(0x0000ffffull));\n  }\n\n  inline ::std::uint64_t\
    \ popcount(::std::uint64_t x) {\n    x = (x & static_cast<::std::uint64_t>(0x5555555555555555ull))\
    \ + (x >> static_cast<::std::uint64_t>(1) & static_cast<::std::uint64_t>(0x5555555555555555ull));\n\
    \    x = (x & static_cast<::std::uint64_t>(0x3333333333333333ull)) + (x >> static_cast<::std::uint64_t>(2)\
    \ & static_cast<::std::uint64_t>(0x3333333333333333ull));\n    x = (x & static_cast<::std::uint64_t>(0x0f0f0f0f0f0f0f0full))\
    \ + (x >> static_cast<::std::uint64_t>(4) & static_cast<::std::uint64_t>(0x0f0f0f0f0f0f0f0full));\n\
    \    x = (x & static_cast<::std::uint64_t>(0x00ff00ff00ff00ffull)) + (x >> static_cast<::std::uint64_t>(8)\
    \ & static_cast<::std::uint64_t>(0x00ff00ff00ff00ffull));\n    x = (x & static_cast<::std::uint64_t>(0x0000ffff0000ffffull))\
    \ + (x >> static_cast<::std::uint64_t>(16) & static_cast<::std::uint64_t>(0x0000ffff0000ffffull));\n\
    \    return (x & static_cast<::std::uint64_t>(0x00000000ffffffffull)) + (x >>\
    \ static_cast<::std::uint64_t>(32) & static_cast<::std::uint64_t>(0x00000000ffffffffull));\n\
    \  }\n\n  inline ::std::int32_t popcount(::std::int32_t x) {\n    return static_cast<::std::int32_t>(::tools::popcount(static_cast<::std::uint32_t>(x)));\n\
    \  }\n\n  inline ::std::int64_t popcount(::std::int64_t x) {\n    return static_cast<::std::int64_t>(::tools::popcount(static_cast<::std::uint64_t>(x)));\n\
    \  }\n}\n\n\n#line 6 \"tools/floor_log2.hpp\"\n\nnamespace tools {\n\n  inline\
    \ ::std::uint32_t floor_log2(::std::uint32_t x) {\n    x |= (x >> static_cast<::std::uint32_t>(1));\n\
    \    x |= (x >> static_cast<::std::uint32_t>(2));\n    x |= (x >> static_cast<::std::uint32_t>(4));\n\
    \    x |= (x >> static_cast<::std::uint32_t>(8));\n    x |= (x >> static_cast<::std::uint32_t>(16));\n\
    \    return ::tools::popcount(x) - static_cast<::std::uint32_t>(1);\n  }\n\n \
    \ inline ::std::uint64_t floor_log2(::std::uint64_t x) {\n    x |= (x >> static_cast<::std::uint64_t>(1));\n\
    \    x |= (x >> static_cast<::std::uint64_t>(2));\n    x |= (x >> static_cast<::std::uint64_t>(4));\n\
    \    x |= (x >> static_cast<::std::uint64_t>(8));\n    x |= (x >> static_cast<::std::uint64_t>(16));\n\
    \    x |= (x >> static_cast<::std::uint64_t>(32));\n    return ::tools::popcount(x)\
    \ - static_cast<::std::uint64_t>(1);\n  }\n\n  inline ::std::int32_t floor_log2(::std::int32_t\
    \ x) {\n    return static_cast<::std::int32_t>(::tools::floor_log2(static_cast<::std::uint32_t>(x)));\n\
    \  }\n\n  inline ::std::int64_t floor_log2(::std::int64_t x) {\n    return static_cast<::std::int64_t>(::tools::floor_log2(static_cast<::std::uint64_t>(x)));\n\
    \  }\n}\n\n\n#line 7 \"tests/floor_log2.test.cpp\"\n\nvoid assert_that(const bool\
    \ cond) {\n  if (!cond) {\n    std::exit(EXIT_FAILURE);\n  }\n}\n\nint main()\
    \ {\n  assert_that(tools::floor_log2(INT32_C(1)) == 0);\n  assert_that(tools::floor_log2(INT32_C(2))\
    \ == 1);\n  assert_that(tools::floor_log2(INT32_C(3)) == 1);\n  assert_that(tools::floor_log2(INT32_C(4))\
    \ == 2);\n  assert_that(tools::floor_log2(INT32_C(5)) == 2);\n  assert_that(tools::floor_log2(INT32_C(6))\
    \ == 2);\n  assert_that(tools::floor_log2(INT32_C(7)) == 2);\n  assert_that(tools::floor_log2(INT32_C(8))\
    \ == 3);\n  assert_that(tools::floor_log2(INT32_C(9)) == 3);\n  assert_that(tools::floor_log2(INT32_C(1073741823))\
    \ == 29);\n  assert_that(tools::floor_log2(INT32_C(1073741824)) == 30);\n  assert_that(tools::floor_log2(INT32_C(1073741825))\
    \ == 30);\n  assert_that(tools::floor_log2(INT32_C(2147483647)) == 30);\n\n  assert_that(tools::floor_log2(UINT32_C(1))\
    \ == 0);\n  assert_that(tools::floor_log2(UINT32_C(2)) == 1);\n  assert_that(tools::floor_log2(UINT32_C(3))\
    \ == 1);\n  assert_that(tools::floor_log2(UINT32_C(4)) == 2);\n  assert_that(tools::floor_log2(UINT32_C(5))\
    \ == 2);\n  assert_that(tools::floor_log2(UINT32_C(6)) == 2);\n  assert_that(tools::floor_log2(UINT32_C(7))\
    \ == 2);\n  assert_that(tools::floor_log2(UINT32_C(8)) == 3);\n  assert_that(tools::floor_log2(UINT32_C(9))\
    \ == 3);\n  assert_that(tools::floor_log2(UINT32_C(2147483647)) == 30);\n  assert_that(tools::floor_log2(UINT32_C(2147483648))\
    \ == 31);\n  assert_that(tools::floor_log2(UINT32_C(2147483649)) == 31);\n  assert_that(tools::floor_log2(UINT32_C(4294967295))\
    \ == 31);\n\n  assert_that(tools::floor_log2(INT64_C(1)) == 0);\n  assert_that(tools::floor_log2(INT64_C(2))\
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
    #include <cstdlib>\n#include <iostream>\n#include <cstdint>\n#include \"tools/floor_log2.hpp\"\
    \n\nvoid assert_that(const bool cond) {\n  if (!cond) {\n    std::exit(EXIT_FAILURE);\n\
    \  }\n}\n\nint main() {\n  assert_that(tools::floor_log2(INT32_C(1)) == 0);\n\
    \  assert_that(tools::floor_log2(INT32_C(2)) == 1);\n  assert_that(tools::floor_log2(INT32_C(3))\
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
  - tools/floor_log2.hpp
  - tools/popcount.hpp
  isVerificationFile: true
  path: tests/floor_log2.test.cpp
  requiredBy: []
  timestamp: '2021-06-27 15:14:05+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/floor_log2.test.cpp
layout: document
redirect_from:
- /verify/tests/floor_log2.test.cpp
- /verify/tests/floor_log2.test.cpp.html
title: tests/floor_log2.test.cpp
---
