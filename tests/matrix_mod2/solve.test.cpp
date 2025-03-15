// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/system_of_linear_equations_mod_2

#include <iostream>
#include <string>
#include "atcoder/modint.hpp"
#include "tools/matrix_mod2.hpp"
#include "tools/vector.hpp"

using mint = atcoder::static_modint<2>;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int N, M;
  std::cin >> N >> M;
  tools::matrix<mint> A(N, M);
  std::cin >> A;
  tools::vector<mint> b(N);
  {
    std::string s;
    std::cin >> s;
    for (int i = 0; i < N; ++i) {
      b[i] = mint::raw(s[i] - '0');
    }
  }

  const auto C = A.solve(b);
  if (C.cols() == 0) {
    std::cout << -1 << '\n';
    return 0;
  }

  std::cout << C.cols() - 1 << '\n';
  for (int i = 0; i < C.rows(); ++i) {
    std::cout << C[i][C.cols() - 1].val();
  }
  std::cout << '\n';
  for (int i = 0; i < C.cols() - 1; ++i) {
    for (int j = 0; j < C.rows(); ++j) {
      std::cout << C[j][i].val();
    }
    std::cout << '\n';
  }

  return 0;
}
