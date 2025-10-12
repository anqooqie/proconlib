#define PROBLEM "https://judge.yosupo.jp/problem/multivariate_convolution"

#include <functional>
#include <iostream>
#include <numeric>
#include <ranges>
#include <vector>
#include "atcoder/modint.hpp"
#include "tools/join.hpp"
#include "tools/multivariate_convolution.hpp"

using mint = atcoder::modint998244353;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int K;
  std::cin >> K;
  std::vector<int> N(K);
  for (auto&& N_i : N) std::cin >> N_i;

  std::vector<mint> f(std::accumulate(N.begin(), N.end(), 1, std::multiplies<int>{}));
  for (auto&& f_i : f) {
    int v;
    std::cin >> v;
    f_i = mint::raw(v);
  }

  std::vector<mint> g(f.size());
  for (auto&& g_i : g) {
    int v;
    std::cin >> v;
    g_i = mint::raw(v);
  }

  const auto h = tools::multivariate_convolution(f, g, N);
  std::cout << tools::join(h | std::views::transform([](const auto& h_i) { return h_i.val(); }), ' ') << '\n';
  return 0;
}
