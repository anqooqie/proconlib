// competitive-verifier: STANDALONE

#include <algorithm>
#include <iostream>
#include <random>
#include <ranges>
#include <tuple>
#include <vector>
#include "tools/assert_that.hpp"
#include "tools/second_order_imos.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  std::random_device seed_gen;
  std::mt19937 engine(seed_gen());
  tools::second_order_imos<int> a(10);
  std::vector<int> b(a.size(), 0);
  std::uniform_int_distribution<int> x_dist(-10, 10);
  std::uniform_int_distribution<int> d_dist(-3, 3);
  for (int L = 0; L < a.size(); ++L) {
    std::uniform_int_distribution<int> lr_dist(L, a.size());
    for (int q = 0; q < 100; ++q) {
      auto l = lr_dist(engine);
      auto r = lr_dist(engine);
      std::tie(l, r) = std::minmax({l, r});
      const auto x = x_dist(engine);
      const auto d = d_dist(engine);
      a.add(l, r, x, d);
      for (int i = l; i < r; ++i) {
        b[i] += x + (i - l) * d;
      }
    }
    for (int i = 0; i <= L; ++i) {
      assert_that(a[i] == b[i]);
    }
  }
  assert_that((a | std::ranges::to<std::vector>()) == b);

  return 0;
}
