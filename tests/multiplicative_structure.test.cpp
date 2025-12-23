// competitive-verifier: STANDALONE

#include <complex>
#include <iostream>
#include "atcoder/modint.hpp"
#include "tools/multiplicative_structure.hpp"
#include "tools/groups.hpp"
#include "tools/fps.hpp"
#include "tools/int128_t.hpp"
#include "tools/monoids.hpp"
#include "tools/permutation.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  static_assert(std::same_as<tools::multiplicative_structure<int>, tools::monoids::multiplies<int>>);
  static_assert(std::same_as<tools::multiplicative_structure<tools::int128_t>, tools::monoids::multiplies<tools::int128_t>>);
  static_assert(std::same_as<tools::multiplicative_structure<double>, tools::groups::multiplies<double>>);
  static_assert(std::same_as<tools::multiplicative_structure<std::complex<double>>, tools::groups::multiplies<std::complex<double>>>);
  static_assert(std::same_as<tools::multiplicative_structure<atcoder::modint998244353>, tools::groups::multiplies<atcoder::modint998244353>>);
  static_assert(std::same_as<tools::multiplicative_structure<atcoder::static_modint<4>>, tools::monoids::multiplies<atcoder::static_modint<4>>>);
  static_assert(std::same_as<tools::multiplicative_structure<atcoder::modint>, tools::groups::multiplies<atcoder::modint>>);
  static_assert(std::same_as<tools::multiplicative_structure<tools::fps<atcoder::modint998244353>>, tools::groups::multiplies<tools::fps<atcoder::modint998244353>>>);
  static_assert(std::same_as<tools::multiplicative_structure<tools::permutation<int>>, tools::monoids::multiplies<tools::permutation<int>>>);

  return 0;
}
