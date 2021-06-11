#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A"

#include <cstdlib>
#include <iostream>
#include "tools/safe_int.hpp"

void assert_that(const bool cond) {
  if (!cond) {
    std::exit(EXIT_FAILURE);
  }
}

int main() {
  const int POS_INF = std::numeric_limits<int>::max();
  const int NEG_INF = std::numeric_limits<int>::min();
  const int INT_MAX = std::numeric_limits<int>::max();
  const int INT_MIN = std::numeric_limits<int>::min();
  using s = tools::safe_int<int>;

  assert_that(s(1) + s(2) == s(3));
  assert_that(s(1) + 2 == s(3));
  assert_that(1 + s(2) == s(3));

  assert_that(s(INT_MAX - 2) + s(1) == s(INT_MAX - 1));
  assert_that(s(INT_MAX - 2) + s(2) == s(POS_INF));
  assert_that(s(INT_MAX - 2) + s(3) == s(POS_INF));
  assert_that(s(1) + s(INT_MAX - 2) == s(INT_MAX - 1));
  assert_that(s(2) + s(INT_MAX - 2) == s(POS_INF));
  assert_that(s(3) + s(INT_MAX - 2) == s(POS_INF));
  assert_that(s(INT_MIN + 2) + s(-1) == s(INT_MIN + 1));
  assert_that(s(INT_MIN + 2) + s(-2) == s(NEG_INF));
  assert_that(s(INT_MIN + 2) + s(-3) == s(NEG_INF));
  assert_that(s(-1) + s(INT_MIN + 2) == s(INT_MIN + 1));
  assert_that(s(-2) + s(INT_MIN + 2) == s(NEG_INF));
  assert_that(s(-3) + s(INT_MIN + 2) == s(NEG_INF));

  assert_that(s(POS_INF) + s(-1) == s(POS_INF));
  assert_that(s(-1) + s(POS_INF) == s(POS_INF));
  assert_that(s(POS_INF) + s(POS_INF) == s(POS_INF));
  assert_that(s(NEG_INF) + s(1) == s(NEG_INF));
  assert_that(s(1) + s(NEG_INF) == s(NEG_INF));
  assert_that(s(NEG_INF) + s(NEG_INF) == s(NEG_INF));

  assert_that(s(1) - s(2) == s(-1));
  assert_that(s(1) - 2 == s(-1));
  assert_that(1 - s(2) == s(-1));

  assert_that(s(INT_MAX - 2) - s(-1) == s(INT_MAX - 1));
  assert_that(s(INT_MAX - 2) - s(-2) == s(POS_INF));
  assert_that(s(INT_MAX - 2) - s(-3) == s(POS_INF));
  assert_that(s(INT_MIN + 2) - s(1) == s(INT_MIN + 1));
  assert_that(s(INT_MIN + 2) - s(2) == s(NEG_INF));
  assert_that(s(INT_MIN + 2) - s(3) == s(NEG_INF));

  assert_that(s(POS_INF) - s(1) == s(POS_INF));
  assert_that(s(POS_INF) - s(NEG_INF) == s(POS_INF));
  assert_that(s(NEG_INF) - s(-1) == s(NEG_INF));
  assert_that(s(NEG_INF) - s(POS_INF) == s(NEG_INF));

  assert_that(s(1) * s(2) == s(2));
  assert_that(s(1) * 2 == s(2));
  assert_that(1 * s(2) == s(2));

  assert_that(s(NEG_INF) * s(NEG_INF) == s(POS_INF));
  assert_that(s(NEG_INF) * s(INT_MIN + 1) == s(POS_INF));
  assert_that(s(NEG_INF) * s(0) == s(0));
  assert_that(s(NEG_INF) * s(INT_MAX - 1) == s(NEG_INF));
  assert_that(s(NEG_INF) * s(POS_INF) == s(NEG_INF));
  assert_that(s(INT_MIN + 1) * s(NEG_INF) == s(POS_INF));
  assert_that(s(INT_MIN + 1) * s(INT_MIN + 1) == s(POS_INF));
  assert_that(s(INT_MIN + 1) * s(0) == s(0));
  assert_that(s(INT_MIN + 1) * s(INT_MAX - 1) == s(NEG_INF));
  assert_that(s(INT_MIN + 1) * s(POS_INF) == s(NEG_INF));
  assert_that(s(0) * s(NEG_INF) == s(0));
  assert_that(s(0) * s(INT_MIN + 1) == s(0));
  assert_that(s(0) * s(0) == s(0));
  assert_that(s(0) * s(INT_MAX - 1) == s(0));
  assert_that(s(0) * s(POS_INF) == s(0));
  assert_that(s(INT_MAX - 1) * s(NEG_INF) == s(NEG_INF));
  assert_that(s(INT_MAX - 1) * s(INT_MIN + 1) == s(NEG_INF));
  assert_that(s(INT_MAX - 1) * s(0) == s(0));
  assert_that(s(INT_MAX - 1) * s(INT_MAX - 1) == s(POS_INF));
  assert_that(s(INT_MAX - 1) * s(POS_INF) == s(POS_INF));
  assert_that(s(POS_INF) * s(NEG_INF) == s(NEG_INF));
  assert_that(s(POS_INF) * s(INT_MIN + 1) == s(NEG_INF));
  assert_that(s(POS_INF) * s(0) == s(0));
  assert_that(s(POS_INF) * s(INT_MAX - 1) == s(POS_INF));
  assert_that(s(POS_INF) * s(POS_INF) == s(POS_INF));

  std::cout << "Hello World" << '\n';
  return 0;
}
