// competitive-verifier: STANDALONE

#include <functional>
#include <iostream>
#include "tools/assert_that.hpp"
#include "tools/triangular_array_compressor.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  for (int n = 0; n <= 7; ++n) {
    {
      tools::triangular_array_compressor<std::less<int>> f(n);
      assert_that(f.size() == n);
      for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
          const auto k = f.compress(i, j);
          assert_that(0 <= k && k < n * (n - 1) / 2);
          const auto [i2, j2] = f.decompress(k);
          assert_that(0 <= i2 && i2 < j2 && j2 < n);
          assert_that(i == i2 && j == j2);
        }
      }
    }
    {
      tools::triangular_array_compressor<std::less_equal<int>> f(n);
      assert_that(f.size() == n);
      for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
          const auto k = f.compress(i, j);
          assert_that(0 <= k && k < n * (n + 1) / 2);
          const auto [i2, j2] = f.decompress(k);
          assert_that(0 <= i2 && i2 <= j2 && j2 < n);
          assert_that(i == i2 && j == j2);
        }
      }
    }
    {
      tools::triangular_array_compressor<std::greater<int>> f(n);
      assert_that(f.size() == n);
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
          const auto k = f.compress(i, j);
          assert_that(0 <= k && k < n * (n - 1) / 2);
          const auto [i2, j2] = f.decompress(k);
          assert_that(0 <= j2 && j2 < i2 && i2 < n);
          assert_that(i == i2 && j == j2);
        }
      }
    }
    {
      tools::triangular_array_compressor<std::greater_equal<int>> f(n);
      assert_that(f.size() == n);
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
          const auto k = f.compress(i, j);
          assert_that(0 <= k && k < n * (n + 1) / 2);
          const auto [i2, j2] = f.decompress(k);
          assert_that(0 <= j2 && j2 <= i2 && i2 < n);
          assert_that(i == i2 && j == j2);
        }
      }
    }
  }

  return 0;
}
