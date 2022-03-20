---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tests/assert_that.hpp
    title: tests/assert_that.hpp
  - icon: ':heavy_check_mark:'
    path: tools/ceil_sqrt.hpp
    title: $\left\lceil \sqrt{x} \right\rceil$
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
  bundledCode: "#line 1 \"tests/ceil_sqrt.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\"\
    \n\n#include <iostream>\n#line 1 \"tests/assert_that.hpp\"\n\n\n\n#define assert_that(cond)\
    \ do {\\\n  if (!(cond)) {\\\n    std::cerr << __FILE__ << ':' << __LINE__ <<\
    \ \": \" << __func__ << \": Assertion `\" << #cond << \"' failed.\" << '\\n';\\\
    \n    std::exit(EXIT_FAILURE);\\\n  }\\\n} while (false)\n\n\n#line 1 \"tools/ceil_sqrt.hpp\"\
    \n\n\n\n#include <cassert>\n\nnamespace tools {\n\n  template <typename T>\n \
    \ T ceil_sqrt(T n) {\n    assert(n >= 0);\n\n    T ok = 0;\n    T ng;\n    for\
    \ (ng = 1; (ng - 1) * (ng - 1) < n; ng *= 2);\n\n    while (ng - ok > 1) {\n \
    \     const T mid = ok + (ng - ok) / 2;\n      if ((mid - 1) * (mid - 1) < n)\
    \ {\n        ok = mid;\n      } else {\n        ng = mid;\n      }\n    }\n\n\
    \    return ok;\n  }\n}\n\n\n#line 6 \"tests/ceil_sqrt.test.cpp\"\n\nint main()\
    \ {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\n  assert_that(tools::ceil_sqrt(0)\
    \ == 0);\n  assert_that(tools::ceil_sqrt(1) == 1);\n  assert_that(tools::ceil_sqrt(2)\
    \ == 2);\n  assert_that(tools::ceil_sqrt(3) == 2);\n  assert_that(tools::ceil_sqrt(4)\
    \ == 2);\n  assert_that(tools::ceil_sqrt(5) == 3);\n  assert_that(tools::ceil_sqrt(6)\
    \ == 3);\n  assert_that(tools::ceil_sqrt(7) == 3);\n  assert_that(tools::ceil_sqrt(8)\
    \ == 3);\n  assert_that(tools::ceil_sqrt(9) == 3);\n  assert_that(tools::ceil_sqrt(10)\
    \ == 4);\n  assert_that(tools::ceil_sqrt(999999999999999999) == 1000000000);\n\
    \  assert_that(tools::ceil_sqrt(1000000000000000000) == 1000000000);\n  assert_that(tools::ceil_sqrt(1000000000000000001)\
    \ == 1000000001);\n\n  std::cout << \"Hello World\" << '\\n';\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\"\n\n\
    #include <iostream>\n#include \"tests/assert_that.hpp\"\n#include \"tools/ceil_sqrt.hpp\"\
    \n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  assert_that(tools::ceil_sqrt(0) == 0);\n  assert_that(tools::ceil_sqrt(1)\
    \ == 1);\n  assert_that(tools::ceil_sqrt(2) == 2);\n  assert_that(tools::ceil_sqrt(3)\
    \ == 2);\n  assert_that(tools::ceil_sqrt(4) == 2);\n  assert_that(tools::ceil_sqrt(5)\
    \ == 3);\n  assert_that(tools::ceil_sqrt(6) == 3);\n  assert_that(tools::ceil_sqrt(7)\
    \ == 3);\n  assert_that(tools::ceil_sqrt(8) == 3);\n  assert_that(tools::ceil_sqrt(9)\
    \ == 3);\n  assert_that(tools::ceil_sqrt(10) == 4);\n  assert_that(tools::ceil_sqrt(999999999999999999)\
    \ == 1000000000);\n  assert_that(tools::ceil_sqrt(1000000000000000000) == 1000000000);\n\
    \  assert_that(tools::ceil_sqrt(1000000000000000001) == 1000000001);\n\n  std::cout\
    \ << \"Hello World\" << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - tests/assert_that.hpp
  - tools/ceil_sqrt.hpp
  isVerificationFile: true
  path: tests/ceil_sqrt.test.cpp
  requiredBy: []
  timestamp: '2022-03-20 11:06:18+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/ceil_sqrt.test.cpp
layout: document
redirect_from:
- /verify/tests/ceil_sqrt.test.cpp
- /verify/tests/ceil_sqrt.test.cpp.html
title: tests/ceil_sqrt.test.cpp
---
