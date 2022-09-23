---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/abs.hpp
    title: Unified interface for std::abs(x) and x.abs()
  - icon: ':heavy_check_mark:'
    path: tools/is_rational.hpp
    title: Check whether T is tools::rational
  - icon: ':heavy_check_mark:'
    path: tools/less_by.hpp
    title: std::less by key
  - icon: ':heavy_check_mark:'
    path: tools/monoid.hpp
    title: Typical monoids
  - icon: ':heavy_check_mark:'
    path: tools/pair_hash.hpp
    title: Hash of std::pair
  - icon: ':heavy_check_mark:'
    path: tools/signum.hpp
    title: Sign function
  - icon: ':heavy_check_mark:'
    path: tools/square.hpp
    title: $x^2$ under a given monoid
  - icon: ':heavy_check_mark:'
    path: tools/vector2.hpp
    title: 2D vector
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: tools/circle_2d.hpp
    title: Two-dimensional circle
  - icon: ':heavy_check_mark:'
    path: tools/directed_line_segment_2d.hpp
    title: Two-dimensional directed line segment
  - icon: ':warning:'
    path: tools/half_line_2d.hpp
    title: Two-dimensional half line
  - icon: ':heavy_check_mark:'
    path: tools/line_2d.hpp
    title: Two-dimensional line
  - icon: ':heavy_check_mark:'
    path: tools/polygon_2d.hpp
    title: Two-dimensional polygon
  - icon: ':heavy_check_mark:'
    path: tools/triangle_2d.hpp
    title: Two-dimensional triangle
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/circle_2d/where/with_radius.test.cpp
    title: tests/circle_2d/where/with_radius.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/circle_2d/where/without_radius.test.cpp
    title: tests/circle_2d/where/without_radius.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/directed_line_segment_2d/cross_point.test.cpp
    title: tests/directed_line_segment_2d/cross_point.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/directed_line_segment_2d/intersection.test.cpp
    title: tests/directed_line_segment_2d/intersection.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/directed_line_segment_2d/squared_distance.test.cpp
    title: tests/directed_line_segment_2d/squared_distance.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/line_2d/is_parallel_to.test.cpp
    title: tests/line_2d/is_parallel_to.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/line_2d/projection.test.cpp
    title: tests/line_2d/projection.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/polygon_2d/area.test.cpp
    title: tests/polygon_2d/area.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/polygon_2d/minimum_bounding_circle.test.cpp
    title: tests/polygon_2d/minimum_bounding_circle.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/polygon_2d/where.test.cpp
    title: tests/polygon_2d/where.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/triangle_2d/circumcircle.test.cpp
    title: tests/triangle_2d/circumcircle.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/triangle_2d/incircle.test.cpp
    title: tests/triangle_2d/incircle.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/detail/geometry_2d.hpp\"\n\n\n\n#include <algorithm>\n\
    #include <array>\n#include <cassert>\n#include <cmath>\n#include <cstddef>\n#include\
    \ <initializer_list>\n#include <limits>\n#include <optional>\n#include <type_traits>\n\
    #include <utility>\n#include <variant>\n#include <vector>\n#line 1 \"tools/abs.hpp\"\
    \n\n\n\n#line 5 \"tools/abs.hpp\"\n\nnamespace tools {\n\n  template <typename\
    \ T>\n  auto abs(const T& v) -> decltype(::std::abs(v)) {\n    return ::std::abs(v);\n\
    \  }\n\n  template <typename T>\n  auto abs(const T& v) -> decltype(v.abs()) {\n\
    \    return v.abs();\n  }\n}\n\n\n#line 1 \"tools/is_rational.hpp\"\n\n\n\nnamespace\
    \ tools {\n\n  template <typename T>\n  struct is_rational {\n    static constexpr\
    \ bool value = false;\n  };\n\n  template <typename T>\n  inline constexpr bool\
    \ is_rational_v = ::tools::is_rational<T>::value;\n}\n\n\n#line 1 \"tools/less_by.hpp\"\
    \n\n\n\nnamespace tools {\n\n  template <class F>\n  class less_by {\n  private:\n\
    \    F selector;\n\n  public:\n    less_by(const F& selector) : selector(selector)\
    \ {\n    }\n\n    template <class T>\n    bool operator()(const T& x, const T&\
    \ y) const {\n      return selector(x) < selector(y);\n    }\n  };\n}\n\n\n#line\
    \ 1 \"tools/signum.hpp\"\n\n\n\n#line 5 \"tools/signum.hpp\"\n\nnamespace tools\
    \ {\n\n  template <typename T>\n  constexpr int signum(const T x) noexcept {\n\
    \    if constexpr (::std::is_signed_v<T>) {\n      return (T(0) < x) - (x < T(0));\n\
    \    } else {\n      return T(0) < x;\n    }\n  }\n}\n\n\n#line 1 \"tools/square.hpp\"\
    \n\n\n\n#line 1 \"tools/monoid.hpp\"\n\n\n\n#line 6 \"tools/monoid.hpp\"\n#include\
    \ <numeric>\n\nnamespace tools {\n  namespace monoid {\n    template <typename\
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
    \ E;\n      }\n    };\n  }\n}\n\n\n#line 5 \"tools/square.hpp\"\n\nnamespace tools\
    \ {\n\n  template <typename M>\n  typename M::T square(const typename M::T& x)\
    \ {\n    return M::op(x, x);\n  }\n\n  template <typename T>\n  T square(const\
    \ T& x) {\n    return ::tools::square<::tools::monoid::multiplies<T>>(x);\n  }\n\
    }\n\n\n#line 1 \"tools/vector2.hpp\"\n\n\n\n#line 8 \"tools/vector2.hpp\"\n#include\
    \ <iostream>\n#include <functional>\n#line 1 \"tools/pair_hash.hpp\"\n\n\n\n#line\
    \ 6 \"tools/pair_hash.hpp\"\n#include <random>\n#line 8 \"tools/pair_hash.hpp\"\
    \n#include <cstdint>\n\nnamespace tools {\n\n  template <class T1, class T2>\n\
    \  struct pair_hash {\n    using result_type = ::std::size_t;\n    using argument_type\
    \ = ::std::pair<T1, T2>;\n    ::std::size_t operator()(const ::std::pair<T1, T2>&\
    \ key) const {\n      static const ::std::size_t salt = ::std::random_device()();\n\
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
    \ key.y));\n    }\n  };\n}\n\n\n#line 22 \"tools/detail/geometry_2d.hpp\"\n\n\
    namespace tools {\n  template <typename T, bool Filled, bool HasRadius = true>\n\
    \  class circle_2d;\n\n  template <typename T>\n  class directed_line_segment_2d;\n\
    \n  template <typename T>\n  class half_line_2d;\n\n  template <typename T>\n\
    \  class line_2d;\n\n  template <typename T, bool Filled>\n  class polygon_2d;\n\
    \n  template <typename T, bool Filled>\n  class triangle_2d;\n\n  template <typename\
    \ T, bool Filled, bool HasRadius>\n  class circle_2d {\n  private:\n    using\
    \ F = ::std::conditional<::std::is_floating_point_v<T>, T, double>;\n    ::tools::vector2<T>\
    \ m_center;\n    T m_radius;\n    T m_squared_radius;\n\n  public:\n    circle_2d()\
    \ = default;\n    circle_2d(const ::tools::circle_2d<T, Filled, HasRadius>&) =\
    \ default;\n    circle_2d(::tools::circle_2d<T, Filled, HasRadius>&&) = default;\n\
    \    ~circle_2d() = default;\n    ::tools::circle_2d<T, Filled, HasRadius>& operator=(const\
    \ ::tools::circle_2d<T, Filled, HasRadius>&) = default;\n    ::tools::circle_2d<T,\
    \ Filled, HasRadius>& operator=(::tools::circle_2d<T, Filled, HasRadius>&&) =\
    \ default;\n\n    circle_2d(const ::tools::vector2<T>& center, const T& radius_or_squared_radius);\n\
    \n    template <bool Filled_ = Filled>\n    ::std::enable_if_t<Filled_, F> area()\
    \ const;\n    ::tools::vector2<T> center() const;\n    template <bool HasRadius_\
    \ = HasRadius>\n    ::std::enable_if_t<HasRadius_, T> radius() const;\n    T squared_radius()\
    \ const;\n    ::std::pair<int, int> where(const ::tools::circle_2d<T, Filled,\
    \ HasRadius>& other) const;\n    int where(const ::tools::vector2<T>& p) const;\n\
    \n    template <typename T_, bool Filled_, bool HasRadius1, bool HasRadius2>\n\
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
    \ p) const;\n\n    template <typename T_>\n    friend ::std::enable_if_t<::tools::is_rational_v<T_>\
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
    \ <typename T, bool Filled, bool HasRadius> template <bool Filled_>\n  ::std::enable_if_t<Filled_,\
    \ typename circle_2d<T, Filled, HasRadius>::F> circle_2d<T, Filled, HasRadius>::area()\
    \ const {\n    return ::std::acos(static_cast<F>(-1)) * static_cast<F>(this->m_squared_radius);\n\
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
    \  }\n\n  template <typename T, bool Filled, bool HasRadius1, bool HasRadius2>\n\
    \  bool operator==(const ::tools::circle_2d<T, Filled, HasRadius1>& lhs, const\
    \ ::tools::circle_2d<T, Filled, HasRadius2>& rhs) {\n    return lhs.m_center ==\
    \ rhs.m_center && lhs.m_squared_radius == rhs.m_squared_radius;\n  }\n\n  template\
    \ <typename T, bool Filled, bool HasRadius1, bool HasRadius2>\n  bool operator!=(const\
    \ ::tools::circle_2d<T, Filled, HasRadius1>& lhs, const ::tools::circle_2d<T,\
    \ Filled, HasRadius2>& rhs) {\n    return !(lhs == rhs);\n  }\n\n  template <typename\
    \ T>\n  directed_line_segment_2d<T>::directed_line_segment_2d(const ::tools::vector2<T>&\
    \ p1, const ::tools::vector2<T>& p2) :\n    m_p1(p1),\n    m_p2(p2) {\n    assert(p1\
    \ != p2);\n  }\n\n  template <typename T>\n  bool directed_line_segment_2d<T>::contains(const\
    \ ::tools::vector2<T>& p) const {\n    if (p == this->m_p1 || p == this->m_p2)\
    \ return true;\n    const ::tools::line_2d<T> l = this->to_line();\n    if (!l.contains(p))\
    \ return false;\n    const T d = (p - this->m_p1).inner_product(this->to_vector());\n\
    \    return T(0) <= d && d <= this->squared_length();\n  }\n\n  template <typename\
    \ T> template <typename T_>\n  ::std::enable_if_t<::tools::is_rational_v<T_> ||\
    \ ::std::is_floating_point_v<T_>, ::std::optional<::tools::vector2<T>>>\n  directed_line_segment_2d<T>::cross_point(const\
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
    \ T>\n  ::std::enable_if_t<::tools::is_rational_v<T> || ::std::is_floating_point_v<T>,\
    \ ::std::optional<::std::variant<::tools::vector2<T>, ::tools::directed_line_segment_2d<T>>>>\n\
    \  operator&(const ::tools::line_2d<T>& lhs, const ::tools::directed_line_segment_2d<T>&\
    \ rhs) {\n    return rhs & lhs;\n  }\n\n  template <typename T>\n  ::std::enable_if_t<::tools::is_rational_v<T>\
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
    \ 1;\n    } else {\n      return 2;\n    }\n  }\n}\n\n\n"
  code: "#ifndef TOOLS_DETAIL_GEOMETRY_2D_HPP\n#define TOOLS_DETAIL_GEOMETRY_2D_HPP\n\
    \n#include <algorithm>\n#include <array>\n#include <cassert>\n#include <cmath>\n\
    #include <cstddef>\n#include <initializer_list>\n#include <limits>\n#include <optional>\n\
    #include <type_traits>\n#include <utility>\n#include <variant>\n#include <vector>\n\
    #include \"tools/abs.hpp\"\n#include \"tools/is_rational.hpp\"\n#include \"tools/less_by.hpp\"\
    \n#include \"tools/signum.hpp\"\n#include \"tools/square.hpp\"\n#include \"tools/vector2.hpp\"\
    \n\nnamespace tools {\n  template <typename T, bool Filled, bool HasRadius = true>\n\
    \  class circle_2d;\n\n  template <typename T>\n  class directed_line_segment_2d;\n\
    \n  template <typename T>\n  class half_line_2d;\n\n  template <typename T>\n\
    \  class line_2d;\n\n  template <typename T, bool Filled>\n  class polygon_2d;\n\
    \n  template <typename T, bool Filled>\n  class triangle_2d;\n\n  template <typename\
    \ T, bool Filled, bool HasRadius>\n  class circle_2d {\n  private:\n    using\
    \ F = ::std::conditional<::std::is_floating_point_v<T>, T, double>;\n    ::tools::vector2<T>\
    \ m_center;\n    T m_radius;\n    T m_squared_radius;\n\n  public:\n    circle_2d()\
    \ = default;\n    circle_2d(const ::tools::circle_2d<T, Filled, HasRadius>&) =\
    \ default;\n    circle_2d(::tools::circle_2d<T, Filled, HasRadius>&&) = default;\n\
    \    ~circle_2d() = default;\n    ::tools::circle_2d<T, Filled, HasRadius>& operator=(const\
    \ ::tools::circle_2d<T, Filled, HasRadius>&) = default;\n    ::tools::circle_2d<T,\
    \ Filled, HasRadius>& operator=(::tools::circle_2d<T, Filled, HasRadius>&&) =\
    \ default;\n\n    circle_2d(const ::tools::vector2<T>& center, const T& radius_or_squared_radius);\n\
    \n    template <bool Filled_ = Filled>\n    ::std::enable_if_t<Filled_, F> area()\
    \ const;\n    ::tools::vector2<T> center() const;\n    template <bool HasRadius_\
    \ = HasRadius>\n    ::std::enable_if_t<HasRadius_, T> radius() const;\n    T squared_radius()\
    \ const;\n    ::std::pair<int, int> where(const ::tools::circle_2d<T, Filled,\
    \ HasRadius>& other) const;\n    int where(const ::tools::vector2<T>& p) const;\n\
    \n    template <typename T_, bool Filled_, bool HasRadius1, bool HasRadius2>\n\
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
    \ p) const;\n\n    template <typename T_>\n    friend ::std::enable_if_t<::tools::is_rational_v<T_>\
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
    \ <typename T, bool Filled, bool HasRadius> template <bool Filled_>\n  ::std::enable_if_t<Filled_,\
    \ typename circle_2d<T, Filled, HasRadius>::F> circle_2d<T, Filled, HasRadius>::area()\
    \ const {\n    return ::std::acos(static_cast<F>(-1)) * static_cast<F>(this->m_squared_radius);\n\
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
    \  }\n\n  template <typename T, bool Filled, bool HasRadius1, bool HasRadius2>\n\
    \  bool operator==(const ::tools::circle_2d<T, Filled, HasRadius1>& lhs, const\
    \ ::tools::circle_2d<T, Filled, HasRadius2>& rhs) {\n    return lhs.m_center ==\
    \ rhs.m_center && lhs.m_squared_radius == rhs.m_squared_radius;\n  }\n\n  template\
    \ <typename T, bool Filled, bool HasRadius1, bool HasRadius2>\n  bool operator!=(const\
    \ ::tools::circle_2d<T, Filled, HasRadius1>& lhs, const ::tools::circle_2d<T,\
    \ Filled, HasRadius2>& rhs) {\n    return !(lhs == rhs);\n  }\n\n  template <typename\
    \ T>\n  directed_line_segment_2d<T>::directed_line_segment_2d(const ::tools::vector2<T>&\
    \ p1, const ::tools::vector2<T>& p2) :\n    m_p1(p1),\n    m_p2(p2) {\n    assert(p1\
    \ != p2);\n  }\n\n  template <typename T>\n  bool directed_line_segment_2d<T>::contains(const\
    \ ::tools::vector2<T>& p) const {\n    if (p == this->m_p1 || p == this->m_p2)\
    \ return true;\n    const ::tools::line_2d<T> l = this->to_line();\n    if (!l.contains(p))\
    \ return false;\n    const T d = (p - this->m_p1).inner_product(this->to_vector());\n\
    \    return T(0) <= d && d <= this->squared_length();\n  }\n\n  template <typename\
    \ T> template <typename T_>\n  ::std::enable_if_t<::tools::is_rational_v<T_> ||\
    \ ::std::is_floating_point_v<T_>, ::std::optional<::tools::vector2<T>>>\n  directed_line_segment_2d<T>::cross_point(const\
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
    \ T>\n  ::std::enable_if_t<::tools::is_rational_v<T> || ::std::is_floating_point_v<T>,\
    \ ::std::optional<::std::variant<::tools::vector2<T>, ::tools::directed_line_segment_2d<T>>>>\n\
    \  operator&(const ::tools::line_2d<T>& lhs, const ::tools::directed_line_segment_2d<T>&\
    \ rhs) {\n    return rhs & lhs;\n  }\n\n  template <typename T>\n  ::std::enable_if_t<::tools::is_rational_v<T>\
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
    \ 1;\n    } else {\n      return 2;\n    }\n  }\n}\n\n#endif\n"
  dependsOn:
  - tools/abs.hpp
  - tools/is_rational.hpp
  - tools/less_by.hpp
  - tools/signum.hpp
  - tools/square.hpp
  - tools/monoid.hpp
  - tools/vector2.hpp
  - tools/pair_hash.hpp
  isVerificationFile: false
  path: tools/detail/geometry_2d.hpp
  requiredBy:
  - tools/directed_line_segment_2d.hpp
  - tools/triangle_2d.hpp
  - tools/half_line_2d.hpp
  - tools/line_2d.hpp
  - tools/circle_2d.hpp
  - tools/polygon_2d.hpp
  timestamp: '2022-09-24 06:34:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/polygon_2d/minimum_bounding_circle.test.cpp
  - tests/polygon_2d/area.test.cpp
  - tests/polygon_2d/where.test.cpp
  - tests/triangle_2d/incircle.test.cpp
  - tests/triangle_2d/circumcircle.test.cpp
  - tests/line_2d/projection.test.cpp
  - tests/line_2d/is_parallel_to.test.cpp
  - tests/circle_2d/where/with_radius.test.cpp
  - tests/circle_2d/where/without_radius.test.cpp
  - tests/directed_line_segment_2d/squared_distance.test.cpp
  - tests/directed_line_segment_2d/cross_point.test.cpp
  - tests/directed_line_segment_2d/intersection.test.cpp
documentation_of: tools/detail/geometry_2d.hpp
layout: document
redirect_from:
- /library/tools/detail/geometry_2d.hpp
- /library/tools/detail/geometry_2d.hpp.html
title: tools/detail/geometry_2d.hpp
---
