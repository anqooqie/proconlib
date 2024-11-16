#define PROBLEM "https://judge.yosupo.jp/problem/bell_number"

#include <iostream>
#include "atcoder/modint.hpp"
#include "tools/bell.hpp"
#include "tools/join.hpp"

using mint = atcoder::modint998244353;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int N;
  std::cin >> N;

  const auto answers = tools::bell::diagonal<mint>(N);
  std::cout << tools::join(answers.begin(), answers.end(), [](const auto B_i) { return B_i.val(); }, " ") << '\n';

  return 0;
}
