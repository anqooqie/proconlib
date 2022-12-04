#define PROBLEM "https://judge.yosupo.jp/problem/division_of_polynomials"

#include <iostream>
#include <cmath>
#include <string>
#include "atcoder/modint.hpp"
#include "tools/polynomial.hpp"

using mint = atcoder::modint998244353;
using ll = long long;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  ll N, M;
  std::cin >> N >> M;
  tools::polynomial<mint> f(N), g(M);
  for (auto& f_i : f) {
    ll x;
    std::cin >> x;
    f_i = mint::raw(x);
  }
  for (auto& g_i : g) {
    ll x;
    std::cin >> x;
    g_i = mint::raw(x);
  }

  const auto q = f / g;
  const auto r = f % g;

  std::cout << q.size() << ' ' << r.size() << '\n';
  std::string delimiter = "";
  for (const auto& q_i : q) {
    std::cout << delimiter << q_i.val();
    delimiter = " ";
  }
  std::cout << '\n';
  delimiter = "";
  for (const auto& r_i : r) {
    std::cout << delimiter << r_i.val();
    delimiter = " ";
  }
  std::cout << '\n';

  return 0;
}
