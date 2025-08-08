// competitive-verifier: STANDALONE

#include <iostream>
#include "tools/int128_t.hpp"
#include "tools/integral.hpp"
#include "tools/uint128_t.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  static_assert(tools::integral<bool>);
  static_assert(tools::integral<const bool>);
  static_assert(!tools::integral<bool&>);
  static_assert(!tools::integral<const bool&>);

  static_assert(tools::integral<int>);
  static_assert(tools::integral<unsigned int>);
  static_assert(tools::integral<const int>);
  static_assert(tools::integral<const unsigned int>);
  static_assert(!tools::integral<int&>);
  static_assert(!tools::integral<unsigned int&>);
  static_assert(!tools::integral<const int&>);
  static_assert(!tools::integral<const unsigned int&>);

  static_assert(!tools::integral<double>);
  static_assert(!tools::integral<const double>);
  static_assert(!tools::integral<double&>);
  static_assert(!tools::integral<const double&>);

  static_assert(tools::integral<tools::int128_t>);
  static_assert(tools::integral<tools::uint128_t>);
  static_assert(tools::integral<const tools::int128_t>);
  static_assert(tools::integral<const tools::uint128_t>);
  static_assert(!tools::integral<tools::int128_t&>);
  static_assert(!tools::integral<tools::uint128_t&>);
  static_assert(!tools::integral<const tools::int128_t&>);
  static_assert(!tools::integral<const tools::uint128_t&>);

  return 0;
}
