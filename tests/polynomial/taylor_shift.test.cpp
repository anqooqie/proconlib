// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/polynomial_taylor_shift

#include <iostream>
#include "atcoder/modint.hpp"
#include "tools/polynomial.hpp"

using mint = atcoder::modint998244353;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int N, c;
  std::cin >> N >> c;
  tools::polynomial<mint> a;
  for (int i = 0; i < N; ++i) {
    int a_i;
    std::cin >> a_i;
    a.push_back(mint::raw(a_i));
  }

  const auto b = a(tools::polynomial<mint>{mint::raw(c), mint::raw(1)});
  std::cout << b.pbegin()[0].val();
  for (int i = 1; i < N; ++i) {
    std::cout << ' ' << b.pbegin()[i].val();
  }
  std::cout << '\n';

  return 0;
}
