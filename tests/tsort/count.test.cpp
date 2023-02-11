#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A"
// Source: https://atcoder.jp/contests/abc041/tasks/abc041_d

#include <iostream>
#include "tools/assert_that.hpp"
#include "tools/tsort.hpp"

void sample_01() {
  tools::tsort graph(3);
  graph.add_edge(1, 0);
  graph.add_edge(1, 2);
  assert_that(graph.count() == 2);
}

void sample_02() {
  tools::tsort graph(5);
  graph.add_edge(0, 1);
  graph.add_edge(1, 2);
  graph.add_edge(2, 4);
  graph.add_edge(0, 3);
  graph.add_edge(3, 4);
  assert_that(graph.count() == 3);
}

void sample_03() {
  tools::tsort graph(16);
  graph.add_edge(0, 1);
  assert_that(graph.count() == 10461394944000);
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  sample_01();
  sample_02();
  sample_03();

  std::cout << "Hello World" << '\n';
  return 0;
}
