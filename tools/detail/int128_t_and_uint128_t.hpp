#ifndef TOOLS_DETAIL_INT128_T_AND_UINT128_T_HPP
#define TOOLS_DETAIL_INT128_T_AND_UINT128_T_HPP

#include <algorithm>
#include <cassert>
#include <cstddef>
#include <cstdint>
#include <functional>
#include <iostream>
#include <limits>
#include <string>
#include <string_view>
#include <utility>
#include <type_traits>
#include "tools/abs.hpp"
#include "tools/bit_ceil.hpp"
#include "tools/bit_floor.hpp"
#include "tools/bit_width.hpp"
#include "tools/countr_zero.hpp"
#include "tools/gcd.hpp"
#include "tools/hash_combine.hpp"
#include "tools/is_integral.hpp"
#include "tools/is_signed.hpp"
#include "tools/is_unsigned.hpp"
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

#if defined(__GLIBCXX__) && defined(__STRICT_ANSI__)
  template <>
  constexpr ::tools::uint128_t bit_ceil<::tools::uint128_t>(::tools::uint128_t x) noexcept {
    if (x <= 1) return 1;
    --x;
    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;
    x |= x >> 32;
    x |= x >> 64;
    return ++x;
  }

  template <>
  constexpr ::tools::uint128_t bit_floor<::tools::uint128_t>(::tools::uint128_t x) noexcept {
    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;
    x |= x >> 32;
    x |= x >> 64;
    return x & ~(x >> 1);
  }

  template <>
  constexpr int bit_width<::tools::uint128_t>(::tools::uint128_t x) noexcept {
    int w = 0;
    if (x & UINT128_C(0xffffffffffffffff0000000000000000)) {
      x >>= 64;
      w += 64;
    }
    if (x & UINT128_C(0xffffffff00000000)) {
      x >>= 32;
      w += 32;
    }
    if (x & UINT128_C(0xffff0000)) {
      x >>= 16;
      w += 16;
    }
    if (x & UINT128_C(0xff00)) {
      x >>= 8;
      w += 8;
    }
    if (x & UINT128_C(0xf0)) {
      x >>= 4;
      w += 4;
    }
    if (x & UINT128_C(0xc)) {
      x >>= 2;
      w += 2;
    }
    if (x & UINT128_C(0x2)) {
      x >>= 1;
      w += 1;
    }
    w += x;
    return w;
  }

  namespace detail {
    namespace countr_zero {
      template <::std::size_t N>
      struct ntz_traits;

      template <>
      struct ntz_traits<128> {
        using type = ::tools::uint128_t;
        static constexpr int shift = 120;
        static constexpr type magic = UINT128_C(0x01061438916347932a5cd9d3ead7b77f);
        static constexpr int ntz_table[255] = {
          128,   0,   1,  -1,   2,  -1,   8,  -1,   3,  -1,  15,  -1,   9,  -1,  22,  -1,
            4,  -1,  29,  -1,  16,  -1,  36,  -1,  10,  -1,  43,  -1,  23,  -1,  50,  -1,
            5,  -1,  33,  -1,  30,  -1,  57,  -1,  17,  -1,  64,  -1,  37,  -1,  71,  -1,
           11,  -1,  60,  -1,  44,  -1,  78,  -1,  24,  -1,  85,  -1,  51,  -1,  92,  -1,
           -1,   6,  -1,  20,  -1,  34,  -1,  48,  31,  -1,  -1,  69,  58,  -1,  -1,  90,
           18,  -1,  67,  -1,  65,  -1,  99,  -1,  38,  -1, 101,  -1,  72,  -1, 106,  -1,
           -1,  12,  -1,  40,  -1,  61,  -1,  82,  45,  -1,  -1, 103,  79,  -1, 113,  -1,
           -1,  25,  -1,  74,  86,  -1,  -1, 116,  -1,  52,  -1, 108,  -1,  93,  -1, 120,
          127,  -1,  -1,   7,  -1,  14,  -1,  21,  -1,  28,  -1,  35,  -1,  42,  -1,  49,
           -1,  32,  -1,  56,  -1,  63,  -1,  70,  -1,  59,  -1,  77,  -1,  84,  -1,  91,
           -1,  19,  -1,  47,  -1,  68,  -1,  89,  -1,  66,  -1,  98,  -1, 100,  -1, 105,
           -1,  39,  -1,  81,  -1, 102,  -1, 112,  -1,  73,  -1, 115,  -1, 107,  -1, 119,
          126,  -1,  13,  -1,  27,  -1,  41,  -1,  -1,  55,  62,  -1,  -1,  76,  83,  -1,
           -1,  46,  -1,  88,  -1,  97,  -1, 104,  -1,  80,  -1, 111,  -1, 114,  -1, 118,
          125,  -1,  26,  -1,  54,  -1,  75,  -1,  -1,  87,  96,  -1,  -1, 110,  -1, 117,
          124,  -1,  53,  -1,  -1,  95, 109,  -1, 123,  -1,  94,  -1, 122,  -1, 121
        };
      };

      template <typename T>
      constexpr int impl(const T x) noexcept {
        using tr = ::tools::detail::countr_zero::ntz_traits<::std::numeric_limits<T>::digits>;
        using type = typename tr::type;
        return tr::ntz_table[static_cast<type>(tr::magic * static_cast<type>(x & -x)) >> tr::shift];
      }
    }
  }

  template <>
  constexpr int countr_zero<::tools::uint128_t>(const ::tools::uint128_t x) noexcept {
    return ::tools::detail::countr_zero::impl(x);
  }

  constexpr ::tools::uint128_t gcd(::tools::uint128_t m, ::tools::uint128_t n) noexcept {
    while (n != 0) {
      m %= n;
      ::std::swap(m, n);
    }
    return m;
  }
  template <typename M, typename N> requires (
    ((::std::is_integral_v<M> && !::std::is_same_v<::std::remove_cv_t<M>, bool>) || ::std::is_same_v<::std::remove_cv_t<M>, ::tools::int128_t> || ::std::is_same_v<::std::remove_cv_t<M>, ::tools::uint128_t>)
    && ((::std::is_integral_v<N> && !::std::is_same_v<::std::remove_cv_t<N>, bool>) || ::std::is_same_v<::std::remove_cv_t<N>, ::tools::int128_t> || ::std::is_same_v<::std::remove_cv_t<N>, ::tools::uint128_t>)
    && !(::std::is_integral_v<M> && !::std::is_same_v<::std::remove_cv_t<M>, bool> && ::std::is_integral_v<N> && !::std::is_same_v<::std::remove_cv_t<N>, bool>)
    && !(::std::is_same_v<::std::remove_cv_t<M>, ::tools::uint128_t> && ::std::is_same_v<::std::remove_cv_t<N>, ::tools::uint128_t>)
  )
  constexpr ::std::common_type_t<M, N> gcd(const M m, const N n) {
    return ::std::common_type_t<M, N>(
      ::tools::gcd(
        m >= 0 ? ::tools::uint128_t(m) : ::tools::uint128_t(-(m + 1)) + 1,
        n >= 0 ? ::tools::uint128_t(n) : ::tools::uint128_t(-(n + 1)) + 1
      )
    );
  }

#endif
}

#endif
