---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/bit_vector.hpp
    title: Bit vector
  - icon: ':heavy_check_mark:'
    path: tools/compress.hpp
    title: Compress values
  - icon: ':question:'
    path: tools/floor_log2.hpp
    title: $\left\lfloor \log_2(x) \right\rfloor$
  - icon: ':question:'
    path: tools/less_by_first.hpp
    title: std::less by first
  - icon: ':heavy_check_mark:'
    path: tools/lower_bound.hpp
    title: std::lower_bound, but returns index
  - icon: ':heavy_check_mark:'
    path: tools/mex.hpp
    title: Minimum excluded value
  - icon: ':question:'
    path: tools/popcount.hpp
    title: Popcount
  - icon: ':heavy_check_mark:'
    path: tools/wavelet_matrix.hpp
    title: Wavelet matrix
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/range_count_distinct.test.cpp
    title: tests/range_count_distinct.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/range_count_distinct.hpp\"\n\n\n\n#include <cstddef>\n\
    #include <cassert>\n#include <vector>\n#include <iterator>\n#include <limits>\n\
    #line 1 \"tools/wavelet_matrix.hpp\"\n\n\n\n#line 5 \"tools/wavelet_matrix.hpp\"\
    \n#include <utility>\n#line 8 \"tools/wavelet_matrix.hpp\"\n#include <algorithm>\n\
    #line 10 \"tools/wavelet_matrix.hpp\"\n#include <array>\n#include <tuple>\n#include\
    \ <optional>\n#line 1 \"tools/bit_vector.hpp\"\n\n\n\n#include <cstdint>\n#line\
    \ 6 \"tools/bit_vector.hpp\"\n#include <immintrin.h>\n\n// Source: https://nyaannyaan.github.io/library/data-structure-2d/wavelet-matrix.hpp.html\n\
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
    #line 1 \"tools/popcount.hpp\"\n\n\n\n#line 8 \"tools/popcount.hpp\"\n\nnamespace\
    \ tools {\n\n  template <typename T>\n  T popcount(T x) {\n    static_assert(::std::is_integral_v<T>);\n\
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
    \ + rid);\n    }\n  };\n}\n\n\n#line 1 \"tools/compress.hpp\"\n\n\n\n#line 8 \"\
    tools/compress.hpp\"\n\nnamespace tools {\n  template <typename InputIterator,\
    \ typename OutputIterator>\n  void compress(InputIterator begin, InputIterator\
    \ end, OutputIterator result) {\n    using T = typename ::std::iterator_traits<InputIterator>::value_type;\n\
    \    ::std::vector<T> orig(begin, end);\n    ::std::vector<T> sorted(orig);\n\
    \    ::std::sort(sorted.begin(), sorted.end());\n    sorted.erase(::std::unique(sorted.begin(),\
    \ sorted.end()), sorted.end());\n    for (auto it = orig.begin(); it != orig.end();\
    \ ++it, ++result) {\n      *result = ::tools::lower_bound(sorted.begin(), sorted.end(),\
    \ *it);\n    }\n  }\n}\n\n\n#line 1 \"tools/mex.hpp\"\n\n\n\n#line 10 \"tools/mex.hpp\"\
    \n\nnamespace tools {\n\n  template <typename InputIterator>\n  ::std::decay_t<decltype(*::std::declval<InputIterator>())>\
    \ mex(InputIterator begin, InputIterator end) {\n    using T = ::std::decay_t<decltype(*::std::declval<InputIterator>())>;\n\
    \    const ::std::vector<T> orig(begin, end);\n    const ::std::size_t n = orig.size();\n\
    \n    assert(::std::all_of(orig.begin(), orig.end(), [](const auto& o) { return\
    \ o >= 0; }));\n\n    ::std::vector<bool> exists(n, false);\n    for (const ::std::size_t\
    \ o : orig) {\n      if (o < n) {\n        exists[o] = true;\n      }\n    }\n\
    \    for (::std::size_t i = 0; i < n; ++i) {\n      if (!exists[i]) {\n      \
    \  return i;\n      }\n    }\n    return n;\n  }\n}\n\n\n#line 12 \"tools/range_count_distinct.hpp\"\
    \n\nnamespace tools {\n  class range_count_distinct {\n  private:\n    ::std::size_t\
    \ m_size;\n    ::tools::wavelet_matrix<::std::size_t> m_wm;\n\n  public:\n   \
    \ range_count_distinct() = default;\n    range_count_distinct(const ::tools::range_count_distinct&)\
    \ = default;\n    range_count_distinct(::tools::range_count_distinct&&) = default;\n\
    \    ~range_count_distinct() = default;\n    ::tools::range_count_distinct& operator=(const\
    \ ::tools::range_count_distinct&) = default;\n    ::tools::range_count_distinct&\
    \ operator=(::tools::range_count_distinct&&) = default;\n\n    template <typename\
    \ InputIterator>\n    range_count_distinct(const InputIterator begin, const InputIterator\
    \ end) {\n      ::std::vector<::std::size_t> seq;\n      ::tools::compress(begin,\
    \ end, ::std::back_inserter(seq));\n      this->m_size = seq.size();\n\n     \
    \ const auto NONE = ::std::numeric_limits<::std::size_t>::max();\n      ::std::vector<::std::size_t>\
    \ prev(::tools::mex(seq.begin(), seq.end()), NONE);\n      for (::std::size_t\
    \ i = 0; i < seq.size(); ++i) {\n        if (prev[seq[i]] != NONE) {\n       \
    \   this->m_wm.add_point(prev[seq[i]], i);\n        }\n        prev[seq[i]] =\
    \ i;\n      }\n\n      this->m_wm.build();\n    }\n\n    ::std::size_t size()\
    \ const {\n      return this->m_size;\n    }\n\n    ::std::size_t query(::std::size_t\
    \ l, ::std::size_t r) const {\n      assert(l <= r && r <= this->size());\n\n\
    \      return (r - l) - this->m_wm.range_freq(l, ::std::numeric_limits<::std::size_t>::max(),\
    \ r);\n    }\n  };\n}\n\n\n"
  code: "#ifndef TOOLS_RANGE_COUNT_DISTINCT_HPP\n#define TOOLS_RANGE_COUNT_DISTINCT_HPP\n\
    \n#include <cstddef>\n#include <cassert>\n#include <vector>\n#include <iterator>\n\
    #include <limits>\n#include \"tools/wavelet_matrix.hpp\"\n#include \"tools/compress.hpp\"\
    \n#include \"tools/mex.hpp\"\n\nnamespace tools {\n  class range_count_distinct\
    \ {\n  private:\n    ::std::size_t m_size;\n    ::tools::wavelet_matrix<::std::size_t>\
    \ m_wm;\n\n  public:\n    range_count_distinct() = default;\n    range_count_distinct(const\
    \ ::tools::range_count_distinct&) = default;\n    range_count_distinct(::tools::range_count_distinct&&)\
    \ = default;\n    ~range_count_distinct() = default;\n    ::tools::range_count_distinct&\
    \ operator=(const ::tools::range_count_distinct&) = default;\n    ::tools::range_count_distinct&\
    \ operator=(::tools::range_count_distinct&&) = default;\n\n    template <typename\
    \ InputIterator>\n    range_count_distinct(const InputIterator begin, const InputIterator\
    \ end) {\n      ::std::vector<::std::size_t> seq;\n      ::tools::compress(begin,\
    \ end, ::std::back_inserter(seq));\n      this->m_size = seq.size();\n\n     \
    \ const auto NONE = ::std::numeric_limits<::std::size_t>::max();\n      ::std::vector<::std::size_t>\
    \ prev(::tools::mex(seq.begin(), seq.end()), NONE);\n      for (::std::size_t\
    \ i = 0; i < seq.size(); ++i) {\n        if (prev[seq[i]] != NONE) {\n       \
    \   this->m_wm.add_point(prev[seq[i]], i);\n        }\n        prev[seq[i]] =\
    \ i;\n      }\n\n      this->m_wm.build();\n    }\n\n    ::std::size_t size()\
    \ const {\n      return this->m_size;\n    }\n\n    ::std::size_t query(::std::size_t\
    \ l, ::std::size_t r) const {\n      assert(l <= r && r <= this->size());\n\n\
    \      return (r - l) - this->m_wm.range_freq(l, ::std::numeric_limits<::std::size_t>::max(),\
    \ r);\n    }\n  };\n}\n\n#endif\n"
  dependsOn:
  - tools/wavelet_matrix.hpp
  - tools/bit_vector.hpp
  - tools/lower_bound.hpp
  - tools/less_by_first.hpp
  - tools/floor_log2.hpp
  - tools/popcount.hpp
  - tools/compress.hpp
  - tools/mex.hpp
  isVerificationFile: false
  path: tools/range_count_distinct.hpp
  requiredBy: []
  timestamp: '2024-01-07 15:56:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/range_count_distinct.test.cpp
documentation_of: tools/range_count_distinct.hpp
layout: document
title: Range count distinct
---

It takes an integer sequence $(a_0, a_1, \ldots, a_{N - 1})$ as input and can answer the number of distinct integers occured in $(a_l, a_{l + 1}, \ldots, a_{r - 1})$ in $\langle O(N \log N), O(\log N) \rangle$ time.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
template <typename InputIterator>
range_count_distinct a(InputIterator begin, InputIterator end);
```

It takes an integer sequence $(a_0, a_1, \ldots, a_{N - 1})$ as input.

### Constraints
- `begin` $\leq$ `end`
- `std::decay_t<decltype(*std::declval<InputIterator>())>` is one of integral types.

### Time Complexity
- $O(N \log N)$

## size
```cpp
std::size_t a.size();
```

It returns $N$.

### Constraints
- None

### Time Complexity
- $O(1)$

## query
```cpp
std::size_t a.query(std::size_t l, std::size_t r);
```

It returns the number of distinct integers occured in $(a_l, a_{l + 1}, \ldots, a_{r - 1})$.

### Constraints
- $0 \leq l \leq r \leq N$

### Time Complexity
- $O(\log N)$
