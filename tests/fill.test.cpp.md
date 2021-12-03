---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tests/assert_that.hpp
    title: tests/assert_that.hpp
  - icon: ':heavy_check_mark:'
    path: tools/fill.hpp
    title: Fill a multi-dimensional vector
  - icon: ':heavy_check_mark:'
    path: tools/is_range.hpp
    title: Check whether T is a range type
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
  bundledCode: "#line 1 \"tests/fill.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\"\
    \n\n#include <cstdlib>\n#include <iostream>\n#include <vector>\n#line 1 \"tests/assert_that.hpp\"\
    \n\n\n\n#define assert_that(cond) do {\\\n  if (!(cond)) {\\\n    std::cerr <<\
    \ __FILE__ << ':' << __LINE__ << \": \" << __func__ << \": Assertion `\" << #cond\
    \ << \"' failed.\" << '\\n';\\\n    std::exit(EXIT_FAILURE);\\\n  }\\\n} while\
    \ (false)\n\n\n#line 1 \"tools/fill.hpp\"\n\n\n\n#line 5 \"tools/fill.hpp\"\n\
    #include <type_traits>\n#include <algorithm>\n#include <iterator>\n#line 1 \"\
    tools/is_range.hpp\"\n\n\n\n#line 6 \"tools/is_range.hpp\"\n#include <utility>\n\
    \nnamespace tools {\n  template <typename T>\n  class is_range {\n  private:\n\
    \    template <typename U>\n    static auto check(U x) -> decltype(::std::begin(x),\
    \ ::std::end(x), ::std::true_type{});\n    static ::std::false_type check(...);\n\
    \n  public:\n    static const bool value = decltype(check(::std::declval<T>()))::value;\n\
    \  };\n}\n\n\n#line 9 \"tools/fill.hpp\"\n\nnamespace tools {\n  template <class\
    \ T, class Allocator, typename V>\n  auto fill(::std::vector<T, Allocator>& vector,\
    \ const V& value) -> ::std::enable_if_t<!::tools::is_range<T>::value, void> {\n\
    \    ::std::fill(::std::begin(vector), ::std::end(vector), value);\n  }\n  template\
    \ <class T, class Allocator, typename V>\n  auto fill(::std::vector<T, Allocator>&\
    \ vector, const V& value) -> ::std::enable_if_t<::tools::is_range<T>::value, void>\
    \ {\n    for (auto& child : vector) {\n      ::tools::fill(child, value);\n  \
    \  }\n  }\n}\n\n\n#line 8 \"tests/fill.test.cpp\"\n\nint main() {\n  std::cin.tie(nullptr);\n\
    \  std::ios_base::sync_with_stdio(false);\n\n  {\n    auto v = std::vector(3,\
    \ std::vector(4, std::vector<int>(5)));\n    tools::fill(v, 6);\n    for (int\
    \ i = 0; i < 3; ++i) {\n      for (int j = 0; j < 4; ++j) {\n        for (int\
    \ k = 0; k < 5; ++k) {\n          assert_that(v[i][j][k] == 6);\n        }\n \
    \     }\n    }\n  }\n\n  {\n    auto v = std::vector(3, std::vector(4, std::vector<int>(0)));\n\
    \    tools::fill(v, 6);\n  }\n\n  {\n    auto v = std::vector<int>(3);\n    tools::fill(v,\
    \ 6);\n    for (int i = 0; i < 3; ++i) {\n      assert_that(v[i] == 6);\n    }\n\
    \  }\n\n  {\n    auto v = std::vector<int>(0);\n    tools::fill(v, 6);\n  }\n\n\
    \  std::cout << \"Hello World\" << '\\n';\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\"\n\n\
    #include <cstdlib>\n#include <iostream>\n#include <vector>\n#include \"tests/assert_that.hpp\"\
    \n#include \"tools/fill.hpp\"\n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  {\n    auto v = std::vector(3, std::vector(4, std::vector<int>(5)));\n   \
    \ tools::fill(v, 6);\n    for (int i = 0; i < 3; ++i) {\n      for (int j = 0;\
    \ j < 4; ++j) {\n        for (int k = 0; k < 5; ++k) {\n          assert_that(v[i][j][k]\
    \ == 6);\n        }\n      }\n    }\n  }\n\n  {\n    auto v = std::vector(3, std::vector(4,\
    \ std::vector<int>(0)));\n    tools::fill(v, 6);\n  }\n\n  {\n    auto v = std::vector<int>(3);\n\
    \    tools::fill(v, 6);\n    for (int i = 0; i < 3; ++i) {\n      assert_that(v[i]\
    \ == 6);\n    }\n  }\n\n  {\n    auto v = std::vector<int>(0);\n    tools::fill(v,\
    \ 6);\n  }\n\n  std::cout << \"Hello World\" << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - tests/assert_that.hpp
  - tools/fill.hpp
  - tools/is_range.hpp
  isVerificationFile: true
  path: tests/fill.test.cpp
  requiredBy: []
  timestamp: '2021-12-04 02:14:32+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/fill.test.cpp
layout: document
redirect_from:
- /verify/tests/fill.test.cpp
- /verify/tests/fill.test.cpp.html
title: tests/fill.test.cpp
---
