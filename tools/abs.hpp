#ifndef TOOLS_ABS_HPP
#define TOOLS_ABS_HPP

#include <cmath>
#include <type_traits>
#include <utility>

namespace tools {
  namespace detail {
    namespace abs {
      template <typename T>
      struct impl {
        constexpr T operator()(const T x) const noexcept(noexcept(std::abs(x))) {
          return std::abs(x);
        }
      };
    }
  }

  template <typename T>
  constexpr auto abs(T&& x) noexcept(noexcept(tools::detail::abs::impl<std::remove_cvref_t<T>>{}(std::forward<T>(x)))) -> decltype(auto) {
    return tools::detail::abs::impl<std::remove_cvref_t<T>>{}(std::forward<T>(x));
  }
}

#endif
