#define PROBLEM "https://atcoder.jp/contests/abc356/tasks/abc356_e"

#include <iostream>
#include <vector>
#include <algorithm>
#include "tools/small_range_lower_bound.hpp"

using ll = long long;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int N;
  std::cin >> N;
  std::vector<int> A(N);
  for (auto&& A_i : A) std::cin >> A_i;

  std::sort(A.begin(), A.end());
  tools::small_range_lower_bound<int> lower_bound(A.begin(), A.end());

  ll answer = 0;
  for (int l = 0, r = 0; l < N; l = r) {
    for (; r < N && A[l] == A[r]; ++r);
    for (int q = 1, max_q = A.back() / A[l]; q <= max_q; ++q) {
      answer += static_cast<ll>(lower_bound.query(A[l] * (q + 1)) - lower_bound.query(A[l] * q)) * q * (r - l);
    }
    answer -= static_cast<ll>(r - l) * (r - l + 1) / 2;
  }

  std::cout << answer << '\n';
  return 0;
}
