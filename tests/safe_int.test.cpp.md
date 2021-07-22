---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: tools/safe_int.hpp
    title: $\mathbb{Z} \cup \{\infty, -\infty, \mathrm{NaN}\}$
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
    \n\n#include <cstdlib>\n#include <iostream>\n#line 1 \"tools/safe_int.hpp\"\n\n\
    \n\n#include <type_traits>\n#include <cstddef>\n#include <cassert>\n#include <limits>\n\
    #include <array>\n#include <optional>\n\nnamespace tools {\n  template <typename\
    \ T, typename ::std::enable_if<::std::is_signed_v<T>, ::std::nullptr_t>::type\
    \ = nullptr>\n  class safe_int {\n  private:\n    enum class type {\n      finite,\n\
    \      pos_inf,\n      neg_inf,\n      nan\n    };\n    typename ::tools::safe_int<T>::type\
    \ m_type;\n    T m_value;\n\n    constexpr safe_int(const type type) :\n     \
    \ m_type(type), m_value(T()) {\n    }\n\n    static constexpr ::tools::safe_int<T>\
    \ pos_inf = tools::safe_int<T>(::tools::safe_int<T>::type::pos_inf);\n    static\
    \ constexpr ::tools::safe_int<T> neg_inf = tools::safe_int<T>(::tools::safe_int<T>::type::neg_inf);\n\
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
    \ y || x == y;\n    }\n  };\n}\n\n\n#line 6 \"tests/safe_int.test.cpp\"\n\nvoid\
    \ assert_that(const bool cond) {\n  if (!cond) {\n    std::exit(EXIT_FAILURE);\n\
    \  }\n}\n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  const tools::safe_int<int> POS_INF = tools::safe_int<int>::infinity;\n  const\
    \ tools::safe_int<int> NEG_INF = -tools::safe_int<int>::infinity;\n  const tools::safe_int<int>\
    \ NAN = tools::safe_int<int>::nan;\n  const int INT_MAX = std::numeric_limits<int>::max();\n\
    \  const int INT_MIN = std::numeric_limits<int>::min();\n  using s = tools::safe_int<int>;\n\
    \n  // basic arithmetic operations\n  assert_that(s(1) + s(2) == s(3));\n  assert_that(s(1)\
    \ - s(2) == s(-1));\n  assert_that(s(1) * s(2) == s(2));\n  assert_that(s(1) /\
    \ s(2) == s(0));\n  assert_that(s(1) % s(2) == s(1));\n\n  // operator+ should\
    \ detect an overflow.\n  assert_that(s(INT_MAX - 2) + s(1) == s(INT_MAX - 1));\n\
    \  assert_that(s(INT_MAX - 2) + s(2) == s(INT_MAX));\n  assert_that(s(INT_MAX\
    \ - 2) + s(3) == NAN);\n  assert_that(s(1) + s(INT_MAX - 2) == s(INT_MAX - 1));\n\
    \  assert_that(s(2) + s(INT_MAX - 2) == s(INT_MAX));\n  assert_that(s(3) + s(INT_MAX\
    \ - 2) == NAN);\n  assert_that(s(INT_MIN + 2) + s(-1) == s(INT_MIN + 1));\n  assert_that(s(INT_MIN\
    \ + 2) + s(-2) == s(INT_MIN));\n  assert_that(s(INT_MIN + 2) + s(-3) == NAN);\n\
    \  assert_that(s(-1) + s(INT_MIN + 2) == s(INT_MIN + 1));\n  assert_that(s(-2)\
    \ + s(INT_MIN + 2) == s(INT_MIN));\n  assert_that(s(-3) + s(INT_MIN + 2) == NAN);\n\
    \n  // infinite + finite should be infinite.\n  assert_that(POS_INF + s(-1) ==\
    \ POS_INF);\n  assert_that(s(-1) + POS_INF == POS_INF);\n  assert_that(POS_INF\
    \ + POS_INF == POS_INF);\n  assert_that(NEG_INF + s(1) == NEG_INF);\n  assert_that(s(1)\
    \ + NEG_INF == NEG_INF);\n  assert_that(NEG_INF + NEG_INF == NEG_INF);\n\n  //\
    \ operator- should detect an overflow.\n  assert_that(s(INT_MAX - 2) - s(-1) ==\
    \ s(INT_MAX - 1));\n  assert_that(s(INT_MAX - 2) - s(-2) == s(INT_MAX));\n  assert_that(s(INT_MAX\
    \ - 2) - s(-3) == NAN);\n  assert_that(s(INT_MIN + 2) - s(1) == s(INT_MIN + 1));\n\
    \  assert_that(s(INT_MIN + 2) - s(2) == s(INT_MIN));\n  assert_that(s(INT_MIN\
    \ + 2) - s(3) == NAN);\n\n  // infinite - finite should be finite.\n  assert_that(POS_INF\
    \ - s(1) == POS_INF);\n  assert_that(POS_INF - NEG_INF == POS_INF);\n  assert_that(NEG_INF\
    \ - s(-1) == NEG_INF);\n  assert_that(NEG_INF - POS_INF == NEG_INF);\n\n  // operator*\
    \ should detect an overflow.\n  assert_that(NEG_INF * NEG_INF == POS_INF);\n \
    \ assert_that(NEG_INF * s(INT_MIN) == POS_INF);\n  assert_that(NEG_INF * s(0)\
    \ == NAN);\n  assert_that(NEG_INF * s(INT_MAX) == NEG_INF);\n  assert_that(NEG_INF\
    \ * POS_INF == NEG_INF);\n  assert_that(s(INT_MIN) * NEG_INF == POS_INF);\n  assert_that(s(INT_MIN)\
    \ * s(INT_MIN) == NAN);\n  assert_that(s(INT_MIN) * s(0) == s(0));\n  assert_that(s(INT_MIN)\
    \ * s(INT_MAX) == NAN);\n  assert_that(s(INT_MIN) * POS_INF == NEG_INF);\n  assert_that(s(0)\
    \ * NEG_INF == NAN);\n  assert_that(s(0) * s(INT_MIN) == s(0));\n  assert_that(s(0)\
    \ * s(0) == s(0));\n  assert_that(s(0) * s(INT_MAX) == s(0));\n  assert_that(s(0)\
    \ * POS_INF == NAN);\n  assert_that(s(INT_MAX) * NEG_INF == NEG_INF);\n  assert_that(s(INT_MAX)\
    \ * s(INT_MIN) == NAN);\n  assert_that(s(INT_MAX) * s(0) == s(0));\n  assert_that(s(INT_MAX)\
    \ * s(INT_MAX) == NAN);\n  assert_that(s(INT_MAX) * POS_INF == POS_INF);\n  assert_that(POS_INF\
    \ * NEG_INF == NEG_INF);\n  assert_that(POS_INF * s(INT_MIN) == NEG_INF);\n  assert_that(POS_INF\
    \ * s(0) == NAN);\n  assert_that(POS_INF * s(INT_MAX) == POS_INF);\n  assert_that(POS_INF\
    \ * POS_INF == POS_INF);\n\n  std::cout << \"Hello World\" << '\\n';\n  return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\"\n\n\
    #include <cstdlib>\n#include <iostream>\n#include \"tools/safe_int.hpp\"\n\nvoid\
    \ assert_that(const bool cond) {\n  if (!cond) {\n    std::exit(EXIT_FAILURE);\n\
    \  }\n}\n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  const tools::safe_int<int> POS_INF = tools::safe_int<int>::infinity;\n  const\
    \ tools::safe_int<int> NEG_INF = -tools::safe_int<int>::infinity;\n  const tools::safe_int<int>\
    \ NAN = tools::safe_int<int>::nan;\n  const int INT_MAX = std::numeric_limits<int>::max();\n\
    \  const int INT_MIN = std::numeric_limits<int>::min();\n  using s = tools::safe_int<int>;\n\
    \n  // basic arithmetic operations\n  assert_that(s(1) + s(2) == s(3));\n  assert_that(s(1)\
    \ - s(2) == s(-1));\n  assert_that(s(1) * s(2) == s(2));\n  assert_that(s(1) /\
    \ s(2) == s(0));\n  assert_that(s(1) % s(2) == s(1));\n\n  // operator+ should\
    \ detect an overflow.\n  assert_that(s(INT_MAX - 2) + s(1) == s(INT_MAX - 1));\n\
    \  assert_that(s(INT_MAX - 2) + s(2) == s(INT_MAX));\n  assert_that(s(INT_MAX\
    \ - 2) + s(3) == NAN);\n  assert_that(s(1) + s(INT_MAX - 2) == s(INT_MAX - 1));\n\
    \  assert_that(s(2) + s(INT_MAX - 2) == s(INT_MAX));\n  assert_that(s(3) + s(INT_MAX\
    \ - 2) == NAN);\n  assert_that(s(INT_MIN + 2) + s(-1) == s(INT_MIN + 1));\n  assert_that(s(INT_MIN\
    \ + 2) + s(-2) == s(INT_MIN));\n  assert_that(s(INT_MIN + 2) + s(-3) == NAN);\n\
    \  assert_that(s(-1) + s(INT_MIN + 2) == s(INT_MIN + 1));\n  assert_that(s(-2)\
    \ + s(INT_MIN + 2) == s(INT_MIN));\n  assert_that(s(-3) + s(INT_MIN + 2) == NAN);\n\
    \n  // infinite + finite should be infinite.\n  assert_that(POS_INF + s(-1) ==\
    \ POS_INF);\n  assert_that(s(-1) + POS_INF == POS_INF);\n  assert_that(POS_INF\
    \ + POS_INF == POS_INF);\n  assert_that(NEG_INF + s(1) == NEG_INF);\n  assert_that(s(1)\
    \ + NEG_INF == NEG_INF);\n  assert_that(NEG_INF + NEG_INF == NEG_INF);\n\n  //\
    \ operator- should detect an overflow.\n  assert_that(s(INT_MAX - 2) - s(-1) ==\
    \ s(INT_MAX - 1));\n  assert_that(s(INT_MAX - 2) - s(-2) == s(INT_MAX));\n  assert_that(s(INT_MAX\
    \ - 2) - s(-3) == NAN);\n  assert_that(s(INT_MIN + 2) - s(1) == s(INT_MIN + 1));\n\
    \  assert_that(s(INT_MIN + 2) - s(2) == s(INT_MIN));\n  assert_that(s(INT_MIN\
    \ + 2) - s(3) == NAN);\n\n  // infinite - finite should be finite.\n  assert_that(POS_INF\
    \ - s(1) == POS_INF);\n  assert_that(POS_INF - NEG_INF == POS_INF);\n  assert_that(NEG_INF\
    \ - s(-1) == NEG_INF);\n  assert_that(NEG_INF - POS_INF == NEG_INF);\n\n  // operator*\
    \ should detect an overflow.\n  assert_that(NEG_INF * NEG_INF == POS_INF);\n \
    \ assert_that(NEG_INF * s(INT_MIN) == POS_INF);\n  assert_that(NEG_INF * s(0)\
    \ == NAN);\n  assert_that(NEG_INF * s(INT_MAX) == NEG_INF);\n  assert_that(NEG_INF\
    \ * POS_INF == NEG_INF);\n  assert_that(s(INT_MIN) * NEG_INF == POS_INF);\n  assert_that(s(INT_MIN)\
    \ * s(INT_MIN) == NAN);\n  assert_that(s(INT_MIN) * s(0) == s(0));\n  assert_that(s(INT_MIN)\
    \ * s(INT_MAX) == NAN);\n  assert_that(s(INT_MIN) * POS_INF == NEG_INF);\n  assert_that(s(0)\
    \ * NEG_INF == NAN);\n  assert_that(s(0) * s(INT_MIN) == s(0));\n  assert_that(s(0)\
    \ * s(0) == s(0));\n  assert_that(s(0) * s(INT_MAX) == s(0));\n  assert_that(s(0)\
    \ * POS_INF == NAN);\n  assert_that(s(INT_MAX) * NEG_INF == NEG_INF);\n  assert_that(s(INT_MAX)\
    \ * s(INT_MIN) == NAN);\n  assert_that(s(INT_MAX) * s(0) == s(0));\n  assert_that(s(INT_MAX)\
    \ * s(INT_MAX) == NAN);\n  assert_that(s(INT_MAX) * POS_INF == POS_INF);\n  assert_that(POS_INF\
    \ * NEG_INF == NEG_INF);\n  assert_that(POS_INF * s(INT_MIN) == NEG_INF);\n  assert_that(POS_INF\
    \ * s(0) == NAN);\n  assert_that(POS_INF * s(INT_MAX) == POS_INF);\n  assert_that(POS_INF\
    \ * POS_INF == POS_INF);\n\n  std::cout << \"Hello World\" << '\\n';\n  return\
    \ 0;\n}\n"
  dependsOn:
  - tools/safe_int.hpp
  isVerificationFile: true
  path: tests/safe_int.test.cpp
  requiredBy: []
  timestamp: '2021-07-22 15:31:38+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: tests/safe_int.test.cpp
layout: document
redirect_from:
- /verify/tests/safe_int.test.cpp
- /verify/tests/safe_int.test.cpp.html
title: tests/safe_int.test.cpp
---
