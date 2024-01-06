#define PROBLEM "https://judge.yosupo.jp/problem/compositional_inverse_of_formal_power_series"

#include <iostream>
#include "atcoder/modint.hpp"
#include "tools/fps.hpp"

using mint = atcoder::modint998244353;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int N;
  std::cin >> N;

  tools::fps<mint> a;
  for (int i = 0; i < N; ++i) {
    int a_i;
    std::cin >> a_i;
    a.emplace_back(a_i);
  }

  const auto b = a.compositional_inverse();
  std::cout << b[0].val();
  for (int i = 1; i < N; ++i) {
    std::cout << ' ' << b[i].val();
  }
  std::cout << '\n';

  return 0;
}
