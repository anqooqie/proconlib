#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/CGL_4_A"

#include <cstdint>
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <utility>
#include "tools/vector2.hpp"
#include "tools/convex_hull.hpp"
#include "tools/less_by.hpp"

using i64 = std::int_fast64_t;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  i64 n;
  std::cin >> n;
  std::vector<tools::vector2<i64>> v(n);
  for (i64 i = 0; i < n; ++i) {
    std::cin >> v[i].x >> v[i].y;
  }

  std::vector<i64> convex_hull;
  tools::convex_hull(v.begin(), v.end(), false, std::back_inserter(convex_hull));

  std::rotate(
    convex_hull.begin(),
    std::min_element(convex_hull.begin(), convex_hull.end(), tools::less_by([&](const i64& i) { return std::make_pair(v[i].y, v[i].x); })),
    convex_hull.end()
  );

  std::cout << convex_hull.size() << '\n';
  for (const i64& i : convex_hull) {
    std::cout << v[i].x << ' ' << v[i].y << '\n';
  }
  return 0;
}
