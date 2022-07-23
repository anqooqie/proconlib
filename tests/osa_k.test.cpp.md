---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/osa_k.hpp
    title: osa_k's algorithm
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc170/tasks/abc170_d
    links:
    - https://atcoder.jp/contests/abc170/tasks/abc170_d
  bundledCode: "#line 1 \"tests/osa_k.test.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/abc170/tasks/abc170_d\"\
    \n\n#include <cstdint>\n#include <iostream>\n#include <vector>\n#include <algorithm>\n\
    #include <unordered_set>\n#line 1 \"tools/osa_k.hpp\"\n\n\n\n#line 5 \"tools/osa_k.hpp\"\
    \n#include <cstddef>\n#include <iterator>\n#line 8 \"tools/osa_k.hpp\"\n#include\
    \ <limits>\n#include <utility>\n#include <unordered_map>\n\nnamespace tools {\n\
    \n  template <typename T>\n  class osa_k {\n  private:\n    ::std::vector<T> m_min_prime_factors;\n\
    \    ::std::vector<T> m_divisor_counts;\n\n  public:\n    class prime_factor_iterable\
    \ {\n    private:\n      const ::std::vector<T>& m_min_prime_factors;\n      T\
    \ m_n;\n\n    public:\n      class iterator {\n      private:\n        const ::std::vector<T>&\
    \ m_min_prime_factors;\n        T m_n;\n\n      public:\n        using difference_type\
    \ = ::std::ptrdiff_t;\n        using value_type = T;\n        using reference\
    \ = T&;\n        using pointer = T*;\n        using iterator_category = ::std::input_iterator_tag;\n\
    \n        iterator(const ::std::vector<T>& min_prime_factors, const T& n) :\n\
    \          m_min_prime_factors(min_prime_factors),\n          m_n(n) {\n     \
    \   }\n\n        iterator(const iterator& other) = default;\n        ~iterator()\
    \ = default;\n        iterator& operator=(const iterator& other) = default;\n\n\
    \        T operator*() const {\n          return this->m_min_prime_factors[this->m_n];\n\
    \        }\n\n        iterator& operator++() {\n          this->m_n /= **this;\n\
    \          return *this;\n        }\n\n        iterator operator++(int) {\n  \
    \        const iterator self = *this;\n          ++*this;\n          return self;\n\
    \        }\n\n        friend bool operator==(const iterator& lhs, const iterator&\
    \ rhs) {\n          return lhs.m_n == rhs.m_n;\n        }\n\n        friend bool\
    \ operator!=(const iterator& lhs, const iterator& rhs) {\n          return !(lhs\
    \ == rhs);\n        }\n      };\n\n      prime_factor_iterable(const ::std::vector<T>&\
    \ min_prime_factors, const T& n) :\n        m_min_prime_factors(min_prime_factors),\n\
    \        m_n(n) {\n      }\n\n      iterator begin() const {\n        return iterator(this->m_min_prime_factors,\
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
    \ ::std::vector<T>& m_min_prime_factors;\n\n    public:\n      class iterator\
    \ {\n      private:\n        const ::std::vector<T>& m_min_prime_factors;\n  \
    \      T m_n;\n\n      public:\n        using difference_type = ::std::ptrdiff_t;\n\
    \        using value_type = T;\n        using reference = T&;\n        using pointer\
    \ = T*;\n        using iterator_category = ::std::input_iterator_tag;\n\n    \
    \    iterator(const ::std::vector<T>& min_prime_factors, const T& n) :\n     \
    \     m_min_prime_factors(min_prime_factors),\n          m_n(n) {\n        }\n\
    \n        iterator(const iterator& other) = default;\n        ~iterator() = default;\n\
    \        iterator& operator=(const iterator& other) = default;\n\n        iterator&\
    \ operator++() {\n          for (++this->m_n; this->m_n < static_cast<T>(this->m_min_prime_factors.size())\
    \ && this->m_min_prime_factors[this->m_n] != this->m_n; ++this->m_n);\n      \
    \    return *this;\n        }\n\n        iterator operator++(int) {\n        \
    \  const iterator self = *this;\n          ++*this;\n          return self;\n\
    \        }\n\n        T operator*() const {\n          return this->m_n;\n   \
    \     }\n\n        friend bool operator==(const iterator& lhs, const iterator&\
    \ rhs) {\n          return lhs.m_n == rhs.m_n;\n        }\n\n        friend bool\
    \ operator!=(const iterator& lhs, const iterator& rhs) {\n          return !(lhs\
    \ == rhs);\n        }\n      };\n\n      prime_iterable(const ::std::vector<T>&\
    \ min_prime_factors) :\n        m_min_prime_factors(min_prime_factors) {\n   \
    \   }\n\n      iterator begin() const {\n        return iterator(this->m_min_prime_factors,\
    \ 2);\n      };\n\n      iterator end() const {\n        return iterator(this->m_min_prime_factors,\
    \ this->m_min_prime_factors.size());\n      }\n    };\n\n    osa_k(T N) :\n  \
    \    m_min_prime_factors(::std::max<T>(N, 1) + 1, ::std::numeric_limits<T>::max()),\n\
    \      m_divisor_counts(::std::max<T>(N, 1) + 1) {\n      N = ::std::max<T>(N,\
    \ 1);\n\n      for (T i = 2; i <= N; ++i) {\n        if (this->m_min_prime_factors[i]\
    \ == ::std::numeric_limits<T>::max()) {\n          this->m_min_prime_factors[i]\
    \ = i;\n          for (T j = i * i; j <= N; j += i) {\n            if (this->m_min_prime_factors[j]\
    \ == ::std::numeric_limits<T>::max()) {\n              this->m_min_prime_factors[j]\
    \ = i;\n            }\n          }\n        }\n      }\n\n      ::std::vector<::std::pair<T,\
    \ T>> dp(N + 1);\n      dp[0] = ::std::make_pair(0, 0);\n      dp[1] = ::std::make_pair(1,\
    \ 1);\n      for (T i = 2; i <= N; ++i) {\n        const ::std::pair<T, T>& prev\
    \ = dp[i / this->m_min_prime_factors[i]];\n        if (this->m_min_prime_factors[i\
    \ / this->m_min_prime_factors[i]] == this->m_min_prime_factors[i]) {\n       \
    \   dp[i] = ::std::make_pair(prev.first + 1, prev.second);\n        } else {\n\
    \          dp[i] = ::std::make_pair(static_cast<T>(2), prev.first * prev.second);\n\
    \        }\n      }\n\n      for (T i = 0; i <= N; ++i) {\n        this->m_divisor_counts[i]\
    \ = dp[i].first * dp[i].second;\n      }\n    }\n\n    T divisor_count(const T&\
    \ n) const {\n      return this->m_divisor_counts[n];\n    }\n\n    prime_factor_iterable\
    \ prime_factor_range(const T& n) const {\n      return prime_factor_iterable(this->m_min_prime_factors,\
    \ n);\n    }\n\n    distinct_prime_factor_iterable distinct_prime_factor_range(const\
    \ T& n) const {\n      return distinct_prime_factor_iterable(this->m_min_prime_factors,\
    \ n);\n    }\n\n    prime_iterable prime_range() const {\n      return prime_iterable(this->m_min_prime_factors);\n\
    \    }\n\n    ::std::vector<T> divisors(const T& n) const {\n      ::std::vector<T>\
    \ result({1});\n      for (const ::std::pair<T, T>& pair : this->distinct_prime_factor_range(n))\
    \ {\n        const T end = result.size();\n        for (T i = 1, x = pair.first;\
    \ i <= pair.second; ++i, x *= pair.first) {\n          for (T j = 0; j < end;\
    \ ++j) {\n            result.push_back(result[j] * x);\n          }\n        }\n\
    \      }\n\n      ::std::sort(result.begin(), result.end());\n      return result;\n\
    \    }\n  };\n}\n\n\n#line 9 \"tests/osa_k.test.cpp\"\n\nusing i64 = std::int_fast64_t;\n\
    \nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  i64 N;\n  std::cin >> N;\n  std::vector<i64> A(N);\n  for (auto& A_i : A)\
    \ std::cin >> A_i;\n\n  std::sort(A.begin(), A.end());\n  tools::osa_k<i64> osa_k(A.back());\n\
    \  std::unordered_set<i64> set;\n  i64 answer = 0;\n  for (i64 l = 0, r = 0; l\
    \ < N; l = r) {\n    for (; r < N && A[l] == A[r]; ++r);\n    if (r - l == 1 &&\
    \ [&]() {\n      for (const auto d : osa_k.divisors(A[l])) {\n        if (set.find(d)\
    \ != set.end()) return false;\n      }\n      return true;\n    }()) {\n     \
    \ ++answer;\n    }\n    set.insert(A[l]);\n  }\n\n  std::cout << answer << '\\\
    n';\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc170/tasks/abc170_d\"\n\n\
    #include <cstdint>\n#include <iostream>\n#include <vector>\n#include <algorithm>\n\
    #include <unordered_set>\n#include \"tools/osa_k.hpp\"\n\nusing i64 = std::int_fast64_t;\n\
    \nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  i64 N;\n  std::cin >> N;\n  std::vector<i64> A(N);\n  for (auto& A_i : A)\
    \ std::cin >> A_i;\n\n  std::sort(A.begin(), A.end());\n  tools::osa_k<i64> osa_k(A.back());\n\
    \  std::unordered_set<i64> set;\n  i64 answer = 0;\n  for (i64 l = 0, r = 0; l\
    \ < N; l = r) {\n    for (; r < N && A[l] == A[r]; ++r);\n    if (r - l == 1 &&\
    \ [&]() {\n      for (const auto d : osa_k.divisors(A[l])) {\n        if (set.find(d)\
    \ != set.end()) return false;\n      }\n      return true;\n    }()) {\n     \
    \ ++answer;\n    }\n    set.insert(A[l]);\n  }\n\n  std::cout << answer << '\\\
    n';\n  return 0;\n}\n"
  dependsOn:
  - tools/osa_k.hpp
  isVerificationFile: true
  path: tests/osa_k.test.cpp
  requiredBy: []
  timestamp: '2022-05-15 18:51:45+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/osa_k.test.cpp
layout: document
redirect_from:
- /verify/tests/osa_k.test.cpp
- /verify/tests/osa_k.test.cpp.html
title: tests/osa_k.test.cpp
---