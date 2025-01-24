// competitive-verifier: STANDALONE

#include <iostream>
#include "tools/assert_that.hpp"
#include "tools/is_monoid.hpp"
#include "tools/monoid.hpp"
#include "tools/group.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  assert_that(tools::is_monoid_v<int> == false);
  assert_that(tools::is_monoid_v<tools::monoid::multiplies<int>> == true);
  assert_that(tools::is_monoid_v<tools::group::plus<int>> == true);

  return 0;
}
