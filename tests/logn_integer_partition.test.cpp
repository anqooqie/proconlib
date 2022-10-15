#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A"

#include <iostream>
#include <vector>
#include <cstddef>
#include <algorithm>
#include <numeric>
#include "tools/logn_integer_partition.hpp"
#include "tools/pow2.hpp"
#include "tools/assert_that.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  for (int n = 0; n < 32; ++n) {
    const auto parts = tools::logn_integer_partition(n);

    std::vector<int> sumset;
    for (std::size_t state = 0; state < tools::pow2(parts.size()); ++state) {
      int sum = 0;
      for (std::size_t i = 0; i < parts.size(); ++i) {
        if (state & (1 << i)) {
          sum += parts[i];
        }
      }
      sumset.push_back(sum);
    }
    std::sort(sumset.begin(), sumset.end());
    sumset.erase(std::unique(sumset.begin(), sumset.end()), sumset.end());

    std::vector<int> expected(n + 1);
    std::iota(expected.begin(), expected.end(), 0);

    assert_that(sumset == expected);
  }

  std::cout << "Hello World" << '\n';
  return 0;
}
