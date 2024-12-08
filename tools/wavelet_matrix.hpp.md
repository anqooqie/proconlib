---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/bit_vector.hpp
    title: Bit vector
  - icon: ':heavy_check_mark:'
    path: tools/floor_log2.hpp
    title: $\left\lfloor \log_2(x) \right\rfloor$
  - icon: ':heavy_check_mark:'
    path: tools/less_by_first.hpp
    title: std::less by first
  - icon: ':heavy_check_mark:'
    path: tools/lower_bound.hpp
    title: std::lower_bound, but returns index
  - icon: ':heavy_check_mark:'
    path: tools/popcount.hpp
    title: Popcount
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: tools/range_count_distinct.hpp
    title: Range count distinct
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/range_count_distinct.test.cpp
    title: tests/range_count_distinct.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/wavelet_matrix/kth_smallest.test.cpp
    title: tests/wavelet_matrix/kth_smallest.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/wavelet_matrix/next_points.test.cpp
    title: tests/wavelet_matrix/next_points.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/wavelet_matrix/prev_points.test.cpp
    title: tests/wavelet_matrix/prev_points.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/wavelet_matrix/range_freq.test.cpp
    title: tests/wavelet_matrix/range_freq.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/wavelet_matrix/range_prod.test.cpp
    title: tests/wavelet_matrix/range_prod.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/wavelet_matrix.hpp\"\n\n\n\n#include <vector>\n#include\
    \ <utility>\n#include <cstddef>\n#include <cassert>\n#include <algorithm>\n#include\
    \ <iterator>\n#include <array>\n#include <tuple>\n#include <optional>\n#line 1\
    \ \"tools/bit_vector.hpp\"\n\n\n\n#include <cstdint>\n#line 6 \"tools/bit_vector.hpp\"\
    \n#include <immintrin.h>\n\n// Source: https://nyaannyaan.github.io/library/data-structure-2d/wavelet-matrix.hpp.html\n\
    // License: CC0 1.0 Universal\n// Author: Nyaan\n\nnamespace tools {\n  class\
    \ bit_vector {\n  private:\n    using u32 = ::std::uint32_t;\n    using i64 =\
    \ ::std::int64_t;\n    using u64 = ::std::uint64_t;\n\n    static constexpr u32\
    \ w = 64;\n    ::std::vector<u64> m_block;\n    ::std::vector<u32> m_count;\n\
    \    u32 m_size, m_zeros;\n\n  public:\n    bit_vector() {}\n    explicit bit_vector(int\
    \ _n) { init(_n); }\n    __attribute__((optimize(\"O3\", \"unroll-loops\"))) void\
    \ init(int _n) {\n      m_size = m_zeros = _n;\n      m_block.resize(m_size /\
    \ w + 1, 0);\n      m_count.resize(m_block.size(), 0);\n    }\n\n    u32 size()\
    \ const { return m_size; }\n    inline u32 get(u32 i) const { return u32(m_block[i\
    \ / w] >> (i % w)) & 1u; }\n    inline void set(u32 i) { m_block[i / w] |= 1LL\
    \ << (i % w); }\n\n    __attribute__((target(\"popcnt\"))) void build() {\n  \
    \    for (u32 i = 1; i < m_block.size(); ++i)\n        m_count[i] = m_count[i\
    \ - 1] + _mm_popcnt_u64(m_block[i - 1]);\n      m_zeros = rank0(m_size);\n   \
    \ }\n\n    u32 zeros() const { return m_zeros; }\n    inline u32 rank0(u32 i)\
    \ const { return i - rank1(i); }\n    __attribute__((target(\"bmi2,popcnt\")))\
    \ inline u32 rank1(u32 i) const {\n      return m_count[i / w] + _mm_popcnt_u64(_bzhi_u64(m_block[i\
    \ / w], i % w));\n    }\n  };\n}\n\n\n#line 1 \"tools/lower_bound.hpp\"\n\n\n\n\
    #line 6 \"tools/lower_bound.hpp\"\n\nnamespace tools {\n\n  template <class ForwardIterator,\
    \ class T>\n  auto lower_bound(ForwardIterator first, ForwardIterator last, const\
    \ T& value) {\n    return ::std::distance(first, ::std::lower_bound(first, last,\
    \ value));\n  }\n\n  template <class ForwardIterator, class T, class Compare>\n\
    \  auto lower_bound(ForwardIterator first, ForwardIterator last, const T& value,\
    \ Compare comp) {\n    return ::std::distance(first, ::std::lower_bound(first,\
    \ last, value, comp));\n  }\n}\n\n\n#line 1 \"tools/less_by_first.hpp\"\n\n\n\n\
    #line 5 \"tools/less_by_first.hpp\"\n\nnamespace tools {\n\n  class less_by_first\
    \ {\n  public:\n    template <class T1, class T2>\n    bool operator()(const ::std::pair<T1,\
    \ T2>& x, const ::std::pair<T1, T2>& y) const {\n      return x.first < y.first;\n\
    \    }\n  };\n}\n\n\n#line 1 \"tools/floor_log2.hpp\"\n\n\n\n#include <type_traits>\n\
    #line 6 \"tools/floor_log2.hpp\"\n#include <limits>\n#line 1 \"tools/popcount.hpp\"\
    \n\n\n\n#line 8 \"tools/popcount.hpp\"\n\nnamespace tools {\n\n  template <typename\
    \ T>\n  T popcount(T x) {\n    static_assert(::std::is_integral_v<T>);\n    assert(x\
    \ >= 0);\n    if constexpr (::std::is_signed_v<T>) {\n      return static_cast<T>(::tools::popcount<::std::make_unsigned_t<T>>(x));\n\
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
    \ 17 \"tools/wavelet_matrix.hpp\"\n\nnamespace tools {\n  template <typename T>\n\
    \  class wavelet_matrix {\n  private:\n    ::std::vector<::std::pair<T, T>> m_ps;\n\
    \    ::std::vector<::std::pair<T, ::std::size_t>> m_xs;\n    ::std::vector<T>\
    \ m_ys;\n    ::std::vector<::std::size_t> m_is;\n    ::std::vector<::tools::bit_vector>\
    \ m_bvs;\n\n    ::std::size_t iid(const ::std::size_t i) const {\n      return\
    \ ::tools::lower_bound(this->m_xs.begin(), this->m_xs.end(), ::std::make_pair(this->m_ps[i].first,\
    \ i));\n    }\n    ::std::size_t xid(const T& x) const {\n      return ::tools::lower_bound(this->m_xs.begin(),\
    \ this->m_xs.end(), ::std::make_pair(x, ::std::size_t{}), ::tools::less_by_first());\n\
    \    }\n    ::std::size_t yid(const T& y) const {\n      return ::tools::lower_bound(this->m_ys.begin(),\
    \ this->m_ys.end(), y);\n    }\n    ::std::size_t lg() const {\n      return this->m_bvs.size();\n\
    \    }\n    bool built() const {\n      return this->lg() > 0;\n    }\n\n  public:\n\
    \    wavelet_matrix() = default;\n    wavelet_matrix(const ::tools::wavelet_matrix<T>&)\
    \ = default;\n    wavelet_matrix(::tools::wavelet_matrix<T>&&) = default;\n  \
    \  ~wavelet_matrix() = default;\n    ::tools::wavelet_matrix<T>& operator=(const\
    \ ::tools::wavelet_matrix<T>&) = default;\n    ::tools::wavelet_matrix<T>& operator=(::tools::wavelet_matrix<T>&&)\
    \ = default;\n\n    ::std::size_t size() const {\n      return this->m_ps.size();\n\
    \    }\n\n    ::std::size_t add_point(const T& x, const T& y) {\n      assert(!this->built());\n\
    \      this->m_ps.emplace_back(x, y);\n      return this->size() - 1;\n    }\n\
    \n    ::std::pair<T, T> get_point(const ::std::size_t i) const {\n      assert(i\
    \ < this->size());\n      return this->m_ps[i];\n    }\n\n    const ::std::vector<::std::pair<T,\
    \ T>>& points() const {\n      return this->m_ps;\n    }\n\n    ::std::vector<::std::vector<::std::size_t>>\
    \ build() {\n      assert(!this->built());\n\n      this->m_xs.reserve(this->size());\n\
    \      for (::std::size_t i = 0; i < this->size(); ++i) {\n        this->m_xs.emplace_back(this->m_ps[i].first,\
    \ i);\n      }\n      ::std::sort(this->m_xs.begin(), this->m_xs.end());\n\n \
    \     this->m_ys.reserve(this->size());\n      ::std::transform(this->m_ps.begin(),\
    \ this->m_ps.end(), ::std::back_inserter(this->m_ys), [](const auto& p) { return\
    \ p.second; });\n      ::std::sort(this->m_ys.begin(), this->m_ys.end());\n  \
    \    this->m_ys.erase(::std::unique(this->m_ys.begin(), this->m_ys.end()), this->m_ys.end());\n\
    \n      const auto n = ::std::max<::std::size_t>(this->size(), 1);\n      this->m_bvs.assign(::tools::floor_log2(::std::max<::std::size_t>(this->m_ys.size(),\
    \ 1)) + 1, ::tools::bit_vector(n));\n\n      ::std::vector<::std::size_t> cur;\n\
    \      cur.reserve(n);\n      ::std::transform(this->m_xs.begin(), this->m_xs.end(),\
    \ ::std::back_inserter(cur), [&](const auto& p) { return this->yid(this->m_ps[p.second].second);\
    \ });\n      cur.resize(n);\n      ::std::vector<::std::size_t> nxt(n);\n\n  \
    \    auto res = ::std::vector(this->lg() + 1, ::std::vector<::std::size_t>(n));\n\
    \      ::std::transform(this->m_xs.begin(), this->m_xs.end(), res.back().begin(),\
    \ [&](const auto& p) { return p.second; });\n\n      for (::std::size_t h = this->lg();\
    \ h --> 0;) {\n        for (::std::size_t i = 0; i < n; ++i) {\n          if ((cur[i]\
    \ >> h) & 1) {\n            this->m_bvs[h].set(i);\n          }\n        }\n \
    \       this->m_bvs[h].build();\n        ::std::array<::std::size_t, 2> offsets\
    \ = {0, this->m_bvs[h].zeros()};\n        for (::std::size_t i = 0; i < n; ++i)\
    \ {\n          auto& offset = offsets[this->m_bvs[h].get(i)];\n          nxt[offset]\
    \ = cur[i];\n          res[h][offset] = res[h + 1][i];\n          ++offset;\n\
    \        }\n        ::std::swap(cur, nxt);\n      }\n\n      this->m_is = res.front();\n\
    \      res.pop_back();\n      return res;\n    }\n\n    ::std::vector<::std::pair<::std::size_t,\
    \ ::std::size_t>> apply(::std::size_t i) const {\n      assert(this->built());\n\
    \      assert(i < this->size());\n\n      ::std::vector<::std::pair<::std::size_t,\
    \ ::std::size_t>> res(this->lg());\n      i = this->iid(i);\n      for (::std::size_t\
    \ h = this->lg(); h --> 0;) {\n        i = this->m_bvs[h].get(i) ? this->m_bvs[h].zeros()\
    \ + this->m_bvs[h].rank1(i) : this->m_bvs[h].rank0(i);\n        res[h] = ::std::make_pair(h,\
    \ i);\n      }\n      return res;\n    }\n\n    ::std::size_t kth_smallest(const\
    \ T& l, const T& r, ::std::size_t k) const {\n      assert(this->built());\n \
    \     assert(l <= r);\n\n      auto lid = this->xid(l);\n      auto rid = this->xid(r);\n\
    \n      assert(k < rid - lid);\n\n      for (::std::size_t h = this->lg(); h -->\
    \ 0;) {\n        const auto l0 = this->m_bvs[h].rank0(lid);\n        const auto\
    \ r0 = this->m_bvs[h].rank0(rid);\n        if (k < r0 - l0) {\n          lid =\
    \ l0;\n          rid = r0;\n        } else {\n          k -= r0 - l0;\n      \
    \    lid += this->m_bvs[h].zeros() - l0;\n          rid += this->m_bvs[h].zeros()\
    \ - r0;\n        }\n      }\n\n      return this->m_is[lid + k];\n    }\n\n  \
    \  ::std::size_t kth_largest(const T& l, const T& r, const ::std::size_t k) const\
    \ {\n      assert(this->built());\n      assert(l <= r);\n\n      const auto lid\
    \ = this->xid(l);\n      const auto rid = this->xid(r);\n\n      assert(k < rid\
    \ - lid);\n\n      return this->kth_smallest(l, r, rid - lid - k - 1);\n    }\n\
    \n    ::std::vector<::std::tuple<::std::size_t, ::std::size_t, ::std::size_t>>\
    \ range_prod(const T& l, const T& r, const T& u) const {\n      assert(this->built());\n\
    \      assert(l <= r);\n\n      auto lid = this->xid(l);\n      auto rid = this->xid(r);\n\
    \      const auto uid = this->yid(u);\n\n      ::std::vector<::std::tuple<::std::size_t,\
    \ ::std::size_t, ::std::size_t>> res(this->lg());\n      for (::std::size_t h\
    \ = this->lg(); h --> 0;) {\n        const auto l0 = this->m_bvs[h].rank0(lid);\n\
    \        const auto r0 = this->m_bvs[h].rank0(rid);\n        if ((uid >> h) &\
    \ 1) {\n          res[h] = ::std::make_tuple(h, l0, r0);\n          lid += this->m_bvs[h].zeros()\
    \ - l0;\n          rid += this->m_bvs[h].zeros() - r0;\n        } else {\n   \
    \       res[h] = ::std::make_tuple(h, 0, 0);\n          lid = l0;\n          rid\
    \ = r0;\n        }\n      }\n      return res;\n    }\n\n    ::std::size_t range_freq(const\
    \ T& l, const T& r) const {\n      assert(this->built());\n      assert(l <= r);\n\
    \n      return this->xid(r) - this->xid(l);\n    }\n\n    ::std::size_t range_freq(const\
    \ T& l, const T& r, const T& u) const {\n      assert(this->built());\n      assert(l\
    \ <= r);\n\n      auto lid = this->xid(l);\n      auto rid = this->xid(r);\n \
    \     const auto uid = this->yid(u);\n\n      ::std::size_t res = 0;\n      for\
    \ (::std::size_t h = this->lg(); h --> 0;) {\n        const auto l0 = this->m_bvs[h].rank0(lid);\n\
    \        const auto r0 = this->m_bvs[h].rank0(rid);\n        if ((uid >> h) &\
    \ 1) {\n          res += r0 - l0;\n          lid += this->m_bvs[h].zeros() - l0;\n\
    \          rid += this->m_bvs[h].zeros() - r0;\n        } else {\n          lid\
    \ = l0;\n          rid = r0;\n        }\n      }\n      return res;\n    }\n\n\
    \    ::std::size_t range_freq(const T& l, const T& r, const T& d, const T& u)\
    \ const {\n      assert(this->built());\n      assert(l <= r);\n      assert(d\
    \ <= u);\n\n      return this->range_freq(l, r, u) - this->range_freq(l, r, d);\n\
    \    }\n\n    ::std::optional<T> prev_value(const T& l, const T& r, const T& u)\
    \ const {\n      assert(this->built());\n      assert(l <= r);\n\n      const\
    \ auto k = this->range_freq(l, r, u);\n      return k == 0 ? ::std::nullopt :\
    \ ::std::make_optional(this->m_ps[this->kth_smallest(l, r, k - 1)].second);\n\
    \    }\n\n    ::std::optional<T> next_value(const T& l, const T& r, const T& d)\
    \ const {\n      assert(this->built());\n      assert(l <= r);\n\n      const\
    \ auto k = this->range_freq(l, r, d);\n      return k == this->range_freq(l, r)\
    \ ? ::std::nullopt : ::std::make_optional(this->m_ps[this->kth_smallest(l, r,\
    \ k)].second);\n    }\n\n    ::std::pair<typename ::std::vector<::std::size_t>::const_iterator,\
    \ typename ::std::vector<::std::size_t>::const_iterator> prev_points(const T&\
    \ l, const T& r, const T& u) const {\n      assert(this->built());\n      assert(l\
    \ <= r);\n\n      auto lid = this->xid(l);\n      auto rid = this->xid(r);\n \
    \     auto k = this->range_freq(l, r, u);\n      if (k == 0) return ::std::make_pair(this->m_is.cend(),\
    \ this->m_is.cend());\n      --k;\n\n      for (::std::size_t h = this->lg();\
    \ h --> 0;) {\n        const auto l0 = this->m_bvs[h].rank0(lid);\n        const\
    \ auto r0 = this->m_bvs[h].rank0(rid);\n        if (k < r0 - l0) {\n         \
    \ lid = l0;\n          rid = r0;\n        } else {\n          k -= r0 - l0;\n\
    \          lid += this->m_bvs[h].zeros() - l0;\n          rid += this->m_bvs[h].zeros()\
    \ - r0;\n        }\n      }\n\n      return ::std::make_pair(this->m_is.cbegin()\
    \ + lid, this->m_is.cbegin() + rid);\n    }\n\n    ::std::pair<typename ::std::vector<::std::size_t>::const_iterator,\
    \ typename ::std::vector<::std::size_t>::const_iterator> next_points(const T&\
    \ l, const T& r, const T& d) const {\n      assert(this->built());\n      assert(l\
    \ <= r);\n\n      auto lid = this->xid(l);\n      auto rid = this->xid(r);\n \
    \     auto k = this->range_freq(l, r, d);\n      if (k == rid - lid) return ::std::make_pair(this->m_is.cend(),\
    \ this->m_is.cend());\n\n      for (::std::size_t h = this->lg(); h --> 0;) {\n\
    \        const auto l0 = this->m_bvs[h].rank0(lid);\n        const auto r0 = this->m_bvs[h].rank0(rid);\n\
    \        if (k < r0 - l0) {\n          lid = l0;\n          rid = r0;\n      \
    \  } else {\n          k -= r0 - l0;\n          lid += this->m_bvs[h].zeros()\
    \ - l0;\n          rid += this->m_bvs[h].zeros() - r0;\n        }\n      }\n\n\
    \      return ::std::make_pair(this->m_is.cbegin() + lid, this->m_is.cbegin()\
    \ + rid);\n    }\n  };\n}\n\n\n"
  code: "#ifndef TOOLS_WAVELET_MATRIX_HPP\n#define TOOLS_WAVELET_MATRIX_HPP\n\n#include\
    \ <vector>\n#include <utility>\n#include <cstddef>\n#include <cassert>\n#include\
    \ <algorithm>\n#include <iterator>\n#include <array>\n#include <tuple>\n#include\
    \ <optional>\n#include \"tools/bit_vector.hpp\"\n#include \"tools/lower_bound.hpp\"\
    \n#include \"tools/less_by_first.hpp\"\n#include \"tools/floor_log2.hpp\"\n\n\
    namespace tools {\n  template <typename T>\n  class wavelet_matrix {\n  private:\n\
    \    ::std::vector<::std::pair<T, T>> m_ps;\n    ::std::vector<::std::pair<T,\
    \ ::std::size_t>> m_xs;\n    ::std::vector<T> m_ys;\n    ::std::vector<::std::size_t>\
    \ m_is;\n    ::std::vector<::tools::bit_vector> m_bvs;\n\n    ::std::size_t iid(const\
    \ ::std::size_t i) const {\n      return ::tools::lower_bound(this->m_xs.begin(),\
    \ this->m_xs.end(), ::std::make_pair(this->m_ps[i].first, i));\n    }\n    ::std::size_t\
    \ xid(const T& x) const {\n      return ::tools::lower_bound(this->m_xs.begin(),\
    \ this->m_xs.end(), ::std::make_pair(x, ::std::size_t{}), ::tools::less_by_first());\n\
    \    }\n    ::std::size_t yid(const T& y) const {\n      return ::tools::lower_bound(this->m_ys.begin(),\
    \ this->m_ys.end(), y);\n    }\n    ::std::size_t lg() const {\n      return this->m_bvs.size();\n\
    \    }\n    bool built() const {\n      return this->lg() > 0;\n    }\n\n  public:\n\
    \    wavelet_matrix() = default;\n    wavelet_matrix(const ::tools::wavelet_matrix<T>&)\
    \ = default;\n    wavelet_matrix(::tools::wavelet_matrix<T>&&) = default;\n  \
    \  ~wavelet_matrix() = default;\n    ::tools::wavelet_matrix<T>& operator=(const\
    \ ::tools::wavelet_matrix<T>&) = default;\n    ::tools::wavelet_matrix<T>& operator=(::tools::wavelet_matrix<T>&&)\
    \ = default;\n\n    ::std::size_t size() const {\n      return this->m_ps.size();\n\
    \    }\n\n    ::std::size_t add_point(const T& x, const T& y) {\n      assert(!this->built());\n\
    \      this->m_ps.emplace_back(x, y);\n      return this->size() - 1;\n    }\n\
    \n    ::std::pair<T, T> get_point(const ::std::size_t i) const {\n      assert(i\
    \ < this->size());\n      return this->m_ps[i];\n    }\n\n    const ::std::vector<::std::pair<T,\
    \ T>>& points() const {\n      return this->m_ps;\n    }\n\n    ::std::vector<::std::vector<::std::size_t>>\
    \ build() {\n      assert(!this->built());\n\n      this->m_xs.reserve(this->size());\n\
    \      for (::std::size_t i = 0; i < this->size(); ++i) {\n        this->m_xs.emplace_back(this->m_ps[i].first,\
    \ i);\n      }\n      ::std::sort(this->m_xs.begin(), this->m_xs.end());\n\n \
    \     this->m_ys.reserve(this->size());\n      ::std::transform(this->m_ps.begin(),\
    \ this->m_ps.end(), ::std::back_inserter(this->m_ys), [](const auto& p) { return\
    \ p.second; });\n      ::std::sort(this->m_ys.begin(), this->m_ys.end());\n  \
    \    this->m_ys.erase(::std::unique(this->m_ys.begin(), this->m_ys.end()), this->m_ys.end());\n\
    \n      const auto n = ::std::max<::std::size_t>(this->size(), 1);\n      this->m_bvs.assign(::tools::floor_log2(::std::max<::std::size_t>(this->m_ys.size(),\
    \ 1)) + 1, ::tools::bit_vector(n));\n\n      ::std::vector<::std::size_t> cur;\n\
    \      cur.reserve(n);\n      ::std::transform(this->m_xs.begin(), this->m_xs.end(),\
    \ ::std::back_inserter(cur), [&](const auto& p) { return this->yid(this->m_ps[p.second].second);\
    \ });\n      cur.resize(n);\n      ::std::vector<::std::size_t> nxt(n);\n\n  \
    \    auto res = ::std::vector(this->lg() + 1, ::std::vector<::std::size_t>(n));\n\
    \      ::std::transform(this->m_xs.begin(), this->m_xs.end(), res.back().begin(),\
    \ [&](const auto& p) { return p.second; });\n\n      for (::std::size_t h = this->lg();\
    \ h --> 0;) {\n        for (::std::size_t i = 0; i < n; ++i) {\n          if ((cur[i]\
    \ >> h) & 1) {\n            this->m_bvs[h].set(i);\n          }\n        }\n \
    \       this->m_bvs[h].build();\n        ::std::array<::std::size_t, 2> offsets\
    \ = {0, this->m_bvs[h].zeros()};\n        for (::std::size_t i = 0; i < n; ++i)\
    \ {\n          auto& offset = offsets[this->m_bvs[h].get(i)];\n          nxt[offset]\
    \ = cur[i];\n          res[h][offset] = res[h + 1][i];\n          ++offset;\n\
    \        }\n        ::std::swap(cur, nxt);\n      }\n\n      this->m_is = res.front();\n\
    \      res.pop_back();\n      return res;\n    }\n\n    ::std::vector<::std::pair<::std::size_t,\
    \ ::std::size_t>> apply(::std::size_t i) const {\n      assert(this->built());\n\
    \      assert(i < this->size());\n\n      ::std::vector<::std::pair<::std::size_t,\
    \ ::std::size_t>> res(this->lg());\n      i = this->iid(i);\n      for (::std::size_t\
    \ h = this->lg(); h --> 0;) {\n        i = this->m_bvs[h].get(i) ? this->m_bvs[h].zeros()\
    \ + this->m_bvs[h].rank1(i) : this->m_bvs[h].rank0(i);\n        res[h] = ::std::make_pair(h,\
    \ i);\n      }\n      return res;\n    }\n\n    ::std::size_t kth_smallest(const\
    \ T& l, const T& r, ::std::size_t k) const {\n      assert(this->built());\n \
    \     assert(l <= r);\n\n      auto lid = this->xid(l);\n      auto rid = this->xid(r);\n\
    \n      assert(k < rid - lid);\n\n      for (::std::size_t h = this->lg(); h -->\
    \ 0;) {\n        const auto l0 = this->m_bvs[h].rank0(lid);\n        const auto\
    \ r0 = this->m_bvs[h].rank0(rid);\n        if (k < r0 - l0) {\n          lid =\
    \ l0;\n          rid = r0;\n        } else {\n          k -= r0 - l0;\n      \
    \    lid += this->m_bvs[h].zeros() - l0;\n          rid += this->m_bvs[h].zeros()\
    \ - r0;\n        }\n      }\n\n      return this->m_is[lid + k];\n    }\n\n  \
    \  ::std::size_t kth_largest(const T& l, const T& r, const ::std::size_t k) const\
    \ {\n      assert(this->built());\n      assert(l <= r);\n\n      const auto lid\
    \ = this->xid(l);\n      const auto rid = this->xid(r);\n\n      assert(k < rid\
    \ - lid);\n\n      return this->kth_smallest(l, r, rid - lid - k - 1);\n    }\n\
    \n    ::std::vector<::std::tuple<::std::size_t, ::std::size_t, ::std::size_t>>\
    \ range_prod(const T& l, const T& r, const T& u) const {\n      assert(this->built());\n\
    \      assert(l <= r);\n\n      auto lid = this->xid(l);\n      auto rid = this->xid(r);\n\
    \      const auto uid = this->yid(u);\n\n      ::std::vector<::std::tuple<::std::size_t,\
    \ ::std::size_t, ::std::size_t>> res(this->lg());\n      for (::std::size_t h\
    \ = this->lg(); h --> 0;) {\n        const auto l0 = this->m_bvs[h].rank0(lid);\n\
    \        const auto r0 = this->m_bvs[h].rank0(rid);\n        if ((uid >> h) &\
    \ 1) {\n          res[h] = ::std::make_tuple(h, l0, r0);\n          lid += this->m_bvs[h].zeros()\
    \ - l0;\n          rid += this->m_bvs[h].zeros() - r0;\n        } else {\n   \
    \       res[h] = ::std::make_tuple(h, 0, 0);\n          lid = l0;\n          rid\
    \ = r0;\n        }\n      }\n      return res;\n    }\n\n    ::std::size_t range_freq(const\
    \ T& l, const T& r) const {\n      assert(this->built());\n      assert(l <= r);\n\
    \n      return this->xid(r) - this->xid(l);\n    }\n\n    ::std::size_t range_freq(const\
    \ T& l, const T& r, const T& u) const {\n      assert(this->built());\n      assert(l\
    \ <= r);\n\n      auto lid = this->xid(l);\n      auto rid = this->xid(r);\n \
    \     const auto uid = this->yid(u);\n\n      ::std::size_t res = 0;\n      for\
    \ (::std::size_t h = this->lg(); h --> 0;) {\n        const auto l0 = this->m_bvs[h].rank0(lid);\n\
    \        const auto r0 = this->m_bvs[h].rank0(rid);\n        if ((uid >> h) &\
    \ 1) {\n          res += r0 - l0;\n          lid += this->m_bvs[h].zeros() - l0;\n\
    \          rid += this->m_bvs[h].zeros() - r0;\n        } else {\n          lid\
    \ = l0;\n          rid = r0;\n        }\n      }\n      return res;\n    }\n\n\
    \    ::std::size_t range_freq(const T& l, const T& r, const T& d, const T& u)\
    \ const {\n      assert(this->built());\n      assert(l <= r);\n      assert(d\
    \ <= u);\n\n      return this->range_freq(l, r, u) - this->range_freq(l, r, d);\n\
    \    }\n\n    ::std::optional<T> prev_value(const T& l, const T& r, const T& u)\
    \ const {\n      assert(this->built());\n      assert(l <= r);\n\n      const\
    \ auto k = this->range_freq(l, r, u);\n      return k == 0 ? ::std::nullopt :\
    \ ::std::make_optional(this->m_ps[this->kth_smallest(l, r, k - 1)].second);\n\
    \    }\n\n    ::std::optional<T> next_value(const T& l, const T& r, const T& d)\
    \ const {\n      assert(this->built());\n      assert(l <= r);\n\n      const\
    \ auto k = this->range_freq(l, r, d);\n      return k == this->range_freq(l, r)\
    \ ? ::std::nullopt : ::std::make_optional(this->m_ps[this->kth_smallest(l, r,\
    \ k)].second);\n    }\n\n    ::std::pair<typename ::std::vector<::std::size_t>::const_iterator,\
    \ typename ::std::vector<::std::size_t>::const_iterator> prev_points(const T&\
    \ l, const T& r, const T& u) const {\n      assert(this->built());\n      assert(l\
    \ <= r);\n\n      auto lid = this->xid(l);\n      auto rid = this->xid(r);\n \
    \     auto k = this->range_freq(l, r, u);\n      if (k == 0) return ::std::make_pair(this->m_is.cend(),\
    \ this->m_is.cend());\n      --k;\n\n      for (::std::size_t h = this->lg();\
    \ h --> 0;) {\n        const auto l0 = this->m_bvs[h].rank0(lid);\n        const\
    \ auto r0 = this->m_bvs[h].rank0(rid);\n        if (k < r0 - l0) {\n         \
    \ lid = l0;\n          rid = r0;\n        } else {\n          k -= r0 - l0;\n\
    \          lid += this->m_bvs[h].zeros() - l0;\n          rid += this->m_bvs[h].zeros()\
    \ - r0;\n        }\n      }\n\n      return ::std::make_pair(this->m_is.cbegin()\
    \ + lid, this->m_is.cbegin() + rid);\n    }\n\n    ::std::pair<typename ::std::vector<::std::size_t>::const_iterator,\
    \ typename ::std::vector<::std::size_t>::const_iterator> next_points(const T&\
    \ l, const T& r, const T& d) const {\n      assert(this->built());\n      assert(l\
    \ <= r);\n\n      auto lid = this->xid(l);\n      auto rid = this->xid(r);\n \
    \     auto k = this->range_freq(l, r, d);\n      if (k == rid - lid) return ::std::make_pair(this->m_is.cend(),\
    \ this->m_is.cend());\n\n      for (::std::size_t h = this->lg(); h --> 0;) {\n\
    \        const auto l0 = this->m_bvs[h].rank0(lid);\n        const auto r0 = this->m_bvs[h].rank0(rid);\n\
    \        if (k < r0 - l0) {\n          lid = l0;\n          rid = r0;\n      \
    \  } else {\n          k -= r0 - l0;\n          lid += this->m_bvs[h].zeros()\
    \ - l0;\n          rid += this->m_bvs[h].zeros() - r0;\n        }\n      }\n\n\
    \      return ::std::make_pair(this->m_is.cbegin() + lid, this->m_is.cbegin()\
    \ + rid);\n    }\n  };\n}\n\n#endif\n"
  dependsOn:
  - tools/bit_vector.hpp
  - tools/lower_bound.hpp
  - tools/less_by_first.hpp
  - tools/floor_log2.hpp
  - tools/popcount.hpp
  isVerificationFile: false
  path: tools/wavelet_matrix.hpp
  requiredBy:
  - tools/range_count_distinct.hpp
  timestamp: '2023-07-22 12:30:26+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/wavelet_matrix/kth_smallest.test.cpp
  - tests/wavelet_matrix/range_prod.test.cpp
  - tests/wavelet_matrix/prev_points.test.cpp
  - tests/wavelet_matrix/next_points.test.cpp
  - tests/wavelet_matrix/range_freq.test.cpp
  - tests/range_count_distinct.test.cpp
