// competitive-verifier: STANDALONE

#include <cstdint>
#include <iostream>
#include <limits>
#include <type_traits>
#include "tools/int128_t.hpp"
#include "tools/is_signed.hpp"
#include "tools/is_unsigned.hpp"
#include "tools/make_wider.hpp"
#include "tools/uint128_t.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  constexpr int max_digits = std::numeric_limits<tools::uint128_t>::digits;

  {
    using T = std::int8_t;
    using W = tools::make_wider_t<T>;
    constexpr bool W_exists = std::numeric_limits<T>::digits * 2 <= max_digits;
    static_assert((W_exists && std::numeric_limits<T>::digits * 2 <= std::numeric_limits<W>::digits && tools::is_signed_v<W>) || (!W_exists && std::is_void_v<W>));
    static_assert(!std::is_const_v<W>);
    static_assert(!std::is_volatile_v<W>);
  }
  {
    using T = std::uint8_t;
    using W = tools::make_wider_t<T>;
    constexpr bool W_exists = std::numeric_limits<T>::digits * 2 <= max_digits;
    static_assert((W_exists && std::numeric_limits<T>::digits * 2 <= std::numeric_limits<W>::digits && tools::is_unsigned_v<W>) || (!W_exists && std::is_void_v<W>));
    static_assert(!std::is_const_v<W>);
    static_assert(!std::is_volatile_v<W>);
  }
  {
    using T = std::int16_t;
    using W = tools::make_wider_t<T>;
    constexpr bool W_exists = std::numeric_limits<T>::digits * 2 <= max_digits;
    static_assert((W_exists && std::numeric_limits<T>::digits * 2 <= std::numeric_limits<W>::digits && tools::is_signed_v<W>) || (!W_exists && std::is_void_v<W>));
    static_assert(!std::is_const_v<W>);
    static_assert(!std::is_volatile_v<W>);
  }
  {
    using T = std::uint16_t;
    using W = tools::make_wider_t<T>;
    constexpr bool W_exists = std::numeric_limits<T>::digits * 2 <= max_digits;
    static_assert((W_exists && std::numeric_limits<T>::digits * 2 <= std::numeric_limits<W>::digits && tools::is_unsigned_v<W>) || (!W_exists && std::is_void_v<W>));
    static_assert(!std::is_const_v<W>);
    static_assert(!std::is_volatile_v<W>);
  }
  {
    using T = std::int32_t;
    using W = tools::make_wider_t<T>;
    constexpr bool W_exists = std::numeric_limits<T>::digits * 2 <= max_digits;
    static_assert((W_exists && std::numeric_limits<T>::digits * 2 <= std::numeric_limits<W>::digits && tools::is_signed_v<W>) || (!W_exists && std::is_void_v<W>));
    static_assert(!std::is_const_v<W>);
    static_assert(!std::is_volatile_v<W>);
  }
  {
    using T = std::uint32_t;
    using W = tools::make_wider_t<T>;
    constexpr bool W_exists = std::numeric_limits<T>::digits * 2 <= max_digits;
    static_assert((W_exists && std::numeric_limits<T>::digits * 2 <= std::numeric_limits<W>::digits && tools::is_unsigned_v<W>) || (!W_exists && std::is_void_v<W>));
    static_assert(!std::is_const_v<W>);
    static_assert(!std::is_volatile_v<W>);
  }
  {
    using T = std::int64_t;
    using W = tools::make_wider_t<T>;
    constexpr bool W_exists = std::numeric_limits<T>::digits * 2 <= max_digits;
    static_assert((W_exists && std::numeric_limits<T>::digits * 2 <= std::numeric_limits<W>::digits && tools::is_signed_v<W>) || (!W_exists && std::is_void_v<W>));
    static_assert(!std::is_const_v<W>);
    static_assert(!std::is_volatile_v<W>);
  }
  {
    using T = std::uint64_t;
    using W = tools::make_wider_t<T>;
    constexpr bool W_exists = std::numeric_limits<T>::digits * 2 <= max_digits;
    static_assert((W_exists && std::numeric_limits<T>::digits * 2 <= std::numeric_limits<W>::digits && tools::is_unsigned_v<W>) || (!W_exists && std::is_void_v<W>));
    static_assert(!std::is_const_v<W>);
    static_assert(!std::is_volatile_v<W>);
  }
  {
    using T = tools::int128_t;
    using W = tools::make_wider_t<T>;
    constexpr bool W_exists = std::numeric_limits<T>::digits * 2 <= max_digits;
    static_assert((W_exists && std::numeric_limits<T>::digits * 2 <= std::numeric_limits<W>::digits && tools::is_signed_v<W>) || (!W_exists && std::is_void_v<W>));
    static_assert(!std::is_const_v<W>);
    static_assert(!std::is_volatile_v<W>);
  }
  {
    using T = tools::uint128_t;
    using W = tools::make_wider_t<T>;
    constexpr bool W_exists = std::numeric_limits<T>::digits * 2 <= max_digits;
    static_assert((W_exists && std::numeric_limits<T>::digits * 2 <= std::numeric_limits<W>::digits && tools::is_unsigned_v<W>) || (!W_exists && std::is_void_v<W>));
    static_assert(!std::is_const_v<W>);
    static_assert(!std::is_volatile_v<W>);
  }

  {
    using T = const int;
    using W = tools::make_wider_t<T>;
    constexpr bool W_exists = std::numeric_limits<T>::digits * 2 <= max_digits;
    static_assert((W_exists && std::numeric_limits<T>::digits * 2 <= std::numeric_limits<W>::digits && tools::is_signed_v<W>) || (!W_exists && std::is_void_v<W>));
    static_assert(std::is_const_v<W>);
    static_assert(!std::is_volatile_v<W>);
  }
  {
    using T = volatile int;
    using W = tools::make_wider_t<T>;
    constexpr bool W_exists = std::numeric_limits<T>::digits * 2 <= max_digits;
    static_assert((W_exists && std::numeric_limits<T>::digits * 2 <= std::numeric_limits<W>::digits && tools::is_signed_v<W>) || (!W_exists && std::is_void_v<W>));
    static_assert(!std::is_const_v<W>);
    static_assert(std::is_volatile_v<W>);
  }
  {
    using T = const volatile int;
    using W = tools::make_wider_t<T>;
    constexpr bool W_exists = std::numeric_limits<T>::digits * 2 <= max_digits;
    static_assert((W_exists && std::numeric_limits<T>::digits * 2 <= std::numeric_limits<W>::digits && tools::is_signed_v<W>) || (!W_exists && std::is_void_v<W>));
    static_assert(std::is_const_v<W>);
    static_assert(std::is_volatile_v<W>);
  }
  {
    using T = const unsigned int;
    using W = tools::make_wider_t<T>;
    constexpr bool W_exists = std::numeric_limits<T>::digits * 2 <= max_digits;
    static_assert((W_exists && std::numeric_limits<T>::digits * 2 <= std::numeric_limits<W>::digits && tools::is_unsigned_v<W>) || (!W_exists && std::is_void_v<W>));
    static_assert(std::is_const_v<W>);
    static_assert(!std::is_volatile_v<W>);
  }
  {
    using T = volatile unsigned int;
    using W = tools::make_wider_t<T>;
    constexpr bool W_exists = std::numeric_limits<T>::digits * 2 <= max_digits;
    static_assert((W_exists && std::numeric_limits<T>::digits * 2 <= std::numeric_limits<W>::digits && tools::is_unsigned_v<W>) || (!W_exists && std::is_void_v<W>));
    static_assert(!std::is_const_v<W>);
    static_assert(std::is_volatile_v<W>);
  }
  {
    using T = const volatile unsigned int;
    using W = tools::make_wider_t<T>;
    constexpr bool W_exists = std::numeric_limits<T>::digits * 2 <= max_digits;
    static_assert((W_exists && std::numeric_limits<T>::digits * 2 <= std::numeric_limits<W>::digits && tools::is_unsigned_v<W>) || (!W_exists && std::is_void_v<W>));
    static_assert(std::is_const_v<W>);
    static_assert(std::is_volatile_v<W>);
  }

  {
    using T = const tools::int128_t;
    using W = tools::make_wider_t<T>;
    constexpr bool W_exists = std::numeric_limits<T>::digits * 2 <= max_digits;
    static_assert((W_exists && std::numeric_limits<T>::digits * 2 <= std::numeric_limits<W>::digits && tools::is_signed_v<W>) || (!W_exists && std::is_void_v<W>));
    static_assert(std::is_const_v<W>);
    static_assert(!std::is_volatile_v<W>);
  }
  {
    using T = volatile tools::int128_t;
    using W = tools::make_wider_t<T>;
    constexpr bool W_exists = std::numeric_limits<T>::digits * 2 <= max_digits;
    static_assert((W_exists && std::numeric_limits<T>::digits * 2 <= std::numeric_limits<W>::digits && tools::is_signed_v<W>) || (!W_exists && std::is_void_v<W>));
    static_assert(!std::is_const_v<W>);
    static_assert(std::is_volatile_v<W>);
  }
  {
    using T = const volatile tools::int128_t;
    using W = tools::make_wider_t<T>;
    constexpr bool W_exists = std::numeric_limits<T>::digits * 2 <= max_digits;
    static_assert((W_exists && std::numeric_limits<T>::digits * 2 <= std::numeric_limits<W>::digits && tools::is_signed_v<W>) || (!W_exists && std::is_void_v<W>));
    static_assert(std::is_const_v<W>);
    static_assert(std::is_volatile_v<W>);
  }
  {
    using T = const tools::uint128_t;
    using W = tools::make_wider_t<T>;
    constexpr bool W_exists = std::numeric_limits<T>::digits * 2 <= max_digits;
    static_assert((W_exists && std::numeric_limits<T>::digits * 2 <= std::numeric_limits<W>::digits && tools::is_unsigned_v<W>) || (!W_exists && std::is_void_v<W>));
    static_assert(std::is_const_v<W>);
    static_assert(!std::is_volatile_v<W>);
  }
  {
    using T = volatile tools::uint128_t;
    using W = tools::make_wider_t<T>;
    constexpr bool W_exists = std::numeric_limits<T>::digits * 2 <= max_digits;
    static_assert((W_exists && std::numeric_limits<T>::digits * 2 <= std::numeric_limits<W>::digits && tools::is_unsigned_v<W>) || (!W_exists && std::is_void_v<W>));
    static_assert(!std::is_const_v<W>);
    static_assert(std::is_volatile_v<W>);
  }
  {
    using T = const volatile tools::uint128_t;
    using W = tools::make_wider_t<T>;
    constexpr bool W_exists = std::numeric_limits<T>::digits * 2 <= max_digits;
    static_assert((W_exists && std::numeric_limits<T>::digits * 2 <= std::numeric_limits<W>::digits && tools::is_unsigned_v<W>) || (!W_exists && std::is_void_v<W>));
    static_assert(std::is_const_v<W>);
    static_assert(std::is_volatile_v<W>);
  }

  return 0;
}
