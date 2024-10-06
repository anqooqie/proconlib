#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A"

#include <iostream>
#include <vector>
#include <numeric>
#include <iterator>
#include "tools/assert_that.hpp"
#include "tools/divisor_moebius.hpp"

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

    std::vector<int> actual_a;
    tools::divisor_moebius(b.begin(), b.end(), std::back_inserter(actual_a));
    assert_that(actual_a == a);

    tools::divisor_moebius(b.begin(), b.end());
    assert_that(b == a);
  }

  std::cout << "Hello World" << '\n';
  return 0;
}
