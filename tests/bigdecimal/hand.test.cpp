// competitive-verifier: STANDALONE

#include <iostream>
#include "tools/assert_that.hpp"
#include "tools/bigdecimal.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  assert_that(::tools::bigdecimal("0.003").divide_and_copy(::tools::bigdecimal("20"), 4, ::tools::rounding_mode::half_even) == ::tools::bigdecimal("0.0002"));
  assert_that(::tools::bigdecimal("0.03").divide_and_copy(::tools::bigdecimal("20"), 3, ::tools::rounding_mode::half_even) == ::tools::bigdecimal("0.002"));
  assert_that(::tools::bigdecimal("0.3").divide_and_copy(::tools::bigdecimal("20"), 2, ::tools::rounding_mode::half_even) == ::tools::bigdecimal("0.02"));
  assert_that(::tools::bigdecimal("3").divide_and_copy(::tools::bigdecimal("20"), 1, ::tools::rounding_mode::half_even) == ::tools::bigdecimal("0.2"));
  assert_that(::tools::bigdecimal("30").divide_and_copy(::tools::bigdecimal("20"), 0, ::tools::rounding_mode::half_even) == ::tools::bigdecimal("2"));
  assert_that(::tools::bigdecimal("300").divide_and_copy(::tools::bigdecimal("20"), -1, ::tools::rounding_mode::half_even) == ::tools::bigdecimal("20"));
  assert_that(::tools::bigdecimal("3000").divide_and_copy(::tools::bigdecimal("20"), -2, ::tools::rounding_mode::half_even) == ::tools::bigdecimal("200"));
  assert_that(::tools::bigdecimal("0.001").divide_and_copy(::tools::bigdecimal("4"), 4, ::tools::rounding_mode::half_even) == ::tools::bigdecimal("0.0002"));
  assert_that(::tools::bigdecimal("0.01").divide_and_copy(::tools::bigdecimal("4"), 3, ::tools::rounding_mode::half_even) == ::tools::bigdecimal("0.002"));
  assert_that(::tools::bigdecimal("0.1").divide_and_copy(::tools::bigdecimal("4"), 2, ::tools::rounding_mode::half_even) == ::tools::bigdecimal("0.02"));
  assert_that(::tools::bigdecimal("1").divide_and_copy(::tools::bigdecimal("4"), 1, ::tools::rounding_mode::half_even) == ::tools::bigdecimal("0.2"));
  assert_that(::tools::bigdecimal("10").divide_and_copy(::tools::bigdecimal("4"), 0, ::tools::rounding_mode::half_even) == ::tools::bigdecimal("2"));
  assert_that(::tools::bigdecimal("100").divide_and_copy(::tools::bigdecimal("4"), -1, ::tools::rounding_mode::half_even) == ::tools::bigdecimal("20"));
  assert_that(::tools::bigdecimal("1000").divide_and_copy(::tools::bigdecimal("4"), -2, ::tools::rounding_mode::half_even) == ::tools::bigdecimal("200"));

  return 0;
}
