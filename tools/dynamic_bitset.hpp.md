---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: tools/ceil.hpp
    title: $\left\lceil \frac{x}{y} \right\rceil$
  - icon: ':question:'
    path: tools/countr_zero.hpp
    title: Number of trailing zeros
  - icon: ':question:'
    path: tools/popcount.hpp
    title: Popcount
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: tests/rotate_left.test.cpp
    title: tests/rotate_left.test.cpp
  - icon: ':x:'
    path: tests/rotate_right.test.cpp
    title: tests/rotate_right.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/scc_graph/edges_to_scc.test.cpp
    title: tests/scc_graph/edges_to_scc.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/dynamic_bitset.hpp\"\n\n\n\n#include <cstddef>\n#include\
    \ <limits>\n#include <cstdint>\n#include <vector>\n#include <string>\n#include\
    \ <cassert>\n#include <algorithm>\n#include <iterator>\n#include <sstream>\n#include\
    \ <iostream>\n#line 1 \"tools/ceil.hpp\"\n\n\n\n#include <type_traits>\n#line\
    \ 6 \"tools/ceil.hpp\"\n\nnamespace tools {\n\n  template <typename M, typename\
    \ N>\n  constexpr ::std::common_type_t<M, N> ceil(const M lhs, const N rhs) {\n\
    \    using T = ::std::common_type_t<M, N>;\n    assert(rhs != N(0));\n    return\
    \ lhs / rhs + T(((lhs > M(0) && rhs > N(0)) || (lhs < M(0) && rhs < N(0))) &&\
    \ lhs % rhs);\n  }\n}\n\n\n#line 1 \"tools/popcount.hpp\"\n\n\n\n#line 8 \"tools/popcount.hpp\"\
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
    \ * static_cast<type>(x & -x)) >> tr::shift];\n    }\n  }\n}\n\n\n#line 17 \"\
    tools/dynamic_bitset.hpp\"\n\nnamespace tools {\n  class dynamic_bitset {\n  \
    \  constexpr static ::std::size_t W = ::std::numeric_limits<::std::uint64_t>::digits;\n\
    \    ::std::size_t m_size;\n    ::std::vector<::std::uint64_t> m_bits;\n\n  public:\n\
    \    class reference {\n      friend class ::tools::dynamic_bitset;\n\n      ::tools::dynamic_bitset\
    \ *m_parent;\n      ::std::size_t m_pos;\n\n      reference(::tools::dynamic_bitset\
    \ * const parent, const ::std::size_t pos) : m_parent(parent), m_pos(pos) {\n\
    \      }\n\n    public:\n      reference(const reference&) = default;\n      reference&\
    \ operator=(const bool x) {\n        this->m_parent->set(this->m_pos, x);\n  \
    \      return *this;\n      }\n      reference& operator=(const reference& other)\
    \ {\n        return *this = static_cast<bool>(other);\n      }\n      bool operator~()\
    \ const {\n        return !static_cast<bool>(*this);\n      }\n      operator\
    \ bool() const {\n        return this->m_parent->test(this->m_pos);\n      }\n\
    \      reference& flip() {\n        this->m_parent->flip(this->m_pos);\n     \
    \   return *this;\n      }\n    };\n\n    dynamic_bitset() : m_size(0) {}\n  \
    \  explicit dynamic_bitset(const ::std::size_t size) : m_size(size), m_bits(::tools::ceil(size,\
    \ W), 0) {}\n    explicit dynamic_bitset(const ::std::string& str) : m_size(str.size()),\
    \ m_bits(::tools::ceil(str.size(), W), 0) {\n      for (::std::size_t i = 0; i\
    \ < str.size(); ++i) {\n        const auto c = str[str.size() - 1 - i];\n    \
    \    assert(c == '0' || c == '1');\n        if (c == '1') {\n          this->m_bits[i\
    \ / W] |= UINT64_C(1) << (i % W);\n        }\n      }\n    }\n\n    ::tools::dynamic_bitset&\
    \ operator&=(const ::tools::dynamic_bitset& other) {\n      assert(this->m_size\
    \ == other.m_size);\n      for (::std::size_t i = 0; i < this->m_bits.size();\
    \ ++i) {\n        this->m_bits[i] &= other.m_bits[i];\n      }\n      return *this;\n\
    \    }\n    ::tools::dynamic_bitset& operator|=(const ::tools::dynamic_bitset&\
    \ other) {\n      assert(this->m_size == other.m_size);\n      for (::std::size_t\
    \ i = 0; i < this->m_bits.size(); ++i) {\n        this->m_bits[i] |= other.m_bits[i];\n\
    \      }\n      return *this;\n    }\n    ::tools::dynamic_bitset& operator^=(const\
    \ ::tools::dynamic_bitset& other) {\n      assert(this->m_size == other.m_size);\n\
    \      for (::std::size_t i = 0; i < this->m_bits.size(); ++i) {\n        this->m_bits[i]\
    \ ^= other.m_bits[i];\n      }\n      return *this;\n    }\n    ::tools::dynamic_bitset&\
    \ operator<<=(const ::std::size_t pos) {\n      const ::std::size_t diff = pos\
    \ / W;\n      if (diff < this->m_bits.size()) {\n        if (pos % W > 0) {\n\
    \          for (::std::size_t i = this->m_bits.size() - diff; i --> 0;) {\n  \
    \          this->m_bits[i] <<= pos % W;\n            if (i > 0) {\n          \
    \    this->m_bits[i] |= this->m_bits[i - 1] >> (W - pos % W);\n            }\n\
    \          }\n        }\n        if (diff > 0) {\n          for (::std::size_t\
    \ i = this->m_bits.size() - diff; i --> 0;) {\n            this->m_bits[i + diff]\
    \ = this->m_bits[i];\n          }\n          ::std::fill(this->m_bits.begin(),\
    \ ::std::next(this->m_bits.begin(), diff), 0);\n        }\n        if (this->m_size\
    \ % W > 0) {\n          this->m_bits.back() &= (UINT64_C(1) << (this->m_size %\
    \ W)) - 1;\n        }\n      } else {\n        ::std::fill(this->m_bits.begin(),\
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
    \ (this->m_size % W > 0) {\n        this->m_bits.back() &= (UINT64_C(1) << (this->m_size\
    \ % W)) - 1;\n      }\n      return *this;\n    }\n    ::tools::dynamic_bitset&\
    \ set(const ::std::size_t pos) {\n      assert(pos < this->m_size);\n      this->m_bits[pos\
    \ / W] |= UINT64_C(1) << (pos % W);\n      return *this;\n    }\n    ::tools::dynamic_bitset&\
    \ set(const ::std::size_t pos, const bool val) {\n      return val ? this->set(pos)\
    \ : this->reset(pos);\n    }\n    ::tools::dynamic_bitset& reset() {\n      ::std::fill(this->m_bits.begin(),\
    \ this->m_bits.end(), 0);\n      return *this;\n    }\n    ::tools::dynamic_bitset&\
    \ reset(const ::std::size_t pos) {\n      assert(pos < this->m_size);\n      this->m_bits[pos\
    \ / W] &= ~(UINT64_C(1) << (pos % W));\n      return *this;\n    }\n    ::tools::dynamic_bitset\
    \ operator~() const {\n      return ::tools::dynamic_bitset(*this).flip();\n \
    \   }\n    ::tools::dynamic_bitset& flip() {\n      for (::std::size_t i = 0;\
    \ i < this->m_bits.size(); ++i) {\n        this->m_bits[i] = ~this->m_bits[i];\n\
    \      }\n      if (this->m_size % W > 0) {\n        this->m_bits.back() &= (UINT64_C(1)\
    \ << (this->m_size % W)) - 1;\n      }\n      return *this;\n    }\n    ::tools::dynamic_bitset&\
    \ flip(const ::std::size_t pos) {\n      assert(pos < this->m_size);\n      this->m_bits[pos\
    \ / W] ^= UINT64_C(1) << (pos % W);\n      return *this;\n    }\n    reference\
    \ operator[](const ::std::size_t pos) {\n      return reference(this, pos);\n\
    \    }\n    bool operator[](const ::std::size_t pos) const {\n      return this->test(pos);\n\
    \    }\n    ::std::size_t count() const {\n      ::std::size_t result = 0;\n \
    \     for (::std::size_t i = 0; i < this->m_bits.size(); ++i) {\n        result\
    \ += ::tools::popcount(this->m_bits[i]);\n      }\n      return result;\n    }\n\
    \    ::std::size_t size() const {\n      return this->m_size;\n    }\n    bool\
    \ test(const ::std::size_t pos) const {\n      assert(pos < this->m_size);\n \
    \     return (this->m_bits[pos / W] >> (pos % W)) & 1;\n    }\n    bool all()\
    \ const {\n      if (this->m_size % W > 0) {\n        for (::std::size_t i = 0;\
    \ i + 1 < this->m_bits.size(); ++i) {\n          if (this->m_bits[i] != ::std::numeric_limits<::std::uint64_t>::max())\
    \ {\n            return false;\n          }\n        }\n        return this->m_bits.back()\
    \ == (UINT64_C(1) << (this->m_size % W)) - 1;\n      } else {\n        for (::std::size_t\
    \ i = 0; i < this->m_bits.size(); ++i) {\n          if (this->m_bits[i] != ::std::numeric_limits<::std::uint64_t>::max())\
    \ {\n            return false;\n          }\n        }\n        return true;\n\
    \      }\n    }\n    bool any() const {\n      for (::std::size_t i = 0; i < this->m_bits.size();\
    \ ++i) {\n        if (this->m_bits[i] != 0) {\n          return true;\n      \
    \  }\n      }\n      return false;\n    }\n    bool none() const {\n      return\
    \ !this->any();\n    }\n    ::std::string to_string() const {\n      ::std::ostringstream\
    \ oss;\n      oss << *this;\n      return oss.str();\n    }\n    friend bool operator==(const\
    \ ::tools::dynamic_bitset& lhs, const ::tools::dynamic_bitset& rhs) {\n      return\
    \ lhs.m_size == rhs.m_size && lhs.m_bits == rhs.m_bits;\n    }\n    friend bool\
    \ operator!=(const ::tools::dynamic_bitset& lhs, const ::tools::dynamic_bitset&\
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
    \ i --> 0;) {\n        for (::std::size_t j = i + 1 < self.m_bits.size() ? W :\
    \ (self.m_size - 1) % W + 1; j --> 0;) {\n          os << ((self.m_bits[i] >>\
    \ j) & 1);\n        }\n      }\n      return os;\n    }\n    void resize(const\
    \ ::std::size_t size) {\n      this->m_size = size;\n      this->m_bits.resize(::tools::ceil(size,\
    \ W));\n      if (size % W > 0) {\n        this->m_bits.back() &= (UINT64_C(1)\
    \ << (size % W)) - 1;\n      }\n    }\n    void shrink_to_fit() {\n      this->m_bits.shrink_to_fit();\n\
    \    }\n  private:\n    ::std::size_t Find_first(const ::std::size_t offset) const\
    \ {\n      for (::std::size_t i = offset; i < this->m_bits.size(); ++i) {\n  \
    \      if (this->m_bits[i] > 0) {\n          return i * W + ::tools::countr_zero(this->m_bits[i]);\n\
    \        }\n      }\n      return this->m_size;\n    }\n  public:\n    ::std::size_t\
    \ Find_first() const {\n      return this->Find_first(0);\n    }\n    ::std::size_t\
    \ Find_next(const ::std::size_t pos) const {\n      assert(pos < this->m_size);\n\
    \n      if (pos % W == W - 1) return this->Find_first((pos + 1) / W);\n      if\
    \ (const auto x = this->m_bits[pos / W] >> (pos % W + 1); x > 0) return pos +\
    \ ::tools::countr_zero(x) + 1;\n      return this->Find_first(pos / W + 1);\n\
    \    }\n  };\n}\n\n\n"
  code: "#ifndef TOOLS_DYNAMIC_BITSET_HPP\n#define TOOLS_DYNAMIC_BITSET_HPP\n\n#include\
    \ <cstddef>\n#include <limits>\n#include <cstdint>\n#include <vector>\n#include\
    \ <string>\n#include <cassert>\n#include <algorithm>\n#include <iterator>\n#include\
    \ <sstream>\n#include <iostream>\n#include \"tools/ceil.hpp\"\n#include \"tools/popcount.hpp\"\
    \n#include \"tools/countr_zero.hpp\"\n\nnamespace tools {\n  class dynamic_bitset\
    \ {\n    constexpr static ::std::size_t W = ::std::numeric_limits<::std::uint64_t>::digits;\n\
    \    ::std::size_t m_size;\n    ::std::vector<::std::uint64_t> m_bits;\n\n  public:\n\
    \    class reference {\n      friend class ::tools::dynamic_bitset;\n\n      ::tools::dynamic_bitset\
    \ *m_parent;\n      ::std::size_t m_pos;\n\n      reference(::tools::dynamic_bitset\
    \ * const parent, const ::std::size_t pos) : m_parent(parent), m_pos(pos) {\n\
    \      }\n\n    public:\n      reference(const reference&) = default;\n      reference&\
    \ operator=(const bool x) {\n        this->m_parent->set(this->m_pos, x);\n  \
    \      return *this;\n      }\n      reference& operator=(const reference& other)\
    \ {\n        return *this = static_cast<bool>(other);\n      }\n      bool operator~()\
    \ const {\n        return !static_cast<bool>(*this);\n      }\n      operator\
    \ bool() const {\n        return this->m_parent->test(this->m_pos);\n      }\n\
    \      reference& flip() {\n        this->m_parent->flip(this->m_pos);\n     \
    \   return *this;\n      }\n    };\n\n    dynamic_bitset() : m_size(0) {}\n  \
    \  explicit dynamic_bitset(const ::std::size_t size) : m_size(size), m_bits(::tools::ceil(size,\
    \ W), 0) {}\n    explicit dynamic_bitset(const ::std::string& str) : m_size(str.size()),\
    \ m_bits(::tools::ceil(str.size(), W), 0) {\n      for (::std::size_t i = 0; i\
    \ < str.size(); ++i) {\n        const auto c = str[str.size() - 1 - i];\n    \
    \    assert(c == '0' || c == '1');\n        if (c == '1') {\n          this->m_bits[i\
    \ / W] |= UINT64_C(1) << (i % W);\n        }\n      }\n    }\n\n    ::tools::dynamic_bitset&\
    \ operator&=(const ::tools::dynamic_bitset& other) {\n      assert(this->m_size\
    \ == other.m_size);\n      for (::std::size_t i = 0; i < this->m_bits.size();\
    \ ++i) {\n        this->m_bits[i] &= other.m_bits[i];\n      }\n      return *this;\n\
    \    }\n    ::tools::dynamic_bitset& operator|=(const ::tools::dynamic_bitset&\
    \ other) {\n      assert(this->m_size == other.m_size);\n      for (::std::size_t\
    \ i = 0; i < this->m_bits.size(); ++i) {\n        this->m_bits[i] |= other.m_bits[i];\n\
    \      }\n      return *this;\n    }\n    ::tools::dynamic_bitset& operator^=(const\
    \ ::tools::dynamic_bitset& other) {\n      assert(this->m_size == other.m_size);\n\
    \      for (::std::size_t i = 0; i < this->m_bits.size(); ++i) {\n        this->m_bits[i]\
    \ ^= other.m_bits[i];\n      }\n      return *this;\n    }\n    ::tools::dynamic_bitset&\
    \ operator<<=(const ::std::size_t pos) {\n      const ::std::size_t diff = pos\
    \ / W;\n      if (diff < this->m_bits.size()) {\n        if (pos % W > 0) {\n\
    \          for (::std::size_t i = this->m_bits.size() - diff; i --> 0;) {\n  \
    \          this->m_bits[i] <<= pos % W;\n            if (i > 0) {\n          \
    \    this->m_bits[i] |= this->m_bits[i - 1] >> (W - pos % W);\n            }\n\
    \          }\n        }\n        if (diff > 0) {\n          for (::std::size_t\
    \ i = this->m_bits.size() - diff; i --> 0;) {\n            this->m_bits[i + diff]\
    \ = this->m_bits[i];\n          }\n          ::std::fill(this->m_bits.begin(),\
    \ ::std::next(this->m_bits.begin(), diff), 0);\n        }\n        if (this->m_size\
    \ % W > 0) {\n          this->m_bits.back() &= (UINT64_C(1) << (this->m_size %\
    \ W)) - 1;\n        }\n      } else {\n        ::std::fill(this->m_bits.begin(),\
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
    \ (this->m_size % W > 0) {\n        this->m_bits.back() &= (UINT64_C(1) << (this->m_size\
    \ % W)) - 1;\n      }\n      return *this;\n    }\n    ::tools::dynamic_bitset&\
    \ set(const ::std::size_t pos) {\n      assert(pos < this->m_size);\n      this->m_bits[pos\
    \ / W] |= UINT64_C(1) << (pos % W);\n      return *this;\n    }\n    ::tools::dynamic_bitset&\
    \ set(const ::std::size_t pos, const bool val) {\n      return val ? this->set(pos)\
    \ : this->reset(pos);\n    }\n    ::tools::dynamic_bitset& reset() {\n      ::std::fill(this->m_bits.begin(),\
    \ this->m_bits.end(), 0);\n      return *this;\n    }\n    ::tools::dynamic_bitset&\
    \ reset(const ::std::size_t pos) {\n      assert(pos < this->m_size);\n      this->m_bits[pos\
    \ / W] &= ~(UINT64_C(1) << (pos % W));\n      return *this;\n    }\n    ::tools::dynamic_bitset\
    \ operator~() const {\n      return ::tools::dynamic_bitset(*this).flip();\n \
    \   }\n    ::tools::dynamic_bitset& flip() {\n      for (::std::size_t i = 0;\
    \ i < this->m_bits.size(); ++i) {\n        this->m_bits[i] = ~this->m_bits[i];\n\
    \      }\n      if (this->m_size % W > 0) {\n        this->m_bits.back() &= (UINT64_C(1)\
    \ << (this->m_size % W)) - 1;\n      }\n      return *this;\n    }\n    ::tools::dynamic_bitset&\
    \ flip(const ::std::size_t pos) {\n      assert(pos < this->m_size);\n      this->m_bits[pos\
    \ / W] ^= UINT64_C(1) << (pos % W);\n      return *this;\n    }\n    reference\
    \ operator[](const ::std::size_t pos) {\n      return reference(this, pos);\n\
    \    }\n    bool operator[](const ::std::size_t pos) const {\n      return this->test(pos);\n\
    \    }\n    ::std::size_t count() const {\n      ::std::size_t result = 0;\n \
    \     for (::std::size_t i = 0; i < this->m_bits.size(); ++i) {\n        result\
    \ += ::tools::popcount(this->m_bits[i]);\n      }\n      return result;\n    }\n\
    \    ::std::size_t size() const {\n      return this->m_size;\n    }\n    bool\
    \ test(const ::std::size_t pos) const {\n      assert(pos < this->m_size);\n \
    \     return (this->m_bits[pos / W] >> (pos % W)) & 1;\n    }\n    bool all()\
    \ const {\n      if (this->m_size % W > 0) {\n        for (::std::size_t i = 0;\
    \ i + 1 < this->m_bits.size(); ++i) {\n          if (this->m_bits[i] != ::std::numeric_limits<::std::uint64_t>::max())\
    \ {\n            return false;\n          }\n        }\n        return this->m_bits.back()\
    \ == (UINT64_C(1) << (this->m_size % W)) - 1;\n      } else {\n        for (::std::size_t\
    \ i = 0; i < this->m_bits.size(); ++i) {\n          if (this->m_bits[i] != ::std::numeric_limits<::std::uint64_t>::max())\
    \ {\n            return false;\n          }\n        }\n        return true;\n\
    \      }\n    }\n    bool any() const {\n      for (::std::size_t i = 0; i < this->m_bits.size();\
    \ ++i) {\n        if (this->m_bits[i] != 0) {\n          return true;\n      \
    \  }\n      }\n      return false;\n    }\n    bool none() const {\n      return\
    \ !this->any();\n    }\n    ::std::string to_string() const {\n      ::std::ostringstream\
    \ oss;\n      oss << *this;\n      return oss.str();\n    }\n    friend bool operator==(const\
    \ ::tools::dynamic_bitset& lhs, const ::tools::dynamic_bitset& rhs) {\n      return\
    \ lhs.m_size == rhs.m_size && lhs.m_bits == rhs.m_bits;\n    }\n    friend bool\
    \ operator!=(const ::tools::dynamic_bitset& lhs, const ::tools::dynamic_bitset&\
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
    \ i --> 0;) {\n        for (::std::size_t j = i + 1 < self.m_bits.size() ? W :\
    \ (self.m_size - 1) % W + 1; j --> 0;) {\n          os << ((self.m_bits[i] >>\
    \ j) & 1);\n        }\n      }\n      return os;\n    }\n    void resize(const\
    \ ::std::size_t size) {\n      this->m_size = size;\n      this->m_bits.resize(::tools::ceil(size,\
    \ W));\n      if (size % W > 0) {\n        this->m_bits.back() &= (UINT64_C(1)\
    \ << (size % W)) - 1;\n      }\n    }\n    void shrink_to_fit() {\n      this->m_bits.shrink_to_fit();\n\
    \    }\n  private:\n    ::std::size_t Find_first(const ::std::size_t offset) const\
    \ {\n      for (::std::size_t i = offset; i < this->m_bits.size(); ++i) {\n  \
    \      if (this->m_bits[i] > 0) {\n          return i * W + ::tools::countr_zero(this->m_bits[i]);\n\
    \        }\n      }\n      return this->m_size;\n    }\n  public:\n    ::std::size_t\
    \ Find_first() const {\n      return this->Find_first(0);\n    }\n    ::std::size_t\
    \ Find_next(const ::std::size_t pos) const {\n      assert(pos < this->m_size);\n\
    \n      if (pos % W == W - 1) return this->Find_first((pos + 1) / W);\n      if\
    \ (const auto x = this->m_bits[pos / W] >> (pos % W + 1); x > 0) return pos +\
    \ ::tools::countr_zero(x) + 1;\n      return this->Find_first(pos / W + 1);\n\
    \    }\n  };\n}\n\n#endif\n"
  dependsOn:
  - tools/ceil.hpp
  - tools/popcount.hpp
  - tools/countr_zero.hpp
  isVerificationFile: false
  path: tools/dynamic_bitset.hpp
  requiredBy: []
  timestamp: '2024-03-22 23:44:26+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - tests/rotate_right.test.cpp
  - tests/scc_graph/edges_to_scc.test.cpp
  - tests/rotate_left.test.cpp
