---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: tools/assert_that.hpp
    title: Assertion macro
  - icon: ':x:'
    path: tools/digit_sum.hpp
    title: Sum of digits
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A
  bundledCode: "#line 1 \"tests/digit_sum.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\"\
    \n\n#include <iostream>\n#line 1 \"tools/assert_that.hpp\"\n\n\n\n#line 5 \"tools/assert_that.hpp\"\
    \n#include <cstdlib>\n\n#define assert_that(cond) do {\\\n  if (!(cond)) {\\\n\
    \    ::std::cerr << __FILE__ << ':' << __LINE__ << \": \" << __func__ << \": Assertion\
    \ `\" << #cond << \"' failed.\" << '\\n';\\\n    ::std::exit(EXIT_FAILURE);\\\n\
    \  }\\\n} while (false)\n\n\n#line 1 \"tools/digit_sum.hpp\"\n\n\n\n#include <cassert>\n\
    \nnamespace tools {\n\n  template <typename T>\n  T digit_sum(T n) {\n    assert(n\
    \ >= 0);\n    T sum = 0;\n    for (; n > 0; n /= 10) {\n      sum += n % 10;\n\
    \    }\n    return sum;\n  }\n}\n\n\n#line 6 \"tests/digit_sum.test.cpp\"\n\n\
    using ll = long long;\n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  assert_that(tools::digit_sum<ll>(0) == 0);\n  assert_that(tools::digit_sum<ll>(1)\
    \ == 1);\n  assert_that(tools::digit_sum<ll>(2) == 2);\n  assert_that(tools::digit_sum<ll>(3)\
    \ == 3);\n  assert_that(tools::digit_sum<ll>(4) == 4);\n  assert_that(tools::digit_sum<ll>(5)\
    \ == 5);\n  assert_that(tools::digit_sum<ll>(6) == 6);\n  assert_that(tools::digit_sum<ll>(7)\
    \ == 7);\n  assert_that(tools::digit_sum<ll>(8) == 8);\n  assert_that(tools::digit_sum<ll>(9)\
    \ == 9);\n  assert_that(tools::digit_sum<ll>(10) == 1);\n  assert_that(tools::digit_sum<ll>(11)\
    \ == 2);\n  assert_that(tools::digit_sum<ll>(12) == 3);\n  assert_that(tools::digit_sum<ll>(13)\
    \ == 4);\n  assert_that(tools::digit_sum<ll>(14) == 5);\n  assert_that(tools::digit_sum<ll>(15)\
    \ == 6);\n  assert_that(tools::digit_sum<ll>(16) == 7);\n  assert_that(tools::digit_sum<ll>(17)\
    \ == 8);\n  assert_that(tools::digit_sum<ll>(18) == 9);\n  assert_that(tools::digit_sum<ll>(19)\
    \ == 10);\n  assert_that(tools::digit_sum<ll>(20) == 2);\n  assert_that(tools::digit_sum<ll>(90)\
    \ == 9);\n  assert_that(tools::digit_sum<ll>(91) == 10);\n  assert_that(tools::digit_sum<ll>(92)\
    \ == 11);\n  assert_that(tools::digit_sum<ll>(93) == 12);\n  assert_that(tools::digit_sum<ll>(94)\
    \ == 13);\n  assert_that(tools::digit_sum<ll>(95) == 14);\n  assert_that(tools::digit_sum<ll>(96)\
    \ == 15);\n  assert_that(tools::digit_sum<ll>(97) == 16);\n  assert_that(tools::digit_sum<ll>(98)\
    \ == 17);\n  assert_that(tools::digit_sum<ll>(99) == 18);\n  assert_that(tools::digit_sum<ll>(100)\
    \ == 1);\n  assert_that(tools::digit_sum<ll>(101) == 2);\n  assert_that(tools::digit_sum<ll>(999)\
    \ == 27);\n  assert_that(tools::digit_sum<ll>(1000) == 1);\n  assert_that(tools::digit_sum<ll>(999999999999999999)\
    \ == 162);\n  assert_that(tools::digit_sum<ll>(1000000000000000000) == 1);\n \
    \ assert_that(tools::digit_sum<ll>(1000000000000000001) == 2);\n  assert_that(tools::digit_sum<ll>(8999999999999999999)\
    \ == 170);\n  assert_that(tools::digit_sum<ll>(9223372036854775806) == 87);\n\
    \  assert_that(tools::digit_sum<ll>(9223372036854775807) == 88);\n\n  std::cout\
    \ << \"Hello World\" << '\\n';\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\"\n\n\
    #include <iostream>\n#include \"tools/assert_that.hpp\"\n#include \"tools/digit_sum.hpp\"\
    \n\nusing ll = long long;\n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  assert_that(tools::digit_sum<ll>(0) == 0);\n  assert_that(tools::digit_sum<ll>(1)\
    \ == 1);\n  assert_that(tools::digit_sum<ll>(2) == 2);\n  assert_that(tools::digit_sum<ll>(3)\
    \ == 3);\n  assert_that(tools::digit_sum<ll>(4) == 4);\n  assert_that(tools::digit_sum<ll>(5)\
    \ == 5);\n  assert_that(tools::digit_sum<ll>(6) == 6);\n  assert_that(tools::digit_sum<ll>(7)\
    \ == 7);\n  assert_that(tools::digit_sum<ll>(8) == 8);\n  assert_that(tools::digit_sum<ll>(9)\
    \ == 9);\n  assert_that(tools::digit_sum<ll>(10) == 1);\n  assert_that(tools::digit_sum<ll>(11)\
    \ == 2);\n  assert_that(tools::digit_sum<ll>(12) == 3);\n  assert_that(tools::digit_sum<ll>(13)\
    \ == 4);\n  assert_that(tools::digit_sum<ll>(14) == 5);\n  assert_that(tools::digit_sum<ll>(15)\
    \ == 6);\n  assert_that(tools::digit_sum<ll>(16) == 7);\n  assert_that(tools::digit_sum<ll>(17)\
    \ == 8);\n  assert_that(tools::digit_sum<ll>(18) == 9);\n  assert_that(tools::digit_sum<ll>(19)\
    \ == 10);\n  assert_that(tools::digit_sum<ll>(20) == 2);\n  assert_that(tools::digit_sum<ll>(90)\
    \ == 9);\n  assert_that(tools::digit_sum<ll>(91) == 10);\n  assert_that(tools::digit_sum<ll>(92)\
    \ == 11);\n  assert_that(tools::digit_sum<ll>(93) == 12);\n  assert_that(tools::digit_sum<ll>(94)\
    \ == 13);\n  assert_that(tools::digit_sum<ll>(95) == 14);\n  assert_that(tools::digit_sum<ll>(96)\
    \ == 15);\n  assert_that(tools::digit_sum<ll>(97) == 16);\n  assert_that(tools::digit_sum<ll>(98)\
    \ == 17);\n  assert_that(tools::digit_sum<ll>(99) == 18);\n  assert_that(tools::digit_sum<ll>(100)\
    \ == 1);\n  assert_that(tools::digit_sum<ll>(101) == 2);\n  assert_that(tools::digit_sum<ll>(999)\
    \ == 27);\n  assert_that(tools::digit_sum<ll>(1000) == 1);\n  assert_that(tools::digit_sum<ll>(999999999999999999)\
    \ == 162);\n  assert_that(tools::digit_sum<ll>(1000000000000000000) == 1);\n \
    \ assert_that(tools::digit_sum<ll>(1000000000000000001) == 2);\n  assert_that(tools::digit_sum<ll>(8999999999999999999)\
    \ == 170);\n  assert_that(tools::digit_sum<ll>(9223372036854775806) == 87);\n\
    \  assert_that(tools::digit_sum<ll>(9223372036854775807) == 88);\n\n  std::cout\
    \ << \"Hello World\" << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - tools/assert_that.hpp
  - tools/digit_sum.hpp
  isVerificationFile: true
  path: tests/digit_sum.test.cpp
  requiredBy: []
  timestamp: '2022-10-08 19:22:04+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: tests/digit_sum.test.cpp
layout: document
redirect_from:
- /verify/tests/digit_sum.test.cpp
- /verify/tests/digit_sum.test.cpp.html
title: tests/digit_sum.test.cpp
---
