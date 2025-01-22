// competitive-verifier: PROBLEM https://yukicoder.me/problems/no/1358

#include <iostream>
#include <array>
#include <algorithm>
#include <tuple>
#include "atcoder/modint.hpp"
#include "tools/bezout.hpp"
#include "tools/floor.hpp"
#include "tools/ceil.hpp"

using mint = atcoder::modint1000000007;
using ll = long long;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  ll T;
  std::cin >> T;
  for (ll t = 0; t < T; ++t) {
    ll N, K, H, Y;
    std::cin >> N >> K >> H >> Y;

    {
      std::array<ll, 3> arr = {N, K, H};
      std::sort(arr.begin(), arr.end());
      std::tie(N, K, H) = std::make_tuple(arr[0], arr[1], arr[2]);
    }

    mint answer = 0;
    for (ll z = 0; z <= Y / H; ++z) {
      const auto solution = tools::bezout(N, K, Y - H * z);
      if (!solution) continue;
      const auto [p, q, r, s] = *solution;
      answer += mint(std::max<ll>(0, tools::floor(-q, p) - tools::ceil(-s, r) + 1));
    }

    std::cout << answer.val() << '\n';
  }

  return 0;
}
