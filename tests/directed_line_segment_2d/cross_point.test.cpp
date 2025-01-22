// competitive-verifier: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/CGL_2_C

#include <iostream>
#include "tools/vector2.hpp"
#include "tools/directed_line_segment_2d.hpp"
#include "tools/rational.hpp"

using ll = long long;
using T = tools::rational;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  ll q;
  std::cin >> q;
  for (ll i = 0; i < q; ++i) {
    tools::vector2<T> p0, p1, p2, p3;
    std::cin >> p0 >> p1 >> p2 >> p3;

    const tools::directed_line_segment_2d<T> s1(p0, p1);
    const tools::directed_line_segment_2d<T> s2(p2, p3);
    const auto answer = *s1.cross_point(s2);

    std::cout << std::fixed << std::setprecision(10) << static_cast<double>(answer.x) << ' ' << static_cast<double>(answer.y) << '\n';
  }

  return 0;
}
