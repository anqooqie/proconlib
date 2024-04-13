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
    path: tests/extend_output.test.cpp
    title: tests/extend_output.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/util.test.cpp
    title: tests/util.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/extend_output.hpp\"\n\n\n\n// WARNING:\n// This file\
    \ adds functions to std namespace for convenience.\n// Strictly speaking, it is\
    \ not allowed in C++.\n// It makes the program ill-formed to include this file,\
    \ and may cause undefined behavior.\n\n#include <array>\n#include <iostream>\n\
    #include <optional>\n#include <queue>\n#include <stack>\n#include <string>\n#include\
    \ <tuple>\n#include <type_traits>\n#include <unordered_map>\n#include <unordered_set>\n\
    #include <utility>\n#include <vector>\n#line 1 \"tools/has_mod.hpp\"\n\n\n\n#line\
    \ 6 \"tools/has_mod.hpp\"\n\nnamespace tools {\n  template <typename T, typename\
    \ = ::std::void_t<>>\n  struct has_mod : ::std::false_type {};\n\n  template <typename\
    \ T>\n  struct has_mod<T, ::std::void_t<decltype(::std::declval<T>().mod())>>\
    \ : ::std::true_type {};\n\n  template <typename T>\n  inline constexpr bool has_mod_v\
    \ = ::tools::has_mod<T>::value;\n}\n\n\n#line 22 \"tools/extend_output.hpp\"\n\
    \nnamespace tools {\n  namespace detail {\n    namespace extend_output {\n   \
    \   template <typename T>\n      ::std::ostream& debug_print(::std::ostream& os,\
    \ const T& container) {\n        ::std::string delimiter = \"\";\n        os <<\
    \ '[';\n        for (const auto& v : container) {\n          os << delimiter <<\
    \ v;\n          delimiter = \", \";\n        }\n        os << ']';\n        return\
    \ os;\n      }\n    }\n  }\n}\n\nnamespace std {\n  template <class T, ::std::size_t\
    \ N>\n  ::std::ostream& operator<<(::std::ostream& os, const ::std::array<T, N>&\
    \ array) {\n    return ::tools::detail::extend_output::debug_print(os, array);\n\
    \  }\n  \n  template <typename T>\n  ::std::ostream& operator<<(::std::ostream&\
    \ os, const ::std::optional<T>& optional) {\n    if (optional) {\n      return\
    \ os << *optional;\n    } else {\n      return os << \"null\";\n    }\n  }\n \
    \ \n  template <class T1, class T2>\n  ::std::ostream& operator<<(::std::ostream&\
    \ os, const ::std::pair<T1, T2>& pair) {\n    return os << '[' << pair.first <<\
    \ \", \" << pair.second << ']';\n  }\n  \n  template <class T, class Container>\n\
    \  ::std::ostream& operator<<(::std::ostream& os, ::std::queue<T, Container>&\
    \ queue) {\n    ::std::queue<T, Container> other = queue;\n    ::std::string delimiter\
    \ = \"\";\n    os << '[';\n    while (!queue.empty()) {\n      os << delimiter\
    \ << queue.front();\n      delimiter = \", \";\n      queue.pop();\n    }\n  \
    \  os << ']';\n  \n    queue = ::std::move(other);\n    return os;\n  }\n  \n\
    \  template <class T, class Container>\n  ::std::ostream& operator<<(::std::ostream&\
    \ os, ::std::stack<T, Container>& stack) {\n    ::std::stack<T, Container> other;\n\
    \    while (!stack.empty()) {\n      other.push(stack.top());\n      stack.pop();\n\
    \    }\n  \n    ::std::string delimiter = \"\";\n    os << '[';\n    while (!other.empty())\
    \ {\n      os << delimiter << other.top();\n      delimiter = \", \";\n      stack.push(other.top());\n\
    \      other.pop();\n    }\n    os << ']';\n  \n    return os;\n  }\n  \n  template\
    \ <int I = -1, typename... Args>\n  ::std::ostream& operator<<(::std::ostream&\
    \ os, const ::std::tuple<Args...>& tuple) {\n    if constexpr (I == -1) {\n  \
    \    os << '[';\n    } else if constexpr (I == int(sizeof...(Args))) {\n     \
    \ os << ']';\n    } else if constexpr (I == 0) {\n      os << ::std::get<I>(tuple);\n\
    \    } else {\n      os << \", \" << ::std::get<I>(tuple);\n    }\n  \n    if\
    \ constexpr (I < int(sizeof...(Args))) {\n      return operator<<<I + 1>(os, tuple);\n\
    \    } else {\n      return os;\n    }\n  }\n  \n  template <class Key, class\
    \ T, class Hash, class Pred, class Allocator>\n  ::std::ostream& operator<<(::std::ostream&\
    \ os, const ::std::unordered_map<Key, T, Hash, Pred, Allocator>& unordered_map)\
    \ {\n    return ::tools::detail::extend_output::debug_print(os, unordered_map);\n\
    \  }\n  \n  template <class Key, class Hash, class Pred, class Allocator>\n  ::std::ostream&\
    \ operator<<(::std::ostream& os, const ::std::unordered_set<Key, Hash, Pred, Allocator>&\
    \ unordered_set) {\n    return ::tools::detail::extend_output::debug_print(os,\
    \ unordered_set);\n  }\n  \n  template <class T, class Allocator>\n  ::std::ostream&\
    \ operator<<(::std::ostream& os, const ::std::vector<T, Allocator>& vector) {\n\
    \    return ::tools::detail::extend_output::debug_print(os, vector);\n  }\n  \n\
    \  template <typename T>\n  ::std::enable_if_t<::tools::has_mod_v<T>, ::std::ostream&>\
    \ operator<<(::std::ostream& os, const T& x) {\n    return os << x.val();\n  }\n\
    }\n\n\n"
  code: "#ifndef TOOLS_EXTEND_OUTPUT_HPP\n#define TOOLS_EXTEND_OUTPUT_HPP\n\n// WARNING:\n\
    // This file adds functions to std namespace for convenience.\n// Strictly speaking,\
    \ it is not allowed in C++.\n// It makes the program ill-formed to include this\
    \ file, and may cause undefined behavior.\n\n#include <array>\n#include <iostream>\n\
    #include <optional>\n#include <queue>\n#include <stack>\n#include <string>\n#include\
    \ <tuple>\n#include <type_traits>\n#include <unordered_map>\n#include <unordered_set>\n\
    #include <utility>\n#include <vector>\n#include \"tools/has_mod.hpp\"\n\nnamespace\
    \ tools {\n  namespace detail {\n    namespace extend_output {\n      template\
    \ <typename T>\n      ::std::ostream& debug_print(::std::ostream& os, const T&\
    \ container) {\n        ::std::string delimiter = \"\";\n        os << '[';\n\
    \        for (const auto& v : container) {\n          os << delimiter << v;\n\
    \          delimiter = \", \";\n        }\n        os << ']';\n        return\
    \ os;\n      }\n    }\n  }\n}\n\nnamespace std {\n  template <class T, ::std::size_t\
    \ N>\n  ::std::ostream& operator<<(::std::ostream& os, const ::std::array<T, N>&\
    \ array) {\n    return ::tools::detail::extend_output::debug_print(os, array);\n\
    \  }\n  \n  template <typename T>\n  ::std::ostream& operator<<(::std::ostream&\
    \ os, const ::std::optional<T>& optional) {\n    if (optional) {\n      return\
    \ os << *optional;\n    } else {\n      return os << \"null\";\n    }\n  }\n \
    \ \n  template <class T1, class T2>\n  ::std::ostream& operator<<(::std::ostream&\
    \ os, const ::std::pair<T1, T2>& pair) {\n    return os << '[' << pair.first <<\
    \ \", \" << pair.second << ']';\n  }\n  \n  template <class T, class Container>\n\
    \  ::std::ostream& operator<<(::std::ostream& os, ::std::queue<T, Container>&\
    \ queue) {\n    ::std::queue<T, Container> other = queue;\n    ::std::string delimiter\
    \ = \"\";\n    os << '[';\n    while (!queue.empty()) {\n      os << delimiter\
    \ << queue.front();\n      delimiter = \", \";\n      queue.pop();\n    }\n  \
    \  os << ']';\n  \n    queue = ::std::move(other);\n    return os;\n  }\n  \n\
    \  template <class T, class Container>\n  ::std::ostream& operator<<(::std::ostream&\
    \ os, ::std::stack<T, Container>& stack) {\n    ::std::stack<T, Container> other;\n\
    \    while (!stack.empty()) {\n      other.push(stack.top());\n      stack.pop();\n\
    \    }\n  \n    ::std::string delimiter = \"\";\n    os << '[';\n    while (!other.empty())\
    \ {\n      os << delimiter << other.top();\n      delimiter = \", \";\n      stack.push(other.top());\n\
    \      other.pop();\n    }\n    os << ']';\n  \n    return os;\n  }\n  \n  template\
    \ <int I = -1, typename... Args>\n  ::std::ostream& operator<<(::std::ostream&\
    \ os, const ::std::tuple<Args...>& tuple) {\n    if constexpr (I == -1) {\n  \
    \    os << '[';\n    } else if constexpr (I == int(sizeof...(Args))) {\n     \
    \ os << ']';\n    } else if constexpr (I == 0) {\n      os << ::std::get<I>(tuple);\n\
    \    } else {\n      os << \", \" << ::std::get<I>(tuple);\n    }\n  \n    if\
    \ constexpr (I < int(sizeof...(Args))) {\n      return operator<<<I + 1>(os, tuple);\n\
    \    } else {\n      return os;\n    }\n  }\n  \n  template <class Key, class\
    \ T, class Hash, class Pred, class Allocator>\n  ::std::ostream& operator<<(::std::ostream&\
    \ os, const ::std::unordered_map<Key, T, Hash, Pred, Allocator>& unordered_map)\
    \ {\n    return ::tools::detail::extend_output::debug_print(os, unordered_map);\n\
    \  }\n  \n  template <class Key, class Hash, class Pred, class Allocator>\n  ::std::ostream&\
    \ operator<<(::std::ostream& os, const ::std::unordered_set<Key, Hash, Pred, Allocator>&\
    \ unordered_set) {\n    return ::tools::detail::extend_output::debug_print(os,\
    \ unordered_set);\n  }\n  \n  template <class T, class Allocator>\n  ::std::ostream&\
    \ operator<<(::std::ostream& os, const ::std::vector<T, Allocator>& vector) {\n\
    \    return ::tools::detail::extend_output::debug_print(os, vector);\n  }\n  \n\
    \  template <typename T>\n  ::std::enable_if_t<::tools::has_mod_v<T>, ::std::ostream&>\
    \ operator<<(::std::ostream& os, const T& x) {\n    return os << x.val();\n  }\n\
    }\n\n#endif\n"
  dependsOn:
  - tools/has_mod.hpp
  isVerificationFile: false
  path: tools/extend_output.hpp
  requiredBy:
  - tools/util.hpp
  timestamp: '2022-11-23 11:35:29+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/util.test.cpp
  - tests/extend_output.test.cpp
