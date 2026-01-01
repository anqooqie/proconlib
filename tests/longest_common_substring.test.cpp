// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/longest_common_substring

#include <iostream>
#include <string>
#include "tools/longest_common_substring.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  std::string S, T;
  std::cin >> S >> T;

  const auto [a, b, c, d] = tools::longest_common_substring(S, T);
  std::cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';

  return 0;
}
