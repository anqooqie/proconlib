#define PROBLEM "https://judge.yosupo.jp/problem/lcm_convolution"

#include <iostream>
#include <cstdint>
#include <vector>
#include <string>
#include "atcoder/modint.hpp"
#include "tools/lcm_convolution.hpp"

using i64 = std::int_fast64_t;
using mint = atcoder::modint998244353;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  i64 N;
  std::cin >> N;
  std::vector<mint> a(N + 1), b(N + 1);
  for (i64 i = 1; i <= N; ++i) {
    i64 a_i;
    std::cin >> a_i;
    a[i] = mint::raw(a_i);
  }
  for (i64 i = 1; i <= N; ++i) {
    i64 b_i;
    std::cin >> b_i;
    b[i] = mint::raw(b_i);
  }

  std::vector<mint> c(N + 1);
  tools::lcm_convolution(a.begin(), a.end(), b.begin(), b.end(), c.begin(), c.end());

  std::string delimiter = "";
  for (i64 i = 1; i <= N; ++i) {
    std::cout << delimiter << c[i].val();
    delimiter = " ";
  }
  std::cout << '\n';

  return 0;
}
