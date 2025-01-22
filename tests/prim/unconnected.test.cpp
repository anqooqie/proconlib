// competitive-verifier: PROBLEM https://atcoder.jp/contests/abc270/tasks/abc270_f

#include <iostream>
#include <vector>
#include <limits>
#include "tools/prim.hpp"
#include "tools/popcount.hpp"
#include "tools/chmin.hpp"

using ll = long long;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  ll N, M;
  std::cin >> N >> M;
  std::vector<ll> X(N), Y(N);
  for (auto& X_i : X) std::cin >> X_i;
  for (auto& Y_i : Y) std::cin >> Y_i;
  std::vector<ll> A(M), B(M), Z(M);
  for (ll i = 0; i < M; ++i) {
    std::cin >> A[i] >> B[i] >> Z[i];
    --A[i], --B[i];
  }

  ll answer = std::numeric_limits<ll>::max();
  for (ll state = 0; state < 4; ++state) {
    tools::prim<ll> graph(N + tools::popcount(state));
    if (state & 1) {
      for (ll i = 0; i < N; ++i) {
        graph.add_edge(i, N, X[i]);
      }
    }
    if (state & 2) {
      for (ll i = 0; i < N; ++i) {
        graph.add_edge(i, N + (state & 1), Y[i]);
      }
    }
    for (ll i = 0; i < M; ++i) {
      graph.add_edge(A[i], B[i], Z[i]);
    }
    if (const auto groups = graph.query().first; groups.size() == 1) {
      tools::chmin(answer, groups[0].first);
    }
  }

  std::cout << answer << '\n';
  return 0;
}
