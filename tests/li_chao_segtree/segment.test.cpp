#define PROBLEM "https://judge.yosupo.jp/problem/segment_add_get_min"

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <limits>
#include "tools/li_chao_segtree.hpp"

using ll = long long;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  ll N, Q;
  std::cin >> N >> Q;
  std::vector<ll> l(N), r(N), a(N), b(N);
  for (ll i = 0; i < N; ++i) {
    std::cin >> l[i] >> r[i] >> a[i] >> b[i];
  }
  std::vector<std::tuple<ll, ll, ll, ll, ll>> queries(Q);
  for (ll i = 0; i < Q; ++i) {
    std::cin >> std::get<0>(queries[i]);
    if (std::get<0>(queries[i]) == 0) {
      std::cin >> std::get<1>(queries[i]) >> std::get<2>(queries[i]) >> std::get<3>(queries[i]) >> std::get<4>(queries[i]);
    } else {
      std::cin >> std::get<1>(queries[i]);
    }
  }

  std::vector<ll> x;
  for (const auto& [t, p, q2, q3, q4] : queries) {
    if (t == 1) {
      x.push_back(p);
    }
  }
  std::sort(x.begin(), x.end());
  x.erase(std::unique(x.begin(), x.end()), x.end());
  tools::li_chao_segtree<ll> seg(x.begin(), x.end(), false);

  for (ll i = 0; i < N; ++i) {
    seg.add(a[i], b[i], l[i], r[i] - 1);
  }
  for (const auto& [t, q1, q2, q3, q4] : queries) {
    if (t == 0) {
      seg.add(q3, q4, q1, q2 - 1);
    } else {
      const auto answer = seg.query(q1);
      if (answer < std::numeric_limits<ll>::max()) {
        std::cout << answer << '\n';
      } else {
        std::cout << "INFINITY" << '\n';
      }
    }
  }
  return 0;
}
