// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/minimum_steiner_tree

#include <iostream>
#include <vector>
#include "tools/join.hpp"
#include "tools/minimum_steiner_tree.hpp"

using ll = long long;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int N, M;
  std::cin >> N >> M;
  tools::minimum_steiner_tree<ll> graph(N);
  for (int i = 0; i < M; ++i) {
    int U, V, W;
    std::cin >> U >> V >> W;
    graph.add_edge(U, V, W);
  }
  int K;
  std::cin >> K;
  std::vector<int> X(K);
  for (auto& X_i : X) std::cin >> X_i;

  const auto qr = graph.query<true>(X);
  std::cout << qr.cost << ' ' << qr.edge_ids.size() << '\n';
  std::cout << tools::join(qr.edge_ids, " ") << '\n';

  return 0;
}
