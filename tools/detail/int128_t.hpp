#ifndef TOOLS_DETAIL_INT128_T_HPP
#define TOOLS_DETAIL_INT128_T_HPP

#include <algorithm>
#include <cassert>
#include <cstddef>
#include <cstdint>
#include <functional>
#include <iostream>
#include <string>
#include <string_view>
#include "tools/abs.hpp"
#include "tools/is_integral.hpp"
#include "tools/is_signed.hpp"
#include "tools/is_unsigned.hpp"
#include "tools/hash_combine.hpp"
#include "tools/make_signed.hpp"
#include "tools/make_unsigned.hpp"
#include "tools/now.hpp"

namespace tools {
  using uint128_t = unsigned __int128;
  using int128_t = __int128;

  namespace detail {
    namespace int128_t {
      constexpr ::tools::uint128_t parse_unsigned(const ::std::string_view s) noexcept {
        assert(!s.empty());
        ::tools::uint128_t x = 0;
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
        return x;
      }

      constexpr ::tools::int128_t parse_signed(const ::std::string_view s) noexcept {
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

  constexpr ::tools::uint128_t abs(const ::tools::uint128_t& x) noexcept {
    return x;
  }
  constexpr ::tools::int128_t abs(const ::tools::int128_t& x) {
    return x >= 0 ? x : -x;
  }
}

#define UINT128_C(c) ::tools::detail::int128_t::parse_unsigned(#c)
#define INT128_C(c) ::tools::detail::int128_t::parse_signed(#c)

inline ::std::istream& operator>>(::std::istream& is, ::tools::uint128_t& x) {
  ::std::string s;
  is >> s;
  x = ::tools::detail::int128_t::parse_unsigned(s);
  return is;
}
inline ::std::istream& operator>>(::std::istream& is, ::tools::int128_t& x) {
  ::std::string s;
  is >> s;
  x = ::tools::detail::int128_t::parse_signed(s);
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
    struct hash<::tools::uint128_t> {
      ::std::size_t operator()(const ::tools::uint128_t& x) const {
        static const ::std::size_t seed = ::tools::now();

        ::std::size_t hash = seed;
        ::tools::hash_combine(hash, static_cast<::std::uint64_t>(x >> 64));
        ::tools::hash_combine(hash, static_cast<::std::uint64_t>(x & ((UINT128_C(1) << 64) - 1)));
        return hash;
      }
    };
    template <>
    struct hash<::tools::int128_t> {
      ::std::size_t operator()(const ::tools::int128_t& x) const {
        static ::std::hash<::tools::uint128_t> hasher;
        return hasher(static_cast<::tools::uint128_t>(x));
      }
    };
  }
#endif

namespace tools {
  template <>
  struct is_integral<::tools::int128_t> : ::std::true_type {};
  template <>
  struct is_integral<::tools::uint128_t> : ::std::true_type {};
  template <>
  struct is_integral<const ::tools::int128_t> : ::std::true_type {};
  template <>
  struct is_integral<const ::tools::uint128_t> : ::std::true_type {};
  template <>
  struct is_integral<volatile ::tools::int128_t> : ::std::true_type {};
  template <>
  struct is_integral<volatile ::tools::uint128_t> : ::std::true_type {};
  template <>
  struct is_integral<const volatile ::tools::int128_t> : ::std::true_type {};
  template <>
  struct is_integral<const volatile ::tools::uint128_t> : ::std::true_type {};

  template <>
  struct is_signed<::tools::int128_t> : ::std::true_type {};
  template <>
  struct is_signed<::tools::uint128_t> : ::std::false_type {};
  template <>
  struct is_signed<const ::tools::int128_t> : ::std::true_type {};
  template <>
  struct is_signed<const ::tools::uint128_t> : ::std::false_type {};
  template <>
  struct is_signed<volatile ::tools::int128_t> : ::std::true_type {};
  template <>
  struct is_signed<volatile ::tools::uint128_t> : ::std::false_type {};
  template <>
  struct is_signed<const volatile ::tools::int128_t> : ::std::true_type {};
  template <>
  struct is_signed<const volatile ::tools::uint128_t> : ::std::false_type {};

  template <>
  struct is_unsigned<::tools::int128_t> : ::std::false_type {};
  template <>
  struct is_unsigned<::tools::uint128_t> : ::std::true_type {};
  template <>
  struct is_unsigned<const ::tools::int128_t> : ::std::false_type {};
  template <>
  struct is_unsigned<const ::tools::uint128_t> : ::std::true_type {};
  template <>
  struct is_unsigned<volatile ::tools::int128_t> : ::std::false_type {};
  template <>
  struct is_unsigned<volatile ::tools::uint128_t> : ::std::true_type {};
  template <>
  struct is_unsigned<const volatile ::tools::int128_t> : ::std::false_type {};
  template <>
  struct is_unsigned<const volatile ::tools::uint128_t> : ::std::true_type {};

  template <>
  struct make_signed<::tools::int128_t> {
    using type = ::tools::int128_t;
  };
  template <>
  struct make_signed<::tools::uint128_t> {
    using type = ::tools::int128_t;
  };
  template <>
  struct make_signed<const ::tools::int128_t> {
    using type = const ::tools::int128_t;
  };
  template <>
  struct make_signed<const ::tools::uint128_t> {
    using type = const ::tools::int128_t;
  };
  template <>
  struct make_signed<volatile ::tools::int128_t> {
    using type = volatile ::tools::int128_t;
  };
  template <>
  struct make_signed<volatile ::tools::uint128_t> {
    using type = volatile ::tools::int128_t;
  };
  template <>
  struct make_signed<const volatile ::tools::int128_t> {
    using type = const volatile ::tools::int128_t;
  };
  template <>
  struct make_signed<const volatile ::tools::uint128_t> {
    using type = const volatile ::tools::int128_t;
  };

  template <>
  struct make_unsigned<::tools::int128_t> {
    using type = ::tools::uint128_t;
  };
  template <>
  struct make_unsigned<::tools::uint128_t> {
    using type = ::tools::uint128_t;
  };
  template <>
  struct make_unsigned<const ::tools::int128_t> {
    using type = const ::tools::uint128_t;
  };
  template <>
  struct make_unsigned<const ::tools::uint128_t> {
    using type = const ::tools::uint128_t;
  };
  template <>
  struct make_unsigned<volatile ::tools::int128_t> {
    using type = volatile ::tools::uint128_t;
  };
  template <>
  struct make_unsigned<volatile ::tools::uint128_t> {
    using type = volatile ::tools::uint128_t;
  };
  template <>
  struct make_unsigned<const volatile ::tools::int128_t> {
    using type = const volatile ::tools::uint128_t;
  };
  template <>
  struct make_unsigned<const volatile ::tools::uint128_t> {
    using type = const volatile ::tools::uint128_t;
  };
}

#endif
