// competitive-verifier: PROBLEM https://atcoder.jp/contests/abc334/tasks/abc334_g

#include <iostream>
#include <vector>
#include <string>
#include "atcoder/modint.hpp"
#include "tools/lowlink.hpp"

using mint = atcoder::modint998244353;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int H, W;
  std::cin >> H >> W;
  std::vector<std::string> S(H);
  for (auto&& S_i : S) std::cin >> S_i;

  auto V = std::vector(H, std::vector<int>(W, -1));
  int k = 0;
  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      if (S[i][j] == '#') {
        V[i][j] = k++;
      }
    }
  }

  tools::lowlink graph(k);
  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      if (i + 1 < H && S[i][j] == '#' && S[i + 1][j] == '#') {
        graph.add_edge(V[i][j], V[i + 1][j]);
      }
      if (j + 1 < W && S[i][j] == '#' && S[i][j + 1] == '#') {
        graph.add_edge(V[i][j], V[i][j + 1]);
      }
    }
  }

  graph.build();

  auto answer = mint::raw(0);
  for (int v = 0; v < k; ++v) {
    answer += mint::raw(graph.ncc_without_vertex(v));
  }
  answer /= mint::raw(k);

  std::cout << answer.val() << '\n';
  return 0;
}
