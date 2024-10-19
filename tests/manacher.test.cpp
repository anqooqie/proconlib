#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/2934"

#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <iterator>
#include <cstdlib>
#include "atcoder/string.hpp"
#include "tools/manacher.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int N;
  std::string T;
  std::cin >> N >> T;

  std::vector<std::pair<int, int>> R;
  tools::manacher(T.begin(), T.end(), std::back_inserter(R));
  const auto Z = atcoder::z_algorithm(T);

  std::cout << [&]() {
    for (int i = 1; i < N; ++i) {
      if (R[i * 2 + 1].first == 0 && [&]() {
        for (int j = 0; j < N; j += R[i * 2 + 1].second - R[i * 2 + 1].first - 1) {
          if (Z[j] < N - j) {
            return false;
          }
        }
        return true;
      }()) {
        return (R[i * 2 + 1].second - R[i * 2 + 1].first + 1) / 2;
      }
    }
    for (int i = 0; i < N; ++i) {
      if (R[i * 2 + 1].second == N) {
        return (N + R[i * 2 + 1].first + 1) / 2;
      }
    }
    std::exit(EXIT_FAILURE);
  }() << '\n';

  return 0;
}
