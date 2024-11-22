---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/assert_that.hpp
    title: Assertion macro
  - icon: ':heavy_check_mark:'
    path: tools/floor_log2.hpp
    title: $\left\lfloor \log_2(x) \right\rfloor$
  - icon: ':heavy_check_mark:'
    path: tools/popcount.hpp
    title: Popcount
  - icon: ':heavy_check_mark:'
    path: tools/reverse.hpp
    title: Bit reverse
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
  bundledCode: "#line 1 \"tests/reverse.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\"\
    \n\n#include <iostream>\n#include <cstdint>\n#line 1 \"tools/assert_that.hpp\"\
    \n\n\n\n#line 5 \"tools/assert_that.hpp\"\n#include <cstdlib>\n\n#define assert_that_impl(cond,\
    \ file, line, func) do {\\\n  if (!cond) {\\\n    ::std::cerr << file << ':' <<\
    \ line << \": \" << func << \": Assertion `\" << #cond << \"' failed.\" << '\\\
    n';\\\n    ::std::exit(EXIT_FAILURE);\\\n  }\\\n} while (false)\n#define assert_that(...)\
    \ assert_that_impl((__VA_ARGS__), __FILE__, __LINE__, __func__)\n\n\n#line 1 \"\
    tools/reverse.hpp\"\n\n\n\n#include <type_traits>\n#include <limits>\n#include\
    \ <cstddef>\n#include <cassert>\n#line 1 \"tools/floor_log2.hpp\"\n\n\n\n#line\
    \ 1 \"tools/popcount.hpp\"\n\n\n\n#line 8 \"tools/popcount.hpp\"\n\nnamespace\
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
    \ 10 \"tools/reverse.hpp\"\n\nnamespace tools {\n  template <typename T>\n  ::std::enable_if_t<::std::is_integral_v<T>\
    \ && !::std::is_signed_v<T> && ::std::numeric_limits<T>::digits == 1, T> reverse(const\
    \ T x, const ::std::size_t n) {\n    assert(n <= ::std::numeric_limits<T>::digits);\n\
    \    assert(!x || n == 1);\n    return x;\n  }\n  template <typename T>\n  ::std::enable_if_t<::std::is_integral_v<T>\
    \ && !::std::is_signed_v<T> && ::std::numeric_limits<T>::digits == 8, T> reverse(T\
    \ x, const ::std::size_t n) {\n    assert(n <= ::std::numeric_limits<T>::digits);\n\
    \    assert(x == 0 || ::tools::floor_log2(x) < n);\n    x = ((x & UINT8_C(0x55))\
    \ << 1) | ((x & UINT8_C(0xAA)) >> 1);\n    x = ((x & UINT8_C(0x33)) << 2) | ((x\
    \ & UINT8_C(0xCC)) >> 2);\n    x = ((x & UINT8_C(0x0F)) << 4) | ((x & UINT8_C(0xF0))\
    \ >> 4);\n    x >>= (::std::numeric_limits<T>::digits - n) & (::std::numeric_limits<T>::digits\
    \ - 1);\n    return x;\n  }\n  template <typename T>\n  ::std::enable_if_t<::std::is_integral_v<T>\
    \ && !::std::is_signed_v<T> && ::std::numeric_limits<T>::digits == 16, T> reverse(T\
    \ x, const ::std::size_t n) {\n    assert(n <= ::std::numeric_limits<T>::digits);\n\
    \    assert(x == 0 || ::tools::floor_log2(x) < n);\n    x = ((x & UINT16_C(0x5555))\
    \ << 1) | ((x & UINT16_C(0xAAAA)) >> 1);\n    x = ((x & UINT16_C(0x3333)) << 2)\
    \ | ((x & UINT16_C(0xCCCC)) >> 2);\n    x = ((x & UINT16_C(0x0F0F)) << 4) | ((x\
    \ & UINT16_C(0xF0F0)) >> 4);\n    x = ((x & UINT16_C(0x00FF)) << 8) | ((x & UINT16_C(0xFF00))\
    \ >> 8);\n    x >>= (::std::numeric_limits<T>::digits - n) & (::std::numeric_limits<T>::digits\
    \ - 1);\n    return x;\n  }\n  template <typename T>\n  ::std::enable_if_t<::std::is_integral_v<T>\
    \ && !::std::is_signed_v<T> && ::std::numeric_limits<T>::digits == 32, T> reverse(T\
    \ x, const ::std::size_t n) {\n    assert(n <= ::std::numeric_limits<T>::digits);\n\
    \    assert(x == 0 || ::tools::floor_log2(x) < n);\n    x = ((x & UINT32_C(0x55555555))\
    \ << 1) | ((x & UINT32_C(0xAAAAAAAA)) >> 1);\n    x = ((x & UINT32_C(0x33333333))\
    \ << 2) | ((x & UINT32_C(0xCCCCCCCC)) >> 2);\n    x = ((x & UINT32_C(0x0F0F0F0F))\
    \ << 4) | ((x & UINT32_C(0xF0F0F0F0)) >> 4);\n    x = ((x & UINT32_C(0x00FF00FF))\
    \ << 8) | ((x & UINT32_C(0xFF00FF00)) >> 8);\n    x = ((x & UINT32_C(0x0000FFFF))\
    \ << 16) | ((x & UINT32_C(0xFFFF0000)) >> 16);\n    x >>= (::std::numeric_limits<T>::digits\
    \ - n) & (::std::numeric_limits<T>::digits - 1);\n    return x;\n  }\n  template\
    \ <typename T>\n  ::std::enable_if_t<::std::is_integral_v<T> && !::std::is_signed_v<T>\
    \ && ::std::numeric_limits<T>::digits == 64, T> reverse(T x, const ::std::size_t\
    \ n) {\n    assert(n <= ::std::numeric_limits<T>::digits);\n    assert(x == 0\
    \ || ::tools::floor_log2(x) < n);\n    x = ((x & UINT64_C(0x5555555555555555))\
    \ << 1) | ((x & UINT64_C(0xAAAAAAAAAAAAAAAA)) >> 1);\n    x = ((x & UINT64_C(0x3333333333333333))\
    \ << 2) | ((x & UINT64_C(0xCCCCCCCCCCCCCCCC)) >> 2);\n    x = ((x & UINT64_C(0x0F0F0F0F0F0F0F0F))\
    \ << 4) | ((x & UINT64_C(0xF0F0F0F0F0F0F0F0)) >> 4);\n    x = ((x & UINT64_C(0x00FF00FF00FF00FF))\
    \ << 8) | ((x & UINT64_C(0xFF00FF00FF00FF00)) >> 8);\n    x = ((x & UINT64_C(0x0000FFFF0000FFFF))\
    \ << 16) | ((x & UINT64_C(0xFFFF0000FFFF0000)) >> 16);\n    x = ((x & UINT64_C(0x00000000FFFFFFFF))\
    \ << 32) | ((x & UINT64_C(0xFFFFFFFF00000000)) >> 32);\n    x >>= (::std::numeric_limits<T>::digits\
    \ - n) & (::std::numeric_limits<T>::digits - 1);\n    return x;\n  }\n  template\
    \ <typename T>\n  ::std::enable_if_t<::std::is_integral_v<T> && ::std::is_signed_v<T>,\
    \ T> reverse(const T x, const ::std::size_t n) {\n    assert(x >= 0);\n    return\
    \ ::tools::reverse(static_cast<::std::make_unsigned_t<T>>(x), n);\n  }\n}\n\n\n\
    #line 7 \"tests/reverse.test.cpp\"\n\nint main() {\n  std::cin.tie(nullptr);\n\
    \  std::ios_base::sync_with_stdio(false);\n\n  assert_that(tools::reverse(false,\
    \ 0) == false);\n  assert_that(tools::reverse(false, 1) == false);\n  assert_that(tools::reverse(true,\
    \ 1) == true);\n\n  assert_that(tools::reverse(INT8_C(0b00000000), 0) == INT8_C(0b00000000));\n\
    \  assert_that(tools::reverse(INT8_C(0b00000000), 1) == INT8_C(0b00000000));\n\
    \  assert_that(tools::reverse(INT8_C(0b00000001), 1) == INT8_C(0b00000001));\n\
    \  assert_that(tools::reverse(INT8_C(0b00000000), 2) == INT8_C(0b00000000));\n\
    \  assert_that(tools::reverse(INT8_C(0b00000001), 2) == INT8_C(0b00000010));\n\
    \  assert_that(tools::reverse(INT8_C(0b00000010), 2) == INT8_C(0b00000001));\n\
    \  assert_that(tools::reverse(INT8_C(0b00000011), 2) == INT8_C(0b00000011));\n\
    \  assert_that(tools::reverse(INT8_C(0b00000000), 5) == INT8_C(0b00000000));\n\
    \  assert_that(tools::reverse(INT8_C(0b00001100), 5) == INT8_C(0b00000110));\n\
    \  assert_that(tools::reverse(INT8_C(0b00011111), 5) == INT8_C(0b00011111));\n\
    \  assert_that(tools::reverse(INT8_C(0b00000000), 6) == INT8_C(0b00000000));\n\
    \  assert_that(tools::reverse(INT8_C(0b00101100), 6) == INT8_C(0b00001101));\n\
    \  assert_that(tools::reverse(INT8_C(0b00111111), 6) == INT8_C(0b00111111));\n\
    \  assert_that(tools::reverse(INT8_C(0b00000000), 7) == INT8_C(0b00000000));\n\
    \  assert_that(tools::reverse(INT8_C(0b00101100), 7) == INT8_C(0b00011010));\n\
    \  assert_that(tools::reverse(INT8_C(0b01111111), 7) == INT8_C(0b01111111));\n\
    \n  assert_that(tools::reverse(UINT8_C(0b00000000), 0) == UINT8_C(0b00000000));\n\
    \  assert_that(tools::reverse(UINT8_C(0b00000000), 1) == UINT8_C(0b00000000));\n\
    \  assert_that(tools::reverse(UINT8_C(0b00000001), 1) == UINT8_C(0b00000001));\n\
    \  assert_that(tools::reverse(UINT8_C(0b00000000), 2) == UINT8_C(0b00000000));\n\
    \  assert_that(tools::reverse(UINT8_C(0b00000001), 2) == UINT8_C(0b00000010));\n\
    \  assert_that(tools::reverse(UINT8_C(0b00000010), 2) == UINT8_C(0b00000001));\n\
    \  assert_that(tools::reverse(UINT8_C(0b00000011), 2) == UINT8_C(0b00000011));\n\
    \  assert_that(tools::reverse(UINT8_C(0b00000000), 5) == UINT8_C(0b00000000));\n\
    \  assert_that(tools::reverse(UINT8_C(0b00001100), 5) == UINT8_C(0b00000110));\n\
    \  assert_that(tools::reverse(UINT8_C(0b00011111), 5) == UINT8_C(0b00011111));\n\
    \  assert_that(tools::reverse(UINT8_C(0b00000000), 7) == UINT8_C(0b00000000));\n\
    \  assert_that(tools::reverse(UINT8_C(0b00101100), 7) == UINT8_C(0b00011010));\n\
    \  assert_that(tools::reverse(UINT8_C(0b01111111), 7) == UINT8_C(0b01111111));\n\
    \  assert_that(tools::reverse(UINT8_C(0b00000000), 8) == UINT8_C(0b00000000));\n\
    \  assert_that(tools::reverse(UINT8_C(0b10101100), 8) == UINT8_C(0b00110101));\n\
    \  assert_that(tools::reverse(UINT8_C(0b11111111), 8) == UINT8_C(0b11111111));\n\
    \n  assert_that(tools::reverse(INT16_C(0b0000000000000000), 0) == INT16_C(0b0000000000000000));\n\
    \  assert_that(tools::reverse(INT16_C(0b0000000000000000), 1) == INT16_C(0b0000000000000000));\n\
    \  assert_that(tools::reverse(INT16_C(0b0000000000000001), 1) == INT16_C(0b0000000000000001));\n\
    \  assert_that(tools::reverse(INT16_C(0b0000000000000000), 2) == INT16_C(0b0000000000000000));\n\
    \  assert_that(tools::reverse(INT16_C(0b0000000000000001), 2) == INT16_C(0b0000000000000010));\n\
    \  assert_that(tools::reverse(INT16_C(0b0000000000000010), 2) == INT16_C(0b0000000000000001));\n\
    \  assert_that(tools::reverse(INT16_C(0b0000000000000011), 2) == INT16_C(0b0000000000000011));\n\
    \  assert_that(tools::reverse(INT16_C(0b0000000000000000), 9) == INT16_C(0b0000000000000000));\n\
    \  assert_that(tools::reverse(INT16_C(0b0000000010101100), 9) == INT16_C(0b0000000001101010));\n\
    \  assert_that(tools::reverse(INT16_C(0b0000000111111111), 9) == INT16_C(0b0000000111111111));\n\
    \  assert_that(tools::reverse(INT16_C(0b0000000000000000), 14) == INT16_C(0b0000000000000000));\n\
    \  assert_that(tools::reverse(INT16_C(0b0010100010101100), 14) == INT16_C(0b0000110101000101));\n\
    \  assert_that(tools::reverse(INT16_C(0b0011111111111111), 14) == INT16_C(0b0011111111111111));\n\
    \  assert_that(tools::reverse(INT16_C(0b0000000000000000), 15) == INT16_C(0b0000000000000000));\n\
    \  assert_that(tools::reverse(INT16_C(0b0010100010101100), 15) == INT16_C(0b0001101010001010));\n\
    \  assert_that(tools::reverse(INT16_C(0b0111111111111111), 15) == INT16_C(0b0111111111111111));\n\
    \n  assert_that(tools::reverse(UINT16_C(0b0000000000000000), 0) == UINT16_C(0b0000000000000000));\n\
    \  assert_that(tools::reverse(UINT16_C(0b0000000000000000), 1) == UINT16_C(0b0000000000000000));\n\
    \  assert_that(tools::reverse(UINT16_C(0b0000000000000001), 1) == UINT16_C(0b0000000000000001));\n\
    \  assert_that(tools::reverse(UINT16_C(0b0000000000000000), 2) == UINT16_C(0b0000000000000000));\n\
    \  assert_that(tools::reverse(UINT16_C(0b0000000000000001), 2) == UINT16_C(0b0000000000000010));\n\
    \  assert_that(tools::reverse(UINT16_C(0b0000000000000010), 2) == UINT16_C(0b0000000000000001));\n\
    \  assert_that(tools::reverse(UINT16_C(0b0000000000000011), 2) == UINT16_C(0b0000000000000011));\n\
    \  assert_that(tools::reverse(UINT16_C(0b0000000000000000), 9) == UINT16_C(0b0000000000000000));\n\
    \  assert_that(tools::reverse(UINT16_C(0b0000000010101100), 9) == UINT16_C(0b0000000001101010));\n\
    \  assert_that(tools::reverse(UINT16_C(0b0000000111111111), 9) == UINT16_C(0b0000000111111111));\n\
    \  assert_that(tools::reverse(UINT16_C(0b0000000000000000), 15) == UINT16_C(0b0000000000000000));\n\
    \  assert_that(tools::reverse(UINT16_C(0b0010100010101100), 15) == UINT16_C(0b0001101010001010));\n\
    \  assert_that(tools::reverse(UINT16_C(0b0111111111111111), 15) == UINT16_C(0b0111111111111111));\n\
    \  assert_that(tools::reverse(UINT16_C(0b0000000000000000), 16) == UINT16_C(0b0000000000000000));\n\
    \  assert_that(tools::reverse(UINT16_C(0b0010100010101100), 16) == UINT16_C(0b0011010100010100));\n\
    \  assert_that(tools::reverse(UINT16_C(0b1111111111111111), 16) == UINT16_C(0b1111111111111111));\n\
    \n  assert_that(tools::reverse(INT32_C(0b00000000000000000000000000000000), 0)\
    \ == INT32_C(0b00000000000000000000000000000000));\n  assert_that(tools::reverse(INT32_C(0b00000000000000000000000000000000),\
    \ 1) == INT32_C(0b00000000000000000000000000000000));\n  assert_that(tools::reverse(INT32_C(0b00000000000000000000000000000001),\
    \ 1) == INT32_C(0b00000000000000000000000000000001));\n  assert_that(tools::reverse(INT32_C(0b00000000000000000000000000000000),\
    \ 2) == INT32_C(0b00000000000000000000000000000000));\n  assert_that(tools::reverse(INT32_C(0b00000000000000000000000000000001),\
    \ 2) == INT32_C(0b00000000000000000000000000000010));\n  assert_that(tools::reverse(INT32_C(0b00000000000000000000000000000010),\
    \ 2) == INT32_C(0b00000000000000000000000000000001));\n  assert_that(tools::reverse(INT32_C(0b00000000000000000000000000000011),\
    \ 2) == INT32_C(0b00000000000000000000000000000011));\n  assert_that(tools::reverse(INT32_C(0b00000000000000000000000000000000),\
    \ 17) == INT32_C(0b00000000000000000000000000000000));\n  assert_that(tools::reverse(INT32_C(0b00000000000000000010100010101100),\
    \ 17) == INT32_C(0b00000000000000000110101000101000));\n  assert_that(tools::reverse(INT32_C(0b00000000000000011111111111111111),\
    \ 17) == INT32_C(0b00000000000000011111111111111111));\n  assert_that(tools::reverse(INT32_C(0b00000000000000000000000000000000),\
    \ 30) == INT32_C(0b00000000000000000000000000000000));\n  assert_that(tools::reverse(INT32_C(0b00100000100010100010100010101100),\
    \ 30) == INT32_C(0b00001101010001010001010001000001));\n  assert_that(tools::reverse(INT32_C(0b00111111111111111111111111111111),\
    \ 30) == INT32_C(0b00111111111111111111111111111111));\n  assert_that(tools::reverse(INT32_C(0b00000000000000000000000000000000),\
    \ 31) == INT32_C(0b00000000000000000000000000000000));\n  assert_that(tools::reverse(INT32_C(0b00100000100010100010100010101100),\
    \ 31) == INT32_C(0b00011010100010100010100010000010));\n  assert_that(tools::reverse(INT32_C(0b01111111111111111111111111111111),\
    \ 31) == INT32_C(0b01111111111111111111111111111111));\n\n  assert_that(tools::reverse(UINT32_C(0b00000000000000000000000000000000),\
    \ 0) == UINT32_C(0b00000000000000000000000000000000));\n  assert_that(tools::reverse(UINT32_C(0b00000000000000000000000000000000),\
    \ 1) == UINT32_C(0b00000000000000000000000000000000));\n  assert_that(tools::reverse(UINT32_C(0b00000000000000000000000000000001),\
    \ 1) == UINT32_C(0b00000000000000000000000000000001));\n  assert_that(tools::reverse(UINT32_C(0b00000000000000000000000000000000),\
    \ 2) == UINT32_C(0b00000000000000000000000000000000));\n  assert_that(tools::reverse(UINT32_C(0b00000000000000000000000000000001),\
    \ 2) == UINT32_C(0b00000000000000000000000000000010));\n  assert_that(tools::reverse(UINT32_C(0b00000000000000000000000000000010),\
    \ 2) == UINT32_C(0b00000000000000000000000000000001));\n  assert_that(tools::reverse(UINT32_C(0b00000000000000000000000000000011),\
    \ 2) == UINT32_C(0b00000000000000000000000000000011));\n  assert_that(tools::reverse(UINT32_C(0b00000000000000000000000000000000),\
    \ 17) == UINT32_C(0b00000000000000000000000000000000));\n  assert_that(tools::reverse(UINT32_C(0b00000000000000000010100010101100),\
    \ 17) == UINT32_C(0b00000000000000000110101000101000));\n  assert_that(tools::reverse(UINT32_C(0b00000000000000011111111111111111),\
    \ 17) == UINT32_C(0b00000000000000011111111111111111));\n  assert_that(tools::reverse(UINT32_C(0b00000000000000000000000000000000),\
    \ 31) == UINT32_C(0b00000000000000000000000000000000));\n  assert_that(tools::reverse(UINT32_C(0b00100000100010100010100010101100),\
    \ 31) == UINT32_C(0b00011010100010100010100010000010));\n  assert_that(tools::reverse(UINT32_C(0b01111111111111111111111111111111),\
    \ 31) == UINT32_C(0b01111111111111111111111111111111));\n  assert_that(tools::reverse(UINT32_C(0b00000000000000000000000000000000),\
    \ 32) == UINT32_C(0b00000000000000000000000000000000));\n  assert_that(tools::reverse(UINT32_C(0b10100000100010100010100010101100),\
    \ 32) == UINT32_C(0b00110101000101000101000100000101));\n  assert_that(tools::reverse(UINT32_C(0b11111111111111111111111111111111),\
    \ 32) == UINT32_C(0b11111111111111111111111111111111));\n\n  assert_that(tools::reverse(INT64_C(0b0000000000000000000000000000000000000000000000000000000000000000),\
    \ 0) == INT64_C(0b0000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::reverse(INT64_C(0b0000000000000000000000000000000000000000000000000000000000000000),\
    \ 1) == INT64_C(0b0000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::reverse(INT64_C(0b0000000000000000000000000000000000000000000000000000000000000001),\
    \ 1) == INT64_C(0b0000000000000000000000000000000000000000000000000000000000000001));\n\
    \  assert_that(tools::reverse(INT64_C(0b0000000000000000000000000000000000000000000000000000000000000000),\
    \ 2) == INT64_C(0b0000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::reverse(INT64_C(0b0000000000000000000000000000000000000000000000000000000000000001),\
    \ 2) == INT64_C(0b0000000000000000000000000000000000000000000000000000000000000010));\n\
    \  assert_that(tools::reverse(INT64_C(0b0000000000000000000000000000000000000000000000000000000000000010),\
    \ 2) == INT64_C(0b0000000000000000000000000000000000000000000000000000000000000001));\n\
    \  assert_that(tools::reverse(INT64_C(0b0000000000000000000000000000000000000000000000000000000000000011),\
    \ 2) == INT64_C(0b0000000000000000000000000000000000000000000000000000000000000011));\n\
    \  assert_that(tools::reverse(INT64_C(0b0000000000000000000000000000000000000000000000000000000000000000),\
    \ 33) == INT64_C(0b0000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::reverse(INT64_C(0b0000000000000000000000000000000010100000100010100010100010101100),\
    \ 33) == INT64_C(0b0000000000000000000000000000000001101010001010001010001000001010));\n\
    \  assert_that(tools::reverse(INT64_C(0b0000000000000000000000000000000111111111111111111111111111111111),\
    \ 33) == INT64_C(0b0000000000000000000000000000000111111111111111111111111111111111));\n\
    \  assert_that(tools::reverse(INT64_C(0b0000000000000000000000000000000000000000000000000000000000000000),\
    \ 62) == INT64_C(0b0000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::reverse(INT64_C(0b0010100000100000100010100010000010100000100010100010100010101100),\
    \ 62) == INT64_C(0b0000110101000101000101000100000101000001000101000100000100000101));\n\
    \  assert_that(tools::reverse(INT64_C(0b0011111111111111111111111111111111111111111111111111111111111111),\
    \ 62) == INT64_C(0b0011111111111111111111111111111111111111111111111111111111111111));\n\
    \  assert_that(tools::reverse(INT64_C(0b0000000000000000000000000000000000000000000000000000000000000000),\
    \ 63) == INT64_C(0b0000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::reverse(INT64_C(0b0010100000100000100010100010000010100000100010100010100010101100),\
    \ 63) == INT64_C(0b0001101010001010001010001000001010000010001010001000001000001010));\n\
    \  assert_that(tools::reverse(INT64_C(0b0111111111111111111111111111111111111111111111111111111111111111),\
    \ 63) == INT64_C(0b0111111111111111111111111111111111111111111111111111111111111111));\n\
    \n  assert_that(tools::reverse(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000),\
    \ 0) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::reverse(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000),\
    \ 1) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::reverse(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001),\
    \ 1) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001));\n\
    \  assert_that(tools::reverse(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000),\
    \ 2) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::reverse(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001),\
    \ 2) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000010));\n\
    \  assert_that(tools::reverse(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000010),\
    \ 2) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001));\n\
    \  assert_that(tools::reverse(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000011),\
    \ 2) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000011));\n\
    \  assert_that(tools::reverse(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000),\
    \ 33) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::reverse(UINT64_C(0b0000000000000000000000000000000010100000100010100010100010101100),\
    \ 33) == UINT64_C(0b0000000000000000000000000000000001101010001010001010001000001010));\n\
    \  assert_that(tools::reverse(UINT64_C(0b0000000000000000000000000000000111111111111111111111111111111111),\
    \ 33) == UINT64_C(0b0000000000000000000000000000000111111111111111111111111111111111));\n\
    \  assert_that(tools::reverse(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000),\
    \ 63) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::reverse(UINT64_C(0b0010100000100000100010100010000010100000100010100010100010101100),\
    \ 63) == UINT64_C(0b0001101010001010001010001000001010000010001010001000001000001010));\n\
    \  assert_that(tools::reverse(UINT64_C(0b0111111111111111111111111111111111111111111111111111111111111111),\
    \ 63) == UINT64_C(0b0111111111111111111111111111111111111111111111111111111111111111));\n\
    \  assert_that(tools::reverse(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000),\
    \ 64) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::reverse(UINT64_C(0b0010100000100000100010100010000010100000100010100010100010101100),\
    \ 64) == UINT64_C(0b0011010100010100010100010000010100000100010100010000010000010100));\n\
    \  assert_that(tools::reverse(UINT64_C(0b1111111111111111111111111111111111111111111111111111111111111111),\
    \ 64) == UINT64_C(0b1111111111111111111111111111111111111111111111111111111111111111));\n\
    \n  assert_that(tools::reverse(0b0000000000000000000000000000000000000000000000000000000000000000LL,\
    \ 0) == 0b0000000000000000000000000000000000000000000000000000000000000000LL);\n\
    \  assert_that(tools::reverse(0b0000000000000000000000000000000000000000000000000000000000000000LL,\
    \ 1) == 0b0000000000000000000000000000000000000000000000000000000000000000LL);\n\
    \  assert_that(tools::reverse(0b0000000000000000000000000000000000000000000000000000000000000001LL,\
    \ 1) == 0b0000000000000000000000000000000000000000000000000000000000000001LL);\n\
    \  assert_that(tools::reverse(0b0000000000000000000000000000000000000000000000000000000000000000LL,\
    \ 2) == 0b0000000000000000000000000000000000000000000000000000000000000000LL);\n\
    \  assert_that(tools::reverse(0b0000000000000000000000000000000000000000000000000000000000000001LL,\
    \ 2) == 0b0000000000000000000000000000000000000000000000000000000000000010LL);\n\
    \  assert_that(tools::reverse(0b0000000000000000000000000000000000000000000000000000000000000010LL,\
    \ 2) == 0b0000000000000000000000000000000000000000000000000000000000000001LL);\n\
    \  assert_that(tools::reverse(0b0000000000000000000000000000000000000000000000000000000000000011LL,\
    \ 2) == 0b0000000000000000000000000000000000000000000000000000000000000011LL);\n\
    \  assert_that(tools::reverse(0b0000000000000000000000000000000000000000000000000000000000000000LL,\
    \ 33) == 0b0000000000000000000000000000000000000000000000000000000000000000LL);\n\
    \  assert_that(tools::reverse(0b0000000000000000000000000000000010100000100010100010100010101100LL,\
    \ 33) == 0b0000000000000000000000000000000001101010001010001010001000001010LL);\n\
    \  assert_that(tools::reverse(0b0000000000000000000000000000000111111111111111111111111111111111LL,\
    \ 33) == 0b0000000000000000000000000000000111111111111111111111111111111111LL);\n\
    \  assert_that(tools::reverse(0b0000000000000000000000000000000000000000000000000000000000000000LL,\
    \ 62) == 0b0000000000000000000000000000000000000000000000000000000000000000LL);\n\
    \  assert_that(tools::reverse(0b0010100000100000100010100010000010100000100010100010100010101100LL,\
    \ 62) == 0b0000110101000101000101000100000101000001000101000100000100000101LL);\n\
    \  assert_that(tools::reverse(0b0011111111111111111111111111111111111111111111111111111111111111LL,\
    \ 62) == 0b0011111111111111111111111111111111111111111111111111111111111111LL);\n\
    \  assert_that(tools::reverse(0b0000000000000000000000000000000000000000000000000000000000000000LL,\
    \ 63) == 0b0000000000000000000000000000000000000000000000000000000000000000LL);\n\
    \  assert_that(tools::reverse(0b0010100000100000100010100010000010100000100010100010100010101100LL,\
    \ 63) == 0b0001101010001010001010001000001010000010001010001000001000001010LL);\n\
    \  assert_that(tools::reverse(0b0111111111111111111111111111111111111111111111111111111111111111LL,\
    \ 63) == 0b0111111111111111111111111111111111111111111111111111111111111111LL);\n\
    \n  std::cout << \"Hello World\" << '\\n';\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\"\n\n\
    #include <iostream>\n#include <cstdint>\n#include \"tools/assert_that.hpp\"\n\
    #include \"tools/reverse.hpp\"\n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  assert_that(tools::reverse(false, 0) == false);\n  assert_that(tools::reverse(false,\
    \ 1) == false);\n  assert_that(tools::reverse(true, 1) == true);\n\n  assert_that(tools::reverse(INT8_C(0b00000000),\
    \ 0) == INT8_C(0b00000000));\n  assert_that(tools::reverse(INT8_C(0b00000000),\
    \ 1) == INT8_C(0b00000000));\n  assert_that(tools::reverse(INT8_C(0b00000001),\
    \ 1) == INT8_C(0b00000001));\n  assert_that(tools::reverse(INT8_C(0b00000000),\
    \ 2) == INT8_C(0b00000000));\n  assert_that(tools::reverse(INT8_C(0b00000001),\
    \ 2) == INT8_C(0b00000010));\n  assert_that(tools::reverse(INT8_C(0b00000010),\
    \ 2) == INT8_C(0b00000001));\n  assert_that(tools::reverse(INT8_C(0b00000011),\
    \ 2) == INT8_C(0b00000011));\n  assert_that(tools::reverse(INT8_C(0b00000000),\
    \ 5) == INT8_C(0b00000000));\n  assert_that(tools::reverse(INT8_C(0b00001100),\
    \ 5) == INT8_C(0b00000110));\n  assert_that(tools::reverse(INT8_C(0b00011111),\
    \ 5) == INT8_C(0b00011111));\n  assert_that(tools::reverse(INT8_C(0b00000000),\
    \ 6) == INT8_C(0b00000000));\n  assert_that(tools::reverse(INT8_C(0b00101100),\
    \ 6) == INT8_C(0b00001101));\n  assert_that(tools::reverse(INT8_C(0b00111111),\
    \ 6) == INT8_C(0b00111111));\n  assert_that(tools::reverse(INT8_C(0b00000000),\
    \ 7) == INT8_C(0b00000000));\n  assert_that(tools::reverse(INT8_C(0b00101100),\
    \ 7) == INT8_C(0b00011010));\n  assert_that(tools::reverse(INT8_C(0b01111111),\
    \ 7) == INT8_C(0b01111111));\n\n  assert_that(tools::reverse(UINT8_C(0b00000000),\
    \ 0) == UINT8_C(0b00000000));\n  assert_that(tools::reverse(UINT8_C(0b00000000),\
    \ 1) == UINT8_C(0b00000000));\n  assert_that(tools::reverse(UINT8_C(0b00000001),\
    \ 1) == UINT8_C(0b00000001));\n  assert_that(tools::reverse(UINT8_C(0b00000000),\
    \ 2) == UINT8_C(0b00000000));\n  assert_that(tools::reverse(UINT8_C(0b00000001),\
    \ 2) == UINT8_C(0b00000010));\n  assert_that(tools::reverse(UINT8_C(0b00000010),\
    \ 2) == UINT8_C(0b00000001));\n  assert_that(tools::reverse(UINT8_C(0b00000011),\
    \ 2) == UINT8_C(0b00000011));\n  assert_that(tools::reverse(UINT8_C(0b00000000),\
    \ 5) == UINT8_C(0b00000000));\n  assert_that(tools::reverse(UINT8_C(0b00001100),\
    \ 5) == UINT8_C(0b00000110));\n  assert_that(tools::reverse(UINT8_C(0b00011111),\
    \ 5) == UINT8_C(0b00011111));\n  assert_that(tools::reverse(UINT8_C(0b00000000),\
    \ 7) == UINT8_C(0b00000000));\n  assert_that(tools::reverse(UINT8_C(0b00101100),\
    \ 7) == UINT8_C(0b00011010));\n  assert_that(tools::reverse(UINT8_C(0b01111111),\
    \ 7) == UINT8_C(0b01111111));\n  assert_that(tools::reverse(UINT8_C(0b00000000),\
    \ 8) == UINT8_C(0b00000000));\n  assert_that(tools::reverse(UINT8_C(0b10101100),\
    \ 8) == UINT8_C(0b00110101));\n  assert_that(tools::reverse(UINT8_C(0b11111111),\
    \ 8) == UINT8_C(0b11111111));\n\n  assert_that(tools::reverse(INT16_C(0b0000000000000000),\
    \ 0) == INT16_C(0b0000000000000000));\n  assert_that(tools::reverse(INT16_C(0b0000000000000000),\
    \ 1) == INT16_C(0b0000000000000000));\n  assert_that(tools::reverse(INT16_C(0b0000000000000001),\
    \ 1) == INT16_C(0b0000000000000001));\n  assert_that(tools::reverse(INT16_C(0b0000000000000000),\
    \ 2) == INT16_C(0b0000000000000000));\n  assert_that(tools::reverse(INT16_C(0b0000000000000001),\
    \ 2) == INT16_C(0b0000000000000010));\n  assert_that(tools::reverse(INT16_C(0b0000000000000010),\
    \ 2) == INT16_C(0b0000000000000001));\n  assert_that(tools::reverse(INT16_C(0b0000000000000011),\
    \ 2) == INT16_C(0b0000000000000011));\n  assert_that(tools::reverse(INT16_C(0b0000000000000000),\
    \ 9) == INT16_C(0b0000000000000000));\n  assert_that(tools::reverse(INT16_C(0b0000000010101100),\
    \ 9) == INT16_C(0b0000000001101010));\n  assert_that(tools::reverse(INT16_C(0b0000000111111111),\
    \ 9) == INT16_C(0b0000000111111111));\n  assert_that(tools::reverse(INT16_C(0b0000000000000000),\
    \ 14) == INT16_C(0b0000000000000000));\n  assert_that(tools::reverse(INT16_C(0b0010100010101100),\
    \ 14) == INT16_C(0b0000110101000101));\n  assert_that(tools::reverse(INT16_C(0b0011111111111111),\
    \ 14) == INT16_C(0b0011111111111111));\n  assert_that(tools::reverse(INT16_C(0b0000000000000000),\
    \ 15) == INT16_C(0b0000000000000000));\n  assert_that(tools::reverse(INT16_C(0b0010100010101100),\
    \ 15) == INT16_C(0b0001101010001010));\n  assert_that(tools::reverse(INT16_C(0b0111111111111111),\
    \ 15) == INT16_C(0b0111111111111111));\n\n  assert_that(tools::reverse(UINT16_C(0b0000000000000000),\
    \ 0) == UINT16_C(0b0000000000000000));\n  assert_that(tools::reverse(UINT16_C(0b0000000000000000),\
    \ 1) == UINT16_C(0b0000000000000000));\n  assert_that(tools::reverse(UINT16_C(0b0000000000000001),\
    \ 1) == UINT16_C(0b0000000000000001));\n  assert_that(tools::reverse(UINT16_C(0b0000000000000000),\
    \ 2) == UINT16_C(0b0000000000000000));\n  assert_that(tools::reverse(UINT16_C(0b0000000000000001),\
    \ 2) == UINT16_C(0b0000000000000010));\n  assert_that(tools::reverse(UINT16_C(0b0000000000000010),\
    \ 2) == UINT16_C(0b0000000000000001));\n  assert_that(tools::reverse(UINT16_C(0b0000000000000011),\
    \ 2) == UINT16_C(0b0000000000000011));\n  assert_that(tools::reverse(UINT16_C(0b0000000000000000),\
    \ 9) == UINT16_C(0b0000000000000000));\n  assert_that(tools::reverse(UINT16_C(0b0000000010101100),\
    \ 9) == UINT16_C(0b0000000001101010));\n  assert_that(tools::reverse(UINT16_C(0b0000000111111111),\
    \ 9) == UINT16_C(0b0000000111111111));\n  assert_that(tools::reverse(UINT16_C(0b0000000000000000),\
    \ 15) == UINT16_C(0b0000000000000000));\n  assert_that(tools::reverse(UINT16_C(0b0010100010101100),\
    \ 15) == UINT16_C(0b0001101010001010));\n  assert_that(tools::reverse(UINT16_C(0b0111111111111111),\
    \ 15) == UINT16_C(0b0111111111111111));\n  assert_that(tools::reverse(UINT16_C(0b0000000000000000),\
    \ 16) == UINT16_C(0b0000000000000000));\n  assert_that(tools::reverse(UINT16_C(0b0010100010101100),\
    \ 16) == UINT16_C(0b0011010100010100));\n  assert_that(tools::reverse(UINT16_C(0b1111111111111111),\
    \ 16) == UINT16_C(0b1111111111111111));\n\n  assert_that(tools::reverse(INT32_C(0b00000000000000000000000000000000),\
    \ 0) == INT32_C(0b00000000000000000000000000000000));\n  assert_that(tools::reverse(INT32_C(0b00000000000000000000000000000000),\
    \ 1) == INT32_C(0b00000000000000000000000000000000));\n  assert_that(tools::reverse(INT32_C(0b00000000000000000000000000000001),\
    \ 1) == INT32_C(0b00000000000000000000000000000001));\n  assert_that(tools::reverse(INT32_C(0b00000000000000000000000000000000),\
    \ 2) == INT32_C(0b00000000000000000000000000000000));\n  assert_that(tools::reverse(INT32_C(0b00000000000000000000000000000001),\
    \ 2) == INT32_C(0b00000000000000000000000000000010));\n  assert_that(tools::reverse(INT32_C(0b00000000000000000000000000000010),\
    \ 2) == INT32_C(0b00000000000000000000000000000001));\n  assert_that(tools::reverse(INT32_C(0b00000000000000000000000000000011),\
    \ 2) == INT32_C(0b00000000000000000000000000000011));\n  assert_that(tools::reverse(INT32_C(0b00000000000000000000000000000000),\
    \ 17) == INT32_C(0b00000000000000000000000000000000));\n  assert_that(tools::reverse(INT32_C(0b00000000000000000010100010101100),\
    \ 17) == INT32_C(0b00000000000000000110101000101000));\n  assert_that(tools::reverse(INT32_C(0b00000000000000011111111111111111),\
    \ 17) == INT32_C(0b00000000000000011111111111111111));\n  assert_that(tools::reverse(INT32_C(0b00000000000000000000000000000000),\
    \ 30) == INT32_C(0b00000000000000000000000000000000));\n  assert_that(tools::reverse(INT32_C(0b00100000100010100010100010101100),\
    \ 30) == INT32_C(0b00001101010001010001010001000001));\n  assert_that(tools::reverse(INT32_C(0b00111111111111111111111111111111),\
    \ 30) == INT32_C(0b00111111111111111111111111111111));\n  assert_that(tools::reverse(INT32_C(0b00000000000000000000000000000000),\
    \ 31) == INT32_C(0b00000000000000000000000000000000));\n  assert_that(tools::reverse(INT32_C(0b00100000100010100010100010101100),\
    \ 31) == INT32_C(0b00011010100010100010100010000010));\n  assert_that(tools::reverse(INT32_C(0b01111111111111111111111111111111),\
    \ 31) == INT32_C(0b01111111111111111111111111111111));\n\n  assert_that(tools::reverse(UINT32_C(0b00000000000000000000000000000000),\
    \ 0) == UINT32_C(0b00000000000000000000000000000000));\n  assert_that(tools::reverse(UINT32_C(0b00000000000000000000000000000000),\
    \ 1) == UINT32_C(0b00000000000000000000000000000000));\n  assert_that(tools::reverse(UINT32_C(0b00000000000000000000000000000001),\
    \ 1) == UINT32_C(0b00000000000000000000000000000001));\n  assert_that(tools::reverse(UINT32_C(0b00000000000000000000000000000000),\
    \ 2) == UINT32_C(0b00000000000000000000000000000000));\n  assert_that(tools::reverse(UINT32_C(0b00000000000000000000000000000001),\
    \ 2) == UINT32_C(0b00000000000000000000000000000010));\n  assert_that(tools::reverse(UINT32_C(0b00000000000000000000000000000010),\
    \ 2) == UINT32_C(0b00000000000000000000000000000001));\n  assert_that(tools::reverse(UINT32_C(0b00000000000000000000000000000011),\
    \ 2) == UINT32_C(0b00000000000000000000000000000011));\n  assert_that(tools::reverse(UINT32_C(0b00000000000000000000000000000000),\
    \ 17) == UINT32_C(0b00000000000000000000000000000000));\n  assert_that(tools::reverse(UINT32_C(0b00000000000000000010100010101100),\
    \ 17) == UINT32_C(0b00000000000000000110101000101000));\n  assert_that(tools::reverse(UINT32_C(0b00000000000000011111111111111111),\
    \ 17) == UINT32_C(0b00000000000000011111111111111111));\n  assert_that(tools::reverse(UINT32_C(0b00000000000000000000000000000000),\
    \ 31) == UINT32_C(0b00000000000000000000000000000000));\n  assert_that(tools::reverse(UINT32_C(0b00100000100010100010100010101100),\
    \ 31) == UINT32_C(0b00011010100010100010100010000010));\n  assert_that(tools::reverse(UINT32_C(0b01111111111111111111111111111111),\
    \ 31) == UINT32_C(0b01111111111111111111111111111111));\n  assert_that(tools::reverse(UINT32_C(0b00000000000000000000000000000000),\
    \ 32) == UINT32_C(0b00000000000000000000000000000000));\n  assert_that(tools::reverse(UINT32_C(0b10100000100010100010100010101100),\
    \ 32) == UINT32_C(0b00110101000101000101000100000101));\n  assert_that(tools::reverse(UINT32_C(0b11111111111111111111111111111111),\
    \ 32) == UINT32_C(0b11111111111111111111111111111111));\n\n  assert_that(tools::reverse(INT64_C(0b0000000000000000000000000000000000000000000000000000000000000000),\
    \ 0) == INT64_C(0b0000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::reverse(INT64_C(0b0000000000000000000000000000000000000000000000000000000000000000),\
    \ 1) == INT64_C(0b0000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::reverse(INT64_C(0b0000000000000000000000000000000000000000000000000000000000000001),\
    \ 1) == INT64_C(0b0000000000000000000000000000000000000000000000000000000000000001));\n\
    \  assert_that(tools::reverse(INT64_C(0b0000000000000000000000000000000000000000000000000000000000000000),\
    \ 2) == INT64_C(0b0000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::reverse(INT64_C(0b0000000000000000000000000000000000000000000000000000000000000001),\
    \ 2) == INT64_C(0b0000000000000000000000000000000000000000000000000000000000000010));\n\
    \  assert_that(tools::reverse(INT64_C(0b0000000000000000000000000000000000000000000000000000000000000010),\
    \ 2) == INT64_C(0b0000000000000000000000000000000000000000000000000000000000000001));\n\
    \  assert_that(tools::reverse(INT64_C(0b0000000000000000000000000000000000000000000000000000000000000011),\
    \ 2) == INT64_C(0b0000000000000000000000000000000000000000000000000000000000000011));\n\
    \  assert_that(tools::reverse(INT64_C(0b0000000000000000000000000000000000000000000000000000000000000000),\
    \ 33) == INT64_C(0b0000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::reverse(INT64_C(0b0000000000000000000000000000000010100000100010100010100010101100),\
    \ 33) == INT64_C(0b0000000000000000000000000000000001101010001010001010001000001010));\n\
    \  assert_that(tools::reverse(INT64_C(0b0000000000000000000000000000000111111111111111111111111111111111),\
    \ 33) == INT64_C(0b0000000000000000000000000000000111111111111111111111111111111111));\n\
    \  assert_that(tools::reverse(INT64_C(0b0000000000000000000000000000000000000000000000000000000000000000),\
    \ 62) == INT64_C(0b0000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::reverse(INT64_C(0b0010100000100000100010100010000010100000100010100010100010101100),\
    \ 62) == INT64_C(0b0000110101000101000101000100000101000001000101000100000100000101));\n\
    \  assert_that(tools::reverse(INT64_C(0b0011111111111111111111111111111111111111111111111111111111111111),\
    \ 62) == INT64_C(0b0011111111111111111111111111111111111111111111111111111111111111));\n\
    \  assert_that(tools::reverse(INT64_C(0b0000000000000000000000000000000000000000000000000000000000000000),\
    \ 63) == INT64_C(0b0000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::reverse(INT64_C(0b0010100000100000100010100010000010100000100010100010100010101100),\
    \ 63) == INT64_C(0b0001101010001010001010001000001010000010001010001000001000001010));\n\
    \  assert_that(tools::reverse(INT64_C(0b0111111111111111111111111111111111111111111111111111111111111111),\
    \ 63) == INT64_C(0b0111111111111111111111111111111111111111111111111111111111111111));\n\
    \n  assert_that(tools::reverse(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000),\
    \ 0) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::reverse(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000),\
    \ 1) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::reverse(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001),\
    \ 1) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001));\n\
    \  assert_that(tools::reverse(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000),\
    \ 2) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::reverse(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001),\
    \ 2) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000010));\n\
    \  assert_that(tools::reverse(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000010),\
    \ 2) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000001));\n\
    \  assert_that(tools::reverse(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000011),\
    \ 2) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000011));\n\
    \  assert_that(tools::reverse(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000),\
    \ 33) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::reverse(UINT64_C(0b0000000000000000000000000000000010100000100010100010100010101100),\
    \ 33) == UINT64_C(0b0000000000000000000000000000000001101010001010001010001000001010));\n\
    \  assert_that(tools::reverse(UINT64_C(0b0000000000000000000000000000000111111111111111111111111111111111),\
    \ 33) == UINT64_C(0b0000000000000000000000000000000111111111111111111111111111111111));\n\
    \  assert_that(tools::reverse(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000),\
    \ 63) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::reverse(UINT64_C(0b0010100000100000100010100010000010100000100010100010100010101100),\
    \ 63) == UINT64_C(0b0001101010001010001010001000001010000010001010001000001000001010));\n\
    \  assert_that(tools::reverse(UINT64_C(0b0111111111111111111111111111111111111111111111111111111111111111),\
    \ 63) == UINT64_C(0b0111111111111111111111111111111111111111111111111111111111111111));\n\
    \  assert_that(tools::reverse(UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000),\
    \ 64) == UINT64_C(0b0000000000000000000000000000000000000000000000000000000000000000));\n\
    \  assert_that(tools::reverse(UINT64_C(0b0010100000100000100010100010000010100000100010100010100010101100),\
    \ 64) == UINT64_C(0b0011010100010100010100010000010100000100010100010000010000010100));\n\
    \  assert_that(tools::reverse(UINT64_C(0b1111111111111111111111111111111111111111111111111111111111111111),\
    \ 64) == UINT64_C(0b1111111111111111111111111111111111111111111111111111111111111111));\n\
    \n  assert_that(tools::reverse(0b0000000000000000000000000000000000000000000000000000000000000000LL,\
    \ 0) == 0b0000000000000000000000000000000000000000000000000000000000000000LL);\n\
    \  assert_that(tools::reverse(0b0000000000000000000000000000000000000000000000000000000000000000LL,\
    \ 1) == 0b0000000000000000000000000000000000000000000000000000000000000000LL);\n\
    \  assert_that(tools::reverse(0b0000000000000000000000000000000000000000000000000000000000000001LL,\
    \ 1) == 0b0000000000000000000000000000000000000000000000000000000000000001LL);\n\
    \  assert_that(tools::reverse(0b0000000000000000000000000000000000000000000000000000000000000000LL,\
    \ 2) == 0b0000000000000000000000000000000000000000000000000000000000000000LL);\n\
    \  assert_that(tools::reverse(0b0000000000000000000000000000000000000000000000000000000000000001LL,\
    \ 2) == 0b0000000000000000000000000000000000000000000000000000000000000010LL);\n\
    \  assert_that(tools::reverse(0b0000000000000000000000000000000000000000000000000000000000000010LL,\
    \ 2) == 0b0000000000000000000000000000000000000000000000000000000000000001LL);\n\
    \  assert_that(tools::reverse(0b0000000000000000000000000000000000000000000000000000000000000011LL,\
    \ 2) == 0b0000000000000000000000000000000000000000000000000000000000000011LL);\n\
    \  assert_that(tools::reverse(0b0000000000000000000000000000000000000000000000000000000000000000LL,\
    \ 33) == 0b0000000000000000000000000000000000000000000000000000000000000000LL);\n\
    \  assert_that(tools::reverse(0b0000000000000000000000000000000010100000100010100010100010101100LL,\
    \ 33) == 0b0000000000000000000000000000000001101010001010001010001000001010LL);\n\
    \  assert_that(tools::reverse(0b0000000000000000000000000000000111111111111111111111111111111111LL,\
    \ 33) == 0b0000000000000000000000000000000111111111111111111111111111111111LL);\n\
    \  assert_that(tools::reverse(0b0000000000000000000000000000000000000000000000000000000000000000LL,\
    \ 62) == 0b0000000000000000000000000000000000000000000000000000000000000000LL);\n\
    \  assert_that(tools::reverse(0b0010100000100000100010100010000010100000100010100010100010101100LL,\
    \ 62) == 0b0000110101000101000101000100000101000001000101000100000100000101LL);\n\
    \  assert_that(tools::reverse(0b0011111111111111111111111111111111111111111111111111111111111111LL,\
    \ 62) == 0b0011111111111111111111111111111111111111111111111111111111111111LL);\n\
    \  assert_that(tools::reverse(0b0000000000000000000000000000000000000000000000000000000000000000LL,\
    \ 63) == 0b0000000000000000000000000000000000000000000000000000000000000000LL);\n\
    \  assert_that(tools::reverse(0b0010100000100000100010100010000010100000100010100010100010101100LL,\
    \ 63) == 0b0001101010001010001010001000001010000010001010001000001000001010LL);\n\
    \  assert_that(tools::reverse(0b0111111111111111111111111111111111111111111111111111111111111111LL,\
    \ 63) == 0b0111111111111111111111111111111111111111111111111111111111111111LL);\n\
    \n  std::cout << \"Hello World\" << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - tools/assert_that.hpp
  - tools/reverse.hpp
  - tools/floor_log2.hpp
  - tools/popcount.hpp
  isVerificationFile: true
  path: tests/reverse.test.cpp
  requiredBy: []
  timestamp: '2024-11-22 20:21:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/reverse.test.cpp
layout: document
redirect_from:
- /verify/tests/reverse.test.cpp
- /verify/tests/reverse.test.cpp.html
title: tests/reverse.test.cpp
---
