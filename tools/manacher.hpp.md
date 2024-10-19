---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/mex.hpp
    title: Minimum excluded value
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/manacher.test.cpp
    title: tests/manacher.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/manacher.hpp\"\n\n\n\n#include <iterator>\n#include\
    \ <vector>\n#include <cstddef>\n#include <utility>\n#include <algorithm>\n#line\
    \ 1 \"tools/mex.hpp\"\n\n\n\n#include <type_traits>\n#line 8 \"tools/mex.hpp\"\
    \n#include <cassert>\n#line 10 \"tools/mex.hpp\"\n\nnamespace tools {\n\n  template\
    \ <typename InputIterator>\n  ::std::decay_t<decltype(*::std::declval<InputIterator>())>\
    \ mex(InputIterator begin, InputIterator end) {\n    using T = ::std::decay_t<decltype(*::std::declval<InputIterator>())>;\n\
    \    const ::std::vector<T> orig(begin, end);\n    const ::std::size_t n = orig.size();\n\
    \n    assert(::std::all_of(orig.begin(), orig.end(), [](const auto& o) { return\
    \ o >= 0; }));\n\n    ::std::vector<bool> exists(n, false);\n    for (const ::std::size_t\
    \ o : orig) {\n      if (o < n) {\n        exists[o] = true;\n      }\n    }\n\
    \    for (::std::size_t i = 0; i < n; ++i) {\n      if (!exists[i]) {\n      \
    \  return i;\n      }\n    }\n    return n;\n  }\n}\n\n\n#line 10 \"tools/manacher.hpp\"\
    \n\nnamespace tools {\n  template <typename InputIterator, typename OutputIterator>\n\
    \  void manacher(const InputIterator begin, const InputIterator end, const OutputIterator\
    \ result) {\n    using T = typename ::std::iterator_traits<InputIterator>::value_type;\n\
    \    ::std::vector<T> S(begin, end);\n    const auto N = S.size();\n    {\n  \
    \    ::std::vector<T> new_S(2 * N + 1, ::tools::mex(S.begin(), S.end()));\n  \
    \    for (::std::size_t i = 0; i < N; ++i) {\n        new_S[2 * i + 1] = S[i];\n\
    \      }\n      S = ::std::move(new_S);\n    }\n\n    ::std::vector<::std::size_t>\
    \ R(S.size());\n    {\n      ::std::size_t i = 0;\n      ::std::size_t j = 0;\n\
    \      while (i < S.size()) {\n        for (; i >= j && i + j < S.size() && S[i\
    \ - j] == S[i + j]; ++j);\n        R[i] = j;\n        ::std::size_t k;\n     \
    \   for (k = 1; i >= k && k + R[i - k] < j; ++k) {\n          R[i + k] = R[i -\
    \ k];\n        }\n        i += k;\n        j -= k;\n      }\n    }\n\n    ::std::vector<::std::pair<::std::size_t,\
    \ ::std::size_t>> new_R(S.size());\n    for (::std::size_t i = 0; i <= N; ++i)\
    \ {\n      new_R[i * 2] = ::std::make_pair(i - (R[i * 2] - 1) / 2, i + (R[i *\
    \ 2] - 1) / 2);\n    }\n    for (::std::size_t i = 0; i < N; ++i) {\n      new_R[i\
    \ * 2 + 1] = ::std::make_pair(i - (R[i * 2 + 1] / 2 - 1), i + R[i * 2 + 1] / 2);\n\
    \    }\n    ::std::move(new_R.begin(), new_R.end(), result);\n  }\n}\n\n\n"
  code: "#ifndef TOOLS_MANACHER_HPP\n#define TOOLS_MANACHER_HPP\n\n#include <iterator>\n\
    #include <vector>\n#include <cstddef>\n#include <utility>\n#include <algorithm>\n\
    #include \"tools/mex.hpp\"\n\nnamespace tools {\n  template <typename InputIterator,\
    \ typename OutputIterator>\n  void manacher(const InputIterator begin, const InputIterator\
    \ end, const OutputIterator result) {\n    using T = typename ::std::iterator_traits<InputIterator>::value_type;\n\
    \    ::std::vector<T> S(begin, end);\n    const auto N = S.size();\n    {\n  \
    \    ::std::vector<T> new_S(2 * N + 1, ::tools::mex(S.begin(), S.end()));\n  \
    \    for (::std::size_t i = 0; i < N; ++i) {\n        new_S[2 * i + 1] = S[i];\n\
    \      }\n      S = ::std::move(new_S);\n    }\n\n    ::std::vector<::std::size_t>\
    \ R(S.size());\n    {\n      ::std::size_t i = 0;\n      ::std::size_t j = 0;\n\
    \      while (i < S.size()) {\n        for (; i >= j && i + j < S.size() && S[i\
    \ - j] == S[i + j]; ++j);\n        R[i] = j;\n        ::std::size_t k;\n     \
    \   for (k = 1; i >= k && k + R[i - k] < j; ++k) {\n          R[i + k] = R[i -\
    \ k];\n        }\n        i += k;\n        j -= k;\n      }\n    }\n\n    ::std::vector<::std::pair<::std::size_t,\
    \ ::std::size_t>> new_R(S.size());\n    for (::std::size_t i = 0; i <= N; ++i)\
    \ {\n      new_R[i * 2] = ::std::make_pair(i - (R[i * 2] - 1) / 2, i + (R[i *\
    \ 2] - 1) / 2);\n    }\n    for (::std::size_t i = 0; i < N; ++i) {\n      new_R[i\
    \ * 2 + 1] = ::std::make_pair(i - (R[i * 2 + 1] / 2 - 1), i + R[i * 2 + 1] / 2);\n\
    \    }\n    ::std::move(new_R.begin(), new_R.end(), result);\n  }\n}\n\n#endif\n"
  dependsOn:
  - tools/mex.hpp
  isVerificationFile: false
  path: tools/manacher.hpp
  requiredBy: []
  timestamp: '2024-10-20 00:08:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/manacher.test.cpp
documentation_of: tools/manacher.hpp
layout: document
title: Manacher
---

```cpp
template <typename InputIterator, typename OutputIterator>
void manacher(InputIterator begin, InputIterator end, OutputIterator result);
```

Given a sequence $(a_0, a_1, \ldots, a_{N - 1})$ from `begin` and `end`, it stores the sequence $((l_0, r_0), (l_1, r_1), \ldots, (l_{2N}, r_{2N}))$ to `result` where the output sequence represents the following facts.

Let $a[l, r)$ denote the continuous subsequence of $a$ created using $a_i$ such that $l \leq i < r$.
The longest palindrome centered on $a_i$ is $a[l_{2i + 1}, r_{2i + 1})$.
The longest palindrome centered on the $i$-th one of the $N + 1$ boundaries between the elements is $a[l_{2i}, r_{2i})$. (Note that $i$ is $0$-indexed.)

### Constraints
- An integer can be read from `<InputIterator>`.
- A pair of two integers can be written to `<OutputIterator>`.

### Time Complexity
- $O(N)$

### License
- CC0

### Author
- anqooqie
