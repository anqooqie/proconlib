#define PROBLEM "https://judge.yosupo.jp/problem/bitwise_and_convolution"

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include "atcoder/modint.hpp"
#include "tools/or_convolution.hpp"

using ll = long long;
using mint = atcoder::modint998244353;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  ll N;
  std::cin >> N;
  std::vector<mint> a(tools::pow2(N)), b(tools::pow2(N));
  for (auto& a_i : a) {
    ll a_i_ll;
    std::cin >> a_i_ll;
    a_i = mint::raw(a_i_ll);
  }
  for (auto& b_i : b) {
    ll b_i_ll;
    std::cin >> b_i_ll;
    b_i = mint::raw(b_i_ll);
  }

  std::vector<mint> c(tools::pow2(N));
  tools::or_convolution(a.rbegin(), a.rend(), b.rbegin(), b.rend(), c.rbegin(), c.rend());

  std::string delimiter = "";
  for (const auto& c_i : c) {
    std::cout << delimiter << c_i.val();
    delimiter = " ";
  }
  std::cout << '\n';

  return 0;
}
