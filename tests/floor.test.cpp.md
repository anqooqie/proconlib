---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: tools/assert_that.hpp
    title: Assertion macro
  - icon: ':question:'
    path: tools/floor.hpp
    title: $\left\lfloor \frac{x}{y} \right\rfloor$
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
  bundledCode: "#line 1 \"tests/floor.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\"\
    \n\n#include <iostream>\n#line 1 \"tools/assert_that.hpp\"\n\n\n\n#line 5 \"tools/assert_that.hpp\"\
    \n#include <cstdlib>\n\n#define assert_that(cond) do {\\\n  if (!(cond)) {\\\n\
    \    ::std::cerr << __FILE__ << ':' << __LINE__ << \": \" << __func__ << \": Assertion\
    \ `\" << #cond << \"' failed.\" << '\\n';\\\n    ::std::exit(EXIT_FAILURE);\\\n\
    \  }\\\n} while (false)\n\n\n#line 1 \"tools/floor.hpp\"\n\n\n\n#include <type_traits>\n\
    #include <cassert>\n\nnamespace tools {\n\n  template <typename M, typename N>\n\
    \  constexpr ::std::common_type_t<M, N> floor(const M lhs, const N rhs) {\n  \
    \  assert(rhs != 0);\n    return lhs / rhs - (((lhs > 0 && rhs < 0) || (lhs <\
    \ 0 && rhs > 0)) && lhs % rhs);\n  }\n}\n\n\n#line 6 \"tests/floor.test.cpp\"\n\
    \nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  assert_that(tools::floor(5, 3) == 1);\n  assert_that(tools::floor(5, -3) ==\
    \ -2);\n  assert_that(tools::floor(-5, 3) == -2);\n  assert_that(tools::floor(-5,\
    \ -3) == 1);\n\n  assert_that(tools::floor(-2, -2) == 1);\n  assert_that(tools::floor(-2,\
    \ -1) == 2);\n  assert_that(tools::floor(-2, 1) == -2);\n  assert_that(tools::floor(-2,\
    \ 2) == -1);\n\n  assert_that(tools::floor(-1, -2) == 0);\n  assert_that(tools::floor(-1,\
    \ -1) == 1);\n  assert_that(tools::floor(-1, 1) == -1);\n  assert_that(tools::floor(-1,\
    \ 2) == -1);\n\n  assert_that(tools::floor(0, -2) == 0);\n  assert_that(tools::floor(0,\
    \ -1) == 0);\n  assert_that(tools::floor(0, 1) == 0);\n  assert_that(tools::floor(0,\
    \ 2) == 0);\n\n  assert_that(tools::floor(1, -2) == -1);\n  assert_that(tools::floor(1,\
    \ -1) == -1);\n  assert_that(tools::floor(1, 1) == 1);\n  assert_that(tools::floor(1,\
    \ 2) == 0);\n\n  assert_that(tools::floor(2, -2) == -1);\n  assert_that(tools::floor(2,\
    \ -1) == -2);\n  assert_that(tools::floor(2, 1) == 2);\n  assert_that(tools::floor(2,\
    \ 2) == 1);\n\n  assert_that(tools::floor(-9223372036854775807 - 1, -3) == 3074457345618258602);\n\
    \  assert_that(tools::floor(-9223372036854775807 - 1, -2) == 4611686018427387904);\n\
    \  assert_that(tools::floor(-9223372036854775807 - 1, 1) == -9223372036854775807\
    \ - 1);\n  assert_that(tools::floor(-9223372036854775807 - 1, 2) == -4611686018427387904);\n\
    \  assert_that(tools::floor(-9223372036854775807 - 1, 3) == -3074457345618258603);\n\
    \n  assert_that(tools::floor(-9223372036854775807, -3) == 3074457345618258602);\n\
    \  assert_that(tools::floor(-9223372036854775807, -2) == 4611686018427387903);\n\
    \  assert_that(tools::floor(-9223372036854775807, -1) == 9223372036854775807);\n\
    \  assert_that(tools::floor(-9223372036854775807, 1) == -9223372036854775807);\n\
    \  assert_that(tools::floor(-9223372036854775807, 2) == -4611686018427387904);\n\
    \  assert_that(tools::floor(-9223372036854775807, 3) == -3074457345618258603);\n\
    \n  assert_that(tools::floor(9223372036854775807, -3) == -3074457345618258603);\n\
    \  assert_that(tools::floor(9223372036854775807, -2) == -4611686018427387904);\n\
    \  assert_that(tools::floor(9223372036854775807, -1) == -9223372036854775807);\n\
    \  assert_that(tools::floor(9223372036854775807, 1) == 9223372036854775807);\n\
    \  assert_that(tools::floor(9223372036854775807, 2) == 4611686018427387903);\n\
    \  assert_that(tools::floor(9223372036854775807, 3) == 3074457345618258602);\n\
    \n  std::cout << \"Hello World\" << '\\n';\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\"\n\n\
    #include <iostream>\n#include \"tools/assert_that.hpp\"\n#include \"tools/floor.hpp\"\
    \n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  assert_that(tools::floor(5, 3) == 1);\n  assert_that(tools::floor(5, -3) ==\
    \ -2);\n  assert_that(tools::floor(-5, 3) == -2);\n  assert_that(tools::floor(-5,\
    \ -3) == 1);\n\n  assert_that(tools::floor(-2, -2) == 1);\n  assert_that(tools::floor(-2,\
    \ -1) == 2);\n  assert_that(tools::floor(-2, 1) == -2);\n  assert_that(tools::floor(-2,\
    \ 2) == -1);\n\n  assert_that(tools::floor(-1, -2) == 0);\n  assert_that(tools::floor(-1,\
    \ -1) == 1);\n  assert_that(tools::floor(-1, 1) == -1);\n  assert_that(tools::floor(-1,\
    \ 2) == -1);\n\n  assert_that(tools::floor(0, -2) == 0);\n  assert_that(tools::floor(0,\
    \ -1) == 0);\n  assert_that(tools::floor(0, 1) == 0);\n  assert_that(tools::floor(0,\
    \ 2) == 0);\n\n  assert_that(tools::floor(1, -2) == -1);\n  assert_that(tools::floor(1,\
    \ -1) == -1);\n  assert_that(tools::floor(1, 1) == 1);\n  assert_that(tools::floor(1,\
    \ 2) == 0);\n\n  assert_that(tools::floor(2, -2) == -1);\n  assert_that(tools::floor(2,\
    \ -1) == -2);\n  assert_that(tools::floor(2, 1) == 2);\n  assert_that(tools::floor(2,\
    \ 2) == 1);\n\n  assert_that(tools::floor(-9223372036854775807 - 1, -3) == 3074457345618258602);\n\
    \  assert_that(tools::floor(-9223372036854775807 - 1, -2) == 4611686018427387904);\n\
    \  assert_that(tools::floor(-9223372036854775807 - 1, 1) == -9223372036854775807\
    \ - 1);\n  assert_that(tools::floor(-9223372036854775807 - 1, 2) == -4611686018427387904);\n\
    \  assert_that(tools::floor(-9223372036854775807 - 1, 3) == -3074457345618258603);\n\
    \n  assert_that(tools::floor(-9223372036854775807, -3) == 3074457345618258602);\n\
    \  assert_that(tools::floor(-9223372036854775807, -2) == 4611686018427387903);\n\
    \  assert_that(tools::floor(-9223372036854775807, -1) == 9223372036854775807);\n\
    \  assert_that(tools::floor(-9223372036854775807, 1) == -9223372036854775807);\n\
    \  assert_that(tools::floor(-9223372036854775807, 2) == -4611686018427387904);\n\
    \  assert_that(tools::floor(-9223372036854775807, 3) == -3074457345618258603);\n\
    \n  assert_that(tools::floor(9223372036854775807, -3) == -3074457345618258603);\n\
    \  assert_that(tools::floor(9223372036854775807, -2) == -4611686018427387904);\n\
    \  assert_that(tools::floor(9223372036854775807, -1) == -9223372036854775807);\n\
    \  assert_that(tools::floor(9223372036854775807, 1) == 9223372036854775807);\n\
    \  assert_that(tools::floor(9223372036854775807, 2) == 4611686018427387903);\n\
    \  assert_that(tools::floor(9223372036854775807, 3) == 3074457345618258602);\n\
    \n  std::cout << \"Hello World\" << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - tools/assert_that.hpp
  - tools/floor.hpp
  isVerificationFile: true
  path: tests/floor.test.cpp
  requiredBy: []
  timestamp: '2022-07-02 14:04:07+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/floor.test.cpp
layout: document
redirect_from:
- /verify/tests/floor.test.cpp
- /verify/tests/floor.test.cpp.html
title: tests/floor.test.cpp
---