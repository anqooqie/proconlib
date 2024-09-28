---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/linear_sieve.hpp
    title: Linear sieve
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/gcd_convolution.test.cpp
    title: tests/gcd_convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/gcd_convolution.hpp\"\n\n\n\n#include <type_traits>\n\
    #include <vector>\n#include <algorithm>\n#include <cstddef>\n#include <iterator>\n\
    #line 1 \"tools/linear_sieve.hpp\"\n\n\n\n#line 7 \"tools/linear_sieve.hpp\"\n\
    #include <cassert>\n#include <tuple>\n#line 10 \"tools/linear_sieve.hpp\"\n\n\
    namespace tools {\n  template <typename T>\n  class linear_sieve {\n    ::std::vector<int>\
    \ m_primes;\n    ::std::vector<int> m_lpf;\n    ::std::vector<int> m_ord;\n  \
    \  ::std::vector<int> m_pow;\n\n    int N() const {\n      return this->m_lpf.size()\
    \ - 1;\n    }\n\n  public:\n    class prime_factor_iterable {\n    private:\n\
    \      ::tools::linear_sieve<T> const *m_parent;\n      int m_n;\n\n    public:\n\
    \      class iterator {\n      private:\n        ::tools::linear_sieve<T> const\
    \ *m_parent;\n        int m_n;\n\n      public:\n        using difference_type\
    \ = ::std::ptrdiff_t;\n        using value_type = T;\n        using reference\
    \ = const T&;\n        using pointer = const T*;\n        using iterator_category\
    \ = ::std::input_iterator_tag;\n\n        iterator() = default;\n        iterator(::tools::linear_sieve<T>\
    \ const * const parent, const int n) : m_parent(parent), m_n(n) {\n        }\n\
    \n        value_type operator*() const {\n          return this->m_parent->m_lpf[this->m_n];\n\
    \        }\n        iterator& operator++() {\n          this->m_n /= **this;\n\
    \          return *this;\n        }\n        iterator operator++(int) {\n    \
    \      const auto self = *this;\n          ++*this;\n          return self;\n\
    \        }\n        friend bool operator==(const iterator lhs, const iterator\
    \ rhs) {\n          assert(lhs.m_parent == rhs.m_parent);\n          return lhs.m_n\
    \ == rhs.m_n;\n        }\n        friend bool operator!=(const iterator lhs, const\
    \ iterator rhs) {\n          return !(lhs == rhs);\n        }\n      };\n\n  \
    \    prime_factor_iterable() = default;\n      prime_factor_iterable(::tools::linear_sieve<T>\
    \ const * const parent, const int n) : m_parent(parent), m_n(n) {\n      }\n\n\
    \      iterator begin() const {\n        return iterator(this->m_parent, this->m_n);\n\
    \      };\n      iterator end() const {\n        return iterator(this->m_parent,\
    \ 1);\n      }\n    };\n\n    class distinct_prime_factor_iterable {\n    private:\n\
    \      ::tools::linear_sieve<T> const *m_parent;\n      int m_n;\n\n    public:\n\
    \      class iterator {\n      private:\n        ::tools::linear_sieve<T> const\
    \ *m_parent;\n        int m_n;\n\n      public:\n        using difference_type\
    \ = ::std::ptrdiff_t;\n        using value_type = ::std::tuple<T, T, T>;\n   \
    \     using reference = const ::std::tuple<T, T, T>&;\n        using pointer =\
    \ const ::std::tuple<T, T, T>*;\n        using iterator_category = ::std::input_iterator_tag;\n\
    \n        iterator() = default;\n        iterator(::tools::linear_sieve<T> const\
    \ * const parent, const int n) : m_parent(parent), m_n(n) {\n        }\n\n   \
    \     value_type operator*() const {\n          return value_type(this->m_parent->m_lpf[this->m_n],\
    \ this->m_parent->m_ord[this->m_n], this->m_parent->m_pow[this->m_n]);\n     \
    \   }\n        iterator& operator++() {\n          this->m_n /= this->m_parent->m_pow[this->m_n];\n\
    \          return *this;\n        }\n        iterator operator++(int) {\n    \
    \      const auto self = *this;\n          ++*this;\n          return self;\n\
    \        }\n        friend bool operator==(const iterator lhs, const iterator\
    \ rhs) {\n          assert(lhs.m_parent == rhs.m_parent);\n          return lhs.m_n\
    \ == rhs.m_n;\n        }\n        friend bool operator!=(const iterator lhs, const\
    \ iterator rhs) {\n          return !(lhs == rhs);\n        }\n      };\n\n  \
    \    distinct_prime_factor_iterable() = default;\n      distinct_prime_factor_iterable(::tools::linear_sieve<T>\
    \ const * const parent, const int n) : m_parent(parent), m_n(n) {\n      }\n\n\
    \      iterator begin() const {\n        return iterator(this->m_parent, this->m_n);\n\
    \      };\n      iterator end() const {\n        return iterator(this->m_parent,\
    \ 1);\n      }\n    };\n\n    class prime_iterable {\n    private:\n      ::tools::linear_sieve<T>\
    \ const *m_parent;\n      int m_l;\n      int m_r;\n\n    public:\n      class\
    \ iterator {\n      private:\n        ::tools::linear_sieve<T> const *m_parent;\n\
    \        int m_i;\n\n      public:\n        using difference_type = ::std::ptrdiff_t;\n\
    \        using value_type = T;\n        using reference = const T&;\n        using\
    \ pointer = const T*;\n        using iterator_category = ::std::input_iterator_tag;\n\
    \n        iterator() = default;\n        iterator(::tools::linear_sieve<T> const\
    \ * const parent, const int n) : m_parent(parent), m_i(::std::distance(parent->m_primes.begin(),\
    \ ::std::lower_bound(parent->m_primes.begin(), parent->m_primes.end(), n))) {\n\
    \        }\n\n        value_type operator*() const {\n          return this->m_parent->m_primes[this->m_i];\n\
    \        }\n        iterator& operator++() {\n          ++this->m_i;\n       \
    \   return *this;\n        }\n        iterator operator++(int) {\n          const\
    \ auto self = *this;\n          ++*this;\n          return self;\n        }\n\
    \        friend bool operator==(const iterator lhs, const iterator rhs) {\n  \
    \        assert(lhs.m_parent == rhs.m_parent);\n          return lhs.m_i == rhs.m_i;\n\
    \        }\n        friend bool operator!=(const iterator lhs, const iterator\
    \ rhs) {\n          return !(lhs == rhs);\n        }\n      };\n\n      prime_iterable()\
    \ = default;\n      prime_iterable(::tools::linear_sieve<T> const * const parent,\
    \ const int l, const int r) : m_parent(parent), m_l(l), m_r(r) {\n      }\n\n\
    \      iterator begin() const {\n        return iterator(this->m_parent, this->m_l);\n\
    \      };\n      iterator end() const {\n        return iterator(this->m_parent,\
    \ this->m_r + 1);\n      }\n    };\n\n    linear_sieve() = default;\n    explicit\
    \ linear_sieve(const int N) : m_lpf(N + 1), m_ord(N + 1), m_pow(N + 1) {\n   \
    \   assert(N >= 1);\n\n      for (int n = 2; n <= N; ++n) {\n        if (!this->m_lpf[n])\
    \ {\n          this->m_primes.push_back(n);\n          this->m_lpf[n] = n;\n \
    \         this->m_ord[n] = 1;\n          this->m_pow[n] = n;\n        }\n    \
    \    for (auto it = this->m_primes.begin(); it != this->m_primes.end() && *it\
    \ <= this->m_lpf[n] && n * *it <= N; ++it) {\n          this->m_lpf[n * *it] =\
    \ *it;\n          if (*it < this->m_lpf[n]) {\n            this->m_ord[n * *it]\
    \ = 1;\n            this->m_pow[n * *it] = *it;\n          } else {\n        \
    \    this->m_ord[n * *it] = this->m_ord[n] + 1;\n            this->m_pow[n * *it]\
    \ = this->m_pow[n] * *it;\n          }\n        }\n      }\n    }\n\n    bool\
    \ is_prime(const int n) const {\n      assert(1 <= n && n <= this->N());\n   \
    \   return n >= 2 && this->m_lpf[n] == n;\n    }\n\n    prime_factor_iterable\
    \ prime_factor_range(const int n) const {\n      assert(1 <= n && n <= this->N());\n\
    \      return prime_factor_iterable(this, n);\n    }\n\n    distinct_prime_factor_iterable\
    \ distinct_prime_factor_range(const int n) const {\n      assert(1 <= n && n <=\
    \ this->N());\n      return distinct_prime_factor_iterable(this, n);\n    }\n\n\
    \    prime_iterable prime_range(const int l, const int r) const {\n      assert(1\
    \ <= l && l <= r && r <= this->N());\n      return prime_iterable(this, l, r);\n\
    \    }\n\n    ::std::vector<T> divisors(const int n) const {\n      assert(1 <=\
    \ n && n <= this->N());\n\n      ::std::vector<T> D{1};\n      for (const auto&\
    \ [p, q, unused] : this->distinct_prime_factor_range(n)) {\n        const int\
    \ end = D.size();\n        for (int e = 1, pe = p; e <= q; ++e, pe *= p) {\n \
    \         for (int i = 0; i < end; ++i) {\n            D.push_back(D[i] * pe);\n\
    \          }\n        }\n      }\n\n      return D;\n    }\n\n    ::std::vector<T>\
    \ sorted_divisors(const int n) const {\n      auto D = this->divisors(n);\n  \
    \    ::std::sort(D.begin(), D.end());\n      return D;\n    }\n  };\n}\n\n\n#line\
    \ 10 \"tools/gcd_convolution.hpp\"\n\nnamespace tools {\n  template <typename\
    \ InputIterator, typename OutputIterator>\n  void gcd_convolution(InputIterator\
    \ a_begin, InputIterator a_end, InputIterator b_begin, InputIterator b_end, OutputIterator\
    \ c_begin, OutputIterator c_end) {\n    if (c_begin == c_end) return;\n\n    using\
    \ T = ::std::decay_t<decltype(*a_begin)>;\n    ::std::vector<T> a(a_begin, a_end);\n\
    \    ::std::vector<T> b(b_begin, b_end);\n    if (a.empty() || b.empty()) {\n\
    \      ::std::fill(c_begin, c_end, T(0));\n      return;\n    }\n    const ::std::size_t\
    \ N = a.size();\n    const ::std::size_t M = b.size();\n    const ::std::size_t\
    \ K = ::std::distance(c_begin, c_end);\n\n    ::std::vector<T> base(K, T(0));\n\
    \    base[0] = a[0] * b[0];\n    for (::std::size_t i = 1; i < ::std::min(N, K);\
    \ ++i) {\n      base[i] += a[i] * b[0];\n    }\n    for (::std::size_t i = 1;\
    \ i < ::std::min(M, K); ++i) {\n      base[i] += a[0] * b[i];\n    }\n\n    ::tools::linear_sieve<::std::size_t>\
    \ sieve(::std::max({N, M, K}) > 2 ? ::std::max({N, M, K}) - 1 : 1);\n    if (N\
    \ > 1) {\n      for (const auto p : sieve.prime_range(1, N - 1)) {\n        for\
    \ (::std::size_t k = (N - 1) / p; k >= 1; --k) {\n          a[k] += a[k * p];\n\
    \        }\n      }\n    }\n    if (M > 1) {\n      for (const auto p : sieve.prime_range(1,\
    \ M - 1)) {\n        for (::std::size_t k = (M - 1) / p; k >= 1; --k) {\n    \
    \      b[k] += b[k * p];\n        }\n      }\n    }\n\n    for (::std::size_t\
    \ i = 1; i < ::std::min({N, M, K}); ++i) {\n      c_begin[i] = a[i] * b[i];\n\
    \    }\n    ::std::fill(::std::next(c_begin, ::std::min({N, M, K})), c_end, T(0));\n\
    \n    if (K > 1) {\n      for (const auto p : sieve.prime_range(1, K - 1)) {\n\
    \        for (::std::size_t k = 1; k * p < K; ++k) {\n          c_begin[k] -=\
    \ c_begin[k * p];\n        }\n      }\n    }\n\n    for (::std::size_t i = 0;\
    \ i < K; ++i) {\n      c_begin[i] += base[i];\n    }\n  }\n}\n\n\n"
  code: "#ifndef TOOLS_GCD_CONVOLUTION_HPP\n#define TOOLS_GCD_CONVOLUTION_HPP\n\n\
    #include <type_traits>\n#include <vector>\n#include <algorithm>\n#include <cstddef>\n\
    #include <iterator>\n#include \"tools/linear_sieve.hpp\"\n\nnamespace tools {\n\
    \  template <typename InputIterator, typename OutputIterator>\n  void gcd_convolution(InputIterator\
    \ a_begin, InputIterator a_end, InputIterator b_begin, InputIterator b_end, OutputIterator\
    \ c_begin, OutputIterator c_end) {\n    if (c_begin == c_end) return;\n\n    using\
    \ T = ::std::decay_t<decltype(*a_begin)>;\n    ::std::vector<T> a(a_begin, a_end);\n\
    \    ::std::vector<T> b(b_begin, b_end);\n    if (a.empty() || b.empty()) {\n\
    \      ::std::fill(c_begin, c_end, T(0));\n      return;\n    }\n    const ::std::size_t\
    \ N = a.size();\n    const ::std::size_t M = b.size();\n    const ::std::size_t\
    \ K = ::std::distance(c_begin, c_end);\n\n    ::std::vector<T> base(K, T(0));\n\
    \    base[0] = a[0] * b[0];\n    for (::std::size_t i = 1; i < ::std::min(N, K);\
    \ ++i) {\n      base[i] += a[i] * b[0];\n    }\n    for (::std::size_t i = 1;\
    \ i < ::std::min(M, K); ++i) {\n      base[i] += a[0] * b[i];\n    }\n\n    ::tools::linear_sieve<::std::size_t>\
    \ sieve(::std::max({N, M, K}) > 2 ? ::std::max({N, M, K}) - 1 : 1);\n    if (N\
    \ > 1) {\n      for (const auto p : sieve.prime_range(1, N - 1)) {\n        for\
    \ (::std::size_t k = (N - 1) / p; k >= 1; --k) {\n          a[k] += a[k * p];\n\
    \        }\n      }\n    }\n    if (M > 1) {\n      for (const auto p : sieve.prime_range(1,\
    \ M - 1)) {\n        for (::std::size_t k = (M - 1) / p; k >= 1; --k) {\n    \
    \      b[k] += b[k * p];\n        }\n      }\n    }\n\n    for (::std::size_t\
    \ i = 1; i < ::std::min({N, M, K}); ++i) {\n      c_begin[i] = a[i] * b[i];\n\
    \    }\n    ::std::fill(::std::next(c_begin, ::std::min({N, M, K})), c_end, T(0));\n\
    \n    if (K > 1) {\n      for (const auto p : sieve.prime_range(1, K - 1)) {\n\
    \        for (::std::size_t k = 1; k * p < K; ++k) {\n          c_begin[k] -=\
    \ c_begin[k * p];\n        }\n      }\n    }\n\n    for (::std::size_t i = 0;\
    \ i < K; ++i) {\n      c_begin[i] += base[i];\n    }\n  }\n}\n\n#endif\n"
  dependsOn:
  - tools/linear_sieve.hpp
  isVerificationFile: false
  path: tools/gcd_convolution.hpp
  requiredBy: []
  timestamp: '2024-09-29 05:36:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/gcd_convolution.test.cpp
