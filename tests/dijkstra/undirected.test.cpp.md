---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/ceil.hpp
    title: $\left\lceil \frac{x}{y} \right\rceil$
  - icon: ':heavy_check_mark:'
    path: tools/ceil_log2.hpp
    title: $\left\lceil \log_2(x) \right\rceil$
  - icon: ':heavy_check_mark:'
    path: tools/chmin.hpp
    title: chmin function
  - icon: ':heavy_check_mark:'
    path: tools/countr_zero.hpp
    title: Number of trailing zeros
  - icon: ':heavy_check_mark:'
    path: tools/dijkstra.hpp
    title: Dijkstra's algorithm
  - icon: ':heavy_check_mark:'
    path: tools/dynamic_bitset.hpp
    title: std::bitset with dynamic size
  - icon: ':heavy_check_mark:'
    path: tools/greater_by_second.hpp
    title: std::greater by second
  - icon: ':heavy_check_mark:'
    path: tools/popcount.hpp
    title: Popcount
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc270/tasks/abc270_c
    links:
    - https://atcoder.jp/contests/abc270/tasks/abc270_c
  bundledCode: "#line 1 \"tests/dijkstra/undirected.test.cpp\"\n#define PROBLEM \"\
    https://atcoder.jp/contests/abc270/tasks/abc270_c\"\n\n#include <iostream>\n#include\
    \ <string>\n#include <limits>\n#include <cstddef>\n#line 1 \"tools/dijkstra.hpp\"\
    \n\n\n\n#line 5 \"tools/dijkstra.hpp\"\n#include <vector>\n#include <cassert>\n\
    #include <utility>\n#include <algorithm>\n#line 10 \"tools/dijkstra.hpp\"\n#include\
    \ <queue>\n#line 1 \"tools/ceil_log2.hpp\"\n\n\n\n#include <type_traits>\n#line\
    \ 7 \"tools/ceil_log2.hpp\"\n#include <tuple>\n#include <array>\n#include <cstdint>\n\
    \n// Source: https://stackoverflow.com/questions/3272424/compute-fast-log-base-2-ceiling/15327567#15327567\n\
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
    \n#line 1 \"tools/greater_by_second.hpp\"\n\n\n\n#line 5 \"tools/greater_by_second.hpp\"\
    \n\nnamespace tools {\n\n  class greater_by_second {\n  public:\n    template\
    \ <class T1, class T2>\n    bool operator()(const ::std::pair<T1, T2>& x, const\
    \ ::std::pair<T1, T2>& y) const {\n      return x.second > y.second;\n    }\n\
    \  };\n}\n\n\n#line 1 \"tools/chmin.hpp\"\n\n\n\n#line 5 \"tools/chmin.hpp\"\n\
    \nnamespace tools {\n\n  template <typename M, typename N>\n  bool chmin(M& lhs,\
    \ const N& rhs) {\n    const bool updated = lhs > rhs;\n    if (updated) lhs =\
    \ rhs;\n    return updated;\n  }\n}\n\n\n#line 1 \"tools/dynamic_bitset.hpp\"\n\
    \n\n\n#line 11 \"tools/dynamic_bitset.hpp\"\n#include <iterator>\n#line 1 \"tools/ceil.hpp\"\
    \n\n\n\n#line 6 \"tools/ceil.hpp\"\n\nnamespace tools {\n\n  template <typename\
    \ M, typename N>\n  constexpr ::std::common_type_t<M, N> ceil(const M lhs, const\
    \ N rhs) {\n    using T = ::std::common_type_t<M, N>;\n    assert(rhs != N(0));\n\
    \    return lhs / rhs + T(((lhs > M(0) && rhs > N(0)) || (lhs < M(0) && rhs <\
    \ N(0))) && lhs % rhs);\n  }\n}\n\n\n#line 1 \"tools/popcount.hpp\"\n\n\n\n#line\
    \ 8 \"tools/popcount.hpp\"\n\nnamespace tools {\n\n  template <typename T>\n \
    \ T popcount(T x) {\n    static_assert(::std::is_integral_v<T>);\n    assert(x\
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
    \      }\n\n      return x;\n    }\n  }\n}\n\n\n#line 1 \"tools/countr_zero.hpp\"\
    \n\n\n\n#line 10 \"tools/countr_zero.hpp\"\n\n// Source: https://qiita.com/kazatsuyu/items/38203287c19890a2b7c6\n\
    // License: unknown\n// Author: \u767D\u5C71 \u98A8\u9732\n\nnamespace tools {\n\
    \  namespace detail {\n    namespace countr_zero {\n      template <::std::size_t\
    \ N>\n      struct ntz_traits;\n\n      template <>\n      struct ntz_traits<1>\
    \ {\n        using type = bool;\n        static constexpr int shift = 0;\n   \
    \     static constexpr type magic = true;\n        static constexpr int ntz_table[2]\
    \ = {\n          1,  0\n        };\n      };\n\n      template <>\n      struct\
    \ ntz_traits<8> {\n        using type = ::std::uint8_t;\n        static constexpr\
    \ int shift = 4;\n        static constexpr type magic = UINT8_C(0x1D);\n     \
    \   static constexpr int ntz_table[15] = {\n          8,  0, -1,  1,  6, -1, -1,\
    \  2,  7, -1,  5, -1, -1,  4,  3\n        };\n      };\n\n      template <>\n\
    \      struct ntz_traits<16> {\n        using type = ::std::uint16_t;\n      \
    \  static constexpr int shift = 11;\n        static constexpr type magic = UINT16_C(0x0F2D);\n\
    \        static constexpr int ntz_table[31] = {\n          16,  0, -1,  1, -1,\
    \  8, -1,  2, 14, -1, -1,  9, -1, 11, -1,  3,\n          15, -1,  7, -1, 13, -1,\
    \ 10, -1, -1,  6, 12, -1,  5, -1,  4,\n        };\n      };\n\n      template\
    \ <>\n      struct ntz_traits<32> {\n        using type = ::std::uint32_t;\n \
    \       static constexpr int shift = 26;\n        static constexpr type magic\
    \ = UINT32_C(0x07C56E99);\n        static constexpr int ntz_table[63] = {\n  \
    \        32,  0, -1,  1, -1, 10, -1,  2, 29, -1, 11, -1, 25, -1, -1,  3,\n   \
    \       30, -1, -1, 23, -1, 12, 14, -1, -1, 26, -1, 16, -1, 19, -1,  4,\n    \
    \      31, -1,  9, -1, 28, -1, 24, -1, -1, 22, -1, 13, -1, 15, 18, -1,\n     \
    \     -1,  8, 27, -1, 21, -1, -1, 17,  7, -1, 20, -1,  6, -1,  5\n        };\n\
    \      };\n\n      template <>\n      struct ntz_traits<64> {\n        using type\
    \ = ::std::uint64_t;\n        static constexpr int shift = 57;\n        static\
    \ constexpr type magic = UINT64_C(0x03F0A933ADCBD8D1);\n        static constexpr\
    \ int ntz_table[127] = {\n          64,  0, -1,  1, -1, 12, -1,  2, 60, -1, 13,\
    \ -1, -1, 53, -1,  3,\n          61, -1, -1, 21, -1, 14, -1, 42, -1, 24, 54, -1,\
    \ -1, 28, -1,  4,\n          62, -1, 58, -1, 19, -1, 22, -1, -1, 17, 15, -1, -1,\
    \ 33, -1, 43,\n          -1, 50, -1, 25, 55, -1, -1, 35, -1, 38, 29, -1, -1, 45,\
    \ -1,  5,\n          63, -1, 11, -1, 59, -1, 52, -1, -1, 20, -1, 41, 23, -1, 27,\
    \ -1,\n          -1, 57, 18, -1, 16, -1, 32, -1, 49, -1, -1, 34, 37, -1, 44, -1,\n\
    \          -1, 10, -1, 51, -1, 40, -1, 26, 56, -1, -1, 31, 48, -1, 36, -1,\n \
    \         9, -1, 39, -1, -1, 30, 47, -1,  8, -1, -1, 46,  7, -1,  6,\n       \
    \ };\n      };\n    }\n  }\n\n  template <typename T>\n  constexpr int countr_zero(const\
    \ T x) noexcept {\n    static_assert(::std::is_integral_v<T>);\n    if constexpr\
    \ (::std::is_signed_v<T>) {\n      assert(x >= 0);\n      return ::std::min(::tools::countr_zero<::std::make_unsigned_t<T>>(x),\
    \ ::std::numeric_limits<T>::digits);\n    } else {\n      using tr = ::tools::detail::countr_zero::ntz_traits<::std::numeric_limits<T>::digits>;\n\
    \      using type = typename tr::type;\n      return tr::ntz_table[static_cast<type>(tr::magic\
    \ * static_cast<type>(x & -x)) >> tr::shift];\n    }\n  }\n}\n\n\n#line 16 \"\
    tools/dynamic_bitset.hpp\"\n\nnamespace tools {\n  class dynamic_bitset {\n  private:\n\
    \    constexpr static ::std::size_t W = ::std::numeric_limits<::std::uint64_t>::digits;\n\
    \    ::std::size_t m_size;\n    ::std::vector<::std::uint64_t> m_bits;\n\n  public:\n\
    \    dynamic_bitset() : m_size(0) {}\n    dynamic_bitset(const ::tools::dynamic_bitset&)\
    \ = default;\n    dynamic_bitset(::tools::dynamic_bitset&&) = default;\n    ~dynamic_bitset()\
    \ = default;\n    ::tools::dynamic_bitset& operator=(const ::tools::dynamic_bitset&)\
    \ = default;\n    ::tools::dynamic_bitset& operator=(::tools::dynamic_bitset&&)\
    \ = default;\n\n    explicit dynamic_bitset(const ::std::size_t size) : m_size(size),\
    \ m_bits(::tools::ceil(size, W), 0) {}\n    explicit dynamic_bitset(const ::std::string&\
    \ str) : m_size(str.size()), m_bits(::tools::ceil(str.size(), W), 0) {\n     \
    \ for (::std::size_t i = 0; i < str.size(); ++i) {\n        const auto c = str[str.size()\
    \ - 1 - i];\n        assert(c == '0' || c == '1');\n        if (c == '1') {\n\
    \          this->m_bits[i / W] |= ::std::uint64_t(1) << (i % W);\n        }\n\
    \      }\n    }\n\n    ::tools::dynamic_bitset& operator&=(const ::tools::dynamic_bitset&\
    \ other) {\n      assert(this->m_size == other.m_size);\n      for (::std::size_t\
    \ i = 0; i < this->m_bits.size(); ++i) {\n        this->m_bits[i] &= other.m_bits[i];\n\
    \      }\n      return *this;\n    }\n    ::tools::dynamic_bitset& operator|=(const\
    \ ::tools::dynamic_bitset& other) {\n      assert(this->m_size == other.m_size);\n\
    \      for (::std::size_t i = 0; i < this->m_bits.size(); ++i) {\n        this->m_bits[i]\
    \ |= other.m_bits[i];\n      }\n      return *this;\n    }\n    ::tools::dynamic_bitset&\
    \ operator^=(const ::tools::dynamic_bitset& other) {\n      assert(this->m_size\
    \ == other.m_size);\n      for (::std::size_t i = 0; i < this->m_bits.size();\
    \ ++i) {\n        this->m_bits[i] ^= other.m_bits[i];\n      }\n      return *this;\n\
    \    }\n    ::tools::dynamic_bitset& operator<<=(const ::std::size_t pos) {\n\
    \      const ::std::size_t diff = pos / W;\n      if (diff < this->m_bits.size())\
    \ {\n        if (pos % W > 0) {\n          for (::std::size_t i = this->m_bits.size()\
    \ - diff; i --> 0;) {\n            this->m_bits[i] <<= pos % W;\n            if\
    \ (i > 0) {\n              this->m_bits[i] |= this->m_bits[i - 1] >> (W - pos\
    \ % W);\n            }\n          }\n        }\n        if (diff > 0) {\n    \
    \      for (::std::size_t i = this->m_bits.size() - diff; i --> 0;) {\n      \
    \      this->m_bits[i + diff] = this->m_bits[i];\n          }\n          ::std::fill(this->m_bits.begin(),\
    \ ::std::next(this->m_bits.begin(), diff), 0);\n        }\n        if (this->m_size\
    \ % W > 0) {\n          this->m_bits.back() &= (::std::uint64_t(1) << (this->m_size\
    \ % W)) - 1;\n        }\n      } else {\n        ::std::fill(this->m_bits.begin(),\
    \ this->m_bits.end(), 0);\n      }\n      return *this;\n    }\n    ::tools::dynamic_bitset&\
    \ operator>>=(const ::std::size_t pos) {\n      const ::std::size_t diff = pos\
    \ / W;\n      if (diff < this->m_bits.size()) {\n        if (pos % W > 0) {\n\
    \          for (::std::size_t i = diff; i < this->m_bits.size(); ++i) {\n    \
    \        this->m_bits[i] >>= pos % W;\n            if (i + 1 < this->m_bits.size())\
    \ {\n              this->m_bits[i] |= this->m_bits[i + 1] << (W - pos % W);\n\
    \            }\n          }\n        }\n        if (diff > 0) {\n          for\
    \ (::std::size_t i = diff; i < this->m_bits.size(); ++i) {\n            this->m_bits[i\
    \ - diff] = this->m_bits[i];\n          }\n          ::std::fill(::std::next(this->m_bits.begin(),\
    \ this->m_bits.size() - diff), this->m_bits.end(), 0);\n        }\n      } else\
    \ {\n        ::std::fill(this->m_bits.begin(), this->m_bits.end(), 0);\n     \
    \ }\n      return *this;\n    }\n    ::tools::dynamic_bitset& set() {\n      ::std::fill(this->m_bits.begin(),\
    \ this->m_bits.end(), ::std::numeric_limits<::std::uint64_t>::max());\n      if\
    \ (this->m_size % W > 0) {\n        this->m_bits.back() &= (::std::uint64_t(1)\
    \ << (this->m_size % W)) - 1;\n      }\n      return *this;\n    }\n    ::tools::dynamic_bitset&\
    \ set(const ::std::size_t pos) {\n      assert(pos < this->m_size);\n      this->m_bits[pos\
    \ / W] |= ::std::uint64_t(1) << (pos % W);\n      return *this;\n    }\n    ::tools::dynamic_bitset&\
    \ reset() {\n      ::std::fill(this->m_bits.begin(), this->m_bits.end(), 0);\n\
    \      return *this;\n    }\n    ::tools::dynamic_bitset& reset(const ::std::size_t\
    \ pos) {\n      assert(pos < this->m_size);\n      this->m_bits[pos / W] &= ~(::std::uint64_t(1)\
    \ << (pos % W));\n      return *this;\n    }\n    ::tools::dynamic_bitset& set(const\
    \ ::std::size_t pos, const bool val) {\n      return val ? this->set(pos) : this->reset(pos);\n\
    \    }\n    ::tools::dynamic_bitset& flip() {\n      for (::std::size_t i = 0;\
    \ i < this->m_bits.size(); ++i) {\n        this->m_bits[i] = ~this->m_bits[i];\n\
    \      }\n      if (this->m_size % W > 0) {\n        this->m_bits.back() &= (::std::uint64_t(1)\
    \ << (this->m_size % W)) - 1;\n      }\n      return *this;\n    }\n    ::tools::dynamic_bitset&\
    \ flip(const ::std::size_t pos) {\n      assert(pos < this->m_size);\n      this->m_bits[pos\
    \ / W] ^= ::std::uint64_t(1) << (pos % W);\n      return *this;\n    }\n    ::tools::dynamic_bitset\
    \ operator~() const {\n      return ::tools::dynamic_bitset(*this).flip();\n \
    \   }\n    ::std::size_t count() const {\n      ::std::size_t result = 0;\n  \
    \    for (::std::size_t i = 0; i < this->m_bits.size(); ++i) {\n        result\
    \ += ::tools::popcount(this->m_bits[i]);\n      }\n      return result;\n    }\n\
    \    ::std::size_t size() const {\n      return this->m_size;\n    }\n    bool\
    \ test(const ::std::size_t pos) const {\n      assert(pos < this->m_size);\n \
    \     return (this->m_bits[pos / W] >> (pos % W)) & 1;\n    }\n    bool operator[](const\
    \ ::std::size_t pos) const {\n      return this->test(pos);\n    }\n    bool all()\
    \ const {\n      if (this->m_size % W > 0) {\n        for (::std::size_t i = 0;\
    \ i + 1 < this->m_bits.size(); ++i) {\n          if (this->m_bits[i] != ::std::numeric_limits<::std::uint64_t>::max())\
    \ {\n            return false;\n          }\n        }\n        return this->m_bits.back()\
    \ == (::std::uint64_t(1) << (this->m_size % W)) - 1;\n      } else {\n       \
    \ for (::std::size_t i = 0; i < this->m_bits.size(); ++i) {\n          if (this->m_bits[i]\
    \ != ::std::numeric_limits<::std::uint64_t>::max()) {\n            return false;\n\
    \          }\n        }\n        return true;\n      }\n    }\n    bool any()\
    \ const {\n      for (::std::size_t i = 0; i < this->m_bits.size(); ++i) {\n \
    \       if (this->m_bits[i] != 0) {\n          return true;\n        }\n     \
    \ }\n      return false;\n    }\n    bool none() const {\n      return !this->any();\n\
    \    }\n    friend bool operator==(const ::tools::dynamic_bitset& lhs, const ::tools::dynamic_bitset&\
    \ rhs) {\n      return lhs.m_size == rhs.m_size && lhs.m_bits == rhs.m_bits;\n\
    \    }\n    friend bool operator!=(const ::tools::dynamic_bitset& lhs, const ::tools::dynamic_bitset&\
    \ rhs) {\n      return !(lhs == rhs);\n    }\n    ::tools::dynamic_bitset operator<<(const\
    \ ::std::size_t pos) const {\n      return ::tools::dynamic_bitset(*this) <<=\
    \ pos;\n    }\n    ::tools::dynamic_bitset operator>>(const ::std::size_t pos)\
    \ const {\n      return ::tools::dynamic_bitset(*this) >>= pos;\n    }\n    friend\
    \ ::tools::dynamic_bitset operator&(const ::tools::dynamic_bitset& lhs, const\
    \ ::tools::dynamic_bitset& rhs) {\n      return ::tools::dynamic_bitset(lhs) &=\
    \ rhs;\n    }\n    friend ::tools::dynamic_bitset operator|(const ::tools::dynamic_bitset&\
    \ lhs, const ::tools::dynamic_bitset& rhs) {\n      return ::tools::dynamic_bitset(lhs)\
    \ |= rhs;\n    }\n    friend ::tools::dynamic_bitset operator^(const ::tools::dynamic_bitset&\
    \ lhs, const ::tools::dynamic_bitset& rhs) {\n      return ::tools::dynamic_bitset(lhs)\
    \ ^= rhs;\n    }\n    friend ::std::istream& operator>>(::std::istream& is, ::tools::dynamic_bitset&\
    \ self) {\n      ::std::string s;\n      is >> s;\n      self = ::tools::dynamic_bitset(s);\n\
    \      return is;\n    }\n    friend ::std::ostream& operator<<(::std::ostream&\
    \ os, const ::tools::dynamic_bitset& self) {\n      for (::std::size_t i = self.m_bits.size();\
    \ i --> 0;) {\n        for (::std::size_t j = (self.m_size - 1) % W + 1; j -->\
    \ 0;) {\n          os << ((self.m_bits[i] >> j) & 1);\n        }\n      }\n  \
    \    return os;\n    }\n    void resize(const ::std::size_t size) {\n      this->m_size\
    \ = size;\n      this->m_bits.resize(::tools::ceil(size, W));\n      if (size\
    \ % W > 0) {\n        this->m_bits.back() &= (::std::uint64_t(1) << (size % W))\
    \ - 1;\n      }\n    }\n    void shrink_to_fit() {\n      this->m_bits.shrink_to_fit();\n\
    \    }\n  private:\n    ::std::size_t Find_first(const ::std::size_t offset) const\
    \ {\n      for (::std::size_t i = offset; i < this->m_bits.size(); ++i) {\n  \
    \      if (this->m_bits[i] > 0) {\n          return i * W + ::tools::countr_zero(this->m_bits[i]);\n\
    \        }\n      }\n      return this->m_size;\n    }\n  public:\n    ::std::size_t\
    \ Find_first() const {\n      return this->Find_first(0);\n    }\n    ::std::size_t\
    \ Find_next(const ::std::size_t pos) const {\n      assert(pos < this->m_size);\n\
    \n      if (pos % W == W - 1) return this->Find_first((pos + 1) / W);\n      if\
    \ (const auto x = this->m_bits[pos / W] >> (pos % W + 1); x > 0) return pos +\
    \ ::tools::countr_zero(x) + 1;\n      return this->Find_first(pos / W + 1);\n\
    \    }\n  };\n}\n\n\n#line 15 \"tools/dijkstra.hpp\"\n\nnamespace tools {\n\n\
    \  template <bool Directed, typename T>\n  class dijkstra {\n  public:\n    struct\
    \ edge {\n      ::std::size_t id;\n      ::std::size_t from;\n      ::std::size_t\
    \ to;\n      T cost;\n    };\n\n  private:\n    ::std::vector<edge> m_edges;\n\
    \    ::std::vector<::std::vector<::std::size_t>> m_graph;\n\n  public:\n    dijkstra()\
    \ = default;\n    dijkstra(const ::tools::dijkstra<Directed, T>&) = default;\n\
    \    dijkstra(::tools::dijkstra<Directed, T>&&) = default;\n    ~dijkstra() =\
    \ default;\n    ::tools::dijkstra<Directed, T>& operator=(const ::tools::dijkstra<Directed,\
    \ T>&) = default;\n    ::tools::dijkstra<Directed, T>& operator=(::tools::dijkstra<Directed,\
    \ T>&&) = default;\n\n    dijkstra(const ::std::size_t n) : m_graph(n) {\n   \
    \ }\n\n    ::std::size_t size() const {\n      return this->m_graph.size();\n\
    \    }\n\n    ::std::size_t add_edge(::std::size_t u, ::std::size_t v, const T&\
    \ w) {\n      assert(u < this->size());\n      assert(v < this->size());\n   \
    \   assert(w >= 0);\n      if constexpr (!Directed) {\n        ::std::tie(u, v)\
    \ = ::std::minmax({u, v});\n      }\n      this->m_edges.push_back(edge({this->m_edges.size(),\
    \ u, v, w}));\n      this->m_graph[u].push_back(this->m_edges.size() - 1);\n \
    \     if constexpr (!Directed) {\n        this->m_graph[v].push_back(this->m_edges.size()\
    \ - 1);\n      }\n      return this->m_edges.size() - 1;\n    }\n\n    const edge&\
    \ get_edge(const ::std::size_t k) const {\n      assert(k < this->m_edges.size());\n\
    \      return this->m_edges[k];\n    }\n\n    const ::std::vector<edge>& edges()\
    \ const {\n      return this->m_edges;\n    }\n\n    ::std::pair<::std::vector<T>,\
    \ ::std::vector<::std::size_t>> query(const ::std::size_t s) {\n      assert(s\
    \ < this->size());\n\n      ::std::vector<T> dist(this->size(), ::std::numeric_limits<T>::max());\n\
    \      dist[s] = 0;\n      ::std::vector<::std::size_t> prev(this->size());\n\
    \      prev[s] = ::std::numeric_limits<::std::size_t>::max();\n\n      if ((this->size()\
    \ + this->m_edges.size()) * ::tools::ceil_log2(this->size()) < this->size() *\
    \ this->size() + this->m_edges.size()) {\n        // Dijkstra for sparse graph:\
    \ O((|V| + |E|) log|V|)\n\n        ::std::priority_queue<::std::pair<::std::size_t,\
    \ T>, ::std::vector<::std::pair<::std::size_t, T>>, ::tools::greater_by_second>\
    \ pq;\n        pq.emplace(s, 0);\n\n        while (!pq.empty()) {\n          const\
    \ auto [here, d] = pq.top();\n          pq.pop();\n          if (dist[here] <\
    \ d) continue;\n          for (const auto edge_id : this->m_graph[here]) {\n \
    \           const auto& edge = this->m_edges[edge_id];\n            const auto\
    \ next = edge.to ^ (Directed ? 0 : edge.from ^ here);\n            if (::tools::chmin(dist[next],\
    \ dist[here] + edge.cost)) {\n              prev[next] = edge.id;\n          \
    \    pq.emplace(next, dist[next]);\n            }\n          }\n        }\n\n\
    \      } else {\n        // Dijkstra for dense graph: O(|V|^2 + |E|)\n\n     \
    \   auto matrix = ::std::vector(this->size(), ::std::vector(this->size(), ::std::numeric_limits<::std::size_t>::max()));\n\
    \        for (const auto& edge : this->m_edges) {\n          if (matrix[edge.from][edge.to]\
    \ == ::std::numeric_limits<::std::size_t>::max() || edge.cost < this->m_edges[matrix[edge.from][edge.to]].cost)\
    \ {\n            matrix[edge.from][edge.to] = edge.id;\n          }\n        }\n\
    \n        ::tools::dynamic_bitset Q(this->size());\n        Q.set();\n       \
    \ ::std::size_t v;\n        while ((v = Q.Find_first()) < this->size()) {\n  \
    \        ::std::size_t here;\n          T d = ::std::numeric_limits<T>::max();\n\
    \          for (; v < this->size(); v = Q.Find_next(v)) {\n            if (::tools::chmin(d,\
    \ dist[v])) {\n              here = v;\n            }\n          }\n         \
    \ if (d == ::std::numeric_limits<T>::max()) break;\n          Q.reset(here);\n\
    \n          for (v = Q.Find_first(); v < this->size(); v = Q.Find_next(v)) {\n\
    \            if (matrix[here][v] != ::std::numeric_limits<::std::size_t>::max()\
    \ && ::tools::chmin(dist[v], dist[here] + this->m_edges[matrix[here][v]].cost))\
    \ {\n              prev[v] = matrix[here][v];\n            }\n          }\n  \
    \      }\n\n      }\n\n      return ::std::make_pair(dist, prev);\n    }\n  };\n\
    }\n\n\n#line 8 \"tests/dijkstra/undirected.test.cpp\"\n\nint main() {\n  std::cin.tie(nullptr);\n\
    \  std::ios_base::sync_with_stdio(false);\n\n  int N, X, Y;\n  std::cin >> N >>\
    \ X >> Y;\n  --X, --Y;\n  tools::dijkstra<false, int> graph(N);\n  for (int i\
    \ = 0; i < N - 1; ++i) {\n    int U, V;\n    std::cin >> U >> V;\n    --U, --V;\n\
    \    graph.add_edge(U, V, 1);\n  }\n\n  const auto prev = graph.query(Y).second;\n\
    \  std::string delimiter;\n  for (int here = X; here >= 0; here = (prev[here]\
    \ < std::numeric_limits<std::size_t>::max() ? graph.get_edge(prev[here]).from\
    \ ^ graph.get_edge(prev[here]).to ^ here : -1)) {\n    std::cout << delimiter\
    \ << here + 1;\n    delimiter = \" \";\n  }\n  std::cout << '\\n';\n\n  return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc270/tasks/abc270_c\"\n\n\
    #include <iostream>\n#include <string>\n#include <limits>\n#include <cstddef>\n\
    #include \"tools/dijkstra.hpp\"\n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  int N, X, Y;\n  std::cin >> N >> X >> Y;\n  --X, --Y;\n  tools::dijkstra<false,\
    \ int> graph(N);\n  for (int i = 0; i < N - 1; ++i) {\n    int U, V;\n    std::cin\
    \ >> U >> V;\n    --U, --V;\n    graph.add_edge(U, V, 1);\n  }\n\n  const auto\
    \ prev = graph.query(Y).second;\n  std::string delimiter;\n  for (int here = X;\
    \ here >= 0; here = (prev[here] < std::numeric_limits<std::size_t>::max() ? graph.get_edge(prev[here]).from\
    \ ^ graph.get_edge(prev[here]).to ^ here : -1)) {\n    std::cout << delimiter\
    \ << here + 1;\n    delimiter = \" \";\n  }\n  std::cout << '\\n';\n\n  return\
    \ 0;\n}\n"
  dependsOn:
  - tools/dijkstra.hpp
  - tools/ceil_log2.hpp
  - tools/greater_by_second.hpp
  - tools/chmin.hpp
  - tools/dynamic_bitset.hpp
  - tools/ceil.hpp
  - tools/popcount.hpp
  - tools/countr_zero.hpp
  isVerificationFile: true
  path: tests/dijkstra/undirected.test.cpp
  requiredBy: []
  timestamp: '2024-02-17 19:44:56+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/dijkstra/undirected.test.cpp
layout: document
redirect_from:
- /verify/tests/dijkstra/undirected.test.cpp
- /verify/tests/dijkstra/undirected.test.cpp.html
title: tests/dijkstra/undirected.test.cpp
---
