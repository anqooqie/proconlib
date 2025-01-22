// competitive-verifier: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/2945

#include <iostream>
#include <array>
#include <utility>
#include <tuple>
#include "tools/zero_one_bfs.hpp"

using ll = long long;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  const auto P = [](const ll x, const ll y) {
    return 100 * y + x;
  };
  for (ll N; std::cin >> N, N > 0;) {
    ll A, B, C, D;
    std::cin >> A >> B >> C >> D;
    --A, --B;
    tools::zero_one_bfs<true, ll> graph(100 * 100);
    for (ll x = 0; x < 100; ++x) {
      for (ll y = 0; y < 100; ++y) {
        for (const auto& [dx, dy] : std::array<std::pair<ll, ll>, 4>({std::make_pair(1, 0), std::make_pair(-1, 0), std::make_pair(0, 1), std::make_pair(0, -1)})) {
          if (0 <= x + dx && x + dx < 100 && 0 <= y + dy && y + dy < 100) {
            graph.add_edge(P(x, y), P(x + dx, y + dy), A <= x + dx && x + dx < C && B <= y + dy && y + dy < D ? 0 : 1);
          }
        }
      }
    }

    ll answer = 0;
    ll pX, pY;
    std::cin >> pX >> pY;
    --pX, --pY;
    for (ll i = 0; i < N; ++i) {
      ll X, Y;
      std::cin >> X >> Y;
      --X, --Y;
      answer += graph.query(P(pX, pY)).first[P(X, Y)];
      std::tie(pX, pY) = std::make_pair(X, Y);
    }

    std::cout << answer << '\n';
  }

  return 0;
}
