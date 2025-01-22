// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/many_factorials

#include <iostream>
#include "atcoder/modint.hpp"
#include "tools/large_fact_mod_cache.hpp"

using mint = atcoder::modint998244353;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int T;
  std::cin >> T;
  tools::large_fact_mod_cache<mint> cache;
  for (int t = 0; t < T; ++t) {
    int N;
    std::cin >> N;
    std::cout << cache.fact(N).val() << '\n';
  }

  return 0;
}
