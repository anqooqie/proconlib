#define PROBLEM "https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence"

#include <iostream>
#include <vector>
#include "atcoder/modint.hpp"
#include "tools/nth_term.hpp"

using ll = long long;
using mint = atcoder::modint998244353;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  ll d, k;
  std::cin >> d >> k;
  std::vector<mint> a;
  a.reserve(d);
  for (ll i = 0; i < d; ++i) {
    ll a_i;
    std::cin >> a_i;
    a.push_back(mint::raw(a_i));
  }
  std::vector<mint> c({mint::raw(1)});
  c.reserve(d + 1);
  for (ll i = 1; i <= d; ++i) {
    ll c_i;
    std::cin >> c_i;
    c.emplace_back(-c_i);
  }

  std::cout << tools::nth_term(a.begin(), a.end(), c.begin(), c.end(), k).val() << '\n';
  return 0;
}