#define PROBLEM "https://judge.yosupo.jp/problem/matrix_product"

#include <iostream>
#include <string>
#include "atcoder/modint.hpp"
#include "tools/matrix.hpp"

using ll = long long;
using mint = atcoder::modint998244353;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  ll N, M, K;
  std::cin >> N >> M >> K;
  tools::matrix<mint> A(N, M);
  for (ll r = 0; r < N; ++r) {
    for (ll c = 0; c < M; ++c) {
      ll A_rc;
      std::cin >> A_rc;
      A[r][c] = mint::raw(A_rc);
    }
  }
  tools::matrix<mint> B(M, K);
  for (ll r = 0; r < M; ++r) {
    for (ll c = 0; c < K; ++c) {
      ll B_rc;
      std::cin >> B_rc;
      B[r][c] = mint::raw(B_rc);
    }
  }

  const tools::matrix<mint> C = A * B;
  for (ll r = 0; r < N; ++r) {
    std::string delimiter = "";
    for (ll c = 0; c < K; ++c) {
      std::cout << delimiter << C[r][c].val();
      delimiter = " ";
    }
    std::cout << '\n';
  }

  return 0;
}
