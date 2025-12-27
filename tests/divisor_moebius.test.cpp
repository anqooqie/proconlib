// competitive-verifier: STANDALONE

#include <iostream>
#include <random>
#include <vector>
#include "atcoder/modint.hpp"
#include "tools/assert_that.hpp"
#include "tools/divisor_moebius.hpp"
#include "tools/divisor_moebius_inplace.hpp"

using mint = atcoder::modint998244353;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  std::random_device seed_gen;
  std::mt19937 engine(seed_gen());
  std::uniform_int_distribution<int> dist(0, 998244352);

  for (int N = 0; N <= 20; ++N) {
    std::vector<mint> a(N);
    for (auto&& a_i : a) a_i = mint::raw(dist(engine));

    std::vector<mint> b(N, mint::raw(0));
    if (N > 0) b[0] = a[0];
    for (int i = 1; i < N; ++i) {
      for (int j = 1; j < N; ++j) {
        if (i % j == 0) b[i] += a[j];
      }
    }

    assert_that(tools::divisor_moebius(b) == a);

    tools::divisor_moebius_inplace(b);
    assert_that(b == a);
  }

  return 0;
}
