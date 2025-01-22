// competitive-verifier: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_C

#include <iostream>
#include <vector>
#include <cstddef>
#include <algorithm>
#include <iterator>
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
    decltype(wm.next_points(0, 0, 0)) partial_answers;
    for (int y = ty; [&]() {
      partial_answers = wm.prev_points(sx, tx, y);
      return partial_answers.first < partial_answers.second && wm.get_point(*partial_answers.first).second >= sy;
    }(); y = wm.get_point(answers.back()).second) {
      std::copy(partial_answers.first, partial_answers.second, std::back_inserter(answers));
    }

    std::sort(answers.begin(), answers.end());
    for (const auto answer : answers) {
      std::cout << answer << '\n';
    }
    std::cout << '\n';
  }

  return 0;
}
