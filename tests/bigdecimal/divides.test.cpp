#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/NTL_2_D"

#include <iostream>
#include "tools/bigdecimal.hpp"
#include "tools/rounding_mode.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  tools::bigdecimal A, B;
  std::cin >> A >> B;
  std::cout << A.divide_and_copy(B, 0, tools::rounding_mode::down) << '\n';
  return 0;
}
