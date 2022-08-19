#define PROBLEM "https://judge.yosupo.jp/problem/find_linear_recurrence"

#include <cstdint>
#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include "atcoder/modint.hpp"
#include "tools/barlekamp_massey.hpp"

using mint = atcoder::modint998244353;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int N;
  std::cin >> N;
  std::vector<mint> a;
  a.reserve(N);
  for (int i = 0; i < N; ++i) {
    int a_i;
    std::cin >> a_i;
    a.push_back(mint::raw(a_i));
  }

  std::vector<mint> c;
  tools::barlekamp_massey(a.begin(), a.end(), std::back_inserter(c));

  std::cout << c.size() - 1 << '\n';
  std::string delimiter = "";
  for (std::size_t i = 1; i < c.size(); ++i) {
    std::cout << delimiter << (-c[i]).val();
    delimiter = " ";
  }
  std::cout << '\n';

  return 0;
}
