// competitive-verifier: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A

#include <cstdlib>
#include <iostream>
#include <vector>
#include <array>
#include "tools/assert_that.hpp"
#include "tools/resize.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  {
    std::vector<std::vector<std::vector<int>>> v;
    tools::resize(v, 3, 4, 5);
    assert_that(v.size() == 3);
    for (int i = 0; i < 3; ++i) {
      assert_that(v[i].size() == 4);
      for (int j = 0; j < 4; ++j) {
        assert_that(v[i][j].size() == 5);
      }
    }
  }

  {
    std::vector<std::vector<std::vector<int>>> v;
    tools::resize(v, 3, 4, 0);
    assert_that(v.size() == 3);
    for (int i = 0; i < 3; ++i) {
      assert_that(v[i].size() == 4);
      for (int j = 0; j < 4; ++j) {
        assert_that(v[i][j].size() == 0);
      }
    }
  }

  {
    std::vector<std::vector<std::vector<int>>> v;
    tools::resize(v, 0, 4, 5);
    assert_that(v.size() == 0);
  }

  {
    std::vector<int> v;
    tools::resize(v, 3);
    assert_that(v.size() == 3);
  }

  {
    std::vector<int> v;
    tools::resize(v, 0);
    assert_that(v.size() == 0);
  }

  {
    std::array<std::vector<std::vector<int>>, 3> v;
    tools::resize(v, 3, 4, 5);
    assert_that(v.size() == 3);
    for (int i = 0; i < 3; ++i) {
      assert_that(v[i].size() == 4);
      for (int j = 0; j < 4; ++j) {
        assert_that(v[i][j].size() == 5);
      }
    }
  }

  {
    std::vector<std::array<std::vector<int>, 4>> v;
    tools::resize(v, 3, 4, 5);
    assert_that(v.size() == 3);
    for (int i = 0; i < 3; ++i) {
      assert_that(v[i].size() == 4);
      for (int j = 0; j < 4; ++j) {
        assert_that(v[i][j].size() == 5);
      }
    }
  }

  {
    std::vector<std::vector<std::array<int, 5>>> v;
    tools::resize(v, 3, 4, 5);
    assert_that(v.size() == 3);
    for (int i = 0; i < 3; ++i) {
      assert_that(v[i].size() == 4);
      for (int j = 0; j < 4; ++j) {
        assert_that(v[i][j].size() == 5);
      }
    }
  }

  {
    std::array<std::array<std::array<int, 5>, 4>, 3> v;
    tools::resize(v, 3, 4, 5);
    assert_that(v.size() == 3);
    for (int i = 0; i < 3; ++i) {
      assert_that(v[i].size() == 4);
      for (int j = 0; j < 4; ++j) {
        assert_that(v[i][j].size() == 5);
      }
    }
  }

  {
    std::array<int, 3> v;
    tools::resize(v, 3);
    assert_that(v.size() == 3);
  }

  std::cout << "Hello World" << '\n';
  return 0;
}
