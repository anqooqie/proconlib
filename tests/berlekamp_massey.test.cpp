// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/find_linear_recurrence

#include <iostream>
#include <string>
#include <cstddef>
#include "atcoder/modint.hpp"
#include "tools/polynomial.hpp"
#include "tools/berlekamp_massey.hpp"

using mint = atcoder::modint998244353;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int N;
  std::cin >> N;
  tools::polynomial<mint> a;
  a.reserve(N);
  for (int i = 0; i < N; ++i) {
    int a_i;
    std::cin >> a_i;
    a.push_back(mint::raw(a_i));
  }

  const auto c = tools::berlekamp_massey(a);

  std::cout << c.size() - 1 << '\n';
  std::string delimiter = "";
  for (std::size_t i = 1; i < c.size(); ++i) {
    std::cout << delimiter << (-c[i]).val();
    delimiter = " ";
  }
  std::cout << '\n';

  return 0;
}
