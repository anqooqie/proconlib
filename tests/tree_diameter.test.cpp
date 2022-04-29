#define PROBLEM "https://judge.yosupo.jp/problem/tree_diameter"

#include <cstdint>
#include <iostream>
#include <vector>
#include <utility>
#include "tools/tree_diameter.hpp"
#include "tools/join.hpp"

using i64 = std::int_fast64_t;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  i64 N;
  std::cin >> N;
  tools::tree_diameter<i64> tree(N);
  std::vector<std::pair<i64, i64>> edges;
  for (i64 i = 0; i < N - 1; ++i) {
    i64 a, b, c;
    std::cin >> a >> b >> c;
    tree.add_edge(a, b, c);
    edges.emplace_back(a, b);
  }

  const auto [X, u, unused] = tree.query();
  std::cout << X << ' ' << u.size() << '\n';
  std::cout << ::tools::join(u.begin(), u.end(), " ") << '\n';
  return 0;
}
