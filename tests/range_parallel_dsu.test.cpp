// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/range_parallel_unionfind

#include <iostream>
#include <utility>
#include <vector>
#include "atcoder/modint.hpp"
#include "tools/range_parallel_dsu.hpp"
#include "tools/square.hpp"

using mint = atcoder::modint998244353;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int N, Q;
  std::cin >> N >> Q;
  std::vector<std::pair<mint, mint>> x(N);
  for (int i = 0; i < N; ++i) {
    int x_i;
    std::cin >> x_i;
    x[i] = {mint::raw(x_i), tools::square(mint::raw(x_i))};
  }

  const auto two_inv = mint::raw(2).inv();
  tools::range_parallel_dsu dsu(N);
  auto answer = mint::raw(0);
  for (int q = 0; q < Q; ++q) {
    int k, a, b;
    std::cin >> k >> a >> b;
    for (const auto& [r1, r2] : dsu.merge(a, b, k)) {
      answer -= (tools::square(x[r1].first) - x[r1].second) * two_inv;
      answer -= (tools::square(x[r2].first) - x[r2].second) * two_inv;
      x[r1].first += x[r2].first;
      x[r1].second += x[r2].second;
      x[r2] = {mint::raw(0), mint::raw(0)};
      answer += (tools::square(x[r1].first) - x[r1].second) * two_inv;
    }
    std::cout << answer.val() << '\n';
  }

  return 0;
}
