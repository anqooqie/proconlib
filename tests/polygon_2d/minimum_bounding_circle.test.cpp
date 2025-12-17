// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/minimum_enclosing_circle

#include <iostream>
#include <string>
#include <vector>
#include "tools/polygon_2d.hpp"
#include "tools/vector2.hpp"

using T = long long;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int N;
  std::cin >> N;
  std::vector<tools::vector2<T>> p(N);
  for (auto& p_i : p) std::cin >> p_i;

  if (N >= 3) {
    const auto C = tools::polygon_2d<T, false>(p).minimum_bounding_circle();

    for (const auto& p_i : p) {
      std::cout << (C.contains(p_i) ? '1' : '0');
    }
  } else {
    std::cout << std::string(N, '1');
  }
  std::cout << '\n';

  return 0;
}
