---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/assert_that.hpp
    title: Assertion macro
  - icon: ':heavy_check_mark:'
    path: tools/cmp_greater.hpp
    title: Polyfill of std::cmp_greater
  - icon: ':heavy_check_mark:'
    path: tools/cmp_less.hpp
    title: Polyfill of std::cmp_less
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
  bundledCode: "#line 1 \"tests/cmp_greater.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\"\
    \n\n#include <iostream>\n#line 1 \"tools/assert_that.hpp\"\n\n\n\n#line 5 \"tools/assert_that.hpp\"\
    \n#include <cstdlib>\n\n#define assert_that_impl(cond, file, line, func) do {\\\
    \n  if (!cond) {\\\n    ::std::cerr << file << ':' << line << \": \" << func <<\
    \ \": Assertion `\" << #cond << \"' failed.\" << '\\n';\\\n    ::std::exit(EXIT_FAILURE);\\\
    \n  }\\\n} while (false)\n#define assert_that(...) assert_that_impl((__VA_ARGS__),\
    \ __FILE__, __LINE__, __func__)\n\n\n#line 1 \"tools/cmp_greater.hpp\"\n\n\n\n\
    #line 1 \"tools/cmp_less.hpp\"\n\n\n\n#include <type_traits>\n\nnamespace tools\
    \ {\n  template <typename T, typename U>\n  constexpr bool cmp_less(const T t,\
    \ const U u) noexcept {\n    using UT = ::std::make_unsigned_t<T>;\n    using\
    \ UU = ::std::make_unsigned_t<U>;\n    if constexpr (::std::is_signed_v<T> ==\
    \ ::std::is_signed_v<U>) {\n      return t < u;\n    } else if constexpr (::std::is_signed_v<T>)\
    \ {\n      return t < 0 ? true : UT(t) < u;\n    } else {\n      return u < 0\
    \ ? false : t < UU(u);\n    }\n  }\n}\n\n\n#line 5 \"tools/cmp_greater.hpp\"\n\
    \nnamespace tools {\n  template <typename T, typename U>\n  constexpr bool cmp_greater(const\
    \ T t, const U u) noexcept {\n    return ::tools::cmp_less(u, t);\n  }\n}\n\n\n\
    #line 6 \"tests/cmp_greater.test.cpp\"\n\nint main() {\n  std::cin.tie(nullptr);\n\
    \  std::ios_base::sync_with_stdio(false);\n\n  assert_that(!tools::cmp_greater(-1,\
    \ 0U));\n  assert_that(!tools::cmp_greater(0U, 0U));\n  assert_that(tools::cmp_greater(0U,\
    \ -1));\n\n  std::cout << \"Hello World\" << '\\n';\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\"\n\n\
    #include <iostream>\n#include \"tools/assert_that.hpp\"\n#include \"tools/cmp_greater.hpp\"\
    \n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  assert_that(!tools::cmp_greater(-1, 0U));\n  assert_that(!tools::cmp_greater(0U,\
    \ 0U));\n  assert_that(tools::cmp_greater(0U, -1));\n\n  std::cout << \"Hello\
    \ World\" << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - tools/assert_that.hpp
  - tools/cmp_greater.hpp
  - tools/cmp_less.hpp
  isVerificationFile: true
  path: tests/cmp_greater.test.cpp
  requiredBy: []
  timestamp: '2024-11-02 17:20:30+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/cmp_greater.test.cpp
layout: document
redirect_from:
- /verify/tests/cmp_greater.test.cpp
- /verify/tests/cmp_greater.test.cpp.html
title: tests/cmp_greater.test.cpp
---
