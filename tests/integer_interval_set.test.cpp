#define PROBLEM "https://atcoder.jp/contests/abc228/tasks/abc228_d"

#include <cstdint>
#include <iostream>
#include <vector>
#include "tools/pow2.hpp"
#include "tools/integer_interval_set.hpp"

using i64 = std::int_fast64_t;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  const i64 N = tools::pow2(20);
  std::vector<i64> A(N, -1);
  tools::integer_interval_set<i64> set;

  i64 Q;
  std::cin >> Q;
  for (i64 q = 0; q < Q; ++q) {
    i64 t, x;
    std::cin >> t >> x;
    if (t == 1) {
      const i64 h = [&]() -> i64 {
        if (auto it = set.find(x % N); it != set.end()) {
          if (it->second == N - 1) {
            if (auto it2 = set.find(0); it2 != set.end()) {
              return it2->second + 1;
            } else {
              return 0;
            }
          } else {
            return it->second + 1;
          }
        } else {
          return x % N;
        }
      }();
      A[h] = x;
      set.insert(h, h);
    } else {
      std::cout << A[x % N] << '\n';
    }
  }

  return 0;
}
