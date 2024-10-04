---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/linear_sieve.test.cpp
    title: tests/linear_sieve.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/linear_sieve.hpp\"\n\n\n\n#include <vector>\n#include\
    \ <cstddef>\n#include <iterator>\n#include <cassert>\n#include <tuple>\n#include\
    \ <algorithm>\n\nnamespace tools {\n  template <typename T>\n  class linear_sieve\
    \ {\n    ::std::vector<int> m_primes;\n    ::std::vector<int> m_lpf;\n    ::std::vector<int>\
    \ m_ord;\n    ::std::vector<int> m_pow;\n\n    int N() const {\n      return this->m_lpf.size()\
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
    \    ::std::sort(D.begin(), D.end());\n      return D;\n    }\n  };\n}\n\n\n"
  code: "#ifndef TOOLS_LINEAR_SIEVE_HPP\n#define TOOLS_LINEAR_SIEVE_HPP\n\n#include\
    \ <vector>\n#include <cstddef>\n#include <iterator>\n#include <cassert>\n#include\
    \ <tuple>\n#include <algorithm>\n\nnamespace tools {\n  template <typename T>\n\
    \  class linear_sieve {\n    ::std::vector<int> m_primes;\n    ::std::vector<int>\
    \ m_lpf;\n    ::std::vector<int> m_ord;\n    ::std::vector<int> m_pow;\n\n   \
    \ int N() const {\n      return this->m_lpf.size() - 1;\n    }\n\n  public:\n\
    \    class prime_factor_iterable {\n    private:\n      ::tools::linear_sieve<T>\
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
    \    ::std::sort(D.begin(), D.end());\n      return D;\n    }\n  };\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/linear_sieve.hpp
  requiredBy: []
  timestamp: '2024-09-29 05:36:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/linear_sieve.test.cpp
documentation_of: tools/linear_sieve.hpp
layout: document
title: Linear sieve
---

It creates a table storing the least prime factor of positive integers.
It provides various operations related to prime factors by using the table.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
linear_sieve<T> sieve(int N);
```

It calculates the least prime factor for each positive integer $n$ such that $1 \leq n \leq N$.

### Constraints
- $N \geq 1$

### Time Complexity
- $O(N \log\log N)$

## is_prime
```cpp
bool sieve.is_prime(int n);
```

It returns whether $n$ is a prime or not.

### Constraints
- $1 \leq n \leq N$

### Time Complexity
- $O(1)$

## prime_factor_range
```cpp
struct prime_factor_iterable {
  struct iterator {
    T operator*();
    iterator& operator++();
    iterator operator++(int):
    friend bool operator==(iterator lhs, iterator rhs);
    friend bool operator!=(iterator lhs, iterator rhs);
  };
  iterator begin();
  iterator end();
};
prime_factor_iterable sieve.prime_factor_range(int n);
```

It returns the prime factors of $n$ in ascending order.

### Constraints
- $1 \leq n \leq N$

### Time Complexity
- If you just call `prime_factor_range`, it takes only $O(1)$ time.
- If you enumerate all the prime factors of $n$, it takes $O(\log n)$ time.

## distinct_prime_factor_range
```cpp
struct distinct_prime_factor_iterable {
  struct iterator {
    std::tuple<T, T, T> operator*();
    iterator& operator++();
    iterator operator++(int):
    friend bool operator==(iterator lhs, iterator rhs);
    friend bool operator!=(iterator lhs, iterator rhs);
  };
  iterator begin();
  iterator end();
};
distinct_prime_factor_iterable sieve.distinct_prime_factor_range(int n);
```

By using some primes $p_1 < p_2 < \cdots < p_k$ and some positive integers $q_1, q_2, \ldots, q_k$, we can denote $n$ as $p_1^{q_1} p_2^{q_2} \cdots p_k^{q_k}$.
It returns $((p_1, q_1, p_1^{q_1}), (p_2, q_2, p_2^{q_2}), \ldots, (p_k, q_k, p_k^{q_k}))$.

### Constraints
- $1 \leq n \leq N$

### Time Complexity
- If you just call `distinct_prime_factor_range`, it takes only $O(1)$ time.
- If you enumerate all the distinct prime factors of $n$, it takes $O\left(\frac{\log n}{\log \log n}\right)$ time.

## prime_range
```cpp
struct prime_iterable {
  struct iterator {
    T operator*();
    iterator& operator++();
    iterator operator++(int):
    friend bool operator==(iterator lhs, iterator rhs);
    friend bool operator!=(iterator lhs, iterator rhs);
  };
  iterator begin();
  iterator end();
};
prime_iterable sieve.prime_range(int l, int r);
```

It returns the primes $p$ such that $l \leq p \leq r$ in ascending order.

### Constraints
- $1 \leq l \leq r \leq N$

### Time Complexity
- If you just call `prime_range`, it takes only $O(1)$ time.
- If you enumerate all the primes $p$ such that $l \leq p \leq r$, it takes $O\left(\log N + \frac{r}{\log r} - \frac{l}{\log l}\right)$ time.

## divisors
```cpp
std::vector<T> sieve.divisors(int n);
```

It returns the positive divisors of $n$.
Note that the order of divisors is undefined.

### Constraints
- $1 \leq n \leq N$

### Time Complexity
- $O\left(2^\frac{\log n}{\log\log n}\right)$

## sorted_divisors
```cpp
std::vector<T> sieve.sorted_divisors(int n);
```

It returns the positive divisors of $n$ in ascending order.

### Constraints
- $1 \leq n \leq N$

### Time Complexity
- $O\left(2^\frac{\log n}{\log\log n} \frac{\log n}{\log\log n}\right)$
