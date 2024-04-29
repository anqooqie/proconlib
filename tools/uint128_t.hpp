#ifndef TOOLS_UINT128_T_HPP
#define TOOLS_UINT128_T_HPP

#include <iostream>
#include <string>
#include <cassert>
#include <cstddef>
#include <algorithm>
#include "tools/abs.hpp"

namespace tools {
  using uint128_t = unsigned __int128;

  constexpr ::tools::uint128_t abs(const ::tools::uint128_t& x) {
    return x;
  }
}

constexpr inline ::tools::uint128_t UINT128_MAX = (::tools::uint128_t(1) << 127) | ((::tools::uint128_t(1) << 127) - 1);

::std::istream& operator>>(::std::istream& is, ::tools::uint128_t& x) {
  ::std::string s;
  is >> s;
  assert(!s.empty());

  x = 0;
  for (::std::size_t i = s[0] == '+'; i < s.size(); ++i) {
    assert('0' <= s[i] && s[i] <= '9');
    x = 10 * x + (s[i] - '0');
  }

  return is;
}

::std::ostream& operator<<(::std::ostream& os, ::tools::uint128_t x) {
  if (x == 0) return os << '0';

  ::std::string s;
  while (x > 0) {
    s.push_back('0' + x % 10);
    x /= 10;
  }
  ::std::reverse(s.begin(), s.end());

  return os << s;
}

#endif
