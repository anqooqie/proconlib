#define PROBLEM "https://yukicoder.me/problems/no/1358"

#include <cstdint>
#include <iostream>
#include <array>
#include <algorithm>
#include <tuple>
#include "atcoder/modint.hpp"
#include "tools/bezout.hpp"
#include "tools/floor.hpp"
#include "tools/ceil.hpp"

using mint = atcoder::modint1000000007;
using i64 = std::int_fast64_t;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  i64 T;
  std::cin >> T;
  for (i64 t = 0; t < T; ++t) {
    i64 N, K, H, Y;
    std::cin >> N >> K >> H >> Y;

    {
      std::array<i64, 3> arr = {N, K, H};
      std::sort(arr.begin(), arr.end());
      std::tie(N, K, H) = std::make_tuple(arr[0], arr[1], arr[2]);
    }

    mint answer = 0;
    for (i64 z = 0; z <= Y / H; ++z) {
      const auto solution = tools::bezout(N, K, Y - H * z);
      if (!solution) continue;
      const auto [p, q, r, s] = *solution;
      answer += mint(std::max<i64>(0, tools::floor(-q, p) - tools::ceil(-s, r) + 1));
    }

    std::cout << answer.val() << '\n';
  }

  return 0;
}
