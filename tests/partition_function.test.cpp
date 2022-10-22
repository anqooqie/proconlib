#define PROBLEM "https://judge.yosupo.jp/problem/partition_function"

#include <iostream>
#include <string>
#include "atcoder/modint.hpp"
#include "tools/partition_function.hpp"

using mint = atcoder::modint998244353;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int N;
  std::cin >> N;

  std::string delimiter = "";
  for (const auto s : tools::partition_function<mint>(N)) {
    std::cout << delimiter << s.val();
    delimiter = " ";
  }
  std::cout << '\n';

  return 0;
}
