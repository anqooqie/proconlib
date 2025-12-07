#ifndef TOOLS_REVERSE_HPP
#define TOOLS_REVERSE_HPP

#include <type_traits>
#include <limits>
#include <cstddef>
#include <cassert>
#include <cstdint>
#include "tools/floor_log2.hpp"

namespace tools {
  template <typename T>
  std::enable_if_t<std::is_integral_v<T> && !std::is_signed_v<T> && std::numeric_limits<T>::digits == 1, T> reverse(const T x, const std::size_t n) {
    assert(n <= std::numeric_limits<T>::digits);
    assert(!x || n == 1);
    return x;
  }
  template <typename T>
  std::enable_if_t<std::is_integral_v<T> && !std::is_signed_v<T> && std::numeric_limits<T>::digits == 8, T> reverse(T x, const std::size_t n) {
    assert(n <= std::numeric_limits<T>::digits);
    assert(x == 0 || tools::floor_log2(x) < n);
    x = ((x & UINT8_C(0x55)) << 1) | ((x & UINT8_C(0xAA)) >> 1);
    x = ((x & UINT8_C(0x33)) << 2) | ((x & UINT8_C(0xCC)) >> 2);
    x = ((x & UINT8_C(0x0F)) << 4) | ((x & UINT8_C(0xF0)) >> 4);
    x >>= (std::numeric_limits<T>::digits - n) & (std::numeric_limits<T>::digits - 1);
    return x;
  }
  template <typename T>
  std::enable_if_t<std::is_integral_v<T> && !std::is_signed_v<T> && std::numeric_limits<T>::digits == 16, T> reverse(T x, const std::size_t n) {
    assert(n <= std::numeric_limits<T>::digits);
    assert(x == 0 || tools::floor_log2(x) < n);
    x = ((x & UINT16_C(0x5555)) << 1) | ((x & UINT16_C(0xAAAA)) >> 1);
    x = ((x & UINT16_C(0x3333)) << 2) | ((x & UINT16_C(0xCCCC)) >> 2);
    x = ((x & UINT16_C(0x0F0F)) << 4) | ((x & UINT16_C(0xF0F0)) >> 4);
    x = ((x & UINT16_C(0x00FF)) << 8) | ((x & UINT16_C(0xFF00)) >> 8);
    x >>= (std::numeric_limits<T>::digits - n) & (std::numeric_limits<T>::digits - 1);
    return x;
  }
  template <typename T>
  std::enable_if_t<std::is_integral_v<T> && !std::is_signed_v<T> && std::numeric_limits<T>::digits == 32, T> reverse(T x, const std::size_t n) {
    assert(n <= std::numeric_limits<T>::digits);
    assert(x == 0 || tools::floor_log2(x) < n);
    x = ((x & UINT32_C(0x55555555)) << 1) | ((x & UINT32_C(0xAAAAAAAA)) >> 1);
    x = ((x & UINT32_C(0x33333333)) << 2) | ((x & UINT32_C(0xCCCCCCCC)) >> 2);
    x = ((x & UINT32_C(0x0F0F0F0F)) << 4) | ((x & UINT32_C(0xF0F0F0F0)) >> 4);
    x = ((x & UINT32_C(0x00FF00FF)) << 8) | ((x & UINT32_C(0xFF00FF00)) >> 8);
    x = ((x & UINT32_C(0x0000FFFF)) << 16) | ((x & UINT32_C(0xFFFF0000)) >> 16);
    x >>= (std::numeric_limits<T>::digits - n) & (std::numeric_limits<T>::digits - 1);
    return x;
  }
  template <typename T>
  std::enable_if_t<std::is_integral_v<T> && !std::is_signed_v<T> && std::numeric_limits<T>::digits == 64, T> reverse(T x, const std::size_t n) {
    assert(n <= std::numeric_limits<T>::digits);
    assert(x == 0 || tools::floor_log2(x) < n);
    x = ((x & UINT64_C(0x5555555555555555)) << 1) | ((x & UINT64_C(0xAAAAAAAAAAAAAAAA)) >> 1);
    x = ((x & UINT64_C(0x3333333333333333)) << 2) | ((x & UINT64_C(0xCCCCCCCCCCCCCCCC)) >> 2);
    x = ((x & UINT64_C(0x0F0F0F0F0F0F0F0F)) << 4) | ((x & UINT64_C(0xF0F0F0F0F0F0F0F0)) >> 4);
    x = ((x & UINT64_C(0x00FF00FF00FF00FF)) << 8) | ((x & UINT64_C(0xFF00FF00FF00FF00)) >> 8);
    x = ((x & UINT64_C(0x0000FFFF0000FFFF)) << 16) | ((x & UINT64_C(0xFFFF0000FFFF0000)) >> 16);
    x = ((x & UINT64_C(0x00000000FFFFFFFF)) << 32) | ((x & UINT64_C(0xFFFFFFFF00000000)) >> 32);
    x >>= (std::numeric_limits<T>::digits - n) & (std::numeric_limits<T>::digits - 1);
    return x;
  }
  template <typename T>
  std::enable_if_t<std::is_integral_v<T> && std::is_signed_v<T>, T> reverse(const T x, const std::size_t n) {
    assert(x >= 0);
    return tools::reverse(static_cast<std::make_unsigned_t<T>>(x), n);
  }
}

#endif
