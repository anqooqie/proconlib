// competitive-verifier: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A

#include <cstdlib>
#include <iostream>
#include <vector>
#include "tools/assert_that.hpp"
#include "tools/mex.hpp"

using ll = long long;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  std::vector<ll> v({1000000000000000000, 2, 1, 0});
  assert_that(tools::mex(v.begin(), v.end()) == 3);
  v = std::vector<ll>({3, 3, 2, 2, 1, 1, 0});
  assert_that(tools::mex(v.begin(), v.end()) == 4);
  v = std::vector<ll>({3, 2, 0, 4, 1});
  assert_that(tools::mex(v.begin(), v.end()) == 5);
  v = std::vector<ll>({3, 2, 4, 1});
  assert_that(tools::mex(v.begin(), v.end()) == 0);

  std::cout << "Hello World" << '\n';
  return 0;
}
