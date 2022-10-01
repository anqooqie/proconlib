#define PROBLEM "https://atcoder.jp/contests/abc270/tasks/abc270_c"

#include <iostream>
#include <string>
#include <limits>
#include <cstddef>
#include "tools/zero_one_bfs.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int N, X, Y;
  std::cin >> N >> X >> Y;
  --X, --Y;
  tools::zero_one_bfs<false, int> graph(N);
  for (int i = 0; i < N - 1; ++i) {
    int U, V;
    std::cin >> U >> V;
    --U, --V;
    graph.add_edge(U, V, 1);
  }

  const auto prev = graph.query(Y).second;
  std::string delimiter;
  for (int here = X; here >= 0; here = (prev[here] < std::numeric_limits<std::size_t>::max() ? graph.get_edge(prev[here]).from ^ graph.get_edge(prev[here]).to ^ here : -1)) {
    std::cout << delimiter << here + 1;
    delimiter = " ";
  }
  std::cout << '\n';

  return 0;
}
