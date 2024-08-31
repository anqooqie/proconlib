---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/assert_that.hpp
    title: Assertion macro
  - icon: ':heavy_check_mark:'
    path: tools/mex.hpp
    title: Minimum excluded value
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
  bundledCode: "#line 1 \"tests/mex.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\"\
    \n\n#include <cstdlib>\n#include <iostream>\n#include <vector>\n#line 1 \"tools/assert_that.hpp\"\
    \n\n\n\n#line 6 \"tools/assert_that.hpp\"\n\n#define assert_that_impl(cond, file,\
    \ line, func) do {\\\n  if (!cond) {\\\n    ::std::cerr << file << ':' << line\
    \ << \": \" << func << \": Assertion `\" << #cond << \"' failed.\" << '\\n';\\\
    \n    ::std::exit(EXIT_FAILURE);\\\n  }\\\n} while (false)\n#define assert_that(...)\
    \ assert_that_impl((__VA_ARGS__), __FILE__, __LINE__, __func__)\n\n\n#line 1 \"\
    tools/mex.hpp\"\n\n\n\n#include <type_traits>\n#include <utility>\n#line 7 \"\
    tools/mex.hpp\"\n#include <cstddef>\n#include <cassert>\n#include <algorithm>\n\
    \nnamespace tools {\n\n  template <typename InputIterator>\n  ::std::decay_t<decltype(*::std::declval<InputIterator>())>\
    \ mex(InputIterator begin, InputIterator end) {\n    using T = ::std::decay_t<decltype(*::std::declval<InputIterator>())>;\n\
    \    const ::std::vector<T> orig(begin, end);\n    const ::std::size_t n = orig.size();\n\
    \n    assert(::std::all_of(orig.begin(), orig.end(), [](const auto& o) { return\
    \ o >= 0; }));\n\n    ::std::vector<bool> exists(n, false);\n    for (const ::std::size_t\
    \ o : orig) {\n      if (o < n) {\n        exists[o] = true;\n      }\n    }\n\
    \    for (::std::size_t i = 0; i < n; ++i) {\n      if (!exists[i]) {\n      \
    \  return i;\n      }\n    }\n    return n;\n  }\n}\n\n\n#line 8 \"tests/mex.test.cpp\"\
    \n\nusing ll = long long;\n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  std::vector<ll> v({1000000000000000000, 2, 1, 0});\n  assert_that(tools::mex(v.begin(),\
    \ v.end()) == 3);\n  v = std::vector<ll>({3, 3, 2, 2, 1, 1, 0});\n  assert_that(tools::mex(v.begin(),\
    \ v.end()) == 4);\n  v = std::vector<ll>({3, 2, 0, 4, 1});\n  assert_that(tools::mex(v.begin(),\
    \ v.end()) == 5);\n  v = std::vector<ll>({3, 2, 4, 1});\n  assert_that(tools::mex(v.begin(),\
    \ v.end()) == 0);\n\n  std::cout << \"Hello World\" << '\\n';\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\"\n\n\
    #include <cstdlib>\n#include <iostream>\n#include <vector>\n#include \"tools/assert_that.hpp\"\
    \n#include \"tools/mex.hpp\"\n\nusing ll = long long;\n\nint main() {\n  std::cin.tie(nullptr);\n\
    \  std::ios_base::sync_with_stdio(false);\n\n  std::vector<ll> v({1000000000000000000,\
    \ 2, 1, 0});\n  assert_that(tools::mex(v.begin(), v.end()) == 3);\n  v = std::vector<ll>({3,\
    \ 3, 2, 2, 1, 1, 0});\n  assert_that(tools::mex(v.begin(), v.end()) == 4);\n \
    \ v = std::vector<ll>({3, 2, 0, 4, 1});\n  assert_that(tools::mex(v.begin(), v.end())\
    \ == 5);\n  v = std::vector<ll>({3, 2, 4, 1});\n  assert_that(tools::mex(v.begin(),\
    \ v.end()) == 0);\n\n  std::cout << \"Hello World\" << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - tools/assert_that.hpp
  - tools/mex.hpp
  isVerificationFile: true
  path: tests/mex.test.cpp
  requiredBy: []
  timestamp: '2024-08-31 13:46:12+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/mex.test.cpp
layout: document
redirect_from:
- /verify/tests/mex.test.cpp
- /verify/tests/mex.test.cpp.html
title: tests/mex.test.cpp
---
