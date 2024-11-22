---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/transposed.test.cpp
    title: tests/transposed.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/transposed.hpp\"\n\n\n\n#include <vector>\n#include\
    \ <cassert>\n#include <algorithm>\n#include <cstddef>\n#include <array>\n\nnamespace\
    \ tools {\n  template <typename T>\n  ::std::vector<::std::vector<T>> transposed(const\
    \ ::std::vector<::std::vector<T>>& matrix) {\n    const auto N = matrix.size();\n\
    \    const auto M = matrix.empty() ? 0 : matrix.front().size();\n    assert(::std::all_of(matrix.begin(),\
    \ matrix.end(), [&](const auto& row) { return row.size() == M; }));\n\n    auto\
    \ res = ::std::vector(M, ::std::vector<T>(N));\n    for (::std::size_t r = 0;\
    \ r < M; ++r) {\n      for (::std::size_t c = 0; c < N; ++c) {\n        res[r][c]\
    \ = matrix[c][r];\n      }\n    }\n    return res;\n  }\n\n  template <typename\
    \ T, ::std::size_t N>\n  ::std::vector<::std::array<T, N>> transposed(const ::std::array<::std::vector<T>,\
    \ N>& matrix) {\n    const auto M = matrix.empty() ? 0 : matrix.front().size();\n\
    \    assert(::std::all_of(matrix.begin(), matrix.end(), [&](const auto& row) {\
    \ return row.size() == M; }));\n\n    auto res = ::std::vector(M, ::std::array<T,\
    \ N>{});\n    for (::std::size_t r = 0; r < M; ++r) {\n      for (::std::size_t\
    \ c = 0; c < N; ++c) {\n        res[r][c] = matrix[c][r];\n      }\n    }\n  \
    \  return res;\n  }\n\n  template <typename T, ::std::size_t M>\n  ::std::array<::std::vector<T>,\
    \ M> transposed(const ::std::vector<::std::array<T, M>>& matrix) {\n    const\
    \ auto N = matrix.size();\n\n    ::std::array<::std::vector<T>, M> res;\n    for\
    \ (::std::size_t r = 0; r < M; ++r) {\n      res[r].resize(N);\n      for (::std::size_t\
    \ c = 0; c < N; ++c) {\n        res[r][c] = matrix[c][r];\n      }\n    }\n  \
    \  return res;\n  }\n\n  template <typename T, ::std::size_t N, ::std::size_t\
    \ M>\n  ::std::array<::std::array<T, N>, M> transposed(const ::std::array<::std::array<T,\
    \ M>, N>& matrix) {\n    ::std::array<::std::array<T, N>, M> res;\n    for (::std::size_t\
    \ r = 0; r < M; ++r) {\n      for (::std::size_t c = 0; c < N; ++c) {\n      \
    \  res[r][c] = matrix[c][r];\n      }\n    }\n    return res;\n  }\n}\n\n\n"
  code: "#ifndef TOOLS_TRANSPOSED_HPP\n#define TOOLS_TRANSPOSED_HPP\n\n#include <vector>\n\
    #include <cassert>\n#include <algorithm>\n#include <cstddef>\n#include <array>\n\
    \nnamespace tools {\n  template <typename T>\n  ::std::vector<::std::vector<T>>\
    \ transposed(const ::std::vector<::std::vector<T>>& matrix) {\n    const auto\
    \ N = matrix.size();\n    const auto M = matrix.empty() ? 0 : matrix.front().size();\n\
    \    assert(::std::all_of(matrix.begin(), matrix.end(), [&](const auto& row) {\
    \ return row.size() == M; }));\n\n    auto res = ::std::vector(M, ::std::vector<T>(N));\n\
    \    for (::std::size_t r = 0; r < M; ++r) {\n      for (::std::size_t c = 0;\
    \ c < N; ++c) {\n        res[r][c] = matrix[c][r];\n      }\n    }\n    return\
    \ res;\n  }\n\n  template <typename T, ::std::size_t N>\n  ::std::vector<::std::array<T,\
    \ N>> transposed(const ::std::array<::std::vector<T>, N>& matrix) {\n    const\
    \ auto M = matrix.empty() ? 0 : matrix.front().size();\n    assert(::std::all_of(matrix.begin(),\
    \ matrix.end(), [&](const auto& row) { return row.size() == M; }));\n\n    auto\
    \ res = ::std::vector(M, ::std::array<T, N>{});\n    for (::std::size_t r = 0;\
    \ r < M; ++r) {\n      for (::std::size_t c = 0; c < N; ++c) {\n        res[r][c]\
    \ = matrix[c][r];\n      }\n    }\n    return res;\n  }\n\n  template <typename\
    \ T, ::std::size_t M>\n  ::std::array<::std::vector<T>, M> transposed(const ::std::vector<::std::array<T,\
    \ M>>& matrix) {\n    const auto N = matrix.size();\n\n    ::std::array<::std::vector<T>,\
    \ M> res;\n    for (::std::size_t r = 0; r < M; ++r) {\n      res[r].resize(N);\n\
    \      for (::std::size_t c = 0; c < N; ++c) {\n        res[r][c] = matrix[c][r];\n\
    \      }\n    }\n    return res;\n  }\n\n  template <typename T, ::std::size_t\
    \ N, ::std::size_t M>\n  ::std::array<::std::array<T, N>, M> transposed(const\
    \ ::std::array<::std::array<T, M>, N>& matrix) {\n    ::std::array<::std::array<T,\
    \ N>, M> res;\n    for (::std::size_t r = 0; r < M; ++r) {\n      for (::std::size_t\
    \ c = 0; c < N; ++c) {\n        res[r][c] = matrix[c][r];\n      }\n    }\n  \
    \  return res;\n  }\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/transposed.hpp
  requiredBy: []
  timestamp: '2024-11-22 17:09:34+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/transposed.test.cpp
documentation_of: tools/transposed.hpp
layout: document
title: Transposition
---

```cpp
template <typename T>
std::vector<std::vector<T>> transposed(std::vector<std::vector<T>> A);

template <typename T, std::size_t N>
std::vector<std::array<T, N>> transposed(std::array<std::vector<T>, N> A);

template <typename T, std::size_t M>
std::array<std::vector<T>, M> transposed(std::vector<std::array<T, M>> A);

template <typename T, std::size_t N, std::size_t M>
std::array<std::array<T, N>, M> transposed(std::array<std::array<T, M>, N> A);
```

Given a $N \times M$ matrix $A$, it returns a $M \times N$ matrix $A^\mathsf{T}$.
If $N = 0$ and a row is `std::vector<T>`, it assumes $M = 0$ since $M$ cannot be determined.

### Constraints
- For all $r$ such that $0 \leq r < N$, `A[r].size()` equals $M$.

### Time Complexity
- $O(NM)$

### License
- CC0

### Author
- anqooqie
