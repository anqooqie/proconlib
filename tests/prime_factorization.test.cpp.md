---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/is_prime.hpp
    title: Primality test
  - icon: ':heavy_check_mark:'
    path: tools/mod.hpp
    title: Minimum non-negative reminder
  - icon: ':heavy_check_mark:'
    path: tools/pow_mod.hpp
    title: $x^y \pmod{M}$
  - icon: ':heavy_check_mark:'
    path: tools/prime_factorization.hpp
    title: Prime factorization
  - icon: ':heavy_check_mark:'
    path: tools/prod_mod.hpp
    title: $x \cdot y \pmod{M}$
  - icon: ':heavy_check_mark:'
    path: tools/quo.hpp
    title: Quotient as integer division
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/factorize
    links:
    - https://judge.yosupo.jp/problem/factorize
  bundledCode: "#line 1 \"tests/prime_factorization.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/factorize\"\n\n#include <cstdint>\n#include <iostream>\n\
    #include <vector>\n#include <iterator>\n#include <algorithm>\n#line 1 \"tools/prime_factorization.hpp\"\
    \n\n\n\n#include <cassert>\n#line 6 \"tools/prime_factorization.hpp\"\n#include\
    \ <random>\n#include <queue>\n#include <numeric>\n#include <cmath>\n#line 1 \"\
    tools/is_prime.hpp\"\n\n\n\n#line 5 \"tools/is_prime.hpp\"\n#include <array>\n\
    #line 1 \"tools/prod_mod.hpp\"\n\n\n\nnamespace tools {\n\n  template <typename\
    \ T1, typename T2, typename T3>\n  constexpr T3 prod_mod(const T1 x, const T2\
    \ y, const T3 m) {\n    using u128 = unsigned __int128;\n    u128 prod_mod = u128(x\
    \ >= 0 ? x : -x) * u128(y >= 0 ? y : -y) % u128(m);\n    if (((x >= 0) ^ (y >=\
    \ 0)) == 1) prod_mod = u128(m) - prod_mod;\n    return prod_mod;\n  }\n}\n\n\n\
    #line 1 \"tools/pow_mod.hpp\"\n\n\n\n#line 1 \"tools/mod.hpp\"\n\n\n\n#include\
    \ <type_traits>\n#line 1 \"tools/quo.hpp\"\n\n\n\n#line 5 \"tools/quo.hpp\"\n\n\
    namespace tools {\n\n  template <typename M, typename N>\n  constexpr ::std::common_type_t<M,\
    \ N> quo(const M lhs, const N rhs) {\n    if (lhs >= 0) {\n      return lhs /\
    \ rhs;\n    } else {\n      if (rhs >= 0) {\n        return -((-lhs - 1 + rhs)\
    \ / rhs);\n      } else {\n        return (-lhs - 1 + -rhs) / -rhs;\n      }\n\
    \    }\n  }\n}\n\n\n#line 6 \"tools/mod.hpp\"\n\nnamespace tools {\n\n  template\
    \ <typename M, typename N>\n  constexpr ::std::common_type_t<M, N> mod(const M\
    \ lhs, const N rhs) {\n    if constexpr (::std::is_unsigned_v<M> && ::std::is_unsigned_v<N>)\
    \ {\n      return lhs % rhs;\n    } else {\n      return lhs - ::tools::quo(lhs,\
    \ rhs) * rhs;\n    }\n  }\n}\n\n\n#line 6 \"tools/pow_mod.hpp\"\n\nnamespace tools\
    \ {\n\n  template <typename T1, typename T2, typename T3>\n  constexpr T3 pow_mod(const\
    \ T1 x, T2 n, const T3 m) {\n    if (m == 1) return 0;\n    T3 r = 1;\n    T3\
    \ y = ::tools::mod(x, m);\n    while (n > 0) {\n      if ((n & 1) > 0) {\n   \
    \     r = ::tools::prod_mod(r, y, m);\n      }\n      y = ::tools::prod_mod(y,\
    \ y, m);\n      n /= 2;\n    }\n    return r;\n  }\n}\n\n\n#line 8 \"tools/is_prime.hpp\"\
    \n\nnamespace tools {\n\n  constexpr bool is_prime(const ::std::uint_fast64_t\
    \ n) {\n    constexpr ::std::array<::std::uint_fast64_t, 7> bases = {2, 325, 9375,\
    \ 28178, 450775, 9780504, 1795265022};\n\n    if (n <= 1) return false;\n    if\
    \ (n == 2) return true;\n    if (n % 2 == 0) return false;\n\n    ::std::uint_fast64_t\
    \ d = n - 1;\n    for (; d % 2 == 0; d /= 2);\n\n    for (const ::std::uint_fast64_t\
    \ a : bases) {\n      if (a % n == 0) return true;\n\n      ::std::uint_fast64_t\
    \ power = d;\n      ::std::uint_fast64_t target = ::tools::pow_mod(a, power, n);\n\
    \n      bool is_composite = true;\n      if (target == 1) is_composite = false;\n\
    \      for (; is_composite && power != n - 1; power *= 2, target = ::tools::prod_mod(target,\
    \ target, n)) {\n        if (target == n - 1) is_composite = false;\n      }\n\
    \n      if (is_composite) {\n        return false;\n      }\n    }\n\n    return\
    \ true;\n  }\n}\n\n\n#line 13 \"tools/prime_factorization.hpp\"\n\nnamespace tools\
    \ {\n\n  template <typename T, typename OutputIterator>\n  void prime_factorization(T\
    \ n, OutputIterator result) {\n    assert(1 <= n && n <= 1000000000000000000);\n\
    \    ::std::vector<T> prime_factors;\n\n    for (; n % 2 == 0; n /= 2) {\n   \
    \   *result = 2;\n      ++result;\n    }\n    if (n == 1) return;\n\n    ::std::minstd_rand\
    \ engine;\n    ::std::queue<T> factors({n});\n    while (!factors.empty()) {\n\
    \      const T factor = factors.front();\n      factors.pop();\n      if (::tools::is_prime(factor))\
    \ {\n        prime_factors.push_back(factor);\n      } else {\n        ::std::uniform_int_distribution<T>\
    \ dist(1, factor - 2);\n        while (true) {\n          T c = dist(engine);\n\
    \          if (c == factor - 2) c = factor - 1;\n          T x = 2;\n        \
    \  T y = 2;\n          T d = 1;\n          while (d == 1) {\n            x = ::tools::prod_mod(x,\
    \ x, factor);\n            x += c;\n            if (x >= factor) x -= factor;\n\
    \            y = ::tools::prod_mod(y, y, factor);\n            y += c;\n     \
    \       if (y >= factor) y -= factor;\n            y = ::tools::prod_mod(y, y,\
    \ factor);\n            y += c;\n            if (y >= factor) y -= factor;\n \
    \           d = ::std::gcd(::std::abs(x - y), factor);\n          }\n        \
    \  if (d < factor) {\n            factors.push(d);\n            factors.push(factor\
    \ / d);\n            break;\n          }\n        }\n      }\n    }\n\n    ::std::sort(prime_factors.begin(),\
    \ prime_factors.end());\n    for (const T& prime_factor : prime_factors) {\n \
    \     *result = prime_factor;\n      ++result;\n    }\n  }\n}\n\n\n#line 9 \"\
    tests/prime_factorization.test.cpp\"\n\nusing i64 = std::int_fast64_t;\n\nint\
    \ main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  i64 Q;\n  std::cin >> Q;\n  for (i64 i = 0; i < Q; ++i) {\n    i64 a_i;\n\
    \    std::cin >> a_i;\n\n    std::vector<i64> prime_factors;\n    tools::prime_factorization(a_i,\
    \ std::back_inserter(prime_factors));\n    std::cout << prime_factors.size();\n\
    \    for (const i64& prime_factor : prime_factors) {\n      std::cout << ' ' <<\
    \ prime_factor;\n    }\n    std::cout << '\\n';\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/factorize\"\n\n#include\
    \ <cstdint>\n#include <iostream>\n#include <vector>\n#include <iterator>\n#include\
    \ <algorithm>\n#include \"tools/prime_factorization.hpp\"\n\nusing i64 = std::int_fast64_t;\n\
    \nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  i64 Q;\n  std::cin >> Q;\n  for (i64 i = 0; i < Q; ++i) {\n    i64 a_i;\n\
    \    std::cin >> a_i;\n\n    std::vector<i64> prime_factors;\n    tools::prime_factorization(a_i,\
    \ std::back_inserter(prime_factors));\n    std::cout << prime_factors.size();\n\
    \    for (const i64& prime_factor : prime_factors) {\n      std::cout << ' ' <<\
    \ prime_factor;\n    }\n    std::cout << '\\n';\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - tools/prime_factorization.hpp
  - tools/is_prime.hpp
  - tools/prod_mod.hpp
  - tools/pow_mod.hpp
  - tools/mod.hpp
  - tools/quo.hpp
  isVerificationFile: true
  path: tests/prime_factorization.test.cpp
  requiredBy: []
  timestamp: '2021-03-29 00:30:01+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/prime_factorization.test.cpp
layout: document
redirect_from:
- /verify/tests/prime_factorization.test.cpp
- /verify/tests/prime_factorization.test.cpp.html
title: tests/prime_factorization.test.cpp
---
