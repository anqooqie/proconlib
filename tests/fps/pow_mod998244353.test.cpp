#define PROBLEM "https://judge.yosupo.jp/problem/pow_of_formal_power_series"

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

  i64 N, M;
  std::cin >> N >> M;
  tools::fps<mint> a;
  a.reserve(N);
  for (i64 i = 0; i < N; ++i) {
    i64 a_i;
    std::cin >> a_i;
    a.emplace_back(a_i);
  }

  a.pow_inplace(M);

  std::string delimiter = "";
  for (const mint& a_i : a) {
    std::cout << delimiter << a_i.val();
    delimiter = " ";
  }
  std::cout << '\n';

  return 0;
}
