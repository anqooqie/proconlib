---
data:
  _extendedDependsOn:
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
    \n\n#include <cstdlib>\n#include <iostream>\n#include <cstdint>\n#line 1 \"tools/ceil_log2.hpp\"\
    \n\n\n\n#line 5 \"tools/ceil_log2.hpp\"\n\nnamespace tools {\n\n  inline std::uint32_t\
    \ ceil_log2(std::uint32_t x) {\n    static const ::std::uint32_t t[6] = {\n  \
    \    0xFFFF0000u,\n      0x0000FF00u,\n      0x000000F0u,\n      0x0000000Cu,\n\
    \      0x00000002u\n    };\n\n    ::std::uint32_t y = (((x & (x - 1)) == 0) ?\
    \ 0 : 1);\n    ::std::uint32_t j = 16;\n\n    for (const ::std::uint32_t& t_i\
    \ : t) {\n      ::std::uint32_t k = (((x & t_i) == 0) ? 0 : j);\n      y += k;\n\
    \      x >>= k;\n      j >>= 1;\n    }\n\n    return y;\n  }\n\n  inline ::std::uint64_t\
    \ ceil_log2(::std::uint64_t x) {\n    static const ::std::uint64_t t[6] = {\n\
    \      0xFFFFFFFF00000000u,\n      0x00000000FFFF0000u,\n      0x000000000000FF00u,\n\
    \      0x00000000000000F0u,\n      0x000000000000000Cu,\n      0x0000000000000002u\n\
    \    };\n\n    ::std::uint64_t y = (((x & (x - 1)) == 0) ? 0 : 1);\n    ::std::uint64_t\
    \ j = 32;\n\n    for (const ::std::uint64_t& t_i : t) {\n      ::std::uint64_t\
    \ k = (((x & t_i) == 0) ? 0 : j);\n      y += k;\n      x >>= k;\n      j >>=\
    \ 1;\n    }\n\n    return y;\n  }\n\n  inline ::std::int32_t ceil_log2(::std::int32_t\
    \ x) {\n    return static_cast<::std::int32_t>(::tools::ceil_log2(static_cast<::std::uint32_t>(x)));\n\
    \  }\n\n  inline ::std::int64_t ceil_log2(::std::int64_t x) {\n    return static_cast<::std::int64_t>(::tools::ceil_log2(static_cast<::std::uint64_t>(x)));\n\
    \  }\n}\n\n\n#line 7 \"tests/ceil_log2.test.cpp\"\n\nvoid assert_that(const bool\
    \ cond) {\n  if (!cond) {\n    std::exit(EXIT_FAILURE);\n  }\n}\n\nint main()\
    \ {\n  assert_that(tools::ceil_log2(INT32_C(1)) == 0);\n  assert_that(tools::ceil_log2(INT32_C(2))\
    \ == 1);\n  assert_that(tools::ceil_log2(INT32_C(3)) == 2);\n  assert_that(tools::ceil_log2(INT32_C(4))\
    \ == 2);\n  assert_that(tools::ceil_log2(INT32_C(5)) == 3);\n  assert_that(tools::ceil_log2(INT32_C(6))\
    \ == 3);\n  assert_that(tools::ceil_log2(INT32_C(7)) == 3);\n  assert_that(tools::ceil_log2(INT32_C(8))\
    \ == 3);\n  assert_that(tools::ceil_log2(INT32_C(9)) == 4);\n  assert_that(tools::ceil_log2(INT32_C(1073741823))\
    \ == 30);\n  assert_that(tools::ceil_log2(INT32_C(1073741824)) == 30);\n  assert_that(tools::ceil_log2(INT32_C(1073741825))\
    \ == 31);\n  assert_that(tools::ceil_log2(INT32_C(2147483647)) == 31);\n\n  assert_that(tools::ceil_log2(UINT32_C(1))\
    \ == 0);\n  assert_that(tools::ceil_log2(UINT32_C(2)) == 1);\n  assert_that(tools::ceil_log2(UINT32_C(3))\
    \ == 2);\n  assert_that(tools::ceil_log2(UINT32_C(4)) == 2);\n  assert_that(tools::ceil_log2(UINT32_C(5))\
    \ == 3);\n  assert_that(tools::ceil_log2(UINT32_C(6)) == 3);\n  assert_that(tools::ceil_log2(UINT32_C(7))\
    \ == 3);\n  assert_that(tools::ceil_log2(UINT32_C(8)) == 3);\n  assert_that(tools::ceil_log2(UINT32_C(9))\
    \ == 4);\n  assert_that(tools::ceil_log2(UINT32_C(2147483647)) == 31);\n  assert_that(tools::ceil_log2(UINT32_C(2147483648))\
    \ == 31);\n  assert_that(tools::ceil_log2(UINT32_C(2147483649)) == 32);\n  assert_that(tools::ceil_log2(UINT32_C(4294967295))\
    \ == 32);\n\n  assert_that(tools::ceil_log2(INT64_C(1)) == 0);\n  assert_that(tools::ceil_log2(INT64_C(2))\
    \ == 1);\n  assert_that(tools::ceil_log2(INT64_C(3)) == 2);\n  assert_that(tools::ceil_log2(INT64_C(4))\
    \ == 2);\n  assert_that(tools::ceil_log2(INT64_C(5)) == 3);\n  assert_that(tools::ceil_log2(INT64_C(6))\
    \ == 3);\n  assert_that(tools::ceil_log2(INT64_C(7)) == 3);\n  assert_that(tools::ceil_log2(INT64_C(8))\
    \ == 3);\n  assert_that(tools::ceil_log2(INT64_C(9)) == 4);\n  assert_that(tools::ceil_log2(INT64_C(4611686018427387903))\
    \ == 62);\n  assert_that(tools::ceil_log2(INT64_C(4611686018427387904)) == 62);\n\
    \  assert_that(tools::ceil_log2(INT64_C(4611686018427387905)) == 63);\n  assert_that(tools::ceil_log2(INT64_C(9223372036854775807))\
    \ == 63);\n\n  assert_that(tools::ceil_log2(UINT64_C(1)) == 0);\n  assert_that(tools::ceil_log2(UINT64_C(2))\
    \ == 1);\n  assert_that(tools::ceil_log2(UINT64_C(3)) == 2);\n  assert_that(tools::ceil_log2(UINT64_C(4))\
    \ == 2);\n  assert_that(tools::ceil_log2(UINT64_C(5)) == 3);\n  assert_that(tools::ceil_log2(UINT64_C(6))\
    \ == 3);\n  assert_that(tools::ceil_log2(UINT64_C(7)) == 3);\n  assert_that(tools::ceil_log2(UINT64_C(8))\
    \ == 3);\n  assert_that(tools::ceil_log2(UINT64_C(9)) == 4);\n  assert_that(tools::ceil_log2(UINT64_C(9223372036854775807))\
    \ == 63);\n  assert_that(tools::ceil_log2(UINT64_C(9223372036854775808)) == 63);\n\
    \  assert_that(tools::ceil_log2(UINT64_C(9223372036854775809)) == 64);\n  assert_that(tools::ceil_log2(UINT64_C(18446744073709551615))\
    \ == 64);\n\n  std::cout << \"Hello World\" << '\\n';\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\"\n\n\
    #include <cstdlib>\n#include <iostream>\n#include <cstdint>\n#include \"tools/ceil_log2.hpp\"\
    \n\nvoid assert_that(const bool cond) {\n  if (!cond) {\n    std::exit(EXIT_FAILURE);\n\
    \  }\n}\n\nint main() {\n  assert_that(tools::ceil_log2(INT32_C(1)) == 0);\n \
    \ assert_that(tools::ceil_log2(INT32_C(2)) == 1);\n  assert_that(tools::ceil_log2(INT32_C(3))\
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
  - tools/ceil_log2.hpp
  isVerificationFile: true
  path: tests/ceil_log2.test.cpp
  requiredBy: []
  timestamp: '2021-06-27 15:14:05+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/ceil_log2.test.cpp
layout: document
redirect_from:
- /verify/tests/ceil_log2.test.cpp
- /verify/tests/ceil_log2.test.cpp.html
title: tests/ceil_log2.test.cpp
---
