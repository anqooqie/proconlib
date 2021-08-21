---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/extgcd.hpp
    title: Extended Euclidean algorithm
  - icon: ':heavy_check_mark:'
    path: tools/garner.hpp
    title: Garner's algorithm
  - icon: ':heavy_check_mark:'
    path: tools/inv_mod.hpp
    title: $x^{-1} \pmod{M}$
  - icon: ':heavy_check_mark:'
    path: tools/is_prime.hpp
    title: Miller-Rabin primality test
  - icon: ':heavy_check_mark:'
    path: tools/mod.hpp
    title: Minimum non-negative reminder
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
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/extended_lucas.test.cpp
    title: tests/extended_lucas.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://w.atwiki.jp/uwicoder/pages/2118.html#id_6779f709
  bundledCode: "#line 1 \"tools/extended_lucas.hpp\"\n\n\n\n#include <vector>\n#include\
    \ <cstdint>\n#include <cassert>\n#include <utility>\n#line 1 \"tools/prime_factorization.hpp\"\
    \n\n\n\n#include <map>\n#line 6 \"tools/prime_factorization.hpp\"\n#include <random>\n\
    #include <queue>\n#include <numeric>\n#include <cmath>\n#line 1 \"tools/is_prime.hpp\"\
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
    \  }\n}\n\n\n#line 1 \"tools/garner.hpp\"\n\n\n\n#line 7 \"tools/garner.hpp\"\n\
    #include <cstddef>\n#line 1 \"tools/inv_mod.hpp\"\n\n\n\n#line 1 \"tools/extgcd.hpp\"\
    \n\n\n\n#include <tuple>\n#line 6 \"tools/extgcd.hpp\"\n\nnamespace tools {\n\n\
    \  template <typename T>\n  ::std::tuple<T, T, T> extgcd(T prev_r, T r) {\n  \
    \  T prev_s = 1;\n    T prev_t = 0;\n    T s = 0;\n    T t = 1;\n    while (r\
    \ != 0) {\n      const T q = ::tools::quo(prev_r, r);\n      const T next_r =\
    \ prev_r - q * r;\n      prev_r = r;\n      r = next_r;\n      const T next_s\
    \ = prev_s - q * s;\n      prev_s = s;\n      s = next_s;\n      const T next_t\
    \ = prev_t - q * t;\n      prev_t = t;\n      t = next_t;\n    }\n\n    if (prev_r\
    \ < T(0)) prev_r = -prev_r;\n    return {prev_s, prev_t, prev_r};\n  }\n}\n\n\n\
    #line 7 \"tools/inv_mod.hpp\"\n\nnamespace tools {\n\n  template <typename T1,\
    \ typename T2>\n  constexpr T2 inv_mod(const T1 x, const T2 m) {\n    const auto\
    \ [x0, y0, gcd] = ::tools::extgcd(x, m);\n    assert(gcd == 1);\n    return ::tools::mod(x0,\
    \ m);\n  }\n}\n\n\n#line 10 \"tools/garner.hpp\"\n\n// Source: https://qiita.com/drken/items/ae02240cd1f8edfc86fd\n\
    // License: unknown\n// Author: drken\n\nnamespace tools {\n\n  template <typename\
    \ Iterator, typename ModType>\n  ::std::pair<::std::int_fast64_t, ::std::int_fast64_t>\
    \ garner(const Iterator& begin, const Iterator& end, const ModType& mod) {\n \
    \   ::std::vector<::std::int_fast64_t> b, m;\n    for (auto it = begin; it !=\
    \ end; ++it) {\n      b.push_back(::tools::mod(it->first, it->second));\n    \
    \  m.push_back(it->second);\n    }\n\n    ::std::int_fast64_t lcm = 1;\n    for\
    \ (::std::size_t i = 0; i < b.size(); ++i) {\n      (lcm *= m[i]) %= mod;\n  \
    \  }\n\n    m.push_back(mod);\n    ::std::vector<::std::int_fast64_t> coeffs(m.size(),\
    \ 1);\n    ::std::vector<::std::int_fast64_t> constants(m.size(), 0);\n    for\
    \ (::std::size_t k = 0; k < b.size(); ++k) {\n      ::std::int_fast64_t t = ::tools::mod((b[k]\
    \ - constants[k]) * ::tools::inv_mod(coeffs[k], m[k]), m[k]);\n      for (::std::size_t\
    \ i = k + 1; i < m.size(); ++i) {\n        (constants[i] += t * coeffs[i]) %=\
    \ m[i];\n        (coeffs[i] *= m[k]) %= m[i];\n      }\n    }\n\n    return ::std::make_pair(constants.back(),\
    \ lcm);\n  }\n\n  template <typename M, typename Iterator>\n  ::std::pair<M, M>\
    \ garner(const Iterator& begin, const Iterator& end) {\n    const auto [y, z]\
    \ = ::tools::garner(begin, end, M::mod());\n    return ::std::make_pair(M::raw(y),\
    \ M::raw(z));\n  }\n}\n\n\n#line 10 \"tools/extended_lucas.hpp\"\n\nnamespace\
    \ tools {\n\n  // Source: https://w.atwiki.jp/uwicoder/pages/2118.html#id_6779f709\n\
    \  // License: unknown\n  // Author: uwi\n\n  template <class M>\n  class extended_lucas\
    \ {\n  private:\n    class prime_power {\n    private:\n      ::std::vector<::std::int_fast64_t>\
    \ fact;\n      ::std::vector<::std::int_fast64_t> ifact;\n\n    public:\n    \
    \  ::std::int_fast64_t p;\n      ::std::int_fast64_t q;\n      ::std::int_fast64_t\
    \ P;\n\n      prime_power(const ::std::int_fast64_t p, const ::std::int_fast64_t\
    \ q) : p(p), q(q) {\n        this->P = 1;\n        for (::std::int_fast64_t i\
    \ = 0; i < q; ++i) {\n          this->P *= p;\n        }\n\n        this->fact.resize(this->P\
    \ + 1);\n        this->ifact.resize(this->P + 1);\n\n        this->fact[0] = 1\
    \ % this->P;\n        for (::std::int_fast64_t i = 1; i <= this->P; ++i) {\n \
    \         this->fact[i] = this->fact[i - 1] * (i % p == 0 ? 1 : i) % this->P;\n\
    \        }\n        for (::std::int_fast64_t i = 0; i <= this->P; ++i) {\n   \
    \       ::std::int_fast64_t ret = 1 % this->P;\n          ::std::int_fast64_t\
    \ mul = this->fact[i];\n          for (::std::int_fast64_t n = this->P / p * (p\
    \ - 1) - 1; n > 0; n /= 2) {\n            if ((n & 1) == 1) {\n              ret\
    \ = (ret * mul) % P;\n            }\n            mul = (mul * mul) % P;\n    \
    \      }\n          this->ifact[i] = ret;\n        }\n      }\n\n      ::std::int_fast64_t\
    \ combination(::std::int_fast64_t n, ::std::int_fast64_t r) const {\n        assert(0\
    \ <= r && r <= n);\n\n        ::std::int_fast64_t z = n - r;\n        ::std::int_fast64_t\
    \ e0 = 0;\n        for (::std::int_fast64_t u = n / this->p; u > 0; u /= this->p)\
    \ e0 += u;\n        for (::std::int_fast64_t u = r / this->p; u > 0; u /= this->p)\
    \ e0 -= u;\n        for (::std::int_fast64_t u = z / this->p; u > 0; u /= this->p)\
    \ e0 -= u;\n \n        ::std::int_fast64_t em = 0;\n        for (::std::int_fast64_t\
    \ u = n / this->P; u > 0; u /= this->p) em += u;\n        for (::std::int_fast64_t\
    \ u = r / this->P; u > 0; u /= this->p) em -= u;\n        for (::std::int_fast64_t\
    \ u = z / this->P; u > 0; u /= this->p) em -= u;\n \n        ::std::int_fast64_t\
    \ ret = 1 % this->P;\n        while (n > 0) {\n          ret = ret * this->fact[n\
    \ % this->P] % this->P * this->ifact[r % this->P] % this->P * this->ifact[z %\
    \ this->P] % this->P;\n          n /= this->p;\n          r /= this->p;\n    \
    \      z /= this->p;\n        }\n        for (::std::int_fast64_t i = 0; i < e0;\
    \ ++i) {\n          ret = ret * this->p % this->P;\n        }\n        if (!(this->p\
    \ == 2 && this->q >= 3) && (em & 1) == 1) {\n          ret = (this->P - ret) %\
    \ this->P;\n        }\n        return ret;\n      }\n    };\n\n    ::std::vector<::tools::extended_lucas<M>::prime_power>\
    \ prime_powers;\n\n  public:\n    extended_lucas() {\n      for (const auto& [p,\
    \ q] : ::tools::prime_factorization(M::mod())) {\n        this->prime_powers.emplace_back(p,\
    \ q);\n      }\n    }\n    extended_lucas(const ::tools::extended_lucas<M>&) =\
    \ default;\n    extended_lucas(::tools::extended_lucas<M>&&) = default;\n    ~extended_lucas()\
    \ = default;\n    ::tools::extended_lucas<M>& operator=(const ::tools::extended_lucas<M>&)\
    \ = default;\n    ::tools::extended_lucas<M>& operator=(::tools::extended_lucas<M>&&)\
    \ = default;\n\n    M combination(const ::std::int_fast64_t n, const ::std::int_fast64_t\
    \ r) const {\n      if (n < 0 || r < 0 || r > n) return M::raw(0);\n\n      ::std::vector<std::pair<::std::int_fast64_t,\
    \ ::std::int_fast64_t>> answers;\n      answers.reserve(this->prime_powers.size());\n\
    \      for (const auto& prime_power : this->prime_powers) {\n        answers.emplace_back(prime_power.combination(n,\
    \ r), prime_power.P);\n      }\n\n      return ::tools::garner<M>(answers.begin(),\
    \ answers.end()).first;\n    }\n  };\n}\n\n\n"
  code: "#ifndef TOOLS_EXTENDED_LUCAS_HPP\n#define TOOLS_EXTENDED_LUCAS_HPP\n\n#include\
    \ <vector>\n#include <cstdint>\n#include <cassert>\n#include <utility>\n#include\
    \ \"tools/prime_factorization.hpp\"\n#include \"tools/garner.hpp\"\n\nnamespace\
    \ tools {\n\n  // Source: https://w.atwiki.jp/uwicoder/pages/2118.html#id_6779f709\n\
    \  // License: unknown\n  // Author: uwi\n\n  template <class M>\n  class extended_lucas\
    \ {\n  private:\n    class prime_power {\n    private:\n      ::std::vector<::std::int_fast64_t>\
    \ fact;\n      ::std::vector<::std::int_fast64_t> ifact;\n\n    public:\n    \
    \  ::std::int_fast64_t p;\n      ::std::int_fast64_t q;\n      ::std::int_fast64_t\
    \ P;\n\n      prime_power(const ::std::int_fast64_t p, const ::std::int_fast64_t\
    \ q) : p(p), q(q) {\n        this->P = 1;\n        for (::std::int_fast64_t i\
    \ = 0; i < q; ++i) {\n          this->P *= p;\n        }\n\n        this->fact.resize(this->P\
    \ + 1);\n        this->ifact.resize(this->P + 1);\n\n        this->fact[0] = 1\
    \ % this->P;\n        for (::std::int_fast64_t i = 1; i <= this->P; ++i) {\n \
    \         this->fact[i] = this->fact[i - 1] * (i % p == 0 ? 1 : i) % this->P;\n\
    \        }\n        for (::std::int_fast64_t i = 0; i <= this->P; ++i) {\n   \
    \       ::std::int_fast64_t ret = 1 % this->P;\n          ::std::int_fast64_t\
    \ mul = this->fact[i];\n          for (::std::int_fast64_t n = this->P / p * (p\
    \ - 1) - 1; n > 0; n /= 2) {\n            if ((n & 1) == 1) {\n              ret\
    \ = (ret * mul) % P;\n            }\n            mul = (mul * mul) % P;\n    \
    \      }\n          this->ifact[i] = ret;\n        }\n      }\n\n      ::std::int_fast64_t\
    \ combination(::std::int_fast64_t n, ::std::int_fast64_t r) const {\n        assert(0\
    \ <= r && r <= n);\n\n        ::std::int_fast64_t z = n - r;\n        ::std::int_fast64_t\
    \ e0 = 0;\n        for (::std::int_fast64_t u = n / this->p; u > 0; u /= this->p)\
    \ e0 += u;\n        for (::std::int_fast64_t u = r / this->p; u > 0; u /= this->p)\
    \ e0 -= u;\n        for (::std::int_fast64_t u = z / this->p; u > 0; u /= this->p)\
    \ e0 -= u;\n \n        ::std::int_fast64_t em = 0;\n        for (::std::int_fast64_t\
    \ u = n / this->P; u > 0; u /= this->p) em += u;\n        for (::std::int_fast64_t\
    \ u = r / this->P; u > 0; u /= this->p) em -= u;\n        for (::std::int_fast64_t\
    \ u = z / this->P; u > 0; u /= this->p) em -= u;\n \n        ::std::int_fast64_t\
    \ ret = 1 % this->P;\n        while (n > 0) {\n          ret = ret * this->fact[n\
    \ % this->P] % this->P * this->ifact[r % this->P] % this->P * this->ifact[z %\
    \ this->P] % this->P;\n          n /= this->p;\n          r /= this->p;\n    \
    \      z /= this->p;\n        }\n        for (::std::int_fast64_t i = 0; i < e0;\
    \ ++i) {\n          ret = ret * this->p % this->P;\n        }\n        if (!(this->p\
    \ == 2 && this->q >= 3) && (em & 1) == 1) {\n          ret = (this->P - ret) %\
    \ this->P;\n        }\n        return ret;\n      }\n    };\n\n    ::std::vector<::tools::extended_lucas<M>::prime_power>\
    \ prime_powers;\n\n  public:\n    extended_lucas() {\n      for (const auto& [p,\
    \ q] : ::tools::prime_factorization(M::mod())) {\n        this->prime_powers.emplace_back(p,\
    \ q);\n      }\n    }\n    extended_lucas(const ::tools::extended_lucas<M>&) =\
    \ default;\n    extended_lucas(::tools::extended_lucas<M>&&) = default;\n    ~extended_lucas()\
    \ = default;\n    ::tools::extended_lucas<M>& operator=(const ::tools::extended_lucas<M>&)\
    \ = default;\n    ::tools::extended_lucas<M>& operator=(::tools::extended_lucas<M>&&)\
    \ = default;\n\n    M combination(const ::std::int_fast64_t n, const ::std::int_fast64_t\
    \ r) const {\n      if (n < 0 || r < 0 || r > n) return M::raw(0);\n\n      ::std::vector<std::pair<::std::int_fast64_t,\
    \ ::std::int_fast64_t>> answers;\n      answers.reserve(this->prime_powers.size());\n\
    \      for (const auto& prime_power : this->prime_powers) {\n        answers.emplace_back(prime_power.combination(n,\
    \ r), prime_power.P);\n      }\n\n      return ::tools::garner<M>(answers.begin(),\
    \ answers.end()).first;\n    }\n  };\n}\n\n#endif\n"
  dependsOn:
  - tools/prime_factorization.hpp
  - tools/is_prime.hpp
  - tools/prod_mod.hpp
  - tools/pow_mod.hpp
  - tools/mod.hpp
  - tools/quo.hpp
  - tools/garner.hpp
  - tools/inv_mod.hpp
  - tools/extgcd.hpp
  isVerificationFile: false
  path: tools/extended_lucas.hpp
  requiredBy: []
  timestamp: '2021-08-22 01:33:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/extended_lucas.test.cpp
documentation_of: tools/extended_lucas.hpp
layout: document
title: Extended Lucas' theorem
---

It precomputes ${}_n C_r \pmod{M}$ for any $n$ and $r$.

### References
- [nCr mod mの求め方 - uwicoder - atwiki（アットウィキ）](https://w.atwiki.jp/uwicoder/pages/2118.html#id_6779f709)

### License
- unknown

### Author
- uwi

## Constructor
```cpp
tools::extended_lucas<T> cache();
```

It precomputes ${}_n C_r \pmod{M}$ for any $n$ and $r$ where $M$ is `T::mod()`.

### Constraints
- `<T>` is `atcoder::static_modint` or `atcoder::dynamic_modint`
- $1 \leq M \leq 10^7$

### Time Complexity
- $O(M \log M)$

## combination
```cpp
T cache.combination(std::int_fast64_t n, std::int_fast64_t r);
```

It returns ${}_n C_r \pmod{M}$ if $0 \leq r \leq n$.
Otherwise, it returns $0$.

### Constraints
- None

### Time Complexity
- $O(\log n + \log r)$
