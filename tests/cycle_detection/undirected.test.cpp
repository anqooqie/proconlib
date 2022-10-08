#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/2891"

#include <iostream>
#include <vector>
#include "tools/cycle_detection.hpp"

using ll = long long;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  ll N;
  std::cin >> N;
  tools::cycle_detection<false> graph(N);
  for (ll i = 0; i < N; ++i) {
    ll u, v;
    std::cin >> u >> v;
    --u, --v;
    graph.add_edge(u, v);
  }

  std::vector<bool> is_in_cycle(N, false);
  for (const auto v : std::vector(graph.query()->first)) {
    is_in_cycle[v] = true;
  }

  ll Q;
  std::cin >> Q;
  for (ll q = 0; q < Q; ++q) {
    ll a, b;
    std::cin >> a >> b;
    --a, --b;
    std::cout << (is_in_cycle[a] && is_in_cycle[b] ? 2 : 1) << '\n';
  }

  return 0;
}
