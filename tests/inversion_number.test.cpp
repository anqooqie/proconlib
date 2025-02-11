// competitive-verifier: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_5_D

#include <iostream>
#include <vector>
#include "tools/inversion_number.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (auto& a_i : a) std::cin >> a_i;
  std::cout << tools::inversion_number(a) << '\n';
  return 0;
}
