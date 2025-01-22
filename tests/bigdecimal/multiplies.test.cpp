// competitive-verifier: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/NTL_2_F

#include <iostream>
#include "tools/bigdecimal.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  tools::bigdecimal A, B;
  std::cin >> A >> B;
  std::cout << A * B << '\n';
  return 0;
}
