// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/bitwise_xor_convolution

#include <iostream>
#include <ranges>
#include <vector>
#include "atcoder/modint.hpp"
#include "tools/join.hpp"
#include "tools/pow2.hpp"
#include "tools/xor_convolution.hpp"

using mint = atcoder::modint998244353;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int N;
  std::cin >> N;
  std::vector<mint> a(tools::pow2(N)), b(tools::pow2(N));
  for (auto& a_i : a) {
    int a_i_int;
    std::cin >> a_i_int;
    a_i = mint::raw(a_i_int);
  }
  for (auto& b_i : b) {
    int b_i_int;
    std::cin >> b_i_int;
    b_i = mint::raw(b_i_int);
  }

  std::cout << tools::join(tools::xor_convolution(a, b) | std::views::transform(&mint::val), ' ') << '\n';
  return 0;
}
