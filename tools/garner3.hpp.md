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
  _extendedRequiredBy:
  - icon: ':question:'
    path: tools/convolution.hpp
    title: Arbitrary modulus convolution
  - icon: ':question:'
    path: tools/fps.hpp
    title: Formal power series
  - icon: ':x:'
    path: tools/nth_term.hpp
    title: Bostan-Mori algorithm
  - icon: ':x:'
    path: tools/partition_function.hpp
    title: Partition function $P(i, i) \pmod{M}$ for $0 \leq i \leq n$ and $P(i, j)
      \pmod{M}$ for $0 \leq i \leq n, 0 \leq j \leq k$
  - icon: ':x:'
    path: tools/stirling_2nd.hpp
    title: Stirling numbers of the second kind $S(n, k) \pmod{P}$ for $0 \leq k \leq
      n$
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/convolution/mod1000000007.test.cpp
    title: tests/convolution/mod1000000007.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/convolution/mod998244353.test.cpp
    title: tests/convolution/mod998244353.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/fps/exp_mod1000000007.test.cpp
    title: tests/fps/exp_mod1000000007.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/fps/exp_mod998244353.test.cpp
    title: tests/fps/exp_mod998244353.test.cpp
  - icon: ':x:'
    path: tests/fps/inv_mod1000000007.test.cpp
    title: tests/fps/inv_mod1000000007.test.cpp
  - icon: ':x:'
    path: tests/fps/inv_mod998244353.test.cpp
    title: tests/fps/inv_mod998244353.test.cpp
  - icon: ':x:'
    path: tests/fps/log_mod1000000007.test.cpp
    title: tests/fps/log_mod1000000007.test.cpp
  - icon: ':x:'
    path: tests/fps/log_mod998244353.test.cpp
    title: tests/fps/log_mod998244353.test.cpp
  - icon: ':x:'
    path: tests/fps/pow_mod1000000007.test.cpp
    title: tests/fps/pow_mod1000000007.test.cpp
  - icon: ':x:'
    path: tests/fps/pow_mod998244353.test.cpp
    title: tests/fps/pow_mod998244353.test.cpp
  - icon: ':x:'
    path: tests/nth_term.test.cpp
    title: tests/nth_term.test.cpp
  - icon: ':x:'
    path: tests/partition_function/n.test.cpp
    title: tests/partition_function/n.test.cpp
  - icon: ':x:'
    path: tests/partition_function/n_k.test.cpp
    title: tests/partition_function/n_k.test.cpp
  - icon: ':x:'
    path: tests/stirling_2nd.test.cpp
    title: tests/stirling_2nd.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/garner3.hpp\"\n\n\n\n#include <cassert>\n#line 1 \"\
    tools/is_prime.hpp\"\n\n\n\n#include <array>\n#line 1 \"tools/prod_mod.hpp\"\n\
    \n\n\nnamespace tools {\n\n  template <typename T1, typename T2, typename T3>\n\
    \  constexpr T3 prod_mod(const T1 x, const T2 y, const T3 m) {\n    using u128\
    \ = unsigned __int128;\n    u128 prod_mod = u128(x >= 0 ? x : -x) * u128(y >=\
    \ 0 ? y : -y) % u128(m);\n    if ((x >= 0) ^ (y >= 0)) prod_mod = u128(m) - prod_mod;\n\
    \    return prod_mod;\n  }\n}\n\n\n#line 1 \"tools/pow_mod.hpp\"\n\n\n\n#line\
    \ 1 \"tools/mod.hpp\"\n\n\n\n#include <type_traits>\n#line 1 \"tools/quo.hpp\"\
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
    \    return r;\n  }\n}\n\n\n#line 7 \"tools/is_prime.hpp\"\n\nnamespace tools\
    \ {\n\n  constexpr bool is_prime(const unsigned long long n) {\n    constexpr\
    \ ::std::array<unsigned long long, 7> bases = {2, 325, 9375, 28178, 450775, 9780504,\
    \ 1795265022};\n\n    if (n <= 1) return false;\n    if (n == 2) return true;\n\
    \    if (n % 2 == 0) return false;\n\n    auto d = n - 1;\n    for (; d % 2 ==\
    \ 0; d /= 2);\n\n    for (const auto a : bases) {\n      if (a % n == 0) return\
    \ true;\n\n      auto power = d;\n      auto target = ::tools::pow_mod(a, power,\
    \ n);\n\n      bool is_composite = true;\n      if (target == 1) is_composite\
    \ = false;\n      for (; is_composite && power != n - 1; power *= 2, target =\
    \ ::tools::prod_mod(target, target, n)) {\n        if (target == n - 1) is_composite\
    \ = false;\n      }\n\n      if (is_composite) {\n        return false;\n    \
    \  }\n    }\n\n    return true;\n  }\n}\n\n\n#line 7 \"tools/garner3.hpp\"\n\n\
    namespace tools {\n\n  template <typename M, typename M1, typename M2, typename\
    \ M3>\n  M garner3(const M1& a, const M2& b, const M3& c, const M m) {\n    using\
    \ ull = unsigned long long;\n    static const M2 m1_inv_mod_m2 = M2::raw(M1::mod()).inv();\n\
    \    static const M3 m1_m2_inv_mod_m3 = (M3::raw(M1::mod()) * M3::raw(M2::mod())).inv();\n\
    \n    static const auto plus_mod = [](ull x, const ull y, const ull mod) {\n \
    \     assert(x < mod);\n      assert(y < mod);\n\n      x += y;\n      if (x >=\
    \ mod) x -= mod;\n      return x; \n    };\n\n    assert(m >= 1);\n    assert(M1::mod()\
    \ < M2::mod());\n    assert(M2::mod() < M3::mod());\n    assert(::tools::is_prime(M1::mod()));\n\
    \    assert(::tools::is_prime(M2::mod()));\n    assert(::tools::is_prime(M3::mod()));\n\
    \n    // t1 = (b - a) / M1; (mod M2)\n    // t2 = (c - a - t1 * M1) / M1 / M2;\
    \ (mod M3)\n    // return a + t1 * M1 + t2 * M1 * M2; (mod m)\n    const M2 t1\
    \ = (b - M2::raw(a.val())) * m1_inv_mod_m2;\n    const M3 t2 = (c - M3::raw(a.val())\
    \ - M3::raw(t1.val()) * M3::raw(M1::mod())) * m1_m2_inv_mod_m3;\n    ull r = ::tools::prod_mod(t2.val(),\
    \ ull(M1::mod()) * ull(M2::mod()), m);\n    assert(r < ull(m));\n    r = plus_mod(r,\
    \ ull(t1.val()) * ull(M1::mod()) % m, m);\n    assert(r < ull(m));\n    r = plus_mod(r,\
    \ a.val() % m, m);\n    assert(r < ull(m));\n    return r;\n  }\n}\n\n\n"
  code: "#ifndef TOOLS_GARNER3_HPP\n#define TOOLS_GARNER3_HPP\n\n#include <cassert>\n\
    #include \"tools/is_prime.hpp\"\n#include \"tools/prod_mod.hpp\"\n\nnamespace\
    \ tools {\n\n  template <typename M, typename M1, typename M2, typename M3>\n\
    \  M garner3(const M1& a, const M2& b, const M3& c, const M m) {\n    using ull\
    \ = unsigned long long;\n    static const M2 m1_inv_mod_m2 = M2::raw(M1::mod()).inv();\n\
    \    static const M3 m1_m2_inv_mod_m3 = (M3::raw(M1::mod()) * M3::raw(M2::mod())).inv();\n\
    \n    static const auto plus_mod = [](ull x, const ull y, const ull mod) {\n \
    \     assert(x < mod);\n      assert(y < mod);\n\n      x += y;\n      if (x >=\
    \ mod) x -= mod;\n      return x; \n    };\n\n    assert(m >= 1);\n    assert(M1::mod()\
    \ < M2::mod());\n    assert(M2::mod() < M3::mod());\n    assert(::tools::is_prime(M1::mod()));\n\
    \    assert(::tools::is_prime(M2::mod()));\n    assert(::tools::is_prime(M3::mod()));\n\
    \n    // t1 = (b - a) / M1; (mod M2)\n    // t2 = (c - a - t1 * M1) / M1 / M2;\
    \ (mod M3)\n    // return a + t1 * M1 + t2 * M1 * M2; (mod m)\n    const M2 t1\
    \ = (b - M2::raw(a.val())) * m1_inv_mod_m2;\n    const M3 t2 = (c - M3::raw(a.val())\
    \ - M3::raw(t1.val()) * M3::raw(M1::mod())) * m1_m2_inv_mod_m3;\n    ull r = ::tools::prod_mod(t2.val(),\
    \ ull(M1::mod()) * ull(M2::mod()), m);\n    assert(r < ull(m));\n    r = plus_mod(r,\
    \ ull(t1.val()) * ull(M1::mod()) % m, m);\n    assert(r < ull(m));\n    r = plus_mod(r,\
    \ a.val() % m, m);\n    assert(r < ull(m));\n    return r;\n  }\n}\n\n#endif\n"
  dependsOn:
  - tools/is_prime.hpp
  - tools/prod_mod.hpp
  - tools/pow_mod.hpp
  - tools/mod.hpp
  - tools/quo.hpp
  isVerificationFile: false
  path: tools/garner3.hpp
  requiredBy:
  - tools/nth_term.hpp
  - tools/fps.hpp
  - tools/stirling_2nd.hpp
  - tools/partition_function.hpp
  - tools/convolution.hpp
  timestamp: '2022-11-06 13:36:53+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - tests/partition_function/n_k.test.cpp
  - tests/partition_function/n.test.cpp
  - tests/fps/exp_mod998244353.test.cpp
  - tests/fps/inv_mod1000000007.test.cpp
  - tests/fps/log_mod1000000007.test.cpp
  - tests/fps/log_mod998244353.test.cpp
  - tests/fps/inv_mod998244353.test.cpp
  - tests/fps/exp_mod1000000007.test.cpp
  - tests/fps/pow_mod998244353.test.cpp
  - tests/fps/pow_mod1000000007.test.cpp
  - tests/stirling_2nd.test.cpp
  - tests/convolution/mod998244353.test.cpp
  - tests/convolution/mod1000000007.test.cpp
  - tests/nth_term.test.cpp
