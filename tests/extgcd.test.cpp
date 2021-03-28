#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/NTL_1_E"

#include <cstdint>
#include <iostream>
#include "tools/extgcd.hpp"

using i64 = std::int_fast64_t;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  i64 a, b;
  std::cin >> a >> b;

  const auto [x0, y0, gcd] = tools::extgcd(a, b);
  std::cout << x0 << ' ' << y0 << '\n';

  return 0;
}
