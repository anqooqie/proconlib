#define PROBLEM "https://atcoder.jp/contests/abc253/tasks/abc253_f"

#include <iostream>
#include <vector>
#include <utility>
#include "tools/persistent_dual_segtree.hpp"
#include "tools/group.hpp"

using ll = long long;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  ll N, M, Q;
  std::cin >> N >> M >> Q;

  std::vector<std::pair<ll, ll>> updated(N, std::make_pair(0, 0));
  tools::persistent_dual_segtree<tools::group::plus<ll>>::buffer buffer;
  std::vector<tools::persistent_dual_segtree<tools::group::plus<ll>>> dual_segtrees;
  dual_segtrees.emplace_back(buffer, M);

  for (ll q = 0; q < Q; ++q) {
    ll t;
    std::cin >> t;
    if (t == 1) {
      ll l, r, x;
      std::cin >> l >> r >> x;
      --l;
      dual_segtrees.push_back(dual_segtrees.back().apply(l, r, x));
    } else if (t == 2) {
      ll i, x;
      std::cin >> i >> x;
      --i;
      dual_segtrees.push_back(dual_segtrees.back());
      updated[i] = std::make_pair(q, x);
    } else {
      ll i, j;
      std::cin >> i >> j;
      --i, --j;
      dual_segtrees.push_back(dual_segtrees.back());
      const auto& [t, x] = updated[i];
      std::cout << dual_segtrees.back().get(j) - dual_segtrees[t].get(j) + x << '\n';
    }
  }
  return 0;
}
