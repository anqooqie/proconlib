---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/assert_that.hpp
    title: Assertion macro
  - icon: ':heavy_check_mark:'
    path: tools/floor_quotients.hpp
    title: Enumerate the range of $\left\lfloor \frac{A}{x} \right\rfloor$
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
  bundledCode: "#line 1 \"tests/floor_quotients.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\"\
    \n\n#include <iostream>\n#include <vector>\n#include <tuple>\n#include <cassert>\n\
    #include <cstddef>\n#include <algorithm>\n#include <limits>\n#line 1 \"tools/assert_that.hpp\"\
    \n\n\n\n#line 5 \"tools/assert_that.hpp\"\n#include <cstdlib>\n\n#define assert_that(cond)\
    \ do {\\\n  if (!(cond)) {\\\n    ::std::cerr << __FILE__ << ':' << __LINE__ <<\
    \ \": \" << __func__ << \": Assertion `\" << #cond << \"' failed.\" << '\\n';\\\
    \n    ::std::exit(EXIT_FAILURE);\\\n  }\\\n} while (false)\n\n\n#line 1 \"tools/floor_quotients.hpp\"\
    \n\n\n\n#line 8 \"tools/floor_quotients.hpp\"\n\nnamespace tools {\n  template\
    \ <typename T>\n  ::std::vector<::std::tuple<T, T, T>> floor_quotients(const T\
    \ A) {\n    assert(A >= 0);\n\n    ::std::vector<::std::tuple<T, T, T>> res;\n\
    \    T x;\n    for (x = 1; x * x <= A; ++x) {\n      res.emplace_back(x, x + 1,\
    \ A / x);\n    }\n    for (T q = A / x; q > 0; --q) {\n      res.emplace_back(A\
    \ / (q + 1) + 1, A / q + 1, q);\n    }\n    res.emplace_back(A + 1, ::std::numeric_limits<T>::max(),\
    \ 0);\n\n    return res;\n  }\n}\n\n\n#line 12 \"tests/floor_quotients.test.cpp\"\
    \n\ntemplate <typename T>\nstd::vector<std::tuple<T, T, T>> naive(const T A) {\n\
    \  assert(A >= 0);\n\n  std::vector<std::tuple<T, T, T>> res;\n  for (T x = 1;\
    \ x <= A + 3; ++x) {\n    res.emplace_back(x, x + 1, A / x);\n  }\n\n  std::size_t\
    \ vl = 0;\n  for (std::size_t vr = 0, al = 0, ar = 0; al < res.size(); vl = vr,\
    \ al = ar) {\n    for (; ar < res.size() && std::get<2>(res[al]) == std::get<2>(res[ar]);\
    \ ++vr, ++ar);\n    if (vl < al) std::move(res.begin() + al, res.begin() + ar,\
    \ res.begin() + vl);\n    std::get<1>(res[vl]) = std::get<1>(res[vr - 1]);\n \
    \   vr = vl + 1;\n  }\n  res.erase(res.begin() + vl, res.end());\n\n  std::get<1>(res.back())\
    \ = std::numeric_limits<T>::max();\n  return res;\n}\n\nint main() {\n  std::cin.tie(nullptr);\n\
    \  std::ios_base::sync_with_stdio(false);\n\n  for (int A = 0; A <= 10000; ++A)\
    \ {\n    assert_that(tools::floor_quotients(A) == naive(A));\n  }\n\n  std::cout\
    \ << \"Hello World\" << '\\n';\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\"\n\n\
    #include <iostream>\n#include <vector>\n#include <tuple>\n#include <cassert>\n\
    #include <cstddef>\n#include <algorithm>\n#include <limits>\n#include \"tools/assert_that.hpp\"\
    \n#include \"tools/floor_quotients.hpp\"\n\ntemplate <typename T>\nstd::vector<std::tuple<T,\
    \ T, T>> naive(const T A) {\n  assert(A >= 0);\n\n  std::vector<std::tuple<T,\
    \ T, T>> res;\n  for (T x = 1; x <= A + 3; ++x) {\n    res.emplace_back(x, x +\
    \ 1, A / x);\n  }\n\n  std::size_t vl = 0;\n  for (std::size_t vr = 0, al = 0,\
    \ ar = 0; al < res.size(); vl = vr, al = ar) {\n    for (; ar < res.size() &&\
    \ std::get<2>(res[al]) == std::get<2>(res[ar]); ++vr, ++ar);\n    if (vl < al)\
    \ std::move(res.begin() + al, res.begin() + ar, res.begin() + vl);\n    std::get<1>(res[vl])\
    \ = std::get<1>(res[vr - 1]);\n    vr = vl + 1;\n  }\n  res.erase(res.begin()\
    \ + vl, res.end());\n\n  std::get<1>(res.back()) = std::numeric_limits<T>::max();\n\
    \  return res;\n}\n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  for (int A = 0; A <= 10000; ++A) {\n    assert_that(tools::floor_quotients(A)\
    \ == naive(A));\n  }\n\n  std::cout << \"Hello World\" << '\\n';\n  return 0;\n\
    }\n"
  dependsOn:
  - tools/assert_that.hpp
  - tools/floor_quotients.hpp
  isVerificationFile: true
  path: tests/floor_quotients.test.cpp
  requiredBy: []
  timestamp: '2023-07-15 18:52:42+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/floor_quotients.test.cpp
layout: document
redirect_from:
- /verify/tests/floor_quotients.test.cpp
- /verify/tests/floor_quotients.test.cpp.html
title: tests/floor_quotients.test.cpp
---
