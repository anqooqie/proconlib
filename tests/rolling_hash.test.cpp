// competitive-verifier: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_14_B

#include <iostream>
#include <string>
#include "tools/rolling_hash.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  std::string T, P;
  std::cin >> T >> P;
  const int n = T.size();
  const int m = P.size();

  tools::rolling_hash T_hash(T), P_hash(P);
  for (int i = 0; i + m <= n; ++i) {
    if (T_hash.slice(i, i + m) == P_hash.slice(0, m)) {
      std::cout << i << '\n';
    }
  }

  return 0;
}
