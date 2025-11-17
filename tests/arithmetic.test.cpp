// competitive-verifier: STANDALONE

#include <iostream>
#include "tools/arithmetic.hpp"
#include "tools/int128_t.hpp"
#include "tools/uint128_t.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  static_assert(tools::arithmetic<bool>);
  static_assert(tools::arithmetic<const bool>);
  static_assert(!tools::arithmetic<bool&>);
  static_assert(!tools::arithmetic<const bool&>);

  static_assert(tools::arithmetic<int>);
  static_assert(tools::arithmetic<unsigned int>);
  static_assert(tools::arithmetic<const int>);
  static_assert(tools::arithmetic<const unsigned int>);
  static_assert(!tools::arithmetic<int&>);
  static_assert(!tools::arithmetic<unsigned int&>);
  static_assert(!tools::arithmetic<const int&>);
  static_assert(!tools::arithmetic<const unsigned int&>);

  static_assert(tools::arithmetic<double>);
  static_assert(tools::arithmetic<const double>);
  static_assert(!tools::arithmetic<double&>);
  static_assert(!tools::arithmetic<const double&>);

  static_assert(tools::arithmetic<tools::int128_t>);
  static_assert(tools::arithmetic<tools::uint128_t>);
  static_assert(tools::arithmetic<const tools::int128_t>);
  static_assert(tools::arithmetic<const tools::uint128_t>);
  static_assert(!tools::arithmetic<tools::int128_t&>);
  static_assert(!tools::arithmetic<tools::uint128_t&>);
  static_assert(!tools::arithmetic<const tools::int128_t&>);
  static_assert(!tools::arithmetic<const tools::uint128_t&>);

  return 0;
}
