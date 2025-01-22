// competitive-verifier: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A

#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <sstream>
#include <tuple>
#include <utility>
#include <vector>
#include "atcoder/modint.hpp"
#include "tools/assert_that.hpp"
#include "tools/extend_input.hpp"

using mint = atcoder::modint998244353;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  {
    std::array<int, 3> v;
    std::istringstream iss("123 456 789 111 222 333");
    iss >> v;
    assert_that(v[0] == 123);
    assert_that(v[1] == 456);
    assert_that(v[2] == 789);
  }
  {
    std::vector<std::array<int, 3>> v;
    std::istringstream iss("123 456 789 111 222 333");
    std::copy_n(std::istream_iterator<std::array<int, 3>>(iss), 2, std::back_inserter(v));
    assert_that(v.size() == 2);
    assert_that(v[0][0] == 123);
    assert_that(v[0][1] == 456);
    assert_that(v[0][2] == 789);
    assert_that(v[1][0] == 111);
    assert_that(v[1][1] == 222);
    assert_that(v[1][2] == 333);
  }

  {
    std::pair<int, int> v;
    std::istringstream iss("123 456 111 222");
    iss >> v;
    assert_that(v.first == 123);
    assert_that(v.second == 456);
  }
  {
    std::vector<std::pair<int, int>> v;
    std::istringstream iss("123 456 111 222");
    std::copy_n(std::istream_iterator<std::pair<int, int>>(iss), 2, std::back_inserter(v));
    assert_that(v.size() == 2);
    assert_that(v[0].first == 123);
    assert_that(v[0].second == 456);
    assert_that(v[1].first == 111);
    assert_that(v[1].second == 222);
  }

  {
    std::tuple<int, int, int> v;
    std::istringstream iss("123 456 789 111 222 333");
    iss >> v;
    assert_that(std::get<0>(v) == 123);
    assert_that(std::get<1>(v) == 456);
    assert_that(std::get<2>(v) == 789);
  }
  {
    std::vector<std::tuple<int, int, int>> v;
    std::istringstream iss("123 456 789 111 222 333");
    std::copy_n(std::istream_iterator<std::tuple<int, int, int>>(iss), 2, std::back_inserter(v));
    assert_that(v.size() == 2);
    assert_that(std::get<0>(v[0]) == 123);
    assert_that(std::get<1>(v[0]) == 456);
    assert_that(std::get<2>(v[0]) == 789);
    assert_that(std::get<0>(v[1]) == 111);
    assert_that(std::get<1>(v[1]) == 222);
    assert_that(std::get<2>(v[1]) == 333);
  }

  {
    std::vector<int> v(3);
    std::istringstream iss("123 456 789 111 222 333");
    iss >> v;
    assert_that(v.size() == 3);
    assert_that(v[0] == 123);
    assert_that(v[1] == 456);
    assert_that(v[2] == 789);
  }

  {
    mint v;
    std::istringstream iss("123");
    iss >> v;
    assert_that(v == mint(123));
  }
  {
    std::vector<mint> v;
    std::istringstream iss("123 456 789 111 222 333");
    std::copy_n(std::istream_iterator<mint>(iss), 3, std::back_inserter(v));
    assert_that(v.size() == 3);
    assert_that(v[0] == mint(123));
    assert_that(v[1] == mint(456));
    assert_that(v[2] == mint(789));
  }

  {
    auto v = std::vector(2, std::vector<int>(3));
    std::istringstream iss("123 456 789 111 222 333");
    iss >> v;
    assert_that(v[0][0] == 123);
    assert_that(v[0][1] == 456);
    assert_that(v[0][2] == 789);
    assert_that(v[1][0] == 111);
    assert_that(v[1][1] == 222);
    assert_that(v[1][2] == 333);
  }
  {
    auto v = std::vector(2, std::array<int, 3>());
    std::istringstream iss("123 456 789 111 222 333");
    iss >> v;
    assert_that(v[0][0] == 123);
    assert_that(v[0][1] == 456);
    assert_that(v[0][2] == 789);
    assert_that(v[1][0] == 111);
    assert_that(v[1][1] == 222);
    assert_that(v[1][2] == 333);
  }
  {
    std::array<std::vector<int>, 2> v;
    for (auto& v_i : v) v_i.resize(3);
    std::istringstream iss("123 456 789 111 222 333");
    iss >> v;
    assert_that(v[0][0] == 123);
    assert_that(v[0][1] == 456);
    assert_that(v[0][2] == 789);
    assert_that(v[1][0] == 111);
    assert_that(v[1][1] == 222);
    assert_that(v[1][2] == 333);
  }
  {
    std::array<std::array<int, 3>, 2> v;
    std::istringstream iss("123 456 789 111 222 333");
    iss >> v;
    assert_that(v[0][0] == 123);
    assert_that(v[0][1] == 456);
    assert_that(v[0][2] == 789);
    assert_that(v[1][0] == 111);
    assert_that(v[1][1] == 222);
    assert_that(v[1][2] == 333);
  }

  std::cout << "Hello World" << '\n';
  return 0;
}