documentation_of: tools/extend_output.hpp
layout: document
title: Extend operator<<
---

```cpp
namespace std {
  template <class T, ::std::size_t N>
  std::ostream& operator<<(std::ostream& os, const std::array<T, N>& array);
  
  template <typename T>
  std::ostream& operator<<(std::ostream& os, const std::optional<T>& optional);
  
  template <class T1, class T2>
  std::ostream& operator<<(std::ostream& os, const std::pair<T1, T2>& pair);
  
  template <class T, class Container>
  std::ostream& operator<<(std::ostream& os, std::queue<T, Container>& queue);
  
  template <class T, class Container>
  std::ostream& operator<<(std::ostream& os, std::stack<T, Container>& stack);
  
  template <typename... Args>
  std::ostream& operator<<(std::ostream& os, const std::tuple<Args...>& tuple);
  
  template <class Key, class T, class Hash, class Pred, class Allocator>
  std::ostream& operator<<(std::ostream& os, const std::unordered_map<Key, T, Hash, Pred, Allocator>& unordered_map);
  
  template <class Key, class Hash, class Pred, class Allocator>
  std::ostream& operator<<(std::ostream& os, const std::unordered_set<Key, Hash, Pred, Allocator>& unordered_set);
  
  template <class T, class Allocator>
  std::ostream& operator<<(std::ostream& os, const std::vector<T, Allocator>& vector);
  
  template <typename T>
  std::enable_if_t<tools::has_mod_v<T>, std::ostream&> operator<<(std::ostream& os, const T& x);
}
```

It adds some overloads of `operator<<`.
Hereby, it gets possible to print a container directly.

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
