// competitive-verifier: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A

#include <iostream>
#include "tools/assert_that.hpp"
#include "tools/digit_sum.hpp"

using ll = long long;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  assert_that(tools::digit_sum<ll>(0) == 0);
  assert_that(tools::digit_sum<ll>(1) == 1);
  assert_that(tools::digit_sum<ll>(2) == 2);
  assert_that(tools::digit_sum<ll>(3) == 3);
  assert_that(tools::digit_sum<ll>(4) == 4);
  assert_that(tools::digit_sum<ll>(5) == 5);
  assert_that(tools::digit_sum<ll>(6) == 6);
  assert_that(tools::digit_sum<ll>(7) == 7);
  assert_that(tools::digit_sum<ll>(8) == 8);
  assert_that(tools::digit_sum<ll>(9) == 9);
  assert_that(tools::digit_sum<ll>(10) == 1);
  assert_that(tools::digit_sum<ll>(11) == 2);
  assert_that(tools::digit_sum<ll>(12) == 3);
  assert_that(tools::digit_sum<ll>(13) == 4);
  assert_that(tools::digit_sum<ll>(14) == 5);
  assert_that(tools::digit_sum<ll>(15) == 6);
  assert_that(tools::digit_sum<ll>(16) == 7);
  assert_that(tools::digit_sum<ll>(17) == 8);
  assert_that(tools::digit_sum<ll>(18) == 9);
  assert_that(tools::digit_sum<ll>(19) == 10);
  assert_that(tools::digit_sum<ll>(20) == 2);
  assert_that(tools::digit_sum<ll>(90) == 9);
  assert_that(tools::digit_sum<ll>(91) == 10);
  assert_that(tools::digit_sum<ll>(92) == 11);
  assert_that(tools::digit_sum<ll>(93) == 12);
  assert_that(tools::digit_sum<ll>(94) == 13);
  assert_that(tools::digit_sum<ll>(95) == 14);
  assert_that(tools::digit_sum<ll>(96) == 15);
  assert_that(tools::digit_sum<ll>(97) == 16);
  assert_that(tools::digit_sum<ll>(98) == 17);
  assert_that(tools::digit_sum<ll>(99) == 18);
  assert_that(tools::digit_sum<ll>(100) == 1);
  assert_that(tools::digit_sum<ll>(101) == 2);
  assert_that(tools::digit_sum<ll>(999) == 27);
  assert_that(tools::digit_sum<ll>(1000) == 1);
  assert_that(tools::digit_sum<ll>(999999999999999999) == 162);
  assert_that(tools::digit_sum<ll>(1000000000000000000) == 1);
  assert_that(tools::digit_sum<ll>(1000000000000000001) == 2);
  assert_that(tools::digit_sum<ll>(8999999999999999999) == 170);
  assert_that(tools::digit_sum<ll>(9223372036854775806) == 87);
  assert_that(tools::digit_sum<ll>(9223372036854775807) == 88);

  std::cout << "Hello World" << '\n';
  return 0;
}
