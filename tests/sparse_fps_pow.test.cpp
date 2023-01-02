#define PROBLEM "https://judge.yosupo.jp/problem/pow_of_formal_power_series_sparse"

#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include "atcoder/modint.hpp"
#include "tools/sparse_fps_pow.hpp"

using ll = long long;
using mint = atcoder::modint998244353;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  ll N, K, M;
  std::cin >> N >> K >> M;
  std::vector<std::pair<int, mint>> a;
  a.reserve(K);
  for (ll k = 0; k < K; ++k) {
    ll i, a_i;
    std::cin >> i >> a_i;
    a.emplace_back(i, mint::raw(a_i));
  }

  const auto b = tools::sparse_fps_pow(a.begin(), a.end(), M, N);

  std::string delimiter = "";
  for (const mint& b_i : b) {
    std::cout << delimiter << b_i.val();
    delimiter = " ";
  }
  std::cout << '\n';

  return 0;
}
