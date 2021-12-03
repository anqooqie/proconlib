#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A"

#include <cstdlib>
#include <iostream>
#include <vector>
#include "tests/assert_that.hpp"
#include "tools/fill.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  {
    auto v = std::vector(3, std::vector(4, std::vector<int>(5)));
    tools::fill(v, 6);
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 4; ++j) {
        for (int k = 0; k < 5; ++k) {
          assert_that(v[i][j][k] == 6);
        }
      }
    }
  }

  {
    auto v = std::vector(3, std::vector(4, std::vector<int>(0)));
    tools::fill(v, 6);
  }

  {
    auto v = std::vector<int>(3);
    tools::fill(v, 6);
    for (int i = 0; i < 3; ++i) {
      assert_that(v[i] == 6);
    }
  }

  {
    auto v = std::vector<int>(0);
    tools::fill(v, 6);
  }

  std::cout << "Hello World" << '\n';
  return 0;
}
