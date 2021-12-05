#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A"

#include <cstdint>
#include <iostream>
#include <vector>
#include <iterator>
#include "tests/assert_that.hpp"
#include "tools/xor_basis.hpp"

using i64 = std::int_fast64_t;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  {
    std::vector<i64> in({1, 1, 2, 4});
    std::vector<i64> out;
    tools::xor_basis(in.begin(), in.end(), std::back_inserter(out));
    assert_that(out.size() == 3);
  }
  {
    std::vector<i64> in({1, 1, 2, 1});
    std::vector<i64> out;
    tools::xor_basis(in.begin(), in.end(), std::back_inserter(out));
    assert_that(out.size() == 2);
  }
  {
    std::vector<i64> in({1, 1, 2, 3});
    std::vector<i64> out;
    tools::xor_basis(in.begin(), in.end(), std::back_inserter(out));
    assert_that(out.size() == 2);
  }
  {
    std::vector<i64> in({1, 2, 3});
    std::vector<i64> out;
    tools::xor_basis(in.begin(), in.end(), std::back_inserter(out));
    assert_that(out.size() == 2);
  }
  {
    std::vector<i64> in({1});
    std::vector<i64> out;
    tools::xor_basis(in.begin(), in.end(), std::back_inserter(out));
    assert_that(out.size() == 1);
  }
  {
    std::vector<i64> in;
    std::vector<i64> out;
    tools::xor_basis(in.begin(), in.end(), std::back_inserter(out));
    assert_that(out.size() == 0);
  }

  std::cout << "Hello World" << '\n';
  return 0;
}
