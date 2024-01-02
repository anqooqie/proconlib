---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/assert_that.hpp
    title: Assertion macro
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
    \n\n#include <cstdlib>\n#include <iostream>\n#include <vector>\n#include <array>\n\
    #line 1 \"tools/assert_that.hpp\"\n\n\n\n#line 6 \"tools/assert_that.hpp\"\n\n\
    #define assert_that(cond) do {\\\n  if (!(cond)) {\\\n    ::std::cerr << __FILE__\
    \ << ':' << __LINE__ << \": \" << __func__ << \": Assertion `\" << #cond << \"\
    ' failed.\" << '\\n';\\\n    ::std::exit(EXIT_FAILURE);\\\n  }\\\n} while (false)\n\
    \n\n#line 1 \"tools/fill.hpp\"\n\n\n\n#include <type_traits>\n#line 6 \"tools/fill.hpp\"\
    \n#include <algorithm>\n#include <iterator>\n#include <cstddef>\n#line 1 \"tools/is_range.hpp\"\
    \n\n\n\n#line 6 \"tools/is_range.hpp\"\n#include <utility>\n\nnamespace tools\
    \ {\n  template <typename T, typename = ::std::void_t<>>\n  struct is_range :\
    \ ::std::false_type {};\n\n  template <typename T>\n  struct is_range<T, ::std::void_t<decltype(::std::begin(::std::declval<T>()),\
    \ ::std::end(::std::declval<T>()))>> : ::std::true_type {};\n\n  template <typename\
    \ T>\n  inline constexpr bool is_range_v = ::tools::is_range<T>::value;\n}\n\n\
    \n#line 11 \"tools/fill.hpp\"\n\nnamespace tools {\n  template <class T, class\
    \ Allocator, typename V>\n  ::std::enable_if_t<!::tools::is_range_v<T>, void>\
    \ fill(::std::vector<T, Allocator>& vector, const V& value) {\n    ::std::fill(::std::begin(vector),\
    \ ::std::end(vector), value);\n  }\n  template <class T, ::std::size_t N, typename\
    \ V>\n  ::std::enable_if_t<!::tools::is_range_v<T>, void> fill(::std::array<T,\
    \ N>& array, const V& value) {\n    ::std::fill(::std::begin(array), ::std::end(array),\
    \ value);\n  }\n\n  template <class T, class Allocator, typename V>\n  ::std::enable_if_t<::tools::is_range_v<T>,\
    \ void> fill(::std::vector<T, Allocator>& vector, const V& value);\n  template\
    \ <class T, ::std::size_t N, typename V>\n  ::std::enable_if_t<::tools::is_range_v<T>,\
    \ void> fill(::std::array<T, N>& array, const V& value);\n\n  template <class\
    \ T, class Allocator, typename V>\n  ::std::enable_if_t<::tools::is_range_v<T>,\
    \ void> fill(::std::vector<T, Allocator>& vector, const V& value) {\n    for (auto&\
    \ child : vector) {\n      ::tools::fill(child, value);\n    }\n  }\n  template\
    \ <class T, ::std::size_t N, typename V>\n  ::std::enable_if_t<::tools::is_range_v<T>,\
    \ void> fill(::std::array<T, N>& array, const V& value) {\n    for (auto& child\
    \ : array) {\n      ::tools::fill(child, value);\n    }\n  }\n}\n\n\n#line 9 \"\
    tests/fill.test.cpp\"\n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  {\n    auto v = std::vector(3, std::vector(4, std::vector<int>(5)));\n   \
    \ tools::fill(v, 6);\n    for (int i = 0; i < 3; ++i) {\n      for (int j = 0;\
    \ j < 4; ++j) {\n        for (int k = 0; k < 5; ++k) {\n          assert_that(v[i][j][k]\
    \ == 6);\n        }\n      }\n    }\n  }\n\n  {\n    auto v = std::vector(3, std::vector(4,\
    \ std::vector<int>(0)));\n    tools::fill(v, 6);\n  }\n\n  {\n    auto v = std::vector<int>(3);\n\
    \    tools::fill(v, 6);\n    for (int i = 0; i < 3; ++i) {\n      assert_that(v[i]\
    \ == 6);\n    }\n  }\n\n  {\n    auto v = std::vector<int>(0);\n    tools::fill(v,\
    \ 6);\n  }\n\n  {\n    std::array<std::vector<std::vector<int>>, 3> v;\n    for\
    \ (int i = 0; i < 3; ++i) {\n      v[i].resize(4);\n      for (int j = 0; j <\
    \ 4; ++j) {\n        v[i][j].resize(5);\n      }\n    }\n    tools::fill(v, 6);\n\
    \    for (int i = 0; i < 3; ++i) {\n      for (int j = 0; j < 4; ++j) {\n    \
    \    for (int k = 0; k < 5; ++k) {\n          assert_that(v[i][j][k] == 6);\n\
    \        }\n      }\n    }\n  }\n\n  {\n    std::vector<std::array<std::vector<int>,\
    \ 4>> v;\n    v.resize(3);\n    for (int i = 0; i < 3; ++i) {\n      for (int\
    \ j = 0; j < 4; ++j) {\n        v[i][j].resize(5);\n      }\n    }\n    tools::fill(v,\
    \ 6);\n    for (int i = 0; i < 3; ++i) {\n      for (int j = 0; j < 4; ++j) {\n\
    \        for (int k = 0; k < 5; ++k) {\n          assert_that(v[i][j][k] == 6);\n\
    \        }\n      }\n    }\n  }\n\n  {\n    std::vector<std::vector<std::array<int,\
    \ 5>>> v;\n    v.resize(3);\n    for (int i = 0; i < 3; ++i) {\n      v[i].resize(4);\n\
    \    }\n    tools::fill(v, 6);\n    for (int i = 0; i < 3; ++i) {\n      for (int\
    \ j = 0; j < 4; ++j) {\n        for (int k = 0; k < 5; ++k) {\n          assert_that(v[i][j][k]\
    \ == 6);\n        }\n      }\n    }\n  }\n\n  {\n    std::array<std::array<std::array<int,\
    \ 5>, 4>, 3> v;\n    tools::fill(v, 6);\n    for (int i = 0; i < 3; ++i) {\n \
    \     for (int j = 0; j < 4; ++j) {\n        for (int k = 0; k < 5; ++k) {\n \
    \         assert_that(v[i][j][k] == 6);\n        }\n      }\n    }\n  }\n\n  {\n\
    \    std::array<int, 3> v;\n    tools::fill(v, 6);\n    for (int i = 0; i < 3;\
    \ ++i) {\n      assert_that(v[i] == 6);\n    }\n  }\n\n  std::cout << \"Hello\
    \ World\" << '\\n';\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\"\n\n\
    #include <cstdlib>\n#include <iostream>\n#include <vector>\n#include <array>\n\
    #include \"tools/assert_that.hpp\"\n#include \"tools/fill.hpp\"\n\nint main()\
    \ {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\n  {\n\
    \    auto v = std::vector(3, std::vector(4, std::vector<int>(5)));\n    tools::fill(v,\
    \ 6);\n    for (int i = 0; i < 3; ++i) {\n      for (int j = 0; j < 4; ++j) {\n\
    \        for (int k = 0; k < 5; ++k) {\n          assert_that(v[i][j][k] == 6);\n\
    \        }\n      }\n    }\n  }\n\n  {\n    auto v = std::vector(3, std::vector(4,\
    \ std::vector<int>(0)));\n    tools::fill(v, 6);\n  }\n\n  {\n    auto v = std::vector<int>(3);\n\
    \    tools::fill(v, 6);\n    for (int i = 0; i < 3; ++i) {\n      assert_that(v[i]\
    \ == 6);\n    }\n  }\n\n  {\n    auto v = std::vector<int>(0);\n    tools::fill(v,\
    \ 6);\n  }\n\n  {\n    std::array<std::vector<std::vector<int>>, 3> v;\n    for\
    \ (int i = 0; i < 3; ++i) {\n      v[i].resize(4);\n      for (int j = 0; j <\
    \ 4; ++j) {\n        v[i][j].resize(5);\n      }\n    }\n    tools::fill(v, 6);\n\
    \    for (int i = 0; i < 3; ++i) {\n      for (int j = 0; j < 4; ++j) {\n    \
    \    for (int k = 0; k < 5; ++k) {\n          assert_that(v[i][j][k] == 6);\n\
    \        }\n      }\n    }\n  }\n\n  {\n    std::vector<std::array<std::vector<int>,\
    \ 4>> v;\n    v.resize(3);\n    for (int i = 0; i < 3; ++i) {\n      for (int\
    \ j = 0; j < 4; ++j) {\n        v[i][j].resize(5);\n      }\n    }\n    tools::fill(v,\
    \ 6);\n    for (int i = 0; i < 3; ++i) {\n      for (int j = 0; j < 4; ++j) {\n\
    \        for (int k = 0; k < 5; ++k) {\n          assert_that(v[i][j][k] == 6);\n\
    \        }\n      }\n    }\n  }\n\n  {\n    std::vector<std::vector<std::array<int,\
    \ 5>>> v;\n    v.resize(3);\n    for (int i = 0; i < 3; ++i) {\n      v[i].resize(4);\n\
    \    }\n    tools::fill(v, 6);\n    for (int i = 0; i < 3; ++i) {\n      for (int\
    \ j = 0; j < 4; ++j) {\n        for (int k = 0; k < 5; ++k) {\n          assert_that(v[i][j][k]\
    \ == 6);\n        }\n      }\n    }\n  }\n\n  {\n    std::array<std::array<std::array<int,\
    \ 5>, 4>, 3> v;\n    tools::fill(v, 6);\n    for (int i = 0; i < 3; ++i) {\n \
    \     for (int j = 0; j < 4; ++j) {\n        for (int k = 0; k < 5; ++k) {\n \
    \         assert_that(v[i][j][k] == 6);\n        }\n      }\n    }\n  }\n\n  {\n\
    \    std::array<int, 3> v;\n    tools::fill(v, 6);\n    for (int i = 0; i < 3;\
    \ ++i) {\n      assert_that(v[i] == 6);\n    }\n  }\n\n  std::cout << \"Hello\
    \ World\" << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - tools/assert_that.hpp
  - tools/fill.hpp
  - tools/is_range.hpp
  isVerificationFile: true
  path: tests/fill.test.cpp
  requiredBy: []
  timestamp: '2022-11-23 11:35:29+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/fill.test.cpp
layout: document
redirect_from:
- /verify/tests/fill.test.cpp
- /verify/tests/fill.test.cpp.html
title: tests/fill.test.cpp
---
