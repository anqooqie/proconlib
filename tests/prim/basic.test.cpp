#define PROBLEM "https://judge.yosupo.jp/problem/minimum_spanning_tree"

#include <iostream>
#include "tools/prim.hpp"
#include "tools/join.hpp"

using ll = long long;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int N, M;
  std::cin >> N >> M;
  tools::prim<ll> graph(N);
  for (int i = 0; i < M; ++i) {
    int a, b, c;
    std::cin >> a >> b >> c;
    graph.add_edge(a, b, c);
  }

  const auto [X, e] = graph.query().first[0];
  std::cout << X << '\n';
  std::cout << tools::join(e.begin(), e.end(), " ") << '\n';

  return 0;
}
