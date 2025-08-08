// competitive-verifier: STANDALONE

#include <iostream>
#include "tools/int128_t.hpp"
#include "tools/is_arithmetic.hpp"
#include "tools/uint128_t.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  static_assert(tools::is_arithmetic_v<bool>);
  static_assert(tools::is_arithmetic_v<const bool>);
  static_assert(!tools::is_arithmetic_v<bool&>);
  static_assert(!tools::is_arithmetic_v<const bool&>);

  static_assert(tools::is_arithmetic_v<int>);
  static_assert(tools::is_arithmetic_v<unsigned int>);
  static_assert(tools::is_arithmetic_v<const int>);
  static_assert(tools::is_arithmetic_v<const unsigned int>);
  static_assert(!tools::is_arithmetic_v<int&>);
  static_assert(!tools::is_arithmetic_v<unsigned int&>);
  static_assert(!tools::is_arithmetic_v<const int&>);
  static_assert(!tools::is_arithmetic_v<const unsigned int&>);

  static_assert(tools::is_arithmetic_v<double>);
  static_assert(tools::is_arithmetic_v<const double>);
  static_assert(!tools::is_arithmetic_v<double&>);
  static_assert(!tools::is_arithmetic_v<const double&>);

  static_assert(tools::is_arithmetic_v<tools::int128_t>);
  static_assert(tools::is_arithmetic_v<tools::uint128_t>);
  static_assert(tools::is_arithmetic_v<const tools::int128_t>);
  static_assert(tools::is_arithmetic_v<const tools::uint128_t>);
  static_assert(!tools::is_arithmetic_v<tools::int128_t&>);
  static_assert(!tools::is_arithmetic_v<tools::uint128_t&>);
  static_assert(!tools::is_arithmetic_v<const tools::int128_t&>);
  static_assert(!tools::is_arithmetic_v<const tools::uint128_t&>);

  return 0;
}
