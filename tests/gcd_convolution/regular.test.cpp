// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/gcd_convolution

#include <iostream>
#include <vector>
#include <string>
#include "atcoder/modint.hpp"
#include "tools/gcd_convolution.hpp"

using ll = long long;
using mint = atcoder::modint998244353;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  ll N;
  std::cin >> N;
  std::vector<mint> a(N + 1), b(N + 1);
  for (ll i = 1; i <= N; ++i) {
    ll a_i;
    std::cin >> a_i;
    a[i] = mint::raw(a_i);
  }
  for (ll i = 1; i <= N; ++i) {
    ll b_i;
    std::cin >> b_i;
    b[i] = mint::raw(b_i);
  }

  std::vector<mint> c(N + 1);
  tools::gcd_convolution(a.begin(), a.end(), b.begin(), b.end(), c.begin(), c.end());

  std::string delimiter = "";
  for (ll i = 1; i <= N; ++i) {
    std::cout << delimiter << c[i].val();
    delimiter = " ";
  }
  std::cout << '\n';

  return 0;
}
