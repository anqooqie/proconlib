// competitive-verifier: STANDALONE

#include <iostream>
#include "tools/assert_that.hpp"
#include "tools/floor.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  assert_that(tools::floor(5, 3) == 1);
  assert_that(tools::floor(5, -3) == -2);
  assert_that(tools::floor(-5, 3) == -2);
  assert_that(tools::floor(-5, -3) == 1);

  assert_that(tools::floor(-2, -2) == 1);
  assert_that(tools::floor(-2, -1) == 2);
  assert_that(tools::floor(-2, 1) == -2);
  assert_that(tools::floor(-2, 2) == -1);

  assert_that(tools::floor(-1, -2) == 0);
  assert_that(tools::floor(-1, -1) == 1);
  assert_that(tools::floor(-1, 1) == -1);
  assert_that(tools::floor(-1, 2) == -1);

  assert_that(tools::floor(0, -2) == 0);
  assert_that(tools::floor(0, -1) == 0);
  assert_that(tools::floor(0, 1) == 0);
  assert_that(tools::floor(0, 2) == 0);

  assert_that(tools::floor(1, -2) == -1);
  assert_that(tools::floor(1, -1) == -1);
  assert_that(tools::floor(1, 1) == 1);
  assert_that(tools::floor(1, 2) == 0);

  assert_that(tools::floor(2, -2) == -1);
  assert_that(tools::floor(2, -1) == -2);
  assert_that(tools::floor(2, 1) == 2);
  assert_that(tools::floor(2, 2) == 1);

  assert_that(tools::floor(-9223372036854775807 - 1, -3) == 3074457345618258602);
  assert_that(tools::floor(-9223372036854775807 - 1, -2) == 4611686018427387904);
  assert_that(tools::floor(-9223372036854775807 - 1, 1) == -9223372036854775807 - 1);
  assert_that(tools::floor(-9223372036854775807 - 1, 2) == -4611686018427387904);
  assert_that(tools::floor(-9223372036854775807 - 1, 3) == -3074457345618258603);

  assert_that(tools::floor(-9223372036854775807, -3) == 3074457345618258602);
  assert_that(tools::floor(-9223372036854775807, -2) == 4611686018427387903);
  assert_that(tools::floor(-9223372036854775807, -1) == 9223372036854775807);
  assert_that(tools::floor(-9223372036854775807, 1) == -9223372036854775807);
  assert_that(tools::floor(-9223372036854775807, 2) == -4611686018427387904);
  assert_that(tools::floor(-9223372036854775807, 3) == -3074457345618258603);

  assert_that(tools::floor(9223372036854775807, -3) == -3074457345618258603);
  assert_that(tools::floor(9223372036854775807, -2) == -4611686018427387904);
  assert_that(tools::floor(9223372036854775807, -1) == -9223372036854775807);
  assert_that(tools::floor(9223372036854775807, 1) == 9223372036854775807);
  assert_that(tools::floor(9223372036854775807, 2) == 4611686018427387903);
  assert_that(tools::floor(9223372036854775807, 3) == 3074457345618258602);

  return 0;
}
