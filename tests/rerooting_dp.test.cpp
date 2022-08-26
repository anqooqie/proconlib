#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_A"

#include <iostream>
#include <vector>
#include <cstddef>
#include "tools/rerooting_dp.hpp"
#include "tools/monoid.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int n;
  std::cin >> n;

  std::vector<int> costs;
  const auto f_ve = [&](const int dist, const std::size_t edge_id) {
    return dist + costs[edge_id];
  };
  const auto f_ev = [](const int dist, std::size_t) {
    return dist;
  };

  tools::rerooting_dp<int, tools::monoid::max<int, 0>, decltype(f_ve), decltype(f_ev)> dp(n, f_ve, f_ev);
  for (int i = 0; i < n - 1; ++i) {
    int s, t, w;
    std::cin >> s >> t >> w;
    dp.add_edge(s, t);
    costs.push_back(w);
  }

  const auto result = dp.query();
  std::cout << *std::max_element(result.begin(), result.end()) << '\n';
  return 0;
}
