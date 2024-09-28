---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/assert_that.hpp
    title: Assertion macro
  - icon: ':heavy_check_mark:'
    path: tools/linear_sieve.hpp
    title: Linear sieve
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A
  bundledCode: "#line 1 \"tests/linear_sieve.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\"\
    \n\n#include <iostream>\n#include <iterator>\n#include <tuple>\n#include <vector>\n\
    #include <algorithm>\n#line 1 \"tools/assert_that.hpp\"\n\n\n\n#line 5 \"tools/assert_that.hpp\"\
    \n#include <cstdlib>\n\n#define assert_that_impl(cond, file, line, func) do {\\\
    \n  if (!cond) {\\\n    ::std::cerr << file << ':' << line << \": \" << func <<\
    \ \": Assertion `\" << #cond << \"' failed.\" << '\\n';\\\n    ::std::exit(EXIT_FAILURE);\\\
    \n  }\\\n} while (false)\n#define assert_that(...) assert_that_impl((__VA_ARGS__),\
    \ __FILE__, __LINE__, __func__)\n\n\n#line 1 \"tools/linear_sieve.hpp\"\n\n\n\n\
    #line 5 \"tools/linear_sieve.hpp\"\n#include <cstddef>\n#line 7 \"tools/linear_sieve.hpp\"\
    \n#include <cassert>\n#line 10 \"tools/linear_sieve.hpp\"\n\nnamespace tools {\n\
    \  template <typename T>\n  class linear_sieve {\n    ::std::vector<int> m_primes;\n\
    \    ::std::vector<int> m_lpf;\n    ::std::vector<int> m_ord;\n    ::std::vector<int>\
    \ m_pow;\n\n    int N() const {\n      return this->m_lpf.size() - 1;\n    }\n\
    \n  public:\n    class prime_factor_iterable {\n    private:\n      ::tools::linear_sieve<T>\
    \ const *m_parent;\n      int m_n;\n\n    public:\n      class iterator {\n  \
    \    private:\n        ::tools::linear_sieve<T> const *m_parent;\n        int\
    \ m_n;\n\n      public:\n        using difference_type = ::std::ptrdiff_t;\n \
    \       using value_type = T;\n        using reference = const T&;\n        using\
    \ pointer = const T*;\n        using iterator_category = ::std::input_iterator_tag;\n\
    \n        iterator() = default;\n        iterator(::tools::linear_sieve<T> const\
    \ * const parent, const int n) : m_parent(parent), m_n(n) {\n        }\n\n   \
    \     value_type operator*() const {\n          return this->m_parent->m_lpf[this->m_n];\n\
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
    \ 10 \"tests/linear_sieve.test.cpp\"\n\nint main() {\n  std::cin.tie(nullptr);\n\
    \  std::ios_base::sync_with_stdio(false);\n\n  {\n    tools::linear_sieve<int>\
    \ sieve(10);\n    {\n      assert_that(!sieve.is_prime(1));\n      assert_that(sieve.is_prime(2));\n\
    \      assert_that(sieve.is_prime(3));\n      assert_that(!sieve.is_prime(4));\n\
    \      assert_that(sieve.is_prime(5));\n      assert_that(!sieve.is_prime(6));\n\
    \      assert_that(sieve.is_prime(7));\n      assert_that(!sieve.is_prime(8));\n\
    \      assert_that(!sieve.is_prime(9));\n      assert_that(!sieve.is_prime(10));\n\
    \    }\n    {\n      auto begin = sieve.prime_factor_range(1).begin(), end = sieve.prime_factor_range(1).end(),\
    \ it = begin;\n      assert_that(std::distance(begin, end) == 0);\n      begin\
    \ = sieve.prime_factor_range(2).begin(), end = sieve.prime_factor_range(2).end(),\
    \ it = begin;\n      assert_that(std::distance(begin, end) == 1);\n      assert_that(*(it++)\
    \ == 2);\n      begin = sieve.prime_factor_range(3).begin(), end = sieve.prime_factor_range(3).end(),\
    \ it = begin;\n      assert_that(std::distance(begin, end) == 1);\n      assert_that(*(it++)\
    \ == 3);\n      begin = sieve.prime_factor_range(4).begin(), end = sieve.prime_factor_range(4).end(),\
    \ it = begin;\n      assert_that(std::distance(begin, end) == 2);\n      assert_that(*(it++)\
    \ == 2);\n      assert_that(*(it++) == 2);\n      begin = sieve.prime_factor_range(5).begin(),\
    \ end = sieve.prime_factor_range(5).end(), it = begin;\n      assert_that(std::distance(begin,\
    \ end) == 1);\n      assert_that(*(it++) == 5);\n      begin = sieve.prime_factor_range(6).begin(),\
    \ end = sieve.prime_factor_range(6).end(), it = begin;\n      assert_that(std::distance(begin,\
    \ end) == 2);\n      assert_that(*(it++) == 2);\n      assert_that(*(it++) ==\
    \ 3);\n      begin = sieve.prime_factor_range(7).begin(), end = sieve.prime_factor_range(7).end(),\
    \ it = begin;\n      assert_that(std::distance(begin, end) == 1);\n      assert_that(*(it++)\
    \ == 7);\n      begin = sieve.prime_factor_range(8).begin(), end = sieve.prime_factor_range(8).end(),\
    \ it = begin;\n      assert_that(std::distance(begin, end) == 3);\n      assert_that(*(it++)\
    \ == 2);\n      assert_that(*(it++) == 2);\n      assert_that(*(it++) == 2);\n\
    \      begin = sieve.prime_factor_range(9).begin(), end = sieve.prime_factor_range(9).end(),\
    \ it = begin;\n      assert_that(std::distance(begin, end) == 2);\n      assert_that(*(it++)\
    \ == 3);\n      assert_that(*(it++) == 3);\n      begin = sieve.prime_factor_range(10).begin(),\
    \ end = sieve.prime_factor_range(10).end(), it = begin;\n      assert_that(std::distance(begin,\
    \ end) == 2);\n      assert_that(*(it++) == 2);\n      assert_that(*(it++) ==\
    \ 5);\n    }\n    {\n      auto begin = sieve.distinct_prime_factor_range(1).begin(),\
    \ end = sieve.distinct_prime_factor_range(1).end(), it = begin;\n      assert_that(std::distance(begin,\
    \ end) == 0);\n      begin = sieve.distinct_prime_factor_range(2).begin(), end\
    \ = sieve.distinct_prime_factor_range(2).end(), it = begin;\n      assert_that(std::distance(begin,\
    \ end) == 1);\n      assert_that(*(it++) == std::make_tuple(2, 1, 2));\n     \
    \ begin = sieve.distinct_prime_factor_range(3).begin(), end = sieve.distinct_prime_factor_range(3).end(),\
    \ it = begin;\n      assert_that(std::distance(begin, end) == 1);\n      assert_that(*(it++)\
    \ == std::make_tuple(3, 1, 3));\n      begin = sieve.distinct_prime_factor_range(4).begin(),\
    \ end = sieve.distinct_prime_factor_range(4).end(), it = begin;\n      assert_that(std::distance(begin,\
    \ end) == 1);\n      assert_that(*(it++) == std::make_tuple(2, 2, 4));\n     \
    \ begin = sieve.distinct_prime_factor_range(5).begin(), end = sieve.distinct_prime_factor_range(5).end(),\
    \ it = begin;\n      assert_that(std::distance(begin, end) == 1);\n      assert_that(*(it++)\
    \ == std::make_tuple(5, 1, 5));\n      begin = sieve.distinct_prime_factor_range(6).begin(),\
    \ end = sieve.distinct_prime_factor_range(6).end(), it = begin;\n      assert_that(std::distance(begin,\
    \ end) == 2);\n      assert_that(*(it++) == std::make_tuple(2, 1, 2));\n     \
    \ assert_that(*(it++) == std::make_tuple(3, 1, 3));\n      begin = sieve.distinct_prime_factor_range(7).begin(),\
    \ end = sieve.distinct_prime_factor_range(7).end(), it = begin;\n      assert_that(std::distance(begin,\
    \ end) == 1);\n      assert_that(*(it++) == std::make_tuple(7, 1, 7));\n     \
    \ begin = sieve.distinct_prime_factor_range(8).begin(), end = sieve.distinct_prime_factor_range(8).end(),\
    \ it = begin;\n      assert_that(std::distance(begin, end) == 1);\n      assert_that(*(it++)\
    \ == std::make_tuple(2, 3, 8));\n      begin = sieve.distinct_prime_factor_range(9).begin(),\
    \ end = sieve.distinct_prime_factor_range(9).end(), it = begin;\n      assert_that(std::distance(begin,\
    \ end) == 1);\n      assert_that(*(it++) == std::make_tuple(3, 2, 9));\n     \
    \ begin = sieve.distinct_prime_factor_range(10).begin(), end = sieve.distinct_prime_factor_range(10).end(),\
    \ it = begin;\n      assert_that(std::distance(begin, end) == 2);\n      assert_that(*(it++)\
    \ == std::make_tuple(2, 1, 2));\n      assert_that(*(it++) == std::make_tuple(5,\
    \ 1, 5));\n    }\n    {\n      auto begin = sieve.prime_range(1, 1).begin(), end\
    \ = sieve.prime_range(1, 1).end(), it = begin;\n      assert_that(std::distance(begin,\
    \ end) == 0);\n      begin = sieve.prime_range(1, 2).begin(), end = sieve.prime_range(1,\
    \ 2).end(), it = begin;\n      assert_that(std::distance(begin, end) == 1);\n\
    \      assert_that(*(it++) == 2);\n      begin = sieve.prime_range(1, 3).begin(),\
    \ end = sieve.prime_range(1, 3).end(), it = begin;\n      assert_that(std::distance(begin,\
    \ end) == 2);\n      assert_that(*(it++) == 2);\n      assert_that(*(it++) ==\
    \ 3);\n      begin = sieve.prime_range(1, 4).begin(), end = sieve.prime_range(1,\
    \ 4).end(), it = begin;\n      assert_that(std::distance(begin, end) == 2);\n\
    \      assert_that(*(it++) == 2);\n      assert_that(*(it++) == 3);\n      begin\
    \ = sieve.prime_range(1, 5).begin(), end = sieve.prime_range(1, 5).end(), it =\
    \ begin;\n      assert_that(std::distance(begin, end) == 3);\n      assert_that(*(it++)\
    \ == 2);\n      assert_that(*(it++) == 3);\n      assert_that(*(it++) == 5);\n\
    \      begin = sieve.prime_range(1, 6).begin(), end = sieve.prime_range(1, 6).end(),\
    \ it = begin;\n      assert_that(std::distance(begin, end) == 3);\n      assert_that(*(it++)\
    \ == 2);\n      assert_that(*(it++) == 3);\n      assert_that(*(it++) == 5);\n\
    \      begin = sieve.prime_range(1, 7).begin(), end = sieve.prime_range(1, 7).end(),\
    \ it = begin;\n      assert_that(std::distance(begin, end) == 4);\n      assert_that(*(it++)\
    \ == 2);\n      assert_that(*(it++) == 3);\n      assert_that(*(it++) == 5);\n\
    \      assert_that(*(it++) == 7);\n      begin = sieve.prime_range(1, 8).begin(),\
    \ end = sieve.prime_range(1, 8).end(), it = begin;\n      assert_that(std::distance(begin,\
    \ end) == 4);\n      assert_that(*(it++) == 2);\n      assert_that(*(it++) ==\
    \ 3);\n      assert_that(*(it++) == 5);\n      assert_that(*(it++) == 7);\n  \
    \    begin = sieve.prime_range(1, 9).begin(), end = sieve.prime_range(1, 9).end(),\
    \ it = begin;\n      assert_that(std::distance(begin, end) == 4);\n      assert_that(*(it++)\
    \ == 2);\n      assert_that(*(it++) == 3);\n      assert_that(*(it++) == 5);\n\
    \      assert_that(*(it++) == 7);\n      begin = sieve.prime_range(1, 10).begin(),\
    \ end = sieve.prime_range(1, 10).end(), it = begin;\n      assert_that(std::distance(begin,\
    \ end) == 4);\n      assert_that(*(it++) == 2);\n      assert_that(*(it++) ==\
    \ 3);\n      assert_that(*(it++) == 5);\n      assert_that(*(it++) == 7);\n  \
    \    begin = sieve.prime_range(2, 2).begin(), end = sieve.prime_range(2, 2).end(),\
    \ it = begin;\n      assert_that(std::distance(begin, end) == 1);\n      assert_that(*(it++)\
    \ == 2);\n      begin = sieve.prime_range(2, 3).begin(), end = sieve.prime_range(2,\
    \ 3).end(), it = begin;\n      assert_that(std::distance(begin, end) == 2);\n\
    \      assert_that(*(it++) == 2);\n      assert_that(*(it++) == 3);\n      begin\
    \ = sieve.prime_range(2, 4).begin(), end = sieve.prime_range(2, 4).end(), it =\
    \ begin;\n      assert_that(std::distance(begin, end) == 2);\n      assert_that(*(it++)\
    \ == 2);\n      assert_that(*(it++) == 3);\n      begin = sieve.prime_range(2,\
    \ 5).begin(), end = sieve.prime_range(2, 5).end(), it = begin;\n      assert_that(std::distance(begin,\
    \ end) == 3);\n      assert_that(*(it++) == 2);\n      assert_that(*(it++) ==\
    \ 3);\n      assert_that(*(it++) == 5);\n      begin = sieve.prime_range(2, 6).begin(),\
    \ end = sieve.prime_range(2, 6).end(), it = begin;\n      assert_that(std::distance(begin,\
    \ end) == 3);\n      assert_that(*(it++) == 2);\n      assert_that(*(it++) ==\
    \ 3);\n      assert_that(*(it++) == 5);\n      begin = sieve.prime_range(2, 7).begin(),\
    \ end = sieve.prime_range(2, 7).end(), it = begin;\n      assert_that(std::distance(begin,\
    \ end) == 4);\n      assert_that(*(it++) == 2);\n      assert_that(*(it++) ==\
    \ 3);\n      assert_that(*(it++) == 5);\n      assert_that(*(it++) == 7);\n  \
    \    begin = sieve.prime_range(2, 8).begin(), end = sieve.prime_range(2, 8).end(),\
    \ it = begin;\n      assert_that(std::distance(begin, end) == 4);\n      assert_that(*(it++)\
    \ == 2);\n      assert_that(*(it++) == 3);\n      assert_that(*(it++) == 5);\n\
    \      assert_that(*(it++) == 7);\n      begin = sieve.prime_range(2, 9).begin(),\
    \ end = sieve.prime_range(2, 9).end(), it = begin;\n      assert_that(std::distance(begin,\
    \ end) == 4);\n      assert_that(*(it++) == 2);\n      assert_that(*(it++) ==\
    \ 3);\n      assert_that(*(it++) == 5);\n      assert_that(*(it++) == 7);\n  \
    \    begin = sieve.prime_range(2, 10).begin(), end = sieve.prime_range(2, 10).end(),\
    \ it = begin;\n      assert_that(std::distance(begin, end) == 4);\n      assert_that(*(it++)\
    \ == 2);\n      assert_that(*(it++) == 3);\n      assert_that(*(it++) == 5);\n\
    \      assert_that(*(it++) == 7);\n      begin = sieve.prime_range(3, 3).begin(),\
    \ end = sieve.prime_range(3, 3).end(), it = begin;\n      assert_that(std::distance(begin,\
    \ end) == 1);\n      assert_that(*(it++) == 3);\n      begin = sieve.prime_range(3,\
    \ 4).begin(), end = sieve.prime_range(3, 4).end(), it = begin;\n      assert_that(std::distance(begin,\
    \ end) == 1);\n      assert_that(*(it++) == 3);\n      begin = sieve.prime_range(3,\
    \ 5).begin(), end = sieve.prime_range(3, 5).end(), it = begin;\n      assert_that(std::distance(begin,\
    \ end) == 2);\n      assert_that(*(it++) == 3);\n      assert_that(*(it++) ==\
    \ 5);\n      begin = sieve.prime_range(3, 6).begin(), end = sieve.prime_range(3,\
    \ 6).end(), it = begin;\n      assert_that(std::distance(begin, end) == 2);\n\
    \      assert_that(*(it++) == 3);\n      assert_that(*(it++) == 5);\n      begin\
    \ = sieve.prime_range(3, 7).begin(), end = sieve.prime_range(3, 7).end(), it =\
    \ begin;\n      assert_that(std::distance(begin, end) == 3);\n      assert_that(*(it++)\
    \ == 3);\n      assert_that(*(it++) == 5);\n      assert_that(*(it++) == 7);\n\
    \      begin = sieve.prime_range(3, 8).begin(), end = sieve.prime_range(3, 8).end(),\
    \ it = begin;\n      assert_that(std::distance(begin, end) == 3);\n      assert_that(*(it++)\
    \ == 3);\n      assert_that(*(it++) == 5);\n      assert_that(*(it++) == 7);\n\
    \      begin = sieve.prime_range(3, 9).begin(), end = sieve.prime_range(3, 9).end(),\
    \ it = begin;\n      assert_that(std::distance(begin, end) == 3);\n      assert_that(*(it++)\
    \ == 3);\n      assert_that(*(it++) == 5);\n      assert_that(*(it++) == 7);\n\
    \      begin = sieve.prime_range(3, 10).begin(), end = sieve.prime_range(3, 10).end(),\
    \ it = begin;\n      assert_that(std::distance(begin, end) == 3);\n      assert_that(*(it++)\
    \ == 3);\n      assert_that(*(it++) == 5);\n      assert_that(*(it++) == 7);\n\
    \      begin = sieve.prime_range(4, 4).begin(), end = sieve.prime_range(4, 4).end(),\
    \ it = begin;\n      assert_that(std::distance(begin, end) == 0);\n      begin\
    \ = sieve.prime_range(4, 5).begin(), end = sieve.prime_range(4, 5).end(), it =\
    \ begin;\n      assert_that(std::distance(begin, end) == 1);\n      assert_that(*(it++)\
    \ == 5);\n      begin = sieve.prime_range(4, 6).begin(), end = sieve.prime_range(4,\
    \ 6).end(), it = begin;\n      assert_that(std::distance(begin, end) == 1);\n\
    \      assert_that(*(it++) == 5);\n      begin = sieve.prime_range(4, 7).begin(),\
    \ end = sieve.prime_range(4, 7).end(), it = begin;\n      assert_that(std::distance(begin,\
    \ end) == 2);\n      assert_that(*(it++) == 5);\n      assert_that(*(it++) ==\
    \ 7);\n      begin = sieve.prime_range(4, 8).begin(), end = sieve.prime_range(4,\
    \ 8).end(), it = begin;\n      assert_that(std::distance(begin, end) == 2);\n\
    \      assert_that(*(it++) == 5);\n      assert_that(*(it++) == 7);\n      begin\
    \ = sieve.prime_range(4, 9).begin(), end = sieve.prime_range(4, 9).end(), it =\
    \ begin;\n      assert_that(std::distance(begin, end) == 2);\n      assert_that(*(it++)\
    \ == 5);\n      assert_that(*(it++) == 7);\n      begin = sieve.prime_range(4,\
    \ 10).begin(), end = sieve.prime_range(4, 10).end(), it = begin;\n      assert_that(std::distance(begin,\
    \ end) == 2);\n      assert_that(*(it++) == 5);\n      assert_that(*(it++) ==\
    \ 7);\n      begin = sieve.prime_range(5, 5).begin(), end = sieve.prime_range(5,\
    \ 5).end(), it = begin;\n      assert_that(std::distance(begin, end) == 1);\n\
    \      assert_that(*(it++) == 5);\n      begin = sieve.prime_range(5, 6).begin(),\
    \ end = sieve.prime_range(5, 6).end(), it = begin;\n      assert_that(std::distance(begin,\
    \ end) == 1);\n      assert_that(*(it++) == 5);\n      begin = sieve.prime_range(5,\
    \ 7).begin(), end = sieve.prime_range(5, 7).end(), it = begin;\n      assert_that(std::distance(begin,\
    \ end) == 2);\n      assert_that(*(it++) == 5);\n      assert_that(*(it++) ==\
    \ 7);\n      begin = sieve.prime_range(5, 8).begin(), end = sieve.prime_range(5,\
    \ 8).end(), it = begin;\n      assert_that(std::distance(begin, end) == 2);\n\
    \      assert_that(*(it++) == 5);\n      assert_that(*(it++) == 7);\n      begin\
    \ = sieve.prime_range(5, 9).begin(), end = sieve.prime_range(5, 9).end(), it =\
    \ begin;\n      assert_that(std::distance(begin, end) == 2);\n      assert_that(*(it++)\
    \ == 5);\n      assert_that(*(it++) == 7);\n      begin = sieve.prime_range(5,\
    \ 10).begin(), end = sieve.prime_range(5, 10).end(), it = begin;\n      assert_that(std::distance(begin,\
    \ end) == 2);\n      assert_that(*(it++) == 5);\n      assert_that(*(it++) ==\
    \ 7);\n      begin = sieve.prime_range(6, 6).begin(), end = sieve.prime_range(6,\
    \ 6).end(), it = begin;\n      assert_that(std::distance(begin, end) == 0);\n\
    \      begin = sieve.prime_range(6, 7).begin(), end = sieve.prime_range(6, 7).end(),\
    \ it = begin;\n      assert_that(std::distance(begin, end) == 1);\n      assert_that(*(it++)\
    \ == 7);\n      begin = sieve.prime_range(6, 8).begin(), end = sieve.prime_range(6,\
    \ 8).end(), it = begin;\n      assert_that(std::distance(begin, end) == 1);\n\
    \      assert_that(*(it++) == 7);\n      begin = sieve.prime_range(6, 9).begin(),\
    \ end = sieve.prime_range(6, 9).end(), it = begin;\n      assert_that(std::distance(begin,\
    \ end) == 1);\n      assert_that(*(it++) == 7);\n      begin = sieve.prime_range(6,\
    \ 10).begin(), end = sieve.prime_range(6, 10).end(), it = begin;\n      assert_that(std::distance(begin,\
    \ end) == 1);\n      assert_that(*(it++) == 7);\n      begin = sieve.prime_range(7,\
    \ 7).begin(), end = sieve.prime_range(7, 7).end(), it = begin;\n      assert_that(std::distance(begin,\
    \ end) == 1);\n      assert_that(*(it++) == 7);\n      begin = sieve.prime_range(7,\
    \ 8).begin(), end = sieve.prime_range(7, 8).end(), it = begin;\n      assert_that(std::distance(begin,\
    \ end) == 1);\n      assert_that(*(it++) == 7);\n      begin = sieve.prime_range(7,\
    \ 9).begin(), end = sieve.prime_range(7, 9).end(), it = begin;\n      assert_that(std::distance(begin,\
    \ end) == 1);\n      assert_that(*(it++) == 7);\n      begin = sieve.prime_range(7,\
    \ 10).begin(), end = sieve.prime_range(7, 10).end(), it = begin;\n      assert_that(std::distance(begin,\
    \ end) == 1);\n      assert_that(*(it++) == 7);\n      begin = sieve.prime_range(8,\
    \ 8).begin(), end = sieve.prime_range(8, 8).end(), it = begin;\n      assert_that(std::distance(begin,\
    \ end) == 0);\n      begin = sieve.prime_range(8, 9).begin(), end = sieve.prime_range(8,\
    \ 9).end(), it = begin;\n      assert_that(std::distance(begin, end) == 0);\n\
    \      begin = sieve.prime_range(8, 10).begin(), end = sieve.prime_range(8, 10).end(),\
    \ it = begin;\n      assert_that(std::distance(begin, end) == 0);\n      begin\
    \ = sieve.prime_range(9, 9).begin(), end = sieve.prime_range(9, 9).end(), it =\
    \ begin;\n      assert_that(std::distance(begin, end) == 0);\n      begin = sieve.prime_range(9,\
    \ 10).begin(), end = sieve.prime_range(9, 10).end(), it = begin;\n      assert_that(std::distance(begin,\
    \ end) == 0);\n      begin = sieve.prime_range(10, 10).begin(), end = sieve.prime_range(10,\
    \ 10).end(), it = begin;\n      assert_that(std::distance(begin, end) == 0);\n\
    \    }\n    {\n      auto divisors = sieve.divisors(1);\n      std::sort(divisors.begin(),\
    \ divisors.end());\n      assert_that(divisors == std::vector<int>{1});\n    \
    \  divisors = sieve.divisors(2);\n      std::sort(divisors.begin(), divisors.end());\n\
    \      assert_that(divisors == std::vector<int>{1, 2});\n      divisors = sieve.divisors(3);\n\
    \      std::sort(divisors.begin(), divisors.end());\n      assert_that(divisors\
    \ == std::vector<int>{1, 3});\n      divisors = sieve.divisors(4);\n      std::sort(divisors.begin(),\
    \ divisors.end());\n      assert_that(divisors == std::vector<int>{1, 2, 4});\n\
    \      divisors = sieve.divisors(5);\n      std::sort(divisors.begin(), divisors.end());\n\
    \      assert_that(divisors == std::vector<int>{1, 5});\n      divisors = sieve.divisors(6);\n\
    \      std::sort(divisors.begin(), divisors.end());\n      assert_that(divisors\
    \ == std::vector<int>{1, 2, 3, 6});\n      divisors = sieve.divisors(7);\n   \
    \   std::sort(divisors.begin(), divisors.end());\n      assert_that(divisors ==\
    \ std::vector<int>{1, 7});\n      divisors = sieve.divisors(8);\n      std::sort(divisors.begin(),\
    \ divisors.end());\n      assert_that(divisors == std::vector<int>{1, 2, 4, 8});\n\
    \      divisors = sieve.divisors(9);\n      std::sort(divisors.begin(), divisors.end());\n\
    \      assert_that(divisors == std::vector<int>{1, 3, 9});\n      divisors = sieve.divisors(10);\n\
    \      std::sort(divisors.begin(), divisors.end());\n      assert_that(divisors\
    \ == std::vector<int>{1, 2, 5, 10});\n    }\n    {\n      assert_that(sieve.sorted_divisors(1)\
    \ == std::vector<int>{1});\n      assert_that(sieve.sorted_divisors(2) == std::vector<int>{1,\
    \ 2});\n      assert_that(sieve.sorted_divisors(3) == std::vector<int>{1, 3});\n\
    \      assert_that(sieve.sorted_divisors(4) == std::vector<int>{1, 2, 4});\n \
    \     assert_that(sieve.sorted_divisors(5) == std::vector<int>{1, 5});\n     \
    \ assert_that(sieve.sorted_divisors(6) == std::vector<int>{1, 2, 3, 6});\n   \
    \   assert_that(sieve.sorted_divisors(7) == std::vector<int>{1, 7});\n      assert_that(sieve.sorted_divisors(8)\
    \ == std::vector<int>{1, 2, 4, 8});\n      assert_that(sieve.sorted_divisors(9)\
    \ == std::vector<int>{1, 3, 9});\n      assert_that(sieve.sorted_divisors(10)\
    \ == std::vector<int>{1, 2, 5, 10});\n    }\n  }\n  {\n    tools::linear_sieve<int>\
    \ sieve(1);\n    {\n      assert_that(!sieve.is_prime(1));\n    }\n    {\n   \
    \   auto begin = sieve.prime_factor_range(1).begin(), end = sieve.prime_factor_range(1).end();\n\
    \      assert_that(std::distance(begin, end) == 0);\n    }\n    {\n      auto\
    \ begin = sieve.distinct_prime_factor_range(1).begin(), end = sieve.distinct_prime_factor_range(1).end();\n\
    \      assert_that(std::distance(begin, end) == 0);\n    }\n    {\n      auto\
    \ begin = sieve.prime_range(1, 1).begin(), end = sieve.prime_range(1, 1).end();\n\
    \      assert_that(std::distance(begin, end) == 0);\n    }\n    {\n      auto\
    \ divisors = sieve.divisors(1);\n      std::sort(divisors.begin(), divisors.end());\n\
    \      assert_that(divisors == std::vector<int>{1});\n    }\n    {\n      assert_that(sieve.sorted_divisors(1)\
    \ == std::vector<int>{1});\n    }\n  }\n  {\n    tools::linear_sieve<int> sieve(2);\n\
    \    {\n      assert_that(!sieve.is_prime(1));\n      assert_that(sieve.is_prime(2));\n\
    \    }\n    {\n      auto begin = sieve.prime_factor_range(1).begin(), end = sieve.prime_factor_range(1).end(),\
    \ it = begin;\n      assert_that(std::distance(begin, end) == 0);\n      begin\
    \ = sieve.prime_factor_range(2).begin(), end = sieve.prime_factor_range(2).end(),\
    \ it = begin;\n      assert_that(std::distance(begin, end) == 1);\n      assert_that(*(it++)\
    \ == 2);\n    }\n    {\n      auto begin = sieve.distinct_prime_factor_range(1).begin(),\
    \ end = sieve.distinct_prime_factor_range(1).end(), it = begin;\n      assert_that(std::distance(begin,\
    \ end) == 0);\n      begin = sieve.distinct_prime_factor_range(2).begin(), end\
    \ = sieve.distinct_prime_factor_range(2).end(), it = begin;\n      assert_that(std::distance(begin,\
    \ end) == 1);\n      assert_that(*(it++) == std::make_tuple(2, 1, 2));\n    }\n\
    \    {\n      auto begin = sieve.prime_range(1, 1).begin(), end = sieve.prime_range(1,\
    \ 1).end(), it = begin;\n      assert_that(std::distance(begin, end) == 0);\n\
    \      begin = sieve.prime_range(1, 2).begin(), end = sieve.prime_range(1, 2).end(),\
    \ it = begin;\n      assert_that(std::distance(begin, end) == 1);\n      assert_that(*(it++)\
    \ == 2);\n      begin = sieve.prime_range(2, 2).begin(), end = sieve.prime_range(2,\
    \ 2).end(), it = begin;\n      assert_that(std::distance(begin, end) == 1);\n\
    \      assert_that(*(it++) == 2);\n    }\n    {\n      auto divisors = sieve.divisors(1);\n\
    \      std::sort(divisors.begin(), divisors.end());\n      assert_that(divisors\
    \ == std::vector<int>{1});\n      divisors = sieve.divisors(2);\n      std::sort(divisors.begin(),\
    \ divisors.end());\n      assert_that(divisors == std::vector<int>{1, 2});\n \
    \   }\n    {\n      assert_that(sieve.sorted_divisors(1) == std::vector<int>{1});\n\
    \      assert_that(sieve.sorted_divisors(2) == std::vector<int>{1, 2});\n    }\n\
    \  }\n  {\n    tools::linear_sieve<int> sieve(10000000);\n    {\n      assert_that(!sieve.is_prime(1));\n\
    \      assert_that(sieve.is_prime(2));\n      assert_that(sieve.is_prime(9999991));\n\
    \      assert_that(!sieve.is_prime(10000000));\n    }\n    {\n      auto begin\
    \ = sieve.prime_factor_range(1).begin(), end = sieve.prime_factor_range(1).end(),\
    \ it = begin;\n      assert_that(std::distance(begin, end) == 0);\n      begin\
    \ = sieve.prime_factor_range(2).begin(), end = sieve.prime_factor_range(2).end(),\
    \ it = begin;\n      assert_that(std::distance(begin, end) == 1);\n      assert_that(*(it++)\
    \ == 2);\n      begin = sieve.prime_factor_range(8648640).begin(), end = sieve.prime_factor_range(8648640).end(),\
    \ it = begin;\n      assert_that(std::distance(begin, end) == 13);\n      assert_that(*(it++)\
    \ == 2);\n      assert_that(*(it++) == 2);\n      assert_that(*(it++) == 2);\n\
    \      assert_that(*(it++) == 2);\n      assert_that(*(it++) == 2);\n      assert_that(*(it++)\
    \ == 2);\n      assert_that(*(it++) == 3);\n      assert_that(*(it++) == 3);\n\
    \      assert_that(*(it++) == 3);\n      assert_that(*(it++) == 5);\n      assert_that(*(it++)\
    \ == 7);\n      assert_that(*(it++) == 11);\n      assert_that(*(it++) == 13);\n\
    \      begin = sieve.prime_factor_range(9999991).begin(), end = sieve.prime_factor_range(9999991).end(),\
    \ it = begin;\n      assert_that(std::distance(begin, end) == 1);\n      assert_that(*(it++)\
    \ == 9999991);\n      begin = sieve.prime_factor_range(10000000).begin(), end\
    \ = sieve.prime_factor_range(10000000).end(), it = begin;\n      assert_that(std::distance(begin,\
    \ end) == 14);\n      assert_that(*(it++) == 2);\n      assert_that(*(it++) ==\
    \ 2);\n      assert_that(*(it++) == 2);\n      assert_that(*(it++) == 2);\n  \
    \    assert_that(*(it++) == 2);\n      assert_that(*(it++) == 2);\n      assert_that(*(it++)\
    \ == 2);\n      assert_that(*(it++) == 5);\n      assert_that(*(it++) == 5);\n\
    \      assert_that(*(it++) == 5);\n      assert_that(*(it++) == 5);\n      assert_that(*(it++)\
    \ == 5);\n      assert_that(*(it++) == 5);\n      assert_that(*(it++) == 5);\n\
    \    }\n    {\n      auto begin = sieve.distinct_prime_factor_range(1).begin(),\
    \ end = sieve.distinct_prime_factor_range(1).end(), it = begin;\n      assert_that(std::distance(begin,\
    \ end) == 0);\n      begin = sieve.distinct_prime_factor_range(2).begin(), end\
    \ = sieve.distinct_prime_factor_range(2).end(), it = begin;\n      assert_that(std::distance(begin,\
    \ end) == 1);\n      assert_that(*(it++) == std::make_tuple(2, 1, 2));\n     \
    \ begin = sieve.distinct_prime_factor_range(8648640).begin(), end = sieve.distinct_prime_factor_range(8648640).end(),\
    \ it = begin;\n      assert_that(std::distance(begin, end) == 6);\n      assert_that(*(it++)\
    \ == std::make_tuple(2, 6, 64));\n      assert_that(*(it++) == std::make_tuple(3,\
    \ 3, 27));\n      assert_that(*(it++) == std::make_tuple(5, 1, 5));\n      assert_that(*(it++)\
    \ == std::make_tuple(7, 1, 7));\n      assert_that(*(it++) == std::make_tuple(11,\
    \ 1, 11));\n      assert_that(*(it++) == std::make_tuple(13, 1, 13));\n      begin\
    \ = sieve.distinct_prime_factor_range(9999991).begin(), end = sieve.distinct_prime_factor_range(9999991).end(),\
    \ it = begin;\n      assert_that(std::distance(begin, end) == 1);\n      assert_that(*(it++)\
    \ == std::make_tuple(9999991, 1, 9999991));\n      begin = sieve.distinct_prime_factor_range(10000000).begin(),\
    \ end = sieve.distinct_prime_factor_range(10000000).end(), it = begin;\n     \
    \ assert_that(std::distance(begin, end) == 2);\n      assert_that(*(it++) == std::make_tuple(2,\
    \ 7, 128));\n      assert_that(*(it++) == std::make_tuple(5, 7, 78125));\n   \
    \ }\n    {\n      auto begin = sieve.prime_range(1, 1).begin(), end = sieve.prime_range(1,\
    \ 1).end(), it = begin;\n      assert_that(std::distance(begin, end) == 0);\n\
    \      begin = sieve.prime_range(1, 2).begin(), end = sieve.prime_range(1, 2).end(),\
    \ it = begin;\n      assert_that(std::distance(begin, end) == 1);\n      assert_that(*(it++)\
    \ == 2);\n      begin = sieve.prime_range(1, 10000000).begin(), end = sieve.prime_range(1,\
    \ 10000000).end(), it = begin;\n      assert_that(std::distance(begin, end) ==\
    \ 664579);\n      assert_that(*it == 2);\n      it = std::next(it, 664578);\n\
    \      assert_that(*it == 9999991);\n    }\n    {\n      auto divisors = sieve.divisors(1);\n\
    \      std::sort(divisors.begin(), divisors.end());\n      assert_that(divisors\
    \ == std::vector<int>{1});\n      divisors = sieve.divisors(2);\n      std::sort(divisors.begin(),\
    \ divisors.end());\n      assert_that(divisors == std::vector<int>{1, 2});\n \
    \     divisors = sieve.divisors(8648640);\n      std::sort(divisors.begin(), divisors.end());\n\
    \      assert_that(divisors == std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10,\
    \ 11, 12, 13, 14, 15, 16, 18, 20, 21, 22, 24, 26, 27, 28, 30, 32, 33, 35, 36,\
    \ 39, 40, 42, 44, 45, 48, 52, 54, 55, 56, 60, 63, 64, 65, 66, 70, 72, 77, 78,\
    \ 80, 84, 88, 90, 91, 96, 99, 104, 105, 108, 110, 112, 117, 120, 126, 130, 132,\
    \ 135, 140, 143, 144, 154, 156, 160, 165, 168, 176, 180, 182, 189, 192, 195, 198,\
    \ 208, 210, 216, 220, 224, 231, 234, 240, 252, 260, 264, 270, 273, 280, 286, 288,\
    \ 297, 308, 312, 315, 320, 330, 336, 351, 352, 360, 364, 378, 385, 390, 396, 416,\
    \ 420, 429, 432, 440, 448, 455, 462, 468, 480, 495, 504, 520, 528, 540, 546, 560,\
    \ 572, 576, 585, 594, 616, 624, 630, 660, 672, 693, 702, 704, 715, 720, 728, 756,\
    \ 770, 780, 792, 819, 832, 840, 858, 864, 880, 910, 924, 936, 945, 960, 990, 1001,\
    \ 1008, 1040, 1056, 1080, 1092, 1120, 1144, 1155, 1170, 1188, 1232, 1248, 1260,\
    \ 1287, 1320, 1344, 1365, 1386, 1404, 1430, 1440, 1456, 1485, 1512, 1540, 1560,\
    \ 1584, 1638, 1680, 1716, 1728, 1755, 1760, 1820, 1848, 1872, 1890, 1980, 2002,\
    \ 2016, 2079, 2080, 2112, 2145, 2160, 2184, 2240, 2288, 2310, 2340, 2376, 2457,\
    \ 2464, 2496, 2520, 2574, 2640, 2730, 2772, 2808, 2860, 2880, 2912, 2970, 3003,\
    \ 3024, 3080, 3120, 3168, 3276, 3360, 3432, 3465, 3510, 3520, 3640, 3696, 3744,\
    \ 3780, 3861, 3960, 4004, 4032, 4095, 4158, 4160, 4290, 4320, 4368, 4576, 4620,\
    \ 4680, 4752, 4914, 4928, 5005, 5040, 5148, 5280, 5460, 5544, 5616, 5720, 5824,\
    \ 5940, 6006, 6048, 6160, 6240, 6336, 6435, 6552, 6720, 6864, 6930, 7020, 7280,\
    \ 7392, 7488, 7560, 7722, 7920, 8008, 8190, 8316, 8580, 8640, 8736, 9009, 9152,\
    \ 9240, 9360, 9504, 9828, 10010, 10080, 10296, 10395, 10560, 10920, 11088, 11232,\
    \ 11440, 11880, 12012, 12096, 12285, 12320, 12480, 12870, 13104, 13728, 13860,\
    \ 14040, 14560, 14784, 15015, 15120, 15444, 15840, 16016, 16380, 16632, 17160,\
    \ 17472, 18018, 18480, 18720, 19008, 19305, 19656, 20020, 20160, 20592, 20790,\
    \ 21840, 22176, 22464, 22880, 23760, 24024, 24570, 24640, 25740, 26208, 27027,\
    \ 27456, 27720, 28080, 29120, 30030, 30240, 30888, 31680, 32032, 32760, 33264,\
    \ 34320, 36036, 36960, 37440, 38610, 39312, 40040, 41184, 41580, 43680, 44352,\
    \ 45045, 45760, 47520, 48048, 49140, 51480, 52416, 54054, 55440, 56160, 60060,\
    \ 60480, 61776, 64064, 65520, 66528, 68640, 72072, 73920, 77220, 78624, 80080,\
    \ 82368, 83160, 87360, 90090, 95040, 96096, 98280, 102960, 108108, 110880, 112320,\
    \ 120120, 123552, 131040, 133056, 135135, 137280, 144144, 154440, 157248, 160160,\
    \ 166320, 180180, 192192, 196560, 205920, 216216, 221760, 240240, 247104, 262080,\
    \ 270270, 288288, 308880, 320320, 332640, 360360, 393120, 411840, 432432, 480480,\
    \ 540540, 576576, 617760, 665280, 720720, 786240, 864864, 960960, 1081080, 1235520,\
    \ 1441440, 1729728, 2162160, 2882880, 4324320, 8648640});\n      divisors = sieve.divisors(9999991);\n\
    \      std::sort(divisors.begin(), divisors.end());\n      assert_that(divisors\
    \ == std::vector<int>{1, 9999991});\n      divisors = sieve.divisors(10000000);\n\
    \      std::sort(divisors.begin(), divisors.end());\n      assert_that(divisors\
    \ == std::vector<int>{1, 2, 4, 5, 8, 10, 16, 20, 25, 32, 40, 50, 64, 80, 100,\
    \ 125, 128, 160, 200, 250, 320, 400, 500, 625, 640, 800, 1000, 1250, 1600, 2000,\
    \ 2500, 3125, 3200, 4000, 5000, 6250, 8000, 10000, 12500, 15625, 16000, 20000,\
    \ 25000, 31250, 40000, 50000, 62500, 78125, 80000, 100000, 125000, 156250, 200000,\
    \ 250000, 312500, 400000, 500000, 625000, 1000000, 1250000, 2000000, 2500000,\
    \ 5000000, 10000000});\n    }\n    {\n      assert_that(sieve.sorted_divisors(1)\
    \ == std::vector<int>{1});\n      assert_that(sieve.sorted_divisors(2) == std::vector<int>{1,\
    \ 2});\n      assert_that(sieve.sorted_divisors(8648640) == std::vector<int>{1,\
    \ 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 18, 20, 21, 22, 24, 26,\
    \ 27, 28, 30, 32, 33, 35, 36, 39, 40, 42, 44, 45, 48, 52, 54, 55, 56, 60, 63,\
    \ 64, 65, 66, 70, 72, 77, 78, 80, 84, 88, 90, 91, 96, 99, 104, 105, 108, 110,\
    \ 112, 117, 120, 126, 130, 132, 135, 140, 143, 144, 154, 156, 160, 165, 168, 176,\
    \ 180, 182, 189, 192, 195, 198, 208, 210, 216, 220, 224, 231, 234, 240, 252, 260,\
    \ 264, 270, 273, 280, 286, 288, 297, 308, 312, 315, 320, 330, 336, 351, 352, 360,\
    \ 364, 378, 385, 390, 396, 416, 420, 429, 432, 440, 448, 455, 462, 468, 480, 495,\
    \ 504, 520, 528, 540, 546, 560, 572, 576, 585, 594, 616, 624, 630, 660, 672, 693,\
    \ 702, 704, 715, 720, 728, 756, 770, 780, 792, 819, 832, 840, 858, 864, 880, 910,\
    \ 924, 936, 945, 960, 990, 1001, 1008, 1040, 1056, 1080, 1092, 1120, 1144, 1155,\
    \ 1170, 1188, 1232, 1248, 1260, 1287, 1320, 1344, 1365, 1386, 1404, 1430, 1440,\
    \ 1456, 1485, 1512, 1540, 1560, 1584, 1638, 1680, 1716, 1728, 1755, 1760, 1820,\
    \ 1848, 1872, 1890, 1980, 2002, 2016, 2079, 2080, 2112, 2145, 2160, 2184, 2240,\
    \ 2288, 2310, 2340, 2376, 2457, 2464, 2496, 2520, 2574, 2640, 2730, 2772, 2808,\
    \ 2860, 2880, 2912, 2970, 3003, 3024, 3080, 3120, 3168, 3276, 3360, 3432, 3465,\
    \ 3510, 3520, 3640, 3696, 3744, 3780, 3861, 3960, 4004, 4032, 4095, 4158, 4160,\
    \ 4290, 4320, 4368, 4576, 4620, 4680, 4752, 4914, 4928, 5005, 5040, 5148, 5280,\
    \ 5460, 5544, 5616, 5720, 5824, 5940, 6006, 6048, 6160, 6240, 6336, 6435, 6552,\
    \ 6720, 6864, 6930, 7020, 7280, 7392, 7488, 7560, 7722, 7920, 8008, 8190, 8316,\
    \ 8580, 8640, 8736, 9009, 9152, 9240, 9360, 9504, 9828, 10010, 10080, 10296, 10395,\
    \ 10560, 10920, 11088, 11232, 11440, 11880, 12012, 12096, 12285, 12320, 12480,\
    \ 12870, 13104, 13728, 13860, 14040, 14560, 14784, 15015, 15120, 15444, 15840,\
    \ 16016, 16380, 16632, 17160, 17472, 18018, 18480, 18720, 19008, 19305, 19656,\
    \ 20020, 20160, 20592, 20790, 21840, 22176, 22464, 22880, 23760, 24024, 24570,\
    \ 24640, 25740, 26208, 27027, 27456, 27720, 28080, 29120, 30030, 30240, 30888,\
    \ 31680, 32032, 32760, 33264, 34320, 36036, 36960, 37440, 38610, 39312, 40040,\
    \ 41184, 41580, 43680, 44352, 45045, 45760, 47520, 48048, 49140, 51480, 52416,\
    \ 54054, 55440, 56160, 60060, 60480, 61776, 64064, 65520, 66528, 68640, 72072,\
    \ 73920, 77220, 78624, 80080, 82368, 83160, 87360, 90090, 95040, 96096, 98280,\
    \ 102960, 108108, 110880, 112320, 120120, 123552, 131040, 133056, 135135, 137280,\
    \ 144144, 154440, 157248, 160160, 166320, 180180, 192192, 196560, 205920, 216216,\
    \ 221760, 240240, 247104, 262080, 270270, 288288, 308880, 320320, 332640, 360360,\
    \ 393120, 411840, 432432, 480480, 540540, 576576, 617760, 665280, 720720, 786240,\
    \ 864864, 960960, 1081080, 1235520, 1441440, 1729728, 2162160, 2882880, 4324320,\
    \ 8648640});\n      assert_that(sieve.sorted_divisors(9999991) == std::vector<int>{1,\
    \ 9999991});\n      assert_that(sieve.sorted_divisors(10000000) == std::vector<int>{1,\
    \ 2, 4, 5, 8, 10, 16, 20, 25, 32, 40, 50, 64, 80, 100, 125, 128, 160, 200, 250,\
    \ 320, 400, 500, 625, 640, 800, 1000, 1250, 1600, 2000, 2500, 3125, 3200, 4000,\
    \ 5000, 6250, 8000, 10000, 12500, 15625, 16000, 20000, 25000, 31250, 40000, 50000,\
    \ 62500, 78125, 80000, 100000, 125000, 156250, 200000, 250000, 312500, 400000,\
    \ 500000, 625000, 1000000, 1250000, 2000000, 2500000, 5000000, 10000000});\n \
    \   }\n  }\n\n  std::cout << \"Hello World\" << '\\n';\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\"\n\n\
    #include <iostream>\n#include <iterator>\n#include <tuple>\n#include <vector>\n\
    #include <algorithm>\n#include \"tools/assert_that.hpp\"\n#include \"tools/linear_sieve.hpp\"\
    \n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  {\n    tools::linear_sieve<int> sieve(10);\n    {\n      assert_that(!sieve.is_prime(1));\n\
    \      assert_that(sieve.is_prime(2));\n      assert_that(sieve.is_prime(3));\n\
    \      assert_that(!sieve.is_prime(4));\n      assert_that(sieve.is_prime(5));\n\
    \      assert_that(!sieve.is_prime(6));\n      assert_that(sieve.is_prime(7));\n\
    \      assert_that(!sieve.is_prime(8));\n      assert_that(!sieve.is_prime(9));\n\
    \      assert_that(!sieve.is_prime(10));\n    }\n    {\n      auto begin = sieve.prime_factor_range(1).begin(),\
    \ end = sieve.prime_factor_range(1).end(), it = begin;\n      assert_that(std::distance(begin,\
    \ end) == 0);\n      begin = sieve.prime_factor_range(2).begin(), end = sieve.prime_factor_range(2).end(),\
    \ it = begin;\n      assert_that(std::distance(begin, end) == 1);\n      assert_that(*(it++)\
    \ == 2);\n      begin = sieve.prime_factor_range(3).begin(), end = sieve.prime_factor_range(3).end(),\
    \ it = begin;\n      assert_that(std::distance(begin, end) == 1);\n      assert_that(*(it++)\
    \ == 3);\n      begin = sieve.prime_factor_range(4).begin(), end = sieve.prime_factor_range(4).end(),\
    \ it = begin;\n      assert_that(std::distance(begin, end) == 2);\n      assert_that(*(it++)\
    \ == 2);\n      assert_that(*(it++) == 2);\n      begin = sieve.prime_factor_range(5).begin(),\
    \ end = sieve.prime_factor_range(5).end(), it = begin;\n      assert_that(std::distance(begin,\
    \ end) == 1);\n      assert_that(*(it++) == 5);\n      begin = sieve.prime_factor_range(6).begin(),\
    \ end = sieve.prime_factor_range(6).end(), it = begin;\n      assert_that(std::distance(begin,\
    \ end) == 2);\n      assert_that(*(it++) == 2);\n      assert_that(*(it++) ==\
    \ 3);\n      begin = sieve.prime_factor_range(7).begin(), end = sieve.prime_factor_range(7).end(),\
    \ it = begin;\n      assert_that(std::distance(begin, end) == 1);\n      assert_that(*(it++)\
    \ == 7);\n      begin = sieve.prime_factor_range(8).begin(), end = sieve.prime_factor_range(8).end(),\
    \ it = begin;\n      assert_that(std::distance(begin, end) == 3);\n      assert_that(*(it++)\
    \ == 2);\n      assert_that(*(it++) == 2);\n      assert_that(*(it++) == 2);\n\
    \      begin = sieve.prime_factor_range(9).begin(), end = sieve.prime_factor_range(9).end(),\
    \ it = begin;\n      assert_that(std::distance(begin, end) == 2);\n      assert_that(*(it++)\
    \ == 3);\n      assert_that(*(it++) == 3);\n      begin = sieve.prime_factor_range(10).begin(),\
    \ end = sieve.prime_factor_range(10).end(), it = begin;\n      assert_that(std::distance(begin,\
    \ end) == 2);\n      assert_that(*(it++) == 2);\n      assert_that(*(it++) ==\
    \ 5);\n    }\n    {\n      auto begin = sieve.distinct_prime_factor_range(1).begin(),\
    \ end = sieve.distinct_prime_factor_range(1).end(), it = begin;\n      assert_that(std::distance(begin,\
    \ end) == 0);\n      begin = sieve.distinct_prime_factor_range(2).begin(), end\
    \ = sieve.distinct_prime_factor_range(2).end(), it = begin;\n      assert_that(std::distance(begin,\
    \ end) == 1);\n      assert_that(*(it++) == std::make_tuple(2, 1, 2));\n     \
    \ begin = sieve.distinct_prime_factor_range(3).begin(), end = sieve.distinct_prime_factor_range(3).end(),\
    \ it = begin;\n      assert_that(std::distance(begin, end) == 1);\n      assert_that(*(it++)\
    \ == std::make_tuple(3, 1, 3));\n      begin = sieve.distinct_prime_factor_range(4).begin(),\
    \ end = sieve.distinct_prime_factor_range(4).end(), it = begin;\n      assert_that(std::distance(begin,\
    \ end) == 1);\n      assert_that(*(it++) == std::make_tuple(2, 2, 4));\n     \
    \ begin = sieve.distinct_prime_factor_range(5).begin(), end = sieve.distinct_prime_factor_range(5).end(),\
    \ it = begin;\n      assert_that(std::distance(begin, end) == 1);\n      assert_that(*(it++)\
    \ == std::make_tuple(5, 1, 5));\n      begin = sieve.distinct_prime_factor_range(6).begin(),\
    \ end = sieve.distinct_prime_factor_range(6).end(), it = begin;\n      assert_that(std::distance(begin,\
    \ end) == 2);\n      assert_that(*(it++) == std::make_tuple(2, 1, 2));\n     \
    \ assert_that(*(it++) == std::make_tuple(3, 1, 3));\n      begin = sieve.distinct_prime_factor_range(7).begin(),\
    \ end = sieve.distinct_prime_factor_range(7).end(), it = begin;\n      assert_that(std::distance(begin,\
    \ end) == 1);\n      assert_that(*(it++) == std::make_tuple(7, 1, 7));\n     \
    \ begin = sieve.distinct_prime_factor_range(8).begin(), end = sieve.distinct_prime_factor_range(8).end(),\
    \ it = begin;\n      assert_that(std::distance(begin, end) == 1);\n      assert_that(*(it++)\
    \ == std::make_tuple(2, 3, 8));\n      begin = sieve.distinct_prime_factor_range(9).begin(),\
    \ end = sieve.distinct_prime_factor_range(9).end(), it = begin;\n      assert_that(std::distance(begin,\
    \ end) == 1);\n      assert_that(*(it++) == std::make_tuple(3, 2, 9));\n     \
    \ begin = sieve.distinct_prime_factor_range(10).begin(), end = sieve.distinct_prime_factor_range(10).end(),\
    \ it = begin;\n      assert_that(std::distance(begin, end) == 2);\n      assert_that(*(it++)\
    \ == std::make_tuple(2, 1, 2));\n      assert_that(*(it++) == std::make_tuple(5,\
    \ 1, 5));\n    }\n    {\n      auto begin = sieve.prime_range(1, 1).begin(), end\
    \ = sieve.prime_range(1, 1).end(), it = begin;\n      assert_that(std::distance(begin,\
    \ end) == 0);\n      begin = sieve.prime_range(1, 2).begin(), end = sieve.prime_range(1,\
    \ 2).end(), it = begin;\n      assert_that(std::distance(begin, end) == 1);\n\
    \      assert_that(*(it++) == 2);\n      begin = sieve.prime_range(1, 3).begin(),\
    \ end = sieve.prime_range(1, 3).end(), it = begin;\n      assert_that(std::distance(begin,\
    \ end) == 2);\n      assert_that(*(it++) == 2);\n      assert_that(*(it++) ==\
    \ 3);\n      begin = sieve.prime_range(1, 4).begin(), end = sieve.prime_range(1,\
    \ 4).end(), it = begin;\n      assert_that(std::distance(begin, end) == 2);\n\
    \      assert_that(*(it++) == 2);\n      assert_that(*(it++) == 3);\n      begin\
    \ = sieve.prime_range(1, 5).begin(), end = sieve.prime_range(1, 5).end(), it =\
    \ begin;\n      assert_that(std::distance(begin, end) == 3);\n      assert_that(*(it++)\
    \ == 2);\n      assert_that(*(it++) == 3);\n      assert_that(*(it++) == 5);\n\
    \      begin = sieve.prime_range(1, 6).begin(), end = sieve.prime_range(1, 6).end(),\
    \ it = begin;\n      assert_that(std::distance(begin, end) == 3);\n      assert_that(*(it++)\
    \ == 2);\n      assert_that(*(it++) == 3);\n      assert_that(*(it++) == 5);\n\
    \      begin = sieve.prime_range(1, 7).begin(), end = sieve.prime_range(1, 7).end(),\
    \ it = begin;\n      assert_that(std::distance(begin, end) == 4);\n      assert_that(*(it++)\
    \ == 2);\n      assert_that(*(it++) == 3);\n      assert_that(*(it++) == 5);\n\
    \      assert_that(*(it++) == 7);\n      begin = sieve.prime_range(1, 8).begin(),\
    \ end = sieve.prime_range(1, 8).end(), it = begin;\n      assert_that(std::distance(begin,\
    \ end) == 4);\n      assert_that(*(it++) == 2);\n      assert_that(*(it++) ==\
    \ 3);\n      assert_that(*(it++) == 5);\n      assert_that(*(it++) == 7);\n  \
    \    begin = sieve.prime_range(1, 9).begin(), end = sieve.prime_range(1, 9).end(),\
    \ it = begin;\n      assert_that(std::distance(begin, end) == 4);\n      assert_that(*(it++)\
    \ == 2);\n      assert_that(*(it++) == 3);\n      assert_that(*(it++) == 5);\n\
    \      assert_that(*(it++) == 7);\n      begin = sieve.prime_range(1, 10).begin(),\
    \ end = sieve.prime_range(1, 10).end(), it = begin;\n      assert_that(std::distance(begin,\
    \ end) == 4);\n      assert_that(*(it++) == 2);\n      assert_that(*(it++) ==\
    \ 3);\n      assert_that(*(it++) == 5);\n      assert_that(*(it++) == 7);\n  \
    \    begin = sieve.prime_range(2, 2).begin(), end = sieve.prime_range(2, 2).end(),\
    \ it = begin;\n      assert_that(std::distance(begin, end) == 1);\n      assert_that(*(it++)\
    \ == 2);\n      begin = sieve.prime_range(2, 3).begin(), end = sieve.prime_range(2,\
    \ 3).end(), it = begin;\n      assert_that(std::distance(begin, end) == 2);\n\
    \      assert_that(*(it++) == 2);\n      assert_that(*(it++) == 3);\n      begin\
    \ = sieve.prime_range(2, 4).begin(), end = sieve.prime_range(2, 4).end(), it =\
    \ begin;\n      assert_that(std::distance(begin, end) == 2);\n      assert_that(*(it++)\
    \ == 2);\n      assert_that(*(it++) == 3);\n      begin = sieve.prime_range(2,\
    \ 5).begin(), end = sieve.prime_range(2, 5).end(), it = begin;\n      assert_that(std::distance(begin,\
    \ end) == 3);\n      assert_that(*(it++) == 2);\n      assert_that(*(it++) ==\
    \ 3);\n      assert_that(*(it++) == 5);\n      begin = sieve.prime_range(2, 6).begin(),\
    \ end = sieve.prime_range(2, 6).end(), it = begin;\n      assert_that(std::distance(begin,\
    \ end) == 3);\n      assert_that(*(it++) == 2);\n      assert_that(*(it++) ==\
    \ 3);\n      assert_that(*(it++) == 5);\n      begin = sieve.prime_range(2, 7).begin(),\
    \ end = sieve.prime_range(2, 7).end(), it = begin;\n      assert_that(std::distance(begin,\
    \ end) == 4);\n      assert_that(*(it++) == 2);\n      assert_that(*(it++) ==\
    \ 3);\n      assert_that(*(it++) == 5);\n      assert_that(*(it++) == 7);\n  \
    \    begin = sieve.prime_range(2, 8).begin(), end = sieve.prime_range(2, 8).end(),\
    \ it = begin;\n      assert_that(std::distance(begin, end) == 4);\n      assert_that(*(it++)\
    \ == 2);\n      assert_that(*(it++) == 3);\n      assert_that(*(it++) == 5);\n\
    \      assert_that(*(it++) == 7);\n      begin = sieve.prime_range(2, 9).begin(),\
    \ end = sieve.prime_range(2, 9).end(), it = begin;\n      assert_that(std::distance(begin,\
    \ end) == 4);\n      assert_that(*(it++) == 2);\n      assert_that(*(it++) ==\
    \ 3);\n      assert_that(*(it++) == 5);\n      assert_that(*(it++) == 7);\n  \
    \    begin = sieve.prime_range(2, 10).begin(), end = sieve.prime_range(2, 10).end(),\
    \ it = begin;\n      assert_that(std::distance(begin, end) == 4);\n      assert_that(*(it++)\
    \ == 2);\n      assert_that(*(it++) == 3);\n      assert_that(*(it++) == 5);\n\
    \      assert_that(*(it++) == 7);\n      begin = sieve.prime_range(3, 3).begin(),\
    \ end = sieve.prime_range(3, 3).end(), it = begin;\n      assert_that(std::distance(begin,\
    \ end) == 1);\n      assert_that(*(it++) == 3);\n      begin = sieve.prime_range(3,\
    \ 4).begin(), end = sieve.prime_range(3, 4).end(), it = begin;\n      assert_that(std::distance(begin,\
    \ end) == 1);\n      assert_that(*(it++) == 3);\n      begin = sieve.prime_range(3,\
    \ 5).begin(), end = sieve.prime_range(3, 5).end(), it = begin;\n      assert_that(std::distance(begin,\
    \ end) == 2);\n      assert_that(*(it++) == 3);\n      assert_that(*(it++) ==\
    \ 5);\n      begin = sieve.prime_range(3, 6).begin(), end = sieve.prime_range(3,\
    \ 6).end(), it = begin;\n      assert_that(std::distance(begin, end) == 2);\n\
    \      assert_that(*(it++) == 3);\n      assert_that(*(it++) == 5);\n      begin\
    \ = sieve.prime_range(3, 7).begin(), end = sieve.prime_range(3, 7).end(), it =\
    \ begin;\n      assert_that(std::distance(begin, end) == 3);\n      assert_that(*(it++)\
    \ == 3);\n      assert_that(*(it++) == 5);\n      assert_that(*(it++) == 7);\n\
    \      begin = sieve.prime_range(3, 8).begin(), end = sieve.prime_range(3, 8).end(),\
    \ it = begin;\n      assert_that(std::distance(begin, end) == 3);\n      assert_that(*(it++)\
    \ == 3);\n      assert_that(*(it++) == 5);\n      assert_that(*(it++) == 7);\n\
    \      begin = sieve.prime_range(3, 9).begin(), end = sieve.prime_range(3, 9).end(),\
    \ it = begin;\n      assert_that(std::distance(begin, end) == 3);\n      assert_that(*(it++)\
    \ == 3);\n      assert_that(*(it++) == 5);\n      assert_that(*(it++) == 7);\n\
    \      begin = sieve.prime_range(3, 10).begin(), end = sieve.prime_range(3, 10).end(),\
    \ it = begin;\n      assert_that(std::distance(begin, end) == 3);\n      assert_that(*(it++)\
    \ == 3);\n      assert_that(*(it++) == 5);\n      assert_that(*(it++) == 7);\n\
    \      begin = sieve.prime_range(4, 4).begin(), end = sieve.prime_range(4, 4).end(),\
    \ it = begin;\n      assert_that(std::distance(begin, end) == 0);\n      begin\
    \ = sieve.prime_range(4, 5).begin(), end = sieve.prime_range(4, 5).end(), it =\
    \ begin;\n      assert_that(std::distance(begin, end) == 1);\n      assert_that(*(it++)\
    \ == 5);\n      begin = sieve.prime_range(4, 6).begin(), end = sieve.prime_range(4,\
    \ 6).end(), it = begin;\n      assert_that(std::distance(begin, end) == 1);\n\
    \      assert_that(*(it++) == 5);\n      begin = sieve.prime_range(4, 7).begin(),\
    \ end = sieve.prime_range(4, 7).end(), it = begin;\n      assert_that(std::distance(begin,\
    \ end) == 2);\n      assert_that(*(it++) == 5);\n      assert_that(*(it++) ==\
    \ 7);\n      begin = sieve.prime_range(4, 8).begin(), end = sieve.prime_range(4,\
    \ 8).end(), it = begin;\n      assert_that(std::distance(begin, end) == 2);\n\
    \      assert_that(*(it++) == 5);\n      assert_that(*(it++) == 7);\n      begin\
    \ = sieve.prime_range(4, 9).begin(), end = sieve.prime_range(4, 9).end(), it =\
    \ begin;\n      assert_that(std::distance(begin, end) == 2);\n      assert_that(*(it++)\
    \ == 5);\n      assert_that(*(it++) == 7);\n      begin = sieve.prime_range(4,\
    \ 10).begin(), end = sieve.prime_range(4, 10).end(), it = begin;\n      assert_that(std::distance(begin,\
    \ end) == 2);\n      assert_that(*(it++) == 5);\n      assert_that(*(it++) ==\
    \ 7);\n      begin = sieve.prime_range(5, 5).begin(), end = sieve.prime_range(5,\
    \ 5).end(), it = begin;\n      assert_that(std::distance(begin, end) == 1);\n\
    \      assert_that(*(it++) == 5);\n      begin = sieve.prime_range(5, 6).begin(),\
    \ end = sieve.prime_range(5, 6).end(), it = begin;\n      assert_that(std::distance(begin,\
    \ end) == 1);\n      assert_that(*(it++) == 5);\n      begin = sieve.prime_range(5,\
    \ 7).begin(), end = sieve.prime_range(5, 7).end(), it = begin;\n      assert_that(std::distance(begin,\
    \ end) == 2);\n      assert_that(*(it++) == 5);\n      assert_that(*(it++) ==\
    \ 7);\n      begin = sieve.prime_range(5, 8).begin(), end = sieve.prime_range(5,\
    \ 8).end(), it = begin;\n      assert_that(std::distance(begin, end) == 2);\n\
    \      assert_that(*(it++) == 5);\n      assert_that(*(it++) == 7);\n      begin\
    \ = sieve.prime_range(5, 9).begin(), end = sieve.prime_range(5, 9).end(), it =\
    \ begin;\n      assert_that(std::distance(begin, end) == 2);\n      assert_that(*(it++)\
    \ == 5);\n      assert_that(*(it++) == 7);\n      begin = sieve.prime_range(5,\
    \ 10).begin(), end = sieve.prime_range(5, 10).end(), it = begin;\n      assert_that(std::distance(begin,\
    \ end) == 2);\n      assert_that(*(it++) == 5);\n      assert_that(*(it++) ==\
    \ 7);\n      begin = sieve.prime_range(6, 6).begin(), end = sieve.prime_range(6,\
    \ 6).end(), it = begin;\n      assert_that(std::distance(begin, end) == 0);\n\
    \      begin = sieve.prime_range(6, 7).begin(), end = sieve.prime_range(6, 7).end(),\
    \ it = begin;\n      assert_that(std::distance(begin, end) == 1);\n      assert_that(*(it++)\
    \ == 7);\n      begin = sieve.prime_range(6, 8).begin(), end = sieve.prime_range(6,\
    \ 8).end(), it = begin;\n      assert_that(std::distance(begin, end) == 1);\n\
    \      assert_that(*(it++) == 7);\n      begin = sieve.prime_range(6, 9).begin(),\
    \ end = sieve.prime_range(6, 9).end(), it = begin;\n      assert_that(std::distance(begin,\
    \ end) == 1);\n      assert_that(*(it++) == 7);\n      begin = sieve.prime_range(6,\
    \ 10).begin(), end = sieve.prime_range(6, 10).end(), it = begin;\n      assert_that(std::distance(begin,\
    \ end) == 1);\n      assert_that(*(it++) == 7);\n      begin = sieve.prime_range(7,\
    \ 7).begin(), end = sieve.prime_range(7, 7).end(), it = begin;\n      assert_that(std::distance(begin,\
    \ end) == 1);\n      assert_that(*(it++) == 7);\n      begin = sieve.prime_range(7,\
    \ 8).begin(), end = sieve.prime_range(7, 8).end(), it = begin;\n      assert_that(std::distance(begin,\
    \ end) == 1);\n      assert_that(*(it++) == 7);\n      begin = sieve.prime_range(7,\
    \ 9).begin(), end = sieve.prime_range(7, 9).end(), it = begin;\n      assert_that(std::distance(begin,\
    \ end) == 1);\n      assert_that(*(it++) == 7);\n      begin = sieve.prime_range(7,\
    \ 10).begin(), end = sieve.prime_range(7, 10).end(), it = begin;\n      assert_that(std::distance(begin,\
    \ end) == 1);\n      assert_that(*(it++) == 7);\n      begin = sieve.prime_range(8,\
    \ 8).begin(), end = sieve.prime_range(8, 8).end(), it = begin;\n      assert_that(std::distance(begin,\
    \ end) == 0);\n      begin = sieve.prime_range(8, 9).begin(), end = sieve.prime_range(8,\
    \ 9).end(), it = begin;\n      assert_that(std::distance(begin, end) == 0);\n\
    \      begin = sieve.prime_range(8, 10).begin(), end = sieve.prime_range(8, 10).end(),\
    \ it = begin;\n      assert_that(std::distance(begin, end) == 0);\n      begin\
    \ = sieve.prime_range(9, 9).begin(), end = sieve.prime_range(9, 9).end(), it =\
    \ begin;\n      assert_that(std::distance(begin, end) == 0);\n      begin = sieve.prime_range(9,\
    \ 10).begin(), end = sieve.prime_range(9, 10).end(), it = begin;\n      assert_that(std::distance(begin,\
    \ end) == 0);\n      begin = sieve.prime_range(10, 10).begin(), end = sieve.prime_range(10,\
    \ 10).end(), it = begin;\n      assert_that(std::distance(begin, end) == 0);\n\
    \    }\n    {\n      auto divisors = sieve.divisors(1);\n      std::sort(divisors.begin(),\
    \ divisors.end());\n      assert_that(divisors == std::vector<int>{1});\n    \
    \  divisors = sieve.divisors(2);\n      std::sort(divisors.begin(), divisors.end());\n\
    \      assert_that(divisors == std::vector<int>{1, 2});\n      divisors = sieve.divisors(3);\n\
    \      std::sort(divisors.begin(), divisors.end());\n      assert_that(divisors\
    \ == std::vector<int>{1, 3});\n      divisors = sieve.divisors(4);\n      std::sort(divisors.begin(),\
    \ divisors.end());\n      assert_that(divisors == std::vector<int>{1, 2, 4});\n\
    \      divisors = sieve.divisors(5);\n      std::sort(divisors.begin(), divisors.end());\n\
    \      assert_that(divisors == std::vector<int>{1, 5});\n      divisors = sieve.divisors(6);\n\
    \      std::sort(divisors.begin(), divisors.end());\n      assert_that(divisors\
    \ == std::vector<int>{1, 2, 3, 6});\n      divisors = sieve.divisors(7);\n   \
    \   std::sort(divisors.begin(), divisors.end());\n      assert_that(divisors ==\
    \ std::vector<int>{1, 7});\n      divisors = sieve.divisors(8);\n      std::sort(divisors.begin(),\
    \ divisors.end());\n      assert_that(divisors == std::vector<int>{1, 2, 4, 8});\n\
    \      divisors = sieve.divisors(9);\n      std::sort(divisors.begin(), divisors.end());\n\
    \      assert_that(divisors == std::vector<int>{1, 3, 9});\n      divisors = sieve.divisors(10);\n\
    \      std::sort(divisors.begin(), divisors.end());\n      assert_that(divisors\
    \ == std::vector<int>{1, 2, 5, 10});\n    }\n    {\n      assert_that(sieve.sorted_divisors(1)\
    \ == std::vector<int>{1});\n      assert_that(sieve.sorted_divisors(2) == std::vector<int>{1,\
    \ 2});\n      assert_that(sieve.sorted_divisors(3) == std::vector<int>{1, 3});\n\
    \      assert_that(sieve.sorted_divisors(4) == std::vector<int>{1, 2, 4});\n \
    \     assert_that(sieve.sorted_divisors(5) == std::vector<int>{1, 5});\n     \
    \ assert_that(sieve.sorted_divisors(6) == std::vector<int>{1, 2, 3, 6});\n   \
    \   assert_that(sieve.sorted_divisors(7) == std::vector<int>{1, 7});\n      assert_that(sieve.sorted_divisors(8)\
    \ == std::vector<int>{1, 2, 4, 8});\n      assert_that(sieve.sorted_divisors(9)\
    \ == std::vector<int>{1, 3, 9});\n      assert_that(sieve.sorted_divisors(10)\
    \ == std::vector<int>{1, 2, 5, 10});\n    }\n  }\n  {\n    tools::linear_sieve<int>\
    \ sieve(1);\n    {\n      assert_that(!sieve.is_prime(1));\n    }\n    {\n   \
    \   auto begin = sieve.prime_factor_range(1).begin(), end = sieve.prime_factor_range(1).end();\n\
    \      assert_that(std::distance(begin, end) == 0);\n    }\n    {\n      auto\
    \ begin = sieve.distinct_prime_factor_range(1).begin(), end = sieve.distinct_prime_factor_range(1).end();\n\
    \      assert_that(std::distance(begin, end) == 0);\n    }\n    {\n      auto\
    \ begin = sieve.prime_range(1, 1).begin(), end = sieve.prime_range(1, 1).end();\n\
    \      assert_that(std::distance(begin, end) == 0);\n    }\n    {\n      auto\
    \ divisors = sieve.divisors(1);\n      std::sort(divisors.begin(), divisors.end());\n\
    \      assert_that(divisors == std::vector<int>{1});\n    }\n    {\n      assert_that(sieve.sorted_divisors(1)\
    \ == std::vector<int>{1});\n    }\n  }\n  {\n    tools::linear_sieve<int> sieve(2);\n\
    \    {\n      assert_that(!sieve.is_prime(1));\n      assert_that(sieve.is_prime(2));\n\
    \    }\n    {\n      auto begin = sieve.prime_factor_range(1).begin(), end = sieve.prime_factor_range(1).end(),\
    \ it = begin;\n      assert_that(std::distance(begin, end) == 0);\n      begin\
    \ = sieve.prime_factor_range(2).begin(), end = sieve.prime_factor_range(2).end(),\
    \ it = begin;\n      assert_that(std::distance(begin, end) == 1);\n      assert_that(*(it++)\
    \ == 2);\n    }\n    {\n      auto begin = sieve.distinct_prime_factor_range(1).begin(),\
    \ end = sieve.distinct_prime_factor_range(1).end(), it = begin;\n      assert_that(std::distance(begin,\
    \ end) == 0);\n      begin = sieve.distinct_prime_factor_range(2).begin(), end\
    \ = sieve.distinct_prime_factor_range(2).end(), it = begin;\n      assert_that(std::distance(begin,\
    \ end) == 1);\n      assert_that(*(it++) == std::make_tuple(2, 1, 2));\n    }\n\
    \    {\n      auto begin = sieve.prime_range(1, 1).begin(), end = sieve.prime_range(1,\
    \ 1).end(), it = begin;\n      assert_that(std::distance(begin, end) == 0);\n\
    \      begin = sieve.prime_range(1, 2).begin(), end = sieve.prime_range(1, 2).end(),\
    \ it = begin;\n      assert_that(std::distance(begin, end) == 1);\n      assert_that(*(it++)\
    \ == 2);\n      begin = sieve.prime_range(2, 2).begin(), end = sieve.prime_range(2,\
    \ 2).end(), it = begin;\n      assert_that(std::distance(begin, end) == 1);\n\
    \      assert_that(*(it++) == 2);\n    }\n    {\n      auto divisors = sieve.divisors(1);\n\
    \      std::sort(divisors.begin(), divisors.end());\n      assert_that(divisors\
    \ == std::vector<int>{1});\n      divisors = sieve.divisors(2);\n      std::sort(divisors.begin(),\
    \ divisors.end());\n      assert_that(divisors == std::vector<int>{1, 2});\n \
    \   }\n    {\n      assert_that(sieve.sorted_divisors(1) == std::vector<int>{1});\n\
    \      assert_that(sieve.sorted_divisors(2) == std::vector<int>{1, 2});\n    }\n\
    \  }\n  {\n    tools::linear_sieve<int> sieve(10000000);\n    {\n      assert_that(!sieve.is_prime(1));\n\
    \      assert_that(sieve.is_prime(2));\n      assert_that(sieve.is_prime(9999991));\n\
    \      assert_that(!sieve.is_prime(10000000));\n    }\n    {\n      auto begin\
    \ = sieve.prime_factor_range(1).begin(), end = sieve.prime_factor_range(1).end(),\
    \ it = begin;\n      assert_that(std::distance(begin, end) == 0);\n      begin\
    \ = sieve.prime_factor_range(2).begin(), end = sieve.prime_factor_range(2).end(),\
    \ it = begin;\n      assert_that(std::distance(begin, end) == 1);\n      assert_that(*(it++)\
    \ == 2);\n      begin = sieve.prime_factor_range(8648640).begin(), end = sieve.prime_factor_range(8648640).end(),\
    \ it = begin;\n      assert_that(std::distance(begin, end) == 13);\n      assert_that(*(it++)\
    \ == 2);\n      assert_that(*(it++) == 2);\n      assert_that(*(it++) == 2);\n\
    \      assert_that(*(it++) == 2);\n      assert_that(*(it++) == 2);\n      assert_that(*(it++)\
    \ == 2);\n      assert_that(*(it++) == 3);\n      assert_that(*(it++) == 3);\n\
    \      assert_that(*(it++) == 3);\n      assert_that(*(it++) == 5);\n      assert_that(*(it++)\
    \ == 7);\n      assert_that(*(it++) == 11);\n      assert_that(*(it++) == 13);\n\
    \      begin = sieve.prime_factor_range(9999991).begin(), end = sieve.prime_factor_range(9999991).end(),\
    \ it = begin;\n      assert_that(std::distance(begin, end) == 1);\n      assert_that(*(it++)\
    \ == 9999991);\n      begin = sieve.prime_factor_range(10000000).begin(), end\
    \ = sieve.prime_factor_range(10000000).end(), it = begin;\n      assert_that(std::distance(begin,\
    \ end) == 14);\n      assert_that(*(it++) == 2);\n      assert_that(*(it++) ==\
    \ 2);\n      assert_that(*(it++) == 2);\n      assert_that(*(it++) == 2);\n  \
    \    assert_that(*(it++) == 2);\n      assert_that(*(it++) == 2);\n      assert_that(*(it++)\
    \ == 2);\n      assert_that(*(it++) == 5);\n      assert_that(*(it++) == 5);\n\
    \      assert_that(*(it++) == 5);\n      assert_that(*(it++) == 5);\n      assert_that(*(it++)\
    \ == 5);\n      assert_that(*(it++) == 5);\n      assert_that(*(it++) == 5);\n\
    \    }\n    {\n      auto begin = sieve.distinct_prime_factor_range(1).begin(),\
    \ end = sieve.distinct_prime_factor_range(1).end(), it = begin;\n      assert_that(std::distance(begin,\
    \ end) == 0);\n      begin = sieve.distinct_prime_factor_range(2).begin(), end\
    \ = sieve.distinct_prime_factor_range(2).end(), it = begin;\n      assert_that(std::distance(begin,\
    \ end) == 1);\n      assert_that(*(it++) == std::make_tuple(2, 1, 2));\n     \
    \ begin = sieve.distinct_prime_factor_range(8648640).begin(), end = sieve.distinct_prime_factor_range(8648640).end(),\
    \ it = begin;\n      assert_that(std::distance(begin, end) == 6);\n      assert_that(*(it++)\
    \ == std::make_tuple(2, 6, 64));\n      assert_that(*(it++) == std::make_tuple(3,\
    \ 3, 27));\n      assert_that(*(it++) == std::make_tuple(5, 1, 5));\n      assert_that(*(it++)\
    \ == std::make_tuple(7, 1, 7));\n      assert_that(*(it++) == std::make_tuple(11,\
    \ 1, 11));\n      assert_that(*(it++) == std::make_tuple(13, 1, 13));\n      begin\
    \ = sieve.distinct_prime_factor_range(9999991).begin(), end = sieve.distinct_prime_factor_range(9999991).end(),\
    \ it = begin;\n      assert_that(std::distance(begin, end) == 1);\n      assert_that(*(it++)\
    \ == std::make_tuple(9999991, 1, 9999991));\n      begin = sieve.distinct_prime_factor_range(10000000).begin(),\
    \ end = sieve.distinct_prime_factor_range(10000000).end(), it = begin;\n     \
    \ assert_that(std::distance(begin, end) == 2);\n      assert_that(*(it++) == std::make_tuple(2,\
    \ 7, 128));\n      assert_that(*(it++) == std::make_tuple(5, 7, 78125));\n   \
    \ }\n    {\n      auto begin = sieve.prime_range(1, 1).begin(), end = sieve.prime_range(1,\
    \ 1).end(), it = begin;\n      assert_that(std::distance(begin, end) == 0);\n\
    \      begin = sieve.prime_range(1, 2).begin(), end = sieve.prime_range(1, 2).end(),\
    \ it = begin;\n      assert_that(std::distance(begin, end) == 1);\n      assert_that(*(it++)\
    \ == 2);\n      begin = sieve.prime_range(1, 10000000).begin(), end = sieve.prime_range(1,\
    \ 10000000).end(), it = begin;\n      assert_that(std::distance(begin, end) ==\
    \ 664579);\n      assert_that(*it == 2);\n      it = std::next(it, 664578);\n\
    \      assert_that(*it == 9999991);\n    }\n    {\n      auto divisors = sieve.divisors(1);\n\
    \      std::sort(divisors.begin(), divisors.end());\n      assert_that(divisors\
    \ == std::vector<int>{1});\n      divisors = sieve.divisors(2);\n      std::sort(divisors.begin(),\
    \ divisors.end());\n      assert_that(divisors == std::vector<int>{1, 2});\n \
    \     divisors = sieve.divisors(8648640);\n      std::sort(divisors.begin(), divisors.end());\n\
    \      assert_that(divisors == std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10,\
    \ 11, 12, 13, 14, 15, 16, 18, 20, 21, 22, 24, 26, 27, 28, 30, 32, 33, 35, 36,\
    \ 39, 40, 42, 44, 45, 48, 52, 54, 55, 56, 60, 63, 64, 65, 66, 70, 72, 77, 78,\
    \ 80, 84, 88, 90, 91, 96, 99, 104, 105, 108, 110, 112, 117, 120, 126, 130, 132,\
    \ 135, 140, 143, 144, 154, 156, 160, 165, 168, 176, 180, 182, 189, 192, 195, 198,\
    \ 208, 210, 216, 220, 224, 231, 234, 240, 252, 260, 264, 270, 273, 280, 286, 288,\
    \ 297, 308, 312, 315, 320, 330, 336, 351, 352, 360, 364, 378, 385, 390, 396, 416,\
    \ 420, 429, 432, 440, 448, 455, 462, 468, 480, 495, 504, 520, 528, 540, 546, 560,\
    \ 572, 576, 585, 594, 616, 624, 630, 660, 672, 693, 702, 704, 715, 720, 728, 756,\
    \ 770, 780, 792, 819, 832, 840, 858, 864, 880, 910, 924, 936, 945, 960, 990, 1001,\
    \ 1008, 1040, 1056, 1080, 1092, 1120, 1144, 1155, 1170, 1188, 1232, 1248, 1260,\
    \ 1287, 1320, 1344, 1365, 1386, 1404, 1430, 1440, 1456, 1485, 1512, 1540, 1560,\
    \ 1584, 1638, 1680, 1716, 1728, 1755, 1760, 1820, 1848, 1872, 1890, 1980, 2002,\
    \ 2016, 2079, 2080, 2112, 2145, 2160, 2184, 2240, 2288, 2310, 2340, 2376, 2457,\
    \ 2464, 2496, 2520, 2574, 2640, 2730, 2772, 2808, 2860, 2880, 2912, 2970, 3003,\
    \ 3024, 3080, 3120, 3168, 3276, 3360, 3432, 3465, 3510, 3520, 3640, 3696, 3744,\
    \ 3780, 3861, 3960, 4004, 4032, 4095, 4158, 4160, 4290, 4320, 4368, 4576, 4620,\
    \ 4680, 4752, 4914, 4928, 5005, 5040, 5148, 5280, 5460, 5544, 5616, 5720, 5824,\
    \ 5940, 6006, 6048, 6160, 6240, 6336, 6435, 6552, 6720, 6864, 6930, 7020, 7280,\
    \ 7392, 7488, 7560, 7722, 7920, 8008, 8190, 8316, 8580, 8640, 8736, 9009, 9152,\
    \ 9240, 9360, 9504, 9828, 10010, 10080, 10296, 10395, 10560, 10920, 11088, 11232,\
    \ 11440, 11880, 12012, 12096, 12285, 12320, 12480, 12870, 13104, 13728, 13860,\
    \ 14040, 14560, 14784, 15015, 15120, 15444, 15840, 16016, 16380, 16632, 17160,\
    \ 17472, 18018, 18480, 18720, 19008, 19305, 19656, 20020, 20160, 20592, 20790,\
    \ 21840, 22176, 22464, 22880, 23760, 24024, 24570, 24640, 25740, 26208, 27027,\
    \ 27456, 27720, 28080, 29120, 30030, 30240, 30888, 31680, 32032, 32760, 33264,\
    \ 34320, 36036, 36960, 37440, 38610, 39312, 40040, 41184, 41580, 43680, 44352,\
    \ 45045, 45760, 47520, 48048, 49140, 51480, 52416, 54054, 55440, 56160, 60060,\
    \ 60480, 61776, 64064, 65520, 66528, 68640, 72072, 73920, 77220, 78624, 80080,\
    \ 82368, 83160, 87360, 90090, 95040, 96096, 98280, 102960, 108108, 110880, 112320,\
    \ 120120, 123552, 131040, 133056, 135135, 137280, 144144, 154440, 157248, 160160,\
    \ 166320, 180180, 192192, 196560, 205920, 216216, 221760, 240240, 247104, 262080,\
    \ 270270, 288288, 308880, 320320, 332640, 360360, 393120, 411840, 432432, 480480,\
    \ 540540, 576576, 617760, 665280, 720720, 786240, 864864, 960960, 1081080, 1235520,\
    \ 1441440, 1729728, 2162160, 2882880, 4324320, 8648640});\n      divisors = sieve.divisors(9999991);\n\
    \      std::sort(divisors.begin(), divisors.end());\n      assert_that(divisors\
    \ == std::vector<int>{1, 9999991});\n      divisors = sieve.divisors(10000000);\n\
    \      std::sort(divisors.begin(), divisors.end());\n      assert_that(divisors\
    \ == std::vector<int>{1, 2, 4, 5, 8, 10, 16, 20, 25, 32, 40, 50, 64, 80, 100,\
    \ 125, 128, 160, 200, 250, 320, 400, 500, 625, 640, 800, 1000, 1250, 1600, 2000,\
    \ 2500, 3125, 3200, 4000, 5000, 6250, 8000, 10000, 12500, 15625, 16000, 20000,\
    \ 25000, 31250, 40000, 50000, 62500, 78125, 80000, 100000, 125000, 156250, 200000,\
    \ 250000, 312500, 400000, 500000, 625000, 1000000, 1250000, 2000000, 2500000,\
    \ 5000000, 10000000});\n    }\n    {\n      assert_that(sieve.sorted_divisors(1)\
    \ == std::vector<int>{1});\n      assert_that(sieve.sorted_divisors(2) == std::vector<int>{1,\
    \ 2});\n      assert_that(sieve.sorted_divisors(8648640) == std::vector<int>{1,\
    \ 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 18, 20, 21, 22, 24, 26,\
    \ 27, 28, 30, 32, 33, 35, 36, 39, 40, 42, 44, 45, 48, 52, 54, 55, 56, 60, 63,\
    \ 64, 65, 66, 70, 72, 77, 78, 80, 84, 88, 90, 91, 96, 99, 104, 105, 108, 110,\
    \ 112, 117, 120, 126, 130, 132, 135, 140, 143, 144, 154, 156, 160, 165, 168, 176,\
    \ 180, 182, 189, 192, 195, 198, 208, 210, 216, 220, 224, 231, 234, 240, 252, 260,\
    \ 264, 270, 273, 280, 286, 288, 297, 308, 312, 315, 320, 330, 336, 351, 352, 360,\
    \ 364, 378, 385, 390, 396, 416, 420, 429, 432, 440, 448, 455, 462, 468, 480, 495,\
    \ 504, 520, 528, 540, 546, 560, 572, 576, 585, 594, 616, 624, 630, 660, 672, 693,\
    \ 702, 704, 715, 720, 728, 756, 770, 780, 792, 819, 832, 840, 858, 864, 880, 910,\
    \ 924, 936, 945, 960, 990, 1001, 1008, 1040, 1056, 1080, 1092, 1120, 1144, 1155,\
    \ 1170, 1188, 1232, 1248, 1260, 1287, 1320, 1344, 1365, 1386, 1404, 1430, 1440,\
    \ 1456, 1485, 1512, 1540, 1560, 1584, 1638, 1680, 1716, 1728, 1755, 1760, 1820,\
    \ 1848, 1872, 1890, 1980, 2002, 2016, 2079, 2080, 2112, 2145, 2160, 2184, 2240,\
    \ 2288, 2310, 2340, 2376, 2457, 2464, 2496, 2520, 2574, 2640, 2730, 2772, 2808,\
    \ 2860, 2880, 2912, 2970, 3003, 3024, 3080, 3120, 3168, 3276, 3360, 3432, 3465,\
    \ 3510, 3520, 3640, 3696, 3744, 3780, 3861, 3960, 4004, 4032, 4095, 4158, 4160,\
    \ 4290, 4320, 4368, 4576, 4620, 4680, 4752, 4914, 4928, 5005, 5040, 5148, 5280,\
    \ 5460, 5544, 5616, 5720, 5824, 5940, 6006, 6048, 6160, 6240, 6336, 6435, 6552,\
    \ 6720, 6864, 6930, 7020, 7280, 7392, 7488, 7560, 7722, 7920, 8008, 8190, 8316,\
    \ 8580, 8640, 8736, 9009, 9152, 9240, 9360, 9504, 9828, 10010, 10080, 10296, 10395,\
    \ 10560, 10920, 11088, 11232, 11440, 11880, 12012, 12096, 12285, 12320, 12480,\
    \ 12870, 13104, 13728, 13860, 14040, 14560, 14784, 15015, 15120, 15444, 15840,\
    \ 16016, 16380, 16632, 17160, 17472, 18018, 18480, 18720, 19008, 19305, 19656,\
    \ 20020, 20160, 20592, 20790, 21840, 22176, 22464, 22880, 23760, 24024, 24570,\
    \ 24640, 25740, 26208, 27027, 27456, 27720, 28080, 29120, 30030, 30240, 30888,\
    \ 31680, 32032, 32760, 33264, 34320, 36036, 36960, 37440, 38610, 39312, 40040,\
    \ 41184, 41580, 43680, 44352, 45045, 45760, 47520, 48048, 49140, 51480, 52416,\
    \ 54054, 55440, 56160, 60060, 60480, 61776, 64064, 65520, 66528, 68640, 72072,\
    \ 73920, 77220, 78624, 80080, 82368, 83160, 87360, 90090, 95040, 96096, 98280,\
    \ 102960, 108108, 110880, 112320, 120120, 123552, 131040, 133056, 135135, 137280,\
    \ 144144, 154440, 157248, 160160, 166320, 180180, 192192, 196560, 205920, 216216,\
    \ 221760, 240240, 247104, 262080, 270270, 288288, 308880, 320320, 332640, 360360,\
    \ 393120, 411840, 432432, 480480, 540540, 576576, 617760, 665280, 720720, 786240,\
    \ 864864, 960960, 1081080, 1235520, 1441440, 1729728, 2162160, 2882880, 4324320,\
    \ 8648640});\n      assert_that(sieve.sorted_divisors(9999991) == std::vector<int>{1,\
    \ 9999991});\n      assert_that(sieve.sorted_divisors(10000000) == std::vector<int>{1,\
    \ 2, 4, 5, 8, 10, 16, 20, 25, 32, 40, 50, 64, 80, 100, 125, 128, 160, 200, 250,\
    \ 320, 400, 500, 625, 640, 800, 1000, 1250, 1600, 2000, 2500, 3125, 3200, 4000,\
    \ 5000, 6250, 8000, 10000, 12500, 15625, 16000, 20000, 25000, 31250, 40000, 50000,\
    \ 62500, 78125, 80000, 100000, 125000, 156250, 200000, 250000, 312500, 400000,\
    \ 500000, 625000, 1000000, 1250000, 2000000, 2500000, 5000000, 10000000});\n \
    \   }\n  }\n\n  std::cout << \"Hello World\" << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - tools/assert_that.hpp
  - tools/linear_sieve.hpp
  isVerificationFile: true
  path: tests/linear_sieve.test.cpp
  requiredBy: []
  timestamp: '2024-09-29 05:36:14+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/linear_sieve.test.cpp
layout: document
redirect_from:
- /verify/tests/linear_sieve.test.cpp
- /verify/tests/linear_sieve.test.cpp.html
title: tests/linear_sieve.test.cpp
---
