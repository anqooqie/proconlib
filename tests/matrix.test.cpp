#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ITP1_7_D"

#include <cstdint>
#include <iostream>
#include "tools/matrix.hpp"

using i64 = std::int_fast64_t;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  i64 n, m, l;
  std::cin >> n >> m >> l;

  tools::matrix<i64> A(n, m), B(m, l);
  std::cin >> A >> B;

  const tools::matrix<i64> C = A * B;
  for (i64 r = 0; r < n; ++r) {
    std::string delimiter = "";
    for (i64 c = 0; c < l; ++c) {
      std::cout << delimiter << C[r][c];
      delimiter = " ";
    }
    std::cout << '\n';
  }

  return 0;
}
