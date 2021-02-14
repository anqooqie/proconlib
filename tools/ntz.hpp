#ifndef TOOLS_NTZ_HPP
#define TOOLS_NTZ_HPP

#include <cstdint>
#include "tools/popcount.hpp"

namespace tools {

  /**
   * computes the number of trailing zeros
   * License: CC0
   * @author anqooqie
   * @param x input
   * @return the number of trailing zeros (e.g., ntz(12300) = 2)
   */
  inline ::std::uint32_t ntz(const ::std::uint32_t& x) {
    return ::tools::popcount((x & -x) - static_cast<::std::uint32_t>(1));
  }

  /**
   * computes the number of trailing zeros
   * License: CC0
   * @author anqooqie
   * @param x input
   * @return the number of trailing zeros (e.g., ntz(12300) = 2)
   */
  inline ::std::uint64_t ntz(const ::std::uint64_t& x) {
    return ::tools::popcount((x & -x) - static_cast<::std::uint64_t>(1));
  }

  /**
   * computes the number of trailing zeros
   * License: CC0
   * @author anqooqie
   * @param x input
   * @return the number of trailing zeros (e.g., ntz(12300) = 2)
   */
  inline ::std::int32_t ntz(::std::int32_t x) {
    return static_cast<::std::int32_t>(::tools::ntz(static_cast<::std::uint32_t>(x)));
  }

  /**
   * computes the number of trailing zeros
   * License: CC0
   * @author anqooqie
   * @param x input
   * @return the number of trailing zeros (e.g., ntz(12300) = 2)
   */
  inline ::std::int64_t ntz(::std::int64_t x) {
    return static_cast<::std::int64_t>(::tools::ntz(static_cast<::std::uint64_t>(x)));
  }
}

#endif
