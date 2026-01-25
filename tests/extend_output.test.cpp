// competitive-verifier: STANDALONE

#include <array>
#include <iostream>
#include <map>
#include <optional>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <tuple>
#include <unordered_set>
#include <unordered_map>
#include <utility>
#include <vector>
#include "atcoder/modint.hpp"
#include "tools/assert_that.hpp"
#include "tools/extend_output.hpp"

using mint = atcoder::modint998244353;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  {
    std::array<int, 3> v = {123, 456, 789};
    std::ostringstream oss;
    oss << v;
    assert_that(oss.str() == "[123, 456, 789]");
  }

  {
    std::map<int, int> v = {{{1, 123}, {2, 456}, {3, 789}}};
    std::ostringstream oss;
    oss << v;
    assert_that(oss.str() == "[[1, 123], [2, 456], [3, 789]]");
  }

  {
    std::optional<int> v;
    std::ostringstream oss;
    oss << v;
    assert_that(oss.str() == "null");
  }
  {
    std::optional<int> v(123);
    std::ostringstream oss;
    oss << v;
    assert_that(oss.str() == "123");
  }

  {
    std::pair<int, int> v(123, 456);
    std::ostringstream oss;
    oss << v;
    assert_that(oss.str() == "[123, 456]");
  }

  {
    std::queue<int> v;
    v.push(123);
    v.push(456);
    v.push(789);
    std::ostringstream oss;
    oss << v;
    assert_that(oss.str() == "[123, 456, 789]");
    assert_that(v.size() == 3);
    assert_that(v.front() == 123);
  }

  {
    std::set<int> v = {123, 456, 789};
    std::ostringstream oss;
    oss << v;
    assert_that(oss.str() == "[123, 456, 789]");
  }

  {
    std::stack<int> v;
    v.push(123);
    v.push(456);
    v.push(789);
    std::ostringstream oss;
    oss << v;
    assert_that(oss.str() == "[123, 456, 789]");
    assert_that(v.size() == 3);
    assert_that(v.top() == 789);
  }

  {
    std::tuple<int, int, int> v(123, 456, 789);
    std::ostringstream oss;
    oss << v;
    assert_that(oss.str() == "[123, 456, 789]");
  }

  {
    std::unordered_set<int> v = {123, 456, 789};
    std::ostringstream oss;
    oss << v;
    assert_that(
      oss.str() == "[123, 456, 789]"
      || oss.str() == "[123, 789, 456]"
      || oss.str() == "[456, 123, 789]"
      || oss.str() == "[456, 789, 123]"
      || oss.str() == "[789, 123, 456]"
      || oss.str() == "[789, 456, 123]"
    );
  }

  {
    std::unordered_map<int, int> v = {{{1, 123}, {2, 456}, {3, 789}}};
    std::ostringstream oss;
    oss << v;
    assert_that(
      oss.str() == "[[1, 123], [2, 456], [3, 789]]"
      || oss.str() == "[[1, 123], [3, 789], [2, 456]]"
      || oss.str() == "[[2, 456], [1, 123], [3, 789]]"
      || oss.str() == "[[2, 456], [3, 789], [1, 123]]"
      || oss.str() == "[[3, 789], [1, 123], [2, 456]]"
      || oss.str() == "[[3, 789], [2, 456], [1, 123]]"
    );
  }

  {
    std::vector<int> v = {123, 456, 789};
    std::ostringstream oss;
    oss << v;
    assert_that(oss.str() == "[123, 456, 789]");
  }

  {
    std::ostringstream oss;
    oss << mint(123);
    assert_that(oss.str() == "123");
  }

  {
    std::array<mint, 3> v = {mint(123), mint(456), mint(789)};
    std::ostringstream oss;
    oss << v;
    assert_that(oss.str() == "[123, 456, 789]");
  }

  {
    std::vector<mint> v = {mint(123), mint(456), mint(789)};
    std::ostringstream oss;
    oss << v;
    assert_that(oss.str() == "[123, 456, 789]");
  }

  return 0;
}
