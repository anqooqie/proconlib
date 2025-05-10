// competitive-verifier: STANDALONE

#include <iostream>
#include <vector>
#include "tools/assert_that.hpp"
#include "tools/is_partitioned.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  assert_that(tools::is_partitioned(0, 0, [](const auto i) -> bool { return std::vector<bool>{false}[i]; }));
  assert_that(tools::is_partitioned(0, 0, [](const auto i) -> bool { return std::vector<bool>{true}[i]; }));
  assert_that(tools::is_partitioned(0, 1, [](const auto i) -> bool { return std::vector<bool>{false, false}[i]; }));
  assert_that(tools::is_partitioned(0, 1, [](const auto i) -> bool { return std::vector<bool>{true, false}[i]; }));
  assert_that(tools::is_partitioned(0, 1, [](const auto i) -> bool { return std::vector<bool>{false, true}[i]; }));
  assert_that(tools::is_partitioned(0, 1, [](const auto i) -> bool { return std::vector<bool>{true, true}[i]; }));
  assert_that(tools::is_partitioned(0, 2, [](const auto i) -> bool { return std::vector<bool>{false, false, false}[i]; }));
  assert_that(tools::is_partitioned(0, 2, [](const auto i) -> bool { return std::vector<bool>{true, false, false}[i]; }));
  assert_that(!tools::is_partitioned(0, 2, [](const auto i) -> bool { return std::vector<bool>{false, true, false}[i]; }));
  assert_that(tools::is_partitioned(0, 2, [](const auto i) -> bool { return std::vector<bool>{true, true, false}[i]; }));
  assert_that(tools::is_partitioned(0, 2, [](const auto i) -> bool { return std::vector<bool>{false, false, true}[i]; }));
  assert_that(!tools::is_partitioned(0, 2, [](const auto i) -> bool { return std::vector<bool>{true, false, true}[i]; }));
  assert_that(tools::is_partitioned(0, 2, [](const auto i) -> bool { return std::vector<bool>{false, true, true}[i]; }));
  assert_that(tools::is_partitioned(0, 2, [](const auto i) -> bool { return std::vector<bool>{true, true, true}[i]; }));
  assert_that(tools::is_partitioned(0, 3, [](const auto i) -> bool { return std::vector<bool>{false, false, false, false}[i]; }));
  assert_that(tools::is_partitioned(0, 3, [](const auto i) -> bool { return std::vector<bool>{true, false, false, false}[i]; }));
  assert_that(!tools::is_partitioned(0, 3, [](const auto i) -> bool { return std::vector<bool>{false, true, false, false}[i]; }));
  assert_that(tools::is_partitioned(0, 3, [](const auto i) -> bool { return std::vector<bool>{true, true, false, false}[i]; }));
  assert_that(!tools::is_partitioned(0, 3, [](const auto i) -> bool { return std::vector<bool>{false, false, true, false}[i]; }));
  assert_that(!tools::is_partitioned(0, 3, [](const auto i) -> bool { return std::vector<bool>{true, false, true, false}[i]; }));
  assert_that(!tools::is_partitioned(0, 3, [](const auto i) -> bool { return std::vector<bool>{false, true, true, false}[i]; }));
  assert_that(tools::is_partitioned(0, 3, [](const auto i) -> bool { return std::vector<bool>{true, true, true, false}[i]; }));
  assert_that(tools::is_partitioned(0, 3, [](const auto i) -> bool { return std::vector<bool>{false, false, false, true}[i]; }));
  assert_that(!tools::is_partitioned(0, 3, [](const auto i) -> bool { return std::vector<bool>{true, false, false, true}[i]; }));
  assert_that(!tools::is_partitioned(0, 3, [](const auto i) -> bool { return std::vector<bool>{false, true, false, true}[i]; }));
  assert_that(!tools::is_partitioned(0, 3, [](const auto i) -> bool { return std::vector<bool>{true, true, false, true}[i]; }));
  assert_that(tools::is_partitioned(0, 3, [](const auto i) -> bool { return std::vector<bool>{false, false, true, true}[i]; }));
  assert_that(!tools::is_partitioned(0, 3, [](const auto i) -> bool { return std::vector<bool>{true, false, true, true}[i]; }));
  assert_that(tools::is_partitioned(0, 3, [](const auto i) -> bool { return std::vector<bool>{false, true, true, true}[i]; }));
  assert_that(tools::is_partitioned(0, 3, [](const auto i) -> bool { return std::vector<bool>{true, true, true, true}[i]; }));

  return 0;
}
