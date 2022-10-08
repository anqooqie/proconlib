---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/abs.hpp
    title: Unified interface for std::abs(x) and x.abs()
  - icon: ':heavy_check_mark:'
    path: tools/bigdecimal.hpp
    title: Arbitrary precision floating-point number
  - icon: ':heavy_check_mark:'
    path: tools/bigint.hpp
    title: Arbitrary precision integer
  - icon: ':heavy_check_mark:'
    path: tools/ceil.hpp
    title: $\left\lceil \frac{x}{y} \right\rceil$
  - icon: ':heavy_check_mark:'
    path: tools/detail/geometry_2d.hpp
    title: tools/detail/geometry_2d.hpp
  - icon: ':heavy_check_mark:'
    path: tools/directed_line_segment_2d.hpp
    title: Two-dimensional directed line segment
  - icon: ':heavy_check_mark:'
    path: tools/floor.hpp
    title: $\left\lfloor \frac{x}{y} \right\rfloor$
  - icon: ':heavy_check_mark:'
    path: tools/garner2.hpp
    title: Garner's algorithm for $\mathbb{Z} / M_1 \mathbb{Z}$ and $\mathbb{Z} /
      M_2 \mathbb{Z}$
  - icon: ':heavy_check_mark:'
    path: tools/is_prime.hpp
    title: Miller-Rabin primality test
  - icon: ':heavy_check_mark:'
    path: tools/is_rational.hpp
    title: Check whether T is tools::rational
  - icon: ':heavy_check_mark:'
    path: tools/less_by.hpp
    title: std::less by key
  - icon: ':heavy_check_mark:'
    path: tools/mod.hpp
    title: Minimum non-negative reminder
  - icon: ':heavy_check_mark:'
    path: tools/monoid.hpp
    title: Typical monoids
  - icon: ':heavy_check_mark:'
    path: tools/pair_hash.hpp
    title: Hash of std::pair
  - icon: ':heavy_check_mark:'
    path: tools/pow2.hpp
    title: $2^x$
  - icon: ':heavy_check_mark:'
    path: tools/pow_mod.hpp
    title: $x^y \pmod{M}$
  - icon: ':heavy_check_mark:'
    path: tools/prod_mod.hpp
    title: $x \cdot y \pmod{M}$
  - icon: ':heavy_check_mark:'
    path: tools/quo.hpp
    title: Quotient as integer division
  - icon: ':heavy_check_mark:'
    path: tools/rational.hpp
    title: Rational number
  - icon: ':heavy_check_mark:'
    path: tools/rounding_mode.hpp
    title: Rounding mode
  - icon: ':heavy_check_mark:'
    path: tools/signum.hpp
    title: Sign function
  - icon: ':heavy_check_mark:'
    path: tools/square.hpp
    title: $x^2$ under a given monoid
  - icon: ':question:'
    path: tools/ssize.hpp
    title: Polyfill of std::ssize
  - icon: ':heavy_check_mark:'
    path: tools/vector2.hpp
    title: 2D vector
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    ERROR: 1e-9
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/CGL_2_D
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/CGL_2_D
  bundledCode: "#line 1 \"tests/directed_line_segment_2d/squared_distance.test.cpp\"\
    \n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/CGL_2_D\"\n#define\
    \ ERROR 1e-9\n\n#include <iostream>\n#line 1 \"tools/vector2.hpp\"\n\n\n\n#include\
    \ <type_traits>\n#include <cmath>\n#include <cstddef>\n#include <array>\n#line\
    \ 9 \"tools/vector2.hpp\"\n#include <functional>\n#line 1 \"tools/abs.hpp\"\n\n\
    \n\n#line 5 \"tools/abs.hpp\"\n\nnamespace tools {\n\n  template <typename T>\n\
    \  auto abs(const T& v) -> decltype(::std::abs(v)) {\n    return ::std::abs(v);\n\
    \  }\n\n  template <typename T>\n  auto abs(const T& v) -> decltype(v.abs()) {\n\
    \    return v.abs();\n  }\n}\n\n\n#line 1 \"tools/pair_hash.hpp\"\n\n\n\n#line\
    \ 5 \"tools/pair_hash.hpp\"\n#include <utility>\n#include <random>\n#line 8 \"\
    tools/pair_hash.hpp\"\n#include <cstdint>\n\nnamespace tools {\n\n  template <class\
    \ T1, class T2>\n  struct pair_hash {\n    using result_type = ::std::size_t;\n\
    \    using argument_type = ::std::pair<T1, T2>;\n    ::std::size_t operator()(const\
    \ ::std::pair<T1, T2>& key) const {\n      static const ::std::size_t salt = ::std::random_device()();\n\
    \      static const ::std::hash<T1> hasher1 = ::std::hash<T1>();\n      static\
    \ const ::std::hash<T2> hasher2 = ::std::hash<T2>();\n      static const ::std::hash<::std::size_t>\
    \ hasher3 = ::std::hash<::std::size_t>();\n      ::std::size_t result = 0;\n \
    \     result ^= hasher1(key.first) + static_cast<::std::size_t>(0x9e3779b9) +\
    \ (result << static_cast<::std::size_t>(6)) + (result >> static_cast<::std::size_t>(2));\n\
    \      result ^= hasher2(key.second) + static_cast<::std::size_t>(0x9e3779b9)\
    \ + (result << static_cast<::std::size_t>(6)) + (result >> static_cast<::std::size_t>(2));\n\
    \      result ^= hasher3(salt) + static_cast<::std::size_t>(0x9e3779b9) + (result\
    \ << static_cast<::std::size_t>(6)) + (result >> static_cast<::std::size_t>(2));\n\
    \      return result;\n    }\n  };\n\n  template <>\n  struct pair_hash<::std::uint64_t,\
    \ ::std::uint64_t> {\n    using result_type = ::std::size_t;\n    using argument_type\
    \ = ::std::pair<::std::uint64_t, ::std::uint64_t>;\n    ::std::size_t operator()(const\
    \ ::std::pair<::std::uint64_t, ::std::uint64_t>& key) const {\n      static const\
    \ ::std::hash<::std::uint64_t> hasher = ::std::hash<::std::uint64_t>();\n    \
    \  return hasher(((key.first << static_cast<::std::uint64_t>(32)) | (key.first\
    \ >> static_cast<::std::uint64_t>(32))) ^ key.second);\n    }\n  };\n\n  template\
    \ <>\n  struct pair_hash<::std::int64_t, ::std::int64_t> {\n    using result_type\
    \ = ::std::size_t;\n    using argument_type = ::std::pair<::std::int64_t, ::std::int64_t>;\n\
    \    ::std::size_t operator()(const ::std::pair<::std::int64_t, ::std::int64_t>&\
    \ key) const {\n      static const ::tools::pair_hash<::std::uint64_t, ::std::uint64_t>\
    \ hasher = ::tools::pair_hash<::std::uint64_t, ::std::uint64_t>();\n      return\
    \ hasher(::std::make_pair<::std::uint64_t, ::std::uint64_t>(key.first, key.second));\n\
    \    }\n  };\n\n  template <>\n  struct pair_hash<::std::uint32_t, ::std::uint32_t>\
    \ {\n    using result_type = ::std::size_t;\n    using argument_type = ::std::pair<::std::uint32_t,\
    \ ::std::uint32_t>;\n    ::std::size_t operator()(const ::std::pair<::std::uint32_t,\
    \ ::std::uint32_t>& key) const {\n      static const ::std::hash<::std::uint64_t>\
    \ hasher = ::std::hash<::std::uint64_t>();\n      return hasher((static_cast<::std::uint64_t>(key.first)\
    \ << static_cast<::std::uint64_t>(32)) | static_cast<::std::uint64_t>(key.second));\n\
    \    }\n  };\n\n  template <>\n  struct pair_hash<::std::int32_t, ::std::int32_t>\
    \ {\n    using result_type = ::std::size_t;\n    using argument_type = ::std::pair<::std::int32_t,\
    \ ::std::int32_t>;\n    ::std::size_t operator()(const ::std::pair<::std::int32_t,\
    \ ::std::int32_t>& key) const {\n      static const ::tools::pair_hash<::std::uint32_t,\
    \ ::std::uint32_t> hasher = ::tools::pair_hash<::std::uint32_t, ::std::uint32_t>();\n\
    \      return hasher(::std::make_pair<::std::uint32_t, ::std::uint32_t>(key.first,\
    \ key.second));\n    }\n  };\n}\n\n\n#line 12 \"tools/vector2.hpp\"\n\nnamespace\
    \ tools {\n\n  template <typename T>\n  class vector2 {\n  private:\n    using\
    \ F = ::std::conditional_t<::std::is_floating_point_v<T>, T, double>;\n\n  public:\n\
    \    T x;\n    T y;\n\n    vector2() :\n      vector2(T(), T()) {\n    }\n\n \
    \   vector2(const T& x, const T& y) :\n      x(x),\n      y(y) {\n    }\n\n  \
    \  T l1_norm() const {\n      return ::tools::abs(this->x) + ::tools::abs(this->y);\n\
    \    }\n\n    F l2_norm() const {\n      return ::std::sqrt(static_cast<F>(this->squared_l2_norm()));\n\
    \    }\n\n    T squared_l2_norm() const {\n      return this->inner_product(*this);\n\
    \    }\n\n    template <typename SFINAE = T, ::std::enable_if_t<::std::is_floating_point_v<SFINAE>,\
    \ ::std::nullptr_t> = nullptr>\n    ::tools::vector2<T> normalized() const {\n\
    \      return *this / this->l2_norm();\n    }\n\n    ::tools::vector2<T> turn90()\
    \ const {\n      return ::tools::vector2<T>(-this->y, this->x);\n    }\n\n   \
    \ ::tools::vector2<T> turn270() const {\n      return ::tools::vector2<T>(this->y,\
    \ -this->x);\n    }\n\n    ::tools::vector2<T> operator+() const {\n      return\
    \ *this;\n    }\n\n    ::tools::vector2<T> operator-() const {\n      return ::tools::vector2<T>(-this->x,\
    \ -this->y);\n    }\n\n    friend ::tools::vector2<T> operator+(const ::tools::vector2<T>&\
    \ lhs, const ::tools::vector2<T>& rhs) {\n      return ::tools::vector2<T>(lhs.x\
    \ + rhs.x, lhs.y + rhs.y);\n    }\n\n    friend ::tools::vector2<T> operator-(const\
    \ ::tools::vector2<T>& lhs, const ::tools::vector2<T>& rhs) {\n      return ::tools::vector2<T>(lhs.x\
    \ - rhs.x, lhs.y - rhs.y);\n    }\n\n    template <typename OTHER, ::std::enable_if_t<!::std::is_same_v<OTHER,\
    \ ::tools::vector2<T>>, ::std::nullptr_t> = nullptr>\n    friend ::tools::vector2<T>\
    \ operator*(const ::tools::vector2<T>& lhs, const OTHER& rhs) {\n      return\
    \ ::tools::vector2<T>(lhs.x * rhs, lhs.y * rhs);\n    }\n    template <typename\
    \ OTHER, ::std::enable_if_t<!::std::is_same_v<OTHER, ::tools::vector2<T>>, ::std::nullptr_t>\
    \ = nullptr>\n    friend ::tools::vector2<T> operator*(const OTHER& lhs, const\
    \ ::tools::vector2<T>& rhs) {\n      return ::tools::vector2<T>(lhs * rhs.x, lhs\
    \ * rhs.y);\n    }\n\n    template <typename OTHER, ::std::enable_if_t<!::std::is_same_v<OTHER,\
    \ ::tools::vector2<T>>, ::std::nullptr_t> = nullptr>\n    friend ::tools::vector2<T>\
    \ operator/(const ::tools::vector2<T>& lhs, const OTHER& rhs) {\n      return\
    \ ::tools::vector2<T>(lhs.x / rhs, lhs.y / rhs);\n    }\n\n    T inner_product(const\
    \ ::tools::vector2<T>& other) const {\n      return this->x * other.x + this->y\
    \ * other.y;\n    }\n\n    T outer_product(const ::tools::vector2<T>& other) const\
    \ {\n      return this->x * other.y - this->y * other.x;\n    }\n\n    ::tools::vector2<T>&\
    \ operator+=(const ::tools::vector2<T>& other) {\n      return *this = *this +\
    \ other;\n    }\n\n    ::tools::vector2<T>& operator-=(const ::tools::vector2<T>&\
    \ other) {\n      return *this = *this - other;\n    }\n\n    template <typename\
    \ OTHER, ::std::enable_if_t<!::std::is_same_v<OTHER, ::tools::vector2<T>>, ::std::nullptr_t>\
    \ = nullptr>\n    ::tools::vector2<T>& operator*=(const OTHER& other) {\n    \
    \  return *this = *this * other;\n    }\n\n    template <typename OTHER, ::std::enable_if_t<!::std::is_same_v<OTHER,\
    \ ::tools::vector2<T>>, ::std::nullptr_t> = nullptr>\n    ::tools::vector2<T>&\
    \ operator/=(const OTHER& other) {\n      return *this = *this / other;\n    }\n\
    \n    friend bool operator==(const ::tools::vector2<T>& lhs, const ::tools::vector2<T>&\
    \ rhs) {\n      return lhs.x == rhs.x && lhs.y == rhs.y;\n    }\n\n    friend\
    \ bool operator!=(const ::tools::vector2<T>& lhs, const ::tools::vector2<T>& rhs)\
    \ {\n      return lhs.x != rhs.x || lhs.y != rhs.y;\n    }\n\n    friend ::std::ostream&\
    \ operator<<(::std::ostream& os, const ::tools::vector2<T>& self) {\n      return\
    \ os << '(' << self.x << \", \" << self.y << ')';\n    }\n\n    friend ::std::istream&\
    \ operator>>(::std::istream& is, ::tools::vector2<T>& self) {\n      return is\
    \ >> self.x >> self.y;\n    }\n\n    static ::std::array<::tools::vector2<T>,\
    \ 4> four_directions() {\n      return ::std::array<::tools::vector2<T>, 4>({\n\
    \        ::tools::vector2<T>(static_cast<T>(1), static_cast<T>(0)),\n        ::tools::vector2<T>(static_cast<T>(0),\
    \ static_cast<T>(1)),\n        ::tools::vector2<T>(static_cast<T>(-1), static_cast<T>(0)),\n\
    \        ::tools::vector2<T>(static_cast<T>(0), static_cast<T>(-1))\n      });\n\
    \    }\n\n    static ::std::array<::tools::vector2<T>, 8> eight_directions() {\n\
    \      return ::std::array<::tools::vector2<T>, 8>({\n        ::tools::vector2<T>(static_cast<T>(1),\
    \ static_cast<T>(0)),\n        ::tools::vector2<T>(static_cast<T>(1), static_cast<T>(1)),\n\
    \        ::tools::vector2<T>(static_cast<T>(0), static_cast<T>(1)),\n        ::tools::vector2<T>(static_cast<T>(-1),\
    \ static_cast<T>(1)),\n        ::tools::vector2<T>(static_cast<T>(-1), static_cast<T>(0)),\n\
    \        ::tools::vector2<T>(static_cast<T>(-1), static_cast<T>(-1)),\n      \
    \  ::tools::vector2<T>(static_cast<T>(0), static_cast<T>(-1)),\n        ::tools::vector2<T>(static_cast<T>(1),\
    \ static_cast<T>(-1))\n      });\n    }\n  };\n}\n\nnamespace std {\n  template\
    \ <typename T>\n  struct hash<::tools::vector2<T>> {\n    using result_type =\
    \ ::std::size_t;\n    using argument_type = ::tools::vector2<T>;\n    ::std::size_t\
    \ operator()(const ::tools::vector2<T>& key) const {\n      static const ::tools::pair_hash<T,\
    \ T> hasher = ::tools::pair_hash<T, T>();\n      return hasher(::std::make_pair(key.x,\
    \ key.y));\n    }\n  };\n}\n\n\n#line 1 \"tools/directed_line_segment_2d.hpp\"\
    \n\n\n\n#line 1 \"tools/detail/geometry_2d.hpp\"\n\n\n\n#include <algorithm>\n\
    #line 6 \"tools/detail/geometry_2d.hpp\"\n#include <cassert>\n#line 9 \"tools/detail/geometry_2d.hpp\"\
    \n#include <initializer_list>\n#include <limits>\n#include <optional>\n#include\
    \ <tuple>\n#line 15 \"tools/detail/geometry_2d.hpp\"\n#include <variant>\n#include\
    \ <vector>\n#line 1 \"tools/is_rational.hpp\"\n\n\n\nnamespace tools {\n\n  template\
    \ <typename T>\n  struct is_rational {\n    static constexpr bool value = false;\n\
    \  };\n\n  template <typename T>\n  inline constexpr bool is_rational_v = ::tools::is_rational<T>::value;\n\
    }\n\n\n#line 1 \"tools/less_by.hpp\"\n\n\n\nnamespace tools {\n\n  template <class\
    \ F>\n  class less_by {\n  private:\n    F selector;\n\n  public:\n    less_by(const\
    \ F& selector) : selector(selector) {\n    }\n\n    template <class T>\n    bool\
    \ operator()(const T& x, const T& y) const {\n      return selector(x) < selector(y);\n\
    \    }\n  };\n}\n\n\n#line 1 \"tools/signum.hpp\"\n\n\n\n#line 5 \"tools/signum.hpp\"\
    \n\nnamespace tools {\n\n  template <typename T>\n  constexpr int signum(const\
    \ T x) noexcept {\n    if constexpr (::std::is_signed_v<T>) {\n      return (T(0)\
    \ < x) - (x < T(0));\n    } else {\n      return T(0) < x;\n    }\n  }\n}\n\n\n\
    #line 1 \"tools/square.hpp\"\n\n\n\n#line 1 \"tools/monoid.hpp\"\n\n\n\n#line\
    \ 6 \"tools/monoid.hpp\"\n#include <numeric>\n\nnamespace tools {\n  namespace\
    \ monoid {\n    template <typename Type, Type E = ::std::numeric_limits<Type>::min()>\n\
    \    struct max {\n      using T = Type;\n      static T op(const T lhs, const\
    \ T rhs) {\n        return ::std::max(lhs, rhs);\n      }\n      static T e()\
    \ {\n        return E;\n      }\n    };\n\n    template <typename Type, Type E\
    \ = ::std::numeric_limits<Type>::max()>\n    struct min {\n      using T = Type;\n\
    \      static T op(const T lhs, const T rhs) {\n        return ::std::min(lhs,\
    \ rhs);\n      }\n      static T e() {\n        return E;\n      }\n    };\n\n\
    \    template <typename Type>\n    struct multiplies {\n      using T = Type;\n\
    \      static T op(const T lhs, const T rhs) {\n        return lhs * rhs;\n  \
    \    }\n      static T e() {\n        return T(1);\n      }\n    };\n\n    template\
    \ <typename Type>\n    struct gcd {\n      using T = Type;\n      static T op(const\
    \ T lhs, const T rhs) {\n        return ::std::gcd(lhs, rhs);\n      }\n     \
    \ static T e() {\n        return T(0);\n      }\n    };\n\n    template <typename\
    \ Type, Type E>\n    struct update {\n      using T = Type;\n      static T op(const\
    \ T lhs, const T rhs) {\n        return lhs == E ? rhs : lhs;\n      }\n     \
    \ static T e() {\n        return E;\n      }\n    };\n  }\n}\n\n\n#line 5 \"tools/square.hpp\"\
    \n\nnamespace tools {\n\n  template <typename M>\n  typename M::T square(const\
    \ typename M::T& x) {\n    return M::op(x, x);\n  }\n\n  template <typename T>\n\
    \  T square(const T& x) {\n    return ::tools::square<::tools::monoid::multiplies<T>>(x);\n\
    \  }\n}\n\n\n#line 23 \"tools/detail/geometry_2d.hpp\"\n\nnamespace tools {\n\
    \  template <typename T, bool Filled, bool HasRadius = true>\n  class circle_2d;\n\
    \n  template <typename T>\n  class directed_line_segment_2d;\n\n  template <typename\
    \ T>\n  class half_line_2d;\n\n  template <typename T>\n  class line_2d;\n\n \
    \ template <typename T, bool Filled>\n  class polygon_2d;\n\n  template <typename\
    \ T, bool Filled>\n  class triangle_2d;\n\n  template <typename T, bool Filled,\
    \ bool HasRadius>\n  class circle_2d {\n  private:\n    ::tools::vector2<T> m_center;\n\
    \    T m_radius;\n    T m_squared_radius;\n\n  public:\n    circle_2d() = default;\n\
    \    circle_2d(const ::tools::circle_2d<T, Filled, HasRadius>&) = default;\n \
    \   circle_2d(::tools::circle_2d<T, Filled, HasRadius>&&) = default;\n    ~circle_2d()\
    \ = default;\n    ::tools::circle_2d<T, Filled, HasRadius>& operator=(const ::tools::circle_2d<T,\
    \ Filled, HasRadius>&) = default;\n    ::tools::circle_2d<T, Filled, HasRadius>&\
    \ operator=(::tools::circle_2d<T, Filled, HasRadius>&&) = default;\n\n    circle_2d(const\
    \ ::tools::vector2<T>& center, const T& radius_or_squared_radius);\n\n    template\
    \ <typename T_ = T, bool Filled_ = Filled>\n    ::std::enable_if_t<::std::is_floating_point_v<T_>\
    \ && Filled_, T> area() const;\n    ::tools::vector2<T> center() const;\n    template\
    \ <bool HasRadius_ = HasRadius>\n    ::std::enable_if_t<HasRadius_, T> radius()\
    \ const;\n    T squared_radius() const;\n    ::std::pair<int, int> where(const\
    \ ::tools::circle_2d<T, Filled, HasRadius>& other) const;\n    int where(const\
    \ ::tools::vector2<T>& p) const;\n\n    template <typename T_, bool HasRadius_>\n\
    \    friend ::std::enable_if_t<::std::is_floating_point_v<T_>, ::std::vector<::tools::vector2<T_>>>\n\
    \    operator&(const ::tools::circle_2d<T_, false, HasRadius_>& lhs, const ::tools::line_2d<T_>&\
    \ rhs);\n    template <typename T_, bool HasRadius_>\n    friend ::std::enable_if_t<::std::is_floating_point_v<T_>,\
    \ ::std::optional<::std::variant<::tools::vector2<T_>, ::tools::directed_line_segment_2d<T_>>>>\n\
    \    operator&(const ::tools::circle_2d<T_, true, HasRadius_>& lhs, const ::tools::line_2d<T_>&\
    \ rhs);\n    template <typename T_, bool Filled_, bool HasRadius1, bool HasRadius2>\n\
    \    friend bool operator==(const ::tools::circle_2d<T_, Filled_, HasRadius1>&\
    \ lhs, const ::tools::circle_2d<T_, Filled_, HasRadius2>& rhs);\n    template\
    \ <typename T_, bool Filled_, bool HasRadius1, bool HasRadius2>\n    friend bool\
    \ operator!=(const ::tools::circle_2d<T_, Filled_, HasRadius1>& lhs, const ::tools::circle_2d<T_,\
    \ Filled_, HasRadius2>& rhs);\n  };\n\n  template <typename T>\n  class directed_line_segment_2d\
    \ {\n  private:\n    ::tools::vector2<T> m_p1;\n    ::tools::vector2<T> m_p2;\n\
    \n  public:\n    directed_line_segment_2d() = default;\n    directed_line_segment_2d(const\
    \ ::tools::directed_line_segment_2d<T>&) = default;\n    directed_line_segment_2d(::tools::directed_line_segment_2d<T>&&)\
    \ = default;\n    ~directed_line_segment_2d() = default;\n    ::tools::directed_line_segment_2d<T>&\
    \ operator=(const ::tools::directed_line_segment_2d<T>&) = default;\n    ::tools::directed_line_segment_2d<T>&\
    \ operator=(::tools::directed_line_segment_2d<T>&&) = default;\n\n    directed_line_segment_2d(const\
    \ ::tools::vector2<T>& p1, const ::tools::vector2<T>& p2);\n\n    bool contains(const\
    \ ::tools::vector2<T>& p) const;\n    ::std::conditional_t<::std::is_floating_point_v<T>,\
    \ T, double> length() const; \n    template <typename T_ = T>\n    ::std::enable_if_t<::tools::is_rational_v<T_>\
    \ || ::std::is_floating_point_v<T_>, ::std::optional<::tools::vector2<T>>>\n \
    \   cross_point(const ::tools::directed_line_segment_2d<T>& other) const;\n  \
    \  template <typename T_ = T>\n    ::std::enable_if_t<::tools::is_rational_v<T_>\
    \ || ::std::is_floating_point_v<T_>, ::std::optional<::tools::vector2<T>>>\n \
    \   cross_point(const ::tools::half_line_2d<T>& other) const;\n    template <typename\
    \ T_ = T>\n    ::std::enable_if_t<::tools::is_rational_v<T_> || ::std::is_floating_point_v<T_>,\
    \ ::std::optional<::tools::vector2<T>>>\n    cross_point(const ::tools::line_2d<T>&\
    \ other) const;\n    template <typename T_ = T>\n    ::std::enable_if_t<::tools::is_rational_v<T_>\
    \ || ::std::is_floating_point_v<T_>, ::tools::vector2<T>>\n    midpoint() const;\n\
    \    const ::tools::vector2<T>& p1() const;\n    const ::tools::vector2<T>& p2()\
    \ const;\n    template <typename T_ = T>\n    ::std::enable_if_t<::tools::is_rational_v<T_>\
    \ || ::std::is_floating_point_v<T_>, T>\n    squared_distance(const ::tools::directed_line_segment_2d<T>&\
    \ other) const;\n    template <typename T_ = T>\n    ::std::enable_if_t<::tools::is_rational_v<T_>\
    \ || ::std::is_floating_point_v<T_>, T>\n    squared_distance(const ::tools::half_line_2d<T>&\
    \ other) const;\n    template <typename T_ = T>\n    ::std::enable_if_t<::tools::is_rational_v<T_>\
    \ || ::std::is_floating_point_v<T_>, T>\n    squared_distance(const ::tools::line_2d<T>&\
    \ other) const;\n    template <typename T_ = T>\n    ::std::enable_if_t<::tools::is_rational_v<T_>\
    \ || ::std::is_floating_point_v<T_>, T>\n    squared_distance(const ::tools::vector2<T>&\
    \ p) const;\n    T squared_length() const;\n    ::tools::half_line_2d<T> to_half_line()\
    \ const;\n    ::tools::line_2d<T> to_line() const;\n    ::tools::vector2<T> to_vector()\
    \ const;\n\n    ::tools::directed_line_segment_2d<T> operator+() const;\n    ::tools::directed_line_segment_2d<T>\
    \ operator-() const;\n    template <typename T_>\n    friend ::std::enable_if_t<::tools::is_rational_v<T_>\
    \ || ::std::is_floating_point_v<T_>, ::std::optional<::std::variant<::tools::vector2<T_>,\
    \ ::tools::directed_line_segment_2d<T_>>>>\n    operator&(const ::tools::directed_line_segment_2d<T_>&\
    \ lhs, const ::tools::directed_line_segment_2d<T_>& rhs);\n    template <typename\
    \ T_>\n    friend ::std::enable_if_t<::tools::is_rational_v<T_> || ::std::is_floating_point_v<T_>,\
    \ ::std::optional<::std::variant<::tools::vector2<T_>, ::tools::directed_line_segment_2d<T_>>>>\n\
    \    operator&(const ::tools::directed_line_segment_2d<T_>& lhs, const ::tools::half_line_2d<T_>&\
    \ rhs);\n    template <typename T_>\n    friend ::std::enable_if_t<::tools::is_rational_v<T_>\
    \ || ::std::is_floating_point_v<T_>, ::std::optional<::std::variant<::tools::vector2<T_>,\
    \ ::tools::directed_line_segment_2d<T_>>>>\n    operator&(const ::tools::directed_line_segment_2d<T_>&\
    \ lhs, const ::tools::line_2d<T_>& rhs);\n    template <typename T_>\n    friend\
    \ bool operator==(const ::tools::directed_line_segment_2d<T_>& lhs, const ::tools::directed_line_segment_2d<T_>&\
    \ rhs);\n    template <typename T_>\n    friend bool operator!=(const ::tools::directed_line_segment_2d<T_>&\
    \ lhs, const ::tools::directed_line_segment_2d<T_>& rhs);\n  };\n\n  template\
    \ <typename T>\n  class half_line_2d {\n  private:\n    ::tools::vector2<T> m_a;\n\
    \    ::tools::vector2<T> m_d;\n\n  public:\n    half_line_2d() = default;\n  \
    \  half_line_2d(const ::tools::half_line_2d<T>&) = default;\n    half_line_2d(::tools::half_line_2d<T>&&)\
    \ = default;\n    ~half_line_2d() = default;\n    ::tools::half_line_2d<T>& operator=(const\
    \ ::tools::half_line_2d<T>&) = default;\n    ::tools::half_line_2d<T>& operator=(::tools::half_line_2d<T>&&)\
    \ = default;\n\n    half_line_2d(const ::tools::vector2<T>& a, const ::tools::vector2<T>&\
    \ d);\n\n    const ::tools::vector2<T>& a() const;\n    bool contains(const ::tools::vector2<T>&\
    \ p) const;\n    template <typename T_ = T>\n    ::std::enable_if_t<::tools::is_rational_v<T_>\
    \ || ::std::is_floating_point_v<T_>, ::std::optional<::tools::vector2<T>>>\n \
    \   cross_point(const ::tools::directed_line_segment_2d<T>& other) const;\n  \
    \  template <typename T_ = T>\n    ::std::enable_if_t<::tools::is_rational_v<T_>\
    \ || ::std::is_floating_point_v<T_>, ::std::optional<::tools::vector2<T>>>\n \
    \   cross_point(const ::tools::half_line_2d<T>& other) const;\n    template <typename\
    \ T_ = T>\n    ::std::enable_if_t<::tools::is_rational_v<T_> || ::std::is_floating_point_v<T_>,\
    \ ::std::optional<::tools::vector2<T>>>\n    cross_point(const ::tools::line_2d<T>&\
    \ other) const;\n    const ::tools::vector2<T>& d() const;\n    template <typename\
    \ T_ = T>\n    ::std::enable_if_t<::tools::is_rational_v<T_> || ::std::is_floating_point_v<T_>,\
    \ T>\n    squared_distance(const ::tools::directed_line_segment_2d<T>& other)\
    \ const;\n    template <typename T_ = T>\n    ::std::enable_if_t<::tools::is_rational_v<T_>\
    \ || ::std::is_floating_point_v<T_>, T>\n    squared_distance(const ::tools::half_line_2d<T>&\
    \ other) const;\n    template <typename T_ = T>\n    ::std::enable_if_t<::tools::is_rational_v<T_>\
    \ || ::std::is_floating_point_v<T_>, T>\n    squared_distance(const ::tools::line_2d<T>&\
    \ other) const;\n    template <typename T_ = T>\n    ::std::enable_if_t<::tools::is_rational_v<T_>\
    \ || ::std::is_floating_point_v<T_>, T>\n    squared_distance(const ::tools::vector2<T>&\
    \ p) const;\n    ::tools::line_2d<T> to_line() const;\n\n    template <typename\
    \ T_>\n    friend ::std::enable_if_t<::tools::is_rational_v<T_> || ::std::is_floating_point_v<T_>,\
    \ ::std::optional<::std::variant<::tools::vector2<T_>, ::tools::directed_line_segment_2d<T_>>>>\n\
    \    operator&(const ::tools::half_line_2d<T_>& lhs, const ::tools::directed_line_segment_2d<T_>&\
    \ rhs);\n    template <typename T_>\n    friend ::std::enable_if_t<::tools::is_rational_v<T_>\
    \ || ::std::is_floating_point_v<T_>, ::std::optional<::std::variant<::tools::vector2<T_>,\
    \ ::tools::directed_line_segment_2d<T_>, ::tools::half_line_2d<T_>>>>\n    operator&(const\
    \ ::tools::half_line_2d<T_>& lhs, const ::tools::half_line_2d<T_>& rhs);\n   \
    \ template <typename T_>\n    friend ::std::enable_if_t<::tools::is_rational_v<T_>\
    \ || ::std::is_floating_point_v<T_>, ::std::optional<::std::variant<::tools::vector2<T_>,\
    \ ::tools::half_line_2d<T_>>>>\n    operator&(const ::tools::half_line_2d<T_>&\
    \ lhs, const ::tools::line_2d<T_>& rhs);\n    template <typename T_>\n    friend\
    \ bool operator==(const ::tools::half_line_2d<T_>& lhs, const ::tools::half_line_2d<T_>&\
    \ rhs);\n    template <typename T_>\n    friend bool operator!=(const ::tools::half_line_2d<T_>&\
    \ lhs, const ::tools::half_line_2d<T_>& rhs);\n  };\n\n  template <typename T>\n\
    \  class line_2d {\n  private:\n    T m_a;\n    T m_b;\n    T m_c;\n\n  public:\n\
    \    line_2d() = default;\n    line_2d(const ::tools::line_2d<T>&) = default;\n\
    \    line_2d(::tools::line_2d<T>&&) = default;\n    ~line_2d() = default;\n  \
    \  ::tools::line_2d<T>& operator=(const ::tools::line_2d<T>&) = default;\n   \
    \ ::tools::line_2d<T>& operator=(::tools::line_2d<T>&&) = default;\n\n    line_2d(const\
    \ T& a, const T& b, const T& c);\n\n    const T& a() const;\n    const T& b()\
    \ const;\n    const T& c() const;\n    bool contains(const ::tools::vector2<T>&\
    \ p) const;\n    template <typename T_ = T>\n    ::std::enable_if_t<::tools::is_rational_v<T_>\
    \ || ::std::is_floating_point_v<T_>, ::std::optional<::tools::vector2<T>>>\n \
    \   cross_point(const ::tools::directed_line_segment_2d<T>& other) const;\n  \
    \  template <typename T_ = T>\n    ::std::enable_if_t<::tools::is_rational_v<T_>\
    \ || ::std::is_floating_point_v<T_>, ::std::optional<::tools::vector2<T>>>\n \
    \   cross_point(const ::tools::half_line_2d<T>& other) const;\n    template <typename\
    \ T_ = T>\n    ::std::enable_if_t<::tools::is_rational_v<T_> || ::std::is_floating_point_v<T_>,\
    \ ::std::optional<::tools::vector2<T>>>\n    cross_point(const ::tools::line_2d<T>&\
    \ other) const;\n    bool crosses(const ::tools::line_2d<T>& other) const;\n \
    \   bool is_parallel_to(const ::tools::line_2d<T>& other) const;\n    ::tools::vector2<T>\
    \ normal() const;\n    template <typename T_ = T>\n    ::std::enable_if_t<::tools::is_rational_v<T_>\
    \ || ::std::is_floating_point_v<T_>, ::tools::vector2<T>>\n    projection(const\
    \ ::tools::vector2<T>& p) const;\n    template <typename T_ = T>\n    ::std::enable_if_t<::tools::is_rational_v<T_>\
    \ || ::std::is_floating_point_v<T_>, T>\n    squared_distance(const ::tools::directed_line_segment_2d<T>&\
    \ other) const;\n    template <typename T_ = T>\n    ::std::enable_if_t<::tools::is_rational_v<T_>\
    \ || ::std::is_floating_point_v<T_>, T>\n    squared_distance(const ::tools::half_line_2d<T>&\
    \ other) const;\n    template <typename T_ = T>\n    ::std::enable_if_t<::tools::is_rational_v<T_>\
    \ || ::std::is_floating_point_v<T_>, T>\n    squared_distance(const ::tools::line_2d<T>&\
    \ other) const;\n    template <typename T_ = T>\n    ::std::enable_if_t<::tools::is_rational_v<T_>\
    \ || ::std::is_floating_point_v<T_>, T>\n    squared_distance(const ::tools::vector2<T>&\
    \ p) const;\n\n    template <typename T_, bool HasRadius_>\n    friend ::std::enable_if_t<::std::is_floating_point_v<T_>,\
    \ ::std::vector<::tools::vector2<T_>>>\n    operator&(const ::tools::line_2d<T_>&\
    \ lhs, const ::tools::circle_2d<T_, false, HasRadius_>& rhs);\n    template <typename\
    \ T_, bool HasRadius_>\n    friend ::std::enable_if_t<::std::is_floating_point_v<T_>,\
    \ ::std::optional<::std::variant<::tools::vector2<T_>, ::tools::directed_line_segment_2d<T_>>>>\n\
    \    operator&(const ::tools::line_2d<T_>& lhs, const ::tools::circle_2d<T_, true,\
    \ HasRadius_>& rhs);\n    template <typename T_>\n    friend ::std::enable_if_t<::tools::is_rational_v<T_>\
    \ || ::std::is_floating_point_v<T_>, ::std::optional<::std::variant<::tools::vector2<T_>,\
    \ ::tools::directed_line_segment_2d<T_>>>>\n    operator&(const ::tools::line_2d<T_>&\
    \ lhs, const ::tools::directed_line_segment_2d<T_>& rhs);\n    template <typename\
    \ T_>\n    friend ::std::enable_if_t<::tools::is_rational_v<T_> || ::std::is_floating_point_v<T_>,\
    \ ::std::optional<::std::variant<::tools::vector2<T_>, ::tools::half_line_2d<T_>>>>\n\
    \    operator&(const ::tools::line_2d<T_>& lhs, const ::tools::half_line_2d<T_>&\
    \ rhs);\n    template <typename T_>\n    friend ::std::enable_if_t<::tools::is_rational_v<T_>\
    \ || ::std::is_floating_point_v<T_>, ::std::optional<::std::variant<::tools::vector2<T_>,\
    \ ::tools::line_2d<T_>>>>\n    operator&(const ::tools::line_2d<T_>& lhs, const\
    \ ::tools::line_2d<T_>& rhs);\n    template <typename T_>\n    friend bool operator==(const\
    \ ::tools::line_2d<T_>& lhs, const ::tools::line_2d<T_>& rhs);\n    template <typename\
    \ T_>\n    friend bool operator!=(const ::tools::line_2d<T_>& lhs, const ::tools::line_2d<T_>&\
    \ rhs);\n\n    static ::tools::line_2d<T> through(const ::tools::vector2<T>& p1,\
    \ const ::tools::vector2<T>& p2);\n  };\n\n  template <typename T, bool Filled>\n\
    \  class polygon_2d {\n  protected:\n    ::std::vector<::tools::vector2<T>> m_points;\n\
    \    T doubled_signed_area() const;\n\n  public:\n    polygon_2d() = default;\n\
    \    polygon_2d(const ::tools::polygon_2d<T, Filled>&) = default;\n    polygon_2d(::tools::polygon_2d<T,\
    \ Filled>&&) = default;\n    ~polygon_2d() = default;\n    ::tools::polygon_2d<T,\
    \ Filled>& operator=(const ::tools::polygon_2d<T, Filled>&) = default;\n    ::tools::polygon_2d<T,\
    \ Filled>& operator=(::tools::polygon_2d<T, Filled>&&) = default;\n\n    template\
    \ <typename InputIterator>\n    polygon_2d(const InputIterator& begin, const InputIterator&\
    \ end);\n    polygon_2d(::std::initializer_list<::tools::vector2<T>> init);\n\n\
    \    template <typename T_ = T, bool Filled_ = Filled>\n    ::std::enable_if_t<(::tools::is_rational_v<T_>\
    \ || ::std::is_floating_point_v<T_>) && Filled_, T> area() const;\n    template\
    \ <bool Filled_ = Filled>\n    ::std::enable_if_t<Filled_, T> doubled_area() const;\n\
    \    bool is_counterclockwise() const;\n    template <typename T_ = T>\n    ::std::enable_if_t<::tools::is_rational_v<T_>\
    \ || ::std::is_floating_point_v<T_>, ::tools::circle_2d<T, Filled, false>> minimum_bounding_circle()\
    \ const;\n    int where(const ::tools::vector2<T>& p) const;\n  };\n\n  template\
    \ <typename T, bool Filled>\n  class triangle_2d : public polygon_2d<T, Filled>\
    \ {\n  private:\n    template <typename OutputIterator>\n    void sorted_edges(OutputIterator\
    \ result) const;\n\n  public:\n    triangle_2d() = default;\n    triangle_2d(const\
    \ ::tools::triangle_2d<T, Filled>&) = default;\n    triangle_2d(::tools::triangle_2d<T,\
    \ Filled>&&) = default;\n    ~triangle_2d() = default;\n    ::tools::triangle_2d<T,\
    \ Filled>& operator=(const ::tools::triangle_2d<T, Filled>&) = default;\n    ::tools::triangle_2d<T,\
    \ Filled>& operator=(::tools::triangle_2d<T, Filled>&&) = default;\n\n    template\
    \ <typename InputIterator>\n    triangle_2d(const InputIterator& begin, const\
    \ InputIterator& end);\n    triangle_2d(::std::initializer_list<::tools::vector2<T>>\
    \ init);\n\n    template <typename T_ = T>\n    ::std::enable_if_t<::tools::is_rational_v<T_>\
    \ || ::std::is_floating_point_v<T_>, ::tools::circle_2d<T, Filled, false>> circumcircle()\
    \ const;\n    template <typename T_ = T>\n    ::std::enable_if_t<::std::is_floating_point_v<T_>,\
    \ ::tools::circle_2d<T, Filled>> incircle() const;\n    template <typename T_\
    \ = T>\n    ::std::enable_if_t<::tools::is_rational_v<T_> || ::std::is_floating_point_v<T_>,\
    \ ::tools::circle_2d<T, Filled, false>> minimum_bounding_circle() const;\n   \
    \ int type() const;\n  };\n\n  template <typename T, bool Filled, bool HasRadius>\n\
    \  circle_2d<T, Filled, HasRadius>::circle_2d(const ::tools::vector2<T>& center,\
    \ const T& radius_or_squared_radius) : m_center(center) {\n    assert(radius_or_squared_radius\
    \ > T(0));\n    if constexpr (HasRadius) {\n      this->m_radius = radius_or_squared_radius;\n\
    \      this->m_squared_radius = ::tools::square(this->m_radius);\n    } else {\n\
    \      this->m_squared_radius = radius_or_squared_radius;\n    }\n  }\n\n  template\
    \ <typename T, bool Filled, bool HasRadius> template <typename T_, bool Filled_>\n\
    \  ::std::enable_if_t<::std::is_floating_point_v<T_> && Filled_, T> circle_2d<T,\
    \ Filled, HasRadius>::area() const {\n    return ::std::acos(T(-1)) * this->m_squared_radius;\n\
    \  }\n\n  template <typename T, bool Filled, bool HasRadius>\n  ::tools::vector2<T>\
    \ circle_2d<T, Filled, HasRadius>::center() const {\n    return this->m_center;\n\
    \  }\n\n  template <typename T, bool Filled, bool HasRadius> template <bool HasRadius_>\n\
    \  ::std::enable_if_t<HasRadius_, T> circle_2d<T, Filled, HasRadius>::radius()\
    \ const {\n    return this->m_radius;\n  }\n\n  template <typename T, bool Filled,\
    \ bool HasRadius>\n  T circle_2d<T, Filled, HasRadius>::squared_radius() const\
    \ {\n    return this->m_squared_radius;\n  }\n\n  template <typename T, bool Filled,\
    \ bool HasRadius>\n  ::std::pair<int, int> circle_2d<T, Filled, HasRadius>::where(const\
    \ ::tools::circle_2d<T, Filled, HasRadius>& other) const {\n    return ::std::make_pair([&]()\
    \ {\n      if (*this == other) {\n        return ::std::numeric_limits<int>::max();\n\
    \      }\n      if constexpr (HasRadius) {\n        const auto d2 = (this->m_center\
    \ - other.m_center).squared_l2_norm();\n        const auto& a_r = this->m_radius;\n\
    \        const auto& b_r = other.m_radius;\n        const ::std::array<T, 2> threshold\
    \ = {::tools::square(a_r - b_r), ::tools::square(a_r + b_r)};\n        if (d2\
    \ < threshold[0]) {\n          return 0;\n        } else if (d2 == threshold[0])\
    \ {\n          return 1;\n        } else if (d2 == threshold[1]) {\n         \
    \ return 3;\n        } else if (threshold[1] < d2) {\n          return 4;\n  \
    \      } else {\n          return 2;\n        }\n      } else {\n        const\
    \ auto d2 = (this->m_center - other.m_center).squared_l2_norm();\n        const\
    \ auto& a_r2 = this->m_squared_radius;\n        const auto& b_r2 = other.m_squared_radius;\n\
    \        const auto threshold = a_r2 + b_r2 - d2;\n        const auto squared_threshold\
    \ = ::tools::square(threshold);\n        const auto v = T(4) * a_r2 * b_r2;\n\
    \        if (threshold > T(0) && v < squared_threshold) {\n          return 0;\n\
    \        } else if (threshold > T(0) && v == squared_threshold) {\n          return\
    \ 1;\n        } else if (threshold < T(0) && v == squared_threshold) {\n     \
    \     return 3;\n        } else if (threshold < T(0) && v < squared_threshold)\
    \ {\n          return 4;\n        } else {\n          return 2;\n        }\n \
    \     }\n    }(), ::tools::signum(this->m_squared_radius - other.m_squared_radius));\n\
    \  }\n\n  template <typename T, bool Filled, bool HasRadius>\n  int circle_2d<T,\
    \ Filled, HasRadius>::where(const ::tools::vector2<T>& p) const {\n    return\
    \ ::tools::signum(this->m_squared_radius - (p - this->m_center).squared_l2_norm());\n\
    \  }\n\n  template <typename T, bool HasRadius>\n  ::std::enable_if_t<::std::is_floating_point_v<T>,\
    \ ::std::vector<::tools::vector2<T>>>\n  operator&(const ::tools::circle_2d<T,\
    \ false, HasRadius>& lhs, const ::tools::line_2d<T>& rhs) {\n    using result_t\
    \ = ::std::vector<::tools::vector2<T>>;\n    if (const auto intersection = ::tools::circle_2d<T,\
    \ true, HasRadius>(lhs.m_center, HasRadius ? lhs.m_radius : lhs.m_squared_radius)\
    \ & rhs; intersection) {\n      struct {\n        result_t operator()(const ::tools::vector2<T>&\
    \ v) {\n          return result_t({v});\n        }\n        result_t operator()(const\
    \ ::tools::directed_line_segment_2d<T>& s) {\n          return result_t({s.p1(),\
    \ s.p2()});\n        }\n      } visitor;\n      return ::std::visit(visitor, *intersection);\n\
    \    } else {\n      return result_t();\n    }\n  }\n\n  template <typename T,\
    \ bool HasRadius>\n  ::std::enable_if_t<::std::is_floating_point_v<T>, ::std::optional<::std::variant<::tools::vector2<T>,\
    \ ::tools::directed_line_segment_2d<T>>>>\n  operator&(const ::tools::circle_2d<T,\
    \ true, HasRadius>& lhs, const ::tools::line_2d<T>& rhs) {\n    using variant_t\
    \ = ::std::variant<::tools::vector2<T>, ::tools::directed_line_segment_2d<T>>;\n\
    \    using result_t = ::std::optional<variant_t>;\n\n    const auto [a, b, c]\
    \ = (rhs.projection(lhs.m_center) - lhs.m_center).inner_product(rhs.normal())\
    \ >= T(0) ? ::std::make_tuple(rhs.a(), rhs.b(), rhs.c()) : ::std::make_tuple(-rhs.a(),\
    \ -rhs.b(), -rhs.c());\n    const auto& x = lhs.m_center.x;\n    const auto& y\
    \ = lhs.m_center.y;\n    const auto r = HasRadius ? lhs.m_radius : ::std::sqrt(lhs.m_squared_radius);\n\
    \    const auto& r2 = lhs.m_squared_radius;\n    const auto d2 = rhs.squared_distance(lhs.m_center);\n\
    \n    if (d2 < r2) {\n      const auto D = ::std::abs(a * x + b * y + c);\n  \
    \    return result_t(variant_t(::tools::directed_line_segment_2d<T>(\n       \
    \ ::tools::vector2<T>((a * D - b * ::std::sqrt((a * a + b * b) * r2 - D * D))\
    \ / (a * a + b * b) + x, (b * D + a * ::std::sqrt((a * a + b * b) * r2 - D * D))\
    \ / (a * a + b * b) + y),\n        ::tools::vector2<T>((a * D + b * ::std::sqrt((a\
    \ * a + b * b) * r2 - D * D)) / (a * a + b * b) + x, (b * D - a * ::std::sqrt((a\
    \ * a + b * b) * r2 - D * D)) / (a * a + b * b) + y)\n      )));\n    } else if\
    \ (d2 == r2) {\n      return result_t(variant_t(::tools::vector2<T>(a * r / ::std::sqrt(a\
    \ * a + b * b) + x, b * r / ::std::sqrt(a * a + b * b) + y)));\n    } else {\n\
    \      return ::std::nullopt;\n    }\n  }\n\n  template <typename T, bool Filled,\
    \ bool HasRadius1, bool HasRadius2>\n  bool operator==(const ::tools::circle_2d<T,\
    \ Filled, HasRadius1>& lhs, const ::tools::circle_2d<T, Filled, HasRadius2>& rhs)\
    \ {\n    return lhs.m_center == rhs.m_center && lhs.m_squared_radius == rhs.m_squared_radius;\n\
    \  }\n\n  template <typename T, bool Filled, bool HasRadius1, bool HasRadius2>\n\
    \  bool operator!=(const ::tools::circle_2d<T, Filled, HasRadius1>& lhs, const\
    \ ::tools::circle_2d<T, Filled, HasRadius2>& rhs) {\n    return !(lhs == rhs);\n\
    \  }\n\n  template <typename T>\n  directed_line_segment_2d<T>::directed_line_segment_2d(const\
    \ ::tools::vector2<T>& p1, const ::tools::vector2<T>& p2) :\n    m_p1(p1),\n \
    \   m_p2(p2) {\n    assert(p1 != p2);\n  }\n\n  template <typename T>\n  bool\
    \ directed_line_segment_2d<T>::contains(const ::tools::vector2<T>& p) const {\n\
    \    if (p == this->m_p1 || p == this->m_p2) return true;\n    const ::tools::line_2d<T>\
    \ l = this->to_line();\n    if (!l.contains(p)) return false;\n    const T d =\
    \ (p - this->m_p1).inner_product(this->to_vector());\n    return T(0) <= d &&\
    \ d <= this->squared_length();\n  }\n\n  template <typename T> template <typename\
    \ T_>\n  ::std::enable_if_t<::tools::is_rational_v<T_> || ::std::is_floating_point_v<T_>,\
    \ ::std::optional<::tools::vector2<T>>>\n  directed_line_segment_2d<T>::cross_point(const\
    \ ::tools::directed_line_segment_2d<T>& other) const {\n    using result_t = ::std::optional<::tools::vector2<T>>;\n\
    \    const auto intersection = *this & other;\n    struct {\n      result_t operator()(const\
    \ ::tools::vector2<T>& v) {\n        return result_t(v);\n      }\n      result_t\
    \ operator()(const ::tools::directed_line_segment_2d<T>&) {\n        return ::std::nullopt;\n\
    \      }\n    } visitor;\n    return intersection ? ::std::visit(visitor, *intersection)\
    \ : ::std::nullopt;\n  }\n\n  template <typename T> template <typename T_>\n \
    \ ::std::enable_if_t<::tools::is_rational_v<T_> || ::std::is_floating_point_v<T_>,\
    \ ::std::optional<::tools::vector2<T>>>\n  directed_line_segment_2d<T>::cross_point(const\
    \ ::tools::half_line_2d<T>& other) const {\n    using result_t = ::std::optional<::tools::vector2<T>>;\n\
    \    const auto intersection = *this & other;\n    struct {\n      result_t operator()(const\
    \ ::tools::vector2<T>& v) {\n        return result_t(v);\n      }\n      result_t\
    \ operator()(const ::tools::directed_line_segment_2d<T>&) {\n        return ::std::nullopt;\n\
    \      }\n    } visitor;\n    return intersection ? ::std::visit(visitor, *intersection)\
    \ : ::std::nullopt;\n  }\n\n  template <typename T> template <typename T_>\n \
    \ ::std::enable_if_t<::tools::is_rational_v<T_> || ::std::is_floating_point_v<T_>,\
    \ ::std::optional<::tools::vector2<T>>>\n  directed_line_segment_2d<T>::cross_point(const\
    \ ::tools::line_2d<T>& other) const {\n    using result_t = ::std::optional<::tools::vector2<T>>;\n\
    \    const auto intersection = *this & other;\n    struct {\n      result_t operator()(const\
    \ ::tools::vector2<T>& v) {\n        return result_t(v);\n      }\n      result_t\
    \ operator()(const ::tools::directed_line_segment_2d<T>&) {\n        return result_t();\n\
    \      }\n    } visitor;\n    return intersection ? ::std::visit(visitor, *intersection)\
    \ : ::std::nullopt;\n  }\n\n  template <typename T>\n  ::std::conditional_t<::std::is_floating_point_v<T>,\
    \ T, double> directed_line_segment_2d<T>::length() const {\n    return this->to_vector().l2_norm();\n\
    \  }\n\n  template <typename T> template <typename T_>\n  ::std::enable_if_t<::tools::is_rational_v<T_>\
    \ || ::std::is_floating_point_v<T_>, ::tools::vector2<T>>\n  directed_line_segment_2d<T>::midpoint()\
    \ const {\n    return (this->m_p1 + this->m_p2) / T(2);\n  }\n\n  template <typename\
    \ T>\n  const ::tools::vector2<T>& directed_line_segment_2d<T>::p1() const {\n\
    \    return this->m_p1;\n  }\n\n  template <typename T>\n  const ::tools::vector2<T>&\
    \ directed_line_segment_2d<T>::p2() const {\n    return this->m_p2;\n  }\n\n \
    \ template <typename T> template <typename T_>\n  ::std::enable_if_t<::tools::is_rational_v<T_>\
    \ || ::std::is_floating_point_v<T_>, T>\n  directed_line_segment_2d<T>::squared_distance(const\
    \ ::tools::directed_line_segment_2d<T>& other) const {\n    if (*this & other)\
    \ {\n      return T(0);\n    }\n    return ::std::min({\n      other.squared_distance(this->m_p1),\n\
    \      other.squared_distance(this->m_p2),\n      this->squared_distance(other.m_p1),\n\
    \      this->squared_distance(other.m_p2)\n    });\n  }\n\n  template <typename\
    \ T> template <typename T_>\n  ::std::enable_if_t<::tools::is_rational_v<T_> ||\
    \ ::std::is_floating_point_v<T_>, T>\n  directed_line_segment_2d<T>::squared_distance(const\
    \ ::tools::half_line_2d<T>& other) const {\n    if (*this & other) {\n      return\
    \ T(0);\n    }\n    return ::std::min({\n      other.squared_distance(this->m_p1),\n\
    \      other.squared_distance(this->m_p2)\n    });\n  }\n\n  template <typename\
    \ T> template <typename T_>\n  ::std::enable_if_t<::tools::is_rational_v<T_> ||\
    \ ::std::is_floating_point_v<T_>, T>\n  directed_line_segment_2d<T>::squared_distance(const\
    \ ::tools::line_2d<T>& other) const {\n    if (*this & other) {\n      return\
    \ T(0);\n    }\n    return ::std::min({\n      other.squared_distance(this->m_p1),\n\
    \      other.squared_distance(this->m_p2)\n    });\n  }\n\n  template <typename\
    \ T> template <typename T_>\n  ::std::enable_if_t<::tools::is_rational_v<T_> ||\
    \ ::std::is_floating_point_v<T_>, T>\n  directed_line_segment_2d<T>::squared_distance(const\
    \ ::tools::vector2<T>& p) const {\n    const auto x = this->to_line().projection(p);\n\
    \    const auto d = this->to_vector().inner_product(x - this->m_p1);\n    return\
    \ (p - (d < T(0) ? this->m_p1 : this->squared_length() < d ? this->m_p2 : x)).squared_l2_norm();\n\
    \  }\n\n  template <typename T>\n  T directed_line_segment_2d<T>::squared_length()\
    \ const {\n    return this->to_vector().squared_l2_norm();\n  }\n\n  template\
    \ <typename T>\n  ::tools::half_line_2d<T> directed_line_segment_2d<T>::to_half_line()\
    \ const {\n    return ::tools::half_line_2d<T>(this->m_p1, this->m_p2 - this->m_p1);\n\
    \  }\n\n  template <typename T>\n  ::tools::line_2d<T> directed_line_segment_2d<T>::to_line()\
    \ const {\n    return ::tools::line_2d<T>::through(this->m_p1, this->m_p2);\n\
    \  }\n\n  template <typename T>\n  ::tools::vector2<T> directed_line_segment_2d<T>::to_vector()\
    \ const {\n    return this->m_p2 - this->m_p1;\n  }\n\n  template <typename T>\n\
    \  ::tools::directed_line_segment_2d<T> directed_line_segment_2d<T>::operator+()\
    \ const {\n    return *this;\n  }\n\n  template <typename T>\n  ::tools::directed_line_segment_2d<T>\
    \ directed_line_segment_2d<T>::operator-() const {\n    return ::tools::directed_line_segment_2d<T>(this->m_p2,\
    \ this->m_p1);\n  }\n\n  template <typename T>\n  ::std::enable_if_t<::tools::is_rational_v<T>\
    \ || ::std::is_floating_point_v<T>, ::std::optional<::std::variant<::tools::vector2<T>,\
    \ ::tools::directed_line_segment_2d<T>>>>\n  operator&(const ::tools::directed_line_segment_2d<T>&\
    \ lhs, const ::tools::directed_line_segment_2d<T>& rhs) {\n    using variant_t\
    \ = ::std::variant<::tools::vector2<T>, ::tools::directed_line_segment_2d<T>>;\n\
    \    using result_t = ::std::optional<variant_t>;\n    const ::tools::line_2d<T>\
    \ l1 = lhs.to_line();\n    const ::tools::line_2d<T> l2 = rhs.to_line();\n   \
    \ if (l1 == l2) {\n      const ::tools::vector2<T> base = lhs.to_vector();\n \
    \     const ::tools::directed_line_segment_2d<T> fixed_rhs = base.inner_product(rhs.to_vector())\
    \ > T(0) ? rhs : -rhs;\n      const T d1(0);\n      const T d2 = base.inner_product(base);\n\
    \      const T d3 = base.inner_product(fixed_rhs.m_p1 - lhs.m_p1);\n      const\
    \ T d4 = base.inner_product(fixed_rhs.m_p2 - lhs.m_p1);\n      if (d1 == d4) return\
    \ result_t(variant_t(lhs.m_p1));\n      if (d2 == d3) return result_t(variant_t(lhs.m_p2));\n\
    \      if (d3 <= d1 && d2 <= d4) return result_t(variant_t(lhs));\n      if (d1\
    \ <= d3 && d4 <= d2) return result_t(variant_t(fixed_rhs));\n      if (d3 <= d1\
    \ && d1 <= d4 && d4 <= d2) return result_t(variant_t(::tools::directed_line_segment_2d<T>(lhs.m_p1,\
    \ fixed_rhs.m_p2)));\n      if (d1 <= d3 && d3 <= d2 && d2 <= d4) return result_t(variant_t(::tools::directed_line_segment_2d<T>(fixed_rhs.m_p1,\
    \ lhs.m_p2)));\n      return ::std::nullopt;\n    }\n    if (l1.is_parallel_to(l2))\
    \ return ::std::nullopt;\n    if (lhs.m_p1 == rhs.m_p1 || lhs.m_p1 == rhs.m_p2)\
    \ return result_t(variant_t(lhs.m_p1));\n    if (lhs.m_p2 == rhs.m_p1 || lhs.m_p2\
    \ == rhs.m_p2) return result_t(variant_t(lhs.m_p2));\n    if (((rhs.m_p1.y - lhs.m_p1.y)\
    \ * (lhs.m_p2.x - lhs.m_p1.x) - (lhs.m_p2.y - lhs.m_p1.y) * (rhs.m_p1.x - lhs.m_p1.x))\
    \ *\n        ((rhs.m_p2.y - lhs.m_p1.y) * (lhs.m_p2.x - lhs.m_p1.x) - (lhs.m_p2.y\
    \ - lhs.m_p1.y) * (rhs.m_p2.x - lhs.m_p1.x)) > T(0) ||\n        ((lhs.m_p1.y -\
    \ rhs.m_p1.y) * (rhs.m_p2.x - rhs.m_p1.x) - (rhs.m_p2.y - rhs.m_p1.y) * (lhs.m_p1.x\
    \ - rhs.m_p1.x)) *\n        ((lhs.m_p2.y - rhs.m_p1.y) * (rhs.m_p2.x - rhs.m_p1.x)\
    \ - (rhs.m_p2.y - rhs.m_p1.y) * (lhs.m_p2.x - rhs.m_p1.x)) > T(0)) return ::std::nullopt;\n\
    \    return result_t(variant_t(*l1.cross_point(l2)));\n  }\n\n  template <typename\
    \ T>\n  ::std::enable_if_t<::tools::is_rational_v<T> || ::std::is_floating_point_v<T>,\
    \ ::std::optional<::std::variant<::tools::vector2<T>, ::tools::directed_line_segment_2d<T>>>>\n\
    \  operator&(const ::tools::directed_line_segment_2d<T>& lhs, const ::tools::half_line_2d<T>&\
    \ rhs) {\n    using variant_t = ::std::variant<::tools::vector2<T>, ::tools::directed_line_segment_2d<T>>;\n\
    \    using result_t = ::std::optional<variant_t>;\n    const ::tools::line_2d<T>\
    \ l1 = lhs.to_line();\n    const ::tools::line_2d<T> l2 = rhs.to_line();\n   \
    \ if (l1 == l2) {\n      const bool has_same_direction = rhs.d().inner_product(lhs.to_vector())\
    \ > T(0);\n      const T d1 = rhs.d().inner_product(lhs.m_p1 - rhs.a());\n   \
    \   const T d2 = rhs.d().inner_product(lhs.m_p2 - rhs.a());\n      if (has_same_direction)\
    \ {\n        if (d2 < T(0)) return ::std::nullopt;\n        if (d2 == T(0)) return\
    \ result_t(variant_t(rhs.a()));\n        if (d1 < T(0)) return result_t(variant_t(::tools::directed_line_segment_2d<T>(rhs.a(),\
    \ lhs.m_p2)));\n        return result_t(variant_t(lhs));\n      } else {\n   \
    \     if (d1 > T(0)) return ::std::nullopt;\n        if (d1 == T(0)) return result_t(variant_t(rhs.a()));\n\
    \        if (d2 > T(0)) return result_t(variant_t(::tools::directed_line_segment_2d<T>(lhs.m_p1,\
    \ rhs.a())));\n        return result_t(variant_t(lhs));\n      }\n    }\n    if\
    \ (rhs.contains(lhs.m_p1)) return result_t(variant_t(lhs.m_p1));\n    if (rhs.contains(lhs.m_p2))\
    \ return result_t(variant_t(lhs.m_p2));\n    if ((l2.a() * lhs.m_p1.x + l2.b()\
    \ * lhs.m_p1.y + l2.c()) * (l2.a() * lhs.m_p2.x + l2.b() * lhs.m_p2.y + l2.c())\
    \ > T(0)) return ::std::nullopt;\n    const ::tools::vector2<T> possible_cross_point\
    \ = *l1.cross_point(l2);\n    if (rhs.d().inner_product(possible_cross_point -\
    \ rhs.a()) < T(0)) return ::std::nullopt;\n    return result_t(variant_t(possible_cross_point));\n\
    \  }\n\n  template <typename T>\n  ::std::enable_if_t<::tools::is_rational_v<T>\
    \ || ::std::is_floating_point_v<T>, ::std::optional<::std::variant<::tools::vector2<T>,\
    \ ::tools::directed_line_segment_2d<T>>>>\n  operator&(const ::tools::directed_line_segment_2d<T>&\
    \ lhs, const ::tools::line_2d<T>& rhs) {\n    using variant_t = ::std::variant<::tools::vector2<T>,\
    \ ::tools::directed_line_segment_2d<T>>;\n    using result_t = ::std::optional<variant_t>;\n\
    \    const ::tools::line_2d<T> lhs_line = lhs.to_line();\n    if (lhs_line ==\
    \ rhs) return result_t(variant_t(lhs));\n    if (rhs.contains(lhs.m_p1)) return\
    \ result_t(variant_t(lhs.m_p1));\n    if (rhs.contains(lhs.m_p2)) return result_t(variant_t(lhs.m_p2));\n\
    \    if ((rhs.a() * lhs.m_p1.x + rhs.b() * lhs.m_p1.y + rhs.c()) * (rhs.a() *\
    \ lhs.m_p2.x + rhs.b() * lhs.m_p2.y + rhs.c()) > T(0)) return ::std::nullopt;\n\
    \    return result_t(variant_t(*lhs_line.cross_point(rhs)));\n  }\n\n  template\
    \ <typename T>\n  bool operator==(const ::tools::directed_line_segment_2d<T>&\
    \ lhs, const ::tools::directed_line_segment_2d<T>& rhs) {\n    return lhs.p1()\
    \ == rhs.p1() && lhs.p2() == rhs.p2();\n  }\n\n  template <typename T>\n  bool\
    \ operator!=(const ::tools::directed_line_segment_2d<T>& lhs, const ::tools::directed_line_segment_2d<T>&\
    \ rhs) {\n    return !(lhs == rhs);\n  }\n\n  template <typename T>\n  half_line_2d<T>::half_line_2d(const\
    \ ::tools::vector2<T>& a, const ::tools::vector2<T>& d) :\n    m_a(a),\n    m_d(d)\
    \ {\n    assert(d != ::tools::vector2<T>(T(0), T(0)));\n  }\n\n  template <typename\
    \ T>\n  const ::tools::vector2<T>& half_line_2d<T>::a() const {\n    return this->m_a;\n\
    \  }\n\n  template <typename T>\n  bool half_line_2d<T>::contains(const ::tools::vector2<T>&\
    \ p) const {\n    const ::tools::line_2d<T> l = this->to_line();\n    return l.a()\
    \ * p.x + l.b() * p.y + l.c() == T(0) && this->m_d.inner_product(p - this->m_a)\
    \ >= T(0);\n  }\n\n  template <typename T> template <typename T_>\n  ::std::enable_if_t<::tools::is_rational_v<T_>\
    \ || ::std::is_floating_point_v<T_>, ::std::optional<::tools::vector2<T>>>\n \
    \ half_line_2d<T>::cross_point(const ::tools::directed_line_segment_2d<T>& other)\
    \ const {\n    return other.cross_point(*this);\n  }\n\n  template <typename T>\
    \ template <typename T_>\n  ::std::enable_if_t<::tools::is_rational_v<T_> || ::std::is_floating_point_v<T_>,\
    \ ::std::optional<::tools::vector2<T>>>\n  half_line_2d<T>::cross_point(const\
    \ ::tools::half_line_2d<T>& other) const {\n    using result_t = ::std::optional<::tools::vector2<T>>;\n\
    \    const auto intersection = *this & other;\n    struct {\n      result_t operator()(const\
    \ ::tools::vector2<T>& v) {\n        return result_t(v);\n      }\n      result_t\
    \ operator()(const ::tools::directed_line_segment_2d<T>&) {\n        return ::std::nullopt;\n\
    \      }\n      result_t operator()(const ::tools::half_line_2d<T>&) {\n     \
    \   return ::std::nullopt;\n      }\n    } visitor;\n    return intersection ?\
    \ ::std::visit(visitor, *intersection) : ::std::nullopt;\n  }\n\n  template <typename\
    \ T> template <typename T_>\n  ::std::enable_if_t<::tools::is_rational_v<T_> ||\
    \ ::std::is_floating_point_v<T_>, ::std::optional<::tools::vector2<T>>>\n  half_line_2d<T>::cross_point(const\
    \ ::tools::line_2d<T>& other) const {\n    using result_t = ::std::optional<::tools::vector2<T>>;\n\
    \    const auto intersection = *this & other;\n    struct {\n      result_t operator()(const\
    \ ::tools::vector2<T>& v) {\n        return result_t(v);\n      }\n      result_t\
    \ operator()(const ::tools::half_line_2d<T>&) {\n        return ::std::nullopt;\n\
    \      }\n    } visitor;\n    return intersection ? ::std::visit(visitor, *intersection)\
    \ : ::std::nullopt;\n  }\n\n  template <typename T>\n  const ::tools::vector2<T>&\
    \ half_line_2d<T>::d() const {\n    return this->m_d;\n  }\n\n  template <typename\
    \ T> template <typename T_>\n  ::std::enable_if_t<::tools::is_rational_v<T_> ||\
    \ ::std::is_floating_point_v<T_>, T>\n  half_line_2d<T>::squared_distance(const\
    \ ::tools::directed_line_segment_2d<T>& other) const {\n    return other.squared_distance(*this);\n\
    \  }\n\n  template <typename T> template <typename T_>\n  ::std::enable_if_t<::tools::is_rational_v<T_>\
    \ || ::std::is_floating_point_v<T_>, T>\n  half_line_2d<T>::squared_distance(const\
    \ ::tools::half_line_2d<T>& other) const {\n    if (*this & other) {\n      return\
    \ T(0);\n    }\n    if (const auto x = this->to_line().cross_point(other.to_line());\
    \ x) {\n      if (this->m_d.inner_product(*x - this->m_a) >= T(0)) {\n       \
    \ return (other.m_a - *x).squared_l2_norm();\n      } else if (other.m_d.inner_product(*x\
    \ - other.m_a) >= T(0)) {\n        return (this->m_a - *x).squared_l2_norm();\n\
    \      } else {\n        return (this->m_a - other.m_a).squared_l2_norm();\n \
    \     }\n    } else {\n      if (this->m_d.inner_product(other.m_a) > T(0)) {\n\
    \        return this->to_line().squared_distance(other.to_line());\n      } else\
    \ if (const auto x = this->to_line().projection(other.m_a); this->m_d.inner_product(x\
    \ - this->m_a) >= T(0)) {\n        return this->to_line().squared_distance(other.to_line());\n\
    \      } else {\n        return (this->m_a - other.m_a).squared_l2_norm();\n \
    \     }\n    }\n  }\n\n  template <typename T> template <typename T_>\n  ::std::enable_if_t<::tools::is_rational_v<T_>\
    \ || ::std::is_floating_point_v<T_>, T>\n  half_line_2d<T>::squared_distance(const\
    \ ::tools::line_2d<T>& other) const {\n    if (*this & other) {\n      return\
    \ T(0);\n    }\n    return other.squared_distance(this->m_a);\n  }\n\n  template\
    \ <typename T> template <typename T_>\n  ::std::enable_if_t<::tools::is_rational_v<T_>\
    \ || ::std::is_floating_point_v<T_>, T>\n  half_line_2d<T>::squared_distance(const\
    \ ::tools::vector2<T>& p) const {\n    auto x = this->to_line().projection(p);\n\
    \    const auto d = this->m_d.inner_product(x - this->m_a);\n    return (p - (d\
    \ < T(0) ? this->m_a : x)).squared_l2_norm();\n  }\n\n  template <typename T>\n\
    \  ::tools::line_2d<T> half_line_2d<T>::to_line() const {\n    return ::tools::line_2d<T>::through(this->m_a,\
    \ this->m_a + this->m_d);\n  }\n\n  template <typename T>\n  ::std::enable_if_t<::tools::is_rational_v<T>\
    \ || ::std::is_floating_point_v<T>, ::std::optional<::std::variant<::tools::vector2<T>,\
    \ ::tools::directed_line_segment_2d<T>>>>\n  operator&(const ::tools::half_line_2d<T>&\
    \ lhs, const ::tools::directed_line_segment_2d<T>& rhs) {\n    return rhs & lhs;\n\
    \  }\n\n  template <typename T>\n  ::std::enable_if_t<::tools::is_rational_v<T>\
    \ || ::std::is_floating_point_v<T>, ::std::optional<::std::variant<::tools::vector2<T>,\
    \ ::tools::directed_line_segment_2d<T>, ::tools::half_line_2d<T>>>>\n  operator&(const\
    \ ::tools::half_line_2d<T>& lhs, const ::tools::half_line_2d<T>& rhs) {\n    using\
    \ variant_t = ::std::variant<::tools::vector2<T>, ::tools::directed_line_segment_2d<T>,\
    \ ::tools::half_line_2d<T>>;\n    using result_t = ::std::optional<variant_t>;\n\
    \    const ::tools::line_2d<T> l1 = lhs.to_line();\n    const ::tools::line_2d<T>\
    \ l2 = rhs.to_line();\n    if (l1 == l2) {\n      if (lhs.d().inner_product(rhs.d())\
    \ > T(0)) {\n        switch (::tools::signum(lhs.d().inner_product(rhs.a() - lhs.a())))\
    \ {\n        case 1:\n        case 0:\n          return result_t(variant_t(rhs));\n\
    \        default:\n          return result_t(variant_t(lhs));\n        }\n   \
    \   } else {\n        switch (::tools::signum(lhs.d().inner_product(rhs.a() -\
    \ lhs.a()))) {\n        case 1:\n          return result_t(variant_t(::tools::directed_line_segment_2d<T>(lhs.a(),\
    \ rhs.a())));\n        case 0:\n          return result_t(variant_t(lhs.a()));\n\
    \        default:\n          return ::std::nullopt;\n        }\n      }\n    }\
    \ else if (l1.is_parallel_to(l2)) {\n      return ::std::nullopt;\n    } else\
    \ {\n      const ::tools::vector2<T> possible_cross_point = *l1.cross_point(l2);\n\
    \      if (lhs.d().inner_product(possible_cross_point - lhs.a()) < T(0) || rhs.d().inner_product(possible_cross_point\
    \ - rhs.a()) < T(0)) {\n        return ::std::nullopt;\n      }\n      return\
    \ result_t(variant_t(possible_cross_point));\n    }\n  }\n\n  template <typename\
    \ T>\n  ::std::enable_if_t<::tools::is_rational_v<T> || ::std::is_floating_point_v<T>,\
    \ ::std::optional<::std::variant<::tools::vector2<T>, ::tools::half_line_2d<T>>>>\n\
    \  operator&(const ::tools::half_line_2d<T>& lhs, const ::tools::line_2d<T>& rhs)\
    \ {\n    using variant_t = ::std::variant<::tools::vector2<T>, ::tools::half_line_2d<T>>;\n\
    \    using result_t = ::std::optional<variant_t>;\n    const auto lhs_line = lhs.to_line();\n\
    \    if (lhs_line == rhs) return result_t(variant_t(lhs));\n    const auto possible_cross_point\
    \ = lhs_line.cross_point(rhs);\n    return possible_cross_point && lhs.m_d.inner_product(*possible_cross_point\
    \ - lhs.m_a) >= T(0)\n      ? result_t(variant_t(*possible_cross_point))\n   \
    \   : ::std::nullopt;\n  }\n\n  template <typename T>\n  bool operator==(const\
    \ ::tools::half_line_2d<T>& lhs, const ::tools::half_line_2d<T>& rhs) {\n    return\
    \ lhs.a() == rhs.a() && lhs.d().x * rhs.d().y == rhs.d().x * lhs.d().y;\n  }\n\
    \n  template <typename T>\n  bool operator!=(const ::tools::half_line_2d<T>& lhs,\
    \ const ::tools::half_line_2d<T>& rhs) {\n    return !(lhs == rhs);\n  }\n\n \
    \ template <typename T>\n  line_2d<T>::line_2d(const T& a, const T& b, const T&\
    \ c) :\n    m_a(a),\n    m_b(b),\n    m_c(c) {\n    assert(a != T(0) || b != T(0));\n\
    \  }\n\n  template <typename T>\n  const T& line_2d<T>::a() const {\n    return\
    \ this->m_a;\n  }\n\n  template <typename T>\n  const T& line_2d<T>::b() const\
    \ {\n    return this->m_b;\n  }\n\n  template <typename T>\n  const T& line_2d<T>::c()\
    \ const {\n    return this->m_c;\n  }\n\n  template <typename T>\n  bool line_2d<T>::contains(const\
    \ ::tools::vector2<T>& p) const {\n    return this->m_a * p.x + this->m_b * p.y\
    \ + this->m_c == T(0);\n  }\n\n  template <typename T> template <typename T_>\n\
    \  ::std::enable_if_t<::tools::is_rational_v<T_> || ::std::is_floating_point_v<T_>,\
    \ ::std::optional<::tools::vector2<T>>>\n  line_2d<T>::cross_point(const ::tools::directed_line_segment_2d<T>&\
    \ other) const {\n    return other.cross_point(*this);\n  }\n\n  template <typename\
    \ T> template <typename T_>\n  ::std::enable_if_t<::tools::is_rational_v<T_> ||\
    \ ::std::is_floating_point_v<T_>, ::std::optional<::tools::vector2<T>>>\n  line_2d<T>::cross_point(const\
    \ ::tools::half_line_2d<T>& other) const {\n    return other.cross_point(*this);\n\
    \  }\n\n  template <typename T> template <typename T_>\n  ::std::enable_if_t<::tools::is_rational_v<T_>\
    \ || ::std::is_floating_point_v<T_>, ::std::optional<::tools::vector2<T>>>\n \
    \ line_2d<T>::cross_point(const ::tools::line_2d<T>& other) const {\n    using\
    \ result_t = ::std::optional<::tools::vector2<T>>;\n    if (!this->crosses(other))\
    \ return ::std::nullopt;\n    return result_t(::tools::vector2<T>(\n      (this->m_b\
    \ * other.m_c - other.m_b * this->m_c) / (this->m_a * other.m_b - other.m_a *\
    \ this->m_b),\n      (other.m_a * this->m_c - this->m_a * other.m_c) / (this->m_a\
    \ * other.m_b - other.m_a * this->m_b)\n    ));\n  }\n\n  template <typename T>\n\
    \  bool line_2d<T>::crosses(const ::tools::line_2d<T>& other) const {\n    return\
    \ this->m_a * other.m_b != other.m_a * this->m_b;\n  }\n\n  template <typename\
    \ T>\n  bool line_2d<T>::is_parallel_to(const ::tools::line_2d<T>& other) const\
    \ {\n    return this->m_a * other.m_b == this->m_b * other.m_a;\n  }\n\n  template\
    \ <typename T>\n  ::tools::vector2<T> line_2d<T>::normal() const {\n    return\
    \ ::tools::vector2<T>(this->m_a, this->m_b);\n  }\n\n  template <typename T> template\
    \ <typename T_>\n  ::std::enable_if_t<::tools::is_rational_v<T_> || ::std::is_floating_point_v<T_>,\
    \ ::tools::vector2<T>>\n  line_2d<T>::projection(const ::tools::vector2<T>& p)\
    \ const {\n    return *::tools::half_line_2d<T>(p, this->normal()).to_line().cross_point(*this);\n\
    \  }\n\n  template <typename T> template <typename T_>\n  ::std::enable_if_t<::tools::is_rational_v<T_>\
    \ || ::std::is_floating_point_v<T_>, T>\n  line_2d<T>::squared_distance(const\
    \ ::tools::directed_line_segment_2d<T>& other) const {\n    return other.squared_distance(*this);\n\
    \  }\n\n  template <typename T> template <typename T_>\n  ::std::enable_if_t<::tools::is_rational_v<T_>\
    \ || ::std::is_floating_point_v<T_>, T>\n  line_2d<T>::squared_distance(const\
    \ ::tools::half_line_2d<T>& other) const {\n    return other.squared_distance(*this);\n\
    \  }\n\n  template <typename T> template <typename T_>\n  ::std::enable_if_t<::tools::is_rational_v<T_>\
    \ || ::std::is_floating_point_v<T_>, T>\n  line_2d<T>::squared_distance(const\
    \ ::tools::line_2d<T>& other) const {\n    if (this->is_parallel_to(other)) {\n\
    \      return ::tools::square(other.m_a * this->m_c - this->m_a * other.m_c) /\
    \ (::tools::square(this->m_a) + ::tools::square(this->m_b)) / ::tools::square(other.m_a);\n\
    \    } else {\n      return T(0);\n    }\n  }\n\n  template <typename T> template\
    \ <typename T_>\n  ::std::enable_if_t<::tools::is_rational_v<T_> || ::std::is_floating_point_v<T_>,\
    \ T>\n  line_2d<T>::squared_distance(const ::tools::vector2<T>& p) const {\n \
    \   return (p - this->projection(p)).squared_l2_norm();\n  }\n\n  template <typename\
    \ T, bool HasRadius>\n  ::std::enable_if_t<::std::is_floating_point_v<T>, ::std::vector<::tools::vector2<T>>>\n\
    \  operator&(const ::tools::line_2d<T>& lhs, const ::tools::circle_2d<T, false,\
    \ HasRadius>& rhs) {\n    return rhs & lhs;\n  }\n\n  template <typename T, bool\
    \ HasRadius>\n  ::std::enable_if_t<::std::is_floating_point_v<T>, ::std::optional<::std::variant<::tools::vector2<T>,\
    \ ::tools::directed_line_segment_2d<T>>>>\n  operator&(const ::tools::line_2d<T>&\
    \ lhs, const ::tools::circle_2d<T, true, HasRadius>& rhs) {\n    return rhs &\
    \ lhs;\n  }\n\n  template <typename T>\n  ::std::enable_if_t<::tools::is_rational_v<T>\
    \ || ::std::is_floating_point_v<T>, ::std::optional<::std::variant<::tools::vector2<T>,\
    \ ::tools::directed_line_segment_2d<T>>>>\n  operator&(const ::tools::line_2d<T>&\
    \ lhs, const ::tools::directed_line_segment_2d<T>& rhs) {\n    return rhs & lhs;\n\
    \  }\n\n  template <typename T>\n  ::std::enable_if_t<::tools::is_rational_v<T>\
    \ || ::std::is_floating_point_v<T>, ::std::optional<::std::variant<::tools::vector2<T>,\
    \ ::tools::half_line_2d<T>>>>\n  operator&(const ::tools::line_2d<T>& lhs, const\
    \ ::tools::half_line_2d<T>& rhs) {\n    return rhs & lhs;\n  }\n\n  template <typename\
    \ T>\n  ::std::enable_if_t<::tools::is_rational_v<T> || ::std::is_floating_point_v<T>,\
    \ ::std::optional<::std::variant<::tools::vector2<T>, ::tools::line_2d<T>>>>\n\
    \  operator&(const ::tools::line_2d<T>& lhs, const ::tools::line_2d<T>& rhs) {\n\
    \    using variant_t = ::std::variant<::tools::vector2<T>, ::tools::line_2d<T>>;\n\
    \    using result_t = ::std::optional<variant_t>;\n    if (lhs == rhs) return\
    \ result_t(variant_t(lhs));\n    const auto possible_cross_point = lhs.cross_point(rhs);\n\
    \    return possible_cross_point ? result_t(variant_t(*possible_cross_point))\
    \ : ::std::nullopt;\n  }\n\n  template <typename T>\n  bool operator==(const ::tools::line_2d<T>&\
    \ lhs, const ::tools::line_2d<T>& rhs) {\n    return lhs.m_b * rhs.m_c == lhs.m_c\
    \ * rhs.m_b && lhs.m_c * rhs.m_a == lhs.m_a * rhs.m_c && lhs.m_a * rhs.m_b ==\
    \ lhs.m_b * rhs.m_a;\n  }\n\n  template <typename T>\n  bool operator!=(const\
    \ ::tools::line_2d<T>& lhs, const ::tools::line_2d<T>& rhs) {\n    return !(lhs\
    \ == rhs);\n  }\n\n  template <typename T>\n  ::tools::line_2d<T> line_2d<T>::through(const\
    \ ::tools::vector2<T>& p1, const ::tools::vector2<T>& p2) {\n    return ::tools::line_2d<T>(p1.y\
    \ - p2.y, p2.x - p1.x, (p2.y - p1.y) * p1.x - (p2.x - p1.x) * p1.y);\n  }\n\n\
    \  template <typename T, bool Filled>\n  T polygon_2d<T, Filled>::doubled_signed_area()\
    \ const {\n    T result(0);\n    for (::std::size_t i = 0; i < this->m_points.size();\
    \ ++i) {\n      result += (this->m_points[i].x - this->m_points[(i + 1) % this->m_points.size()].x)\
    \ * (this->m_points[i].y + this->m_points[(i + 1) % this->m_points.size()].y);\n\
    \    }\n    return result;\n  }\n\n  template <typename T, bool Filled>\n  template\
    \ <typename InputIterator>\n  polygon_2d<T, Filled>::polygon_2d(const InputIterator&\
    \ begin, const InputIterator& end) : m_points(begin, end) {\n    assert(this->m_points.size()\
    \ >= 3);\n  }\n\n  template <typename T, bool Filled>\n  polygon_2d<T, Filled>::polygon_2d(::std::initializer_list<::tools::vector2<T>>\
    \ init) : polygon_2d(init.begin(), init.end()) {\n  }\n\n  template <typename\
    \ T, bool Filled> template <typename T_, bool Filled_>\n  ::std::enable_if_t<(::tools::is_rational_v<T_>\
    \ || ::std::is_floating_point_v<T_>) && Filled_, T> polygon_2d<T, Filled>::area()\
    \ const {\n    return this->doubled_area() / T(2);\n  }\n\n  template <typename\
    \ T, bool Filled> template <bool Filled_>\n  ::std::enable_if_t<Filled_, T> polygon_2d<T,\
    \ Filled>::doubled_area() const {\n    return ::tools::abs(this->doubled_signed_area());\n\
    \  }\n\n  template <typename T, bool Filled>\n  bool polygon_2d<T, Filled>::is_counterclockwise()\
    \ const {\n    return this->doubled_signed_area() > T(0);\n  }\n\n  template <typename\
    \ T, bool Filled> template <typename T_>\n  ::std::enable_if_t<::tools::is_rational_v<T_>\
    \ || ::std::is_floating_point_v<T_>, ::tools::circle_2d<T, Filled, false>> polygon_2d<T,\
    \ Filled>::minimum_bounding_circle() const {\n    ::std::optional<::tools::circle_2d<T,\
    \ Filled, false>> answer;\n    for (::std::size_t i = 0; i < this->m_points.size();\
    \ ++i) {\n      for (::std::size_t j = i + 1; j < this->m_points.size(); ++j)\
    \ {\n        for (::std::size_t k = j + 1; k < this->m_points.size(); ++k) {\n\
    \          if (const auto possible_answer = ::tools::triangle_2d<T, Filled>({this->m_points[i],\
    \ this->m_points[j], this->m_points[k]}).minimum_bounding_circle();\n        \
    \      !answer || answer->squared_radius() < possible_answer.squared_radius())\
    \ {\n            answer = ::std::move(possible_answer);\n          }\n       \
    \ }\n      }\n    }\n    return *answer;\n  }\n\n  template <typename T, bool\
    \ Filled>\n  int polygon_2d<T, Filled>::where(const ::tools::vector2<T>& p) const\
    \ {\n    ::std::vector<::tools::directed_line_segment_2d<T>> edges;\n    for (::std::size_t\
    \ i = 0; i < this->m_points.size(); ++i) {\n      edges.emplace_back(this->m_points[i],\
    \ this->m_points[(i + 1) % this->m_points.size()]);\n    }\n\n    if (std::any_of(edges.begin(),\
    \ edges.end(), [&](const auto& edge) { return edge.contains(p); })) {\n      return\
    \ 0;\n    } else {\n      bool in = false;\n      for (const auto& edge : edges)\
    \ {\n        if ([&]() {\n          const auto l = edge.to_line();\n         \
    \ if (l == ::tools::line_2d<T>(T(0), T(1), -p.y)) return false;\n          if\
    \ (p.x <= edge.p1().x && p.y == edge.p1().y) return edge.p2().y < edge.p1().y;\n\
    \          if (p.x <= edge.p2().x && p.y == edge.p2().y) return edge.p1().y <\
    \ edge.p2().y;\n          if ((edge.p1().y - p.y) * (edge.p2().y - p.y) > T(0))\
    \ return false;\n          return l.a() * (l.a() * p.x + l.b() * p.y + l.c())\
    \ < T(0);\n        }()) {\n          in = !in;\n        }\n      }\n      return\
    \ in ? 1 : -1;\n    }\n  }\n\n  template <typename T, bool Filled>\n  template\
    \ <typename OutputIterator>\n  void triangle_2d<T, Filled>::sorted_edges(OutputIterator\
    \ result) const {\n    ::std::array<::tools::directed_line_segment_2d<T>, 3> edges;\n\
    \    for (int i = 0; i < 3; ++i) {\n      edges[i] = ::tools::directed_line_segment_2d<T>(this->m_points[i],\
    \ this->m_points[(i + 1) % 3]);\n    }\n    ::std::sort(edges.begin(), edges.end(),\
    \ ::tools::less_by([](const auto& edge) {\n      return edge.squared_length();\n\
    \    }));\n    for (const auto& edge : edges) {\n      *result = edge;\n     \
    \ ++result;\n    }\n  }\n\n  template <typename T, bool Filled>\n  template <typename\
    \ InputIterator>\n  triangle_2d<T, Filled>::triangle_2d(const InputIterator& begin,\
    \ const InputIterator& end) : polygon_2d<T, Filled>(begin, end) {\n    assert(this->m_points.size()\
    \ == 3);\n  }\n\n  template <typename T, bool Filled>\n  triangle_2d<T, Filled>::triangle_2d(::std::initializer_list<::tools::vector2<T>>\
    \ init) : triangle_2d(init.begin(), init.end()) {\n  }\n\n  template <typename\
    \ T, bool Filled> template <typename T_>\n  ::std::enable_if_t<::tools::is_rational_v<T_>\
    \ || ::std::is_floating_point_v<T_>, ::tools::circle_2d<T, Filled, false>> triangle_2d<T,\
    \ Filled>::circumcircle() const {\n    const auto& A = this->m_points[0];\n  \
    \  const auto& B = this->m_points[1];\n    const auto& C = this->m_points[2];\n\
    \    const auto a2 = (C - B).squared_l2_norm();\n    const auto b2 = (A - C).squared_l2_norm();\n\
    \    const auto c2 = (B - A).squared_l2_norm();\n    const auto kA = a2 * (b2\
    \ + c2 - a2);\n    const auto kB = b2 * (c2 + a2 - b2);\n    const auto kC = c2\
    \ * (a2 + b2 - c2);\n    const auto circumcenter = (kA * A + kB * B + kC * C)\
    \ / (kA + kB + kC);\n    return ::tools::circle_2d<T, Filled, false>(circumcenter,\
    \ (circumcenter - A).squared_l2_norm());\n  }\n\n  template <typename T, bool\
    \ Filled> template <typename T_>\n  ::std::enable_if_t<::std::is_floating_point_v<T_>,\
    \ ::tools::circle_2d<T, Filled>> triangle_2d<T, Filled>::incircle() const {\n\
    \    const auto& A = this->m_points[0];\n    const auto& B = this->m_points[1];\n\
    \    const auto& C = this->m_points[2];\n    const auto a = (C - B).l2_norm();\n\
    \    const auto b = (A - C).l2_norm();\n    const auto c = (B - A).l2_norm();\n\
    \    const auto incenter = (a * A + b * B + c * C) / (a + b + c);\n    return\
    \ ::tools::circle_2d<T, Filled>(incenter, ::tools::abs(this->doubled_signed_area())\
    \ / (a + b + c));\n  }\n\n  template <typename T, bool Filled> template <typename\
    \ T_>\n  ::std::enable_if_t<::tools::is_rational_v<T_> || ::std::is_floating_point_v<T_>,\
    \ ::tools::circle_2d<T, Filled, false>> triangle_2d<T, Filled>::minimum_bounding_circle()\
    \ const {\n    ::std::array<::tools::directed_line_segment_2d<T>, 3> edges;\n\
    \    this->sorted_edges(edges.begin());\n    if (edges[0].squared_length() + edges[1].squared_length()\
    \ <= edges[2].squared_length()) {\n      const auto center = edges[2].midpoint();\n\
    \      return ::tools::circle_2d<T, Filled, false>(center, (center - edges[2].p1()).squared_l2_norm());\n\
    \    } else {\n      return this->circumcircle();\n    }\n  }\n\n  template <typename\
    \ T, bool Filled>\n  int triangle_2d<T, Filled>::type() const {\n    ::std::array<::tools::directed_line_segment_2d<T>,\
    \ 3> edges;\n    this->sorted_edges(edges.begin());\n    const auto c2 = edges[2].squared_length();\n\
    \    const auto a2b2 = edges[1].squared_length() + edges[0].squared_length();\n\
    \    if (c2 < a2b2) {\n      return 0;\n    } else if (c2 == a2b2) {\n      return\
    \ 1;\n    } else {\n      return 2;\n    }\n  }\n}\n\n\n#line 5 \"tools/directed_line_segment_2d.hpp\"\
    \n\n\n#line 1 \"tools/rational.hpp\"\n\n\n\n#line 1 \"tools/bigint.hpp\"\n\n\n\
    \n#line 9 \"tools/bigint.hpp\"\n#include <iterator>\n#line 11 \"tools/bigint.hpp\"\
    \n#include <string>\n#line 17 \"tools/bigint.hpp\"\n#include <iomanip>\n#line\
    \ 1 \"lib/ac-library/atcoder/modint.hpp\"\n\n\n\n#line 7 \"lib/ac-library/atcoder/modint.hpp\"\
    \n\n#ifdef _MSC_VER\n#include <intrin.h>\n#endif\n\n#line 1 \"lib/ac-library/atcoder/internal_math.hpp\"\
    \n\n\n\n#line 5 \"lib/ac-library/atcoder/internal_math.hpp\"\n\n#ifdef _MSC_VER\n\
    #include <intrin.h>\n#endif\n\nnamespace atcoder {\n\nnamespace internal {\n\n\
    // @param m `1 <= m`\n// @return x mod m\nconstexpr long long safe_mod(long long\
    \ x, long long m) {\n    x %= m;\n    if (x < 0) x += m;\n    return x;\n}\n\n\
    // Fast modular multiplication by barrett reduction\n// Reference: https://en.wikipedia.org/wiki/Barrett_reduction\n\
    // NOTE: reconsider after Ice Lake\nstruct barrett {\n    unsigned int _m;\n \
    \   unsigned long long im;\n\n    // @param m `1 <= m < 2^31`\n    explicit barrett(unsigned\
    \ int m) : _m(m), im((unsigned long long)(-1) / m + 1) {}\n\n    // @return m\n\
    \    unsigned int umod() const { return _m; }\n\n    // @param a `0 <= a < m`\n\
    \    // @param b `0 <= b < m`\n    // @return `a * b % m`\n    unsigned int mul(unsigned\
    \ int a, unsigned int b) const {\n        // [1] m = 1\n        // a = b = im\
    \ = 0, so okay\n\n        // [2] m >= 2\n        // im = ceil(2^64 / m)\n    \
    \    // -> im * m = 2^64 + r (0 <= r < m)\n        // let z = a*b = c*m + d (0\
    \ <= c, d < m)\n        // a*b * im = (c*m + d) * im = c*(im*m) + d*im = c*2^64\
    \ + c*r + d*im\n        // c*r + d*im < m * m + m * im < m * m + 2^64 + m <= 2^64\
    \ + m * (m + 1) < 2^64 * 2\n        // ((ab * im) >> 64) == c or c + 1\n     \
    \   unsigned long long z = a;\n        z *= b;\n#ifdef _MSC_VER\n        unsigned\
    \ long long x;\n        _umul128(z, im, &x);\n#else\n        unsigned long long\
    \ x =\n            (unsigned long long)(((unsigned __int128)(z)*im) >> 64);\n\
    #endif\n        unsigned int v = (unsigned int)(z - x * _m);\n        if (_m <=\
    \ v) v += _m;\n        return v;\n    }\n};\n\n// @param n `0 <= n`\n// @param\
    \ m `1 <= m`\n// @return `(x ** n) % m`\nconstexpr long long pow_mod_constexpr(long\
    \ long x, long long n, int m) {\n    if (m == 1) return 0;\n    unsigned int _m\
    \ = (unsigned int)(m);\n    unsigned long long r = 1;\n    unsigned long long\
    \ y = safe_mod(x, m);\n    while (n) {\n        if (n & 1) r = (r * y) % _m;\n\
    \        y = (y * y) % _m;\n        n >>= 1;\n    }\n    return r;\n}\n\n// Reference:\n\
    // M. Forisek and J. Jancina,\n// Fast Primality Testing for Integers That Fit\
    \ into a Machine Word\n// @param n `0 <= n`\nconstexpr bool is_prime_constexpr(int\
    \ n) {\n    if (n <= 1) return false;\n    if (n == 2 || n == 7 || n == 61) return\
    \ true;\n    if (n % 2 == 0) return false;\n    long long d = n - 1;\n    while\
    \ (d % 2 == 0) d /= 2;\n    constexpr long long bases[3] = {2, 7, 61};\n    for\
    \ (long long a : bases) {\n        long long t = d;\n        long long y = pow_mod_constexpr(a,\
    \ t, n);\n        while (t != n - 1 && y != 1 && y != n - 1) {\n            y\
    \ = y * y % n;\n            t <<= 1;\n        }\n        if (y != n - 1 && t %\
    \ 2 == 0) {\n            return false;\n        }\n    }\n    return true;\n}\n\
    template <int n> constexpr bool is_prime = is_prime_constexpr(n);\n\n// @param\
    \ b `1 <= b`\n// @return pair(g, x) s.t. g = gcd(a, b), xa = g (mod b), 0 <= x\
    \ < b/g\nconstexpr std::pair<long long, long long> inv_gcd(long long a, long long\
    \ b) {\n    a = safe_mod(a, b);\n    if (a == 0) return {b, 0};\n\n    // Contracts:\n\
    \    // [1] s - m0 * a = 0 (mod b)\n    // [2] t - m1 * a = 0 (mod b)\n    //\
    \ [3] s * |m1| + t * |m0| <= b\n    long long s = b, t = a;\n    long long m0\
    \ = 0, m1 = 1;\n\n    while (t) {\n        long long u = s / t;\n        s -=\
    \ t * u;\n        m0 -= m1 * u;  // |m1 * u| <= |m1| * s <= b\n\n        // [3]:\n\
    \        // (s - t * u) * |m1| + t * |m0 - m1 * u|\n        // <= s * |m1| - t\
    \ * u * |m1| + t * (|m0| + |m1| * u)\n        // = s * |m1| + t * |m0| <= b\n\n\
    \        auto tmp = s;\n        s = t;\n        t = tmp;\n        tmp = m0;\n\
    \        m0 = m1;\n        m1 = tmp;\n    }\n    // by [3]: |m0| <= b/g\n    //\
    \ by g != b: |m0| < b/g\n    if (m0 < 0) m0 += b / s;\n    return {s, m0};\n}\n\
    \n// Compile time primitive root\n// @param m must be prime\n// @return primitive\
    \ root (and minimum in now)\nconstexpr int primitive_root_constexpr(int m) {\n\
    \    if (m == 2) return 1;\n    if (m == 167772161) return 3;\n    if (m == 469762049)\
    \ return 3;\n    if (m == 754974721) return 11;\n    if (m == 998244353) return\
    \ 3;\n    int divs[20] = {};\n    divs[0] = 2;\n    int cnt = 1;\n    int x =\
    \ (m - 1) / 2;\n    while (x % 2 == 0) x /= 2;\n    for (int i = 3; (long long)(i)*i\
    \ <= x; i += 2) {\n        if (x % i == 0) {\n            divs[cnt++] = i;\n \
    \           while (x % i == 0) {\n                x /= i;\n            }\n   \
    \     }\n    }\n    if (x > 1) {\n        divs[cnt++] = x;\n    }\n    for (int\
    \ g = 2;; g++) {\n        bool ok = true;\n        for (int i = 0; i < cnt; i++)\
    \ {\n            if (pow_mod_constexpr(g, (m - 1) / divs[i], m) == 1) {\n    \
    \            ok = false;\n                break;\n            }\n        }\n \
    \       if (ok) return g;\n    }\n}\ntemplate <int m> constexpr int primitive_root\
    \ = primitive_root_constexpr(m);\n\n// @param n `n < 2^32`\n// @param m `1 <=\
    \ m < 2^32`\n// @return sum_{i=0}^{n-1} floor((ai + b) / m) (mod 2^64)\nunsigned\
    \ long long floor_sum_unsigned(unsigned long long n,\n                       \
    \               unsigned long long m,\n                                      unsigned\
    \ long long a,\n                                      unsigned long long b) {\n\
    \    unsigned long long ans = 0;\n    while (true) {\n        if (a >= m) {\n\
    \            ans += n * (n - 1) / 2 * (a / m);\n            a %= m;\n        }\n\
    \        if (b >= m) {\n            ans += n * (b / m);\n            b %= m;\n\
    \        }\n\n        unsigned long long y_max = a * n + b;\n        if (y_max\
    \ < m) break;\n        // y_max < m * (n + 1)\n        // floor(y_max / m) <=\
    \ n\n        n = (unsigned long long)(y_max / m);\n        b = (unsigned long\
    \ long)(y_max % m);\n        std::swap(m, a);\n    }\n    return ans;\n}\n\n}\
    \  // namespace internal\n\n}  // namespace atcoder\n\n\n#line 1 \"lib/ac-library/atcoder/internal_type_traits.hpp\"\
    \n\n\n\n#line 7 \"lib/ac-library/atcoder/internal_type_traits.hpp\"\n\nnamespace\
    \ atcoder {\n\nnamespace internal {\n\n#ifndef _MSC_VER\ntemplate <class T>\n\
    using is_signed_int128 =\n    typename std::conditional<std::is_same<T, __int128_t>::value\
    \ ||\n                                  std::is_same<T, __int128>::value,\n  \
    \                            std::true_type,\n                              std::false_type>::type;\n\
    \ntemplate <class T>\nusing is_unsigned_int128 =\n    typename std::conditional<std::is_same<T,\
    \ __uint128_t>::value ||\n                                  std::is_same<T, unsigned\
    \ __int128>::value,\n                              std::true_type,\n         \
    \                     std::false_type>::type;\n\ntemplate <class T>\nusing make_unsigned_int128\
    \ =\n    typename std::conditional<std::is_same<T, __int128_t>::value,\n     \
    \                         __uint128_t,\n                              unsigned\
    \ __int128>;\n\ntemplate <class T>\nusing is_integral = typename std::conditional<std::is_integral<T>::value\
    \ ||\n                                                  is_signed_int128<T>::value\
    \ ||\n                                                  is_unsigned_int128<T>::value,\n\
    \                                              std::true_type,\n             \
    \                                 std::false_type>::type;\n\ntemplate <class T>\n\
    using is_signed_int = typename std::conditional<(is_integral<T>::value &&\n  \
    \                                               std::is_signed<T>::value) ||\n\
    \                                                    is_signed_int128<T>::value,\n\
    \                                                std::true_type,\n           \
    \                                     std::false_type>::type;\n\ntemplate <class\
    \ T>\nusing is_unsigned_int =\n    typename std::conditional<(is_integral<T>::value\
    \ &&\n                               std::is_unsigned<T>::value) ||\n        \
    \                          is_unsigned_int128<T>::value,\n                   \
    \           std::true_type,\n                              std::false_type>::type;\n\
    \ntemplate <class T>\nusing to_unsigned = typename std::conditional<\n    is_signed_int128<T>::value,\n\
    \    make_unsigned_int128<T>,\n    typename std::conditional<std::is_signed<T>::value,\n\
    \                              std::make_unsigned<T>,\n                      \
    \        std::common_type<T>>::type>::type;\n\n#else\n\ntemplate <class T> using\
    \ is_integral = typename std::is_integral<T>;\n\ntemplate <class T>\nusing is_signed_int\
    \ =\n    typename std::conditional<is_integral<T>::value && std::is_signed<T>::value,\n\
    \                              std::true_type,\n                             \
    \ std::false_type>::type;\n\ntemplate <class T>\nusing is_unsigned_int =\n   \
    \ typename std::conditional<is_integral<T>::value &&\n                       \
    \           std::is_unsigned<T>::value,\n                              std::true_type,\n\
    \                              std::false_type>::type;\n\ntemplate <class T>\n\
    using to_unsigned = typename std::conditional<is_signed_int<T>::value,\n     \
    \                                         std::make_unsigned<T>,\n           \
    \                                   std::common_type<T>>::type;\n\n#endif\n\n\
    template <class T>\nusing is_signed_int_t = std::enable_if_t<is_signed_int<T>::value>;\n\
    \ntemplate <class T>\nusing is_unsigned_int_t = std::enable_if_t<is_unsigned_int<T>::value>;\n\
    \ntemplate <class T> using to_unsigned_t = typename to_unsigned<T>::type;\n\n\
    }  // namespace internal\n\n}  // namespace atcoder\n\n\n#line 14 \"lib/ac-library/atcoder/modint.hpp\"\
    \n\nnamespace atcoder {\n\nnamespace internal {\n\nstruct modint_base {};\nstruct\
    \ static_modint_base : modint_base {};\n\ntemplate <class T> using is_modint =\
    \ std::is_base_of<modint_base, T>;\ntemplate <class T> using is_modint_t = std::enable_if_t<is_modint<T>::value>;\n\
    \n}  // namespace internal\n\ntemplate <int m, std::enable_if_t<(1 <= m)>* = nullptr>\n\
    struct static_modint : internal::static_modint_base {\n    using mint = static_modint;\n\
    \n  public:\n    static constexpr int mod() { return m; }\n    static mint raw(int\
    \ v) {\n        mint x;\n        x._v = v;\n        return x;\n    }\n\n    static_modint()\
    \ : _v(0) {}\n    template <class T, internal::is_signed_int_t<T>* = nullptr>\n\
    \    static_modint(T v) {\n        long long x = (long long)(v % (long long)(umod()));\n\
    \        if (x < 0) x += umod();\n        _v = (unsigned int)(x);\n    }\n   \
    \ template <class T, internal::is_unsigned_int_t<T>* = nullptr>\n    static_modint(T\
    \ v) {\n        _v = (unsigned int)(v % umod());\n    }\n\n    unsigned int val()\
    \ const { return _v; }\n\n    mint& operator++() {\n        _v++;\n        if\
    \ (_v == umod()) _v = 0;\n        return *this;\n    }\n    mint& operator--()\
    \ {\n        if (_v == 0) _v = umod();\n        _v--;\n        return *this;\n\
    \    }\n    mint operator++(int) {\n        mint result = *this;\n        ++*this;\n\
    \        return result;\n    }\n    mint operator--(int) {\n        mint result\
    \ = *this;\n        --*this;\n        return result;\n    }\n\n    mint& operator+=(const\
    \ mint& rhs) {\n        _v += rhs._v;\n        if (_v >= umod()) _v -= umod();\n\
    \        return *this;\n    }\n    mint& operator-=(const mint& rhs) {\n     \
    \   _v -= rhs._v;\n        if (_v >= umod()) _v += umod();\n        return *this;\n\
    \    }\n    mint& operator*=(const mint& rhs) {\n        unsigned long long z\
    \ = _v;\n        z *= rhs._v;\n        _v = (unsigned int)(z % umod());\n    \
    \    return *this;\n    }\n    mint& operator/=(const mint& rhs) { return *this\
    \ = *this * rhs.inv(); }\n\n    mint operator+() const { return *this; }\n   \
    \ mint operator-() const { return mint() - *this; }\n\n    mint pow(long long\
    \ n) const {\n        assert(0 <= n);\n        mint x = *this, r = 1;\n      \
    \  while (n) {\n            if (n & 1) r *= x;\n            x *= x;\n        \
    \    n >>= 1;\n        }\n        return r;\n    }\n    mint inv() const {\n \
    \       if (prime) {\n            assert(_v);\n            return pow(umod() -\
    \ 2);\n        } else {\n            auto eg = internal::inv_gcd(_v, m);\n   \
    \         assert(eg.first == 1);\n            return eg.second;\n        }\n \
    \   }\n\n    friend mint operator+(const mint& lhs, const mint& rhs) {\n     \
    \   return mint(lhs) += rhs;\n    }\n    friend mint operator-(const mint& lhs,\
    \ const mint& rhs) {\n        return mint(lhs) -= rhs;\n    }\n    friend mint\
    \ operator*(const mint& lhs, const mint& rhs) {\n        return mint(lhs) *= rhs;\n\
    \    }\n    friend mint operator/(const mint& lhs, const mint& rhs) {\n      \
    \  return mint(lhs) /= rhs;\n    }\n    friend bool operator==(const mint& lhs,\
    \ const mint& rhs) {\n        return lhs._v == rhs._v;\n    }\n    friend bool\
    \ operator!=(const mint& lhs, const mint& rhs) {\n        return lhs._v != rhs._v;\n\
    \    }\n\n  private:\n    unsigned int _v;\n    static constexpr unsigned int\
    \ umod() { return m; }\n    static constexpr bool prime = internal::is_prime<m>;\n\
    };\n\ntemplate <int id> struct dynamic_modint : internal::modint_base {\n    using\
    \ mint = dynamic_modint;\n\n  public:\n    static int mod() { return (int)(bt.umod());\
    \ }\n    static void set_mod(int m) {\n        assert(1 <= m);\n        bt = internal::barrett(m);\n\
    \    }\n    static mint raw(int v) {\n        mint x;\n        x._v = v;\n   \
    \     return x;\n    }\n\n    dynamic_modint() : _v(0) {}\n    template <class\
    \ T, internal::is_signed_int_t<T>* = nullptr>\n    dynamic_modint(T v) {\n   \
    \     long long x = (long long)(v % (long long)(mod()));\n        if (x < 0) x\
    \ += mod();\n        _v = (unsigned int)(x);\n    }\n    template <class T, internal::is_unsigned_int_t<T>*\
    \ = nullptr>\n    dynamic_modint(T v) {\n        _v = (unsigned int)(v % mod());\n\
    \    }\n\n    unsigned int val() const { return _v; }\n\n    mint& operator++()\
    \ {\n        _v++;\n        if (_v == umod()) _v = 0;\n        return *this;\n\
    \    }\n    mint& operator--() {\n        if (_v == 0) _v = umod();\n        _v--;\n\
    \        return *this;\n    }\n    mint operator++(int) {\n        mint result\
    \ = *this;\n        ++*this;\n        return result;\n    }\n    mint operator--(int)\
    \ {\n        mint result = *this;\n        --*this;\n        return result;\n\
    \    }\n\n    mint& operator+=(const mint& rhs) {\n        _v += rhs._v;\n   \
    \     if (_v >= umod()) _v -= umod();\n        return *this;\n    }\n    mint&\
    \ operator-=(const mint& rhs) {\n        _v += mod() - rhs._v;\n        if (_v\
    \ >= umod()) _v -= umod();\n        return *this;\n    }\n    mint& operator*=(const\
    \ mint& rhs) {\n        _v = bt.mul(_v, rhs._v);\n        return *this;\n    }\n\
    \    mint& operator/=(const mint& rhs) { return *this = *this * rhs.inv(); }\n\
    \n    mint operator+() const { return *this; }\n    mint operator-() const { return\
    \ mint() - *this; }\n\n    mint pow(long long n) const {\n        assert(0 <=\
    \ n);\n        mint x = *this, r = 1;\n        while (n) {\n            if (n\
    \ & 1) r *= x;\n            x *= x;\n            n >>= 1;\n        }\n       \
    \ return r;\n    }\n    mint inv() const {\n        auto eg = internal::inv_gcd(_v,\
    \ mod());\n        assert(eg.first == 1);\n        return eg.second;\n    }\n\n\
    \    friend mint operator+(const mint& lhs, const mint& rhs) {\n        return\
    \ mint(lhs) += rhs;\n    }\n    friend mint operator-(const mint& lhs, const mint&\
    \ rhs) {\n        return mint(lhs) -= rhs;\n    }\n    friend mint operator*(const\
    \ mint& lhs, const mint& rhs) {\n        return mint(lhs) *= rhs;\n    }\n   \
    \ friend mint operator/(const mint& lhs, const mint& rhs) {\n        return mint(lhs)\
    \ /= rhs;\n    }\n    friend bool operator==(const mint& lhs, const mint& rhs)\
    \ {\n        return lhs._v == rhs._v;\n    }\n    friend bool operator!=(const\
    \ mint& lhs, const mint& rhs) {\n        return lhs._v != rhs._v;\n    }\n\n \
    \ private:\n    unsigned int _v;\n    static internal::barrett bt;\n    static\
    \ unsigned int umod() { return bt.umod(); }\n};\ntemplate <int id> internal::barrett\
    \ dynamic_modint<id>::bt(998244353);\n\nusing modint998244353 = static_modint<998244353>;\n\
    using modint1000000007 = static_modint<1000000007>;\nusing modint = dynamic_modint<-1>;\n\
    \nnamespace internal {\n\ntemplate <class T>\nusing is_static_modint = std::is_base_of<internal::static_modint_base,\
    \ T>;\n\ntemplate <class T>\nusing is_static_modint_t = std::enable_if_t<is_static_modint<T>::value>;\n\
    \ntemplate <class> struct is_dynamic_modint : public std::false_type {};\ntemplate\
    \ <int id>\nstruct is_dynamic_modint<dynamic_modint<id>> : public std::true_type\
    \ {};\n\ntemplate <class T>\nusing is_dynamic_modint_t = std::enable_if_t<is_dynamic_modint<T>::value>;\n\
    \n}  // namespace internal\n\n}  // namespace atcoder\n\n\n#line 1 \"lib/ac-library/atcoder/convolution.hpp\"\
    \n\n\n\n#line 9 \"lib/ac-library/atcoder/convolution.hpp\"\n\n#line 1 \"lib/ac-library/atcoder/internal_bit.hpp\"\
    \n\n\n\n#ifdef _MSC_VER\n#include <intrin.h>\n#endif\n\nnamespace atcoder {\n\n\
    namespace internal {\n\n// @param n `0 <= n`\n// @return minimum non-negative\
    \ `x` s.t. `n <= 2**x`\nint ceil_pow2(int n) {\n    int x = 0;\n    while ((1U\
    \ << x) < (unsigned int)(n)) x++;\n    return x;\n}\n\n// @param n `1 <= n`\n\
    // @return minimum non-negative `x` s.t. `(n & (1 << x)) != 0`\nconstexpr int\
    \ bsf_constexpr(unsigned int n) {\n    int x = 0;\n    while (!(n & (1 << x)))\
    \ x++;\n    return x;\n}\n\n// @param n `1 <= n`\n// @return minimum non-negative\
    \ `x` s.t. `(n & (1 << x)) != 0`\nint bsf(unsigned int n) {\n#ifdef _MSC_VER\n\
    \    unsigned long index;\n    _BitScanForward(&index, n);\n    return index;\n\
    #else\n    return __builtin_ctz(n);\n#endif\n}\n\n}  // namespace internal\n\n\
    }  // namespace atcoder\n\n\n#line 12 \"lib/ac-library/atcoder/convolution.hpp\"\
    \n\nnamespace atcoder {\n\nnamespace internal {\n\ntemplate <class mint,\n   \
    \       int g = internal::primitive_root<mint::mod()>,\n          internal::is_static_modint_t<mint>*\
    \ = nullptr>\nstruct fft_info {\n    static constexpr int rank2 = bsf_constexpr(mint::mod()\
    \ - 1);\n    std::array<mint, rank2 + 1> root;   // root[i]^(2^i) == 1\n    std::array<mint,\
    \ rank2 + 1> iroot;  // root[i] * iroot[i] == 1\n\n    std::array<mint, std::max(0,\
    \ rank2 - 2 + 1)> rate2;\n    std::array<mint, std::max(0, rank2 - 2 + 1)> irate2;\n\
    \n    std::array<mint, std::max(0, rank2 - 3 + 1)> rate3;\n    std::array<mint,\
    \ std::max(0, rank2 - 3 + 1)> irate3;\n\n    fft_info() {\n        root[rank2]\
    \ = mint(g).pow((mint::mod() - 1) >> rank2);\n        iroot[rank2] = root[rank2].inv();\n\
    \        for (int i = rank2 - 1; i >= 0; i--) {\n            root[i] = root[i\
    \ + 1] * root[i + 1];\n            iroot[i] = iroot[i + 1] * iroot[i + 1];\n \
    \       }\n\n        {\n            mint prod = 1, iprod = 1;\n            for\
    \ (int i = 0; i <= rank2 - 2; i++) {\n                rate2[i] = root[i + 2] *\
    \ prod;\n                irate2[i] = iroot[i + 2] * iprod;\n                prod\
    \ *= iroot[i + 2];\n                iprod *= root[i + 2];\n            }\n   \
    \     }\n        {\n            mint prod = 1, iprod = 1;\n            for (int\
    \ i = 0; i <= rank2 - 3; i++) {\n                rate3[i] = root[i + 3] * prod;\n\
    \                irate3[i] = iroot[i + 3] * iprod;\n                prod *= iroot[i\
    \ + 3];\n                iprod *= root[i + 3];\n            }\n        }\n   \
    \ }\n};\n\ntemplate <class mint, internal::is_static_modint_t<mint>* = nullptr>\n\
    void butterfly(std::vector<mint>& a) {\n    int n = int(a.size());\n    int h\
    \ = internal::ceil_pow2(n);\n\n    static const fft_info<mint> info;\n\n    int\
    \ len = 0;  // a[i, i+(n>>len), i+2*(n>>len), ..] is transformed\n    while (len\
    \ < h) {\n        if (h - len == 1) {\n            int p = 1 << (h - len - 1);\n\
    \            mint rot = 1;\n            for (int s = 0; s < (1 << len); s++) {\n\
    \                int offset = s << (h - len);\n                for (int i = 0;\
    \ i < p; i++) {\n                    auto l = a[i + offset];\n               \
    \     auto r = a[i + offset + p] * rot;\n                    a[i + offset] = l\
    \ + r;\n                    a[i + offset + p] = l - r;\n                }\n  \
    \              if (s + 1 != (1 << len))\n                    rot *= info.rate2[bsf(~(unsigned\
    \ int)(s))];\n            }\n            len++;\n        } else {\n          \
    \  // 4-base\n            int p = 1 << (h - len - 2);\n            mint rot =\
    \ 1, imag = info.root[2];\n            for (int s = 0; s < (1 << len); s++) {\n\
    \                mint rot2 = rot * rot;\n                mint rot3 = rot2 * rot;\n\
    \                int offset = s << (h - len);\n                for (int i = 0;\
    \ i < p; i++) {\n                    auto mod2 = 1ULL * mint::mod() * mint::mod();\n\
    \                    auto a0 = 1ULL * a[i + offset].val();\n                 \
    \   auto a1 = 1ULL * a[i + offset + p].val() * rot.val();\n                  \
    \  auto a2 = 1ULL * a[i + offset + 2 * p].val() * rot2.val();\n              \
    \      auto a3 = 1ULL * a[i + offset + 3 * p].val() * rot3.val();\n          \
    \          auto a1na3imag =\n                        1ULL * mint(a1 + mod2 - a3).val()\
    \ * imag.val();\n                    auto na2 = mod2 - a2;\n                 \
    \   a[i + offset] = a0 + a2 + a1 + a3;\n                    a[i + offset + 1 *\
    \ p] = a0 + a2 + (2 * mod2 - (a1 + a3));\n                    a[i + offset + 2\
    \ * p] = a0 + na2 + a1na3imag;\n                    a[i + offset + 3 * p] = a0\
    \ + na2 + (mod2 - a1na3imag);\n                }\n                if (s + 1 !=\
    \ (1 << len))\n                    rot *= info.rate3[bsf(~(unsigned int)(s))];\n\
    \            }\n            len += 2;\n        }\n    }\n}\n\ntemplate <class\
    \ mint, internal::is_static_modint_t<mint>* = nullptr>\nvoid butterfly_inv(std::vector<mint>&\
    \ a) {\n    int n = int(a.size());\n    int h = internal::ceil_pow2(n);\n\n  \
    \  static const fft_info<mint> info;\n\n    int len = h;  // a[i, i+(n>>len),\
    \ i+2*(n>>len), ..] is transformed\n    while (len) {\n        if (len == 1) {\n\
    \            int p = 1 << (h - len);\n            mint irot = 1;\n           \
    \ for (int s = 0; s < (1 << (len - 1)); s++) {\n                int offset = s\
    \ << (h - len + 1);\n                for (int i = 0; i < p; i++) {\n         \
    \           auto l = a[i + offset];\n                    auto r = a[i + offset\
    \ + p];\n                    a[i + offset] = l + r;\n                    a[i +\
    \ offset + p] =\n                        (unsigned long long)(mint::mod() + l.val()\
    \ - r.val()) *\n                        irot.val();\n                    ;\n \
    \               }\n                if (s + 1 != (1 << (len - 1)))\n          \
    \          irot *= info.irate2[bsf(~(unsigned int)(s))];\n            }\n    \
    \        len--;\n        } else {\n            // 4-base\n            int p =\
    \ 1 << (h - len);\n            mint irot = 1, iimag = info.iroot[2];\n       \
    \     for (int s = 0; s < (1 << (len - 2)); s++) {\n                mint irot2\
    \ = irot * irot;\n                mint irot3 = irot2 * irot;\n               \
    \ int offset = s << (h - len + 2);\n                for (int i = 0; i < p; i++)\
    \ {\n                    auto a0 = 1ULL * a[i + offset + 0 * p].val();\n     \
    \               auto a1 = 1ULL * a[i + offset + 1 * p].val();\n              \
    \      auto a2 = 1ULL * a[i + offset + 2 * p].val();\n                    auto\
    \ a3 = 1ULL * a[i + offset + 3 * p].val();\n\n                    auto a2na3iimag\
    \ =\n                        1ULL *\n                        mint((mint::mod()\
    \ + a2 - a3) * iimag.val()).val();\n\n                    a[i + offset] = a0 +\
    \ a1 + a2 + a3;\n                    a[i + offset + 1 * p] =\n               \
    \         (a0 + (mint::mod() - a1) + a2na3iimag) * irot.val();\n             \
    \       a[i + offset + 2 * p] =\n                        (a0 + a1 + (mint::mod()\
    \ - a2) + (mint::mod() - a3)) *\n                        irot2.val();\n      \
    \              a[i + offset + 3 * p] =\n                        (a0 + (mint::mod()\
    \ - a1) + (mint::mod() - a2na3iimag)) *\n                        irot3.val();\n\
    \                }\n                if (s + 1 != (1 << (len - 2)))\n         \
    \           irot *= info.irate3[bsf(~(unsigned int)(s))];\n            }\n   \
    \         len -= 2;\n        }\n    }\n}\n\ntemplate <class mint, internal::is_static_modint_t<mint>*\
    \ = nullptr>\nstd::vector<mint> convolution_naive(const std::vector<mint>& a,\n\
    \                                    const std::vector<mint>& b) {\n    int n\
    \ = int(a.size()), m = int(b.size());\n    std::vector<mint> ans(n + m - 1);\n\
    \    if (n < m) {\n        for (int j = 0; j < m; j++) {\n            for (int\
    \ i = 0; i < n; i++) {\n                ans[i + j] += a[i] * b[j];\n         \
    \   }\n        }\n    } else {\n        for (int i = 0; i < n; i++) {\n      \
    \      for (int j = 0; j < m; j++) {\n                ans[i + j] += a[i] * b[j];\n\
    \            }\n        }\n    }\n    return ans;\n}\n\ntemplate <class mint,\
    \ internal::is_static_modint_t<mint>* = nullptr>\nstd::vector<mint> convolution_fft(std::vector<mint>\
    \ a, std::vector<mint> b) {\n    int n = int(a.size()), m = int(b.size());\n \
    \   int z = 1 << internal::ceil_pow2(n + m - 1);\n    a.resize(z);\n    internal::butterfly(a);\n\
    \    b.resize(z);\n    internal::butterfly(b);\n    for (int i = 0; i < z; i++)\
    \ {\n        a[i] *= b[i];\n    }\n    internal::butterfly_inv(a);\n    a.resize(n\
    \ + m - 1);\n    mint iz = mint(z).inv();\n    for (int i = 0; i < n + m - 1;\
    \ i++) a[i] *= iz;\n    return a;\n}\n\n}  // namespace internal\n\ntemplate <class\
    \ mint, internal::is_static_modint_t<mint>* = nullptr>\nstd::vector<mint> convolution(std::vector<mint>&&\
    \ a, std::vector<mint>&& b) {\n    int n = int(a.size()), m = int(b.size());\n\
    \    if (!n || !m) return {};\n    if (std::min(n, m) <= 60) return convolution_naive(a,\
    \ b);\n    return internal::convolution_fft(a, b);\n}\n\ntemplate <class mint,\
    \ internal::is_static_modint_t<mint>* = nullptr>\nstd::vector<mint> convolution(const\
    \ std::vector<mint>& a,\n                              const std::vector<mint>&\
    \ b) {\n    int n = int(a.size()), m = int(b.size());\n    if (!n || !m) return\
    \ {};\n    if (std::min(n, m) <= 60) return convolution_naive(a, b);\n    return\
    \ internal::convolution_fft(a, b);\n}\n\ntemplate <unsigned int mod = 998244353,\n\
    \          class T,\n          std::enable_if_t<internal::is_integral<T>::value>*\
    \ = nullptr>\nstd::vector<T> convolution(const std::vector<T>& a, const std::vector<T>&\
    \ b) {\n    int n = int(a.size()), m = int(b.size());\n    if (!n || !m) return\
    \ {};\n\n    using mint = static_modint<mod>;\n    std::vector<mint> a2(n), b2(m);\n\
    \    for (int i = 0; i < n; i++) {\n        a2[i] = mint(a[i]);\n    }\n    for\
    \ (int i = 0; i < m; i++) {\n        b2[i] = mint(b[i]);\n    }\n    auto c2 =\
    \ convolution(move(a2), move(b2));\n    std::vector<T> c(n + m - 1);\n    for\
    \ (int i = 0; i < n + m - 1; i++) {\n        c[i] = c2[i].val();\n    }\n    return\
    \ c;\n}\n\nstd::vector<long long> convolution_ll(const std::vector<long long>&\
    \ a,\n                                      const std::vector<long long>& b) {\n\
    \    int n = int(a.size()), m = int(b.size());\n    if (!n || !m) return {};\n\
    \n    static constexpr unsigned long long MOD1 = 754974721;  // 2^24\n    static\
    \ constexpr unsigned long long MOD2 = 167772161;  // 2^25\n    static constexpr\
    \ unsigned long long MOD3 = 469762049;  // 2^26\n    static constexpr unsigned\
    \ long long M2M3 = MOD2 * MOD3;\n    static constexpr unsigned long long M1M3\
    \ = MOD1 * MOD3;\n    static constexpr unsigned long long M1M2 = MOD1 * MOD2;\n\
    \    static constexpr unsigned long long M1M2M3 = MOD1 * MOD2 * MOD3;\n\n    static\
    \ constexpr unsigned long long i1 =\n        internal::inv_gcd(MOD2 * MOD3, MOD1).second;\n\
    \    static constexpr unsigned long long i2 =\n        internal::inv_gcd(MOD1\
    \ * MOD3, MOD2).second;\n    static constexpr unsigned long long i3 =\n      \
    \  internal::inv_gcd(MOD1 * MOD2, MOD3).second;\n\n    auto c1 = convolution<MOD1>(a,\
    \ b);\n    auto c2 = convolution<MOD2>(a, b);\n    auto c3 = convolution<MOD3>(a,\
    \ b);\n\n    std::vector<long long> c(n + m - 1);\n    for (int i = 0; i < n +\
    \ m - 1; i++) {\n        unsigned long long x = 0;\n        x += (c1[i] * i1)\
    \ % MOD1 * M2M3;\n        x += (c2[i] * i2) % MOD2 * M1M3;\n        x += (c3[i]\
    \ * i3) % MOD3 * M1M2;\n        // B = 2^63, -B <= x, r(real value) < B\n    \
    \    // (x, x - M, x - 2M, or x - 3M) = r (mod 2B)\n        // r = c1[i] (mod\
    \ MOD1)\n        // focus on MOD1\n        // r = x, x - M', x - 2M', x - 3M'\
    \ (M' = M % 2^64) (mod 2B)\n        // r = x,\n        //     x - M' + (0 or 2B),\n\
    \        //     x - 2M' + (0, 2B or 4B),\n        //     x - 3M' + (0, 2B, 4B\
    \ or 6B) (without mod!)\n        // (r - x) = 0, (0)\n        //           - M'\
    \ + (0 or 2B), (1)\n        //           -2M' + (0 or 2B or 4B), (2)\n       \
    \ //           -3M' + (0 or 2B or 4B or 6B) (3) (mod MOD1)\n        // we checked\
    \ that\n        //   ((1) mod MOD1) mod 5 = 2\n        //   ((2) mod MOD1) mod\
    \ 5 = 3\n        //   ((3) mod MOD1) mod 5 = 4\n        long long diff =\n   \
    \         c1[i] - internal::safe_mod((long long)(x), (long long)(MOD1));\n   \
    \     if (diff < 0) diff += MOD1;\n        static constexpr unsigned long long\
    \ offset[5] = {\n            0, 0, M1M2M3, 2 * M1M2M3, 3 * M1M2M3};\n        x\
    \ -= offset[diff % 5];\n        c[i] = x;\n    }\n\n    return c;\n}\n\n}  //\
    \ namespace atcoder\n\n\n#line 1 \"tools/quo.hpp\"\n\n\n\n#line 5 \"tools/quo.hpp\"\
    \n\nnamespace tools {\n\n  template <typename M, typename N>\n  constexpr ::std::common_type_t<M,\
    \ N> quo(const M lhs, const N rhs) {\n    if (lhs >= 0) {\n      return lhs /\
    \ rhs;\n    } else {\n      if (rhs >= 0) {\n        return -((-lhs - 1 + rhs)\
    \ / rhs);\n      } else {\n        return (-lhs - 1 + -rhs) / -rhs;\n      }\n\
    \    }\n  }\n}\n\n\n#line 1 \"tools/mod.hpp\"\n\n\n\n#line 6 \"tools/mod.hpp\"\
    \n\nnamespace tools {\n\n  template <typename M, typename N>\n  constexpr ::std::common_type_t<M,\
    \ N> mod(const M lhs, const N rhs) {\n    if constexpr (::std::is_unsigned_v<M>\
    \ && ::std::is_unsigned_v<N>) {\n      return lhs % rhs;\n    } else {\n     \
    \ return lhs - ::tools::quo(lhs, rhs) * rhs;\n    }\n  }\n}\n\n\n#line 1 \"tools/floor.hpp\"\
    \n\n\n\n#line 6 \"tools/floor.hpp\"\n\nnamespace tools {\n\n  template <typename\
    \ M, typename N>\n  constexpr ::std::common_type_t<M, N> floor(const M lhs, const\
    \ N rhs) {\n    assert(rhs != 0);\n    return lhs / rhs - (((lhs > 0 && rhs <\
    \ 0) || (lhs < 0 && rhs > 0)) && lhs % rhs);\n  }\n}\n\n\n#line 1 \"tools/ssize.hpp\"\
    \n\n\n\n#line 6 \"tools/ssize.hpp\"\n\nnamespace tools {\n\n  template <typename\
    \ C>\n  constexpr auto ssize(const C& c) -> ::std::common_type_t<::std::ptrdiff_t,\
    \ ::std::make_signed_t<decltype(c.size())>> {\n    return c.size();\n  }\n}\n\n\
    \n#line 1 \"tools/ceil.hpp\"\n\n\n\n#line 6 \"tools/ceil.hpp\"\n\nnamespace tools\
    \ {\n\n  template <typename M, typename N>\n  constexpr ::std::common_type_t<M,\
    \ N> ceil(const M lhs, const N rhs) {\n    assert(rhs != 0);\n    return lhs /\
    \ rhs + (((lhs > 0 && rhs > 0) || (lhs < 0 && rhs < 0)) && lhs % rhs);\n  }\n\
    }\n\n\n#line 1 \"tools/garner2.hpp\"\n\n\n\n#line 1 \"tools/is_prime.hpp\"\n\n\
    \n\n#line 1 \"tools/prod_mod.hpp\"\n\n\n\nnamespace tools {\n\n  template <typename\
    \ T1, typename T2, typename T3>\n  constexpr T3 prod_mod(const T1 x, const T2\
    \ y, const T3 m) {\n    using u128 = unsigned __int128;\n    u128 prod_mod = u128(x\
    \ >= 0 ? x : -x) * u128(y >= 0 ? y : -y) % u128(m);\n    if ((x >= 0) ^ (y >=\
    \ 0)) prod_mod = u128(m) - prod_mod;\n    return prod_mod;\n  }\n}\n\n\n#line\
    \ 1 \"tools/pow_mod.hpp\"\n\n\n\n#line 6 \"tools/pow_mod.hpp\"\n\nnamespace tools\
    \ {\n\n  template <typename T1, typename T2, typename T3>\n  constexpr T3 pow_mod(const\
    \ T1 x, T2 n, const T3 m) {\n    if (m == 1) return 0;\n    T3 r = 1;\n    T3\
    \ y = ::tools::mod(x, m);\n    while (n > 0) {\n      if ((n & 1) > 0) {\n   \
    \     r = ::tools::prod_mod(r, y, m);\n      }\n      y = ::tools::prod_mod(y,\
    \ y, m);\n      n /= 2;\n    }\n    return r;\n  }\n}\n\n\n#line 7 \"tools/is_prime.hpp\"\
    \n\nnamespace tools {\n\n  constexpr bool is_prime(const ::std::uint_fast64_t\
    \ n) {\n    constexpr ::std::array<unsigned long long, 7> bases = {2, 325, 9375,\
    \ 28178, 450775, 9780504, 1795265022};\n\n    if (n <= 1) return false;\n    if\
    \ (n == 2) return true;\n    if (n % 2 == 0) return false;\n\n    auto d = n -\
    \ 1;\n    for (; d % 2 == 0; d /= 2);\n\n    for (const auto a : bases) {\n  \
    \    if (a % n == 0) return true;\n\n      auto power = d;\n      auto target\
    \ = ::tools::pow_mod(a, power, n);\n\n      bool is_composite = true;\n      if\
    \ (target == 1) is_composite = false;\n      for (; is_composite && power != n\
    \ - 1; power *= 2, target = ::tools::prod_mod(target, target, n)) {\n        if\
    \ (target == n - 1) is_composite = false;\n      }\n\n      if (is_composite)\
    \ {\n        return false;\n      }\n    }\n\n    return true;\n  }\n}\n\n\n#line\
    \ 6 \"tools/garner2.hpp\"\n\nnamespace tools {\n\n  template <typename M1, typename\
    \ M2>\n  long long garner2(const M1& a, const M2& b) {\n    using ull = unsigned\
    \ long long;\n    static constexpr ull m1_m2 = ull(M1::mod()) * ull(M2::mod());\n\
    \    static const M2 m1_inv_mod_m2 = M2::raw(M1::mod()).inv();\n\n    assert(M1::mod()\
    \ < M2::mod());\n    assert(::tools::is_prime(M1::mod()));\n    assert(::tools::is_prime(M2::mod()));\n\
    \n    // t = (b - a) / M1; (mod M2)\n    // return a + t * M1;\n    const M2 t\
    \ = (b - M2::raw(a.val())) * m1_inv_mod_m2;\n    ull r = t.val();\n    r *= M1::mod();\n\
    \    r += a.val();\n    if (r >= m1_m2) r -= m1_m2;\n    return r;\n  }\n}\n\n\
    \n#line 1 \"tools/pow2.hpp\"\n\n\n\n#line 6 \"tools/pow2.hpp\"\n\nnamespace tools\
    \ {\n\n  template <typename T, typename ::std::enable_if<::std::is_unsigned<T>::value,\
    \ ::std::nullptr_t>::type = nullptr>\n  constexpr T pow2(const T x) {\n    return\
    \ static_cast<T>(1) << x;\n  }\n\n  template <typename T, typename ::std::enable_if<::std::is_signed<T>::value,\
    \ ::std::nullptr_t>::type = nullptr>\n  constexpr T pow2(const T x) {\n    return\
    \ static_cast<T>(static_cast<typename ::std::make_unsigned<T>::type>(1) << static_cast<typename\
    \ ::std::make_unsigned<T>::type>(x));\n  }\n}\n\n\n#line 27 \"tools/bigint.hpp\"\
    \n\nnamespace tools {\n  class bigint {\n  private:\n    using mint1 = ::atcoder::static_modint<167772161>;\n\
    \    using mint2 = ::atcoder::static_modint<469762049>;\n\n    bool m_positive;\n\
    \    ::std::vector<::std::int_fast32_t> m_digits;\n    static constexpr ::std::int_fast32_t\
    \ BASE = 10000;\n    static constexpr ::std::int_fast32_t LOG10_BASE = 4;\n  \
    \  static constexpr ::std::array<::std::int_fast32_t, 5> POW10 = {1, 10, 100,\
    \ 1000, 10000};\n\n    static int compare_3way(const ::std::size_t lhs, const\
    \ ::std::size_t rhs) {\n      if (lhs < rhs) return -1;\n      if (lhs == rhs)\
    \ return 0;\n      return 1;\n    }\n    static int compare_3way_abs(const ::tools::bigint&\
    \ lhs, const ::tools::bigint& rhs) {\n      if (const auto comp = ::tools::bigint::compare_3way(lhs.m_digits.size(),\
    \ rhs.m_digits.size()); comp != 0) {\n        return comp;\n      }\n      for\
    \ (::std::size_t i = 0; i < lhs.m_digits.size(); ++i) {\n        if (const auto\
    \ comp = ::tools::bigint::compare_3way(lhs.m_digits[lhs.m_digits.size() - 1 -\
    \ i], rhs.m_digits[rhs.m_digits.size() - 1 - i]); comp != 0) {\n          return\
    \ comp;\n        }\n      }\n      return 0;\n    }\n\n    ::tools::bigint& regularize(const\
    \ int level) {\n      if (level > 0) {\n        if (level == 2) {\n          for\
    \ (::std::size_t i = 0; i + 1 < this->m_digits.size(); ++i) {\n            this->m_digits[i\
    \ + 1] += ::tools::quo(this->m_digits[i], BASE);\n            this->m_digits[i]\
    \ = ::tools::mod(this->m_digits[i], BASE);\n          }\n        } else {\n  \
    \        for (::std::size_t i = 0; i + 1 < this->m_digits.size(); ++i) {\n   \
    \         if (this->m_digits[i] < 0) {\n              this->m_digits[i] += BASE;\n\
    \              --this->m_digits[i + 1];\n            } else if (this->m_digits[i]\
    \ >= BASE) {\n              this->m_digits[i] -= BASE;\n              ++this->m_digits[i\
    \ + 1];\n            }\n          }\n        }\n        if (!this->m_digits.empty()\
    \ && this->m_digits.back() < 0) {\n          this->m_positive = !this->m_positive;\n\
    \          for (::std::size_t i = 0; i < this->m_digits.size(); ++i) {\n     \
    \       this->m_digits[i] = -this->m_digits[i];\n          }\n          for (::std::size_t\
    \ i = 0; i + 1 < this->m_digits.size(); ++i) {\n            if (this->m_digits[i]\
    \ < 0) {\n              this->m_digits[i] = BASE + this->m_digits[i];\n      \
    \        --this->m_digits[i + 1];\n            }\n          }\n        }\n   \
    \     if (level == 2) {\n          while (!this->m_digits.empty() && this->m_digits.back()\
    \ >= BASE) {\n            this->m_digits.push_back(this->m_digits.back() / BASE);\n\
    \            this->m_digits[this->m_digits.size() - 2] %= BASE;\n          }\n\
    \        } else {\n          if (!this->m_digits.empty() && this->m_digits.back()\
    \ >= BASE) {\n            this->m_digits.back() -= BASE;\n            this->m_digits.push_back(1);\n\
    \          }\n        }\n      }\n      while (!this->m_digits.empty() && this->m_digits.back()\
    \ == 0) {\n        this->m_digits.pop_back();\n      }\n      if (this->m_digits.empty()\
    \ && !this->m_positive) {\n        this->m_positive = true;\n      }\n      return\
    \ *this;\n    }\n\n  public:\n    ::tools::bigint& negate() {\n      if (!this->m_digits.empty())\
    \ {\n        this->m_positive = !this->m_positive;\n      }\n      return *this;\n\
    \    }\n    ::tools::bigint abs() const {\n      ::tools::bigint result(*this);\n\
    \      if (!result.m_positive) result.negate();\n      return result;\n    }\n\
    \    ::tools::bigint& multiply_by_pow10(const ::std::ptrdiff_t exponent) {\n \
    \     if (!this->m_digits.empty()) {\n        const ::std::ptrdiff_t exponent10000\
    \ = ::tools::floor(exponent, LOG10_BASE);\n        ::std::int_fast32_t mod = 0;\n\
    \        if (exponent10000 > 0) {\n          ::std::vector<::std::int_fast32_t>\
    \ zero(exponent10000, 0);\n          this->m_digits.insert(this->m_digits.begin(),\
    \ zero.begin(), zero.end());\n        } else if (exponent10000 < 0) {\n      \
    \    if (::tools::ssize(this->m_digits) >= -exponent10000) {\n            mod\
    \ = this->m_digits[-exponent10000 - 1] / POW10[LOG10_BASE * (exponent10000 + 1)\
    \ - exponent];\n          }\n          this->m_digits.erase(this->m_digits.begin(),\
    \ this->m_digits.begin() + ::std::min<::std::size_t>(-exponent10000, this->m_digits.size()));\n\
    \        }\n        if (const ::std::int_fast32_t coefficient = POW10[exponent\
    \ - LOG10_BASE * exponent10000]; coefficient > POW10[0]) {\n          for (auto&\
    \ d : this->m_digits) {\n            d *= coefficient;\n          }\n        \
    \  if (mod > 0 && this->m_digits.empty()) {\n            this->m_digits.push_back(0);\n\
    \          }\n          this->m_digits[0] += mod;\n          this->regularize(2);\n\
    \        } else {\n          this->regularize(0);\n        }\n      }\n      return\
    \ *this;\n    }\n    ::tools::bigint& divide_by_pow10(const ::std::ptrdiff_t exponent)\
    \ {\n      this->multiply_by_pow10(-exponent);\n      return *this;\n    }\n \
    \   static int compare_3way(const ::tools::bigint& lhs, const ::tools::bigint&\
    \ rhs) {\n      if (!lhs.m_positive && rhs.m_positive) return -1;\n      if (lhs.m_positive\
    \ && !rhs.m_positive) return 1;\n      return ::tools::bigint::compare_3way_abs(lhs,\
    \ rhs) * (lhs.m_positive ? 1 : -1);\n    }\n    int signum() const {\n      if\
    \ (!this->m_positive) return -1;\n      if (this->m_digits.empty()) return 0;\n\
    \      return 1;\n    }\n    ::std::size_t size() const {\n      if (this->m_digits.empty())\
    \ return 0;\n      return LOG10_BASE * (this->m_digits.size() - 1) + ::std::distance(POW10.begin(),\
    \ ::std::upper_bound(POW10.begin(), POW10.end(), this->m_digits[this->m_digits.size()\
    \ - 1]));\n    }\n    ::std::int_fast32_t operator[](const ::std::size_t i) const\
    \ {\n      return i < LOG10_BASE * this->m_digits.size() ? this->m_digits[i /\
    \ LOG10_BASE] / POW10[i % LOG10_BASE] % 10 : 0;\n    }\n\n  private:\n    ::tools::bigint&\
    \ internal_add(const ::tools::bigint& other, const bool plus) {\n      const bool\
    \ this_positive = this->m_positive;\n      if (!this_positive) {\n        this->negate();\n\
    \      }\n      this->m_digits.resize(::std::max(this->m_digits.size(), other.m_digits.size()));\n\
    \      if (this_positive == (other.m_positive == plus)) {\n        for (::std::size_t\
    \ i = 0; i < other.m_digits.size(); ++i) {\n          this->m_digits[i] += other.m_digits[i];\n\
    \        }\n      } else {\n        for (::std::size_t i = 0; i < other.m_digits.size();\
    \ ++i) {\n          this->m_digits[i] -= other.m_digits[i];\n        }\n     \
    \ }\n      this->regularize(1);\n      if (!this_positive) {\n        this->negate();\n\
    \      }\n      return *this;\n    }\n\n  public:\n    bigint() : m_positive(true)\
    \ {\n    }\n    bigint(const ::tools::bigint&) = default;\n    bigint(::tools::bigint&&)\
    \ = default;\n    ~bigint() = default;\n    ::tools::bigint& operator=(const ::tools::bigint&)\
    \ = default;\n    ::tools::bigint& operator=(::tools::bigint&&) = default;\n\n\
    \    template <typename T, typename ::std::enable_if<::std::is_integral_v<T>,\
    \ ::std::nullptr_t>::type = nullptr>\n    explicit bigint(T n) : m_positive(n\
    \ >= 0) {\n      while (n != 0) {\n        this->m_digits.push_back(n % BASE);\n\
    \        n /= BASE;\n      }\n      if (!this->m_positive) {\n        for (auto&\
    \ d : this->m_digits) {\n          d = -d;\n        }\n      }\n    }\n    explicit\
    \ bigint(const ::std::string& s) {\n      assert(!s.empty());\n\n      ::std::size_t\
    \ offset;\n      if (s[0] == '+') {\n        this->m_positive = true;\n      \
    \  offset = 1;\n      } else if (s[0] == '-') {\n        this->m_positive = false;\n\
    \        offset = 1;\n      } else {\n        this->m_positive = true;\n     \
    \   offset = 0;\n      }\n\n      this->m_digits.reserve(::tools::ceil<::std::size_t>(s.size()\
    \ - offset, LOG10_BASE));\n      for (::std::size_t i = 0; i < s.size() - offset;\
    \ i += LOG10_BASE) {\n        this->m_digits.push_back(0);\n        for (::std::size_t\
    \ j = ::std::min(i + LOG10_BASE, s.size() - offset); j --> i;) {\n          assert('0'\
    \ <= s[s.size() - 1 - j] && s[s.size() - 1 - j] <= '9');\n          this->m_digits.back()\
    \ = this->m_digits.back() * 10 + (s[s.size() - 1 - j] - '0');\n        }\n   \
    \   }\n\n      this->regularize(0);\n    }\n\n    friend bool operator==(const\
    \ ::tools::bigint& lhs, const ::tools::bigint& rhs) {\n      return lhs.m_positive\
    \ == rhs.m_positive && lhs.m_digits == rhs.m_digits;\n    }\n    friend bool operator!=(const\
    \ ::tools::bigint& lhs, const ::tools::bigint& rhs) {\n      return !(lhs == rhs);\n\
    \    }\n    friend bool operator<(const ::tools::bigint& lhs, const ::tools::bigint&\
    \ rhs) {\n      return ::tools::bigint::compare_3way(lhs, rhs) < 0;\n    }\n \
    \   friend bool operator>(const ::tools::bigint& lhs, const ::tools::bigint& rhs)\
    \ {\n      return ::tools::bigint::compare_3way(lhs, rhs) > 0;\n    }\n    friend\
    \ bool operator<=(const ::tools::bigint& lhs, const ::tools::bigint& rhs) {\n\
    \      return ::tools::bigint::compare_3way(lhs, rhs) <= 0;\n    }\n    friend\
    \ bool operator>=(const ::tools::bigint& lhs, const ::tools::bigint& rhs) {\n\
    \      return ::tools::bigint::compare_3way(lhs, rhs) >= 0;\n    }\n\n    ::tools::bigint\
    \ operator+() const {\n      return *this;\n    }\n    ::tools::bigint operator-()\
    \ const {\n      return ::tools::bigint(*this).negate();\n    }\n\n    ::tools::bigint&\
    \ operator+=(const ::tools::bigint& other) {\n      return this->internal_add(other,\
    \ true);\n    }\n    ::tools::bigint& operator-=(const ::tools::bigint& other)\
    \ {\n      return this->internal_add(other, false);\n    }\n    ::tools::bigint&\
    \ operator*=(const ::tools::bigint& other) {\n      // Constraint derived from\
    \ atcoder::convolution\n      assert(this->m_digits.size() + other.m_digits.size()\
    \ <= ::tools::pow2(25) + 1);\n\n      ::std::vector<mint1> a1, b1;\n      ::std::vector<mint2>\
    \ a2, b2;\n      a1.reserve(this->m_digits.size());\n      a2.reserve(this->m_digits.size());\n\
    \      b1.reserve(other.m_digits.size());\n      b2.reserve(other.m_digits.size());\n\
    \      for (const auto a_i : this->m_digits) {\n        a1.push_back(mint1::raw(a_i));\n\
    \        a2.push_back(mint2::raw(a_i));\n      }\n      for (const auto b_i :\
    \ other.m_digits) {\n        b1.push_back(mint1::raw(b_i));\n        b2.push_back(mint2::raw(b_i));\n\
    \      }\n\n      const auto c1 = ::atcoder::convolution(a1, b1);\n      const\
    \ auto c2 = ::atcoder::convolution(a2, b2);\n\n      this->m_digits.clear();\n\
    \      this->m_digits.reserve(c1.size() + 1);\n      long long carry = 0;\n  \
    \    for (::std::size_t i = 0; i < c1.size(); ++i) {\n\n        // Since a_i <=\
    \ 10^4 - 1 and b_i <= 10^4 - 1, c_i <= (10^4 - 1)^2 * min(this->m_digits.size(),\
    \ other.m_digits.size()) holds.\n        // In addition, since this->m_digits.size()\
    \ + other.m_digits.size() <= 2^25 + 1, c_i <= (10^4 - 1)^2 * 2^24 = 1677386072457216\
    \ holds eventually.\n        // 1677386072457216 < 167772161 * 469762049 = 78812994116517889\
    \ holds, so we can reconstruct c_i from mod(c_i, 167772161) and mod(c_i, 469762049)\
    \ by CRT.\n        long long c_i = ::tools::garner2(c1[i], c2[i]);\n\n       \
    \ c_i += carry;\n        carry = c_i / BASE;\n        c_i %= BASE;\n        this->m_digits.push_back(c_i);\n\
    \      }\n      if (carry > 0) {\n        this->m_digits.push_back(carry);\n \
    \     }\n\n      this->m_positive = this->m_positive == other.m_positive;\n  \
    \    this->regularize(0);\n      return *this;\n    }\n\n    friend ::tools::bigint\
    \ operator+(const ::tools::bigint& lhs, const ::tools::bigint& rhs) {\n      return\
    \ ::tools::bigint(lhs) += rhs;\n    }\n    friend ::tools::bigint operator-(const\
    \ ::tools::bigint& lhs, const ::tools::bigint& rhs) {\n      return ::tools::bigint(lhs)\
    \ -= rhs;\n    }\n    friend ::tools::bigint operator*(const ::tools::bigint&\
    \ lhs, const ::tools::bigint& rhs) {\n      return ::tools::bigint(lhs) *= rhs;\n\
    \    }\n\n    ::tools::bigint& operator++() {\n      return *this += ::tools::bigint(1);\n\
    \    }\n    ::tools::bigint operator++(int) {\n      ::tools::bigint old(*this);\n\
    \      ++(*this);\n      return old;\n    }\n    ::tools::bigint& operator--()\
    \ {\n      return *this -= ::tools::bigint(1);\n    }\n    ::tools::bigint operator--(int)\
    \ {\n      ::tools::bigint old(*this);\n      --(*this);\n      return old;\n\
    \    }\n\n    ::tools::bigint& operator/=(const ::tools::bigint& other) {\n  \
    \    assert(other.signum() != 0);\n      if (::tools::bigint::compare_3way_abs(*this,\
    \ other) < 0) {\n        this->m_digits.clear();\n        this->m_positive = true;\
    \        \n        return *this;\n      }\n      if (other.m_digits.size() ==\
    \ 1 && other.m_digits[0] == 1) {\n        this->m_positive = (this->m_positive\
    \ == other.m_positive);\n        return *this;\n      }\n\n      using u64 = ::std::uint_fast64_t;\n\
    \      static const ::tools::bigint u64_threshold((::std::numeric_limits<u64>::max()\
    \ - (BASE - 1)) / BASE);\n      using u128 = unsigned __int128;\n      static\
    \ const ::tools::bigint u128_threshold(\"34028236692093846346337460743176820\"\
    );\n\n      #define TOOLS_BIGINT_NAIVE(type) do {\\\n        if (::tools::bigint::compare_3way_abs(other,\
    \ type ## _threshold) <= 0) { \\\n          type mod = 0;\\\n          for (::std::size_t\
    \ i = other.m_digits.size(); i --> 0;) {\\\n            mod *= BASE;\\\n     \
    \       mod += other.m_digits[i];\\\n          }\\\n          \\\n          type\
    \ carry = 0;\\\n          for (::std::size_t i = this->m_digits.size(); i--> 0;)\
    \ {\\\n            carry *= BASE;\\\n            carry += this->m_digits[i];\\\
    \n            this->m_digits[i] = carry / mod;\\\n            carry %= mod;\\\n\
    \          }\\\n          \\\n          this->m_positive = (this->m_positive ==\
    \ other.m_positive);\\\n          return this->regularize(0);\\\n        }\\\n\
    \      } while (false)\n\n      TOOLS_BIGINT_NAIVE(u64);\n      TOOLS_BIGINT_NAIVE(u128);\n\
    \n      #undef TOOLS_BIGINT_NAIVE\n\n      using bigdecimal = ::std::pair<::tools::bigint,\
    \ ::std::ptrdiff_t>;\n      static const auto precision = [](const bigdecimal&\
    \ x) {\n        return x.first.m_digits.size();\n      };\n      static const\
    \ auto regularize = [](bigdecimal& x) -> bigdecimal& {\n        if (x.first.m_digits.empty())\
    \ {\n          x.second = 0;\n        }\n        return x;\n      };\n      static\
    \ const auto negate = [](bigdecimal& x) -> bigdecimal& {\n        x.first.negate();\n\
    \        return x;\n      };\n      static const auto make_abs = [](bigdecimal&\
    \ x) -> bigdecimal& {\n        if (!x.first.m_positive) {\n          negate(x);\n\
    \        }\n        return x;\n      };\n      static const auto set_precision\
    \ = [](bigdecimal& x, const ::std::size_t p) -> bigdecimal& {\n        const ::std::ptrdiff_t\
    \ diff = ::std::ptrdiff_t(p) - ::std::ptrdiff_t(precision(x));\n        x.first.multiply_by_pow10(diff\
    \ * LOG10_BASE);\n        x.second -= diff;\n        regularize(x);\n        return\
    \ x;\n      };\n      static const auto plus = [](bigdecimal& x, bigdecimal& y)\
    \ -> bigdecimal& {\n        if (x.second < y.second) {\n          set_precision(y,\
    \ precision(y) + (y.second - x.second));\n        } else if (x.second > y.second)\
    \ {\n          set_precision(x, precision(x) + (x.second - y.second));\n     \
    \   }\n        x.first += y.first;\n        regularize(x);\n        return x;\n\
    \      };\n      static const auto multiplies = [](bigdecimal& x, const bigdecimal&\
    \ y) -> bigdecimal& {\n        x.first *= y.first;\n        x.second += y.second;\n\
    \        regularize(x);\n        return x;\n      };\n      static const auto\
    \ compare_3way = [](const bigdecimal& x, const bigdecimal& y) {\n        if (!x.first.m_positive\
    \ && y.first.m_positive) return -1;\n        if (x.first.m_positive && !y.first.m_positive)\
    \ return 1;\n        return [&]() {\n          if (x.second <= y.second) {\n \
    \           if (const auto comp = ::tools::bigint::compare_3way(precision(x),\
    \ precision(y) + (y.second - x.second)); comp != 0) {\n              return comp;\n\
    \            }\n            for (::std::size_t i = 0; i < precision(x); ++i) {\n\
    \              if (const auto comp = ::tools::bigint::compare_3way(x.first.m_digits[precision(x)\
    \ - 1 - i], precision(y) >= i + 1 ? y.first.m_digits[precision(y) - 1 - i] : 0);\
    \ comp != 0) {\n                return comp;\n              }\n            }\n\
    \          } else {\n            if (const auto comp = ::tools::bigint::compare_3way(precision(x)\
    \ + (x.second - y.second), precision(y)); comp != 0) {\n              return comp;\n\
    \            }\n            for (::std::size_t i = 0; i < precision(y); ++i) {\n\
    \              if (const auto comp = ::tools::bigint::compare_3way(precision(x)\
    \ >= i + 1 ? x.first.m_digits[precision(x) - 1 - i] : 0, y.first.m_digits[precision(y)\
    \ - 1 - i]); comp != 0) {\n                return comp;\n              }\n   \
    \         }\n          }\n          return 0;\n        }() * (x.first.m_positive\
    \ ? 1 : -1);\n      };\n\n      const bool r_positive = this->m_positive == other.m_positive;\n\
    \      if (!this->m_positive) {\n        this->negate();\n      }\n      const\
    \ ::std::size_t inv_final_goal_precision = this->m_digits.size() - other.m_digits.size()\
    \ + 2;\n      const ::std::size_t inv_first_goal_precision = ::std::min<::std::size_t>(inv_final_goal_precision,\
    \ 3);\n\n      bigdecimal o(other, 0);\n      make_abs(o);\n      set_precision(o,\
    \ ::std::min<::std::size_t>(other.m_digits.size(), 6));\n      bigdecimal prev_inv(::tools::bigint(0),\
    \ 0);\n      bigdecimal inv(::tools::bigint(1), -::tools::ssize(other.m_digits));\n\
    \n      while (compare_3way(prev_inv, inv) != 0) {\n        prev_inv = inv;\n\
    \        negate(inv);\n        multiplies(inv, o);\n        bigdecimal two(::tools::bigint(2),\
    \ 0);\n        plus(inv, two);\n        multiplies(inv, prev_inv);\n        set_precision(inv,\
    \ ::std::min(precision(inv), inv_first_goal_precision));\n      }\n\n      if\
    \ (inv_first_goal_precision < inv_final_goal_precision) {\n        prev_inv =\
    \ bigdecimal(::tools::bigint(0), 0);\n        while (compare_3way(prev_inv, inv)\
    \ != 0) {\n          prev_inv = inv;\n          negate(inv);\n          multiplies(inv,\
    \ o);\n          bigdecimal two(::tools::bigint(2), 0);\n          plus(inv, two);\n\
    \          multiplies(inv, prev_inv);\n          set_precision(inv, ::std::min(precision(prev_inv)\
    \ * 2, inv_final_goal_precision));\n\n          const ::std::size_t o_precision\
    \ = precision(o);\n          o = bigdecimal(other, 0);\n          make_abs(o);\n\
    \          set_precision(o, ::std::min(o_precision * 2, other.m_digits.size()));\n\
    \        }\n      }\n\n      set_precision(inv, inv_final_goal_precision);\n \
    \     o = bigdecimal(other, 0);\n      make_abs(o);\n      bigdecimal r(*this,\
    \ 0);\n      multiplies(r, inv);\n      set_precision(r, precision(r) + r.second);\n\
    \n      ::tools::bigint r_plus_1 = r.first + ::tools::bigint(1);\n      if (*this\
    \ >= r_plus_1 * o.first) {\n        *this = ::std::move(r_plus_1);\n      } else\
    \ {\n        *this = ::std::move(r.first);\n      }\n\n      this->m_positive\
    \ = r_positive;\n      return *this;\n    }\n    friend ::tools::bigint operator/(const\
    \ ::tools::bigint& lhs, const ::tools::bigint& rhs) {\n      return ::tools::bigint(lhs)\
    \ /= rhs;\n    }\n    ::tools::bigint& operator%=(const ::tools::bigint& other)\
    \ {\n      using u64 = ::std::uint_fast64_t;\n      static const ::tools::bigint\
    \ u64_threshold((::std::numeric_limits<u64>::max() - (BASE - 1)) / BASE);\n  \
    \    using u128 = unsigned __int128;\n      static const ::tools::bigint u128_threshold(\"\
    34028236692093846346337460743176820\");\n\n      #define TOOLS_BIGINT_NAIVE(type)\
    \ do {\\\n        if (::tools::bigint::compare_3way_abs(other, type ## _threshold)\
    \ <= 0) { \\\n          type mod = 0;\\\n          for (::std::size_t i = other.m_digits.size();\
    \ i --> 0;) {\\\n            mod *= BASE;\\\n            mod += other.m_digits[i];\\\
    \n          }\\\n          \\\n          type result = 0;\\\n          for (::std::size_t\
    \ i = this->m_digits.size(); i --> 0;) {\\\n            result *= BASE;\\\n  \
    \          result += this->m_digits[i];\\\n            result %= mod;\\\n    \
    \      }\\\n          \\\n          this->m_digits.clear();\\\n          while\
    \ (result > 0) {\\\n            this->m_digits.push_back(result % BASE);\\\n \
    \           result /= BASE;\\\n          }\\\n          \\\n          return this->regularize(0);\\\
    \n        }\\\n      } while (false)\n\n      TOOLS_BIGINT_NAIVE(u64);\n     \
    \ TOOLS_BIGINT_NAIVE(u128);\n\n      #undef TOOLS_BIGINT_NAIVE\n\n      const\
    \ ::tools::bigint self = *this;\n      *this /= other;\n      this->negate();\n\
    \      *this *= other;\n      *this += self;\n      return *this;\n    }\n   \
    \ friend ::tools::bigint operator%(const ::tools::bigint& lhs, const ::tools::bigint&\
    \ rhs) {\n      return ::tools::bigint(lhs) %= rhs;\n    }\n\n    static ::tools::bigint\
    \ gcd(::tools::bigint x, ::tools::bigint y) {\n      if (x.signum() < 0) x.negate();\n\
    \      if (y.signum() < 0) y.negate();\n\n      while (y.signum() != 0) {\n  \
    \      x %= y;\n        ::std::swap(x, y);\n      }\n\n      return x;\n    }\n\
    \n    template <typename T, ::std::enable_if_t<::std::is_integral_v<T>, ::std::nullptr_t>\
    \ = nullptr>\n    explicit operator T() const {\n      assert(::tools::bigint(::std::numeric_limits<T>::min())\
    \ <= *this && *this <= ::tools::bigint(::std::numeric_limits<T>::max()));\n  \
    \    T result = 0;\n      for (::std::size_t i = this->m_digits.size(); i -->\
    \ 0;) {\n        result = result * BASE + this->m_digits[i] * (this->m_positive\
    \ ? 1 : -1);\n      }\n      return result;\n    }\n\n    explicit operator double()\
    \ const {\n      long double result = 0.0;\n      const ::std::size_t precision\
    \ = this->size();\n      for (::std::size_t i = 0; i < ::std::numeric_limits<long\
    \ double>::digits10; ++i) {\n        result = result * 10.0L + (precision >= i\
    \ + 1 ? (*this)[precision - 1 - i] : 0) * this->signum();\n      }\n      result\
    \ *= ::std::pow(10.0L, static_cast<long double>(precision) - static_cast<long\
    \ double>(::std::numeric_limits<long double>::digits10));\n      return static_cast<double>(result);\n\
    \    }\n\n    friend ::std::istream& operator>>(::std::istream& is, ::tools::bigint&\
    \ self) {\n      ::std::string s;\n      is >> s;\n      self = ::tools::bigint(s);\n\
    \      return is;\n    }\n    friend ::std::ostream& operator<<(::std::ostream&\
    \ os, const ::tools::bigint& self) {\n      if (!self.m_positive) {\n        os\
    \ << '-';\n      }\n      if (self.m_digits.empty()) {\n        return os << '0';\n\
    \      }\n      os << self.m_digits.back();\n      for (::std::size_t i = 1; i\
    \ < self.m_digits.size(); ++i) {\n        os << ::std::setw(LOG10_BASE) << ::std::setfill('0')\
    \ << self.m_digits[self.m_digits.size() - 1 - i];\n      }\n      return os;\n\
    \    }\n  };\n}\n\n\n#line 1 \"tools/bigdecimal.hpp\"\n\n\n\n#line 1 \"tools/rounding_mode.hpp\"\
    \n\n\n\nnamespace tools {\n  enum class rounding_mode {\n    ceiling,\n    down,\n\
    \    floor,\n    half_down,\n    half_even,\n    half_up,\n    up\n  };\n}\n\n\
    \n#line 16 \"tools/bigdecimal.hpp\"\n\nnamespace tools {\n  class bigdecimal {\n\
    \  private:\n    // *this := this->m_unscaled_value * (10 ** -this->m_scale)\n\
    \    ::tools::bigint m_unscaled_value;\n    ::std::ptrdiff_t m_scale;\n\n    ::tools::bigdecimal&\
    \ regularize() {\n      if (this->m_unscaled_value.signum() == 0) {\n        this->m_scale\
    \ = 0;\n      }\n      return *this;\n    }\n\n  public:\n    const ::tools::bigint&\
    \ unscaled_value() const {\n      return this->m_unscaled_value;\n    }\n    ::std::size_t\
    \ precision() const {\n      return this->m_unscaled_value.size();\n    }\n  \
    \  ::std::ptrdiff_t scale() const {\n      return this->m_scale;\n    }\n    int\
    \ signum() const {\n      return this->m_unscaled_value.signum();\n    }\n   \
    \ ::tools::bigdecimal& negate() {\n      this->m_unscaled_value.negate();\n  \
    \    return *this;\n    }\n    ::tools::bigdecimal abs() const {\n      ::tools::bigdecimal\
    \ result(*this);\n      if (result.signum() < 0) result.negate();\n      return\
    \ result;\n    }\n    ::tools::bigdecimal& multiply_by_pow10(const ::std::ptrdiff_t\
    \ n) {\n      this->m_scale -= n;\n      return *this;\n    }\n    ::tools::bigdecimal&\
    \ divide_by_pow10(const ::std::ptrdiff_t n) {\n      return this->multiply_by_pow10(-n);\n\
    \    }\n    ::tools::bigdecimal& set_scale(const ::std::ptrdiff_t s) {\n     \
    \ this->m_unscaled_value.multiply_by_pow10(s - this->m_scale);\n      this->m_scale\
    \ = s;\n      this->regularize();\n      return *this;\n    }\n    static int\
    \ compare_3way(const ::tools::bigdecimal& x, const ::tools::bigdecimal& y) {\n\
    \      if (const auto comp = ::tools::signum(x.m_unscaled_value.signum() - y.m_unscaled_value.signum());\
    \ comp != 0) {\n        return comp;\n      }\n      return [&]() {\n        ::tools::bigdecimal\
    \ abs_x(x);\n        if (abs_x.signum() < 0) abs_x.negate();\n        abs_x.set_scale(::std::max(x.m_scale,\
    \ y.m_scale));\n        ::tools::bigdecimal abs_y(y);\n        if (abs_y.signum()\
    \ < 0) abs_y.negate();\n        abs_y.set_scale(::std::max(x.m_scale, y.m_scale));\n\
    \        return ::tools::bigint::compare_3way(abs_x.m_unscaled_value, abs_y.m_unscaled_value);\n\
    \      }() * x.m_unscaled_value.signum();\n    }\n\n    bigdecimal() : m_unscaled_value(0),\
    \ m_scale(0) {\n    }\n    bigdecimal(const ::tools::bigdecimal&) = default;\n\
    \    bigdecimal(::tools::bigdecimal&&) = default;\n    ~bigdecimal() = default;\n\
    \    ::tools::bigdecimal& operator=(const ::tools::bigdecimal&) = default;\n \
    \   ::tools::bigdecimal& operator=(::tools::bigdecimal&&) = default;\n\n    explicit\
    \ bigdecimal(const long long n) : m_unscaled_value(n), m_scale(0) {\n    }\n \
    \   explicit bigdecimal(const ::tools::bigint& n) : m_unscaled_value(n), m_scale(0)\
    \ {\n    }\n    explicit bigdecimal(::std::string s) {\n      if (const auto pos\
    \ = s.find('.'); pos != ::std::string::npos) {\n        this->m_scale = s.size()\
    \ - pos - 1;\n        s.erase(pos, 1);\n      } else {\n        this->m_scale\
    \ = 0;\n      }\n      this->m_unscaled_value = ::tools::bigint(s);\n      this->regularize();\n\
    \    }\n\n    friend bool operator==(const ::tools::bigdecimal& lhs, const ::tools::bigdecimal&\
    \ rhs) {\n      return ::tools::bigdecimal::compare_3way(lhs, rhs) == 0;\n   \
    \ }\n    friend bool operator!=(const ::tools::bigdecimal& lhs, const ::tools::bigdecimal&\
    \ rhs) {\n      return ::tools::bigdecimal::compare_3way(lhs, rhs) != 0;\n   \
    \ }\n    friend bool operator<(const ::tools::bigdecimal& lhs, const ::tools::bigdecimal&\
    \ rhs) {\n      return ::tools::bigdecimal::compare_3way(lhs, rhs) < 0;\n    }\n\
    \    friend bool operator>(const ::tools::bigdecimal& lhs, const ::tools::bigdecimal&\
    \ rhs) {\n      return ::tools::bigdecimal::compare_3way(lhs, rhs) > 0;\n    }\n\
    \    friend bool operator<=(const ::tools::bigdecimal& lhs, const ::tools::bigdecimal&\
    \ rhs) {\n      return ::tools::bigdecimal::compare_3way(lhs, rhs) <= 0;\n   \
    \ }\n    friend bool operator>=(const ::tools::bigdecimal& lhs, const ::tools::bigdecimal&\
    \ rhs) {\n      return ::tools::bigdecimal::compare_3way(lhs, rhs) >= 0;\n   \
    \ }\n\n    ::tools::bigdecimal operator+() const {\n      return *this;\n    }\n\
    \    ::tools::bigdecimal operator-() const {\n      return ::tools::bigdecimal(*this).negate();\n\
    \    }\n\n    ::tools::bigdecimal& operator+=(::tools::bigdecimal other) {\n \
    \     const ::std::size_t scale = ::std::max(this->m_scale, other.m_scale);\n\
    \      this->set_scale(scale);\n      other.set_scale(scale);\n      this->m_unscaled_value\
    \ += other.m_unscaled_value;\n      return this->regularize();\n    }\n    ::tools::bigdecimal&\
    \ operator-=(::tools::bigdecimal other) {\n      const ::std::size_t scale = ::std::max(this->m_scale,\
    \ other.m_scale);\n      this->set_scale(scale);\n      other.set_scale(scale);\n\
    \      this->m_unscaled_value -= other.m_unscaled_value;\n      return this->regularize();\n\
    \    }\n    ::tools::bigdecimal& operator*=(const ::tools::bigdecimal& other)\
    \ {\n      this->m_unscaled_value *= other.m_unscaled_value;\n      this->m_scale\
    \ += other.m_scale;\n      return this->regularize();\n    }\n    ::tools::bigdecimal&\
    \ divide(const ::tools::bigdecimal& other, const ::std::ptrdiff_t scale, const\
    \ ::tools::rounding_mode rounding_mode) {\n      assert(other.signum() != 0);\n\
    \n      static const auto compare_3way_abs = [](::tools::bigdecimal& x, ::tools::bigdecimal&\
    \ y) {\n        const bool x_positive = x.signum() >= 0;\n        const bool y_positive\
    \ = y.signum() >= 0;\n        if (!x_positive) x.negate();\n        if (!y_positive)\
    \ y.negate();\n        const int result = ::tools::bigdecimal::compare_3way(x,\
    \ y);\n        if (!x_positive) x.negate();\n        if (!y_positive) y.negate();\n\
    \        return result;\n      };\n\n      ::tools::bigdecimal old_this(*this);\n\
    \n      this->m_unscaled_value.multiply_by_pow10(scale - (this->m_scale - other.m_scale));\n\
    \      this->m_unscaled_value /= other.m_unscaled_value;\n      this->m_scale\
    \ = scale;\n      this->regularize();\n\n      if ([&]() {\n        if (rounding_mode\
    \ == ::tools::rounding_mode::down) {\n          return false;\n        }\n   \
    \     if (rounding_mode == ::tools::rounding_mode::ceiling || rounding_mode ==\
    \ ::tools::rounding_mode::floor || rounding_mode == ::tools::rounding_mode::up)\
    \ {\n          if ((rounding_mode == ::tools::rounding_mode::ceiling && old_this.signum()\
    \ * other.signum() > 0)\n            || (rounding_mode == ::tools::rounding_mode::floor\
    \ && old_this.signum() * other.signum() < 0)\n            || rounding_mode ==\
    \ ::tools::rounding_mode::up) {\n            ::tools::bigdecimal d(*this);\n \
    \           d *= other;\n            return compare_3way_abs(old_this, d) > 0;\n\
    \          } else {\n            return false;\n          }\n        }\n\n   \
    \     ::tools::bigdecimal d(*this);\n        d += ::tools::bigdecimal(5 * old_this.signum()\
    \ * other.signum()).divide_by_pow10(scale + 1);\n        d *= other;\n       \
    \ const int comp = compare_3way_abs(old_this, d);\n        if (rounding_mode ==\
    \ ::tools::rounding_mode::half_down) {\n          return comp > 0;\n        }\n\
    \        if (rounding_mode == ::tools::rounding_mode::half_up) {\n          return\
    \ comp >= 0;\n        }\n        return comp > 0 || (comp == 0 && this->m_unscaled_value[0]\
    \ % 2 != 0);\n      }()) {\n        this->m_unscaled_value += ::tools::bigint(old_this.signum()\
    \ * other.signum());\n        this->regularize();\n      }\n\n      return *this;\n\
    \    }\n    ::tools::bigdecimal& divide(const ::tools::bigdecimal& other, const\
    \ ::std::ptrdiff_t scale) {\n      return this->divide(other, scale, ::tools::rounding_mode::half_even);\n\
    \    }\n    ::tools::bigdecimal& operator/=(const ::tools::bigdecimal& other)\
    \ {\n      return this->divide(other, this->m_scale - other.m_scale);\n    }\n\
    \n    friend ::tools::bigdecimal operator+(const ::tools::bigdecimal& lhs, const\
    \ ::tools::bigdecimal& rhs) {\n      return ::tools::bigdecimal(lhs) += rhs;\n\
    \    }\n    friend ::tools::bigdecimal operator-(const ::tools::bigdecimal& lhs,\
    \ const ::tools::bigdecimal& rhs) {\n      return ::tools::bigdecimal(lhs) -=\
    \ rhs;\n    }\n    friend ::tools::bigdecimal operator*(const ::tools::bigdecimal&\
    \ lhs, const ::tools::bigdecimal& rhs) {\n      return ::tools::bigdecimal(lhs)\
    \ *= rhs;\n    }\n    ::tools::bigdecimal divide_and_copy(const ::tools::bigdecimal&\
    \ other, const ::std::ptrdiff_t scale, const ::tools::rounding_mode rounding_mode)\
    \ const {\n      return ::tools::bigdecimal(*this).divide(other, scale, rounding_mode);\n\
    \    }\n    ::tools::bigdecimal divide_and_copy(const ::tools::bigdecimal& other,\
    \ const ::std::ptrdiff_t scale) const {\n      return ::tools::bigdecimal(*this).divide(other,\
    \ scale);\n    }\n    friend ::tools::bigdecimal operator/(const ::tools::bigdecimal&\
    \ lhs, const ::tools::bigdecimal& rhs) {\n      return ::tools::bigdecimal(lhs)\
    \ /= rhs;\n    }\n\n    template <typename T, ::std::enable_if_t<::std::is_integral_v<T>,\
    \ ::std::nullptr_t> = nullptr>\n    explicit operator T() const {\n      auto\
    \ x = *this;\n      x.set_scale(0);\n      return static_cast<T>(x.m_unscaled_value);\n\
    \    }\n\n    explicit operator double() const {\n      long double result = 0.0;\n\
    \      const ::std::size_t precision = this->precision();\n      for (::std::size_t\
    \ i = 0; i < ::std::numeric_limits<long double>::digits10; ++i) {\n        result\
    \ = result * 10.0L + (precision >= i + 1 ? this->m_unscaled_value[precision -\
    \ 1 - i] : 0) * this->signum();\n      }\n      result *= ::std::pow(10.0L, static_cast<long\
    \ double>(precision) - static_cast<long double>(this->m_scale) - static_cast<long\
    \ double>(::std::numeric_limits<long double>::digits10));\n      return static_cast<double>(result);\n\
    \    }\n\n    friend ::std::istream& operator>>(::std::istream& is, ::tools::bigdecimal&\
    \ self) {\n      ::std::string s;\n      is >> s;\n      self = ::tools::bigdecimal(s);\n\
    \      return is;\n    }\n    friend ::std::ostream& operator<<(::std::ostream&\
    \ os, const ::tools::bigdecimal& self) {\n      if (self.signum() < 0) {\n   \
    \     os << '-';\n      }\n      for (auto i = ::std::max(::tools::ssize(self.m_unscaled_value)\
    \ - 1, self.m_scale); i >= ::std::min<::std::ptrdiff_t>(0, self.m_scale); --i)\
    \ {\n        if (i == self.m_scale - 1) {\n          os << '.';\n        }\n \
    \       os << (0 <= i && i < ::tools::ssize(self.m_unscaled_value) ? self.m_unscaled_value[i]\
    \ : 0);\n      }\n      return os;\n    }\n  };\n}\n\n\n#line 14 \"tools/rational.hpp\"\
    \n\nnamespace tools {\n  class rational {\n  private:\n    ::tools::bigint m_numerator;\n\
    \    ::tools::bigint m_denominator;\n\n    ::tools::rational& regularize() {\n\
    \      if (this->m_denominator.signum() < 0) {\n        this->m_numerator.negate();\n\
    \        this->m_denominator.negate();\n      }\n      if (this->m_numerator.signum()\
    \ == 0) {\n        this->m_denominator = ::tools::bigint(1);\n      } else {\n\
    \        const ::tools::bigint gcd = ::tools::bigint::gcd(this->m_numerator, this->m_denominator);\n\
    \        this->m_numerator /= gcd;\n        this->m_denominator /= gcd;\n    \
    \  }\n      return *this;\n    }\n\n  public:\n    int signum() const {\n    \
    \  return this->m_numerator.signum();\n    }\n    ::tools::rational& negate()\
    \ {\n      this->m_numerator.negate();\n      return *this;\n    }\n    ::tools::rational\
    \ abs() const {\n      ::tools::rational result(*this);\n      if (result.signum()\
    \ < 0) result.negate();\n      return result;\n    }\n    static int compare_3way(const\
    \ ::tools::rational& lhs, const ::tools::rational& rhs) {\n      if (const auto\
    \ comp = ::tools::signum(lhs.signum() - rhs.signum()); comp != 0) {\n        return\
    \ comp;\n      }\n      return ::tools::bigint::compare_3way(lhs.m_numerator *\
    \ rhs.m_denominator, rhs.m_numerator * lhs.m_denominator);\n    }\n\n    rational()\
    \ : m_numerator(0), m_denominator(1) {\n    }\n    rational(const ::tools::rational&)\
    \ = default;\n    rational(::tools::rational&&) = default;\n    ~rational() =\
    \ default;\n    ::tools::rational& operator=(const ::tools::rational&) = default;\n\
    \    ::tools::rational& operator=(::tools::rational&&) = default;\n\n    explicit\
    \ rational(const long long n) : m_numerator(n), m_denominator(1) {\n    }\n  \
    \  explicit rational(const ::tools::bigint& n) : m_numerator(n), m_denominator(1)\
    \ {\n    }\n    explicit rational(const ::tools::bigdecimal& d)\n      : m_numerator(::tools::bigint(1).multiply_by_pow10(::std::max<::std::ptrdiff_t>(0,\
    \ -d.scale())) *= d.unscaled_value()),\n        m_denominator(::tools::bigint(1).multiply_by_pow10(::std::max<::std::ptrdiff_t>(0,\
    \ d.scale()))) {\n      this->regularize();\n    }\n    rational(const long long\
    \ numerator, const long long denominator)\n      : m_numerator(numerator), m_denominator(denominator)\
    \ {\n      assert(denominator != 0);\n      this->regularize();\n    }\n    rational(const\
    \ ::tools::bigint& numerator, const ::tools::bigint& denominator)\n      : m_numerator(numerator),\
    \ m_denominator(denominator) {\n      assert(this->m_denominator.signum() != 0);\n\
    \      this->regularize();\n    }\n\n    const ::tools::bigint& numerator() const\
    \ {\n      return this->m_numerator;\n    }\n    const ::tools::bigint& denominator()\
    \ const {\n      return this->m_denominator;\n    }\n\n    friend bool operator==(const\
    \ ::tools::rational& lhs, const ::tools::rational& rhs) {\n      return lhs.m_numerator\
    \ == rhs.m_numerator && lhs.m_denominator == rhs.m_denominator;\n    }\n    friend\
    \ bool operator!=(const ::tools::rational& lhs, const ::tools::rational& rhs)\
    \ {\n      return !(lhs == rhs);\n    }\n    friend bool operator<(const ::tools::rational&\
    \ lhs, const ::tools::rational& rhs) {\n      return ::tools::rational::compare_3way(lhs,\
    \ rhs) < 0;\n    }\n    friend bool operator>(const ::tools::rational& lhs, const\
    \ ::tools::rational& rhs) {\n      return ::tools::rational::compare_3way(lhs,\
    \ rhs) > 0;\n    }\n    friend bool operator<=(const ::tools::rational& lhs, const\
    \ ::tools::rational& rhs) {\n      return ::tools::rational::compare_3way(lhs,\
    \ rhs) <= 0;\n    }\n    friend bool operator>=(const ::tools::rational& lhs,\
    \ const ::tools::rational& rhs) {\n      return ::tools::rational::compare_3way(lhs,\
    \ rhs) >= 0;\n    }\n\n    ::tools::rational operator+() const {\n      return\
    \ *this;\n    }\n    ::tools::rational operator-() const {\n      return ::tools::rational(*this).negate();\n\
    \    }\n\n    ::tools::rational& operator+=(const ::tools::rational& other) {\n\
    \      this->m_numerator *= other.m_denominator;\n      this->m_numerator += other.m_numerator\
    \ * this->m_denominator;\n      this->m_denominator *= other.m_denominator;\n\
    \      return this->regularize();\n    }\n    friend ::tools::rational operator+(const\
    \ ::tools::rational& lhs, const ::tools::rational& rhs) {\n      return ::tools::rational(lhs)\
    \ += rhs;\n    }\n\n    ::tools::rational& operator-=(const ::tools::rational&\
    \ other) {\n      this->m_numerator *= other.m_denominator;\n      this->m_numerator\
    \ -= other.m_numerator * this->m_denominator;\n      this->m_denominator *= other.m_denominator;\n\
    \      return this->regularize();\n    }\n    friend ::tools::rational operator-(const\
    \ ::tools::rational& lhs, const ::tools::rational& rhs) {\n      return ::tools::rational(lhs)\
    \ -= rhs;\n    }\n\n    ::tools::rational& operator*=(const ::tools::rational&\
    \ other) {\n      this->m_numerator *= other.m_numerator;\n      this->m_denominator\
    \ *= other.m_denominator;\n      return this->regularize();\n    }\n    friend\
    \ ::tools::rational operator*(const ::tools::rational& lhs, const ::tools::rational&\
    \ rhs) {\n      return ::tools::rational(lhs) *= rhs;\n    }\n\n    ::tools::rational&\
    \ operator/=(const ::tools::rational& other) {\n      assert(other.signum() !=\
    \ 0);\n      this->m_numerator *= other.m_denominator;\n      this->m_denominator\
    \ *= other.m_numerator;\n      return this->regularize();\n    }\n    friend ::tools::rational\
    \ operator/(const ::tools::rational& lhs, const ::tools::rational& rhs) {\n  \
    \    return ::tools::rational(lhs) /= rhs;\n    }\n\n    template <typename T,\
    \ ::std::enable_if_t<::std::is_integral_v<T>, ::std::nullptr_t> = nullptr>\n \
    \   explicit operator T() const {\n      return static_cast<T>(this->m_numerator\
    \ / this->m_denominator);\n    }\n\n    explicit operator double() const {\n \
    \     ::tools::bigint unscaled_value(this->m_numerator);\n      unscaled_value.multiply_by_pow10((::std::numeric_limits<double>::digits10\
    \ + 2) - (::tools::ssize(this->m_numerator) - ::tools::ssize(this->m_denominator)));\n\
    \      unscaled_value /= this->m_denominator;\n\n      ::tools::bigdecimal result(unscaled_value);\n\
    \      result.divide_by_pow10((::std::numeric_limits<double>::digits10 + 2) -\
    \ (::tools::ssize(this->m_numerator) - ::tools::ssize(this->m_denominator)));\n\
    \      return static_cast<double>(result);\n    }\n\n    friend ::std::istream&\
    \ operator>>(::std::istream& is, ::tools::rational& self) {\n      ::tools::bigdecimal\
    \ value;\n      is >> value;\n      self = ::tools::rational(value);\n      return\
    \ is;\n    }\n    friend ::std::ostream& operator<<(::std::ostream& os, const\
    \ ::tools::rational& self) {\n      return os << '(' << self.m_numerator << '/'\
    \ << self.m_denominator << ')';\n    }\n  };\n\n  template <>\n  struct is_rational<::tools::rational>\
    \ {\n    static constexpr bool value = true;\n  };\n}\n\n\n#line 8 \"tests/directed_line_segment_2d/squared_distance.test.cpp\"\
    \n\nusing ll = long long;\nusing T = tools::rational;\n\nint main() {\n  std::cin.tie(nullptr);\n\
    \  std::ios_base::sync_with_stdio(false);\n\n  ll q;\n  std::cin >> q;\n  for\
    \ (ll i = 0; i < q; ++i) {\n    tools::vector2<T> p0, p1, p2, p3;\n    std::cin\
    \ >> p0 >> p1 >> p2 >> p3;\n    const tools::directed_line_segment_2d<T> s1(p0,\
    \ p1);\n    const tools::directed_line_segment_2d<T> s2(p2, p3);\n    std::cout\
    \ << std::fixed << std::setprecision(10) << std::sqrt(static_cast<double>(s1.squared_distance(s2)))\
    \ << '\\n';\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/CGL_2_D\"\n#define\
    \ ERROR 1e-9\n\n#include <iostream>\n#include \"tools/vector2.hpp\"\n#include\
    \ \"tools/directed_line_segment_2d.hpp\"\n#include \"tools/rational.hpp\"\n\n\
    using ll = long long;\nusing T = tools::rational;\n\nint main() {\n  std::cin.tie(nullptr);\n\
    \  std::ios_base::sync_with_stdio(false);\n\n  ll q;\n  std::cin >> q;\n  for\
    \ (ll i = 0; i < q; ++i) {\n    tools::vector2<T> p0, p1, p2, p3;\n    std::cin\
    \ >> p0 >> p1 >> p2 >> p3;\n    const tools::directed_line_segment_2d<T> s1(p0,\
    \ p1);\n    const tools::directed_line_segment_2d<T> s2(p2, p3);\n    std::cout\
    \ << std::fixed << std::setprecision(10) << std::sqrt(static_cast<double>(s1.squared_distance(s2)))\
    \ << '\\n';\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - tools/vector2.hpp
  - tools/abs.hpp
  - tools/pair_hash.hpp
  - tools/directed_line_segment_2d.hpp
  - tools/detail/geometry_2d.hpp
  - tools/is_rational.hpp
  - tools/less_by.hpp
  - tools/signum.hpp
  - tools/square.hpp
  - tools/monoid.hpp
  - tools/rational.hpp
  - tools/bigint.hpp
  - tools/quo.hpp
  - tools/mod.hpp
  - tools/floor.hpp
  - tools/ssize.hpp
  - tools/ceil.hpp
  - tools/garner2.hpp
  - tools/is_prime.hpp
  - tools/prod_mod.hpp
  - tools/pow_mod.hpp
  - tools/pow2.hpp
  - tools/bigdecimal.hpp
  - tools/rounding_mode.hpp
  isVerificationFile: true
  path: tests/directed_line_segment_2d/squared_distance.test.cpp
  requiredBy: []
  timestamp: '2022-10-08 19:22:04+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/directed_line_segment_2d/squared_distance.test.cpp
layout: document
redirect_from:
- /verify/tests/directed_line_segment_2d/squared_distance.test.cpp
- /verify/tests/directed_line_segment_2d/squared_distance.test.cpp.html
title: tests/directed_line_segment_2d/squared_distance.test.cpp
---
