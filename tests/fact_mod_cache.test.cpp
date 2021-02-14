#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_D"

#include <cstdint>
#include <iostream>
#include "atcoder/modint.hpp"
#include "tools/fact_mod_cache.hpp"

using i64 = std::int_fast64_t;
using mint = atcoder::modint1000000007;

int main() {
  i64 n, k;
  std::cin >> n >> k;
  tools::fact_mod_cache<mint> cache(n + k - 1);
  std::cout << cache.combination(n + k - 1, n).val() << '\n';
  return 0;
}
