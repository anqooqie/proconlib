#define PROBLEM "https://atcoder.jp/contests/abc247/tasks/abc247_g"

#include <cstdint>
#include <iostream>
#include <vector>
#include <optional>
#include <utility>
#include "tools/weighted_bipartite_matching.hpp"

using i64 = std::int_fast64_t;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  i64 N;
  std::cin >> N;
  tools::weighted_bipartite_matching<i64> graph(150, 150, true);
  for (i64 i = 0; i < N; ++i) {
    i64 A, B, C;
    std::cin >> A >> B >> C;
    --A, --B;
    graph.add_edge(A, B, C);
  }

  std::vector<i64> answers;
  std::optional<std::pair<i64, std::vector<tools::weighted_bipartite_matching<i64>::edge>>> matching;
  for (i64 k = 1; (matching = graph.query(k)).has_value(); ++k) {
    answers.push_back(matching->first);
  }

  std::cout << answers.size() << '\n';
  for (const auto answer : answers) {
    std::cout << answer << '\n';
  }
  return 0;
}
