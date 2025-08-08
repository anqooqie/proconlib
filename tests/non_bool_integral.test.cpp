// competitive-verifier: STANDALONE

#include <iostream>
#include "tools/int128_t.hpp"
#include "tools/non_bool_integral.hpp"
#include "tools/uint128_t.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  static_assert(!tools::non_bool_integral<bool>);
  static_assert(!tools::non_bool_integral<const bool>);
  static_assert(!tools::non_bool_integral<bool&>);
  static_assert(!tools::non_bool_integral<const bool&>);

  static_assert(tools::non_bool_integral<int>);
  static_assert(tools::non_bool_integral<unsigned int>);
  static_assert(tools::non_bool_integral<const int>);
  static_assert(tools::non_bool_integral<const unsigned int>);
  static_assert(!tools::non_bool_integral<int&>);
  static_assert(!tools::non_bool_integral<unsigned int&>);
  static_assert(!tools::non_bool_integral<const int&>);
  static_assert(!tools::non_bool_integral<const unsigned int&>);

  static_assert(!tools::non_bool_integral<double>);
  static_assert(!tools::non_bool_integral<const double>);
  static_assert(!tools::non_bool_integral<double&>);
  static_assert(!tools::non_bool_integral<const double&>);

  static_assert(tools::non_bool_integral<tools::int128_t>);
  static_assert(tools::non_bool_integral<tools::uint128_t>);
  static_assert(tools::non_bool_integral<const tools::int128_t>);
  static_assert(tools::non_bool_integral<const tools::uint128_t>);
  static_assert(!tools::non_bool_integral<tools::int128_t&>);
  static_assert(!tools::non_bool_integral<tools::uint128_t&>);
  static_assert(!tools::non_bool_integral<const tools::int128_t&>);
  static_assert(!tools::non_bool_integral<const tools::uint128_t&>);

  return 0;
}
