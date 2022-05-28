#define PROBLEM "https://judge.yosupo.jp/problem/sort_points_by_argument"

#include <cstdint>
#include <iostream>
#include "tools/vector2.hpp"
#include "tools/greater_by_arg_total.hpp"

using i64 = std::int_fast64_t;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  i64 N;
  std::cin >> N;
  std::vector<tools::vector2<i64>> p(N);
  for (auto& p_i : p) std::cin >> p_i;

  std::sort(p.rbegin(), p.rend(), tools::greater_by_arg_total(tools::vector2<i64>(0, 0), tools::vector2<i64>(-1000000001, -1)));

  for (const auto& p_i : p) {
    std::cout << p_i.x << ' ' << p_i.y << '\n';
  }
}
