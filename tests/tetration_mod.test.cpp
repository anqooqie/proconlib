#define PROBLEM "https://judge.yosupo.jp/problem/tetration_mod"

#include <cstdint>
#include <iostream>
#include "tools/tetration_mod.hpp"

using i64 = std::int_fast64_t;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  i64 T;
  std::cin >> T;
  for (i64 i = 0; i < T; ++i) {
    i64 A, B, M;
    std::cin >> A >> B >> M;
    std::cout << tools::tetration_mod(A, B, M) << '\n';
  }
  return 0;
}
