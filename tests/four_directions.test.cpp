// competitive-verifier: STANDALONE

#include <array>
#include <iostream>
#include <utility>
#include "tools/four_directions.hpp"
#include "tools/int128_t.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  static_assert(tools::four_directions<int>() == std::array<std::pair<int, int>, 4>{{
    {0, 1}, {1, 0}, {0, -1}, {-1, 0}
  }});
  static_assert(tools::four_directions<long long>() == std::array<std::pair<long long, long long>, 4>{{
    {0, 1}, {1, 0}, {0, -1}, {-1, 0}
  }});
  static_assert(tools::four_directions<tools::int128_t>() == std::array<std::pair<tools::int128_t, tools::int128_t>, 4>{{
    {0, 1}, {1, 0}, {0, -1}, {-1, 0}
  }});

  return 0;
}
