// competitive-verifier: STANDALONE

#include <array>
#include <iostream>
#include <utility>
#include "tools/eight_directions.hpp"
#include "tools/int128_t.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  static_assert(tools::eight_directions<int>() == std::array<std::pair<int, int>, 8>{{
    {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}
  }});
  static_assert(tools::eight_directions<long long>() == std::array<std::pair<long long, long long>, 8>{{
    {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}
  }});
  static_assert(tools::eight_directions<tools::int128_t>() == std::array<std::pair<tools::int128_t, tools::int128_t>, 8>{{
    {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}
  }});

  return 0;
}
