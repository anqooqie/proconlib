#define PROBLEM "https://atcoder.jp/contests/abc281/tasks/abc281_e"

#include <tuple>
#include <algorithm>
#include <limits>
#include <variant>
#include <iostream>
#include <vector>
#include "tools/avl_tree.hpp"
#include "tools/less_by_get.hpp"

using ll = long long;

using S = std::tuple<ll, ll, ll>;
struct SM {
  using T = S;
  static T op(const T& x, const T& y) {
    return T(std::max(std::get<0>(x), std::get<0>(y)), std::min(::std::get<1>(x), std::get<1>(y)), std::get<2>(x) + std::get<2>(y));
  }
  static T e() {
    return T(std::numeric_limits<ll>::min(), std::numeric_limits<ll>::max(), 0LL);
  }
};
using F = std::monostate;
struct FM {
  using T = F;
  static T op(const T& f, const T&) {
    return f;
  }
  static T e() {
    return std::monostate{};
  }
};
S mapping(const F&, const S& x) {
  return x;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int N, M, K;
  std::cin >> N >> M >> K;
  std::vector<ll> A(N);
  for (auto& A_i : A) std::cin >> A_i;

  std::vector<S> init;
  init.reserve(M);
  for (int i = 0; i < M; ++i) {
    init.emplace_back(A[i], A[i], A[i]);
  }
  std::sort(init.begin(), init.end(), tools::less_by_get<0>());

  tools::avl_tree<SM, FM, mapping> avl_tree(init);
  std::cout << std::get<2>(avl_tree.prod(0, K));
  for (int i = 1; i + M <= N; ++i) {
    avl_tree.insert(avl_tree.max_right(0, [&](const S& x) { return std::get<0>(x) < A[i + M - 1]; }), S(A[i + M - 1], A[i + M - 1], A[i + M - 1]));
    avl_tree.erase(avl_tree.min_left(M + 1, [&](const S& x) { return std::get<1>(x) >= A[i - 1]; }));
    std::cout << ' ' << std::get<2>(avl_tree.prod(0, K));
  }
  std::cout << '\n';

  return 0;
}
