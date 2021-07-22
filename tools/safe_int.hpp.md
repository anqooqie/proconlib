---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: tests/safe_int.test.cpp
    title: tests/safe_int.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/safe_int.hpp\"\n\n\n\n#include <type_traits>\n#include\
    \ <cstddef>\n#include <cassert>\n#include <limits>\n#include <array>\n#include\
    \ <optional>\n\nnamespace tools {\n  template <typename T, typename ::std::enable_if<::std::is_signed_v<T>,\
    \ ::std::nullptr_t>::type = nullptr>\n  class safe_int {\n  private:\n    enum\
    \ class type {\n      finite,\n      pos_inf,\n      neg_inf,\n      nan\n   \
    \ };\n    typename ::tools::safe_int<T>::type m_type;\n    T m_value;\n\n    constexpr\
    \ safe_int(const type type) :\n      m_type(type), m_value(T()) {\n    }\n\n \
    \   static constexpr ::tools::safe_int<T> pos_inf = tools::safe_int<T>(::tools::safe_int<T>::type::pos_inf);\n\
    \    static constexpr ::tools::safe_int<T> neg_inf = tools::safe_int<T>(::tools::safe_int<T>::type::neg_inf);\n\
    \n  public:\n    constexpr safe_int() :\n      m_type(::tools::safe_int<T>::type::finite),\
    \ m_value(T()) {\n    }\n    explicit constexpr safe_int(const T value) :\n  \
    \    m_type(::tools::safe_int<T>::type::finite), m_value(value) {\n    }\n   \
    \ constexpr safe_int(const ::tools::safe_int<T>& other) :\n      m_type(other.m_type),\
    \ m_value(other.m_value) {\n    }\n    ~safe_int() = default;\n    constexpr ::tools::safe_int<T>&\
    \ operator=(const ::tools::safe_int<T>& other) {\n      this->m_type = other.m_type;\n\
    \      this->m_value = other.m_value;\n    }\n\n    static constexpr ::tools::safe_int<T>\
    \ infinity = tools::safe_int<T>(::tools::safe_int<T>::type::pos_inf);\n    static\
    \ constexpr ::tools::safe_int<T> nan = tools::safe_int<T>(::tools::safe_int<T>::type::nan);\n\
    \n  private:\n    static constexpr int f1(const ::tools::safe_int<T>& n) {\n \
    \     switch (n.m_type) {\n      case ::tools::safe_int<T>::type::neg_inf:\n \
    \       return 0;\n      case ::tools::safe_int<T>::type::finite:\n        return\
    \ 1;\n      case ::tools::safe_int<T>::type::pos_inf:\n        return 2;\n   \
    \   default: // nan\n        return 3;\n      }\n    };\n    static constexpr\
    \ ::tools::safe_int<T> g1(int i) {\n      return ::std::array<::tools::safe_int<T>,\
    \ 4>({\n        ::tools::safe_int<T>::neg_inf,\n        ::tools::safe_int<T>(),\n\
    \        ::tools::safe_int<T>::pos_inf,\n        ::tools::safe_int<T>::nan\n \
    \     })[i];\n    }\n    static constexpr int f2(const ::tools::safe_int<T>& n)\
    \ {\n      switch (n.m_type) {\n      case ::tools::safe_int<T>::type::neg_inf:\n\
    \        return 0;\n      case ::tools::safe_int<T>::type::finite:\n        if\
    \ (n.m_value < 0) {\n          return 1;\n        } else if (n.m_value == 0) {\n\
    \          return 2;\n        } else {\n          return 3;\n        }\n     \
    \ case ::tools::safe_int<T>::type::pos_inf:\n        return 4;\n      default:\
    \ // nan\n        return 5;\n      }\n    };\n    static constexpr ::tools::safe_int<T>\
    \ g2(int i) {\n      return ::std::array<::tools::safe_int<T>, 6>({\n        ::tools::safe_int<T>::neg_inf,\n\
    \        ::tools::safe_int<T>(),\n        ::tools::safe_int<T>(0),\n        ::tools::safe_int<T>(),\n\
    \        ::tools::safe_int<T>::pos_inf,\n        ::tools::safe_int<T>::nan\n \
    \     })[i];\n    }\n\n  public:\n    constexpr bool is_finite() const {\n   \
    \   return this->m_type == ::tools::safe_int<T>::type::finite;\n    }\n\n    constexpr\
    \ T val() const {\n      assert(this->is_finite());\n      return this->m_value;\n\
    \    }\n\n    friend constexpr bool operator==(const ::tools::safe_int<T>& x,\
    \ const ::tools::safe_int<T>& y) {\n      if (x.is_finite() && y.is_finite())\
    \ {\n        return x.m_value == y.m_value;\n      } else if (!x.is_finite() &&\
    \ !y.is_finite()) {\n        return x.m_type == y.m_type;\n      } else {\n  \
    \      return false;\n      }\n    }\n    friend constexpr bool operator!=(const\
    \ ::tools::safe_int<T>& x, const ::tools::safe_int<T>& y) {\n      return !(x\
    \ == y);\n    }\n\n    constexpr ::tools::safe_int<T> operator+() const {\n  \
    \    return *this;\n    }\n    constexpr ::tools::safe_int<T> operator-() const\
    \ {\n      switch (this->m_type) {\n      case ::tools::safe_int<T>::type::finite:\n\
    \        return this->m_value == ::std::numeric_limits<T>::min()\n          ?\
    \ ::tools::safe_int<T>::nan\n          : ::tools::safe_int<T>(-this->m_value);\n\
    \      case ::tools::safe_int<T>::type::pos_inf:\n        return ::tools::safe_int<T>::neg_inf;\n\
    \      case ::tools::safe_int<T>::type::neg_inf:\n        return ::tools::safe_int<T>::pos_inf;\n\
    \      default: // nan\n        return ::tools::safe_int<T>::nan;\n      }\n \
    \   }\n\n    friend constexpr ::tools::safe_int<T> operator+(const ::tools::safe_int<T>&\
    \ x, const ::tools::safe_int<T>& y) {\n      const int NI = 0;\n      const int\
    \ F = 1;\n      const int PI = 2;\n      const int U = 3;\n      const int r =\
    \ ::std::array<::std::array<int, 4>, 4>({{\n        {NI, NI,  U,  U},\n      \
    \  {NI,  F, PI,  U},\n        { U, PI, PI,  U},\n        { U,  U,  U,  U}\n  \
    \    }})[f1(x)][f1(y)];\n      if (r == F) {\n        if (y.m_value > 0 && x.m_value\
    \ > ::std::numeric_limits<T>::max() - y.m_value) return g1(U);\n        if (y.m_value\
    \ < 0 && x.m_value < ::std::numeric_limits<T>::min() - y.m_value) return g1(U);\n\
    \        return ::tools::safe_int<T>(x.m_value + y.m_value);\n      } else {\n\
    \        return g1(r);\n      }\n    }\n    friend constexpr ::tools::safe_int<T>\
    \ operator+(const ::tools::safe_int<T>& x, const T& y) {\n      return x + tools::safe_int<T>(y);\n\
    \    }\n    friend constexpr ::tools::safe_int<T> operator+(const T& x, const\
    \ ::tools::safe_int<T>& y) {\n      return tools::safe_int<T>(x) + y;\n    }\n\
    \n    friend constexpr ::tools::safe_int<T> operator-(const ::tools::safe_int<T>&\
    \ x, const ::tools::safe_int<T>& y) {\n      const int NI = 0;\n      const int\
    \ F = 1;\n      const int PI = 2;\n      const int U = 3;\n      const int r =\
    \ ::std::array<::std::array<int, 4>, 4>({{\n        { U, NI, NI,  U},\n      \
    \  {PI,  F, NI,  U},\n        {PI, PI,  U,  U},\n        { U,  U,  U,  U}\n  \
    \    }})[f1(x)][f1(y)];\n      if (r == F) {\n        if (y.m_value < 0 && x.m_value\
    \ > ::std::numeric_limits<T>::max() + y.m_value) return g1(U);\n        if (y.m_value\
    \ > 0 && x.m_value < ::std::numeric_limits<T>::min() + y.m_value) return g1(U);\n\
    \        return ::tools::safe_int<T>(x.m_value - y.m_value);\n      } else {\n\
    \        return g1(r);\n      }\n    }\n    friend constexpr ::tools::safe_int<T>\
    \ operator-(const ::tools::safe_int<T>& x, const T& y) {\n      return x - tools::safe_int<T>(y);\n\
    \    }\n    friend constexpr ::tools::safe_int<T> operator-(const T& x, const\
    \ ::tools::safe_int<T>& y) {\n      return tools::safe_int<T>(x) - y;\n    }\n\
    \n    friend constexpr ::tools::safe_int<T> operator*(const ::tools::safe_int<T>&\
    \ x, const ::tools::safe_int<T>& y) {\n      const int NI = 0;\n      const int\
    \ NF = 1;\n      const int Z = 2;\n      const int PF = 3;\n      const int PI\
    \ = 4;\n      const int U = 5;\n      const int r = ::std::array<::std::array<int,\
    \ 6>, 6>({{\n        {PI, PI,  U, NI, NI,  U},\n        {PI, PF,  Z, NF, NI, \
    \ U},\n        { U,  Z,  Z,  Z,  U,  U},\n        {NI, NF,  Z, PF, PI,  U},\n\
    \        {NI, NI,  U, PI, PI,  U},\n        { U,  U,  U,  U,  U,  U}\n      }})[f2(x)][f2(y)];\n\
    \      if (r == NF || r == PF) {\n        if (x.m_value > 0) {\n          if (y.m_value\
    \ > 0) {\n            if (x.m_value > ::std::numeric_limits<T>::max() / y.m_value)\
    \ {\n              return g2(U);\n            }\n          } else {\n        \
    \    if (y.m_value < ::std::numeric_limits<T>::min() / x.m_value) {\n        \
    \      return g2(U);\n            }\n          }\n        } else {\n         \
    \ if (y.m_value > 0) {\n            if (x.m_value < ::std::numeric_limits<T>::min()\
    \ / y.m_value) {\n              return g2(U);\n            }\n          } else\
    \ {\n            if (x.m_value != 0 && y.m_value < ::std::numeric_limits<T>::max()\
    \ / x.m_value) {\n              return g2(U);\n            }\n          }\n  \
    \      }\n        return ::tools::safe_int<T>(x.m_value * y.m_value);\n      }\
    \ else {\n        return g2(r);\n      }\n    }\n    friend constexpr ::tools::safe_int<T>\
    \ operator*(const ::tools::safe_int<T>& x, const T& y) {\n      return x * tools::safe_int<T>(y);\n\
    \    }\n    friend constexpr ::tools::safe_int<T> operator*(const T& x, const\
    \ ::tools::safe_int<T>& y) {\n      return tools::safe_int<T>(x) * y;\n    }\n\
    \n    friend constexpr ::tools::safe_int<T> operator/(const ::tools::safe_int<T>&\
    \ x, const ::tools::safe_int<T>& y) {\n      const int NI = 0;\n      const int\
    \ NF = 1;\n      const int Z = 2;\n      const int PF = 3;\n      const int PI\
    \ = 4;\n      const int U = 5;\n      const int r = ::std::array<::std::array<int,\
    \ 6>, 6>({{\n        { U, PI,  U, NI,  U,  U},\n        { Z, PF,  U, NF,  Z, \
    \ U},\n        { Z,  Z,  U,  Z,  Z,  U},\n        { Z, NF,  U, PF,  Z,  U},\n\
    \        { U, NI,  U, PI,  U,  U},\n        { U,  U,  U,  U,  U,  U}\n      }})[f2(x)][f2(y)];\n\
    \      if (r == NF || r == PF) {\n        if (x.m_value == ::std::numeric_limits<T>::min()\
    \ && y.m_value == -1) return g2(U);\n        return ::tools::safe_int<T>(x.m_value\
    \ / y.m_value);\n      } else {\n        return g2(r);\n      }\n    }\n    friend\
    \ constexpr ::tools::safe_int<T> operator/(const ::tools::safe_int<T>& x, const\
    \ T& y) {\n      return x / tools::safe_int<T>(y);\n    }\n    friend constexpr\
    \ ::tools::safe_int<T> operator/(const T& x, const ::tools::safe_int<T>& y) {\n\
    \      return tools::safe_int<T>(x) / y;\n    }\n\n    friend constexpr ::tools::safe_int<T>\
    \ operator%(const ::tools::safe_int<T>& x, const ::tools::safe_int<T>& y) {\n\
    \      const int NF = 1;\n      const int Z = 2;\n      const int PF = 3;\n  \
    \    const int U = 5;\n      const int r = ::std::array<::std::array<int, 6>,\
    \ 6>({{\n        { U,  U,  U,  U,  U,  U},\n        { U, NF,  U, NF,  U,  U},\n\
    \        { U,  Z,  U,  Z,  U,  U},\n        { U, PF,  U, PF,  U,  U},\n      \
    \  { U,  U,  U,  U,  U,  U},\n        { U,  U,  U,  U,  U,  U}\n      }})[f2(x)][f2(y)];\n\
    \      if (r == NF || r == PF) {\n        if (x.m_value == ::std::numeric_limits<T>::min()\
    \ && y.m_value == -1) return g2(U);\n        return ::tools::safe_int<T>(x.m_value\
    \ % y.m_value);\n      } else {\n        return g2(r);\n      }\n    }\n    friend\
    \ constexpr ::tools::safe_int<T> operator%(const ::tools::safe_int<T>& x, const\
    \ T& y) {\n      return x % tools::safe_int<T>(y);\n    }\n    friend constexpr\
    \ ::tools::safe_int<T> operator%(const T& x, const ::tools::safe_int<T>& y) {\n\
    \      return tools::safe_int<T>(x) % y;\n    }\n\n    constexpr ::tools::safe_int<T>&\
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
    \ ::tools::safe_int<T>& y) {\n      const ::std::optional<bool> FALSE = ::std::make_optional(false);\n\
    \      const ::std::optional<bool> TRUE = ::std::make_optional(true);\n      const\
    \ ::std::optional<bool> UNKNOWN = ::std::nullopt;\n      const ::std::optional<bool>\
    \ r = ::std::array<::std::array<::std::optional<bool>, 4>, 4>({{\n        {FALSE,\
    \    TRUE,  TRUE, FALSE},\n        {FALSE, UNKNOWN,  TRUE, FALSE},\n        {FALSE,\
    \   FALSE, FALSE, FALSE},\n        {FALSE,   FALSE, FALSE, FALSE}\n      }})[f1(x)][f1(y)];\n\
    \      if (!r) {\n        return x.m_value < y.m_value;\n      } else {\n    \
    \    return *r;\n      }\n    }\n    friend constexpr bool operator>(const ::tools::safe_int<T>&\
    \ x, const ::tools::safe_int<T>& y) {\n      const ::std::optional<bool> FALSE\
    \ = ::std::make_optional(false);\n      const ::std::optional<bool> TRUE = ::std::make_optional(true);\n\
    \      const ::std::optional<bool> UNKNOWN = ::std::nullopt;\n      const ::std::optional<bool>\
    \ r = ::std::array<::std::array<::std::optional<bool>, 4>, 4>({{\n        {FALSE,\
    \   FALSE, FALSE, FALSE},\n        { TRUE, UNKNOWN, FALSE, FALSE},\n        {\
    \ TRUE,    TRUE, FALSE, FALSE},\n        {FALSE,   FALSE, FALSE, FALSE}\n    \
    \  }})[f1(x)][f1(y)];\n      if (!r) {\n        return x.m_value > y.m_value;\n\
    \      } else {\n        return *r;\n      }\n    }\n    friend constexpr bool\
    \ operator<=(const ::tools::safe_int<T>& x, const ::tools::safe_int<T>& y) {\n\
    \      return x < y || x == y;\n    }\n    friend constexpr bool operator>=(const\
    \ ::tools::safe_int<T>& x, const ::tools::safe_int<T>& y) {\n      return x >\
    \ y || x == y;\n    }\n  };\n}\n\n\n"
  code: "#ifndef TOOLS_SAFE_INT_HPP\n#define TOOLS_SAFE_INT_HPP\n\n#include <type_traits>\n\
    #include <cstddef>\n#include <cassert>\n#include <limits>\n#include <array>\n\
    #include <optional>\n\nnamespace tools {\n  template <typename T, typename ::std::enable_if<::std::is_signed_v<T>,\
    \ ::std::nullptr_t>::type = nullptr>\n  class safe_int {\n  private:\n    enum\
    \ class type {\n      finite,\n      pos_inf,\n      neg_inf,\n      nan\n   \
    \ };\n    typename ::tools::safe_int<T>::type m_type;\n    T m_value;\n\n    constexpr\
    \ safe_int(const type type) :\n      m_type(type), m_value(T()) {\n    }\n\n \
    \   static constexpr ::tools::safe_int<T> pos_inf = tools::safe_int<T>(::tools::safe_int<T>::type::pos_inf);\n\
    \    static constexpr ::tools::safe_int<T> neg_inf = tools::safe_int<T>(::tools::safe_int<T>::type::neg_inf);\n\
    \n  public:\n    constexpr safe_int() :\n      m_type(::tools::safe_int<T>::type::finite),\
    \ m_value(T()) {\n    }\n    explicit constexpr safe_int(const T value) :\n  \
    \    m_type(::tools::safe_int<T>::type::finite), m_value(value) {\n    }\n   \
    \ constexpr safe_int(const ::tools::safe_int<T>& other) :\n      m_type(other.m_type),\
    \ m_value(other.m_value) {\n    }\n    ~safe_int() = default;\n    constexpr ::tools::safe_int<T>&\
    \ operator=(const ::tools::safe_int<T>& other) {\n      this->m_type = other.m_type;\n\
    \      this->m_value = other.m_value;\n    }\n\n    static constexpr ::tools::safe_int<T>\
    \ infinity = tools::safe_int<T>(::tools::safe_int<T>::type::pos_inf);\n    static\
    \ constexpr ::tools::safe_int<T> nan = tools::safe_int<T>(::tools::safe_int<T>::type::nan);\n\
    \n  private:\n    static constexpr int f1(const ::tools::safe_int<T>& n) {\n \
    \     switch (n.m_type) {\n      case ::tools::safe_int<T>::type::neg_inf:\n \
    \       return 0;\n      case ::tools::safe_int<T>::type::finite:\n        return\
    \ 1;\n      case ::tools::safe_int<T>::type::pos_inf:\n        return 2;\n   \
    \   default: // nan\n        return 3;\n      }\n    };\n    static constexpr\
    \ ::tools::safe_int<T> g1(int i) {\n      return ::std::array<::tools::safe_int<T>,\
    \ 4>({\n        ::tools::safe_int<T>::neg_inf,\n        ::tools::safe_int<T>(),\n\
    \        ::tools::safe_int<T>::pos_inf,\n        ::tools::safe_int<T>::nan\n \
    \     })[i];\n    }\n    static constexpr int f2(const ::tools::safe_int<T>& n)\
    \ {\n      switch (n.m_type) {\n      case ::tools::safe_int<T>::type::neg_inf:\n\
    \        return 0;\n      case ::tools::safe_int<T>::type::finite:\n        if\
    \ (n.m_value < 0) {\n          return 1;\n        } else if (n.m_value == 0) {\n\
    \          return 2;\n        } else {\n          return 3;\n        }\n     \
    \ case ::tools::safe_int<T>::type::pos_inf:\n        return 4;\n      default:\
    \ // nan\n        return 5;\n      }\n    };\n    static constexpr ::tools::safe_int<T>\
    \ g2(int i) {\n      return ::std::array<::tools::safe_int<T>, 6>({\n        ::tools::safe_int<T>::neg_inf,\n\
    \        ::tools::safe_int<T>(),\n        ::tools::safe_int<T>(0),\n        ::tools::safe_int<T>(),\n\
    \        ::tools::safe_int<T>::pos_inf,\n        ::tools::safe_int<T>::nan\n \
    \     })[i];\n    }\n\n  public:\n    constexpr bool is_finite() const {\n   \
    \   return this->m_type == ::tools::safe_int<T>::type::finite;\n    }\n\n    constexpr\
    \ T val() const {\n      assert(this->is_finite());\n      return this->m_value;\n\
    \    }\n\n    friend constexpr bool operator==(const ::tools::safe_int<T>& x,\
    \ const ::tools::safe_int<T>& y) {\n      if (x.is_finite() && y.is_finite())\
    \ {\n        return x.m_value == y.m_value;\n      } else if (!x.is_finite() &&\
    \ !y.is_finite()) {\n        return x.m_type == y.m_type;\n      } else {\n  \
    \      return false;\n      }\n    }\n    friend constexpr bool operator!=(const\
    \ ::tools::safe_int<T>& x, const ::tools::safe_int<T>& y) {\n      return !(x\
    \ == y);\n    }\n\n    constexpr ::tools::safe_int<T> operator+() const {\n  \
    \    return *this;\n    }\n    constexpr ::tools::safe_int<T> operator-() const\
    \ {\n      switch (this->m_type) {\n      case ::tools::safe_int<T>::type::finite:\n\
    \        return this->m_value == ::std::numeric_limits<T>::min()\n          ?\
    \ ::tools::safe_int<T>::nan\n          : ::tools::safe_int<T>(-this->m_value);\n\
    \      case ::tools::safe_int<T>::type::pos_inf:\n        return ::tools::safe_int<T>::neg_inf;\n\
    \      case ::tools::safe_int<T>::type::neg_inf:\n        return ::tools::safe_int<T>::pos_inf;\n\
    \      default: // nan\n        return ::tools::safe_int<T>::nan;\n      }\n \
    \   }\n\n    friend constexpr ::tools::safe_int<T> operator+(const ::tools::safe_int<T>&\
    \ x, const ::tools::safe_int<T>& y) {\n      const int NI = 0;\n      const int\
    \ F = 1;\n      const int PI = 2;\n      const int U = 3;\n      const int r =\
    \ ::std::array<::std::array<int, 4>, 4>({{\n        {NI, NI,  U,  U},\n      \
    \  {NI,  F, PI,  U},\n        { U, PI, PI,  U},\n        { U,  U,  U,  U}\n  \
    \    }})[f1(x)][f1(y)];\n      if (r == F) {\n        if (y.m_value > 0 && x.m_value\
    \ > ::std::numeric_limits<T>::max() - y.m_value) return g1(U);\n        if (y.m_value\
    \ < 0 && x.m_value < ::std::numeric_limits<T>::min() - y.m_value) return g1(U);\n\
    \        return ::tools::safe_int<T>(x.m_value + y.m_value);\n      } else {\n\
    \        return g1(r);\n      }\n    }\n    friend constexpr ::tools::safe_int<T>\
    \ operator+(const ::tools::safe_int<T>& x, const T& y) {\n      return x + tools::safe_int<T>(y);\n\
    \    }\n    friend constexpr ::tools::safe_int<T> operator+(const T& x, const\
    \ ::tools::safe_int<T>& y) {\n      return tools::safe_int<T>(x) + y;\n    }\n\
    \n    friend constexpr ::tools::safe_int<T> operator-(const ::tools::safe_int<T>&\
    \ x, const ::tools::safe_int<T>& y) {\n      const int NI = 0;\n      const int\
    \ F = 1;\n      const int PI = 2;\n      const int U = 3;\n      const int r =\
    \ ::std::array<::std::array<int, 4>, 4>({{\n        { U, NI, NI,  U},\n      \
    \  {PI,  F, NI,  U},\n        {PI, PI,  U,  U},\n        { U,  U,  U,  U}\n  \
    \    }})[f1(x)][f1(y)];\n      if (r == F) {\n        if (y.m_value < 0 && x.m_value\
    \ > ::std::numeric_limits<T>::max() + y.m_value) return g1(U);\n        if (y.m_value\
    \ > 0 && x.m_value < ::std::numeric_limits<T>::min() + y.m_value) return g1(U);\n\
    \        return ::tools::safe_int<T>(x.m_value - y.m_value);\n      } else {\n\
    \        return g1(r);\n      }\n    }\n    friend constexpr ::tools::safe_int<T>\
    \ operator-(const ::tools::safe_int<T>& x, const T& y) {\n      return x - tools::safe_int<T>(y);\n\
    \    }\n    friend constexpr ::tools::safe_int<T> operator-(const T& x, const\
    \ ::tools::safe_int<T>& y) {\n      return tools::safe_int<T>(x) - y;\n    }\n\
    \n    friend constexpr ::tools::safe_int<T> operator*(const ::tools::safe_int<T>&\
    \ x, const ::tools::safe_int<T>& y) {\n      const int NI = 0;\n      const int\
    \ NF = 1;\n      const int Z = 2;\n      const int PF = 3;\n      const int PI\
    \ = 4;\n      const int U = 5;\n      const int r = ::std::array<::std::array<int,\
    \ 6>, 6>({{\n        {PI, PI,  U, NI, NI,  U},\n        {PI, PF,  Z, NF, NI, \
    \ U},\n        { U,  Z,  Z,  Z,  U,  U},\n        {NI, NF,  Z, PF, PI,  U},\n\
    \        {NI, NI,  U, PI, PI,  U},\n        { U,  U,  U,  U,  U,  U}\n      }})[f2(x)][f2(y)];\n\
    \      if (r == NF || r == PF) {\n        if (x.m_value > 0) {\n          if (y.m_value\
    \ > 0) {\n            if (x.m_value > ::std::numeric_limits<T>::max() / y.m_value)\
    \ {\n              return g2(U);\n            }\n          } else {\n        \
    \    if (y.m_value < ::std::numeric_limits<T>::min() / x.m_value) {\n        \
    \      return g2(U);\n            }\n          }\n        } else {\n         \
    \ if (y.m_value > 0) {\n            if (x.m_value < ::std::numeric_limits<T>::min()\
    \ / y.m_value) {\n              return g2(U);\n            }\n          } else\
    \ {\n            if (x.m_value != 0 && y.m_value < ::std::numeric_limits<T>::max()\
    \ / x.m_value) {\n              return g2(U);\n            }\n          }\n  \
    \      }\n        return ::tools::safe_int<T>(x.m_value * y.m_value);\n      }\
    \ else {\n        return g2(r);\n      }\n    }\n    friend constexpr ::tools::safe_int<T>\
    \ operator*(const ::tools::safe_int<T>& x, const T& y) {\n      return x * tools::safe_int<T>(y);\n\
    \    }\n    friend constexpr ::tools::safe_int<T> operator*(const T& x, const\
    \ ::tools::safe_int<T>& y) {\n      return tools::safe_int<T>(x) * y;\n    }\n\
    \n    friend constexpr ::tools::safe_int<T> operator/(const ::tools::safe_int<T>&\
    \ x, const ::tools::safe_int<T>& y) {\n      const int NI = 0;\n      const int\
    \ NF = 1;\n      const int Z = 2;\n      const int PF = 3;\n      const int PI\
    \ = 4;\n      const int U = 5;\n      const int r = ::std::array<::std::array<int,\
    \ 6>, 6>({{\n        { U, PI,  U, NI,  U,  U},\n        { Z, PF,  U, NF,  Z, \
    \ U},\n        { Z,  Z,  U,  Z,  Z,  U},\n        { Z, NF,  U, PF,  Z,  U},\n\
    \        { U, NI,  U, PI,  U,  U},\n        { U,  U,  U,  U,  U,  U}\n      }})[f2(x)][f2(y)];\n\
    \      if (r == NF || r == PF) {\n        if (x.m_value == ::std::numeric_limits<T>::min()\
    \ && y.m_value == -1) return g2(U);\n        return ::tools::safe_int<T>(x.m_value\
    \ / y.m_value);\n      } else {\n        return g2(r);\n      }\n    }\n    friend\
    \ constexpr ::tools::safe_int<T> operator/(const ::tools::safe_int<T>& x, const\
    \ T& y) {\n      return x / tools::safe_int<T>(y);\n    }\n    friend constexpr\
    \ ::tools::safe_int<T> operator/(const T& x, const ::tools::safe_int<T>& y) {\n\
    \      return tools::safe_int<T>(x) / y;\n    }\n\n    friend constexpr ::tools::safe_int<T>\
    \ operator%(const ::tools::safe_int<T>& x, const ::tools::safe_int<T>& y) {\n\
    \      const int NF = 1;\n      const int Z = 2;\n      const int PF = 3;\n  \
    \    const int U = 5;\n      const int r = ::std::array<::std::array<int, 6>,\
    \ 6>({{\n        { U,  U,  U,  U,  U,  U},\n        { U, NF,  U, NF,  U,  U},\n\
    \        { U,  Z,  U,  Z,  U,  U},\n        { U, PF,  U, PF,  U,  U},\n      \
    \  { U,  U,  U,  U,  U,  U},\n        { U,  U,  U,  U,  U,  U}\n      }})[f2(x)][f2(y)];\n\
    \      if (r == NF || r == PF) {\n        if (x.m_value == ::std::numeric_limits<T>::min()\
    \ && y.m_value == -1) return g2(U);\n        return ::tools::safe_int<T>(x.m_value\
    \ % y.m_value);\n      } else {\n        return g2(r);\n      }\n    }\n    friend\
    \ constexpr ::tools::safe_int<T> operator%(const ::tools::safe_int<T>& x, const\
    \ T& y) {\n      return x % tools::safe_int<T>(y);\n    }\n    friend constexpr\
    \ ::tools::safe_int<T> operator%(const T& x, const ::tools::safe_int<T>& y) {\n\
    \      return tools::safe_int<T>(x) % y;\n    }\n\n    constexpr ::tools::safe_int<T>&\
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
    \ ::tools::safe_int<T>& y) {\n      const ::std::optional<bool> FALSE = ::std::make_optional(false);\n\
    \      const ::std::optional<bool> TRUE = ::std::make_optional(true);\n      const\
    \ ::std::optional<bool> UNKNOWN = ::std::nullopt;\n      const ::std::optional<bool>\
    \ r = ::std::array<::std::array<::std::optional<bool>, 4>, 4>({{\n        {FALSE,\
    \    TRUE,  TRUE, FALSE},\n        {FALSE, UNKNOWN,  TRUE, FALSE},\n        {FALSE,\
    \   FALSE, FALSE, FALSE},\n        {FALSE,   FALSE, FALSE, FALSE}\n      }})[f1(x)][f1(y)];\n\
    \      if (!r) {\n        return x.m_value < y.m_value;\n      } else {\n    \
    \    return *r;\n      }\n    }\n    friend constexpr bool operator>(const ::tools::safe_int<T>&\
    \ x, const ::tools::safe_int<T>& y) {\n      const ::std::optional<bool> FALSE\
    \ = ::std::make_optional(false);\n      const ::std::optional<bool> TRUE = ::std::make_optional(true);\n\
    \      const ::std::optional<bool> UNKNOWN = ::std::nullopt;\n      const ::std::optional<bool>\
    \ r = ::std::array<::std::array<::std::optional<bool>, 4>, 4>({{\n        {FALSE,\
    \   FALSE, FALSE, FALSE},\n        { TRUE, UNKNOWN, FALSE, FALSE},\n        {\
    \ TRUE,    TRUE, FALSE, FALSE},\n        {FALSE,   FALSE, FALSE, FALSE}\n    \
    \  }})[f1(x)][f1(y)];\n      if (!r) {\n        return x.m_value > y.m_value;\n\
    \      } else {\n        return *r;\n      }\n    }\n    friend constexpr bool\
    \ operator<=(const ::tools::safe_int<T>& x, const ::tools::safe_int<T>& y) {\n\
    \      return x < y || x == y;\n    }\n    friend constexpr bool operator>=(const\
    \ ::tools::safe_int<T>& x, const ::tools::safe_int<T>& y) {\n      return x >\
    \ y || x == y;\n    }\n  };\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/safe_int.hpp
  requiredBy: []
  timestamp: '2021-07-22 15:31:38+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - tests/safe_int.test.cpp
