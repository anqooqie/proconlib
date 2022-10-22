#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/CGL_7_E"
#define ERROR 1e-6

#include <iostream>
#include <vector>
#include <cstdlib>
#include <utility>
#include <algorithm>
#include <variant>
#include <iomanip>
#include "tools/vector2.hpp"
#include "tools/circle_2d.hpp"
#include "tools/less_by.hpp"

using T = double;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  T c1x, c1y, c1r, c2x, c2y, c2r;
  std::cin >> c1x >> c1y >> c1r >> c2x >> c2y >> c2r;

  const tools::circle_2d<T, false, true> c1(tools::vector2<T>(c1x, c1y), c1r);
  const tools::circle_2d<T, false, true> c2(tools::vector2<T>(c2x, c2y), c2r);

  struct {
    std::vector<tools::vector2<T>> operator()(const tools::circle_2d<T, false, true>&) {
      std::exit(EXIT_FAILURE);
    }
    std::vector<tools::vector2<T>> operator()(const std::vector<tools::vector2<T>>& intersections) {
      if (intersections.size() == 1) {
        return std::vector<tools::vector2<T>>({intersections[0], intersections[0]});
      } else if (intersections.size() == 2) {
        const auto comp = tools::less_by([](const auto& p) { return std::make_pair(p.x, p.y); });
        const auto [p1, p2] = std::minmax({intersections[0], intersections[1]}, comp);
        return std::vector<tools::vector2<T>>({p1, p2});
      } else {
        std::exit(EXIT_FAILURE);
      }
    }
  } visitor;
  const auto answers = std::visit(visitor, *(c1 & c2));

  std::cout << std::fixed << std::setprecision(10) << answers[0].x << ' ' << answers[0].y << ' ' << answers[1].x << ' ' << answers[1].y << '\n';
  return 0;
}
