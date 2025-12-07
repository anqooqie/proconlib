// competitive-verifier: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/CGL_3_C

#include <iostream>
#include <vector>
#include "tools/polygon_2d.hpp"
#include "tools/vector2.hpp"

using ll = long long;
using T = std::int_fast64_t;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  ll n;
  std::cin >> n;
  tools::polygon_2d<T, false> polygon([&]() {
    std::vector<tools::vector2<T>> g(n);
    for (auto& g_i : g) std::cin >> g_i;
    return g;
  }());

  ll Q;
  std::cin >> Q;
  for (ll q = 0; q < Q; ++q) {
    tools::vector2<T> p;
    std::cin >> p;
    std::cout << polygon.where(p) + 1 << '\n';
  }

  return 0;
}
