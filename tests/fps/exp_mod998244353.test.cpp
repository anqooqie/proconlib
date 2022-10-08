#define PROBLEM "https://judge.yosupo.jp/problem/exp_of_formal_power_series"

#include <iostream>
#include <string>
#include "atcoder/modint.hpp"
#include "tools/fps.hpp"

using ll = long long;
using mint = atcoder::modint998244353;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  ll N;
  std::cin >> N;
  tools::fps<mint> a;
  a.reserve(N);
  for (ll i = 0; i < N; ++i) {
    ll a_i;
    std::cin >> a_i;
    a.emplace_back(a_i);
  }

  a.exp_inplace();

  std::string delimiter = "";
  for (const mint& a_i : a) {
    std::cout << delimiter << a_i.val();
    delimiter = " ";
  }
  std::cout << '\n';

  return 0;
}
