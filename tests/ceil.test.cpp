// competitive-verifier: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A

#include <iostream>
#include "tools/assert_that.hpp"
#include "tools/ceil.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  assert_that(tools::ceil(5, 3) == 2);
  assert_that(tools::ceil(5, -3) == -1);
  assert_that(tools::ceil(-5, 3) == -1);
  assert_that(tools::ceil(-5, -3) == 2);

  assert_that(tools::ceil(-2, -2) == 1);
  assert_that(tools::ceil(-2, -1) == 2);
  assert_that(tools::ceil(-2, 1) == -2);
  assert_that(tools::ceil(-2, 2) == -1);

  assert_that(tools::ceil(-1, -2) == 1);
  assert_that(tools::ceil(-1, -1) == 1);
  assert_that(tools::ceil(-1, 1) == -1);
  assert_that(tools::ceil(-1, 2) == 0);

  assert_that(tools::ceil(0, -2) == 0);
  assert_that(tools::ceil(0, -1) == 0);
  assert_that(tools::ceil(0, 1) == 0);
  assert_that(tools::ceil(0, 2) == 0);

  assert_that(tools::ceil(1, -2) == 0);
  assert_that(tools::ceil(1, -1) == -1);
  assert_that(tools::ceil(1, 1) == 1);
  assert_that(tools::ceil(1, 2) == 1);

  assert_that(tools::ceil(2, -2) == -1);
  assert_that(tools::ceil(2, -1) == -2);
  assert_that(tools::ceil(2, 1) == 2);
  assert_that(tools::ceil(2, 2) == 1);

  assert_that(tools::ceil(-9223372036854775807 - 1, -3) == 3074457345618258603);
  assert_that(tools::ceil(-9223372036854775807 - 1, -2) == 4611686018427387904);
  assert_that(tools::ceil(-9223372036854775807 - 1, 1) == -9223372036854775807 - 1);
  assert_that(tools::ceil(-9223372036854775807 - 1, 2) == -4611686018427387904);
  assert_that(tools::ceil(-9223372036854775807 - 1, 3) == -3074457345618258602);

  assert_that(tools::ceil(-9223372036854775807, -3) == 3074457345618258603);
  assert_that(tools::ceil(-9223372036854775807, -2) == 4611686018427387904);
  assert_that(tools::ceil(-9223372036854775807, -1) == 9223372036854775807);
  assert_that(tools::ceil(-9223372036854775807, 1) == -9223372036854775807);
  assert_that(tools::ceil(-9223372036854775807, 2) == -4611686018427387903);
  assert_that(tools::ceil(-9223372036854775807, 3) == -3074457345618258602);

  assert_that(tools::ceil(9223372036854775807, -3) == -3074457345618258602);
  assert_that(tools::ceil(9223372036854775807, -2) == -4611686018427387903);
  assert_that(tools::ceil(9223372036854775807, -1) == -9223372036854775807);
  assert_that(tools::ceil(9223372036854775807, 1) == 9223372036854775807);
  assert_that(tools::ceil(9223372036854775807, 2) == 4611686018427387904);
  assert_that(tools::ceil(9223372036854775807, 3) == 3074457345618258603);

  std::cout << "Hello World" << '\n';
  return 0;
}
