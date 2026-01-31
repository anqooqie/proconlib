// competitive-verifier: STANDALONE
// Source: https://atcoder.jp/contests/abc311/tasks/abc311_g

#include <iostream>
#include <limits>
#include <vector>
#include "tools/assert_that.hpp"
#include "tools/cartesian_tree.hpp"
#include "tools/chmax.hpp"
#include "tools/chmin.hpp"
#include "tools/cumsum2d.hpp"

using ll = long long;

ll solve(const int N, const int M, const std::vector<std::vector<int>>& A) {
  const tools::cumsum2d<int> sum(A);

  auto answer = std::numeric_limits<ll>::min();
  for (int r1 = 0; r1 < N; ++r1) {
    std::vector<int> row(M, std::numeric_limits<int>::max());
    for (int r2 = r1 + 1; r2 <= N; ++r2) {
      for (int c = 0; c < M; ++c) {
        tools::chmin(row[c], A[r2 - 1][c]);
      }
      const tools::cartesian_tree cartesian_tree(row);
      for (int c = 0; c < M; ++c) {
        const auto& [c1, c2] = cartesian_tree.get_vertex(c).interval;
        tools::chmax(answer, static_cast<ll>(row[c]) * sum.query(r1, r2, c1, c2));
      }
    }
  }

  return answer;
}

void sample01() {
  const int N = 3;
  const int M = 3;
  const std::vector<std::vector<int>> A = {
    {5, 4, 3},
    {4, 3, 2},
    {3, 2, 1},
  };
  assert_that(solve(N, M, A) == 48);
}

void sample02() {
  const int N = 4;
  const int M = 5;
  const std::vector<std::vector<int>> A = {
    {3, 1, 4, 1, 5},
    {9, 2, 6, 5, 3},
    {5, 8, 9, 7, 9},
    {3, 2, 3, 8, 4},
  };
  assert_that(solve(N, M, A) == 231);
}

void sample03() {
  const int N = 6;
  const int M = 6;
  const std::vector<std::vector<int>> A = {
    {1, 300, 300, 300, 300, 300},
    {300, 1, 300, 300, 300, 300},
    {300, 300, 1, 300, 300, 300},
    {300, 300, 300, 1, 300, 300},
    {300, 300, 300, 300, 1, 300},
    {300, 300, 300, 300, 300, 1},
  };
  assert_that(solve(N, M, A) == 810000);
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  sample01();
  sample02();
  sample03();

  return 0;
}
