---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: tools/has_mod.hpp
    title: Check whether T has the member function mod()
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: tools/util.hpp
    title: Commonly used utilities for competitive programming
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/extend_input.test.cpp
    title: tests/extend_input.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/util.test.cpp
    title: tests/util.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/extend_input.hpp\"\n\n\n\n// WARNING:\n// This file\
    \ adds functions to std namespace for convenience.\n// Strictly speaking, it is\
    \ not allowed in C++.\n// It makes the program ill-formed to include this file,\
    \ and may cause undefined behavior.\n\n#include <array>\n#include <iostream>\n\
    #include <tuple>\n#include <type_traits>\n#include <utility>\n#include <vector>\n\
    #line 1 \"tools/has_mod.hpp\"\n\n\n\n#line 6 \"tools/has_mod.hpp\"\n\nnamespace\
    \ tools {\n  template <typename T, typename = ::std::void_t<>>\n  struct has_mod\
    \ : ::std::false_type {};\n\n  template <typename T>\n  struct has_mod<T, ::std::void_t<decltype(::std::declval<T>().mod())>>\
    \ : ::std::true_type {};\n\n  template <typename T>\n  inline constexpr bool has_mod_v\
    \ = ::tools::has_mod<T>::value;\n}\n\n\n#line 16 \"tools/extend_input.hpp\"\n\n\
    namespace tools {\n  namespace detail {\n    namespace extend_input {\n      template\
    \ <typename T>\n      ::std::istream& read(::std::istream& is, T& container) {\n\
    \        for (auto& v : container) {\n          is >> v;\n        }\n        return\
    \ is;\n      }\n    }\n  }\n}\n\nnamespace std {\n  template <class T, ::std::size_t\
    \ N>\n  ::std::istream& operator>>(::std::istream& is, ::std::array<T, N>& array)\
    \ {\n    return ::tools::detail::extend_input::read(is, array);\n  }\n\n  template\
    \ <class T1, class T2>\n  ::std::istream& operator>>(::std::istream& is, ::std::pair<T1,\
    \ T2>& pair) {\n    return is >> pair.first >> pair.second;\n  }\n\n  template\
    \ <int I = 0, typename... Args>\n  ::std::istream& operator>>(::std::istream&\
    \ is, ::std::tuple<Args...>& tuple) {\n    if constexpr (I < int(sizeof...(Args)))\
    \ {\n        is >> ::std::get<I>(tuple);\n        return operator>><I + 1>(is,\
    \ tuple);\n      } else {\n      return is;\n    }\n  }\n\n  template <class T,\
    \ class Allocator>\n  ::std::istream& operator>>(::std::istream& is, ::std::vector<T,\
    \ Allocator>& vector) {\n    return ::tools::detail::extend_input::read(is, vector);\n\
    \  }\n\n  template <typename T>\n  ::std::enable_if_t<::tools::has_mod_v<T>, ::std::istream&>\
    \ operator>>(::std::istream& is, T& x) {\n    long long n;\n    is >> n;\n   \
    \ x = T(n);\n    return is;\n  }\n}\n\n\n"
  code: "#ifndef TOOLS_EXTEND_INPUT_HPP\n#define TOOLS_EXTEND_INPUT_HPP\n\n// WARNING:\n\
    // This file adds functions to std namespace for convenience.\n// Strictly speaking,\
    \ it is not allowed in C++.\n// It makes the program ill-formed to include this\
    \ file, and may cause undefined behavior.\n\n#include <array>\n#include <iostream>\n\
    #include <tuple>\n#include <type_traits>\n#include <utility>\n#include <vector>\n\
    #include \"tools/has_mod.hpp\"\n\nnamespace tools {\n  namespace detail {\n  \
    \  namespace extend_input {\n      template <typename T>\n      ::std::istream&\
    \ read(::std::istream& is, T& container) {\n        for (auto& v : container)\
    \ {\n          is >> v;\n        }\n        return is;\n      }\n    }\n  }\n\
    }\n\nnamespace std {\n  template <class T, ::std::size_t N>\n  ::std::istream&\
    \ operator>>(::std::istream& is, ::std::array<T, N>& array) {\n    return ::tools::detail::extend_input::read(is,\
    \ array);\n  }\n\n  template <class T1, class T2>\n  ::std::istream& operator>>(::std::istream&\
    \ is, ::std::pair<T1, T2>& pair) {\n    return is >> pair.first >> pair.second;\n\
    \  }\n\n  template <int I = 0, typename... Args>\n  ::std::istream& operator>>(::std::istream&\
    \ is, ::std::tuple<Args...>& tuple) {\n    if constexpr (I < int(sizeof...(Args)))\
    \ {\n        is >> ::std::get<I>(tuple);\n        return operator>><I + 1>(is,\
    \ tuple);\n      } else {\n      return is;\n    }\n  }\n\n  template <class T,\
    \ class Allocator>\n  ::std::istream& operator>>(::std::istream& is, ::std::vector<T,\
    \ Allocator>& vector) {\n    return ::tools::detail::extend_input::read(is, vector);\n\
    \  }\n\n  template <typename T>\n  ::std::enable_if_t<::tools::has_mod_v<T>, ::std::istream&>\
    \ operator>>(::std::istream& is, T& x) {\n    long long n;\n    is >> n;\n   \
    \ x = T(n);\n    return is;\n  }\n}\n\n#endif\n"
  dependsOn:
  - tools/has_mod.hpp
  isVerificationFile: false
  path: tools/extend_input.hpp
  requiredBy:
  - tools/util.hpp
  timestamp: '2022-11-23 11:35:29+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/extend_input.test.cpp
  - tests/util.test.cpp
documentation_of: tools/extend_input.hpp
layout: document
title: Extend operator>>
---

```cpp
namespace std {
  template <class T, std::size_t N>
  std::istream& operator>>(std::istream& is, std::array<T, N>& array);

  template <class T1, class T2>
  std::istream& operator>>(std::istream& is, std::pair<T1, T2>& pair);

  template <typename... Args>
  std::istream& operator>>(std::istream& is, std::tuple<Args...>& tuple);

  template <class T, class Allocator>
  std::istream& operator>>(std::istream& is, std::vector<T, Allocator>& vector);

  template <typename T>
  std::enable_if_t<tools::has_mod_v<T>, std::istream&> operator>>(std::istream& is, T& x);
}
```

It adds some overloads of `operator>>`.
Hereby, it gets possible to store values to a container directly.

### Warning
This file adds functions to std namespace for convenience.
Strictly speaking, it is not allowed in C++.
It makes the program ill-formed to include this file, and may cause undefined behavior.

### Constraints
- None

### Time Complexity
- Not applicable

### License
- CC0

### Author
- anqooqie
