---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/ceil.hpp
    title: $\left\lceil \frac{x}{y} \right\rceil$
  - icon: ':heavy_check_mark:'
    path: tools/detail/ceil_and_floor.hpp
    title: tools/detail/ceil_and_floor.hpp
  - icon: ':heavy_check_mark:'
    path: tools/popcount.hpp
    title: Popcount
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/dynamic_bitset.hpp\"\n\n\n\n#include <cstddef>\n#include\
    \ <vector>\n#include <cstdint>\n#include <limits>\n#include <cassert>\n#include\
    \ <algorithm>\n#include <iterator>\n#include <iostream>\n#line 1 \"tools/ceil.hpp\"\
    \n\n\n\n#line 1 \"tools/detail/ceil_and_floor.hpp\"\n\n\n\n#include <type_traits>\n\
    \nnamespace tools {\n\n  template <typename M, typename N>\n  constexpr ::std::common_type_t<M,\
    \ N> floor(const M& lhs, const N& rhs);\n\n  template <typename M, typename N>\n\
    \  constexpr ::std::common_type_t<M, N> ceil(const M& lhs, const N& rhs);\n  \n\
    \  template <typename M, typename N>\n  constexpr ::std::common_type_t<M, N> floor(const\
    \ M& lhs, const N& rhs) {\n    return\n      lhs >= 0 && rhs >= 0 ?\n        lhs\
    \ / rhs :\n      lhs < 0 && rhs >= 0 ?\n        -::tools::ceil(-lhs, rhs) :\n\
    \      lhs >= 0 && rhs < 0 ?\n        -::tools::ceil(lhs, -rhs) :\n        ::tools::floor(-lhs,\
    \ -rhs);\n  }\n  \n  template <typename M, typename N>\n  constexpr ::std::common_type_t<M,\
    \ N> ceil(const M& lhs, const N& rhs) {\n    return\n      lhs >= 0 && rhs >=\
    \ 0 ?\n        (lhs - 1 + rhs) / rhs :\n      lhs < 0 && rhs >= 0 ?\n        -::tools::floor(-lhs,\
    \ rhs) :\n      lhs >= 0 && rhs < 0 ?\n        -::tools::floor(lhs, -rhs) :\n\
    \        ::tools::ceil(-lhs, -rhs);\n  }\n}\n\n\n#line 5 \"tools/ceil.hpp\"\n\n\
    \n#line 1 \"tools/popcount.hpp\"\n\n\n\n#line 5 \"tools/popcount.hpp\"\n\nnamespace\
    \ tools {\n\n  inline ::std::uint32_t popcount(::std::uint32_t x) {\n    x = (x\
    \ & static_cast<::std::uint32_t>(0x55555555ull)) + (x >> static_cast<::std::uint32_t>(1)\
    \ & static_cast<::std::uint32_t>(0x55555555ull));\n    x = (x & static_cast<::std::uint32_t>(0x33333333ull))\
    \ + (x >> static_cast<::std::uint32_t>(2) & static_cast<::std::uint32_t>(0x33333333ull));\n\
    \    x = (x & static_cast<::std::uint32_t>(0x0f0f0f0full)) + (x >> static_cast<::std::uint32_t>(4)\
    \ & static_cast<::std::uint32_t>(0x0f0f0f0full));\n    x = (x & static_cast<::std::uint32_t>(0x00ff00ffull))\
    \ + (x >> static_cast<::std::uint32_t>(8) & static_cast<::std::uint32_t>(0x00ff00ffull));\n\
    \    return (x & static_cast<::std::uint32_t>(0x0000ffffull)) + (x >> static_cast<::std::uint32_t>(16)\
    \ & static_cast<::std::uint32_t>(0x0000ffffull));\n  }\n\n  inline ::std::uint64_t\
    \ popcount(::std::uint64_t x) {\n    x = (x & static_cast<::std::uint64_t>(0x5555555555555555ull))\
    \ + (x >> static_cast<::std::uint64_t>(1) & static_cast<::std::uint64_t>(0x5555555555555555ull));\n\
    \    x = (x & static_cast<::std::uint64_t>(0x3333333333333333ull)) + (x >> static_cast<::std::uint64_t>(2)\
    \ & static_cast<::std::uint64_t>(0x3333333333333333ull));\n    x = (x & static_cast<::std::uint64_t>(0x0f0f0f0f0f0f0f0full))\
    \ + (x >> static_cast<::std::uint64_t>(4) & static_cast<::std::uint64_t>(0x0f0f0f0f0f0f0f0full));\n\
    \    x = (x & static_cast<::std::uint64_t>(0x00ff00ff00ff00ffull)) + (x >> static_cast<::std::uint64_t>(8)\
    \ & static_cast<::std::uint64_t>(0x00ff00ff00ff00ffull));\n    x = (x & static_cast<::std::uint64_t>(0x0000ffff0000ffffull))\
    \ + (x >> static_cast<::std::uint64_t>(16) & static_cast<::std::uint64_t>(0x0000ffff0000ffffull));\n\
    \    return (x & static_cast<::std::uint64_t>(0x00000000ffffffffull)) + (x >>\
    \ static_cast<::std::uint64_t>(32) & static_cast<::std::uint64_t>(0x00000000ffffffffull));\n\
    \  }\n\n  inline ::std::int32_t popcount(::std::int32_t x) {\n    return static_cast<::std::int32_t>(::tools::popcount(static_cast<::std::uint32_t>(x)));\n\
    \  }\n\n  inline ::std::int64_t popcount(::std::int64_t x) {\n    return static_cast<::std::int64_t>(::tools::popcount(static_cast<::std::uint64_t>(x)));\n\
    \  }\n}\n\n\n#line 14 \"tools/dynamic_bitset.hpp\"\n\nnamespace tools {\n  class\
    \ dynamic_bitset {\n  private:\n    ::std::size_t m_size;\n    ::std::vector<::std::uint64_t>\
    \ m_bits;\n\n  public:\n    dynamic_bitset() : m_size(0) {}\n    explicit dynamic_bitset(const\
    \ ::std::size_t size) : m_size(size), m_bits(::tools::ceil(size, ::std::numeric_limits<::std::uint64_t>::digits))\
    \ {}\n    dynamic_bitset(const ::tools::dynamic_bitset&) = default;\n    dynamic_bitset(::tools::dynamic_bitset&&)\
    \ = default;\n    ~dynamic_bitset() = default;\n    ::tools::dynamic_bitset& operator=(const\
    \ ::tools::dynamic_bitset&) = default;\n    ::tools::dynamic_bitset& operator=(::tools::dynamic_bitset&&)\
    \ = default;\n\n    ::tools::dynamic_bitset& operator&=(const ::tools::dynamic_bitset&\
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
    \ ^= rhs;\n    }\n    friend ::std::ostream& operator<<(::std::ostream& os, const\
    \ ::tools::dynamic_bitset& self) {\n      for (::std::size_t i = self.m_bits.size();\
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
    \ <cassert>\n#include <algorithm>\n#include <iterator>\n#include <iostream>\n\
    #include \"tools/ceil.hpp\"\n#include \"tools/popcount.hpp\"\n\nnamespace tools\
    \ {\n  class dynamic_bitset {\n  private:\n    ::std::size_t m_size;\n    ::std::vector<::std::uint64_t>\
    \ m_bits;\n\n  public:\n    dynamic_bitset() : m_size(0) {}\n    explicit dynamic_bitset(const\
    \ ::std::size_t size) : m_size(size), m_bits(::tools::ceil(size, ::std::numeric_limits<::std::uint64_t>::digits))\
    \ {}\n    dynamic_bitset(const ::tools::dynamic_bitset&) = default;\n    dynamic_bitset(::tools::dynamic_bitset&&)\
    \ = default;\n    ~dynamic_bitset() = default;\n    ::tools::dynamic_bitset& operator=(const\
    \ ::tools::dynamic_bitset&) = default;\n    ::tools::dynamic_bitset& operator=(::tools::dynamic_bitset&&)\
    \ = default;\n\n    ::tools::dynamic_bitset& operator&=(const ::tools::dynamic_bitset&\
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
    \ ^= rhs;\n    }\n    friend ::std::ostream& operator<<(::std::ostream& os, const\
    \ ::tools::dynamic_bitset& self) {\n      for (::std::size_t i = self.m_bits.size();\
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
  - tools/detail/ceil_and_floor.hpp
  - tools/popcount.hpp
  isVerificationFile: false
  path: tools/dynamic_bitset.hpp
  requiredBy: []
  timestamp: '2022-06-04 23:59:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tools/dynamic_bitset.hpp
layout: document
title: std::bitset with dynamic size
---

It is compatible to `std::bitset`, but it also allows you to specify the size of it dynamically.

### License
- CC0

### Author
- anqooqie
