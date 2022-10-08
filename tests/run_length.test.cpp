#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A"

#include <cstdlib>
#include <iostream>
#include <vector>
#include <iterator>
#include "tools/assert_that.hpp"
#include "tools/run_length.hpp"

using ll = long long;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  std::string s;
  std::vector<std::pair<char, ll>> v;

  s = "ABBCCC";
  v.clear();
  tools::run_length(s.begin(), s.end(), std::back_inserter(v));
  assert_that(v.size() == 3);
  assert_that(v[0].first == 'A');
  assert_that(v[0].second == 1);
  assert_that(v[1].first == 'B');
  assert_that(v[1].second == 2);
  assert_that(v[2].first == 'C');
  assert_that(v[2].second == 3);

  s = "AAABBC";
  v.clear();
  tools::run_length(s.begin(), s.end(), std::back_inserter(v));
  assert_that(v.size() == 3);
  assert_that(v[0].first == 'A');
  assert_that(v[0].second == 3);
  assert_that(v[1].first == 'B');
  assert_that(v[1].second == 2);
  assert_that(v[2].first == 'C');
  assert_that(v[2].second == 1);

  s = "";
  v.clear();
  tools::run_length(s.begin(), s.end(), std::back_inserter(v));
  assert_that(v.size() == 0);

  s = "A";
  v.clear();
  tools::run_length(s.begin(), s.end(), std::back_inserter(v));
  assert_that(v.size() == 1);
  assert_that(v[0].first == 'A');
  assert_that(v[0].second == 1);

  std::cout << "Hello World" << '\n';
  return 0;
}
