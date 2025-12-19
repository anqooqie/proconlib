#ifndef TOOLS_GCD_HPP
#define TOOLS_GCD_HPP

#include <numeric>
#include <type_traits>
#include <utility>

namespace tools {
  namespace detail {
    namespace gcd {
      template <typename M, typename N>
      struct impl {
        constexpr std::common_type_t<M, N> operator()(const M m, const N n) const noexcept(noexcept(std::gcd(m, n))) {
          return std::gcd(m, n);
        }
      };
    }
  }

  template <typename M, typename N>
  constexpr decltype(auto) gcd(M&& m, N&& n) noexcept(noexcept(tools::detail::gcd::impl<std::remove_cvref_t<M>, std::remove_cvref_t<N>>{}(std::forward<M>(m), std::forward<N>(n)))) {
    return tools::detail::gcd::impl<std::remove_cvref_t<M>, std::remove_cvref_t<N>>{}(std::forward<M>(m), std::forward<N>(n));
  }
}

#endif
