---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: tools/assert_that.hpp
    title: Assertion macro
  - icon: ':heavy_check_mark:'
    path: tools/floor_sqrt.hpp
    title: $\left\lfloor \sqrt{x} \right\rfloor$
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
  bundledCode: "#line 1 \"tests/floor_sqrt.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\"\
    \n\n#include <iostream>\n#line 1 \"tools/assert_that.hpp\"\n\n\n\n#line 5 \"tools/assert_that.hpp\"\
    \n#include <cstdlib>\n\n#define assert_that(cond) do {\\\n  if (!(cond)) {\\\n\
    \    ::std::cerr << __FILE__ << ':' << __LINE__ << \": \" << __func__ << \": Assertion\
    \ `\" << #cond << \"' failed.\" << '\\n';\\\n    ::std::exit(EXIT_FAILURE);\\\n\
    \  }\\\n} while (false)\n\n\n#line 1 \"tools/floor_sqrt.hpp\"\n\n\n\n#include\
    \ <cassert>\n\nnamespace tools {\n\n  template <typename T>\n  T floor_sqrt(const\
    \ T n) {\n    assert(n >= 0);\n\n    T ok = 0;\n    T ng;\n    for (ng = 1; ng\
    \ <= n / ng; ng *= 2);\n\n    while (ng - ok > 1) {\n      const T mid = ok +\
    \ (ng - ok) / 2;\n      if (mid <= n / mid) {\n        ok = mid;\n      } else\
    \ {\n        ng = mid;\n      }\n    }\n\n    return ok;\n  }\n}\n\n\n#line 6\
    \ \"tests/floor_sqrt.test.cpp\"\n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  assert_that(tools::floor_sqrt(0) == 0);\n  assert_that(tools::floor_sqrt(1)\
    \ == 1);\n  assert_that(tools::floor_sqrt(2) == 1);\n  assert_that(tools::floor_sqrt(3)\
    \ == 1);\n  assert_that(tools::floor_sqrt(4) == 2);\n  assert_that(tools::floor_sqrt(5)\
    \ == 2);\n  assert_that(tools::floor_sqrt(6) == 2);\n  assert_that(tools::floor_sqrt(7)\
    \ == 2);\n  assert_that(tools::floor_sqrt(8) == 2);\n  assert_that(tools::floor_sqrt(9)\
    \ == 3);\n  assert_that(tools::floor_sqrt(10) == 3);\n  assert_that(tools::floor_sqrt(9223372030926249000)\
    \ == 3037000498);\n  assert_that(tools::floor_sqrt(9223372030926249001) == 3037000499);\n\
    \  assert_that(tools::floor_sqrt(9223372030926249002) == 3037000499);\n  assert_that(tools::floor_sqrt(9223372036854775807)\
    \ == 3037000499);\n\n  std::cout << \"Hello World\" << '\\n';\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\"\n\n\
    #include <iostream>\n#include \"tools/assert_that.hpp\"\n#include \"tools/floor_sqrt.hpp\"\
    \n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  assert_that(tools::floor_sqrt(0) == 0);\n  assert_that(tools::floor_sqrt(1)\
    \ == 1);\n  assert_that(tools::floor_sqrt(2) == 1);\n  assert_that(tools::floor_sqrt(3)\
    \ == 1);\n  assert_that(tools::floor_sqrt(4) == 2);\n  assert_that(tools::floor_sqrt(5)\
    \ == 2);\n  assert_that(tools::floor_sqrt(6) == 2);\n  assert_that(tools::floor_sqrt(7)\
    \ == 2);\n  assert_that(tools::floor_sqrt(8) == 2);\n  assert_that(tools::floor_sqrt(9)\
    \ == 3);\n  assert_that(tools::floor_sqrt(10) == 3);\n  assert_that(tools::floor_sqrt(9223372030926249000)\
    \ == 3037000498);\n  assert_that(tools::floor_sqrt(9223372030926249001) == 3037000499);\n\
    \  assert_that(tools::floor_sqrt(9223372030926249002) == 3037000499);\n  assert_that(tools::floor_sqrt(9223372036854775807)\
    \ == 3037000499);\n\n  std::cout << \"Hello World\" << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - tools/assert_that.hpp
  - tools/floor_sqrt.hpp
  isVerificationFile: true
  path: tests/floor_sqrt.test.cpp
  requiredBy: []
  timestamp: '2022-07-02 14:04:07+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/floor_sqrt.test.cpp
layout: document
redirect_from:
- /verify/tests/floor_sqrt.test.cpp
- /verify/tests/floor_sqrt.test.cpp.html
title: tests/floor_sqrt.test.cpp
---
