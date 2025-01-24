// competitive-verifier: STANDALONE

#include <iostream>
#include <vector>
#include <array>
#include "tools/assert_that.hpp"
#include "tools/transposed.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  assert_that(tools::transposed(std::vector<std::vector<int>> {
  }) == std::vector<std::vector<int>> {
  });
  assert_that(tools::transposed(std::vector<std::vector<int>> {
    {},
    {},
  }) == std::vector<std::vector<int>> {
  });
  assert_that(tools::transposed(std::vector<std::vector<int>> {
    {1, 2, 3},
    {4, 5, 6},
  }) == std::vector<std::vector<int>> {
    {1, 4},
    {2, 5},
    {3, 6},
  });

  assert_that(tools::transposed(std::array<std::vector<int>, 0> {{
  }}) == std::vector<std::array<int, 0>> {
  });
  assert_that(tools::transposed(std::array<std::vector<int>, 2> {{
    {},
    {},
  }}) == std::vector<std::array<int, 2>> {
  });
  assert_that(tools::transposed(std::array<std::vector<int>, 2> {{
    {1, 2, 3},
    {4, 5, 6},
  }}) == std::vector<std::array<int, 2>> {
    {1, 4},
    {2, 5},
    {3, 6},
  });

  assert_that(tools::transposed(std::vector<std::array<int, 0>> {
  }) == std::array<std::vector<int>, 0> {{
  }});
  assert_that(tools::transposed(std::vector<std::array<int, 3>> {
  }) == std::array<std::vector<int>, 3> {{
    {},
    {},
    {},
  }});
  assert_that(tools::transposed(std::vector<std::array<int, 0>> {
    {},
    {},
  }) == std::array<std::vector<int>, 0> {{
  }});
  assert_that(tools::transposed(std::vector<std::array<int, 3>> {
    {1, 2, 3},
    {4, 5, 6},
  }) == std::array<std::vector<int>, 3> {{
    {1, 4},
    {2, 5},
    {3, 6},
  }});

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

  return 0;
}
