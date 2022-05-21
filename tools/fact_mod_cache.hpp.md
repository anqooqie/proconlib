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
    path: tools/pow_mod.hpp
    title: $x^y \pmod{M}$
  - icon: ':heavy_check_mark:'
    path: tools/prod_mod.hpp
    title: $x \cdot y \pmod{M}$
  - icon: ':heavy_check_mark:'
    path: tools/quo.hpp
    title: Quotient as integer division
  - icon: ':heavy_check_mark:'
    path: tools/signum.hpp
    title: Sign function
  - icon: ':heavy_check_mark:'
    path: tools/ssize.hpp
    title: Polyfill of std::ssize
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/fact_mod_cache/combination.test.cpp
    title: tests/fact_mod_cache/combination.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/fact_mod_cache/permutation.test.cpp
    title: tests/fact_mod_cache/permutation.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/fact_mod_cache.hpp\"\n\n\n\n#include <vector>\n#include\
    \ <cstdint>\n#include <cassert>\n#include <algorithm>\n#include <cmath>\n#line\
    \ 1 \"tools/is_prime.hpp\"\n\n\n\n#line 5 \"tools/is_prime.hpp\"\n#include <array>\n\
    #line 1 \"tools/prod_mod.hpp\"\n\n\n\nnamespace tools {\n\n  template <typename\
    \ T1, typename T2, typename T3>\n  constexpr T3 prod_mod(const T1 x, const T2\
    \ y, const T3 m) {\n    using u128 = unsigned __int128;\n    u128 prod_mod = u128(x\
    \ >= 0 ? x : -x) * u128(y >= 0 ? y : -y) % u128(m);\n    if ((x >= 0) ^ (y >=\
    \ 0)) prod_mod = u128(m) - prod_mod;\n    return prod_mod;\n  }\n}\n\n\n#line\
    \ 1 \"tools/pow_mod.hpp\"\n\n\n\n#line 1 \"tools/mod.hpp\"\n\n\n\n#include <type_traits>\n\
    #line 1 \"tools/quo.hpp\"\n\n\n\n#line 5 \"tools/quo.hpp\"\n\nnamespace tools\
    \ {\n\n  template <typename M, typename N>\n  constexpr ::std::common_type_t<M,\
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
    \ true;\n  }\n}\n\n\n#line 1 \"tools/ssize.hpp\"\n\n\n\n#line 5 \"tools/ssize.hpp\"\
    \n#include <cstddef>\n\nnamespace tools {\n\n  template <typename C>\n  constexpr\
    \ auto ssize(const C& c) -> ::std::common_type_t<::std::ptrdiff_t, ::std::make_signed_t<decltype(c.size())>>\
    \ {\n    return c.size();\n  }\n}\n\n\n#line 1 \"tools/signum.hpp\"\n\n\n\n#line\
    \ 5 \"tools/signum.hpp\"\n\nnamespace tools {\n\n  template <typename T>\n  constexpr\
    \ int signum(const T x) noexcept {\n    if constexpr (::std::is_signed_v<T>) {\n\
    \      return (T(0) < x) - (x < T(0));\n    } else {\n      return T(0) < x;\n\
    \    }\n  }\n}\n\n\n#line 12 \"tools/fact_mod_cache.hpp\"\n\nnamespace tools {\n\
    \n  template <class M>\n  class fact_mod_cache {\n  private:\n    using i64 =\
    \ ::std::int_fast64_t;\n    ::std::vector<M> m_inv;\n    ::std::vector<M> m_fact;\n\
    \    ::std::vector<M> m_fact_inv;\n\n  public:\n    fact_mod_cache() : m_inv({M::raw(0),\
    \ M::raw(1)}), m_fact({M::raw(1), M::raw(1)}), m_fact_inv({M::raw(1), M::raw(1)})\
    \ {\n      assert(::tools::is_prime(M::mod()));\n    }\n    fact_mod_cache(const\
    \ ::tools::fact_mod_cache<M>&) = default;\n    fact_mod_cache(::tools::fact_mod_cache<M>&&)\
    \ = default;\n    ~fact_mod_cache() = default;\n    ::tools::fact_mod_cache<M>&\
    \ operator=(const ::tools::fact_mod_cache<M>&) = default;\n    ::tools::fact_mod_cache<M>&\
    \ operator=(::tools::fact_mod_cache<M>&&) = default;\n\n    M inv(const i64 n)\
    \ {\n      assert(n % M::mod() != 0);\n      const i64 size = ::tools::ssize(this->m_inv);\n\
    \      this->m_inv.resize(::std::clamp<i64>(::std::abs(n) + 1, size, M::mod()));\n\
    \      for (i64 i = size; i < ::tools::ssize(this->m_inv); ++i) {\n        this->m_inv[i]\
    \ = -this->m_inv[M::mod() % i] * M::raw(M::mod() / i);\n      }\n      return\
    \ ::tools::signum(n) * this->m_inv[::std::abs(n) % M::mod()];\n    }\n    M fact(const\
    \ i64 n) {\n      assert(n >= 0);\n      const i64 size = ::tools::ssize(this->m_fact);\n\
    \      this->m_fact.resize(::std::clamp<i64>(n + 1, size, M::mod()));\n      for\
    \ (i64 i = size; i < ::tools::ssize(this->m_fact); ++i) {\n        this->m_fact[i]\
    \ = this->m_fact[i - 1] * M::raw(i);\n      }\n      return n < M::mod() ? this->m_fact[n]\
    \ : M::raw(0);\n    }\n    M fact_inv(const i64 n) {\n      assert(0 <= n && n\
    \ < M::mod());\n      const i64 size = ::tools::ssize(this->m_fact_inv);\n   \
    \   this->m_fact_inv.resize(::std::max<i64>(size, n + 1));\n      this->inv(this->m_fact_inv.size()\
    \ - 1);\n      for (i64 i = size; i < ::tools::ssize(this->m_fact_inv); ++i) {\n\
    \        this->m_fact_inv[i] = this->m_fact_inv[i - 1] * this->m_inv[i];\n   \
    \   }\n      return this->m_fact_inv[n];\n    }\n\n    explicit fact_mod_cache(const\
    \ i64 max) : fact_mod_cache() {\n      this->fact(::std::min<i64>(max, M::mod()\
    \ - 1));\n      this->fact_inv(::std::min<i64>(max, M::mod() - 1));\n    }\n\n\
    \    M combination(i64 n, i64 r) {\n      if (!(0 <= r && r <= n)) return M::raw(0);\n\
    \n      this->fact(::std::min<i64>(n, M::mod() - 1));\n      this->fact_inv(::std::min<i64>(n,\
    \ M::mod() - 1));\n      const auto c = [&](const i64 nn, const i64 rr) {\n  \
    \      return 0 <= rr && rr <= nn ? this->m_fact[nn] * this->m_fact_inv[nn - rr]\
    \ * this->m_fact_inv[rr] : M::raw(0);\n      };\n\n      M answer(1);\n      while\
    \ (n > 0 || r > 0) {\n        answer *= c(n % M::mod(), r % M::mod());\n     \
    \   n /= M::mod();\n        r /= M::mod();\n      }\n\n      return answer;\n\
    \    }\n    M permutation(const i64 n, const i64 r) {\n      if (!(0 <= r && r\
    \ <= n)) return M::raw(0);\n      return this->combination(n, r) * this->fact(r);\n\
    \    }\n  };\n}\n\n\n"
  code: "#ifndef TOOLS_FACT_MOD_CACHE_HPP\n#define TOOLS_FACT_MOD_CACHE_HPP\n\n#include\
    \ <vector>\n#include <cstdint>\n#include <cassert>\n#include <algorithm>\n#include\
    \ <cmath>\n#include \"tools/is_prime.hpp\"\n#include \"tools/ssize.hpp\"\n#include\
    \ \"tools/signum.hpp\"\n\nnamespace tools {\n\n  template <class M>\n  class fact_mod_cache\
    \ {\n  private:\n    using i64 = ::std::int_fast64_t;\n    ::std::vector<M> m_inv;\n\
    \    ::std::vector<M> m_fact;\n    ::std::vector<M> m_fact_inv;\n\n  public:\n\
    \    fact_mod_cache() : m_inv({M::raw(0), M::raw(1)}), m_fact({M::raw(1), M::raw(1)}),\
    \ m_fact_inv({M::raw(1), M::raw(1)}) {\n      assert(::tools::is_prime(M::mod()));\n\
    \    }\n    fact_mod_cache(const ::tools::fact_mod_cache<M>&) = default;\n   \
    \ fact_mod_cache(::tools::fact_mod_cache<M>&&) = default;\n    ~fact_mod_cache()\
    \ = default;\n    ::tools::fact_mod_cache<M>& operator=(const ::tools::fact_mod_cache<M>&)\
    \ = default;\n    ::tools::fact_mod_cache<M>& operator=(::tools::fact_mod_cache<M>&&)\
    \ = default;\n\n    M inv(const i64 n) {\n      assert(n % M::mod() != 0);\n \
    \     const i64 size = ::tools::ssize(this->m_inv);\n      this->m_inv.resize(::std::clamp<i64>(::std::abs(n)\
    \ + 1, size, M::mod()));\n      for (i64 i = size; i < ::tools::ssize(this->m_inv);\
    \ ++i) {\n        this->m_inv[i] = -this->m_inv[M::mod() % i] * M::raw(M::mod()\
    \ / i);\n      }\n      return ::tools::signum(n) * this->m_inv[::std::abs(n)\
    \ % M::mod()];\n    }\n    M fact(const i64 n) {\n      assert(n >= 0);\n    \
    \  const i64 size = ::tools::ssize(this->m_fact);\n      this->m_fact.resize(::std::clamp<i64>(n\
    \ + 1, size, M::mod()));\n      for (i64 i = size; i < ::tools::ssize(this->m_fact);\
    \ ++i) {\n        this->m_fact[i] = this->m_fact[i - 1] * M::raw(i);\n      }\n\
    \      return n < M::mod() ? this->m_fact[n] : M::raw(0);\n    }\n    M fact_inv(const\
    \ i64 n) {\n      assert(0 <= n && n < M::mod());\n      const i64 size = ::tools::ssize(this->m_fact_inv);\n\
    \      this->m_fact_inv.resize(::std::max<i64>(size, n + 1));\n      this->inv(this->m_fact_inv.size()\
    \ - 1);\n      for (i64 i = size; i < ::tools::ssize(this->m_fact_inv); ++i) {\n\
    \        this->m_fact_inv[i] = this->m_fact_inv[i - 1] * this->m_inv[i];\n   \
    \   }\n      return this->m_fact_inv[n];\n    }\n\n    explicit fact_mod_cache(const\
    \ i64 max) : fact_mod_cache() {\n      this->fact(::std::min<i64>(max, M::mod()\
    \ - 1));\n      this->fact_inv(::std::min<i64>(max, M::mod() - 1));\n    }\n\n\
    \    M combination(i64 n, i64 r) {\n      if (!(0 <= r && r <= n)) return M::raw(0);\n\
    \n      this->fact(::std::min<i64>(n, M::mod() - 1));\n      this->fact_inv(::std::min<i64>(n,\
    \ M::mod() - 1));\n      const auto c = [&](const i64 nn, const i64 rr) {\n  \
    \      return 0 <= rr && rr <= nn ? this->m_fact[nn] * this->m_fact_inv[nn - rr]\
    \ * this->m_fact_inv[rr] : M::raw(0);\n      };\n\n      M answer(1);\n      while\
    \ (n > 0 || r > 0) {\n        answer *= c(n % M::mod(), r % M::mod());\n     \
    \   n /= M::mod();\n        r /= M::mod();\n      }\n\n      return answer;\n\
    \    }\n    M permutation(const i64 n, const i64 r) {\n      if (!(0 <= r && r\
    \ <= n)) return M::raw(0);\n      return this->combination(n, r) * this->fact(r);\n\
    \    }\n  };\n}\n\n#endif\n"
  dependsOn:
  - tools/is_prime.hpp
  - tools/prod_mod.hpp
  - tools/pow_mod.hpp
  - tools/mod.hpp
  - tools/quo.hpp
  - tools/ssize.hpp
  - tools/signum.hpp
  isVerificationFile: false
  path: tools/fact_mod_cache.hpp
  requiredBy: []
  timestamp: '2022-05-21 13:58:49+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/fact_mod_cache/combination.test.cpp
  - tests/fact_mod_cache/permutation.test.cpp
