// competitive-verifier: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A
// oj-verify currently cannot handle https://onlinejudge.u-aizu.ac.jp/problems/GRL_4_B properly, so I implemented a special judge for the problem.

#include <iostream>
#include <cstddef>
#include "tools/assert_that.hpp"
#include "tools/tsort.hpp"
#include "tools/permutation.hpp"

void verify(const tools::tsort& graph) {
  const auto result = [&]() {
    const auto r = graph.query();
    return tools::permutation<std::size_t>(r.begin(), r.end());
  }();

  assert_that(result.size() == graph.size());
  for (const auto& edge : graph.edges()) {
    assert_that(result.inv(edge.from) < result.inv(edge.to));
  }
}

void sample_00() {
  tools::tsort graph(6);
  graph.add_edge(0, 1);
  graph.add_edge(1, 2);
  graph.add_edge(3, 1);
  graph.add_edge(3, 4);
  graph.add_edge(4, 5);
  graph.add_edge(5, 2);
  verify(graph);
}

void small_00() {
  tools::tsort graph(5);
  graph.add_edge(0, 1);
  graph.add_edge(0, 2);
  graph.add_edge(2, 3);
  graph.add_edge(2, 4);
  graph.add_edge(3, 4);
  verify(graph);
}

void small_01() {
  tools::tsort graph(6);
  graph.add_edge(0, 1);
  graph.add_edge(0, 3);
  graph.add_edge(0, 2);
  graph.add_edge(2, 3);
  graph.add_edge(1, 4);
  graph.add_edge(3, 5);
  graph.add_edge(4, 5);
  verify(graph);
}

void small_02() {
  tools::tsort graph(8);
  graph.add_edge(0, 1);
  graph.add_edge(0, 2);
  graph.add_edge(2, 1);
  graph.add_edge(1, 3);
  graph.add_edge(2, 3);
  graph.add_edge(2, 4);
  graph.add_edge(3, 4);
  graph.add_edge(3, 5);
  graph.add_edge(4, 6);
  graph.add_edge(5, 7);
  graph.add_edge(6, 7);
  verify(graph);
}

void small_03() {
  tools::tsort graph(8);
  graph.add_edge(0, 1);
  graph.add_edge(0, 3);
  graph.add_edge(1, 2);
  graph.add_edge(4, 5);
  graph.add_edge(4, 7);
  graph.add_edge(5, 7);
  graph.add_edge(7, 6);
  verify(graph);
}

void small_04() {
  tools::tsort graph(8);
  graph.add_edge(0, 7);
  graph.add_edge(1, 7);
  graph.add_edge(2, 7);
  graph.add_edge(3, 7);
  graph.add_edge(4, 7);
  graph.add_edge(5, 7);
  graph.add_edge(6, 7);
  verify(graph);
}

void small_05() {
  tools::tsort graph(9);
  graph.add_edge(1, 2);
  graph.add_edge(3, 4);
  graph.add_edge(5, 6);
  graph.add_edge(7, 8);
  graph.add_edge(0, 2);
  graph.add_edge(0, 3);
  graph.add_edge(0, 6);
  graph.add_edge(0, 7);
  verify(graph);
}

void small_06() {
  tools::tsort graph(5);
  graph.add_edge(0, 1);
  graph.add_edge(0, 2);
  graph.add_edge(2, 3);
  graph.add_edge(2, 4);
  graph.add_edge(3, 4);
  verify(graph);
}

void corner_00() {
  tools::tsort graph(2);
  graph.add_edge(0, 1);
  verify(graph);
}

void corner_01() {
  tools::tsort graph(2);
  verify(graph);
}

void corner_02() {
  tools::tsort graph(4);
  graph.add_edge(0, 1);
  graph.add_edge(2, 3);
  verify(graph);
}

void corner_03() {
  tools::tsort graph(3);
  graph.add_edge(0, 2);
  graph.add_edge(1, 2);
  verify(graph);
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  sample_00();
  small_00();
  small_01();
  small_02();
  small_03();
  small_04();
  small_05();
  small_06();
  corner_00();
  corner_01();
  corner_02();
  corner_03();

  std::cout << "Hello World" << '\n';
  return 0;
}
