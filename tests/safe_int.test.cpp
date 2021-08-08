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
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  const tools::safe_int<int> POS_INF = tools::safe_int<int>::infinity();
  const tools::safe_int<int> NEG_INF = -tools::safe_int<int>::infinity();
  const int INT_MAX = std::numeric_limits<int>::max();
  const int INT_MIN = std::numeric_limits<int>::min();
  using s = tools::safe_int<int>;

  // basic arithmetic operations
  assert_that(s(1) + s(2) == s(3));
  assert_that(s(1) - s(2) == s(-1));
  assert_that(s(1) * s(2) == s(2));
  assert_that(s(1) / s(2) == s(0));
  assert_that(s(1) % s(2) == s(1));

  // operator+ should detect an overflow.
  assert_that(s(INT_MAX - 2) + s(1) == s(INT_MAX - 1));
  assert_that(s(INT_MAX - 2) + s(2) == s(INT_MAX));
  assert_that((s(INT_MAX - 2) + s(3)).is_nan());
  assert_that(s(1) + s(INT_MAX - 2) == s(INT_MAX - 1));
  assert_that(s(2) + s(INT_MAX - 2) == s(INT_MAX));
  assert_that((s(3) + s(INT_MAX - 2)).is_nan());
  assert_that(s(INT_MIN + 2) + s(-1) == s(INT_MIN + 1));
  assert_that(s(INT_MIN + 2) + s(-2) == s(INT_MIN));
  assert_that((s(INT_MIN + 2) + s(-3)).is_nan());
  assert_that(s(-1) + s(INT_MIN + 2) == s(INT_MIN + 1));
  assert_that(s(-2) + s(INT_MIN + 2) == s(INT_MIN));
  assert_that((s(-3) + s(INT_MIN + 2)).is_nan());

  // infinite + finite should be infinite.
  assert_that(POS_INF + s(-1) == POS_INF);
  assert_that(s(-1) + POS_INF == POS_INF);
  assert_that(POS_INF + POS_INF == POS_INF);
  assert_that(NEG_INF + s(1) == NEG_INF);
  assert_that(s(1) + NEG_INF == NEG_INF);
  assert_that(NEG_INF + NEG_INF == NEG_INF);

  // operator- should detect an overflow.
  assert_that(s(INT_MAX - 2) - s(-1) == s(INT_MAX - 1));
  assert_that(s(INT_MAX - 2) - s(-2) == s(INT_MAX));
  assert_that(s((INT_MAX - 2) - s(-3)).is_nan());
  assert_that(s(INT_MIN + 2) - s(1) == s(INT_MIN + 1));
  assert_that(s(INT_MIN + 2) - s(2) == s(INT_MIN));
  assert_that((s(INT_MIN + 2) - s(3)).is_nan());

  // infinite - finite should be finite.
  assert_that(POS_INF - s(1) == POS_INF);
  assert_that(POS_INF - NEG_INF == POS_INF);
  assert_that(NEG_INF - s(-1) == NEG_INF);
  assert_that(NEG_INF - POS_INF == NEG_INF);

  // operator* should detect an overflow.
  assert_that(NEG_INF * NEG_INF == POS_INF);
  assert_that(NEG_INF * s(INT_MIN) == POS_INF);
  assert_that((NEG_INF * s(0)).is_nan());
  assert_that(NEG_INF * s(INT_MAX) == NEG_INF);
  assert_that(NEG_INF * POS_INF == NEG_INF);
  assert_that(s(INT_MIN) * NEG_INF == POS_INF);
  assert_that((s(INT_MIN) * s(INT_MIN)).is_nan());
  assert_that(s(INT_MIN) * s(0) == s(0));
  assert_that((s(INT_MIN) * s(INT_MAX)).is_nan());
  assert_that(s(INT_MIN) * POS_INF == NEG_INF);
  assert_that((s(0) * NEG_INF).is_nan());
  assert_that(s(0) * s(INT_MIN) == s(0));
  assert_that(s(0) * s(0) == s(0));
  assert_that(s(0) * s(INT_MAX) == s(0));
  assert_that((s(0) * POS_INF).is_nan());
  assert_that(s(INT_MAX) * NEG_INF == NEG_INF);
  assert_that((s(INT_MAX) * s(INT_MIN)).is_nan());
  assert_that(s(INT_MAX) * s(0) == s(0));
  assert_that((s(INT_MAX) * s(INT_MAX)).is_nan());
  assert_that(s(INT_MAX) * POS_INF == POS_INF);
  assert_that(POS_INF * NEG_INF == NEG_INF);
  assert_that(POS_INF * s(INT_MIN) == NEG_INF);
  assert_that((POS_INF * s(0)).is_nan());
  assert_that(POS_INF * s(INT_MAX) == POS_INF);
  assert_that(POS_INF * POS_INF == POS_INF);

  std::cout << "Hello World" << '\n';
  return 0;
}
