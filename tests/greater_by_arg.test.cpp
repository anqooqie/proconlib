// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/sort_points_by_argument

#include <algorithm>
#include <iostream>
#include <vector>
#include "tools/greater_by_arg.hpp"
#include "tools/vector2.hpp"

using ll = long long;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  constexpr ll max_abs_p_i = 1000000000;

  int N;
  std::cin >> N;
  std::vector<tools::vector2<ll>> p(N);
  for (auto& p_i : p) {
    std::cin >> p_i;
    if (p_i.x == 0 && p_i.y == 0) {
      p_i.x = max_abs_p_i + 1;
    }
  }

  std::sort(p.rbegin(), p.rend(), tools::greater_by_arg(tools::vector2<ll>(0, 0), tools::vector2<ll>(-max_abs_p_i - 1, -1)));

  for (auto& p_i : p) {
    if (p_i.x == max_abs_p_i + 1) p_i.x = 0;
    std::cout << p_i.x << ' ' << p_i.y << '\n';
  }
}