documentation_of: tools/wavelet_matrix.hpp
layout: document
title: Wavelet matrix
---

It is a data structure which can process various queries at high speed for $n$ weighted points $(x_0, y_0, w_0), (x_1, y_1, w_1), \ldots, (x_{n - 1}, y_{n - 1}, w_{n - 1})$ on a two-dimensional plane.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
wavelet_matrix<T> wm();
```

It creates an empty two-dimensional plane.

### Constraints
- None

### Time Complexity
- $O(1)$

## size
```cpp
std::size_t wm.size();
```

It returns the number of points on the plane.

### Constraints
- None

### Time Complexity
- $O(1)$

## add_point
```cpp
std::size_t wm.add_point(T x, T y);
```

It adds a point $(x, y)$ to the plane.
It returns an integer $i$ such that this is the $i$-th ($0$ indexed) point that is added.

### Constraints
- `wm.build()` has not been called ever.

### Time Complexity
- $O(1)$ amortized

## get_point
```cpp
std::pair<T, T> wm.get_point(std::size_t i)
```

It returns the $i$-th ($0$ indexed) point.

### Constraints
- $i < n$ where $n$ is `wm.size()`

### Time Complexity
- $O(1)$

## points
```cpp
const std::vector<std::pair<T, T>>& wm.points();
```

It returns all the points on the plane.
The points are ordered in the same order as added by `add_point`.

### Constraints
- None

### Time Complexity
- $O(1)$

## build
```cpp
std::vector<std::vector<std::size_t>> wm.build();
```

It internally creates the data structure called as wavelet matrix.

It also returns the matrix $A_{h, j}$ with $O(\log n)$ rows and $n$ columns.
Each row of $A_h$ is the permutation of $(0, 1, \ldots, n - 1)$.
You can initialize an auxiliary data structure by $A_{h, j}$, for querying weighted points.

### Example
```cpp
// Given n weighted points, answer the sum of w_i such that l <= x_i < r and d <= y_i < u.