documentation_of: tools/fact_mod_cache.hpp
layout: document
title: $n^{-1} \pmod{P}, n! \pmod{P}, n!^{-1} \pmod{P}, {}_n C_r \pmod{P}, {}_n P_r
  \pmod{P}$
---

It returns $n^{-1} \pmod{P}, n! \pmod{P}, n!^{-1} \pmod{P}, {}_n C_r \pmod{P}, {}_n P_r \pmod{P}$.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
(1) fact_mod_cache<M> cache();
(2) fact_mod_cache<M> cache(std::int_fast64_t N);
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
M cache.inv(std::int_fast64_t n);
```

It returns $n^{-1} \pmod{P}$.

### Constraints
- $n \not\equiv 0 \pmod{P}$

### Time Complexity
- $O(\min(\|n\|, P))$ worst
- $O(1)$ amortized

## fact
```cpp
M cache.fact(std::int_fast64_t n);
```

It returns $n! \pmod{P}$.

### Constraints
- $n \geq 0$

### Time Complexity
- $O(\min(n, P))$ worst
- $O(1)$ amortized

## fact_inv
```cpp
M cache.fact_inv(std::int_fast64_t n);
```

It returns $n!^{-1} \pmod{P}$.

### Constraints
- $0 < n < P$

### Time Complexity
- $O(n)$ worst
- $O(1)$ amortized

## combination
```cpp
M cache.combination(std::int_fast64_t n, std::int_fast64_t r);
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
M cache.permutation(std::int_fast64_t n, std::int_fast64_t r);
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
