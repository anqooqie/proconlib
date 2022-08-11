#define PROBLEM "https://atcoder.jp/contests/abc236/tasks/abc236_d"

#include <cstdint>
#include <iostream>
#include <vector>
#include <numeric>
#include <limits>
#include "tools/chmax.hpp"
#include "tools/next_matching.hpp"

using i64 = std::int_fast64_t;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  i64 N;
  std::cin >> N;

  auto A = std::vector(2 * N, std::vector<i64>(2 * N));
  for (i64 i = 0; i < 2 * N; ++i) {
    for (i64 j = i + 1; j < 2 * N; ++j) {
      std::cin >> A[i][j];
      A[j][i] = A[i][j];
    }
  }

  std::vector<i64> pattern(2 * N);
  std::iota(pattern.begin(), pattern.end(), 0);

  i64 answer = std::numeric_limits<int>::min();
  do {
    i64 possible_answer = 0;
    for (i64 i = 0; i < 2 * N; i += 2) {
      possible_answer ^= A[pattern[i]][pattern[i + 1]];
    }
    tools::chmax(answer, possible_answer);
  } while (tools::next_matching(pattern.begin(), pattern.end()));

  std::cout << answer << '\n';
  return 0;
}
