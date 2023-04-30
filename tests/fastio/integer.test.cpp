#define PROBLEM "https://judge.yosupo.jp/problem/many_aplusb"

#include <iostream>
#include "tools/cin.hpp"
#include "tools/cout.hpp"

using ll = long long;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int T;
  tools::cin >> T;
  for (int i = 0; i < T; ++i) {
    ll A, B;
    tools::cin >> A >> B;
    tools::cout << A + B << '\n';
  }

  return 0;
}
