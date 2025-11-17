// competitive-verifier: STANDALONE

#include <cmath>
#include <iostream>
#include <vector>
#include "tools/assert_that.hpp"
#include "tools/convolution.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  const std::vector<double> A{1, 2, 3, 4}, B{1, 2, 4, 8};

  auto C = tools::convolution(A, B);
  for (auto& C_i : C) C_i = std::round(C_i);

  assert_that(C == std::vector<double>{1, 4, 11, 26, 36, 40, 32});

  return 0;
}
