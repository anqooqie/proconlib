---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/fill.hpp
    title: Fill a multi-dimensional vector
  - icon: ':heavy_check_mark:'
    path: tools/is_range.hpp
    title: Check whether T is a range type
  - icon: ':heavy_check_mark:'
    path: tools/resize.hpp
    title: Resize a multi-dimensional vector
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://anqooqie.github.io/proconlib/
  bundledCode: "#line 1 \"tools/util.hpp\"\n\n\n\n// To see the details of my library,\
    \ visit my GitHub Pages.\n// https://anqooqie.github.io/proconlib/\n\n#ifdef LOCAL\n\
    \  #ifndef _GLIBCXX_DEBUG\n    #define _GLIBCXX_DEBUG\n  #endif\n#else\n  #ifndef\
    \ NDEBUG\n    #define NDEBUG\n  #endif\n#endif\n\n#include <bits/stdc++.h>\n#line\
    \ 1 \"tools/resize.hpp\"\n\n\n\n#line 5 \"tools/resize.hpp\"\n\n// Source: https://koyumeishi.hatenablog.com/entry/2016/02/01/152426\n\
    // License: unknown\n// Author: koyumeishi\n\nnamespace tools {\n  template <class\
    \ T, class Allocator, typename Head>\n  void resize(::std::vector<T, Allocator>&\
    \ vector, const Head& head) {\n    vector.resize(head);\n  }\n  template <class\
    \ T, class Allocator, typename Head, typename... Tail>\n  void resize(::std::vector<T,\
    \ Allocator>& vector, const Head& head, const Tail&... tail) {\n    vector.resize(head);\n\
    \    for (auto& child : vector) {\n      ::tools::resize(child, tail...);\n  \
    \  }\n  }\n}\n\n\n#line 1 \"tools/fill.hpp\"\n\n\n\n#line 5 \"tools/fill.hpp\"\
    \n#include <type_traits>\n#line 1 \"tools/is_range.hpp\"\n\n\n\n#line 7 \"tools/is_range.hpp\"\
    \n\nnamespace tools {\n  template <typename T>\n  class is_range {\n  private:\n\
    \    template <typename U>\n    static auto check(U x) -> decltype(::std::begin(x),\
    \ ::std::end(x), ::std::true_type{});\n    static ::std::false_type check(...);\n\
    \n  public:\n    static const bool value = decltype(check(::std::declval<T>()))::value;\n\
    \  };\n}\n\n\n#line 9 \"tools/fill.hpp\"\n\nnamespace tools {\n  template <class\
    \ T, class Allocator, typename V>\n  auto fill(::std::vector<T, Allocator>& vector,\
    \ const V& value) -> ::std::enable_if_t<!::tools::is_range<T>::value, void> {\n\
    \    ::std::fill(::std::begin(vector), ::std::end(vector), value);\n  }\n  template\
    \ <class T, class Allocator, typename V>\n  auto fill(::std::vector<T, Allocator>&\
    \ vector, const V& value) -> ::std::enable_if_t<::tools::is_range<T>::value, void>\
    \ {\n    for (auto& child : vector) {\n      ::tools::fill(child, value);\n  \
    \  }\n  }\n}\n\n\n#line 20 \"tools/util.hpp\"\n\nusing i64 = ::std::int_fast64_t;\n\
    using u64 = ::std::uint_fast64_t;\nusing i32 = ::std::int_fast32_t;\nusing u32\
    \ = ::std::uint_fast32_t;\n\n#define ALL(x) ::std::begin((x)), ::std::end((x))\n\
    #define REP(i, n) for (::std::int_fast64_t i = 0; i < static_cast<::std::int_fast64_t>(n);\
    \ ++i)\n\nnamespace tools {\n  namespace detail {\n    namespace util {\n    \
    \  template <typename T>\n      class has_mod {\n      private:\n        template\
    \ <typename U>\n        static auto check(U x) -> decltype(x.mod(), ::std::true_type{});\n\
    \        static ::std::false_type check(...);\n\n      public:\n        static\
    \ const bool value = decltype(check(::std::declval<T>()))::value;\n      };\n\n\
    \      template <typename T>\n      ::std::istream& read(::std::istream& is, T&\
    \ container) {\n        for (auto& v : container) {\n          is >> v;\n    \
    \    }\n        return is;\n      }\n\n      template <typename T>\n      ::std::ostream&\
    \ debug_print(::std::ostream& os, const T& container) {\n        ::std::string\
    \ delimiter = \"\";\n        os << '[';\n        for (const auto& v : container)\
    \ {\n          os << delimiter << v;\n          delimiter = \", \";\n        }\n\
    \        os << ']';\n        return os;\n      }\n    }\n  }\n}\n\ntemplate <class\
    \ T, class Allocator>\n::std::istream& operator>>(::std::istream& is, ::std::vector<T,\
    \ Allocator>& vector) {\n  return ::tools::detail::util::read(is, vector);\n}\n\
    template <class T, ::std::size_t N>\n::std::istream& operator>>(::std::istream&\
    \ is, ::std::array<T, N>& array) {\n  return ::tools::detail::util::read(is, array);\n\
    }\ntemplate <class T, class Allocator>\n::std::ostream& operator<<(::std::ostream&\
    \ os, const ::std::vector<T, Allocator>& vector) {\n  return ::tools::detail::util::debug_print(os,\
    \ vector);\n}\ntemplate <class T, ::std::size_t N>\n::std::ostream& operator<<(::std::ostream&\
    \ os, const ::std::array<T, N>& array) {\n  return ::tools::detail::util::debug_print(os,\
    \ array);\n}\ntemplate <class Key, class Hash, class Pred, class Allocator>\n\
    ::std::ostream& operator<<(::std::ostream& os, const ::std::unordered_set<Key,\
    \ Hash, Pred, Allocator>& unordered_set) {\n  return ::tools::detail::util::debug_print(os,\
    \ unordered_set);\n}\n\ntemplate <class T, class Container>\n::std::ostream& operator<<(::std::ostream&\
    \ os, ::std::stack<T, Container>& stack) {\n  ::std::stack<T, Container> other;\n\
    \  while (!stack.empty()) {\n    other.push(stack.top());\n    stack.pop();\n\
    \  }\n\n  ::std::string delimiter = \"\";\n  os << '[';\n  while (!other.empty())\
    \ {\n    os << delimiter << other.top();\n    delimiter = \", \";\n    stack.push(other.top());\n\
    \    other.pop();\n  }\n  os << ']';\n\n  return os;\n}\n\ntemplate <class T,\
    \ class Container>\n::std::ostream& operator<<(::std::ostream& os, ::std::queue<T,\
    \ Container>& queue) {\n  ::std::queue<T, Container> other = queue;\n  ::std::string\
    \ delimiter = \"\";\n  os << '[';\n  while (!queue.empty()) {\n    os << delimiter\
    \ << queue.front();\n    delimiter = \", \";\n    queue.pop();\n  }\n  os << ']';\n\
    \n  queue = ::std::move(other);\n  return os;\n}\n\ntemplate <class T1, class\
    \ T2>\n::std::istream& operator>>(::std::istream& is, ::std::pair<T1, T2>& pair)\
    \ {\n  return is >> pair.first >> pair.second;\n}\ntemplate <class T1, class T2>\n\
    ::std::ostream& operator<<(::std::ostream& os, const ::std::pair<T1, T2>& pair)\
    \ {\n  return os << '[' << pair.first << \", \" << pair.second << ']';\n}\ntemplate\
    \ <int I = 0, typename... Args>\n::std::istream& operator>>(::std::istream& is,\
    \ const ::std::tuple<Args...>& tuple) {\n  if constexpr (I < int(sizeof...(Args)))\
    \ {\n    is >> ::std::get<I>(tuple);\n    return operator>><I + 1>(is, tuple);\n\
    \  } else {\n    return is;\n  }\n}\ntemplate <int I = -1, typename... Args>\n\
    ::std::ostream& operator<<(::std::ostream& os, const ::std::tuple<Args...>& tuple)\
    \ {\n  if constexpr (I == -1) {\n    os << '[';\n  } else if constexpr (I == int(sizeof...(Args)))\
    \ {\n    os << ']';\n  } else if constexpr (I == 0) {\n    os << ::std::get<I>(tuple);\n\
    \  } else {\n    os << \", \" << ::std::get<I>(tuple);\n  }\n\n  if constexpr\
    \ (I < int(sizeof...(Args))) {\n    return operator<<<I + 1>(os, tuple);\n  }\
    \ else {\n    return os;\n  }\n}\n\ntemplate <typename T>\nauto operator>>(::std::istream&\
    \ is, T& x) -> ::std::enable_if_t<::tools::detail::util::has_mod<T>::value, ::std::istream&>\
    \ {\n  ::std::int_fast64_t n;\n  is >> n;\n  x = T(n);\n  return is;\n}\ntemplate\
    \ <typename T>\nauto operator<<(::std::ostream& os, const T& x) -> ::std::enable_if_t<::tools::detail::util::has_mod<T>::value,\
    \ ::std::ostream&> {\n  return os << x.val();\n}\n\n\n"
  code: "#ifndef TOOLS_UTIL_HPP\n#define TOOLS_UTIL_HPP\n\n// To see the details of\
    \ my library, visit my GitHub Pages.\n// https://anqooqie.github.io/proconlib/\n\
    \n#ifdef LOCAL\n  #ifndef _GLIBCXX_DEBUG\n    #define _GLIBCXX_DEBUG\n  #endif\n\
    #else\n  #ifndef NDEBUG\n    #define NDEBUG\n  #endif\n#endif\n\n#include <bits/stdc++.h>\n\
    #include \"tools/resize.hpp\"\n#include \"tools/fill.hpp\"\n\nusing i64 = ::std::int_fast64_t;\n\
    using u64 = ::std::uint_fast64_t;\nusing i32 = ::std::int_fast32_t;\nusing u32\
    \ = ::std::uint_fast32_t;\n\n#define ALL(x) ::std::begin((x)), ::std::end((x))\n\
    #define REP(i, n) for (::std::int_fast64_t i = 0; i < static_cast<::std::int_fast64_t>(n);\
    \ ++i)\n\nnamespace tools {\n  namespace detail {\n    namespace util {\n    \
    \  template <typename T>\n      class has_mod {\n      private:\n        template\
    \ <typename U>\n        static auto check(U x) -> decltype(x.mod(), ::std::true_type{});\n\
    \        static ::std::false_type check(...);\n\n      public:\n        static\
    \ const bool value = decltype(check(::std::declval<T>()))::value;\n      };\n\n\
    \      template <typename T>\n      ::std::istream& read(::std::istream& is, T&\
    \ container) {\n        for (auto& v : container) {\n          is >> v;\n    \
    \    }\n        return is;\n      }\n\n      template <typename T>\n      ::std::ostream&\
    \ debug_print(::std::ostream& os, const T& container) {\n        ::std::string\
    \ delimiter = \"\";\n        os << '[';\n        for (const auto& v : container)\
    \ {\n          os << delimiter << v;\n          delimiter = \", \";\n        }\n\
    \        os << ']';\n        return os;\n      }\n    }\n  }\n}\n\ntemplate <class\
    \ T, class Allocator>\n::std::istream& operator>>(::std::istream& is, ::std::vector<T,\
    \ Allocator>& vector) {\n  return ::tools::detail::util::read(is, vector);\n}\n\
    template <class T, ::std::size_t N>\n::std::istream& operator>>(::std::istream&\
    \ is, ::std::array<T, N>& array) {\n  return ::tools::detail::util::read(is, array);\n\
    }\ntemplate <class T, class Allocator>\n::std::ostream& operator<<(::std::ostream&\
    \ os, const ::std::vector<T, Allocator>& vector) {\n  return ::tools::detail::util::debug_print(os,\
    \ vector);\n}\ntemplate <class T, ::std::size_t N>\n::std::ostream& operator<<(::std::ostream&\
    \ os, const ::std::array<T, N>& array) {\n  return ::tools::detail::util::debug_print(os,\
    \ array);\n}\ntemplate <class Key, class Hash, class Pred, class Allocator>\n\
    ::std::ostream& operator<<(::std::ostream& os, const ::std::unordered_set<Key,\
    \ Hash, Pred, Allocator>& unordered_set) {\n  return ::tools::detail::util::debug_print(os,\
    \ unordered_set);\n}\n\ntemplate <class T, class Container>\n::std::ostream& operator<<(::std::ostream&\
    \ os, ::std::stack<T, Container>& stack) {\n  ::std::stack<T, Container> other;\n\
    \  while (!stack.empty()) {\n    other.push(stack.top());\n    stack.pop();\n\
    \  }\n\n  ::std::string delimiter = \"\";\n  os << '[';\n  while (!other.empty())\
    \ {\n    os << delimiter << other.top();\n    delimiter = \", \";\n    stack.push(other.top());\n\
    \    other.pop();\n  }\n  os << ']';\n\n  return os;\n}\n\ntemplate <class T,\
    \ class Container>\n::std::ostream& operator<<(::std::ostream& os, ::std::queue<T,\
    \ Container>& queue) {\n  ::std::queue<T, Container> other = queue;\n  ::std::string\
    \ delimiter = \"\";\n  os << '[';\n  while (!queue.empty()) {\n    os << delimiter\
    \ << queue.front();\n    delimiter = \", \";\n    queue.pop();\n  }\n  os << ']';\n\
    \n  queue = ::std::move(other);\n  return os;\n}\n\ntemplate <class T1, class\
    \ T2>\n::std::istream& operator>>(::std::istream& is, ::std::pair<T1, T2>& pair)\
    \ {\n  return is >> pair.first >> pair.second;\n}\ntemplate <class T1, class T2>\n\
    ::std::ostream& operator<<(::std::ostream& os, const ::std::pair<T1, T2>& pair)\
    \ {\n  return os << '[' << pair.first << \", \" << pair.second << ']';\n}\ntemplate\
    \ <int I = 0, typename... Args>\n::std::istream& operator>>(::std::istream& is,\
    \ const ::std::tuple<Args...>& tuple) {\n  if constexpr (I < int(sizeof...(Args)))\
    \ {\n    is >> ::std::get<I>(tuple);\n    return operator>><I + 1>(is, tuple);\n\
    \  } else {\n    return is;\n  }\n}\ntemplate <int I = -1, typename... Args>\n\
    ::std::ostream& operator<<(::std::ostream& os, const ::std::tuple<Args...>& tuple)\
    \ {\n  if constexpr (I == -1) {\n    os << '[';\n  } else if constexpr (I == int(sizeof...(Args)))\
    \ {\n    os << ']';\n  } else if constexpr (I == 0) {\n    os << ::std::get<I>(tuple);\n\
    \  } else {\n    os << \", \" << ::std::get<I>(tuple);\n  }\n\n  if constexpr\
    \ (I < int(sizeof...(Args))) {\n    return operator<<<I + 1>(os, tuple);\n  }\
    \ else {\n    return os;\n  }\n}\n\ntemplate <typename T>\nauto operator>>(::std::istream&\
    \ is, T& x) -> ::std::enable_if_t<::tools::detail::util::has_mod<T>::value, ::std::istream&>\
    \ {\n  ::std::int_fast64_t n;\n  is >> n;\n  x = T(n);\n  return is;\n}\ntemplate\
    \ <typename T>\nauto operator<<(::std::ostream& os, const T& x) -> ::std::enable_if_t<::tools::detail::util::has_mod<T>::value,\
    \ ::std::ostream&> {\n  return os << x.val();\n}\n\n#endif\n"
  dependsOn:
  - tools/resize.hpp
  - tools/fill.hpp
  - tools/is_range.hpp
  isVerificationFile: false
  path: tools/util.hpp
  requiredBy: []
  timestamp: '2021-12-11 09:41:25+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tools/util.hpp
layout: document
title: Commonly used utilities for competitive programming
---

They are miscellaneous code snippets for competitive programming.

## Constraints
- They require GCC.

## Time Complexity
- Not applicable

## License
- CC0

## Author
- anqooqie
