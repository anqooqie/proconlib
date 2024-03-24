---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/ceil_log2.hpp
    title: $\left\lceil \log_2(x) \right\rceil$
  - icon: ':heavy_check_mark:'
    path: tools/disjoint_sparse_table_2d.hpp
    title: 2D disjoint sparse table
  - icon: ':heavy_check_mark:'
    path: tools/floor_log2.hpp
    title: $\left\lfloor \log_2(x) \right\rfloor$
  - icon: ':heavy_check_mark:'
    path: tools/group.hpp
    title: Typical groups
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/0560
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/0560
  bundledCode: "#line 1 \"tests/disjoint_sparse_table_2d.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/problems/0560\"\n\n#include <iostream>\n\
    #include <vector>\n#include <string>\n#include <algorithm>\n#include <iterator>\n\
    #line 1 \"tools/disjoint_sparse_table_2d.hpp\"\n\n\n\n#line 5 \"tools/disjoint_sparse_table_2d.hpp\"\
    \n#include <cstddef>\n#line 8 \"tools/disjoint_sparse_table_2d.hpp\"\n#include\
    \ <cassert>\n#line 1 \"tools/ceil_log2.hpp\"\n\n\n\n#include <type_traits>\n#line\
    \ 6 \"tools/ceil_log2.hpp\"\n#include <limits>\n#include <tuple>\n#include <array>\n\
    #include <cstdint>\n\n// Source: https://stackoverflow.com/questions/3272424/compute-fast-log-base-2-ceiling/15327567#15327567\n\
    // License: CC BY-SA 3.0\n// Author: dgobbi\n\nnamespace tools {\n\n  template\
    \ <typename T>\n  T ceil_log2(T x) {\n    static_assert(::std::is_integral_v<T>);\n\
    \    assert(x > 0);\n    if constexpr (::std::is_signed_v<T>) {\n      return\
    \ static_cast<T>(::tools::ceil_log2<::std::make_unsigned_t<T>>(x));\n    } else\
    \ {\n      const auto log2 = [](const int w) {\n        if (w == 8) return 3;\n\
    \        if (w == 16) return 4;\n        if (w == 32) return 5;\n        if (w\
    \ == 64) return 6;\n        return -1;\n      };\n      static_assert(log2(::std::numeric_limits<T>::digits)\
    \ >= 0);\n\n      constexpr auto t = ::std::make_tuple(\n        ::std::array<::std::uint8_t,\
    \ 3>({\n          UINT8_C(0xf0),\n          UINT8_C(0x0c),\n          UINT8_C(0x02)\n\
    \        }),\n        ::std::array<::std::uint16_t, 4>({\n          UINT16_C(0xff00),\n\
    \          UINT16_C(0x00f0),\n          UINT16_C(0x000c),\n          UINT16_C(0x0002)\n\
    \        }),\n        ::std::array<::std::uint32_t, 5>({\n          UINT32_C(0xffff0000),\n\
    \          UINT32_C(0x0000ff00),\n          UINT32_C(0x000000f0),\n          UINT32_C(0x0000000c),\n\
    \          UINT32_C(0x00000002)\n        }),\n        ::std::array<::std::uint64_t,\
    \ 6>({\n          UINT64_C(0xffffffff00000000),\n          UINT64_C(0x00000000ffff0000),\n\
    \          UINT64_C(0x000000000000ff00),\n          UINT64_C(0x00000000000000f0),\n\
    \          UINT64_C(0x000000000000000c),\n          UINT64_C(0x0000000000000002)\n\
    \        })\n      );\n\n      T y = (((x & (x - 1)) == 0) ? 0 : 1);\n      T\
    \ j = ::std::numeric_limits<T>::digits / 2;\n\n      for (const auto t_i : ::std::get<log2(::std::numeric_limits<T>::digits)\
    \ - 3>(t)) {\n        T k = (((x & t_i) == 0) ? 0 : j);\n        y += k;\n   \
    \     x >>= k;\n        j >>= 1;\n      }\n\n      return y;\n    }\n  }\n}\n\n\
    \n#line 1 \"tools/pow2.hpp\"\n\n\n\n#line 6 \"tools/pow2.hpp\"\n\nnamespace tools\
    \ {\n\n  template <typename T, typename ::std::enable_if<::std::is_unsigned<T>::value,\
    \ ::std::nullptr_t>::type = nullptr>\n  constexpr T pow2(const T x) {\n    return\
    \ static_cast<T>(1) << x;\n  }\n\n  template <typename T, typename ::std::enable_if<::std::is_signed<T>::value,\
    \ ::std::nullptr_t>::type = nullptr>\n  constexpr T pow2(const T x) {\n    return\
    \ static_cast<T>(static_cast<typename ::std::make_unsigned<T>::type>(1) << static_cast<typename\
    \ ::std::make_unsigned<T>::type>(x));\n  }\n}\n\n\n#line 1 \"tools/floor_log2.hpp\"\
    \n\n\n\n#line 1 \"tools/popcount.hpp\"\n\n\n\n#line 8 \"tools/popcount.hpp\"\n\
    \nnamespace tools {\n\n  template <typename T>\n  T popcount(T x) {\n    static_assert(::std::is_integral_v<T>);\n\
    \    assert(x >= 0);\n    if constexpr (::std::is_signed_v<T>) {\n      return\
    \ static_cast<T>(::tools::popcount<::std::make_unsigned_t<T>>(x));\n    } else\
    \ {\n      const auto log2 = [](const int w) {\n        if (w == 8) return 3;\n\
    \        if (w == 16) return 4;\n        if (w == 32) return 5;\n        if (w\
    \ == 64) return 6;\n        return -1;\n      };\n      static_assert(log2(::std::numeric_limits<T>::digits)\
    \ >= 0);\n\n      if constexpr (::std::numeric_limits<T>::digits == 8) {\n   \
    \     x = (x & UINT8_C(0x55)) + (x >> 1 & UINT8_C(0x55));\n        x = (x & UINT8_C(0x33))\
    \ + (x >> 2 & UINT8_C(0x33));\n        x = (x & UINT8_C(0x0f)) + (x >> 4 & UINT8_C(0x0f));\n\
    \      } else if constexpr (::std::numeric_limits<T>::digits == 16) {\n      \
    \  x = (x & UINT16_C(0x5555)) + (x >> 1 & UINT16_C(0x5555));\n        x = (x &\
    \ UINT16_C(0x3333)) + (x >> 2 & UINT16_C(0x3333));\n        x = (x & UINT16_C(0x0f0f))\
    \ + (x >> 4 & UINT16_C(0x0f0f));\n        x = (x & UINT16_C(0x00ff)) + (x >> 8\
    \ & UINT16_C(0x00ff));\n      } else if constexpr (::std::numeric_limits<T>::digits\
    \ == 32) {\n        x = (x & UINT32_C(0x55555555)) + (x >> 1 & UINT32_C(0x55555555));\n\
    \        x = (x & UINT32_C(0x33333333)) + (x >> 2 & UINT32_C(0x33333333));\n \
    \       x = (x & UINT32_C(0x0f0f0f0f)) + (x >> 4 & UINT32_C(0x0f0f0f0f));\n  \
    \      x = (x & UINT32_C(0x00ff00ff)) + (x >> 8 & UINT32_C(0x00ff00ff));\n   \
    \     x = (x & UINT32_C(0x0000ffff)) + (x >> 16 & UINT32_C(0x0000ffff));\n   \
    \   } else if constexpr (::std::numeric_limits<T>::digits == 64) {\n        x\
    \ = (x & UINT64_C(0x5555555555555555)) + (x >> 1 & UINT64_C(0x5555555555555555));\n\
    \        x = (x & UINT64_C(0x3333333333333333)) + (x >> 2 & UINT64_C(0x3333333333333333));\n\
    \        x = (x & UINT64_C(0x0f0f0f0f0f0f0f0f)) + (x >> 4 & UINT64_C(0x0f0f0f0f0f0f0f0f));\n\
    \        x = (x & UINT64_C(0x00ff00ff00ff00ff)) + (x >> 8 & UINT64_C(0x00ff00ff00ff00ff));\n\
    \        x = (x & UINT64_C(0x0000ffff0000ffff)) + (x >> 16 & UINT64_C(0x0000ffff0000ffff));\n\
    \        x = (x & UINT64_C(0x00000000ffffffff)) + (x >> 32 & UINT64_C(0x00000000ffffffff));\n\
    \      }\n\n      return x;\n    }\n  }\n}\n\n\n#line 8 \"tools/floor_log2.hpp\"\
    \n\nnamespace tools {\n\n  template <typename T>\n  T floor_log2(T x) {\n    static_assert(::std::is_integral_v<T>);\n\
    \    assert(x > 0);\n    if constexpr (::std::is_signed_v<T>) {\n      return\
    \ static_cast<T>(::tools::floor_log2<::std::make_unsigned_t<T>>(x));\n    } else\
    \ {\n      const auto log2 = [](const int w) {\n        if (w == 8) return 3;\n\
    \        if (w == 16) return 4;\n        if (w == 32) return 5;\n        if (w\
    \ == 64) return 6;\n        return -1;\n      };\n      static_assert(log2(::std::numeric_limits<T>::digits)\
    \ >= 0);\n\n      x |= (x >> 1);\n      x |= (x >> 2);\n      x |= (x >> 4);\n\
    \      if constexpr (::std::numeric_limits<T>::digits > 8) x |= (x >> 8);\n  \
    \    if constexpr (::std::numeric_limits<T>::digits > 16) x |= (x >> 16);\n  \
    \    if constexpr (::std::numeric_limits<T>::digits > 32) x |= (x >> 32);\n  \
    \    return ::tools::popcount(x) - static_cast<T>(1);\n    }\n  }\n}\n\n\n#line\
    \ 12 \"tools/disjoint_sparse_table_2d.hpp\"\n\nnamespace tools {\n  template <typename\
    \ M>\n  class disjoint_sparse_table_2d {\n  private:\n    using T = typename M::T;\n\
    \    ::std::vector<::std::vector<T>> m_value;\n    ::std::size_t m_height;\n \
    \   ::std::size_t m_width;\n    ::std::size_t m_hcapacity;\n    ::std::size_t\
    \ m_wcapacity;\n\n  public:\n    disjoint_sparse_table_2d() = default;\n    disjoint_sparse_table_2d(const\
    \ ::tools::disjoint_sparse_table_2d<M>&) = default;\n    disjoint_sparse_table_2d(::tools::disjoint_sparse_table_2d<M>&&)\
    \ = default;\n    ~disjoint_sparse_table_2d() = default;\n    ::tools::disjoint_sparse_table_2d<M>&\
    \ operator=(const ::tools::disjoint_sparse_table_2d<M>&) = default;\n    ::tools::disjoint_sparse_table_2d<M>&\
    \ operator=(::tools::disjoint_sparse_table_2d<M>&&) = default;\n\n    template\
    \ <typename Range>\n    explicit disjoint_sparse_table_2d(const Range& range)\
    \ {\n      const auto begin = ::std::begin(range);\n      const auto end = ::std::end(range);\n\
    \      this->m_height = ::std::distance(begin, end);\n      this->m_width = this->m_height\
    \ == 0 ? 0 : ::std::distance(::std::begin(*begin), ::std::end(*begin));\n    \
    \  assert(::std::all_of(begin, end, [&](const auto& row) { return static_cast<::std::size_t>(::std::distance(::std::begin(row),\
    \ ::std::end(row))) == this->m_width; }));\n\n      const auto hdepth = this->m_height\
    \ <= 1 ? this->m_height : ::tools::ceil_log2(this->m_height);\n      const auto\
    \ wdepth = this->m_width <= 1 ? this->m_width : ::tools::ceil_log2(this->m_width);\n\
    \      this->m_hcapacity = this->m_height <= 1 ? this->m_height : ::tools::pow2(hdepth);\n\
    \      this->m_wcapacity = this->m_width <= 1 ? this->m_width : ::tools::pow2(wdepth);\n\
    \n      const auto construct_horizontal_dst = [&](::std::vector<T>& row) {\n \
    \       row.resize(wdepth * this->m_wcapacity);\n        ::std::fill(row.begin()\
    \ + this->m_width, row.begin() + this->m_wcapacity, M::e());\n\n        for (::std::size_t\
    \ d = 1; d < wdepth; ++d) {\n          const ::std::size_t offset = d * this->m_wcapacity;\n\
    \          for (::std::size_t m = ::tools::pow2(d); m < this->m_wcapacity; m +=\
    \ ::tools::pow2(d + 1)) {\n            row[offset + (m - 1)] = row[m - 1];\n \
    \           row[offset + m] = row[m];\n            for (::std::size_t l = m -\
    \ 1; l --> m - ::tools::pow2(d);) {\n              row[offset + l] = M::op(row[l],\
    \ row[offset + (l + 1)]);\n            }\n            for (::std::size_t r = m\
    \ + 2; r <= m + ::tools::pow2(d); ++r) {\n              row[offset + (r - 1)]\
    \ = M::op(row[offset + (r - 2)], row[r - 1]);\n            }\n          }\n  \
    \      }\n      };\n\n      this->m_value.resize(hdepth * this->m_hcapacity);\n\
    \      for (auto& row : this->m_value) {\n        row.reserve(wdepth * this->m_wcapacity);\n\
    \      }\n      for (::std::size_t h = 0; h < this->m_height; ++h) {\n       \
    \ ::std::copy(::std::begin(begin[h]), ::std::end(begin[h]), ::std::back_inserter(this->m_value[h]));\n\
    \        construct_horizontal_dst(this->m_value[h]);\n      }\n      for (::std::size_t\
    \ h = this->m_height; h < this->m_hcapacity; ++h) {\n        this->m_value[h].resize(wdepth\
    \ * this->m_wcapacity, M::e());\n      }\n\n      for (::std::size_t d = 1; d\
    \ < hdepth; ++d) {\n        const ::std::size_t offset = d * this->m_hcapacity;\n\
    \        for (::std::size_t m = ::tools::pow2(d); m < this->m_hcapacity; m +=\
    \ ::tools::pow2(d + 1)) {\n          ::std::copy(this->m_value[m - 1].begin(),\
    \ this->m_value[m - 1].end(), ::std::back_inserter(this->m_value[offset + (m -\
    \ 1)]));\n          ::std::copy(this->m_value[m].begin(), this->m_value[m].end(),\
    \ ::std::back_inserter(this->m_value[offset + m]));\n          for (::std::size_t\
    \ l = m - 1; l --> m - ::tools::pow2(d);) {\n            for (::std::size_t w\
    \ = 0; w < wdepth * this->m_wcapacity; ++w) {\n              this->m_value[offset\
    \ + l].push_back(M::op(this->m_value[l][w], this->m_value[offset + (l + 1)][w]));\n\
    \            }\n          }\n          for (::std::size_t r = m + 2; r <= m +\
    \ ::tools::pow2(d); ++r) {\n            for (::std::size_t w = 0; w < wdepth *\
    \ this->m_wcapacity; ++w) {\n              this->m_value[offset + (r - 1)].push_back(M::op(this->m_value[offset\
    \ + (r - 2)][w], this->m_value[r - 1][w]));\n            }\n          }\n    \
    \    }\n      }\n    }\n\n    ::std::size_t height() const {\n      return this->m_height;\n\
    \    }\n    ::std::size_t width() const {\n      return this->m_width;\n    }\n\
    \n    T prod(const ::std::size_t d, const ::std::size_t u, const ::std::size_t\
    \ l, const ::std::size_t r) const {\n      assert(d <= u && u <= this->m_height);\n\
    \      assert(l <= r && r <= this->m_width);\n      if (u - d == 0 || r - l ==\
    \ 0) {\n        return M::e();\n      } else if (u - d == 1 && r - l == 1) {\n\
    \        return this->m_value[d][l];\n      } else if (u - d == 1) {\n       \
    \ const ::std::size_t woffset = ::tools::floor_log2(l ^ (r - 1)) * this->m_wcapacity;\n\
    \        return M::op(this->m_value[d][woffset + l], this->m_value[d][woffset\
    \ + (r - 1)]);\n      } else if (r - l == 1) {\n        const ::std::size_t hoffset\
    \ = ::tools::floor_log2(d ^ (u - 1)) * this->m_hcapacity;\n        return M::op(this->m_value[hoffset\
    \ + d][l], this->m_value[hoffset + (u - 1)][l]);\n      } else {\n        const\
    \ ::std::size_t hoffset = ::tools::floor_log2(d ^ (u - 1)) * this->m_hcapacity;\n\
    \        const ::std::size_t woffset = ::tools::floor_log2(l ^ (r - 1)) * this->m_wcapacity;\n\
    \        return M::op(\n          M::op(this->m_value[hoffset + d][woffset + l],\
    \ this->m_value[hoffset + d][woffset + (r - 1)]),\n          M::op(this->m_value[hoffset\
    \ + (u - 1)][woffset + l], this->m_value[hoffset + (u - 1)][woffset + (r - 1)])\n\
    \        );\n      }\n    }\n  };\n}\n\n\n#line 1 \"tools/group.hpp\"\n\n\n\n\
    namespace tools {\n  namespace group {\n    template <typename G>\n    struct\
    \ plus {\n      using T = G;\n      static T op(const T& lhs, const T& rhs) {\n\
    \        return lhs + rhs;\n      }\n      static T e() {\n        return T(0);\n\
    \      }\n      static T inv(const T& v) {\n        return -v;\n      }\n    };\n\
    \n    template <typename G>\n    struct multiplies {\n      using T = G;\n   \
    \   static T op(const T& lhs, const T& rhs) {\n        return lhs * rhs;\n   \
    \   }\n      static T e() {\n        return T(1);\n      }\n      static T inv(const\
    \ T& v) {\n        return e() / v;\n      }\n    };\n\n    template <typename\
    \ G>\n    struct bit_xor {\n      using T = G;\n      static T op(const T& lhs,\
    \ const T& rhs) {\n        return lhs ^ rhs;\n      }\n      static T e() {\n\
    \        return T(0);\n      }\n      static T inv(const T& v) {\n        return\
    \ v;\n      }\n    };\n  }\n}\n\n\n#line 10 \"tests/disjoint_sparse_table_2d.test.cpp\"\
    \n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  int M, N, K;\n  std::cin >> M >> N >> K;\n  std::vector<std::string> map;\n\
    \  map.reserve(M);\n  std::copy_n(std::istream_iterator<std::string>(std::cin),\
    \ M, std::back_inserter(map));\n\n  auto J = std::vector(M, std::vector<int>(N,\
    \ 0));\n  auto O = std::vector(M, std::vector<int>(N, 0));\n  auto I = std::vector(M,\
    \ std::vector<int>(N, 0));\n  for (int y = 0; y < M; ++y) {\n    for (int x =\
    \ 0; x < N; ++x) {\n      switch (map[y][x]) {\n      case 'J':\n        ++J[y][x];\n\
    \        break;\n      case 'O':\n        ++O[y][x];\n        break;\n      case\
    \ 'I':\n        ++I[y][x];\n        break;\n      }\n    }\n  }\n\n  tools::disjoint_sparse_table_2d<tools::group::plus<int>>\
    \ J_dst(J);\n  tools::disjoint_sparse_table_2d<tools::group::plus<int>> O_dst(O);\n\
    \  tools::disjoint_sparse_table_2d<tools::group::plus<int>> I_dst(I);\n\n  for\
    \ (int i = 0; i < K; ++i) {\n    int a, b, c, d;\n    std::cin >> a >> b >> c\
    \ >> d;\n    --a;\n    --b;\n    std::cout << J_dst.prod(a, c, b, d) << ' ' <<\
    \ O_dst.prod(a, c, b, d) << ' ' << I_dst.prod(a, c, b, d) << '\\n';\n  }\n\n \
    \ return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/0560\"\n\n#include\
    \ <iostream>\n#include <vector>\n#include <string>\n#include <algorithm>\n#include\
    \ <iterator>\n#include \"tools/disjoint_sparse_table_2d.hpp\"\n#include \"tools/group.hpp\"\
    \n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  int M, N, K;\n  std::cin >> M >> N >> K;\n  std::vector<std::string> map;\n\
    \  map.reserve(M);\n  std::copy_n(std::istream_iterator<std::string>(std::cin),\
    \ M, std::back_inserter(map));\n\n  auto J = std::vector(M, std::vector<int>(N,\
    \ 0));\n  auto O = std::vector(M, std::vector<int>(N, 0));\n  auto I = std::vector(M,\
    \ std::vector<int>(N, 0));\n  for (int y = 0; y < M; ++y) {\n    for (int x =\
    \ 0; x < N; ++x) {\n      switch (map[y][x]) {\n      case 'J':\n        ++J[y][x];\n\
    \        break;\n      case 'O':\n        ++O[y][x];\n        break;\n      case\
    \ 'I':\n        ++I[y][x];\n        break;\n      }\n    }\n  }\n\n  tools::disjoint_sparse_table_2d<tools::group::plus<int>>\
    \ J_dst(J);\n  tools::disjoint_sparse_table_2d<tools::group::plus<int>> O_dst(O);\n\
    \  tools::disjoint_sparse_table_2d<tools::group::plus<int>> I_dst(I);\n\n  for\
    \ (int i = 0; i < K; ++i) {\n    int a, b, c, d;\n    std::cin >> a >> b >> c\
    \ >> d;\n    --a;\n    --b;\n    std::cout << J_dst.prod(a, c, b, d) << ' ' <<\
    \ O_dst.prod(a, c, b, d) << ' ' << I_dst.prod(a, c, b, d) << '\\n';\n  }\n\n \
    \ return 0;\n}\n"
  dependsOn:
  - tools/disjoint_sparse_table_2d.hpp
  - tools/ceil_log2.hpp
  - tools/pow2.hpp
  - tools/floor_log2.hpp
  - tools/popcount.hpp
  - tools/group.hpp
  isVerificationFile: true
  path: tests/disjoint_sparse_table_2d.test.cpp
  requiredBy: []
  timestamp: '2024-02-18 13:45:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/disjoint_sparse_table_2d.test.cpp
layout: document
redirect_from:
- /verify/tests/disjoint_sparse_table_2d.test.cpp
- /verify/tests/disjoint_sparse_table_2d.test.cpp.html
title: tests/disjoint_sparse_table_2d.test.cpp
---
