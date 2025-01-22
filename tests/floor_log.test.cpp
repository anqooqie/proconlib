// competitive-verifier: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A

#include <cstdlib>
#include <iostream>
#include "tools/assert_that.hpp"
#include "tools/floor_log.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  assert_that(tools::floor_log(2, 1) == 0);
  assert_that(tools::floor_log(2, 2) == 1);
  assert_that(tools::floor_log(2, 3) == 1);
  assert_that(tools::floor_log(2, 4) == 2);
  assert_that(tools::floor_log(2, 5) == 2);
  assert_that(tools::floor_log(2, 6) == 2);
  assert_that(tools::floor_log(2, 7) == 2);
  assert_that(tools::floor_log(2, 8) == 3);
  assert_that(tools::floor_log(2, 9) == 3);
  assert_that(tools::floor_log(3, 1) == 0);
  assert_that(tools::floor_log(3, 2) == 0);
  assert_that(tools::floor_log(3, 3) == 1);
  assert_that(tools::floor_log(3, 4) == 1);
  assert_that(tools::floor_log(3, 5) == 1);
  assert_that(tools::floor_log(3, 6) == 1);
  assert_that(tools::floor_log(3, 7) == 1);
  assert_that(tools::floor_log(3, 8) == 1);
  assert_that(tools::floor_log(3, 9) == 2);
  assert_that(tools::floor_log(4, 1) == 0);
  assert_that(tools::floor_log(4, 2) == 0);
  assert_that(tools::floor_log(4, 3) == 0);
  assert_that(tools::floor_log(4, 4) == 1);
  assert_that(tools::floor_log(4, 5) == 1);
  assert_that(tools::floor_log(4, 6) == 1);
  assert_that(tools::floor_log(4, 7) == 1);
  assert_that(tools::floor_log(4, 8) == 1);
  assert_that(tools::floor_log(4, 9) == 1);
  assert_that(tools::floor_log(2, 576460752303423487) == 58);
  assert_that(tools::floor_log(2, 576460752303423488) == 59);
  assert_that(tools::floor_log(2, 576460752303423489) == 59);
  assert_that(tools::floor_log(2, 1000000000000000000) == 59);
  assert_that(tools::floor_log(1000000000000000000, 1) == 0);
  assert_that(tools::floor_log(1000000000000000000, 2) == 0);
  assert_that(tools::floor_log(999999999999999999, 999999999999999998) == 0);
  assert_that(tools::floor_log(999999999999999999, 999999999999999999) == 1);
  assert_that(tools::floor_log(999999999999999999, 1000000000000000000) == 1);

  std::cout << "Hello World" << '\n';
  return 0;
}
