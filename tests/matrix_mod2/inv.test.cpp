// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/inverse_matrix_mod_2

#include <iostream>
#include "atcoder/modint.hpp"
#include "tools/matrix_mod2.hpp"

using mint = atcoder::static_modint<2>;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int N;
  std::cin >> N;
  tools::matrix<mint> A(N, N);
  std::cin >> A;

  if (const auto B = A.inv(); B) {
    for (int r = 0; r < N; ++r) {
      for (int c = 0; c < N; ++c) {
        std::cout << (*B)[r][c].val();
      }
      std::cout << '\n';
    }
  } else {
    std::cout << -1 << '\n';
  }

  return 0;
}
