---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/assert_that.hpp
    title: Assertion macro
  - icon: ':heavy_check_mark:'
    path: tools/ceil.hpp
    title: $\left\lceil \frac{x}{y} \right\rceil$
  - icon: ':heavy_check_mark:'
    path: tools/dynamic_bitset.hpp
    title: std::bitset with dynamic size
  - icon: ':heavy_check_mark:'
    path: tools/mod.hpp
    title: Minimum non-negative reminder
  - icon: ':heavy_check_mark:'
    path: tools/popcount.hpp
    title: Popcount
  - icon: ':heavy_check_mark:'
    path: tools/quo.hpp
    title: Quotient as integer division
  - icon: ':heavy_check_mark:'
    path: tools/rotate_right.hpp
    title: Circular shift to the right
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A
  bundledCode: "#line 1 \"tests/rotate_right.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\"\
    \n\n#include <iostream>\n#include <cstdint>\n#include <bitset>\n#line 1 \"tools/assert_that.hpp\"\
    \n\n\n\n#line 5 \"tools/assert_that.hpp\"\n#include <cstdlib>\n\n#define assert_that(cond)\
    \ do {\\\n  if (!(cond)) {\\\n    ::std::cerr << __FILE__ << ':' << __LINE__ <<\
    \ \": \" << __func__ << \": Assertion `\" << #cond << \"' failed.\" << '\\n';\\\
    \n    ::std::exit(EXIT_FAILURE);\\\n  }\\\n} while (false)\n\n\n#line 1 \"tools/rotate_right.hpp\"\
    \n\n\n\n#include <cassert>\n#include <limits>\n#line 1 \"tools/mod.hpp\"\n\n\n\
    \n#include <type_traits>\n#line 1 \"tools/quo.hpp\"\n\n\n\n#line 5 \"tools/quo.hpp\"\
    \n\nnamespace tools {\n\n  template <typename M, typename N>\n  constexpr ::std::common_type_t<M,\
    \ N> quo(const M lhs, const N rhs) {\n    if (lhs >= 0) {\n      return lhs /\
    \ rhs;\n    } else {\n      if (rhs >= 0) {\n        return -((-lhs - 1 + rhs)\
    \ / rhs);\n      } else {\n        return (-lhs - 1 + -rhs) / -rhs;\n      }\n\
    \    }\n  }\n}\n\n\n#line 6 \"tools/mod.hpp\"\n\nnamespace tools {\n\n  template\
    \ <typename M, typename N>\n  constexpr ::std::common_type_t<M, N> mod(const M\
    \ lhs, const N rhs) {\n    if constexpr (::std::is_unsigned_v<M> && ::std::is_unsigned_v<N>)\
    \ {\n      return lhs % rhs;\n    } else {\n      return lhs - ::tools::quo(lhs,\
    \ rhs) * rhs;\n    }\n  }\n}\n\n\n#line 7 \"tools/rotate_right.hpp\"\n\nnamespace\
    \ tools {\n\n  template <typename T, typename U>\n  constexpr T rotate_right(const\
    \ T x, const ::std::size_t n, U s) {\n    assert(n <= ::std::numeric_limits<T>::digits);\n\
    \    const T mask = (n == ::std::numeric_limits<T>::digits ? ::std::numeric_limits<T>::max()\
    \ : (T(1) << n) - 1);\n    assert(0 <= x && x <= mask);\n    s = ::tools::mod(s,\
    \ n);\n    return ((x << ((n - s) % n)) | (x >> s)) & mask;\n  }\n\n  template\
    \ <typename T, typename U>\n  T rotate_right(const T& x, U s) {\n    s = ::tools::mod(s,\
    \ x.size());\n    return (x << ((x.size() - s) % x.size())) | (x >> s);\n  }\n\
    }\n\n\n#line 1 \"tools/dynamic_bitset.hpp\"\n\n\n\n#include <cstddef>\n#include\
    \ <vector>\n#line 8 \"tools/dynamic_bitset.hpp\"\n#include <string>\n#line 10\
    \ \"tools/dynamic_bitset.hpp\"\n#include <algorithm>\n#include <iterator>\n#line\
    \ 1 \"tools/ceil.hpp\"\n\n\n\n#line 6 \"tools/ceil.hpp\"\n\nnamespace tools {\n\
    \n  template <typename M, typename N>\n  constexpr ::std::common_type_t<M, N>\
    \ ceil(const M lhs, const N rhs) {\n    assert(rhs != 0);\n    return lhs / rhs\
    \ + (((lhs > 0 && rhs > 0) || (lhs < 0 && rhs < 0)) && lhs % rhs);\n  }\n}\n\n\
    \n#line 1 \"tools/popcount.hpp\"\n\n\n\n#line 8 \"tools/popcount.hpp\"\n\nnamespace\
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
    \    }\n  };\n}\n\n\n#line 9 \"tests/rotate_right.test.cpp\"\n\nint main() {\n\
    \  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\n  assert_that(tools::rotate_right(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000),\
    \ 64, -9223372036854775807 - 1) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,     -9223372036854775807) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,                     -128) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,                     -127) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,                      -65) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,                      -64) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,                      -63) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,                       -2) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,                       -1) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,                        0) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,                        1) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,                        2) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,                       63) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,                       64) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,                       65) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,                      127) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,                      128) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,      9223372036854775807) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000));\n\
    \n  assert_that(tools::rotate_right(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001),\
    \ 64, -9223372036854775807 - 1) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001),\
    \ 64,     -9223372036854775807) == UINT64_C(0b1000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001),\
    \ 64,                     -128) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001),\
    \ 64,                     -127) == UINT64_C(0b1000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001),\
    \ 64,                      -65) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000010));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001),\
    \ 64,                      -64) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001),\
    \ 64,                      -63) == UINT64_C(0b1000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001),\
    \ 64,                       -2) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000100));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001),\
    \ 64,                       -1) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000010));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001),\
    \ 64,                        0) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001),\
    \ 64,                        1) == UINT64_C(0b1000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001),\
    \ 64,                        2) == UINT64_C(0b0100000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001),\
    \ 64,                       63) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000010));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001),\
    \ 64,                       64) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001),\
    \ 64,                       65) == UINT64_C(0b1000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001),\
    \ 64,                      127) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000010));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001),\
    \ 64,                      128) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001),\
    \ 64,      9223372036854775807) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000010));\n\
    \n  assert_that(tools::rotate_right(UINT64_C(0b1000000000000000000000000000000000000000000000000000000000000000),\
    \ 64, -9223372036854775807 - 1) == UINT64_C(0b1000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b1000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,     -9223372036854775807) == UINT64_C(0b0100000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b1000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,                     -128) == UINT64_C(0b1000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b1000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,                     -127) == UINT64_C(0b0100000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b1000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,                      -65) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b1000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,                      -64) == UINT64_C(0b1000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b1000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,                      -63) == UINT64_C(0b0100000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b1000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,                       -2) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000010));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b1000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,                       -1) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b1000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,                        0) == UINT64_C(0b1000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b1000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,                        1) == UINT64_C(0b0100000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b1000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,                        2) == UINT64_C(0b0010000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b1000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,                       63) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b1000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,                       64) == UINT64_C(0b1000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b1000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,                       65) == UINT64_C(0b0100000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b1000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,                      127) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b1000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,                      128) == UINT64_C(0b1000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b1000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,      9223372036854775807) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001));\n\
    \n  assert_that(tools::rotate_right(UINT64_C(0b0101010011111101111000100000100110001010011110011111001110110100),\
    \ 64, -9223372036854775807 - 1) == UINT64_C(0b0101010011111101111000100000100110001010011110011111001110110100));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b0101010011111101111000100000100110001010011110011111001110110100),\
    \ 64,     -9223372036854775807) == UINT64_C(0b0010101001111110111100010000010011000101001111001111100111011010));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b0101010011111101111000100000100110001010011110011111001110110100),\
    \ 64,                     -128) == UINT64_C(0b0101010011111101111000100000100110001010011110011111001110110100));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b0101010011111101111000100000100110001010011110011111001110110100),\
    \ 64,                     -127) == UINT64_C(0b0010101001111110111100010000010011000101001111001111100111011010));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b0101010011111101111000100000100110001010011110011111001110110100),\
    \ 64,                      -65) == UINT64_C(0b1010100111111011110001000001001100010100111100111110011101101000));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b0101010011111101111000100000100110001010011110011111001110110100),\
    \ 64,                      -64) == UINT64_C(0b0101010011111101111000100000100110001010011110011111001110110100));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b0101010011111101111000100000100110001010011110011111001110110100),\
    \ 64,                      -63) == UINT64_C(0b0010101001111110111100010000010011000101001111001111100111011010));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b0101010011111101111000100000100110001010011110011111001110110100),\
    \ 64,                       -2) == UINT64_C(0b0101001111110111100010000010011000101001111001111100111011010001));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b0101010011111101111000100000100110001010011110011111001110110100),\
    \ 64,                       -1) == UINT64_C(0b1010100111111011110001000001001100010100111100111110011101101000));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b0101010011111101111000100000100110001010011110011111001110110100),\
    \ 64,                        0) == UINT64_C(0b0101010011111101111000100000100110001010011110011111001110110100));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b0101010011111101111000100000100110001010011110011111001110110100),\
    \ 64,                        1) == UINT64_C(0b0010101001111110111100010000010011000101001111001111100111011010));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b0101010011111101111000100000100110001010011110011111001110110100),\
    \ 64,                        2) == UINT64_C(0b0001010100111111011110001000001001100010100111100111110011101101));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b0101010011111101111000100000100110001010011110011111001110110100),\
    \ 64,                       63) == UINT64_C(0b1010100111111011110001000001001100010100111100111110011101101000));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b0101010011111101111000100000100110001010011110011111001110110100),\
    \ 64,                       64) == UINT64_C(0b0101010011111101111000100000100110001010011110011111001110110100));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b0101010011111101111000100000100110001010011110011111001110110100),\
    \ 64,                       65) == UINT64_C(0b0010101001111110111100010000010011000101001111001111100111011010));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b0101010011111101111000100000100110001010011110011111001110110100),\
    \ 64,                      127) == UINT64_C(0b1010100111111011110001000001001100010100111100111110011101101000));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b0101010011111101111000100000100110001010011110011111001110110100),\
    \ 64,                      128) == UINT64_C(0b0101010011111101111000100000100110001010011110011111001110110100));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b0101010011111101111000100000100110001010011110011111001110110100),\
    \ 64,      9223372036854775807) == UINT64_C(0b1010100111111011110001000001001100010100111100111110011101101000));\n\
    \n  assert_that(tools::rotate_right(INT64_C(0b000000000000000000000000000000000000000000000000000000000000000),\
    \ 63, -9223372036854775807 - 1) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b000000000000000000000000000000000000000000000000000000000000000),\
    \ 63,     -9223372036854775807) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b000000000000000000000000000000000000000000000000000000000000000),\
    \ 63,                     -126) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b000000000000000000000000000000000000000000000000000000000000000),\
    \ 63,                     -125) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b000000000000000000000000000000000000000000000000000000000000000),\
    \ 63,                      -64) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b000000000000000000000000000000000000000000000000000000000000000),\
    \ 63,                      -63) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b000000000000000000000000000000000000000000000000000000000000000),\
    \ 63,                      -62) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b000000000000000000000000000000000000000000000000000000000000000),\
    \ 63,                       -2) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b000000000000000000000000000000000000000000000000000000000000000),\
    \ 63,                       -1) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b000000000000000000000000000000000000000000000000000000000000000),\
    \ 63,                        0) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b000000000000000000000000000000000000000000000000000000000000000),\
    \ 63,                        1) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b000000000000000000000000000000000000000000000000000000000000000),\
    \ 63,                        2) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b000000000000000000000000000000000000000000000000000000000000000),\
    \ 63,                       62) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b000000000000000000000000000000000000000000000000000000000000000),\
    \ 63,                       63) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b000000000000000000000000000000000000000000000000000000000000000),\
    \ 63,                       64) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b000000000000000000000000000000000000000000000000000000000000000),\
    \ 63,                      125) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b000000000000000000000000000000000000000000000000000000000000000),\
    \ 63,                      126) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b000000000000000000000000000000000000000000000000000000000000000),\
    \ 63,      9223372036854775807) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000000));\n\
    \n  assert_that(tools::rotate_right(INT64_C(0b000000000000000000000000000000000000000000000000000000000000001),\
    \ 63, -9223372036854775807 - 1) == INT64_C(0b000000000000000000000000000000000000000000000000000000100000000));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b000000000000000000000000000000000000000000000000000000000000001),\
    \ 63,     -9223372036854775807) == INT64_C(0b000000000000000000000000000000000000000000000000000000010000000));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b000000000000000000000000000000000000000000000000000000000000001),\
    \ 63,                     -126) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000001));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b000000000000000000000000000000000000000000000000000000000000001),\
    \ 63,                     -125) == INT64_C(0b100000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b000000000000000000000000000000000000000000000000000000000000001),\
    \ 63,                      -64) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000010));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b000000000000000000000000000000000000000000000000000000000000001),\
    \ 63,                      -63) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000001));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b000000000000000000000000000000000000000000000000000000000000001),\
    \ 63,                      -62) == INT64_C(0b100000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b000000000000000000000000000000000000000000000000000000000000001),\
    \ 63,                       -2) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000100));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b000000000000000000000000000000000000000000000000000000000000001),\
    \ 63,                       -1) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000010));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b000000000000000000000000000000000000000000000000000000000000001),\
    \ 63,                        0) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000001));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b000000000000000000000000000000000000000000000000000000000000001),\
    \ 63,                        1) == INT64_C(0b100000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b000000000000000000000000000000000000000000000000000000000000001),\
    \ 63,                        2) == INT64_C(0b010000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b000000000000000000000000000000000000000000000000000000000000001),\
    \ 63,                       62) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000010));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b000000000000000000000000000000000000000000000000000000000000001),\
    \ 63,                       63) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000001));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b000000000000000000000000000000000000000000000000000000000000001),\
    \ 63,                       64) == INT64_C(0b100000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b000000000000000000000000000000000000000000000000000000000000001),\
    \ 63,                      125) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000010));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b000000000000000000000000000000000000000000000000000000000000001),\
    \ 63,                      126) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000001));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b000000000000000000000000000000000000000000000000000000000000001),\
    \ 63,      9223372036854775807) == INT64_C(0b000000100000000000000000000000000000000000000000000000000000000));\n\
    \n  assert_that(tools::rotate_right(INT64_C(0b100000000000000000000000000000000000000000000000000000000000000),\
    \ 63, -9223372036854775807 - 1) == INT64_C(0b000000000000000000000000000000000000000000000000000000010000000));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b100000000000000000000000000000000000000000000000000000000000000),\
    \ 63,     -9223372036854775807) == INT64_C(0b000000000000000000000000000000000000000000000000000000001000000));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b100000000000000000000000000000000000000000000000000000000000000),\
    \ 63,                     -126) == INT64_C(0b100000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b100000000000000000000000000000000000000000000000000000000000000),\
    \ 63,                     -125) == INT64_C(0b010000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b100000000000000000000000000000000000000000000000000000000000000),\
    \ 63,                      -64) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000001));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b100000000000000000000000000000000000000000000000000000000000000),\
    \ 63,                      -63) == INT64_C(0b100000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b100000000000000000000000000000000000000000000000000000000000000),\
    \ 63,                      -62) == INT64_C(0b010000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b100000000000000000000000000000000000000000000000000000000000000),\
    \ 63,                       -2) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000010));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b100000000000000000000000000000000000000000000000000000000000000),\
    \ 63,                       -1) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000001));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b100000000000000000000000000000000000000000000000000000000000000),\
    \ 63,                        0) == INT64_C(0b100000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b100000000000000000000000000000000000000000000000000000000000000),\
    \ 63,                        1) == INT64_C(0b010000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b100000000000000000000000000000000000000000000000000000000000000),\
    \ 63,                        2) == INT64_C(0b001000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b100000000000000000000000000000000000000000000000000000000000000),\
    \ 63,                       62) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000001));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b100000000000000000000000000000000000000000000000000000000000000),\
    \ 63,                       63) == INT64_C(0b100000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b100000000000000000000000000000000000000000000000000000000000000),\
    \ 63,                       64) == INT64_C(0b010000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b100000000000000000000000000000000000000000000000000000000000000),\
    \ 63,                      125) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000001));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b100000000000000000000000000000000000000000000000000000000000000),\
    \ 63,                      126) == INT64_C(0b100000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b100000000000000000000000000000000000000000000000000000000000000),\
    \ 63,      9223372036854775807) == INT64_C(0b000000010000000000000000000000000000000000000000000000000000000));\n\
    \n  assert_that(tools::rotate_right(INT64_C(0b101010011111101111000100000100110001010011110011111001110110100),\
    \ 63, -9223372036854775807 - 1) == INT64_C(0b111110111100010000010011000101001111001111100111011010010101001));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b101010011111101111000100000100110001010011110011111001110110100),\
    \ 63,     -9223372036854775807) == INT64_C(0b111111011110001000001001100010100111100111110011101101001010100));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b101010011111101111000100000100110001010011110011111001110110100),\
    \ 63,                     -126) == INT64_C(0b101010011111101111000100000100110001010011110011111001110110100));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b101010011111101111000100000100110001010011110011111001110110100),\
    \ 63,                     -125) == INT64_C(0b010101001111110111100010000010011000101001111001111100111011010));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b101010011111101111000100000100110001010011110011111001110110100),\
    \ 63,                      -64) == INT64_C(0b010100111111011110001000001001100010100111100111110011101101001));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b101010011111101111000100000100110001010011110011111001110110100),\
    \ 63,                      -63) == INT64_C(0b101010011111101111000100000100110001010011110011111001110110100));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b101010011111101111000100000100110001010011110011111001110110100),\
    \ 63,                      -62) == INT64_C(0b010101001111110111100010000010011000101001111001111100111011010));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b101010011111101111000100000100110001010011110011111001110110100),\
    \ 63,                       -2) == INT64_C(0b101001111110111100010000010011000101001111001111100111011010010));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b101010011111101111000100000100110001010011110011111001110110100),\
    \ 63,                       -1) == INT64_C(0b010100111111011110001000001001100010100111100111110011101101001));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b101010011111101111000100000100110001010011110011111001110110100),\
    \ 63,                        0) == INT64_C(0b101010011111101111000100000100110001010011110011111001110110100));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b101010011111101111000100000100110001010011110011111001110110100),\
    \ 63,                        1) == INT64_C(0b010101001111110111100010000010011000101001111001111100111011010));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b101010011111101111000100000100110001010011110011111001110110100),\
    \ 63,                        2) == INT64_C(0b001010100111111011110001000001001100010100111100111110011101101));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b101010011111101111000100000100110001010011110011111001110110100),\
    \ 63,                       62) == INT64_C(0b010100111111011110001000001001100010100111100111110011101101001));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b101010011111101111000100000100110001010011110011111001110110100),\
    \ 63,                       63) == INT64_C(0b101010011111101111000100000100110001010011110011111001110110100));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b101010011111101111000100000100110001010011110011111001110110100),\
    \ 63,                       64) == INT64_C(0b010101001111110111100010000010011000101001111001111100111011010));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b101010011111101111000100000100110001010011110011111001110110100),\
    \ 63,                      125) == INT64_C(0b010100111111011110001000001001100010100111100111110011101101001));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b101010011111101111000100000100110001010011110011111001110110100),\
    \ 63,                      126) == INT64_C(0b101010011111101111000100000100110001010011110011111001110110100));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b101010011111101111000100000100110001010011110011111001110110100),\
    \ 63,      9223372036854775807) == INT64_C(0b011010010101001111110111100010000010011000101001111001111100111));\n\
    \n  assert_that(tools::rotate_right(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ), -9223372036854775807 - 1) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ),     -9223372036854775807) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ),                     -128) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ),                     -127) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ),                      -65) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ),                      -64) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ),                      -63) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ),                       -2) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ),                       -1) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ),                        0) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ),                        1) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ),                        2) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ),                       63) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ),                       64) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ),                       65) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ),                      127) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ),                      128) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ),      9223372036854775807) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n\n  assert_that(tools::rotate_right(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000001\"\
    ), -9223372036854775807 - 1) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000001\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000001\"\
    ),     -9223372036854775807) == std::bitset<64>(\"1000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000001\"\
    ),                     -128) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000001\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000001\"\
    ),                     -127) == std::bitset<64>(\"1000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000001\"\
    ),                      -65) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000010\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000001\"\
    ),                      -64) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000001\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000001\"\
    ),                      -63) == std::bitset<64>(\"1000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000001\"\
    ),                       -2) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000100\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000001\"\
    ),                       -1) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000010\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000001\"\
    ),                        0) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000001\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000001\"\
    ),                        1) == std::bitset<64>(\"1000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000001\"\
    ),                        2) == std::bitset<64>(\"0100000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000001\"\
    ),                       63) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000010\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000001\"\
    ),                       64) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000001\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000001\"\
    ),                       65) == std::bitset<64>(\"1000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000001\"\
    ),                      127) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000010\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000001\"\
    ),                      128) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000001\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000001\"\
    ),      9223372036854775807) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000010\"\
    ));\n\n  assert_that(tools::rotate_right(std::bitset<64>(\"1000000000000000000000000000000000000000000000000000000000000000\"\
    ), -9223372036854775807 - 1) == std::bitset<64>(\"1000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"1000000000000000000000000000000000000000000000000000000000000000\"\
    ),     -9223372036854775807) == std::bitset<64>(\"0100000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"1000000000000000000000000000000000000000000000000000000000000000\"\
    ),                     -128) == std::bitset<64>(\"1000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"1000000000000000000000000000000000000000000000000000000000000000\"\
    ),                     -127) == std::bitset<64>(\"0100000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"1000000000000000000000000000000000000000000000000000000000000000\"\
    ),                      -65) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000001\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"1000000000000000000000000000000000000000000000000000000000000000\"\
    ),                      -64) == std::bitset<64>(\"1000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"1000000000000000000000000000000000000000000000000000000000000000\"\
    ),                      -63) == std::bitset<64>(\"0100000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"1000000000000000000000000000000000000000000000000000000000000000\"\
    ),                       -2) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000010\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"1000000000000000000000000000000000000000000000000000000000000000\"\
    ),                       -1) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000001\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"1000000000000000000000000000000000000000000000000000000000000000\"\
    ),                        0) == std::bitset<64>(\"1000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"1000000000000000000000000000000000000000000000000000000000000000\"\
    ),                        1) == std::bitset<64>(\"0100000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"1000000000000000000000000000000000000000000000000000000000000000\"\
    ),                        2) == std::bitset<64>(\"0010000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"1000000000000000000000000000000000000000000000000000000000000000\"\
    ),                       63) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000001\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"1000000000000000000000000000000000000000000000000000000000000000\"\
    ),                       64) == std::bitset<64>(\"1000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"1000000000000000000000000000000000000000000000000000000000000000\"\
    ),                       65) == std::bitset<64>(\"0100000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"1000000000000000000000000000000000000000000000000000000000000000\"\
    ),                      127) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000001\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"1000000000000000000000000000000000000000000000000000000000000000\"\
    ),                      128) == std::bitset<64>(\"1000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"1000000000000000000000000000000000000000000000000000000000000000\"\
    ),      9223372036854775807) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000001\"\
    ));\n\n  assert_that(tools::rotate_right(std::bitset<64>(\"0101010011111101111000100000100110001010011110011111001110110100\"\
    ), -9223372036854775807 - 1) == std::bitset<64>(\"0101010011111101111000100000100110001010011110011111001110110100\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"0101010011111101111000100000100110001010011110011111001110110100\"\
    ),     -9223372036854775807) == std::bitset<64>(\"0010101001111110111100010000010011000101001111001111100111011010\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"0101010011111101111000100000100110001010011110011111001110110100\"\
    ),                     -128) == std::bitset<64>(\"0101010011111101111000100000100110001010011110011111001110110100\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"0101010011111101111000100000100110001010011110011111001110110100\"\
    ),                     -127) == std::bitset<64>(\"0010101001111110111100010000010011000101001111001111100111011010\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"0101010011111101111000100000100110001010011110011111001110110100\"\
    ),                      -65) == std::bitset<64>(\"1010100111111011110001000001001100010100111100111110011101101000\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"0101010011111101111000100000100110001010011110011111001110110100\"\
    ),                      -64) == std::bitset<64>(\"0101010011111101111000100000100110001010011110011111001110110100\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"0101010011111101111000100000100110001010011110011111001110110100\"\
    ),                      -63) == std::bitset<64>(\"0010101001111110111100010000010011000101001111001111100111011010\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"0101010011111101111000100000100110001010011110011111001110110100\"\
    ),                       -2) == std::bitset<64>(\"0101001111110111100010000010011000101001111001111100111011010001\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"0101010011111101111000100000100110001010011110011111001110110100\"\
    ),                       -1) == std::bitset<64>(\"1010100111111011110001000001001100010100111100111110011101101000\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"0101010011111101111000100000100110001010011110011111001110110100\"\
    ),                        0) == std::bitset<64>(\"0101010011111101111000100000100110001010011110011111001110110100\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"0101010011111101111000100000100110001010011110011111001110110100\"\
    ),                        1) == std::bitset<64>(\"0010101001111110111100010000010011000101001111001111100111011010\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"0101010011111101111000100000100110001010011110011111001110110100\"\
    ),                        2) == std::bitset<64>(\"0001010100111111011110001000001001100010100111100111110011101101\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"0101010011111101111000100000100110001010011110011111001110110100\"\
    ),                       63) == std::bitset<64>(\"1010100111111011110001000001001100010100111100111110011101101000\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"0101010011111101111000100000100110001010011110011111001110110100\"\
    ),                       64) == std::bitset<64>(\"0101010011111101111000100000100110001010011110011111001110110100\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"0101010011111101111000100000100110001010011110011111001110110100\"\
    ),                       65) == std::bitset<64>(\"0010101001111110111100010000010011000101001111001111100111011010\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"0101010011111101111000100000100110001010011110011111001110110100\"\
    ),                      127) == std::bitset<64>(\"1010100111111011110001000001001100010100111100111110011101101000\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"0101010011111101111000100000100110001010011110011111001110110100\"\
    ),                      128) == std::bitset<64>(\"0101010011111101111000100000100110001010011110011111001110110100\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"0101010011111101111000100000100110001010011110011111001110110100\"\
    ),      9223372036854775807) == std::bitset<64>(\"1010100111111011110001000001001100010100111100111110011101101000\"\
    ));\n\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ), -9223372036854775807 - 1) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ),     -9223372036854775807) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ),                     -126) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ),                     -125) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ),                      -64) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ),                      -63) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ),                      -62) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ),                       -2) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ),                       -1) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ),                        0) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ),                        1) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ),                        2) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ),                       62) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ),                       63) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ),                       64) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ),                      125) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ),                      126) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ),      9223372036854775807) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000001\"\
    ), -9223372036854775807 - 1) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000100000000\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000001\"\
    ),     -9223372036854775807) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000010000000\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000001\"\
    ),                     -126) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000001\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000001\"\
    ),                     -125) == tools::dynamic_bitset(\"100000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000001\"\
    ),                      -64) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000010\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000001\"\
    ),                      -63) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000001\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000001\"\
    ),                      -62) == tools::dynamic_bitset(\"100000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000001\"\
    ),                       -2) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000100\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000001\"\
    ),                       -1) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000010\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000001\"\
    ),                        0) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000001\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000001\"\
    ),                        1) == tools::dynamic_bitset(\"100000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000001\"\
    ),                        2) == tools::dynamic_bitset(\"010000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000001\"\
    ),                       62) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000010\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000001\"\
    ),                       63) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000001\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000001\"\
    ),                       64) == tools::dynamic_bitset(\"100000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000001\"\
    ),                      125) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000010\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000001\"\
    ),                      126) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000001\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000001\"\
    ),      9223372036854775807) == tools::dynamic_bitset(\"000000100000000000000000000000000000000000000000000000000000000\"\
    ));\n\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"100000000000000000000000000000000000000000000000000000000000000\"\
    ), -9223372036854775807 - 1) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000010000000\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"100000000000000000000000000000000000000000000000000000000000000\"\
    ),     -9223372036854775807) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000001000000\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"100000000000000000000000000000000000000000000000000000000000000\"\
    ),                     -126) == tools::dynamic_bitset(\"100000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"100000000000000000000000000000000000000000000000000000000000000\"\
    ),                     -125) == tools::dynamic_bitset(\"010000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"100000000000000000000000000000000000000000000000000000000000000\"\
    ),                      -64) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000001\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"100000000000000000000000000000000000000000000000000000000000000\"\
    ),                      -63) == tools::dynamic_bitset(\"100000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"100000000000000000000000000000000000000000000000000000000000000\"\
    ),                      -62) == tools::dynamic_bitset(\"010000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"100000000000000000000000000000000000000000000000000000000000000\"\
    ),                       -2) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000010\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"100000000000000000000000000000000000000000000000000000000000000\"\
    ),                       -1) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000001\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"100000000000000000000000000000000000000000000000000000000000000\"\
    ),                        0) == tools::dynamic_bitset(\"100000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"100000000000000000000000000000000000000000000000000000000000000\"\
    ),                        1) == tools::dynamic_bitset(\"010000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"100000000000000000000000000000000000000000000000000000000000000\"\
    ),                        2) == tools::dynamic_bitset(\"001000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"100000000000000000000000000000000000000000000000000000000000000\"\
    ),                       62) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000001\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"100000000000000000000000000000000000000000000000000000000000000\"\
    ),                       63) == tools::dynamic_bitset(\"100000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"100000000000000000000000000000000000000000000000000000000000000\"\
    ),                       64) == tools::dynamic_bitset(\"010000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"100000000000000000000000000000000000000000000000000000000000000\"\
    ),                      125) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000001\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"100000000000000000000000000000000000000000000000000000000000000\"\
    ),                      126) == tools::dynamic_bitset(\"100000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"100000000000000000000000000000000000000000000000000000000000000\"\
    ),      9223372036854775807) == tools::dynamic_bitset(\"000000010000000000000000000000000000000000000000000000000000000\"\
    ));\n\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"101010011111101111000100000100110001010011110011111001110110100\"\
    ), -9223372036854775807 - 1) == tools::dynamic_bitset(\"111110111100010000010011000101001111001111100111011010010101001\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"101010011111101111000100000100110001010011110011111001110110100\"\
    ),     -9223372036854775807) == tools::dynamic_bitset(\"111111011110001000001001100010100111100111110011101101001010100\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"101010011111101111000100000100110001010011110011111001110110100\"\
    ),                     -126) == tools::dynamic_bitset(\"101010011111101111000100000100110001010011110011111001110110100\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"101010011111101111000100000100110001010011110011111001110110100\"\
    ),                     -125) == tools::dynamic_bitset(\"010101001111110111100010000010011000101001111001111100111011010\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"101010011111101111000100000100110001010011110011111001110110100\"\
    ),                      -64) == tools::dynamic_bitset(\"010100111111011110001000001001100010100111100111110011101101001\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"101010011111101111000100000100110001010011110011111001110110100\"\
    ),                      -63) == tools::dynamic_bitset(\"101010011111101111000100000100110001010011110011111001110110100\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"101010011111101111000100000100110001010011110011111001110110100\"\
    ),                      -62) == tools::dynamic_bitset(\"010101001111110111100010000010011000101001111001111100111011010\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"101010011111101111000100000100110001010011110011111001110110100\"\
    ),                       -2) == tools::dynamic_bitset(\"101001111110111100010000010011000101001111001111100111011010010\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"101010011111101111000100000100110001010011110011111001110110100\"\
    ),                       -1) == tools::dynamic_bitset(\"010100111111011110001000001001100010100111100111110011101101001\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"101010011111101111000100000100110001010011110011111001110110100\"\
    ),                        0) == tools::dynamic_bitset(\"101010011111101111000100000100110001010011110011111001110110100\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"101010011111101111000100000100110001010011110011111001110110100\"\
    ),                        1) == tools::dynamic_bitset(\"010101001111110111100010000010011000101001111001111100111011010\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"101010011111101111000100000100110001010011110011111001110110100\"\
    ),                        2) == tools::dynamic_bitset(\"001010100111111011110001000001001100010100111100111110011101101\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"101010011111101111000100000100110001010011110011111001110110100\"\
    ),                       62) == tools::dynamic_bitset(\"010100111111011110001000001001100010100111100111110011101101001\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"101010011111101111000100000100110001010011110011111001110110100\"\
    ),                       63) == tools::dynamic_bitset(\"101010011111101111000100000100110001010011110011111001110110100\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"101010011111101111000100000100110001010011110011111001110110100\"\
    ),                       64) == tools::dynamic_bitset(\"010101001111110111100010000010011000101001111001111100111011010\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"101010011111101111000100000100110001010011110011111001110110100\"\
    ),                      125) == tools::dynamic_bitset(\"010100111111011110001000001001100010100111100111110011101101001\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"101010011111101111000100000100110001010011110011111001110110100\"\
    ),                      126) == tools::dynamic_bitset(\"101010011111101111000100000100110001010011110011111001110110100\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"101010011111101111000100000100110001010011110011111001110110100\"\
    ),      9223372036854775807) == tools::dynamic_bitset(\"011010010101001111110111100010000010011000101001111001111100111\"\
    ));\n\n  assert_that(tools::rotate_right(0, 0, 9223372036854775807) == 0);\n \
    \ assert_that(tools::rotate_right(0, 1, 9223372036854775807) == 0);\n  assert_that(tools::rotate_right(1,\
    \ 1, 9223372036854775807) == 1);\n\n  std::cout << \"Hello World\" << '\\n';\n\
    \  return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\"\n\n\
    #include <iostream>\n#include <cstdint>\n#include <bitset>\n#include \"tools/assert_that.hpp\"\
    \n#include \"tools/rotate_right.hpp\"\n#include \"tools/dynamic_bitset.hpp\"\n\
    \nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  assert_that(tools::rotate_right(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000),\
    \ 64, -9223372036854775807 - 1) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,     -9223372036854775807) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,                     -128) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,                     -127) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,                      -65) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,                      -64) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,                      -63) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,                       -2) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,                       -1) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,                        0) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,                        1) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,                        2) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,                       63) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,                       64) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,                       65) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,                      127) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,                      128) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,      9223372036854775807) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000));\n\
    \n  assert_that(tools::rotate_right(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001),\
    \ 64, -9223372036854775807 - 1) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001),\
    \ 64,     -9223372036854775807) == UINT64_C(0b1000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001),\
    \ 64,                     -128) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001),\
    \ 64,                     -127) == UINT64_C(0b1000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001),\
    \ 64,                      -65) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000010));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001),\
    \ 64,                      -64) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001),\
    \ 64,                      -63) == UINT64_C(0b1000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001),\
    \ 64,                       -2) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000100));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001),\
    \ 64,                       -1) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000010));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001),\
    \ 64,                        0) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001),\
    \ 64,                        1) == UINT64_C(0b1000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001),\
    \ 64,                        2) == UINT64_C(0b0100000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001),\
    \ 64,                       63) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000010));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001),\
    \ 64,                       64) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001),\
    \ 64,                       65) == UINT64_C(0b1000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001),\
    \ 64,                      127) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000010));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001),\
    \ 64,                      128) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001),\
    \ 64,      9223372036854775807) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000010));\n\
    \n  assert_that(tools::rotate_right(UINT64_C(0b1000000000000000000000000000000000000000000000000000000000000000),\
    \ 64, -9223372036854775807 - 1) == UINT64_C(0b1000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b1000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,     -9223372036854775807) == UINT64_C(0b0100000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b1000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,                     -128) == UINT64_C(0b1000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b1000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,                     -127) == UINT64_C(0b0100000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b1000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,                      -65) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b1000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,                      -64) == UINT64_C(0b1000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b1000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,                      -63) == UINT64_C(0b0100000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b1000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,                       -2) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000010));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b1000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,                       -1) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b1000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,                        0) == UINT64_C(0b1000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b1000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,                        1) == UINT64_C(0b0100000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b1000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,                        2) == UINT64_C(0b0010000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b1000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,                       63) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b1000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,                       64) == UINT64_C(0b1000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b1000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,                       65) == UINT64_C(0b0100000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b1000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,                      127) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b1000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,                      128) == UINT64_C(0b1000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b1000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,      9223372036854775807) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001));\n\
    \n  assert_that(tools::rotate_right(UINT64_C(0b0101010011111101111000100000100110001010011110011111001110110100),\
    \ 64, -9223372036854775807 - 1) == UINT64_C(0b0101010011111101111000100000100110001010011110011111001110110100));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b0101010011111101111000100000100110001010011110011111001110110100),\
    \ 64,     -9223372036854775807) == UINT64_C(0b0010101001111110111100010000010011000101001111001111100111011010));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b0101010011111101111000100000100110001010011110011111001110110100),\
    \ 64,                     -128) == UINT64_C(0b0101010011111101111000100000100110001010011110011111001110110100));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b0101010011111101111000100000100110001010011110011111001110110100),\
    \ 64,                     -127) == UINT64_C(0b0010101001111110111100010000010011000101001111001111100111011010));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b0101010011111101111000100000100110001010011110011111001110110100),\
    \ 64,                      -65) == UINT64_C(0b1010100111111011110001000001001100010100111100111110011101101000));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b0101010011111101111000100000100110001010011110011111001110110100),\
    \ 64,                      -64) == UINT64_C(0b0101010011111101111000100000100110001010011110011111001110110100));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b0101010011111101111000100000100110001010011110011111001110110100),\
    \ 64,                      -63) == UINT64_C(0b0010101001111110111100010000010011000101001111001111100111011010));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b0101010011111101111000100000100110001010011110011111001110110100),\
    \ 64,                       -2) == UINT64_C(0b0101001111110111100010000010011000101001111001111100111011010001));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b0101010011111101111000100000100110001010011110011111001110110100),\
    \ 64,                       -1) == UINT64_C(0b1010100111111011110001000001001100010100111100111110011101101000));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b0101010011111101111000100000100110001010011110011111001110110100),\
    \ 64,                        0) == UINT64_C(0b0101010011111101111000100000100110001010011110011111001110110100));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b0101010011111101111000100000100110001010011110011111001110110100),\
    \ 64,                        1) == UINT64_C(0b0010101001111110111100010000010011000101001111001111100111011010));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b0101010011111101111000100000100110001010011110011111001110110100),\
    \ 64,                        2) == UINT64_C(0b0001010100111111011110001000001001100010100111100111110011101101));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b0101010011111101111000100000100110001010011110011111001110110100),\
    \ 64,                       63) == UINT64_C(0b1010100111111011110001000001001100010100111100111110011101101000));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b0101010011111101111000100000100110001010011110011111001110110100),\
    \ 64,                       64) == UINT64_C(0b0101010011111101111000100000100110001010011110011111001110110100));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b0101010011111101111000100000100110001010011110011111001110110100),\
    \ 64,                       65) == UINT64_C(0b0010101001111110111100010000010011000101001111001111100111011010));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b0101010011111101111000100000100110001010011110011111001110110100),\
    \ 64,                      127) == UINT64_C(0b1010100111111011110001000001001100010100111100111110011101101000));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b0101010011111101111000100000100110001010011110011111001110110100),\
    \ 64,                      128) == UINT64_C(0b0101010011111101111000100000100110001010011110011111001110110100));\n\
    \  assert_that(tools::rotate_right(UINT64_C(0b0101010011111101111000100000100110001010011110011111001110110100),\
    \ 64,      9223372036854775807) == UINT64_C(0b1010100111111011110001000001001100010100111100111110011101101000));\n\
    \n  assert_that(tools::rotate_right(INT64_C(0b000000000000000000000000000000000000000000000000000000000000000),\
    \ 63, -9223372036854775807 - 1) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b000000000000000000000000000000000000000000000000000000000000000),\
    \ 63,     -9223372036854775807) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b000000000000000000000000000000000000000000000000000000000000000),\
    \ 63,                     -126) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b000000000000000000000000000000000000000000000000000000000000000),\
    \ 63,                     -125) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b000000000000000000000000000000000000000000000000000000000000000),\
    \ 63,                      -64) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b000000000000000000000000000000000000000000000000000000000000000),\
    \ 63,                      -63) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b000000000000000000000000000000000000000000000000000000000000000),\
    \ 63,                      -62) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b000000000000000000000000000000000000000000000000000000000000000),\
    \ 63,                       -2) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b000000000000000000000000000000000000000000000000000000000000000),\
    \ 63,                       -1) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b000000000000000000000000000000000000000000000000000000000000000),\
    \ 63,                        0) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b000000000000000000000000000000000000000000000000000000000000000),\
    \ 63,                        1) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b000000000000000000000000000000000000000000000000000000000000000),\
    \ 63,                        2) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b000000000000000000000000000000000000000000000000000000000000000),\
    \ 63,                       62) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b000000000000000000000000000000000000000000000000000000000000000),\
    \ 63,                       63) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b000000000000000000000000000000000000000000000000000000000000000),\
    \ 63,                       64) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b000000000000000000000000000000000000000000000000000000000000000),\
    \ 63,                      125) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b000000000000000000000000000000000000000000000000000000000000000),\
    \ 63,                      126) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b000000000000000000000000000000000000000000000000000000000000000),\
    \ 63,      9223372036854775807) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000000));\n\
    \n  assert_that(tools::rotate_right(INT64_C(0b000000000000000000000000000000000000000000000000000000000000001),\
    \ 63, -9223372036854775807 - 1) == INT64_C(0b000000000000000000000000000000000000000000000000000000100000000));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b000000000000000000000000000000000000000000000000000000000000001),\
    \ 63,     -9223372036854775807) == INT64_C(0b000000000000000000000000000000000000000000000000000000010000000));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b000000000000000000000000000000000000000000000000000000000000001),\
    \ 63,                     -126) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000001));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b000000000000000000000000000000000000000000000000000000000000001),\
    \ 63,                     -125) == INT64_C(0b100000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b000000000000000000000000000000000000000000000000000000000000001),\
    \ 63,                      -64) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000010));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b000000000000000000000000000000000000000000000000000000000000001),\
    \ 63,                      -63) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000001));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b000000000000000000000000000000000000000000000000000000000000001),\
    \ 63,                      -62) == INT64_C(0b100000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b000000000000000000000000000000000000000000000000000000000000001),\
    \ 63,                       -2) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000100));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b000000000000000000000000000000000000000000000000000000000000001),\
    \ 63,                       -1) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000010));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b000000000000000000000000000000000000000000000000000000000000001),\
    \ 63,                        0) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000001));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b000000000000000000000000000000000000000000000000000000000000001),\
    \ 63,                        1) == INT64_C(0b100000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b000000000000000000000000000000000000000000000000000000000000001),\
    \ 63,                        2) == INT64_C(0b010000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b000000000000000000000000000000000000000000000000000000000000001),\
    \ 63,                       62) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000010));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b000000000000000000000000000000000000000000000000000000000000001),\
    \ 63,                       63) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000001));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b000000000000000000000000000000000000000000000000000000000000001),\
    \ 63,                       64) == INT64_C(0b100000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b000000000000000000000000000000000000000000000000000000000000001),\
    \ 63,                      125) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000010));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b000000000000000000000000000000000000000000000000000000000000001),\
    \ 63,                      126) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000001));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b000000000000000000000000000000000000000000000000000000000000001),\
    \ 63,      9223372036854775807) == INT64_C(0b000000100000000000000000000000000000000000000000000000000000000));\n\
    \n  assert_that(tools::rotate_right(INT64_C(0b100000000000000000000000000000000000000000000000000000000000000),\
    \ 63, -9223372036854775807 - 1) == INT64_C(0b000000000000000000000000000000000000000000000000000000010000000));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b100000000000000000000000000000000000000000000000000000000000000),\
    \ 63,     -9223372036854775807) == INT64_C(0b000000000000000000000000000000000000000000000000000000001000000));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b100000000000000000000000000000000000000000000000000000000000000),\
    \ 63,                     -126) == INT64_C(0b100000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b100000000000000000000000000000000000000000000000000000000000000),\
    \ 63,                     -125) == INT64_C(0b010000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b100000000000000000000000000000000000000000000000000000000000000),\
    \ 63,                      -64) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000001));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b100000000000000000000000000000000000000000000000000000000000000),\
    \ 63,                      -63) == INT64_C(0b100000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b100000000000000000000000000000000000000000000000000000000000000),\
    \ 63,                      -62) == INT64_C(0b010000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b100000000000000000000000000000000000000000000000000000000000000),\
    \ 63,                       -2) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000010));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b100000000000000000000000000000000000000000000000000000000000000),\
    \ 63,                       -1) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000001));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b100000000000000000000000000000000000000000000000000000000000000),\
    \ 63,                        0) == INT64_C(0b100000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b100000000000000000000000000000000000000000000000000000000000000),\
    \ 63,                        1) == INT64_C(0b010000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b100000000000000000000000000000000000000000000000000000000000000),\
    \ 63,                        2) == INT64_C(0b001000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b100000000000000000000000000000000000000000000000000000000000000),\
    \ 63,                       62) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000001));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b100000000000000000000000000000000000000000000000000000000000000),\
    \ 63,                       63) == INT64_C(0b100000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b100000000000000000000000000000000000000000000000000000000000000),\
    \ 63,                       64) == INT64_C(0b010000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b100000000000000000000000000000000000000000000000000000000000000),\
    \ 63,                      125) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000001));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b100000000000000000000000000000000000000000000000000000000000000),\
    \ 63,                      126) == INT64_C(0b100000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b100000000000000000000000000000000000000000000000000000000000000),\
    \ 63,      9223372036854775807) == INT64_C(0b000000010000000000000000000000000000000000000000000000000000000));\n\
    \n  assert_that(tools::rotate_right(INT64_C(0b101010011111101111000100000100110001010011110011111001110110100),\
    \ 63, -9223372036854775807 - 1) == INT64_C(0b111110111100010000010011000101001111001111100111011010010101001));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b101010011111101111000100000100110001010011110011111001110110100),\
    \ 63,     -9223372036854775807) == INT64_C(0b111111011110001000001001100010100111100111110011101101001010100));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b101010011111101111000100000100110001010011110011111001110110100),\
    \ 63,                     -126) == INT64_C(0b101010011111101111000100000100110001010011110011111001110110100));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b101010011111101111000100000100110001010011110011111001110110100),\
    \ 63,                     -125) == INT64_C(0b010101001111110111100010000010011000101001111001111100111011010));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b101010011111101111000100000100110001010011110011111001110110100),\
    \ 63,                      -64) == INT64_C(0b010100111111011110001000001001100010100111100111110011101101001));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b101010011111101111000100000100110001010011110011111001110110100),\
    \ 63,                      -63) == INT64_C(0b101010011111101111000100000100110001010011110011111001110110100));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b101010011111101111000100000100110001010011110011111001110110100),\
    \ 63,                      -62) == INT64_C(0b010101001111110111100010000010011000101001111001111100111011010));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b101010011111101111000100000100110001010011110011111001110110100),\
    \ 63,                       -2) == INT64_C(0b101001111110111100010000010011000101001111001111100111011010010));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b101010011111101111000100000100110001010011110011111001110110100),\
    \ 63,                       -1) == INT64_C(0b010100111111011110001000001001100010100111100111110011101101001));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b101010011111101111000100000100110001010011110011111001110110100),\
    \ 63,                        0) == INT64_C(0b101010011111101111000100000100110001010011110011111001110110100));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b101010011111101111000100000100110001010011110011111001110110100),\
    \ 63,                        1) == INT64_C(0b010101001111110111100010000010011000101001111001111100111011010));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b101010011111101111000100000100110001010011110011111001110110100),\
    \ 63,                        2) == INT64_C(0b001010100111111011110001000001001100010100111100111110011101101));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b101010011111101111000100000100110001010011110011111001110110100),\
    \ 63,                       62) == INT64_C(0b010100111111011110001000001001100010100111100111110011101101001));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b101010011111101111000100000100110001010011110011111001110110100),\
    \ 63,                       63) == INT64_C(0b101010011111101111000100000100110001010011110011111001110110100));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b101010011111101111000100000100110001010011110011111001110110100),\
    \ 63,                       64) == INT64_C(0b010101001111110111100010000010011000101001111001111100111011010));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b101010011111101111000100000100110001010011110011111001110110100),\
    \ 63,                      125) == INT64_C(0b010100111111011110001000001001100010100111100111110011101101001));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b101010011111101111000100000100110001010011110011111001110110100),\
    \ 63,                      126) == INT64_C(0b101010011111101111000100000100110001010011110011111001110110100));\n\
    \  assert_that(tools::rotate_right(INT64_C(0b101010011111101111000100000100110001010011110011111001110110100),\
    \ 63,      9223372036854775807) == INT64_C(0b011010010101001111110111100010000010011000101001111001111100111));\n\
    \n  assert_that(tools::rotate_right(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ), -9223372036854775807 - 1) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ),     -9223372036854775807) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ),                     -128) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ),                     -127) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ),                      -65) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ),                      -64) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ),                      -63) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ),                       -2) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ),                       -1) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ),                        0) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ),                        1) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ),                        2) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ),                       63) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ),                       64) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ),                       65) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ),                      127) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ),                      128) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ),      9223372036854775807) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n\n  assert_that(tools::rotate_right(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000001\"\
    ), -9223372036854775807 - 1) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000001\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000001\"\
    ),     -9223372036854775807) == std::bitset<64>(\"1000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000001\"\
    ),                     -128) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000001\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000001\"\
    ),                     -127) == std::bitset<64>(\"1000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000001\"\
    ),                      -65) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000010\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000001\"\
    ),                      -64) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000001\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000001\"\
    ),                      -63) == std::bitset<64>(\"1000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000001\"\
    ),                       -2) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000100\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000001\"\
    ),                       -1) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000010\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000001\"\
    ),                        0) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000001\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000001\"\
    ),                        1) == std::bitset<64>(\"1000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000001\"\
    ),                        2) == std::bitset<64>(\"0100000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000001\"\
    ),                       63) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000010\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000001\"\
    ),                       64) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000001\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000001\"\
    ),                       65) == std::bitset<64>(\"1000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000001\"\
    ),                      127) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000010\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000001\"\
    ),                      128) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000001\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000001\"\
    ),      9223372036854775807) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000010\"\
    ));\n\n  assert_that(tools::rotate_right(std::bitset<64>(\"1000000000000000000000000000000000000000000000000000000000000000\"\
    ), -9223372036854775807 - 1) == std::bitset<64>(\"1000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"1000000000000000000000000000000000000000000000000000000000000000\"\
    ),     -9223372036854775807) == std::bitset<64>(\"0100000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"1000000000000000000000000000000000000000000000000000000000000000\"\
    ),                     -128) == std::bitset<64>(\"1000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"1000000000000000000000000000000000000000000000000000000000000000\"\
    ),                     -127) == std::bitset<64>(\"0100000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"1000000000000000000000000000000000000000000000000000000000000000\"\
    ),                      -65) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000001\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"1000000000000000000000000000000000000000000000000000000000000000\"\
    ),                      -64) == std::bitset<64>(\"1000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"1000000000000000000000000000000000000000000000000000000000000000\"\
    ),                      -63) == std::bitset<64>(\"0100000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"1000000000000000000000000000000000000000000000000000000000000000\"\
    ),                       -2) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000010\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"1000000000000000000000000000000000000000000000000000000000000000\"\
    ),                       -1) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000001\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"1000000000000000000000000000000000000000000000000000000000000000\"\
    ),                        0) == std::bitset<64>(\"1000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"1000000000000000000000000000000000000000000000000000000000000000\"\
    ),                        1) == std::bitset<64>(\"0100000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"1000000000000000000000000000000000000000000000000000000000000000\"\
    ),                        2) == std::bitset<64>(\"0010000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"1000000000000000000000000000000000000000000000000000000000000000\"\
    ),                       63) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000001\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"1000000000000000000000000000000000000000000000000000000000000000\"\
    ),                       64) == std::bitset<64>(\"1000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"1000000000000000000000000000000000000000000000000000000000000000\"\
    ),                       65) == std::bitset<64>(\"0100000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"1000000000000000000000000000000000000000000000000000000000000000\"\
    ),                      127) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000001\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"1000000000000000000000000000000000000000000000000000000000000000\"\
    ),                      128) == std::bitset<64>(\"1000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"1000000000000000000000000000000000000000000000000000000000000000\"\
    ),      9223372036854775807) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000001\"\
    ));\n\n  assert_that(tools::rotate_right(std::bitset<64>(\"0101010011111101111000100000100110001010011110011111001110110100\"\
    ), -9223372036854775807 - 1) == std::bitset<64>(\"0101010011111101111000100000100110001010011110011111001110110100\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"0101010011111101111000100000100110001010011110011111001110110100\"\
    ),     -9223372036854775807) == std::bitset<64>(\"0010101001111110111100010000010011000101001111001111100111011010\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"0101010011111101111000100000100110001010011110011111001110110100\"\
    ),                     -128) == std::bitset<64>(\"0101010011111101111000100000100110001010011110011111001110110100\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"0101010011111101111000100000100110001010011110011111001110110100\"\
    ),                     -127) == std::bitset<64>(\"0010101001111110111100010000010011000101001111001111100111011010\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"0101010011111101111000100000100110001010011110011111001110110100\"\
    ),                      -65) == std::bitset<64>(\"1010100111111011110001000001001100010100111100111110011101101000\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"0101010011111101111000100000100110001010011110011111001110110100\"\
    ),                      -64) == std::bitset<64>(\"0101010011111101111000100000100110001010011110011111001110110100\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"0101010011111101111000100000100110001010011110011111001110110100\"\
    ),                      -63) == std::bitset<64>(\"0010101001111110111100010000010011000101001111001111100111011010\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"0101010011111101111000100000100110001010011110011111001110110100\"\
    ),                       -2) == std::bitset<64>(\"0101001111110111100010000010011000101001111001111100111011010001\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"0101010011111101111000100000100110001010011110011111001110110100\"\
    ),                       -1) == std::bitset<64>(\"1010100111111011110001000001001100010100111100111110011101101000\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"0101010011111101111000100000100110001010011110011111001110110100\"\
    ),                        0) == std::bitset<64>(\"0101010011111101111000100000100110001010011110011111001110110100\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"0101010011111101111000100000100110001010011110011111001110110100\"\
    ),                        1) == std::bitset<64>(\"0010101001111110111100010000010011000101001111001111100111011010\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"0101010011111101111000100000100110001010011110011111001110110100\"\
    ),                        2) == std::bitset<64>(\"0001010100111111011110001000001001100010100111100111110011101101\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"0101010011111101111000100000100110001010011110011111001110110100\"\
    ),                       63) == std::bitset<64>(\"1010100111111011110001000001001100010100111100111110011101101000\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"0101010011111101111000100000100110001010011110011111001110110100\"\
    ),                       64) == std::bitset<64>(\"0101010011111101111000100000100110001010011110011111001110110100\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"0101010011111101111000100000100110001010011110011111001110110100\"\
    ),                       65) == std::bitset<64>(\"0010101001111110111100010000010011000101001111001111100111011010\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"0101010011111101111000100000100110001010011110011111001110110100\"\
    ),                      127) == std::bitset<64>(\"1010100111111011110001000001001100010100111100111110011101101000\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"0101010011111101111000100000100110001010011110011111001110110100\"\
    ),                      128) == std::bitset<64>(\"0101010011111101111000100000100110001010011110011111001110110100\"\
    ));\n  assert_that(tools::rotate_right(std::bitset<64>(\"0101010011111101111000100000100110001010011110011111001110110100\"\
    ),      9223372036854775807) == std::bitset<64>(\"1010100111111011110001000001001100010100111100111110011101101000\"\
    ));\n\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ), -9223372036854775807 - 1) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ),     -9223372036854775807) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ),                     -126) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ),                     -125) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ),                      -64) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ),                      -63) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ),                      -62) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ),                       -2) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ),                       -1) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ),                        0) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ),                        1) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ),                        2) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ),                       62) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ),                       63) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ),                       64) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ),                      125) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ),                      126) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ),      9223372036854775807) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000001\"\
    ), -9223372036854775807 - 1) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000100000000\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000001\"\
    ),     -9223372036854775807) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000010000000\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000001\"\
    ),                     -126) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000001\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000001\"\
    ),                     -125) == tools::dynamic_bitset(\"100000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000001\"\
    ),                      -64) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000010\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000001\"\
    ),                      -63) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000001\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000001\"\
    ),                      -62) == tools::dynamic_bitset(\"100000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000001\"\
    ),                       -2) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000100\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000001\"\
    ),                       -1) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000010\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000001\"\
    ),                        0) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000001\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000001\"\
    ),                        1) == tools::dynamic_bitset(\"100000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000001\"\
    ),                        2) == tools::dynamic_bitset(\"010000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000001\"\
    ),                       62) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000010\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000001\"\
    ),                       63) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000001\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000001\"\
    ),                       64) == tools::dynamic_bitset(\"100000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000001\"\
    ),                      125) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000010\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000001\"\
    ),                      126) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000001\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000001\"\
    ),      9223372036854775807) == tools::dynamic_bitset(\"000000100000000000000000000000000000000000000000000000000000000\"\
    ));\n\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"100000000000000000000000000000000000000000000000000000000000000\"\
    ), -9223372036854775807 - 1) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000010000000\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"100000000000000000000000000000000000000000000000000000000000000\"\
    ),     -9223372036854775807) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000001000000\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"100000000000000000000000000000000000000000000000000000000000000\"\
    ),                     -126) == tools::dynamic_bitset(\"100000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"100000000000000000000000000000000000000000000000000000000000000\"\
    ),                     -125) == tools::dynamic_bitset(\"010000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"100000000000000000000000000000000000000000000000000000000000000\"\
    ),                      -64) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000001\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"100000000000000000000000000000000000000000000000000000000000000\"\
    ),                      -63) == tools::dynamic_bitset(\"100000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"100000000000000000000000000000000000000000000000000000000000000\"\
    ),                      -62) == tools::dynamic_bitset(\"010000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"100000000000000000000000000000000000000000000000000000000000000\"\
    ),                       -2) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000010\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"100000000000000000000000000000000000000000000000000000000000000\"\
    ),                       -1) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000001\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"100000000000000000000000000000000000000000000000000000000000000\"\
    ),                        0) == tools::dynamic_bitset(\"100000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"100000000000000000000000000000000000000000000000000000000000000\"\
    ),                        1) == tools::dynamic_bitset(\"010000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"100000000000000000000000000000000000000000000000000000000000000\"\
    ),                        2) == tools::dynamic_bitset(\"001000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"100000000000000000000000000000000000000000000000000000000000000\"\
    ),                       62) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000001\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"100000000000000000000000000000000000000000000000000000000000000\"\
    ),                       63) == tools::dynamic_bitset(\"100000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"100000000000000000000000000000000000000000000000000000000000000\"\
    ),                       64) == tools::dynamic_bitset(\"010000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"100000000000000000000000000000000000000000000000000000000000000\"\
    ),                      125) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000001\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"100000000000000000000000000000000000000000000000000000000000000\"\
    ),                      126) == tools::dynamic_bitset(\"100000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"100000000000000000000000000000000000000000000000000000000000000\"\
    ),      9223372036854775807) == tools::dynamic_bitset(\"000000010000000000000000000000000000000000000000000000000000000\"\
    ));\n\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"101010011111101111000100000100110001010011110011111001110110100\"\
    ), -9223372036854775807 - 1) == tools::dynamic_bitset(\"111110111100010000010011000101001111001111100111011010010101001\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"101010011111101111000100000100110001010011110011111001110110100\"\
    ),     -9223372036854775807) == tools::dynamic_bitset(\"111111011110001000001001100010100111100111110011101101001010100\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"101010011111101111000100000100110001010011110011111001110110100\"\
    ),                     -126) == tools::dynamic_bitset(\"101010011111101111000100000100110001010011110011111001110110100\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"101010011111101111000100000100110001010011110011111001110110100\"\
    ),                     -125) == tools::dynamic_bitset(\"010101001111110111100010000010011000101001111001111100111011010\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"101010011111101111000100000100110001010011110011111001110110100\"\
    ),                      -64) == tools::dynamic_bitset(\"010100111111011110001000001001100010100111100111110011101101001\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"101010011111101111000100000100110001010011110011111001110110100\"\
    ),                      -63) == tools::dynamic_bitset(\"101010011111101111000100000100110001010011110011111001110110100\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"101010011111101111000100000100110001010011110011111001110110100\"\
    ),                      -62) == tools::dynamic_bitset(\"010101001111110111100010000010011000101001111001111100111011010\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"101010011111101111000100000100110001010011110011111001110110100\"\
    ),                       -2) == tools::dynamic_bitset(\"101001111110111100010000010011000101001111001111100111011010010\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"101010011111101111000100000100110001010011110011111001110110100\"\
    ),                       -1) == tools::dynamic_bitset(\"010100111111011110001000001001100010100111100111110011101101001\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"101010011111101111000100000100110001010011110011111001110110100\"\
    ),                        0) == tools::dynamic_bitset(\"101010011111101111000100000100110001010011110011111001110110100\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"101010011111101111000100000100110001010011110011111001110110100\"\
    ),                        1) == tools::dynamic_bitset(\"010101001111110111100010000010011000101001111001111100111011010\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"101010011111101111000100000100110001010011110011111001110110100\"\
    ),                        2) == tools::dynamic_bitset(\"001010100111111011110001000001001100010100111100111110011101101\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"101010011111101111000100000100110001010011110011111001110110100\"\
    ),                       62) == tools::dynamic_bitset(\"010100111111011110001000001001100010100111100111110011101101001\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"101010011111101111000100000100110001010011110011111001110110100\"\
    ),                       63) == tools::dynamic_bitset(\"101010011111101111000100000100110001010011110011111001110110100\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"101010011111101111000100000100110001010011110011111001110110100\"\
    ),                       64) == tools::dynamic_bitset(\"010101001111110111100010000010011000101001111001111100111011010\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"101010011111101111000100000100110001010011110011111001110110100\"\
    ),                      125) == tools::dynamic_bitset(\"010100111111011110001000001001100010100111100111110011101101001\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"101010011111101111000100000100110001010011110011111001110110100\"\
    ),                      126) == tools::dynamic_bitset(\"101010011111101111000100000100110001010011110011111001110110100\"\
    ));\n  assert_that(tools::rotate_right(tools::dynamic_bitset(\"101010011111101111000100000100110001010011110011111001110110100\"\
    ),      9223372036854775807) == tools::dynamic_bitset(\"011010010101001111110111100010000010011000101001111001111100111\"\
    ));\n\n  assert_that(tools::rotate_right(0, 0, 9223372036854775807) == 0);\n \
    \ assert_that(tools::rotate_right(0, 1, 9223372036854775807) == 0);\n  assert_that(tools::rotate_right(1,\
    \ 1, 9223372036854775807) == 1);\n\n  std::cout << \"Hello World\" << '\\n';\n\
    \  return 0;\n}\n"
  dependsOn:
  - tools/assert_that.hpp
  - tools/rotate_right.hpp
  - tools/mod.hpp
  - tools/quo.hpp
  - tools/dynamic_bitset.hpp
  - tools/ceil.hpp
  - tools/popcount.hpp
  isVerificationFile: true
  path: tests/rotate_right.test.cpp
  requiredBy: []
  timestamp: '2022-10-08 19:22:04+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/rotate_right.test.cpp
layout: document
redirect_from:
- /verify/tests/rotate_right.test.cpp
- /verify/tests/rotate_right.test.cpp.html
title: tests/rotate_right.test.cpp
---
