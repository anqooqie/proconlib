#define PROBLEM "https://atcoder.jp/contests/acl1/tasks/acl1_c"

#include <iostream>
#include <vector>
#include <string>
#include <variant>
#include <queue>
#include "tools/weighted_bipartite_matching.hpp"
#include "tools/vector2.hpp"

using ll = long long;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  ll N, M;
  std::cin >> N >> M;
  std::vector<std::string> S(N);
  for (auto& S_i : S) std::cin >> S_i;

  tools::weighted_bipartite_matching<ll> graph(N * M, N * M, true);
  ll number_of_pieces = 0;
  for (ll y1 = 0; y1 < N; ++y1) {
    for (ll x1 = 0; x1 < M; ++x1) {
      if (S[y1][x1] == 'o') {
        ++number_of_pieces;
        std::queue<tools::vector2<ll>> queue;
        queue.emplace(x1, y1);
        auto will_visit = std::vector(N, std::vector(M, false));
        will_visit[y1][x1] = true;
        while (!queue.empty()) {
          const auto here = queue.front();
          queue.pop();
          graph.add_edge(y1 * M + x1, here.y * M + here.x, (here.y - y1) + (here.x - x1));
          if (here.y + 1 < N && !will_visit[here.y + 1][here.x] && S[here.y + 1][here.x] != '#') {
            queue.emplace(here.x, here.y + 1);
            will_visit[here.y + 1][here.x] = true;
          }
          if (here.x + 1 < M && !will_visit[here.y][here.x + 1] && S[here.y][here.x + 1] != '#') {
            queue.emplace(here.x + 1, here.y);
            will_visit[here.y][here.x + 1] = true;
          }
        }
      }
    }
  }

  std::cout << graph.query(number_of_pieces)->first << '\n';
  return 0;
}
