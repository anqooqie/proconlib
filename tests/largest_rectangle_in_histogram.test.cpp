#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DPL_3_C"

#include <iostream>
#include <vector>
#include "tools/largest_rectangle_in_histogram.hpp"

using ll = long long;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  ll N;
  std::cin >> N;
  std::vector<ll> h(N);
  for (ll& h_i : h) std::cin >> h_i;
  std::cout << tools::largest_rectangle_in_histogram(h.begin(), h.end()) << '\n';

  return 0;
}
