#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DPL_3_C"

#include <cstdint>
#include <iostream>
#include <vector>
#include "tools/largest_rectangle_in_histogram.hpp"

using i64 = std::int_fast64_t;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  i64 N;
  std::cin >> N;
  std::vector<i64> h(N);
  for (i64& h_i : h) std::cin >> h_i;
  std::cout << tools::largest_rectangle_in_histogram(h.begin(), h.end()) << '\n';

  return 0;
}
