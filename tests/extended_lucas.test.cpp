#define PROBLEM "https://judge.yosupo.jp/problem/binomial_coefficient"

#include <cstdint>
#include <iostream>
#include "atcoder/modint.hpp"
#include "tools/extended_lucas.hpp"

using mint = atcoder::modint;
using i64 = std::int_fast64_t;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  i64 T, m;
  std::cin >> T >> m;
  mint::set_mod(m);
  tools::extended_lucas<mint> cache;

  for (i64 i = 0; i < T; ++i) {
    i64 n, k;
    std::cin >> n >> k;
    std::cout << cache.combination(n, k).val() << '\n';
  }
  return 0;
}
