---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/extgcd.hpp
    title: Extended Euclidean algorithm
  - icon: ':question:'
    path: tools/quo.hpp
    title: Quotient as integer division
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/NTL_1_E
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/NTL_1_E
  bundledCode: "#line 1 \"tests/extgcd.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/NTL_1_E\"\
    \n\n#include <cstdint>\n#include <iostream>\n#line 1 \"tools/extgcd.hpp\"\n\n\n\
    \n#include <tuple>\n#line 1 \"tools/quo.hpp\"\n\n\n\n#include <type_traits>\n\n\
    namespace tools {\n\n  template <typename M, typename N>\n  constexpr ::std::common_type_t<M,\
    \ N> quo(const M lhs, const N rhs) {\n    if (lhs >= 0) {\n      return lhs /\
    \ rhs;\n    } else {\n      if (rhs >= 0) {\n        return -((-lhs - 1 + rhs)\
    \ / rhs);\n      } else {\n        return (-lhs - 1 + -rhs) / -rhs;\n      }\n\
    \    }\n  }\n}\n\n\n#line 6 \"tools/extgcd.hpp\"\n\nnamespace tools {\n\n  template\
    \ <typename T>\n  ::std::tuple<T, T, T> extgcd(T prev_r, T r) {\n    T prev_s\
    \ = 1;\n    T prev_t = 0;\n    T s = 0;\n    T t = 1;\n    while (r != 0) {\n\
    \      const T q = ::tools::quo(prev_r, r);\n      const T next_r = prev_r - q\
    \ * r;\n      prev_r = r;\n      r = next_r;\n      const T next_s = prev_s -\
    \ q * s;\n      prev_s = s;\n      s = next_s;\n      const T next_t = prev_t\
    \ - q * t;\n      prev_t = t;\n      t = next_t;\n    }\n\n    if (prev_r < T(0))\
    \ prev_r = -prev_r;\n    return {prev_s, prev_t, prev_r};\n  }\n}\n\n\n#line 6\
    \ \"tests/extgcd.test.cpp\"\n\nusing i64 = std::int_fast64_t;\n\nint main() {\n\
    \  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\n  i64 a,\
    \ b;\n  std::cin >> a >> b;\n\n  const auto [x0, y0, gcd] = tools::extgcd(a, b);\n\
    \  std::cout << x0 << ' ' << y0 << '\\n';\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/NTL_1_E\"\n\n\
    #include <cstdint>\n#include <iostream>\n#include \"tools/extgcd.hpp\"\n\nusing\
    \ i64 = std::int_fast64_t;\n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  i64 a, b;\n  std::cin >> a >> b;\n\n  const auto [x0, y0, gcd] = tools::extgcd(a,\
    \ b);\n  std::cout << x0 << ' ' << y0 << '\\n';\n\n  return 0;\n}\n"
  dependsOn:
  - tools/extgcd.hpp
  - tools/quo.hpp
  isVerificationFile: true
  path: tests/extgcd.test.cpp
  requiredBy: []
  timestamp: '2021-03-29 00:30:01+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/extgcd.test.cpp
layout: document
redirect_from:
- /verify/tests/extgcd.test.cpp
- /verify/tests/extgcd.test.cpp.html
title: tests/extgcd.test.cpp
---
