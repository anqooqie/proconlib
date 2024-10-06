---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/assert_that.hpp
    title: Assertion macro
  - icon: ':heavy_check_mark:'
    path: tools/divisor_moebius.hpp
    title: "Divisor M\xF6bius transform"
  - icon: ':heavy_check_mark:'
    path: tools/eratosthenes_sieve.hpp
    title: Sieve of Eratosthenes
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
  bundledCode: "#line 1 \"tests/divisor_moebius.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\"\
    \n\n#include <iostream>\n#include <vector>\n#include <numeric>\n#include <iterator>\n\
    #line 1 \"tools/assert_that.hpp\"\n\n\n\n#line 5 \"tools/assert_that.hpp\"\n#include\
    \ <cstdlib>\n\n#define assert_that_impl(cond, file, line, func) do {\\\n  if (!cond)\
    \ {\\\n    ::std::cerr << file << ':' << line << \": \" << func << \": Assertion\
    \ `\" << #cond << \"' failed.\" << '\\n';\\\n    ::std::exit(EXIT_FAILURE);\\\n\
    \  }\\\n} while (false)\n#define assert_that(...) assert_that_impl((__VA_ARGS__),\
    \ __FILE__, __LINE__, __func__)\n\n\n#line 1 \"tools/divisor_moebius.hpp\"\n\n\
    \n\n#line 6 \"tools/divisor_moebius.hpp\"\n#include <algorithm>\n#line 1 \"tools/eratosthenes_sieve.hpp\"\
    \n\n\n\n#include <array>\n#include <cstdint>\n#line 7 \"tools/eratosthenes_sieve.hpp\"\
    \n#include <cstddef>\n#line 9 \"tools/eratosthenes_sieve.hpp\"\n#include <cassert>\n\
    #line 11 \"tools/eratosthenes_sieve.hpp\"\n\nnamespace tools {\n  template <typename\
    \ T>\n  class eratosthenes_sieve {\n    constexpr static ::std::array<::std::uint64_t,\
    \ 15> init = {\n      UINT64_C(0b0010100000100010100010100010000010100000100010100010100010000010),\n\
    \      UINT64_C(0b1000001010000010001010001010001000001010000010001010001010001000),\n\
    \      UINT64_C(0b1000100000101000001000101000101000100000101000001000101000101000),\n\
    \      UINT64_C(0b0010100010000010100000100010100010100010000010100000100010100010),\n\
    \      UINT64_C(0b1010001010001000001010000010001010001010001000001010000010001010),\n\
    \      UINT64_C(0b1000101000101000100000101000001000101000101000100000101000001000),\n\
    \      UINT64_C(0b0000100010100010100010000010100000100010100010100010000010100000),\n\
    \      UINT64_C(0b1010000010001010001010001000001010000010001010001010001000001010),\n\
    \      UINT64_C(0b0000101000001000101000101000100000101000001000101000101000100000),\n\
    \      UINT64_C(0b0010000010100000100010100010100010000010100000100010100010100010),\n\
    \      UINT64_C(0b1010001000001010000010001010001010001000001010000010001010001010),\n\
    \      UINT64_C(0b1000101000100000101000001000101000101000100000101000001000101000),\n\
    \      UINT64_C(0b0010100010100010000010100000100010100010100010000010100000100010),\n\
    \      UINT64_C(0b0010001010001010001000001010000010001010001010001000001010000010),\n\
    \      UINT64_C(0b1000001000101000101000100000101000001000101000101000100000101000),\n\
    \    };\n    ::std::vector<::std::uint64_t> m_is_prime;\n    int m_n;\n\n  public:\n\
    \    class prime_iterable {\n    private:\n      ::tools::eratosthenes_sieve<T>\
    \ const *m_parent;\n      int m_l;\n      int m_r;\n\n    public:\n      class\
    \ iterator {\n      private:\n        ::tools::eratosthenes_sieve<T> const *m_parent;\n\
    \        int m_p;\n\n      public:\n        using difference_type = ::std::ptrdiff_t;\n\
    \        using value_type = T;\n        using reference = const T&;\n        using\
    \ pointer = const T*;\n        using iterator_category = ::std::input_iterator_tag;\n\
    \n        iterator() = default;\n        iterator(::tools::eratosthenes_sieve<T>\
    \ const * const parent, const int p) : m_parent(parent), m_p(p) {\n          for\
    \ (; this->m_p <= parent->m_n && !parent->is_prime(this->m_p); ++this->m_p);\n\
    \        }\n\n        value_type operator*() const {\n          return this->m_p;\n\
    \        }\n        iterator& operator++() {\n          for (++this->m_p; this->m_p\
    \ <= this->m_parent->m_n && !this->m_parent->is_prime(this->m_p); ++this->m_p);\n\
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
    \  explicit eratosthenes_sieve(const int n) : m_n(n) {\n      assert(n >= 1);\n\
    \      this->m_is_prime.reserve((n >> 6) + 1);\n      for (int i = 0; i <= n;\
    \ i += 960) {\n        ::std::copy(init.begin(), n < i + 959 ? ::std::next(init.begin(),\
    \ (n >> 6) % 15 + 1) : init.end(), ::std::back_inserter(this->m_is_prime));\n\
    \      }\n      this->m_is_prime[0] ^= UINT64_C(0b101110);\n\n      int i = 7;\n\
    \      while (true) {\n        if (n < i * i) break;\n        if (this->is_prime(i))\
    \ { // 7\n          int j = i * i;\n          while (true) {\n            this->m_is_prime[j\
    \ >> 6] &= ~(UINT64_C(1) << (j & 0b111111)); // 7 * 7\n            j += i * 4;\n\
    \            if (n < j) break;\n            this->m_is_prime[j >> 6] &= ~(UINT64_C(1)\
    \ << (j & 0b111111)); // 7 * 11\n            j += i + i;\n            if (n <\
    \ j) break;\n            this->m_is_prime[j >> 6] &= ~(UINT64_C(1) << (j & 0b111111));\
    \ // 7 * 13\n            j += i * 4;\n            if (n < j) break;\n        \
    \    this->m_is_prime[j >> 6] &= ~(UINT64_C(1) << (j & 0b111111)); // 7 * 17\n\
    \            j += i + i;\n            if (n < j) break;\n            this->m_is_prime[j\
    \ >> 6] &= ~(UINT64_C(1) << (j & 0b111111)); // 7 * 19\n            j += i * 4;\n\
    \            if (n < j) break;\n            this->m_is_prime[j >> 6] &= ~(UINT64_C(1)\
    \ << (j & 0b111111)); // 7 * 23\n            j += i * 6;\n            if (n <\
    \ j) break;\n            this->m_is_prime[j >> 6] &= ~(UINT64_C(1) << (j & 0b111111));\
    \ // 7 * 29\n            j += i + i;\n            if (n < j) break;\n        \
    \    this->m_is_prime[j >> 6] &= ~(UINT64_C(1) << (j & 0b111111)); // 7 * 1\n\
    \            j += i * 6;\n            if (n < j) break;\n          }\n       \
    \ }\n        i += 4;\n        if (n < i * i) break;\n        if (this->is_prime(i))\
    \ { // 11\n          int j = i * i;\n          while (true) {\n            this->m_is_prime[j\
    \ >> 6] &= ~(UINT64_C(1) << (j & 0b111111)); // 11 * 11\n            j += i +\
    \ i;\n            if (n < j) break;\n            this->m_is_prime[j >> 6] &= ~(UINT64_C(1)\
    \ << (j & 0b111111)); // 11 * 13\n            j += i * 4;\n            if (n <\
    \ j) break;\n            this->m_is_prime[j >> 6] &= ~(UINT64_C(1) << (j & 0b111111));\
    \ // 11 * 17\n            j += i + i;\n            if (n < j) break;\n       \
    \     this->m_is_prime[j >> 6] &= ~(UINT64_C(1) << (j & 0b111111)); // 11 * 19\n\
    \            j += i * 4;\n            if (n < j) break;\n            this->m_is_prime[j\
    \ >> 6] &= ~(UINT64_C(1) << (j & 0b111111)); // 11 * 23\n            j += i *\
    \ 6;\n            if (n < j) break;\n            this->m_is_prime[j >> 6] &= ~(UINT64_C(1)\
    \ << (j & 0b111111)); // 11 * 29\n            j += i + i;\n            if (n <\
    \ j) break;\n            this->m_is_prime[j >> 6] &= ~(UINT64_C(1) << (j & 0b111111));\
    \ // 11 * 1\n            j += i * 6;\n            if (n < j) break;\n        \
    \    this->m_is_prime[j >> 6] &= ~(UINT64_C(1) << (j & 0b111111)); // 11 * 7\n\
    \            j += i * 4;\n            if (n < j) break;\n          }\n       \
    \ }\n        i += 2;\n        if (n < i * i) break;\n        if (this->is_prime(i))\
    \ { // 13\n          int j = i * i;\n          while (true) {\n            this->m_is_prime[j\
    \ >> 6] &= ~(UINT64_C(1) << (j & 0b111111)); // 13 * 13\n            j += i *\
    \ 4;\n            if (n < j) break;\n            this->m_is_prime[j >> 6] &= ~(UINT64_C(1)\
    \ << (j & 0b111111)); // 13 * 17\n            j += i + i;\n            if (n <\
    \ j) break;\n            this->m_is_prime[j >> 6] &= ~(UINT64_C(1) << (j & 0b111111));\
    \ // 13 * 19\n            j += i * 4;\n            if (n < j) break;\n       \
    \     this->m_is_prime[j >> 6] &= ~(UINT64_C(1) << (j & 0b111111)); // 13 * 23\n\
    \            j += i * 6;\n            if (n < j) break;\n            this->m_is_prime[j\
    \ >> 6] &= ~(UINT64_C(1) << (j & 0b111111)); // 13 * 29\n            j += i +\
    \ i;\n            if (n < j) break;\n            this->m_is_prime[j >> 6] &= ~(UINT64_C(1)\
    \ << (j & 0b111111)); // 13 * 1\n            j += i * 6;\n            if (n <\
    \ j) break;\n            this->m_is_prime[j >> 6] &= ~(UINT64_C(1) << (j & 0b111111));\
    \ // 13 * 7\n            j += i * 4;\n            if (n < j) break;\n        \
    \    this->m_is_prime[j >> 6] &= ~(UINT64_C(1) << (j & 0b111111)); // 13 * 11\n\
    \            j += i + i;\n            if (n < j) break;\n          }\n       \
    \ }\n        i += 4;\n        if (n < i * i) break;\n        if (this->is_prime(i))\
    \ { // 17\n          int j = i * i;\n          while (true) {\n            this->m_is_prime[j\
    \ >> 6] &= ~(UINT64_C(1) << (j & 0b111111)); // 17 * 17\n            j += i +\
    \ i;\n            if (n < j) break;\n            this->m_is_prime[j >> 6] &= ~(UINT64_C(1)\
    \ << (j & 0b111111)); // 17 * 19\n            j += i * 4;\n            if (n <\
    \ j) break;\n            this->m_is_prime[j >> 6] &= ~(UINT64_C(1) << (j & 0b111111));\
    \ // 17 * 23\n            j += i * 6;\n            if (n < j) break;\n       \
    \     this->m_is_prime[j >> 6] &= ~(UINT64_C(1) << (j & 0b111111)); // 17 * 29\n\
    \            j += i + i;\n            if (n < j) break;\n            this->m_is_prime[j\
    \ >> 6] &= ~(UINT64_C(1) << (j & 0b111111)); // 17 * 1\n            j += i * 6;\n\
    \            if (n < j) break;\n            this->m_is_prime[j >> 6] &= ~(UINT64_C(1)\
    \ << (j & 0b111111)); // 17 * 7\n            j += i * 4;\n            if (n <\
    \ j) break;\n            this->m_is_prime[j >> 6] &= ~(UINT64_C(1) << (j & 0b111111));\
    \ // 17 * 11\n            j += i + i;\n            if (n < j) break;\n       \
    \     this->m_is_prime[j >> 6] &= ~(UINT64_C(1) << (j & 0b111111)); // 17 * 13\n\
    \            j += i * 4;\n            if (n < j) break;\n          }\n       \
    \ }\n        i += 2;\n        if (n < i * i) break;\n        if (this->is_prime(i))\
    \ { // 19\n          int j = i * i;\n          while (true) {\n            this->m_is_prime[j\
    \ >> 6] &= ~(UINT64_C(1) << (j & 0b111111)); // 19 * 19\n            j += i *\
    \ 4;\n            if (n < j) break;\n            this->m_is_prime[j >> 6] &= ~(UINT64_C(1)\
    \ << (j & 0b111111)); // 19 * 23\n            j += i * 6;\n            if (n <\
    \ j) break;\n            this->m_is_prime[j >> 6] &= ~(UINT64_C(1) << (j & 0b111111));\
    \ // 19 * 29\n            j += i + i;\n            if (n < j) break;\n       \
    \     this->m_is_prime[j >> 6] &= ~(UINT64_C(1) << (j & 0b111111)); // 19 * 1\n\
    \            j += i * 6;\n            if (n < j) break;\n            this->m_is_prime[j\
    \ >> 6] &= ~(UINT64_C(1) << (j & 0b111111)); // 19 * 7\n            j += i * 4;\n\
    \            if (n < j) break;\n            this->m_is_prime[j >> 6] &= ~(UINT64_C(1)\
    \ << (j & 0b111111)); // 19 * 11\n            j += i + i;\n            if (n <\
    \ j) break;\n            this->m_is_prime[j >> 6] &= ~(UINT64_C(1) << (j & 0b111111));\
    \ // 19 * 13\n            j += i * 4;\n            if (n < j) break;\n       \
    \     this->m_is_prime[j >> 6] &= ~(UINT64_C(1) << (j & 0b111111)); // 19 * 17\n\
    \            j += i + i;\n            if (n < j) break;\n          }\n       \
    \ }\n        i += 4;\n        if (n < i * i) break;\n        if (this->is_prime(i))\
    \ { // 23\n          int j = i * i;\n          while (true) {\n            this->m_is_prime[j\
    \ >> 6] &= ~(UINT64_C(1) << (j & 0b111111)); // 23 * 23\n            j += i *\
    \ 6;\n            if (n < j) break;\n            this->m_is_prime[j >> 6] &= ~(UINT64_C(1)\
    \ << (j & 0b111111)); // 23 * 29\n            j += i + i;\n            if (n <\
    \ j) break;\n            this->m_is_prime[j >> 6] &= ~(UINT64_C(1) << (j & 0b111111));\
    \ // 23 * 1\n            j += i * 6;\n            if (n < j) break;\n        \
    \    this->m_is_prime[j >> 6] &= ~(UINT64_C(1) << (j & 0b111111)); // 23 * 7\n\
    \            j += i * 4;\n            if (n < j) break;\n            this->m_is_prime[j\
    \ >> 6] &= ~(UINT64_C(1) << (j & 0b111111)); // 23 * 11\n            j += i +\
    \ i;\n            if (n < j) break;\n            this->m_is_prime[j >> 6] &= ~(UINT64_C(1)\
    \ << (j & 0b111111)); // 23 * 13\n            j += i * 4;\n            if (n <\
    \ j) break;\n            this->m_is_prime[j >> 6] &= ~(UINT64_C(1) << (j & 0b111111));\
    \ // 23 * 17\n            j += i + i;\n            if (n < j) break;\n       \
    \     this->m_is_prime[j >> 6] &= ~(UINT64_C(1) << (j & 0b111111)); // 23 * 19\n\
    \            j += i * 4;\n            if (n < j) break;\n          }\n       \
    \ }\n        i += 6;\n        if (n < i * i) break;\n        if (this->is_prime(i))\
    \ { // 29\n          int j = i * i;\n          while (true) {\n            this->m_is_prime[j\
    \ >> 6] &= ~(UINT64_C(1) << (j & 0b111111)); // 29 * 29\n            j += i +\
    \ i;\n            if (n < j) break;\n            this->m_is_prime[j >> 6] &= ~(UINT64_C(1)\
    \ << (j & 0b111111)); // 29 * 1\n            j += i * 6;\n            if (n <\
    \ j) break;\n            this->m_is_prime[j >> 6] &= ~(UINT64_C(1) << (j & 0b111111));\
    \ // 29 * 7\n            j += i * 4;\n            if (n < j) break;\n        \
    \    this->m_is_prime[j >> 6] &= ~(UINT64_C(1) << (j & 0b111111)); // 29 * 11\n\
    \            j += i + i;\n            if (n < j) break;\n            this->m_is_prime[j\
    \ >> 6] &= ~(UINT64_C(1) << (j & 0b111111)); // 29 * 13\n            j += i *\
    \ 4;\n            if (n < j) break;\n            this->m_is_prime[j >> 6] &= ~(UINT64_C(1)\
    \ << (j & 0b111111)); // 29 * 17\n            j += i + i;\n            if (n <\
    \ j) break;\n            this->m_is_prime[j >> 6] &= ~(UINT64_C(1) << (j & 0b111111));\
    \ // 29 * 19\n            j += i * 4;\n            if (n < j) break;\n       \
    \     this->m_is_prime[j >> 6] &= ~(UINT64_C(1) << (j & 0b111111)); // 29 * 23\n\
    \            j += i * 6;\n            if (n < j) break;\n          }\n       \
    \ }\n        i += 2;\n        if (n < i * i) break;\n        if (this->is_prime(i))\
    \ { // 1\n          int j = i * i;\n          while (true) {\n            this->m_is_prime[j\
    \ >> 6] &= ~(UINT64_C(1) << (j & 0b111111)); // 1 * 1\n            j += i * 6;\n\
    \            if (n < j) break;\n            this->m_is_prime[j >> 6] &= ~(UINT64_C(1)\
    \ << (j & 0b111111)); // 1 * 7\n            j += i * 4;\n            if (n < j)\
    \ break;\n            this->m_is_prime[j >> 6] &= ~(UINT64_C(1) << (j & 0b111111));\
    \ // 1 * 11\n            j += i + i;\n            if (n < j) break;\n        \
    \    this->m_is_prime[j >> 6] &= ~(UINT64_C(1) << (j & 0b111111)); // 1 * 13\n\
    \            j += i * 4;\n            if (n < j) break;\n            this->m_is_prime[j\
    \ >> 6] &= ~(UINT64_C(1) << (j & 0b111111)); // 1 * 17\n            j += i + i;\n\
    \            if (n < j) break;\n            this->m_is_prime[j >> 6] &= ~(UINT64_C(1)\
    \ << (j & 0b111111)); // 1 * 19\n            j += i * 4;\n            if (n <\
    \ j) break;\n            this->m_is_prime[j >> 6] &= ~(UINT64_C(1) << (j & 0b111111));\
    \ // 1 * 23\n            j += i * 6;\n            if (n < j) break;\n        \
    \    this->m_is_prime[j >> 6] &= ~(UINT64_C(1) << (j & 0b111111)); // 1 * 29\n\
    \            j += i + i;\n            if (n < j) break;\n          }\n       \
    \ }\n        i += 6;\n      }\n    }\n\n    inline bool is_prime(const int i)\
    \ const {\n      assert(1 <= i && i <= this->m_n);\n      return (this->m_is_prime[i\
    \ >> 6] >> (i & 0b111111)) & 1;\n    }\n\n    prime_iterable prime_range(const\
    \ int l, const int r) const {\n      assert(1 <= l && l <= r && r <= this->m_n);\n\
    \      return prime_iterable(this, l, r);\n    }\n  };\n}\n\n\n#line 8 \"tools/divisor_moebius.hpp\"\
    \n\nnamespace tools {\n  template <typename RandomAccessIterator>\n  void divisor_moebius(const\
    \ RandomAccessIterator begin, const RandomAccessIterator end) {\n    const int\
    \ N = end - begin;\n    if (N < 2) return;\n\n    ::tools::eratosthenes_sieve<int>\
    \ sieve(N - 1);\n    for (const auto p : sieve.prime_range(1, N - 1)) {\n    \
    \  for (int i = (N - 1) / p; i >= 1; --i) {\n        begin[i * p] -= begin[i];\n\
    \      }\n    }\n\n    for (int i = 1; i < N; ++i) {\n      begin[0] -= begin[i];\n\
    \    }\n  }\n\n  template <typename InputIterator, typename OutputIterator>\n\
    \  void divisor_moebius(const InputIterator begin, const InputIterator end, const\
    \ OutputIterator result) {\n    using T = typename ::std::iterator_traits<InputIterator>::value_type;\n\
    \    ::std::vector<T> b(begin, end);\n    ::tools::divisor_moebius(b.begin(),\
    \ b.end());\n    ::std::move(b.begin(), b.end(), result);\n  }\n}\n\n\n#line 9\
    \ \"tests/divisor_moebius.test.cpp\"\n\nint main() {\n  std::cin.tie(nullptr);\n\
    \  std::ios_base::sync_with_stdio(false);\n\n  for (int N = 0; N <= 20; ++N) {\n\
    \    std::vector<int> a(N);\n    for (int i = 0; i < N; ++i) {\n      a[i] = 1\
    \ << i;\n    }\n\n    std::vector<int> b(N, 0);\n    for (int i = 0; i < N; ++i)\
    \ {\n      for (int j = 0; j < N; ++j) {\n        if (std::lcm(i, j) == i) b[i]\
    \ += a[j];\n      }\n    }\n\n    std::vector<int> actual_a;\n    tools::divisor_moebius(b.begin(),\
    \ b.end(), std::back_inserter(actual_a));\n    assert_that(actual_a == a);\n\n\
    \    tools::divisor_moebius(b.begin(), b.end());\n    assert_that(b == a);\n \
    \ }\n\n  std::cout << \"Hello World\" << '\\n';\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\"\n\n\
    #include <iostream>\n#include <vector>\n#include <numeric>\n#include <iterator>\n\
    #include \"tools/assert_that.hpp\"\n#include \"tools/divisor_moebius.hpp\"\n\n\
    int main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  for (int N = 0; N <= 20; ++N) {\n    std::vector<int> a(N);\n    for (int\
    \ i = 0; i < N; ++i) {\n      a[i] = 1 << i;\n    }\n\n    std::vector<int> b(N,\
    \ 0);\n    for (int i = 0; i < N; ++i) {\n      for (int j = 0; j < N; ++j) {\n\
    \        if (std::lcm(i, j) == i) b[i] += a[j];\n      }\n    }\n\n    std::vector<int>\
    \ actual_a;\n    tools::divisor_moebius(b.begin(), b.end(), std::back_inserter(actual_a));\n\
    \    assert_that(actual_a == a);\n\n    tools::divisor_moebius(b.begin(), b.end());\n\
    \    assert_that(b == a);\n  }\n\n  std::cout << \"Hello World\" << '\\n';\n \
    \ return 0;\n}\n"
  dependsOn:
  - tools/assert_that.hpp
  - tools/divisor_moebius.hpp
  - tools/eratosthenes_sieve.hpp
  isVerificationFile: true
  path: tests/divisor_moebius.test.cpp
  requiredBy: []
  timestamp: '2024-10-07 01:25:58+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/divisor_moebius.test.cpp
layout: document
redirect_from:
- /verify/tests/divisor_moebius.test.cpp
- /verify/tests/divisor_moebius.test.cpp.html
title: tests/divisor_moebius.test.cpp
---
