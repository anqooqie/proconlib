#ifndef TOOLS_NTZ_HPP
#define TOOLS_NTZ_HPP

#include <cstdint>
#include "tools/popcount.hpp"

namespace tools {

  inline ::std::uint32_t ntz(const ::std::uint32_t& x) {
    return ::tools::popcount((x & -x) - static_cast<::std::uint32_t>(1));
  }

  inline ::std::uint64_t ntz(const ::std::uint64_t& x) {
    return ::tools::popcount((x & -x) - static_cast<::std::uint64_t>(1));
  }

  inline ::std::int32_t ntz(::std::int32_t x) {
    return static_cast<::std::int32_t>(::tools::ntz(static_cast<::std::uint32_t>(x)));
  }

  inline ::std::int64_t ntz(::std::int64_t x) {
    return static_cast<::std::int64_t>(::tools::ntz(static_cast<::std::uint64_t>(x)));
  }
}

#endif
