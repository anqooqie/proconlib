// competitive-verifier: STANDALONE
// Source: https://atcoder.jp/contests/abc270/tasks/abc270_f

#include <iostream>
#include <limits>
#include <vector>
#include "tools/assert_that.hpp"
#include "tools/chmin.hpp"
#include "tools/popcount.hpp"
#include "tools/prim.hpp"

using ll = long long;

ll solve(const ll N, const ll M, const std::vector<ll>& X, const std::vector<ll>& Y, const std::vector<ll>& A, const std::vector<ll>& B, const std::vector<ll>& Z) {
  auto answer = std::numeric_limits<ll>::max();
  for (ll state = 0; state < 4; ++state) {
    tools::prim<ll> graph(N + tools::popcount(state));
    if (state & 1) {
      for (ll i = 0; i < N; ++i) {
        graph.add_edge(i, N, X[i]);
      }
    }
    if (state & 2) {
      for (ll i = 0; i < N; ++i) {
        graph.add_edge(i, N + (state & 1), Y[i]);
      }
    }
    for (ll i = 0; i < M; ++i) {
      graph.add_edge(A[i], B[i], Z[i]);
    }
    if (const auto costs = graph.query(); costs.size() == 1) {
      tools::chmin(answer, costs[0]);
    }
  }
  return answer;
}

void sample_01() {
  const ll N = 4;
  const ll M = 2;
  const std::vector<ll> X = {1, 20, 4, 7};
  const std::vector<ll> Y = {20, 2, 20, 3};
  const std::vector<ll> A = {0, 0};
  const std::vector<ll> B = {2, 3};
  const std::vector<ll> Z = {5, 6};
  assert_that(solve(N, M, X, Y, A, B, Z) == 16);
}

void sample_02() {
  const ll N = 3;
  const ll M = 1;
  const std::vector<ll> X = {1, 1, 1};
  const std::vector<ll> Y = {10, 10, 10};
  const std::vector<ll> A = {0};
  const std::vector<ll> B = {1};
  const std::vector<ll> Z = {100};
  assert_that(solve(N, M, X, Y, A, B, Z) == 3);
}

void sample_03() {
  const ll N = 7;
  const ll M = 8;
  const std::vector<ll> X = {35, 29, 36, 88, 58, 15, 25};
  const std::vector<ll> Y = {99, 7, 49, 61, 67, 4, 57};
  const std::vector<ll> A = {1, 1, 1, 0, 4, 0, 2, 4};
  const std::vector<ll> B = {2, 4, 5, 5, 6, 2, 3, 5};
  const std::vector<ll> Z = {3, 36, 89, 24, 55, 71, 94, 21};
  assert_that(solve(N, M, X, Y, A, B, Z) == 160);
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  sample_01();
  sample_02();
  sample_03();

  return 0;
}
