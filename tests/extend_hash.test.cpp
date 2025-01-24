// competitive-verifier: STANDALONE

#include <algorithm>
#include <functional>
#include <iostream>
#include <tuple>
#include <utility>
#include <vector>
#include "tools/assert_that.hpp"
#include "tools/extend_hash.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  {
    std::vector<std::size_t> v;
    const std::hash<std::pair<int, int>> hasher;
    for (int i = 0; i < 3000; ++i) {
      for (int j = 0; j < 3000; ++j) {
        const auto pair = std::make_pair(i, j);
        v.push_back(hasher(pair));
        assert_that(hasher(pair) == v.back());
      }
    }

    const auto old_size = v.size();
    std::sort(v.begin(), v.end());
    v.erase(std::unique(v.begin(), v.end()), v.end());
    assert_that(v.size() == old_size);
  }

  {
    std::vector<std::size_t> v;
    const std::hash<std::tuple<int, int>> hasher;
    for (int i = 0; i < 3000; ++i) {
      for (int j = 0; j < 3000; ++j) {
        const auto tuple = std::make_tuple(i, j);
        v.push_back(hasher(tuple));
        assert_that(hasher(tuple) == v.back());
      }
    }

    const auto old_size = v.size();
    std::sort(v.begin(), v.end());
    v.erase(std::unique(v.begin(), v.end()), v.end());
    assert_that(v.size() == old_size);
  }

  return 0;
}
