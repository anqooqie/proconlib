#define PROBLEM "https://atcoder.jp/contests/abc225/tasks/abc225_e"

#include <iostream>
#include <vector>
#include <algorithm>
#include "tools/vector2.hpp"
#include "tools/less_by_arg.hpp"

using ll = long long;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  ll N;
  std::cin >> N;
  std::vector<tools::vector2<ll>> v(N);
  for (auto& v_i : v) std::cin >> v_i;

  const tools::less_by_arg<ll> comp(tools::vector2<ll>(0, 0), tools::vector2<ll>(1, 0));
  std::sort(v.begin(), v.end(), [&](const auto& v1, const auto& v2) {
    return comp(v1 + tools::vector2<ll>(-1, 0), v2 + tools::vector2<ll>(-1, 0));
  });

  ll answer = 0;
  for (ll i = 0; i < N;) {
    ++answer;
    const auto end = v[i] + tools::vector2<ll>(-1, 0);
    for (; i < N && comp(v[i] + tools::vector2<ll>(0, -1), end); ++i);
  }
  std::cout << answer << '\n';
  return 0;
}
