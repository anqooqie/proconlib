// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/shift_of_sampling_points_of_polynomial

#include <iostream>
#include <ranges>
#include <utility>
#include <vector>
#include "atcoder/modint.hpp"
#include "tools/join.hpp"
#include "tools/sample_point_shift.hpp"

using mint = atcoder::modint998244353;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int N, M;
  std::cin >> N >> M;
  mint c;
  {
    int c_int;
    std::cin >> c_int;
    c = mint::raw(c_int);
  }
  std::vector<mint> f(N);
  for (int i = 0; i < N; ++i) {
    int f_i;
    std::cin >> f_i;
    f[i] = mint::raw(f_i);
  }

  std::cout << tools::join(tools::sample_point_shift(std::move(f), c, M) | std::views::transform(&mint::val), ' ') << '\n';

  return 0;
}
