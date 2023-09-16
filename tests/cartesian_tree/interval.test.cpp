#define PROBLEM "https://atcoder.jp/contests/abc311/tasks/abc311_g"

#include <iostream>
#include <vector>
#include <limits>
#include <functional>
#include "tools/cumsum2d.hpp"
#include "tools/group.hpp"
#include "tools/chmin.hpp"
#include "tools/cartesian_tree.hpp"
#include "tools/chmax.hpp"

using ll = long long;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int N, M;
  std::cin >> N >> M;
  auto A = std::vector(N, std::vector<int>(M));
  for (auto& A_r : A) {
    for (auto& A_rc: A_r) {
      std::cin >> A_rc;
    }
  }

  const tools::cumsum2d<tools::group::plus<int>> sum(A);

  ll answer = std::numeric_limits<ll>::min();
  for (int r1 = 0; r1 < N; ++r1) {
    std::vector<int> row(M, std::numeric_limits<int>::max());
    for (int r2 = r1 + 1; r2 <= N; ++r2) {
      for (int c = 0; c < M; ++c) {
        tools::chmin(row[c], A[r2 - 1][c]);
      }
      const tools::cartesian_tree<int> cartesian_tree(row);
      for (int c = 0; c < M; ++c) {
        const auto& [c1, c2] = cartesian_tree.get_vertex(c).interval;
        tools::chmax(answer, static_cast<ll>(row[c]) * sum.query(r1, r2, c1, c2));
      }
    }
  }

  std::cout << answer << '\n';
  return 0;
}
