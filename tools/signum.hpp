#ifndef TOOLS_SIGNUM_HPP
#define TOOLS_SIGNUM_HPP

#include <type_traits>
#include "tools/is_unsigned.hpp"

namespace tools {
  namespace detail {
    namespace signum {
      template <typename T>
      struct impl {
        constexpr int operator()(const T x) const noexcept(noexcept(T(0))) {
          if constexpr (tools::is_unsigned_v<T>) {
            return T(0) < x;
          } else {
            return (T(0) < x) - (x < T(0));
          }
        }
      };
    }
  }

  template <typename T>
  constexpr auto signum(T&& x) noexcept(noexcept(tools::detail::signum::impl<std::remove_cvref_t<T>>{}(std::forward<T>(x)))) -> decltype(auto) {
    return tools::detail::signum::impl<std::remove_cvref_t<T>>{}(std::forward<T>(x));
  }
}

#endif
