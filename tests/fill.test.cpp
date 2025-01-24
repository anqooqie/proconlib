// competitive-verifier: STANDALONE

#include <cstdlib>
#include <iostream>
#include <vector>
#include <array>
#include "tools/assert_that.hpp"
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

  {
    std::array<std::vector<std::vector<int>>, 3> v;
    for (int i = 0; i < 3; ++i) {
      v[i].resize(4);
      for (int j = 0; j < 4; ++j) {
        v[i][j].resize(5);
      }
    }
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
    std::vector<std::array<std::vector<int>, 4>> v;
    v.resize(3);
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 4; ++j) {
        v[i][j].resize(5);
      }
    }
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
    std::vector<std::vector<std::array<int, 5>>> v;
    v.resize(3);
    for (int i = 0; i < 3; ++i) {
      v[i].resize(4);
    }
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
    std::array<std::array<std::array<int, 5>, 4>, 3> v;
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
    std::array<int, 3> v;
    tools::fill(v, 6);
    for (int i = 0; i < 3; ++i) {
      assert_that(v[i] == 6);
    }
  }

  return 0;
}
