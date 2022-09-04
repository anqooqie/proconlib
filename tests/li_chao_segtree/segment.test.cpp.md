---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: tools/ceil_log2.hpp
    title: $\left\lceil \log_2(x) \right\rceil$
  - icon: ':heavy_check_mark:'
    path: tools/floor_log2.hpp
    title: $\left\lfloor \log_2(x) \right\rfloor$
  - icon: ':heavy_check_mark:'
    path: tools/li_chao_segtree.hpp
    title: Li Chao segment tree
  - icon: ':question:'
    path: tools/lower_bound.hpp
    title: std::lower_bound, but returns index
  - icon: ':heavy_check_mark:'
    path: tools/popcount.hpp
    title: Popcount
  - icon: ':question:'
    path: tools/pow2.hpp
    title: $2^x$
  - icon: ':question:'
    path: tools/ssize.hpp
    title: Polyfill of std::ssize
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/segment_add_get_min
    links:
    - https://judge.yosupo.jp/problem/segment_add_get_min
  bundledCode: "#line 1 \"tests/li_chao_segtree/segment.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/segment_add_get_min\"\n\n#include <cstdint>\n\
    #include <iostream>\n#include <vector>\n#include <tuple>\n#include <algorithm>\n\
    #include <limits>\n#line 1 \"tools/li_chao_segtree.hpp\"\n\n\n\n#line 5 \"tools/li_chao_segtree.hpp\"\
    \n#include <cstddef>\n#include <utility>\n#line 8 \"tools/li_chao_segtree.hpp\"\
    \n#include <cassert>\n#line 10 \"tools/li_chao_segtree.hpp\"\n#include <numeric>\n\
    #include <iterator>\n#line 1 \"tools/pow2.hpp\"\n\n\n\n#include <type_traits>\n\
    #line 6 \"tools/pow2.hpp\"\n\nnamespace tools {\n\n  template <typename T, typename\
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
    \  }\n}\n\n\n#line 1 \"tools/ceil_log2.hpp\"\n\n\n\n#line 5 \"tools/ceil_log2.hpp\"\
    \n\n// Source: https://stackoverflow.com/questions/3272424/compute-fast-log-base-2-ceiling/15327567#15327567\n\
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
    \  }\n}\n\n\n#line 1 \"tools/lower_bound.hpp\"\n\n\n\n#line 6 \"tools/lower_bound.hpp\"\
    \n\nnamespace tools {\n\n  template <class ForwardIterator, class T>\n  auto lower_bound(ForwardIterator\
    \ first, ForwardIterator last, const T& value) {\n    return ::std::distance(first,\
    \ ::std::lower_bound(first, last, value));\n  }\n\n  template <class ForwardIterator,\
    \ class T, class Compare>\n  auto lower_bound(ForwardIterator first, ForwardIterator\
    \ last, const T& value, Compare comp) {\n    return ::std::distance(first, ::std::lower_bound(first,\
    \ last, value, comp));\n  }\n}\n\n\n#line 1 \"tools/ssize.hpp\"\n\n\n\n#line 6\
    \ \"tools/ssize.hpp\"\n\nnamespace tools {\n\n  template <typename C>\n  constexpr\
    \ auto ssize(const C& c) -> ::std::common_type_t<::std::ptrdiff_t, ::std::make_signed_t<decltype(c.size())>>\
    \ {\n    return c.size();\n  }\n}\n\n\n#line 18 \"tools/li_chao_segtree.hpp\"\n\
    \nnamespace tools {\n  template <typename T>\n  class li_chao_segtree {\n  private:\n\
    \    bool m_maximal;\n    ::std::vector<T> m_xs;\n    ::std::size_t m_height;\n\
    \    ::std::vector<::std::pair<T, T>> m_nodes;\n\n    ::std::size_t capacity()\
    \ const {\n      return this->m_nodes.size() / 2;\n    }\n\n    bool comp(const\
    \ T& x, const T& y) const {\n      return this->m_maximal ? x < y : y < x;\n \
    \   }\n\n    void add_impl(T fa, T fb, ::std::size_t node_id) {\n      assert(::tools::floor_log2(node_id)\
    \ <= this->m_height);\n      ::std::size_t l = (node_id - ::tools::pow2(::tools::floor_log2(node_id)))\
    \ * ::tools::pow2(this->m_height - ::tools::floor_log2(node_id));\n      ::std::size_t\
    \ r = l + ::tools::pow2(this->m_height - ::tools::floor_log2(node_id));\n    \
    \  while (node_id < this->m_nodes.size()) {\n        const ::std::size_t m = (l\
    \ + r) / 2;\n        auto& [ga, gb] = this->m_nodes[node_id];\n        bool greater_l\
    \ = this->comp(ga * this->m_xs[l] + gb, fa * this->m_xs[l] + fb);\n        bool\
    \ greater_m = this->comp(ga * this->m_xs[m] + gb, fa * this->m_xs[m] + fb);\n\
    \        bool greater_r = this->comp(ga * this->m_xs[r] + gb, fa * this->m_xs[r]\
    \ + fb);\n        if (greater_l == greater_m && greater_m == greater_r) {\n  \
    \        if (greater_l) {\n            ::std::swap(fa, ga);\n            ::std::swap(fb,\
    \ gb);\n          }\n          return;\n        }\n        if (greater_m) {\n\
    \          ::std::swap(fa, ga);\n          ::std::swap(fb, gb);\n          greater_l\
    \ = !greater_l;\n          greater_m = !greater_m;\n          greater_r = !greater_r;\n\
    \        }\n        if (greater_l) {\n          node_id = node_id * 2;\n     \
    \     r = m;\n        } else {\n          node_id = node_id * 2 + 1;\n       \
    \   l = m;\n        }\n      }\n    }\n\n  public:\n    template <typename Iterator>\n\
    \    li_chao_segtree(const Iterator& begin, const Iterator& end, const bool maximal)\
    \ :\n      m_maximal(maximal),\n      m_xs(begin, end),\n      m_height(::tools::ceil_log2(this->m_xs.size())),\n\
    \      m_nodes(::tools::pow2(this->m_height + 1), ::std::pair<T, T>(0, maximal\
    \ ? ::std::numeric_limits<T>::min() : ::std::numeric_limits<T>::max())) {\n  \
    \    assert(::std::is_sorted(this->m_xs.begin(), this->m_xs.end()));\n      const\
    \ ::std::size_t n = this->m_xs.size();\n      this->m_xs.resize(this->capacity()\
    \ + 1);\n      ::std::iota(this->m_xs.begin() + n, this->m_xs.end(), this->m_xs[n\
    \ - 1] + 1);\n    }\n\n    li_chao_segtree() = default;\n    li_chao_segtree(const\
    \ ::tools::li_chao_segtree<T>&) = default;\n    li_chao_segtree(::tools::li_chao_segtree<T>&&)\
    \ = default;\n    ~li_chao_segtree() = default;\n    ::tools::li_chao_segtree<T>&\
    \ operator=(const ::tools::li_chao_segtree<T>&) = default;\n    ::tools::li_chao_segtree<T>&\
    \ operator=(::tools::li_chao_segtree<T>&&) = default;\n\n    void add(const T&\
    \ a, const T& b) {\n      this->add_impl(a, b, 1);\n    }\n\n    void add(const\
    \ T& a, const T& b, const T& l, const T& r) {\n      auto l_id = ::tools::lower_bound(this->m_xs.begin(),\
    \ ::std::prev(this->m_xs.end()), l);\n      auto r_id = ::tools::lower_bound(this->m_xs.begin(),\
    \ ::std::prev(this->m_xs.end()), r);\n      if (r_id == ::tools::ssize(this->m_xs)\
    \ - 1 || r < this->m_xs[r_id]) --r_id;\n      if (r_id < l_id) return;\n     \
    \ l_id += this->capacity();\n      r_id += this->capacity() + 1;\n\n      for\
    \ (; l_id < r_id; l_id >>= 1, r_id >>= 1) {\n        if (l_id & 1) {\n       \
    \   this->add_impl(a, b, l_id);\n          ++l_id;\n        }\n        if (r_id\
    \ & 1) {\n          --r_id;\n          this->add_impl(a, b, r_id);\n        }\n\
    \      }\n    }\n\n    T query(const T& x) const {\n      const auto it = ::std::lower_bound(this->m_xs.begin(),\
    \ this->m_xs.end(), x);\n      assert(*it == x);\n      const ::std::size_t node_id\
    \ = this->capacity() + ::std::distance(this->m_xs.begin(), it);\n\n      T answer\
    \ = this->m_maximal ? ::std::numeric_limits<T>::min() : ::std::numeric_limits<T>::max();\n\
    \      for (::std::size_t h = this->m_height + 1; h --> 0;) {\n        const auto&\
    \ [fa, fb] = this->m_nodes[node_id >> h];\n        if (this->comp(answer, fa *\
    \ x + fb)) {\n          answer = fa * x + fb;\n        }\n      }\n      \n  \
    \    return answer;\n    }\n  };\n}\n\n\n#line 10 \"tests/li_chao_segtree/segment.test.cpp\"\
    \n\nusing i64 = std::int_fast64_t;\n\nint main() {\n  std::cin.tie(nullptr);\n\
    \  std::ios_base::sync_with_stdio(false);\n\n  i64 N, Q;\n  std::cin >> N >> Q;\n\
    \  std::vector<i64> l(N), r(N), a(N), b(N);\n  for (i64 i = 0; i < N; ++i) {\n\
    \    std::cin >> l[i] >> r[i] >> a[i] >> b[i];\n  }\n  std::vector<std::tuple<i64,\
    \ i64, i64, i64, i64>> queries(Q);\n  for (i64 i = 0; i < Q; ++i) {\n    std::cin\
    \ >> std::get<0>(queries[i]);\n    if (std::get<0>(queries[i]) == 0) {\n     \
    \ std::cin >> std::get<1>(queries[i]) >> std::get<2>(queries[i]) >> std::get<3>(queries[i])\
    \ >> std::get<4>(queries[i]);\n    } else {\n      std::cin >> std::get<1>(queries[i]);\n\
    \    }\n  }\n\n  std::vector<i64> x;\n  for (const auto& [t, p, q2, q3, q4] :\
    \ queries) {\n    if (t == 1) {\n      x.push_back(p);\n    }\n  }\n  std::sort(x.begin(),\
    \ x.end());\n  x.erase(std::unique(x.begin(), x.end()), x.end());\n  tools::li_chao_segtree<i64>\
    \ seg(x.begin(), x.end(), false);\n\n  for (i64 i = 0; i < N; ++i) {\n    seg.add(a[i],\
    \ b[i], l[i], r[i] - 1);\n  }\n  for (const auto& [t, q1, q2, q3, q4] : queries)\
    \ {\n    if (t == 0) {\n      seg.add(q3, q4, q1, q2 - 1);\n    } else {\n   \
    \   const auto answer = seg.query(q1);\n      if (answer < std::numeric_limits<i64>::max())\
    \ {\n        std::cout << answer << '\\n';\n      } else {\n        std::cout\
    \ << \"INFINITY\" << '\\n';\n      }\n    }\n  }\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/segment_add_get_min\"\n\
    \n#include <cstdint>\n#include <iostream>\n#include <vector>\n#include <tuple>\n\
    #include <algorithm>\n#include <limits>\n#include \"tools/li_chao_segtree.hpp\"\
    \n\nusing i64 = std::int_fast64_t;\n\nint main() {\n  std::cin.tie(nullptr);\n\
    \  std::ios_base::sync_with_stdio(false);\n\n  i64 N, Q;\n  std::cin >> N >> Q;\n\
    \  std::vector<i64> l(N), r(N), a(N), b(N);\n  for (i64 i = 0; i < N; ++i) {\n\
    \    std::cin >> l[i] >> r[i] >> a[i] >> b[i];\n  }\n  std::vector<std::tuple<i64,\
    \ i64, i64, i64, i64>> queries(Q);\n  for (i64 i = 0; i < Q; ++i) {\n    std::cin\
    \ >> std::get<0>(queries[i]);\n    if (std::get<0>(queries[i]) == 0) {\n     \
    \ std::cin >> std::get<1>(queries[i]) >> std::get<2>(queries[i]) >> std::get<3>(queries[i])\
    \ >> std::get<4>(queries[i]);\n    } else {\n      std::cin >> std::get<1>(queries[i]);\n\
    \    }\n  }\n\n  std::vector<i64> x;\n  for (const auto& [t, p, q2, q3, q4] :\
    \ queries) {\n    if (t == 1) {\n      x.push_back(p);\n    }\n  }\n  std::sort(x.begin(),\
    \ x.end());\n  x.erase(std::unique(x.begin(), x.end()), x.end());\n  tools::li_chao_segtree<i64>\
    \ seg(x.begin(), x.end(), false);\n\n  for (i64 i = 0; i < N; ++i) {\n    seg.add(a[i],\
    \ b[i], l[i], r[i] - 1);\n  }\n  for (const auto& [t, q1, q2, q3, q4] : queries)\
    \ {\n    if (t == 0) {\n      seg.add(q3, q4, q1, q2 - 1);\n    } else {\n   \
    \   const auto answer = seg.query(q1);\n      if (answer < std::numeric_limits<i64>::max())\
    \ {\n        std::cout << answer << '\\n';\n      } else {\n        std::cout\
    \ << \"INFINITY\" << '\\n';\n      }\n    }\n  }\n  return 0;\n}\n"
  dependsOn:
  - tools/li_chao_segtree.hpp
  - tools/pow2.hpp
  - tools/floor_log2.hpp
  - tools/popcount.hpp
  - tools/ceil_log2.hpp
  - tools/lower_bound.hpp
  - tools/ssize.hpp
  isVerificationFile: true
  path: tests/li_chao_segtree/segment.test.cpp
  requiredBy: []
  timestamp: '2022-05-30 15:17:45+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/li_chao_segtree/segment.test.cpp
layout: document
redirect_from:
- /verify/tests/li_chao_segtree/segment.test.cpp
- /verify/tests/li_chao_segtree/segment.test.cpp.html
title: tests/li_chao_segtree/segment.test.cpp
---
