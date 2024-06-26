#ifndef TOOLS_INT128_T_HPP
#define TOOLS_INT128_T_HPP

#include <iostream>
#include <string>
#include <cassert>
#include <cstddef>
#include <algorithm>
#include "tools/abs.hpp"
#include "tools/uint128_t.hpp"

namespace tools {
  using int128_t = __int128;

  constexpr ::tools::int128_t abs(const ::tools::int128_t& x) {
    return x < 0 ? -x : x;
  }
}

constexpr inline ::tools::int128_t INT128_MAX = (::tools::int128_t(1) << 126) | ((::tools::int128_t(1) << 126) - 1);
constexpr inline ::tools::int128_t INT128_MIN = -INT128_MAX - 1;

::std::istream& operator>>(::std::istream& is, ::tools::int128_t& x) {
  ::std::string s;
  is >> s;
  assert(!s.empty());

  if (s == "-170141183460469231731687303715884105728") {
    x = INT128_MIN;
    return is;
  }

  x = 0;
  for (::std::size_t i = s[0] == '+' || s[0] == '-'; i < s.size(); ++i) {
    assert('0' <= s[i] && s[i] <= '9');
    x = 10 * x + (s[i] - '0');
  }

  if (s[0] == '-') x = -x;

  return is;
}

::std::ostream& operator<<(::std::ostream& os, ::tools::int128_t x) {
  if (x == 0) return os << '0';
  if (x == INT128_MIN) return os << "-170141183460469231731687303715884105728";

  ::std::string s;
  const bool negative = x < 0;

  if (negative) x = -x;
  while (x > 0) {
    s.push_back('0' + x % 10);
    x /= 10;
  }

  if (negative) s.push_back('-');
  ::std::reverse(s.begin(), s.end());
  return os << s;
}

#endif
