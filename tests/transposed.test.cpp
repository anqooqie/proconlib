// competitive-verifier: STANDALONE

#include <array>
#include <iostream>
#include <string>
#include <vector>
#include "tools/assert_that.hpp"
#include "tools/transposed.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  assert_that(tools::transposed(std::array<std::array<int, 0>, 0> {{
  }}) == std::array<std::array<int, 0>, 0> {{
  }});
  assert_that(tools::transposed(std::array<std::array<int, 3>, 0> {{
  }}) == std::array<std::array<int, 0>, 3> {{
    {},
    {},
    {},
  }});
  assert_that(tools::transposed(std::array<std::array<int, 0>, 2> {{
    {},
    {},
  }}) == std::array<std::array<int, 2>, 0> {{
  }});
  assert_that(tools::transposed(std::array<std::array<int, 3>, 2> {{
    {1, 2, 3},
    {4, 5, 6},
  }}) == std::array<std::array<int, 2>, 3> {{
    {1, 4},
    {2, 5},
    {3, 6},
  }});

  assert_that(tools::transposed(std::vector<std::vector<int>> {
    {1, 2, 3},
    {4, 5, 6},
  }) == std::vector<std::vector<int>> {
    {1, 4},
    {2, 5},
    {3, 6},
  });

  assert_that(tools::transposed(std::vector<std::string> {
    "abc",
    "def",
  }) == std::vector<std::string> {
    "ad",
    "be",
    "cf",
  });

  return 0;
}
