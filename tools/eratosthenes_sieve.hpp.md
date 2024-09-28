---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/eratosthenes_sieve.test.cpp
    title: tests/eratosthenes_sieve.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/eratosthenes_sieve.hpp\"\n\n\n\n#include <vector>\n\
    #include <cstddef>\n#include <cassert>\n\nnamespace tools {\n  template <typename\
    \ T>\n  class eratosthenes_sieve {\n    ::std::vector<bool> m_is_prime;\n\n  \
    \  int n() const {\n      return this->m_is_prime.size() - 1;\n    }\n\n  public:\n\
    \    class prime_iterable {\n    private:\n      ::tools::eratosthenes_sieve<T>\
    \ const *m_parent;\n      int m_l;\n      int m_r;\n\n    public:\n      class\
    \ iterator {\n      private:\n        ::tools::eratosthenes_sieve<T> const *m_parent;\n\
    \        int m_p;\n\n      public:\n        using difference_type = ::std::ptrdiff_t;\n\
    \        using value_type = T;\n        using reference = const T&;\n        using\
    \ pointer = const T*;\n        using iterator_category = ::std::input_iterator_tag;\n\
    \n        iterator() = default;\n        iterator(::tools::eratosthenes_sieve<T>\
    \ const * const parent, const int p) : m_parent(parent), m_p(p) {\n          for\
    \ (; this->m_p <= parent->n() && !parent->m_is_prime[this->m_p]; ++this->m_p);\n\
    \        }\n\n        value_type operator*() const {\n          return this->m_p;\n\
    \        }\n        iterator& operator++() {\n          for (++this->m_p; this->m_p\
    \ <= this->m_parent->n() && !this->m_parent->m_is_prime[this->m_p]; ++this->m_p);\n\
    \          return *this;\n        }\n        iterator operator++(int) {\n    \
    \      const auto self = *this;\n          ++*this;\n          return self;\n\
    \        }\n        friend bool operator==(const iterator lhs, const iterator\
    \ rhs) {\n          assert(lhs.m_parent == rhs.m_parent);\n          return lhs.m_p\
    \ == rhs.m_p;\n        }\n        friend bool operator!=(const iterator lhs, const\
    \ iterator rhs) {\n          return !(lhs == rhs);\n        }\n      };\n\n  \
    \    prime_iterable() = default;\n      prime_iterable(::tools::eratosthenes_sieve<T>\
    \ const * const parent, const int l, const int r) : m_parent(parent), m_l(l),\
    \ m_r(r) {\n      }\n\n      iterator begin() const {\n        return iterator(this->m_parent,\
    \ this->m_l);\n      };\n      iterator end() const {\n        return iterator(this->m_parent,\
    \ this->m_r + 1);\n      }\n    };\n\n    eratosthenes_sieve() = default;\n  \
    \  explicit eratosthenes_sieve(const int n) : m_is_prime(n + 1, true) {\n    \
    \  assert(n >= 1);\n\n      this->m_is_prime[0] = false;\n      this->m_is_prime[1]\
    \ = false;\n      for (int i = 4; i <= n; i += 2) this->m_is_prime[i] = false;\n\
    \      for (int i = 9; i <= n; i += 6) this->m_is_prime[i] = false;\n      {\n\
    \        int i = 25;\n        while (true) {\n          if (n < i) break;\n  \
    \        this->m_is_prime[i] = false;\n          i += 10;\n          if (n < i)\
    \ break;\n          this->m_is_prime[i] = false;\n          i += 20;\n       \
    \ }\n      }\n\n      int i = 7;\n      while (true) {\n        if (n < i * i)\
    \ break;\n        if (this->m_is_prime[i]) { // 7\n          int j = i * i;\n\
    \          while (true) {\n            this->m_is_prime[j] = false; // 7 * 7\n\
    \            j += i * 4;\n            if (n < j) break;\n            this->m_is_prime[j]\
    \ = false; // 7 * 11\n            j += i + i;\n            if (n < j) break;\n\
    \            this->m_is_prime[j] = false; // 7 * 13\n            j += i * 4;\n\
    \            if (n < j) break;\n            this->m_is_prime[j] = false; // 7\
    \ * 17\n            j += i + i;\n            if (n < j) break;\n            this->m_is_prime[j]\
    \ = false; // 7 * 19\n            j += i * 4;\n            if (n < j) break;\n\
    \            this->m_is_prime[j] = false; // 7 * 23\n            j += i * 6;\n\
    \            if (n < j) break;\n            this->m_is_prime[j] = false; // 7\
    \ * 29\n            j += i + i;\n            if (n < j) break;\n            this->m_is_prime[j]\
    \ = false; // 7 * 1\n            j += i * 6;\n            if (n < j) break;\n\
    \          }\n        }\n        i += 4;\n        if (n < i * i) break;\n    \
    \    if (this->m_is_prime[i]) { // 11\n          int j = i * i;\n          while\
    \ (true) {\n            this->m_is_prime[j] = false; // 11 * 11\n            j\
    \ += i + i;\n            if (n < j) break;\n            this->m_is_prime[j] =\
    \ false; // 11 * 13\n            j += i * 4;\n            if (n < j) break;\n\
    \            this->m_is_prime[j] = false; // 11 * 17\n            j += i + i;\n\
    \            if (n < j) break;\n            this->m_is_prime[j] = false; // 11\
    \ * 19\n            j += i * 4;\n            if (n < j) break;\n            this->m_is_prime[j]\
    \ = false; // 11 * 23\n            j += i * 6;\n            if (n < j) break;\n\
    \            this->m_is_prime[j] = false; // 11 * 29\n            j += i + i;\n\
    \            if (n < j) break;\n            this->m_is_prime[j] = false; // 11\
    \ * 1\n            j += i * 6;\n            if (n < j) break;\n            this->m_is_prime[j]\
    \ = false; // 11 * 7\n            j += i * 4;\n            if (n < j) break;\n\
    \          }\n        }\n        i += 2;\n        if (n < i * i) break;\n    \
    \    if (this->m_is_prime[i]) { // 13\n          int j = i * i;\n          while\
    \ (true) {\n            this->m_is_prime[j] = false; // 13 * 13\n            j\
    \ += i * 4;\n            if (n < j) break;\n            this->m_is_prime[j] =\
    \ false; // 13 * 17\n            j += i + i;\n            if (n < j) break;\n\
    \            this->m_is_prime[j] = false; // 13 * 19\n            j += i * 4;\n\
    \            if (n < j) break;\n            this->m_is_prime[j] = false; // 13\
    \ * 23\n            j += i * 6;\n            if (n < j) break;\n            this->m_is_prime[j]\
    \ = false; // 13 * 29\n            j += i + i;\n            if (n < j) break;\n\
    \            this->m_is_prime[j] = false; // 13 * 1\n            j += i * 6;\n\
    \            if (n < j) break;\n            this->m_is_prime[j] = false; // 13\
    \ * 7\n            j += i * 4;\n            if (n < j) break;\n            this->m_is_prime[j]\
    \ = false; // 13 * 11\n            j += i + i;\n            if (n < j) break;\n\
    \          }\n        }\n        i += 4;\n        if (n < i * i) break;\n    \
    \    if (this->m_is_prime[i]) { // 17\n          int j = i * i;\n          while\
    \ (true) {\n            this->m_is_prime[j] = false; // 17 * 17\n            j\
    \ += i + i;\n            if (n < j) break;\n            this->m_is_prime[j] =\
    \ false; // 17 * 19\n            j += i * 4;\n            if (n < j) break;\n\
    \            this->m_is_prime[j] = false; // 17 * 23\n            j += i * 6;\n\
    \            if (n < j) break;\n            this->m_is_prime[j] = false; // 17\
    \ * 29\n            j += i + i;\n            if (n < j) break;\n            this->m_is_prime[j]\
    \ = false; // 17 * 1\n            j += i * 6;\n            if (n < j) break;\n\
    \            this->m_is_prime[j] = false; // 17 * 7\n            j += i * 4;\n\
    \            if (n < j) break;\n            this->m_is_prime[j] = false; // 17\
    \ * 11\n            j += i + i;\n            if (n < j) break;\n            this->m_is_prime[j]\
    \ = false; // 17 * 13\n            j += i * 4;\n            if (n < j) break;\n\
    \          }\n        }\n        i += 2;\n        if (n < i * i) break;\n    \
    \    if (this->m_is_prime[i]) { // 19\n          int j = i * i;\n          while\
    \ (true) {\n            this->m_is_prime[j] = false; // 19 * 19\n            j\
    \ += i * 4;\n            if (n < j) break;\n            this->m_is_prime[j] =\
    \ false; // 19 * 23\n            j += i * 6;\n            if (n < j) break;\n\
    \            this->m_is_prime[j] = false; // 19 * 29\n            j += i + i;\n\
    \            if (n < j) break;\n            this->m_is_prime[j] = false; // 19\
    \ * 1\n            j += i * 6;\n            if (n < j) break;\n            this->m_is_prime[j]\
    \ = false; // 19 * 7\n            j += i * 4;\n            if (n < j) break;\n\
    \            this->m_is_prime[j] = false; // 19 * 11\n            j += i + i;\n\
    \            if (n < j) break;\n            this->m_is_prime[j] = false; // 19\
    \ * 13\n            j += i * 4;\n            if (n < j) break;\n            this->m_is_prime[j]\
    \ = false; // 19 * 17\n            j += i + i;\n            if (n < j) break;\n\
    \          }\n        }\n        i += 4;\n        if (n < i * i) break;\n    \
    \    if (this->m_is_prime[i]) { // 23\n          int j = i * i;\n          while\
    \ (true) {\n            this->m_is_prime[j] = false; // 23 * 23\n            j\
    \ += i * 6;\n            if (n < j) break;\n            this->m_is_prime[j] =\
    \ false; // 23 * 29\n            j += i + i;\n            if (n < j) break;\n\
    \            this->m_is_prime[j] = false; // 23 * 1\n            j += i * 6;\n\
    \            if (n < j) break;\n            this->m_is_prime[j] = false; // 23\
    \ * 7\n            j += i * 4;\n            if (n < j) break;\n            this->m_is_prime[j]\
    \ = false; // 23 * 11\n            j += i + i;\n            if (n < j) break;\n\
    \            this->m_is_prime[j] = false; // 23 * 13\n            j += i * 4;\n\
    \            if (n < j) break;\n            this->m_is_prime[j] = false; // 23\
    \ * 17\n            j += i + i;\n            if (n < j) break;\n            this->m_is_prime[j]\
    \ = false; // 23 * 19\n            j += i * 4;\n            if (n < j) break;\n\
    \          }\n        }\n        i += 6;\n        if (n < i * i) break;\n    \
    \    if (this->m_is_prime[i]) { // 29\n          int j = i * i;\n          while\
    \ (true) {\n            this->m_is_prime[j] = false; // 29 * 29\n            j\
    \ += i + i;\n            if (n < j) break;\n            this->m_is_prime[j] =\
    \ false; // 29 * 1\n            j += i * 6;\n            if (n < j) break;\n \
    \           this->m_is_prime[j] = false; // 29 * 7\n            j += i * 4;\n\
    \            if (n < j) break;\n            this->m_is_prime[j] = false; // 29\
    \ * 11\n            j += i + i;\n            if (n < j) break;\n            this->m_is_prime[j]\
    \ = false; // 29 * 13\n            j += i * 4;\n            if (n < j) break;\n\
    \            this->m_is_prime[j] = false; // 29 * 17\n            j += i + i;\n\
    \            if (n < j) break;\n            this->m_is_prime[j] = false; // 29\
    \ * 19\n            j += i * 4;\n            if (n < j) break;\n            this->m_is_prime[j]\
    \ = false; // 29 * 23\n            j += i * 6;\n            if (n < j) break;\n\
    \          }\n        }\n        i += 2;\n        if (n < i * i) break;\n    \
    \    if (this->m_is_prime[i]) { // 1\n          int j = i * i;\n          while\
    \ (true) {\n            this->m_is_prime[j] = false; // 1 * 1\n            j +=\
    \ i * 6;\n            if (n < j) break;\n            this->m_is_prime[j] = false;\
    \ // 1 * 7\n            j += i * 4;\n            if (n < j) break;\n         \
    \   this->m_is_prime[j] = false; // 1 * 11\n            j += i + i;\n        \
    \    if (n < j) break;\n            this->m_is_prime[j] = false; // 1 * 13\n \
    \           j += i * 4;\n            if (n < j) break;\n            this->m_is_prime[j]\
    \ = false; // 1 * 17\n            j += i + i;\n            if (n < j) break;\n\
    \            this->m_is_prime[j] = false; // 1 * 19\n            j += i * 4;\n\
    \            if (n < j) break;\n            this->m_is_prime[j] = false; // 1\
    \ * 23\n            j += i * 6;\n            if (n < j) break;\n            this->m_is_prime[j]\
    \ = false; // 1 * 29\n            j += i + i;\n            if (n < j) break;\n\
    \          }\n        }\n        i += 6;\n      }\n    }\n\n    bool is_prime(const\
    \ int i) const {\n      assert(1 <= i && i <= this->n());\n      return this->m_is_prime[i];\n\
    \    }\n\n    prime_iterable prime_range(const int l, const int r) const {\n \
    \     assert(1 <= l && l <= r && r <= this->n());\n      return prime_iterable(this,\
    \ l, r);\n    }\n  };\n}\n\n\n"
  code: "#ifndef TOOLS_ERATOSTHENES_SIEVE_HPP\n#define TOOLS_ERATOSTHENES_SIEVE_HPP\n\
    \n#include <vector>\n#include <cstddef>\n#include <cassert>\n\nnamespace tools\
    \ {\n  template <typename T>\n  class eratosthenes_sieve {\n    ::std::vector<bool>\
    \ m_is_prime;\n\n    int n() const {\n      return this->m_is_prime.size() - 1;\n\
    \    }\n\n  public:\n    class prime_iterable {\n    private:\n      ::tools::eratosthenes_sieve<T>\
    \ const *m_parent;\n      int m_l;\n      int m_r;\n\n    public:\n      class\
    \ iterator {\n      private:\n        ::tools::eratosthenes_sieve<T> const *m_parent;\n\
    \        int m_p;\n\n      public:\n        using difference_type = ::std::ptrdiff_t;\n\
    \        using value_type = T;\n        using reference = const T&;\n        using\
    \ pointer = const T*;\n        using iterator_category = ::std::input_iterator_tag;\n\
    \n        iterator() = default;\n        iterator(::tools::eratosthenes_sieve<T>\
    \ const * const parent, const int p) : m_parent(parent), m_p(p) {\n          for\
    \ (; this->m_p <= parent->n() && !parent->m_is_prime[this->m_p]; ++this->m_p);\n\
    \        }\n\n        value_type operator*() const {\n          return this->m_p;\n\
    \        }\n        iterator& operator++() {\n          for (++this->m_p; this->m_p\
    \ <= this->m_parent->n() && !this->m_parent->m_is_prime[this->m_p]; ++this->m_p);\n\
    \          return *this;\n        }\n        iterator operator++(int) {\n    \
    \      const auto self = *this;\n          ++*this;\n          return self;\n\
    \        }\n        friend bool operator==(const iterator lhs, const iterator\
    \ rhs) {\n          assert(lhs.m_parent == rhs.m_parent);\n          return lhs.m_p\
    \ == rhs.m_p;\n        }\n        friend bool operator!=(const iterator lhs, const\
    \ iterator rhs) {\n          return !(lhs == rhs);\n        }\n      };\n\n  \
    \    prime_iterable() = default;\n      prime_iterable(::tools::eratosthenes_sieve<T>\
    \ const * const parent, const int l, const int r) : m_parent(parent), m_l(l),\
    \ m_r(r) {\n      }\n\n      iterator begin() const {\n        return iterator(this->m_parent,\
    \ this->m_l);\n      };\n      iterator end() const {\n        return iterator(this->m_parent,\
    \ this->m_r + 1);\n      }\n    };\n\n    eratosthenes_sieve() = default;\n  \
    \  explicit eratosthenes_sieve(const int n) : m_is_prime(n + 1, true) {\n    \
    \  assert(n >= 1);\n\n      this->m_is_prime[0] = false;\n      this->m_is_prime[1]\
    \ = false;\n      for (int i = 4; i <= n; i += 2) this->m_is_prime[i] = false;\n\
    \      for (int i = 9; i <= n; i += 6) this->m_is_prime[i] = false;\n      {\n\
    \        int i = 25;\n        while (true) {\n          if (n < i) break;\n  \
    \        this->m_is_prime[i] = false;\n          i += 10;\n          if (n < i)\
    \ break;\n          this->m_is_prime[i] = false;\n          i += 20;\n       \
    \ }\n      }\n\n      int i = 7;\n      while (true) {\n        if (n < i * i)\
    \ break;\n        if (this->m_is_prime[i]) { // 7\n          int j = i * i;\n\
    \          while (true) {\n            this->m_is_prime[j] = false; // 7 * 7\n\
    \            j += i * 4;\n            if (n < j) break;\n            this->m_is_prime[j]\
    \ = false; // 7 * 11\n            j += i + i;\n            if (n < j) break;\n\
    \            this->m_is_prime[j] = false; // 7 * 13\n            j += i * 4;\n\
    \            if (n < j) break;\n            this->m_is_prime[j] = false; // 7\
    \ * 17\n            j += i + i;\n            if (n < j) break;\n            this->m_is_prime[j]\
    \ = false; // 7 * 19\n            j += i * 4;\n            if (n < j) break;\n\
    \            this->m_is_prime[j] = false; // 7 * 23\n            j += i * 6;\n\
    \            if (n < j) break;\n            this->m_is_prime[j] = false; // 7\
    \ * 29\n            j += i + i;\n            if (n < j) break;\n            this->m_is_prime[j]\
    \ = false; // 7 * 1\n            j += i * 6;\n            if (n < j) break;\n\
    \          }\n        }\n        i += 4;\n        if (n < i * i) break;\n    \
    \    if (this->m_is_prime[i]) { // 11\n          int j = i * i;\n          while\
    \ (true) {\n            this->m_is_prime[j] = false; // 11 * 11\n            j\
    \ += i + i;\n            if (n < j) break;\n            this->m_is_prime[j] =\
    \ false; // 11 * 13\n            j += i * 4;\n            if (n < j) break;\n\
    \            this->m_is_prime[j] = false; // 11 * 17\n            j += i + i;\n\
    \            if (n < j) break;\n            this->m_is_prime[j] = false; // 11\
    \ * 19\n            j += i * 4;\n            if (n < j) break;\n            this->m_is_prime[j]\
    \ = false; // 11 * 23\n            j += i * 6;\n            if (n < j) break;\n\
    \            this->m_is_prime[j] = false; // 11 * 29\n            j += i + i;\n\
    \            if (n < j) break;\n            this->m_is_prime[j] = false; // 11\
    \ * 1\n            j += i * 6;\n            if (n < j) break;\n            this->m_is_prime[j]\
    \ = false; // 11 * 7\n            j += i * 4;\n            if (n < j) break;\n\
    \          }\n        }\n        i += 2;\n        if (n < i * i) break;\n    \
    \    if (this->m_is_prime[i]) { // 13\n          int j = i * i;\n          while\
    \ (true) {\n            this->m_is_prime[j] = false; // 13 * 13\n            j\
    \ += i * 4;\n            if (n < j) break;\n            this->m_is_prime[j] =\
    \ false; // 13 * 17\n            j += i + i;\n            if (n < j) break;\n\
    \            this->m_is_prime[j] = false; // 13 * 19\n            j += i * 4;\n\
    \            if (n < j) break;\n            this->m_is_prime[j] = false; // 13\
    \ * 23\n            j += i * 6;\n            if (n < j) break;\n            this->m_is_prime[j]\
    \ = false; // 13 * 29\n            j += i + i;\n            if (n < j) break;\n\
    \            this->m_is_prime[j] = false; // 13 * 1\n            j += i * 6;\n\
    \            if (n < j) break;\n            this->m_is_prime[j] = false; // 13\
    \ * 7\n            j += i * 4;\n            if (n < j) break;\n            this->m_is_prime[j]\
    \ = false; // 13 * 11\n            j += i + i;\n            if (n < j) break;\n\
    \          }\n        }\n        i += 4;\n        if (n < i * i) break;\n    \
    \    if (this->m_is_prime[i]) { // 17\n          int j = i * i;\n          while\
    \ (true) {\n            this->m_is_prime[j] = false; // 17 * 17\n            j\
    \ += i + i;\n            if (n < j) break;\n            this->m_is_prime[j] =\
    \ false; // 17 * 19\n            j += i * 4;\n            if (n < j) break;\n\
    \            this->m_is_prime[j] = false; // 17 * 23\n            j += i * 6;\n\
    \            if (n < j) break;\n            this->m_is_prime[j] = false; // 17\
    \ * 29\n            j += i + i;\n            if (n < j) break;\n            this->m_is_prime[j]\
    \ = false; // 17 * 1\n            j += i * 6;\n            if (n < j) break;\n\
    \            this->m_is_prime[j] = false; // 17 * 7\n            j += i * 4;\n\
    \            if (n < j) break;\n            this->m_is_prime[j] = false; // 17\
    \ * 11\n            j += i + i;\n            if (n < j) break;\n            this->m_is_prime[j]\
    \ = false; // 17 * 13\n            j += i * 4;\n            if (n < j) break;\n\
    \          }\n        }\n        i += 2;\n        if (n < i * i) break;\n    \
    \    if (this->m_is_prime[i]) { // 19\n          int j = i * i;\n          while\
    \ (true) {\n            this->m_is_prime[j] = false; // 19 * 19\n            j\
    \ += i * 4;\n            if (n < j) break;\n            this->m_is_prime[j] =\
    \ false; // 19 * 23\n            j += i * 6;\n            if (n < j) break;\n\
    \            this->m_is_prime[j] = false; // 19 * 29\n            j += i + i;\n\
    \            if (n < j) break;\n            this->m_is_prime[j] = false; // 19\
    \ * 1\n            j += i * 6;\n            if (n < j) break;\n            this->m_is_prime[j]\
    \ = false; // 19 * 7\n            j += i * 4;\n            if (n < j) break;\n\
    \            this->m_is_prime[j] = false; // 19 * 11\n            j += i + i;\n\
    \            if (n < j) break;\n            this->m_is_prime[j] = false; // 19\
    \ * 13\n            j += i * 4;\n            if (n < j) break;\n            this->m_is_prime[j]\
    \ = false; // 19 * 17\n            j += i + i;\n            if (n < j) break;\n\
    \          }\n        }\n        i += 4;\n        if (n < i * i) break;\n    \
    \    if (this->m_is_prime[i]) { // 23\n          int j = i * i;\n          while\
    \ (true) {\n            this->m_is_prime[j] = false; // 23 * 23\n            j\
    \ += i * 6;\n            if (n < j) break;\n            this->m_is_prime[j] =\
    \ false; // 23 * 29\n            j += i + i;\n            if (n < j) break;\n\
    \            this->m_is_prime[j] = false; // 23 * 1\n            j += i * 6;\n\
    \            if (n < j) break;\n            this->m_is_prime[j] = false; // 23\
    \ * 7\n            j += i * 4;\n            if (n < j) break;\n            this->m_is_prime[j]\
    \ = false; // 23 * 11\n            j += i + i;\n            if (n < j) break;\n\
    \            this->m_is_prime[j] = false; // 23 * 13\n            j += i * 4;\n\
    \            if (n < j) break;\n            this->m_is_prime[j] = false; // 23\
    \ * 17\n            j += i + i;\n            if (n < j) break;\n            this->m_is_prime[j]\
    \ = false; // 23 * 19\n            j += i * 4;\n            if (n < j) break;\n\
    \          }\n        }\n        i += 6;\n        if (n < i * i) break;\n    \
    \    if (this->m_is_prime[i]) { // 29\n          int j = i * i;\n          while\
    \ (true) {\n            this->m_is_prime[j] = false; // 29 * 29\n            j\
    \ += i + i;\n            if (n < j) break;\n            this->m_is_prime[j] =\
    \ false; // 29 * 1\n            j += i * 6;\n            if (n < j) break;\n \
    \           this->m_is_prime[j] = false; // 29 * 7\n            j += i * 4;\n\
    \            if (n < j) break;\n            this->m_is_prime[j] = false; // 29\
    \ * 11\n            j += i + i;\n            if (n < j) break;\n            this->m_is_prime[j]\
    \ = false; // 29 * 13\n            j += i * 4;\n            if (n < j) break;\n\
    \            this->m_is_prime[j] = false; // 29 * 17\n            j += i + i;\n\
    \            if (n < j) break;\n            this->m_is_prime[j] = false; // 29\
    \ * 19\n            j += i * 4;\n            if (n < j) break;\n            this->m_is_prime[j]\
    \ = false; // 29 * 23\n            j += i * 6;\n            if (n < j) break;\n\
    \          }\n        }\n        i += 2;\n        if (n < i * i) break;\n    \
    \    if (this->m_is_prime[i]) { // 1\n          int j = i * i;\n          while\
    \ (true) {\n            this->m_is_prime[j] = false; // 1 * 1\n            j +=\
    \ i * 6;\n            if (n < j) break;\n            this->m_is_prime[j] = false;\
    \ // 1 * 7\n            j += i * 4;\n            if (n < j) break;\n         \
    \   this->m_is_prime[j] = false; // 1 * 11\n            j += i + i;\n        \
    \    if (n < j) break;\n            this->m_is_prime[j] = false; // 1 * 13\n \
    \           j += i * 4;\n            if (n < j) break;\n            this->m_is_prime[j]\
    \ = false; // 1 * 17\n            j += i + i;\n            if (n < j) break;\n\
    \            this->m_is_prime[j] = false; // 1 * 19\n            j += i * 4;\n\
    \            if (n < j) break;\n            this->m_is_prime[j] = false; // 1\
    \ * 23\n            j += i * 6;\n            if (n < j) break;\n            this->m_is_prime[j]\
    \ = false; // 1 * 29\n            j += i + i;\n            if (n < j) break;\n\
    \          }\n        }\n        i += 6;\n      }\n    }\n\n    bool is_prime(const\
    \ int i) const {\n      assert(1 <= i && i <= this->n());\n      return this->m_is_prime[i];\n\
    \    }\n\n    prime_iterable prime_range(const int l, const int r) const {\n \
    \     assert(1 <= l && l <= r && r <= this->n());\n      return prime_iterable(this,\
    \ l, r);\n    }\n  };\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/eratosthenes_sieve.hpp
  requiredBy: []
  timestamp: '2024-09-28 18:25:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/eratosthenes_sieve.test.cpp
documentation_of: tools/eratosthenes_sieve.hpp
layout: document
title: Sieve of Eratosthenes
---

For all positive integers less than or equal to $n$, it determines if they are prime.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
eratosthenes_sieve<T> sieve(int n);
```

For all positive integers less than or equal to $n$, it determines if they are prime.

### Constraints
- $n \geq 1$

### Time Complexity
- $O(n \log\log n)$

## is_prime
```cpp
bool sieve.is_prime(int i);
```

It returns whether $i$ is a prime or not.

### Constraints
- $1 \leq i \leq n$

### Time Complexity
- $O(1)$

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
- $1 \leq l \leq r \leq n$

### Time Complexity
- If you just call `prime_range`, it takes only $O(1)$ time.
- If you enumerate all the primes $p$ such that $l \leq p \leq r$, it takes $O(r - l)$ time.
