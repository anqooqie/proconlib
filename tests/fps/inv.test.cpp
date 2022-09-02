#define PROBLEM "https://judge.yosupo.jp/problem/inv_of_formal_power_series"

#include <cstdint>
#include <iostream>
#include <string>
#include "atcoder/modint.hpp"
#include "tools/fps.hpp"

using i64 = std::int_fast64_t;
using mint = atcoder::modint998244353;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  i64 N;
  std::cin >> N;
  tools::fps<mint> a;
  a.reserve(N);
  for (i64 i = 0; i < N; ++i) {
    i64 a_i;
    std::cin >> a_i;
    a.emplace_back(a_i);
  }

  const auto b = a.inv();

  std::string delimiter = "";
  for (const mint& b_i : b) {
    std::cout << delimiter << b_i.val();
    delimiter = " ";
  }
  std::cout << '\n';

  return 0;
}
