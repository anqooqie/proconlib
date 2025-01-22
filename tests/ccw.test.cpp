// competitive-verifier: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/CGL_1_C

#include <iostream>
#include "tools/vector2.hpp"
#include "tools/ccw.hpp"

using ll = long long;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  tools::vector2<ll> p0, p1;
  ll q;
  std::cin >> p0 >> p1 >> q;
  for (ll i = 0; i < q; ++i) {
    tools::vector2<ll> p2;
    std::cin >> p2;
    switch (tools::ccw(p0, p1, p2)) {
    case +1:
      std::cout << "COUNTER_CLOCKWISE" << '\n';
      break;
    case -1:
      std::cout << "CLOCKWISE" << '\n';
      break;
    case +2:
      std::cout << "ONLINE_BACK" << '\n';
      break;
    case -2:
      std::cout << "ONLINE_FRONT" << '\n';
      break;
    default: // 0
      std::cout << "ON_SEGMENT" << '\n';
      break;
    }
  }
}
