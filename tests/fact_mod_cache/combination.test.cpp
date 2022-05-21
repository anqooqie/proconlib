#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DPL_5_E"

#include <cstdint>
#include <iostream>
#include "atcoder/modint.hpp"
#include "tools/fact_mod_cache.hpp"

using i64 = std::int_fast64_t;
using mint = atcoder::modint1000000007;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  i64 n, k;
  std::cin >> n >> k;
  tools::fact_mod_cache<mint> cache;
  std::cout << cache.combination(k, n).val() << '\n';
  return 0;
}
