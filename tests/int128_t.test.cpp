#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A"

#include <iostream>
#include <sstream>
#include <vector>
#include <cstddef>
#include <functional>
#include <algorithm>
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

  {
    std::vector<std::size_t> v;
    const std::hash<tools::int128_t> hasher;
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
