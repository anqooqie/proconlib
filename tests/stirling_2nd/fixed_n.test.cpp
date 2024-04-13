#define PROBLEM "https://judge.yosupo.jp/problem/stirling_number_of_the_second_kind"

#include <iostream>
#include "atcoder/modint.hpp"
#include "tools/stirling_2nd.hpp"
#include "tools/join.hpp"

using mint = atcoder::modint998244353;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int N;
  std::cin >> N;

  const auto answer = tools::stirling_2nd::fixed_n<mint>(N, N);
  std::cout << tools::join(answer.begin(), answer.end(), [](const auto x) { return x.val(); }, " ") << '\n';

  return 0;
}
