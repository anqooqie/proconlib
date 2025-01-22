// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/chromatic_number

#include <iostream>
#include "tools/chromatic_number.hpp"

using ll = long long;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  ll N, M;
  std::cin >> N >> M;
  tools::chromatic_number graph(N);
  for (ll i = 0; i < M; ++i) {
    ll u, v;
    std::cin >> u >> v;
    graph.add_edge(u, v);
  }

  std::cout << graph.query() << '\n';
  return 0;
}
