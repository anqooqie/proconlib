#ifndef TOOLS_LOG_HPP
#define TOOLS_LOG_HPP

#include <cmath>
#include <type_traits>
#include <utility>

namespace tools {
  namespace detail::log {
    template <typename T>
    struct impl {
      constexpr decltype(auto) operator()(const T x) const noexcept(noexcept(std::log(x))) {
        return std::log(x);
      }
    };
  }

  template <typename T>
  constexpr decltype(auto) log(T&& x) noexcept(noexcept(tools::detail::log::impl<std::remove_cvref_t<T>>{}(std::forward<T>(x)))) {
    return tools::detail::log::impl<std::remove_cvref_t<T>>{}(std::forward<T>(x));
  }
}

#endif
