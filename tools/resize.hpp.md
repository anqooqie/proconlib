---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: tools/util.hpp
    title: Commonly used utilities for competitive programming
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/range_of_digit_products.test.cpp
    title: tests/range_of_digit_products.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/resize.test.cpp
    title: tests/resize.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/util.test.cpp
    title: tests/util.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/resize.hpp\"\n\n\n\n#include <vector>\n#include <cstddef>\n\
    #include <array>\n#include <cassert>\n\nnamespace tools {\n  template <class T,\
    \ class Allocator, typename Head>\n  void resize(::std::vector<T, Allocator>&\
    \ vector, const Head& head) {\n    vector.resize(head);\n  }\n  template <class\
    \ T, ::std::size_t N, typename Head>\n  void resize([[maybe_unused]] ::std::array<T,\
    \ N>& array, [[maybe_unused]] const Head& head) {\n    assert(array.size() ==\
    \ static_cast<::std::size_t>(head));\n  }\n\n  template <class T, class Allocator,\
    \ typename Head, typename... Tail>\n  void resize(::std::vector<T, Allocator>&\
    \ vector, const Head& head, const Tail&... tail);\n  template <class T, ::std::size_t\
    \ N, typename Head, typename... Tail>\n  void resize(::std::array<T, N>& array,\
    \ const Head& head, const Tail&... tail);\n\n  template <class T, class Allocator,\
    \ typename Head, typename... Tail>\n  void resize(::std::vector<T, Allocator>&\
    \ vector, const Head& head, const Tail&... tail) {\n    vector.resize(head);\n\
    \    for (auto& child : vector) {\n      ::tools::resize(child, tail...);\n  \
    \  }\n  }\n  template <class T, ::std::size_t N, typename Head, typename... Tail>\n\
    \  void resize(::std::array<T, N>& array, [[maybe_unused]] const Head& head, const\
    \ Tail&... tail) {\n    assert(array.size() == static_cast<::std::size_t>(head));\n\
    \    for (auto& child : array) {\n      ::tools::resize(child, tail...);\n   \
    \ }\n  }\n}\n\n\n"
  code: "#ifndef TOOLS_RESIZE_HPP\n#define TOOLS_RESIZE_HPP\n\n#include <vector>\n\
    #include <cstddef>\n#include <array>\n#include <cassert>\n\nnamespace tools {\n\
    \  template <class T, class Allocator, typename Head>\n  void resize(::std::vector<T,\
    \ Allocator>& vector, const Head& head) {\n    vector.resize(head);\n  }\n  template\
    \ <class T, ::std::size_t N, typename Head>\n  void resize([[maybe_unused]] ::std::array<T,\
    \ N>& array, [[maybe_unused]] const Head& head) {\n    assert(array.size() ==\
    \ static_cast<::std::size_t>(head));\n  }\n\n  template <class T, class Allocator,\
    \ typename Head, typename... Tail>\n  void resize(::std::vector<T, Allocator>&\
    \ vector, const Head& head, const Tail&... tail);\n  template <class T, ::std::size_t\
    \ N, typename Head, typename... Tail>\n  void resize(::std::array<T, N>& array,\
    \ const Head& head, const Tail&... tail);\n\n  template <class T, class Allocator,\
    \ typename Head, typename... Tail>\n  void resize(::std::vector<T, Allocator>&\
    \ vector, const Head& head, const Tail&... tail) {\n    vector.resize(head);\n\
    \    for (auto& child : vector) {\n      ::tools::resize(child, tail...);\n  \
    \  }\n  }\n  template <class T, ::std::size_t N, typename Head, typename... Tail>\n\
    \  void resize(::std::array<T, N>& array, [[maybe_unused]] const Head& head, const\
    \ Tail&... tail) {\n    assert(array.size() == static_cast<::std::size_t>(head));\n\
    \    for (auto& child : array) {\n      ::tools::resize(child, tail...);\n   \
    \ }\n  }\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/resize.hpp
  requiredBy:
  - tools/util.hpp
  timestamp: '2022-09-03 15:52:01+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/util.test.cpp
  - tests/resize.test.cpp
  - tests/range_of_digit_products.test.cpp
documentation_of: tools/resize.hpp
layout: document
title: Resize a multi-dimensional vector
---

```cpp
template <class T, class Allocator, typename Head>
void resize(std::vector<T, Allocator>& vector, const Head& head);

template <class T, class Allocator, typename Head, typename... Tail>
void resize(std::vector<T, Allocator>& vector, const Head& head, const Tail&... tail);
```

It resizes each dimension of a multi-dimensional vector at once.

## Example
Let us assume that the type of `v` is `std::vector<std::vector<std::vector<int>>>`.
After calling `tools::resize(v, 3, 4, 5);`, `v[x][y][z]` for $0 \leq x < 3$, $0 \leq y < 4$ and $0 \leq z < 5$ will be available.

## Constraints
- None

## Time Complexity
- $O(N)$ where N is the product of the size of all dimensions

## References
- [C++ の 再帰template を使ったあまり使えない競プロ用 std::vector 操作テク - koyumeishiのブログ](https://koyumeishi.hatenablog.com/entry/2016/02/01/152426)

## License
- CC0

## Author
- anqooqie
