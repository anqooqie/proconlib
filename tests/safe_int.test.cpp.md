---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/safe_int.hpp
    title: Integer type with $\infty$ and $-\infty$
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A
  bundledCode: "#line 1 \"tests/safe_int.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\"\
    \n\n#include <cstdlib>\n#include <iostream>\n#line 1 \"tools/safe_int.hpp\"\n\n\
    \n\n#include <type_traits>\n#include <cstddef>\n#include <limits>\n#include <stdexcept>\n\
    \nnamespace tools {\n  template <typename T, typename ::std::enable_if<::std::is_signed_v<T>,\
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
    \    }\n  };\n}\n\n\n#line 6 \"tests/safe_int.test.cpp\"\n\nvoid assert_that(const\
    \ bool cond) {\n  if (!cond) {\n    std::exit(EXIT_FAILURE);\n  }\n}\n\nint main()\
    \ {\n  const int POS_INF = std::numeric_limits<int>::max();\n  const int NEG_INF\
    \ = std::numeric_limits<int>::min();\n  const int INT_MAX = std::numeric_limits<int>::max();\n\
    \  const int INT_MIN = std::numeric_limits<int>::min();\n  using s = tools::safe_int<int>;\n\
    \n  assert_that(s(1) + s(2) == s(3));\n  assert_that(s(1) + 2 == s(3));\n  assert_that(1\
    \ + s(2) == s(3));\n\n  assert_that(s(INT_MAX - 2) + s(1) == s(INT_MAX - 1));\n\
    \  assert_that(s(INT_MAX - 2) + s(2) == s(POS_INF));\n  assert_that(s(INT_MAX\
    \ - 2) + s(3) == s(POS_INF));\n  assert_that(s(1) + s(INT_MAX - 2) == s(INT_MAX\
    \ - 1));\n  assert_that(s(2) + s(INT_MAX - 2) == s(POS_INF));\n  assert_that(s(3)\
    \ + s(INT_MAX - 2) == s(POS_INF));\n  assert_that(s(INT_MIN + 2) + s(-1) == s(INT_MIN\
    \ + 1));\n  assert_that(s(INT_MIN + 2) + s(-2) == s(NEG_INF));\n  assert_that(s(INT_MIN\
    \ + 2) + s(-3) == s(NEG_INF));\n  assert_that(s(-1) + s(INT_MIN + 2) == s(INT_MIN\
    \ + 1));\n  assert_that(s(-2) + s(INT_MIN + 2) == s(NEG_INF));\n  assert_that(s(-3)\
    \ + s(INT_MIN + 2) == s(NEG_INF));\n\n  assert_that(s(POS_INF) + s(-1) == s(POS_INF));\n\
    \  assert_that(s(-1) + s(POS_INF) == s(POS_INF));\n  assert_that(s(POS_INF) +\
    \ s(POS_INF) == s(POS_INF));\n  assert_that(s(NEG_INF) + s(1) == s(NEG_INF));\n\
    \  assert_that(s(1) + s(NEG_INF) == s(NEG_INF));\n  assert_that(s(NEG_INF) + s(NEG_INF)\
    \ == s(NEG_INF));\n\n  assert_that(s(1) - s(2) == s(-1));\n  assert_that(s(1)\
    \ - 2 == s(-1));\n  assert_that(1 - s(2) == s(-1));\n\n  assert_that(s(INT_MAX\
    \ - 2) - s(-1) == s(INT_MAX - 1));\n  assert_that(s(INT_MAX - 2) - s(-2) == s(POS_INF));\n\
    \  assert_that(s(INT_MAX - 2) - s(-3) == s(POS_INF));\n  assert_that(s(INT_MIN\
    \ + 2) - s(1) == s(INT_MIN + 1));\n  assert_that(s(INT_MIN + 2) - s(2) == s(NEG_INF));\n\
    \  assert_that(s(INT_MIN + 2) - s(3) == s(NEG_INF));\n\n  assert_that(s(POS_INF)\
    \ - s(1) == s(POS_INF));\n  assert_that(s(POS_INF) - s(NEG_INF) == s(POS_INF));\n\
    \  assert_that(s(NEG_INF) - s(-1) == s(NEG_INF));\n  assert_that(s(NEG_INF) -\
    \ s(POS_INF) == s(NEG_INF));\n\n  assert_that(s(1) * s(2) == s(2));\n  assert_that(s(1)\
    \ * 2 == s(2));\n  assert_that(1 * s(2) == s(2));\n\n  assert_that(s(NEG_INF)\
    \ * s(NEG_INF) == s(POS_INF));\n  assert_that(s(NEG_INF) * s(INT_MIN + 1) == s(POS_INF));\n\
    \  assert_that(s(NEG_INF) * s(0) == s(0));\n  assert_that(s(NEG_INF) * s(INT_MAX\
    \ - 1) == s(NEG_INF));\n  assert_that(s(NEG_INF) * s(POS_INF) == s(NEG_INF));\n\
    \  assert_that(s(INT_MIN + 1) * s(NEG_INF) == s(POS_INF));\n  assert_that(s(INT_MIN\
    \ + 1) * s(INT_MIN + 1) == s(POS_INF));\n  assert_that(s(INT_MIN + 1) * s(0) ==\
    \ s(0));\n  assert_that(s(INT_MIN + 1) * s(INT_MAX - 1) == s(NEG_INF));\n  assert_that(s(INT_MIN\
    \ + 1) * s(POS_INF) == s(NEG_INF));\n  assert_that(s(0) * s(NEG_INF) == s(0));\n\
    \  assert_that(s(0) * s(INT_MIN + 1) == s(0));\n  assert_that(s(0) * s(0) == s(0));\n\
    \  assert_that(s(0) * s(INT_MAX - 1) == s(0));\n  assert_that(s(0) * s(POS_INF)\
    \ == s(0));\n  assert_that(s(INT_MAX - 1) * s(NEG_INF) == s(NEG_INF));\n  assert_that(s(INT_MAX\
    \ - 1) * s(INT_MIN + 1) == s(NEG_INF));\n  assert_that(s(INT_MAX - 1) * s(0) ==\
    \ s(0));\n  assert_that(s(INT_MAX - 1) * s(INT_MAX - 1) == s(POS_INF));\n  assert_that(s(INT_MAX\
    \ - 1) * s(POS_INF) == s(POS_INF));\n  assert_that(s(POS_INF) * s(NEG_INF) ==\
    \ s(NEG_INF));\n  assert_that(s(POS_INF) * s(INT_MIN + 1) == s(NEG_INF));\n  assert_that(s(POS_INF)\
    \ * s(0) == s(0));\n  assert_that(s(POS_INF) * s(INT_MAX - 1) == s(POS_INF));\n\
    \  assert_that(s(POS_INF) * s(POS_INF) == s(POS_INF));\n\n  std::cout << \"Hello\
    \ World\" << '\\n';\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\"\n\n\
    #include <cstdlib>\n#include <iostream>\n#include \"tools/safe_int.hpp\"\n\nvoid\
    \ assert_that(const bool cond) {\n  if (!cond) {\n    std::exit(EXIT_FAILURE);\n\
    \  }\n}\n\nint main() {\n  const int POS_INF = std::numeric_limits<int>::max();\n\
    \  const int NEG_INF = std::numeric_limits<int>::min();\n  const int INT_MAX =\
    \ std::numeric_limits<int>::max();\n  const int INT_MIN = std::numeric_limits<int>::min();\n\
    \  using s = tools::safe_int<int>;\n\n  assert_that(s(1) + s(2) == s(3));\n  assert_that(s(1)\
    \ + 2 == s(3));\n  assert_that(1 + s(2) == s(3));\n\n  assert_that(s(INT_MAX -\
    \ 2) + s(1) == s(INT_MAX - 1));\n  assert_that(s(INT_MAX - 2) + s(2) == s(POS_INF));\n\
    \  assert_that(s(INT_MAX - 2) + s(3) == s(POS_INF));\n  assert_that(s(1) + s(INT_MAX\
    \ - 2) == s(INT_MAX - 1));\n  assert_that(s(2) + s(INT_MAX - 2) == s(POS_INF));\n\
    \  assert_that(s(3) + s(INT_MAX - 2) == s(POS_INF));\n  assert_that(s(INT_MIN\
    \ + 2) + s(-1) == s(INT_MIN + 1));\n  assert_that(s(INT_MIN + 2) + s(-2) == s(NEG_INF));\n\
    \  assert_that(s(INT_MIN + 2) + s(-3) == s(NEG_INF));\n  assert_that(s(-1) + s(INT_MIN\
    \ + 2) == s(INT_MIN + 1));\n  assert_that(s(-2) + s(INT_MIN + 2) == s(NEG_INF));\n\
    \  assert_that(s(-3) + s(INT_MIN + 2) == s(NEG_INF));\n\n  assert_that(s(POS_INF)\
    \ + s(-1) == s(POS_INF));\n  assert_that(s(-1) + s(POS_INF) == s(POS_INF));\n\
    \  assert_that(s(POS_INF) + s(POS_INF) == s(POS_INF));\n  assert_that(s(NEG_INF)\
    \ + s(1) == s(NEG_INF));\n  assert_that(s(1) + s(NEG_INF) == s(NEG_INF));\n  assert_that(s(NEG_INF)\
    \ + s(NEG_INF) == s(NEG_INF));\n\n  assert_that(s(1) - s(2) == s(-1));\n  assert_that(s(1)\
    \ - 2 == s(-1));\n  assert_that(1 - s(2) == s(-1));\n\n  assert_that(s(INT_MAX\
    \ - 2) - s(-1) == s(INT_MAX - 1));\n  assert_that(s(INT_MAX - 2) - s(-2) == s(POS_INF));\n\
    \  assert_that(s(INT_MAX - 2) - s(-3) == s(POS_INF));\n  assert_that(s(INT_MIN\
    \ + 2) - s(1) == s(INT_MIN + 1));\n  assert_that(s(INT_MIN + 2) - s(2) == s(NEG_INF));\n\
    \  assert_that(s(INT_MIN + 2) - s(3) == s(NEG_INF));\n\n  assert_that(s(POS_INF)\
    \ - s(1) == s(POS_INF));\n  assert_that(s(POS_INF) - s(NEG_INF) == s(POS_INF));\n\
    \  assert_that(s(NEG_INF) - s(-1) == s(NEG_INF));\n  assert_that(s(NEG_INF) -\
    \ s(POS_INF) == s(NEG_INF));\n\n  assert_that(s(1) * s(2) == s(2));\n  assert_that(s(1)\
    \ * 2 == s(2));\n  assert_that(1 * s(2) == s(2));\n\n  assert_that(s(NEG_INF)\
    \ * s(NEG_INF) == s(POS_INF));\n  assert_that(s(NEG_INF) * s(INT_MIN + 1) == s(POS_INF));\n\
    \  assert_that(s(NEG_INF) * s(0) == s(0));\n  assert_that(s(NEG_INF) * s(INT_MAX\
    \ - 1) == s(NEG_INF));\n  assert_that(s(NEG_INF) * s(POS_INF) == s(NEG_INF));\n\
    \  assert_that(s(INT_MIN + 1) * s(NEG_INF) == s(POS_INF));\n  assert_that(s(INT_MIN\
    \ + 1) * s(INT_MIN + 1) == s(POS_INF));\n  assert_that(s(INT_MIN + 1) * s(0) ==\
    \ s(0));\n  assert_that(s(INT_MIN + 1) * s(INT_MAX - 1) == s(NEG_INF));\n  assert_that(s(INT_MIN\
    \ + 1) * s(POS_INF) == s(NEG_INF));\n  assert_that(s(0) * s(NEG_INF) == s(0));\n\
    \  assert_that(s(0) * s(INT_MIN + 1) == s(0));\n  assert_that(s(0) * s(0) == s(0));\n\
    \  assert_that(s(0) * s(INT_MAX - 1) == s(0));\n  assert_that(s(0) * s(POS_INF)\
    \ == s(0));\n  assert_that(s(INT_MAX - 1) * s(NEG_INF) == s(NEG_INF));\n  assert_that(s(INT_MAX\
    \ - 1) * s(INT_MIN + 1) == s(NEG_INF));\n  assert_that(s(INT_MAX - 1) * s(0) ==\
    \ s(0));\n  assert_that(s(INT_MAX - 1) * s(INT_MAX - 1) == s(POS_INF));\n  assert_that(s(INT_MAX\
    \ - 1) * s(POS_INF) == s(POS_INF));\n  assert_that(s(POS_INF) * s(NEG_INF) ==\
    \ s(NEG_INF));\n  assert_that(s(POS_INF) * s(INT_MIN + 1) == s(NEG_INF));\n  assert_that(s(POS_INF)\
    \ * s(0) == s(0));\n  assert_that(s(POS_INF) * s(INT_MAX - 1) == s(POS_INF));\n\
    \  assert_that(s(POS_INF) * s(POS_INF) == s(POS_INF));\n\n  std::cout << \"Hello\
    \ World\" << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - tools/safe_int.hpp
  isVerificationFile: true
  path: tests/safe_int.test.cpp
  requiredBy: []
  timestamp: '2021-06-12 04:14:22+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/safe_int.test.cpp
layout: document
redirect_from:
- /verify/tests/safe_int.test.cpp
- /verify/tests/safe_int.test.cpp.html
title: tests/safe_int.test.cpp
---
