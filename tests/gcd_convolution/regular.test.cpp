// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/gcd_convolution

#include <iostream>
#include <ranges>
#include <vector>
#include "atcoder/modint.hpp"
#include "tools/gcd_convolution.hpp"
#include "tools/join.hpp"

using mint = atcoder::modint998244353;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int N;
  std::cin >> N;
  std::vector<mint> a(N + 1), b(N + 1);
  for (int i = 1; i <= N; ++i) {
    int a_i;
    std::cin >> a_i;
    a[i] = mint::raw(a_i);
  }
  for (int i = 1; i <= N; ++i) {
    int b_i;
    std::cin >> b_i;
    b[i] = mint::raw(b_i);
  }

  std::cout << tools::join(tools::gcd_convolution(a, b) | std::views::drop(1) | std::views::transform(&mint::val), ' ') << '\n';
  return 0;
}
