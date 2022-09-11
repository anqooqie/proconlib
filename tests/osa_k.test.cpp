#define PROBLEM "https://atcoder.jp/contests/abc170/tasks/abc170_d"

#include <cstdint>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include "tools/osa_k.hpp"

using i64 = std::int_fast64_t;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  i64 N;
  std::cin >> N;
  std::vector<i64> A(N);
  for (auto& A_i : A) std::cin >> A_i;

  std::sort(A.begin(), A.end());
  tools::osa_k<i64> osa_k(A.back() + 1);
  std::unordered_set<i64> set;
  i64 answer = 0;
  for (i64 l = 0, r = 0; l < N; l = r) {
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
