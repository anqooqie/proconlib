// competitive-verifier: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/CGL_3_A

#include <iomanip>
#include <ios>
#include <iostream>
#include <vector>
#include "tools/bigint.hpp"
#include "tools/polygon_2d.hpp"
#include "tools/rational.hpp"
#include "tools/vector2.hpp"

using ll = long long;
using T = tools::rational<tools::bigint>;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  ll n;
  std::cin >> n;
  tools::polygon_2d<T, true> polygon([&]() {
    std::vector<tools::vector2<T>> g(n);
    for (auto& g_i : g) std::cin >> g_i;
    return g;
  }());

  std::cout << std::fixed << std::setprecision(1) << static_cast<double>(polygon.area()) << '\n';
  return 0;
}
