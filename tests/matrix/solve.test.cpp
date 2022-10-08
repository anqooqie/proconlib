#define PROBLEM "https://judge.yosupo.jp/problem/system_of_linear_equations"

#include <iostream>
#include <string>
#include "atcoder/modint.hpp"
#include "tools/matrix.hpp"
#include "tools/vector.hpp"

using ll = long long;
using mint = atcoder::modint998244353;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  ll N, M;
  std::cin >> N >> M;
  tools::matrix<mint> A(N, M);
  for (ll r = 0; r < N; ++r) {
    for (ll c = 0; c < M; ++c) {
      ll A_rc;
      std::cin >> A_rc;
      A[r][c] = mint::raw(A_rc);
    }
  }
  tools::vector<mint> b(N);
  for (ll i = 0; i < N; ++i) {
    ll b_i;
    std::cin >> b_i;
    b[i] = mint::raw(b_i);
  }

  const tools::matrix<mint> C = A.solve(b);
  if (C.cols() == 0) {
    std::cout << -1 << '\n';
    return 0;
  }

  std::cout << C.cols() - 1 << '\n';
  std::string delimiter = "";
  for (ll i = 0; i < ll(C.rows()); ++i) {
    std::cout << delimiter << C[i][C.cols() - 1].val();
    delimiter = " ";
  }
  std::cout << '\n';
  for (ll i = 0; i < ll(C.cols()) - 1; ++i) {
    delimiter = "";
    for (ll j = 0; j < ll(C.rows()); ++j) {
      std::cout << delimiter << C[j][i].val();
      delimiter = " ";
    }
    std::cout << '\n';
  }

  return 0;
}
