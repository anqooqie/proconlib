// competitive-verifier: STANDALONE

#include <iostream>
#include <random>
#include <vector>
#include "atcoder/modint.hpp"
#include "tools/assert_that.hpp"
#include "tools/pow2.hpp"
#include "tools/subset_zeta.hpp"
#include "tools/subset_zeta_inplace.hpp"

using mint = atcoder::modint998244353;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  std::random_device seed_gen;
  std::mt19937 engine(seed_gen());
  std::uniform_int_distribution<int> dist(0, 998244352);

  for (int N = 1; N <= 10; ++N) {
    std::vector<mint> a(tools::pow2(N));
    for (auto&& a_i : a) a_i = mint::raw(dist(engine));

    std::vector<mint> b(tools::pow2(N), mint::raw(0));
    for (int i = 0; i < tools::pow2(N); ++i) {
      for (int j = 0; j < tools::pow2(N); ++j) {
        if ((i | j) == i) b[i] += a[j];
      }
    }

    assert_that(tools::subset_zeta(a) == b);

    tools::subset_zeta_inplace(a);
    assert_that(a == b);
  }

  return 0;
}
