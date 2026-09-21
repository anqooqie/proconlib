// competitive-verifier: STANDALONE

#include <array>
#include <iostream>
#include <string>
#include <vector>
#include "tools/assert_that.hpp"
#include "tools/rotr45.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  assert_that(tools::rotr45(std::array<std::array<int, 3>, 2> {{
    {1, 2, 3},
    {4, 5, 6},
  }}, 0) == std::array<std::array<int, 4>, 4> {{
    {0, 1, 0, 0},
    {4, 0, 2, 0},
    {0, 5, 0, 3},
    {0, 0, 6, 0},
  }});

  assert_that(tools::rotr45(std::array<std::array<int, 1>, 1> {{
    {7},
  }}, 0) == std::array<std::array<int, 1>, 1> {{
    {7},
  }});

  assert_that(tools::rotr45(std::vector<std::vector<int>> {
    {1, 2, 3},
    {4, 5, 6},
  }, 0) == std::vector<std::vector<int>> {
    {0, 1, 0, 0},
    {4, 0, 2, 0},
    {0, 5, 0, 3},
    {0, 0, 6, 0},
  });

  assert_that(tools::rotr45(std::vector<std::vector<int>> {
    {1},
    {2},
    {3},
  }, 0) == std::vector<std::vector<int>> {
    {0, 0, 1},
    {0, 2, 0},
    {3, 0, 0},
  });

  assert_that(tools::rotr45(std::vector<std::vector<int>> {
    {7},
  }, 0) == std::vector<std::vector<int>> {
    {7},
  });

  assert_that(tools::rotr45(std::vector<std::string> {
    "abc",
    "def",
  }, '.') == std::vector<std::string> {
    ".a..",
    "d.b.",
    ".e.c",
    "..f.",
  });

  assert_that(tools::rotr45(std::vector<std::string> {
    "a",
    "b",
    "c",
  }, '.') == std::vector<std::string> {
    "..a",
    ".b.",
    "c..",
  });

  assert_that(tools::rotr45(std::vector<std::string> {
    "g",
  }, '.') == std::vector<std::string> {
    "g",
  });

  return 0;
}
