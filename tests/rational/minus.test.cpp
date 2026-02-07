// competitive-verifier: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/NTL_2_B

#include <iostream>
#include "tools/rational.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  tools::rational A, B;
  std::cin >> A >> B;
  std::cout << (A - B).numerator() << '\n';
  return 0;
}
