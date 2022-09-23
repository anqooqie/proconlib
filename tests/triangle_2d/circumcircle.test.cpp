#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/CGL_7_C"
#define ERROR 1e-6

#include <iostream>
#include <array>
#include <iomanip>
#include <cmath>
#include "tools/vector2.hpp"
#include "tools/rational.hpp"
#include "tools/triangle_2d.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  std::array<tools::vector2<tools::rational>, 3> p;
  std::cin >> p[0] >> p[1] >> p[2];
  const auto circumcircle = tools::triangle_2d<tools::rational, false>(p.begin(), p.end()).circumcircle();
  std::cout << std::fixed << std::setprecision(10) << static_cast<double>(circumcircle.center().x) << ' ' << static_cast<double>(circumcircle.center().y) << ' ' << std::sqrt(static_cast<double>(circumcircle.squared_radius())) << '\n';

  return 0;
}
