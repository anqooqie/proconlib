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
    path: tools/countr_zero.hpp
    title: Number of trailing zeros
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
    path: tools/rotate_left.hpp
    title: Circular shift to the left
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
  bundledCode: "#line 1 \"tests/rotate_left.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\"\
    \n\n#include <iostream>\n#include <cstdint>\n#include <bitset>\n#line 1 \"tools/assert_that.hpp\"\
    \n\n\n\n#line 5 \"tools/assert_that.hpp\"\n#include <cstdlib>\n\n#define assert_that_impl(cond,\
    \ file, line, func) do {\\\n  if (!cond) {\\\n    ::std::cerr << file << ':' <<\
    \ line << \": \" << func << \": Assertion `\" << #cond << \"' failed.\" << '\\\
    n';\\\n    ::std::exit(EXIT_FAILURE);\\\n  }\\\n} while (false)\n#define assert_that(...)\
    \ assert_that_impl((__VA_ARGS__), __FILE__, __LINE__, __func__)\n\n\n#line 1 \"\
    tools/rotate_left.hpp\"\n\n\n\n#include <cassert>\n#include <limits>\n#line 1\
    \ \"tools/mod.hpp\"\n\n\n\n#include <type_traits>\n#line 1 \"tools/quo.hpp\"\n\
    \n\n\n#line 5 \"tools/quo.hpp\"\n\nnamespace tools {\n\n  template <typename M,\
    \ typename N>\n  constexpr ::std::common_type_t<M, N> quo(const M lhs, const N\
    \ rhs) {\n    using T = ::std::common_type_t<M, N>;\n    if (lhs >= M(0)) {\n\
    \      return lhs / rhs;\n    } else {\n      if (rhs >= N(0)) {\n        return\
    \ -((-lhs - T(1) + rhs) / rhs);\n      } else {\n        return (-lhs - T(1) +\
    \ -rhs) / -rhs;\n      }\n    }\n  }\n}\n\n\n#line 6 \"tools/mod.hpp\"\n\nnamespace\
    \ tools {\n\n  template <typename M, typename N>\n  constexpr ::std::common_type_t<M,\
    \ N> mod(const M lhs, const N rhs) {\n    if constexpr (::std::is_unsigned_v<M>\
    \ && ::std::is_unsigned_v<N>) {\n      return lhs % rhs;\n    } else {\n     \
    \ return lhs - ::tools::quo(lhs, rhs) * rhs;\n    }\n  }\n}\n\n\n#line 7 \"tools/rotate_left.hpp\"\
    \n\nnamespace tools {\n\n  template <typename T, typename U>\n  constexpr T rotate_left(const\
    \ T x, const ::std::size_t n, U s) {\n    assert(n <= ::std::numeric_limits<T>::digits);\n\
    \    const T mask = (n == ::std::numeric_limits<T>::digits ? ::std::numeric_limits<T>::max()\
    \ : (T(1) << n) - 1);\n    assert(0 <= x && x <= mask);\n    s = ::tools::mod(s,\
    \ n);\n    return ((x << s) | (x >> ((n - s) % n))) & mask;\n  }\n\n  template\
    \ <typename T, typename U>\n  T rotate_left(const T& x, U s) {\n    s = ::tools::mod(s,\
    \ x.size());\n    return (x << s) | (x >> ((x.size() - s) % x.size()));\n  }\n\
    }\n\n\n#line 1 \"tools/dynamic_bitset.hpp\"\n\n\n\n#include <cstddef>\n#line 7\
    \ \"tools/dynamic_bitset.hpp\"\n#include <vector>\n#include <string>\n#line 10\
    \ \"tools/dynamic_bitset.hpp\"\n#include <algorithm>\n#include <iterator>\n#include\
    \ <sstream>\n#line 1 \"tools/ceil.hpp\"\n\n\n\n#line 6 \"tools/ceil.hpp\"\n\n\
    namespace tools {\n\n  template <typename M, typename N>\n  constexpr ::std::common_type_t<M,\
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
    \ j) & 1);\n        }\n      }\n      return os;\n    }\n    bool empty() const\
    \ {\n      return this->m_size == 0;\n    }\n    void resize(const ::std::size_t\
    \ size) {\n      this->m_size = size;\n      this->m_bits.resize(::tools::ceil(size,\
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
    \    }\n  };\n}\n\n\n#line 9 \"tests/rotate_left.test.cpp\"\n\nint main() {\n\
    \  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\n  assert_that(tools::rotate_left(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000),\
    \ 64, -9223372036854775807 - 1) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,     -9223372036854775807) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,                     -128) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,                     -127) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,                      -65) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,                      -64) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,                      -63) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,                       -2) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,                       -1) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,                        0) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,                        1) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,                        2) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,                       63) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,                       64) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,                       65) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,                      127) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,                      128) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,      9223372036854775807) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000));\n\
    \n  assert_that(tools::rotate_left(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001),\
    \ 64, -9223372036854775807 - 1) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001),\
    \ 64,     -9223372036854775807) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000010));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001),\
    \ 64,                     -128) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001),\
    \ 64,                     -127) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000010));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001),\
    \ 64,                      -65) == UINT64_C(0b1000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001),\
    \ 64,                      -64) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001),\
    \ 64,                      -63) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000010));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001),\
    \ 64,                       -2) == UINT64_C(0b0100000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001),\
    \ 64,                       -1) == UINT64_C(0b1000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001),\
    \ 64,                        0) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001),\
    \ 64,                        1) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000010));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001),\
    \ 64,                        2) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000100));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001),\
    \ 64,                       63) == UINT64_C(0b1000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001),\
    \ 64,                       64) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001),\
    \ 64,                       65) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000010));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001),\
    \ 64,                      127) == UINT64_C(0b1000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001),\
    \ 64,                      128) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001),\
    \ 64,      9223372036854775807) == UINT64_C(0b1000000000000000000000000000000000000000000000000000000000000000));\n\
    \n  assert_that(tools::rotate_left(UINT64_C(0b1000000000000000000000000000000000000000000000000000000000000000),\
    \ 64, -9223372036854775807 - 1) == UINT64_C(0b1000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b1000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,     -9223372036854775807) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b1000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,                     -128) == UINT64_C(0b1000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b1000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,                     -127) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b1000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,                      -65) == UINT64_C(0b0100000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b1000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,                      -64) == UINT64_C(0b1000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b1000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,                      -63) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b1000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,                       -2) == UINT64_C(0b0010000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b1000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,                       -1) == UINT64_C(0b0100000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b1000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,                        0) == UINT64_C(0b1000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b1000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,                        1) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b1000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,                        2) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000010));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b1000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,                       63) == UINT64_C(0b0100000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b1000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,                       64) == UINT64_C(0b1000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b1000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,                       65) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b1000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,                      127) == UINT64_C(0b0100000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b1000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,                      128) == UINT64_C(0b1000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b1000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,      9223372036854775807) == UINT64_C(0b0100000000000000000000000000000000000000000000000000000000000000));\n\
    \n  assert_that(tools::rotate_left(UINT64_C(0b0101010011111101111000100000100110001010011110011111001110110100),\
    \ 64, -9223372036854775807 - 1) == UINT64_C(0b0101010011111101111000100000100110001010011110011111001110110100));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b0101010011111101111000100000100110001010011110011111001110110100),\
    \ 64,     -9223372036854775807) == UINT64_C(0b1010100111111011110001000001001100010100111100111110011101101000));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b0101010011111101111000100000100110001010011110011111001110110100),\
    \ 64,                     -128) == UINT64_C(0b0101010011111101111000100000100110001010011110011111001110110100));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b0101010011111101111000100000100110001010011110011111001110110100),\
    \ 64,                     -127) == UINT64_C(0b1010100111111011110001000001001100010100111100111110011101101000));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b0101010011111101111000100000100110001010011110011111001110110100),\
    \ 64,                      -65) == UINT64_C(0b0010101001111110111100010000010011000101001111001111100111011010));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b0101010011111101111000100000100110001010011110011111001110110100),\
    \ 64,                      -64) == UINT64_C(0b0101010011111101111000100000100110001010011110011111001110110100));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b0101010011111101111000100000100110001010011110011111001110110100),\
    \ 64,                      -63) == UINT64_C(0b1010100111111011110001000001001100010100111100111110011101101000));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b0101010011111101111000100000100110001010011110011111001110110100),\
    \ 64,                       -2) == UINT64_C(0b0001010100111111011110001000001001100010100111100111110011101101));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b0101010011111101111000100000100110001010011110011111001110110100),\
    \ 64,                       -1) == UINT64_C(0b0010101001111110111100010000010011000101001111001111100111011010));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b0101010011111101111000100000100110001010011110011111001110110100),\
    \ 64,                        0) == UINT64_C(0b0101010011111101111000100000100110001010011110011111001110110100));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b0101010011111101111000100000100110001010011110011111001110110100),\
    \ 64,                        1) == UINT64_C(0b1010100111111011110001000001001100010100111100111110011101101000));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b0101010011111101111000100000100110001010011110011111001110110100),\
    \ 64,                        2) == UINT64_C(0b0101001111110111100010000010011000101001111001111100111011010001));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b0101010011111101111000100000100110001010011110011111001110110100),\
    \ 64,                       63) == UINT64_C(0b0010101001111110111100010000010011000101001111001111100111011010));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b0101010011111101111000100000100110001010011110011111001110110100),\
    \ 64,                       64) == UINT64_C(0b0101010011111101111000100000100110001010011110011111001110110100));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b0101010011111101111000100000100110001010011110011111001110110100),\
    \ 64,                       65) == UINT64_C(0b1010100111111011110001000001001100010100111100111110011101101000));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b0101010011111101111000100000100110001010011110011111001110110100),\
    \ 64,                      127) == UINT64_C(0b0010101001111110111100010000010011000101001111001111100111011010));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b0101010011111101111000100000100110001010011110011111001110110100),\
    \ 64,                      128) == UINT64_C(0b0101010011111101111000100000100110001010011110011111001110110100));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b0101010011111101111000100000100110001010011110011111001110110100),\
    \ 64,      9223372036854775807) == UINT64_C(0b0010101001111110111100010000010011000101001111001111100111011010));\n\
    \n  assert_that(tools::rotate_left(INT64_C(0b000000000000000000000000000000000000000000000000000000000000000),\
    \ 63, -9223372036854775807 - 1) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b000000000000000000000000000000000000000000000000000000000000000),\
    \ 63,     -9223372036854775807) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b000000000000000000000000000000000000000000000000000000000000000),\
    \ 63,                     -126) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b000000000000000000000000000000000000000000000000000000000000000),\
    \ 63,                     -125) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b000000000000000000000000000000000000000000000000000000000000000),\
    \ 63,                      -64) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b000000000000000000000000000000000000000000000000000000000000000),\
    \ 63,                      -63) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b000000000000000000000000000000000000000000000000000000000000000),\
    \ 63,                      -62) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b000000000000000000000000000000000000000000000000000000000000000),\
    \ 63,                       -2) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b000000000000000000000000000000000000000000000000000000000000000),\
    \ 63,                       -1) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b000000000000000000000000000000000000000000000000000000000000000),\
    \ 63,                        0) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b000000000000000000000000000000000000000000000000000000000000000),\
    \ 63,                        1) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b000000000000000000000000000000000000000000000000000000000000000),\
    \ 63,                        2) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b000000000000000000000000000000000000000000000000000000000000000),\
    \ 63,                       62) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b000000000000000000000000000000000000000000000000000000000000000),\
    \ 63,                       63) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b000000000000000000000000000000000000000000000000000000000000000),\
    \ 63,                       64) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b000000000000000000000000000000000000000000000000000000000000000),\
    \ 63,                      125) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b000000000000000000000000000000000000000000000000000000000000000),\
    \ 63,                      126) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b000000000000000000000000000000000000000000000000000000000000000),\
    \ 63,      9223372036854775807) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000000));\n\
    \n  assert_that(tools::rotate_left(INT64_C(0b000000000000000000000000000000000000000000000000000000000000001),\
    \ 63, -9223372036854775807 - 1) == INT64_C(0b000000010000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b000000000000000000000000000000000000000000000000000000000000001),\
    \ 63,     -9223372036854775807) == INT64_C(0b000000100000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b000000000000000000000000000000000000000000000000000000000000001),\
    \ 63,                     -126) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000001));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b000000000000000000000000000000000000000000000000000000000000001),\
    \ 63,                     -125) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000010));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b000000000000000000000000000000000000000000000000000000000000001),\
    \ 63,                      -64) == INT64_C(0b100000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b000000000000000000000000000000000000000000000000000000000000001),\
    \ 63,                      -63) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000001));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b000000000000000000000000000000000000000000000000000000000000001),\
    \ 63,                      -62) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000010));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b000000000000000000000000000000000000000000000000000000000000001),\
    \ 63,                       -2) == INT64_C(0b010000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b000000000000000000000000000000000000000000000000000000000000001),\
    \ 63,                       -1) == INT64_C(0b100000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b000000000000000000000000000000000000000000000000000000000000001),\
    \ 63,                        0) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000001));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b000000000000000000000000000000000000000000000000000000000000001),\
    \ 63,                        1) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000010));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b000000000000000000000000000000000000000000000000000000000000001),\
    \ 63,                        2) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000100));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b000000000000000000000000000000000000000000000000000000000000001),\
    \ 63,                       62) == INT64_C(0b100000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b000000000000000000000000000000000000000000000000000000000000001),\
    \ 63,                       63) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000001));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b000000000000000000000000000000000000000000000000000000000000001),\
    \ 63,                       64) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000010));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b000000000000000000000000000000000000000000000000000000000000001),\
    \ 63,                      125) == INT64_C(0b100000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b000000000000000000000000000000000000000000000000000000000000001),\
    \ 63,                      126) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000001));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b000000000000000000000000000000000000000000000000000000000000001),\
    \ 63,      9223372036854775807) == INT64_C(0b000000000000000000000000000000000000000000000000000000010000000));\n\
    \n  assert_that(tools::rotate_left(INT64_C(0b100000000000000000000000000000000000000000000000000000000000000),\
    \ 63, -9223372036854775807 - 1) == INT64_C(0b000000001000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b100000000000000000000000000000000000000000000000000000000000000),\
    \ 63,     -9223372036854775807) == INT64_C(0b000000010000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b100000000000000000000000000000000000000000000000000000000000000),\
    \ 63,                     -126) == INT64_C(0b100000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b100000000000000000000000000000000000000000000000000000000000000),\
    \ 63,                     -125) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000001));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b100000000000000000000000000000000000000000000000000000000000000),\
    \ 63,                      -64) == INT64_C(0b010000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b100000000000000000000000000000000000000000000000000000000000000),\
    \ 63,                      -63) == INT64_C(0b100000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b100000000000000000000000000000000000000000000000000000000000000),\
    \ 63,                      -62) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000001));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b100000000000000000000000000000000000000000000000000000000000000),\
    \ 63,                       -2) == INT64_C(0b001000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b100000000000000000000000000000000000000000000000000000000000000),\
    \ 63,                       -1) == INT64_C(0b010000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b100000000000000000000000000000000000000000000000000000000000000),\
    \ 63,                        0) == INT64_C(0b100000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b100000000000000000000000000000000000000000000000000000000000000),\
    \ 63,                        1) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000001));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b100000000000000000000000000000000000000000000000000000000000000),\
    \ 63,                        2) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000010));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b100000000000000000000000000000000000000000000000000000000000000),\
    \ 63,                       62) == INT64_C(0b010000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b100000000000000000000000000000000000000000000000000000000000000),\
    \ 63,                       63) == INT64_C(0b100000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b100000000000000000000000000000000000000000000000000000000000000),\
    \ 63,                       64) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000001));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b100000000000000000000000000000000000000000000000000000000000000),\
    \ 63,                      125) == INT64_C(0b010000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b100000000000000000000000000000000000000000000000000000000000000),\
    \ 63,                      126) == INT64_C(0b100000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b100000000000000000000000000000000000000000000000000000000000000),\
    \ 63,      9223372036854775807) == INT64_C(0b000000000000000000000000000000000000000000000000000000001000000));\n\
    \n  assert_that(tools::rotate_left(INT64_C(0b101010011111101111000100000100110001010011110011111001110110100),\
    \ 63, -9223372036854775807 - 1) == INT64_C(0b101101001010100111111011110001000001001100010100111100111110011));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b101010011111101111000100000100110001010011110011111001110110100),\
    \ 63,     -9223372036854775807) == INT64_C(0b011010010101001111110111100010000010011000101001111001111100111));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b101010011111101111000100000100110001010011110011111001110110100),\
    \ 63,                     -126) == INT64_C(0b101010011111101111000100000100110001010011110011111001110110100));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b101010011111101111000100000100110001010011110011111001110110100),\
    \ 63,                     -125) == INT64_C(0b010100111111011110001000001001100010100111100111110011101101001));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b101010011111101111000100000100110001010011110011111001110110100),\
    \ 63,                      -64) == INT64_C(0b010101001111110111100010000010011000101001111001111100111011010));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b101010011111101111000100000100110001010011110011111001110110100),\
    \ 63,                      -63) == INT64_C(0b101010011111101111000100000100110001010011110011111001110110100));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b101010011111101111000100000100110001010011110011111001110110100),\
    \ 63,                      -62) == INT64_C(0b010100111111011110001000001001100010100111100111110011101101001));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b101010011111101111000100000100110001010011110011111001110110100),\
    \ 63,                       -2) == INT64_C(0b001010100111111011110001000001001100010100111100111110011101101));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b101010011111101111000100000100110001010011110011111001110110100),\
    \ 63,                       -1) == INT64_C(0b010101001111110111100010000010011000101001111001111100111011010));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b101010011111101111000100000100110001010011110011111001110110100),\
    \ 63,                        0) == INT64_C(0b101010011111101111000100000100110001010011110011111001110110100));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b101010011111101111000100000100110001010011110011111001110110100),\
    \ 63,                        1) == INT64_C(0b010100111111011110001000001001100010100111100111110011101101001));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b101010011111101111000100000100110001010011110011111001110110100),\
    \ 63,                        2) == INT64_C(0b101001111110111100010000010011000101001111001111100111011010010));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b101010011111101111000100000100110001010011110011111001110110100),\
    \ 63,                       62) == INT64_C(0b010101001111110111100010000010011000101001111001111100111011010));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b101010011111101111000100000100110001010011110011111001110110100),\
    \ 63,                       63) == INT64_C(0b101010011111101111000100000100110001010011110011111001110110100));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b101010011111101111000100000100110001010011110011111001110110100),\
    \ 63,                       64) == INT64_C(0b010100111111011110001000001001100010100111100111110011101101001));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b101010011111101111000100000100110001010011110011111001110110100),\
    \ 63,                      125) == INT64_C(0b010101001111110111100010000010011000101001111001111100111011010));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b101010011111101111000100000100110001010011110011111001110110100),\
    \ 63,                      126) == INT64_C(0b101010011111101111000100000100110001010011110011111001110110100));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b101010011111101111000100000100110001010011110011111001110110100),\
    \ 63,      9223372036854775807) == INT64_C(0b111111011110001000001001100010100111100111110011101101001010100));\n\
    \n  assert_that(tools::rotate_left(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ), -9223372036854775807 - 1) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ),     -9223372036854775807) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ),                     -128) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ),                     -127) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ),                      -65) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ),                      -64) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ),                      -63) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ),                       -2) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ),                       -1) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ),                        0) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ),                        1) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ),                        2) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ),                       63) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ),                       64) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ),                       65) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ),                      127) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ),                      128) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ),      9223372036854775807) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n\n  assert_that(tools::rotate_left(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000001\"\
    ), -9223372036854775807 - 1) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000001\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000001\"\
    ),     -9223372036854775807) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000010\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000001\"\
    ),                     -128) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000001\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000001\"\
    ),                     -127) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000010\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000001\"\
    ),                      -65) == std::bitset<64>(\"1000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000001\"\
    ),                      -64) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000001\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000001\"\
    ),                      -63) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000010\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000001\"\
    ),                       -2) == std::bitset<64>(\"0100000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000001\"\
    ),                       -1) == std::bitset<64>(\"1000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000001\"\
    ),                        0) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000001\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000001\"\
    ),                        1) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000010\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000001\"\
    ),                        2) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000100\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000001\"\
    ),                       63) == std::bitset<64>(\"1000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000001\"\
    ),                       64) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000001\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000001\"\
    ),                       65) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000010\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000001\"\
    ),                      127) == std::bitset<64>(\"1000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000001\"\
    ),                      128) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000001\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000001\"\
    ),      9223372036854775807) == std::bitset<64>(\"1000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n\n  assert_that(tools::rotate_left(std::bitset<64>(\"1000000000000000000000000000000000000000000000000000000000000000\"\
    ), -9223372036854775807 - 1) == std::bitset<64>(\"1000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"1000000000000000000000000000000000000000000000000000000000000000\"\
    ),     -9223372036854775807) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000001\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"1000000000000000000000000000000000000000000000000000000000000000\"\
    ),                     -128) == std::bitset<64>(\"1000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"1000000000000000000000000000000000000000000000000000000000000000\"\
    ),                     -127) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000001\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"1000000000000000000000000000000000000000000000000000000000000000\"\
    ),                      -65) == std::bitset<64>(\"0100000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"1000000000000000000000000000000000000000000000000000000000000000\"\
    ),                      -64) == std::bitset<64>(\"1000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"1000000000000000000000000000000000000000000000000000000000000000\"\
    ),                      -63) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000001\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"1000000000000000000000000000000000000000000000000000000000000000\"\
    ),                       -2) == std::bitset<64>(\"0010000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"1000000000000000000000000000000000000000000000000000000000000000\"\
    ),                       -1) == std::bitset<64>(\"0100000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"1000000000000000000000000000000000000000000000000000000000000000\"\
    ),                        0) == std::bitset<64>(\"1000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"1000000000000000000000000000000000000000000000000000000000000000\"\
    ),                        1) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000001\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"1000000000000000000000000000000000000000000000000000000000000000\"\
    ),                        2) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000010\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"1000000000000000000000000000000000000000000000000000000000000000\"\
    ),                       63) == std::bitset<64>(\"0100000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"1000000000000000000000000000000000000000000000000000000000000000\"\
    ),                       64) == std::bitset<64>(\"1000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"1000000000000000000000000000000000000000000000000000000000000000\"\
    ),                       65) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000001\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"1000000000000000000000000000000000000000000000000000000000000000\"\
    ),                      127) == std::bitset<64>(\"0100000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"1000000000000000000000000000000000000000000000000000000000000000\"\
    ),                      128) == std::bitset<64>(\"1000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"1000000000000000000000000000000000000000000000000000000000000000\"\
    ),      9223372036854775807) == std::bitset<64>(\"0100000000000000000000000000000000000000000000000000000000000000\"\
    ));\n\n  assert_that(tools::rotate_left(std::bitset<64>(\"0101010011111101111000100000100110001010011110011111001110110100\"\
    ), -9223372036854775807 - 1) == std::bitset<64>(\"0101010011111101111000100000100110001010011110011111001110110100\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"0101010011111101111000100000100110001010011110011111001110110100\"\
    ),     -9223372036854775807) == std::bitset<64>(\"1010100111111011110001000001001100010100111100111110011101101000\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"0101010011111101111000100000100110001010011110011111001110110100\"\
    ),                     -128) == std::bitset<64>(\"0101010011111101111000100000100110001010011110011111001110110100\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"0101010011111101111000100000100110001010011110011111001110110100\"\
    ),                     -127) == std::bitset<64>(\"1010100111111011110001000001001100010100111100111110011101101000\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"0101010011111101111000100000100110001010011110011111001110110100\"\
    ),                      -65) == std::bitset<64>(\"0010101001111110111100010000010011000101001111001111100111011010\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"0101010011111101111000100000100110001010011110011111001110110100\"\
    ),                      -64) == std::bitset<64>(\"0101010011111101111000100000100110001010011110011111001110110100\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"0101010011111101111000100000100110001010011110011111001110110100\"\
    ),                      -63) == std::bitset<64>(\"1010100111111011110001000001001100010100111100111110011101101000\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"0101010011111101111000100000100110001010011110011111001110110100\"\
    ),                       -2) == std::bitset<64>(\"0001010100111111011110001000001001100010100111100111110011101101\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"0101010011111101111000100000100110001010011110011111001110110100\"\
    ),                       -1) == std::bitset<64>(\"0010101001111110111100010000010011000101001111001111100111011010\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"0101010011111101111000100000100110001010011110011111001110110100\"\
    ),                        0) == std::bitset<64>(\"0101010011111101111000100000100110001010011110011111001110110100\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"0101010011111101111000100000100110001010011110011111001110110100\"\
    ),                        1) == std::bitset<64>(\"1010100111111011110001000001001100010100111100111110011101101000\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"0101010011111101111000100000100110001010011110011111001110110100\"\
    ),                        2) == std::bitset<64>(\"0101001111110111100010000010011000101001111001111100111011010001\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"0101010011111101111000100000100110001010011110011111001110110100\"\
    ),                       63) == std::bitset<64>(\"0010101001111110111100010000010011000101001111001111100111011010\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"0101010011111101111000100000100110001010011110011111001110110100\"\
    ),                       64) == std::bitset<64>(\"0101010011111101111000100000100110001010011110011111001110110100\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"0101010011111101111000100000100110001010011110011111001110110100\"\
    ),                       65) == std::bitset<64>(\"1010100111111011110001000001001100010100111100111110011101101000\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"0101010011111101111000100000100110001010011110011111001110110100\"\
    ),                      127) == std::bitset<64>(\"0010101001111110111100010000010011000101001111001111100111011010\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"0101010011111101111000100000100110001010011110011111001110110100\"\
    ),                      128) == std::bitset<64>(\"0101010011111101111000100000100110001010011110011111001110110100\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"0101010011111101111000100000100110001010011110011111001110110100\"\
    ),      9223372036854775807) == std::bitset<64>(\"0010101001111110111100010000010011000101001111001111100111011010\"\
    ));\n\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ), -9223372036854775807 - 1) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ),     -9223372036854775807) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ),                     -126) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ),                     -125) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ),                      -64) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ),                      -63) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ),                      -62) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ),                       -2) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ),                       -1) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ),                        0) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ),                        1) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ),                        2) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ),                       62) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ),                       63) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ),                       64) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ),                      125) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ),                      126) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ),      9223372036854775807) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000001\"\
    ), -9223372036854775807 - 1) == tools::dynamic_bitset(\"000000010000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000001\"\
    ),     -9223372036854775807) == tools::dynamic_bitset(\"000000100000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000001\"\
    ),                     -126) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000001\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000001\"\
    ),                     -125) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000010\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000001\"\
    ),                      -64) == tools::dynamic_bitset(\"100000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000001\"\
    ),                      -63) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000001\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000001\"\
    ),                      -62) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000010\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000001\"\
    ),                       -2) == tools::dynamic_bitset(\"010000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000001\"\
    ),                       -1) == tools::dynamic_bitset(\"100000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000001\"\
    ),                        0) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000001\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000001\"\
    ),                        1) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000010\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000001\"\
    ),                        2) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000100\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000001\"\
    ),                       62) == tools::dynamic_bitset(\"100000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000001\"\
    ),                       63) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000001\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000001\"\
    ),                       64) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000010\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000001\"\
    ),                      125) == tools::dynamic_bitset(\"100000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000001\"\
    ),                      126) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000001\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000001\"\
    ),      9223372036854775807) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000010000000\"\
    ));\n\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"100000000000000000000000000000000000000000000000000000000000000\"\
    ), -9223372036854775807 - 1) == tools::dynamic_bitset(\"000000001000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"100000000000000000000000000000000000000000000000000000000000000\"\
    ),     -9223372036854775807) == tools::dynamic_bitset(\"000000010000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"100000000000000000000000000000000000000000000000000000000000000\"\
    ),                     -126) == tools::dynamic_bitset(\"100000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"100000000000000000000000000000000000000000000000000000000000000\"\
    ),                     -125) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000001\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"100000000000000000000000000000000000000000000000000000000000000\"\
    ),                      -64) == tools::dynamic_bitset(\"010000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"100000000000000000000000000000000000000000000000000000000000000\"\
    ),                      -63) == tools::dynamic_bitset(\"100000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"100000000000000000000000000000000000000000000000000000000000000\"\
    ),                      -62) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000001\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"100000000000000000000000000000000000000000000000000000000000000\"\
    ),                       -2) == tools::dynamic_bitset(\"001000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"100000000000000000000000000000000000000000000000000000000000000\"\
    ),                       -1) == tools::dynamic_bitset(\"010000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"100000000000000000000000000000000000000000000000000000000000000\"\
    ),                        0) == tools::dynamic_bitset(\"100000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"100000000000000000000000000000000000000000000000000000000000000\"\
    ),                        1) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000001\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"100000000000000000000000000000000000000000000000000000000000000\"\
    ),                        2) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000010\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"100000000000000000000000000000000000000000000000000000000000000\"\
    ),                       62) == tools::dynamic_bitset(\"010000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"100000000000000000000000000000000000000000000000000000000000000\"\
    ),                       63) == tools::dynamic_bitset(\"100000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"100000000000000000000000000000000000000000000000000000000000000\"\
    ),                       64) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000001\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"100000000000000000000000000000000000000000000000000000000000000\"\
    ),                      125) == tools::dynamic_bitset(\"010000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"100000000000000000000000000000000000000000000000000000000000000\"\
    ),                      126) == tools::dynamic_bitset(\"100000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"100000000000000000000000000000000000000000000000000000000000000\"\
    ),      9223372036854775807) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000001000000\"\
    ));\n\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"101010011111101111000100000100110001010011110011111001110110100\"\
    ), -9223372036854775807 - 1) == tools::dynamic_bitset(\"101101001010100111111011110001000001001100010100111100111110011\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"101010011111101111000100000100110001010011110011111001110110100\"\
    ),     -9223372036854775807) == tools::dynamic_bitset(\"011010010101001111110111100010000010011000101001111001111100111\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"101010011111101111000100000100110001010011110011111001110110100\"\
    ),                     -126) == tools::dynamic_bitset(\"101010011111101111000100000100110001010011110011111001110110100\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"101010011111101111000100000100110001010011110011111001110110100\"\
    ),                     -125) == tools::dynamic_bitset(\"010100111111011110001000001001100010100111100111110011101101001\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"101010011111101111000100000100110001010011110011111001110110100\"\
    ),                      -64) == tools::dynamic_bitset(\"010101001111110111100010000010011000101001111001111100111011010\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"101010011111101111000100000100110001010011110011111001110110100\"\
    ),                      -63) == tools::dynamic_bitset(\"101010011111101111000100000100110001010011110011111001110110100\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"101010011111101111000100000100110001010011110011111001110110100\"\
    ),                      -62) == tools::dynamic_bitset(\"010100111111011110001000001001100010100111100111110011101101001\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"101010011111101111000100000100110001010011110011111001110110100\"\
    ),                       -2) == tools::dynamic_bitset(\"001010100111111011110001000001001100010100111100111110011101101\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"101010011111101111000100000100110001010011110011111001110110100\"\
    ),                       -1) == tools::dynamic_bitset(\"010101001111110111100010000010011000101001111001111100111011010\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"101010011111101111000100000100110001010011110011111001110110100\"\
    ),                        0) == tools::dynamic_bitset(\"101010011111101111000100000100110001010011110011111001110110100\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"101010011111101111000100000100110001010011110011111001110110100\"\
    ),                        1) == tools::dynamic_bitset(\"010100111111011110001000001001100010100111100111110011101101001\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"101010011111101111000100000100110001010011110011111001110110100\"\
    ),                        2) == tools::dynamic_bitset(\"101001111110111100010000010011000101001111001111100111011010010\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"101010011111101111000100000100110001010011110011111001110110100\"\
    ),                       62) == tools::dynamic_bitset(\"010101001111110111100010000010011000101001111001111100111011010\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"101010011111101111000100000100110001010011110011111001110110100\"\
    ),                       63) == tools::dynamic_bitset(\"101010011111101111000100000100110001010011110011111001110110100\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"101010011111101111000100000100110001010011110011111001110110100\"\
    ),                       64) == tools::dynamic_bitset(\"010100111111011110001000001001100010100111100111110011101101001\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"101010011111101111000100000100110001010011110011111001110110100\"\
    ),                      125) == tools::dynamic_bitset(\"010101001111110111100010000010011000101001111001111100111011010\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"101010011111101111000100000100110001010011110011111001110110100\"\
    ),                      126) == tools::dynamic_bitset(\"101010011111101111000100000100110001010011110011111001110110100\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"101010011111101111000100000100110001010011110011111001110110100\"\
    ),      9223372036854775807) == tools::dynamic_bitset(\"111111011110001000001001100010100111100111110011101101001010100\"\
    ));\n\n  assert_that(tools::rotate_left(0, 0, 9223372036854775807) == 0);\n  assert_that(tools::rotate_left(0,\
    \ 1, 9223372036854775807) == 0);\n  assert_that(tools::rotate_left(1, 1, 9223372036854775807)\
    \ == 1);\n\n  std::cout << \"Hello World\" << '\\n';\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\"\n\n\
    #include <iostream>\n#include <cstdint>\n#include <bitset>\n#include \"tools/assert_that.hpp\"\
    \n#include \"tools/rotate_left.hpp\"\n#include \"tools/dynamic_bitset.hpp\"\n\n\
    int main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  assert_that(tools::rotate_left(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000),\
    \ 64, -9223372036854775807 - 1) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,     -9223372036854775807) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,                     -128) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,                     -127) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,                      -65) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,                      -64) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,                      -63) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,                       -2) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,                       -1) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,                        0) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,                        1) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,                        2) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,                       63) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,                       64) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,                       65) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,                      127) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,                      128) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,      9223372036854775807) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000));\n\
    \n  assert_that(tools::rotate_left(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001),\
    \ 64, -9223372036854775807 - 1) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001),\
    \ 64,     -9223372036854775807) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000010));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001),\
    \ 64,                     -128) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001),\
    \ 64,                     -127) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000010));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001),\
    \ 64,                      -65) == UINT64_C(0b1000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001),\
    \ 64,                      -64) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001),\
    \ 64,                      -63) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000010));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001),\
    \ 64,                       -2) == UINT64_C(0b0100000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001),\
    \ 64,                       -1) == UINT64_C(0b1000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001),\
    \ 64,                        0) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001),\
    \ 64,                        1) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000010));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001),\
    \ 64,                        2) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000100));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001),\
    \ 64,                       63) == UINT64_C(0b1000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001),\
    \ 64,                       64) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001),\
    \ 64,                       65) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000010));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001),\
    \ 64,                      127) == UINT64_C(0b1000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001),\
    \ 64,                      128) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001),\
    \ 64,      9223372036854775807) == UINT64_C(0b1000000000000000000000000000000000000000000000000000000000000000));\n\
    \n  assert_that(tools::rotate_left(UINT64_C(0b1000000000000000000000000000000000000000000000000000000000000000),\
    \ 64, -9223372036854775807 - 1) == UINT64_C(0b1000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b1000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,     -9223372036854775807) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b1000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,                     -128) == UINT64_C(0b1000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b1000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,                     -127) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b1000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,                      -65) == UINT64_C(0b0100000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b1000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,                      -64) == UINT64_C(0b1000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b1000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,                      -63) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b1000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,                       -2) == UINT64_C(0b0010000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b1000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,                       -1) == UINT64_C(0b0100000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b1000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,                        0) == UINT64_C(0b1000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b1000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,                        1) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b1000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,                        2) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000010));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b1000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,                       63) == UINT64_C(0b0100000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b1000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,                       64) == UINT64_C(0b1000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b1000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,                       65) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b1000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,                      127) == UINT64_C(0b0100000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b1000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,                      128) == UINT64_C(0b1000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b1000000000000000000000000000000000000000000000000000000000000000),\
    \ 64,      9223372036854775807) == UINT64_C(0b0100000000000000000000000000000000000000000000000000000000000000));\n\
    \n  assert_that(tools::rotate_left(UINT64_C(0b0101010011111101111000100000100110001010011110011111001110110100),\
    \ 64, -9223372036854775807 - 1) == UINT64_C(0b0101010011111101111000100000100110001010011110011111001110110100));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b0101010011111101111000100000100110001010011110011111001110110100),\
    \ 64,     -9223372036854775807) == UINT64_C(0b1010100111111011110001000001001100010100111100111110011101101000));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b0101010011111101111000100000100110001010011110011111001110110100),\
    \ 64,                     -128) == UINT64_C(0b0101010011111101111000100000100110001010011110011111001110110100));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b0101010011111101111000100000100110001010011110011111001110110100),\
    \ 64,                     -127) == UINT64_C(0b1010100111111011110001000001001100010100111100111110011101101000));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b0101010011111101111000100000100110001010011110011111001110110100),\
    \ 64,                      -65) == UINT64_C(0b0010101001111110111100010000010011000101001111001111100111011010));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b0101010011111101111000100000100110001010011110011111001110110100),\
    \ 64,                      -64) == UINT64_C(0b0101010011111101111000100000100110001010011110011111001110110100));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b0101010011111101111000100000100110001010011110011111001110110100),\
    \ 64,                      -63) == UINT64_C(0b1010100111111011110001000001001100010100111100111110011101101000));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b0101010011111101111000100000100110001010011110011111001110110100),\
    \ 64,                       -2) == UINT64_C(0b0001010100111111011110001000001001100010100111100111110011101101));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b0101010011111101111000100000100110001010011110011111001110110100),\
    \ 64,                       -1) == UINT64_C(0b0010101001111110111100010000010011000101001111001111100111011010));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b0101010011111101111000100000100110001010011110011111001110110100),\
    \ 64,                        0) == UINT64_C(0b0101010011111101111000100000100110001010011110011111001110110100));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b0101010011111101111000100000100110001010011110011111001110110100),\
    \ 64,                        1) == UINT64_C(0b1010100111111011110001000001001100010100111100111110011101101000));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b0101010011111101111000100000100110001010011110011111001110110100),\
    \ 64,                        2) == UINT64_C(0b0101001111110111100010000010011000101001111001111100111011010001));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b0101010011111101111000100000100110001010011110011111001110110100),\
    \ 64,                       63) == UINT64_C(0b0010101001111110111100010000010011000101001111001111100111011010));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b0101010011111101111000100000100110001010011110011111001110110100),\
    \ 64,                       64) == UINT64_C(0b0101010011111101111000100000100110001010011110011111001110110100));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b0101010011111101111000100000100110001010011110011111001110110100),\
    \ 64,                       65) == UINT64_C(0b1010100111111011110001000001001100010100111100111110011101101000));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b0101010011111101111000100000100110001010011110011111001110110100),\
    \ 64,                      127) == UINT64_C(0b0010101001111110111100010000010011000101001111001111100111011010));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b0101010011111101111000100000100110001010011110011111001110110100),\
    \ 64,                      128) == UINT64_C(0b0101010011111101111000100000100110001010011110011111001110110100));\n\
    \  assert_that(tools::rotate_left(UINT64_C(0b0101010011111101111000100000100110001010011110011111001110110100),\
    \ 64,      9223372036854775807) == UINT64_C(0b0010101001111110111100010000010011000101001111001111100111011010));\n\
    \n  assert_that(tools::rotate_left(INT64_C(0b000000000000000000000000000000000000000000000000000000000000000),\
    \ 63, -9223372036854775807 - 1) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b000000000000000000000000000000000000000000000000000000000000000),\
    \ 63,     -9223372036854775807) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b000000000000000000000000000000000000000000000000000000000000000),\
    \ 63,                     -126) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b000000000000000000000000000000000000000000000000000000000000000),\
    \ 63,                     -125) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b000000000000000000000000000000000000000000000000000000000000000),\
    \ 63,                      -64) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b000000000000000000000000000000000000000000000000000000000000000),\
    \ 63,                      -63) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b000000000000000000000000000000000000000000000000000000000000000),\
    \ 63,                      -62) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b000000000000000000000000000000000000000000000000000000000000000),\
    \ 63,                       -2) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b000000000000000000000000000000000000000000000000000000000000000),\
    \ 63,                       -1) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b000000000000000000000000000000000000000000000000000000000000000),\
    \ 63,                        0) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b000000000000000000000000000000000000000000000000000000000000000),\
    \ 63,                        1) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b000000000000000000000000000000000000000000000000000000000000000),\
    \ 63,                        2) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b000000000000000000000000000000000000000000000000000000000000000),\
    \ 63,                       62) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b000000000000000000000000000000000000000000000000000000000000000),\
    \ 63,                       63) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b000000000000000000000000000000000000000000000000000000000000000),\
    \ 63,                       64) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b000000000000000000000000000000000000000000000000000000000000000),\
    \ 63,                      125) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b000000000000000000000000000000000000000000000000000000000000000),\
    \ 63,                      126) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b000000000000000000000000000000000000000000000000000000000000000),\
    \ 63,      9223372036854775807) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000000));\n\
    \n  assert_that(tools::rotate_left(INT64_C(0b000000000000000000000000000000000000000000000000000000000000001),\
    \ 63, -9223372036854775807 - 1) == INT64_C(0b000000010000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b000000000000000000000000000000000000000000000000000000000000001),\
    \ 63,     -9223372036854775807) == INT64_C(0b000000100000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b000000000000000000000000000000000000000000000000000000000000001),\
    \ 63,                     -126) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000001));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b000000000000000000000000000000000000000000000000000000000000001),\
    \ 63,                     -125) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000010));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b000000000000000000000000000000000000000000000000000000000000001),\
    \ 63,                      -64) == INT64_C(0b100000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b000000000000000000000000000000000000000000000000000000000000001),\
    \ 63,                      -63) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000001));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b000000000000000000000000000000000000000000000000000000000000001),\
    \ 63,                      -62) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000010));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b000000000000000000000000000000000000000000000000000000000000001),\
    \ 63,                       -2) == INT64_C(0b010000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b000000000000000000000000000000000000000000000000000000000000001),\
    \ 63,                       -1) == INT64_C(0b100000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b000000000000000000000000000000000000000000000000000000000000001),\
    \ 63,                        0) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000001));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b000000000000000000000000000000000000000000000000000000000000001),\
    \ 63,                        1) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000010));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b000000000000000000000000000000000000000000000000000000000000001),\
    \ 63,                        2) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000100));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b000000000000000000000000000000000000000000000000000000000000001),\
    \ 63,                       62) == INT64_C(0b100000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b000000000000000000000000000000000000000000000000000000000000001),\
    \ 63,                       63) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000001));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b000000000000000000000000000000000000000000000000000000000000001),\
    \ 63,                       64) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000010));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b000000000000000000000000000000000000000000000000000000000000001),\
    \ 63,                      125) == INT64_C(0b100000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b000000000000000000000000000000000000000000000000000000000000001),\
    \ 63,                      126) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000001));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b000000000000000000000000000000000000000000000000000000000000001),\
    \ 63,      9223372036854775807) == INT64_C(0b000000000000000000000000000000000000000000000000000000010000000));\n\
    \n  assert_that(tools::rotate_left(INT64_C(0b100000000000000000000000000000000000000000000000000000000000000),\
    \ 63, -9223372036854775807 - 1) == INT64_C(0b000000001000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b100000000000000000000000000000000000000000000000000000000000000),\
    \ 63,     -9223372036854775807) == INT64_C(0b000000010000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b100000000000000000000000000000000000000000000000000000000000000),\
    \ 63,                     -126) == INT64_C(0b100000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b100000000000000000000000000000000000000000000000000000000000000),\
    \ 63,                     -125) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000001));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b100000000000000000000000000000000000000000000000000000000000000),\
    \ 63,                      -64) == INT64_C(0b010000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b100000000000000000000000000000000000000000000000000000000000000),\
    \ 63,                      -63) == INT64_C(0b100000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b100000000000000000000000000000000000000000000000000000000000000),\
    \ 63,                      -62) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000001));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b100000000000000000000000000000000000000000000000000000000000000),\
    \ 63,                       -2) == INT64_C(0b001000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b100000000000000000000000000000000000000000000000000000000000000),\
    \ 63,                       -1) == INT64_C(0b010000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b100000000000000000000000000000000000000000000000000000000000000),\
    \ 63,                        0) == INT64_C(0b100000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b100000000000000000000000000000000000000000000000000000000000000),\
    \ 63,                        1) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000001));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b100000000000000000000000000000000000000000000000000000000000000),\
    \ 63,                        2) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000010));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b100000000000000000000000000000000000000000000000000000000000000),\
    \ 63,                       62) == INT64_C(0b010000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b100000000000000000000000000000000000000000000000000000000000000),\
    \ 63,                       63) == INT64_C(0b100000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b100000000000000000000000000000000000000000000000000000000000000),\
    \ 63,                       64) == INT64_C(0b000000000000000000000000000000000000000000000000000000000000001));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b100000000000000000000000000000000000000000000000000000000000000),\
    \ 63,                      125) == INT64_C(0b010000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b100000000000000000000000000000000000000000000000000000000000000),\
    \ 63,                      126) == INT64_C(0b100000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b100000000000000000000000000000000000000000000000000000000000000),\
    \ 63,      9223372036854775807) == INT64_C(0b000000000000000000000000000000000000000000000000000000001000000));\n\
    \n  assert_that(tools::rotate_left(INT64_C(0b101010011111101111000100000100110001010011110011111001110110100),\
    \ 63, -9223372036854775807 - 1) == INT64_C(0b101101001010100111111011110001000001001100010100111100111110011));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b101010011111101111000100000100110001010011110011111001110110100),\
    \ 63,     -9223372036854775807) == INT64_C(0b011010010101001111110111100010000010011000101001111001111100111));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b101010011111101111000100000100110001010011110011111001110110100),\
    \ 63,                     -126) == INT64_C(0b101010011111101111000100000100110001010011110011111001110110100));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b101010011111101111000100000100110001010011110011111001110110100),\
    \ 63,                     -125) == INT64_C(0b010100111111011110001000001001100010100111100111110011101101001));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b101010011111101111000100000100110001010011110011111001110110100),\
    \ 63,                      -64) == INT64_C(0b010101001111110111100010000010011000101001111001111100111011010));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b101010011111101111000100000100110001010011110011111001110110100),\
    \ 63,                      -63) == INT64_C(0b101010011111101111000100000100110001010011110011111001110110100));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b101010011111101111000100000100110001010011110011111001110110100),\
    \ 63,                      -62) == INT64_C(0b010100111111011110001000001001100010100111100111110011101101001));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b101010011111101111000100000100110001010011110011111001110110100),\
    \ 63,                       -2) == INT64_C(0b001010100111111011110001000001001100010100111100111110011101101));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b101010011111101111000100000100110001010011110011111001110110100),\
    \ 63,                       -1) == INT64_C(0b010101001111110111100010000010011000101001111001111100111011010));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b101010011111101111000100000100110001010011110011111001110110100),\
    \ 63,                        0) == INT64_C(0b101010011111101111000100000100110001010011110011111001110110100));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b101010011111101111000100000100110001010011110011111001110110100),\
    \ 63,                        1) == INT64_C(0b010100111111011110001000001001100010100111100111110011101101001));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b101010011111101111000100000100110001010011110011111001110110100),\
    \ 63,                        2) == INT64_C(0b101001111110111100010000010011000101001111001111100111011010010));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b101010011111101111000100000100110001010011110011111001110110100),\
    \ 63,                       62) == INT64_C(0b010101001111110111100010000010011000101001111001111100111011010));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b101010011111101111000100000100110001010011110011111001110110100),\
    \ 63,                       63) == INT64_C(0b101010011111101111000100000100110001010011110011111001110110100));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b101010011111101111000100000100110001010011110011111001110110100),\
    \ 63,                       64) == INT64_C(0b010100111111011110001000001001100010100111100111110011101101001));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b101010011111101111000100000100110001010011110011111001110110100),\
    \ 63,                      125) == INT64_C(0b010101001111110111100010000010011000101001111001111100111011010));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b101010011111101111000100000100110001010011110011111001110110100),\
    \ 63,                      126) == INT64_C(0b101010011111101111000100000100110001010011110011111001110110100));\n\
    \  assert_that(tools::rotate_left(INT64_C(0b101010011111101111000100000100110001010011110011111001110110100),\
    \ 63,      9223372036854775807) == INT64_C(0b111111011110001000001001100010100111100111110011101101001010100));\n\
    \n  assert_that(tools::rotate_left(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ), -9223372036854775807 - 1) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ),     -9223372036854775807) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ),                     -128) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ),                     -127) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ),                      -65) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ),                      -64) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ),                      -63) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ),                       -2) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ),                       -1) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ),                        0) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ),                        1) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ),                        2) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ),                       63) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ),                       64) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ),                       65) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ),                      127) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ),                      128) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ),      9223372036854775807) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n\n  assert_that(tools::rotate_left(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000001\"\
    ), -9223372036854775807 - 1) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000001\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000001\"\
    ),     -9223372036854775807) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000010\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000001\"\
    ),                     -128) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000001\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000001\"\
    ),                     -127) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000010\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000001\"\
    ),                      -65) == std::bitset<64>(\"1000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000001\"\
    ),                      -64) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000001\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000001\"\
    ),                      -63) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000010\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000001\"\
    ),                       -2) == std::bitset<64>(\"0100000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000001\"\
    ),                       -1) == std::bitset<64>(\"1000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000001\"\
    ),                        0) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000001\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000001\"\
    ),                        1) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000010\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000001\"\
    ),                        2) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000100\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000001\"\
    ),                       63) == std::bitset<64>(\"1000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000001\"\
    ),                       64) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000001\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000001\"\
    ),                       65) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000010\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000001\"\
    ),                      127) == std::bitset<64>(\"1000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000001\"\
    ),                      128) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000001\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000001\"\
    ),      9223372036854775807) == std::bitset<64>(\"1000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n\n  assert_that(tools::rotate_left(std::bitset<64>(\"1000000000000000000000000000000000000000000000000000000000000000\"\
    ), -9223372036854775807 - 1) == std::bitset<64>(\"1000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"1000000000000000000000000000000000000000000000000000000000000000\"\
    ),     -9223372036854775807) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000001\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"1000000000000000000000000000000000000000000000000000000000000000\"\
    ),                     -128) == std::bitset<64>(\"1000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"1000000000000000000000000000000000000000000000000000000000000000\"\
    ),                     -127) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000001\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"1000000000000000000000000000000000000000000000000000000000000000\"\
    ),                      -65) == std::bitset<64>(\"0100000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"1000000000000000000000000000000000000000000000000000000000000000\"\
    ),                      -64) == std::bitset<64>(\"1000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"1000000000000000000000000000000000000000000000000000000000000000\"\
    ),                      -63) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000001\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"1000000000000000000000000000000000000000000000000000000000000000\"\
    ),                       -2) == std::bitset<64>(\"0010000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"1000000000000000000000000000000000000000000000000000000000000000\"\
    ),                       -1) == std::bitset<64>(\"0100000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"1000000000000000000000000000000000000000000000000000000000000000\"\
    ),                        0) == std::bitset<64>(\"1000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"1000000000000000000000000000000000000000000000000000000000000000\"\
    ),                        1) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000001\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"1000000000000000000000000000000000000000000000000000000000000000\"\
    ),                        2) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000010\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"1000000000000000000000000000000000000000000000000000000000000000\"\
    ),                       63) == std::bitset<64>(\"0100000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"1000000000000000000000000000000000000000000000000000000000000000\"\
    ),                       64) == std::bitset<64>(\"1000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"1000000000000000000000000000000000000000000000000000000000000000\"\
    ),                       65) == std::bitset<64>(\"0000000000000000000000000000000000000000000000000000000000000001\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"1000000000000000000000000000000000000000000000000000000000000000\"\
    ),                      127) == std::bitset<64>(\"0100000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"1000000000000000000000000000000000000000000000000000000000000000\"\
    ),                      128) == std::bitset<64>(\"1000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"1000000000000000000000000000000000000000000000000000000000000000\"\
    ),      9223372036854775807) == std::bitset<64>(\"0100000000000000000000000000000000000000000000000000000000000000\"\
    ));\n\n  assert_that(tools::rotate_left(std::bitset<64>(\"0101010011111101111000100000100110001010011110011111001110110100\"\
    ), -9223372036854775807 - 1) == std::bitset<64>(\"0101010011111101111000100000100110001010011110011111001110110100\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"0101010011111101111000100000100110001010011110011111001110110100\"\
    ),     -9223372036854775807) == std::bitset<64>(\"1010100111111011110001000001001100010100111100111110011101101000\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"0101010011111101111000100000100110001010011110011111001110110100\"\
    ),                     -128) == std::bitset<64>(\"0101010011111101111000100000100110001010011110011111001110110100\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"0101010011111101111000100000100110001010011110011111001110110100\"\
    ),                     -127) == std::bitset<64>(\"1010100111111011110001000001001100010100111100111110011101101000\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"0101010011111101111000100000100110001010011110011111001110110100\"\
    ),                      -65) == std::bitset<64>(\"0010101001111110111100010000010011000101001111001111100111011010\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"0101010011111101111000100000100110001010011110011111001110110100\"\
    ),                      -64) == std::bitset<64>(\"0101010011111101111000100000100110001010011110011111001110110100\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"0101010011111101111000100000100110001010011110011111001110110100\"\
    ),                      -63) == std::bitset<64>(\"1010100111111011110001000001001100010100111100111110011101101000\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"0101010011111101111000100000100110001010011110011111001110110100\"\
    ),                       -2) == std::bitset<64>(\"0001010100111111011110001000001001100010100111100111110011101101\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"0101010011111101111000100000100110001010011110011111001110110100\"\
    ),                       -1) == std::bitset<64>(\"0010101001111110111100010000010011000101001111001111100111011010\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"0101010011111101111000100000100110001010011110011111001110110100\"\
    ),                        0) == std::bitset<64>(\"0101010011111101111000100000100110001010011110011111001110110100\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"0101010011111101111000100000100110001010011110011111001110110100\"\
    ),                        1) == std::bitset<64>(\"1010100111111011110001000001001100010100111100111110011101101000\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"0101010011111101111000100000100110001010011110011111001110110100\"\
    ),                        2) == std::bitset<64>(\"0101001111110111100010000010011000101001111001111100111011010001\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"0101010011111101111000100000100110001010011110011111001110110100\"\
    ),                       63) == std::bitset<64>(\"0010101001111110111100010000010011000101001111001111100111011010\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"0101010011111101111000100000100110001010011110011111001110110100\"\
    ),                       64) == std::bitset<64>(\"0101010011111101111000100000100110001010011110011111001110110100\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"0101010011111101111000100000100110001010011110011111001110110100\"\
    ),                       65) == std::bitset<64>(\"1010100111111011110001000001001100010100111100111110011101101000\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"0101010011111101111000100000100110001010011110011111001110110100\"\
    ),                      127) == std::bitset<64>(\"0010101001111110111100010000010011000101001111001111100111011010\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"0101010011111101111000100000100110001010011110011111001110110100\"\
    ),                      128) == std::bitset<64>(\"0101010011111101111000100000100110001010011110011111001110110100\"\
    ));\n  assert_that(tools::rotate_left(std::bitset<64>(\"0101010011111101111000100000100110001010011110011111001110110100\"\
    ),      9223372036854775807) == std::bitset<64>(\"0010101001111110111100010000010011000101001111001111100111011010\"\
    ));\n\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ), -9223372036854775807 - 1) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ),     -9223372036854775807) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ),                     -126) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ),                     -125) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ),                      -64) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ),                      -63) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ),                      -62) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ),                       -2) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ),                       -1) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ),                        0) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ),                        1) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ),                        2) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ),                       62) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ),                       63) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ),                       64) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ),                      125) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ),                      126) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ),      9223372036854775807) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000000\"\
    ));\n\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000001\"\
    ), -9223372036854775807 - 1) == tools::dynamic_bitset(\"000000010000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000001\"\
    ),     -9223372036854775807) == tools::dynamic_bitset(\"000000100000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000001\"\
    ),                     -126) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000001\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000001\"\
    ),                     -125) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000010\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000001\"\
    ),                      -64) == tools::dynamic_bitset(\"100000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000001\"\
    ),                      -63) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000001\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000001\"\
    ),                      -62) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000010\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000001\"\
    ),                       -2) == tools::dynamic_bitset(\"010000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000001\"\
    ),                       -1) == tools::dynamic_bitset(\"100000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000001\"\
    ),                        0) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000001\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000001\"\
    ),                        1) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000010\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000001\"\
    ),                        2) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000100\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000001\"\
    ),                       62) == tools::dynamic_bitset(\"100000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000001\"\
    ),                       63) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000001\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000001\"\
    ),                       64) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000010\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000001\"\
    ),                      125) == tools::dynamic_bitset(\"100000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000001\"\
    ),                      126) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000001\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000001\"\
    ),      9223372036854775807) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000010000000\"\
    ));\n\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"100000000000000000000000000000000000000000000000000000000000000\"\
    ), -9223372036854775807 - 1) == tools::dynamic_bitset(\"000000001000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"100000000000000000000000000000000000000000000000000000000000000\"\
    ),     -9223372036854775807) == tools::dynamic_bitset(\"000000010000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"100000000000000000000000000000000000000000000000000000000000000\"\
    ),                     -126) == tools::dynamic_bitset(\"100000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"100000000000000000000000000000000000000000000000000000000000000\"\
    ),                     -125) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000001\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"100000000000000000000000000000000000000000000000000000000000000\"\
    ),                      -64) == tools::dynamic_bitset(\"010000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"100000000000000000000000000000000000000000000000000000000000000\"\
    ),                      -63) == tools::dynamic_bitset(\"100000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"100000000000000000000000000000000000000000000000000000000000000\"\
    ),                      -62) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000001\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"100000000000000000000000000000000000000000000000000000000000000\"\
    ),                       -2) == tools::dynamic_bitset(\"001000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"100000000000000000000000000000000000000000000000000000000000000\"\
    ),                       -1) == tools::dynamic_bitset(\"010000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"100000000000000000000000000000000000000000000000000000000000000\"\
    ),                        0) == tools::dynamic_bitset(\"100000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"100000000000000000000000000000000000000000000000000000000000000\"\
    ),                        1) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000001\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"100000000000000000000000000000000000000000000000000000000000000\"\
    ),                        2) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000010\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"100000000000000000000000000000000000000000000000000000000000000\"\
    ),                       62) == tools::dynamic_bitset(\"010000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"100000000000000000000000000000000000000000000000000000000000000\"\
    ),                       63) == tools::dynamic_bitset(\"100000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"100000000000000000000000000000000000000000000000000000000000000\"\
    ),                       64) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000000000001\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"100000000000000000000000000000000000000000000000000000000000000\"\
    ),                      125) == tools::dynamic_bitset(\"010000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"100000000000000000000000000000000000000000000000000000000000000\"\
    ),                      126) == tools::dynamic_bitset(\"100000000000000000000000000000000000000000000000000000000000000\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"100000000000000000000000000000000000000000000000000000000000000\"\
    ),      9223372036854775807) == tools::dynamic_bitset(\"000000000000000000000000000000000000000000000000000000001000000\"\
    ));\n\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"101010011111101111000100000100110001010011110011111001110110100\"\
    ), -9223372036854775807 - 1) == tools::dynamic_bitset(\"101101001010100111111011110001000001001100010100111100111110011\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"101010011111101111000100000100110001010011110011111001110110100\"\
    ),     -9223372036854775807) == tools::dynamic_bitset(\"011010010101001111110111100010000010011000101001111001111100111\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"101010011111101111000100000100110001010011110011111001110110100\"\
    ),                     -126) == tools::dynamic_bitset(\"101010011111101111000100000100110001010011110011111001110110100\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"101010011111101111000100000100110001010011110011111001110110100\"\
    ),                     -125) == tools::dynamic_bitset(\"010100111111011110001000001001100010100111100111110011101101001\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"101010011111101111000100000100110001010011110011111001110110100\"\
    ),                      -64) == tools::dynamic_bitset(\"010101001111110111100010000010011000101001111001111100111011010\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"101010011111101111000100000100110001010011110011111001110110100\"\
    ),                      -63) == tools::dynamic_bitset(\"101010011111101111000100000100110001010011110011111001110110100\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"101010011111101111000100000100110001010011110011111001110110100\"\
    ),                      -62) == tools::dynamic_bitset(\"010100111111011110001000001001100010100111100111110011101101001\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"101010011111101111000100000100110001010011110011111001110110100\"\
    ),                       -2) == tools::dynamic_bitset(\"001010100111111011110001000001001100010100111100111110011101101\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"101010011111101111000100000100110001010011110011111001110110100\"\
    ),                       -1) == tools::dynamic_bitset(\"010101001111110111100010000010011000101001111001111100111011010\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"101010011111101111000100000100110001010011110011111001110110100\"\
    ),                        0) == tools::dynamic_bitset(\"101010011111101111000100000100110001010011110011111001110110100\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"101010011111101111000100000100110001010011110011111001110110100\"\
    ),                        1) == tools::dynamic_bitset(\"010100111111011110001000001001100010100111100111110011101101001\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"101010011111101111000100000100110001010011110011111001110110100\"\
    ),                        2) == tools::dynamic_bitset(\"101001111110111100010000010011000101001111001111100111011010010\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"101010011111101111000100000100110001010011110011111001110110100\"\
    ),                       62) == tools::dynamic_bitset(\"010101001111110111100010000010011000101001111001111100111011010\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"101010011111101111000100000100110001010011110011111001110110100\"\
    ),                       63) == tools::dynamic_bitset(\"101010011111101111000100000100110001010011110011111001110110100\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"101010011111101111000100000100110001010011110011111001110110100\"\
    ),                       64) == tools::dynamic_bitset(\"010100111111011110001000001001100010100111100111110011101101001\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"101010011111101111000100000100110001010011110011111001110110100\"\
    ),                      125) == tools::dynamic_bitset(\"010101001111110111100010000010011000101001111001111100111011010\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"101010011111101111000100000100110001010011110011111001110110100\"\
    ),                      126) == tools::dynamic_bitset(\"101010011111101111000100000100110001010011110011111001110110100\"\
    ));\n  assert_that(tools::rotate_left(tools::dynamic_bitset(\"101010011111101111000100000100110001010011110011111001110110100\"\
    ),      9223372036854775807) == tools::dynamic_bitset(\"111111011110001000001001100010100111100111110011101101001010100\"\
    ));\n\n  assert_that(tools::rotate_left(0, 0, 9223372036854775807) == 0);\n  assert_that(tools::rotate_left(0,\
    \ 1, 9223372036854775807) == 0);\n  assert_that(tools::rotate_left(1, 1, 9223372036854775807)\
    \ == 1);\n\n  std::cout << \"Hello World\" << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - tools/assert_that.hpp
  - tools/rotate_left.hpp
  - tools/mod.hpp
  - tools/quo.hpp
  - tools/dynamic_bitset.hpp
  - tools/ceil.hpp
  - tools/popcount.hpp
  - tools/countr_zero.hpp
  isVerificationFile: true
  path: tests/rotate_left.test.cpp
  requiredBy: []
  timestamp: '2024-10-19 09:52:21+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/rotate_left.test.cpp
layout: document
redirect_from:
- /verify/tests/rotate_left.test.cpp
- /verify/tests/rotate_left.test.cpp.html
title: tests/rotate_left.test.cpp
---
