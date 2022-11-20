#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A"

#include <iostream>
#include <sstream>
#include <vector>
#include <cstddef>
#include <functional>
#include <algorithm>
#include "tools/assert_that.hpp"
#include "tools/uint128_t.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  {
    tools::uint128_t v;
    std::istringstream iss("0");
    iss >> v;
    std::ostringstream oss;
    oss << v;
    assert_that(oss.str() == "0");
  }
  {
    tools::uint128_t v;
    std::istringstream iss("+0");
    iss >> v;
    std::ostringstream oss;
    oss << v;
    assert_that(oss.str() == "0");
  }

  {
    tools::uint128_t v;
    std::istringstream iss("1");
    iss >> v;
    std::ostringstream oss;
    oss << v;
    assert_that(oss.str() == "1");
  }
  {
    tools::uint128_t v;
    std::istringstream iss("+1");
    iss >> v;
    std::ostringstream oss;
    oss << v;
    assert_that(oss.str() == "1");
  }

  {
    tools::uint128_t v;
    std::istringstream iss("340282366920938463463374607431768211455");
    iss >> v;
    std::ostringstream oss;
    oss << v;
    assert_that(oss.str() == "340282366920938463463374607431768211455");
  }
  {
    tools::uint128_t v;
    std::istringstream iss("+340282366920938463463374607431768211455");
    iss >> v;
    std::ostringstream oss;
    oss << v;
    assert_that(oss.str() == "340282366920938463463374607431768211455");
  }

  {
    std::vector<std::size_t> v;
    const std::hash<tools::uint128_t> hasher;
    for (int i = 0; i < 1000000; ++i) {
      v.push_back(hasher(i));
      assert_that(hasher(i) == v.back());
    }

    const auto old_size = v.size();
    std::sort(v.begin(), v.end());
    v.erase(std::unique(v.begin(), v.end()), v.end());
    assert_that(v.size() == old_size);
  }

  std::cout << "Hello World" << '\n';
  return 0;
}
