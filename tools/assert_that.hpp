#ifndef TOOLS_ASSERT_THAT_HPP
#define TOOLS_ASSERT_THAT_HPP

#include <iostream>
#include <cstdlib>

#define assert_that_impl(cond, file, line, func) do {\
  if (!cond) {\
    ::std::cerr << file << ':' << line << ": " << func << ": Assertion `" << #cond << "' failed." << '\n';\
    ::std::exit(EXIT_FAILURE);\
  }\
} while (false)
#define assert_that(...) assert_that_impl((__VA_ARGS__), __FILE__, __LINE__, __func__)

#endif
