// competitive-verifier: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/CGL_7_C
// competitive-verifier: ERROR 1e-6

#include <array>
#include <cmath>
#include <iomanip>
#include <ios>
#include <iostream>
#include "tools/triangle_2d.hpp"
#include "tools/vector2.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  std::array<tools::vector2<double>, 3> p;
  std::cin >> p[0] >> p[1] >> p[2];
  const auto circumcircle = tools::triangle_2d<double, false>(p).circumcircle();
  std::cout << std::fixed << std::setprecision(10) << circumcircle.center().x << ' ' << circumcircle.center().y << ' ' << std::sqrt(circumcircle.squared_radius()) << '\n';

  return 0;
}
