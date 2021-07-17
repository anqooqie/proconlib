#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A"
// oj-verify currently cannot handle https://onlinejudge.u-aizu.ac.jp/problems/GRL_4_B properly, so I implemented a special judge for the problem.

#include <cstdint>
#include <cstdlib>
#include <vector>
#include <utility>
#include <iostream>
#include "tools/tsort.hpp"
#include "tools/lower_bound.hpp"

using i64 = std::int_fast64_t;

void assert_that(const bool cond) {
  if (!cond) {
    std::exit(EXIT_FAILURE);
  }
}

void verify(const i64 node_count, std::vector<std::pair<i64, i64>>& edges) {

  tools::tsort tsort(node_count);
  for (const auto& [s, t] : edges) {
    tsort.add_edge(s, t);
  }

  std::vector<i64> result;
  tsort.query(std::back_inserter(result));

  assert_that(i64(result.size()) == node_count);

  std::vector<i64> order(node_count);
  for (i64 i = 0; i < node_count; ++i) {
    order[result[i]] = i;
  }
  for (const auto& [s, t] : edges) {
    assert_that(order[s] < order[t]);
  }
}

void sample_00() {
  std::vector<std::pair<i64, i64>> edges;
  edges.emplace_back(0, 1);
  edges.emplace_back(1, 2);
  edges.emplace_back(3, 1);
  edges.emplace_back(3, 4);
  edges.emplace_back(4, 5);
  edges.emplace_back(5, 2);
  verify(6, edges);
}

void small_00() {
  std::vector<std::pair<i64, i64>> edges;
  edges.emplace_back(0, 1);
  edges.emplace_back(0, 2);
  edges.emplace_back(2, 3);
  edges.emplace_back(2, 4);
  edges.emplace_back(3, 4);
  verify(5, edges);
}

void small_01() {
  std::vector<std::pair<i64, i64>> edges;
  edges.emplace_back(0, 1);
  edges.emplace_back(0, 3);
  edges.emplace_back(0, 2);
  edges.emplace_back(2, 3);
  edges.emplace_back(1, 4);
  edges.emplace_back(3, 5);
  edges.emplace_back(4, 5);
  verify(6, edges);
}

void small_02() {
  std::vector<std::pair<i64, i64>> edges;
  edges.emplace_back(0, 1);
  edges.emplace_back(0, 2);
  edges.emplace_back(2, 1);
  edges.emplace_back(1, 3);
  edges.emplace_back(2, 3);
  edges.emplace_back(2, 4);
  edges.emplace_back(3, 4);
  edges.emplace_back(3, 5);
  edges.emplace_back(4, 6);
  edges.emplace_back(5, 7);
  edges.emplace_back(6, 7);
  verify(8, edges);
}

void small_03() {
  std::vector<std::pair<i64, i64>> edges;
  edges.emplace_back(0, 1);
  edges.emplace_back(0, 3);
  edges.emplace_back(1, 2);
  edges.emplace_back(4, 5);
  edges.emplace_back(4, 7);
  edges.emplace_back(5, 7);
  edges.emplace_back(7, 6);
  verify(8, edges);
}

void small_04() {
  std::vector<std::pair<i64, i64>> edges;
  edges.emplace_back(0, 7);
  edges.emplace_back(1, 7);
  edges.emplace_back(2, 7);
  edges.emplace_back(3, 7);
  edges.emplace_back(4, 7);
  edges.emplace_back(5, 7);
  edges.emplace_back(6, 7);
  verify(8, edges);
}

void small_05() {
  std::vector<std::pair<i64, i64>> edges;
  edges.emplace_back(1, 2);
  edges.emplace_back(3, 4);
  edges.emplace_back(5, 6);
  edges.emplace_back(7, 8);
  edges.emplace_back(0, 2);
  edges.emplace_back(0, 3);
  edges.emplace_back(0, 6);
  edges.emplace_back(0, 7);
  verify(9, edges);
}

void small_06() {
  std::vector<std::pair<i64, i64>> edges;
  edges.emplace_back(0, 1);
  edges.emplace_back(0, 2);
  edges.emplace_back(2, 3);
  edges.emplace_back(2, 4);
  edges.emplace_back(3, 4);
  verify(5, edges);
}

void corner_00() {
  std::vector<std::pair<i64, i64>> edges;
  edges.emplace_back(0, 1);
  verify(2, edges);
}

void corner_01() {
  std::vector<std::pair<i64, i64>> edges;
  verify(2, edges);
}

void corner_02() {
  std::vector<std::pair<i64, i64>> edges;
  edges.emplace_back(0, 1);
  edges.emplace_back(2, 3);
  verify(4, edges);
}

void corner_03() {
  std::vector<std::pair<i64, i64>> edges;
  edges.emplace_back(0, 2);
  edges.emplace_back(1, 2);
  verify(3, edges);
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
