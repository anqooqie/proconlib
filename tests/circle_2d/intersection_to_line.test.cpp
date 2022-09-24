#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/CGL_7_D"
#define ERROR 1e-6

#include <iostream>
#include <cassert>
#include <algorithm>
#include <utility>
#include <iomanip>
#include "tools/vector2.hpp"
#include "tools/circle_2d.hpp"
#include "tools/line_2d.hpp"
#include "tools/less_by.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  double cx, cy, r;
  std::cin >> cx >> cy >> r;
  tools::circle_2d<double, false> c(tools::vector2<double>(cx, cy), r);
  int Q;
  std::cin >> Q;
  for (int q = 0; q < Q; ++q) {
    double x1, y1, x2, y2;
    std::cin >> x1 >> y1 >> x2 >> y2;
    auto res = c & tools::line_2d<double>::through(tools::vector2<double>(x1, y1), tools::vector2<double>(x2, y2));
    assert(!res.empty());
    if (res.size() == 1) res.push_back(res[0]);
    std::sort(res.begin(), res.end(), tools::less_by([](const auto& p) { return std::make_pair(p.x, p.y); }));
    std::cout << std::fixed << std::setprecision(10) << res[0].x << ' ' << res[0].y << ' ' << res[1].x << ' ' << res[1].y << '\n';
  }

  return 0;
}
