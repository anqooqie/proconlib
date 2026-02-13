// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/inv_of_polynomials

#include <iostream>
#include <ranges>
#include "atcoder/modint.hpp"
#include "tools/extgcd.hpp"
#include "tools/join.hpp"
#include "tools/polynomial.hpp"

using mint = atcoder::modint998244353;
using P = tools::polynomial<mint>;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int N, M;
  std::cin >> N >> M;
  P f(N), g(M);
  for (auto& f_i : f) {
    int x;
    std::cin >> x;
    f_i = mint::raw(x);
  }
  for (auto& g_i : g) {
    int x;
    std::cin >> x;
    g_i = mint::raw(x);
  }

  auto [h, q, gcd] = tools::extgcd(f, g);

  if (gcd.size() != 1) {
    std::cout << -1 << '\n';
  } else {
    std::cout << h.size() << '\n';
    if (!h.empty()) {
      std::cout << tools::join(h | std::views::transform(&mint::val), ' ') << '\n';
    }
  }

  return 0;
}
