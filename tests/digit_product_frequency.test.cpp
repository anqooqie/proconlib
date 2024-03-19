#define PROBLEM "https://atcoder.jp/contests/abc208/tasks/abc208_e"

#include <iostream>
#include <numeric>
#include "tools/digit_product_frequency.hpp"

using ll = long long;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  ll N, K;
  std::cin >> N >> K;

  const auto freq = tools::digit_product_frequency(N);
  std::cout << ::std::accumulate(freq.begin(), freq.upper_bound(K), 0LL, [](const auto sum, const auto& pair) { return sum + pair.second; }) << '\n';

  return 0;
}
