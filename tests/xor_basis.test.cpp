// competitive-verifier: STANDALONE

#include <iostream>
#include <vector>
#include "tools/assert_that.hpp"
#include "tools/xor_basis.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  assert_that(tools::xor_basis(std::vector<int>{1, 1, 2, 4}).size() == 3);
  assert_that(tools::xor_basis(std::vector<int>{1, 1, 2, 1}).size() == 2);
  assert_that(tools::xor_basis(std::vector<int>{1, 1, 2, 3}).size() == 2);
  assert_that(tools::xor_basis(std::vector<int>{1, 2, 3}).size() == 2);
  assert_that(tools::xor_basis(std::vector<int>{1}).size() == 1);
  assert_that(tools::xor_basis(std::vector<int>{}).size() == 0);

  return 0;
}
