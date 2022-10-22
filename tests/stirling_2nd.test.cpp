#define PROBLEM "https://judge.yosupo.jp/problem/stirling_number_of_the_second_kind"

#include <iostream>
#include <cstddef>
#include <string>
#include "atcoder/modint.hpp"
#include "tools/stirling_2nd.hpp"

using mint = atcoder::modint998244353;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  std::size_t N;
  std::cin >> N;

  std::string delimiter = "";
  for (const auto s : tools::stirling_2nd<mint>(N)) {
    std::cout << delimiter << s.val();
    delimiter = " ";
  }
  std::cout << '\n';

  return 0;
}
