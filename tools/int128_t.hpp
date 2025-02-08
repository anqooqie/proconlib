#ifndef TOOLS_INT128_T_HPP
#define TOOLS_INT128_T_HPP

#include <algorithm>
#include <cassert>
#include <cstddef>
#include <functional>
#include <iostream>
#include <string>
#include <string_view>
#include "tools/abs.hpp"
#include "tools/uint128_t.hpp"

namespace tools {
  using int128_t = __int128;

  namespace detail {
    namespace int128_t {
      constexpr ::tools::int128_t parse(const ::std::string_view s) {
        assert(!s.empty());
        ::tools::int128_t x = 0;
        if (s[0] == '-') {
          ::std::size_t i = 1;
          if (i + 1 < s.size() && s[i] == '0' && (s[i + 1] == 'x' || s[i + 1] == 'X')) {
            for (i += 2; i < s.size(); ++i) {
              assert(('0' <= s[i] && s[i] <= '9') || ('a' <= s[i] && s[i] <= 'f') || ('A' <= s[i] && s[i] <= 'F'));
              x *= 16;
              if ('0' <= s[i] && s[i] <= '9') {
                x -= s[i] - '0';
              } else if ('a' <= s[i] && s[i] <= 'f') {
                x -= s[i] - 'a' + 10;
              } else {
                x -= s[i] - 'A' + 10;
              }
            }
          } else {
            for (; i < s.size(); ++i) {
              assert('0' <= s[i] && s[i] <= '9');
              x *= 10;
              x -= s[i] - '0';
            }
          }
        } else {
          ::std::size_t i = s[0] == '+';
          if (i + 1 < s.size() && s[i] == '0' && (s[i + 1] == 'x' || s[i + 1] == 'X')) {
            for (i += 2; i < s.size(); ++i) {
              assert(('0' <= s[i] && s[i] <= '9') || ('a' <= s[i] && s[i] <= 'f') || ('A' <= s[i] && s[i] <= 'F'));
              x <<= 4;
              if ('0' <= s[i] && s[i] <= '9') {
                x |= s[i] - '0';
              } else if ('a' <= s[i] && s[i] <= 'f') {
                x |= s[i] - 'a' + 10;
              } else {
                x |= s[i] - 'A' + 10;
              }
            }
          } else {
            for (; i < s.size(); ++i) {
              assert('0' <= s[i] && s[i] <= '9');
              x *= 10;
              x += s[i] - '0';
            }
          }
        }
        return x;
      }
    }
  }

  constexpr ::tools::int128_t abs(const ::tools::int128_t& x) {
    return x >= 0 ? x : -x;
  }
}

#define INT128_C(c) ::tools::detail::int128_t::parse(#c)

inline ::std::istream& operator>>(::std::istream& is, ::tools::int128_t& x) {
  ::std::string s;
  is >> s;
  x = ::tools::detail::int128_t::parse(s);
  return is;
}

inline ::std::ostream& operator<<(::std::ostream& os, ::tools::int128_t x) {
  ::std::string s;
  if (x > 0) {
    while (x > 0) {
      s.push_back('0' + x % 10);
      x /= 10;
    }
  } else if (x < 0) {
    while (x < 0) {
      s.push_back('0' + (-(x % 10)));
      x /= 10;
    }
    s.push_back('-');
  } else {
    s.push_back('0');
  }

  ::std::ranges::reverse(s);
  return os << s;
}

#if defined(__GLIBCXX__) && defined(__STRICT_ANSI__)
  namespace std {
    template <>
    struct hash<::tools::int128_t> {
      ::std::size_t operator()(const ::tools::int128_t& x) const {
        static ::std::hash<::tools::uint128_t> hasher;
        return hasher(static_cast<::tools::uint128_t>(x));
      }
    };
  }
#endif

#endif
