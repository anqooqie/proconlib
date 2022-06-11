---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/assert_that.hpp
    title: Assertion macro
  - icon: ':heavy_check_mark:'
    path: tools/chmin.hpp
    title: chmin function
  - icon: ':heavy_check_mark:'
    path: tools/xor_basis.hpp
    title: Basis of xor
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
  bundledCode: "#line 1 \"tests/xor_basis.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\"\
    \n\n#include <cstdint>\n#include <iostream>\n#include <vector>\n#include <iterator>\n\
    #line 1 \"tools/assert_that.hpp\"\n\n\n\n#define assert_that(cond) do {\\\n  if\
    \ (!(cond)) {\\\n    std::cerr << __FILE__ << ':' << __LINE__ << \": \" << __func__\
    \ << \": Assertion `\" << #cond << \"' failed.\" << '\\n';\\\n    std::exit(EXIT_FAILURE);\\\
    \n  }\\\n} while (false)\n\n\n#line 1 \"tools/xor_basis.hpp\"\n\n\n\n#include\
    \ <type_traits>\n#line 1 \"tools/chmin.hpp\"\n\n\n\n#include <algorithm>\n\nnamespace\
    \ tools {\n\n  template <typename M, typename N>\n  bool chmin(M& lhs, const N&\
    \ rhs) {\n    const bool updated = lhs > rhs;\n    if (updated) lhs = rhs;\n \
    \   return updated;\n  }\n}\n\n\n#line 7 \"tools/xor_basis.hpp\"\n\n// Source:\
    \ https://twitter.com/noshi91/status/1200702280128856064\n// License: unknown\n\
    // Author: noshi91\n\nnamespace tools {\n  template <typename InputIterator, typename\
    \ OutputIterator>\n  void xor_basis(const InputIterator& begin, const InputIterator&\
    \ end, OutputIterator result) {\n    using T = ::std::decay_t<decltype(*begin)>;\n\
    \n    ::std::vector<T> basis;\n    for (auto it = begin; it != end; ++it) {\n\
    \      T e = *it;\n      for (const T& b : basis) {\n        ::tools::chmin(e,\
    \ e ^ b);\n      }\n      if (e != 0) {\n        basis.push_back(e);\n      }\n\
    \    }\n\n    for (const T& b : basis) {\n      *result = b;\n      ++result;\n\
    \    }\n  }\n}\n\n\n#line 9 \"tests/xor_basis.test.cpp\"\n\nusing i64 = std::int_fast64_t;\n\
    \nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  {\n    std::vector<i64> in({1, 1, 2, 4});\n    std::vector<i64> out;\n   \
    \ tools::xor_basis(in.begin(), in.end(), std::back_inserter(out));\n    assert_that(out.size()\
    \ == 3);\n  }\n  {\n    std::vector<i64> in({1, 1, 2, 1});\n    std::vector<i64>\
    \ out;\n    tools::xor_basis(in.begin(), in.end(), std::back_inserter(out));\n\
    \    assert_that(out.size() == 2);\n  }\n  {\n    std::vector<i64> in({1, 1, 2,\
    \ 3});\n    std::vector<i64> out;\n    tools::xor_basis(in.begin(), in.end(),\
    \ std::back_inserter(out));\n    assert_that(out.size() == 2);\n  }\n  {\n   \
    \ std::vector<i64> in({1, 2, 3});\n    std::vector<i64> out;\n    tools::xor_basis(in.begin(),\
    \ in.end(), std::back_inserter(out));\n    assert_that(out.size() == 2);\n  }\n\
    \  {\n    std::vector<i64> in({1});\n    std::vector<i64> out;\n    tools::xor_basis(in.begin(),\
    \ in.end(), std::back_inserter(out));\n    assert_that(out.size() == 1);\n  }\n\
    \  {\n    std::vector<i64> in;\n    std::vector<i64> out;\n    tools::xor_basis(in.begin(),\
    \ in.end(), std::back_inserter(out));\n    assert_that(out.size() == 0);\n  }\n\
    \n  std::cout << \"Hello World\" << '\\n';\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\"\n\n\
    #include <cstdint>\n#include <iostream>\n#include <vector>\n#include <iterator>\n\
    #include \"tools/assert_that.hpp\"\n#include \"tools/xor_basis.hpp\"\n\nusing\
    \ i64 = std::int_fast64_t;\n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  {\n    std::vector<i64> in({1, 1, 2, 4});\n    std::vector<i64> out;\n   \
    \ tools::xor_basis(in.begin(), in.end(), std::back_inserter(out));\n    assert_that(out.size()\
    \ == 3);\n  }\n  {\n    std::vector<i64> in({1, 1, 2, 1});\n    std::vector<i64>\
    \ out;\n    tools::xor_basis(in.begin(), in.end(), std::back_inserter(out));\n\
    \    assert_that(out.size() == 2);\n  }\n  {\n    std::vector<i64> in({1, 1, 2,\
    \ 3});\n    std::vector<i64> out;\n    tools::xor_basis(in.begin(), in.end(),\
    \ std::back_inserter(out));\n    assert_that(out.size() == 2);\n  }\n  {\n   \
    \ std::vector<i64> in({1, 2, 3});\n    std::vector<i64> out;\n    tools::xor_basis(in.begin(),\
    \ in.end(), std::back_inserter(out));\n    assert_that(out.size() == 2);\n  }\n\
    \  {\n    std::vector<i64> in({1});\n    std::vector<i64> out;\n    tools::xor_basis(in.begin(),\
    \ in.end(), std::back_inserter(out));\n    assert_that(out.size() == 1);\n  }\n\
    \  {\n    std::vector<i64> in;\n    std::vector<i64> out;\n    tools::xor_basis(in.begin(),\
    \ in.end(), std::back_inserter(out));\n    assert_that(out.size() == 0);\n  }\n\
    \n  std::cout << \"Hello World\" << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - tools/assert_that.hpp
  - tools/xor_basis.hpp
  - tools/chmin.hpp
  isVerificationFile: true
  path: tests/xor_basis.test.cpp
  requiredBy: []
  timestamp: '2022-06-11 15:16:18+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/xor_basis.test.cpp
layout: document
redirect_from:
- /verify/tests/xor_basis.test.cpp
- /verify/tests/xor_basis.test.cpp.html
title: tests/xor_basis.test.cpp
---
