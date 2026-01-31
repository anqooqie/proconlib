// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/cartesian_tree

#include <iostream>
#include <vector>
#include "tools/cartesian_tree.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int N;
  std::cin >> N;
  std::vector<int> a(N);
  for (auto& a_i : a) std::cin >> a_i;

  const tools::cartesian_tree cartesian_tree(a);
  for (int i = 0; i < N; ++i) {
    if (i) std::cout << ' ';
    auto p = cartesian_tree.get_vertex(i).parent;
    if (p == -1) p = i;
    std::cout << p;
  }
  std::cout << '\n';

  return 0;
}
