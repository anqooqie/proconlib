#define PROBLEM "https://judge.yosupo.jp/problem/persistent_queue"

#include <cstdint>
#include <iostream>
#include "tools/persistent_queue.hpp"

using i64 = std::int_fast64_t;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  tools::persistent_queue_buffer<i64> S;
  S.emplace_back();
  i64 Q;
  std::cin >> Q;
  for (i64 q = 0; q < Q; ++q) {
    i64 type;
    std::cin >> type;
    if (type == 0) {
      i64 t, x;
      std::cin >> t >> x;
      ++t;
      S.push_back(S[t].push(x));
    } else {
      i64 t;
      std::cin >> t;
      ++t;
      std::cout << S[t].front() << '\n';
      S.push_back(S[t].pop());
    }
  }

  return 0;
}
