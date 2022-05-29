#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A"

#include <cstdint>
#include <iostream>
#include "tests/assert_that.hpp"
#include "tools/digit_sum.hpp"

using i64 = std::int_fast64_t;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  assert_that(tools::digit_sum<i64>(0) == 0);
  assert_that(tools::digit_sum<i64>(1) == 1);
  assert_that(tools::digit_sum<i64>(2) == 2);
  assert_that(tools::digit_sum<i64>(3) == 3);
  assert_that(tools::digit_sum<i64>(4) == 4);
  assert_that(tools::digit_sum<i64>(5) == 5);
  assert_that(tools::digit_sum<i64>(6) == 6);
  assert_that(tools::digit_sum<i64>(7) == 7);
  assert_that(tools::digit_sum<i64>(8) == 8);
  assert_that(tools::digit_sum<i64>(9) == 9);
  assert_that(tools::digit_sum<i64>(10) == 1);
  assert_that(tools::digit_sum<i64>(11) == 2);
  assert_that(tools::digit_sum<i64>(12) == 3);
  assert_that(tools::digit_sum<i64>(13) == 4);
  assert_that(tools::digit_sum<i64>(14) == 5);
  assert_that(tools::digit_sum<i64>(15) == 6);
  assert_that(tools::digit_sum<i64>(16) == 7);
  assert_that(tools::digit_sum<i64>(17) == 8);
  assert_that(tools::digit_sum<i64>(18) == 9);
  assert_that(tools::digit_sum<i64>(19) == 10);
  assert_that(tools::digit_sum<i64>(20) == 2);
  assert_that(tools::digit_sum<i64>(90) == 9);
  assert_that(tools::digit_sum<i64>(91) == 10);
  assert_that(tools::digit_sum<i64>(92) == 11);
  assert_that(tools::digit_sum<i64>(93) == 12);
  assert_that(tools::digit_sum<i64>(94) == 13);
  assert_that(tools::digit_sum<i64>(95) == 14);
  assert_that(tools::digit_sum<i64>(96) == 15);
  assert_that(tools::digit_sum<i64>(97) == 16);
  assert_that(tools::digit_sum<i64>(98) == 17);
  assert_that(tools::digit_sum<i64>(99) == 18);
  assert_that(tools::digit_sum<i64>(100) == 1);
  assert_that(tools::digit_sum<i64>(101) == 2);
  assert_that(tools::digit_sum<i64>(999) == 27);
  assert_that(tools::digit_sum<i64>(1000) == 1);
  assert_that(tools::digit_sum<i64>(999999999999999999) == 162);
  assert_that(tools::digit_sum<i64>(1000000000000000000) == 1);
  assert_that(tools::digit_sum<i64>(1000000000000000001) == 2);
  assert_that(tools::digit_sum<i64>(8999999999999999999) == 170);
  assert_that(tools::digit_sum<i64>(9223372036854775806) == 87);
  assert_that(tools::digit_sum<i64>(9223372036854775807) == 88);

  std::cout << "Hello World" << '\n';
  return 0;
}
