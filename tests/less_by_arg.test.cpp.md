---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/ccw.hpp
    title: Counter clockwise function
  - icon: ':heavy_check_mark:'
    path: tools/less_by_arg.hpp
    title: std::less by the argument
  - icon: ':heavy_check_mark:'
    path: tools/pair_hash.hpp
    title: Hash of std::pair
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
    PROBLEM: https://judge.yosupo.jp/problem/sort_points_by_argument
    links:
    - https://judge.yosupo.jp/problem/sort_points_by_argument
  bundledCode: "#line 1 \"tests/less_by_arg.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/sort_points_by_argument\"\
    \n\n#include <cstdint>\n#include <iostream>\n#line 1 \"tools/vector2.hpp\"\n\n\
    \n\n#include <cmath>\n#include <type_traits>\n#include <cstddef>\n#include <array>\n\
    #include <string>\n#include <functional>\n#include <limits>\n#line 1 \"tools/pair_hash.hpp\"\
    \n\n\n\n#line 5 \"tools/pair_hash.hpp\"\n#include <utility>\n#include <random>\n\
    #line 9 \"tools/pair_hash.hpp\"\n\nnamespace tools {\n\n  template <class T1,\
    \ class T2>\n  struct pair_hash {\n    using result_type = ::std::size_t;\n  \
    \  using argument_type = ::std::pair<T1, T2>;\n    ::std::size_t operator()(const\
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
    \ key.second));\n    }\n  };\n}\n\n\n#line 13 \"tools/vector2.hpp\"\n\nnamespace\
    \ tools {\n\n  template <typename T>\n  class vector2 {\n  public:\n    T x;\n\
    \    T y;\n\n    vector2() :\n      vector2(T(), T()) {\n    }\n\n    vector2(const\
    \ T& x, const T& y) :\n      x(x),\n      y(y) {\n    }\n\n    double norm() const\
    \ {\n      return ::std::sqrt(static_cast<double>(this->squared_norm()));\n  \
    \  }\n\n    T squared_norm() const {\n      return this->inner_product(*this);\n\
    \    }\n\n    template <typename SFINAE_T = T, typename ::std::enable_if<::std::is_same<SFINAE_T,\
    \ double>::value, ::std::nullptr_t>::type = nullptr>\n    ::tools::vector2<double>\
    \ normalized() const {\n      return *this / this->norm();\n    }\n\n    ::tools::vector2<T>\
    \ operator+() const {\n      return *this;\n    }\n\n    ::tools::vector2<T> operator-()\
    \ const {\n      return ::tools::vector2<T>(-this->x, -this->y);\n    }\n\n  \
    \  friend ::tools::vector2<T> operator+(const ::tools::vector2<T>& lhs, const\
    \ ::tools::vector2<T>& rhs) {\n      return ::tools::vector2<T>(lhs.x + rhs.x,\
    \ lhs.y + rhs.y);\n    }\n\n    friend ::tools::vector2<T> operator-(const ::tools::vector2<T>&\
    \ lhs, const ::tools::vector2<T>& rhs) {\n      return ::tools::vector2<T>(lhs.x\
    \ - rhs.x, lhs.y - rhs.y);\n    }\n\n    template <typename OTHER, typename ::std::enable_if<!::std::is_same<OTHER,\
    \ ::tools::vector2<T>>::value, ::std::nullptr_t>::type = nullptr>\n    friend\
    \ ::tools::vector2<T> operator*(const ::tools::vector2<T>& lhs, const OTHER& rhs)\
    \ {\n      return ::tools::vector2<T>(lhs.x * rhs, lhs.y * rhs);\n    }\n    template\
    \ <typename OTHER, typename ::std::enable_if<!::std::is_same<OTHER, ::tools::vector2<T>>::value,\
    \ ::std::nullptr_t>::type = nullptr>\n    friend ::tools::vector2<T> operator*(const\
    \ OTHER& lhs, const ::tools::vector2<T>& rhs) {\n      return ::tools::vector2<T>(lhs\
    \ * rhs.x, lhs * rhs.y);\n    }\n\n    template <typename OTHER, typename ::std::enable_if<!::std::is_same<OTHER,\
    \ ::tools::vector2<T>>::value, ::std::nullptr_t>::type = nullptr>\n    friend\
    \ ::tools::vector2<T> operator/(const ::tools::vector2<T>& lhs, const OTHER& rhs)\
    \ {\n      return ::tools::vector2<T>(lhs.x / rhs, lhs.y / rhs);\n    }\n\n  \
    \  T inner_product(const ::tools::vector2<T>& other) const {\n      return this->x\
    \ * other.x + this->y * other.y;\n    }\n\n    T outer_product(const ::tools::vector2<T>&\
    \ other) const {\n      return this->x * other.y - this->y * other.x;\n    }\n\
    \n    ::tools::vector2<T>& operator+=(const ::tools::vector2<T>& other) {\n  \
    \    return *this = *this + other;\n    }\n\n    ::tools::vector2<T>& operator-=(const\
    \ ::tools::vector2<T>& other) {\n      return *this = *this - other;\n    }\n\n\
    \    template <typename OTHER, typename ::std::enable_if<!::std::is_same<OTHER,\
    \ ::tools::vector2<T>>::value, ::std::nullptr_t>::type = nullptr>\n    ::tools::vector2<T>&\
    \ operator*=(const OTHER& other) {\n      return *this = *this * other;\n    }\n\
    \n    template <typename OTHER, typename ::std::enable_if<!::std::is_same<OTHER,\
    \ ::tools::vector2<T>>::value, ::std::nullptr_t>::type = nullptr>\n    ::tools::vector2<T>&\
    \ operator/=(const OTHER& other) {\n      return *this = *this / other;\n    }\n\
    \n    friend bool operator==(const ::tools::vector2<T>& lhs, const ::tools::vector2<T>&\
    \ rhs) {\n      return lhs.x == rhs.x && lhs.y == rhs.y;\n    }\n\n    friend\
    \ bool operator!=(const ::tools::vector2<T>& lhs, const ::tools::vector2<T>& rhs)\
    \ {\n      return lhs.x != rhs.x || lhs.y != rhs.y;\n    }\n\n    static ::std::array<::tools::vector2<T>,\
    \ 4> four_directions() {\n      return ::std::array<::tools::vector2<T>, 4>({\n\
    \        ::tools::vector2<T>(static_cast<T>(-1), static_cast<T>(0)),\n       \
    \ ::tools::vector2<T>(static_cast<T>(1), static_cast<T>(0)),\n        ::tools::vector2<T>(static_cast<T>(0),\
    \ static_cast<T>(-1)),\n        ::tools::vector2<T>(static_cast<T>(0), static_cast<T>(1))\n\
    \      });\n    }\n\n    static ::std::array<::tools::vector2<T>, 8> eight_directions()\
    \ {\n      return ::std::array<::tools::vector2<T>, 8>({\n        ::tools::vector2<T>(static_cast<T>(-1),\
    \ static_cast<T>(-1)),\n        ::tools::vector2<T>(static_cast<T>(-1), static_cast<T>(0)),\n\
    \        ::tools::vector2<T>(static_cast<T>(-1), static_cast<T>(1)),\n       \
    \ ::tools::vector2<T>(static_cast<T>(0), static_cast<T>(-1)),\n        ::tools::vector2<T>(static_cast<T>(0),\
    \ static_cast<T>(1)),\n        ::tools::vector2<T>(static_cast<T>(0), static_cast<T>(-1)),\n\
    \        ::tools::vector2<T>(static_cast<T>(1), static_cast<T>(-1)),\n       \
    \ ::tools::vector2<T>(static_cast<T>(1), static_cast<T>(0)),\n        ::tools::vector2<T>(static_cast<T>(1),\
    \ static_cast<T>(1))\n      });\n    }\n  };\n}\n\nnamespace std {\n  template\
    \ <typename T>\n  ::std::string to_string(const ::tools::vector2<T>& f) {\n  \
    \  return '(' + ::std::to_string(f.x) + \", \" + ::std::to_string(f.y) + ')';\n\
    \  }\n\n  template <typename T>\n  struct hash<::tools::vector2<T>> {\n    using\
    \ result_type = ::std::size_t;\n    using argument_type = ::tools::vector2<T>;\n\
    \    ::std::size_t operator()(const ::tools::vector2<T>& key) const {\n      static\
    \ const ::tools::pair_hash<T, T> hasher = ::tools::pair_hash<T, T>();\n      return\
    \ hasher(key.x, key.y);\n    }\n  };\n\n  template <typename T>\n  ::std::ostream&\
    \ operator<<(::std::ostream& os, const ::tools::vector2<T>& self) {\n    return\
    \ os << ::std::to_string(self);\n  }\n\n  template <typename T>\n  ::std::istream&\
    \ operator>>(::std::istream& is, ::tools::vector2<T>& self) {\n    return is >>\
    \ self.x >> self.y;\n  }\n}\n\n\n#line 1 \"tools/less_by_arg.hpp\"\n\n\n\n#include\
    \ <cassert>\n#line 1 \"tools/ccw.hpp\"\n\n\n\n#line 5 \"tools/ccw.hpp\"\n\nnamespace\
    \ tools {\n  template <typename T>\n  ::std::int_fast64_t ccw(const ::tools::vector2<T>&\
    \ a, ::tools::vector2<T> b, ::tools::vector2<T> c) {\n    b -= a;\n    c -= a;\n\
    \    if (b.outer_product(c) > 0) return +1;\n    if (b.outer_product(c) < 0) return\
    \ -1;\n    if (b.inner_product(c) < 0) return +2;\n    if (b.squared_norm() <\
    \ c.squared_norm()) return -2;\n    return 0;\n  }\n}\n\n\n#line 7 \"tools/less_by_arg.hpp\"\
    \n\nnamespace tools {\n\n  template <bool DEFAULT, typename T>\n  class less_by_arg\
    \ {\n  private:\n    ::tools::vector2<T> d;\n\n    template <typename U>\n   \
    \ int where(const ::tools::vector2<U>& p) const {\n      if constexpr (DEFAULT)\
    \ {\n        return p.y > 0 || (p.y == 0 && p.x >= 0) ? 0 : 1;\n      } else {\n\
    \        if (this->d.x == 0 && this->d.y == 0) {\n          return p.y > 0 ||\
    \ (p.y == 0 && p.x >= 0) ? 0 : 1;\n        } else {\n          if (p.x == 0 &&\
    \ p.y == 0) {\n            const int ccw = ::tools::ccw(::tools::vector2<U>(0,\
    \ 0), this->d, ::tools::vector2<U>(1, 0));\n            if (ccw == +1) return\
    \ 2;\n            if (ccw == +2) return 4;\n            if (ccw == -1) return\
    \ 7;\n            return 9;\n          } else {\n            if (this->d == p)\
    \ return 0;\n            const int ccw = ::tools::ccw(::tools::vector2<U>(0, 0),\
    \ this->d, p);\n            if (ccw == -2) return 0;\n            if (ccw == +1)\
    \ {\n              const int ccw2 = ::tools::ccw(::tools::vector2<U>(0, 0), this->d,\
    \ ::tools::vector2<U>(1, 0));\n              if (ccw2 != +1) return 1;\n     \
    \         const int ccw3 = ::tools::ccw(::tools::vector2<U>(0, 0), ::tools::vector2<U>(1,\
    \ 0), p);\n              if (ccw3 == -1) return 1;\n              return 3;\n\
    \            }\n            if (ccw == +2) return 5;\n            if (ccw == -1)\
    \ {\n              const int ccw2 = ::tools::ccw(::tools::vector2<U>(0, 0), this->d,\
    \ ::tools::vector2<U>(1, 0));\n              if (ccw2 != -1) return 6;\n     \
    \         const int ccw3 = ::tools::ccw(::tools::vector2<U>(0, 0), ::tools::vector2<U>(1,\
    \ 0), p);\n              if (ccw3 == -1) return 6;\n              return 8;\n\
    \            }\n            return 9;\n          }\n        }\n      }\n    }\n\
    \n  public:\n    less_by_arg() = default;\n\n    template <typename U>\n    explicit\
    \ less_by_arg(const ::tools::vector2<U>& d) : d(d) {\n    }\n\n    template <typename\
    \ U>\n    bool operator()(const ::tools::vector2<U>& a, const ::tools::vector2<U>&\
    \ b) const {\n      const int wa = this->where(a);\n      const int wb = this->where(b);\n\
    \      return wa == wb ? a.outer_product(b) > 0 || (a.outer_product(b) == 0 &&\
    \ a.squared_norm() < b.squared_norm()) : wa < wb;\n    }\n  };\n\n  less_by_arg()\
    \ -> less_by_arg<true, int>;\n\n  template <typename U>\n  less_by_arg(const ::tools::vector2<U>&)\
    \ -> less_by_arg<false, U>;\n}\n\n\n#line 7 \"tests/less_by_arg.test.cpp\"\n\n\
    using i64 = std::int_fast64_t;\n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  i64 N;\n  std::cin >> N;\n  std::vector<tools::vector2<i64>> p(N);\n  for\
    \ (auto& p_i : p) std::cin >> p_i;\n\n  std::sort(p.begin(), p.end(), tools::less_by_arg(tools::vector2<i64>(-1000000001,\
    \ -1)));\n\n  for (const auto& p_i : p) {\n    std::cout << p_i.x << ' ' << p_i.y\
    \ << '\\n';\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/sort_points_by_argument\"\
    \n\n#include <cstdint>\n#include <iostream>\n#include \"tools/vector2.hpp\"\n\
    #include \"tools/less_by_arg.hpp\"\n\nusing i64 = std::int_fast64_t;\n\nint main()\
    \ {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\n  i64\
    \ N;\n  std::cin >> N;\n  std::vector<tools::vector2<i64>> p(N);\n  for (auto&\
    \ p_i : p) std::cin >> p_i;\n\n  std::sort(p.begin(), p.end(), tools::less_by_arg(tools::vector2<i64>(-1000000001,\
    \ -1)));\n\n  for (const auto& p_i : p) {\n    std::cout << p_i.x << ' ' << p_i.y\
    \ << '\\n';\n  }\n}\n"
  dependsOn:
  - tools/vector2.hpp
  - tools/pair_hash.hpp
  - tools/less_by_arg.hpp
  - tools/ccw.hpp
  isVerificationFile: true
  path: tests/less_by_arg.test.cpp
  requiredBy: []
  timestamp: '2021-07-25 10:07:08+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/less_by_arg.test.cpp
layout: document
redirect_from:
- /verify/tests/less_by_arg.test.cpp
- /verify/tests/less_by_arg.test.cpp.html
title: tests/less_by_arg.test.cpp
---
