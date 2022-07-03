#define PROBLEM "https://judge.yosupo.jp/problem/kth_root_integer"

#include <cstdint>
#include <iostream>
#include "tools/floor_kth_root.hpp"

using u64 = std::uint_fast64_t;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int T;
  std::cin >> T;
  for (int t = 0; t < T; ++t) {
    u64 A;
    int K;
    std::cin >> A >> K;
    std::cout << tools::floor_kth_root(A, K) << '\n';
  }

  return 0;
}
