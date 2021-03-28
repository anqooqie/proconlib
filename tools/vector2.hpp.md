---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: tools/pair_hash.hpp
    title: tools/pair_hash.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/vector2.hpp\"\n\n\n\n#include <cmath>\n#include <type_traits>\n\
    #include <cstddef>\n#include <array>\n#include <string>\n#include <functional>\n\
    #include <limits>\n#include <iostream>\n#line 1 \"tools/pair_hash.hpp\"\n\n\n\n\
    #line 5 \"tools/pair_hash.hpp\"\n#include <utility>\n#include <random>\n#line\
    \ 8 \"tools/pair_hash.hpp\"\n#include <cstdint>\n\nnamespace tools {\n\n  /**\n\
    \   * hash of `std::pair<T1, T2>`\n   * License: Boost Software License, Version\
    \ 1.0 ( http://www.boost.org/LICENSE_1_0.txt )\n   * Reference: Boost, Version\
    \ 1.71.0 ( https://github.com/boostorg/container_hash/blob/boost-1.71.0/include/boost/container_hash/hash.hpp\
    \ )\n   * @author Daniel James\n   * @param <T1> first type of `key`\n   * @param\
    \ <T2> second type of `key`\n   * @param key value of `std::pair<T1, T2>`\n  \
    \ * @return hash of `key`\n   */\n  template <class T1, class T2>\n  struct pair_hash\
    \ {\n    using result_type = ::std::size_t;\n    using argument_type = ::std::pair<T1,\
    \ T2>;\n    ::std::size_t operator()(const ::std::pair<T1, T2>& key) const {\n\
    \      static const ::std::size_t salt = ::std::random_device()();\n      static\
    \ const ::std::hash<T1> hasher1 = ::std::hash<T1>();\n      static const ::std::hash<T2>\
    \ hasher2 = ::std::hash<T2>();\n      static const ::std::hash<::std::size_t>\
    \ hasher3 = ::std::hash<::std::size_t>();\n      ::std::size_t result = 0;\n \
    \     result ^= hasher1(key.first) + static_cast<::std::size_t>(0x9e3779b9) +\
    \ (result << static_cast<::std::size_t>(6)) + (result >> static_cast<::std::size_t>(2));\n\
    \      result ^= hasher2(key.second) + static_cast<::std::size_t>(0x9e3779b9)\
    \ + (result << static_cast<::std::size_t>(6)) + (result >> static_cast<::std::size_t>(2));\n\
    \      result ^= hasher3(salt) + static_cast<::std::size_t>(0x9e3779b9) + (result\
    \ << static_cast<::std::size_t>(6)) + (result >> static_cast<::std::size_t>(2));\n\
    \      return result;\n    }\n  };\n\n  /**\n   * hash of `std::pair<std::uint64_t,\
    \ std::uint64_t>`\n   * License: CC0\n   *\n   * Usage:\n   * ```\n   * using\
    \ u64 = std::uint64_t;\n   * std::unordered_map<std::pair<u64, u64>, int, tools::pair_hash<u64,\
    \ u64>> map;\n   * ```\n   *\n   * @author anqooqie\n   * @param value of `std::pair<std::uint64_t,\
    \ std::uint64_t>`\n   * @return hash of `key`\n   */\n  template <>\n  struct\
    \ pair_hash<::std::uint64_t, ::std::uint64_t> {\n    using result_type = ::std::size_t;\n\
    \    using argument_type = ::std::pair<::std::uint64_t, ::std::uint64_t>;\n  \
    \  ::std::size_t operator()(const ::std::pair<::std::uint64_t, ::std::uint64_t>&\
    \ key) const {\n      static const ::std::hash<::std::uint64_t> hasher = ::std::hash<::std::uint64_t>();\n\
    \      return hasher(((key.first << static_cast<::std::uint64_t>(32)) | (key.first\
    \ >> static_cast<::std::uint64_t>(32))) ^ key.second);\n    }\n  };\n\n  /**\n\
    \   * hash of `std::pair<std::int64_t, std::int64_t>`\n   * License: CC0\n   *\n\
    \   * Usage:\n   * ```\n   * using i64 = std::int64_t;\n   * std::unordered_map<std::pair<i64,\
    \ i64>, int, tools::pair_hash<i64, i64>> map;\n   * ```\n   *\n   * @author anqooqie\n\
    \   * @param value of `std::pair<std::int64_t, std::int64_t>`\n   * @return hash\
    \ of `key`\n   */\n  template <>\n  struct pair_hash<::std::int64_t, ::std::int64_t>\
    \ {\n    using result_type = ::std::size_t;\n    using argument_type = ::std::pair<::std::int64_t,\
    \ ::std::int64_t>;\n    ::std::size_t operator()(const ::std::pair<::std::int64_t,\
    \ ::std::int64_t>& key) const {\n      static const ::tools::pair_hash<::std::uint64_t,\
    \ ::std::uint64_t> hasher = ::tools::pair_hash<::std::uint64_t, ::std::uint64_t>();\n\
    \      return hasher(::std::make_pair<::std::uint64_t, ::std::uint64_t>(key.first,\
    \ key.second));\n    }\n  };\n\n  /**\n   * hash of `std::pair<std::uint32_t,\
    \ std::uint32_t>`\n   * License: CC0\n   *\n   * Usage:\n   * ```\n   * using\
    \ u32 = std::uint32_t;\n   * std::unordered_map<std::pair<u32, u32>, int, tools::pair_hash<u32,\
    \ u32>> map;\n   * ```\n   *\n   * @author anqooqie\n   * @param value of `std::pair<std::uint32_t,\
    \ std::uint32_t>`\n   * @return hash of `key`\n   */\n  template <>\n  struct\
    \ pair_hash<::std::uint32_t, ::std::uint32_t> {\n    using result_type = ::std::size_t;\n\
    \    using argument_type = ::std::pair<::std::uint32_t, ::std::uint32_t>;\n  \
    \  ::std::size_t operator()(const ::std::pair<::std::uint32_t, ::std::uint32_t>&\
    \ key) const {\n      static const ::std::hash<::std::uint64_t> hasher = ::std::hash<::std::uint64_t>();\n\
    \      return hasher((static_cast<::std::uint64_t>(key.first) << static_cast<::std::uint64_t>(32))\
    \ | static_cast<::std::uint64_t>(key.second));\n    }\n  };\n\n  /**\n   * hash\
    \ of `std::pair<std::int32_t, std::int32_t>`\n   * License: CC0\n   *\n   * Usage:\n\
    \   * ```\n   * using i32 = std::int32_t;\n   * std::unordered_map<std::pair<i32,\
    \ i32>, int, tools::pair_hash<i32, i32>> map;\n   * ```\n   *\n   * @author anqooqie\n\
    \   * @param value of `std::pair<std::int32_t, std::int32_t>`\n   * @return hash\
    \ of `key`\n   */\n  template <>\n  struct pair_hash<::std::int32_t, ::std::int32_t>\
    \ {\n    using result_type = ::std::size_t;\n    using argument_type = ::std::pair<::std::int32_t,\
    \ ::std::int32_t>;\n    ::std::size_t operator()(const ::std::pair<::std::int32_t,\
    \ ::std::int32_t>& key) const {\n      static const ::tools::pair_hash<::std::uint32_t,\
    \ ::std::uint32_t> hasher = ::tools::pair_hash<::std::uint32_t, ::std::uint32_t>();\n\
    \      return hasher(::std::make_pair<::std::uint32_t, ::std::uint32_t>(key.first,\
    \ key.second));\n    }\n  };\n}\n\n\n#line 13 \"tools/vector2.hpp\"\n\nnamespace\
    \ tools {\n\n  /**\n   * 2D vector\n   * License: CC0\n   *\n   * Usage:\n   *\
    \ ```\n   * tools::vector2<int>(6, 5) //=> (6, 5)\n   * ```\n   *\n   * @author\
    \ anqooqie\n   * @param <T> type of scalar\n   */\n  template <typename T>\n \
    \ class vector2 {\n  public:\n    T x;\n    T y;\n\n    vector2() :\n      vector2(T(),\
    \ T()) {\n    }\n\n    vector2(const T& x, const T& y) :\n      x(x),\n      y(y)\
    \ {\n    }\n\n    double norm() const {\n      return ::std::sqrt(this->squaredNorm());\n\
    \    }\n\n    T squaredNorm() const {\n      return this->inner_product(*this);\n\
    \    }\n\n    template <typename SFINAE_T = T, typename ::std::enable_if<::std::is_same<SFINAE_T,\
    \ double>::value, ::std::nullptr_t>::type = nullptr>\n    double normalize() const\
    \ {\n      return *this / this->norm();\n    }\n\n    ::tools::vector2<T> operator+()\
    \ const {\n      return *this;\n    }\n\n    ::tools::vector2<T> operator-() const\
    \ {\n      return ::tools::vector2<T>(-this->x, -this->y);\n    }\n\n    friend\
    \ ::tools::vector2<T> operator+(const ::tools::vector2<T>& lhs, const ::tools::vector2<T>&\
    \ rhs) {\n      return ::tools::vector2<T>(lhs.x + rhs.x, lhs.y + rhs.y);\n  \
    \  }\n\n    friend ::tools::vector2<T> operator-(const ::tools::vector2<T>& lhs,\
    \ const ::tools::vector2<T>& rhs) {\n      return ::tools::vector2<T>(lhs.x -\
    \ rhs.x, lhs.y - rhs.y);\n    }\n\n    template <typename OTHER, typename ::std::enable_if<!::std::is_same<OTHER,\
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
    \ * other.x + this->y * other.y;\n    }\n\n    ::tools::vector2<T>& operator+=(const\
    \ ::tools::vector2<T>& other) {\n      return *this = *this + other;\n    }\n\n\
    \    ::tools::vector2<T>& operator-=(const ::tools::vector2<T>& other) {\n   \
    \   return *this = *this - other;\n    }\n\n    template <typename OTHER, typename\
    \ ::std::enable_if<!::std::is_same<OTHER, ::tools::vector2<T>>::value, ::std::nullptr_t>::type\
    \ = nullptr>\n    ::tools::vector2<T>& operator*=(const OTHER& other) {\n    \
    \  return *this = *this * other;\n    }\n\n    template <typename OTHER, typename\
    \ ::std::enable_if<!::std::is_same<OTHER, ::tools::vector2<T>>::value, ::std::nullptr_t>::type\
    \ = nullptr>\n    ::tools::vector2<T>& operator/=(const OTHER& other) {\n    \
    \  return *this = *this / other;\n    }\n\n    friend bool operator==(const ::tools::vector2<T>&\
    \ lhs, const ::tools::vector2<T>& rhs) {\n      return lhs.x == rhs.x && lhs.y\
    \ == rhs.y;\n    }\n\n    friend bool operator!=(const ::tools::vector2<T>& lhs,\
    \ const ::tools::vector2<T>& rhs) {\n      return lhs.x != rhs.x || lhs.y != rhs.y;\n\
    \    }\n\n    static ::std::array<::tools::vector2<T>, 4> four_directions() {\n\
    \      return ::std::array<::tools::vector2<T>, 4>({\n        ::tools::vector2<T>(static_cast<T>(-1),\
    \ static_cast<T>(0)),\n        ::tools::vector2<T>(static_cast<T>(1), static_cast<T>(0)),\n\
    \        ::tools::vector2<T>(static_cast<T>(0), static_cast<T>(-1)),\n       \
    \ ::tools::vector2<T>(static_cast<T>(0), static_cast<T>(1))\n      });\n    }\n\
    \n    static ::std::array<::tools::vector2<T>, 8> eight_directions() {\n     \
    \ return ::std::array<::tools::vector2<T>, 8>({\n        ::tools::vector2<T>(static_cast<T>(-1),\
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
    \ self.x >> self.y;\n  }\n}\n\n\n"
  code: "#ifndef TOOLS_VECTOR2_HPP\n#define TOOLS_VECTOR2_HPP\n\n#include <cmath>\n\
    #include <type_traits>\n#include <cstddef>\n#include <array>\n#include <string>\n\
    #include <functional>\n#include <limits>\n#include <iostream>\n#include \"tools/pair_hash.hpp\"\
    \n\nnamespace tools {\n\n  /**\n   * 2D vector\n   * License: CC0\n   *\n   *\
    \ Usage:\n   * ```\n   * tools::vector2<int>(6, 5) //=> (6, 5)\n   * ```\n   *\n\
    \   * @author anqooqie\n   * @param <T> type of scalar\n   */\n  template <typename\
    \ T>\n  class vector2 {\n  public:\n    T x;\n    T y;\n\n    vector2() :\n  \
    \    vector2(T(), T()) {\n    }\n\n    vector2(const T& x, const T& y) :\n   \
    \   x(x),\n      y(y) {\n    }\n\n    double norm() const {\n      return ::std::sqrt(this->squaredNorm());\n\
    \    }\n\n    T squaredNorm() const {\n      return this->inner_product(*this);\n\
    \    }\n\n    template <typename SFINAE_T = T, typename ::std::enable_if<::std::is_same<SFINAE_T,\
    \ double>::value, ::std::nullptr_t>::type = nullptr>\n    double normalize() const\
    \ {\n      return *this / this->norm();\n    }\n\n    ::tools::vector2<T> operator+()\
    \ const {\n      return *this;\n    }\n\n    ::tools::vector2<T> operator-() const\
    \ {\n      return ::tools::vector2<T>(-this->x, -this->y);\n    }\n\n    friend\
    \ ::tools::vector2<T> operator+(const ::tools::vector2<T>& lhs, const ::tools::vector2<T>&\
    \ rhs) {\n      return ::tools::vector2<T>(lhs.x + rhs.x, lhs.y + rhs.y);\n  \
    \  }\n\n    friend ::tools::vector2<T> operator-(const ::tools::vector2<T>& lhs,\
    \ const ::tools::vector2<T>& rhs) {\n      return ::tools::vector2<T>(lhs.x -\
    \ rhs.x, lhs.y - rhs.y);\n    }\n\n    template <typename OTHER, typename ::std::enable_if<!::std::is_same<OTHER,\
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
    \ * other.x + this->y * other.y;\n    }\n\n    ::tools::vector2<T>& operator+=(const\
    \ ::tools::vector2<T>& other) {\n      return *this = *this + other;\n    }\n\n\
    \    ::tools::vector2<T>& operator-=(const ::tools::vector2<T>& other) {\n   \
    \   return *this = *this - other;\n    }\n\n    template <typename OTHER, typename\
    \ ::std::enable_if<!::std::is_same<OTHER, ::tools::vector2<T>>::value, ::std::nullptr_t>::type\
    \ = nullptr>\n    ::tools::vector2<T>& operator*=(const OTHER& other) {\n    \
    \  return *this = *this * other;\n    }\n\n    template <typename OTHER, typename\
    \ ::std::enable_if<!::std::is_same<OTHER, ::tools::vector2<T>>::value, ::std::nullptr_t>::type\
    \ = nullptr>\n    ::tools::vector2<T>& operator/=(const OTHER& other) {\n    \
    \  return *this = *this / other;\n    }\n\n    friend bool operator==(const ::tools::vector2<T>&\
    \ lhs, const ::tools::vector2<T>& rhs) {\n      return lhs.x == rhs.x && lhs.y\
    \ == rhs.y;\n    }\n\n    friend bool operator!=(const ::tools::vector2<T>& lhs,\
    \ const ::tools::vector2<T>& rhs) {\n      return lhs.x != rhs.x || lhs.y != rhs.y;\n\
    \    }\n\n    static ::std::array<::tools::vector2<T>, 4> four_directions() {\n\
    \      return ::std::array<::tools::vector2<T>, 4>({\n        ::tools::vector2<T>(static_cast<T>(-1),\
    \ static_cast<T>(0)),\n        ::tools::vector2<T>(static_cast<T>(1), static_cast<T>(0)),\n\
    \        ::tools::vector2<T>(static_cast<T>(0), static_cast<T>(-1)),\n       \
    \ ::tools::vector2<T>(static_cast<T>(0), static_cast<T>(1))\n      });\n    }\n\
    \n    static ::std::array<::tools::vector2<T>, 8> eight_directions() {\n     \
    \ return ::std::array<::tools::vector2<T>, 8>({\n        ::tools::vector2<T>(static_cast<T>(-1),\
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
    \ self.x >> self.y;\n  }\n}\n\n#endif\n"
  dependsOn:
  - tools/pair_hash.hpp
  isVerificationFile: false
  path: tools/vector2.hpp
  requiredBy: []
  timestamp: '2021-02-14 17:58:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tools/vector2.hpp
layout: document
redirect_from:
- /library/tools/vector2.hpp
- /library/tools/vector2.hpp.html
title: tools/vector2.hpp
---
