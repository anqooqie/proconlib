// competitive-verifier: STANDALONE

#include <iostream>
#include <limits>
#include <sstream>
#include <unordered_set>
#include "tools/abs.hpp"
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
    oss.str("");
    oss << UINT128_C(0);
    assert_that(oss.str() == "0");
  }
  {
    tools::uint128_t v;
    std::istringstream iss("+0");
    iss >> v;
    std::ostringstream oss;
    oss << v;
    assert_that(oss.str() == "0");
    oss.str("");
    oss << UINT128_C(+0);
    assert_that(oss.str() == "0");
  }

  {
    tools::uint128_t v;
    std::istringstream iss("1");
    iss >> v;
    std::ostringstream oss;
    oss << v;
    assert_that(oss.str() == "1");
    oss.str("");
    oss << UINT128_C(1);
    assert_that(oss.str() == "1");
  }
  {
    tools::uint128_t v;
    std::istringstream iss("+1");
    iss >> v;
    std::ostringstream oss;
    oss << v;
    assert_that(oss.str() == "1");
    oss.str("");
    oss << UINT128_C(+1);
    assert_that(oss.str() == "1");
  }

  {
    tools::uint128_t v;
    std::istringstream iss("340282366920938463463374607431768211455");
    iss >> v;
    std::ostringstream oss;
    oss << v;
    assert_that(oss.str() == "340282366920938463463374607431768211455");
    oss.str("");
    oss << UINT128_C(340282366920938463463374607431768211455);
    assert_that(oss.str() == "340282366920938463463374607431768211455");
  }
  {
    tools::uint128_t v;
    std::istringstream iss("+340282366920938463463374607431768211455");
    iss >> v;
    std::ostringstream oss;
    oss << v;
    assert_that(oss.str() == "340282366920938463463374607431768211455");
    oss.str("");
    oss << UINT128_C(+340282366920938463463374607431768211455);
    assert_that(oss.str() == "340282366920938463463374607431768211455");
  }

  {
    static_assert(tools::abs(UINT128_C(0)) == UINT128_C(0));
    static_assert(tools::abs(UINT128_C(1)) == UINT128_C(1));
    static_assert(tools::abs(UINT128_C(340282366920938463463374607431768211455)) == UINT128_C(340282366920938463463374607431768211455));
  }

  {
    std::unordered_set<tools::uint128_t> s;
    for (tools::uint128_t i = 0; i < 200000; ++i) {
      s.insert(i);
    }
    assert_that(s.size() == 200000);
  }

  {
    assert_that(std::numeric_limits<tools::uint128_t>::min() == UINT128_C(0));
    assert_that(std::numeric_limits<tools::uint128_t>::max() == UINT128_C(340282366920938463463374607431768211455));
  }

  return 0;
}
