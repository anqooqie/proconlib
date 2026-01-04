// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/assignment

#include <algorithm>
#include <functional>
#include <iostream>
#include <ranges>
#include <vector>
#include "tools/join.hpp"
#include "tools/weighted_bipartite_matching.hpp"

using ll = long long;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  ll N;
  std::cin >> N;

  tools::weighted_bipartite_matching<false, ll> graph(N, N);
  for (ll i = 0; i < N; ++i) {
    for (ll j = 0; j < N; ++j) {
      ll a_ij;
      std::cin >> a_ij;
      graph.add_edge(i, j, a_ij);
    }
  }

  std::vector<ll> p(N);
  const auto edges = *graph.query<true>(N);
  for (const auto& edge : edges | std::views::transform([&](const auto k) { return graph.get_edge(k); })) {
    p[edge.from] = edge.to;
  }

  std::cout << std::ranges::fold_left(edges | std::views::transform([&](const auto k) { return graph.get_edge(k).weight; }), 0LL, std::plus<ll>{}) << '\n';
  std::cout << tools::join(p, ' ') << '\n';
  return 0;
}
