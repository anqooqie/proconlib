#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/CGL_7_A"

#include <iostream>
#include "tools/vector2.hpp"
#include "tools/circle_2d.hpp"

using ll = long long;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  ll c1x, c1y, c1r, c2x, c2y, c2r;
  std::cin >> c1x >> c1y >> c1r >> c2x >> c2y >> c2r;
  std::cout << tools::circle_2d<ll, false, false>(tools::vector2<ll>(c1x, c1y), c1r * c1r).where(tools::circle_2d<ll, false, false>(tools::vector2<ll>(c2x, c2y), c2r * c2r)).first << '\n';
  return 0;
}
