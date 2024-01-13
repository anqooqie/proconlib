#define PROBLEM "https://judge.yosupo.jp/problem/stirling_number_of_the_first_kind"

#include <iostream>
#include "atcoder/modint.hpp"
#include "tools/stirling_1st.hpp"

using mint = atcoder::modint998244353;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int N;
  std::cin >> N;

  const auto s = tools::stirling_1st<mint>(N);

  std::cout << s[0].val();
  for (int i = 1; i <= N; ++i) {
    std::cout << ' ' << s[i].val();
  }
  std::cout << '\n';

  return 0;
}
