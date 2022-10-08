#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A"

#include <iostream>
#include <random>
#include "atcoder/dsu.hpp"
#include "tools/assert_that.hpp"
#include "tools/random_tree.hpp"

using ll = long long;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  std::random_device seed_gen;
  std::mt19937 engine(seed_gen());

  for (ll n = 1; n <= 1000; ++n) {
    tools::random_tree<ll> dist(n);
    for (ll i = 0; i < 10; ++i) {
      atcoder::dsu dsu(n);
      ll edge_count = 0;
      for (const auto& [u, v] : dist(engine)) {
        dsu.merge(u, v);
        ++edge_count;
      }
      assert_that(dsu.groups().size() == 1);
      assert_that(edge_count == n - 1);
    }
  }

  std::cout << "Hello World" << '\n';
  return 0;
}
