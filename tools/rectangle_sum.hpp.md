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
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/rectangle_sum.test.cpp
    title: tests/rectangle_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/rectangle_sum.hpp\"\n\n\n\n#include <vector>\n#include\
    \ <utility>\n#include <algorithm>\n#include <cassert>\n#include <array>\n#line\
    \ 1 \"lib/ac-library/atcoder/fenwicktree.hpp\"\n\n\n\n#line 6 \"lib/ac-library/atcoder/fenwicktree.hpp\"\
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
    \ atcoder\n\n\n#line 1 \"tools/bit_vector.hpp\"\n\n\n\n#include <cstdint>\n#line\
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
    #include <iterator>\n#line 6 \"tools/lower_bound.hpp\"\n\nnamespace tools {\n\n\
    \  template <class ForwardIterator, class T>\n  auto lower_bound(ForwardIterator\
    \ first, ForwardIterator last, const T& value) {\n    return ::std::distance(first,\
    \ ::std::lower_bound(first, last, value));\n  }\n\n  template <class ForwardIterator,\
    \ class T, class Compare>\n  auto lower_bound(ForwardIterator first, ForwardIterator\
    \ last, const T& value, Compare comp) {\n    return ::std::distance(first, ::std::lower_bound(first,\
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
    \ 14 \"tools/rectangle_sum.hpp\"\n\nnamespace tools {\n  template <typename T>\n\
    \  class rectangle_sum {\n  private:\n    ::std::vector<::std::pair<T, T>> m_ps;\n\
    \    ::std::vector<T> m_ys;\n    ::std::vector<::tools::bit_vector> m_bvs;\n \
    \   ::std::vector<::atcoder::fenwick_tree<T>> m_fws;\n\n    int xid(const T x)\
    \ const {\n      return ::tools::lower_bound(this->m_ps.begin(), this->m_ps.end(),\
    \ ::std::make_pair(x, T()), ::tools::less_by_first());\n    }\n    int yid(const\
    \ T y) const {\n      return ::tools::lower_bound(this->m_ys.begin(), this->m_ys.end(),\
    \ y);\n    }\n    int size() const {\n      return this->m_ps.size();\n    }\n\
    \    int lg() const {\n      return this->m_bvs.size();\n    }\n    bool built()\
    \ const {\n      return this->lg() > 0;\n    }\n\n  public:\n    rectangle_sum()\
    \ = default;\n    rectangle_sum(const ::tools::rectangle_sum<T>&) = default;\n\
    \    rectangle_sum(::tools::rectangle_sum<T>&&) = default;\n    ~rectangle_sum()\
    \ = default;\n    ::tools::rectangle_sum<T>& operator=(const ::tools::rectangle_sum<T>&)\
    \ = default;\n    ::tools::rectangle_sum<T>& operator=(::tools::rectangle_sum<T>&&)\
    \ = default;\n\n    void register_point(const T x, const T y) {\n      assert(!this->built());\n\
    \n      this->m_ps.emplace_back(x, y);\n      this->m_ys.push_back(y);\n    }\n\
    \n    void build() {\n      assert(!this->built());\n\n      ::std::sort(this->m_ps.begin(),\
    \ this->m_ps.end());\n      this->m_ps.erase(::std::unique(this->m_ps.begin(),\
    \ this->m_ps.end()), this->m_ps.end());\n\n      ::std::sort(this->m_ys.begin(),\
    \ this->m_ys.end());\n      this->m_ys.erase(::std::unique(this->m_ys.begin(),\
    \ this->m_ys.end()), this->m_ys.end());\n\n      const int n = ::std::max(this->size(),\
    \ 1);\n      this->m_bvs.assign(::tools::floor_log2(::std::max<int>(this->m_ys.size(),\
    \ 1)) + 1, ::tools::bit_vector(n));\n\n      ::std::vector<int> cur;\n      cur.reserve(n);\n\
    \      for (int i = 0; i < this->size(); ++i) {\n        cur.push_back(this->yid(this->m_ps[i].second));\n\
    \      }\n      cur.resize(n);\n      ::std::vector<int> nxt(n);\n\n      for\
    \ (int h = this->lg() - 1; h >= 0; --h) {\n        for (int i = 0; i < n; ++i)\n\
    \          if ((cur[i] >> h) & 1) this->m_bvs[h].set(i);\n        this->m_bvs[h].build();\n\
    \        ::std::array<decltype(nxt.begin()), 2> it{nxt.begin(), nxt.begin() +\
    \ this->m_bvs[h].zeros()};\n        for (int i = 0; i < n; ++i) *it[this->m_bvs[h].get(i)]++\
    \ = cur[i];\n        ::std::swap(cur, nxt);\n      }\n\n      this->m_fws.assign(this->lg(),\
    \ ::atcoder::fenwick_tree<T>(n));\n    }\n\n    void add(const T x, const T y,\
    \ const T w) {\n      assert(this->built());\n\n      int k = ::tools::lower_bound(this->m_ps.begin(),\
    \ this->m_ps.end(), ::std::make_pair(x, y));\n\n      assert(k < this->size());\n\
    \      assert(this->m_ps[k] == ::std::make_pair(x, y));\n\n      for (int h =\
    \ this->lg() - 1; h >= 0; --h) {\n        k = this->m_bvs[h].get(k) ? this->m_bvs[h].rank1(k)\
    \ + this->m_bvs[h].zeros() : this->m_bvs[h].rank0(k);\n        this->m_fws[h].add(k,\
    \ w);\n      }\n    }\n\n  private:\n    T sum(int l, int r, const int u) {\n\
    \      assert(this->built());\n      assert(0 <= l && l <= r && r <= this->size());\n\
    \      assert(0 <= u);\n\n      T res = 0;\n      for (int h = this->lg() - 1;\
    \ h >= 0; --h) {\n        const auto l0 = this->m_bvs[h].rank0(l);\n        const\
    \ auto r0 = this->m_bvs[h].rank0(r);\n        if ((u >> h) & 1) {\n          res\
    \ += this->m_fws[h].sum(l0, r0);\n          l += this->m_bvs[h].zeros() - l0;\n\
    \          r += this->m_bvs[h].zeros() - r0;\n        } else {\n          l =\
    \ l0;\n          r = r0;\n        }\n      }\n      return res;\n    }\n\n  public:\n\
    \    T sum(T l, T r, const T d, const T u) {\n      assert(this->built());\n \
    \     assert(l <= r);\n      assert(d <= u);\n\n      l = this->xid(l);\n    \
    \  r = this->xid(r);\n      return this->sum(l, r, this->yid(u)) - this->sum(l,\
    \ r, this->yid(d));\n    }\n  };\n}\n\n\n"
  code: "#ifndef TOOLS_RECTANGLE_SUM\n#define TOOLS_RECTANGLE_SUM\n\n#include <vector>\n\
    #include <utility>\n#include <algorithm>\n#include <cassert>\n#include <array>\n\
    #include \"atcoder/fenwicktree.hpp\"\n#include \"tools/bit_vector.hpp\"\n#include\
    \ \"tools/lower_bound.hpp\"\n#include \"tools/less_by_first.hpp\"\n#include \"\
    tools/floor_log2.hpp\"\n\nnamespace tools {\n  template <typename T>\n  class\
    \ rectangle_sum {\n  private:\n    ::std::vector<::std::pair<T, T>> m_ps;\n  \
    \  ::std::vector<T> m_ys;\n    ::std::vector<::tools::bit_vector> m_bvs;\n   \
    \ ::std::vector<::atcoder::fenwick_tree<T>> m_fws;\n\n    int xid(const T x) const\
    \ {\n      return ::tools::lower_bound(this->m_ps.begin(), this->m_ps.end(), ::std::make_pair(x,\
    \ T()), ::tools::less_by_first());\n    }\n    int yid(const T y) const {\n  \
    \    return ::tools::lower_bound(this->m_ys.begin(), this->m_ys.end(), y);\n \
    \   }\n    int size() const {\n      return this->m_ps.size();\n    }\n    int\
    \ lg() const {\n      return this->m_bvs.size();\n    }\n    bool built() const\
    \ {\n      return this->lg() > 0;\n    }\n\n  public:\n    rectangle_sum() = default;\n\
    \    rectangle_sum(const ::tools::rectangle_sum<T>&) = default;\n    rectangle_sum(::tools::rectangle_sum<T>&&)\
    \ = default;\n    ~rectangle_sum() = default;\n    ::tools::rectangle_sum<T>&\
    \ operator=(const ::tools::rectangle_sum<T>&) = default;\n    ::tools::rectangle_sum<T>&\
    \ operator=(::tools::rectangle_sum<T>&&) = default;\n\n    void register_point(const\
    \ T x, const T y) {\n      assert(!this->built());\n\n      this->m_ps.emplace_back(x,\
    \ y);\n      this->m_ys.push_back(y);\n    }\n\n    void build() {\n      assert(!this->built());\n\
    \n      ::std::sort(this->m_ps.begin(), this->m_ps.end());\n      this->m_ps.erase(::std::unique(this->m_ps.begin(),\
    \ this->m_ps.end()), this->m_ps.end());\n\n      ::std::sort(this->m_ys.begin(),\
    \ this->m_ys.end());\n      this->m_ys.erase(::std::unique(this->m_ys.begin(),\
    \ this->m_ys.end()), this->m_ys.end());\n\n      const int n = ::std::max(this->size(),\
    \ 1);\n      this->m_bvs.assign(::tools::floor_log2(::std::max<int>(this->m_ys.size(),\
    \ 1)) + 1, ::tools::bit_vector(n));\n\n      ::std::vector<int> cur;\n      cur.reserve(n);\n\
    \      for (int i = 0; i < this->size(); ++i) {\n        cur.push_back(this->yid(this->m_ps[i].second));\n\
    \      }\n      cur.resize(n);\n      ::std::vector<int> nxt(n);\n\n      for\
    \ (int h = this->lg() - 1; h >= 0; --h) {\n        for (int i = 0; i < n; ++i)\n\
    \          if ((cur[i] >> h) & 1) this->m_bvs[h].set(i);\n        this->m_bvs[h].build();\n\
    \        ::std::array<decltype(nxt.begin()), 2> it{nxt.begin(), nxt.begin() +\
    \ this->m_bvs[h].zeros()};\n        for (int i = 0; i < n; ++i) *it[this->m_bvs[h].get(i)]++\
    \ = cur[i];\n        ::std::swap(cur, nxt);\n      }\n\n      this->m_fws.assign(this->lg(),\
    \ ::atcoder::fenwick_tree<T>(n));\n    }\n\n    void add(const T x, const T y,\
    \ const T w) {\n      assert(this->built());\n\n      int k = ::tools::lower_bound(this->m_ps.begin(),\
    \ this->m_ps.end(), ::std::make_pair(x, y));\n\n      assert(k < this->size());\n\
    \      assert(this->m_ps[k] == ::std::make_pair(x, y));\n\n      for (int h =\
    \ this->lg() - 1; h >= 0; --h) {\n        k = this->m_bvs[h].get(k) ? this->m_bvs[h].rank1(k)\
    \ + this->m_bvs[h].zeros() : this->m_bvs[h].rank0(k);\n        this->m_fws[h].add(k,\
    \ w);\n      }\n    }\n\n  private:\n    T sum(int l, int r, const int u) {\n\
    \      assert(this->built());\n      assert(0 <= l && l <= r && r <= this->size());\n\
    \      assert(0 <= u);\n\n      T res = 0;\n      for (int h = this->lg() - 1;\
    \ h >= 0; --h) {\n        const auto l0 = this->m_bvs[h].rank0(l);\n        const\
    \ auto r0 = this->m_bvs[h].rank0(r);\n        if ((u >> h) & 1) {\n          res\
    \ += this->m_fws[h].sum(l0, r0);\n          l += this->m_bvs[h].zeros() - l0;\n\
    \          r += this->m_bvs[h].zeros() - r0;\n        } else {\n          l =\
    \ l0;\n          r = r0;\n        }\n      }\n      return res;\n    }\n\n  public:\n\
    \    T sum(T l, T r, const T d, const T u) {\n      assert(this->built());\n \
    \     assert(l <= r);\n      assert(d <= u);\n\n      l = this->xid(l);\n    \
    \  r = this->xid(r);\n      return this->sum(l, r, this->yid(u)) - this->sum(l,\
    \ r, this->yid(d));\n    }\n  };\n}\n\n#endif\n"
  dependsOn:
  - tools/bit_vector.hpp
  - tools/lower_bound.hpp
  - tools/less_by_first.hpp
  - tools/floor_log2.hpp
  - tools/popcount.hpp
  isVerificationFile: false
  path: tools/rectangle_sum.hpp
  requiredBy: []
  timestamp: '2023-06-25 14:37:01+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/rectangle_sum.test.cpp
documentation_of: tools/rectangle_sum.hpp
layout: document
title: Rectangle sum
---

Given $n$ weighted points on two-dimensional plane, it processes the following queries in offline.

- Adding a new point with weight $w$ at $(x, y)$ in $O\left((\log n)^2\right)$ time. If there is another point at the same coordinates, add as a distinct point.
- Finding the sum of weight of points such that $l \leq x < r, d \leq y < u$ is satisfied in $O\left((\log n)^2\right)$ time.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
rectangle_sum<T> rs();
```

It creates an empty two-dimensional plane.

### Constraints
- None

### Time Complexity
- $O(1)$

## register_point
```cpp
void rs.register_point(T x, T y);
```

It asserts that $(x, y)$ will be added.

### Constraints
- `rs.build()` has not been called ever.

### Time Complexity
- $O(1)$ amortized

## build
```cpp
void rs.build();
```

It internally creates the the data structure.

### Constraints
- `rs.build()` has not been called ever.

### Time Complexity
- $O(n \log n)$

## add
```cpp
void rs.add(T x, T y, T w);
```

It adds a new point with weight $w$ at $(x, y)$.
If there is another point at the same coordinates, add as a distinct point.

### Constraints
- `rs.build()` has been called ever.
- `rs.register_point(x, y)` has been called ever.

### Time Complexity
- $O\left((\log n)^2\right)$

## sum
```cpp
T rs.sum(T l, T r, T d, T u);
```

It returns the sum of weight of points such that $l \leq x < r, d \leq y < u$ is satisfied.

### Constraints
- `rs.build()` has been called ever.

### Time Complexity
- $O\left((\log n)^2\right)$
