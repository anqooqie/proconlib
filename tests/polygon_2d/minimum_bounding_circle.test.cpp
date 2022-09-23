#define PROBLEM "https://atcoder.jp/contests/abc151/tasks/abc151_f"
#define ERROR 1e-6

#include <cstdint>
#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include "tools/vector2.hpp"
#include "tools/convex_hull.hpp"
#include "tools/rational.hpp"
#include "tools/polygon_2d.hpp"

using i64 = std::int_fast64_t;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  i64 N;
  std::cin >> N;
  std::vector<tools::vector2<i64>> v(N);
  for (auto& v_i : v) std::cin >> v_i;

  if (N == 2) {
    std::cout << std::fixed << std::setprecision(18) << (v[1] - v[0]).l2_norm() / 2.0 << '\n';
    return 0;
  }

  std::vector<i64> convex_hull;
  tools::convex_hull(v.begin(), v.end(), true, std::back_inserter(convex_hull));

  if (convex_hull.size() == 2) {
    std::cout << std::fixed << std::setprecision(18) << (v[convex_hull[1]] - v[convex_hull[0]]).l2_norm() / 2.0 << '\n';
    return 0;
  }

  std::vector<tools::vector2<tools::rational>> v2;
  for (const auto& i : convex_hull) {
    v2.emplace_back(tools::rational(v[i].x), tools::rational(v[i].y));
  }

  std::cout << std::fixed << std::setprecision(18) << std::sqrt(static_cast<double>(tools::polygon_2d<tools::rational, false>(v2.begin(), v2.end()).minimum_bounding_circle().squared_radius())) << '\n';
  return 0;
}
