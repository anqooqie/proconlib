---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/lcm_convolution.hpp
    title: LCM convolution
  - icon: ':heavy_check_mark:'
    path: tools/osa_k.hpp
    title: osa_k's algorithm
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/lcm_convolution
    links:
    - https://judge.yosupo.jp/problem/lcm_convolution
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ tools/lcm_convolution.hpp: line 9: unable to process #include in #if / #ifdef\
    \ / #ifndef other than include guards\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lcm_convolution\"\n\n#include\
    \ <iostream>\n#include <cstdint>\n#include <vector>\n#include <string>\n#include\
    \ \"atcoder/modint.hpp\"\n#include \"tools/lcm_convolution.hpp\"\n\nusing i64\
    \ = std::int_fast64_t;\nusing mint = atcoder::modint998244353;\n\nint main() {\n\
    \  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\n  i64 N;\n\
    \  std::cin >> N;\n  std::vector<mint> a(N + 1), b(N + 1);\n  for (i64 i = 1;\
    \ i <= N; ++i) {\n    i64 a_i;\n    std::cin >> a_i;\n    a[i] = mint::raw(a_i);\n\
    \  }\n  for (i64 i = 1; i <= N; ++i) {\n    i64 b_i;\n    std::cin >> b_i;\n \
    \   b[i] = mint::raw(b_i);\n  }\n\n  std::vector<mint> c(N + 1);\n  tools::lcm_convolution(a.begin(),\
    \ a.end(), b.begin(), b.end(), c.begin(), c.end());\n\n  std::string delimiter\
    \ = \"\";\n  for (i64 i = 1; i <= N; ++i) {\n    std::cout << delimiter << c[i].val();\n\
    \    delimiter = \" \";\n  }\n  std::cout << '\\n';\n\n  return 0;\n}\n"
  dependsOn:
  - tools/lcm_convolution.hpp
  - tools/osa_k.hpp
  isVerificationFile: true
  path: tests/lcm_convolution.test.cpp
  requiredBy: []
  timestamp: '2022-09-11 13:33:11+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/lcm_convolution.test.cpp
layout: document
redirect_from:
- /verify/tests/lcm_convolution.test.cpp
- /verify/tests/lcm_convolution.test.cpp.html
title: tests/lcm_convolution.test.cpp
---
