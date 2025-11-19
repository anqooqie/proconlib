// competitive-verifier: STANDALONE

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#include "tools/assert_that.hpp"
#include "tools/kth_smallest_by_oracle.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  const std::vector<int> S{1, 1, 2, 3, 3, 4, 5, 5, 5, 6, 9};
  const auto f = [&](const int x) {
    return std::distance(S.begin(), std::ranges::upper_bound(S, x));
  };

  assert_that(tools::kth_smallest_by_oracle(1, f, 1, 9) == 1);
  assert_that(tools::kth_smallest_by_oracle(2, f, 1, 9) == 1);
  assert_that(tools::kth_smallest_by_oracle(3, f, 1, 9) == 2);
  assert_that(tools::kth_smallest_by_oracle(4, f, 1, 9) == 3);
  assert_that(tools::kth_smallest_by_oracle(5, f, 1, 9) == 3);
  assert_that(tools::kth_smallest_by_oracle(6, f, 1, 9) == 4);
  assert_that(tools::kth_smallest_by_oracle(7, f, 1, 9) == 5);
  assert_that(tools::kth_smallest_by_oracle(8, f, 1, 9) == 5);
  assert_that(tools::kth_smallest_by_oracle(9, f, 1, 9) == 5);
  assert_that(tools::kth_smallest_by_oracle(10, f, 1, 9) == 6);
  assert_that(tools::kth_smallest_by_oracle(11, f, 1, 9) == 9);

  return 0;
}
