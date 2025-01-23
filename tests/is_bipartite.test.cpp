// competitive-verifier: PROBLEM https://atcoder.jp/contests/abc327/tasks/abc327_d
// competitive-verifier: IGNORE

#include <iostream>
#include <vector>
#include "tools/is_bipartite.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int N, M;
  std::cin >> N >> M;
  std::vector<int> A(M), B(M);
  for (auto& A_i : A) {
    std::cin >> A_i;
    --A_i;
  }
  for (auto& B_i : B) {
    std::cin >> B_i;
    --B_i;
  }

  tools::is_bipartite graph(N);
  for (int i = 0; i < M; ++i) {
    graph.add_edge(A[i], B[i]);
  }

  std::cout << (graph.query() ? "Yes" : "No") << '\n';
  return 0;
}
