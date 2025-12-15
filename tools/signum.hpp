#ifndef TOOLS_SIGNUM_HPP
#define TOOLS_SIGNUM_HPP

#include <cassert>
#include <compare>
#include <type_traits>
#include <utility>
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
      template <>
      struct impl<std::strong_ordering> {
        constexpr int operator()(const std::strong_ordering x) const noexcept {
          if (x < 0) {
            return -1;
          } else if (x == 0) {
            return 0;
          } else {
            return 1;
          }
        }
      };
      template <>
      struct impl<std::weak_ordering> {
        constexpr int operator()(const std::weak_ordering x) const noexcept {
          if (x < 0) {
            return -1;
          } else if (x == 0) {
            return 0;
          } else {
            return 1;
          }
        }
      };
      template <>
      struct impl<std::partial_ordering> {
        constexpr int operator()(const std::partial_ordering x) const noexcept {
          assert(x != std::partial_ordering::unordered);
          if (x < 0) {
            return -1;
          } else if (x == 0) {
            return 0;
          } else {
            return 1;
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
