#define PROBLEM "https://judge.yosupo.jp/problem/system_of_linear_equations"

#include <cstdint>
#include <iostream>
#include <string>
#include "atcoder/modint.hpp"
#include "tools/matrix.hpp"
#include "tools/vector.hpp"

using i64 = std::int_fast64_t;
using mint = atcoder::modint998244353;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  i64 N, M;
  std::cin >> N >> M;
  tools::matrix<mint> A(N, M);
  for (i64 r = 0; r < N; ++r) {
    for (i64 c = 0; c < M; ++c) {
      i64 A_rc;
      std::cin >> A_rc;
      A[r][c] = mint::raw(A_rc);
    }
  }
  tools::vector<mint> b(N);
  for (i64 i = 0; i < N; ++i) {
    i64 b_i;
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
  for (i64 i = 0; i < i64(C.rows()); ++i) {
    std::cout << delimiter << C[i][C.cols() - 1].val();
    delimiter = " ";
  }
  std::cout << '\n';
  for (i64 i = 0; i < i64(C.cols()) - 1; ++i) {
    delimiter = "";
    for (i64 j = 0; j < i64(C.rows()); ++j) {
      std::cout << delimiter << C[j][i].val();
      delimiter = " ";
    }
    std::cout << '\n';
  }

  return 0;
}
