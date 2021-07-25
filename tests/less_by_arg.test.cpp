#define PROBLEM "https://judge.yosupo.jp/problem/sort_points_by_argument"

#include <cstdint>
#include <iostream>
#include "tools/vector2.hpp"
#include "tools/less_by_arg.hpp"

using i64 = std::int_fast64_t;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  i64 N;
  std::cin >> N;
  std::vector<tools::vector2<i64>> p(N);
  for (auto& p_i : p) std::cin >> p_i;

  std::sort(p.begin(), p.end(), tools::less_by_arg(tools::vector2<i64>(-1000000001, -1)));

  for (const auto& p_i : p) {
    std::cout << p_i.x << ' ' << p_i.y << '\n';
  }
}
