// competitive-verifier: PROBLEM https://atcoder.jp/contests/abc247/tasks/abc247_g
// competitive-verifier: IGNORE

#include <iostream>
#include <vector>
#include <optional>
#include <utility>
#include "tools/weighted_bipartite_matching.hpp"

using ll = long long;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  ll N;
  std::cin >> N;
  tools::weighted_bipartite_matching<ll> graph(150, 150, true);
  for (ll i = 0; i < N; ++i) {
    ll A, B, C;
    std::cin >> A >> B >> C;
    --A, --B;
    graph.add_edge(A, B, C);
  }

  std::vector<ll> answers;
  std::optional<std::pair<ll, std::vector<std::size_t>>> matching;
  for (ll k = 1; (matching = graph.query(k)).has_value(); ++k) {
    answers.push_back(matching->first);
  }

  std::cout << answers.size() << '\n';
  for (const auto answer : answers) {
    std::cout << answer << '\n';
  }
  return 0;
}
