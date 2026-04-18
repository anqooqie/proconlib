#ifndef TOOLS_ASSERT_THAT_HPP
#define TOOLS_ASSERT_THAT_HPP

#include <cstdlib>
#include <iostream>
#include <source_location>

namespace tools {
  namespace detail::assert_that {
    constexpr void impl(const bool cond, const char* const expr, const std::source_location loc = std::source_location::current()) {
      if (cond) return;
      if consteval {
        throw "assertion failed";
      } else {
        std::cerr << loc.file_name() << ':' << loc.line() << ": " << loc.function_name() << ": Assertion `" << expr << "' failed." << '\n';
        std::abort();
      }
    }
  }
}

#define assert_that(...) ::tools::detail::assert_that::impl((__VA_ARGS__), #__VA_ARGS__)

#endif
