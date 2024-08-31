---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: tools/assert_that.hpp
    title: Assertion macro
  - icon: ':question:'
    path: tools/safe_int.hpp
    title: $\mathbb{Z} \cup \{\infty, -\infty, \mathrm{NaN}\}$ and $\mathbb{Z}_{\geq
      0} \cup \{\infty, \mathrm{NaN}\}$
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A
  bundledCode: "#line 1 \"tests/safe_int.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\"\
    \n\n#include <cstdlib>\n#include <iostream>\n#line 1 \"tools/assert_that.hpp\"\
    \n\n\n\n#line 6 \"tools/assert_that.hpp\"\n\n#define assert_that_impl(cond, file,\
    \ line, func) do {\\\n  if (!cond) {\\\n    ::std::cerr << file << ':' << line\
    \ << \": \" << func << \": Assertion `\" << #cond << \"' failed.\" << '\\n';\\\
    \n    ::std::exit(EXIT_FAILURE);\\\n  }\\\n} while (false)\n#define assert_that(...)\
    \ assert_that_impl((__VA_ARGS__), __FILE__, __LINE__, __func__)\n\n\n#line 1 \"\
    tools/safe_int.hpp\"\n\n\n\n#include <type_traits>\n#include <cstddef>\n#include\
    \ <cassert>\n#include <limits>\n#include <array>\n#include <optional>\n#line 11\
    \ \"tools/safe_int.hpp\"\n\nnamespace tools {\n  template <typename T, typename\
    \ = void>\n  class safe_int;\n\n  template <typename T>\n  class safe_int<T, ::std::enable_if_t<::std::is_signed_v<T>>>\
    \ {\n  private:\n    enum class type {\n      finite,\n      pos_inf,\n      neg_inf,\n\
    \      nan\n    };\n    typename ::tools::safe_int<T>::type m_type;\n    T m_value;\n\
    \n    constexpr safe_int(const typename ::tools::safe_int<T>::type type) :\n \
    \     m_type(type), m_value(T()) {\n    }\n\n  public:\n    constexpr safe_int()\
    \ :\n      m_type(::tools::safe_int<T>::type::finite), m_value(T()) {\n    }\n\
    \    explicit constexpr safe_int(const T value) :\n      m_type(::tools::safe_int<T>::type::finite),\
    \ m_value(value) {\n    }\n    constexpr safe_int(const ::tools::safe_int<T>&\
    \ other) :\n      m_type(other.m_type), m_value(other.m_value) {\n    }\n    ~safe_int()\
    \ = default;\n    constexpr ::tools::safe_int<T>& operator=(const ::tools::safe_int<T>&\
    \ other) {\n      this->m_type = other.m_type;\n      this->m_value = other.m_value;\n\
    \      return *this;\n    }\n\n    static constexpr ::tools::safe_int<T> infinity()\
    \ {\n      return tools::safe_int<T>(::tools::safe_int<T>::type::pos_inf);\n \
    \   }\n    static constexpr ::tools::safe_int<T> nan() {\n      return tools::safe_int<T>(::tools::safe_int<T>::type::nan);\n\
    \    }\n\n  private:\n    static constexpr int f1(const ::tools::safe_int<T>&\
    \ n) {\n      switch (n.m_type) {\n      case ::tools::safe_int<T>::type::neg_inf:\n\
    \        return 0;\n      case ::tools::safe_int<T>::type::finite:\n        return\
    \ 1;\n      case ::tools::safe_int<T>::type::pos_inf:\n        return 2;\n   \
    \   default: // nan\n        return 3;\n      }\n    };\n    static constexpr\
    \ int f2(const ::tools::safe_int<T>& n) {\n      switch (n.m_type) {\n      case\
    \ ::tools::safe_int<T>::type::neg_inf:\n        return 0;\n      case ::tools::safe_int<T>::type::finite:\n\
    \        if (n.m_value < 0) {\n          return 1;\n        } else if (n.m_value\
    \ == 0) {\n          return 2;\n        } else {\n          return 3;\n      \
    \  }\n      case ::tools::safe_int<T>::type::pos_inf:\n        return 4;\n   \
    \   default: // nan\n        return 5;\n      }\n    };\n    static constexpr\
    \ ::std::optional<::tools::safe_int<T>> Q() {\n      return ::std::nullopt;\n\
    \    }\n    static constexpr ::std::optional<::tools::safe_int<T>> Z() {\n   \
    \   return ::std::optional<::tools::safe_int<T>>(::tools::safe_int<T>(0));\n \
    \   }\n    static constexpr ::std::optional<::tools::safe_int<T>> N() {\n    \
    \  return ::std::optional<::tools::safe_int<T>>(::tools::safe_int<T>(::tools::safe_int<T>::type::neg_inf));\n\
    \    }\n    static constexpr ::std::optional<::tools::safe_int<T>> P() {\n   \
    \   return ::std::optional<::tools::safe_int<T>>(::tools::safe_int<T>(::tools::safe_int<T>::type::pos_inf));\n\
    \    }\n    static constexpr ::std::optional<::tools::safe_int<T>> U() {\n   \
    \   return ::std::optional<::tools::safe_int<T>>(::tools::safe_int<T>(::tools::safe_int<T>::type::nan));\n\
    \    }\n    static constexpr ::std::optional<bool> BQ() {\n      return ::std::nullopt;\n\
    \    }\n    static constexpr ::std::optional<bool> BF() {\n      return ::std::optional<bool>(false);\n\
    \    }\n    static constexpr ::std::optional<bool> BT() {\n      return ::std::optional<bool>(true);\n\
    \    }\n\n  public:\n    constexpr bool is_finite() const {\n      return this->m_type\
    \ == ::tools::safe_int<T>::type::finite;\n    }\n\n    constexpr bool is_nan()\
    \ const {\n      return this->m_type == ::tools::safe_int<T>::type::nan;\n   \
    \ }\n\n    constexpr T val() const {\n      assert(this->is_finite());\n     \
    \ return this->m_value;\n    }\n\n    friend constexpr bool operator==(const ::tools::safe_int<T>&\
    \ x, const ::tools::safe_int<T>& y) {\n      constexpr auto table = ::std::array<::std::array<::std::optional<bool>,\
    \ 4>, 4>({{\n        {BT(), BF(), BF(), BF()},\n        {BF(), BQ(), BF(), BF()},\n\
    \        {BF(), BF(), BT(), BF()},\n        {BF(), BF(), BF(), BF()}\n      }});\n\
    \      if (const auto r = table[f1(x)][f1(y)]; r) return *r;\n\n      return x.m_value\
    \ == y.m_value;\n    }\n    friend constexpr bool operator!=(const ::tools::safe_int<T>&\
    \ x, const ::tools::safe_int<T>& y) {\n      return !(x == y);\n    }\n\n    constexpr\
    \ ::tools::safe_int<T> operator+() const {\n      return *this;\n    }\n    constexpr\
    \ ::tools::safe_int<T> operator-() const {\n      constexpr auto table = ::std::array<::std::optional<::tools::safe_int<T>>,\
    \ 4>({\n        {P(), Q(), N(), U()}\n      });\n      if (const auto r = table[f1(*this)];\
    \ r) return *r;\n\n      if (this->m_value == ::std::numeric_limits<T>::min())\
    \ return *U();\n      return ::tools::safe_int<T>(-this->m_value);\n    }\n\n\
    \    friend constexpr ::tools::safe_int<T> operator+(const ::tools::safe_int<T>&\
    \ x, const ::tools::safe_int<T>& y) {\n      constexpr auto table = ::std::array<::std::array<::std::optional<::tools::safe_int<T>>,\
    \ 4>, 4>({{\n        {N(), N(), U(), U()},\n        {N(), Q(), P(), U()},\n  \
    \      {U(), P(), P(), U()},\n        {U(), U(), U(), U()}\n      }});\n     \
    \ if (const auto r = table[f1(x)][f1(y)]; r) return *r;\n\n      if (y.m_value\
    \ > 0 && x.m_value > ::std::numeric_limits<T>::max() - y.m_value) return *U();\n\
    \      if (y.m_value < 0 && x.m_value < ::std::numeric_limits<T>::min() - y.m_value)\
    \ return *U();\n      return ::tools::safe_int<T>(x.m_value + y.m_value);\n  \
    \  }\n    friend constexpr ::tools::safe_int<T> operator+(const ::tools::safe_int<T>&\
    \ x, const T& y) {\n      return x + tools::safe_int<T>(y);\n    }\n    friend\
    \ constexpr ::tools::safe_int<T> operator+(const T& x, const ::tools::safe_int<T>&\
    \ y) {\n      return tools::safe_int<T>(x) + y;\n    }\n\n    friend constexpr\
    \ ::tools::safe_int<T> operator-(const ::tools::safe_int<T>& x, const ::tools::safe_int<T>&\
    \ y) {\n      constexpr auto table = ::std::array<::std::array<::std::optional<::tools::safe_int<T>>,\
    \ 4>, 4>({{\n        {U(), N(), N(), U()},\n        {P(), Q(), N(), U()},\n  \
    \      {P(), P(), U(), U()},\n        {U(), U(), U(), U()}\n      }});\n     \
    \ if (const auto r = table[f1(x)][f1(y)]; r) return *r;\n\n      if (y.m_value\
    \ < 0 && x.m_value > ::std::numeric_limits<T>::max() + y.m_value) return *U();\n\
    \      if (y.m_value > 0 && x.m_value < ::std::numeric_limits<T>::min() + y.m_value)\
    \ return *U();\n      return ::tools::safe_int<T>(x.m_value - y.m_value);\n  \
    \  }\n    friend constexpr ::tools::safe_int<T> operator-(const ::tools::safe_int<T>&\
    \ x, const T& y) {\n      return x - tools::safe_int<T>(y);\n    }\n    friend\
    \ constexpr ::tools::safe_int<T> operator-(const T& x, const ::tools::safe_int<T>&\
    \ y) {\n      return tools::safe_int<T>(x) - y;\n    }\n\n    friend constexpr\
    \ ::tools::safe_int<T> operator*(const ::tools::safe_int<T>& x, const ::tools::safe_int<T>&\
    \ y) {\n      constexpr auto table = ::std::array<::std::array<::std::optional<::tools::safe_int<T>>,\
    \ 6>, 6>({{\n        {P(), P(), U(), N(), N(), U()},\n        {P(), Q(), Z(),\
    \ Q(), N(), U()},\n        {U(), Z(), Z(), Z(), U(), U()},\n        {N(), Q(),\
    \ Z(), Q(), P(), U()},\n        {N(), N(), U(), P(), P(), U()},\n        {U(),\
    \ U(), U(), U(), U(), U()}\n      }});\n      if (const auto r = table[f2(x)][f2(y)];\
    \ r) return *r;\n\n      if (x.m_value > 0) {\n        if (y.m_value > 0) {\n\
    \          if (x.m_value > ::std::numeric_limits<T>::max() / y.m_value) {\n  \
    \          return *U();\n          }\n        } else {\n          if (y.m_value\
    \ < ::std::numeric_limits<T>::min() / x.m_value) {\n            return *U();\n\
    \          }\n        }\n      } else {\n        if (y.m_value > 0) {\n      \
    \    if (x.m_value < ::std::numeric_limits<T>::min() / y.m_value) {\n        \
    \    return *U();\n          }\n        } else {\n          if (x.m_value != 0\
    \ && y.m_value < ::std::numeric_limits<T>::max() / x.m_value) {\n            return\
    \ *U();\n          }\n        }\n      }\n      return ::tools::safe_int<T>(x.m_value\
    \ * y.m_value);\n    }\n    friend constexpr ::tools::safe_int<T> operator*(const\
    \ ::tools::safe_int<T>& x, const T& y) {\n      return x * tools::safe_int<T>(y);\n\
    \    }\n    friend constexpr ::tools::safe_int<T> operator*(const T& x, const\
    \ ::tools::safe_int<T>& y) {\n      return tools::safe_int<T>(x) * y;\n    }\n\
    \n    friend constexpr ::tools::safe_int<T> operator/(const ::tools::safe_int<T>&\
    \ x, const ::tools::safe_int<T>& y) {\n      constexpr auto table = ::std::array<::std::array<::std::optional<::tools::safe_int<T>>,\
    \ 6>, 6>({{\n        {U(), P(), U(), N(), U(), U()},\n        {Z(), Q(), U(),\
    \ Q(), Z(), U()},\n        {Z(), Z(), U(), Z(), Z(), U()},\n        {Z(), Q(),\
    \ U(), Q(), Z(), U()},\n        {U(), N(), U(), P(), U(), U()},\n        {U(),\
    \ U(), U(), U(), U(), U()}\n      }});\n      if (const auto r = table[f2(x)][f2(y)];\
    \ r) return *r;\n\n      if (x.m_value == ::std::numeric_limits<T>::min() && y.m_value\
    \ == -1) return *U();\n      return ::tools::safe_int<T>(x.m_value / y.m_value);\n\
    \    }\n    friend constexpr ::tools::safe_int<T> operator/(const ::tools::safe_int<T>&\
    \ x, const T& y) {\n      return x / tools::safe_int<T>(y);\n    }\n    friend\
    \ constexpr ::tools::safe_int<T> operator/(const T& x, const ::tools::safe_int<T>&\
    \ y) {\n      return tools::safe_int<T>(x) / y;\n    }\n\n    friend constexpr\
    \ ::tools::safe_int<T> operator%(const ::tools::safe_int<T>& x, const ::tools::safe_int<T>&\
    \ y) {\n      constexpr auto table = ::std::array<::std::array<::std::optional<::tools::safe_int<T>>,\
    \ 6>, 6>({{\n        {U(), U(), U(), U(), U(), U()},\n        {U(), Q(), U(),\
    \ Q(), U(), U()},\n        {U(), Z(), U(), Z(), U(), U()},\n        {U(), Q(),\
    \ U(), Q(), U(), U()},\n        {U(), U(), U(), U(), U(), U()},\n        {U(),\
    \ U(), U(), U(), U(), U()}\n      }});\n      if (const auto r = table[f2(x)][f2(y)];\
    \ r) return *r;\n\n      if (x.m_value == ::std::numeric_limits<T>::min() && y.m_value\
    \ == -1) return *U();\n      return ::tools::safe_int<T>(x.m_value % y.m_value);\n\
    \    }\n    friend constexpr ::tools::safe_int<T> operator%(const ::tools::safe_int<T>&\
    \ x, const T& y) {\n      return x % tools::safe_int<T>(y);\n    }\n    friend\
    \ constexpr ::tools::safe_int<T> operator%(const T& x, const ::tools::safe_int<T>&\
    \ y) {\n      return tools::safe_int<T>(x) % y;\n    }\n\n    constexpr ::tools::safe_int<T>&\
    \ operator+=(const ::tools::safe_int<T>& other) {\n      return *this = *this\
    \ + other;\n    }\n    constexpr ::tools::safe_int<T>& operator+=(const T& other)\
    \ {\n      return *this = *this + ::tools::safe_int<T>(other);\n    }\n    constexpr\
    \ ::tools::safe_int<T>& operator-=(const ::tools::safe_int<T>& other) {\n    \
    \  return *this = *this - other;\n    }\n    constexpr ::tools::safe_int<T>& operator-=(const\
    \ T& other) {\n      return *this = *this - ::tools::safe_int<T>(other);\n   \
    \ }\n    constexpr ::tools::safe_int<T>& operator*=(const ::tools::safe_int<T>&\
    \ other) {\n      return *this = *this * other;\n    }\n    constexpr ::tools::safe_int<T>&\
    \ operator*=(const T& other) {\n      return *this = *this * ::tools::safe_int<T>(other);\n\
    \    }\n    constexpr ::tools::safe_int<T>& operator/=(const ::tools::safe_int<T>&\
    \ other) {\n      return *this = *this / other;\n    }\n    constexpr ::tools::safe_int<T>&\
    \ operator/=(const T& other) {\n      return *this = *this / ::tools::safe_int<T>(other);\n\
    \    }\n    constexpr ::tools::safe_int<T>& operator%=(const ::tools::safe_int<T>&\
    \ other) {\n      return *this = *this % other;\n    }\n    constexpr ::tools::safe_int<T>&\
    \ operator%=(const T& other) {\n      return *this = *this % ::tools::safe_int<T>(other);\n\
    \    }\n\n    constexpr ::tools::safe_int<T>& operator++() {\n      return *this\
    \ += ::tools::safe_int<T>(T(1));\n    }\n    constexpr ::tools::safe_int<T> operator++(int)\
    \ {\n      const auto r = *this;\n      ++(*this);\n      return r;\n    }\n \
    \   constexpr ::tools::safe_int<T>& operator--() {\n      return *this -= ::tools::safe_int<T>(T(1));\n\
    \    }\n    constexpr ::tools::safe_int<T> operator--(int) {\n      const auto\
    \ r = *this;\n      --(*this);\n      return r;\n    }\n\n    friend constexpr\
    \ bool operator<(const ::tools::safe_int<T>& x, const ::tools::safe_int<T>& y)\
    \ {\n      constexpr auto table = ::std::array<::std::array<::std::optional<bool>,\
    \ 4>, 4>({{\n        {BF(), BT(), BT(), BF()},\n        {BF(), BQ(), BT(), BF()},\n\
    \        {BF(), BF(), BF(), BF()},\n        {BF(), BF(), BF(), BF()}\n      }});\n\
    \      if (const auto r = table[f1(x)][f1(y)]; r) return *r;\n\n      return x.m_value\
    \ < y.m_value;\n    }\n    friend constexpr bool operator>(const ::tools::safe_int<T>&\
    \ x, const ::tools::safe_int<T>& y) {\n      constexpr auto table = ::std::array<::std::array<::std::optional<bool>,\
    \ 4>, 4>({{\n        {BF(), BF(), BF(), BF()},\n        {BT(), BQ(), BF(), BF()},\n\
    \        {BT(), BT(), BF(), BF()},\n        {BF(), BF(), BF(), BF()}\n      }});\n\
    \      if (const auto r = table[f1(x)][f1(y)]; r) return *r;\n\n      return x.m_value\
    \ > y.m_value;\n    }\n    friend constexpr bool operator<=(const ::tools::safe_int<T>&\
    \ x, const ::tools::safe_int<T>& y) {\n      return x < y || x == y;\n    }\n\
    \    friend constexpr bool operator>=(const ::tools::safe_int<T>& x, const ::tools::safe_int<T>&\
    \ y) {\n      return x > y || x == y;\n    }\n\n    friend ::std::istream& operator>>(::std::istream&\
    \ is, ::tools::safe_int<T>& self) {\n      self.m_type = ::tools::safe_int<T>::type::finite;\n\
    \      return is >> self.m_value;\n    }\n    friend ::std::ostream& operator<<(::std::ostream&\
    \ os, const ::tools::safe_int<T>& self) {\n      switch (self.m_type) {\n    \
    \  case ::tools::safe_int<T>::type::neg_inf:\n        return os << \"-inf\";\n\
    \      case ::tools::safe_int<T>::type::finite:\n        return os << self.m_value;\n\
    \      case ::tools::safe_int<T>::type::pos_inf:\n        return os << \"inf\"\
    ;\n      default: // nan\n        return os << \"nan\";\n      }\n    }\n  };\n\
    \n  template <typename T>\n  class safe_int<T, ::std::enable_if_t<::std::is_unsigned_v<T>>>\
    \ {\n  private:\n    enum class type {\n      finite,\n      pos_inf,\n      nan\n\
    \    };\n    typename ::tools::safe_int<T>::type m_type;\n    T m_value;\n\n \
    \   constexpr safe_int(const typename ::tools::safe_int<T>::type type) :\n   \
    \   m_type(type), m_value(T()) {\n    }\n\n  public:\n    constexpr safe_int()\
    \ :\n      m_type(::tools::safe_int<T>::type::finite), m_value(T()) {\n    }\n\
    \    explicit constexpr safe_int(const T value) :\n      m_type(::tools::safe_int<T>::type::finite),\
    \ m_value(value) {\n    }\n    constexpr safe_int(const ::tools::safe_int<T>&\
    \ other) :\n      m_type(other.m_type), m_value(other.m_value) {\n    }\n    ~safe_int()\
    \ = default;\n    constexpr ::tools::safe_int<T>& operator=(const ::tools::safe_int<T>&\
    \ other) {\n      this->m_type = other.m_type;\n      this->m_value = other.m_value;\n\
    \      return *this;\n    }\n\n    static constexpr ::tools::safe_int<T> infinity()\
    \ {\n      return tools::safe_int<T>(::tools::safe_int<T>::type::pos_inf);\n \
    \   }\n    static constexpr ::tools::safe_int<T> nan() {\n      return tools::safe_int<T>(::tools::safe_int<T>::type::nan);\n\
    \    }\n\n  private:\n    static constexpr int f1(const ::tools::safe_int<T>&\
    \ n) {\n      switch (n.m_type) {\n      case ::tools::safe_int<T>::type::finite:\n\
    \        return 0;\n      case ::tools::safe_int<T>::type::pos_inf:\n        return\
    \ 1;\n      default: // nan\n        return 2;\n      }\n    };\n    static constexpr\
    \ int f2(const ::tools::safe_int<T>& n) {\n      switch (n.m_type) {\n      case\
    \ ::tools::safe_int<T>::type::finite:\n        if (n.m_value == 0) {\n       \
    \   return 0;\n        } else {\n          return 1;\n        }\n      case ::tools::safe_int<T>::type::pos_inf:\n\
    \        return 2;\n      default: // nan\n        return 3;\n      }\n    };\n\
    \    static constexpr ::std::optional<::tools::safe_int<T>> Q() {\n      return\
    \ ::std::nullopt;\n    }\n    static constexpr ::std::optional<::tools::safe_int<T>>\
    \ Z() {\n      return ::std::optional<::tools::safe_int<T>>(::tools::safe_int<T>(0));\n\
    \    }\n    static constexpr ::std::optional<::tools::safe_int<T>> P() {\n   \
    \   return ::std::optional<::tools::safe_int<T>>(::tools::safe_int<T>(::tools::safe_int<T>::type::pos_inf));\n\
    \    }\n    static constexpr ::std::optional<::tools::safe_int<T>> U() {\n   \
    \   return ::std::optional<::tools::safe_int<T>>(::tools::safe_int<T>(::tools::safe_int<T>::type::nan));\n\
    \    }\n    static constexpr ::std::optional<bool> BQ() {\n      return ::std::nullopt;\n\
    \    }\n    static constexpr ::std::optional<bool> BF() {\n      return ::std::optional<bool>(false);\n\
    \    }\n    static constexpr ::std::optional<bool> BT() {\n      return ::std::optional<bool>(true);\n\
    \    }\n\n  public:\n    constexpr bool is_finite() const {\n      return this->m_type\
    \ == ::tools::safe_int<T>::type::finite;\n    }\n\n    constexpr bool is_nan()\
    \ const {\n      return this->m_type == ::tools::safe_int<T>::type::nan;\n   \
    \ }\n\n    constexpr T val() const {\n      assert(this->is_finite());\n     \
    \ return this->m_value;\n    }\n\n    friend constexpr bool operator==(const ::tools::safe_int<T>&\
    \ x, const ::tools::safe_int<T>& y) {\n      constexpr auto table = ::std::array<::std::array<::std::optional<bool>,\
    \ 3>, 3>({{\n        {BQ(), BF(), BF()},\n        {BF(), BT(), BF()},\n      \
    \  {BF(), BF(), BF()}\n      }});\n      if (const auto r = table[f1(x)][f1(y)];\
    \ r) return *r;\n\n      return x.m_value == y.m_value;\n    }\n    friend constexpr\
    \ bool operator!=(const ::tools::safe_int<T>& x, const ::tools::safe_int<T>& y)\
    \ {\n      return !(x == y);\n    }\n\n    constexpr ::tools::safe_int<T> operator+()\
    \ const {\n      return *this;\n    }\n    constexpr ::tools::safe_int<T> operator-()\
    \ const {\n      constexpr auto table = ::std::array<::std::optional<::tools::safe_int<T>>,\
    \ 3>({\n        {Q(), U(), U()}\n      });\n      if (const auto r = table[f1(*this)];\
    \ r) return *r;\n\n      if (this->m_value > 0) return *U();\n      return ::tools::safe_int<T>(0);\n\
    \    }\n\n    friend constexpr ::tools::safe_int<T> operator+(const ::tools::safe_int<T>&\
    \ x, const ::tools::safe_int<T>& y) {\n      constexpr auto table = ::std::array<::std::array<::std::optional<::tools::safe_int<T>>,\
    \ 3>, 3>({{\n        {Q(), P(), U()},\n        {P(), P(), U()},\n        {U(),\
    \ U(), U()}\n      }});\n      if (const auto r = table[f1(x)][f1(y)]; r) return\
    \ *r;\n\n      if (y.m_value > 0 && x.m_value > ::std::numeric_limits<T>::max()\
    \ - y.m_value) return *U();\n      return ::tools::safe_int<T>(x.m_value + y.m_value);\n\
    \    }\n    friend constexpr ::tools::safe_int<T> operator+(const ::tools::safe_int<T>&\
    \ x, const T& y) {\n      return x + tools::safe_int<T>(y);\n    }\n    friend\
    \ constexpr ::tools::safe_int<T> operator+(const T& x, const ::tools::safe_int<T>&\
    \ y) {\n      return tools::safe_int<T>(x) + y;\n    }\n\n    friend constexpr\
    \ ::tools::safe_int<T> operator-(const ::tools::safe_int<T>& x, const ::tools::safe_int<T>&\
    \ y) {\n      constexpr auto table = ::std::array<::std::array<::std::optional<::tools::safe_int<T>>,\
    \ 3>, 3>({{\n        {Q(), U(), U()},\n        {P(), U(), U()},\n        {U(),\
    \ U(), U()}\n      }});\n      if (const auto r = table[f1(x)][f1(y)]; r) return\
    \ *r;\n\n      if (x.m_value < y.m_value) return *U();\n      return ::tools::safe_int<T>(x.m_value\
    \ - y.m_value);\n    }\n    friend constexpr ::tools::safe_int<T> operator-(const\
    \ ::tools::safe_int<T>& x, const T& y) {\n      return x - tools::safe_int<T>(y);\n\
    \    }\n    friend constexpr ::tools::safe_int<T> operator-(const T& x, const\
    \ ::tools::safe_int<T>& y) {\n      return tools::safe_int<T>(x) - y;\n    }\n\
    \n    friend constexpr ::tools::safe_int<T> operator*(const ::tools::safe_int<T>&\
    \ x, const ::tools::safe_int<T>& y) {\n      constexpr auto table = ::std::array<::std::array<::std::optional<::tools::safe_int<T>>,\
    \ 4>, 4>({{\n        {Z(), Z(), U(), U()},\n        {Z(), Q(), P(), U()},\n  \
    \      {U(), P(), P(), U()},\n        {U(), U(), U(), U()}\n      }});\n     \
    \ if (const auto r = table[f2(x)][f2(y)]; r) return *r;\n\n      if (x.m_value\
    \ > ::std::numeric_limits<T>::max() / y.m_value) {\n        return *U();\n   \
    \   }\n      return ::tools::safe_int<T>(x.m_value * y.m_value);\n    }\n    friend\
    \ constexpr ::tools::safe_int<T> operator*(const ::tools::safe_int<T>& x, const\
    \ T& y) {\n      return x * tools::safe_int<T>(y);\n    }\n    friend constexpr\
    \ ::tools::safe_int<T> operator*(const T& x, const ::tools::safe_int<T>& y) {\n\
    \      return tools::safe_int<T>(x) * y;\n    }\n\n    friend constexpr ::tools::safe_int<T>\
    \ operator/(const ::tools::safe_int<T>& x, const ::tools::safe_int<T>& y) {\n\
    \      constexpr auto table = ::std::array<::std::array<::std::optional<::tools::safe_int<T>>,\
    \ 4>, 4>({{\n        {U(), Z(), Z(), U()},\n        {U(), Q(), Z(), U()},\n  \
    \      {U(), P(), U(), U()},\n        {U(), U(), U(), U()}\n      }});\n     \
    \ if (const auto r = table[f2(x)][f2(y)]; r) return *r;\n\n      return ::tools::safe_int<T>(x.m_value\
    \ / y.m_value);\n    }\n    friend constexpr ::tools::safe_int<T> operator/(const\
    \ ::tools::safe_int<T>& x, const T& y) {\n      return x / tools::safe_int<T>(y);\n\
    \    }\n    friend constexpr ::tools::safe_int<T> operator/(const T& x, const\
    \ ::tools::safe_int<T>& y) {\n      return tools::safe_int<T>(x) / y;\n    }\n\
    \n    friend constexpr ::tools::safe_int<T> operator%(const ::tools::safe_int<T>&\
    \ x, const ::tools::safe_int<T>& y) {\n      constexpr auto table = ::std::array<::std::array<::std::optional<::tools::safe_int<T>>,\
    \ 4>, 4>({{\n        {U(), Z(), U(), U()},\n        {U(), Q(), U(), U()},\n  \
    \      {U(), U(), U(), U()},\n        {U(), U(), U(), U()}\n      }});\n     \
    \ if (const auto r = table[f2(x)][f2(y)]; r) return *r;\n\n      return ::tools::safe_int<T>(x.m_value\
    \ % y.m_value);\n    }\n    friend constexpr ::tools::safe_int<T> operator%(const\
    \ ::tools::safe_int<T>& x, const T& y) {\n      return x % tools::safe_int<T>(y);\n\
    \    }\n    friend constexpr ::tools::safe_int<T> operator%(const T& x, const\
    \ ::tools::safe_int<T>& y) {\n      return tools::safe_int<T>(x) % y;\n    }\n\
    \n    constexpr ::tools::safe_int<T>& operator+=(const ::tools::safe_int<T>& other)\
    \ {\n      return *this = *this + other;\n    }\n    constexpr ::tools::safe_int<T>&\
    \ operator+=(const T& other) {\n      return *this = *this + ::tools::safe_int<T>(other);\n\
    \    }\n    constexpr ::tools::safe_int<T>& operator-=(const ::tools::safe_int<T>&\
    \ other) {\n      return *this = *this - other;\n    }\n    constexpr ::tools::safe_int<T>&\
    \ operator-=(const T& other) {\n      return *this = *this - ::tools::safe_int<T>(other);\n\
    \    }\n    constexpr ::tools::safe_int<T>& operator*=(const ::tools::safe_int<T>&\
    \ other) {\n      return *this = *this * other;\n    }\n    constexpr ::tools::safe_int<T>&\
    \ operator*=(const T& other) {\n      return *this = *this * ::tools::safe_int<T>(other);\n\
    \    }\n    constexpr ::tools::safe_int<T>& operator/=(const ::tools::safe_int<T>&\
    \ other) {\n      return *this = *this / other;\n    }\n    constexpr ::tools::safe_int<T>&\
    \ operator/=(const T& other) {\n      return *this = *this / ::tools::safe_int<T>(other);\n\
    \    }\n    constexpr ::tools::safe_int<T>& operator%=(const ::tools::safe_int<T>&\
    \ other) {\n      return *this = *this % other;\n    }\n    constexpr ::tools::safe_int<T>&\
    \ operator%=(const T& other) {\n      return *this = *this % ::tools::safe_int<T>(other);\n\
    \    }\n\n    constexpr ::tools::safe_int<T>& operator++() {\n      return *this\
    \ += ::tools::safe_int<T>(T(1));\n    }\n    constexpr ::tools::safe_int<T> operator++(int)\
    \ {\n      const auto r = *this;\n      ++(*this);\n      return r;\n    }\n \
    \   constexpr ::tools::safe_int<T>& operator--() {\n      return *this -= ::tools::safe_int<T>(T(1));\n\
    \    }\n    constexpr ::tools::safe_int<T> operator--(int) {\n      const auto\
    \ r = *this;\n      --(*this);\n      return r;\n    }\n\n    friend constexpr\
    \ bool operator<(const ::tools::safe_int<T>& x, const ::tools::safe_int<T>& y)\
    \ {\n      constexpr auto table = ::std::array<::std::array<::std::optional<bool>,\
    \ 3>, 3>({{\n        {BQ(), BT(), BF()},\n        {BF(), BF(), BF()},\n      \
    \  {BF(), BF(), BF()}\n      }});\n      if (const auto r = table[f1(x)][f1(y)];\
    \ r) return *r;\n\n      return x.m_value < y.m_value;\n    }\n    friend constexpr\
    \ bool operator>(const ::tools::safe_int<T>& x, const ::tools::safe_int<T>& y)\
    \ {\n      constexpr auto table = ::std::array<::std::array<::std::optional<bool>,\
    \ 3>, 3>({{\n        {BQ(), BF(), BF()},\n        {BT(), BF(), BF()},\n      \
    \  {BF(), BF(), BF()}\n      }});\n      if (const auto r = table[f1(x)][f1(y)];\
    \ r) return *r;\n\n      return x.m_value > y.m_value;\n    }\n    friend constexpr\
    \ bool operator<=(const ::tools::safe_int<T>& x, const ::tools::safe_int<T>& y)\
    \ {\n      return x < y || x == y;\n    }\n    friend constexpr bool operator>=(const\
    \ ::tools::safe_int<T>& x, const ::tools::safe_int<T>& y) {\n      return x >\
    \ y || x == y;\n    }\n\n    friend ::std::istream& operator>>(::std::istream&\
    \ is, ::tools::safe_int<T>& self) {\n      self.m_type = ::tools::safe_int<T>::type::finite;\n\
    \      return is >> self.m_value;\n    }\n    friend ::std::ostream& operator<<(::std::ostream&\
    \ os, const ::tools::safe_int<T>& self) {\n      switch (self.m_type) {\n    \
    \  case ::tools::safe_int<T>::type::finite:\n        return os << self.m_value;\n\
    \      case ::tools::safe_int<T>::type::pos_inf:\n        return os << \"inf\"\
    ;\n      default: // nan\n        return os << \"nan\";\n      }\n    }\n  };\n\
    }\n\n\n#line 7 \"tests/safe_int.test.cpp\"\n\nvoid test_signed_int() {\n  const\
    \ tools::safe_int<int> POS_INF = tools::safe_int<int>::infinity();\n  const tools::safe_int<int>\
    \ NEG_INF = -tools::safe_int<int>::infinity();\n  const int INT_MAX = std::numeric_limits<int>::max();\n\
    \  const int INT_MIN = std::numeric_limits<int>::min();\n  using s = tools::safe_int<int>;\n\
    \n  // basic arithmetic operations\n  assert_that(s(1) + s(2) == s(3));\n  assert_that(s(1)\
    \ - s(2) == s(-1));\n  assert_that(s(1) * s(2) == s(2));\n  assert_that(s(1) /\
    \ s(2) == s(0));\n  assert_that(s(1) % s(2) == s(1));\n\n  // operator+ should\
    \ detect an overflow.\n  assert_that(s(INT_MAX - 2) + s(1) == s(INT_MAX - 1));\n\
    \  assert_that(s(INT_MAX - 2) + s(2) == s(INT_MAX));\n  assert_that((s(INT_MAX\
    \ - 2) + s(3)).is_nan());\n  assert_that(s(1) + s(INT_MAX - 2) == s(INT_MAX -\
    \ 1));\n  assert_that(s(2) + s(INT_MAX - 2) == s(INT_MAX));\n  assert_that((s(3)\
    \ + s(INT_MAX - 2)).is_nan());\n  assert_that(s(INT_MIN + 2) + s(-1) == s(INT_MIN\
    \ + 1));\n  assert_that(s(INT_MIN + 2) + s(-2) == s(INT_MIN));\n  assert_that((s(INT_MIN\
    \ + 2) + s(-3)).is_nan());\n  assert_that(s(-1) + s(INT_MIN + 2) == s(INT_MIN\
    \ + 1));\n  assert_that(s(-2) + s(INT_MIN + 2) == s(INT_MIN));\n  assert_that((s(-3)\
    \ + s(INT_MIN + 2)).is_nan());\n\n  // infinite + finite should be infinite.\n\
    \  assert_that(POS_INF + s(-1) == POS_INF);\n  assert_that(s(-1) + POS_INF ==\
    \ POS_INF);\n  assert_that(POS_INF + POS_INF == POS_INF);\n  assert_that(NEG_INF\
    \ + s(1) == NEG_INF);\n  assert_that(s(1) + NEG_INF == NEG_INF);\n  assert_that(NEG_INF\
    \ + NEG_INF == NEG_INF);\n\n  // operator- should detect an overflow.\n  assert_that(s(INT_MAX\
    \ - 2) - s(-1) == s(INT_MAX - 1));\n  assert_that(s(INT_MAX - 2) - s(-2) == s(INT_MAX));\n\
    \  assert_that(s((INT_MAX - 2) - s(-3)).is_nan());\n  assert_that(s(INT_MIN +\
    \ 2) - s(1) == s(INT_MIN + 1));\n  assert_that(s(INT_MIN + 2) - s(2) == s(INT_MIN));\n\
    \  assert_that((s(INT_MIN + 2) - s(3)).is_nan());\n\n  // infinite - finite should\
    \ be finite.\n  assert_that(POS_INF - s(1) == POS_INF);\n  assert_that(POS_INF\
    \ - NEG_INF == POS_INF);\n  assert_that(NEG_INF - s(-1) == NEG_INF);\n  assert_that(NEG_INF\
    \ - POS_INF == NEG_INF);\n\n  // operator* should detect an overflow.\n  assert_that(NEG_INF\
    \ * NEG_INF == POS_INF);\n  assert_that(NEG_INF * s(INT_MIN) == POS_INF);\n  assert_that((NEG_INF\
    \ * s(0)).is_nan());\n  assert_that(NEG_INF * s(INT_MAX) == NEG_INF);\n  assert_that(NEG_INF\
    \ * POS_INF == NEG_INF);\n  assert_that(s(INT_MIN) * NEG_INF == POS_INF);\n  assert_that((s(INT_MIN)\
    \ * s(INT_MIN)).is_nan());\n  assert_that(s(INT_MIN) * s(0) == s(0));\n  assert_that((s(INT_MIN)\
    \ * s(INT_MAX)).is_nan());\n  assert_that(s(INT_MIN) * POS_INF == NEG_INF);\n\
    \  assert_that((s(0) * NEG_INF).is_nan());\n  assert_that(s(0) * s(INT_MIN) ==\
    \ s(0));\n  assert_that(s(0) * s(0) == s(0));\n  assert_that(s(0) * s(INT_MAX)\
    \ == s(0));\n  assert_that((s(0) * POS_INF).is_nan());\n  assert_that(s(INT_MAX)\
    \ * NEG_INF == NEG_INF);\n  assert_that((s(INT_MAX) * s(INT_MIN)).is_nan());\n\
    \  assert_that(s(INT_MAX) * s(0) == s(0));\n  assert_that((s(INT_MAX) * s(INT_MAX)).is_nan());\n\
    \  assert_that(s(INT_MAX) * POS_INF == POS_INF);\n  assert_that(POS_INF * NEG_INF\
    \ == NEG_INF);\n  assert_that(POS_INF * s(INT_MIN) == NEG_INF);\n  assert_that((POS_INF\
    \ * s(0)).is_nan());\n  assert_that(POS_INF * s(INT_MAX) == POS_INF);\n  assert_that(POS_INF\
    \ * POS_INF == POS_INF);\n}\n\nvoid test_unsigned_int() {\n  const tools::safe_int<unsigned\
    \ int> POS_INF = tools::safe_int<unsigned int>::infinity();\n  const unsigned\
    \ int UINT_MAX = std::numeric_limits<unsigned int>::max();\n  using u = tools::safe_int<unsigned\
    \ int>;\n\n  // basic arithmetic operations\n  assert_that(u(3) + u(2) == u(5));\n\
    \  assert_that(u(3) - u(2) == u(1));\n  assert_that(u(3) * u(2) == u(6));\n  assert_that(u(3)\
    \ / u(2) == u(1));\n  assert_that(u(3) % u(2) == u(1));\n\n  // operator+ should\
    \ detect an overflow.\n  assert_that(u(UINT_MAX - 2) + u(1) == u(UINT_MAX - 1));\n\
    \  assert_that(u(UINT_MAX - 2) + u(2) == u(UINT_MAX));\n  assert_that((u(UINT_MAX\
    \ - 2) + u(3)).is_nan());\n  assert_that(u(1) + u(UINT_MAX - 2) == u(UINT_MAX\
    \ - 1));\n  assert_that(u(2) + u(UINT_MAX - 2) == u(UINT_MAX));\n  assert_that((u(3)\
    \ + u(UINT_MAX - 2)).is_nan());\n\n  // infinite + finite should be infinite.\n\
    \  assert_that(POS_INF + u(1) == POS_INF);\n  assert_that(u(1) + POS_INF == POS_INF);\n\
    \  assert_that(POS_INF + POS_INF == POS_INF);\n\n  // operator- should detect\
    \ an overflow.\n  assert_that(u(2) - u(1) == u(1));\n  assert_that(u(2) - u(2)\
    \ == u(0));\n  assert_that((u(2) - u(3)).is_nan());\n\n  // infinite - finite\
    \ should be finite.\n  assert_that(POS_INF - u(1) == POS_INF);\n\n  // operator*\
    \ should detect an overflow.\n  assert_that(u(0) * u(0) == u(0));\n  assert_that(u(0)\
    \ * u(UINT_MAX) == u(0));\n  assert_that((u(0) * POS_INF).is_nan());\n  assert_that(u(UINT_MAX)\
    \ * u(0) == u(0));\n  assert_that((u(UINT_MAX) * u(UINT_MAX)).is_nan());\n  assert_that(u(UINT_MAX)\
    \ * POS_INF == POS_INF);\n  assert_that((POS_INF * u(0)).is_nan());\n  assert_that(POS_INF\
    \ * u(UINT_MAX) == POS_INF);\n  assert_that(POS_INF * POS_INF == POS_INF);\n}\n\
    \nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  test_signed_int();\n  test_unsigned_int();\n\n  std::cout << \"Hello World\"\
    \ << '\\n';\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\"\n\n\
    #include <cstdlib>\n#include <iostream>\n#include \"tools/assert_that.hpp\"\n\
    #include \"tools/safe_int.hpp\"\n\nvoid test_signed_int() {\n  const tools::safe_int<int>\
    \ POS_INF = tools::safe_int<int>::infinity();\n  const tools::safe_int<int> NEG_INF\
    \ = -tools::safe_int<int>::infinity();\n  const int INT_MAX = std::numeric_limits<int>::max();\n\
    \  const int INT_MIN = std::numeric_limits<int>::min();\n  using s = tools::safe_int<int>;\n\
    \n  // basic arithmetic operations\n  assert_that(s(1) + s(2) == s(3));\n  assert_that(s(1)\
    \ - s(2) == s(-1));\n  assert_that(s(1) * s(2) == s(2));\n  assert_that(s(1) /\
    \ s(2) == s(0));\n  assert_that(s(1) % s(2) == s(1));\n\n  // operator+ should\
    \ detect an overflow.\n  assert_that(s(INT_MAX - 2) + s(1) == s(INT_MAX - 1));\n\
    \  assert_that(s(INT_MAX - 2) + s(2) == s(INT_MAX));\n  assert_that((s(INT_MAX\
    \ - 2) + s(3)).is_nan());\n  assert_that(s(1) + s(INT_MAX - 2) == s(INT_MAX -\
    \ 1));\n  assert_that(s(2) + s(INT_MAX - 2) == s(INT_MAX));\n  assert_that((s(3)\
    \ + s(INT_MAX - 2)).is_nan());\n  assert_that(s(INT_MIN + 2) + s(-1) == s(INT_MIN\
    \ + 1));\n  assert_that(s(INT_MIN + 2) + s(-2) == s(INT_MIN));\n  assert_that((s(INT_MIN\
    \ + 2) + s(-3)).is_nan());\n  assert_that(s(-1) + s(INT_MIN + 2) == s(INT_MIN\
    \ + 1));\n  assert_that(s(-2) + s(INT_MIN + 2) == s(INT_MIN));\n  assert_that((s(-3)\
    \ + s(INT_MIN + 2)).is_nan());\n\n  // infinite + finite should be infinite.\n\
    \  assert_that(POS_INF + s(-1) == POS_INF);\n  assert_that(s(-1) + POS_INF ==\
    \ POS_INF);\n  assert_that(POS_INF + POS_INF == POS_INF);\n  assert_that(NEG_INF\
    \ + s(1) == NEG_INF);\n  assert_that(s(1) + NEG_INF == NEG_INF);\n  assert_that(NEG_INF\
    \ + NEG_INF == NEG_INF);\n\n  // operator- should detect an overflow.\n  assert_that(s(INT_MAX\
    \ - 2) - s(-1) == s(INT_MAX - 1));\n  assert_that(s(INT_MAX - 2) - s(-2) == s(INT_MAX));\n\
    \  assert_that(s((INT_MAX - 2) - s(-3)).is_nan());\n  assert_that(s(INT_MIN +\
    \ 2) - s(1) == s(INT_MIN + 1));\n  assert_that(s(INT_MIN + 2) - s(2) == s(INT_MIN));\n\
    \  assert_that((s(INT_MIN + 2) - s(3)).is_nan());\n\n  // infinite - finite should\
    \ be finite.\n  assert_that(POS_INF - s(1) == POS_INF);\n  assert_that(POS_INF\
    \ - NEG_INF == POS_INF);\n  assert_that(NEG_INF - s(-1) == NEG_INF);\n  assert_that(NEG_INF\
    \ - POS_INF == NEG_INF);\n\n  // operator* should detect an overflow.\n  assert_that(NEG_INF\
    \ * NEG_INF == POS_INF);\n  assert_that(NEG_INF * s(INT_MIN) == POS_INF);\n  assert_that((NEG_INF\
    \ * s(0)).is_nan());\n  assert_that(NEG_INF * s(INT_MAX) == NEG_INF);\n  assert_that(NEG_INF\
    \ * POS_INF == NEG_INF);\n  assert_that(s(INT_MIN) * NEG_INF == POS_INF);\n  assert_that((s(INT_MIN)\
    \ * s(INT_MIN)).is_nan());\n  assert_that(s(INT_MIN) * s(0) == s(0));\n  assert_that((s(INT_MIN)\
    \ * s(INT_MAX)).is_nan());\n  assert_that(s(INT_MIN) * POS_INF == NEG_INF);\n\
    \  assert_that((s(0) * NEG_INF).is_nan());\n  assert_that(s(0) * s(INT_MIN) ==\
    \ s(0));\n  assert_that(s(0) * s(0) == s(0));\n  assert_that(s(0) * s(INT_MAX)\
    \ == s(0));\n  assert_that((s(0) * POS_INF).is_nan());\n  assert_that(s(INT_MAX)\
    \ * NEG_INF == NEG_INF);\n  assert_that((s(INT_MAX) * s(INT_MIN)).is_nan());\n\
    \  assert_that(s(INT_MAX) * s(0) == s(0));\n  assert_that((s(INT_MAX) * s(INT_MAX)).is_nan());\n\
    \  assert_that(s(INT_MAX) * POS_INF == POS_INF);\n  assert_that(POS_INF * NEG_INF\
    \ == NEG_INF);\n  assert_that(POS_INF * s(INT_MIN) == NEG_INF);\n  assert_that((POS_INF\
    \ * s(0)).is_nan());\n  assert_that(POS_INF * s(INT_MAX) == POS_INF);\n  assert_that(POS_INF\
    \ * POS_INF == POS_INF);\n}\n\nvoid test_unsigned_int() {\n  const tools::safe_int<unsigned\
    \ int> POS_INF = tools::safe_int<unsigned int>::infinity();\n  const unsigned\
    \ int UINT_MAX = std::numeric_limits<unsigned int>::max();\n  using u = tools::safe_int<unsigned\
    \ int>;\n\n  // basic arithmetic operations\n  assert_that(u(3) + u(2) == u(5));\n\
    \  assert_that(u(3) - u(2) == u(1));\n  assert_that(u(3) * u(2) == u(6));\n  assert_that(u(3)\
    \ / u(2) == u(1));\n  assert_that(u(3) % u(2) == u(1));\n\n  // operator+ should\
    \ detect an overflow.\n  assert_that(u(UINT_MAX - 2) + u(1) == u(UINT_MAX - 1));\n\
    \  assert_that(u(UINT_MAX - 2) + u(2) == u(UINT_MAX));\n  assert_that((u(UINT_MAX\
    \ - 2) + u(3)).is_nan());\n  assert_that(u(1) + u(UINT_MAX - 2) == u(UINT_MAX\
    \ - 1));\n  assert_that(u(2) + u(UINT_MAX - 2) == u(UINT_MAX));\n  assert_that((u(3)\
    \ + u(UINT_MAX - 2)).is_nan());\n\n  // infinite + finite should be infinite.\n\
    \  assert_that(POS_INF + u(1) == POS_INF);\n  assert_that(u(1) + POS_INF == POS_INF);\n\
    \  assert_that(POS_INF + POS_INF == POS_INF);\n\n  // operator- should detect\
    \ an overflow.\n  assert_that(u(2) - u(1) == u(1));\n  assert_that(u(2) - u(2)\
    \ == u(0));\n  assert_that((u(2) - u(3)).is_nan());\n\n  // infinite - finite\
    \ should be finite.\n  assert_that(POS_INF - u(1) == POS_INF);\n\n  // operator*\
    \ should detect an overflow.\n  assert_that(u(0) * u(0) == u(0));\n  assert_that(u(0)\
    \ * u(UINT_MAX) == u(0));\n  assert_that((u(0) * POS_INF).is_nan());\n  assert_that(u(UINT_MAX)\
    \ * u(0) == u(0));\n  assert_that((u(UINT_MAX) * u(UINT_MAX)).is_nan());\n  assert_that(u(UINT_MAX)\
    \ * POS_INF == POS_INF);\n  assert_that((POS_INF * u(0)).is_nan());\n  assert_that(POS_INF\
    \ * u(UINT_MAX) == POS_INF);\n  assert_that(POS_INF * POS_INF == POS_INF);\n}\n\
    \nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  test_signed_int();\n  test_unsigned_int();\n\n  std::cout << \"Hello World\"\
    \ << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - tools/assert_that.hpp
  - tools/safe_int.hpp
  isVerificationFile: true
  path: tests/safe_int.test.cpp
  requiredBy: []
  timestamp: '2024-08-31 13:46:12+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: tests/safe_int.test.cpp
layout: document
redirect_from:
- /verify/tests/safe_int.test.cpp
- /verify/tests/safe_int.test.cpp.html
title: tests/safe_int.test.cpp
---
