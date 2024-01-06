---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: tools/bit_vector.hpp
    title: Bit vector
  - icon: ':question:'
    path: tools/floor_log2.hpp
    title: $\left\lfloor \log_2(x) \right\rfloor$
  - icon: ':question:'
    path: tools/less_by_first.hpp
    title: std::less by first
  - icon: ':question:'
    path: tools/lower_bound.hpp
    title: std::lower_bound, but returns index
  - icon: ':question:'
    path: tools/popcount.hpp
    title: Popcount
  - icon: ':question:'
    path: tools/ssize.hpp
    title: Polyfill of std::ssize
  - icon: ':question:'
    path: tools/wavelet_matrix.hpp
    title: Wavelet matrix
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_add_rectangle_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_rectangle_sum
  bundledCode: "#line 1 \"tests/wavelet_matrix/range_prod.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/point_add_rectangle_sum\"\n\n#include <iostream>\n\
    #include <vector>\n#include <queue>\n#include <tuple>\n#line 1 \"lib/ac-library/atcoder/fenwicktree.hpp\"\
    \n\n\n\n#include <cassert>\n#line 6 \"lib/ac-library/atcoder/fenwicktree.hpp\"\
    \n\n#line 1 \"lib/ac-library/atcoder/internal_type_traits.hpp\"\n\n\n\n#line 5\
    \ \"lib/ac-library/atcoder/internal_type_traits.hpp\"\n#include <numeric>\n#include\
    \ <type_traits>\n\nnamespace atcoder {\n\nnamespace internal {\n\n#ifndef _MSC_VER\n\
    template <class T>\nusing is_signed_int128 =\n    typename std::conditional<std::is_same<T,\
    \ __int128_t>::value ||\n                                  std::is_same<T, __int128>::value,\n\
    \                              std::true_type,\n                             \
    \ std::false_type>::type;\n\ntemplate <class T>\nusing is_unsigned_int128 =\n\
    \    typename std::conditional<std::is_same<T, __uint128_t>::value ||\n      \
    \                            std::is_same<T, unsigned __int128>::value,\n    \
    \                          std::true_type,\n                              std::false_type>::type;\n\
    \ntemplate <class T>\nusing make_unsigned_int128 =\n    typename std::conditional<std::is_same<T,\
    \ __int128_t>::value,\n                              __uint128_t,\n          \
    \                    unsigned __int128>;\n\ntemplate <class T>\nusing is_integral\
    \ = typename std::conditional<std::is_integral<T>::value ||\n                \
    \                                  is_signed_int128<T>::value ||\n           \
    \                                       is_unsigned_int128<T>::value,\n      \
    \                                        std::true_type,\n                   \
    \                           std::false_type>::type;\n\ntemplate <class T>\nusing\
    \ is_signed_int = typename std::conditional<(is_integral<T>::value &&\n      \
    \                                           std::is_signed<T>::value) ||\n   \
    \                                                 is_signed_int128<T>::value,\n\
    \                                                std::true_type,\n           \
    \                                     std::false_type>::type;\n\ntemplate <class\
    \ T>\nusing is_unsigned_int =\n    typename std::conditional<(is_integral<T>::value\
    \ &&\n                               std::is_unsigned<T>::value) ||\n        \
    \                          is_unsigned_int128<T>::value,\n                   \
    \           std::true_type,\n                              std::false_type>::type;\n\
    \ntemplate <class T>\nusing to_unsigned = typename std::conditional<\n    is_signed_int128<T>::value,\n\
    \    make_unsigned_int128<T>,\n    typename std::conditional<std::is_signed<T>::value,\n\
    \                              std::make_unsigned<T>,\n                      \
    \        std::common_type<T>>::type>::type;\n\n#else\n\ntemplate <class T> using\
    \ is_integral = typename std::is_integral<T>;\n\ntemplate <class T>\nusing is_signed_int\
    \ =\n    typename std::conditional<is_integral<T>::value && std::is_signed<T>::value,\n\
    \                              std::true_type,\n                             \
    \ std::false_type>::type;\n\ntemplate <class T>\nusing is_unsigned_int =\n   \
    \ typename std::conditional<is_integral<T>::value &&\n                       \
    \           std::is_unsigned<T>::value,\n                              std::true_type,\n\
    \                              std::false_type>::type;\n\ntemplate <class T>\n\
    using to_unsigned = typename std::conditional<is_signed_int<T>::value,\n     \
    \                                         std::make_unsigned<T>,\n           \
    \                                   std::common_type<T>>::type;\n\n#endif\n\n\
    template <class T>\nusing is_signed_int_t = std::enable_if_t<is_signed_int<T>::value>;\n\
    \ntemplate <class T>\nusing is_unsigned_int_t = std::enable_if_t<is_unsigned_int<T>::value>;\n\
    \ntemplate <class T> using to_unsigned_t = typename to_unsigned<T>::type;\n\n\
    }  // namespace internal\n\n}  // namespace atcoder\n\n\n#line 8 \"lib/ac-library/atcoder/fenwicktree.hpp\"\
    \n\nnamespace atcoder {\n\n// Reference: https://en.wikipedia.org/wiki/Fenwick_tree\n\
    template <class T> struct fenwick_tree {\n    using U = internal::to_unsigned_t<T>;\n\
    \n  public:\n    fenwick_tree() : _n(0) {}\n    explicit fenwick_tree(int n) :\
    \ _n(n), data(n) {}\n\n    void add(int p, T x) {\n        assert(0 <= p && p\
    \ < _n);\n        p++;\n        while (p <= _n) {\n            data[p - 1] +=\
    \ U(x);\n            p += p & -p;\n        }\n    }\n\n    T sum(int l, int r)\
    \ {\n        assert(0 <= l && l <= r && r <= _n);\n        return sum(r) - sum(l);\n\
    \    }\n\n  private:\n    int _n;\n    std::vector<U> data;\n\n    U sum(int r)\
    \ {\n        U s = 0;\n        while (r > 0) {\n            s += data[r - 1];\n\
    \            r -= r & -r;\n        }\n        return s;\n    }\n};\n\n}  // namespace\
    \ atcoder\n\n\n#line 1 \"tools/wavelet_matrix.hpp\"\n\n\n\n#line 5 \"tools/wavelet_matrix.hpp\"\
    \n#include <utility>\n#include <cstddef>\n#line 8 \"tools/wavelet_matrix.hpp\"\
    \n#include <algorithm>\n#include <iterator>\n#include <array>\n#line 12 \"tools/wavelet_matrix.hpp\"\
    \n#include <optional>\n#line 1 \"tools/bit_vector.hpp\"\n\n\n\n#include <cstdint>\n\
    #line 6 \"tools/bit_vector.hpp\"\n#include <immintrin.h>\n\n// Source: https://nyaannyaan.github.io/library/data-structure-2d/wavelet-matrix.hpp.html\n\
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
    \    }\n  };\n}\n\n\n#line 1 \"tools/floor_log2.hpp\"\n\n\n\n#line 6 \"tools/floor_log2.hpp\"\
    \n#include <limits>\n#line 1 \"tools/popcount.hpp\"\n\n\n\n#line 8 \"tools/popcount.hpp\"\
    \n\nnamespace tools {\n\n  template <typename T>\n  T popcount(T x) {\n    static_assert(::std::is_integral_v<T>);\n\
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
    \ + rid);\n    }\n  };\n}\n\n\n#line 1 \"tools/ssize.hpp\"\n\n\n\n#line 6 \"tools/ssize.hpp\"\
    \n\nnamespace tools {\n\n  template <typename C>\n  constexpr auto ssize(const\
    \ C& c) -> ::std::common_type_t<::std::ptrdiff_t, ::std::make_signed_t<decltype(c.size())>>\
    \ {\n    return c.size();\n  }\n}\n\n\n#line 10 \"tests/wavelet_matrix/range_prod.test.cpp\"\
    \n\nusing ll = long long;\n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  int N, Q;\n  std::cin >> N >> Q;\n\n  tools::wavelet_matrix<int> wm;\n  std::vector<int>\
    \ ws;\n  std::queue<int> qts;\n  std::queue<std::tuple<int, int, int, int>> q2s;\n\
    \  for (int i = 0; i < N; ++i) {\n    int x, y, w;\n    std::cin >> x >> y >>\
    \ w;\n    wm.add_point(x, y);\n    ws.push_back(w);\n  }\n  for (int q = 0; q\
    \ < Q; ++q) {\n    int qt;\n    std::cin >> qt;\n    if (qt == 0) {\n      int\
    \ x, y, w;\n      std::cin >> x >> y >> w;\n      wm.add_point(x, y);\n      ws.push_back(w);\n\
    \      qts.push(0);\n    } else {\n      int l, d, r, u;\n      std::cin >> l\
    \ >> d >> r >> u;\n      qts.push(1);\n      q2s.emplace(l, d, r, u);\n    }\n\
    \  }\n\n  std::vector<atcoder::fenwick_tree<ll>> fws;\n  for (const auto& v :\
    \ wm.build()) {\n    fws.emplace_back(v.size());\n    for (int i = 0; i < tools::ssize(v);\
    \ ++i) {\n      if (int(v[i]) < N) {\n        fws.back().add(i, ws[v[i]]);\n \
    \     }\n    }\n  }\n\n  int p = N;\n  for (int q = 0; q < Q; ++q) {\n    const\
    \ auto qt = qts.front();\n    qts.pop();\n    if (qt == 0) {\n      for (const\
    \ auto& [h, i] : wm.apply(p)) {\n        fws[h].add(i, ws[p]);\n      }\n    \
    \  ++p;\n    } else {\n      const auto [l, d, r, u] = q2s.front();\n      q2s.pop();\n\
    \      ll answer = 0;\n      for (const auto& [h, il, ir] : wm.range_prod(l, r,\
    \ u)) {\n        answer += fws[h].sum(il, ir);\n      }\n      for (const auto&\
    \ [h, il, ir] : wm.range_prod(l, r, d)) {\n        answer -= fws[h].sum(il, ir);\n\
    \      }\n      std::cout << answer << '\\n';\n    }\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_rectangle_sum\"\
    \n\n#include <iostream>\n#include <vector>\n#include <queue>\n#include <tuple>\n\
    #include \"atcoder/fenwicktree.hpp\"\n#include \"tools/wavelet_matrix.hpp\"\n\
    #include \"tools/ssize.hpp\"\n\nusing ll = long long;\n\nint main() {\n  std::cin.tie(nullptr);\n\
    \  std::ios_base::sync_with_stdio(false);\n\n  int N, Q;\n  std::cin >> N >> Q;\n\
    \n  tools::wavelet_matrix<int> wm;\n  std::vector<int> ws;\n  std::queue<int>\
    \ qts;\n  std::queue<std::tuple<int, int, int, int>> q2s;\n  for (int i = 0; i\
    \ < N; ++i) {\n    int x, y, w;\n    std::cin >> x >> y >> w;\n    wm.add_point(x,\
    \ y);\n    ws.push_back(w);\n  }\n  for (int q = 0; q < Q; ++q) {\n    int qt;\n\
    \    std::cin >> qt;\n    if (qt == 0) {\n      int x, y, w;\n      std::cin >>\
    \ x >> y >> w;\n      wm.add_point(x, y);\n      ws.push_back(w);\n      qts.push(0);\n\
    \    } else {\n      int l, d, r, u;\n      std::cin >> l >> d >> r >> u;\n  \
    \    qts.push(1);\n      q2s.emplace(l, d, r, u);\n    }\n  }\n\n  std::vector<atcoder::fenwick_tree<ll>>\
    \ fws;\n  for (const auto& v : wm.build()) {\n    fws.emplace_back(v.size());\n\
    \    for (int i = 0; i < tools::ssize(v); ++i) {\n      if (int(v[i]) < N) {\n\
    \        fws.back().add(i, ws[v[i]]);\n      }\n    }\n  }\n\n  int p = N;\n \
    \ for (int q = 0; q < Q; ++q) {\n    const auto qt = qts.front();\n    qts.pop();\n\
    \    if (qt == 0) {\n      for (const auto& [h, i] : wm.apply(p)) {\n        fws[h].add(i,\
    \ ws[p]);\n      }\n      ++p;\n    } else {\n      const auto [l, d, r, u] =\
    \ q2s.front();\n      q2s.pop();\n      ll answer = 0;\n      for (const auto&\
    \ [h, il, ir] : wm.range_prod(l, r, u)) {\n        answer += fws[h].sum(il, ir);\n\
    \      }\n      for (const auto& [h, il, ir] : wm.range_prod(l, r, d)) {\n   \
    \     answer -= fws[h].sum(il, ir);\n      }\n      std::cout << answer << '\\\
    n';\n    }\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - tools/wavelet_matrix.hpp
  - tools/bit_vector.hpp
  - tools/lower_bound.hpp
  - tools/less_by_first.hpp
  - tools/floor_log2.hpp
  - tools/popcount.hpp
  - tools/ssize.hpp
  isVerificationFile: true
  path: tests/wavelet_matrix/range_prod.test.cpp
  requiredBy: []
  timestamp: '2023-07-22 12:30:26+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/wavelet_matrix/range_prod.test.cpp
layout: document
redirect_from:
- /verify/tests/wavelet_matrix/range_prod.test.cpp
- /verify/tests/wavelet_matrix/range_prod.test.cpp.html
title: tests/wavelet_matrix/range_prod.test.cpp
---
