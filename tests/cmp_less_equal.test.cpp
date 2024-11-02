#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A"

#include <iostream>
#include "tools/assert_that.hpp"
#include "tools/cmp_less_equal.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  assert_that(tools::cmp_less_equal(-1, 0U));
  assert_that(tools::cmp_less_equal(0U, 0U));
  assert_that(!tools::cmp_less_equal(0U, -1));

  std::cout << "Hello World" << '\n';
  return 0;
}