documentation_of: tools/gcd_convolution.hpp
layout: document
title: GCD convolution
---

```cpp
template <typename InputIterator, typename OutputIterator>
void gcd_convolution(InputIterator a_begin, InputIterator a_end, InputIterator b_begin, InputIterator b_end, OutputIterator c_begin, OutputIterator c_end);
```

Given two infinite sequences $(a_0, a_1, \ldots, a_{N - 1}, 0, 0, \ldots)$ and $(b_0, b_1, \ldots, b_{M - 1}, 0, 0, \ldots)$, it returns the first $K$ terms of the infinite sequence $(c_0, c_1, \ldots)$ where

$$\begin{align*}
N &= \mathrm{a\_end} - \mathrm{a\_begin}\\
M &= \mathrm{b\_end} - \mathrm{b\_begin}\\
K &= \mathrm{c\_end} - \mathrm{c\_begin}\\
c_k &= \sum_{\gcd(i, j) = k} a_i b_j
\end{align*}$$

Note that we define $\gcd(x, 0) = x$, $\gcd(0, y) = y$ and $\gcd(0, 0) = 0$ in this function.

### Constraints
- `a_begin` $\leq$ `a_end`
- `b_begin` $\leq$ `b_end`
- `c_begin` $\leq$ `c_end`

### Time Complexity
- $O(\max(N, M, K) \log\log(\max(N, M, K)))$

### License
- CC0

### Author
- anqooqie
