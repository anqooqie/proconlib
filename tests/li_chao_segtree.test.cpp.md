---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/ceil_log2.hpp
    title: $\left\lceil \log_2(x) \right\rceil$
  - icon: ':heavy_check_mark:'
    path: tools/li_chao_segtree.hpp
    title: Li Chao segment tree
  - icon: ':heavy_check_mark:'
    path: tools/pow2.hpp
    title: $2^x$
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/line_add_get_min
    links:
    - https://judge.yosupo.jp/problem/line_add_get_min
  bundledCode: "#line 1 \"tests/li_chao_segtree.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/line_add_get_min\"\
    \n\n#include <cstdint>\n#include <iostream>\n#line 1 \"tools/li_chao_segtree.hpp\"\
    \n\n\n\n#include <functional>\n#include <vector>\n#include <cstddef>\n#include\
    \ <optional>\n#include <utility>\n#include <algorithm>\n#include <cassert>\n#include\
    \ <numeric>\n#include <iterator>\n#line 1 \"tools/ceil_log2.hpp\"\n\n\n\n#line\
    \ 5 \"tools/ceil_log2.hpp\"\n\n// Source: https://stackoverflow.com/questions/3272424/compute-fast-log-base-2-ceiling/15327567#15327567\n\
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
    \ ::std::make_unsigned<T>::type>(x));\n  }\n}\n\n\n#line 15 \"tools/li_chao_segtree.hpp\"\
    \n\nnamespace tools {\n  template <typename T, typename Compare = ::std::less<T>>\n\
    \  class li_chao_segtree {\n  private:\n    Compare m_comp;\n    ::std::vector<T>\
    \ m_xs;\n    ::std::size_t m_height;\n    ::std::vector<::std::optional<::std::pair<T,\
    \ T>>> m_nodes;\n\n    ::std::size_t capacity() const {\n      return this->m_nodes.size()\
    \ / 2;\n    }\n\n  public:\n    template <typename Iterator>\n    li_chao_segtree(const\
    \ Iterator& begin, const Iterator& end, const Compare& comp) :\n      m_comp(comp),\n\
    \      m_xs(begin, end),\n      m_height(::tools::ceil_log2(this->m_xs.size())),\n\
    \      m_nodes(::tools::pow2(this->m_height + 1)) {\n      assert(::std::is_sorted(this->m_xs.begin(),\
    \ this->m_xs.end()));\n      const ::std::size_t n = this->m_xs.size();\n    \
    \  this->m_xs.resize(this->capacity() + 1);\n      ::std::iota(this->m_xs.begin()\
    \ + n, this->m_xs.end(), this->m_xs[n - 1] + 1);\n    }\n    template <typename\
    \ Iterator>\n    li_chao_segtree(const Iterator& begin, const Iterator& end) :\n\
    \      li_chao_segtree(begin, end, Compare()) {\n    }\n\n    li_chao_segtree()\
    \ = default;\n    li_chao_segtree(const ::tools::li_chao_segtree<T, Compare>&)\
    \ = default;\n    li_chao_segtree(::tools::li_chao_segtree<T, Compare>&&) = default;\n\
    \    ~li_chao_segtree() = default;\n    ::tools::li_chao_segtree<T, Compare>&\
    \ operator=(const ::tools::li_chao_segtree<T, Compare>&) = default;\n    ::tools::li_chao_segtree<T,\
    \ Compare>& operator=(::tools::li_chao_segtree<T, Compare>&&) = default;\n\n \
    \   void add(T fa, T fb) {\n      ::std::size_t node_id = 1;\n      ::std::size_t\
    \ l = 0;\n      ::std::size_t r = this->capacity();\n      while (node_id < this->m_nodes.size())\
    \ {\n        if (!this->m_nodes[node_id].has_value()) {\n          this->m_nodes[node_id]\
    \ = ::std::make_optional(::std::make_pair(fa, fb));\n          return;\n     \
    \   }\n        const ::std::size_t m = (l + r) / 2;\n        auto& [ga, gb] =\
    \ *this->m_nodes[node_id];\n        bool greater_l = this->m_comp(ga * this->m_xs[l]\
    \ + gb, fa * this->m_xs[l] + fb);\n        bool greater_m = this->m_comp(ga *\
    \ this->m_xs[m] + gb, fa * this->m_xs[m] + fb);\n        bool greater_r = this->m_comp(ga\
    \ * this->m_xs[r] + gb, fa * this->m_xs[r] + fb);\n        if (greater_l == greater_m\
    \ && greater_m == greater_r) {\n          if (greater_l) {\n            ::std::swap(fa,\
    \ ga);\n            ::std::swap(fb, gb);\n          }\n          return;\n   \
    \     }\n        if (greater_m) {\n          ::std::swap(fa, ga);\n          ::std::swap(fb,\
    \ gb);\n          greater_l = !greater_l;\n          greater_m = !greater_m;\n\
    \          greater_r = !greater_r;\n        }\n        if (greater_l) {\n    \
    \      node_id = node_id * 2;\n          r = m;\n        } else {\n          node_id\
    \ = node_id * 2 + 1;\n          l = m;\n        }\n      }\n    }\n\n    T query(const\
    \ T& x) const {\n      assert(this->m_nodes[1].has_value());\n\n      const auto\
    \ it = ::std::lower_bound(this->m_xs.begin(), this->m_xs.end(), x);\n      assert(*it\
    \ == x);\n      const ::std::size_t node_id = this->capacity() + ::std::distance(this->m_xs.begin(),\
    \ it);\n\n      ::std::optional<T> answer;\n      for (::std::size_t h = this->m_height\
    \ + 1; h --> 0 && this->m_nodes[node_id >> h].has_value();) {\n        const auto&\
    \ [fa, fb] = *this->m_nodes[node_id >> h];\n        if (!answer.has_value() ||\
    \ this->m_comp(*answer, fa * x + fb)) {\n          answer = ::std::make_optional(fa\
    \ * x + fb);\n        }\n      }\n      \n      return *answer;\n    }\n  };\n\
    }\n\n\n#line 6 \"tests/li_chao_segtree.test.cpp\"\n\nusing i64 = std::int_fast64_t;\n\
    \nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  i64 N, Q;\n  std::cin >> N >> Q;\n  std::vector<i64> a(N), b(N);\n  for (i64\
    \ i = 0; i < N; ++i) {\n    std::cin >> a[i] >> b[i];\n  }\n  std::vector<std::tuple<i64,\
    \ i64, i64>> queries(Q);\n  for (i64 i = 0; i < Q; ++i) {\n    std::cin >> std::get<0>(queries[i]);\n\
    \    if (std::get<0>(queries[i]) == 0) {\n      std::cin >> std::get<1>(queries[i])\
    \ >> std::get<2>(queries[i]);\n    } else {\n      std::cin >> std::get<1>(queries[i]);\n\
    \    }\n  }\n\n  std::vector<i64> x;\n  for (const auto& [t, p, _] : queries)\
    \ {\n    if (t == 1) {\n      x.push_back(p);\n    }\n  }\n  std::sort(x.begin(),\
    \ x.end());\n  x.erase(std::unique(x.begin(), x.end()), x.end());\n  tools::li_chao_segtree<i64,\
    \ std::greater<i64>> seg(x.begin(), x.end());\n\n  for (i64 i = 0; i < N; ++i)\
    \ {\n    seg.add(a[i], b[i]);\n  }\n  for (const auto& [t, q1, q2] : queries)\
    \ {\n    if (t == 0) {\n      seg.add(q1, q2);\n    } else {\n      std::cout\
    \ << seg.query(q1) << '\\n';\n    }\n  }\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/line_add_get_min\"\n\n\
    #include <cstdint>\n#include <iostream>\n#include \"tools/li_chao_segtree.hpp\"\
    \n\nusing i64 = std::int_fast64_t;\n\nint main() {\n  std::cin.tie(nullptr);\n\
    \  std::ios_base::sync_with_stdio(false);\n\n  i64 N, Q;\n  std::cin >> N >> Q;\n\
    \  std::vector<i64> a(N), b(N);\n  for (i64 i = 0; i < N; ++i) {\n    std::cin\
    \ >> a[i] >> b[i];\n  }\n  std::vector<std::tuple<i64, i64, i64>> queries(Q);\n\
    \  for (i64 i = 0; i < Q; ++i) {\n    std::cin >> std::get<0>(queries[i]);\n \
    \   if (std::get<0>(queries[i]) == 0) {\n      std::cin >> std::get<1>(queries[i])\
    \ >> std::get<2>(queries[i]);\n    } else {\n      std::cin >> std::get<1>(queries[i]);\n\
    \    }\n  }\n\n  std::vector<i64> x;\n  for (const auto& [t, p, _] : queries)\
    \ {\n    if (t == 1) {\n      x.push_back(p);\n    }\n  }\n  std::sort(x.begin(),\
    \ x.end());\n  x.erase(std::unique(x.begin(), x.end()), x.end());\n  tools::li_chao_segtree<i64,\
    \ std::greater<i64>> seg(x.begin(), x.end());\n\n  for (i64 i = 0; i < N; ++i)\
    \ {\n    seg.add(a[i], b[i]);\n  }\n  for (const auto& [t, q1, q2] : queries)\
    \ {\n    if (t == 0) {\n      seg.add(q1, q2);\n    } else {\n      std::cout\
    \ << seg.query(q1) << '\\n';\n    }\n  }\n  return 0;\n}\n"
  dependsOn:
  - tools/li_chao_segtree.hpp
  - tools/ceil_log2.hpp
  - tools/pow2.hpp
  isVerificationFile: true
  path: tests/li_chao_segtree.test.cpp
  requiredBy: []
  timestamp: '2021-11-27 16:26:56+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/li_chao_segtree.test.cpp
layout: document
redirect_from:
- /verify/tests/li_chao_segtree.test.cpp
- /verify/tests/li_chao_segtree.test.cpp.html
title: tests/li_chao_segtree.test.cpp
---
