// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/matrix_product_mod_2

#include <iostream>
#include "atcoder/modint.hpp"
#include "tools/matrix_mod2.hpp"

using mint = atcoder::static_modint<2>;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int N, M, K;
  std::cin >> N >> M >> K;
  tools::matrix<mint> A(N, M), B(M, K);
  std::cin >> A >> B;

  const auto C = A * B;
  for (int r = 0; r < N; ++r) {
    for (int c = 0; c < K; ++c) {
      std::cout << C[r][c].val();
    }
    std::cout << '\n';
  }

  return 0;
}
