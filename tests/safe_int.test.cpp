// competitive-verifier: STANDALONE

#include <cstdlib>
#include <iostream>
#include "tools/assert_that.hpp"
#include "tools/safe_int.hpp"

void test_signed_int() {
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
}

void test_unsigned_int() {
  const tools::safe_int<unsigned int> POS_INF = tools::safe_int<unsigned int>::infinity();
  const unsigned int UINT_MAX = std::numeric_limits<unsigned int>::max();
  using u = tools::safe_int<unsigned int>;

  // basic arithmetic operations
  assert_that(u(3) + u(2) == u(5));
  assert_that(u(3) - u(2) == u(1));
  assert_that(u(3) * u(2) == u(6));
  assert_that(u(3) / u(2) == u(1));
  assert_that(u(3) % u(2) == u(1));

  // operator+ should detect an overflow.
  assert_that(u(UINT_MAX - 2) + u(1) == u(UINT_MAX - 1));
  assert_that(u(UINT_MAX - 2) + u(2) == u(UINT_MAX));
  assert_that((u(UINT_MAX - 2) + u(3)).is_nan());
  assert_that(u(1) + u(UINT_MAX - 2) == u(UINT_MAX - 1));
  assert_that(u(2) + u(UINT_MAX - 2) == u(UINT_MAX));
  assert_that((u(3) + u(UINT_MAX - 2)).is_nan());

  // infinite + finite should be infinite.
  assert_that(POS_INF + u(1) == POS_INF);
  assert_that(u(1) + POS_INF == POS_INF);
  assert_that(POS_INF + POS_INF == POS_INF);

  // operator- should detect an overflow.
  assert_that(u(2) - u(1) == u(1));
  assert_that(u(2) - u(2) == u(0));
  assert_that((u(2) - u(3)).is_nan());

  // infinite - finite should be finite.
  assert_that(POS_INF - u(1) == POS_INF);

  // operator* should detect an overflow.
  assert_that(u(0) * u(0) == u(0));
  assert_that(u(0) * u(UINT_MAX) == u(0));
  assert_that((u(0) * POS_INF).is_nan());
  assert_that(u(UINT_MAX) * u(0) == u(0));
  assert_that((u(UINT_MAX) * u(UINT_MAX)).is_nan());
  assert_that(u(UINT_MAX) * POS_INF == POS_INF);
  assert_that((POS_INF * u(0)).is_nan());
  assert_that(POS_INF * u(UINT_MAX) == POS_INF);
  assert_that(POS_INF * POS_INF == POS_INF);
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  test_signed_int();
  test_unsigned_int();

  return 0;
}
