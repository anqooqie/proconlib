// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/matrix_rank_mod_2

#include <iostream>
#include "atcoder/modint.hpp"
#include "tools/matrix_mod2.hpp"

using mint = atcoder::static_modint<2>;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int N, M;
  std::cin >> N >> M;
  tools::matrix<mint> A(N, M);
  std::cin >> A;

  std::cout << A.rank() << '\n';
  return 0;
}
