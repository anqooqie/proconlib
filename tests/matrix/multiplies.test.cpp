// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/matrix_product

#include <iostream>
#include "atcoder/modint.hpp"
#include "tools/matrix.hpp"

using mint = atcoder::modint998244353;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int N, M, K;
  std::cin >> N >> M >> K;
  tools::matrix<mint> A(N, M);
  for (int r = 0; r < N; ++r) {
    for (int c = 0; c < M; ++c) {
      int A_rc;
      std::cin >> A_rc;
      A[r][c] = mint::raw(A_rc);
    }
  }
  tools::matrix<mint> B(M, K);
  for (int r = 0; r < M; ++r) {
    for (int c = 0; c < K; ++c) {
      int B_rc;
      std::cin >> B_rc;
      B[r][c] = mint::raw(B_rc);
    }
  }

  const tools::matrix<mint> C = A * B;
  for (int r = 0; r < N; ++r) {
    for (int c = 0; c < K; ++c) {
      std::cout << C[r][c].val() << " \n"[c == K - 1];
    }
  }

  return 0;
}
