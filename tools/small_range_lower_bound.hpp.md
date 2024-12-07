---
data:
  _extendedDependsOn: []
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
    #include <type_traits>\n#include <iterator>\n#include <cstddef>\n#include <limits>\n\
    #include <algorithm>\n#include <numeric>\n\nnamespace tools {\n  template <typename\
    \ T>\n  class small_range_lower_bound {\n    T m_min;\n    ::std::vector<int>\
    \ m_res;\n\n    template <typename ForwardIterator, ::std::enable_if_t<::std::is_base_of_v<::std::forward_iterator_tag,\
    \ typename ::std::iterator_traits<ForwardIterator>::iterator_category>, ::std::nullptr_t>\
    \ = nullptr>\n    void init(const ForwardIterator begin, const ForwardIterator\
    \ end) {\n      if (begin == end) {\n        this->m_min = ::std::numeric_limits<T>::max();\n\
    \        this->m_res.assign({0});\n      } else {\n        const auto [minit,\
    \ maxit] = ::std::minmax_element(begin, end);\n        this->m_min = *minit;\n\
    \        this->m_res.assign(*maxit - *minit + 2, 0);\n        for (auto it = begin;\
    \ it != end; ++it) {\n          ++this->m_res[*it - *minit + 1];\n        }\n\
    \        ::std::partial_sum(this->m_res.begin(), this->m_res.end(), this->m_res.begin());\n\
    \      }\n    }\n\n  public:\n    small_range_lower_bound() = default;\n    template\
    \ <typename ForwardIterator, ::std::enable_if_t<::std::is_base_of_v<::std::forward_iterator_tag,\
    \ typename ::std::iterator_traits<ForwardIterator>::iterator_category>, ::std::nullptr_t>\
    \ = nullptr>\n    small_range_lower_bound(const ForwardIterator begin, const ForwardIterator\
    \ end) {\n      this->init(begin, end);\n    }\n    template <typename InputIterator,\
    \ ::std::enable_if_t<!::std::is_base_of_v<::std::forward_iterator_tag, typename\
    \ ::std::iterator_traits<InputIterator>::iterator_category>, ::std::nullptr_t>\
    \ = nullptr>\n    small_range_lower_bound(const InputIterator begin, const InputIterator\
    \ end) {\n      ::std::vector<T> v(begin, end);\n      this->init(v.begin(), v.end());\n\
    \    }\n\n    T query(const T x) {\n      if (x < this->m_min) return 0;\n   \
    \   return this->m_res[::std::min<int>(x - this->m_min, this->m_res.size() - 1)];\n\
    \    }\n  };\n}\n\n\n"
  code: "#ifndef TOOLS_SMALL_RANGE_LOWER_BOUND_HPP\n#define TOOLS_SMALL_RANGE_LOWER_BOUND_HPP\n\
    \n#include <vector>\n#include <type_traits>\n#include <iterator>\n#include <cstddef>\n\
    #include <limits>\n#include <algorithm>\n#include <numeric>\n\nnamespace tools\
    \ {\n  template <typename T>\n  class small_range_lower_bound {\n    T m_min;\n\
    \    ::std::vector<int> m_res;\n\n    template <typename ForwardIterator, ::std::enable_if_t<::std::is_base_of_v<::std::forward_iterator_tag,\
    \ typename ::std::iterator_traits<ForwardIterator>::iterator_category>, ::std::nullptr_t>\
    \ = nullptr>\n    void init(const ForwardIterator begin, const ForwardIterator\
    \ end) {\n      if (begin == end) {\n        this->m_min = ::std::numeric_limits<T>::max();\n\
    \        this->m_res.assign({0});\n      } else {\n        const auto [minit,\
    \ maxit] = ::std::minmax_element(begin, end);\n        this->m_min = *minit;\n\
    \        this->m_res.assign(*maxit - *minit + 2, 0);\n        for (auto it = begin;\
    \ it != end; ++it) {\n          ++this->m_res[*it - *minit + 1];\n        }\n\
    \        ::std::partial_sum(this->m_res.begin(), this->m_res.end(), this->m_res.begin());\n\
    \      }\n    }\n\n  public:\n    small_range_lower_bound() = default;\n    template\
    \ <typename ForwardIterator, ::std::enable_if_t<::std::is_base_of_v<::std::forward_iterator_tag,\
    \ typename ::std::iterator_traits<ForwardIterator>::iterator_category>, ::std::nullptr_t>\
    \ = nullptr>\n    small_range_lower_bound(const ForwardIterator begin, const ForwardIterator\
    \ end) {\n      this->init(begin, end);\n    }\n    template <typename InputIterator,\
    \ ::std::enable_if_t<!::std::is_base_of_v<::std::forward_iterator_tag, typename\
    \ ::std::iterator_traits<InputIterator>::iterator_category>, ::std::nullptr_t>\
    \ = nullptr>\n    small_range_lower_bound(const InputIterator begin, const InputIterator\
    \ end) {\n      ::std::vector<T> v(begin, end);\n      this->init(v.begin(), v.end());\n\
    \    }\n\n    T query(const T x) {\n      if (x < this->m_min) return 0;\n   \
    \   return this->m_res[::std::min<int>(x - this->m_min, this->m_res.size() - 1)];\n\
    \    }\n  };\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/small_range_lower_bound.hpp
  requiredBy: []
  timestamp: '2024-12-07 15:39:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/small_range_lower_bound.test.cpp
documentation_of: tools/small_range_lower_bound.hpp
layout: document
title: std::lower_bound in $\left\langle O(N + \max(A_i) - \min(A_i)), O(1) \right\rangle$
  time
---

Given an integer sequence $(A_0, A_1, \ldots, A_{N - 1})$, it returns $\|\\{i \in \mathbb{N} \mid A_i < x \\}\|$ in $\left\langle O(N + \max(A_i) - \min(A_i)), O(1) \right\rangle$ time.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
template <typename InputIterator>
small_range_lower_bound<T> lower_bound(InputIterator begin, InputIterator end);
```

Given an integer sequence $(A_0, A_1, \ldots, A_{N - 1})$, it constructs a data structure that allows $\|\\{i \in \mathbb{N} \mid A_i < x \\}\|$ to be returned in $O(1)$ time.

### Constraints
- `<T>` is an integral type.

### Time Complexity
- $O(N + \max(A_i) - \min(A_i))$

## query
```cpp
T lower_bound.query(T x);
```

It returns $\|\\{i \in \mathbb{N} \mid A_i < x \\}\|$.

### Constraints
- None

### Time Complexity
- $O(1)$
