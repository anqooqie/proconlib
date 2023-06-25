#define PROBLEM "https://judge.yosupo.jp/problem/point_add_rectangle_sum"

#include <iostream>
#include <vector>
#include <tuple>
#include "tools/rectangle_sum.hpp"

using ll = long long;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  ll N, Q;
  std::cin >> N >> Q;

  std::vector<std::tuple<ll, ll, ll, ll, ll>> queries;
  tools::rectangle_sum<ll> rs;
  for (ll i = 0; i < N; ++i) {
    ll x, y, w;
    std::cin >> x >> y >> w;
    queries.emplace_back(0, x, y, w, 0);
    rs.register_point(x, y);
  }
  for (ll q = 0; q < Q; ++q) {
    ll t;
    std::cin >> t;
    if (t == 0) {
      ll x, y, w;
      std::cin >> x >> y >> w;
      queries.emplace_back(t, x, y, w, 0);
      rs.register_point(x, y);
    } else {
      ll l, d, r, u;
      std::cin >> l >> d >> r >> u;
      queries.emplace_back(t, l, d, r, u);
    }
  }

  rs.build();

  for (ll i = 0; i < N; ++i) {
    const auto& [t, x, y, w, ignore] = queries[i];
    rs.add(x, y, w);
  }
  for (ll q = N; q < N + Q; ++q) {
    if (std::get<0>(queries[q]) == 0) {
      const auto& [t, x, y, w, ignore] = queries[q];
      rs.add(x, y, w);
    } else {
      const auto& [t, l, d, r, u] = queries[q];
      std::cout << rs.sum(l, r, d, u) << '\n';
    }
  }

  return 0;
}
