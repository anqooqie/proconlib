// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/longest_increasing_subsequence

#include <iostream>
#include <vector>
#include "tools/lis.hpp"
#include "tools/join.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int N;
  std::cin >> N;
  std::vector<int> A(N);
  for (auto&& A_i : A) std::cin >> A_i;

  const auto lis = tools::lis::bisect<true, true>(A.begin(), A.end());
  std::cout << lis.size() << '\n';
  std::cout << tools::join(lis, " ") << '\n';

  return 0;
}
