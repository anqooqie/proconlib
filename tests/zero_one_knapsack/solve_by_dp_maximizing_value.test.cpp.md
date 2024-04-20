---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: tools/assert_that.hpp
    title: Assertion macro
  - icon: ':heavy_check_mark:'
    path: tools/ceil.hpp
    title: $\left\lceil \frac{x}{y} \right\rceil$
  - icon: ':heavy_check_mark:'
    path: tools/chmax.hpp
    title: chmax function
  - icon: ':heavy_check_mark:'
    path: tools/chmin.hpp
    title: chmin function
  - icon: ':heavy_check_mark:'
    path: tools/cmp_less.hpp
    title: Polyfill of std::cmp_less
  - icon: ':heavy_check_mark:'
    path: tools/less_by_get.hpp
    title: std::less by std::get
  - icon: ':heavy_check_mark:'
    path: tools/pow2.hpp
    title: $2^x$
  - icon: ':heavy_check_mark:'
    path: tools/safe_int.hpp
    title: $\mathbb{Z} \cup \{\infty, -\infty, \mathrm{NaN}\}$ and $\mathbb{Z}_{\geq
      0} \cup \{\infty, \mathrm{NaN}\}$
  - icon: ':heavy_check_mark:'
    path: tools/zero_one_knapsack.hpp
    title: 0-1 knapsack problem
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/DPL_1_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/DPL_1_B
  bundledCode: "#line 1 \"tests/zero_one_knapsack/solve_by_dp_maximizing_value.test.cpp\"\
    \n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/DPL_1_B\"\n\n#include\
    \ <iostream>\n#line 1 \"tools/zero_one_knapsack.hpp\"\n\n\n\n#include <vector>\n\
    #include <utility>\n#include <cassert>\n#include <cstddef>\n#include <limits>\n\
    #include <iterator>\n#include <algorithm>\n#include <tuple>\n#include <array>\n\
    #include <numeric>\n#line 1 \"tools/chmax.hpp\"\n\n\n\n#include <type_traits>\n\
    #line 1 \"tools/cmp_less.hpp\"\n\n\n\n#line 5 \"tools/cmp_less.hpp\"\n\nnamespace\
    \ tools {\n  template <typename T, typename U>\n  constexpr bool cmp_less(const\
    \ T t, const U u) noexcept {\n    using UT = ::std::make_unsigned_t<T>;\n    using\
    \ UU = ::std::make_unsigned_t<U>;\n    if constexpr (::std::is_signed_v<T> ==\
    \ ::std::is_signed_v<U>) {\n      return t < u;\n    } else if constexpr (::std::is_signed_v<T>)\
    \ {\n      return t < 0 ? true : UT(t) < u;\n    } else {\n      return u < 0\
    \ ? false : t < UU(u);\n    }\n  }\n}\n\n\n#line 6 \"tools/chmax.hpp\"\n\nnamespace\
    \ tools {\n\n  template <typename M, typename N>\n  bool chmax(M& lhs, const N&\
    \ rhs) {\n    bool updated;\n    if constexpr (::std::is_integral_v<M> && ::std::is_integral_v<N>)\
    \ {\n      updated = ::tools::cmp_less(lhs, rhs);\n    } else {\n      updated\
    \ = lhs < rhs;\n    }\n    if (updated) lhs = rhs;\n    return updated;\n  }\n\
    }\n\n\n#line 1 \"tools/chmin.hpp\"\n\n\n\n#line 6 \"tools/chmin.hpp\"\n\nnamespace\
    \ tools {\n\n  template <typename M, typename N>\n  bool chmin(M& lhs, const N&\
    \ rhs) {\n    bool updated;\n    if constexpr (::std::is_integral_v<M> && ::std::is_integral_v<N>)\
    \ {\n      updated = ::tools::cmp_less(rhs, lhs);\n    } else {\n      updated\
    \ = rhs < lhs;\n    }\n    if (updated) lhs = rhs;\n    return updated;\n  }\n\
    }\n\n\n#line 1 \"tools/less_by_get.hpp\"\n\n\n\n#line 6 \"tools/less_by_get.hpp\"\
    \n\nnamespace tools {\n\n  template <::std::size_t I>\n  struct less_by_get {\n\
    \    template <class T>\n    bool operator()(const T& x, const T& y) const {\n\
    \      return ::std::get<I>(x) < ::std::get<I>(y);\n    }\n  };\n}\n\n\n#line\
    \ 1 \"tools/safe_int.hpp\"\n\n\n\n#line 9 \"tools/safe_int.hpp\"\n#include <optional>\n\
    #line 11 \"tools/safe_int.hpp\"\n\nnamespace tools {\n  template <typename T,\
    \ typename = void>\n  class safe_int;\n\n  template <typename T>\n  class safe_int<T,\
    \ ::std::enable_if_t<::std::is_signed_v<T>>> {\n  private:\n    enum class type\
    \ {\n      finite,\n      pos_inf,\n      neg_inf,\n      nan\n    };\n    typename\
    \ ::tools::safe_int<T>::type m_type;\n    T m_value;\n\n    constexpr safe_int(const\
    \ typename ::tools::safe_int<T>::type type) :\n      m_type(type), m_value(T())\
    \ {\n    }\n\n  public:\n    constexpr safe_int() :\n      m_type(::tools::safe_int<T>::type::finite),\
    \ m_value(T()) {\n    }\n    explicit constexpr safe_int(const T value) :\n  \
    \    m_type(::tools::safe_int<T>::type::finite), m_value(value) {\n    }\n   \
    \ constexpr safe_int(const ::tools::safe_int<T>& other) :\n      m_type(other.m_type),\
    \ m_value(other.m_value) {\n    }\n    ~safe_int() = default;\n    constexpr ::tools::safe_int<T>&\
    \ operator=(const ::tools::safe_int<T>& other) {\n      this->m_type = other.m_type;\n\
    \      this->m_value = other.m_value;\n      return *this;\n    }\n\n    static\
    \ constexpr ::tools::safe_int<T> infinity() {\n      return tools::safe_int<T>(::tools::safe_int<T>::type::pos_inf);\n\
    \    }\n    static constexpr ::tools::safe_int<T> nan() {\n      return tools::safe_int<T>(::tools::safe_int<T>::type::nan);\n\
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
    }\n\n\n#line 1 \"tools/ceil.hpp\"\n\n\n\n#line 6 \"tools/ceil.hpp\"\n\nnamespace\
    \ tools {\n\n  template <typename M, typename N>\n  constexpr ::std::common_type_t<M,\
    \ N> ceil(const M lhs, const N rhs) {\n    using T = ::std::common_type_t<M, N>;\n\
    \    assert(rhs != N(0));\n    return lhs / rhs + T(((lhs > M(0) && rhs > N(0))\
    \ || (lhs < M(0) && rhs < N(0))) && lhs % rhs);\n  }\n}\n\n\n#line 1 \"tools/pow2.hpp\"\
    \n\n\n\n#line 6 \"tools/pow2.hpp\"\n\nnamespace tools {\n\n  template <typename\
    \ T, typename ::std::enable_if<::std::is_unsigned<T>::value, ::std::nullptr_t>::type\
    \ = nullptr>\n  constexpr T pow2(const T x) {\n    return static_cast<T>(1) <<\
    \ x;\n  }\n\n  template <typename T, typename ::std::enable_if<::std::is_signed<T>::value,\
    \ ::std::nullptr_t>::type = nullptr>\n  constexpr T pow2(const T x) {\n    return\
    \ static_cast<T>(static_cast<typename ::std::make_unsigned<T>::type>(1) << static_cast<typename\
    \ ::std::make_unsigned<T>::type>(x));\n  }\n}\n\n\n#line 20 \"tools/zero_one_knapsack.hpp\"\
    \n\nnamespace tools {\n  template <typename T>\n  class zero_one_knapsack {\n\
    \  private:\n    T m_W;\n    ::std::vector<::std::pair<T, T>> m_items;\n\n  public:\n\
    \    zero_one_knapsack() = default;\n    zero_one_knapsack(const ::tools::zero_one_knapsack<T>&)\
    \ = default;\n    zero_one_knapsack(::tools::zero_one_knapsack<T>&&) = default;\n\
    \    ~zero_one_knapsack() = default;\n    ::tools::zero_one_knapsack<T>& operator=(const\
    \ ::tools::zero_one_knapsack<T>&) = default;\n    ::tools::zero_one_knapsack<T>&\
    \ operator=(::tools::zero_one_knapsack<T>&&) = default;\n\n    explicit zero_one_knapsack(const\
    \ T W) : m_W(W) {\n      assert(W >= 0);\n    }\n\n    ::std::size_t size() const\
    \ {\n      return this->m_items.size();\n    }\n\n    T capacity() const {\n \
    \     return this->m_W;\n    }\n\n    ::std::size_t add_item(const T v, const\
    \ T w) {\n      assert(v >= 0);\n      assert(w >= 0);\n      this->m_items.emplace_back(v,\
    \ w);\n      return this->m_items.size() - 1;\n    }\n\n    ::std::pair<T, T>\
    \ get_item(const ::std::size_t k) const {\n      assert(k < this->m_items.size());\n\
    \      return this->m_items[k];\n    }\n\n    const ::std::vector<::std::pair<T,\
    \ T>>& items() const {\n      return this->m_items;\n    }\n\n  private:\n   \
    \ ::std::pair<T, ::std::vector<::std::size_t>> solve_by_dp_maximizing_value()\
    \ const {\n      auto dp = ::std::vector(this->size() + 1, ::std::vector(this->m_W\
    \ + 1, ::std::numeric_limits<T>::min()));\n      dp[0][0] = 0;\n      for (::std::size_t\
    \ i = 1; i <= this->size(); ++i) {\n        const auto [v, w] = this->m_items[i\
    \ - 1];\n        for (T j = 0; j <= this->m_W; ++j) {\n          dp[i][j] = dp[i\
    \ - 1][j];\n          if (j >= w && dp[i - 1][j - w] >= 0) {\n            ::tools::chmax(dp[i][j],\
    \ dp[i - 1][j - w] + v);\n          }\n        }\n      }\n\n      ::std::pair<T,\
    \ ::std::vector<::std::size_t>> res;\n      auto& [answer, selected] = res;\n\
    \      T left = ::std::distance(dp[this->size()].begin(), ::std::max_element(dp[this->size()].begin(),\
    \ dp[this->size()].end()));\n      answer = dp[this->size()][left];\n      for\
    \ (::std::size_t i = this->size(); i --> 0;) {\n        const auto [v, w] = this->m_items[i];\n\
    \        if (dp[i + 1][left] != dp[i][left]) {\n          assert(left >= w);\n\
    \          assert(dp[i + 1][left] == dp[i][left - w] + v);\n          selected.push_back(i);\n\
    \          left -= w;\n        }\n      }\n      assert(left == 0);\n\n      ::std::reverse(selected.begin(),\
    \ selected.end());\n      return res;\n    }\n\n    ::std::pair<T, ::std::vector<::std::size_t>>\
    \ solve_by_dp_minimizing_weight() const {\n      const auto max_V = ::std::accumulate(this->m_items.begin(),\
    \ this->m_items.end(), static_cast<T>(0), [](const auto sum, const auto& item)\
    \ { return sum + item.first; });\n      auto dp = ::std::vector(this->size() +\
    \ 1, ::std::vector(max_V + 1, ::std::numeric_limits<T>::max()));\n      dp[0][0]\
    \ = 0;\n      for (::std::size_t i = 1; i <= this->size(); ++i) {\n        const\
    \ auto [v, w] = this->m_items[i - 1];\n        for (T j = 0; j <= max_V; ++j)\
    \ {\n          dp[i][j] = dp[i - 1][j];\n          if (j >= v && dp[i - 1][j -\
    \ v] < ::std::numeric_limits<T>::max() && dp[i - 1][j - v] + w <= this->m_W) {\n\
    \            ::tools::chmin(dp[i][j], dp[i - 1][j - v] + w);\n          }\n  \
    \      }\n      }\n\n      ::std::pair<T, ::std::vector<::std::size_t>> res;\n\
    \      auto& [answer, selected] = res;\n      answer = ::std::distance(dp[this->size()].begin(),\
    \ ::std::prev(::std::find_if(dp[this->size()].rbegin(), dp[this->size()].rend(),\
    \ [](const auto w) { return w < ::std::numeric_limits<T>::max(); }).base()));\n\
    \      T left = answer;\n      for (::std::size_t i = this->size(); i --> 0;)\
    \ {\n        const auto [v, w] = this->m_items[i];\n        if (dp[i + 1][left]\
    \ != dp[i][left]) {\n          assert(left >= v);\n          assert(dp[i + 1][left]\
    \ == dp[i][left - v] + w);\n          selected.push_back(i);\n          left -=\
    \ v;\n        }\n      }\n      assert(left == 0);\n\n      ::std::reverse(selected.begin(),\
    \ selected.end());\n      return res;\n    }\n\n    ::std::pair<T, ::std::vector<::std::size_t>>\
    \ solve_by_meet_in_the_middle() const {\n      const auto f = [&](const ::std::size_t\
    \ L, const ::std::size_t R) {\n        ::std::vector<::std::tuple<::std::size_t,\
    \ T, T>> res;\n        res.emplace_back(0, 0, 0);\n        for (::std::size_t\
    \ i = L; i < R; ++i) {\n          ::std::size_t n = res.size();\n          for\
    \ (::std::size_t j = 0; j < n && ::std::get<2>(res[j]) + this->m_items[i].second\
    \ <= this->m_W; ++j) {\n            res.emplace_back(::std::get<0>(res[j]) | (static_cast<::std::size_t>(1)\
    \ << (i - L)), ::std::get<1>(res[j]) + this->m_items[i].first, ::std::get<2>(res[j])\
    \ + this->m_items[i].second);\n          }\n          ::std::inplace_merge(res.begin(),\
    \ res.begin() + n, res.end(), ::tools::less_by_get<2>());\n        }\n\n     \
    \   for (::std::size_t l = 0, r = 0; l < res.size(); l = r) {\n          for (;\
    \ r < res.size() && ::std::get<2>(res[l]) == ::std::get<2>(res[r]); ++r);\n  \
    \        ::std::iter_swap(res.begin() + l, ::std::max_element(res.begin() + l,\
    \ res.begin() + r, ::tools::less_by_get<1>()));\n        }\n\n        ::std::size_t\
    \ vl = 0;\n        for (::std::size_t vr = 0, al = 0, ar = 0; al < res.size();\
    \ vl = vr, al = ar) {\n          for (; ar < res.size() && ::std::get<1>(res[al])\
    \ >= ::std::get<1>(res[ar]); ++vr, ++ar);\n          if (vl < al) ::std::move(res.begin()\
    \ + al, res.begin() + ar, res.begin() + vl);\n          vr = vl + 1;\n       \
    \ }\n        res.erase(res.begin() + vl, res.end());\n\n        return res;\n\
    \      };\n\n      const auto first_half = f(0, this->size() / 2);\n      const\
    \ auto second_half = f(this->size() / 2, this->size());\n\n      ::std::pair<T,\
    \ ::std::vector<::std::size_t>> res;\n      auto& [answer, selected] = res;\n\
    \      answer = ::std::numeric_limits<T>::min();\n      ::std::pair<::std::size_t,\
    \ ::std::size_t> selected_as_bitset;\n      ::std::size_t r = second_half.size();\n\
    \      for (const auto [state, v, w] : first_half) {\n        for (; w + ::std::get<2>(second_half[r\
    \ - 1]) > this->m_W; --r);\n        if (::tools::chmax(answer, v + ::std::get<1>(second_half[r\
    \ - 1]))) {\n          selected_as_bitset = ::std::make_pair(state, ::std::get<0>(second_half[r\
    \ - 1]));\n        }\n      }\n\n      for (::std::size_t i = 0; i < this->size()\
    \ / 2; ++i) {\n        if (selected_as_bitset.first & (static_cast<::std::size_t>(1)\
    \ << i)) {\n          selected.push_back(i);\n        }\n      }\n      for (::std::size_t\
    \ i = this->size() / 2; i < this->size(); ++i) {\n        if (selected_as_bitset.second\
    \ & (static_cast<::std::size_t>(1) << (i - this->size() / 2))) {\n          selected.push_back(i);\n\
    \        }\n      }\n\n      return res;\n    }\n\n  public:\n    ::std::pair<T,\
    \ ::std::vector<::std::size_t>> query() const {\n      using S = ::tools::safe_int<long\
    \ long>;\n      ::std::array<S, 3> complexities = {\n        S(this->size()) *\
    \ S(this->m_W),\n        S(this->size()) * ::std::accumulate(this->m_items.begin(),\
    \ this->m_items.end(), S(0), [](const auto sum, const auto& item) { return sum\
    \ + S(item.first); }),\n        ::tools::ceil(this->size(), 2) < ::std::numeric_limits<long\
    \ long>::digits ? S(::tools::pow2<long long>(::tools::ceil(this->size(), 2)))\
    \ : S::nan(),\n      };\n      for (auto& complexity : complexities) {\n     \
    \   if (complexity.is_nan()) complexity = S::infinity();\n      }\n      const\
    \ auto min_complexity = *::std::min_element(complexities.begin(), complexities.end());\n\
    \      if (complexities[0] == min_complexity) {\n        return this->solve_by_dp_maximizing_value();\n\
    \      } else if (complexities[1] == min_complexity) {\n        return this->solve_by_dp_minimizing_weight();\n\
    \      } else {\n        return this->solve_by_meet_in_the_middle();\n      }\n\
    \    }\n  };\n}\n\n\n#line 1 \"tools/assert_that.hpp\"\n\n\n\n#line 5 \"tools/assert_that.hpp\"\
    \n#include <cstdlib>\n\n#define assert_that(cond) do {\\\n  if (!(cond)) {\\\n\
    \    ::std::cerr << __FILE__ << ':' << __LINE__ << \": \" << __func__ << \": Assertion\
    \ `\" << #cond << \"' failed.\" << '\\n';\\\n    ::std::exit(EXIT_FAILURE);\\\n\
    \  }\\\n} while (false)\n\n\n#line 6 \"tests/zero_one_knapsack/solve_by_dp_maximizing_value.test.cpp\"\
    \n\nusing ll = long long;\n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  ll N, W;\n  std::cin >> N >> W;\n  tools::zero_one_knapsack<ll> solver(W);\n\
    \  for (ll i = 0; i < N; ++i) {\n    ll v, w;\n    std::cin >> v >> w;\n    solver.add_item(v,\
    \ w);\n  }\n\n  const auto [answer, selected] = solver.query();\n  ll v = 0;\n\
    \  ll w = 0;\n  for (const auto i : selected) {\n    v += solver.get_item(i).first;\n\
    \    w += solver.get_item(i).second;\n  }\n  assert_that(v == answer);\n  assert_that(w\
    \ <= W);\n  std::cout << answer << '\\n';\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/DPL_1_B\"\n\n\
    #include <iostream>\n#include \"tools/zero_one_knapsack.hpp\"\n#include \"tools/assert_that.hpp\"\
    \n\nusing ll = long long;\n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  ll N, W;\n  std::cin >> N >> W;\n  tools::zero_one_knapsack<ll> solver(W);\n\
    \  for (ll i = 0; i < N; ++i) {\n    ll v, w;\n    std::cin >> v >> w;\n    solver.add_item(v,\
    \ w);\n  }\n\n  const auto [answer, selected] = solver.query();\n  ll v = 0;\n\
    \  ll w = 0;\n  for (const auto i : selected) {\n    v += solver.get_item(i).first;\n\
    \    w += solver.get_item(i).second;\n  }\n  assert_that(v == answer);\n  assert_that(w\
    \ <= W);\n  std::cout << answer << '\\n';\n\n  return 0;\n}\n"
  dependsOn:
  - tools/zero_one_knapsack.hpp
  - tools/chmax.hpp
  - tools/cmp_less.hpp
  - tools/chmin.hpp
  - tools/less_by_get.hpp
  - tools/safe_int.hpp
  - tools/ceil.hpp
  - tools/pow2.hpp
  - tools/assert_that.hpp
  isVerificationFile: true
  path: tests/zero_one_knapsack/solve_by_dp_maximizing_value.test.cpp
  requiredBy: []
  timestamp: '2024-03-24 19:16:21+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/zero_one_knapsack/solve_by_dp_maximizing_value.test.cpp
layout: document
redirect_from:
- /verify/tests/zero_one_knapsack/solve_by_dp_maximizing_value.test.cpp
- /verify/tests/zero_one_knapsack/solve_by_dp_maximizing_value.test.cpp.html
title: tests/zero_one_knapsack/solve_by_dp_maximizing_value.test.cpp
---
