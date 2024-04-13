---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: tools/abs.hpp
    title: std::abs(x) extended for my library
  - icon: ':question:'
    path: tools/extgcd.hpp
    title: Extended Euclidean algorithm
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
    \n\n#include <iostream>\n#line 1 \"tools/extgcd.hpp\"\n\n\n\n#include <tuple>\n\
    #include <utility>\n#include <cassert>\n#include <algorithm>\n#line 1 \"tools/abs.hpp\"\
    \n\n\n\nnamespace tools {\n  constexpr float abs(const float x) {\n    return\
    \ x < 0 ? -x : x;\n  }\n  constexpr double abs(const double x) {\n    return x\
    \ < 0 ? -x : x;\n  }\n  constexpr long double abs(const long double x) {\n   \
    \ return x < 0 ? -x : x;\n  }\n  constexpr int abs(const int x) {\n    return\
    \ x < 0 ? -x : x;\n  }\n  constexpr long abs(const long x) {\n    return x < 0\
    \ ? -x : x;\n  }\n  constexpr long long abs(const long long x) {\n    return x\
    \ < 0 ? -x : x;\n  }\n  constexpr unsigned int abs(const unsigned int x) {\n \
    \   return x;\n  }\n  constexpr unsigned long abs(const unsigned long x) {\n \
    \   return x;\n  }\n  constexpr unsigned long long abs(const unsigned long long\
    \ x) {\n    return x;\n  }\n}\n\n\n#line 9 \"tools/extgcd.hpp\"\n\nnamespace tools\
    \ {\n\n  template <typename T>\n  ::std::tuple<T, T, T> extgcd(T prev_r, T r)\
    \ {\n    const bool prev_r_is_neg = prev_r < T(0);\n    const bool r_is_neg =\
    \ r < T(0);\n\n    if (prev_r_is_neg) prev_r = -prev_r;\n    if (r_is_neg) r =\
    \ -r;\n\n    #ifndef NDEBUG\n    const T a = prev_r;\n    const T b = r;\n   \
    \ #endif\n\n    T prev_s(1);\n    T prev_t(0);\n    T s(0);\n    T t(1);\n   \
    \ while (r != T(0)) {\n      const T q = prev_r / r;\n      ::std::tie(prev_r,\
    \ r) = ::std::make_pair(r, prev_r - q * r);\n      ::std::tie(prev_s, s) = ::std::make_pair(s,\
    \ prev_s - q * s);\n      ::std::tie(prev_t, t) = ::std::make_pair(t, prev_t -\
    \ q * t);\n    }\n\n    if (prev_r_is_neg) prev_s = -prev_s;\n    if (r_is_neg)\
    \ prev_t = -prev_t;\n\n    assert(::tools::abs(prev_s) <= ::std::max(b / prev_r\
    \ / T(2), T(1)));\n    assert(::tools::abs(prev_t) <= ::std::max(a / prev_r /\
    \ T(2), T(1)));\n    return ::std::make_tuple(prev_s, prev_t, prev_r);\n  }\n\
    }\n\n\n#line 5 \"tests/extgcd.test.cpp\"\n\nusing ll = long long;\n\nint main()\
    \ {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\n  ll\
    \ a, b;\n  std::cin >> a >> b;\n\n  const auto [x0, y0, gcd] = tools::extgcd(a,\
    \ b);\n  std::cout << x0 << ' ' << y0 << '\\n';\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/NTL_1_E\"\n\n\
    #include <iostream>\n#include \"tools/extgcd.hpp\"\n\nusing ll = long long;\n\n\
    int main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  ll a, b;\n  std::cin >> a >> b;\n\n  const auto [x0, y0, gcd] = tools::extgcd(a,\
    \ b);\n  std::cout << x0 << ' ' << y0 << '\\n';\n\n  return 0;\n}\n"
  dependsOn:
  - tools/extgcd.hpp
  - tools/abs.hpp
  isVerificationFile: true
  path: tests/extgcd.test.cpp
  requiredBy: []
  timestamp: '2023-08-26 14:07:16+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/extgcd.test.cpp
layout: document
redirect_from:
- /verify/tests/extgcd.test.cpp
- /verify/tests/extgcd.test.cpp.html
title: tests/extgcd.test.cpp
---
