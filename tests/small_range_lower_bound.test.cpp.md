---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/cmp_less.hpp
    title: Polyfill of std::cmp_less
  - icon: ':heavy_check_mark:'
    path: tools/cmp_less_equal.hpp
    title: Polyfill of std::cmp_less_equal
  - icon: ':heavy_check_mark:'
    path: tools/small_range_lower_bound.hpp
    title: std::lower_bound in $\left\langle O(N + \max(A_i) - \min(A_i)), O(1) \right\rangle$
      time
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc356/tasks/abc356_e
    links:
    - https://atcoder.jp/contests/abc356/tasks/abc356_e
  bundledCode: "#line 1 \"tests/small_range_lower_bound.test.cpp\"\n#define PROBLEM\
    \ \"https://atcoder.jp/contests/abc356/tasks/abc356_e\"\n\n#include <iostream>\n\
    #include <vector>\n#include <algorithm>\n#line 1 \"tools/small_range_lower_bound.hpp\"\
    \n\n\n\n#line 5 \"tools/small_range_lower_bound.hpp\"\n#include <type_traits>\n\
    #include <iterator>\n#include <cstddef>\n#include <cassert>\n#line 10 \"tools/small_range_lower_bound.hpp\"\
    \n#include <limits>\n#line 1 \"tools/cmp_less_equal.hpp\"\n\n\n\n#line 1 \"tools/cmp_less.hpp\"\
    \n\n\n\n#line 5 \"tools/cmp_less.hpp\"\n\nnamespace tools {\n  template <typename\
    \ T, typename U>\n  constexpr bool cmp_less(const T t, const U u) noexcept {\n\
    \    using UT = ::std::make_unsigned_t<T>;\n    using UU = ::std::make_unsigned_t<U>;\n\
    \    if constexpr (::std::is_signed_v<T> == ::std::is_signed_v<U>) {\n      return\
    \ t < u;\n    } else if constexpr (::std::is_signed_v<T>) {\n      return t <\
    \ 0 ? true : UT(t) < u;\n    } else {\n      return u < 0 ? false : t < UU(u);\n\
    \    }\n  }\n}\n\n\n#line 5 \"tools/cmp_less_equal.hpp\"\n\nnamespace tools {\n\
    \  template <typename T, typename U>\n  constexpr bool cmp_less_equal(const T\
    \ t, const U u) noexcept {\n    return !::tools::cmp_less(u, t);\n  }\n}\n\n\n\
    #line 14 \"tools/small_range_lower_bound.hpp\"\n\nnamespace tools {\n  template\
    \ <typename T>\n  class small_range_lower_bound {\n    T m_min;\n    ::std::vector<int>\
    \ m_res;\n\n    template <typename RandomAccessIterator, ::std::enable_if_t<::std::is_base_of_v<::std::random_access_iterator_tag,\
    \ typename ::std::iterator_traits<RandomAccessIterator>::iterator_category>, ::std::nullptr_t>\
    \ = nullptr>\n    void init(const RandomAccessIterator begin, const RandomAccessIterator\
    \ end) {\n      assert(::std::is_sorted(begin, end));\n      const int N = end\
    \ - begin;\n      if (begin == end) {\n        this->m_min = ::std::numeric_limits<T>::max();\n\
    \        this->m_res.resize(1);\n      } else {\n        this->m_min = *begin;\n\
    \        this->m_res.resize(*::std::prev(end) - *begin + 2);\n        for (int\
    \ l = 0, r = 0, d = 0; l < N; d = begin[l] - *begin + 1, l = r) {\n          for\
    \ (; r < N && begin[l] == begin[r]; ++r);\n          for (int x = d; ::tools::cmp_less_equal(x,\
    \ begin[l] - *begin); ++x) {\n            this->m_res[x] = l;\n          }\n \
    \       }\n      }\n      this->m_res.back() = N;\n    }\n\n  public:\n    small_range_lower_bound()\
    \ = default;\n    template <typename RandomAccessIterator, ::std::enable_if_t<::std::is_base_of_v<::std::random_access_iterator_tag,\
    \ typename ::std::iterator_traits<RandomAccessIterator>::iterator_category>, ::std::nullptr_t>\
    \ = nullptr>\n    small_range_lower_bound(const RandomAccessIterator begin, const\
    \ RandomAccessIterator end) {\n      this->init(begin, end);\n    }\n    template\
    \ <typename InputIterator, ::std::enable_if_t<!::std::is_base_of_v<::std::random_access_iterator_tag,\
    \ typename ::std::iterator_traits<InputIterator>::iterator_category>, ::std::nullptr_t>\
    \ = nullptr>\n    small_range_lower_bound(const InputIterator begin, const InputIterator\
    \ end) {\n      ::std::vector<T> v(begin, end);\n      this->init(v.begin(), v.end());\n\
    \    }\n\n    T query(const T x) {\n      if (x < this->m_min) return 0;\n   \
    \   return this->m_res[::std::min<int>(x - this->m_min, this->m_res.size() - 1)];\n\
    \    }\n  };\n}\n\n\n#line 7 \"tests/small_range_lower_bound.test.cpp\"\n\nusing\
    \ ll = long long;\n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  int N;\n  std::cin >> N;\n  std::vector<int> A(N);\n  for (auto&& A_i : A)\
    \ std::cin >> A_i;\n\n  std::sort(A.begin(), A.end());\n  tools::small_range_lower_bound<int>\
    \ lower_bound(A.begin(), A.end());\n\n  ll answer = 0;\n  for (int l = 0, r =\
    \ 0; l < N; l = r) {\n    for (; r < N && A[l] == A[r]; ++r);\n    for (int q\
    \ = 1, max_q = A.back() / A[l]; q <= max_q; ++q) {\n      answer += static_cast<ll>(lower_bound.query(A[l]\
    \ * (q + 1)) - lower_bound.query(A[l] * q)) * q * (r - l);\n    }\n    answer\
    \ -= static_cast<ll>(r - l) * (r - l + 1) / 2;\n  }\n\n  std::cout << answer <<\
    \ '\\n';\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc356/tasks/abc356_e\"\n\n\
    #include <iostream>\n#include <vector>\n#include <algorithm>\n#include \"tools/small_range_lower_bound.hpp\"\
    \n\nusing ll = long long;\n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  int N;\n  std::cin >> N;\n  std::vector<int> A(N);\n  for (auto&& A_i : A)\
    \ std::cin >> A_i;\n\n  std::sort(A.begin(), A.end());\n  tools::small_range_lower_bound<int>\
    \ lower_bound(A.begin(), A.end());\n\n  ll answer = 0;\n  for (int l = 0, r =\
    \ 0; l < N; l = r) {\n    for (; r < N && A[l] == A[r]; ++r);\n    for (int q\
    \ = 1, max_q = A.back() / A[l]; q <= max_q; ++q) {\n      answer += static_cast<ll>(lower_bound.query(A[l]\
    \ * (q + 1)) - lower_bound.query(A[l] * q)) * q * (r - l);\n    }\n    answer\
    \ -= static_cast<ll>(r - l) * (r - l + 1) / 2;\n  }\n\n  std::cout << answer <<\
    \ '\\n';\n  return 0;\n}\n"
  dependsOn:
  - tools/small_range_lower_bound.hpp
  - tools/cmp_less_equal.hpp
  - tools/cmp_less.hpp
  isVerificationFile: true
  path: tests/small_range_lower_bound.test.cpp
  requiredBy: []
  timestamp: '2024-11-17 01:04:26+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/small_range_lower_bound.test.cpp
layout: document
redirect_from:
- /verify/tests/small_range_lower_bound.test.cpp
- /verify/tests/small_range_lower_bound.test.cpp.html
title: tests/small_range_lower_bound.test.cpp
---
