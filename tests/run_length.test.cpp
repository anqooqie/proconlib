// competitive-verifier: STANDALONE

#include <iostream>
#include <string>
#include "tools/assert_that.hpp"
#include "tools/run_length.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  {
    const std::string s = "ABBCCC";
    const auto v = tools::run_length(s);
    assert_that(v.size() == 3);
    assert_that(v[0].first == 'A');
    assert_that(v[0].second == 1);
    assert_that(v[1].first == 'B');
    assert_that(v[1].second == 2);
    assert_that(v[2].first == 'C');
    assert_that(v[2].second == 3);
  }

  {
    const std::string s = "AAABBC";
    const auto v = tools::run_length(s);
    assert_that(v.size() == 3);
    assert_that(v[0].first == 'A');
    assert_that(v[0].second == 3);
    assert_that(v[1].first == 'B');
    assert_that(v[1].second == 2);
    assert_that(v[2].first == 'C');
    assert_that(v[2].second == 1);
  }

  {
    const std::string s = "";
    const auto v = tools::run_length(s);
    assert_that(v.size() == 0);
  }

  {
    const std::string s = "A";
    const auto v = tools::run_length(s);
    assert_that(v.size() == 1);
    assert_that(v[0].first == 'A');
    assert_that(v[0].second == 1);
  }

  return 0;
}
