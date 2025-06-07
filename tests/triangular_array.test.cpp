// competitive-verifier: STANDALONE

#include <functional>
#include <iostream>
#include <sstream>
#include "tools/assert_that.hpp"
#include "tools/triangular_array.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  for (int n = 0; n <= 7; ++n) {
    {
      tools::triangular_array<int, std::less<int>> a(n, 0);
      int k = 1;
      for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
          a[i][j] = k++;
        }
      }
      k = 1;
      for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
          assert_that(a[i][j] == k++);
        }
      }
    }
    {
      std::stringstream ss;
      int k = 1;
      for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
          ss << k++ << " \n"[j == n - 1];
        }
      }
      tools::triangular_array<int, std::less<int>> a(n);
      ss >> a;
      k = 1;
      for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
          assert_that(a[i][j] == k++);
        }
      }
    }
    {
      tools::triangular_array<int, std::less_equal<int>> a(n, 0);
      int k = 1;
      for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
          a[i][j] = k++;
        }
      }
      k = 1;
      for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
          assert_that(a[i][j] == k++);
        }
      }
    }
    {
      std::stringstream ss;
      int k = 1;
      for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
          ss << k++ << " \n"[j == n - 1];
        }
      }
      tools::triangular_array<int, std::less_equal<int>> a(n);
      ss >> a;
      k = 1;
      for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
          assert_that(a[i][j] == k++);
        }
      }
    }
    {
      tools::triangular_array<int, std::greater<int>> a(n, 0);
      int k = 1;
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
          a[i][j] = k++;
        }
      }
      k = 1;
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
          assert_that(a[i][j] == k++);
        }
      }
    }
    {
      std::stringstream ss;
      int k = 1;
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
          ss << k++ << " \n"[j == i - 1];
        }
      }
      tools::triangular_array<int, std::greater<int>> a(n);
      ss >> a;
      k = 1;
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
          assert_that(a[i][j] == k++);
        }
      }
    }
    {
      tools::triangular_array<int, std::greater_equal<int>> a(n, 0);
      int k = 1;
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
          a[i][j] = k++;
        }
      }
      k = 1;
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
          assert_that(a[i][j] == k++);
        }
      }
    }
    {
      std::stringstream ss;
      int k = 1;
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
          ss << k++ << " \n"[j == i];
        }
      }
      tools::triangular_array<int, std::greater_equal<int>> a(n);
      ss >> a;
      k = 1;
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
          assert_that(a[i][j] == k++);
        }
      }
    }
  }

  return 0;
}
