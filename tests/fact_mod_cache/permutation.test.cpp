#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DPL_5_B"

#include <iostream>
#include "atcoder/modint.hpp"
#include "tools/fact_mod_cache.hpp"

using ll = long long;
using mint = atcoder::modint1000000007;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  ll n, k;
  std::cin >> n >> k;
  tools::fact_mod_cache<mint> cache;
  std::cout << cache.permutation(k, n).val() << '\n';
  return 0;
}