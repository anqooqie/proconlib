#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A"

#include <iostream>
#include <vector>
#include <iterator>
#include <cmath>
#include "tools/assert_that.hpp"
#include "tools/convolution.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  const std::vector<double> A({1, 2, 3, 4}), B({1, 2, 4, 8});

  std::vector<double> C;
  tools::convolution(A.begin(), A.end(), B.begin(), B.end(), std::back_inserter(C));
  for (auto& C_i : C) C_i = std::round(C_i);

  assert_that(C == std::vector<double>({1, 4, 11, 26, 36, 40, 32}));

  std::cout << "Hello World" << '\n';
  return 0;
}
