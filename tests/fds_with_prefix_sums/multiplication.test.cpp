// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/dirichlet_convolution_and_prefix_sums

#include <iostream>
#include <iterator>
#include <ranges>
#include <vector>
#include "atcoder/modint.hpp"
#include "tools/fds_with_prefix_sums.hpp"
#include "tools/floor_sqrt.hpp"
#include "tools/join.hpp"

using mint = atcoder::modint998244353;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int T;
  std::cin >> T;
  for (int t = 0; t < T; ++t) {
    long long N;
    std::cin >> N;
    const auto sqrt_N = tools::floor_sqrt(N);
    std::vector<mint> f(2 * sqrt_N - (N < sqrt_N * (sqrt_N + 1)));
    for (int i = 0; i < std::ssize(f); ++i) {
      int v;
      std::cin >> v;
      f[i] = mint::raw(v);
    }
    std::vector<mint> g(2 * sqrt_N - (N < sqrt_N * (sqrt_N + 1)));
    for (int i = 0; i < std::ssize(g); ++i) {
      int v;
      std::cin >> v;
      g[i] = mint::raw(v);
    }
    std::cout << tools::join(
      (tools::fds_with_prefix_sums<mint>(N, f) * tools::fds_with_prefix_sums<mint>(N, g)) |
        std::views::transform([](const mint x) { return x.val(); }),
      ' '
    ) << '\n';
  }

  return 0;
}
