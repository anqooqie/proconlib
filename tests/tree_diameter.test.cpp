#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_A"

#include <cstdint>
#include <iostream>
#include "tools/tree_diameter.hpp"

using i64 = std::int_fast64_t;

int main() {
  i64 n;
  std::cin >> n;
  tools::tree_diameter<i64> tree(n);
  for (i64 i = 0; i < n - 1; ++i) {
    i64 s, t, w;
    std::cin >> s >> t >> w;
    tree.add_edge(s, t, w);
  }
  std::cout << tree.query() << '\n';
  return 0;
}
