// competitive-verifier: STANDALONE

#include <iostream>
#include <limits>
#include <sstream>
#include <unordered_set>
#include "tools/abs.hpp"
#include "tools/assert_that.hpp"
#include "tools/int128_t.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  {
    tools::int128_t v;
    std::istringstream iss("-170141183460469231731687303715884105728");
    iss >> v;
    std::ostringstream oss;
    oss << v;
    assert_that(oss.str() == "-170141183460469231731687303715884105728");
    oss.str("");
    oss << INT128_C(-170141183460469231731687303715884105728);
    assert_that(oss.str() == "-170141183460469231731687303715884105728");
  }

  {
    tools::int128_t v;
    std::istringstream iss("-1");
    iss >> v;
    std::ostringstream oss;
    oss << v;
    assert_that(oss.str() == "-1");
    oss.str("");
    oss << INT128_C(-1);
    assert_that(oss.str() == "-1");
  }

  {
    tools::int128_t v;
    std::istringstream iss("0");
    iss >> v;
    std::ostringstream oss;
    oss << v;
    assert_that(oss.str() == "0");
    oss.str("");
    oss << INT128_C(0);
    assert_that(oss.str() == "0");
  }
  {
    tools::int128_t v;
    std::istringstream iss("+0");
    iss >> v;
    std::ostringstream oss;
    oss << v;
    assert_that(oss.str() == "0");
    oss.str("");
    oss << INT128_C(+0);
    assert_that(oss.str() == "0");
  }

  {
    tools::int128_t v;
    std::istringstream iss("1");
    iss >> v;
    std::ostringstream oss;
    oss << v;
    assert_that(oss.str() == "1");
    oss.str("");
    oss << INT128_C(1);
    assert_that(oss.str() == "1");
  }
  {
    tools::int128_t v;
    std::istringstream iss("+1");
    iss >> v;
    std::ostringstream oss;
    oss << v;
    assert_that(oss.str() == "1");
    oss.str("");
    oss << INT128_C(+1);
    assert_that(oss.str() == "1");
  }

  {
    tools::int128_t v;
    std::istringstream iss("170141183460469231731687303715884105727");
    iss >> v;
    std::ostringstream oss;
    oss << v;
    assert_that(oss.str() == "170141183460469231731687303715884105727");
    oss.str("");
    oss << INT128_C(170141183460469231731687303715884105727);
    assert_that(oss.str() == "170141183460469231731687303715884105727");
  }
  {
    tools::int128_t v;
    std::istringstream iss("+170141183460469231731687303715884105727");
    iss >> v;
    std::ostringstream oss;
    oss << v;
    assert_that(oss.str() == "170141183460469231731687303715884105727");
    oss.str("");
    oss << INT128_C(+170141183460469231731687303715884105727);
    assert_that(oss.str() == "170141183460469231731687303715884105727");
  }

  {
    static_assert(tools::abs(INT128_C(-170141183460469231731687303715884105727)) == INT128_C(170141183460469231731687303715884105727));
    static_assert(tools::abs(INT128_C(-1)) == INT128_C(1));
    static_assert(tools::abs(INT128_C(0)) == INT128_C(0));
    static_assert(tools::abs(INT128_C(1)) == INT128_C(1));
    static_assert(tools::abs(INT128_C(170141183460469231731687303715884105727)) == INT128_C(170141183460469231731687303715884105727));
  }

  {
    std::unordered_set<tools::int128_t> s;
    for (tools::int128_t i = -100000; i < 100000; ++i) {
      s.insert(i);
    }
    assert_that(s.size() == 200000);
  }

  {
    assert_that(std::numeric_limits<tools::int128_t>::min() == INT128_C(-170141183460469231731687303715884105728));
    assert_that(std::numeric_limits<tools::int128_t>::max() == INT128_C(170141183460469231731687303715884105727));
  }

  return 0;
}
