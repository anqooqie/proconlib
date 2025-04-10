// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/kth_root_integer

#include <iostream>
#include "tools/floor_kth_root.hpp"

using ull = unsigned long long;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int T;
  std::cin >> T;
  for (int t = 0; t < T; ++t) {
    ull A;
    int K;
    std::cin >> A >> K;
    std::cout << tools::floor_kth_root(A, K) << '\n';
  }

  return 0;
}
