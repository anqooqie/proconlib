// competitive-verifier: STANDALONE
// Source: https://atcoder.jp/contests/acl1/tasks/acl1_c

#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include "tools/assert_that.hpp"
#include "tools/vector2.hpp"
#include "tools/weighted_bipartite_matching.hpp"

using ll = long long;

ll solve(const ll N, const ll M, const std::vector<std::string>& S) {
  tools::weighted_bipartite_matching<true, ll> graph(N * M, N * M);
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
  return *graph.query(number_of_pieces);
}

void sample_01() {
  const ll N = 3;
  const ll M = 3;
  const std::vector<std::string> S = {
    "o..",
    "...",
    "o.#",
  };
  assert_that(solve(N, M, S) == 4);
}

void sample_02() {
  const ll N = 9;
  const ll M = 10;
  const std::vector<std::string> S = {
    ".#....o#..",
    ".#..#..##o",
    ".....#o.##",
    ".###.#o..o",
    "#.#...##.#",
    "..#..#.###",
    "#o.....#..",
    "....###..o",
    "o.......o#",
  };
  assert_that(solve(N, M, S) == 24);
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  sample_01();
  sample_02();

  return 0;
}