documentation_of: tools/safe_int.hpp
layout: document
title: $\mathbb{Z} \cup \{\infty, -\infty, \mathrm{NaN}\}$
---

It adds the three elements $\infty, -\infty, \mathrm{NaN}$ to a given signed integral type `<T>`.

### References
- [INT32-C. 符号付き整数演算がオーバーフローを引き起こさないことを保証する](https://www.jpcert.or.jp/sc-rules/c-int32-c.html)

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
(1) tools::safe_int<T> x();
(2) tools::safe_int<T> x(T n);
```

- (1)
    - It creates $0$.
- (2)
    - It creates the finite integer value which represents $n$.

### Constraints
- `<T>` is a signed integral type.

### Time Complexity
- $O(1)$

## infinity
```cpp
tools::safe_int<T> tools::safe_int<T>::infinity;
```

It is $\infty$.

## nan
```cpp
tools::safe_int<T> tools::safe_int<T>::nan;
```

It is $\mathrm{NaN}$.

## is_finite
```cpp
bool x.is_finite();
```

It returns `true` if $x \in \mathbb{Z}$.
Otherwise, it returns `false`.

### Constraints
- None

### Time Complexity
- $O(1)$

## val
```cpp
T x.val();
```

It returns $x$ as `<T>`.

### Constraints
- $x \in \mathbb{Z}$

### Time Complexity
- $O(1)$

## +x
```cpp
tools::safe_int<T> +x;
```

It returns $x$.

### Constraints
- None

### Time Complexity
- $O(1)$

## -x
```cpp
tools::safe_int<T> -x;
```

It returns 

$$\begin{align*}
\left\{\begin{array}{ll}
-x & \text{(if $x \in \mathbb{Z}$ and $-x$ does not cause an overflow)}\\
\mathrm{NaN} & \text{(if $x \in \mathbb{Z}$ and $-x$ causes an overflow)}\\
-\infty & \text{(if $x = \infty$)}\\
\infty & \text{(if $x = -\infty$)}\\
\mathrm{NaN} & \text{(if $x = \mathrm{NaN}$)}
\end{array}\right.&
\end{align*}$$

### Constraints
- None

### Time Complexity
- $O(1)$

## x + y
```cpp
tools::safe_int<T> x + y;
```

The return value is as follows.

|$x \backslash y$|$-\infty$|$\mathbb{Z}$|$\infty$|$\mathrm{NaN}$|
|$-\infty$|$-\infty$|$-\infty$|$\mathrm{NaN}$|$\mathrm{NaN}$|
|$\mathbb{Z}$|$-\infty$|(see below)|$\infty$|$\mathrm{NaN}$|
|$\infty$|$\mathrm{NaN}$|$\infty$|$\infty$|$\mathrm{NaN}$|
|$\mathrm{NaN}$|$\mathrm{NaN}$|$\mathrm{NaN}$|$\mathrm{NaN}$|$\mathrm{NaN}$|

If $x \in \mathbb{Z}$ and $y \in \mathbb{Z}$, it returns 

$$\begin{align*}
\left\{\begin{array}{ll}
x + y & \text{(if $x + y$ does not cause an overflow)}\\
\mathrm{NaN} & \text{(if $x + y$ causes an overflow)}
\end{array}\right.&
\end{align*}$$

### Constraints
- None

### Time Complexity
- $O(1)$

## x - y
```cpp
tools::safe_int<T> x - y;
```

The return value is as follows.

|$x \backslash y$|$-\infty$|$\mathbb{Z}$|$\infty$|$\mathrm{NaN}$|
|$-\infty$|$\mathrm{NaN}$|$-\infty$|$-\infty$|$\mathrm{NaN}$|
|$\mathbb{Z}$|$\infty$|(see below)|$-\infty$|$\mathrm{NaN}$|
|$\infty$|$\infty$|$\infty$|$\mathrm{NaN}$|$\mathrm{NaN}$|
|$\mathrm{NaN}$|$\mathrm{NaN}$|$\mathrm{NaN}$|$\mathrm{NaN}$|$\mathrm{NaN}$|

If $x \in \mathbb{Z}$ and $y \in \mathbb{Z}$, it returns 

$$\begin{align*}
\left\{\begin{array}{ll}
x - y & \text{(if $x - y$ does not cause an overflow)}\\
\mathrm{NaN} & \text{(if $x - y$ causes an overflow)}
\end{array}\right.&
\end{align*}$$

### Constraints
- None

### Time Complexity
- $O(1)$

## x * y
```cpp
tools::safe_int<T> x * y;
```

The return value is as follows.

|$x \backslash y$|$-\infty$|$\mathbb{Z}_{<0}$|$0$|$\mathbb{Z}_{>0}$|$\infty$|$\mathrm{NaN}$|
|$-\infty$|$\infty$|$\infty$|$\mathrm{NaN}$|$-\infty$|$-\infty$|$\mathrm{NaN}$|
|$\mathbb{Z}_{<0}$|$\infty$|(see below)|$0$|(see below)|$-\infty$|$\mathrm{NaN}$|
|$0$|$\mathrm{NaN}$|$0$|$0$|$0$|$\mathrm{NaN}$|$\mathrm{NaN}$|
|$\mathbb{Z}_{>0}$|$-\infty$|(see below)|$0$|(see below)|$\infty$|$\mathrm{NaN}$|
|$\infty$|$-\infty$|$-\infty$|$\mathrm{NaN}$|$\infty$|$\infty$|$\mathrm{NaN}$|
|$\mathrm{NaN}$|$\mathrm{NaN}$|$\mathrm{NaN}$|$\mathrm{NaN}$|$\mathrm{NaN}$|$\mathrm{NaN}$|$\mathrm{NaN}$|

If $x \in \mathbb{Z}$ and $y \in \mathbb{Z}$, it returns 

$$\begin{align*}
\left\{\begin{array}{ll}
xy & \text{(if $xy$ does not cause an overflow)}\\
\mathrm{NaN} & \text{(if $xy$ causes an overflow)}
\end{array}\right.&
\end{align*}$$

### Constraints
- None

### Time Complexity
- $O(1)$

## x / y
```cpp
tools::safe_int<T> x / y;
```

The return value is as follows.

|$x \backslash y$|$-\infty$|$\mathbb{Z}_{<0}$|$0$|$\mathbb{Z}_{>0}$|$\infty$|$\mathrm{NaN}$|
|$-\infty$|$\mathrm{NaN}$|$\infty$|$\mathrm{NaN}$|$-\infty$|$\mathrm{NaN}$|$\mathrm{NaN}$|
|$\mathbb{Z}_{<0}$|$0$|(see below)|$\mathrm{NaN}$|(see below)|$0$|$\mathrm{NaN}$|
|$0$|$0$|$0$|$\mathrm{NaN}$|$0$|$0$|$\mathrm{NaN}$|
|$\mathbb{Z}_{>0}$|$0$|(see below)|$\mathrm{NaN}$|(see below)|$0$|$\mathrm{NaN}$|
|$\infty$|$\mathrm{NaN}$|$-\infty$|$\mathrm{NaN}$|$\infty$|$\mathrm{NaN}$|$\mathrm{NaN}$|
|$\mathrm{NaN}$|$\mathrm{NaN}$|$\mathrm{NaN}$|$\mathrm{NaN}$|$\mathrm{NaN}$|$\mathrm{NaN}$|$\mathrm{NaN}$|

If $x \in \mathbb{Z}$ and $y \in \mathbb{Z} \setminus \\{0\\}$, the return value is as follows.

- If $x = $ `std::numeric_limits<T>::min()` and $y = -1$, it returns $\mathrm{NaN}$.
- Otherwise, it returns the rounded $\frac{x}{y}$ towards zero.

### Constraints
- None

### Time Complexity
- $O(1)$

## x % y
```cpp
tools::safe_int<T> x % y;
```

The return value is as follows.

|$x \backslash y$|$-\infty$|$\mathbb{Z}_{<0}$|$0$|$\mathbb{Z}_{>0}$|$\infty$|$\mathrm{NaN}$|
|$-\infty$|$\mathrm{NaN}$|$\mathrm{NaN}$|$\mathrm{NaN}$|$\mathrm{NaN}$|$\mathrm{NaN}$|$\mathrm{NaN}$|
|$\mathbb{Z}_{<0}$|$\mathrm{NaN}$|(see below)|$\mathrm{NaN}$|(see below)|$\mathrm{NaN}$|$\mathrm{NaN}$|
|$0$|$\mathrm{NaN}$|$0$|$\mathrm{NaN}$|$0$|$\mathrm{NaN}$|$\mathrm{NaN}$|
|$\mathbb{Z}_{>0}$|$\mathrm{NaN}$|(see below)|$\mathrm{NaN}$|(see below)|$\mathrm{NaN}$|$\mathrm{NaN}$|
|$\infty$|$\mathrm{NaN}$|$\mathrm{NaN}$|$\mathrm{NaN}$|$\mathrm{NaN}$|$\mathrm{NaN}$|$\mathrm{NaN}$|
|$\mathrm{NaN}$|$\mathrm{NaN}$|$\mathrm{NaN}$|$\mathrm{NaN}$|$\mathrm{NaN}$|$\mathrm{NaN}$|$\mathrm{NaN}$|

If $x \in \mathbb{Z}$ and $y \in \mathbb{Z} \setminus \\{0\\}$, the return value is as follows.

- If $x = $ `std::numeric_limits<T>::min()` and $y = -1$, it returns $\mathrm{NaN}$.
- Otherwise, it returns $x - qy$ where $q$ is the rounded $\frac{x}{y}$ towards zero.

### Constraints
- None

### Time Complexity
- $O(1)$

## x += y
```cpp
tools::safe_int<T>& x += y;
```

It runs `x = x + y;` and returns $x$.

### Constraints
- None

### Time Complexity
- $O(1)$

## x -= y
```cpp
tools::safe_int<T>& x -= y;
```

It runs `x = x - y;` and returns $x$.

### Constraints
- None

### Time Complexity
- $O(1)$

## x *= y
```cpp
tools::safe_int<T>& x *= y;
```

It runs `x = x * y;` and returns $x$.

### Constraints
- None

### Time Complexity
- $O(1)$

## x /= y
```cpp
tools::safe_int<T>& x /= y;
```

It runs `x = x / y;` and returns $x$.

### Constraints
- None

### Time Complexity
- $O(1)$

## x %= y
```cpp
tools::safe_int<T>& x %= y;
```

It runs `x = x % y;` and returns $x$.

### Constraints
- None

### Time Complexity
- $O(1)$

## x == y
```cpp
bool x == y;
```

The return value is as follows.

|$x \backslash y$|$-\infty$|$\mathbb{Z}$|$\infty$|$\mathrm{NaN}$|
|$-\infty$|true|false|false|false|
|$\mathbb{Z}$|false|$x == y$|false|false|
|$\infty$|false|false|true|false|
|$\mathrm{NaN}$|false|false|false|false|

### Constraints
- None

### Time Complexity
- $O(1)$

## x != y
```cpp
bool x != y;
```

It returns `!(x == y)`.

### Constraints
- None

### Time Complexity
- $O(1)$

## x < y
```cpp
bool x < y;
```

The return value is as follows.

|$x \backslash y$|$-\infty$|$\mathbb{Z}$|$\infty$|$\mathrm{NaN}$|
|$-\infty$|false|true|true|false|
|$\mathbb{Z}$|false|$x < y$|true|false|
|$\infty$|false|false|false|false|
|$\mathrm{NaN}$|false|false|false|false|

### Constraints
- None

### Time Complexity
- $O(1)$

## x > y
```cpp
bool x > y;
```

The return value is as follows.

|$x \backslash y$|$-\infty$|$\mathbb{Z}$|$\infty$|$\mathrm{NaN}$|
|$-\infty$|false|false|false|false|
|$\mathbb{Z}$|true|$x > y$|false|false|
|$\infty$|true|true|false|false|
|$\mathrm{NaN}$|false|false|false|false|

### Constraints
- None

### Time Complexity
- $O(1)$

## x <= y
```cpp
bool x <= y;
```

It returns `(x < y) || (x == y)`.

### Constraints
- None

### Time Complexity
- $O(1)$

## x >= y
```cpp
bool x >= y;
```

It returns `(x > y) || (x == y)`.

### Constraints
- None

### Time Complexity
- $O(1)$
