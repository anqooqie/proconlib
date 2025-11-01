// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/subset_convolution

#include <iostream>
#include <ranges>
#include <utility>
#include <vector>
#include "atcoder/modint.hpp"
#include "tools/join.hpp"
#include "tools/pow2.hpp"
#include "tools/subset_convolution.hpp"

using mint = atcoder::modint998244353;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int N;
  std::cin >> N;
  std::vector<mint> a, b;
  a.reserve(tools::pow2(N));
  b.reserve(tools::pow2(N));
  for (int i = 0; i < tools::pow2(N); ++i) {
    int v;
    std::cin >> v;
    a.push_back(mint::raw(v));
  }
  for (int i = 0; i < tools::pow2(N); ++i) {
    int v;
    std::cin >> v;
    b.push_back(mint::raw(v));
  }

  std::cout << tools::join(tools::subset_convolution(std::move(a), std::move(b)) | std::views::transform(&mint::val), ' ') << '\n';
  return 0;
}