tools::wavelet_matrix<int> wm;
for (int i = 0; i < n; ++i) {
  wm.add_point(x[i], y[i]);
}

std::vector<tools::online_cumsum<int>> cumsums;
for (const auto& A_h : wm.build()) {
  cumsums.emplace_back(n);
  for (int j = 0; j < n; ++j) {
    cumsums.back()[j] = w[A_h[j]];
  }
}

ll answer = 0;
for (const auto& [h, jl, jr] : wm.range_prod(l, r, u)) {
  answer += cumsums[h].sum(jl, jr);
}
for (const auto& [h, jl, jr] : wm.range_prod(l, r, d)) {
  answer -= cumsums[h].sum(jl, jr);
}
std::cout << answer << '\n';
```

### Constraints
- `wm.build()` has not been called ever.

### Time Complexity
- $O(n \log n)$

## apply
```cpp
std::vector<std::pair<std::size_t, std::size_t>> wm.apply(std::size_t i);
```

It has no side effects, but just returns pairs $(0, j_0), (1, j_1), \ldots, (H - 1, j_{H - 1})$ where $H$ is the number of rows of the returned matrix from `wm.build()`.
You can update the auxiliary data structure by the returned pairs, for querying weighted points.

### Example
```cpp
// Answer Q queries.
// (type 1 query) 1 x y w: Add a point (x, y) at weight w.
// (type 2 query) 2 l r d u: Print the sum of w_i such that l <= x_i < r and d <= y_i < u.

