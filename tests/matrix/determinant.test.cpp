// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/matrix_det

#include <iostream>
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

  std::cout << A.determinant().val() << '\n';
  return 0;
}
