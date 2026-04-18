#ifndef TOOLS_ASSERT_CLOSE_HPP
#define TOOLS_ASSERT_CLOSE_HPP

#include <algorithm>
#include <cassert>
#include <cmath>
#include <concepts>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>
#include <source_location>

namespace tools {
  template <std::floating_point T>
  constexpr void assert_close(const T expected, const T actual, const T tolerance, const std::source_location loc = std::source_location::current()) {
    assert(tolerance >= T(0));
    const T diff = std::abs(expected - actual);
    const T threshold = tolerance * std::max({T(1), std::abs(expected), std::abs(actual)});
    if (diff <= threshold) return;
    if consteval {
      throw "assertion failed";
    } else {
      std::cerr << std::setprecision(std::numeric_limits<T>::max_digits10)
                << loc.file_name() << ':' << loc.line() << ": " << loc.function_name()
                << ": assert_close failed: |" << expected << " - " << actual << "| = "
                << diff << " > " << threshold
                << " (tolerance=" << tolerance << ")" << '\n';
      std::abort();
    }
  }
}

#endif