documentation_of: tools/dynamic_bitset.hpp
layout: document
title: std::bitset with dynamic size
---

It is a sequence of bits of length $n$ determined at runtime.
Its interface is compatible to that of `std::bitset`.

### License
- CC0

### Author
- anqooqie

## Methods based on std::bitset
```cpp
dynamic_bitset s();
dynamic_bitset s(const dynamic_bitset& t);
dynamic_bitset s(dynamic_bitset&& t);
dynamic_bitset& s.operator=(const dynamic_bitset& t);
dynamic_bitset& s.operator=(dynamic_bitset&& t);

dynamic_bitset s(std::size_t n);
dynamic_bitset s(const std::string& str);

dynamic_bitset& s.operator&=(const dynamic_bitset& t);
dynamic_bitset& s.operator|=(const dynamic_bitset& t);
dynamic_bitset& s.operator^=(const dynamic_bitset& t);
dynamic_bitset& s.operator<<=(std::size_t pos);
dynamic_bitset& s.operator>>=(std::size_t pos);
dynamic_bitset& s.set();
dynamic_bitset& s.set(std::size_t pos);
dynamic_bitset& s.set(std::size_t pos, bool val);
dynamic_bitset& s.reset();
dynamic_bitset& s.reset(std::size_t pos);
dynamic_bitset s.operator~() const;
dynamic_bitset& s.flip();
dynamic_bitset& s.flip(std::size_t pos);

typename dynamic_bitset::reference s.operator[](std::size_t pos);
bool s.operator[](std::size_t pos) const;
std::size_t s.count() const;
std::size_t s.size() const;
bool s.test(std::size_t pos) const;
bool s.all() const;
bool s.any() const;
bool s.none() const;
std::string s.to_string() const;
bool operator==(const dynamic_bitset& s, const dynamic_bitset& t);
bool operator!=(const dynamic_bitset& s, const dynamic_bitset& t);
dynamic_bitset s.operator<<(std::size_t pos) const;
dynamic_bitset s.operator>>(std::size_t pos) const;

dynamic_bitset operator&(const dynamic_bitset& s, const dynamic_bitset& t);
dynamic_bitset operator|(const dynamic_bitset& s, const dynamic_bitset& t);
dynamic_bitset operator^(const dynamic_bitset& s, const dynamic_bitset& t);
std::istream& operator>>(std::istream& is, dynamic_bitset& s);
std::ostream& operator<<(std::ostream& os, const dynamic_bitset& s);

struct reference {
  reference& operator=(bool x);
  reference& operator=(const reference& other);
  bool operator~() const;
  operator bool() const;
  reference& flip();
};
```

