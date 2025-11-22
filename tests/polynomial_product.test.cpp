// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/product_of_polynomial_sequence

#include <iostream>
#include <ranges>
#include <string>
#include <vector>
#include "atcoder/modint.hpp"
#include "tools/join.hpp"
#include "tools/polynomial.hpp"
#include "tools/polynomial_product.hpp"

using mint = atcoder::modint998244353;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int N;
  std::cin >> N;

  std::vector<tools::polynomial<mint>> f(N);
  int D = 0;
  for (int i = 0; i < N; ++i) {
    int d;
    std::cin >> d;
    f[i].reserve(d + 1);
    for (int j = 0; j <= d; ++j) {
      int a;
      std::cin >> a;
      f[i].push_back(mint::raw(a));
    }
    D += d;
  }

  const auto answer = tools::polynomial_product(f);
  std::cout << tools::join(std::views::counted(answer.pbegin(), D + 1) | std::views::transform(&mint::val), ' ') << '\n';

  return 0;
}
