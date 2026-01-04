// competitive-verifier: STANDALONE
// Source: https://atcoder.jp/contests/abc247/tasks/abc247_g

#include <iostream>
#include <optional>
#include <vector>
#include "tools/assert_that.hpp"
#include "tools/weighted_bipartite_matching.hpp"

using ll = long long;

std::vector<ll> solve(const ll N, const std::vector<ll>& A, const std::vector<ll>& B, const std::vector<ll>& C) {
  tools::weighted_bipartite_matching<true, ll> graph(150, 150);
  for (ll i = 0; i < N; ++i) {
    graph.add_edge(A[i], B[i], C[i]);
  }

  std::vector<ll> answers;
  std::optional<ll> matching;
  for (ll k = 1; (matching = graph.query(k)).has_value(); ++k) {
    answers.push_back(*matching);
  }

  return answers;
}

void sample_01() {
  const ll N = 3;
  const std::vector<ll> A = {0, 0, 1};
  const std::vector<ll> B = {0, 19, 0};
  const std::vector<ll> C = {100, 10, 1};
  assert_that(solve(N, A, B, C) == std::vector<ll>{100, 11});
}

void sample_02() {
  const ll N = 10;
  const std::vector<ll> A = {0, 1, 2, 4, 1, 1, 2, 4, 0, 4};
  const std::vector<ll> B = {3, 5, 0, 0, 1, 3, 6, 1, 6, 2};
  const std::vector<ll> C = {142135623, 457513110, 622776601, 961524227, 360679774, 494897427, 416573867, 915026221, 320508075, 851648071};
  assert_that(solve(N, A, B, C) == std::vector<ll>{961524227, 1537802822, 2032700249, 2353208324});
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  sample_01();
  sample_02();

  return 0;
}
