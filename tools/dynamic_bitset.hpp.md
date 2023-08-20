---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: tools/ceil.hpp
    title: $\left\lceil \frac{x}{y} \right\rceil$
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
  - icon: ':x:'
    path: tests/scc_graph/edges_to_scc.test.cpp
    title: tests/scc_graph/edges_to_scc.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/dynamic_bitset.hpp\"\n\n\n\n#include <cstddef>\n#include\
    \ <vector>\n#include <cstdint>\n#include <limits>\n#include <string>\n#include\
    \ <cassert>\n#include <algorithm>\n#include <iterator>\n#include <iostream>\n\
    #line 1 \"tools/ceil.hpp\"\n\n\n\n#include <type_traits>\n#line 6 \"tools/ceil.hpp\"\
    \n\nnamespace tools {\n\n  template <typename M, typename N>\n  constexpr ::std::common_type_t<M,\
    \ N> ceil(const M lhs, const N rhs) {\n    using T = ::std::common_type_t<M, N>;\n\
    \    assert(rhs != N(0));\n    return lhs / rhs + T(((lhs > M(0) && rhs > N(0))\
    \ || (lhs < M(0) && rhs < N(0))) && lhs % rhs);\n  }\n}\n\n\n#line 1 \"tools/popcount.hpp\"\
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
    \      }\n\n      return x;\n    }\n  }\n}\n\n\n#line 15 \"tools/dynamic_bitset.hpp\"\
    \n\nnamespace tools {\n  class dynamic_bitset {\n  private:\n    ::std::size_t\
    \ m_size;\n    ::std::vector<::std::uint64_t> m_bits;\n\n  public:\n    dynamic_bitset()\
    \ : m_size(0) {}\n    dynamic_bitset(const ::tools::dynamic_bitset&) = default;\n\
    \    dynamic_bitset(::tools::dynamic_bitset&&) = default;\n    ~dynamic_bitset()\
    \ = default;\n    ::tools::dynamic_bitset& operator=(const ::tools::dynamic_bitset&)\
    \ = default;\n    ::tools::dynamic_bitset& operator=(::tools::dynamic_bitset&&)\
    \ = default;\n\n    explicit dynamic_bitset(const ::std::size_t size) : m_size(size),\
    \ m_bits(::tools::ceil(size, ::std::numeric_limits<::std::uint64_t>::digits),\
    \ 0) {}\n    explicit dynamic_bitset(const ::std::string& str) : m_size(str.size()),\
    \ m_bits(::tools::ceil(str.size(), ::std::numeric_limits<::std::uint64_t>::digits),\
    \ 0) {\n      for (::std::size_t i = 0; i < str.size(); ++i) {\n        const\
    \ auto c = str[str.size() - 1 - i];\n        assert(c == '0' || c == '1');\n \
    \       if (c == '1') {\n          this->m_bits[i / ::std::numeric_limits<::std::uint64_t>::digits]\
    \ |= ::std::uint64_t(1) << (i % ::std::numeric_limits<::std::uint64_t>::digits);\n\
    \        }\n      }\n    }\n\n    ::tools::dynamic_bitset& operator&=(const ::tools::dynamic_bitset&\
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
    \      const ::std::size_t diff = pos / ::std::numeric_limits<::std::uint64_t>::digits;\n\
    \      if (diff < this->m_bits.size()) {\n        if (pos % ::std::numeric_limits<::std::uint64_t>::digits\
    \ > 0) {\n          for (::std::size_t i = this->m_bits.size() - diff; i --> 0;)\
    \ {\n            this->m_bits[i] <<= pos % ::std::numeric_limits<::std::uint64_t>::digits;\n\
    \            if (i > 0) {\n              this->m_bits[i] |= this->m_bits[i - 1]\
    \ >> (::std::numeric_limits<::std::uint64_t>::digits - pos % ::std::numeric_limits<::std::uint64_t>::digits);\n\
    \            }\n          }\n        }\n        if (diff > 0) {\n          for\
    \ (::std::size_t i = this->m_bits.size() - diff; i --> 0;) {\n            this->m_bits[i\
    \ + diff] = this->m_bits[i];\n          }\n          ::std::fill(this->m_bits.begin(),\
    \ ::std::next(this->m_bits.begin(), diff), 0);\n        }\n        if (this->m_size\
    \ % ::std::numeric_limits<::std::uint64_t>::digits > 0) {\n          this->m_bits.back()\
    \ &= (::std::uint64_t(1) << (this->m_size % ::std::numeric_limits<::std::uint64_t>::digits))\
    \ - 1;\n        }\n      } else {\n        ::std::fill(this->m_bits.begin(), this->m_bits.end(),\
    \ 0);\n      }\n      return *this;\n    }\n    ::tools::dynamic_bitset& operator>>=(const\
    \ ::std::size_t pos) {\n      const ::std::size_t diff = pos / ::std::numeric_limits<::std::uint64_t>::digits;\n\
    \      if (diff < this->m_bits.size()) {\n        if (pos % ::std::numeric_limits<::std::uint64_t>::digits\
    \ > 0) {\n          for (::std::size_t i = diff; i < this->m_bits.size(); ++i)\
    \ {\n            this->m_bits[i] >>= pos % ::std::numeric_limits<::std::uint64_t>::digits;\n\
    \            if (i + 1 < this->m_bits.size()) {\n              this->m_bits[i]\
    \ |= this->m_bits[i + 1] << (::std::numeric_limits<::std::uint64_t>::digits -\
    \ pos % ::std::numeric_limits<::std::uint64_t>::digits);\n            }\n    \
    \      }\n        }\n        if (diff > 0) {\n          for (::std::size_t i =\
    \ diff; i < this->m_bits.size(); ++i) {\n            this->m_bits[i - diff] =\
    \ this->m_bits[i];\n          }\n          ::std::fill(::std::next(this->m_bits.begin(),\
    \ this->m_bits.size() - diff), this->m_bits.end(), 0);\n        }\n      } else\
    \ {\n        ::std::fill(this->m_bits.begin(), this->m_bits.end(), 0);\n     \
    \ }\n      return *this;\n    }\n    ::tools::dynamic_bitset& set() {\n      ::std::fill(this->m_bits.begin(),\
    \ this->m_bits.end(), ::std::numeric_limits<::std::uint64_t>::max());\n      if\
    \ (this->m_size % ::std::numeric_limits<::std::uint64_t>::digits > 0) {\n    \
    \    this->m_bits.back() &= (::std::uint64_t(1) << (this->m_size % ::std::numeric_limits<::std::uint64_t>::digits))\
    \ - 1;\n      }\n      return *this;\n    }\n    ::tools::dynamic_bitset& set(const\
    \ ::std::size_t pos) {\n      assert(pos < this->m_size);\n      this->m_bits[pos\
    \ / ::std::numeric_limits<::std::uint64_t>::digits] |= ::std::uint64_t(1) << (pos\
    \ % ::std::numeric_limits<::std::uint64_t>::digits);\n      return *this;\n  \
    \  }\n    ::tools::dynamic_bitset& reset() {\n      ::std::fill(this->m_bits.begin(),\
    \ this->m_bits.end(), 0);\n      return *this;\n    }\n    ::tools::dynamic_bitset&\
    \ reset(const ::std::size_t pos) {\n      assert(pos < this->m_size);\n      this->m_bits[pos\
    \ / ::std::numeric_limits<::std::uint64_t>::digits] &= ~(::std::uint64_t(1) <<\
    \ (pos % ::std::numeric_limits<::std::uint64_t>::digits));\n      return *this;\n\
    \    }\n    ::tools::dynamic_bitset& set(const ::std::size_t pos, const bool val)\
    \ {\n      return val ? this->set(pos) : this->reset(pos);\n    }\n    ::tools::dynamic_bitset&\
    \ flip() {\n      for (::std::size_t i = 0; i < this->m_bits.size(); ++i) {\n\
    \        this->m_bits[i] = ~this->m_bits[i];\n      }\n      if (this->m_size\
    \ % ::std::numeric_limits<::std::uint64_t>::digits > 0) {\n        this->m_bits.back()\
    \ &= (::std::uint64_t(1) << (this->m_size % ::std::numeric_limits<::std::uint64_t>::digits))\
    \ - 1;\n      }\n      return *this;\n    }\n    ::tools::dynamic_bitset& flip(const\
    \ ::std::size_t pos) {\n      assert(pos < this->m_size);\n      this->m_bits[pos\
    \ / ::std::numeric_limits<::std::uint64_t>::digits] ^= ::std::uint64_t(1) << (pos\
    \ % ::std::numeric_limits<::std::uint64_t>::digits);\n      return *this;\n  \
    \  }\n    ::tools::dynamic_bitset operator~() const {\n      return ::tools::dynamic_bitset(*this).flip();\n\
    \    }\n    ::std::size_t count() const {\n      ::std::size_t result = 0;\n \
    \     for (::std::size_t i = 0; i < this->m_bits.size(); ++i) {\n        result\
    \ += ::tools::popcount(this->m_bits[i]);\n      }\n      return result;\n    }\n\
    \    ::std::size_t size() const {\n      return this->m_size;\n    }\n    bool\
    \ test(const ::std::size_t pos) const {\n      assert(pos < this->m_size);\n \
    \     return (this->m_bits[pos / ::std::numeric_limits<::std::uint64_t>::digits]\
    \ >> (pos % ::std::numeric_limits<::std::uint64_t>::digits)) & 1;\n    }\n   \
    \ bool operator[](const ::std::size_t pos) const {\n      return this->test(pos);\n\
    \    }\n    bool all() const {\n      if (this->m_size % ::std::numeric_limits<::std::uint64_t>::digits\
    \ > 0) {\n        for (::std::size_t i = 0; i + 1 < this->m_bits.size(); ++i)\
    \ {\n          if (this->m_bits[i] != ::std::numeric_limits<::std::uint64_t>::max())\
    \ {\n            return false;\n          }\n        }\n        return this->m_bits.back()\
    \ == (::std::uint64_t(1) << (this->m_size % ::std::numeric_limits<::std::uint64_t>::digits))\
    \ - 1;\n      } else {\n        for (::std::size_t i = 0; i < this->m_bits.size();\
    \ ++i) {\n          if (this->m_bits[i] != ::std::numeric_limits<::std::uint64_t>::max())\
    \ {\n            return false;\n          }\n        }\n        return true;\n\
    \      }\n    }\n    bool any() const {\n      for (::std::size_t i = 0; i < this->m_bits.size();\
    \ ++i) {\n        if (this->m_bits[i] != 0) {\n          return true;\n      \
    \  }\n      }\n      return false;\n    }\n    bool none() const {\n      return\
    \ !this->any();\n    }\n    friend bool operator==(const ::tools::dynamic_bitset&\
    \ lhs, const ::tools::dynamic_bitset& rhs) {\n      return lhs.m_size == rhs.m_size\
    \ && lhs.m_bits == rhs.m_bits;\n    }\n    friend bool operator!=(const ::tools::dynamic_bitset&\
    \ lhs, const ::tools::dynamic_bitset& rhs) {\n      return !(lhs == rhs);\n  \
    \  }\n    ::tools::dynamic_bitset operator<<(const ::std::size_t pos) const {\n\
    \      return ::tools::dynamic_bitset(*this) <<= pos;\n    }\n    ::tools::dynamic_bitset\
    \ operator>>(const ::std::size_t pos) const {\n      return ::tools::dynamic_bitset(*this)\
    \ >>= pos;\n    }\n    friend ::tools::dynamic_bitset operator&(const ::tools::dynamic_bitset&\
    \ lhs, const ::tools::dynamic_bitset& rhs) {\n      return ::tools::dynamic_bitset(lhs)\
    \ &= rhs;\n    }\n    friend ::tools::dynamic_bitset operator|(const ::tools::dynamic_bitset&\
    \ lhs, const ::tools::dynamic_bitset& rhs) {\n      return ::tools::dynamic_bitset(lhs)\
    \ |= rhs;\n    }\n    friend ::tools::dynamic_bitset operator^(const ::tools::dynamic_bitset&\
    \ lhs, const ::tools::dynamic_bitset& rhs) {\n      return ::tools::dynamic_bitset(lhs)\
    \ ^= rhs;\n    }\n    friend ::std::istream& operator>>(::std::istream& is, ::tools::dynamic_bitset&\
    \ self) {\n      ::std::string s;\n      is >> s;\n      self = ::tools::dynamic_bitset(s);\n\
    \      return is;\n    }\n    friend ::std::ostream& operator<<(::std::ostream&\
    \ os, const ::tools::dynamic_bitset& self) {\n      for (::std::size_t i = self.m_bits.size();\
    \ i --> 0;) {\n        for (::std::size_t j = (self.m_size - 1) % ::std::numeric_limits<::std::uint64_t>::digits\
    \ + 1; j --> 0;) {\n          os << ((self.m_bits[i] >> j) & 1);\n        }\n\
    \      }\n      return os;\n    }\n    void resize(const ::std::size_t size) {\n\
    \      this->m_size = size;\n      this->m_bits.resize(::tools::ceil(size, ::std::numeric_limits<::std::uint64_t>::digits));\n\
    \      if (size % ::std::numeric_limits<::std::uint64_t>::digits > 0) {\n    \
    \    this->m_bits.back() &= (::std::uint64_t(1) << (size % ::std::numeric_limits<::std::uint64_t>::digits))\
    \ - 1;\n      }\n    }\n    void shrink_to_fit() {\n      this->m_bits.shrink_to_fit();\n\
    \    }\n  };\n}\n\n\n"
  code: "#ifndef TOOLS_DYNAMIC_BITSET_HPP\n#define TOOLS_DYNAMIC_BITSET_HPP\n\n#include\
    \ <cstddef>\n#include <vector>\n#include <cstdint>\n#include <limits>\n#include\
    \ <string>\n#include <cassert>\n#include <algorithm>\n#include <iterator>\n#include\
    \ <iostream>\n#include \"tools/ceil.hpp\"\n#include \"tools/popcount.hpp\"\n\n\
    namespace tools {\n  class dynamic_bitset {\n  private:\n    ::std::size_t m_size;\n\
    \    ::std::vector<::std::uint64_t> m_bits;\n\n  public:\n    dynamic_bitset()\
    \ : m_size(0) {}\n    dynamic_bitset(const ::tools::dynamic_bitset&) = default;\n\
    \    dynamic_bitset(::tools::dynamic_bitset&&) = default;\n    ~dynamic_bitset()\
    \ = default;\n    ::tools::dynamic_bitset& operator=(const ::tools::dynamic_bitset&)\
    \ = default;\n    ::tools::dynamic_bitset& operator=(::tools::dynamic_bitset&&)\
    \ = default;\n\n    explicit dynamic_bitset(const ::std::size_t size) : m_size(size),\
    \ m_bits(::tools::ceil(size, ::std::numeric_limits<::std::uint64_t>::digits),\
    \ 0) {}\n    explicit dynamic_bitset(const ::std::string& str) : m_size(str.size()),\
    \ m_bits(::tools::ceil(str.size(), ::std::numeric_limits<::std::uint64_t>::digits),\
    \ 0) {\n      for (::std::size_t i = 0; i < str.size(); ++i) {\n        const\
    \ auto c = str[str.size() - 1 - i];\n        assert(c == '0' || c == '1');\n \
    \       if (c == '1') {\n          this->m_bits[i / ::std::numeric_limits<::std::uint64_t>::digits]\
    \ |= ::std::uint64_t(1) << (i % ::std::numeric_limits<::std::uint64_t>::digits);\n\
    \        }\n      }\n    }\n\n    ::tools::dynamic_bitset& operator&=(const ::tools::dynamic_bitset&\
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
    \      const ::std::size_t diff = pos / ::std::numeric_limits<::std::uint64_t>::digits;\n\
    \      if (diff < this->m_bits.size()) {\n        if (pos % ::std::numeric_limits<::std::uint64_t>::digits\
    \ > 0) {\n          for (::std::size_t i = this->m_bits.size() - diff; i --> 0;)\
    \ {\n            this->m_bits[i] <<= pos % ::std::numeric_limits<::std::uint64_t>::digits;\n\
    \            if (i > 0) {\n              this->m_bits[i] |= this->m_bits[i - 1]\
    \ >> (::std::numeric_limits<::std::uint64_t>::digits - pos % ::std::numeric_limits<::std::uint64_t>::digits);\n\
    \            }\n          }\n        }\n        if (diff > 0) {\n          for\
    \ (::std::size_t i = this->m_bits.size() - diff; i --> 0;) {\n            this->m_bits[i\
    \ + diff] = this->m_bits[i];\n          }\n          ::std::fill(this->m_bits.begin(),\
    \ ::std::next(this->m_bits.begin(), diff), 0);\n        }\n        if (this->m_size\
    \ % ::std::numeric_limits<::std::uint64_t>::digits > 0) {\n          this->m_bits.back()\
    \ &= (::std::uint64_t(1) << (this->m_size % ::std::numeric_limits<::std::uint64_t>::digits))\
    \ - 1;\n        }\n      } else {\n        ::std::fill(this->m_bits.begin(), this->m_bits.end(),\
    \ 0);\n      }\n      return *this;\n    }\n    ::tools::dynamic_bitset& operator>>=(const\
    \ ::std::size_t pos) {\n      const ::std::size_t diff = pos / ::std::numeric_limits<::std::uint64_t>::digits;\n\
    \      if (diff < this->m_bits.size()) {\n        if (pos % ::std::numeric_limits<::std::uint64_t>::digits\
    \ > 0) {\n          for (::std::size_t i = diff; i < this->m_bits.size(); ++i)\
    \ {\n            this->m_bits[i] >>= pos % ::std::numeric_limits<::std::uint64_t>::digits;\n\
    \            if (i + 1 < this->m_bits.size()) {\n              this->m_bits[i]\
    \ |= this->m_bits[i + 1] << (::std::numeric_limits<::std::uint64_t>::digits -\
    \ pos % ::std::numeric_limits<::std::uint64_t>::digits);\n            }\n    \
    \      }\n        }\n        if (diff > 0) {\n          for (::std::size_t i =\
    \ diff; i < this->m_bits.size(); ++i) {\n            this->m_bits[i - diff] =\
    \ this->m_bits[i];\n          }\n          ::std::fill(::std::next(this->m_bits.begin(),\
    \ this->m_bits.size() - diff), this->m_bits.end(), 0);\n        }\n      } else\
    \ {\n        ::std::fill(this->m_bits.begin(), this->m_bits.end(), 0);\n     \
    \ }\n      return *this;\n    }\n    ::tools::dynamic_bitset& set() {\n      ::std::fill(this->m_bits.begin(),\
    \ this->m_bits.end(), ::std::numeric_limits<::std::uint64_t>::max());\n      if\
    \ (this->m_size % ::std::numeric_limits<::std::uint64_t>::digits > 0) {\n    \
    \    this->m_bits.back() &= (::std::uint64_t(1) << (this->m_size % ::std::numeric_limits<::std::uint64_t>::digits))\
    \ - 1;\n      }\n      return *this;\n    }\n    ::tools::dynamic_bitset& set(const\
    \ ::std::size_t pos) {\n      assert(pos < this->m_size);\n      this->m_bits[pos\
    \ / ::std::numeric_limits<::std::uint64_t>::digits] |= ::std::uint64_t(1) << (pos\
    \ % ::std::numeric_limits<::std::uint64_t>::digits);\n      return *this;\n  \
    \  }\n    ::tools::dynamic_bitset& reset() {\n      ::std::fill(this->m_bits.begin(),\
    \ this->m_bits.end(), 0);\n      return *this;\n    }\n    ::tools::dynamic_bitset&\
    \ reset(const ::std::size_t pos) {\n      assert(pos < this->m_size);\n      this->m_bits[pos\
    \ / ::std::numeric_limits<::std::uint64_t>::digits] &= ~(::std::uint64_t(1) <<\
    \ (pos % ::std::numeric_limits<::std::uint64_t>::digits));\n      return *this;\n\
    \    }\n    ::tools::dynamic_bitset& set(const ::std::size_t pos, const bool val)\
    \ {\n      return val ? this->set(pos) : this->reset(pos);\n    }\n    ::tools::dynamic_bitset&\
    \ flip() {\n      for (::std::size_t i = 0; i < this->m_bits.size(); ++i) {\n\
    \        this->m_bits[i] = ~this->m_bits[i];\n      }\n      if (this->m_size\
    \ % ::std::numeric_limits<::std::uint64_t>::digits > 0) {\n        this->m_bits.back()\
    \ &= (::std::uint64_t(1) << (this->m_size % ::std::numeric_limits<::std::uint64_t>::digits))\
    \ - 1;\n      }\n      return *this;\n    }\n    ::tools::dynamic_bitset& flip(const\
    \ ::std::size_t pos) {\n      assert(pos < this->m_size);\n      this->m_bits[pos\
    \ / ::std::numeric_limits<::std::uint64_t>::digits] ^= ::std::uint64_t(1) << (pos\
    \ % ::std::numeric_limits<::std::uint64_t>::digits);\n      return *this;\n  \
    \  }\n    ::tools::dynamic_bitset operator~() const {\n      return ::tools::dynamic_bitset(*this).flip();\n\
    \    }\n    ::std::size_t count() const {\n      ::std::size_t result = 0;\n \
    \     for (::std::size_t i = 0; i < this->m_bits.size(); ++i) {\n        result\
    \ += ::tools::popcount(this->m_bits[i]);\n      }\n      return result;\n    }\n\
    \    ::std::size_t size() const {\n      return this->m_size;\n    }\n    bool\
    \ test(const ::std::size_t pos) const {\n      assert(pos < this->m_size);\n \
    \     return (this->m_bits[pos / ::std::numeric_limits<::std::uint64_t>::digits]\
    \ >> (pos % ::std::numeric_limits<::std::uint64_t>::digits)) & 1;\n    }\n   \
    \ bool operator[](const ::std::size_t pos) const {\n      return this->test(pos);\n\
    \    }\n    bool all() const {\n      if (this->m_size % ::std::numeric_limits<::std::uint64_t>::digits\
    \ > 0) {\n        for (::std::size_t i = 0; i + 1 < this->m_bits.size(); ++i)\
    \ {\n          if (this->m_bits[i] != ::std::numeric_limits<::std::uint64_t>::max())\
    \ {\n            return false;\n          }\n        }\n        return this->m_bits.back()\
    \ == (::std::uint64_t(1) << (this->m_size % ::std::numeric_limits<::std::uint64_t>::digits))\
    \ - 1;\n      } else {\n        for (::std::size_t i = 0; i < this->m_bits.size();\
    \ ++i) {\n          if (this->m_bits[i] != ::std::numeric_limits<::std::uint64_t>::max())\
    \ {\n            return false;\n          }\n        }\n        return true;\n\
    \      }\n    }\n    bool any() const {\n      for (::std::size_t i = 0; i < this->m_bits.size();\
    \ ++i) {\n        if (this->m_bits[i] != 0) {\n          return true;\n      \
    \  }\n      }\n      return false;\n    }\n    bool none() const {\n      return\
    \ !this->any();\n    }\n    friend bool operator==(const ::tools::dynamic_bitset&\
    \ lhs, const ::tools::dynamic_bitset& rhs) {\n      return lhs.m_size == rhs.m_size\
    \ && lhs.m_bits == rhs.m_bits;\n    }\n    friend bool operator!=(const ::tools::dynamic_bitset&\
    \ lhs, const ::tools::dynamic_bitset& rhs) {\n      return !(lhs == rhs);\n  \
    \  }\n    ::tools::dynamic_bitset operator<<(const ::std::size_t pos) const {\n\
    \      return ::tools::dynamic_bitset(*this) <<= pos;\n    }\n    ::tools::dynamic_bitset\
    \ operator>>(const ::std::size_t pos) const {\n      return ::tools::dynamic_bitset(*this)\
    \ >>= pos;\n    }\n    friend ::tools::dynamic_bitset operator&(const ::tools::dynamic_bitset&\
    \ lhs, const ::tools::dynamic_bitset& rhs) {\n      return ::tools::dynamic_bitset(lhs)\
    \ &= rhs;\n    }\n    friend ::tools::dynamic_bitset operator|(const ::tools::dynamic_bitset&\
    \ lhs, const ::tools::dynamic_bitset& rhs) {\n      return ::tools::dynamic_bitset(lhs)\
    \ |= rhs;\n    }\n    friend ::tools::dynamic_bitset operator^(const ::tools::dynamic_bitset&\
    \ lhs, const ::tools::dynamic_bitset& rhs) {\n      return ::tools::dynamic_bitset(lhs)\
    \ ^= rhs;\n    }\n    friend ::std::istream& operator>>(::std::istream& is, ::tools::dynamic_bitset&\
    \ self) {\n      ::std::string s;\n      is >> s;\n      self = ::tools::dynamic_bitset(s);\n\
    \      return is;\n    }\n    friend ::std::ostream& operator<<(::std::ostream&\
    \ os, const ::tools::dynamic_bitset& self) {\n      for (::std::size_t i = self.m_bits.size();\
    \ i --> 0;) {\n        for (::std::size_t j = (self.m_size - 1) % ::std::numeric_limits<::std::uint64_t>::digits\
    \ + 1; j --> 0;) {\n          os << ((self.m_bits[i] >> j) & 1);\n        }\n\
    \      }\n      return os;\n    }\n    void resize(const ::std::size_t size) {\n\
    \      this->m_size = size;\n      this->m_bits.resize(::tools::ceil(size, ::std::numeric_limits<::std::uint64_t>::digits));\n\
    \      if (size % ::std::numeric_limits<::std::uint64_t>::digits > 0) {\n    \
    \    this->m_bits.back() &= (::std::uint64_t(1) << (size % ::std::numeric_limits<::std::uint64_t>::digits))\
    \ - 1;\n      }\n    }\n    void shrink_to_fit() {\n      this->m_bits.shrink_to_fit();\n\
    \    }\n  };\n}\n\n#endif\n"
  dependsOn:
  - tools/ceil.hpp
  - tools/popcount.hpp
  isVerificationFile: false
  path: tools/dynamic_bitset.hpp
  requiredBy: []
  timestamp: '2023-08-20 17:29:18+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - tests/rotate_left.test.cpp
  - tests/rotate_right.test.cpp
  - tests/scc_graph/edges_to_scc.test.cpp
documentation_of: tools/dynamic_bitset.hpp
layout: document
title: std::bitset with dynamic size
---

It is compatible to `std::bitset`, but it also allows you to specify the size of it dynamically.

### License
- CC0

### Author
- anqooqie
