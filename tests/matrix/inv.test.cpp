// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/inverse_matrix

#include <iostream>
#include "atcoder/modint.hpp"
#include "tools/matrix.hpp"

using mint = atcoder::modint998244353;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int N;
  std::cin >> N;
  tools::matrix<mint> A(N, N);
  for (int r = 0; r < N; ++r) {
    for (int c = 0; c < N; ++c) {
      int A_rc;
      std::cin >> A_rc;
      A[r][c] = mint::raw(A_rc);
    }
  }

  if (const auto B = A.inv(); B) {
    for (int r = 0; r < N; ++r) {
      for (int c = 0; c < N; ++c) {
        std::cout << (*B)[r][c].val() << " \n"[c == N - 1];
      }
    }
  } else {
    std::cout << -1 << '\n';
  }

  return 0;
}
