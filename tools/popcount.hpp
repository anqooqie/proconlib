#ifndef TOOLS_POPCOUNT_HPP
#define TOOLS_POPCOUNT_HPP

#include <bit>
#include <cassert>
#include <type_traits>
#include <utility>
#include "tools/is_signed.hpp"
#include "tools/is_unsigned.hpp"
#include "tools/make_unsigned.hpp"
#include "tools/non_bool_integral.hpp"

namespace tools {
  namespace detail::popcount {
    template <tools::non_bool_integral T>
    struct impl {
      constexpr int operator()(const T x) const noexcept(noexcept(impl<tools::make_unsigned_t<T>>{}(x))) requires tools::is_signed_v<T> {
        assert(x >= 0);
        return impl<tools::make_unsigned_t<T>>{}(x);
      }
      constexpr int operator()(const T x) const noexcept(noexcept(std::popcount(x))) requires tools::is_unsigned_v<T> {
        return std::popcount(x);
      }
    };
  }

  template <typename T>
  constexpr decltype(auto) popcount(T&& x) noexcept(noexcept(tools::detail::popcount::impl<std::remove_cvref_t<T>>{}(std::forward<T>(x)))) {
    return tools::detail::popcount::impl<std::remove_cvref_t<T>>{}(std::forward<T>(x));
  }
}

#endif
