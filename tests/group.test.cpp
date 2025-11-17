// competitive-verifier: STANDALONE

#include <iostream>
#include "tools/group.hpp"
#include "tools/groups.hpp"
#include "tools/monoids.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  static_assert(!tools::group<int>);
  static_assert(!tools::group<tools::monoids::multiplies<int>>);
  static_assert(tools::group<tools::groups::plus<int>>);

  return 0;
}
