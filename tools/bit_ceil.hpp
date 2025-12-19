#ifndef TOOLS_BIT_CEIL_HPP
#define TOOLS_BIT_CEIL_HPP

#include <bit>
#include <cassert>
#include <type_traits>
#include <utility>
#include "tools/is_signed.hpp"
#include "tools/is_unsigned.hpp"
#include "tools/make_unsigned.hpp"
#include "tools/non_bool_integral.hpp"

namespace tools {
  namespace detail {
    namespace bit_ceil {
      template <tools::non_bool_integral T>
      struct impl {
        constexpr T operator()(const T x) const noexcept(noexcept(impl<tools::make_unsigned_t<T>>{}(x))) requires tools::is_signed_v<T> {
          assert(x >= 0);
          return impl<tools::make_unsigned_t<T>>{}(x);
        }
        constexpr T operator()(const T x) const noexcept(noexcept(std::bit_ceil(x))) requires tools::is_unsigned_v<T> {
          return std::bit_ceil(x);
        }
      };
    }
  }

  template <typename T>
  constexpr decltype(auto) bit_ceil(T&& x) noexcept(noexcept(tools::detail::bit_ceil::impl<std::remove_cvref_t<T>>{}(std::forward<T>(x)))) {
    return tools::detail::bit_ceil::impl<std::remove_cvref_t<T>>{}(std::forward<T>(x));
  }
}

#endif
