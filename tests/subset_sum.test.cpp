// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/sharp_p_subset_sum

#include <iostream>
#include <ranges>
#include <vector>
#include "atcoder/modint.hpp"
#include "tools/join.hpp"
#include "tools/subset_sum.hpp"

using mint = atcoder::modint998244353;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int N, T;
  std::cin >> N >> T;
  std::vector<int> s(N);
  for (auto& s_i : s) std::cin >> s_i;

  const auto p = tools::subset_sum<mint>(s, T);

  std::cout << tools::join(p | std::views::drop(1) | std::views::transform(&mint::val), ' ') << '\n';

  return 0;
}
