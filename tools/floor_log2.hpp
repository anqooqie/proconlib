#ifndef TOOLS_FLOOR_LOG2_HPP
#define TOOLS_FLOOR_LOG2_HPP

#include <cstdint>
#include "tools/popcount.hpp"

namespace tools {

  inline ::std::uint32_t floor_log2(::std::uint32_t x) {
    x |= (x >> static_cast<::std::uint32_t>(1));
    x |= (x >> static_cast<::std::uint32_t>(2));
    x |= (x >> static_cast<::std::uint32_t>(4));
    x |= (x >> static_cast<::std::uint32_t>(8));
    x |= (x >> static_cast<::std::uint32_t>(16));
    return ::tools::popcount(x) - static_cast<::std::uint32_t>(1);
  }

  inline ::std::uint64_t floor_log2(::std::uint64_t x) {
    x |= (x >> static_cast<::std::uint64_t>(1));
    x |= (x >> static_cast<::std::uint64_t>(2));
    x |= (x >> static_cast<::std::uint64_t>(4));
    x |= (x >> static_cast<::std::uint64_t>(8));
    x |= (x >> static_cast<::std::uint64_t>(16));
    x |= (x >> static_cast<::std::uint64_t>(32));
    return ::tools::popcount(x) - static_cast<::std::uint64_t>(1);
  }

  inline ::std::int32_t floor_log2(::std::int32_t x) {
    return static_cast<::std::int32_t>(::tools::floor_log2(static_cast<::std::uint32_t>(x)));
  }

  inline ::std::int64_t floor_log2(::std::int64_t x) {
    return static_cast<::std::int64_t>(::tools::floor_log2(static_cast<::std::uint64_t>(x)));
  }
}

#endif
