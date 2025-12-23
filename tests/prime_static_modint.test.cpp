// competitive-verifier: STANDALONE

#include <iostream>
#include "atcoder/modint.hpp"
#include "tools/prime_static_modint.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  static_assert(tools::prime_static_modint<atcoder::modint998244353>);
  static_assert(tools::prime_static_modint<atcoder::static_modint<2>>);
  static_assert(tools::prime_static_modint<atcoder::static_modint<3>>);
  static_assert(!tools::prime_static_modint<atcoder::static_modint<4>>);
  static_assert(tools::prime_static_modint<atcoder::static_modint<5>>);
  static_assert(!tools::prime_static_modint<atcoder::static_modint<6>>);
  static_assert(!tools::prime_static_modint<atcoder::modint>);

  return 0;
}
