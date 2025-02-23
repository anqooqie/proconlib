// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/tree_diameter

#include <iostream>
#include <vector>
#include <utility>
#include "tools/tree_diameter.hpp"
#include "tools/join.hpp"

using ll = long long;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  ll N;
  std::cin >> N;
  tools::tree_diameter<ll> tree(N);
  std::vector<std::pair<ll, ll>> edges;
  for (ll i = 0; i < N - 1; ++i) {
    ll a, b, c;
    std::cin >> a >> b >> c;
    tree.add_edge(a, b, c);
    edges.emplace_back(a, b);
  }

  const auto [X, u, unused] = tree.query();
  std::cout << X << ' ' << u.size() << '\n';
  std::cout << ::tools::join(u, " ") << '\n';
  return 0;
}
