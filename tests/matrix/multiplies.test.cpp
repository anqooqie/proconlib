#define PROBLEM "https://judge.yosupo.jp/problem/matrix_product"

#include <cstdint>
#include <iostream>
#include <string>
#include "atcoder/modint.hpp"
#include "tools/matrix.hpp"

using i64 = std::int_fast64_t;
using mint = atcoder::modint998244353;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  i64 N, M, K;
  std::cin >> N >> M >> K;
  tools::matrix<mint> A(N, M);
  for (i64 r = 0; r < N; ++r) {
    for (i64 c = 0; c < M; ++c) {
      i64 A_rc;
      std::cin >> A_rc;
      A[r][c] = mint::raw(A_rc);
    }
  }
  tools::matrix<mint> B(M, K);
  for (i64 r = 0; r < M; ++r) {
    for (i64 c = 0; c < K; ++c) {
      i64 B_rc;
      std::cin >> B_rc;
      B[r][c] = mint::raw(B_rc);
    }
  }

  const tools::matrix<mint> C = A * B;
  for (i64 r = 0; r < N; ++r) {
    std::string delimiter = "";
    for (i64 c = 0; c < K; ++c) {
      std::cout << delimiter << C[r][c].val();
      delimiter = " ";
    }
    std::cout << '\n';
  }

  return 0;
}
