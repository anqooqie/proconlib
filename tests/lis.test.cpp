#define PROBLEM "https://judge.yosupo.jp/problem/longest_increasing_subsequence"

#include <iostream>
#include <vector>
#include "tools/lis.hpp"
#include "tools/join.hpp"

using ll = long long;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  ll N;
  std::cin >> N;
  std::vector<ll> A(N);
  for (auto& A_i : A) std::cin >> A_i;

  const auto lis_indices = tools::lis(A.begin(), A.end(), true).second;
  std::cout << lis_indices.size() << '\n';
  std::cout << tools::join(lis_indices.begin(), lis_indices.end(), " ") << '\n';

  return 0;
}
