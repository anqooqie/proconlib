---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/qcfium.hpp
    title: QCFium's method
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
  bundledCode: "#line 1 \"tests/qcfium.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\"\
    \n\n#include <iostream>\n#line 1 \"tools/qcfium.hpp\"\n\n\n\n#pragma GCC target(\"\
    avx2\")\n#pragma GCC optimize(\"O3\")\n#pragma GCC optimize(\"unroll-loops\")\n\
    \n\n#line 5 \"tests/qcfium.test.cpp\"\n\nint main() {\n  std::cin.tie(nullptr);\n\
    \  std::ios_base::sync_with_stdio(false);\n\n  std::cout << \"Hello World\" <<\
    \ '\\n';\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\"\n\n\
    #include <iostream>\n#include \"tools/qcfium.hpp\"\n\nint main() {\n  std::cin.tie(nullptr);\n\
    \  std::ios_base::sync_with_stdio(false);\n\n  std::cout << \"Hello World\" <<\
    \ '\\n';\n  return 0;\n}\n"
  dependsOn:
  - tools/qcfium.hpp
  isVerificationFile: true
  path: tests/qcfium.test.cpp
  requiredBy: []
  timestamp: '2021-11-27 17:53:56+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/qcfium.test.cpp
layout: document
redirect_from:
- /verify/tests/qcfium.test.cpp
- /verify/tests/qcfium.test.cpp.html
title: tests/qcfium.test.cpp
---
