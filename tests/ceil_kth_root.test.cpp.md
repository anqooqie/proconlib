---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: tools/assert_that.hpp
    title: Assertion macro
  - icon: ':question:'
    path: tools/ceil.hpp
    title: $\left\lceil \frac{x}{y} \right\rceil$
  - icon: ':heavy_check_mark:'
    path: tools/ceil_kth_root.hpp
    title: $\left\lceil x^\frac{1}{k} \right\rceil$
  - icon: ':question:'
    path: tools/ceil_sqrt.hpp
    title: $\left\lceil \sqrt{x} \right\rceil$
  - icon: ':question:'
    path: tools/monoid.hpp
    title: Typical monoids
  - icon: ':question:'
    path: tools/pow.hpp
    title: $b^n$ under a given monoid, and std::pow(b, n) extended for my library
  - icon: ':heavy_check_mark:'
    path: tools/safe_int.hpp
    title: $\mathbb{Z} \cup \{\infty, -\infty, \mathrm{NaN}\}$ and $\mathbb{Z}_{\geq
      0} \cup \{\infty, \mathrm{NaN}\}$
  - icon: ':question:'
    path: tools/square.hpp
    title: $x^2$ under a given monoid
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
  bundledCode: "#line 1 \"tests/ceil_kth_root.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\"\
    \n\n#include <iostream>\n#line 1 \"tools/assert_that.hpp\"\n\n\n\n#line 5 \"tools/assert_that.hpp\"\
    \n#include <cstdlib>\n\n#define assert_that(cond) do {\\\n  if (!(cond)) {\\\n\
    \    ::std::cerr << __FILE__ << ':' << __LINE__ << \": \" << __func__ << \": Assertion\
    \ `\" << #cond << \"' failed.\" << '\\n';\\\n    ::std::exit(EXIT_FAILURE);\\\n\
    \  }\\\n} while (false)\n\n\n#line 1 \"tools/ceil_kth_root.hpp\"\n\n\n\n#include\
    \ <cassert>\n#line 1 \"tools/ceil_sqrt.hpp\"\n\n\n\n#line 1 \"tools/ceil.hpp\"\
    \n\n\n\n#include <type_traits>\n#line 6 \"tools/ceil.hpp\"\n\nnamespace tools\
    \ {\n\n  template <typename M, typename N>\n  constexpr ::std::common_type_t<M,\
    \ N> ceil(const M lhs, const N rhs) {\n    assert(rhs != 0);\n    return lhs /\
    \ rhs + (((lhs > 0 && rhs > 0) || (lhs < 0 && rhs < 0)) && lhs % rhs);\n  }\n\
    }\n\n\n#line 6 \"tools/ceil_sqrt.hpp\"\n\nnamespace tools {\n\n  template <typename\
    \ T>\n  T ceil_sqrt(const T n) {\n    assert(n >= 0);\n\n    if (n == 0) return\
    \ 0;\n\n    T ok = 1;\n    T ng;\n    for (ng = 2; ng - 1 < tools::ceil(n, ng\
    \ - 1); ng *= 2);\n\n    while (ng - ok > 1) {\n      const T mid = ok + (ng -\
    \ ok) / 2;\n      if (mid - 1 < tools::ceil(n, mid - 1)) {\n        ok = mid;\n\
    \      } else {\n        ng = mid;\n      }\n    }\n\n    return ok;\n  }\n}\n\
    \n\n#line 1 \"tools/pow.hpp\"\n\n\n\n#line 6 \"tools/pow.hpp\"\n#include <cmath>\n\
    #line 1 \"tools/monoid.hpp\"\n\n\n\n#include <algorithm>\n#include <limits>\n\
    #include <numeric>\n\nnamespace tools {\n  namespace monoid {\n    template <typename\
    \ Type, Type E = ::std::numeric_limits<Type>::min()>\n    struct max {\n     \
    \ using T = Type;\n      static T op(const T lhs, const T rhs) {\n        return\
    \ ::std::max(lhs, rhs);\n      }\n      static T e() {\n        return E;\n  \
    \    }\n    };\n\n    template <typename Type, Type E = ::std::numeric_limits<Type>::max()>\n\
    \    struct min {\n      using T = Type;\n      static T op(const T lhs, const\
    \ T rhs) {\n        return ::std::min(lhs, rhs);\n      }\n      static T e()\
    \ {\n        return E;\n      }\n    };\n\n    template <typename Type>\n    struct\
    \ multiplies {\n      using T = Type;\n      static T op(const T lhs, const T\
    \ rhs) {\n        return lhs * rhs;\n      }\n      static T e() {\n        return\
    \ T(1);\n      }\n    };\n\n    template <typename Type>\n    struct gcd {\n \
    \     using T = Type;\n      static T op(const T lhs, const T rhs) {\n       \
    \ return ::std::gcd(lhs, rhs);\n      }\n      static T e() {\n        return\
    \ T(0);\n      }\n    };\n\n    template <typename Type, Type E>\n    struct update\
    \ {\n      using T = Type;\n      static T op(const T lhs, const T rhs) {\n  \
    \      return lhs == E ? rhs : lhs;\n      }\n      static T e() {\n        return\
    \ E;\n      }\n    };\n  }\n}\n\n\n#line 1 \"tools/square.hpp\"\n\n\n\n#line 5\
    \ \"tools/square.hpp\"\n\nnamespace tools {\n\n  template <typename M>\n  typename\
    \ M::T square(const typename M::T& x) {\n    return M::op(x, x);\n  }\n\n  template\
    \ <typename T>\n  T square(const T& x) {\n    return ::tools::square<::tools::monoid::multiplies<T>>(x);\n\
    \  }\n}\n\n\n#line 9 \"tools/pow.hpp\"\n\nnamespace tools {\n\n  template <typename\
    \ M, typename E>\n  ::std::enable_if_t<::std::is_integral_v<E>, typename M::T>\
    \ pow(const typename M::T& base, const E exponent) {\n    assert(exponent >= 0);\n\
    \    return exponent == 0\n      ? M::e()\n      : exponent % 2 == 0\n       \
    \ ? ::tools::square<M>(::tools::pow<M>(base, exponent / 2))\n        : M::op(::tools::pow<M>(base,\
    \ exponent - 1), base);\n  }\n\n  template <typename T, typename E>\n  ::std::enable_if_t<::std::is_integral_v<E>,\
    \ T> pow(const T& base, const E exponent) {\n    assert(exponent >= 0);\n    return\
    \ ::tools::pow<::tools::monoid::multiplies<T>>(base, exponent);\n  }\n\n  template\
    \ <typename T, typename E>\n  auto pow(const T base, const E exponent) -> ::std::enable_if_t<!::std::is_integral_v<E>,\
    \ decltype(::std::pow(base, exponent))> {\n    return ::std::pow(base, exponent);\n\
    \  }\n}\n\n\n#line 1 \"tools/safe_int.hpp\"\n\n\n\n#line 5 \"tools/safe_int.hpp\"\
    \n#include <cstddef>\n#line 8 \"tools/safe_int.hpp\"\n#include <array>\n#include\
    \ <optional>\n\nnamespace tools {\n  template <typename T, typename = void>\n\
    \  class safe_int;\n\n  template <typename T>\n  class safe_int<T, ::std::enable_if_t<::std::is_signed_v<T>>>\
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
    \    }\n\n    friend constexpr bool operator<(const ::tools::safe_int<T>& x, const\
    \ ::tools::safe_int<T>& y) {\n      constexpr auto table = ::std::array<::std::array<::std::optional<bool>,\
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
    \ y) {\n      return x > y || x == y;\n    }\n  };\n\n  template <typename T>\n\
    \  class safe_int<T, ::std::enable_if_t<::std::is_unsigned_v<T>>> {\n  private:\n\
    \    enum class type {\n      finite,\n      pos_inf,\n      nan\n    };\n   \
    \ typename ::tools::safe_int<T>::type m_type;\n    T m_value;\n\n    constexpr\
    \ safe_int(const typename ::tools::safe_int<T>::type type) :\n      m_type(type),\
    \ m_value(T()) {\n    }\n\n  public:\n    constexpr safe_int() :\n      m_type(::tools::safe_int<T>::type::finite),\
    \ m_value(T()) {\n    }\n    explicit constexpr safe_int(const T value) :\n  \
    \    m_type(::tools::safe_int<T>::type::finite), m_value(value) {\n    }\n   \
    \ constexpr safe_int(const ::tools::safe_int<T>& other) :\n      m_type(other.m_type),\
    \ m_value(other.m_value) {\n    }\n    ~safe_int() = default;\n    constexpr ::tools::safe_int<T>&\
    \ operator=(const ::tools::safe_int<T>& other) {\n      this->m_type = other.m_type;\n\
    \      this->m_value = other.m_value;\n      return *this;\n    }\n\n    static\
    \ constexpr ::tools::safe_int<T> infinity() {\n      return tools::safe_int<T>(::tools::safe_int<T>::type::pos_inf);\n\
    \    }\n    static constexpr ::tools::safe_int<T> nan() {\n      return tools::safe_int<T>(::tools::safe_int<T>::type::nan);\n\
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
    \    }\n\n    friend constexpr bool operator<(const ::tools::safe_int<T>& x, const\
    \ ::tools::safe_int<T>& y) {\n      constexpr auto table = ::std::array<::std::array<::std::optional<bool>,\
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
    \ y || x == y;\n    }\n  };\n}\n\n\n#line 9 \"tools/ceil_kth_root.hpp\"\n\nnamespace\
    \ tools {\n\n  template <typename T, typename U>\n  T ceil_kth_root(const T x,\
    \ const U k) {\n    assert(x >= 0);\n    assert(k >= 1);\n\n    if (x == 0) return\
    \ 0;\n    if (k == 1) return x;\n    if (k == 2) return ::tools::ceil_sqrt(x);\n\
    \    if (k == 3) {\n      T ok = 1;\n      T ng;\n      for (ng = 2; (ng - 1)\
    \ * (ng - 1) < ::tools::ceil(x, ng - 1); ng *= 2);\n\n      while (ng - ok > 1)\
    \ {\n        const T mid = ok + (ng - ok) / 2;\n        if ((mid - 1) * (mid -\
    \ 1) < ::tools::ceil(x, mid - 1)) {\n          ok = mid;\n        } else {\n \
    \         ng = mid;\n        }\n      }\n      return ok;\n    }\n\n    T ok =\
    \ 1;\n    T ng;\n    for (ng = 2; ::tools::pow(::tools::safe_int<T>(ng - 1), k)\
    \ < ::tools::safe_int<T>(x); ng *= 2);\n\n    while (ng - ok > 1) {\n      const\
    \ T mid = ok + (ng - ok) / 2;\n      if (::tools::pow(::tools::safe_int<T>(mid\
    \ - 1), k) < ::tools::safe_int<T>(x)) {\n        ok = mid;\n      } else {\n \
    \       ng = mid;\n      }\n    }\n\n    return ok;\n  }\n}\n\n\n#line 6 \"tests/ceil_kth_root.test.cpp\"\
    \n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  assert_that(tools::ceil_kth_root(0, 1) == 0);\n  assert_that(tools::ceil_kth_root(1,\
    \ 1) == 1);\n  assert_that(tools::ceil_kth_root(2, 1) == 2);\n  assert_that(tools::ceil_kth_root(3,\
    \ 1) == 3);\n  assert_that(tools::ceil_kth_root(9223372036854775807, 1) == 9223372036854775807);\n\
    \n  assert_that(tools::ceil_kth_root(0, 2) == 0);\n  assert_that(tools::ceil_kth_root(1,\
    \ 2) == 1);\n  assert_that(tools::ceil_kth_root(2, 2) == 2);\n  assert_that(tools::ceil_kth_root(3,\
    \ 2) == 2);\n  assert_that(tools::ceil_kth_root(4, 2) == 2);\n  assert_that(tools::ceil_kth_root(5,\
    \ 2) == 3);\n  assert_that(tools::ceil_kth_root(8, 2) == 3);\n  assert_that(tools::ceil_kth_root(9,\
    \ 2) == 3);\n  assert_that(tools::ceil_kth_root(10, 2) == 4);\n  assert_that(tools::ceil_kth_root(9223372030926249000,\
    \ 2) == 3037000499);\n  assert_that(tools::ceil_kth_root(9223372030926249001,\
    \ 2) == 3037000499);\n  assert_that(tools::ceil_kth_root(9223372030926249002,\
    \ 2) == 3037000500);\n  assert_that(tools::ceil_kth_root(9223372036854775807,\
    \ 2) == 3037000500);\n\n  assert_that(tools::ceil_kth_root(0, 3) == 0);\n  assert_that(tools::ceil_kth_root(1,\
    \ 3) == 1);\n  assert_that(tools::ceil_kth_root(2, 3) == 2);\n  assert_that(tools::ceil_kth_root(7,\
    \ 3) == 2);\n  assert_that(tools::ceil_kth_root(8, 3) == 2);\n  assert_that(tools::ceil_kth_root(9,\
    \ 3) == 3);\n  assert_that(tools::ceil_kth_root(26, 3) == 3);\n  assert_that(tools::ceil_kth_root(27,\
    \ 3) == 3);\n  assert_that(tools::ceil_kth_root(28, 3) == 4);\n  assert_that(tools::ceil_kth_root(9223358842721533950,\
    \ 3) == 2097151);\n  assert_that(tools::ceil_kth_root(9223358842721533951, 3)\
    \ == 2097151);\n  assert_that(tools::ceil_kth_root(9223358842721533952, 3) ==\
    \ 2097152);\n  assert_that(tools::ceil_kth_root(9223372036854775807, 3) == 2097152);\n\
    \n  assert_that(tools::ceil_kth_root(0, 4) == 0);\n  assert_that(tools::ceil_kth_root(1,\
    \ 4) == 1);\n  assert_that(tools::ceil_kth_root(2, 4) == 2);\n  assert_that(tools::ceil_kth_root(15,\
    \ 4) == 2);\n  assert_that(tools::ceil_kth_root(16, 4) == 2);\n  assert_that(tools::ceil_kth_root(17,\
    \ 4) == 3);\n  assert_that(tools::ceil_kth_root(80, 4) == 3);\n  assert_that(tools::ceil_kth_root(81,\
    \ 4) == 3);\n  assert_that(tools::ceil_kth_root(82, 4) == 4);\n  assert_that(tools::ceil_kth_root(9222710978872688895,\
    \ 4) == 55108);\n  assert_that(tools::ceil_kth_root(9222710978872688896, 4) ==\
    \ 55108);\n  assert_that(tools::ceil_kth_root(9222710978872688897, 4) == 55109);\n\
    \  assert_that(tools::ceil_kth_root(9223372036854775807, 4) == 55109);\n\n  assert_that(tools::ceil_kth_root(0,\
    \ 5) == 0);\n  assert_that(tools::ceil_kth_root(1, 5) == 1);\n  assert_that(tools::ceil_kth_root(2,\
    \ 5) == 2);\n  assert_that(tools::ceil_kth_root(31, 5) == 2);\n  assert_that(tools::ceil_kth_root(32,\
    \ 5) == 2);\n  assert_that(tools::ceil_kth_root(33, 5) == 3);\n  assert_that(tools::ceil_kth_root(242,\
    \ 5) == 3);\n  assert_that(tools::ceil_kth_root(243, 5) == 3);\n  assert_that(tools::ceil_kth_root(244,\
    \ 5) == 4);\n  assert_that(tools::ceil_kth_root(9220586390859808767, 5) == 6208);\n\
    \  assert_that(tools::ceil_kth_root(9220586390859808768, 5) == 6208);\n  assert_that(tools::ceil_kth_root(9220586390859808769,\
    \ 5) == 6209);\n  assert_that(tools::ceil_kth_root(9223372036854775807, 5) ==\
    \ 6209);\n\n  assert_that(tools::ceil_kth_root(0, 6) == 0);\n  assert_that(tools::ceil_kth_root(1,\
    \ 6) == 1);\n  assert_that(tools::ceil_kth_root(2, 6) == 2);\n  assert_that(tools::ceil_kth_root(63,\
    \ 6) == 2);\n  assert_that(tools::ceil_kth_root(64, 6) == 2);\n  assert_that(tools::ceil_kth_root(65,\
    \ 6) == 3);\n  assert_that(tools::ceil_kth_root(728, 6) == 3);\n  assert_that(tools::ceil_kth_root(729,\
    \ 6) == 3);\n  assert_that(tools::ceil_kth_root(730, 6) == 4);\n  assert_that(tools::ceil_kth_root(9217462324974321663,\
    \ 6) == 1448);\n  assert_that(tools::ceil_kth_root(9217462324974321664, 6) ==\
    \ 1448);\n  assert_that(tools::ceil_kth_root(9217462324974321665, 6) == 1449);\n\
    \  assert_that(tools::ceil_kth_root(9223372036854775807, 6) == 1449);\n\n  assert_that(tools::ceil_kth_root(0,\
    \ 39) == 0);\n  assert_that(tools::ceil_kth_root(1, 39) == 1);\n  assert_that(tools::ceil_kth_root(2,\
    \ 39) == 2);\n  assert_that(tools::ceil_kth_root(549755813887, 39) == 2);\n  assert_that(tools::ceil_kth_root(549755813888,\
    \ 39) == 2);\n  assert_that(tools::ceil_kth_root(549755813889, 39) == 3);\n  assert_that(tools::ceil_kth_root(4052555153018976266,\
    \ 39) == 3);\n  assert_that(tools::ceil_kth_root(4052555153018976267, 39) == 3);\n\
    \  assert_that(tools::ceil_kth_root(4052555153018976268, 39) == 4);\n  assert_that(tools::ceil_kth_root(9223372036854775807,\
    \ 39) == 4);\n\n  assert_that(tools::ceil_kth_root(0, 62) == 0);\n  assert_that(tools::ceil_kth_root(1,\
    \ 62) == 1);\n  assert_that(tools::ceil_kth_root(2, 62) == 2);\n  assert_that(tools::ceil_kth_root(4611686018427387903,\
    \ 62) == 2);\n  assert_that(tools::ceil_kth_root(4611686018427387904, 62) == 2);\n\
    \  assert_that(tools::ceil_kth_root(4611686018427387905, 62) == 3);\n  assert_that(tools::ceil_kth_root(9223372036854775807,\
    \ 62) == 3);\n\n  assert_that(tools::ceil_kth_root(0, 63) == 0);\n  assert_that(tools::ceil_kth_root(1,\
    \ 63) == 1);\n  assert_that(tools::ceil_kth_root(2, 63) == 2);\n  assert_that(tools::ceil_kth_root(9223372036854775807,\
    \ 63) == 2);\n\n  assert_that(tools::ceil_kth_root(0, 64) == 0);\n  assert_that(tools::ceil_kth_root(1,\
    \ 64) == 1);\n  assert_that(tools::ceil_kth_root(2, 64) == 2);\n  assert_that(tools::ceil_kth_root(9223372036854775807,\
    \ 64) == 2);\n\n  std::cout << \"Hello World\" << '\\n';\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\"\n\n\
    #include <iostream>\n#include \"tools/assert_that.hpp\"\n#include \"tools/ceil_kth_root.hpp\"\
    \n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  assert_that(tools::ceil_kth_root(0, 1) == 0);\n  assert_that(tools::ceil_kth_root(1,\
    \ 1) == 1);\n  assert_that(tools::ceil_kth_root(2, 1) == 2);\n  assert_that(tools::ceil_kth_root(3,\
    \ 1) == 3);\n  assert_that(tools::ceil_kth_root(9223372036854775807, 1) == 9223372036854775807);\n\
    \n  assert_that(tools::ceil_kth_root(0, 2) == 0);\n  assert_that(tools::ceil_kth_root(1,\
    \ 2) == 1);\n  assert_that(tools::ceil_kth_root(2, 2) == 2);\n  assert_that(tools::ceil_kth_root(3,\
    \ 2) == 2);\n  assert_that(tools::ceil_kth_root(4, 2) == 2);\n  assert_that(tools::ceil_kth_root(5,\
    \ 2) == 3);\n  assert_that(tools::ceil_kth_root(8, 2) == 3);\n  assert_that(tools::ceil_kth_root(9,\
    \ 2) == 3);\n  assert_that(tools::ceil_kth_root(10, 2) == 4);\n  assert_that(tools::ceil_kth_root(9223372030926249000,\
    \ 2) == 3037000499);\n  assert_that(tools::ceil_kth_root(9223372030926249001,\
    \ 2) == 3037000499);\n  assert_that(tools::ceil_kth_root(9223372030926249002,\
    \ 2) == 3037000500);\n  assert_that(tools::ceil_kth_root(9223372036854775807,\
    \ 2) == 3037000500);\n\n  assert_that(tools::ceil_kth_root(0, 3) == 0);\n  assert_that(tools::ceil_kth_root(1,\
    \ 3) == 1);\n  assert_that(tools::ceil_kth_root(2, 3) == 2);\n  assert_that(tools::ceil_kth_root(7,\
    \ 3) == 2);\n  assert_that(tools::ceil_kth_root(8, 3) == 2);\n  assert_that(tools::ceil_kth_root(9,\
    \ 3) == 3);\n  assert_that(tools::ceil_kth_root(26, 3) == 3);\n  assert_that(tools::ceil_kth_root(27,\
    \ 3) == 3);\n  assert_that(tools::ceil_kth_root(28, 3) == 4);\n  assert_that(tools::ceil_kth_root(9223358842721533950,\
    \ 3) == 2097151);\n  assert_that(tools::ceil_kth_root(9223358842721533951, 3)\
    \ == 2097151);\n  assert_that(tools::ceil_kth_root(9223358842721533952, 3) ==\
    \ 2097152);\n  assert_that(tools::ceil_kth_root(9223372036854775807, 3) == 2097152);\n\
    \n  assert_that(tools::ceil_kth_root(0, 4) == 0);\n  assert_that(tools::ceil_kth_root(1,\
    \ 4) == 1);\n  assert_that(tools::ceil_kth_root(2, 4) == 2);\n  assert_that(tools::ceil_kth_root(15,\
    \ 4) == 2);\n  assert_that(tools::ceil_kth_root(16, 4) == 2);\n  assert_that(tools::ceil_kth_root(17,\
    \ 4) == 3);\n  assert_that(tools::ceil_kth_root(80, 4) == 3);\n  assert_that(tools::ceil_kth_root(81,\
    \ 4) == 3);\n  assert_that(tools::ceil_kth_root(82, 4) == 4);\n  assert_that(tools::ceil_kth_root(9222710978872688895,\
    \ 4) == 55108);\n  assert_that(tools::ceil_kth_root(9222710978872688896, 4) ==\
    \ 55108);\n  assert_that(tools::ceil_kth_root(9222710978872688897, 4) == 55109);\n\
    \  assert_that(tools::ceil_kth_root(9223372036854775807, 4) == 55109);\n\n  assert_that(tools::ceil_kth_root(0,\
    \ 5) == 0);\n  assert_that(tools::ceil_kth_root(1, 5) == 1);\n  assert_that(tools::ceil_kth_root(2,\
    \ 5) == 2);\n  assert_that(tools::ceil_kth_root(31, 5) == 2);\n  assert_that(tools::ceil_kth_root(32,\
    \ 5) == 2);\n  assert_that(tools::ceil_kth_root(33, 5) == 3);\n  assert_that(tools::ceil_kth_root(242,\
    \ 5) == 3);\n  assert_that(tools::ceil_kth_root(243, 5) == 3);\n  assert_that(tools::ceil_kth_root(244,\
    \ 5) == 4);\n  assert_that(tools::ceil_kth_root(9220586390859808767, 5) == 6208);\n\
    \  assert_that(tools::ceil_kth_root(9220586390859808768, 5) == 6208);\n  assert_that(tools::ceil_kth_root(9220586390859808769,\
    \ 5) == 6209);\n  assert_that(tools::ceil_kth_root(9223372036854775807, 5) ==\
    \ 6209);\n\n  assert_that(tools::ceil_kth_root(0, 6) == 0);\n  assert_that(tools::ceil_kth_root(1,\
    \ 6) == 1);\n  assert_that(tools::ceil_kth_root(2, 6) == 2);\n  assert_that(tools::ceil_kth_root(63,\
    \ 6) == 2);\n  assert_that(tools::ceil_kth_root(64, 6) == 2);\n  assert_that(tools::ceil_kth_root(65,\
    \ 6) == 3);\n  assert_that(tools::ceil_kth_root(728, 6) == 3);\n  assert_that(tools::ceil_kth_root(729,\
    \ 6) == 3);\n  assert_that(tools::ceil_kth_root(730, 6) == 4);\n  assert_that(tools::ceil_kth_root(9217462324974321663,\
    \ 6) == 1448);\n  assert_that(tools::ceil_kth_root(9217462324974321664, 6) ==\
    \ 1448);\n  assert_that(tools::ceil_kth_root(9217462324974321665, 6) == 1449);\n\
    \  assert_that(tools::ceil_kth_root(9223372036854775807, 6) == 1449);\n\n  assert_that(tools::ceil_kth_root(0,\
    \ 39) == 0);\n  assert_that(tools::ceil_kth_root(1, 39) == 1);\n  assert_that(tools::ceil_kth_root(2,\
    \ 39) == 2);\n  assert_that(tools::ceil_kth_root(549755813887, 39) == 2);\n  assert_that(tools::ceil_kth_root(549755813888,\
    \ 39) == 2);\n  assert_that(tools::ceil_kth_root(549755813889, 39) == 3);\n  assert_that(tools::ceil_kth_root(4052555153018976266,\
    \ 39) == 3);\n  assert_that(tools::ceil_kth_root(4052555153018976267, 39) == 3);\n\
    \  assert_that(tools::ceil_kth_root(4052555153018976268, 39) == 4);\n  assert_that(tools::ceil_kth_root(9223372036854775807,\
    \ 39) == 4);\n\n  assert_that(tools::ceil_kth_root(0, 62) == 0);\n  assert_that(tools::ceil_kth_root(1,\
    \ 62) == 1);\n  assert_that(tools::ceil_kth_root(2, 62) == 2);\n  assert_that(tools::ceil_kth_root(4611686018427387903,\
    \ 62) == 2);\n  assert_that(tools::ceil_kth_root(4611686018427387904, 62) == 2);\n\
    \  assert_that(tools::ceil_kth_root(4611686018427387905, 62) == 3);\n  assert_that(tools::ceil_kth_root(9223372036854775807,\
    \ 62) == 3);\n\n  assert_that(tools::ceil_kth_root(0, 63) == 0);\n  assert_that(tools::ceil_kth_root(1,\
    \ 63) == 1);\n  assert_that(tools::ceil_kth_root(2, 63) == 2);\n  assert_that(tools::ceil_kth_root(9223372036854775807,\
    \ 63) == 2);\n\n  assert_that(tools::ceil_kth_root(0, 64) == 0);\n  assert_that(tools::ceil_kth_root(1,\
    \ 64) == 1);\n  assert_that(tools::ceil_kth_root(2, 64) == 2);\n  assert_that(tools::ceil_kth_root(9223372036854775807,\
    \ 64) == 2);\n\n  std::cout << \"Hello World\" << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - tools/assert_that.hpp
  - tools/ceil_kth_root.hpp
  - tools/ceil_sqrt.hpp
  - tools/ceil.hpp
  - tools/pow.hpp
  - tools/monoid.hpp
  - tools/square.hpp
  - tools/safe_int.hpp
  isVerificationFile: true
  path: tests/ceil_kth_root.test.cpp
  requiredBy: []
  timestamp: '2022-11-03 23:21:16+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/ceil_kth_root.test.cpp
layout: document
redirect_from:
- /verify/tests/ceil_kth_root.test.cpp
- /verify/tests/ceil_kth_root.test.cpp.html
title: tests/ceil_kth_root.test.cpp
---
