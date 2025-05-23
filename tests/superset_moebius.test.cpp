// competitive-verifier: STANDALONE

#include <iostream>
#include <random>
#include <vector>
#include <iterator>
#include "atcoder/modint.hpp"
#include "tools/assert_that.hpp"
#include "tools/superset_moebius.hpp"

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
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        if ((i & j) == i) b[i] += a[j];
      }
    }

    std::vector<mint> actual_a;
    tools::superset_moebius(b.begin(), b.end(), std::back_inserter(actual_a));
    assert_that(actual_a == a);

    tools::superset_moebius(b.begin(), b.end());
    assert_that(b == a);
  }

  return 0;
}