They are methods based on `std::bitset`.

### Constraints
- Same as ones of `std::bitset`.

### Time Complexity
- Same as ones of `std::bitset`.

## resize
```cpp
void s.resize(std::size_t m);
```

It resizes `s` to contain $m$ bits.
If the current size $n$ is greater than $m$, `s` is reduced to its first $m$ bits.
If the current size $n$ is less than $m$, additional $0$s are appended to `s`.

### Constraints
- None

### Time Complexity
- $O(n)$

## shrink_to_fit
```cpp
void s.shrink_to_fit();
```

It requests the removal of unused memory allocated for `s`.
It is a non-binding request.
It depends on the implementation whether the request is fulfilled.

### Constraints
- None

### Time Complexity
- $O(n)$

## Find_first
```cpp
std::size_t s.Find_first();
```

It returns the least $i$ such that $0 \leq i < n$ and `s.test(i)` hold.
If such the integer does not exist, it returns $n$.

### Constraints
- None

### Time Complexity
- $O(i)$ where $i$ is the return value of `s.Find_first()`

## Find_next
```cpp
std::size_t s.Find_next(std::size_t i);
```

It returns the least $j$ such that $i < j < n$ and `s.test(j)` hold.
If such the integer does not exist, it returns $n$.

### Constraints
- $i < n$

### Time Complexity
- $O(j - i)$ where $j$ is the return value of `s.Find_next(i)`
