#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_9_C"

#include <cstdint>
#include <iostream>
#include <string>
#include <utility>
#include "tools/binary_heap.hpp"

using i64 = std::int_fast64_t;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  tools::binary_heap<i64, i64> heap;
  i64 id = 0;

  std::string instruction;
  while (true) {
    std::cin >> instruction;
    if (instruction == "insert") {
      i64 k;
      std::cin >> k;
      heap.push(std::make_pair(id++, k));
    } else if (instruction == "extract") {
      std::cout << heap.top().second << '\n';
      heap.pop();
    } else {
      break;
    }
  }

  return 0;
}
