---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tests/assert_that.hpp
    title: tests/assert_that.hpp
  - icon: ':heavy_check_mark:'
    path: tools/fix.hpp
    title: Fixed point combinator
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
  bundledCode: "#line 1 \"tests/fix.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\"\
    \n\n#include <iostream>\n#line 1 \"tests/assert_that.hpp\"\n\n\n\n#define assert_that(cond)\
    \ do {\\\n  if (!(cond)) {\\\n    std::cerr << __FILE__ << ':' << __LINE__ <<\
    \ \": \" << __func__ << \": Assertion `\" << #cond << \"' failed.\" << '\\n';\\\
    \n    std::exit(EXIT_FAILURE);\\\n  }\\\n} while (false)\n\n\n#line 1 \"tools/fix.hpp\"\
    \n\n\n\n#include <utility>\n#include <type_traits>\n\nnamespace tools {\n  template\
    \ <typename F>\n  struct fix : F {\n    template <typename G>\n    fix(G&& g)\
    \ : F({::std::forward<G>(g)}) {\n    }\n\n    template <typename... Args>\n  \
    \  decltype(auto) operator()(Args&&... args) const {\n      return F::operator()(*this,\
    \ ::std::forward<Args>(args)...);\n    }\n  };\n\n  template <typename F>\n  fix(F&&)\
    \ -> fix<::std::decay_t<F>>;\n}\n\n\n#line 6 \"tests/fix.test.cpp\"\n\nint main()\
    \ {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\n  assert_that(tools::fix([&](auto&&\
    \ fib, const int n) -> int {\n    return n >= 2 ? fib(n - 2) + fib(n - 1) : n;\n\
    \  })(10) == 55);\n\n  std::cout << \"Hello World\" << '\\n';\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\"\n\n\
    #include <iostream>\n#include \"tests/assert_that.hpp\"\n#include \"tools/fix.hpp\"\
    \n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  assert_that(tools::fix([&](auto&& fib, const int n) -> int {\n    return n\
    \ >= 2 ? fib(n - 2) + fib(n - 1) : n;\n  })(10) == 55);\n\n  std::cout << \"Hello\
    \ World\" << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - tests/assert_that.hpp
  - tools/fix.hpp
  isVerificationFile: true
  path: tests/fix.test.cpp
  requiredBy: []
  timestamp: '2021-11-27 17:50:09+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/fix.test.cpp
layout: document
redirect_from:
- /verify/tests/fix.test.cpp
- /verify/tests/fix.test.cpp.html
title: tests/fix.test.cpp
---