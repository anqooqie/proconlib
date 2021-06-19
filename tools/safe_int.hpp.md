---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: tools/bellman_ford.hpp
    title: Bellman-Ford algorithm
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/bellman_ford.test.cpp
    title: tests/bellman_ford.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/safe_int.test.cpp
    title: tests/safe_int.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/safe_int.hpp\"\n\n\n\n#include <type_traits>\n#include\
    \ <cstddef>\n#include <limits>\n#include <stdexcept>\n\nnamespace tools {\n  template\
    \ <typename T, typename ::std::enable_if<::std::is_signed_v<T>, ::std::nullptr_t>::type\
    \ = nullptr>\n  class safe_int {\n  private:\n    T m_value;\n\n  public:\n  \
    \  safe_int() = default;\n    safe_int(const safe_int&) = default;\n    safe_int(safe_int&&)\
    \ = default;\n    ~safe_int() = default;\n    safe_int& operator=(const safe_int&)\
    \ = default;\n    safe_int& operator=(safe_int&&) = default;\n\n    safe_int(const\
    \ T value) : m_value(value) {\n    }\n\n    T val() const {\n      return this->m_value;\n\
    \    }\n\n    friend bool operator==(const safe_int<T>& lhs, const safe_int<T>&\
    \ rhs) {\n      return lhs.val() == rhs.val();\n    }\n    friend bool operator!=(const\
    \ safe_int<T>& lhs, const safe_int<T>& rhs) {\n      return lhs.val() != rhs.val();\n\
    \    }\n\n    friend safe_int<T> operator+(const safe_int<T>& lhs, const safe_int<T>&\
    \ rhs) {\n      if (lhs.val() == ::std::numeric_limits<T>::min() && rhs.val()\
    \ == ::std::numeric_limits<T>::max()) throw std::runtime_error(\"Indefinite.\"\
    );\n      if (lhs.val() == ::std::numeric_limits<T>::max() && rhs.val() == ::std::numeric_limits<T>::min())\
    \ throw std::runtime_error(\"Indefinite.\");\n      if (lhs.val() == ::std::numeric_limits<T>::min()\
    \ || rhs.val() == ::std::numeric_limits<T>::min()) return safe_int<T>(::std::numeric_limits<T>::min());\n\
    \      if (lhs.val() == ::std::numeric_limits<T>::max() || rhs.val() == ::std::numeric_limits<T>::max())\
    \ return safe_int<T>(::std::numeric_limits<T>::max());\n      if (rhs.val() >\
    \ 0 && lhs.val() > ::std::numeric_limits<T>::max() - rhs.val()) return safe_int<T>(::std::numeric_limits<T>::max());\n\
    \      if (rhs.val() < 0 && lhs.val() < ::std::numeric_limits<T>::min() - rhs.val())\
    \ return safe_int<T>(::std::numeric_limits<T>::min());\n      return safe_int<T>(lhs.val()\
    \ + rhs.val());\n    }\n    template <typename U, typename ::std::enable_if<!::std::is_same<U,\
    \ safe_int<T>>::value, ::std::nullptr_t>::type = nullptr>\n    friend safe_int<T>\
    \ operator+(const U& lhs, const safe_int<T>& rhs) {\n      return safe_int<T>(lhs)\
    \ + rhs;\n    }\n    template <typename U, typename ::std::enable_if<!::std::is_same<U,\
    \ safe_int<T>>::value, ::std::nullptr_t>::type = nullptr>\n    friend safe_int<T>\
    \ operator+(const safe_int<T>& lhs, const U& rhs) {\n      return lhs + safe_int<T>(rhs);\n\
    \    }\n\n    friend safe_int<T> operator-(const safe_int<T>& lhs, const safe_int<T>&\
    \ rhs) {\n      if (lhs.val() == ::std::numeric_limits<T>::max() && rhs.val()\
    \ == ::std::numeric_limits<T>::max()) throw std::runtime_error(\"Indefinite.\"\
    );\n      if (lhs.val() == ::std::numeric_limits<T>::min() && rhs.val() == ::std::numeric_limits<T>::min())\
    \ throw std::runtime_error(\"Indefinite.\");\n      if (lhs.val() == ::std::numeric_limits<T>::max()\
    \ || rhs.val() == ::std::numeric_limits<T>::min()) return safe_int<T>(::std::numeric_limits<T>::max());\n\
    \      if (lhs.val() == ::std::numeric_limits<T>::min() || rhs.val() == ::std::numeric_limits<T>::max())\
    \ return safe_int<T>(::std::numeric_limits<T>::min());\n      if (rhs.val() <\
    \ 0 && lhs.val() > ::std::numeric_limits<T>::max() + rhs.val()) return safe_int<T>(::std::numeric_limits<T>::max());\n\
    \      if (rhs.val() > 0 && lhs.val() < ::std::numeric_limits<T>::min() + rhs.val())\
    \ return safe_int<T>(::std::numeric_limits<T>::min());\n      return safe_int<T>(lhs.val()\
    \ - rhs.val());\n    }\n    template <typename U, typename ::std::enable_if<!::std::is_same<U,\
    \ safe_int<T>>::value, ::std::nullptr_t>::type = nullptr>\n    friend safe_int<T>\
    \ operator-(const U& lhs, const safe_int<T>& rhs) {\n      return safe_int<T>(lhs)\
    \ - rhs;\n    }\n    template <typename U, typename ::std::enable_if<!::std::is_same<U,\
    \ safe_int<T>>::value, ::std::nullptr_t>::type = nullptr>\n    friend safe_int<T>\
    \ operator-(const safe_int<T>& lhs, const U& rhs) {\n      return lhs - safe_int<T>(rhs);\n\
    \    }\n\n    friend safe_int<T> operator*(const safe_int<T>& lhs, const safe_int<T>&\
    \ rhs) {\n      if (lhs.val() == 0 || rhs.val() == 0) return safe_int<T>(0);\n\
    \      if (lhs.val() == ::std::numeric_limits<T>::min() || lhs.val() == ::std::numeric_limits<T>::max()\
    \ || rhs.val() == ::std::numeric_limits<T>::min() || rhs.val() == ::std::numeric_limits<T>::max())\
    \ {\n        if ((lhs.val() > 0) == (rhs.val() > 0)) return safe_int<T>(::std::numeric_limits<T>::max());\n\
    \        else return safe_int<T>(::std::numeric_limits<T>::min());\n      }\n\
    \      if (lhs.val() > 0) {\n        if (rhs.val() > 0) {\n          if (lhs.val()\
    \ > ::std::numeric_limits<T>::max() / rhs.val()) {\n            return safe_int<T>(::std::numeric_limits<T>::max());\n\
    \          }\n        } else {\n          if (rhs.val() < ::std::numeric_limits<T>::min()\
    \ / lhs.val()) {\n            return safe_int<T>(::std::numeric_limits<T>::min());\n\
    \          }\n        }\n      } else {\n        if (rhs.val() > 0) {\n      \
    \    if (lhs.val() < ::std::numeric_limits<T>::min() / rhs.val()) {\n        \
    \    return safe_int<T>(::std::numeric_limits<T>::min());\n          }\n     \
    \   } else {\n          if (lhs.val() != 0 && rhs.val() < ::std::numeric_limits<T>::max()\
    \ / lhs.val()) {\n            return safe_int<T>(::std::numeric_limits<T>::max());\n\
    \          }\n        }\n      }\n      return safe_int<T>(lhs.val() * rhs.val());\n\
    \    }\n    template <typename U, typename ::std::enable_if<!::std::is_same<U,\
    \ safe_int<T>>::value, ::std::nullptr_t>::type = nullptr>\n    friend safe_int<T>\
    \ operator*(const U& lhs, const safe_int<T>& rhs) {\n      return safe_int<T>(lhs)\
    \ * rhs;\n    }\n    template <typename U, typename ::std::enable_if<!::std::is_same<U,\
    \ safe_int<T>>::value, ::std::nullptr_t>::type = nullptr>\n    friend safe_int<T>\
    \ operator*(const safe_int<T>& lhs, const U& rhs) {\n      return lhs * safe_int<T>(rhs);\n\
    \    }\n  };\n}\n\n\n"
  code: "#ifndef TOOLS_SAFE_INT_HPP\n#define TOOLS_SAFE_INT_HPP\n\n#include <type_traits>\n\
    #include <cstddef>\n#include <limits>\n#include <stdexcept>\n\nnamespace tools\
    \ {\n  template <typename T, typename ::std::enable_if<::std::is_signed_v<T>,\
    \ ::std::nullptr_t>::type = nullptr>\n  class safe_int {\n  private:\n    T m_value;\n\
    \n  public:\n    safe_int() = default;\n    safe_int(const safe_int&) = default;\n\
    \    safe_int(safe_int&&) = default;\n    ~safe_int() = default;\n    safe_int&\
    \ operator=(const safe_int&) = default;\n    safe_int& operator=(safe_int&&) =\
    \ default;\n\n    safe_int(const T value) : m_value(value) {\n    }\n\n    T val()\
    \ const {\n      return this->m_value;\n    }\n\n    friend bool operator==(const\
    \ safe_int<T>& lhs, const safe_int<T>& rhs) {\n      return lhs.val() == rhs.val();\n\
    \    }\n    friend bool operator!=(const safe_int<T>& lhs, const safe_int<T>&\
    \ rhs) {\n      return lhs.val() != rhs.val();\n    }\n\n    friend safe_int<T>\
    \ operator+(const safe_int<T>& lhs, const safe_int<T>& rhs) {\n      if (lhs.val()\
    \ == ::std::numeric_limits<T>::min() && rhs.val() == ::std::numeric_limits<T>::max())\
    \ throw std::runtime_error(\"Indefinite.\");\n      if (lhs.val() == ::std::numeric_limits<T>::max()\
    \ && rhs.val() == ::std::numeric_limits<T>::min()) throw std::runtime_error(\"\
    Indefinite.\");\n      if (lhs.val() == ::std::numeric_limits<T>::min() || rhs.val()\
    \ == ::std::numeric_limits<T>::min()) return safe_int<T>(::std::numeric_limits<T>::min());\n\
    \      if (lhs.val() == ::std::numeric_limits<T>::max() || rhs.val() == ::std::numeric_limits<T>::max())\
    \ return safe_int<T>(::std::numeric_limits<T>::max());\n      if (rhs.val() >\
    \ 0 && lhs.val() > ::std::numeric_limits<T>::max() - rhs.val()) return safe_int<T>(::std::numeric_limits<T>::max());\n\
    \      if (rhs.val() < 0 && lhs.val() < ::std::numeric_limits<T>::min() - rhs.val())\
    \ return safe_int<T>(::std::numeric_limits<T>::min());\n      return safe_int<T>(lhs.val()\
    \ + rhs.val());\n    }\n    template <typename U, typename ::std::enable_if<!::std::is_same<U,\
    \ safe_int<T>>::value, ::std::nullptr_t>::type = nullptr>\n    friend safe_int<T>\
    \ operator+(const U& lhs, const safe_int<T>& rhs) {\n      return safe_int<T>(lhs)\
    \ + rhs;\n    }\n    template <typename U, typename ::std::enable_if<!::std::is_same<U,\
    \ safe_int<T>>::value, ::std::nullptr_t>::type = nullptr>\n    friend safe_int<T>\
    \ operator+(const safe_int<T>& lhs, const U& rhs) {\n      return lhs + safe_int<T>(rhs);\n\
    \    }\n\n    friend safe_int<T> operator-(const safe_int<T>& lhs, const safe_int<T>&\
    \ rhs) {\n      if (lhs.val() == ::std::numeric_limits<T>::max() && rhs.val()\
    \ == ::std::numeric_limits<T>::max()) throw std::runtime_error(\"Indefinite.\"\
    );\n      if (lhs.val() == ::std::numeric_limits<T>::min() && rhs.val() == ::std::numeric_limits<T>::min())\
    \ throw std::runtime_error(\"Indefinite.\");\n      if (lhs.val() == ::std::numeric_limits<T>::max()\
    \ || rhs.val() == ::std::numeric_limits<T>::min()) return safe_int<T>(::std::numeric_limits<T>::max());\n\
    \      if (lhs.val() == ::std::numeric_limits<T>::min() || rhs.val() == ::std::numeric_limits<T>::max())\
    \ return safe_int<T>(::std::numeric_limits<T>::min());\n      if (rhs.val() <\
    \ 0 && lhs.val() > ::std::numeric_limits<T>::max() + rhs.val()) return safe_int<T>(::std::numeric_limits<T>::max());\n\
    \      if (rhs.val() > 0 && lhs.val() < ::std::numeric_limits<T>::min() + rhs.val())\
    \ return safe_int<T>(::std::numeric_limits<T>::min());\n      return safe_int<T>(lhs.val()\
    \ - rhs.val());\n    }\n    template <typename U, typename ::std::enable_if<!::std::is_same<U,\
    \ safe_int<T>>::value, ::std::nullptr_t>::type = nullptr>\n    friend safe_int<T>\
    \ operator-(const U& lhs, const safe_int<T>& rhs) {\n      return safe_int<T>(lhs)\
    \ - rhs;\n    }\n    template <typename U, typename ::std::enable_if<!::std::is_same<U,\
    \ safe_int<T>>::value, ::std::nullptr_t>::type = nullptr>\n    friend safe_int<T>\
    \ operator-(const safe_int<T>& lhs, const U& rhs) {\n      return lhs - safe_int<T>(rhs);\n\
    \    }\n\n    friend safe_int<T> operator*(const safe_int<T>& lhs, const safe_int<T>&\
    \ rhs) {\n      if (lhs.val() == 0 || rhs.val() == 0) return safe_int<T>(0);\n\
    \      if (lhs.val() == ::std::numeric_limits<T>::min() || lhs.val() == ::std::numeric_limits<T>::max()\
    \ || rhs.val() == ::std::numeric_limits<T>::min() || rhs.val() == ::std::numeric_limits<T>::max())\
    \ {\n        if ((lhs.val() > 0) == (rhs.val() > 0)) return safe_int<T>(::std::numeric_limits<T>::max());\n\
    \        else return safe_int<T>(::std::numeric_limits<T>::min());\n      }\n\
    \      if (lhs.val() > 0) {\n        if (rhs.val() > 0) {\n          if (lhs.val()\
    \ > ::std::numeric_limits<T>::max() / rhs.val()) {\n            return safe_int<T>(::std::numeric_limits<T>::max());\n\
    \          }\n        } else {\n          if (rhs.val() < ::std::numeric_limits<T>::min()\
    \ / lhs.val()) {\n            return safe_int<T>(::std::numeric_limits<T>::min());\n\
    \          }\n        }\n      } else {\n        if (rhs.val() > 0) {\n      \
    \    if (lhs.val() < ::std::numeric_limits<T>::min() / rhs.val()) {\n        \
    \    return safe_int<T>(::std::numeric_limits<T>::min());\n          }\n     \
    \   } else {\n          if (lhs.val() != 0 && rhs.val() < ::std::numeric_limits<T>::max()\
    \ / lhs.val()) {\n            return safe_int<T>(::std::numeric_limits<T>::max());\n\
    \          }\n        }\n      }\n      return safe_int<T>(lhs.val() * rhs.val());\n\
    \    }\n    template <typename U, typename ::std::enable_if<!::std::is_same<U,\
    \ safe_int<T>>::value, ::std::nullptr_t>::type = nullptr>\n    friend safe_int<T>\
    \ operator*(const U& lhs, const safe_int<T>& rhs) {\n      return safe_int<T>(lhs)\
    \ * rhs;\n    }\n    template <typename U, typename ::std::enable_if<!::std::is_same<U,\
    \ safe_int<T>>::value, ::std::nullptr_t>::type = nullptr>\n    friend safe_int<T>\
    \ operator*(const safe_int<T>& lhs, const U& rhs) {\n      return lhs * safe_int<T>(rhs);\n\
    \    }\n  };\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/safe_int.hpp
  requiredBy:
  - tools/bellman_ford.hpp
  timestamp: '2021-06-12 04:14:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/bellman_ford.test.cpp
  - tests/safe_int.test.cpp
documentation_of: tools/safe_int.hpp
layout: document
title: Integer type with $\infty$ and $-\infty$
---

It is the integer type which has two special behaviors.

1. It regards `std::numeric_limits<T>::max()` as $\infty$ and `std::numeric_limits<T>::min()` as $-\infty$.
1. It returns $\infty$ or $-\infty$ when it detects overflow.

## Usage
```cpp
// ∞ - 1 = ∞
assert((tools::safe_int<int>(std::numeric_limits<int>::max()) - tools::safe_int<int>(1)).val() == std::numeric_limits<int>::max());

// It returns ∞ since 1000000000 + 2000000000 causes overflow.
assert((tools::safe_int<int>(1000000000) + tools::safe_int<int>(2000000000)).val() == std::numeric_limits<int>::max());
```

## License
- CC0

## Author
- anqooqie
