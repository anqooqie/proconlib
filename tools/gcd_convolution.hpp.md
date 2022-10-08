---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: tools/osa_k.hpp
    title: osa_k's algorithm
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: tests/gcd_convolution.test.cpp
    title: tests/gcd_convolution.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/gcd_convolution.hpp\"\n\n\n\n#include <type_traits>\n\
    #include <vector>\n#include <algorithm>\n#include <cstddef>\n#include <iterator>\n\
    #line 1 \"tools/osa_k.hpp\"\n\n\n\n#line 7 \"tools/osa_k.hpp\"\n#include <utility>\n\
    #line 9 \"tools/osa_k.hpp\"\n#include <limits>\n#include <cassert>\n\nnamespace\
    \ tools {\n\n  template <typename T>\n  class osa_k {\n  private:\n    ::std::vector<T>\
    \ m_min_prime_factors;\n    ::std::vector<T> m_divisor_counts;\n\n    T size()\
    \ const {\n      return this->m_min_prime_factors.size();\n    }\n\n  public:\n\
    \    class prime_factor_iterable {\n    private:\n      const ::std::vector<T>&\
    \ m_min_prime_factors;\n      T m_n;\n\n    public:\n      class iterator {\n\
    \      private:\n        const ::std::vector<T>& m_min_prime_factors;\n      \
    \  T m_n;\n\n      public:\n        using difference_type = ::std::ptrdiff_t;\n\
    \        using value_type = T;\n        using reference = T&;\n        using pointer\
    \ = T*;\n        using iterator_category = ::std::input_iterator_tag;\n\n    \
    \    iterator(const ::std::vector<T>& min_prime_factors, const T& n) :\n     \
    \     m_min_prime_factors(min_prime_factors),\n          m_n(n) {\n        }\n\
    \n        iterator(const iterator& other) = default;\n        ~iterator() = default;\n\
    \        iterator& operator=(const iterator& other) = default;\n\n        T operator*()\
    \ const {\n          return this->m_min_prime_factors[this->m_n];\n        }\n\
    \n        iterator& operator++() {\n          this->m_n /= **this;\n         \
    \ return *this;\n        }\n\n        iterator operator++(int) {\n          const\
    \ iterator self = *this;\n          ++*this;\n          return self;\n       \
    \ }\n\n        friend bool operator==(const iterator& lhs, const iterator& rhs)\
    \ {\n          return lhs.m_n == rhs.m_n;\n        }\n\n        friend bool operator!=(const\
    \ iterator& lhs, const iterator& rhs) {\n          return !(lhs == rhs);\n   \
    \     }\n      };\n\n      prime_factor_iterable(const ::std::vector<T>& min_prime_factors,\
    \ const T& n) :\n        m_min_prime_factors(min_prime_factors),\n        m_n(n)\
    \ {\n      }\n\n      iterator begin() const {\n        return iterator(this->m_min_prime_factors,\
    \ this->m_n);\n      };\n\n      iterator end() const {\n        return iterator(this->m_min_prime_factors,\
    \ 1);\n      }\n    };\n\n    class distinct_prime_factor_iterable {\n    private:\n\
    \      const ::std::vector<T>& m_min_prime_factors;\n      T m_n;\n\n    public:\n\
    \      class iterator {\n      private:\n        const ::std::vector<T>& m_min_prime_factors;\n\
    \        T m_n;\n        bool m_evaluated;\n        ::std::pair<T, T> m_value;\n\
    \        T m_next_n;\n\n      public:\n        using difference_type = ::std::ptrdiff_t;\n\
    \        using value_type = ::std::pair<T, T>;\n        using reference = ::std::pair<T,\
    \ T>&;\n        using pointer = ::std::pair<T, T>*;\n        using iterator_category\
    \ = ::std::input_iterator_tag;\n\n        iterator(const ::std::vector<T>& min_prime_factors,\
    \ const T& n) :\n          m_min_prime_factors(min_prime_factors),\n         \
    \ m_n(n),\n          m_evaluated(false) {\n        }\n\n        iterator(const\
    \ iterator& other) = default;\n        ~iterator() = default;\n        iterator&\
    \ operator=(const iterator& other) = default;\n\n        iterator& operator++()\
    \ {\n          **this;\n          this->m_n = this->m_next_n;\n          this->m_evaluated\
    \ = false;\n          return *this;\n        }\n\n        iterator operator++(int)\
    \ {\n          **this;\n          const iterator self = *this;\n          this->m_n\
    \ = this->m_next_n;\n          this->m_evaluated = false;\n          return self;\n\
    \        }\n\n        ::std::pair<T, T> operator*() {\n          if (!this->m_evaluated)\
    \ {\n            for (\n              this->m_next_n = this->m_n, this->m_value\
    \ = ::std::make_pair(this->m_min_prime_factors[this->m_n], 0);\n             \
    \ this->m_min_prime_factors[this->m_next_n] == this->m_min_prime_factors[this->m_n];\n\
    \              this->m_next_n /= this->m_min_prime_factors[this->m_n], ++this->m_value.second\n\
    \            );\n            this->m_evaluated = true;\n          }\n        \
    \  return this->m_value;\n        }\n\n        friend bool operator==(const iterator&\
    \ lhs, const iterator& rhs) {\n          return lhs.m_n == rhs.m_n;\n        }\n\
    \n        friend bool operator!=(const iterator& lhs, const iterator& rhs) {\n\
    \          return !(lhs == rhs);\n        }\n      };\n\n      distinct_prime_factor_iterable(const\
    \ ::std::vector<T>& min_prime_factors, const T& n) :\n        m_min_prime_factors(min_prime_factors),\n\
    \        m_n(n) {\n      }\n\n      iterator begin() const {\n        return iterator(this->m_min_prime_factors,\
    \ this->m_n);\n      };\n\n      iterator end() const {\n        return iterator(this->m_min_prime_factors,\
    \ 1);\n      }\n    };\n\n    class prime_iterable {\n    private:\n      const\
    \ ::std::vector<T>& m_min_prime_factors;\n      T m_l;\n      T m_r;\n\n    public:\n\
    \      class iterator {\n      private:\n        const ::std::vector<T>& m_min_prime_factors;\n\
    \        T m_p;\n\n        T size() const {\n          return this->m_min_prime_factors.size();\n\
    \        }\n\n      public:\n        using difference_type = ::std::ptrdiff_t;\n\
    \        using value_type = T;\n        using reference = T&;\n        using pointer\
    \ = T*;\n        using iterator_category = ::std::input_iterator_tag;\n\n    \
    \    iterator(const ::std::vector<T>& min_prime_factors, const T p) :\n      \
    \    m_min_prime_factors(min_prime_factors),\n          m_p(p) {\n          for\
    \ (; this->m_p < this->size() && this->m_min_prime_factors[this->m_p] != this->m_p;\
    \ ++this->m_p);\n        }\n\n        iterator(const iterator& other) = default;\n\
    \        ~iterator() = default;\n        iterator& operator=(const iterator& other)\
    \ = default;\n\n        iterator& operator++() {\n          for (++this->m_p;\
    \ this->m_p < this->size() && this->m_min_prime_factors[this->m_p] != this->m_p;\
    \ ++this->m_p);\n          return *this;\n        }\n\n        iterator operator++(int)\
    \ {\n          const iterator self = *this;\n          ++*this;\n          return\
    \ self;\n        }\n\n        T operator*() const {\n          return this->m_p;\n\
    \        }\n\n        friend bool operator==(const iterator& lhs, const iterator&\
    \ rhs) {\n          return lhs.m_p == rhs.m_p;\n        }\n\n        friend bool\
    \ operator!=(const iterator& lhs, const iterator& rhs) {\n          return !(lhs\
    \ == rhs);\n        }\n      };\n\n      prime_iterable(const ::std::vector<T>&\
    \ min_prime_factors, const T l, const T r) :\n        m_min_prime_factors(min_prime_factors),\
    \ m_l(l), m_r(r) {\n      }\n\n      iterator begin() const {\n        return\
    \ iterator(this->m_min_prime_factors, this->m_l);\n      };\n\n      iterator\
    \ end() const {\n        return iterator(this->m_min_prime_factors, this->m_r);\n\
    \      }\n    };\n\n    osa_k(const T N) :\n      m_min_prime_factors(::std::max<T>(N,\
    \ 1), ::std::numeric_limits<T>::max()),\n      m_divisor_counts(::std::max<T>(N,\
    \ 1)) {\n      assert(N >= 1);\n\n      for (T i = 2; i < N; ++i) {\n        if\
    \ (this->m_min_prime_factors[i] == ::std::numeric_limits<T>::max()) {\n      \
    \    this->m_min_prime_factors[i] = i;\n          for (T j = i * i; j < N; j +=\
    \ i) {\n            if (this->m_min_prime_factors[j] == ::std::numeric_limits<T>::max())\
    \ {\n              this->m_min_prime_factors[j] = i;\n            }\n        \
    \  }\n        }\n      }\n\n      ::std::vector<::std::pair<T, T>> dp(N);\n  \
    \    dp[0] = ::std::make_pair(0, 0);\n      if (N > 1) dp[1] = ::std::make_pair(1,\
    \ 1);\n      for (T i = 2; i < N; ++i) {\n        const auto& prev = dp[i / this->m_min_prime_factors[i]];\n\
    \        if (this->m_min_prime_factors[i / this->m_min_prime_factors[i]] == this->m_min_prime_factors[i])\
    \ {\n          dp[i] = ::std::make_pair(prev.first + 1, prev.second);\n      \
    \  } else {\n          dp[i] = ::std::make_pair(T(2), prev.first * prev.second);\n\
    \        }\n      }\n\n      for (T i = 0; i < N; ++i) {\n        this->m_divisor_counts[i]\
    \ = dp[i].first * dp[i].second;\n      }\n    }\n\n    T divisor_count(const T\
    \ n) const {\n      assert(1 <= n && n < this->size());\n      return this->m_divisor_counts[n];\n\
    \    }\n\n    prime_factor_iterable prime_factor_range(const T n) const {\n  \
    \    assert(1 <= n && n < this->size());\n      return prime_factor_iterable(this->m_min_prime_factors,\
    \ n);\n    }\n\n    distinct_prime_factor_iterable distinct_prime_factor_range(const\
    \ T n) const {\n      assert(1 <= n && n < this->size());\n      return distinct_prime_factor_iterable(this->m_min_prime_factors,\
    \ n);\n    }\n\n    prime_iterable prime_range(const T l, const T r) const {\n\
    \      assert(1 <= l && l <= r && r <= this->size());\n      return prime_iterable(this->m_min_prime_factors,\
    \ l, r);\n    }\n\n    ::std::vector<T> divisors(const T n) const {\n      assert(1\
    \ <= n && n < this->size());\n      ::std::vector<T> result({1});\n      for (const\
    \ auto& pair : this->distinct_prime_factor_range(n)) {\n        const T end =\
    \ result.size();\n        for (T i = 1, x = pair.first; i <= pair.second; ++i,\
    \ x *= pair.first) {\n          for (T j = 0; j < end; ++j) {\n            result.push_back(result[j]\
    \ * x);\n          }\n        }\n      }\n\n      ::std::sort(result.begin(),\
    \ result.end());\n      return result;\n    }\n  };\n}\n\n\n#line 10 \"tools/gcd_convolution.hpp\"\
    \n\nnamespace tools {\n  template <typename InputIterator, typename OutputIterator>\n\
    \  void gcd_convolution(InputIterator a_begin, InputIterator a_end, InputIterator\
    \ b_begin, InputIterator b_end, OutputIterator c_begin, OutputIterator c_end)\
    \ {\n    if (c_begin == c_end) return;\n\n    using T = ::std::decay_t<decltype(*a_begin)>;\n\
    \    ::std::vector<T> a(a_begin, a_end);\n    ::std::vector<T> b(b_begin, b_end);\n\
    \    if (a.empty() || b.empty()) {\n      ::std::fill(c_begin, c_end, T(0));\n\
    \      return;\n    }\n    const ::std::size_t N = a.size();\n    const ::std::size_t\
    \ M = b.size();\n    const ::std::size_t K = ::std::distance(c_begin, c_end);\n\
    \n    ::std::vector<T> base(K, T(0));\n    base[0] = a[0] * b[0];\n    for (::std::size_t\
    \ i = 1; i < ::std::min(N, K); ++i) {\n      base[i] += a[i] * b[0];\n    }\n\
    \    for (::std::size_t i = 1; i < ::std::min(M, K); ++i) {\n      base[i] +=\
    \ a[0] * b[i];\n    }\n\n    ::tools::osa_k<::std::size_t> osa_k(::std::max({N,\
    \ M, K}));\n    for (const auto p : osa_k.prime_range(1, N)) {\n      for (::std::size_t\
    \ k = (N - 1) / p; k >= 1; --k) {\n        a[k] += a[k * p];\n      }\n    }\n\
    \    for (const auto p : osa_k.prime_range(1, M)) {\n      for (::std::size_t\
    \ k = (M - 1) / p; k >= 1; --k) {\n        b[k] += b[k * p];\n      }\n    }\n\
    \n    for (::std::size_t i = 1; i < ::std::min({N, M, K}); ++i) {\n      c_begin[i]\
    \ = a[i] * b[i];\n    }\n    ::std::fill(::std::next(c_begin, ::std::min({N, M,\
    \ K})), c_end, T(0));\n\n    for (const auto p : osa_k.prime_range(1, K)) {\n\
    \      for (::std::size_t k = 1; k * p < K; ++k) {\n        c_begin[k] -= c_begin[k\
    \ * p];\n      }\n    }\n\n    for (::std::size_t i = 0; i < K; ++i) {\n     \
    \ c_begin[i] += base[i];\n    }\n  }\n}\n\n\n"
  code: "#ifndef TOOLS_GCD_CONVOLUTION_HPP\n#define TOOLS_GCD_CONVOLUTION_HPP\n\n\
    #include <type_traits>\n#include <vector>\n#include <algorithm>\n#include <cstddef>\n\
    #include <iterator>\n#include \"tools/osa_k.hpp\"\n\nnamespace tools {\n  template\
    \ <typename InputIterator, typename OutputIterator>\n  void gcd_convolution(InputIterator\
    \ a_begin, InputIterator a_end, InputIterator b_begin, InputIterator b_end, OutputIterator\
    \ c_begin, OutputIterator c_end) {\n    if (c_begin == c_end) return;\n\n    using\
    \ T = ::std::decay_t<decltype(*a_begin)>;\n    ::std::vector<T> a(a_begin, a_end);\n\
    \    ::std::vector<T> b(b_begin, b_end);\n    if (a.empty() || b.empty()) {\n\
    \      ::std::fill(c_begin, c_end, T(0));\n      return;\n    }\n    const ::std::size_t\
    \ N = a.size();\n    const ::std::size_t M = b.size();\n    const ::std::size_t\
    \ K = ::std::distance(c_begin, c_end);\n\n    ::std::vector<T> base(K, T(0));\n\
    \    base[0] = a[0] * b[0];\n    for (::std::size_t i = 1; i < ::std::min(N, K);\
    \ ++i) {\n      base[i] += a[i] * b[0];\n    }\n    for (::std::size_t i = 1;\
    \ i < ::std::min(M, K); ++i) {\n      base[i] += a[0] * b[i];\n    }\n\n    ::tools::osa_k<::std::size_t>\
    \ osa_k(::std::max({N, M, K}));\n    for (const auto p : osa_k.prime_range(1,\
    \ N)) {\n      for (::std::size_t k = (N - 1) / p; k >= 1; --k) {\n        a[k]\
    \ += a[k * p];\n      }\n    }\n    for (const auto p : osa_k.prime_range(1, M))\
    \ {\n      for (::std::size_t k = (M - 1) / p; k >= 1; --k) {\n        b[k] +=\
    \ b[k * p];\n      }\n    }\n\n    for (::std::size_t i = 1; i < ::std::min({N,\
    \ M, K}); ++i) {\n      c_begin[i] = a[i] * b[i];\n    }\n    ::std::fill(::std::next(c_begin,\
    \ ::std::min({N, M, K})), c_end, T(0));\n\n    for (const auto p : osa_k.prime_range(1,\
    \ K)) {\n      for (::std::size_t k = 1; k * p < K; ++k) {\n        c_begin[k]\
    \ -= c_begin[k * p];\n      }\n    }\n\n    for (::std::size_t i = 0; i < K; ++i)\
    \ {\n      c_begin[i] += base[i];\n    }\n  }\n}\n\n#endif\n"
  dependsOn:
  - tools/osa_k.hpp
  isVerificationFile: false
  path: tools/gcd_convolution.hpp
  requiredBy: []
  timestamp: '2022-09-17 11:30:02+09:00'
  verificationStatus: LIBRARY_ALL_WA
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

## Constraints
- `a_begin` $\leq$ `a_end`
- `b_begin` $\leq$ `b_end`
- `c_begin` $\leq$ `c_end`

## Time Complexity
- $O(\max(N, M, K) \log\log(\max(N, M, K)))$

## License
- CC0

## Author
- anqooqie
