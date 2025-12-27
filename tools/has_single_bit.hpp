#ifndef TOOLS_HAS_SINGLE_BIT_HPP
#define TOOLS_HAS_SINGLE_BIT_HPP

#include <bit>
#include <cassert>
#include <type_traits>
#include <utility>
#include "tools/is_signed.hpp"
#include "tools/is_unsigned.hpp"
#include "tools/make_unsigned.hpp"
#include "tools/non_bool_integral.hpp"

namespace tools {
  namespace detail::has_single_bit {
    template <tools::non_bool_integral T>
    struct impl {
      constexpr bool operator()(const T x) const noexcept(noexcept(impl<tools::make_unsigned_t<T>>{}(x))) requires tools::is_signed_v<T> {
        assert(x >= 0);
        return impl<tools::make_unsigned_t<T>>{}(x);
      }
      constexpr bool operator()(const T x) const noexcept(noexcept(std::has_single_bit(x))) requires tools::is_unsigned_v<T> {
        return std::has_single_bit(x);
      }
    };
  }

  template <typename T>
  constexpr decltype(auto) has_single_bit(T&& x) noexcept(noexcept(tools::detail::has_single_bit::impl<std::remove_cvref_t<T>>{}(std::forward<T>(x)))) {
    return tools::detail::has_single_bit::impl<std::remove_cvref_t<T>>{}(std::forward<T>(x));
  }
}

#endif
