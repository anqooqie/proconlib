// competitive-verifier: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/CGL_1_A
// competitive-verifier: ERROR 1e-9

#include <iostream>
#include "tools/bigint.hpp"
#include "tools/rational.hpp"
#include "tools/vector2.hpp"
#include "tools/line_2d.hpp"

using ll = long long;
using T = tools::rational<tools::bigint>;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  tools::vector2<T> p1, p2;
  std::cin >> p1 >> p2;
  const auto l = tools::line_2d<T>::through(p1, p2);
  ll q;
  std::cin >> q;
  for (ll i = 0; i < q; ++i) {
    tools::vector2<T> p;
    std::cin >> p;
    const auto x = l.projection(p);
    std::cout << std::fixed << std::setprecision(10) << static_cast<double>(x.x) << ' ' << static_cast<double>(x.y) << '\n';
  }

  return 0;
}
