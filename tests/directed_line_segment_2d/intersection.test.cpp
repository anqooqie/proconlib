#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/CGL_2_B"

#include <cstdint>
#include <iostream>
#include "tools/vector2.hpp"
#include "tools/directed_line_segment_2d.hpp"
#include "tools/rational.hpp"

using i64 = std::int_fast64_t;
using T = tools::rational;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  i64 q;
  std::cin >> q;
  for (i64 i = 0; i < q; ++i) {
    tools::vector2<T> p0, p1, p2, p3;
    std::cin >> p0 >> p1 >> p2 >> p3;

    const tools::directed_line_segment_2d<T> s1(p0, p1);
    const tools::directed_line_segment_2d<T> s2(p2, p3);

    std::cout << (s1.intersection(s2) ? 1 : 0) << '\n';
  }

  return 0;
}
