#ifndef TOOLS_UINT128_T_HPP
#define TOOLS_UINT128_T_HPP

#include <algorithm>
#include <cassert>
#include <cstddef>
#include <cstdint>
#include <functional>
#include <iostream>
#include <string>
#include "tools/abs.hpp"
#include "tools/hash_combine.hpp"
#include "tools/now.hpp"

namespace tools {
  using uint128_t = unsigned __int128;

  namespace detail {
    namespace uint128_t {
      constexpr ::tools::uint128_t parse(const ::std::string& s) {
        assert(!s.empty());
        ::tools::uint128_t x = 0;
        for (::std::size_t i = s[0] == '+'; i < s.size(); ++i) {
          assert('0' <= s[i] && s[i] <= '9');
          x *= 10;
          x += s[i] - '0';
        }
        return x;
      }
    }
  }

  constexpr ::tools::uint128_t abs(const ::tools::uint128_t& x) noexcept {
    return x;
  }
}

#define UINT128_C(c) ::tools::detail::uint128_t::parse(#c)

inline ::std::istream& operator>>(::std::istream& is, ::tools::uint128_t& x) {
  ::std::string s;
  is >> s;
  x = ::tools::detail::uint128_t::parse(s);
  return is;
}

inline ::std::ostream& operator<<(::std::ostream& os, ::tools::uint128_t x) {
  ::std::string s;
  if (x > 0) {
    while (x > 0) {
      s.push_back('0' + x % 10);
      x /= 10;
    }
  } else {
    s.push_back('0');
  }

  ::std::ranges::reverse(s);
  return os << s;
}

#if defined(__GLIBCXX__) && defined(__STRICT_ANSI__)
  namespace std {
    template <>
    struct hash<::tools::uint128_t> {
      ::std::size_t operator()(const ::tools::uint128_t& x) const {
        static const ::std::size_t seed = ::tools::now();

        ::std::size_t hash = seed;
        ::tools::hash_combine(hash, static_cast<::std::uint64_t>(x >> 64));
        ::tools::hash_combine(hash, static_cast<::std::uint64_t>(x & ((UINT128_C(1) << 64) - 1)));
        return hash;
      }
    };
  }
#endif

#endif
