#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_A"

#include <cstdint>
#include <iostream>
#include <algorithm>
#include <variant>
#include <vector>
#include "tools/dp_with_rerooting.hpp"

using i64 = std::int_fast64_t;

struct monoid {
  using T = i64;
  static T op(const T x, const T y) {
    return std::max(x, y);
  }
  static T e() {
    return 0;
  }
};

i64 f_ve(const i64 w, const i64 vertex) {
  return w + vertex;
}
i64 f_ev(std::monostate, const i64 edge) {
  return edge;
}

int main() {
  i64 n;
  std::cin >> n;

  tools::dp_with_rerooting<std::monostate, i64, i64, monoid, f_ve, f_ev> dp;
  for (i64 i = 0; i < n; ++i) {
    dp.add_vertex(std::monostate());
  }
  for (i64 i = 0; i < n - 1; ++i) {
    i64 s, t, w;
    std::cin >> s >> t >> w;
    dp.add_edge(s, t, w);
  }

  const std::vector<i64> result = dp.query();
  std::cout << *std::max_element(result.begin(), result.end()) << '\n';
  return 0;
}
