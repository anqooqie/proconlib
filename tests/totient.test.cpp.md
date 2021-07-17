---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/is_prime.hpp
    title: Miller-Rabin primality test
  - icon: ':heavy_check_mark:'
    path: tools/mod.hpp
    title: Minimum non-negative reminder
  - icon: ':heavy_check_mark:'
    path: tools/monoid.hpp
    title: Typical monoids
  - icon: ':heavy_check_mark:'
    path: tools/pow.hpp
    title: $b^n$ under a given monoid
  - icon: ':heavy_check_mark:'
    path: tools/pow_mod.hpp
    title: $x^y \pmod{M}$
  - icon: ':heavy_check_mark:'
    path: tools/prime_factorization.hpp
    title: Pollard's rho algorithm
  - icon: ':heavy_check_mark:'
    path: tools/prod_mod.hpp
    title: $x \cdot y \pmod{M}$
  - icon: ':heavy_check_mark:'
    path: tools/quo.hpp
    title: Quotient as integer division
  - icon: ':heavy_check_mark:'
    path: tools/square.hpp
    title: $x^2$ under a given monoid
  - icon: ':heavy_check_mark:'
    path: tools/totient.hpp
    title: Euler's totient function
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/NTL_1_D
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/NTL_1_D
  bundledCode: "#line 1 \"tests/totient.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/NTL_1_D\"\
    \n\n#include <cstdint>\n#include <iostream>\n#line 1 \"tools/totient.hpp\"\n\n\
    \n\n#include <cassert>\n#line 1 \"tools/prime_factorization.hpp\"\n\n\n\n#include\
    \ <map>\n#line 6 \"tools/prime_factorization.hpp\"\n#include <random>\n#include\
    \ <queue>\n#include <numeric>\n#include <cmath>\n#line 1 \"tools/is_prime.hpp\"\
    \n\n\n\n#line 5 \"tools/is_prime.hpp\"\n#include <array>\n#line 1 \"tools/prod_mod.hpp\"\
    \n\n\n\nnamespace tools {\n\n  template <typename T1, typename T2, typename T3>\n\
    \  constexpr T3 prod_mod(const T1 x, const T2 y, const T3 m) {\n    using u128\
    \ = unsigned __int128;\n    u128 prod_mod = u128(x >= 0 ? x : -x) * u128(y >=\
    \ 0 ? y : -y) % u128(m);\n    if (((x >= 0) ^ (y >= 0)) == 1) prod_mod = u128(m)\
    \ - prod_mod;\n    return prod_mod;\n  }\n}\n\n\n#line 1 \"tools/pow_mod.hpp\"\
    \n\n\n\n#line 1 \"tools/mod.hpp\"\n\n\n\n#include <type_traits>\n#line 1 \"tools/quo.hpp\"\
    \n\n\n\n#line 5 \"tools/quo.hpp\"\n\nnamespace tools {\n\n  template <typename\
    \ M, typename N>\n  constexpr ::std::common_type_t<M, N> quo(const M lhs, const\
    \ N rhs) {\n    if (lhs >= 0) {\n      return lhs / rhs;\n    } else {\n     \
    \ if (rhs >= 0) {\n        return -((-lhs - 1 + rhs) / rhs);\n      } else {\n\
    \        return (-lhs - 1 + -rhs) / -rhs;\n      }\n    }\n  }\n}\n\n\n#line 6\
    \ \"tools/mod.hpp\"\n\nnamespace tools {\n\n  template <typename M, typename N>\n\
    \  constexpr ::std::common_type_t<M, N> mod(const M lhs, const N rhs) {\n    if\
    \ constexpr (::std::is_unsigned_v<M> && ::std::is_unsigned_v<N>) {\n      return\
    \ lhs % rhs;\n    } else {\n      return lhs - ::tools::quo(lhs, rhs) * rhs;\n\
    \    }\n  }\n}\n\n\n#line 6 \"tools/pow_mod.hpp\"\n\nnamespace tools {\n\n  template\
    \ <typename T1, typename T2, typename T3>\n  constexpr T3 pow_mod(const T1 x,\
    \ T2 n, const T3 m) {\n    if (m == 1) return 0;\n    T3 r = 1;\n    T3 y = ::tools::mod(x,\
    \ m);\n    while (n > 0) {\n      if ((n & 1) > 0) {\n        r = ::tools::prod_mod(r,\
    \ y, m);\n      }\n      y = ::tools::prod_mod(y, y, m);\n      n /= 2;\n    }\n\
    \    return r;\n  }\n}\n\n\n#line 8 \"tools/is_prime.hpp\"\n\nnamespace tools\
    \ {\n\n  constexpr bool is_prime(const ::std::uint_fast64_t n) {\n    constexpr\
    \ ::std::array<::std::uint_fast64_t, 7> bases = {2, 325, 9375, 28178, 450775,\
    \ 9780504, 1795265022};\n\n    if (n <= 1) return false;\n    if (n == 2) return\
    \ true;\n    if (n % 2 == 0) return false;\n\n    ::std::uint_fast64_t d = n -\
    \ 1;\n    for (; d % 2 == 0; d /= 2);\n\n    for (const ::std::uint_fast64_t a\
    \ : bases) {\n      if (a % n == 0) return true;\n\n      ::std::uint_fast64_t\
    \ power = d;\n      ::std::uint_fast64_t target = ::tools::pow_mod(a, power, n);\n\
    \n      bool is_composite = true;\n      if (target == 1) is_composite = false;\n\
    \      for (; is_composite && power != n - 1; power *= 2, target = ::tools::prod_mod(target,\
    \ target, n)) {\n        if (target == n - 1) is_composite = false;\n      }\n\
    \n      if (is_composite) {\n        return false;\n      }\n    }\n\n    return\
    \ true;\n  }\n}\n\n\n#line 12 \"tools/prime_factorization.hpp\"\n\nnamespace tools\
    \ {\n\n  template <typename T>\n  ::std::map<T, T> prime_factorization(T n) {\n\
    \    assert(1 <= n && n <= 1000000000000000000);\n    ::std::map<T, T> result;\n\
    \n    for (; n % 2 == 0; n /= 2) {\n      ++result[2];\n    }\n    if (n == 1)\
    \ return result;\n\n    ::std::minstd_rand engine;\n    ::std::queue<T> factors({n});\n\
    \    while (!factors.empty()) {\n      const T factor = factors.front();\n   \
    \   factors.pop();\n      if (::tools::is_prime(factor)) {\n        ++result[factor];\n\
    \      } else {\n        ::std::uniform_int_distribution<T> dist(1, factor - 2);\n\
    \        while (true) {\n          T c = dist(engine);\n          if (c == factor\
    \ - 2) c = factor - 1;\n          T x = 2;\n          T y = 2;\n          T d\
    \ = 1;\n          while (d == 1) {\n            x = ::tools::prod_mod(x, x, factor);\n\
    \            x += c;\n            if (x >= factor) x -= factor;\n            y\
    \ = ::tools::prod_mod(y, y, factor);\n            y += c;\n            if (y >=\
    \ factor) y -= factor;\n            y = ::tools::prod_mod(y, y, factor);\n   \
    \         y += c;\n            if (y >= factor) y -= factor;\n            d =\
    \ ::std::gcd(::std::abs(x - y), factor);\n          }\n          if (d < factor)\
    \ {\n            factors.push(d);\n            factors.push(factor / d);\n   \
    \         break;\n          }\n        }\n      }\n    }\n\n    return result;\n\
    \  }\n}\n\n\n#line 1 \"tools/pow.hpp\"\n\n\n\n#include <cstddef>\n#line 1 \"tools/monoid.hpp\"\
    \n\n\n\n#include <algorithm>\n#include <limits>\n#line 7 \"tools/monoid.hpp\"\n\
    \nnamespace tools {\n  namespace monoid {\n    template <typename Type, Type E\
    \ = ::std::numeric_limits<Type>::min()>\n    struct max {\n      using T = Type;\n\
    \      static T op(const T lhs, const T rhs) {\n        return ::std::max(lhs,\
    \ rhs);\n      }\n      static T e() {\n        return E;\n      }\n    };\n\n\
    \    template <typename Type, Type E = ::std::numeric_limits<Type>::max()>\n \
    \   struct min {\n      using T = Type;\n      static T op(const T lhs, const\
    \ T rhs) {\n        return ::std::min(lhs, rhs);\n      }\n      static T e()\
    \ {\n        return E;\n      }\n    };\n\n    template <typename Type>\n    struct\
    \ multiplies {\n      using T = Type;\n      static T op(const T lhs, const T\
    \ rhs) {\n        return lhs * rhs;\n      }\n      static T e() {\n        return\
    \ T(1);\n      }\n    };\n\n    template <typename Type>\n    struct gcd {\n \
    \     using T = Type;\n      static T op(const T lhs, const T rhs) {\n       \
    \ return ::std::gcd(lhs, rhs);\n      }\n      static T e() {\n        return\
    \ T(0);\n      }\n    };\n\n    template <typename Type, Type E>\n    struct update\
    \ {\n      using T = Type;\n      static T op(const T lhs, const T rhs) {\n  \
    \      return lhs == E ? rhs : lhs;\n      }\n      static T e() {\n        return\
    \ E;\n      }\n    };\n  }\n}\n\n\n#line 1 \"tools/square.hpp\"\n\n\n\n#line 5\
    \ \"tools/square.hpp\"\n\nnamespace tools {\n\n  template <typename M>\n  typename\
    \ M::T square(const typename M::T& x) {\n    return M::op(x, x);\n  }\n\n  template\
    \ <typename T>\n  T square(const T& x) {\n    return ::tools::square<::tools::monoid::multiplies<T>>(x);\n\
    \  }\n}\n\n\n#line 7 \"tools/pow.hpp\"\n\nnamespace tools {\n\n  template <typename\
    \ M>\n  typename M::T pow(const typename M::T& base, const ::std::size_t& exponent)\
    \ {\n    return exponent == 0\n      ? M::e()\n      : exponent % 2 == 0\n   \
    \     ? ::tools::square<M>(::tools::pow<M>(base, exponent / 2))\n        : M::op(::tools::pow<M>(base,\
    \ exponent - 1), base);\n  }\n\n  template <typename T>\n  T pow(const T& base,\
    \ const ::std::size_t& exponent) {\n    return ::tools::pow<::tools::monoid::multiplies<T>>(base,\
    \ exponent);\n  }\n}\n\n\n#line 7 \"tools/totient.hpp\"\n\nnamespace tools {\n\
    \n  template <typename T>\n  T totient(const T& x) {\n    assert(1 <= x && x <=\
    \ 1000000000000000000);\n    T prod = 1;\n    for (const auto& [distinct_prime_factor,\
    \ exponent] : ::tools::prime_factorization(x)) {\n      prod *= ::tools::pow(distinct_prime_factor,\
    \ exponent - 1) * (distinct_prime_factor - 1);\n    }\n    return prod;\n  }\n\
    }\n\n\n#line 6 \"tests/totient.test.cpp\"\n\nusing i64 = std::int_fast64_t;\n\n\
    int main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  i64 n;\n  std::cin >> n;\n  std::cout << tools::totient(n) << '\\n';\n  return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/NTL_1_D\"\n\n\
    #include <cstdint>\n#include <iostream>\n#include \"tools/totient.hpp\"\n\nusing\
    \ i64 = std::int_fast64_t;\n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  i64 n;\n  std::cin >> n;\n  std::cout << tools::totient(n) << '\\n';\n  return\
    \ 0;\n}\n"
  dependsOn:
  - tools/totient.hpp
  - tools/prime_factorization.hpp
  - tools/is_prime.hpp
  - tools/prod_mod.hpp
  - tools/pow_mod.hpp
  - tools/mod.hpp
  - tools/quo.hpp
  - tools/pow.hpp
  - tools/monoid.hpp
  - tools/square.hpp
  isVerificationFile: true
  path: tests/totient.test.cpp
  requiredBy: []
  timestamp: '2021-07-17 23:00:45+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/totient.test.cpp
layout: document
redirect_from:
- /verify/tests/totient.test.cpp
- /verify/tests/totient.test.cpp.html
title: tests/totient.test.cpp
---
