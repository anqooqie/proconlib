#ifndef TOOLS_COUNTR_ZERO_HPP
#define TOOLS_COUNTR_ZERO_HPP

#include <algorithm>
#include <bit>
#include <cassert>
#include <limits>
#include <type_traits>
#include <utility>
#include "tools/is_signed.hpp"
#include "tools/is_unsigned.hpp"
#include "tools/make_unsigned.hpp"
#include "tools/non_bool_integral.hpp"

namespace tools {
  namespace detail::countr_zero {
    template <tools::non_bool_integral T>
    struct impl {
      constexpr int operator()(const T x) const noexcept(noexcept(impl<tools::make_unsigned_t<T>>{}(x))) requires tools::is_signed_v<T> {
        assert(x >= 0);
        return std::min(impl<tools::make_unsigned_t<T>>{}(x), std::numeric_limits<T>::digits);
      }
      constexpr int operator()(const T x) const noexcept(noexcept(std::countr_zero(x))) requires tools::is_unsigned_v<T> {
        return std::countr_zero(x);
      }
    };
  }

  template <typename T>
  constexpr decltype(auto) countr_zero(T&& x) noexcept(noexcept(tools::detail::countr_zero::impl<std::remove_cvref_t<T>>{}(std::forward<T>(x)))) {
    return tools::detail::countr_zero::impl<std::remove_cvref_t<T>>{}(std::forward<T>(x));
  }
}

#endif
