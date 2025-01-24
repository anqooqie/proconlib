// competitive-verifier: STANDALONE

#include <iostream>
#include <array>
#include <cstddef>
#include <vector>
#include "tools/assert_that.hpp"
#include "tools/virtual_vector.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  std::array<int, 5> a{1, 2, 3, 4, 5};
  const tools::virtual_vector v(5, [a](const std::size_t i) -> const int& { return a[i]; });
  assert_that(std::equal(v.begin(), v.end(), a.begin(), a.end()));

  std::vector<int> b{1, 2, 3, 4, 5};
  const tools::virtual_vector u(5, [b](const std::size_t i) -> const int& { return b[i]; });
  assert_that(v == u);

  return 0;
}
