#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DPL_1_F"

#include <iostream>
#include "tools/zero_one_knapsack.hpp"
#include "tools/assert_that.hpp"

using ll = long long;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  ll N, W;
  std::cin >> N >> W;
  tools::zero_one_knapsack<ll> solver(W);
  for (ll i = 0; i < N; ++i) {
    ll v, w;
    std::cin >> v >> w;
    solver.add_item(v, w);
  }

  const auto [answer, selected] = solver.query();
  ll v = 0;
  ll w = 0;
  for (const auto i : selected) {
    v += solver.get_item(i).first;
    w += solver.get_item(i).second;
  }
  assert_that(v == answer);
  assert_that(w <= W);
  std::cout << answer << '\n';

  return 0;
}
