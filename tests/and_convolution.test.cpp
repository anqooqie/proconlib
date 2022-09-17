#define PROBLEM "https://judge.yosupo.jp/problem/bitwise_and_convolution"

#include <cstdint>
#include <iostream>
#include <vector>
#include <string>
#include "atcoder/modint.hpp"
#include "tools/and_convolution.hpp"

using i64 = std::int_fast64_t;
using mint = atcoder::modint998244353;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  i64 N;
  std::cin >> N;
  std::vector<mint> a(tools::pow2(N)), b(tools::pow2(N));
  for (auto& a_i : a) {
    i64 a_i_i64;
    std::cin >> a_i_i64;
    a_i = mint::raw(a_i_i64);
  }
  for (auto& b_i : b) {
    i64 b_i_i64;
    std::cin >> b_i_i64;
    b_i = mint::raw(b_i_i64);
  }

  std::vector<mint> c(tools::pow2(N));
  tools::and_convolution(a.begin(), a.end(), b.begin(), b.end(), c.begin(), c.end());

  std::string delimiter = "";
  for (const auto& c_i : c) {
    std::cout << delimiter << c_i.val();
    delimiter = " ";
  }
  std::cout << '\n';

  return 0;
}
