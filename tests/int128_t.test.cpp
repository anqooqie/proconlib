// competitive-verifier: STANDALONE

#include <iostream>
#include <sstream>
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
  }

  {
    tools::int128_t v;
    std::istringstream iss("-170141183460469231731687303715884105727");
    iss >> v;
    std::ostringstream oss;
    oss << v;
    assert_that(oss.str() == "-170141183460469231731687303715884105727");
  }

  {
    tools::int128_t v;
    std::istringstream iss("-1");
    iss >> v;
    std::ostringstream oss;
    oss << v;
    assert_that(oss.str() == "-1");
  }

  {
    tools::int128_t v;
    std::istringstream iss("0");
    iss >> v;
    std::ostringstream oss;
    oss << v;
    assert_that(oss.str() == "0");
  }
  {
    tools::int128_t v;
    std::istringstream iss("+0");
    iss >> v;
    std::ostringstream oss;
    oss << v;
    assert_that(oss.str() == "0");
  }

  {
    tools::int128_t v;
    std::istringstream iss("1");
    iss >> v;
    std::ostringstream oss;
    oss << v;
    assert_that(oss.str() == "1");
  }
  {
    tools::int128_t v;
    std::istringstream iss("+1");
    iss >> v;
    std::ostringstream oss;
    oss << v;
    assert_that(oss.str() == "1");
  }

  {
    tools::int128_t v;
    std::istringstream iss("170141183460469231731687303715884105727");
    iss >> v;
    std::ostringstream oss;
    oss << v;
    assert_that(oss.str() == "170141183460469231731687303715884105727");
  }
  {
    tools::int128_t v;
    std::istringstream iss("+170141183460469231731687303715884105727");
    iss >> v;
    std::ostringstream oss;
    oss << v;
    assert_that(oss.str() == "170141183460469231731687303715884105727");
  }

  return 0;
}
