#ifndef TOOLS_CEIL_LOG2_HPP
#define TOOLS_CEIL_LOG2_HPP

#include <cstdint>

namespace tools {

  inline std::uint32_t ceil_log2(std::uint32_t x) {
    static const ::std::uint32_t t[6] = {
      0xFFFF0000u,
      0x0000FF00u,
      0x000000F0u,
      0x0000000Cu,
      0x00000002u
    };

    ::std::uint32_t y = (((x & (x - 1)) == 0) ? 0 : 1);
    ::std::uint32_t j = 16;

    for (const ::std::uint32_t& t_i : t) {
      ::std::uint32_t k = (((x & t_i) == 0) ? 0 : j);
      y += k;
      x >>= k;
      j >>= 1;
    }

    return y;
  }

  inline ::std::uint64_t ceil_log2(::std::uint64_t x) {
    static const ::std::uint64_t t[6] = {
      0xFFFFFFFF00000000u,
      0x00000000FFFF0000u,
      0x000000000000FF00u,
      0x00000000000000F0u,
      0x000000000000000Cu,
      0x0000000000000002u
    };

    ::std::uint64_t y = (((x & (x - 1)) == 0) ? 0 : 1);
    ::std::uint64_t j = 32;

    for (const ::std::uint64_t& t_i : t) {
      ::std::uint64_t k = (((x & t_i) == 0) ? 0 : j);
      y += k;
      x >>= k;
      j >>= 1;
    }

    return y;
  }

  inline ::std::int32_t ceil_log2(::std::int32_t x) {
    return static_cast<::std::int32_t>(::tools::ceil_log2(static_cast<::std::uint32_t>(x)));
  }

  inline ::std::int64_t ceil_log2(::std::int64_t x) {
    return static_cast<::std::int64_t>(::tools::ceil_log2(static_cast<::std::uint64_t>(x)));
  }
}

#endif
