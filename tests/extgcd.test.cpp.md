---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: tools/extgcd.hpp
    title: Extended Euclidean algorithm
  - icon: ':question:'
    path: tools/quo.hpp
    title: Quotient as integer division
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/NTL_1_E
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/NTL_1_E
  bundledCode: "#line 1 \"tests/extgcd.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/NTL_1_E\"\
    \n\n#include <iostream>\n#line 1 \"tools/extgcd.hpp\"\n\n\n\n#include <tuple>\n\
    #include <utility>\n#line 1 \"tools/quo.hpp\"\n\n\n\n#include <type_traits>\n\n\
    namespace tools {\n\n  template <typename M, typename N>\n  constexpr ::std::common_type_t<M,\
    \ N> quo(const M lhs, const N rhs) {\n    using T = ::std::common_type_t<M, N>;\n\
    \    if (lhs >= M(0)) {\n      return lhs / rhs;\n    } else {\n      if (rhs\
    \ >= N(0)) {\n        return -((-lhs - T(1) + rhs) / rhs);\n      } else {\n \
    \       return (-lhs - T(1) + -rhs) / -rhs;\n      }\n    }\n  }\n}\n\n\n#line\
    \ 7 \"tools/extgcd.hpp\"\n\nnamespace tools {\n\n  template <typename T>\n  ::std::tuple<T,\
    \ T, T> extgcd(T prev_r, T r) {\n    T prev_s(1);\n    T prev_t(0);\n    T s(0);\n\
    \    T t(1);\n    while (r != T(0)) {\n      const T q = ::tools::quo(prev_r,\
    \ r);\n      ::std::tie(prev_r, r) = ::std::make_pair(r, prev_r - q * r);\n  \
    \    ::std::tie(prev_s, s) = ::std::make_pair(s, prev_s - q * s);\n      ::std::tie(prev_t,\
    \ t) = ::std::make_pair(t, prev_t - q * t);\n    }\n\n    if (prev_r < T(0)) prev_r\
    \ = -prev_r;\n    return ::std::make_tuple(prev_s, prev_t, prev_r);\n  }\n}\n\n\
    \n#line 5 \"tests/extgcd.test.cpp\"\n\nusing ll = long long;\n\nint main() {\n\
    \  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\n  ll a,\
    \ b;\n  std::cin >> a >> b;\n\n  const auto [x0, y0, gcd] = tools::extgcd(a, b);\n\
    \  std::cout << x0 << ' ' << y0 << '\\n';\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/NTL_1_E\"\n\n\
    #include <iostream>\n#include \"tools/extgcd.hpp\"\n\nusing ll = long long;\n\n\
    int main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  ll a, b;\n  std::cin >> a >> b;\n\n  const auto [x0, y0, gcd] = tools::extgcd(a,\
    \ b);\n  std::cout << x0 << ' ' << y0 << '\\n';\n\n  return 0;\n}\n"
  dependsOn:
  - tools/extgcd.hpp
  - tools/quo.hpp
  isVerificationFile: true
  path: tests/extgcd.test.cpp
  requiredBy: []
  timestamp: '2023-08-20 17:29:18+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: tests/extgcd.test.cpp
layout: document
redirect_from:
- /verify/tests/extgcd.test.cpp
- /verify/tests/extgcd.test.cpp.html
title: tests/extgcd.test.cpp
---
