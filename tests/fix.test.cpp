#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A"

#include <iostream>
#include "tools/assert_that.hpp"
#include "tools/fix.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  assert_that(tools::fix([&](auto&& fib, const int n) -> int {
    return n >= 2 ? fib(n - 2) + fib(n - 1) : n;
  })(10) == 55);

  std::cout << "Hello World" << '\n';
  return 0;
}
