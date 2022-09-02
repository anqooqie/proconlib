---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: tools/abs.hpp
    title: Unified interface for std::abs(x) and x.abs()
  - icon: ':question:'
    path: tools/ccw.hpp
    title: Counter clockwise function
  - icon: ':question:'
    path: tools/less_by.hpp
    title: std::less by key
  - icon: ':question:'
    path: tools/pair_hash.hpp
    title: Hash of std::pair
  - icon: ':question:'
    path: tools/vector2.hpp
    title: 2D vector
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/convex_hull.test.cpp
    title: tests/convex_hull.test.cpp
  - icon: ':x:'
    path: tests/polygon_2d/minimum_bounding_circle.test.cpp
    title: tests/polygon_2d/minimum_bounding_circle.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/convex_hull.hpp\"\n\n\n\n#include <type_traits>\n\
    #include <vector>\n#include <cstddef>\n#include <numeric>\n#include <algorithm>\n\
    #include <utility>\n#include <iterator>\n#include <stack>\n#line 1 \"tools/vector2.hpp\"\
    \n\n\n\n#line 5 \"tools/vector2.hpp\"\n#include <cmath>\n#line 7 \"tools/vector2.hpp\"\
    \n#include <array>\n#include <iostream>\n#include <functional>\n#line 1 \"tools/abs.hpp\"\
    \n\n\n\n#line 5 \"tools/abs.hpp\"\n\nnamespace tools {\n\n  template <typename\
    \ T>\n  auto abs(const T& v) -> decltype(::std::abs(v)) {\n    return ::std::abs(v);\n\
    \  }\n\n  template <typename T>\n  auto abs(const T& v) -> decltype(v.abs()) {\n\
    \    return v.abs();\n  }\n}\n\n\n#line 1 \"tools/pair_hash.hpp\"\n\n\n\n#line\
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
    \ key.y));\n    }\n  };\n}\n\n\n#line 1 \"tools/less_by.hpp\"\n\n\n\nnamespace\
    \ tools {\n\n  template <class F>\n  class less_by {\n  private:\n    F selector;\n\
    \n  public:\n    less_by(const F& selector) : selector(selector) {\n    }\n\n\
    \    template <class T>\n    bool operator()(const T& x, const T& y) const {\n\
    \      return selector(x) < selector(y);\n    }\n  };\n}\n\n\n#line 1 \"tools/ccw.hpp\"\
    \n\n\n\n#line 5 \"tools/ccw.hpp\"\n\nnamespace tools {\n  template <typename T>\n\
    \  ::std::int_fast64_t ccw(const ::tools::vector2<T>& a, ::tools::vector2<T> b,\
    \ ::tools::vector2<T> c) {\n    b -= a;\n    c -= a;\n    if (b.outer_product(c)\
    \ > 0) return +1;\n    if (b.outer_product(c) < 0) return -1;\n    if (b.inner_product(c)\
    \ < 0) return +2;\n    if (b.squared_l2_norm() < c.squared_l2_norm()) return -2;\n\
    \    return 0;\n  }\n}\n\n\n#line 15 \"tools/convex_hull.hpp\"\n\nnamespace tools\
    \ {\n  template <typename InputIterator, typename OutputIterator>\n  void convex_hull(const\
    \ InputIterator begin, const InputIterator end, bool minimum, OutputIterator result)\
    \ {\n    using T = ::std::decay_t<decltype(begin->x)>;\n\n    const ::std::vector<::tools::vector2<T>>\
    \ v(begin, end);\n    ::std::vector<::std::size_t> a(v.size());\n    ::std::iota(a.begin(),\
    \ a.end(), 0);\n    ::std::sort(a.begin(), a.end(), ::tools::less_by([&](const\
    \ T& i) {\n      return ::std::make_pair(v[i].x, v[i].y);\n    }));\n    ::std::vector<::std::vector<::std::size_t>>\
    \ duplicates;\n\n    if (minimum) {\n      ::std::size_t vl = 0;\n      for (::std::size_t\
    \ vr = 0, al = 0, ar = 0; al < a.size(); vl = vr, al = ar) {\n        for (; ar\
    \ < a.size() && v[a[al]].x == v[a[ar]].x; ::std::swap(a[vr], a[ar]), ++vr, ++ar);\n\
    \        if (v[a[vl]].y == v[a[vr - 1]].y) {\n          vr -= vr - vl - 1;\n \
    \         duplicates.emplace_back();\n          duplicates.back().push_back(a[vl]);\n\
    \        } else {\n          ::std::swap(a[vl + 1], a[vr - 1]);\n          vr\
    \ -= vr - vl - 2;\n          duplicates.emplace_back();\n          duplicates.back().push_back(a[vl]);\n\
    \          duplicates.emplace_back();\n          duplicates.back().push_back(a[vl\
    \ + 1]);\n        }\n      }\n      a.erase(::std::next(a.begin(), vl), a.end());\n\
    \    } else {\n      ::std::size_t vl = 0;\n      for (::std::size_t vr = 0, al\
    \ = 0, ar = 0; al < a.size(); vl = vr, al = ar) {\n        for (; ar < a.size()\
    \ && v[a[al]] == v[a[ar]]; ::std::swap(a[vr], a[ar]), ++vr, ++ar);\n        duplicates.emplace_back();\n\
    \        for (::std::size_t i = vl; i < vr; ++i) {\n          duplicates.back().push_back(a[i]);\n\
    \        }\n        vr -= vr - vl - 1;\n      }\n      a.erase(::std::next(a.begin(),\
    \ vl), a.end());\n    }\n\n    ::std::vector<::std::size_t> convex_hull;\n   \
    \ if (a.size() >= 3) {\n\n      convex_hull.push_back(0);\n      convex_hull.push_back(1);\n\
    \      for (::std::size_t p3 = 2; p3 < a.size(); ++p3) {\n        while (convex_hull.size()\
    \ >= 2) {\n          const int ccw = ::tools::ccw(v[a[convex_hull.rbegin()[1]]],\
    \ v[a[convex_hull.back()]], v[a[p3]]);\n          if (ccw == 1 || (!minimum &&\
    \ ccw == -2)) {\n            break;\n          }\n          convex_hull.pop_back();\n\
    \        }\n        convex_hull.push_back(p3);\n      }\n\n      const ::std::size_t\
    \ threshold = convex_hull.size() + 1;\n      for (::std::size_t p3 = convex_hull.back();\
    \ p3 --> 0;) {\n        while (convex_hull.size() >= threshold) {\n          const\
    \ int ccw = ::tools::ccw(v[a[convex_hull.rbegin()[1]]], v[a[convex_hull.back()]],\
    \ v[a[p3]]);\n          if (ccw == 1 || (!minimum && ccw == -2)) {\n         \
    \   break;\n          }\n          convex_hull.pop_back();\n        }\n      \
    \  convex_hull.push_back(p3);\n      }\n      convex_hull.pop_back();\n\n    }\
    \ else {\n      for (::std::size_t i = 0; i < a.size(); ++i) {\n        convex_hull.push_back(i);\n\
    \      }\n    }\n\n    for (const ::std::size_t& c : convex_hull) {\n      for\
    \ (const ::std::size_t& i : duplicates[c]) {\n        if constexpr (::std::is_assignable_v<OutputIterator,\
    \ ::std::size_t>) {\n          *result = i;\n        } else {\n          *result\
    \ = v[i];\n        }\n        ++result;\n      }\n    }\n  }\n}\n\n\n"
  code: "#ifndef TOOLS_CONVEX_HULL_HPP\n#define TOOLS_CONVEX_HULL_HPP\n\n#include\
    \ <type_traits>\n#include <vector>\n#include <cstddef>\n#include <numeric>\n#include\
    \ <algorithm>\n#include <utility>\n#include <iterator>\n#include <stack>\n#include\
    \ \"tools/vector2.hpp\"\n#include \"tools/less_by.hpp\"\n#include \"tools/ccw.hpp\"\
    \n\nnamespace tools {\n  template <typename InputIterator, typename OutputIterator>\n\
    \  void convex_hull(const InputIterator begin, const InputIterator end, bool minimum,\
    \ OutputIterator result) {\n    using T = ::std::decay_t<decltype(begin->x)>;\n\
    \n    const ::std::vector<::tools::vector2<T>> v(begin, end);\n    ::std::vector<::std::size_t>\
    \ a(v.size());\n    ::std::iota(a.begin(), a.end(), 0);\n    ::std::sort(a.begin(),\
    \ a.end(), ::tools::less_by([&](const T& i) {\n      return ::std::make_pair(v[i].x,\
    \ v[i].y);\n    }));\n    ::std::vector<::std::vector<::std::size_t>> duplicates;\n\
    \n    if (minimum) {\n      ::std::size_t vl = 0;\n      for (::std::size_t vr\
    \ = 0, al = 0, ar = 0; al < a.size(); vl = vr, al = ar) {\n        for (; ar <\
    \ a.size() && v[a[al]].x == v[a[ar]].x; ::std::swap(a[vr], a[ar]), ++vr, ++ar);\n\
    \        if (v[a[vl]].y == v[a[vr - 1]].y) {\n          vr -= vr - vl - 1;\n \
    \         duplicates.emplace_back();\n          duplicates.back().push_back(a[vl]);\n\
    \        } else {\n          ::std::swap(a[vl + 1], a[vr - 1]);\n          vr\
    \ -= vr - vl - 2;\n          duplicates.emplace_back();\n          duplicates.back().push_back(a[vl]);\n\
    \          duplicates.emplace_back();\n          duplicates.back().push_back(a[vl\
    \ + 1]);\n        }\n      }\n      a.erase(::std::next(a.begin(), vl), a.end());\n\
    \    } else {\n      ::std::size_t vl = 0;\n      for (::std::size_t vr = 0, al\
    \ = 0, ar = 0; al < a.size(); vl = vr, al = ar) {\n        for (; ar < a.size()\
    \ && v[a[al]] == v[a[ar]]; ::std::swap(a[vr], a[ar]), ++vr, ++ar);\n        duplicates.emplace_back();\n\
    \        for (::std::size_t i = vl; i < vr; ++i) {\n          duplicates.back().push_back(a[i]);\n\
    \        }\n        vr -= vr - vl - 1;\n      }\n      a.erase(::std::next(a.begin(),\
    \ vl), a.end());\n    }\n\n    ::std::vector<::std::size_t> convex_hull;\n   \
    \ if (a.size() >= 3) {\n\n      convex_hull.push_back(0);\n      convex_hull.push_back(1);\n\
    \      for (::std::size_t p3 = 2; p3 < a.size(); ++p3) {\n        while (convex_hull.size()\
    \ >= 2) {\n          const int ccw = ::tools::ccw(v[a[convex_hull.rbegin()[1]]],\
    \ v[a[convex_hull.back()]], v[a[p3]]);\n          if (ccw == 1 || (!minimum &&\
    \ ccw == -2)) {\n            break;\n          }\n          convex_hull.pop_back();\n\
    \        }\n        convex_hull.push_back(p3);\n      }\n\n      const ::std::size_t\
    \ threshold = convex_hull.size() + 1;\n      for (::std::size_t p3 = convex_hull.back();\
    \ p3 --> 0;) {\n        while (convex_hull.size() >= threshold) {\n          const\
    \ int ccw = ::tools::ccw(v[a[convex_hull.rbegin()[1]]], v[a[convex_hull.back()]],\
    \ v[a[p3]]);\n          if (ccw == 1 || (!minimum && ccw == -2)) {\n         \
    \   break;\n          }\n          convex_hull.pop_back();\n        }\n      \
    \  convex_hull.push_back(p3);\n      }\n      convex_hull.pop_back();\n\n    }\
    \ else {\n      for (::std::size_t i = 0; i < a.size(); ++i) {\n        convex_hull.push_back(i);\n\
    \      }\n    }\n\n    for (const ::std::size_t& c : convex_hull) {\n      for\
    \ (const ::std::size_t& i : duplicates[c]) {\n        if constexpr (::std::is_assignable_v<OutputIterator,\
    \ ::std::size_t>) {\n          *result = i;\n        } else {\n          *result\
    \ = v[i];\n        }\n        ++result;\n      }\n    }\n  }\n}\n\n#endif\n"
  dependsOn:
  - tools/vector2.hpp
  - tools/abs.hpp
  - tools/pair_hash.hpp
  - tools/less_by.hpp
  - tools/ccw.hpp
  isVerificationFile: false
  path: tools/convex_hull.hpp
  requiredBy: []
  timestamp: '2022-08-28 15:47:23+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - tests/convex_hull.test.cpp
  - tests/polygon_2d/minimum_bounding_circle.test.cpp
documentation_of: tools/convex_hull.hpp
layout: document
title: Convex hull
---

```cpp
template <typename InputIterator, typename OutputIterator>
void convex_hull(InputIterator begin, InputIterator end, bool minimum, OutputIterator result);
```

It stores the indices of vertices or the vertices themselves which are on the edge of the convex hull of a given polygon to `result`.
If `minimum` is `true`, only the minimal vertices required for the convex hull will be stored.
On the other hand, if `minimum` is `false`, all the vertices on the edge of the convex hull will be stored.

The vertices will be stored counterclockwisely.
The first sroted vertex will be the leftmost vertex.
If the number of the leftmost vertices is more than one, the first stored vertex will be the lowermost vertex in them.

## Constraints
- `begin` $\leq$ `end`
- The type of `*begin` is `tools::vector2<T>`.
- Either `std::size_t` or `tools::vector2<T>` is assignable to `*result`.

## Time Complexity
- $O(n \log n)$ where $n$ is `end` - `begin`

## License
- CC0

## Author
- anqooqie
