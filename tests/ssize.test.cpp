#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A"

#include <iostream>
#include "tools/assert_that.hpp"
#include "tools/binary_heap.hpp"
#include "tools/ssize.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  assert_that(tools::ssize(std::vector<int>({1, 2, 3})) == 3);

  tools::binary_heap<int, int> heap;
  heap.emplace(1, 1);
  heap.emplace(2, 2);
  heap.emplace(3, 3);
  assert_that(tools::ssize(heap) == 3);

  std::cout << "Hello World" << '\n';
  return 0;
}
