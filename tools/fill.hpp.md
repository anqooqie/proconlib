---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/is_range.hpp
    title: Check whether T is a range type
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: tools/util.hpp
    title: Commonly used utilities for competitive programming
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/fill.test.cpp
    title: tests/fill.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/util.test.cpp
    title: tests/util.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/fill.hpp\"\n\n\n\n#include <type_traits>\n#include\
    \ <vector>\n#include <algorithm>\n#include <iterator>\n#include <cstddef>\n#include\
    \ <array>\n#line 1 \"tools/is_range.hpp\"\n\n\n\n#line 6 \"tools/is_range.hpp\"\
    \n#include <utility>\n\nnamespace tools {\n  template <typename T, typename =\
    \ ::std::void_t<>>\n  struct is_range : ::std::false_type {};\n\n  template <typename\
    \ T>\n  struct is_range<T, ::std::void_t<decltype(::std::begin(::std::declval<T>()),\
    \ ::std::end(::std::declval<T>()))>> : ::std::true_type {};\n\n  template <typename\
    \ T>\n  inline constexpr bool is_range_v = ::tools::is_range<T>::value;\n}\n\n\
    \n#line 11 \"tools/fill.hpp\"\n\nnamespace tools {\n  template <class T, class\
    \ Allocator, typename V>\n  ::std::enable_if_t<!::tools::is_range_v<T>, void>\
    \ fill(::std::vector<T, Allocator>& vector, const V& value) {\n    ::std::fill(::std::begin(vector),\
    \ ::std::end(vector), value);\n  }\n  template <class T, ::std::size_t N, typename\
    \ V>\n  ::std::enable_if_t<!::tools::is_range_v<T>, void> fill(::std::array<T,\
    \ N>& array, const V& value) {\n    ::std::fill(::std::begin(array), ::std::end(array),\
    \ value);\n  }\n\n  template <class T, class Allocator, typename V>\n  ::std::enable_if_t<::tools::is_range_v<T>,\
    \ void> fill(::std::vector<T, Allocator>& vector, const V& value);\n  template\
    \ <class T, ::std::size_t N, typename V>\n  ::std::enable_if_t<::tools::is_range_v<T>,\
    \ void> fill(::std::array<T, N>& array, const V& value);\n\n  template <class\
    \ T, class Allocator, typename V>\n  ::std::enable_if_t<::tools::is_range_v<T>,\
    \ void> fill(::std::vector<T, Allocator>& vector, const V& value) {\n    for (auto&\
    \ child : vector) {\n      ::tools::fill(child, value);\n    }\n  }\n  template\
    \ <class T, ::std::size_t N, typename V>\n  ::std::enable_if_t<::tools::is_range_v<T>,\
    \ void> fill(::std::array<T, N>& array, const V& value) {\n    for (auto& child\
    \ : array) {\n      ::tools::fill(child, value);\n    }\n  }\n}\n\n\n"
  code: "#ifndef TOOLS_FILL_HPP\n#define TOOLS_FILL_HPP\n\n#include <type_traits>\n\
    #include <vector>\n#include <algorithm>\n#include <iterator>\n#include <cstddef>\n\
    #include <array>\n#include \"tools/is_range.hpp\"\n\nnamespace tools {\n  template\
    \ <class T, class Allocator, typename V>\n  ::std::enable_if_t<!::tools::is_range_v<T>,\
    \ void> fill(::std::vector<T, Allocator>& vector, const V& value) {\n    ::std::fill(::std::begin(vector),\
    \ ::std::end(vector), value);\n  }\n  template <class T, ::std::size_t N, typename\
    \ V>\n  ::std::enable_if_t<!::tools::is_range_v<T>, void> fill(::std::array<T,\
    \ N>& array, const V& value) {\n    ::std::fill(::std::begin(array), ::std::end(array),\
    \ value);\n  }\n\n  template <class T, class Allocator, typename V>\n  ::std::enable_if_t<::tools::is_range_v<T>,\
    \ void> fill(::std::vector<T, Allocator>& vector, const V& value);\n  template\
    \ <class T, ::std::size_t N, typename V>\n  ::std::enable_if_t<::tools::is_range_v<T>,\
    \ void> fill(::std::array<T, N>& array, const V& value);\n\n  template <class\
    \ T, class Allocator, typename V>\n  ::std::enable_if_t<::tools::is_range_v<T>,\
    \ void> fill(::std::vector<T, Allocator>& vector, const V& value) {\n    for (auto&\
    \ child : vector) {\n      ::tools::fill(child, value);\n    }\n  }\n  template\
    \ <class T, ::std::size_t N, typename V>\n  ::std::enable_if_t<::tools::is_range_v<T>,\
    \ void> fill(::std::array<T, N>& array, const V& value) {\n    for (auto& child\
    \ : array) {\n      ::tools::fill(child, value);\n    }\n  }\n}\n\n#endif\n"
  dependsOn:
  - tools/is_range.hpp
  isVerificationFile: false
  path: tools/fill.hpp
  requiredBy:
  - tools/util.hpp
  timestamp: '2022-11-23 11:35:29+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/fill.test.cpp
  - tests/util.test.cpp
documentation_of: tools/fill.hpp
layout: document
title: Fill a multi-dimensional vector
---

```cpp
template <class T, class Allocator, typename V>
void fill(std::vector<T, Allocator>& vector, const V& value);
```

It fills all the elements of a multi-dimensional vector at once.

### Example
Let us assume that the type of `v` is `std::vector<std::vector<std::vector<int>>>`.
After calling `tools::fill(v, -1);`, all of `v[x][y][z]` will be $-1$.

### Constraints
- None

### Time Complexity
- $O(N)$ where N is the product of the size of all dimensions

### References
- [C++ の 再帰template を使ったあまり使えない競プロ用 std::vector 操作テク - koyumeishiのブログ](https://koyumeishi.hatenablog.com/entry/2016/02/01/152426)

### License
- CC0

### Author
- anqooqie
