#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A"

#include <cstdlib>
#include <iostream>
#include "tests/assert_that.hpp"
#include "tools/median_solver.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  tools::median_solver<std::int_fast64_t> median;
  median.push(2);
  assert_that(median.lesser() == 2);
  assert_that(median.greater() == 2);
  median.push(1);
  assert_that(median.lesser() == 1);
  assert_that(median.greater() == 2);
  median.push(3);
  assert_that(median.lesser() == 2);
  assert_that(median.greater() == 2);
  median.push(4);
  assert_that(median.lesser() == 2);
  assert_that(median.greater() == 3);

  std::cout << "Hello World" << '\n';
  return 0;
}
