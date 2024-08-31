---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: tools/assert_that.hpp
    title: Assertion macro
  - icon: ':question:'
    path: tools/floor.hpp
    title: $\left\lfloor \frac{x}{y} \right\rfloor$
  - icon: ':x:'
    path: tools/floor_log.hpp
    title: $\left\lfloor \log_b(x) \right\rfloor$
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
  bundledCode: "#line 1 \"tests/floor_log.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\"\
    \n\n#include <cstdlib>\n#include <iostream>\n#line 1 \"tools/assert_that.hpp\"\
    \n\n\n\n#line 6 \"tools/assert_that.hpp\"\n\n#define assert_that_impl(cond, file,\
    \ line, func) do {\\\n  if (!cond) {\\\n    ::std::cerr << file << ':' << line\
    \ << \": \" << func << \": Assertion `\" << #cond << \"' failed.\" << '\\n';\\\
    \n    ::std::exit(EXIT_FAILURE);\\\n  }\\\n} while (false)\n#define assert_that(...)\
    \ assert_that_impl((__VA_ARGS__), __FILE__, __LINE__, __func__)\n\n\n#line 1 \"\
    tools/floor_log.hpp\"\n\n\n\n#include <type_traits>\n#include <cassert>\n#line\
    \ 1 \"tools/floor.hpp\"\n\n\n\n#line 6 \"tools/floor.hpp\"\n\nnamespace tools\
    \ {\n\n  template <typename M, typename N>\n  constexpr ::std::common_type_t<M,\
    \ N> floor(const M lhs, const N rhs) {\n    using T = ::std::common_type_t<M,\
    \ N>;\n    assert(rhs != N(0));\n    return lhs / rhs - T(((lhs > M(0) && rhs\
    \ < N(0)) || (lhs < M(0) && rhs > N(0))) && lhs % rhs);\n  }\n}\n\n\n#line 7 \"\
    tools/floor_log.hpp\"\n\nnamespace tools {\n\n  template <typename M, typename\
    \ N>\n  ::std::common_type_t<M, N> floor_log(const M& base, const N& antilogarithm)\
    \ {\n    assert(2 <= base && base <= 1000000000000000000);\n    assert(1 <= antilogarithm\
    \ && antilogarithm <= 1000000000000000000);\n\n    const ::std::common_type_t<M,\
    \ N> threshold = ::tools::floor(antilogarithm, base);\n    ::std::common_type_t<M,\
    \ N> logarithm = 0;\n    for (::std::common_type_t<M, N> pow = 1; pow <= antilogarithm;\
    \ pow = (pow <= threshold ? pow * base : antilogarithm + 1)) {\n      ++logarithm;\n\
    \    }\n\n    return logarithm - 1;\n  }\n}\n\n\n#line 7 \"tests/floor_log.test.cpp\"\
    \n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  assert_that(tools::floor_log(2, 1) == 0);\n  assert_that(tools::floor_log(2,\
    \ 2) == 1);\n  assert_that(tools::floor_log(2, 3) == 1);\n  assert_that(tools::floor_log(2,\
    \ 4) == 2);\n  assert_that(tools::floor_log(2, 5) == 2);\n  assert_that(tools::floor_log(2,\
    \ 6) == 2);\n  assert_that(tools::floor_log(2, 7) == 2);\n  assert_that(tools::floor_log(2,\
    \ 8) == 3);\n  assert_that(tools::floor_log(2, 9) == 3);\n  assert_that(tools::floor_log(3,\
    \ 1) == 0);\n  assert_that(tools::floor_log(3, 2) == 0);\n  assert_that(tools::floor_log(3,\
    \ 3) == 1);\n  assert_that(tools::floor_log(3, 4) == 1);\n  assert_that(tools::floor_log(3,\
    \ 5) == 1);\n  assert_that(tools::floor_log(3, 6) == 1);\n  assert_that(tools::floor_log(3,\
    \ 7) == 1);\n  assert_that(tools::floor_log(3, 8) == 1);\n  assert_that(tools::floor_log(3,\
    \ 9) == 2);\n  assert_that(tools::floor_log(4, 1) == 0);\n  assert_that(tools::floor_log(4,\
    \ 2) == 0);\n  assert_that(tools::floor_log(4, 3) == 0);\n  assert_that(tools::floor_log(4,\
    \ 4) == 1);\n  assert_that(tools::floor_log(4, 5) == 1);\n  assert_that(tools::floor_log(4,\
    \ 6) == 1);\n  assert_that(tools::floor_log(4, 7) == 1);\n  assert_that(tools::floor_log(4,\
    \ 8) == 1);\n  assert_that(tools::floor_log(4, 9) == 1);\n  assert_that(tools::floor_log(2,\
    \ 576460752303423487) == 58);\n  assert_that(tools::floor_log(2, 576460752303423488)\
    \ == 59);\n  assert_that(tools::floor_log(2, 576460752303423489) == 59);\n  assert_that(tools::floor_log(2,\
    \ 1000000000000000000) == 59);\n  assert_that(tools::floor_log(1000000000000000000,\
    \ 1) == 0);\n  assert_that(tools::floor_log(1000000000000000000, 2) == 0);\n \
    \ assert_that(tools::floor_log(999999999999999999, 999999999999999998) == 0);\n\
    \  assert_that(tools::floor_log(999999999999999999, 999999999999999999) == 1);\n\
    \  assert_that(tools::floor_log(999999999999999999, 1000000000000000000) == 1);\n\
    \n  std::cout << \"Hello World\" << '\\n';\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\"\n\n\
    #include <cstdlib>\n#include <iostream>\n#include \"tools/assert_that.hpp\"\n\
    #include \"tools/floor_log.hpp\"\n\nint main() {\n  std::cin.tie(nullptr);\n \
    \ std::ios_base::sync_with_stdio(false);\n\n  assert_that(tools::floor_log(2,\
    \ 1) == 0);\n  assert_that(tools::floor_log(2, 2) == 1);\n  assert_that(tools::floor_log(2,\
    \ 3) == 1);\n  assert_that(tools::floor_log(2, 4) == 2);\n  assert_that(tools::floor_log(2,\
    \ 5) == 2);\n  assert_that(tools::floor_log(2, 6) == 2);\n  assert_that(tools::floor_log(2,\
    \ 7) == 2);\n  assert_that(tools::floor_log(2, 8) == 3);\n  assert_that(tools::floor_log(2,\
    \ 9) == 3);\n  assert_that(tools::floor_log(3, 1) == 0);\n  assert_that(tools::floor_log(3,\
    \ 2) == 0);\n  assert_that(tools::floor_log(3, 3) == 1);\n  assert_that(tools::floor_log(3,\
    \ 4) == 1);\n  assert_that(tools::floor_log(3, 5) == 1);\n  assert_that(tools::floor_log(3,\
    \ 6) == 1);\n  assert_that(tools::floor_log(3, 7) == 1);\n  assert_that(tools::floor_log(3,\
    \ 8) == 1);\n  assert_that(tools::floor_log(3, 9) == 2);\n  assert_that(tools::floor_log(4,\
    \ 1) == 0);\n  assert_that(tools::floor_log(4, 2) == 0);\n  assert_that(tools::floor_log(4,\
    \ 3) == 0);\n  assert_that(tools::floor_log(4, 4) == 1);\n  assert_that(tools::floor_log(4,\
    \ 5) == 1);\n  assert_that(tools::floor_log(4, 6) == 1);\n  assert_that(tools::floor_log(4,\
    \ 7) == 1);\n  assert_that(tools::floor_log(4, 8) == 1);\n  assert_that(tools::floor_log(4,\
    \ 9) == 1);\n  assert_that(tools::floor_log(2, 576460752303423487) == 58);\n \
    \ assert_that(tools::floor_log(2, 576460752303423488) == 59);\n  assert_that(tools::floor_log(2,\
    \ 576460752303423489) == 59);\n  assert_that(tools::floor_log(2, 1000000000000000000)\
    \ == 59);\n  assert_that(tools::floor_log(1000000000000000000, 1) == 0);\n  assert_that(tools::floor_log(1000000000000000000,\
    \ 2) == 0);\n  assert_that(tools::floor_log(999999999999999999, 999999999999999998)\
    \ == 0);\n  assert_that(tools::floor_log(999999999999999999, 999999999999999999)\
    \ == 1);\n  assert_that(tools::floor_log(999999999999999999, 1000000000000000000)\
    \ == 1);\n\n  std::cout << \"Hello World\" << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - tools/assert_that.hpp
  - tools/floor_log.hpp
  - tools/floor.hpp
  isVerificationFile: true
  path: tests/floor_log.test.cpp
  requiredBy: []
  timestamp: '2024-08-31 13:46:12+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: tests/floor_log.test.cpp
layout: document
redirect_from:
- /verify/tests/floor_log.test.cpp
- /verify/tests/floor_log.test.cpp.html
title: tests/floor_log.test.cpp
---
