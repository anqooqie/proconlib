---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/ceil_log2.hpp
    title: $\left\lceil \log_2(x) \right\rceil$
  - icon: ':heavy_check_mark:'
    path: tools/pow2.hpp
    title: $2^x$
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/li_chao_segtree.test.cpp
    title: tests/li_chao_segtree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/li_chao_segtree.hpp\"\n\n\n\n#include <functional>\n\
    #include <vector>\n#include <cstddef>\n#include <optional>\n#include <utility>\n\
    #include <algorithm>\n#include <cassert>\n#include <numeric>\n#include <iterator>\n\
    #line 1 \"tools/ceil_log2.hpp\"\n\n\n\n#include <cstdint>\n\n// Source: https://stackoverflow.com/questions/3272424/compute-fast-log-base-2-ceiling/15327567#15327567\n\
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
    }\n\n\n"
  code: "#ifndef TOOLS_LI_CHAO_SEGTREE_HPP\n#define TOOLS_LI_CHAO_SEGTREE_HPP\n\n\
    #include <functional>\n#include <vector>\n#include <cstddef>\n#include <optional>\n\
    #include <utility>\n#include <algorithm>\n#include <cassert>\n#include <numeric>\n\
    #include <iterator>\n#include \"tools/ceil_log2.hpp\"\n#include \"tools/pow2.hpp\"\
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
    }\n\n#endif\n"
  dependsOn:
  - tools/ceil_log2.hpp
  - tools/pow2.hpp
  isVerificationFile: false
  path: tools/li_chao_segtree.hpp
  requiredBy: []
  timestamp: '2021-11-27 16:26:56+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/li_chao_segtree.test.cpp
documentation_of: tools/li_chao_segtree.hpp
layout: document
title: Li Chao segment tree
---

It is a data structure which supports the following operations.

- Add a straight line $y = ax + b$.
- Find the maximal $y$ at given $x$.

It is required to give a predefined list of possible $x$s to a constructor.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
template <typename Iterator>
li_chao_segtree<T, Compare = std::less<T>> segtree(Iterator begin, Iterator end);

template <typename Iterator>
li_chao_segtree<T, Compare = std::less<T>> segtree(Iterator begin, Iterator end, Compare comp);
```

It creates an empty set of straight lines.
$\[mathrm{begin}, \mathrm{end})$ represents a list of possible $x$s.
If `std::greater<T>()` are given as `comp`, it will be able to find the minimal $y$ instead of the maximal.

### Constraints
- $\mathrm{end} - \mathrm{begin} \geq 1$
- $\[mathrm{begin}, \mathrm{end})$ are sorted.

### Time Complexity
- $O(n)$ where $n$ is $\mathrm{end} - \mathrm{begin}$

## add
```cpp
void segtree.add(T a, T b);
```

It adds a straight line $y = ax + b$ to the set.

### Constraints
- None

### Time Complexity
- $O(\log n)$ where $n$ is $\mathrm{end} - \mathrm{begin}$

## query
```cpp
T segtree.query(T x);
```

It returns the maximal $y$ at given $x$.

### Constraints
- $x$ is in the predefined list of possible parameters.

### Time Complexity
- $O(\log n)$ where $n$ is $\mathrm{end} - \mathrm{begin}$
