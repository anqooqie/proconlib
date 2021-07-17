#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/NTL_1_D"

#include <cstdint>
#include <iostream>
#include "tools/totient.hpp"

using i64 = std::int_fast64_t;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  i64 n;
  std::cin >> n;
  std::cout << tools::totient(n) << '\n';
  return 0;
}
