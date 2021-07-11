---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/ceil.hpp
    title: $\left\lceil \frac{x}{y} \right\rceil$
  - icon: ':heavy_check_mark:'
    path: tools/ceil_log.hpp
    title: $\left\lceil \log_b(x) \right\rceil$
  - icon: ':heavy_check_mark:'
    path: tools/detail/ceil_and_floor.hpp
    title: tools/detail/ceil_and_floor.hpp
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
  bundledCode: "#line 1 \"tests/ceil_log.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\"\
    \n\n#include <cstdlib>\n#include <iostream>\n#line 1 \"tools/ceil_log.hpp\"\n\n\
    \n\n#include <type_traits>\n#include <cassert>\n#line 1 \"tools/ceil.hpp\"\n\n\
    \n\n#line 1 \"tools/detail/ceil_and_floor.hpp\"\n\n\n\n#line 5 \"tools/detail/ceil_and_floor.hpp\"\
    \n\nnamespace tools {\n\n  template <typename M, typename N>\n  constexpr ::std::common_type_t<M,\
    \ N> floor(const M& lhs, const N& rhs);\n\n  template <typename M, typename N>\n\
    \  constexpr ::std::common_type_t<M, N> ceil(const M& lhs, const N& rhs);\n  \n\
    \  template <typename M, typename N>\n  constexpr ::std::common_type_t<M, N> floor(const\
    \ M& lhs, const N& rhs) {\n    return\n      lhs >= 0 && rhs >= 0 ?\n        lhs\
    \ / rhs :\n      lhs < 0 && rhs >= 0 ?\n        -::tools::ceil(-lhs, rhs) :\n\
    \      lhs >= 0 && rhs < 0 ?\n        -::tools::ceil(lhs, -rhs) :\n        ::tools::floor(-lhs,\
    \ -rhs);\n  }\n  \n  template <typename M, typename N>\n  constexpr ::std::common_type_t<M,\
    \ N> ceil(const M& lhs, const N& rhs) {\n    return\n      lhs >= 0 && rhs >=\
    \ 0 ?\n        (lhs - 1 + rhs) / rhs :\n      lhs < 0 && rhs >= 0 ?\n        -::tools::floor(-lhs,\
    \ rhs) :\n      lhs >= 0 && rhs < 0 ?\n        -::tools::floor(lhs, -rhs) :\n\
    \        ::tools::ceil(-lhs, -rhs);\n  }\n}\n\n\n#line 5 \"tools/ceil.hpp\"\n\n\
    \n#line 7 \"tools/ceil_log.hpp\"\n\nnamespace tools {\n\n  template <typename\
    \ M, typename N>\n  ::std::common_type_t<M, N> ceil_log(const M& base, const N&\
    \ antilogarithm) {\n    assert(2 <= base && base <= 1000000000000000000);\n  \
    \  assert(1 <= antilogarithm && antilogarithm <= 1000000000000000000);\n\n   \
    \ const ::std::common_type_t<M, N> threshold = tools::ceil(antilogarithm, base);\n\
    \    ::std::common_type_t<M, N> logarithm = 0;\n    for (::std::common_type_t<M,\
    \ N> pow = 1; pow < antilogarithm; pow = (pow < threshold ? pow * base : antilogarithm))\
    \ {\n      ++logarithm;\n    }\n\n    return logarithm;\n  }\n}\n\n\n#line 6 \"\
    tests/ceil_log.test.cpp\"\n\nvoid assert_that(const bool cond) {\n  if (!cond)\
    \ {\n    std::exit(EXIT_FAILURE);\n  }\n}\n\nint main() {\n  assert_that(tools::ceil_log(2,\
    \ 1) == 0);\n  assert_that(tools::ceil_log(2, 2) == 1);\n  assert_that(tools::ceil_log(2,\
    \ 3) == 2);\n  assert_that(tools::ceil_log(2, 4) == 2);\n  assert_that(tools::ceil_log(2,\
    \ 5) == 3);\n  assert_that(tools::ceil_log(2, 6) == 3);\n  assert_that(tools::ceil_log(2,\
    \ 7) == 3);\n  assert_that(tools::ceil_log(2, 8) == 3);\n  assert_that(tools::ceil_log(2,\
    \ 9) == 4);\n  assert_that(tools::ceil_log(3, 1) == 0);\n  assert_that(tools::ceil_log(3,\
    \ 2) == 1);\n  assert_that(tools::ceil_log(3, 3) == 1);\n  assert_that(tools::ceil_log(3,\
    \ 4) == 2);\n  assert_that(tools::ceil_log(3, 5) == 2);\n  assert_that(tools::ceil_log(3,\
    \ 6) == 2);\n  assert_that(tools::ceil_log(3, 7) == 2);\n  assert_that(tools::ceil_log(3,\
    \ 8) == 2);\n  assert_that(tools::ceil_log(3, 9) == 2);\n  assert_that(tools::ceil_log(4,\
    \ 1) == 0);\n  assert_that(tools::ceil_log(4, 2) == 1);\n  assert_that(tools::ceil_log(4,\
    \ 3) == 1);\n  assert_that(tools::ceil_log(4, 4) == 1);\n  assert_that(tools::ceil_log(4,\
    \ 5) == 2);\n  assert_that(tools::ceil_log(4, 6) == 2);\n  assert_that(tools::ceil_log(4,\
    \ 7) == 2);\n  assert_that(tools::ceil_log(4, 8) == 2);\n  assert_that(tools::ceil_log(4,\
    \ 9) == 2);\n  assert_that(tools::ceil_log(2, 576460752303423487) == 59);\n  assert_that(tools::ceil_log(2,\
    \ 576460752303423488) == 59);\n  assert_that(tools::ceil_log(2, 576460752303423489)\
    \ == 60);\n  assert_that(tools::ceil_log(2, 1000000000000000000) == 60);\n  assert_that(tools::ceil_log(1000000000000000000,\
    \ 1) == 0);\n  assert_that(tools::ceil_log(1000000000000000000, 2) == 1);\n  assert_that(tools::ceil_log(999999999999999999,\
    \ 999999999999999998) == 1);\n  assert_that(tools::ceil_log(999999999999999999,\
    \ 999999999999999999) == 1);\n  assert_that(tools::ceil_log(999999999999999999,\
    \ 1000000000000000000) == 2);\n\n  std::cout << \"Hello World\" << '\\n';\n  return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\"\n\n\
    #include <cstdlib>\n#include <iostream>\n#include \"tools/ceil_log.hpp\"\n\nvoid\
    \ assert_that(const bool cond) {\n  if (!cond) {\n    std::exit(EXIT_FAILURE);\n\
    \  }\n}\n\nint main() {\n  assert_that(tools::ceil_log(2, 1) == 0);\n  assert_that(tools::ceil_log(2,\
    \ 2) == 1);\n  assert_that(tools::ceil_log(2, 3) == 2);\n  assert_that(tools::ceil_log(2,\
    \ 4) == 2);\n  assert_that(tools::ceil_log(2, 5) == 3);\n  assert_that(tools::ceil_log(2,\
    \ 6) == 3);\n  assert_that(tools::ceil_log(2, 7) == 3);\n  assert_that(tools::ceil_log(2,\
    \ 8) == 3);\n  assert_that(tools::ceil_log(2, 9) == 4);\n  assert_that(tools::ceil_log(3,\
    \ 1) == 0);\n  assert_that(tools::ceil_log(3, 2) == 1);\n  assert_that(tools::ceil_log(3,\
    \ 3) == 1);\n  assert_that(tools::ceil_log(3, 4) == 2);\n  assert_that(tools::ceil_log(3,\
    \ 5) == 2);\n  assert_that(tools::ceil_log(3, 6) == 2);\n  assert_that(tools::ceil_log(3,\
    \ 7) == 2);\n  assert_that(tools::ceil_log(3, 8) == 2);\n  assert_that(tools::ceil_log(3,\
    \ 9) == 2);\n  assert_that(tools::ceil_log(4, 1) == 0);\n  assert_that(tools::ceil_log(4,\
    \ 2) == 1);\n  assert_that(tools::ceil_log(4, 3) == 1);\n  assert_that(tools::ceil_log(4,\
    \ 4) == 1);\n  assert_that(tools::ceil_log(4, 5) == 2);\n  assert_that(tools::ceil_log(4,\
    \ 6) == 2);\n  assert_that(tools::ceil_log(4, 7) == 2);\n  assert_that(tools::ceil_log(4,\
    \ 8) == 2);\n  assert_that(tools::ceil_log(4, 9) == 2);\n  assert_that(tools::ceil_log(2,\
    \ 576460752303423487) == 59);\n  assert_that(tools::ceil_log(2, 576460752303423488)\
    \ == 59);\n  assert_that(tools::ceil_log(2, 576460752303423489) == 60);\n  assert_that(tools::ceil_log(2,\
    \ 1000000000000000000) == 60);\n  assert_that(tools::ceil_log(1000000000000000000,\
    \ 1) == 0);\n  assert_that(tools::ceil_log(1000000000000000000, 2) == 1);\n  assert_that(tools::ceil_log(999999999999999999,\
    \ 999999999999999998) == 1);\n  assert_that(tools::ceil_log(999999999999999999,\
    \ 999999999999999999) == 1);\n  assert_that(tools::ceil_log(999999999999999999,\
    \ 1000000000000000000) == 2);\n\n  std::cout << \"Hello World\" << '\\n';\n  return\
    \ 0;\n}\n"
  dependsOn:
  - tools/ceil_log.hpp
  - tools/ceil.hpp
  - tools/detail/ceil_and_floor.hpp
  isVerificationFile: true
  path: tests/ceil_log.test.cpp
  requiredBy: []
  timestamp: '2021-03-29 00:30:01+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/ceil_log.test.cpp
layout: document
redirect_from:
- /verify/tests/ceil_log.test.cpp
- /verify/tests/ceil_log.test.cpp.html
title: tests/ceil_log.test.cpp
---