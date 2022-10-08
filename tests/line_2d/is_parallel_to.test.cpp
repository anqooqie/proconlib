#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/CGL_2_A"

#include <iostream>
#include "tools/vector2.hpp"
#include "tools/line_2d.hpp"

using ll = long long;
using T = long long;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  ll q;
  std::cin >> q;
  for (ll i = 0; i < q; ++i) {
    tools::vector2<T> p0, p1, p2, p3;
    std::cin >> p0 >> p1 >> p2 >> p3;

    const auto s1 = tools::line_2d<T>::through(p0, p1);
    const auto s2 = tools::line_2d<T>::through(p2, p3);

    if (s1.is_parallel_to(s2)) {
      std::cout << 2 << '\n';
    } else if (tools::vector2<T>(s1.a(), s1.b()).inner_product(tools::vector2<T>(s2.a(), s2.b())) == T(0)) {
      std::cout << 1 << '\n';
    } else {
      std::cout << 0 << '\n';
    }
  }

  return 0;
}
