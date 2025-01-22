// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/division_of_big_integers

#include <iostream>
#include "tools/bigint.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int T;
  std::cin >> T;
  for (int t = 0; t < T; ++t) {
    tools::bigint A, B;
    std::cin >> A >> B;
    const auto [Q, R] = A.divmod(B);
    std::cout << Q << ' ' << R << '\n';
  }
  return 0;
}
