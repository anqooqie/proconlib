// competitive-verifier: STANDALONE

#include <iostream>
#include <type_traits>
#include "tools/int128_t.hpp"
#include "tools/make_signed.hpp"
#include "tools/uint128_t.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  static_assert(std::is_same_v<tools::make_signed_t<int>, int>);
  static_assert(std::is_same_v<tools::make_signed_t<unsigned int>, int>);
  static_assert(std::is_same_v<tools::make_signed_t<const int>, const int>);
  static_assert(std::is_same_v<tools::make_signed_t<const unsigned int>, const int>);

  static_assert(std::is_same_v<tools::make_signed_t<tools::int128_t>, tools::int128_t>);
  static_assert(std::is_same_v<tools::make_signed_t<tools::uint128_t>, tools::int128_t>);
  static_assert(std::is_same_v<tools::make_signed_t<const tools::int128_t>, const tools::int128_t>);
  static_assert(std::is_same_v<tools::make_signed_t<const tools::uint128_t>, const tools::int128_t>);

  return 0;
}