std::queue<int> query_types;
tools::wavelet_matrix<int> wm;
std::vector<int> weights;
std::queue<std::tuple<int, int, int, int>> query2;

int Q;
std::cin >> Q;
for (int q = 0; q < Q; ++q) {
  int t;
  std::cin >> t;
  query_types.push(t);
  if (t == 1) {
    int x, y, w;
    wm.add_point(x, y);
    weights.push_back(w);
  } else {
    int l, r, d, u;
    std::cin >> l >> r >> d >> u;
    query2.emplace(l, r, d, u);
  }
}

auto fws = std::vector(wm.build().size(), atcoder::fenwick_tree<ll>(wm.size()));

int i = 0;
while (!query_types.empty()) {
  const auto t = query_types.front();
  query_types.pop();
  if (t == 1) {
    for (const auto& [h, j] : wm.apply(i)) {
      fws[h].add(j, weights[i]);
    }
    ++i;
  } else {
    const auto [l, r, d, u] = query2.front();
    query2.pop();

    ll answer = 0;
    for (const auto& [h, jl, jr] : wm.range_prod(l, r, u)) {
      answer += fws[h].sum(jl, jr);
    }
    for (const auto& [h, jl, jr] : wm.range_prod(l, r, d)) {
      answer -= fws[h].sum(jl, jr);
    }
    std::cout << answer << '\n';
  }
}
```

### Constraints
- `wm.build()` has been called ever.
- $i < n$

### Time Complexity
- $O(\log n)$

## kth_smallest
```cpp
std::size_t wm.kth_smallest(T l, T r, std::size_t k);
```

It returns $i$ such that $l \leq x_i < r$ and $\|\\{j \mid l \leq x_j < r \land (y_j, j) < (y_i, i)) \\}\| = k$.

### Constraints
- `wm.build()` has been called ever.
- $l \leq r$
- $k < \|\\{i \mid l \leq x_i < r\\}\|$

### Time Complexity
- $O(\log n)$

## kth_largest
```cpp
std::size_t wm.kth_largest(T l, T r, std::size_t k);
```

It returns $i$ such that $l \leq x_i < r$ and $\|\\{j \mid l \leq x_j < r \land (y_i, i) < (y_j, j)) \\}\| = k$.

### Constraints
- `wm.build()` has been called ever.
- $l \leq r$
- $k < \|\\{i \mid l \leq x_i < r\\}\|$

### Time Complexity
- $O(\log n)$

## range_prod
```cpp
std::vector<std::tuple<std::size_t, std::size_t, std::size_t>> wm.range_prod(T l, T r, T u);
```

It has no side effects, but just returns tuples $(0, l_0, r_0), (1, l_1, r_1), \ldots, (H - 1, l_{H - 1}, r_{H - 1})$ where $H$ is the number of rows of the returned matrix from `wm.build()`.
You can answer the query about weighted points using the auxiliary data structure and the returned tuples.

### Example
See the examples of `build` and `apply`.

### Constraints
- `wm.build()` has been called ever.
- $l \leq r$

### Time Complexity
- $O(\log n)$

## range_freq
```cpp
(1) std::size_t wm.range_freq(T l, T r);
(2) std::size_t wm.range_freq(T l, T r, T u);
(3) std::size_t wm.range_freq(T l, T r, T d, T u);
```

- (1)
    - It returns $\|\\{i \mid l \leq x_i < r \\}\|$.
- (2)
    - It returns $\|\\{i \mid l \leq x_i < r \land y_i < u \\}\|$.
- (3)
    - It returns $\|\\{i \mid l \leq x_i < r \land d \leq y_i < u \\}\|$.

### Constraints
- (1), (2)
    - `wm.build()` has been called ever.
    - $l \leq r$
- (3)
    - `wm.build()` has been called ever.
    - $l \leq r$
    - $d \leq u$

### Time Complexity
- $O(\log n)$

## prev_value
```cpp
std::optional<T> wm.prev_value(T l, T r, T u);
```

It returns the maximum $y_i$ such that $l \leq x_i < r$ and $y_i < u$.
If such the $y_i$ does not exist, it returns `std::nullopt`.

### Constraints
- `wm.build()` has been called ever.
- $l \leq r$

### Time Complexity
- $O(\log n)$

## next_value
```cpp
std::optional<T> wm.next_value(T l, T r, T d);
```

It returns the minimum $y_i$ such that $l \leq x_i < r$ and $d \leq y_i$.
If such the $y_i$ does not exist, it returns `std::nullopt`.

### Constraints
- `wm.build()` has been called ever.
- $l \leq r$

### Time Complexity
- $O(\log n)$

## prev_points
```cpp
std::pair<typename std::vector<std::size_t>::const_iterator, typename std::vector<std::size_t>::const_iterator> prev_points(T l, T r, T u)
```

Let us denote the returned iterator pair by `begin` and `end`.
`std::vector<std::size_t>(begin, end)` would be $\\{i \mid l \leq x_i < r \land y_i = y\\}$ sorted in ascending order, where $y$ is `wm.prev_value(l, r, u)`.

### Constraints
- `wm.build()` has been called ever.
- $l \leq r$

### Time Complexity
- $O(\log n)$

## next_points
```cpp
std::pair<typename std::vector<std::size_t>::const_iterator, typename std::vector<std::size_t>::const_iterator> next_points(T l, T r, T d)
```

Let us denote the returned iterator pair by `begin` and `end`.
`std::vector<std::size_t>(begin, end)` would be $\\{i \mid l \leq x_i < r \land y_i = y\\}$ sorted in ascending order, where $y$ is `wm.next_value(l, r, d)`.

### Constraints
- `wm.build()` has been called ever.
- $l \leq r$

### Time Complexity
- $O(\log n)$
