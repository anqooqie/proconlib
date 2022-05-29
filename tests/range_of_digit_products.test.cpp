#define PROBLEM "https://atcoder.jp/contests/abc208/tasks/abc208_e"

#include <cstdint>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iterator>
#include "tools/range_of_digit_products.hpp"
#include "tools/resize.hpp"
#include "tools/fill.hpp"
#include "tools/ssize.hpp"
#include "tools/lower_bound.hpp"
#include "tools/upper_bound.hpp"

using i64 = std::int_fast64_t;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  std::vector<i64> N;
  {
    i64 n;
    std::cin >> n;
    while (n > 0) {
      N.push_back(n % 10);
      n /= 10;
    }
    std::reverse(N.begin(), N.end());
  }

  i64 K;
  std::cin >> K;

  std::vector<i64> possible_products = tools::range_of_digit_products<i64>(std::min<i64>(N.size(), 18));

  std::vector<std::vector<std::vector<i64>>> dp;
  tools::resize(dp, N.size(), 2, possible_products.size());
  tools::fill(dp, 0);
  const int STRICT = 0;
  const int LOOSE = 1;

  dp[0][STRICT][N[0]] = 1;
  for (i64 d = 1; d < N[0]; ++d) {
    dp[0][LOOSE][d] = 1;
  }
  for (i64 i = 0; i + 1 < tools::ssize(N); ++i) {
    for (i64 j = 0; j < tools::ssize(possible_products); ++j) {
      if (dp[i][STRICT][j] > 0) {
        dp[i + 1][STRICT][tools::lower_bound(possible_products.begin(), possible_products.end(), possible_products[j] * N[i + 1])] += dp[i][STRICT][j];
        for (i64 d = 0; d < N[i + 1]; ++d) {
          dp[i + 1][LOOSE][tools::lower_bound(possible_products.begin(), possible_products.end(), possible_products[j] * d)] += dp[i][STRICT][j];
        }
      }
      if (dp[i][LOOSE][j] > 0) {
        for (i64 d = 0; d < 10; ++d) {
          dp[i + 1][LOOSE][tools::lower_bound(possible_products.begin(), possible_products.end(), possible_products[j] * d)] += dp[i][LOOSE][j];
        }
      }
    }
    for (i64 j = 1; j < 10; ++j) {
      ++dp[i + 1][LOOSE][j];
    }
  }

  i64 answer = 0;
  for (const auto& dp_i : dp.back()) {
    answer += std::accumulate(dp_i.begin(), std::next(dp_i.begin(), tools::upper_bound(possible_products.begin(), possible_products.end(), K)), i64(0));
  }
  std::cout << answer << '\n';
  return 0;
}
