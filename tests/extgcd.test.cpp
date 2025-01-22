// competitive-verifier: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/NTL_1_E

#include <iostream>
#include "tools/extgcd.hpp"

using ll = long long;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  ll a, b;
  std::cin >> a >> b;

  const auto [x0, y0, gcd] = tools::extgcd(a, b);
  std::cout << x0 << ' ' << y0 << '\n';

  return 0;
}
