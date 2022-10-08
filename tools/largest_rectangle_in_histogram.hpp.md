---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: tools/chmax.hpp
    title: chmax function
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/largest_rectangle_in_histogram.test.cpp
    title: tests/largest_rectangle_in_histogram.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/largest_rectangle_in_histogram.hpp\"\n\n\n\n#include\
    \ <iterator>\n#include <stack>\n#include <utility>\n#include <tuple>\n#line 1\
    \ \"tools/chmax.hpp\"\n\n\n\n#include <algorithm>\n\nnamespace tools {\n\n  template\
    \ <typename M, typename N>\n  bool chmax(M& lhs, const N& rhs) {\n    const bool\
    \ updated = lhs < rhs;\n    if (updated) lhs = rhs;\n    return updated;\n  }\n\
    }\n\n\n#line 9 \"tools/largest_rectangle_in_histogram.hpp\"\n\nnamespace tools\
    \ {\n  template <typename InputIterator>\n  typename ::std::iterator_traits<InputIterator>::value_type\
    \ largest_rectangle_in_histogram(const InputIterator& begin, const InputIterator&\
    \ end) {\n    using T = typename ::std::iterator_traits<InputIterator>::value_type;\n\
    \n    T result = 0;\n    ::std::stack<::std::pair<T, T>> dp;\n    for (auto [i,\
    \ it, breaks] = ::std::make_tuple(0, begin, false); !breaks; ++i, breaks = it\
    \ == end, it = ::std::next(it, breaks ? 0 : 1)) {\n      const T v = it != end\
    \ ? *it : 0;\n      if (dp.empty() || dp.top().second < v) {\n        dp.emplace(i,\
    \ v);\n      } else if (dp.top().second > v) {\n        T leftmost;\n        while\
    \ (!dp.empty() && dp.top().second > v) {\n          leftmost = dp.top().first;\n\
    \          ::tools::chmax(result, dp.top().second * (i - dp.top().first));\n \
    \         dp.pop();\n        }\n        if (dp.empty() || dp.top().second < v)\
    \ {\n          dp.emplace(leftmost, v);\n        }\n      }\n    }\n\n    return\
    \ result;\n  }\n}\n\n\n"
  code: "#ifndef TOOLS_LARGEST_RECTANGLE_IN_HISTOGRAM_HPP\n#define TOOLS_LARGEST_RECTANGLE_IN_HISTOGRAM_HPP\n\
    \n#include <iterator>\n#include <stack>\n#include <utility>\n#include <tuple>\n\
    #include \"tools/chmax.hpp\"\n\nnamespace tools {\n  template <typename InputIterator>\n\
    \  typename ::std::iterator_traits<InputIterator>::value_type largest_rectangle_in_histogram(const\
    \ InputIterator& begin, const InputIterator& end) {\n    using T = typename ::std::iterator_traits<InputIterator>::value_type;\n\
    \n    T result = 0;\n    ::std::stack<::std::pair<T, T>> dp;\n    for (auto [i,\
    \ it, breaks] = ::std::make_tuple(0, begin, false); !breaks; ++i, breaks = it\
    \ == end, it = ::std::next(it, breaks ? 0 : 1)) {\n      const T v = it != end\
    \ ? *it : 0;\n      if (dp.empty() || dp.top().second < v) {\n        dp.emplace(i,\
    \ v);\n      } else if (dp.top().second > v) {\n        T leftmost;\n        while\
    \ (!dp.empty() && dp.top().second > v) {\n          leftmost = dp.top().first;\n\
    \          ::tools::chmax(result, dp.top().second * (i - dp.top().first));\n \
    \         dp.pop();\n        }\n        if (dp.empty() || dp.top().second < v)\
    \ {\n          dp.emplace(leftmost, v);\n        }\n      }\n    }\n\n    return\
    \ result;\n  }\n}\n\n#endif\n"
  dependsOn:
  - tools/chmax.hpp
  isVerificationFile: false
  path: tools/largest_rectangle_in_histogram.hpp
  requiredBy: []
  timestamp: '2021-07-18 21:35:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/largest_rectangle_in_histogram.test.cpp
documentation_of: tools/largest_rectangle_in_histogram.hpp
layout: document
title: Largest rectangle in histogram
---

```cpp
template <typename Iterator>
typename ::std::iterator_traits<Iterator>::value_type largest_rectangle_in_histogram(Iterator begin, Iterator end);
```

It returns the area of the largest rectangle in a given histogram.

## Constraints
- `begin` $\leq$ `end`

## Time Complexity
- $O(n)$ where $n$ is `end` - `begin`

## License
- CC0

## Author
- anqooqie
