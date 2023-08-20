---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/hash_combine.hpp
    title: Combine hash values
  - icon: ':heavy_check_mark:'
    path: tools/now.hpp
    title: The number of nanoseconds that have elapsed since epoch
  - icon: ':heavy_check_mark:'
    path: tools/tuple_hash.hpp
    title: Hash of std::tuple
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: tools/util.hpp
    title: Commonly used utilities for competitive programming
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/extend_hash.test.cpp
    title: tests/extend_hash.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/util.test.cpp
    title: tests/util.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/extend_hash.hpp\"\n\n\n\n// WARNING:\n// This file\
    \ adds partial specializations for classes in std namespace, for convenience.\n\
    // Strictly speaking, it is not allowed in C++.\n// It makes the program ill-formed\
    \ to include this file, and may cause undefined behavior.\n\n#include <cstddef>\n\
    #include <functional>\n#include <tuple>\n#include <utility>\n#line 1 \"tools/tuple_hash.hpp\"\
    \n\n\n\n#line 6 \"tools/tuple_hash.hpp\"\n#include <limits>\n#line 1 \"tools/now.hpp\"\
    \n\n\n\n#include <chrono>\n\nnamespace tools {\n  inline long long now() {\n \
    \   return ::std::chrono::duration_cast<::std::chrono::nanoseconds>(::std::chrono::high_resolution_clock::now().time_since_epoch()).count();\n\
    \  }\n}\n\n\n#line 1 \"tools/hash_combine.hpp\"\n\n\n\n#line 6 \"tools/hash_combine.hpp\"\
    \n\n// Source: https://github.com/google/cityhash/blob/f5dc54147fcce12cefd16548c8e760d68ac04226/src/city.h\n\
    // License: MIT\n// Author: Google Inc.\n\n// Copyright (c) 2011 Google, Inc.\n\
    //\n// Permission is hereby granted, free of charge, to any person obtaining a\
    \ copy\n// of this software and associated documentation files (the \"Software\"\
    ), to deal\n// in the Software without restriction, including without limitation\
    \ the rights\n// to use, copy, modify, merge, publish, distribute, sublicense,\
    \ and/or sell\n// copies of the Software, and to permit persons to whom the Software\
    \ is\n// furnished to do so, subject to the following conditions:\n//\n// The\
    \ above copyright notice and this permission notice shall be included in\n// all\
    \ copies or substantial portions of the Software.\n//\n// THE SOFTWARE IS PROVIDED\
    \ \"AS IS\", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR\n// IMPLIED, INCLUDING BUT\
    \ NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,\n// FITNESS FOR A PARTICULAR\
    \ PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE\n// AUTHORS OR COPYRIGHT\
    \ HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER\n// LIABILITY, WHETHER IN\
    \ AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,\n// OUT OF OR IN CONNECTION\
    \ WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN\n// THE SOFTWARE.\n\nnamespace\
    \ tools {\n  template <typename T>\n  void hash_combine(::std::size_t& seed, const\
    \ T& v) {\n    static const ::std::hash<T> hasher;\n    static constexpr ::std::size_t\
    \ k_mul = 0x9ddfea08eb382d69ULL;\n    ::std::size_t a = (hasher(v) ^ seed) * k_mul;\n\
    \    a ^= (a >> 47);\n    ::std::size_t b = (seed ^ a) * k_mul;\n    b ^= (b >>\
    \ 47);\n    seed = b * k_mul;\n  }\n}\n\n\n#line 11 \"tools/tuple_hash.hpp\"\n\
    \nnamespace tools {\n  template <typename... Ts>\n  struct tuple_hash {\n    template\
    \ <::std::size_t I = sizeof...(Ts) - 1>\n    ::std::size_t operator()(const ::std::tuple<Ts...>&\
    \ key) const {\n      if constexpr (I == ::std::numeric_limits<::std::size_t>::max())\
    \ {\n        static const ::std::size_t seed = ::tools::now();\n        return\
    \ seed;\n      } else {\n        ::std::size_t seed = this->operator()<I - 1>(key);\n\
    \        ::tools::hash_combine(seed, ::std::get<I>(key));\n        return seed;\n\
    \      }\n    }\n  };\n}\n\n\n#line 14 \"tools/extend_hash.hpp\"\n\nnamespace\
    \ std {\n  template <class T1, class T2>\n  struct hash<::std::pair<T1, T2>> {\n\
    \    ::std::size_t operator()(const ::std::pair<T1, T2>& key) const {\n      static\
    \ const ::tools::tuple_hash<T1, T2> hasher;\n      return hasher(::std::make_tuple(key.first,\
    \ key.second));\n    }\n  };\n\n  template <class... Args>\n  struct hash<::std::tuple<Args...>>\
    \ {\n    ::std::size_t operator()(const ::std::tuple<Args...>& key) const {\n\
    \      static const ::tools::tuple_hash<Args...> hasher;\n      return hasher(key);\n\
    \    }\n  };\n}\n\n\n"
  code: "#ifndef TOOLS_EXTEND_HASH_HPP\n#define TOOLS_EXTEND_HASH_HPP\n\n// WARNING:\n\
    // This file adds partial specializations for classes in std namespace, for convenience.\n\
    // Strictly speaking, it is not allowed in C++.\n// It makes the program ill-formed\
    \ to include this file, and may cause undefined behavior.\n\n#include <cstddef>\n\
    #include <functional>\n#include <tuple>\n#include <utility>\n#include \"tools/tuple_hash.hpp\"\
    \n\nnamespace std {\n  template <class T1, class T2>\n  struct hash<::std::pair<T1,\
    \ T2>> {\n    ::std::size_t operator()(const ::std::pair<T1, T2>& key) const {\n\
    \      static const ::tools::tuple_hash<T1, T2> hasher;\n      return hasher(::std::make_tuple(key.first,\
    \ key.second));\n    }\n  };\n\n  template <class... Args>\n  struct hash<::std::tuple<Args...>>\
    \ {\n    ::std::size_t operator()(const ::std::tuple<Args...>& key) const {\n\
    \      static const ::tools::tuple_hash<Args...> hasher;\n      return hasher(key);\n\
    \    }\n  };\n}\n\n#endif\n"
  dependsOn:
  - tools/tuple_hash.hpp
  - tools/now.hpp
  - tools/hash_combine.hpp
  isVerificationFile: false
  path: tools/extend_hash.hpp
  requiredBy:
  - tools/util.hpp
  timestamp: '2022-11-20 17:00:02+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/util.test.cpp
  - tests/extend_hash.test.cpp
documentation_of: tools/extend_hash.hpp
layout: document
title: Extend std::hash
---

```cpp
namespace std {
  template <class T1, class T2>
  struct hash<std::pair<T1, T2>> {
    std::size_t operator()(const std::pair<T1, T2>& key) const;
  };

  template <class... Args>
  struct hash<std::tuple<Args...>> {
    std::size_t operator()(const std::tuple<Args...>& key) const;
  };
}
```

It adds some specializations of `std::hash`.
Hereby, it gets possible to compile `std::hash<std::pair<T1, T2>>` and `std::hash<std::tuple<Args...>>`.

## Warning
This file adds partial specializations for classes in std namespace, for convenience.
Strictly speaking, it is not allowed in C++.
It makes the program ill-formed to include this file, and may cause undefined behavior.

## Constraints
- None

## Time Complexity
- Not applicable

## License
- CC0

## Author
- anqooqie
