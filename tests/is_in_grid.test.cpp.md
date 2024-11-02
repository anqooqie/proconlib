---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/assert_that.hpp
    title: Assertion macro
  - icon: ':heavy_check_mark:'
    path: tools/cmp_greater_equal.hpp
    title: Polyfill of std::cmp_greater_equal
  - icon: ':heavy_check_mark:'
    path: tools/cmp_less.hpp
    title: Polyfill of std::cmp_less
  - icon: ':heavy_check_mark:'
    path: tools/cmp_less_equal.hpp
    title: Polyfill of std::cmp_less_equal
  - icon: ':heavy_check_mark:'
    path: tools/is_in_grid.hpp
    title: Check whether $(r, c)$ is in a grid of height $h$ and width $w$
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
  bundledCode: "#line 1 \"tests/is_in_grid.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\"\
    \n\n#include <iostream>\n#line 1 \"tools/assert_that.hpp\"\n\n\n\n#line 5 \"tools/assert_that.hpp\"\
    \n#include <cstdlib>\n\n#define assert_that_impl(cond, file, line, func) do {\\\
    \n  if (!cond) {\\\n    ::std::cerr << file << ':' << line << \": \" << func <<\
    \ \": Assertion `\" << #cond << \"' failed.\" << '\\n';\\\n    ::std::exit(EXIT_FAILURE);\\\
    \n  }\\\n} while (false)\n#define assert_that(...) assert_that_impl((__VA_ARGS__),\
    \ __FILE__, __LINE__, __func__)\n\n\n#line 1 \"tools/is_in_grid.hpp\"\n\n\n\n\
    #include <cassert>\n#line 1 \"tools/cmp_greater_equal.hpp\"\n\n\n\n#line 1 \"\
    tools/cmp_less.hpp\"\n\n\n\n#include <type_traits>\n\nnamespace tools {\n  template\
    \ <typename T, typename U>\n  constexpr bool cmp_less(const T t, const U u) noexcept\
    \ {\n    using UT = ::std::make_unsigned_t<T>;\n    using UU = ::std::make_unsigned_t<U>;\n\
    \    if constexpr (::std::is_signed_v<T> == ::std::is_signed_v<U>) {\n      return\
    \ t < u;\n    } else if constexpr (::std::is_signed_v<T>) {\n      return t <\
    \ 0 ? true : UT(t) < u;\n    } else {\n      return u < 0 ? false : t < UU(u);\n\
    \    }\n  }\n}\n\n\n#line 5 \"tools/cmp_greater_equal.hpp\"\n\nnamespace tools\
    \ {\n  template <typename T, typename U>\n  constexpr bool cmp_greater_equal(const\
    \ T t, const U u) noexcept {\n    return !::tools::cmp_less(t, u);\n  }\n}\n\n\
    \n#line 1 \"tools/cmp_less_equal.hpp\"\n\n\n\n#line 5 \"tools/cmp_less_equal.hpp\"\
    \n\nnamespace tools {\n  template <typename T, typename U>\n  constexpr bool cmp_less_equal(const\
    \ T t, const U u) noexcept {\n    return !::tools::cmp_less(u, t);\n  }\n}\n\n\
    \n#line 8 \"tools/is_in_grid.hpp\"\n\nnamespace tools {\n  template <typename\
    \ T1, typename T2, typename T3, typename T4>\n  constexpr bool is_in_grid(const\
    \ T1 r, const T2 c, const T3 h, const T4 w) noexcept {\n    assert(::tools::cmp_greater_equal(h,\
    \ 0));\n    assert(::tools::cmp_greater_equal(w, 0));\n    return ::tools::cmp_less_equal(0,\
    \ r) && ::tools::cmp_less(r, h) && ::tools::cmp_less_equal(0, c) && ::tools::cmp_less(c,\
    \ w);\n  }\n}\n\n\n#line 6 \"tests/is_in_grid.test.cpp\"\n\nint main() {\n  std::cin.tie(nullptr);\n\
    \  std::ios_base::sync_with_stdio(false);\n\n  assert_that(!tools::is_in_grid(-1,\
    \ -1, 2U, 3U));\n  assert_that(!tools::is_in_grid(-1, 0, 2U, 3U));\n  assert_that(!tools::is_in_grid(-1,\
    \ 1, 2U, 3U));\n  assert_that(!tools::is_in_grid(-1, 2, 2U, 3U));\n  assert_that(!tools::is_in_grid(-1,\
    \ 3, 2U, 3U));\n  assert_that(!tools::is_in_grid(0, -1, 2U, 3U));\n  assert_that(tools::is_in_grid(0,\
    \ 0, 2U, 3U));\n  assert_that(tools::is_in_grid(0, 1, 2U, 3U));\n  assert_that(tools::is_in_grid(0,\
    \ 2, 2U, 3U));\n  assert_that(!tools::is_in_grid(0, 3, 2U, 3U));\n  assert_that(!tools::is_in_grid(1,\
    \ -1, 2U, 3U));\n  assert_that(tools::is_in_grid(1, 0, 2U, 3U));\n  assert_that(tools::is_in_grid(1,\
    \ 1, 2U, 3U));\n  assert_that(tools::is_in_grid(1, 2, 2U, 3U));\n  assert_that(!tools::is_in_grid(1,\
    \ 3, 2U, 3U));\n  assert_that(!tools::is_in_grid(2, -1, 2U, 3U));\n  assert_that(!tools::is_in_grid(2,\
    \ 0, 2U, 3U));\n  assert_that(!tools::is_in_grid(2, 1, 2U, 3U));\n  assert_that(!tools::is_in_grid(2,\
    \ 2, 2U, 3U));\n  assert_that(!tools::is_in_grid(2, 3, 2U, 3U));\n\n  assert_that(!tools::is_in_grid(-1,\
    \ -1, 0U, 0U));\n  assert_that(!tools::is_in_grid(-1, 0, 0U, 0U));\n  assert_that(!tools::is_in_grid(0,\
    \ -1, 0U, 0U));\n  assert_that(!tools::is_in_grid(0, 0, 0U, 0U));\n\n  std::cout\
    \ << \"Hello World\" << '\\n';\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\"\n\n\
    #include <iostream>\n#include \"tools/assert_that.hpp\"\n#include \"tools/is_in_grid.hpp\"\
    \n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  assert_that(!tools::is_in_grid(-1, -1, 2U, 3U));\n  assert_that(!tools::is_in_grid(-1,\
    \ 0, 2U, 3U));\n  assert_that(!tools::is_in_grid(-1, 1, 2U, 3U));\n  assert_that(!tools::is_in_grid(-1,\
    \ 2, 2U, 3U));\n  assert_that(!tools::is_in_grid(-1, 3, 2U, 3U));\n  assert_that(!tools::is_in_grid(0,\
    \ -1, 2U, 3U));\n  assert_that(tools::is_in_grid(0, 0, 2U, 3U));\n  assert_that(tools::is_in_grid(0,\
    \ 1, 2U, 3U));\n  assert_that(tools::is_in_grid(0, 2, 2U, 3U));\n  assert_that(!tools::is_in_grid(0,\
    \ 3, 2U, 3U));\n  assert_that(!tools::is_in_grid(1, -1, 2U, 3U));\n  assert_that(tools::is_in_grid(1,\
    \ 0, 2U, 3U));\n  assert_that(tools::is_in_grid(1, 1, 2U, 3U));\n  assert_that(tools::is_in_grid(1,\
    \ 2, 2U, 3U));\n  assert_that(!tools::is_in_grid(1, 3, 2U, 3U));\n  assert_that(!tools::is_in_grid(2,\
    \ -1, 2U, 3U));\n  assert_that(!tools::is_in_grid(2, 0, 2U, 3U));\n  assert_that(!tools::is_in_grid(2,\
    \ 1, 2U, 3U));\n  assert_that(!tools::is_in_grid(2, 2, 2U, 3U));\n  assert_that(!tools::is_in_grid(2,\
    \ 3, 2U, 3U));\n\n  assert_that(!tools::is_in_grid(-1, -1, 0U, 0U));\n  assert_that(!tools::is_in_grid(-1,\
    \ 0, 0U, 0U));\n  assert_that(!tools::is_in_grid(0, -1, 0U, 0U));\n  assert_that(!tools::is_in_grid(0,\
    \ 0, 0U, 0U));\n\n  std::cout << \"Hello World\" << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - tools/assert_that.hpp
  - tools/is_in_grid.hpp
  - tools/cmp_greater_equal.hpp
  - tools/cmp_less.hpp
  - tools/cmp_less_equal.hpp
  isVerificationFile: true
  path: tests/is_in_grid.test.cpp
  requiredBy: []
  timestamp: '2024-11-02 17:42:08+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/is_in_grid.test.cpp
layout: document
redirect_from:
- /verify/tests/is_in_grid.test.cpp
- /verify/tests/is_in_grid.test.cpp.html
title: tests/is_in_grid.test.cpp
---
