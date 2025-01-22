// competitive-verifier: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/DPL_5_G

#include <iostream>
#include "atcoder/modint.hpp"
#include "tools/bell.hpp"

using mint = atcoder::modint1000000007;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int n, k;
  std::cin >> n >> k;
  std::cout << tools::bell::all<mint>(n, k)[n][k].val() << '\n';

  return 0;
}
