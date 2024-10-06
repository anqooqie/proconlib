#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A"

#include <iostream>
#include <vector>
#include <numeric>
#include <iterator>
#include "tools/assert_that.hpp"
#include "tools/divisor_zeta.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  for (int N = 0; N <= 20; ++N) {
    std::vector<int> a(N);
    for (int i = 0; i < N; ++i) {
      a[i] = 1 << i;
    }

    std::vector<int> b(N, 0);
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        if (std::lcm(i, j) == i) b[i] += a[j];
      }
    }

    std::vector<int> actual_b;
    tools::divisor_zeta(a.begin(), a.end(), std::back_inserter(actual_b));
    assert_that(actual_b == b);

    tools::divisor_zeta(a.begin(), a.end());
    assert_that(a == b);
  }

  std::cout << "Hello World" << '\n';
  return 0;
}
