#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A"

#include <iostream>
#include <vector>
#include <iterator>
#include "tools/assert_that.hpp"
#include "tools/xor_basis.hpp"

using ll = long long;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  {
    std::vector<ll> in({1, 1, 2, 4});
    std::vector<ll> out;
    tools::xor_basis(in.begin(), in.end(), std::back_inserter(out));
    assert_that(out.size() == 3);
  }
  {
    std::vector<ll> in({1, 1, 2, 1});
    std::vector<ll> out;
    tools::xor_basis(in.begin(), in.end(), std::back_inserter(out));
    assert_that(out.size() == 2);
  }
  {
    std::vector<ll> in({1, 1, 2, 3});
    std::vector<ll> out;
    tools::xor_basis(in.begin(), in.end(), std::back_inserter(out));
    assert_that(out.size() == 2);
  }
  {
    std::vector<ll> in({1, 2, 3});
    std::vector<ll> out;
    tools::xor_basis(in.begin(), in.end(), std::back_inserter(out));
    assert_that(out.size() == 2);
  }
  {
    std::vector<ll> in({1});
    std::vector<ll> out;
    tools::xor_basis(in.begin(), in.end(), std::back_inserter(out));
    assert_that(out.size() == 1);
  }
  {
    std::vector<ll> in;
    std::vector<ll> out;
    tools::xor_basis(in.begin(), in.end(), std::back_inserter(out));
    assert_that(out.size() == 0);
  }

  std::cout << "Hello World" << '\n';
  return 0;
}
