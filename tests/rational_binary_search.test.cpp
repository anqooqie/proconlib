#define PROBLEM "https://judge.yosupo.jp/problem/rational_approximation"

#include <iostream>
#include <tuple>
#include <utility>
#include "tools/rational_binary_search.hpp"

using ll = long long;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int T;
  std::cin >> T;
  for (int t = 0; t < T; ++t) {
    ll N, x, y;
    std::cin >> N >> x >> y;
    if (x < y) {
      auto [p1, q1, p2, q2] = tools::rational_binary_search(0LL, 1LL, 1LL, 0LL, [&](const auto& p, const auto& q) { return p * y <= x * q; }, N);
      if (p1 * y == x * q1) std::tie(p2, q2) = std::make_pair(p1, q1);
      std::cout << p1 << ' ' << q1 << ' ' << p2 << ' ' << q2 << '\n';
    } else {
      auto [q2, p2, q1, p1] = tools::rational_binary_search(0LL, 1LL, 1LL, 0LL, [&](const auto& q, const auto& p) { return q * x <= y * p; }, N);
      if (q2 * x == y * p2) std::tie(p1, q1) = std::make_pair(p2, q2);
      std::cout << p1 << ' ' << q1 << ' ' << p2 << ' ' << q2 << '\n';
    }
  }

  return 0;
}
