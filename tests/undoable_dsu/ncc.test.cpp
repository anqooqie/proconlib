// competitive-verifier: STANDALONE
// Source: https://atcoder.jp/contests/abc334/tasks/abc334_e

#include <algorithm>
#include <functional>
#include <iostream>
#include <ranges>
#include <string>
#include <vector>
#include "atcoder/modint.hpp"
#include "tools/assert_that.hpp"
#include "tools/undoable_dsu.hpp"

using mint = atcoder::modint998244353;

mint solve(const std::vector<std::string>& S) {
  const int H = S.size();
  const int W = S[0].size();

  auto V = std::vector(H, std::vector<int>(W, -1));
  int k = 0;
  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      if (S[i][j] == '#') {
        V[i][j] = k++;
      }
    }
  }

  tools::undoable_dsu dsu(k + 1);
  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      if (i + 1 < H && S[i][j] == '#' && S[i + 1][j] == '#') {
        dsu.merge(V[i][j], V[i + 1][j]);
      }
      if (j + 1 < W && S[i][j] == '#' && S[i][j + 1] == '#') {
        dsu.merge(V[i][j], V[i][j + 1]);
      }
    }
  }

  auto answer = mint::raw(0);
  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      if (S[i][j] == '.') {
        int rollback = 0;
        if (0 <= i - 1 && S[i - 1][j] == '#') {
          dsu.merge(k, V[i - 1][j]);
          ++rollback;
        }
        if (i + 1 < H && S[i + 1][j] == '#') {
          dsu.merge(k, V[i + 1][j]);
          ++rollback;
        }
        if (0 <= j - 1 && S[i][j - 1] == '#') {
          dsu.merge(k, V[i][j - 1]);
          ++rollback;
        }
        if (j + 1 < W && S[i][j + 1] == '#') {
          dsu.merge(k, V[i][j + 1]);
          ++rollback;
        }

        answer += mint::raw(dsu.ncc());

        for (int r = 0; r < rollback; ++r) {
          dsu.undo();
        }
      }
    }
  }
  answer /= mint::raw(std::ranges::fold_left(S | std::views::transform([](const auto& S_i) { return std::ranges::count(S_i, '.'); }), 0, std::plus{}));
  return answer;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  assert_that(solve({
    "##.",
    "#.#",
    "#..",
  }) == mint::raw(499122178));
  assert_that(solve({
    "..#..",
    ".###.",
    "#####",
    "..#..",
  }) == mint::raw(598946613));
  assert_that(solve({
    "#...",
    ".#.#",
    "..##",
  }) == mint::raw(285212675));

  return 0;
}
