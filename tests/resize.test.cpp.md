---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/assert_that.hpp
    title: Assertion macro
  - icon: ':heavy_check_mark:'
    path: tools/resize.hpp
    title: Resize a multi-dimensional vector
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
  bundledCode: "#line 1 \"tests/resize.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\"\
    \n\n#include <cstdlib>\n#include <iostream>\n#include <vector>\n#line 1 \"tools/assert_that.hpp\"\
    \n\n\n\n#define assert_that(cond) do {\\\n  if (!(cond)) {\\\n    std::cerr <<\
    \ __FILE__ << ':' << __LINE__ << \": \" << __func__ << \": Assertion `\" << #cond\
    \ << \"' failed.\" << '\\n';\\\n    std::exit(EXIT_FAILURE);\\\n  }\\\n} while\
    \ (false)\n\n\n#line 1 \"tools/resize.hpp\"\n\n\n\n#line 5 \"tools/resize.hpp\"\
    \n\n// Source: https://koyumeishi.hatenablog.com/entry/2016/02/01/152426\n// License:\
    \ unknown\n// Author: koyumeishi\n\nnamespace tools {\n  template <class T, class\
    \ Allocator, typename Head>\n  void resize(::std::vector<T, Allocator>& vector,\
    \ const Head& head) {\n    vector.resize(head);\n  }\n  template <class T, class\
    \ Allocator, typename Head, typename... Tail>\n  void resize(::std::vector<T,\
    \ Allocator>& vector, const Head& head, const Tail&... tail) {\n    vector.resize(head);\n\
    \    for (auto& child : vector) {\n      ::tools::resize(child, tail...);\n  \
    \  }\n  }\n}\n\n\n#line 8 \"tests/resize.test.cpp\"\n\nint main() {\n  std::cin.tie(nullptr);\n\
    \  std::ios_base::sync_with_stdio(false);\n\n  {\n    std::vector<std::vector<std::vector<int>>>\
    \ v;\n    tools::resize(v, 3, 4, 5);\n    assert_that(v.size() == 3);\n    for\
    \ (int i = 0; i < 3; ++i) {\n      assert_that(v[i].size() == 4);\n      for (int\
    \ j = 0; j < 4; ++j) {\n        assert_that(v[i][j].size() == 5);\n      }\n \
    \   }\n  }\n\n  {\n    std::vector<std::vector<std::vector<int>>> v;\n    tools::resize(v,\
    \ 3, 4, 0);\n    assert_that(v.size() == 3);\n    for (int i = 0; i < 3; ++i)\
    \ {\n      assert_that(v[i].size() == 4);\n      for (int j = 0; j < 4; ++j) {\n\
    \        assert_that(v[i][j].size() == 0);\n      }\n    }\n  }\n\n  {\n    std::vector<std::vector<std::vector<int>>>\
    \ v;\n    tools::resize(v, 0, 4, 5);\n    assert_that(v.size() == 0);\n  }\n\n\
    \  {\n    std::vector<int> v;\n    tools::resize(v, 3);\n    assert_that(v.size()\
    \ == 3);\n  }\n\n  {\n    std::vector<int> v;\n    tools::resize(v, 0);\n    assert_that(v.size()\
    \ == 0);\n  }\n\n  std::cout << \"Hello World\" << '\\n';\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\"\n\n\
    #include <cstdlib>\n#include <iostream>\n#include <vector>\n#include \"tools/assert_that.hpp\"\
    \n#include \"tools/resize.hpp\"\n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  {\n    std::vector<std::vector<std::vector<int>>> v;\n    tools::resize(v,\
    \ 3, 4, 5);\n    assert_that(v.size() == 3);\n    for (int i = 0; i < 3; ++i)\
    \ {\n      assert_that(v[i].size() == 4);\n      for (int j = 0; j < 4; ++j) {\n\
    \        assert_that(v[i][j].size() == 5);\n      }\n    }\n  }\n\n  {\n    std::vector<std::vector<std::vector<int>>>\
    \ v;\n    tools::resize(v, 3, 4, 0);\n    assert_that(v.size() == 3);\n    for\
    \ (int i = 0; i < 3; ++i) {\n      assert_that(v[i].size() == 4);\n      for (int\
    \ j = 0; j < 4; ++j) {\n        assert_that(v[i][j].size() == 0);\n      }\n \
    \   }\n  }\n\n  {\n    std::vector<std::vector<std::vector<int>>> v;\n    tools::resize(v,\
    \ 0, 4, 5);\n    assert_that(v.size() == 0);\n  }\n\n  {\n    std::vector<int>\
    \ v;\n    tools::resize(v, 3);\n    assert_that(v.size() == 3);\n  }\n\n  {\n\
    \    std::vector<int> v;\n    tools::resize(v, 0);\n    assert_that(v.size() ==\
    \ 0);\n  }\n\n  std::cout << \"Hello World\" << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - tools/assert_that.hpp
  - tools/resize.hpp
  isVerificationFile: true
  path: tests/resize.test.cpp
  requiredBy: []
  timestamp: '2022-06-11 15:16:18+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/resize.test.cpp
layout: document
redirect_from:
- /verify/tests/resize.test.cpp
- /verify/tests/resize.test.cpp.html
title: tests/resize.test.cpp
---
