#define PROBLEM "https://judge.yosupo.jp/problem/many_aplusb"

#include <iostream>
#include "tools/fastio.hpp"

using ll = long long;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int T;
  fastio::rd(T);
  for (int i = 0; i < T; ++i) {
    ll A, B;
    fastio::rd(A);
    fastio::rd(B);
    fastio::wtn(A + B);
  }

  return 0;
}
