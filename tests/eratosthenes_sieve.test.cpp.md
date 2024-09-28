---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/eratosthenes_sieve.hpp
    title: Sieve of Eratosthenes
  - icon: ':heavy_check_mark:'
    path: tools/join.hpp
    title: Join elements with delimiter
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/enumerate_primes
    links:
    - https://judge.yosupo.jp/problem/enumerate_primes
  bundledCode: "#line 1 \"tests/eratosthenes_sieve.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/enumerate_primes\"\n\n#include <iostream>\n#include\
    \ <iterator>\n#include <vector>\n#include <algorithm>\n#line 1 \"tools/eratosthenes_sieve.hpp\"\
    \n\n\n\n#line 5 \"tools/eratosthenes_sieve.hpp\"\n#include <cstddef>\n#include\
    \ <cassert>\n\nnamespace tools {\n  template <typename T>\n  class eratosthenes_sieve\
    \ {\n    ::std::vector<bool> m_is_prime;\n\n    int n() const {\n      return\
    \ this->m_is_prime.size() - 1;\n    }\n\n  public:\n    class prime_iterable {\n\
    \    private:\n      ::tools::eratosthenes_sieve<T> const *m_parent;\n      int\
    \ m_l;\n      int m_r;\n\n    public:\n      class iterator {\n      private:\n\
    \        ::tools::eratosthenes_sieve<T> const *m_parent;\n        int m_p;\n\n\
    \      public:\n        using difference_type = ::std::ptrdiff_t;\n        using\
    \ value_type = T;\n        using reference = const T&;\n        using pointer\
    \ = const T*;\n        using iterator_category = ::std::input_iterator_tag;\n\n\
    \        iterator() = default;\n        iterator(::tools::eratosthenes_sieve<T>\
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
    \ l, r);\n    }\n  };\n}\n\n\n#line 1 \"tools/join.hpp\"\n\n\n\n#include <string>\n\
    #include <sstream>\n#line 7 \"tools/join.hpp\"\n\nnamespace tools {\n\n  template\
    \ <typename Iterator>\n  ::std::string join(const Iterator begin, const Iterator\
    \ end, const ::std::string& delimiter) {\n    ::std::ostringstream ss;\n    if\
    \ (begin != end) {\n      ss << *begin;\n      for (auto it = ::std::next(begin);\
    \ it != end; ++it) {\n        ss << delimiter << *it;\n      }\n    }\n    return\
    \ ss.str();\n  }\n\n  template <typename Iterator, typename F>\n  ::std::string\
    \ join(const Iterator begin, const Iterator end, const F& mapper, const ::std::string&\
    \ delimiter) {\n    ::std::ostringstream ss;\n    if (begin != end) {\n      ss\
    \ << mapper(*begin);\n      for (auto it = ::std::next(begin); it != end; ++it)\
    \ {\n        ss << delimiter << mapper(*it);\n      }\n    }\n    return ss.str();\n\
    \  }\n}\n\n\n#line 9 \"tests/eratosthenes_sieve.test.cpp\"\n\nint main() {\n \
    \ std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\n  int N,\
    \ A, B;\n  std::cin >> N >> A >> B;\n\n  tools::eratosthenes_sieve<int> sieve(N);\n\
    \n  const auto begin = sieve.prime_range(1, N).begin();\n  const auto end = sieve.prime_range(1,\
    \ N).end();\n  const int pi_N = std::distance(begin, end);\n\n  std::vector<int>\
    \ answers;\n  int i = B;\n  for (auto it = std::next(begin, std::min(i, pi_N));\
    \ it != end; it = std::next(it, std::min(A, pi_N - i)), i = std::min(i + A, pi_N))\
    \ {\n    answers.push_back(*it);\n  }\n\n  std::cout << pi_N << ' ' << answers.size()\
    \ << '\\n';\n  std::cout << tools::join(answers.begin(), answers.end(), \" \"\
    ) << '\\n';\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_primes\"\n\n\
    #include <iostream>\n#include <iterator>\n#include <vector>\n#include <algorithm>\n\
    #include \"tools/eratosthenes_sieve.hpp\"\n#include \"tools/join.hpp\"\n\nint\
    \ main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  int N, A, B;\n  std::cin >> N >> A >> B;\n\n  tools::eratosthenes_sieve<int>\
    \ sieve(N);\n\n  const auto begin = sieve.prime_range(1, N).begin();\n  const\
    \ auto end = sieve.prime_range(1, N).end();\n  const int pi_N = std::distance(begin,\
    \ end);\n\n  std::vector<int> answers;\n  int i = B;\n  for (auto it = std::next(begin,\
    \ std::min(i, pi_N)); it != end; it = std::next(it, std::min(A, pi_N - i)), i\
    \ = std::min(i + A, pi_N)) {\n    answers.push_back(*it);\n  }\n\n  std::cout\
    \ << pi_N << ' ' << answers.size() << '\\n';\n  std::cout << tools::join(answers.begin(),\
    \ answers.end(), \" \") << '\\n';\n\n  return 0;\n}\n"
  dependsOn:
  - tools/eratosthenes_sieve.hpp
  - tools/join.hpp
  isVerificationFile: true
  path: tests/eratosthenes_sieve.test.cpp
  requiredBy: []
  timestamp: '2024-09-28 18:25:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/eratosthenes_sieve.test.cpp
layout: document
redirect_from:
- /verify/tests/eratosthenes_sieve.test.cpp
- /verify/tests/eratosthenes_sieve.test.cpp.html
title: tests/eratosthenes_sieve.test.cpp
---