documentation_of: tools/garner3.hpp
layout: document
title: Garner's algorithm for $\mathbb{Z} / M_1 \mathbb{Z}$, $\mathbb{Z} / M_2 \mathbb{Z}$
  and $\mathbb{Z} / M_3 \mathbb{Z}$
---

```cpp
template <typename M, typename M1, typename M2, typename M3>
M garner3(M1 a, M2 b, M3 c, M m);
```

It solves the following modular equation system and returns $(x \bmod M_1 M_2 M_3) \bmod m$ where $M_1$ is `M1::mod()`, $M_2$ is `M2::mod()` and $M_3$ is `M3::mod()`.

$$\begin{align*}
\left\{\begin{array}{ll}
x \equiv a &\pmod{M_1}\\
x \equiv b &\pmod{M_2}\\
x \equiv c &\pmod{M_3}
\end{array}\right.&
\end{align*}$$

It is useful to reconstruct $x$ less than $M_1 M_2 M_3$ from $x \bmod M_1$, $x \bmod M_2$ and $x \bmod M_3$.

## Constraints
- `M1` is `atcoder::static_modint` or `atcoder::dynamic_modint`.
- `M2` is `atcoder::static_modint` or `atcoder::dynamic_modint`.
- `M3` is `atcoder::static_modint` or `atcoder::dynamic_modint`.
- `M` is a built-in integral type.
- $M_1$ is a prime.
- $M_2$ is a prime.
- $M_3$ is a prime.
- $M_1 < M_2 < M_3$
- $m \geq 1$

## Time Complexity
- $O(1)$

## License
- CC0

## Author
- anqooqie
