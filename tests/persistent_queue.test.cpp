// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/persistent_queue

#include <iostream>
#include <vector>
#include "tools/assert_that.hpp"
#include "tools/persistent_queue.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  {
    std::vector<tools::persistent_queue<int>> S;
    S.emplace_back();
    int Q;
    std::cin >> Q;
    while (Q--) {
      int type;
      std::cin >> type;
      if (type == 0) {
        int t, x;
        std::cin >> t >> x;
        ++t;
        S.push_back(S[t].push(x));
      } else {
        int t;
        std::cin >> t;
        ++t;
        std::cout << S[t].front() << '\n';
        S.push_back(S[t].pop());
      }
    }
  }

  assert_that(tools::persistent_queue<int>::fully_released());
  return 0;
}
