// competitive-verifier: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A

#include <iostream>
#include "tools/assert_that.hpp"
#include "tools/is_in_grid.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  assert_that(!tools::is_in_grid(-1, -1, 2U, 3U));
  assert_that(!tools::is_in_grid(-1, 0, 2U, 3U));
  assert_that(!tools::is_in_grid(-1, 1, 2U, 3U));
  assert_that(!tools::is_in_grid(-1, 2, 2U, 3U));
  assert_that(!tools::is_in_grid(-1, 3, 2U, 3U));
  assert_that(!tools::is_in_grid(0, -1, 2U, 3U));
  assert_that(tools::is_in_grid(0, 0, 2U, 3U));
  assert_that(tools::is_in_grid(0, 1, 2U, 3U));
  assert_that(tools::is_in_grid(0, 2, 2U, 3U));
  assert_that(!tools::is_in_grid(0, 3, 2U, 3U));
  assert_that(!tools::is_in_grid(1, -1, 2U, 3U));
  assert_that(tools::is_in_grid(1, 0, 2U, 3U));
  assert_that(tools::is_in_grid(1, 1, 2U, 3U));
  assert_that(tools::is_in_grid(1, 2, 2U, 3U));
  assert_that(!tools::is_in_grid(1, 3, 2U, 3U));
  assert_that(!tools::is_in_grid(2, -1, 2U, 3U));
  assert_that(!tools::is_in_grid(2, 0, 2U, 3U));
  assert_that(!tools::is_in_grid(2, 1, 2U, 3U));
  assert_that(!tools::is_in_grid(2, 2, 2U, 3U));
  assert_that(!tools::is_in_grid(2, 3, 2U, 3U));

  assert_that(!tools::is_in_grid(-1, -1, 0U, 0U));
  assert_that(!tools::is_in_grid(-1, 0, 0U, 0U));
  assert_that(!tools::is_in_grid(0, -1, 0U, 0U));
  assert_that(!tools::is_in_grid(0, 0, 0U, 0U));

  std::cout << "Hello World" << '\n';
  return 0;
}
