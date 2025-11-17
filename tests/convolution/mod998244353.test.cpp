// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/convolution_mod

#include <iostream>
#include <vector>
#include "atcoder/modint.hpp"
#include "tools/convolution.hpp"
#include "tools/join.hpp"

using ll = long long;
using mint = atcoder::modint998244353;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  ll N, M;
  std::cin >> N >> M;
  std::vector<mint> a, b;
  a.reserve(N);
  b.reserve(M);
  for (ll i = 0; i < N; ++i) {
    ll a_i;
    std::cin >> a_i;
    a.emplace_back(a_i);
  }
  for (ll i = 0; i < M; ++i) {
    ll b_i;
    std::cin >> b_i;
    b.emplace_back(b_i);
  }

  std::cout << tools::join(tools::convolution(a, b) | std::views::transform(&mint::val), ' ') << '\n';

  return 0;
}
