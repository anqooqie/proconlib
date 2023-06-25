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
    path: tools/popcount.hpp
    title: Popcount
  - icon: ':heavy_check_mark:'
    path: tools/wavelet_matrix.hpp
    title: Wavelet matrix
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/2674
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/2674
  bundledCode: "#line 1 \"tests/wavelet_matrix/range_freq.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/problems/2674\"\n\n#include <iostream>\n\
    #include <algorithm>\n#line 1 \"tools/wavelet_matrix.hpp\"\n\n\n\n#include <cstdint>\n\
    #include <vector>\n#line 7 \"tools/wavelet_matrix.hpp\"\n#include <iterator>\n\
    #include <array>\n#include <utility>\n#include <cassert>\n#line 1 \"tools/bit_vector.hpp\"\
    \n\n\n\n#line 6 \"tools/bit_vector.hpp\"\n#include <immintrin.h>\n\n// Source:\
    \ https://nyaannyaan.github.io/library/data-structure-2d/wavelet-matrix.hpp.html\n\
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
    \ / w], i % w));\n    }\n  };\n}\n\n\n#line 1 \"tools/floor_log2.hpp\"\n\n\n\n\
    #include <type_traits>\n#line 6 \"tools/floor_log2.hpp\"\n#include <limits>\n\
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
    \ 13 \"tools/wavelet_matrix.hpp\"\n\n// Source: https://nyaannyaan.github.io/library/data-structure-2d/wavelet-matrix.hpp.html\n\
    // License: CC0 1.0 Universal\n// Author: Nyaan\n\nnamespace tools {\n  template\
    \ <typename T>\n  class wavelet_matrix {\n  private:\n    using u32 = ::std::uint32_t;\n\
    \    using i64 = ::std::int64_t;\n    using u64 = ::std::uint64_t;\n\n    int\
    \ n, lg;\n    ::std::vector<T> a;\n    ::std::vector<::tools::bit_vector> bv;\n\
    \n  public:\n    wavelet_matrix() = default;\n    wavelet_matrix(const wavelet_matrix<T>&)\
    \ = default;\n    wavelet_matrix<T>& operator=(const wavelet_matrix<T>&) = default;\n\
    \n    explicit wavelet_matrix(u32 _n) : n(::std::max<u32>(_n, 1)), a(n) {}\n \
    \   wavelet_matrix(const ::std::vector<T>& _a) : n(_a.size()), a(_a) { build();\
    \ }\n\n    __attribute__((optimize(\"O3\"))) void build() {\n      assert(::std::all_of(::std::begin(a),\
    \ ::std::end(a), [](const auto a_i) { return a_i >= 0; }));\n\n      lg = ::tools::floor_log2(::std::max<T>(*::std::max_element(::std::begin(a),\
    \ ::std::end(a)), 1)) + 1;\n      bv.assign(lg, ::tools::bit_vector(n));\n   \
    \   ::std::vector<T> cur = a, nxt(n);\n      for (int h = lg - 1; h >= 0; --h)\
    \ {\n        for (int i = 0; i < n; ++i)\n          if ((cur[i] >> h) & 1) bv[h].set(i);\n\
    \        bv[h].build();\n        ::std::array<decltype(::std::begin(nxt)), 2>\
    \ it{::std::begin(nxt), ::std::begin(nxt) + bv[h].zeros()};\n        for (int\
    \ i = 0; i < n; ++i) *it[bv[h].get(i)]++ = cur[i];\n        ::std::swap(cur, nxt);\n\
    \      }\n      return;\n    }\n\n    void set(u32 i, const T& x) {\n      assert(x\
    \ >= 0);\n      a[i] = x; \n    }\n\n    // return a[k]\n    T access(u32 k) const\
    \ {\n      assert(k <= u32(n));\n\n      T ret = 0;\n      for (int h = lg - 1;\
    \ h >= 0; --h) {\n        u32 f = bv[h].get(k);\n        ret |= f ? T(1) << h\
    \ : 0;\n        k = f ? bv[h].rank1(k) + bv[h].zeros() : bv[h].rank0(k);\n   \
    \   }\n      return ret;\n    }\n\n    // k-th (0-indexed) smallest number in\
    \ a[l, r)\n    T kth_smallest(u32 l, u32 r, u32 k) const {\n      assert(l <=\
    \ r && r <= u32(n));\n      assert(k < r - l);\n\n      T res = 0;\n      for\
    \ (int h = lg - 1; h >= 0; --h) {\n        u32 l0 = bv[h].rank0(l), r0 = bv[h].rank0(r);\n\
    \        if (k < r0 - l0)\n          l = l0, r = r0;\n        else {\n       \
    \   k -= r0 - l0;\n          res |= T(1) << h;\n          l += bv[h].zeros() -\
    \ l0;\n          r += bv[h].zeros() - r0;\n        }\n      }\n      return res;\n\
    \    }\n\n    // k-th (0-indexed) largest number in a[l, r)\n    T kth_largest(int\
    \ l, int r, int k) {\n      assert(l <= r && r <= n);\n      assert(k < r - l);\n\
    \n      return kth_smallest(l, r, r - l - k - 1);\n    }\n\n    // count i s.t.\
    \ (l <= i < r) && (v[i] < upper)\n    int range_freq(int l, int r, T upper) {\n\
    \      assert(l <= r && r <= n);\n      assert(upper >= 0);\n\n      if (upper\
    \ >= (T(1) << lg)) return r - l;\n      int ret = 0;\n      for (int h = lg -\
    \ 1; h >= 0; --h) {\n        bool f = (upper >> h) & 1;\n        u32 l0 = bv[h].rank0(l),\
    \ r0 = bv[h].rank0(r);\n        if (f) {\n          ret += r0 - l0;\n        \
    \  l += bv[h].zeros() - l0;\n          r += bv[h].zeros() - r0;\n        } else\
    \ {\n          l = l0;\n          r = r0;\n        }\n      }\n      return ret;\n\
    \    }\n\n    int range_freq(int l, int r, T lower, T upper) {\n      assert(l\
    \ <= r && r <= n);\n      assert(0 <= lower && lower <= upper);\n\n      return\
    \ range_freq(l, r, upper) - range_freq(l, r, lower);\n    }\n\n    // max v[i]\
    \ s.t. (l <= i < r) && (v[i] < upper)\n    T prev_value(int l, int r, T upper)\
    \ {\n      assert(l <= r && r <= n);\n      assert(upper >= 0);\n\n      int cnt\
    \ = range_freq(l, r, upper);\n      return cnt == 0 ? T(-1) : kth_smallest(l,\
    \ r, cnt - 1);\n    }\n\n    // min v[i] s.t. (l <= i < r) && (lower <= v[i])\n\
    \    T next_value(int l, int r, T lower) {\n      assert(l <= r && r <= n);\n\
    \      assert(lower >= 0);\n\n      int cnt = range_freq(l, r, lower);\n     \
    \ return cnt == r - l ? T(-1) : kth_smallest(l, r, cnt);\n    }\n  };\n}\n\n\n\
    #line 6 \"tests/wavelet_matrix/range_freq.test.cpp\"\n\nint main() {\n  std::cin.tie(nullptr);\n\
    \  std::ios_base::sync_with_stdio(false);\n\n  int D;\n  std::cin >> D;\n  tools::wavelet_matrix<int>\
    \ x(D);\n  for (int i = 0; i < D; ++i) {\n    int x_i;\n    std::cin >> x_i;\n\
    \    x_i += 100000000;\n    x.set(i, x_i);\n  }\n  x.build();\n\n  int Q;\n  std::cin\
    \ >> Q;\n  for (int q = 0; q < Q; ++q) {\n    int l, r, e;\n    std::cin >> l\
    \ >> r >> e;\n    --l;\n    const auto [a, b] = std::minmax({x.access(l), x.access(r\
    \ - 1)});\n    std::cout << (r - l) - x.range_freq(l, r, std::max(0, a - e), b\
    \ + e + 1) << \"\\n\";\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/2674\"\n\n#include\
    \ <iostream>\n#include <algorithm>\n#include \"tools/wavelet_matrix.hpp\"\n\n\
    int main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  int D;\n  std::cin >> D;\n  tools::wavelet_matrix<int> x(D);\n  for (int i\
    \ = 0; i < D; ++i) {\n    int x_i;\n    std::cin >> x_i;\n    x_i += 100000000;\n\
    \    x.set(i, x_i);\n  }\n  x.build();\n\n  int Q;\n  std::cin >> Q;\n  for (int\
    \ q = 0; q < Q; ++q) {\n    int l, r, e;\n    std::cin >> l >> r >> e;\n    --l;\n\
    \    const auto [a, b] = std::minmax({x.access(l), x.access(r - 1)});\n    std::cout\
    \ << (r - l) - x.range_freq(l, r, std::max(0, a - e), b + e + 1) << \"\\n\";\n\
    \  }\n\n  return 0;\n}\n"
  dependsOn:
  - tools/wavelet_matrix.hpp
  - tools/bit_vector.hpp
  - tools/floor_log2.hpp
  - tools/popcount.hpp
  isVerificationFile: true
  path: tests/wavelet_matrix/range_freq.test.cpp
  requiredBy: []
  timestamp: '2023-06-25 14:36:39+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/wavelet_matrix/range_freq.test.cpp
layout: document
redirect_from:
- /verify/tests/wavelet_matrix/range_freq.test.cpp
- /verify/tests/wavelet_matrix/range_freq.test.cpp.html
title: tests/wavelet_matrix/range_freq.test.cpp
---
