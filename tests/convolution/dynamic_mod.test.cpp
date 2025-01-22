// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/convolution_mod

#include <iostream>
#include <vector>
#include <string>
#include "atcoder/modint.hpp"
#include "tools/convolution.hpp"

using ll = long long;
using mint = atcoder::modint;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  mint::set_mod(998244353);

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

  std::vector<mint> c;
  tools::convolution(a.begin(), a.end(), b.begin(), b.end(), std::back_inserter(c));

  std::string delimiter = "";
  for (const mint& c_i : c) {
    std::cout << delimiter << c_i.val();
    delimiter = " ";
  }
  std::cout << '\n';

  return 0;
}
