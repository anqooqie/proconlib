#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A"

#include <iostream>
#include "tests/assert_that.hpp"
#include "tools/ceil_sqrt.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  assert_that(tools::ceil_sqrt(0) == 0);
  assert_that(tools::ceil_sqrt(1) == 1);
  assert_that(tools::ceil_sqrt(2) == 2);
  assert_that(tools::ceil_sqrt(3) == 2);
  assert_that(tools::ceil_sqrt(4) == 2);
  assert_that(tools::ceil_sqrt(5) == 3);
  assert_that(tools::ceil_sqrt(6) == 3);
  assert_that(tools::ceil_sqrt(7) == 3);
  assert_that(tools::ceil_sqrt(8) == 3);
  assert_that(tools::ceil_sqrt(9) == 3);
  assert_that(tools::ceil_sqrt(10) == 4);
  assert_that(tools::ceil_sqrt(999999999999999999) == 1000000000);
  assert_that(tools::ceil_sqrt(1000000000000000000) == 1000000000);
  assert_that(tools::ceil_sqrt(1000000000000000001) == 1000000001);

  std::cout << "Hello World" << '\n';
  return 0;
}
