#define PROBLEM "https://judge.yosupo.jp/problem/matrix_rank"

#include <iostream>
#include "atcoder/modint.hpp"
#include "tools/matrix.hpp"

using mint = atcoder::modint998244353;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int N, M;
  std::cin >> N >> M;
  tools::matrix<mint> A(N, M);
  for (int r = 0; r < N; ++r) {
    for (int c = 0; c < M; ++c) {
      int A_rc;
      std::cin >> A_rc;
      A[r][c] = mint::raw(A_rc);
    }
  }

  std::cout << A.rank() << '\n';

  return 0;
}
