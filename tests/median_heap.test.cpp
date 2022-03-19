#define PROBLEM "https://atcoder.jp/contests/abc127/tasks/abc127_f"

#include <cstdint>
#include <iostream>
#include "tools/median_heap.hpp"

using i64 = std::int_fast64_t;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  i64 Q;
  std::cin >> Q;

  tools::median_heap<i64> heap;
  i64 min = 0;
  for (i64 i = 0; i < Q; ++i) {
    i64 t;
    std::cin >> t;
    if (t == 1) {
      i64 a, b;
      std::cin >> a >> b;

      const bool uses_prev_median = heap.size() % 2 == 1 && a < heap.lesser();
      if (uses_prev_median) {
        min += std::abs(heap.lesser() - a) + b;
      }
      heap.push(a);
      if (!uses_prev_median) {
        min += std::abs(heap.lesser() - a) + b;
      }
    } else {
      std::cout << heap.lesser() << ' ' << min << '\n';
    }
  }

  return 0;
}
