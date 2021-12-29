#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod_1000000007"

#include <iostream>
#include <cstdint>
#include <vector>
#include <string>
#include "atcoder/modint.hpp"
#include "tools/convolution.hpp"

using i64 = std::int_fast64_t;
using mint = atcoder::modint1000000007;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  i64 N, M;
  std::cin >> N >> M;
  std::vector<mint> a, b;
  a.reserve(N);
  b.reserve(M);
  for (i64 i = 0; i < N; ++i) {
    i64 a_i;
    std::cin >> a_i;
    a.emplace_back(a_i);
  }
  for (i64 i = 0; i < M; ++i) {
    i64 b_i;
    std::cin >> b_i;
    b.emplace_back(b_i);
  }

  std::vector<mint> c;
  tools::convolution(a.begin(), a.end(), b.begin(), b.end(), std::back_inserter(c));

  std::string delimiter = "";
  for (const mint& c_i : c) {
    std::cout << delimiter << c_i.val();
    delimiter = " ";
  }
  std::cout << '\n';

  return 0;
}
