#ifndef TOOLS_ASSERT_THAT_HPP
#define TOOLS_ASSERT_THAT_HPP

#include <iostream>
#include <cstdlib>

#define assert_that(cond) do {\
  if (!(cond)) {\
    ::std::cerr << __FILE__ << ':' << __LINE__ << ": " << __func__ << ": Assertion `" << #cond << "' failed." << '\n';\
    ::std::exit(EXIT_FAILURE);\
  }\
} while (false)

#endif
