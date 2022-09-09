#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/CGL_7_B"
#define ERROR 1e-6

#include <iostream>
#include <array>
#include <iomanip>
#include "tools/vector2.hpp"
#include "tools/triangle_2d.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  std::array<tools::vector2<double>, 3> p;
  std::cin >> p[0] >> p[1] >> p[2];
  const auto incircle = tools::triangle_2d<double>(p.begin(), p.end()).incircle();
  std::cout << std::fixed << std::setprecision(10) << incircle.center().x << ' ' << incircle.center().y << ' ' << incircle.radius() << '\n';

  return 0;
}
