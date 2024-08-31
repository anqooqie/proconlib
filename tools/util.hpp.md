---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: tools/extend_hash.hpp
    title: Extend std::hash
  - icon: ':question:'
    path: tools/extend_input.hpp
    title: Extend operator>>
  - icon: ':question:'
    path: tools/extend_output.hpp
    title: Extend operator<<
  - icon: ':question:'
    path: tools/fill.hpp
    title: Fill a multi-dimensional vector
  - icon: ':question:'
    path: tools/has_mod.hpp
    title: Check whether T has the member function mod()
  - icon: ':question:'
    path: tools/hash_combine.hpp
    title: Combine hash values
  - icon: ':question:'
    path: tools/is_range.hpp
    title: Check whether T is a range type
  - icon: ':question:'
    path: tools/now.hpp
    title: The number of nanoseconds that have elapsed since epoch
  - icon: ':question:'
    path: tools/resize.hpp
    title: Resize a multi-dimensional vector
  - icon: ':question:'
    path: tools/tuple_hash.hpp
    title: Hash of std::tuple
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/util.test.cpp
    title: tests/util.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://anqooqie.github.io/proconlib/
  bundledCode: "#line 1 \"tools/util.hpp\"\n\n\n\n// To see the details of my library,\
    \ visit my GitHub Pages.\n// https://anqooqie.github.io/proconlib/\n\n#ifdef LOCAL\n\
    \  #ifndef _GLIBCXX_DEBUG\n    #define _GLIBCXX_DEBUG\n  #endif\n#else\n  #ifndef\
    \ NDEBUG\n    #define NDEBUG\n  #endif\n#endif\n\n#include <bits/stdc++.h>\n#line\
    \ 1 \"tools/resize.hpp\"\n\n\n\n#line 8 \"tools/resize.hpp\"\n\nnamespace tools\
    \ {\n  template <class T, class Allocator, typename Head>\n  void resize(::std::vector<T,\
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
    \ }\n  }\n}\n\n\n#line 1 \"tools/fill.hpp\"\n\n\n\n#include <type_traits>\n#line\
    \ 1 \"tools/is_range.hpp\"\n\n\n\n#line 7 \"tools/is_range.hpp\"\n\nnamespace\
    \ tools {\n  template <typename T, typename = ::std::void_t<>>\n  struct is_range\
    \ : ::std::false_type {};\n\n  template <typename T>\n  struct is_range<T, ::std::void_t<decltype(::std::begin(::std::declval<T>()),\
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
    \ : array) {\n      ::tools::fill(child, value);\n    }\n  }\n}\n\n\n#line 1 \"\
    tools/extend_input.hpp\"\n\n\n\n// WARNING:\n// This file adds functions to std\
    \ namespace for convenience.\n// Strictly speaking, it is not allowed in C++.\n\
    // It makes the program ill-formed to include this file, and may cause undefined\
    \ behavior.\n\n#line 1 \"tools/has_mod.hpp\"\n\n\n\n#line 6 \"tools/has_mod.hpp\"\
    \n\nnamespace tools {\n  template <typename T, typename = ::std::void_t<>>\n \
    \ struct has_mod : ::std::false_type {};\n\n  template <typename T>\n  struct\
    \ has_mod<T, ::std::void_t<decltype(::std::declval<T>().mod())>> : ::std::true_type\
    \ {};\n\n  template <typename T>\n  inline constexpr bool has_mod_v = ::tools::has_mod<T>::value;\n\
    }\n\n\n#line 16 \"tools/extend_input.hpp\"\n\nnamespace tools {\n  namespace detail\
    \ {\n    namespace extend_input {\n      template <typename T>\n      ::std::istream&\
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
    \ x = T(n);\n    return is;\n  }\n}\n\n\n#line 1 \"tools/extend_output.hpp\"\n\
    \n\n\n// WARNING:\n// This file adds functions to std namespace for convenience.\n\
    // Strictly speaking, it is not allowed in C++.\n// It makes the program ill-formed\
    \ to include this file, and may cause undefined behavior.\n\n#line 11 \"tools/extend_output.hpp\"\
    \n#include <optional>\n#line 22 \"tools/extend_output.hpp\"\n\nnamespace tools\
    \ {\n  namespace detail {\n    namespace extend_output {\n      template <typename\
    \ T>\n      ::std::ostream& debug_print(::std::ostream& os, const T& container)\
    \ {\n        ::std::string delimiter = \"\";\n        os << '[';\n        for\
    \ (const auto& v : container) {\n          os << delimiter << v;\n          delimiter\
    \ = \", \";\n        }\n        os << ']';\n        return os;\n      }\n    }\n\
    \  }\n}\n\nnamespace std {\n  template <class T, ::std::size_t N>\n  ::std::ostream&\
    \ operator<<(::std::ostream& os, const ::std::array<T, N>& array) {\n    return\
    \ ::tools::detail::extend_output::debug_print(os, array);\n  }\n  \n  template\
    \ <typename T>\n  ::std::ostream& operator<<(::std::ostream& os, const ::std::optional<T>&\
    \ optional) {\n    if (optional) {\n      return os << *optional;\n    } else\
    \ {\n      return os << \"null\";\n    }\n  }\n  \n  template <class T1, class\
    \ T2>\n  ::std::ostream& operator<<(::std::ostream& os, const ::std::pair<T1,\
    \ T2>& pair) {\n    return os << '[' << pair.first << \", \" << pair.second <<\
    \ ']';\n  }\n  \n  template <class T, class Container>\n  ::std::ostream& operator<<(::std::ostream&\
    \ os, ::std::queue<T, Container>& queue) {\n    ::std::queue<T, Container> other\
    \ = queue;\n    ::std::string delimiter = \"\";\n    os << '[';\n    while (!queue.empty())\
    \ {\n      os << delimiter << queue.front();\n      delimiter = \", \";\n    \
    \  queue.pop();\n    }\n    os << ']';\n  \n    queue = ::std::move(other);\n\
    \    return os;\n  }\n  \n  template <class T, class Container>\n  ::std::ostream&\
    \ operator<<(::std::ostream& os, ::std::stack<T, Container>& stack) {\n    ::std::stack<T,\
    \ Container> other;\n    while (!stack.empty()) {\n      other.push(stack.top());\n\
    \      stack.pop();\n    }\n  \n    ::std::string delimiter = \"\";\n    os <<\
    \ '[';\n    while (!other.empty()) {\n      os << delimiter << other.top();\n\
    \      delimiter = \", \";\n      stack.push(other.top());\n      other.pop();\n\
    \    }\n    os << ']';\n  \n    return os;\n  }\n  \n  template <int I = -1, typename...\
    \ Args>\n  ::std::ostream& operator<<(::std::ostream& os, const ::std::tuple<Args...>&\
    \ tuple) {\n    if constexpr (I == -1) {\n      os << '[';\n    } else if constexpr\
    \ (I == int(sizeof...(Args))) {\n      os << ']';\n    } else if constexpr (I\
    \ == 0) {\n      os << ::std::get<I>(tuple);\n    } else {\n      os << \", \"\
    \ << ::std::get<I>(tuple);\n    }\n  \n    if constexpr (I < int(sizeof...(Args)))\
    \ {\n      return operator<<<I + 1>(os, tuple);\n    } else {\n      return os;\n\
    \    }\n  }\n  \n  template <class Key, class T, class Hash, class Pred, class\
    \ Allocator>\n  ::std::ostream& operator<<(::std::ostream& os, const ::std::unordered_map<Key,\
    \ T, Hash, Pred, Allocator>& unordered_map) {\n    return ::tools::detail::extend_output::debug_print(os,\
    \ unordered_map);\n  }\n  \n  template <class Key, class Hash, class Pred, class\
    \ Allocator>\n  ::std::ostream& operator<<(::std::ostream& os, const ::std::unordered_set<Key,\
    \ Hash, Pred, Allocator>& unordered_set) {\n    return ::tools::detail::extend_output::debug_print(os,\
    \ unordered_set);\n  }\n  \n  template <class T, class Allocator>\n  ::std::ostream&\
    \ operator<<(::std::ostream& os, const ::std::vector<T, Allocator>& vector) {\n\
    \    return ::tools::detail::extend_output::debug_print(os, vector);\n  }\n  \n\
    \  template <typename T>\n  ::std::enable_if_t<::tools::has_mod_v<T>, ::std::ostream&>\
    \ operator<<(::std::ostream& os, const T& x) {\n    return os << x.val();\n  }\n\
    }\n\n\n#line 1 \"tools/extend_hash.hpp\"\n\n\n\n// WARNING:\n// This file adds\
    \ partial specializations for classes in std namespace, for convenience.\n// Strictly\
    \ speaking, it is not allowed in C++.\n// It makes the program ill-formed to include\
    \ this file, and may cause undefined behavior.\n\n#line 1 \"tools/tuple_hash.hpp\"\
    \n\n\n\n#line 1 \"tools/now.hpp\"\n\n\n\n#line 5 \"tools/now.hpp\"\n\nnamespace\
    \ tools {\n  inline long long now() {\n    return ::std::chrono::duration_cast<::std::chrono::nanoseconds>(::std::chrono::high_resolution_clock::now().time_since_epoch()).count();\n\
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
    \    }\n  };\n}\n\n\n#line 23 \"tools/util.hpp\"\n\nusing ll = long long;\nusing\
    \ ull = unsigned long long;\nusing i32 = ::std::int32_t;\nusing u32 = ::std::uint32_t;\n\
    using i64 = ::std::int64_t;\nusing u64 = ::std::uint64_t;\n\n#define ALL(x) ::std::begin(x),\
    \ ::std::end(x)\n#define REP(i, n) for (long long i = 0, i##_len = static_cast<long\
    \ long>(n); i < i##_len; ++i)\n\n\n"
  code: "#ifndef TOOLS_UTIL_HPP\n#define TOOLS_UTIL_HPP\n\n// To see the details of\
    \ my library, visit my GitHub Pages.\n// https://anqooqie.github.io/proconlib/\n\
    \n#ifdef LOCAL\n  #ifndef _GLIBCXX_DEBUG\n    #define _GLIBCXX_DEBUG\n  #endif\n\
    #else\n  #ifndef NDEBUG\n    #define NDEBUG\n  #endif\n#endif\n\n#include <bits/stdc++.h>\n\
    #include \"tools/resize.hpp\"\n#include \"tools/fill.hpp\"\n#include \"tools/extend_input.hpp\"\
    \n#include \"tools/extend_output.hpp\"\n#include \"tools/extend_hash.hpp\"\n\n\
    using ll = long long;\nusing ull = unsigned long long;\nusing i32 = ::std::int32_t;\n\
    using u32 = ::std::uint32_t;\nusing i64 = ::std::int64_t;\nusing u64 = ::std::uint64_t;\n\
    \n#define ALL(x) ::std::begin(x), ::std::end(x)\n#define REP(i, n) for (long long\
    \ i = 0, i##_len = static_cast<long long>(n); i < i##_len; ++i)\n\n#endif\n"
  dependsOn:
  - tools/resize.hpp
  - tools/fill.hpp
  - tools/is_range.hpp
  - tools/extend_input.hpp
  - tools/has_mod.hpp
  - tools/extend_output.hpp
  - tools/extend_hash.hpp
  - tools/tuple_hash.hpp
  - tools/now.hpp
  - tools/hash_combine.hpp
  isVerificationFile: false
  path: tools/util.hpp
  requiredBy: []
  timestamp: '2024-03-30 17:59:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/util.test.cpp
documentation_of: tools/util.hpp
layout: document
title: Commonly used utilities for competitive programming
---

They are miscellaneous code snippets for competitive programming.

### Warning
This file contains code snippets convenient to competitive programming but not allowed in C++ standard.
Therefore, it makes the program ill-formed to include this file, and may cause undefined behavior.

### Constraints
- It requires GCC.

### Time Complexity
- Not applicable

### License
- CC0

### Author
- anqooqie
