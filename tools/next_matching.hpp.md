---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: tests/next_matching.test.cpp
    title: tests/next_matching.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/next_matching.hpp\"\n\n\n\n#include <iterator>\n#include\
    \ <cassert>\n#include <algorithm>\n\nnamespace tools {\n  template <typename RandomAccessIterator>\n\
    \  bool next_matching(RandomAccessIterator begin, RandomAccessIterator end) {\n\
    \    const auto N = ::std::distance(begin, end);\n    // assert(::tools::mex(begin,\
    \ end) == N);\n    if (N <= 2) return false;\n\n    auto l = (N - 2) / 2 * 2;\n\
    \    for (; l > 0 && begin[l - 1] > begin[l + 1]; l -= 2);\n    ::std::sort(::std::next(begin,\
    \ l), ::std::prev(end, N % 2));\n\n    if (l == 0) {\n      if (N % 2 == 0) return\
    \ false;\n      if (begin[N - 1] == 0) {\n        ::std::rotate(begin, ::std::prev(end),\
    \ end);\n        return false;\n      }\n      ::std::iter_swap(::std::next(begin,\
    \ begin[N - 1] - 1), ::std::prev(end));\n      return true;\n    }\n\n    ::std::iter_swap(::std::next(begin,\
    \ l - 1), ::std::upper_bound(::std::next(begin, l), ::std::prev(end, N % 2), begin[l\
    \ - 1]));\n    return true;\n  }\n}\n\n\n"
  code: "#ifndef TOOLS_NEXT_MATCHING_HPP\n#define TOOLS_NEXT_MATCHING_HPP\n\n#include\
    \ <iterator>\n#include <cassert>\n#include <algorithm>\n\nnamespace tools {\n\
    \  template <typename RandomAccessIterator>\n  bool next_matching(RandomAccessIterator\
    \ begin, RandomAccessIterator end) {\n    const auto N = ::std::distance(begin,\
    \ end);\n    // assert(::tools::mex(begin, end) == N);\n    if (N <= 2) return\
    \ false;\n\n    auto l = (N - 2) / 2 * 2;\n    for (; l > 0 && begin[l - 1] >\
    \ begin[l + 1]; l -= 2);\n    ::std::sort(::std::next(begin, l), ::std::prev(end,\
    \ N % 2));\n\n    if (l == 0) {\n      if (N % 2 == 0) return false;\n      if\
    \ (begin[N - 1] == 0) {\n        ::std::rotate(begin, ::std::prev(end), end);\n\
    \        return false;\n      }\n      ::std::iter_swap(::std::next(begin, begin[N\
    \ - 1] - 1), ::std::prev(end));\n      return true;\n    }\n\n    ::std::iter_swap(::std::next(begin,\
    \ l - 1), ::std::upper_bound(::std::next(begin, l), ::std::prev(end, N % 2), begin[l\
    \ - 1]));\n    return true;\n  }\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/next_matching.hpp
  requiredBy: []
  timestamp: '2022-08-13 22:46:28+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - tests/next_matching.test.cpp
documentation_of: tools/next_matching.hpp
layout: document
title: Enumerate all matchings
---

```cpp
template <typename RandomAccessIterator>
bool next_matching(RandomAccessIterator begin, RandomAccessIterator end);
```

It enumerates all the ways to divide $\\{0, 1, \ldots, N - 1\\}$ into $\left\lfloor \frac{N}{2} \right\rfloor$ unordered pairs and at most one remainder.
It can be used as follows.

```cpp
std::vector<int> a(N);
std::iota(a.begin(), a.end(), 0);
do {
  // a[0] and a[1] are a pair, a[2] and a[3] are a pair, and so on.
} while (tools::next_matching(a.begin(), a.end()));
```

It returns `true` if the next way exists, `false` otherwise.

## Constraints
- The given sequence is a permutation of $(0, 1, \ldots, N - 1)$.

## Time Complexity
- $O(N \log N)$ worst
- $O(1)$ amortized
- Note: Since the number of ways is $\left(2 \left\lfloor \frac{N - 1}{2} \right\rfloor + 1\right)!!$, it takes $O\left(\left(2 \left\lfloor \frac{N - 1}{2} \right\rfloor + 1\right)!!\right)$ time totally if you enumerate all the ways.

## License
- CC0

## Author
- anqooqie
