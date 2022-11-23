#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A"

#include <iostream>
#include <sstream>
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

  std::cout << "Hello World" << '\n';
  return 0;
}
