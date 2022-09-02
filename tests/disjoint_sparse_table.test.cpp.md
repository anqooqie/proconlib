---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: tools/ceil_log2.hpp
    title: $\left\lceil \log_2(x) \right\rceil$
  - icon: ':heavy_check_mark:'
    path: tools/disjoint_sparse_table.hpp
    title: Disjoint sparse table
  - icon: ':heavy_check_mark:'
    path: tools/floor_log2.hpp
    title: $\left\lfloor \log_2(x) \right\rfloor$
  - icon: ':heavy_check_mark:'
    path: tools/monoid.hpp
    title: Typical monoids
  - icon: ':heavy_check_mark:'
    path: tools/popcount.hpp
    title: Popcount
  - icon: ':question:'
    path: tools/pow2.hpp
    title: $2^x$
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    links:
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "#line 1 \"tests/disjoint_sparse_table.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/staticrmq\"\n\n#include <cstdint>\n#include\
    \ <iostream>\n#line 1 \"tools/monoid.hpp\"\n\n\n\n#include <algorithm>\n#include\
    \ <limits>\n#include <numeric>\n\nnamespace tools {\n  namespace monoid {\n  \
    \  template <typename Type, Type E = ::std::numeric_limits<Type>::min()>\n   \
    \ struct max {\n      using T = Type;\n      static T op(const T lhs, const T\
    \ rhs) {\n        return ::std::max(lhs, rhs);\n      }\n      static T e() {\n\
    \        return E;\n      }\n    };\n\n    template <typename Type, Type E = ::std::numeric_limits<Type>::max()>\n\
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
    \ E;\n      }\n    };\n  }\n}\n\n\n#line 1 \"tools/disjoint_sparse_table.hpp\"\
    \n\n\n\n#include <vector>\n#include <cstddef>\n#line 7 \"tools/disjoint_sparse_table.hpp\"\
    \n#include <iterator>\n#include <cassert>\n#line 1 \"tools/ceil_log2.hpp\"\n\n\
    \n\n#line 5 \"tools/ceil_log2.hpp\"\n\n// Source: https://stackoverflow.com/questions/3272424/compute-fast-log-base-2-ceiling/15327567#15327567\n\
    // License: CC BY-SA 3.0\n// Author: dgobbi\n\nnamespace tools {\n\n  inline std::uint32_t\
    \ ceil_log2(std::uint32_t x) {\n    static const ::std::uint32_t t[6] = {\n  \
    \    0xFFFF0000u,\n      0x0000FF00u,\n      0x000000F0u,\n      0x0000000Cu,\n\
    \      0x00000002u\n    };\n\n    ::std::uint32_t y = (((x & (x - 1)) == 0) ?\
    \ 0 : 1);\n    ::std::uint32_t j = 16;\n\n    for (const ::std::uint32_t& t_i\
    \ : t) {\n      ::std::uint32_t k = (((x & t_i) == 0) ? 0 : j);\n      y += k;\n\
    \      x >>= k;\n      j >>= 1;\n    }\n\n    return y;\n  }\n\n  inline ::std::uint64_t\
    \ ceil_log2(::std::uint64_t x) {\n    static const ::std::uint64_t t[6] = {\n\
    \      0xFFFFFFFF00000000u,\n      0x00000000FFFF0000u,\n      0x000000000000FF00u,\n\
    \      0x00000000000000F0u,\n      0x000000000000000Cu,\n      0x0000000000000002u\n\
    \    };\n\n    ::std::uint64_t y = (((x & (x - 1)) == 0) ? 0 : 1);\n    ::std::uint64_t\
    \ j = 32;\n\n    for (const ::std::uint64_t& t_i : t) {\n      ::std::uint64_t\
    \ k = (((x & t_i) == 0) ? 0 : j);\n      y += k;\n      x >>= k;\n      j >>=\
    \ 1;\n    }\n\n    return y;\n  }\n\n  inline ::std::int32_t ceil_log2(::std::int32_t\
    \ x) {\n    return static_cast<::std::int32_t>(::tools::ceil_log2(static_cast<::std::uint32_t>(x)));\n\
    \  }\n\n  inline ::std::int64_t ceil_log2(::std::int64_t x) {\n    return static_cast<::std::int64_t>(::tools::ceil_log2(static_cast<::std::uint64_t>(x)));\n\
    \  }\n}\n\n\n#line 1 \"tools/pow2.hpp\"\n\n\n\n#include <type_traits>\n#line 6\
    \ \"tools/pow2.hpp\"\n\nnamespace tools {\n\n  template <typename T, typename\
    \ ::std::enable_if<::std::is_unsigned<T>::value, ::std::nullptr_t>::type = nullptr>\n\
    \  constexpr T pow2(const T x) {\n    return static_cast<T>(1) << x;\n  }\n\n\
    \  template <typename T, typename ::std::enable_if<::std::is_signed<T>::value,\
    \ ::std::nullptr_t>::type = nullptr>\n  constexpr T pow2(const T x) {\n    return\
    \ static_cast<T>(static_cast<typename ::std::make_unsigned<T>::type>(1) << static_cast<typename\
    \ ::std::make_unsigned<T>::type>(x));\n  }\n}\n\n\n#line 1 \"tools/floor_log2.hpp\"\
    \n\n\n\n#line 1 \"tools/popcount.hpp\"\n\n\n\n#line 5 \"tools/popcount.hpp\"\n\
    \nnamespace tools {\n\n  inline ::std::uint32_t popcount(::std::uint32_t x) {\n\
    \    x = (x & static_cast<::std::uint32_t>(0x55555555ull)) + (x >> static_cast<::std::uint32_t>(1)\
    \ & static_cast<::std::uint32_t>(0x55555555ull));\n    x = (x & static_cast<::std::uint32_t>(0x33333333ull))\
    \ + (x >> static_cast<::std::uint32_t>(2) & static_cast<::std::uint32_t>(0x33333333ull));\n\
    \    x = (x & static_cast<::std::uint32_t>(0x0f0f0f0full)) + (x >> static_cast<::std::uint32_t>(4)\
    \ & static_cast<::std::uint32_t>(0x0f0f0f0full));\n    x = (x & static_cast<::std::uint32_t>(0x00ff00ffull))\
    \ + (x >> static_cast<::std::uint32_t>(8) & static_cast<::std::uint32_t>(0x00ff00ffull));\n\
    \    return (x & static_cast<::std::uint32_t>(0x0000ffffull)) + (x >> static_cast<::std::uint32_t>(16)\
    \ & static_cast<::std::uint32_t>(0x0000ffffull));\n  }\n\n  inline ::std::uint64_t\
    \ popcount(::std::uint64_t x) {\n    x = (x & static_cast<::std::uint64_t>(0x5555555555555555ull))\
    \ + (x >> static_cast<::std::uint64_t>(1) & static_cast<::std::uint64_t>(0x5555555555555555ull));\n\
    \    x = (x & static_cast<::std::uint64_t>(0x3333333333333333ull)) + (x >> static_cast<::std::uint64_t>(2)\
    \ & static_cast<::std::uint64_t>(0x3333333333333333ull));\n    x = (x & static_cast<::std::uint64_t>(0x0f0f0f0f0f0f0f0full))\
    \ + (x >> static_cast<::std::uint64_t>(4) & static_cast<::std::uint64_t>(0x0f0f0f0f0f0f0f0full));\n\
    \    x = (x & static_cast<::std::uint64_t>(0x00ff00ff00ff00ffull)) + (x >> static_cast<::std::uint64_t>(8)\
    \ & static_cast<::std::uint64_t>(0x00ff00ff00ff00ffull));\n    x = (x & static_cast<::std::uint64_t>(0x0000ffff0000ffffull))\
    \ + (x >> static_cast<::std::uint64_t>(16) & static_cast<::std::uint64_t>(0x0000ffff0000ffffull));\n\
    \    return (x & static_cast<::std::uint64_t>(0x00000000ffffffffull)) + (x >>\
    \ static_cast<::std::uint64_t>(32) & static_cast<::std::uint64_t>(0x00000000ffffffffull));\n\
    \  }\n\n  inline ::std::int32_t popcount(::std::int32_t x) {\n    return static_cast<::std::int32_t>(::tools::popcount(static_cast<::std::uint32_t>(x)));\n\
    \  }\n\n  inline ::std::int64_t popcount(::std::int64_t x) {\n    return static_cast<::std::int64_t>(::tools::popcount(static_cast<::std::uint64_t>(x)));\n\
    \  }\n}\n\n\n#line 6 \"tools/floor_log2.hpp\"\n\nnamespace tools {\n\n  inline\
    \ ::std::uint32_t floor_log2(::std::uint32_t x) {\n    x |= (x >> static_cast<::std::uint32_t>(1));\n\
    \    x |= (x >> static_cast<::std::uint32_t>(2));\n    x |= (x >> static_cast<::std::uint32_t>(4));\n\
    \    x |= (x >> static_cast<::std::uint32_t>(8));\n    x |= (x >> static_cast<::std::uint32_t>(16));\n\
    \    return ::tools::popcount(x) - static_cast<::std::uint32_t>(1);\n  }\n\n \
    \ inline ::std::uint64_t floor_log2(::std::uint64_t x) {\n    x |= (x >> static_cast<::std::uint64_t>(1));\n\
    \    x |= (x >> static_cast<::std::uint64_t>(2));\n    x |= (x >> static_cast<::std::uint64_t>(4));\n\
    \    x |= (x >> static_cast<::std::uint64_t>(8));\n    x |= (x >> static_cast<::std::uint64_t>(16));\n\
    \    x |= (x >> static_cast<::std::uint64_t>(32));\n    return ::tools::popcount(x)\
    \ - static_cast<::std::uint64_t>(1);\n  }\n\n  inline ::std::int32_t floor_log2(::std::int32_t\
    \ x) {\n    return static_cast<::std::int32_t>(::tools::floor_log2(static_cast<::std::uint32_t>(x)));\n\
    \  }\n\n  inline ::std::int64_t floor_log2(::std::int64_t x) {\n    return static_cast<::std::int64_t>(::tools::floor_log2(static_cast<::std::uint64_t>(x)));\n\
    \  }\n}\n\n\n#line 12 \"tools/disjoint_sparse_table.hpp\"\n\nnamespace tools {\n\
    \  template <typename M>\n  class disjoint_sparse_table {\n  private:\n    using\
    \ T = typename M::T;\n    ::std::vector<T> m_value;\n    ::std::size_t m_size;\n\
    \    ::std::size_t m_capacity;\n    ::std::size_t m_height;\n\n  public:\n   \
    \ disjoint_sparse_table() = default;\n    disjoint_sparse_table(const ::tools::disjoint_sparse_table<M>&)\
    \ = default;\n    disjoint_sparse_table(::tools::disjoint_sparse_table<M>&&) =\
    \ default;\n    ~disjoint_sparse_table() = default;\n    ::tools::disjoint_sparse_table<M>&\
    \ operator=(const ::tools::disjoint_sparse_table<M>&) = default;\n    ::tools::disjoint_sparse_table<M>&\
    \ operator=(::tools::disjoint_sparse_table<M>&&) = default;\n\n    template <typename\
    \ InputIterator>\n    disjoint_sparse_table(const InputIterator& begin, const\
    \ InputIterator& end) {\n      ::std::copy(begin, end, ::std::back_inserter(this->m_value));\n\
    \      this->m_size = this->m_value.size();\n      this->m_height = this->m_size\
    \ <= 1 ? this->m_size : ::tools::ceil_log2(this->m_size);\n      this->m_capacity\
    \ = this->m_size <= 1 ? this->m_size : ::tools::pow2(this->m_height);\n      this->m_value.resize(this->m_height\
    \ * this->m_capacity);\n      ::std::fill(this->m_value.begin() + this->m_size,\
    \ this->m_value.begin() + this->m_capacity, M::e());\n\n      for (::std::size_t\
    \ d = 1; d < this->m_height; ++d) {\n        const ::std::size_t offset = d *\
    \ this->m_capacity;\n        for (::std::size_t m = ::tools::pow2(d); m < this->m_capacity;\
    \ m += ::tools::pow2(d + 1)) {\n          this->m_value[offset + (m - 1)] = this->m_value[m\
    \ - 1];\n          this->m_value[offset + m] = this->m_value[m];\n          for\
    \ (::std::size_t l = m - 1; l --> m - ::tools::pow2(d);) {\n            this->m_value[offset\
    \ + l] = M::op(this->m_value[l], this->m_value[offset + (l + 1)]);\n         \
    \ }\n          for (::std::size_t r = m + 2; r <= m + ::tools::pow2(d); ++r) {\n\
    \            this->m_value[offset + (r - 1)] = M::op(this->m_value[offset + (r\
    \ - 2)], this->m_value[r - 1]);\n          }\n        }\n      }\n    }\n\n  \
    \  ::std::size_t size() const {\n      return this->m_size;\n    }\n\n    T prod(const\
    \ ::std::size_t l, const ::std::size_t r) const {\n      assert(l <= r && r <=\
    \ this->m_size);\n      if (r - l == 0) {\n        return M::e();\n      } else\
    \ if (r - l == 1) {\n        return this->m_value[l];\n      } else {\n      \
    \  const ::std::size_t offset = ::tools::floor_log2(l ^ (r - 1)) * this->m_capacity;\n\
    \        return M::op(this->m_value[offset + l], this->m_value[offset + (r - 1)]);\n\
    \      }\n    }\n  };\n}\n\n\n#line 7 \"tests/disjoint_sparse_table.test.cpp\"\
    \n\nusing i64 = std::int_fast64_t;\n\nint main() {\n  std::cin.tie(nullptr);\n\
    \  std::ios_base::sync_with_stdio(false);\n\n  i64 N, Q;\n  std::cin >> N >> Q;\n\
    \  std::vector<i64> a(N);\n  for (auto& a_i : a) {\n    std::cin >> a_i;\n  }\n\
    \n  tools::disjoint_sparse_table<tools::monoid::min<i64>> dst(a.begin(), a.end());\n\
    \  for (i64 q = 0; q < Q; ++q) {\n    i64 l, r;\n    std::cin >> l >> r;\n   \
    \ std::cout << dst.prod(l, r) << '\\n';\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n\n#include\
    \ <cstdint>\n#include <iostream>\n#include \"tools/monoid.hpp\"\n#include \"tools/disjoint_sparse_table.hpp\"\
    \n\nusing i64 = std::int_fast64_t;\n\nint main() {\n  std::cin.tie(nullptr);\n\
    \  std::ios_base::sync_with_stdio(false);\n\n  i64 N, Q;\n  std::cin >> N >> Q;\n\
    \  std::vector<i64> a(N);\n  for (auto& a_i : a) {\n    std::cin >> a_i;\n  }\n\
    \n  tools::disjoint_sparse_table<tools::monoid::min<i64>> dst(a.begin(), a.end());\n\
    \  for (i64 q = 0; q < Q; ++q) {\n    i64 l, r;\n    std::cin >> l >> r;\n   \
    \ std::cout << dst.prod(l, r) << '\\n';\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - tools/monoid.hpp
  - tools/disjoint_sparse_table.hpp
  - tools/ceil_log2.hpp
  - tools/pow2.hpp
  - tools/floor_log2.hpp
  - tools/popcount.hpp
  isVerificationFile: true
  path: tests/disjoint_sparse_table.test.cpp
  requiredBy: []
  timestamp: '2021-12-29 01:11:21+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/disjoint_sparse_table.test.cpp
layout: document
redirect_from:
- /verify/tests/disjoint_sparse_table.test.cpp
- /verify/tests/disjoint_sparse_table.test.cpp.html
title: tests/disjoint_sparse_table.test.cpp
---
