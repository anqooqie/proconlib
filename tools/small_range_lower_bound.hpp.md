---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/cmp_less.hpp
    title: Polyfill of std::cmp_less
  - icon: ':heavy_check_mark:'
    path: tools/cmp_less_equal.hpp
    title: Polyfill of std::cmp_less_equal
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/small_range_lower_bound.test.cpp
    title: tests/small_range_lower_bound.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/small_range_lower_bound.hpp\"\n\n\n\n#include <vector>\n\
    #include <type_traits>\n#include <iterator>\n#include <cstddef>\n#include <cassert>\n\
    #include <algorithm>\n#include <limits>\n#line 1 \"tools/cmp_less_equal.hpp\"\n\
    \n\n\n#line 1 \"tools/cmp_less.hpp\"\n\n\n\n#line 5 \"tools/cmp_less.hpp\"\n\n\
    namespace tools {\n  template <typename T, typename U>\n  constexpr bool cmp_less(const\
    \ T t, const U u) noexcept {\n    using UT = ::std::make_unsigned_t<T>;\n    using\
    \ UU = ::std::make_unsigned_t<U>;\n    if constexpr (::std::is_signed_v<T> ==\
    \ ::std::is_signed_v<U>) {\n      return t < u;\n    } else if constexpr (::std::is_signed_v<T>)\
    \ {\n      return t < 0 ? true : UT(t) < u;\n    } else {\n      return u < 0\
    \ ? false : t < UU(u);\n    }\n  }\n}\n\n\n#line 5 \"tools/cmp_less_equal.hpp\"\
    \n\nnamespace tools {\n  template <typename T, typename U>\n  constexpr bool cmp_less_equal(const\
    \ T t, const U u) noexcept {\n    return !::tools::cmp_less(u, t);\n  }\n}\n\n\
    \n#line 14 \"tools/small_range_lower_bound.hpp\"\n\nnamespace tools {\n  template\
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
    \    }\n  };\n}\n\n\n"
  code: "#ifndef TOOLS_SMALL_RANGE_LOWER_BOUND_HPP\n#define TOOLS_SMALL_RANGE_LOWER_BOUND_HPP\n\
    \n#include <vector>\n#include <type_traits>\n#include <iterator>\n#include <cstddef>\n\
    #include <cassert>\n#include <algorithm>\n#include <limits>\n#include <iterator>\n\
    #include <vector>\n#include \"tools/cmp_less_equal.hpp\"\n\nnamespace tools {\n\
    \  template <typename T>\n  class small_range_lower_bound {\n    T m_min;\n  \
    \  ::std::vector<int> m_res;\n\n    template <typename RandomAccessIterator, ::std::enable_if_t<::std::is_base_of_v<::std::random_access_iterator_tag,\
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
    \    }\n  };\n}\n\n#endif\n"
  dependsOn:
  - tools/cmp_less_equal.hpp
  - tools/cmp_less.hpp
  isVerificationFile: false
  path: tools/small_range_lower_bound.hpp
  requiredBy: []
  timestamp: '2024-11-17 01:04:26+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/small_range_lower_bound.test.cpp
documentation_of: tools/small_range_lower_bound.hpp
layout: document
title: std::lower_bound in $\left\langle O(N + \max(A_i) - \min(A_i)), O(1) \right\rangle$
  time
---

Given a sorted integer sequence $(A_0, A_1, \ldots, A_{N - 1})$, it returns $\|\\{i \in \mathbb{N} \mid 0 \leq i < N \land A_i < x \\}\|$ in $\left\langle O(N + A_{N - 1} - A_0), O(1) \right\rangle$ time.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
template <typename InputIterator>
small_range_lower_bound<T> lower_bound(InputIterator begin, InputIterator end);
```

Given a sorted integer sequence $(A_0, A_1, \ldots, A_{N - 1})$, it constructs a data structure that allows $\|\\{i \in \mathbb{N} \mid 0 \leq i < N \land A_i < x \\}\|$ to be returned in $O(1)$ time.

### Constraints
- `<T>` is an integral type.

### Time Complexity
- $O(N + A_{N - 1} - A_0)$

## query
```cpp
T lower_bound.query(T x);
```

It returns $\|\\{i \in \mathbb{N} \mid 0 \leq i < N \land A_i < x \\}\|$.

### Constraints
- None

### Time Complexity
- $O(1)$
