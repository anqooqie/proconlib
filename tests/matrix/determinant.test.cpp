#define PROBLEM "https://judge.yosupo.jp/problem/matrix_det"

#include <cstdint>
#include <iostream>
#include "atcoder/modint.hpp"
#include "tools/matrix.hpp"

using i64 = std::int_fast64_t;
using mint = atcoder::modint998244353;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  i64 N;
  std::cin >> N;
  tools::matrix<mint> A(N, N);
  for (i64 r = 0; r < N; ++r) {
    for (i64 c = 0; c < N; ++c) {
      i64 A_rc;
      std::cin >> A_rc;
      A[r][c] = mint::raw(A_rc);
    }
  }

  std::cout << A.determinant().val() << '\n';
  return 0;
}
