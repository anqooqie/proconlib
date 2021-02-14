#ifndef TOOLS_FLOOR_LOG2_HPP
#define TOOLS_FLOOR_LOG2_HPP

#include <cstdint>
#include "tools/popcount.hpp"

namespace tools {

  /**
   * computes $\left\lfloor \log_2(x) \right\rfloor$
   * License: CC0
   * @author anqooqie
   * @param x input
   * @return $\left\lfloor \log_2(x) \right\rfloor$
   */
  inline ::std::uint32_t floor_log2(::std::uint32_t x) {
    x |= (x >> static_cast<::std::uint32_t>(1));
    x |= (x >> static_cast<::std::uint32_t>(2));
    x |= (x >> static_cast<::std::uint32_t>(4));
    x |= (x >> static_cast<::std::uint32_t>(8));
    x |= (x >> static_cast<::std::uint32_t>(16));
    return ::tools::popcount(x) - static_cast<::std::uint32_t>(1);
  }

  /**
   * computes $\left\lfloor \log_2(x) \right\rfloor$
   * License: CC0
   * @author anqooqie
   * @param x input
   * @return $\left\lfloor \log_2(x) \right\rfloor$
   */
  inline ::std::uint64_t floor_log2(::std::uint64_t x) {
    x |= (x >> static_cast<::std::uint64_t>(1));
    x |= (x >> static_cast<::std::uint64_t>(2));
    x |= (x >> static_cast<::std::uint64_t>(4));
    x |= (x >> static_cast<::std::uint64_t>(8));
    x |= (x >> static_cast<::std::uint64_t>(16));
    x |= (x >> static_cast<::std::uint64_t>(32));
    return ::tools::popcount(x) - static_cast<::std::uint64_t>(1);
  }

  /**
   * computes $\left\lfloor \log_2(x) \right\rfloor$
   * License: CC0
   * @author anqooqie
   * @param x input
   * @return $\left\lfloor \log_2(x) \right\rfloor$
   */
  inline ::std::int32_t floor_log2(::std::int32_t x) {
    return static_cast<::std::int32_t>(::tools::floor_log2(static_cast<::std::uint32_t>(x)));
  }

  /**
   * computes $\left\lfloor \log_2(x) \right\rfloor$
   * License: CC0
   * @author anqooqie
   * @param x input
   * @return $\left\lfloor \log_2(x) \right\rfloor$
   */
  inline ::std::int64_t floor_log2(::std::int64_t x) {
    return static_cast<::std::int64_t>(::tools::floor_log2(static_cast<::std::uint64_t>(x)));
  }
}

#endif
