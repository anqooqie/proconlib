#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/CGL_1_A"
#define ERROR 1e-9

#include <cstdint>
#include <iostream>
#include "tools/rational.hpp"
#include "tools/vector2.hpp"
#include "tools/line_2d.hpp"

using i64 = std::int_fast64_t;
using T = tools::rational;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  tools::vector2<T> p1, p2;
  std::cin >> p1 >> p2;
  const auto l = tools::line_2d<T>::through(p1, p2);
  i64 q;
  std::cin >> q;
  for (i64 i = 0; i < q; ++i) {
    tools::vector2<T> p;
    std::cin >> p;
    const auto x = l.projection(p);
    std::cout << std::fixed << std::setprecision(10) << static_cast<double>(x.x) << ' ' << static_cast<double>(x.y) << '\n';
  }

  return 0;
}
