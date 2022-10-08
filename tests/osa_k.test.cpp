#define PROBLEM "https://atcoder.jp/contests/abc170/tasks/abc170_d"

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include "tools/osa_k.hpp"

using ll = long long;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  ll N;
  std::cin >> N;
  std::vector<ll> A(N);
  for (auto& A_i : A) std::cin >> A_i;

  std::sort(A.begin(), A.end());
  tools::osa_k<ll> osa_k(A.back() + 1);
  std::unordered_set<ll> set;
  ll answer = 0;
  for (ll l = 0, r = 0; l < N; l = r) {
    for (; r < N && A[l] == A[r]; ++r);
    if (r - l == 1 && [&]() {
      for (const auto d : osa_k.divisors(A[l])) {
        if (set.find(d) != set.end()) return false;
      }
      return true;
    }()) {
      ++answer;
    }
    set.insert(A[l]);
  }

  std::cout << answer << '\n';
  return 0;
}
