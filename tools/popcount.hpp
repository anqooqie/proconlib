#ifndef TOOLS_POPCOUNT_HPP
#define TOOLS_POPCOUNT_HPP

#include <cstdint>

namespace tools {

  inline ::std::uint32_t popcount(::std::uint32_t x) {
    x = (x & static_cast<::std::uint32_t>(0x55555555ull)) + (x >> static_cast<::std::uint32_t>(1) & static_cast<::std::uint32_t>(0x55555555ull));
    x = (x & static_cast<::std::uint32_t>(0x33333333ull)) + (x >> static_cast<::std::uint32_t>(2) & static_cast<::std::uint32_t>(0x33333333ull));
    x = (x & static_cast<::std::uint32_t>(0x0f0f0f0full)) + (x >> static_cast<::std::uint32_t>(4) & static_cast<::std::uint32_t>(0x0f0f0f0full));
    x = (x & static_cast<::std::uint32_t>(0x00ff00ffull)) + (x >> static_cast<::std::uint32_t>(8) & static_cast<::std::uint32_t>(0x00ff00ffull));
    return (x & static_cast<::std::uint32_t>(0x0000ffffull)) + (x >> static_cast<::std::uint32_t>(16) & static_cast<::std::uint32_t>(0x0000ffffull));
  }

  inline ::std::uint64_t popcount(::std::uint64_t x) {
    x = (x & static_cast<::std::uint64_t>(0x5555555555555555ull)) + (x >> static_cast<::std::uint64_t>(1) & static_cast<::std::uint64_t>(0x5555555555555555ull));
    x = (x & static_cast<::std::uint64_t>(0x3333333333333333ull)) + (x >> static_cast<::std::uint64_t>(2) & static_cast<::std::uint64_t>(0x3333333333333333ull));
    x = (x & static_cast<::std::uint64_t>(0x0f0f0f0f0f0f0f0full)) + (x >> static_cast<::std::uint64_t>(4) & static_cast<::std::uint64_t>(0x0f0f0f0f0f0f0f0full));
    x = (x & static_cast<::std::uint64_t>(0x00ff00ff00ff00ffull)) + (x >> static_cast<::std::uint64_t>(8) & static_cast<::std::uint64_t>(0x00ff00ff00ff00ffull));
    x = (x & static_cast<::std::uint64_t>(0x0000ffff0000ffffull)) + (x >> static_cast<::std::uint64_t>(16) & static_cast<::std::uint64_t>(0x0000ffff0000ffffull));
    return (x & static_cast<::std::uint64_t>(0x00000000ffffffffull)) + (x >> static_cast<::std::uint64_t>(32) & static_cast<::std::uint64_t>(0x00000000ffffffffull));
  }

  inline ::std::int32_t popcount(::std::int32_t x) {
    return static_cast<::std::int32_t>(::tools::popcount(static_cast<::std::uint32_t>(x)));
  }

  inline ::std::int64_t popcount(::std::int64_t x) {
    return static_cast<::std::int64_t>(::tools::popcount(static_cast<::std::uint64_t>(x)));
  }
}

#endif
