---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: tools/is_prime.hpp
    title: Miller-Rabin primality test
  - icon: ':question:'
    path: tools/mod.hpp
    title: Minimum non-negative reminder
  - icon: ':question:'
    path: tools/pow_mod.hpp
    title: $x^y \pmod{M}$
  - icon: ':question:'
    path: tools/prod_mod.hpp
    title: $x \cdot y \pmod{M}$
  - icon: ':question:'
    path: tools/quo.hpp
    title: Quotient as integer division
  - icon: ':question:'
    path: tools/ssize.hpp
    title: Polyfill of std::ssize
  - icon: ':question:'
    path: tools/uint128_t.hpp
    title: 128 bit unsigned integer
  _extendedRequiredBy:
  - icon: ':x:'
    path: tools/stirling_2nd.hpp
    title: Stirling numbers of the second kind $S(n, k) \pmod{P}$ for $0 \leq k \leq
      n$
  _extendedVerifiedWith:
  - icon: ':x:'
    path: tests/fact_mod_cache.test.cpp
    title: tests/fact_mod_cache.test.cpp
  - icon: ':x:'
    path: tests/stirling_2nd.test.cpp
    title: tests/stirling_2nd.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/fact_mod_cache.hpp\"\n\n\n\n#include <vector>\n#include\
    \ <cassert>\n#include <algorithm>\n#include <cmath>\n#line 1 \"tools/is_prime.hpp\"\
    \n\n\n\n#include <array>\n#line 1 \"tools/prod_mod.hpp\"\n\n\n\n#line 1 \"tools/uint128_t.hpp\"\
    \n\n\n\n#include <iostream>\n#include <string>\n#line 7 \"tools/uint128_t.hpp\"\
    \n#include <cstddef>\n#line 9 \"tools/uint128_t.hpp\"\n\nnamespace tools {\n \
    \ using uint128_t = unsigned __int128;\n}\n\n::std::istream& operator>>(::std::istream&\
    \ is, ::tools::uint128_t& x) {\n  ::std::string s;\n  is >> s;\n  assert(!s.empty());\n\
    \n  x = 0;\n  for (::std::size_t i = s[0] == '+'; i < s.size(); ++i) {\n    assert('0'\
    \ <= s[i] && s[i] <= '9');\n    x = 10 * x + (s[i] - '0');\n  }\n\n  return is;\n\
    }\n\n::std::ostream& operator<<(::std::ostream& os, ::tools::uint128_t x) {\n\
    \  if (x == 0) return os << '0';\n\n  ::std::string s;\n  while (x > 0) {\n  \
    \  s.push_back('0' + x % 10);\n    x /= 10;\n  }\n  ::std::reverse(s.begin(),\
    \ s.end());\n\n  return os << s;\n}\n\n\n#line 5 \"tools/prod_mod.hpp\"\n\nnamespace\
    \ tools {\n\n  template <typename T1, typename T2, typename T3>\n  constexpr T3\
    \ prod_mod(const T1 x, const T2 y, const T3 m) {\n    using u128 = ::tools::uint128_t;\n\
    \    u128 prod_mod = u128(x >= 0 ? x : -x) * u128(y >= 0 ? y : -y) % u128(m);\n\
    \    if ((x >= 0) ^ (y >= 0)) prod_mod = u128(m) - prod_mod;\n    return prod_mod;\n\
    \  }\n}\n\n\n#line 1 \"tools/pow_mod.hpp\"\n\n\n\n#line 1 \"tools/mod.hpp\"\n\n\
    \n\n#include <type_traits>\n#line 1 \"tools/quo.hpp\"\n\n\n\n#line 5 \"tools/quo.hpp\"\
    \n\nnamespace tools {\n\n  template <typename M, typename N>\n  constexpr ::std::common_type_t<M,\
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
    \ y, m);\n      n /= 2;\n    }\n    return r;\n  }\n}\n\n\n#line 7 \"tools/is_prime.hpp\"\
    \n\nnamespace tools {\n\n  constexpr bool is_prime(const unsigned long long n)\
    \ {\n    constexpr ::std::array<unsigned long long, 7> bases = {2, 325, 9375,\
    \ 28178, 450775, 9780504, 1795265022};\n\n    if (n <= 1) return false;\n    if\
    \ (n == 2) return true;\n    if (n % 2 == 0) return false;\n\n    auto d = n -\
    \ 1;\n    for (; d % 2 == 0; d /= 2);\n\n    for (const auto a : bases) {\n  \
    \    if (a % n == 0) return true;\n\n      auto power = d;\n      auto target\
    \ = ::tools::pow_mod(a, power, n);\n\n      bool is_composite = true;\n      if\
    \ (target == 1) is_composite = false;\n      for (; is_composite && power != n\
    \ - 1; power *= 2, target = ::tools::prod_mod(target, target, n)) {\n        if\
    \ (target == n - 1) is_composite = false;\n      }\n\n      if (is_composite)\
    \ {\n        return false;\n      }\n    }\n\n    return true;\n  }\n}\n\n\n#line\
    \ 1 \"tools/ssize.hpp\"\n\n\n\n#line 6 \"tools/ssize.hpp\"\n\nnamespace tools\
    \ {\n\n  template <typename C>\n  constexpr auto ssize(const C& c) -> ::std::common_type_t<::std::ptrdiff_t,\
    \ ::std::make_signed_t<decltype(c.size())>> {\n    return c.size();\n  }\n}\n\n\
    \n#line 10 \"tools/fact_mod_cache.hpp\"\n\nnamespace tools {\n\n  template <class\
    \ M>\n  class fact_mod_cache {\n  private:\n    ::std::vector<M> m_inv;\n    ::std::vector<M>\
    \ m_fact;\n    ::std::vector<M> m_fact_inv;\n\n  public:\n    fact_mod_cache()\
    \ : m_inv({M::raw(0), M::raw(1)}), m_fact({M::raw(1), M::raw(1)}), m_fact_inv({M::raw(1),\
    \ M::raw(1)}) {\n      assert(::tools::is_prime(M::mod()));\n    }\n    fact_mod_cache(const\
    \ ::tools::fact_mod_cache<M>&) = default;\n    fact_mod_cache(::tools::fact_mod_cache<M>&&)\
    \ = default;\n    ~fact_mod_cache() = default;\n    ::tools::fact_mod_cache<M>&\
    \ operator=(const ::tools::fact_mod_cache<M>&) = default;\n    ::tools::fact_mod_cache<M>&\
    \ operator=(::tools::fact_mod_cache<M>&&) = default;\n\n    M inv(const long long\
    \ n) {\n      assert(n % M::mod() != 0);\n      const long long size = ::tools::ssize(this->m_inv);\n\
    \      this->m_inv.resize(::std::clamp<long long>(::std::abs(n) + 1, size, M::mod()));\n\
    \      for (long long i = size; i < ::tools::ssize(this->m_inv); ++i) {\n    \
    \    this->m_inv[i] = -this->m_inv[M::mod() % i] * M::raw(M::mod() / i);\n   \
    \   }\n      M result = this->m_inv[::std::abs(n) % M::mod()];\n      if (n <\
    \ 0) result = -result;\n      return result;\n    }\n    M fact(const long long\
    \ n) {\n      assert(n >= 0);\n      const long long size = ::tools::ssize(this->m_fact);\n\
    \      this->m_fact.resize(::std::clamp<long long>(n + 1, size, M::mod()));\n\
    \      for (long long i = size; i < ::tools::ssize(this->m_fact); ++i) {\n   \
    \     this->m_fact[i] = this->m_fact[i - 1] * M::raw(i);\n      }\n      return\
    \ n < M::mod() ? this->m_fact[n] : M::raw(0);\n    }\n    M fact_inv(const long\
    \ long n) {\n      assert(0 <= n && n < M::mod());\n      const long long size\
    \ = ::tools::ssize(this->m_fact_inv);\n      this->m_fact_inv.resize(::std::max<long\
    \ long>(size, n + 1));\n      this->inv(this->m_fact_inv.size() - 1);\n      for\
    \ (long long i = size; i < ::tools::ssize(this->m_fact_inv); ++i) {\n        this->m_fact_inv[i]\
    \ = this->m_fact_inv[i - 1] * this->m_inv[i];\n      }\n      return this->m_fact_inv[n];\n\
    \    }\n\n    explicit fact_mod_cache(const long long max) : fact_mod_cache()\
    \ {\n      this->fact(::std::min<long long>(max, M::mod() - 1));\n      this->fact_inv(::std::min<long\
    \ long>(max, M::mod() - 1));\n    }\n\n    M combination(long long n, long long\
    \ r) {\n      if (!(0 <= r && r <= n)) return M::raw(0);\n\n      this->fact(::std::min<long\
    \ long>(n, M::mod() - 1));\n      this->fact_inv(::std::min<long long>(n, M::mod()\
    \ - 1));\n      const auto c = [&](const long long nn, const long long rr) {\n\
    \        return 0 <= rr && rr <= nn ? this->m_fact[nn] * this->m_fact_inv[nn -\
    \ rr] * this->m_fact_inv[rr] : M::raw(0);\n      };\n\n      M result(1);\n  \
    \    while (n > 0 || r > 0) {\n        result *= c(n % M::mod(), r % M::mod());\n\
    \        n /= M::mod();\n        r /= M::mod();\n      }\n\n      return result;\n\
    \    }\n    M permutation(const long long n, const long long r) {\n      if (!(0\
    \ <= r && r <= n)) return M::raw(0);\n      return this->combination(n, r) * this->fact(r);\n\
    \    }\n    M combination_with_repetition(const long long n, const long long r)\
    \ {\n      if (n < 0) return M::raw(0);\n      if (r < 0) return M::raw(0);\n\
    \      if (n == 0 && r == 0) return M(1);\n      return this->combination(n +\
    \ r - 1, r);\n    }\n  };\n}\n\n\n"
  code: "#ifndef TOOLS_FACT_MOD_CACHE_HPP\n#define TOOLS_FACT_MOD_CACHE_HPP\n\n#include\
    \ <vector>\n#include <cassert>\n#include <algorithm>\n#include <cmath>\n#include\
    \ \"tools/is_prime.hpp\"\n#include \"tools/ssize.hpp\"\n\nnamespace tools {\n\n\
    \  template <class M>\n  class fact_mod_cache {\n  private:\n    ::std::vector<M>\
    \ m_inv;\n    ::std::vector<M> m_fact;\n    ::std::vector<M> m_fact_inv;\n\n \
    \ public:\n    fact_mod_cache() : m_inv({M::raw(0), M::raw(1)}), m_fact({M::raw(1),\
    \ M::raw(1)}), m_fact_inv({M::raw(1), M::raw(1)}) {\n      assert(::tools::is_prime(M::mod()));\n\
    \    }\n    fact_mod_cache(const ::tools::fact_mod_cache<M>&) = default;\n   \
    \ fact_mod_cache(::tools::fact_mod_cache<M>&&) = default;\n    ~fact_mod_cache()\
    \ = default;\n    ::tools::fact_mod_cache<M>& operator=(const ::tools::fact_mod_cache<M>&)\
    \ = default;\n    ::tools::fact_mod_cache<M>& operator=(::tools::fact_mod_cache<M>&&)\
    \ = default;\n\n    M inv(const long long n) {\n      assert(n % M::mod() != 0);\n\
    \      const long long size = ::tools::ssize(this->m_inv);\n      this->m_inv.resize(::std::clamp<long\
    \ long>(::std::abs(n) + 1, size, M::mod()));\n      for (long long i = size; i\
    \ < ::tools::ssize(this->m_inv); ++i) {\n        this->m_inv[i] = -this->m_inv[M::mod()\
    \ % i] * M::raw(M::mod() / i);\n      }\n      M result = this->m_inv[::std::abs(n)\
    \ % M::mod()];\n      if (n < 0) result = -result;\n      return result;\n   \
    \ }\n    M fact(const long long n) {\n      assert(n >= 0);\n      const long\
    \ long size = ::tools::ssize(this->m_fact);\n      this->m_fact.resize(::std::clamp<long\
    \ long>(n + 1, size, M::mod()));\n      for (long long i = size; i < ::tools::ssize(this->m_fact);\
    \ ++i) {\n        this->m_fact[i] = this->m_fact[i - 1] * M::raw(i);\n      }\n\
    \      return n < M::mod() ? this->m_fact[n] : M::raw(0);\n    }\n    M fact_inv(const\
    \ long long n) {\n      assert(0 <= n && n < M::mod());\n      const long long\
    \ size = ::tools::ssize(this->m_fact_inv);\n      this->m_fact_inv.resize(::std::max<long\
    \ long>(size, n + 1));\n      this->inv(this->m_fact_inv.size() - 1);\n      for\
    \ (long long i = size; i < ::tools::ssize(this->m_fact_inv); ++i) {\n        this->m_fact_inv[i]\
    \ = this->m_fact_inv[i - 1] * this->m_inv[i];\n      }\n      return this->m_fact_inv[n];\n\
    \    }\n\n    explicit fact_mod_cache(const long long max) : fact_mod_cache()\
    \ {\n      this->fact(::std::min<long long>(max, M::mod() - 1));\n      this->fact_inv(::std::min<long\
    \ long>(max, M::mod() - 1));\n    }\n\n    M combination(long long n, long long\
    \ r) {\n      if (!(0 <= r && r <= n)) return M::raw(0);\n\n      this->fact(::std::min<long\
    \ long>(n, M::mod() - 1));\n      this->fact_inv(::std::min<long long>(n, M::mod()\
    \ - 1));\n      const auto c = [&](const long long nn, const long long rr) {\n\
    \        return 0 <= rr && rr <= nn ? this->m_fact[nn] * this->m_fact_inv[nn -\
    \ rr] * this->m_fact_inv[rr] : M::raw(0);\n      };\n\n      M result(1);\n  \
    \    while (n > 0 || r > 0) {\n        result *= c(n % M::mod(), r % M::mod());\n\
    \        n /= M::mod();\n        r /= M::mod();\n      }\n\n      return result;\n\
    \    }\n    M permutation(const long long n, const long long r) {\n      if (!(0\
    \ <= r && r <= n)) return M::raw(0);\n      return this->combination(n, r) * this->fact(r);\n\
    \    }\n    M combination_with_repetition(const long long n, const long long r)\
    \ {\n      if (n < 0) return M::raw(0);\n      if (r < 0) return M::raw(0);\n\
    \      if (n == 0 && r == 0) return M(1);\n      return this->combination(n +\
    \ r - 1, r);\n    }\n  };\n}\n\n#endif\n"
  dependsOn:
  - tools/is_prime.hpp
  - tools/prod_mod.hpp
  - tools/uint128_t.hpp
  - tools/pow_mod.hpp
  - tools/mod.hpp
  - tools/quo.hpp
  - tools/ssize.hpp
  isVerificationFile: false
  path: tools/fact_mod_cache.hpp
  requiredBy:
  - tools/stirling_2nd.hpp
  timestamp: '2022-11-23 11:49:11+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - tests/fact_mod_cache.test.cpp
  - tests/stirling_2nd.test.cpp
