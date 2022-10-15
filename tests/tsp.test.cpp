#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DPL_2_A"

#include <iostream>
#include <cassert>
#include "tools/tsp.hpp"
#include "tools/assert_that.hpp"
#include "tools/ssize.hpp"

using ll = long long;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  ll V, E;
  std::cin >> V >> E;
  tools::tsp<true, ll> graph(V);
  for (ll i = 0; i < E; ++i) {
    ll s, t, d;
    std::cin >> s >> t >> d;
    graph.add_edge(s, t, d);
  }

  const auto res = graph.query();
  if (res) {
    const auto& [answer, vids, eids] = *res;
    assert_that(tools::ssize(vids) == V);
    assert_that(tools::ssize(eids) == V);
    ll sum = 0;
    for (ll i = 0; i < V; ++i) {
      assert_that(graph.get_edge(eids[i]).from == vids[i]);
      assert_that(graph.get_edge(eids[i]).to == vids[(i + 1) % V]);
      sum += graph.get_edge(eids[i]).cost;
    }
    assert_that(answer == sum);
    std::cout << answer << '\n';
  } else {
    std::cout << -1 << '\n';
  }

  return 0;
}
