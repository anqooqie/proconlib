// competitive-verifier: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A

#include <iostream>
#include "tools/assert_that.hpp"
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
  assert_that(tools::ceil_sqrt(9223372030926249000) == 3037000499);
  assert_that(tools::ceil_sqrt(9223372030926249001) == 3037000499);
  assert_that(tools::ceil_sqrt(9223372030926249002) == 3037000500);
  assert_that(tools::ceil_sqrt(9223372036854775807) == 3037000500);

  std::cout << "Hello World" << '\n';
  return 0;
}
