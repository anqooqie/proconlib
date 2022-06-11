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
    \n\n\n\n#define assert_that(cond) do {\\\n  if (!(cond)) {\\\n    std::cerr <<\
    \ __FILE__ << ':' << __LINE__ << \": \" << __func__ << \": Assertion `\" << #cond\
    \ << \"' failed.\" << '\\n';\\\n    std::exit(EXIT_FAILURE);\\\n  }\\\n} while\
    \ (false)\n\n\n#line 1 \"tools/mex.hpp\"\n\n\n\n#include <iterator>\n#line 6 \"\
    tools/mex.hpp\"\n\nnamespace tools {\n\n  template <typename InputIterator>\n\
    \  typename ::std::iterator_traits<InputIterator>::value_type mex(InputIterator\
    \ begin, InputIterator end) {\n    using T = typename ::std::iterator_traits<InputIterator>::value_type;\n\
    \    const ::std::vector<T> orig(begin, end);\n    const T n = orig.size();\n\
    \    ::std::vector<bool> exists(n, false);\n    for (const auto& o : orig) {\n\
    \      if (0 <= o && o < n) {\n        exists[o] = true;\n      }\n    }\n   \
    \ for (T i = 0; i < n; ++i) {\n      if (!exists[i]) {\n        return i;\n  \
    \    }\n    }\n    return n;\n  }\n}\n\n\n#line 8 \"tests/mex.test.cpp\"\n\nusing\
    \ i64 = std::int_fast64_t;\n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  std::vector<i64> v({1000000000000000000, 2, 1, 0, -1});\n  assert_that(tools::mex(v.begin(),\
    \ v.end()) == 3);\n  v = std::vector<i64>({3, 3, 2, 2, 1, 1, 0});\n  assert_that(tools::mex(v.begin(),\
    \ v.end()) == 4);\n  v = std::vector<i64>({3, 2, 0, 4, 1});\n  assert_that(tools::mex(v.begin(),\
    \ v.end()) == 5);\n  v = std::vector<i64>({3, 2, 4, 1});\n  assert_that(tools::mex(v.begin(),\
    \ v.end()) == 0);\n\n  std::cout << \"Hello World\" << '\\n';\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\"\n\n\
    #include <cstdlib>\n#include <iostream>\n#include <vector>\n#include \"tools/assert_that.hpp\"\
    \n#include \"tools/mex.hpp\"\n\nusing i64 = std::int_fast64_t;\n\nint main() {\n\
    \  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\n  std::vector<i64>\
    \ v({1000000000000000000, 2, 1, 0, -1});\n  assert_that(tools::mex(v.begin(),\
    \ v.end()) == 3);\n  v = std::vector<i64>({3, 3, 2, 2, 1, 1, 0});\n  assert_that(tools::mex(v.begin(),\
    \ v.end()) == 4);\n  v = std::vector<i64>({3, 2, 0, 4, 1});\n  assert_that(tools::mex(v.begin(),\
    \ v.end()) == 5);\n  v = std::vector<i64>({3, 2, 4, 1});\n  assert_that(tools::mex(v.begin(),\
    \ v.end()) == 0);\n\n  std::cout << \"Hello World\" << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - tools/assert_that.hpp
  - tools/mex.hpp
  isVerificationFile: true
  path: tests/mex.test.cpp
  requiredBy: []
  timestamp: '2022-06-11 15:16:18+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/mex.test.cpp
layout: document
redirect_from:
- /verify/tests/mex.test.cpp
- /verify/tests/mex.test.cpp.html
title: tests/mex.test.cpp
---
