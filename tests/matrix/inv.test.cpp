// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/inverse_matrix

#include <iostream>
#include <string>
#include "atcoder/modint.hpp"
#include "tools/matrix.hpp"

using ll = long long;
using mint = atcoder::modint998244353;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  ll N;
  std::cin >> N;
  tools::matrix<mint> A(N, N);
  for (ll r = 0; r < N; ++r) {
    for (ll c = 0; c < N; ++c) {
      ll A_rc;
      std::cin >> A_rc;
      A[r][c] = mint::raw(A_rc);
    }
  }

  const auto B = A.inv();
  if (!B) {
    std::cout << -1 << '\n';
    return 0;
  }

  ::tools::matrix<mint> AI(N, N * 2);
  for (ll r = 0; r < N; ++r) {
    for (ll c = 0; c < N; ++c) {
      AI[r][c] = A[r][c];
    }
    for (ll c = N; c < N * 2; ++c) {
      AI[r][c] = mint(0);
    }
    AI[r][N + r] = mint(1);
  }
  AI.gauss_jordan();

  for (ll r = 0; r < N; ++r) {
    std::string delimiter = "";
    for (ll c = 0; c < N; ++c) {
      std::cout << delimiter << (*B)[r][c].val();
      delimiter = " ";
    }
    std::cout << '\n';
  }

  return 0;
}
