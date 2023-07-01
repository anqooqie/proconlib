#define PROBLEM "https://atcoder.jp/contests/abc292/tasks/abc292_f"
#define ERROR 1e-9

#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include "tools/golden_section_search.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  double A, B;
  std::cin >> A >> B;

  const auto pi = std::acos(-1);
  static const auto f = [&](const auto theta) { return std::min(B / std::cos(theta), A / std::sin(pi / 3 + theta)); };

  std::cout << std::fixed << std::setprecision(10) << tools::golden_section_search(0.0, pi / 6, f, true).second << '\n';
  return 0;
}
