// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/bernoulli_number

#include <iostream>
#include <string>
#include "atcoder/modint.hpp"
#include "tools/bernoulli.hpp"

using mint = atcoder::modint998244353;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int N;
  std::cin >> N;

  std::string delimiter = "";
  for (const auto b : tools::bernoulli<mint>(N)) {
    std::cout << delimiter << b.val();
    delimiter = " ";
  }
  std::cout << '\n';

  return 0;
}
