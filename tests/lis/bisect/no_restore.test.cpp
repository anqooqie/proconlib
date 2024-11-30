#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DPL_1_D"

#include <iostream>
#include <vector>
#include "tools/lis.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (auto&& a_i : a) std::cin >> a_i;

  std::cout << tools::lis::bisect<true>(a.begin(), a.end()) << '\n';
  return 0;
}
