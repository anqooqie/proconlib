#ifndef TOOLS_EXP_HPP
#define TOOLS_EXP_HPP

#include <cmath>
#include <type_traits>
#include <utility>

namespace tools {
  namespace detail::exp {
    template <typename T>
    struct impl {
      constexpr decltype(auto) operator()(const T x) const noexcept(noexcept(std::exp(x))) {
        return std::exp(x);
      }
    };
  }

  template <typename T>
  constexpr decltype(auto) exp(T&& x) noexcept(noexcept(tools::detail::exp::impl<std::remove_cvref_t<T>>{}(std::forward<T>(x)))) {
    return tools::detail::exp::impl<std::remove_cvref_t<T>>{}(std::forward<T>(x));
  }
}

#endif
