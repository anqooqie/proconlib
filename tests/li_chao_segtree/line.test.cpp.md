---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/ceil_log2.hpp
    title: $\left\lceil \log_2(x) \right\rceil$
  - icon: ':heavy_check_mark:'
    path: tools/floor_log2.hpp
    title: $\left\lfloor \log_2(x) \right\rfloor$
  - icon: ':heavy_check_mark:'
    path: tools/li_chao_segtree.hpp
    title: Li Chao segment tree
  - icon: ':heavy_check_mark:'
    path: tools/lower_bound.hpp
    title: std::lower_bound, but returns index
  - icon: ':heavy_check_mark:'
    path: tools/popcount.hpp
    title: Popcount
  - icon: ':heavy_check_mark:'
    path: tools/pow2.hpp
    title: $2^x$
  - icon: ':heavy_check_mark:'
    path: tools/ssize.hpp
    title: Polyfill of std::ssize
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
  bundledCode: "#line 1 \"tests/li_chao_segtree/line.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/line_add_get_min\"\n\n#include <iostream>\n#include\
    \ <vector>\n#include <tuple>\n#include <algorithm>\n#line 1 \"tools/li_chao_segtree.hpp\"\
    \n\n\n\n#line 5 \"tools/li_chao_segtree.hpp\"\n#include <cstddef>\n#include <utility>\n\
    #include <limits>\n#include <cassert>\n#line 10 \"tools/li_chao_segtree.hpp\"\n\
    #include <numeric>\n#include <iterator>\n#line 1 \"tools/pow2.hpp\"\n\n\n\n#include\
    \ <type_traits>\n#line 6 \"tools/pow2.hpp\"\n\nnamespace tools {\n\n  template\
    \ <typename T, typename ::std::enable_if<::std::is_unsigned<T>::value, ::std::nullptr_t>::type\
    \ = nullptr>\n  constexpr T pow2(const T x) {\n    return static_cast<T>(1) <<\
    \ x;\n  }\n\n  template <typename T, typename ::std::enable_if<::std::is_signed<T>::value,\
    \ ::std::nullptr_t>::type = nullptr>\n  constexpr T pow2(const T x) {\n    return\
    \ static_cast<T>(static_cast<typename ::std::make_unsigned<T>::type>(1) << static_cast<typename\
    \ ::std::make_unsigned<T>::type>(x));\n  }\n}\n\n\n#line 1 \"tools/floor_log2.hpp\"\
    \n\n\n\n#line 1 \"tools/popcount.hpp\"\n\n\n\n#line 7 \"tools/popcount.hpp\"\n\
    #include <cstdint>\n\nnamespace tools {\n\n  template <typename T>\n  T popcount(T\
    \ x) {\n    static_assert(::std::is_integral_v<T>);\n    assert(x >= 0);\n   \
    \ if constexpr (::std::is_signed_v<T>) {\n      return static_cast<T>(::tools::popcount<::std::make_unsigned_t<T>>(x));\n\
    \    } else {\n      const auto log2 = [](const int w) {\n        if (w == 8)\
    \ return 3;\n        if (w == 16) return 4;\n        if (w == 32) return 5;\n\
    \        if (w == 64) return 6;\n        return -1;\n      };\n      static_assert(log2(::std::numeric_limits<T>::digits)\
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
    \ 1 \"tools/ceil_log2.hpp\"\n\n\n\n#line 8 \"tools/ceil_log2.hpp\"\n#include <array>\n\
    #line 10 \"tools/ceil_log2.hpp\"\n\n// Source: https://stackoverflow.com/questions/3272424/compute-fast-log-base-2-ceiling/15327567#15327567\n\
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
    \n#line 1 \"tools/lower_bound.hpp\"\n\n\n\n#line 6 \"tools/lower_bound.hpp\"\n\
    \nnamespace tools {\n\n  template <class ForwardIterator, class T>\n  auto lower_bound(ForwardIterator\
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
    \ :\n      m_maximal(maximal),\n      m_xs(begin, end),\n      m_height(this->m_xs.empty()\
    \ ? ::std::numeric_limits<T>::min() : ::tools::ceil_log2(this->m_xs.size())),\n\
    \      m_nodes(this->m_xs.empty() ? 0 : ::tools::pow2(this->m_height + 1), ::std::pair<T,\
    \ T>(0, maximal ? ::std::numeric_limits<T>::min() : ::std::numeric_limits<T>::max()))\
    \ {\n      if (this->m_xs.empty()) return;\n\n      assert(::std::is_sorted(this->m_xs.begin(),\
    \ this->m_xs.end()));\n      const ::std::size_t n = this->m_xs.size();\n    \
    \  this->m_xs.resize(this->capacity() + 1);\n      ::std::iota(this->m_xs.begin()\
    \ + n, this->m_xs.end(), this->m_xs[n - 1] + 1);\n    }\n\n    li_chao_segtree()\
    \ = default;\n    li_chao_segtree(const ::tools::li_chao_segtree<T>&) = default;\n\
    \    li_chao_segtree(::tools::li_chao_segtree<T>&&) = default;\n    ~li_chao_segtree()\
    \ = default;\n    ::tools::li_chao_segtree<T>& operator=(const ::tools::li_chao_segtree<T>&)\
    \ = default;\n    ::tools::li_chao_segtree<T>& operator=(::tools::li_chao_segtree<T>&&)\
    \ = default;\n\n    void add(const T& a, const T& b) {\n      if (this->m_xs.empty())\
    \ return;\n\n      this->add_impl(a, b, 1);\n    }\n\n    void add(const T& a,\
    \ const T& b, const T& l, const T& r) {\n      if (this->m_xs.empty()) return;\n\
    \n      auto l_id = ::tools::lower_bound(this->m_xs.begin(), ::std::prev(this->m_xs.end()),\
    \ l);\n      auto r_id = ::tools::lower_bound(this->m_xs.begin(), ::std::prev(this->m_xs.end()),\
    \ r);\n      if (r_id == ::tools::ssize(this->m_xs) - 1 || r < this->m_xs[r_id])\
    \ --r_id;\n      if (r_id < l_id) return;\n      l_id += this->capacity();\n \
    \     r_id += this->capacity() + 1;\n\n      for (; l_id < r_id; l_id >>= 1, r_id\
    \ >>= 1) {\n        if (l_id & 1) {\n          this->add_impl(a, b, l_id);\n \
    \         ++l_id;\n        }\n        if (r_id & 1) {\n          --r_id;\n   \
    \       this->add_impl(a, b, r_id);\n        }\n      }\n    }\n\n    T query(const\
    \ T& x) const {\n      const auto it = ::std::lower_bound(this->m_xs.begin(),\
    \ this->m_xs.end(), x);\n      assert(*it == x);\n      const ::std::size_t node_id\
    \ = this->capacity() + ::std::distance(this->m_xs.begin(), it);\n\n      T answer\
    \ = this->m_maximal ? ::std::numeric_limits<T>::min() : ::std::numeric_limits<T>::max();\n\
    \      for (::std::size_t h = this->m_height + 1; h --> 0;) {\n        const auto&\
    \ [fa, fb] = this->m_nodes[node_id >> h];\n        if (this->comp(answer, fa *\
    \ x + fb)) {\n          answer = fa * x + fb;\n        }\n      }\n      \n  \
    \    return answer;\n    }\n  };\n}\n\n\n#line 8 \"tests/li_chao_segtree/line.test.cpp\"\
    \n\nusing ll = long long;\n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  ll N, Q;\n  std::cin >> N >> Q;\n  std::vector<ll> a(N), b(N);\n  for (ll\
    \ i = 0; i < N; ++i) {\n    std::cin >> a[i] >> b[i];\n  }\n  std::vector<std::tuple<ll,\
    \ ll, ll>> queries(Q);\n  for (ll i = 0; i < Q; ++i) {\n    std::cin >> std::get<0>(queries[i]);\n\
    \    if (std::get<0>(queries[i]) == 0) {\n      std::cin >> std::get<1>(queries[i])\
    \ >> std::get<2>(queries[i]);\n    } else {\n      std::cin >> std::get<1>(queries[i]);\n\
    \    }\n  }\n\n  std::vector<ll> x;\n  for (const auto& [t, p, _] : queries) {\n\
    \    if (t == 1) {\n      x.push_back(p);\n    }\n  }\n  std::sort(x.begin(),\
    \ x.end());\n  x.erase(std::unique(x.begin(), x.end()), x.end());\n  tools::li_chao_segtree<ll>\
    \ seg(x.begin(), x.end(), false);\n\n  for (ll i = 0; i < N; ++i) {\n    seg.add(a[i],\
    \ b[i]);\n  }\n  for (const auto& [t, q1, q2] : queries) {\n    if (t == 0) {\n\
    \      seg.add(q1, q2);\n    } else {\n      std::cout << seg.query(q1) << '\\\
    n';\n    }\n  }\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/line_add_get_min\"\n\n\
    #include <iostream>\n#include <vector>\n#include <tuple>\n#include <algorithm>\n\
    #include \"tools/li_chao_segtree.hpp\"\n\nusing ll = long long;\n\nint main()\
    \ {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\n  ll\
    \ N, Q;\n  std::cin >> N >> Q;\n  std::vector<ll> a(N), b(N);\n  for (ll i = 0;\
    \ i < N; ++i) {\n    std::cin >> a[i] >> b[i];\n  }\n  std::vector<std::tuple<ll,\
    \ ll, ll>> queries(Q);\n  for (ll i = 0; i < Q; ++i) {\n    std::cin >> std::get<0>(queries[i]);\n\
    \    if (std::get<0>(queries[i]) == 0) {\n      std::cin >> std::get<1>(queries[i])\
    \ >> std::get<2>(queries[i]);\n    } else {\n      std::cin >> std::get<1>(queries[i]);\n\
    \    }\n  }\n\n  std::vector<ll> x;\n  for (const auto& [t, p, _] : queries) {\n\
    \    if (t == 1) {\n      x.push_back(p);\n    }\n  }\n  std::sort(x.begin(),\
    \ x.end());\n  x.erase(std::unique(x.begin(), x.end()), x.end());\n  tools::li_chao_segtree<ll>\
    \ seg(x.begin(), x.end(), false);\n\n  for (ll i = 0; i < N; ++i) {\n    seg.add(a[i],\
    \ b[i]);\n  }\n  for (const auto& [t, q1, q2] : queries) {\n    if (t == 0) {\n\
    \      seg.add(q1, q2);\n    } else {\n      std::cout << seg.query(q1) << '\\\
    n';\n    }\n  }\n  return 0;\n}\n"
  dependsOn:
  - tools/li_chao_segtree.hpp
  - tools/pow2.hpp
  - tools/floor_log2.hpp
  - tools/popcount.hpp
  - tools/ceil_log2.hpp
  - tools/lower_bound.hpp
  - tools/ssize.hpp
  isVerificationFile: true
  path: tests/li_chao_segtree/line.test.cpp
  requiredBy: []
  timestamp: '2022-10-08 19:22:04+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/li_chao_segtree/line.test.cpp
layout: document
redirect_from:
- /verify/tests/li_chao_segtree/line.test.cpp
- /verify/tests/li_chao_segtree/line.test.cpp.html
title: tests/li_chao_segtree/line.test.cpp
---
