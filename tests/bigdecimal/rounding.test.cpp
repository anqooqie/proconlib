// competitive-verifier: PROBLEM https://atcoder.jp/contests/abc273/tasks/abc273_b
// competitive-verifier: IGNORE

#include <iostream>
#include "tools/bigdecimal.hpp"
#include "tools/rounding_mode.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  tools::bigdecimal X;
  int K;
  std::cin >> X >> K;

  for (int k = 0; k < K; ++k) {
    X.divide_inplace(tools::bigdecimal(1), -k - 1, tools::rounding_mode::half_up);
  }

  std::cout << X << '\n';
  return 0;
}