documentation_of: tools/fact_mod_cache.hpp
layout: document
title: Precompute $n^{-1} \pmod{P}, n! \pmod{P}, n!^{-1} \pmod{P}, {}_n C_r \pmod{P},
  {}_n P_r \pmod{P}$
---

It returns $n^{-1} \pmod{P}, n! \pmod{P}, n!^{-1} \pmod{P}, {}_n C_r \pmod{P}, {}_n P_r \pmod{P}$.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
(1) fact_mod_cache<M> cache();
(2) fact_mod_cache<M> cache(long long N);
```

- (1)
    - It creates an empty cache to store $n^{-1} \pmod{P}, n! \pmod{P}, n!^{-1} \pmod{P}$ where $P$ is `M::mod()`.
- (2)
    - It precomputes $n^{-1} \pmod{P}, n! \pmod{P}, n!^{-1} \pmod{P}$ for $0 \leq n \leq N$, where $P$ is `M::mod()`.

### Constraints
- `<M>` is `atcoder::static_modint` or `atcoder::dynamic_modint`
- `M::mod()` is a prime

### Time Complexity
- (1)
    - $O(1)$
- (2)
    - $O(\min(N, P))$

## inv
```cpp
M cache.inv(long long n);
```

It returns $n^{-1} \pmod{P}$.

### Constraints
- $n \not\equiv 0 \pmod{P}$

### Time Complexity
- $O(\min(\|n\|, P))$ worst
- $O(1)$ amortized

## fact
```cpp
M cache.fact(long long n);
```

It returns $n! \pmod{P}$.

### Constraints
- $n \geq 0$

### Time Complexity
- $O(\min(n, P))$ worst
- $O(1)$ amortized

## fact_inv
```cpp
M cache.fact_inv(long long n);
```

It returns $n!^{-1} \pmod{P}$.

### Constraints
- $0 < n < P$

### Time Complexity
- $O(n)$ worst
- $O(1)$ amortized

## combination
```cpp
M cache.combination(long long n, long long r);
```

It returns

$$\begin{align*}
\left\{\begin{array}{ll}
{}_n C_r \pmod{P} & \text{(if $0 \leq r \leq n$)}\\
0 \pmod{P} & \text{(otherwise)}
\end{array}\right.&
\end{align*}$$

### Constraints
- None

### Time Complexity
- $O(\min(n, P) + \log_P(n))$ worst
- $O(\log_P(n))$ amortized

## permutation
```cpp
M cache.permutation(long long n, long long r);
```

It returns

$$\begin{align*}
\left\{\begin{array}{ll}
{}_n P_r \pmod{P} & \text{(if $0 \leq r \leq n$)}\\
0 \pmod{P} & \text{(otherwise)}
\end{array}\right.&
\end{align*}$$

### Constraints
- None

### Time Complexity
- $O(\min(n, P) + \log_P(n))$ worst
- $O(\log_P(n))$ amortized

## combination_with_repetition
```cpp
M cache.combination_with_repetition(long long n, long long r);
```

It returns

$$\begin{align*}
\left\{\begin{array}{ll}
{}_n H_r \pmod{P} & \text{(if $n \geq 0$ and $r \geq 0$)}\\
0 \pmod{P} & \text{(otherwise)}
\end{array}\right.&
\end{align*}$$

### Constraints
- None

### Time Complexity
- $O(\min(n + r, P) + \log_P(n + r))$ worst
- $O(\log_P(n + r))$ amortized
