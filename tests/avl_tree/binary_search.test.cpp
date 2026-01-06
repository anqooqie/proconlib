// competitive-verifier: STANDALONE
// Source: https://atcoder.jp/contests/abc281/tasks/abc281_e

#include <algorithm>
#include <iostream>
#include <limits>
#include <tuple>
#include <variant>
#include <vector>
#include "tools/assert_that.hpp"
#include "tools/avl_tree.hpp"
#include "tools/less_by_get.hpp"

using ll = long long;

using S = std::tuple<ll, ll, ll>;
struct SM {
  using T = S;
  static T op(const T& x, const T& y) {
    return T(std::max(std::get<0>(x), std::get<0>(y)), std::min(std::get<1>(x), std::get<1>(y)), std::get<2>(x) + std::get<2>(y));
  }
  static T e() {
    return T(std::numeric_limits<ll>::min(), std::numeric_limits<ll>::max(), 0LL);
  }
};

std::vector<ll> solve(const int N, const int M, const int K, const std::vector<ll>& A) {
  std::vector<S> init;
  init.reserve(M);
  for (int i = 0; i < M; ++i) {
    init.emplace_back(A[i], A[i], A[i]);
  }
  std::ranges::sort(init, tools::less_by_get<0>{});

  tools::avl_tree<SM>::buffer buffer;
  tools::avl_tree<SM> avl_tree(buffer, init);
  std::vector<ll> answers{std::get<2>(avl_tree.prod(0, K))};
  for (int i = 1; i + M <= N; ++i) {
    avl_tree.insert(avl_tree.max_right(0, [&](const S& x) { return std::get<0>(x) < A[i + M - 1]; }), S(A[i + M - 1], A[i + M - 1], A[i + M - 1]));
    avl_tree.erase(avl_tree.min_left(M + 1, [&](const S& x) { return std::get<1>(x) >= A[i - 1]; }));
    answers.push_back(std::get<2>(avl_tree.prod(0, K)));
  }

  return answers;
}

void sample_01() {
  const int N = 6;
  const int M = 4;
  const int K = 3;
  const std::vector<ll> A{3, 1, 4, 1, 5, 9};
  assert_that(solve(N, M, K, A) == std::vector<ll>{5, 6, 10});
}

void sample_02() {
  const int N = 10;
  const int M = 6;
  const int K = 3;
  const std::vector<ll> A{12, 2, 17, 11, 19, 8, 4, 3, 6, 20};
  assert_that(solve(N, M, K, A) == std::vector<ll>{21, 14, 15, 13, 13});
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  sample_01();
  sample_02();

  return 0;
}
