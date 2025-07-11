// competitive-verifier: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_C

#include <algorithm>
#include <iostream>
#include <iterator>
#include <ranges>
#include <vector>
#include "tools/wavelet_matrix.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int n;
  std::cin >> n;
  tools::wavelet_matrix<int> wm;
  for (int i = 0; i < n; ++i) {
    int x, y;
    std::cin >> x >> y;
    wm.add_point(x, y);
  }
  wm.build();

  int Q;
  std::cin >> Q;
  for (int q = 0; q < Q; ++q) {
    int sx, tx, sy, ty;
    std::cin >> sx >> tx >> sy >> ty;
    ++tx, ++ty;

    std::vector<std::size_t> answers;
    std::ranges::subrange<std::vector<int>::const_iterator> partial_answers;
    for (int y = ty; [&]() {
      partial_answers = wm.prev_points(sx, tx, y);
      return !std::ranges::empty(partial_answers) && wm.get_point(*std::ranges::begin(partial_answers)).second >= sy;
    }(); y = wm.get_point(answers.back()).second) {
      std::ranges::copy(partial_answers, std::back_inserter(answers));
    }

    std::ranges::sort(answers);
    for (const auto answer : answers) {
      std::cout << answer << '\n';
    }
    std::cout << '\n';
  }

  return 0;
}
