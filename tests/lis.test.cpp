#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DPL_1_D"

#include <cstdint>
#include <iostream>
#include <vector>
#include "tools/lis.hpp"

using i64 = std::int_fast64_t;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  i64 n;
  std::cin >> n;
  std::vector<i64> a(n);
  for (i64& a_i : a) std::cin >> a_i;
  std::cout << tools::lis(a.begin(), a.end(), true) << '\n';

  return 0;
}
