#ifndef TOOLS_EXTGCD_HPP
#define TOOLS_EXTGCD_HPP

#include <algorithm>
#include <cassert>
#include <concepts>
#include <tuple>
#include <type_traits>
#include <utility>
#include "tools/abs.hpp"
#include "tools/signed_integral.hpp"

namespace tools {
  namespace detail::extgcd {
    template <typename M, typename N>
    struct impl {
      using T = std::common_type_t<M, N>;
      constexpr std::tuple<T, T, T> operator()(const M a, const N b) const noexcept requires (tools::signed_integral<M> && tools::signed_integral<N>) {
        T prev_r = static_cast<T>(a);
        T r = static_cast<T>(b);

        const bool prev_r_is_neg = prev_r < T(0);
        const bool r_is_neg = r < T(0);

        if (prev_r_is_neg) prev_r = -prev_r;
        if (r_is_neg) r = -r;

        T prev_s(1);
        T prev_t(0);
        T s(0);
        T t(1);
        while (r != T(0)) {
          const T q = prev_r / r;
          std::tie(prev_r, r) = std::make_pair(r, prev_r - q * r);
          std::tie(prev_s, s) = std::make_pair(s, prev_s - q * s);
          std::tie(prev_t, t) = std::make_pair(t, prev_t - q * t);
        }

        if (prev_r_is_neg) prev_s = -prev_s;
        if (r_is_neg) prev_t = -prev_t;

        assert(tools::abs(prev_s) <= std::max(tools::abs(T(b)) / prev_r / T(2), T(1)));
        assert(tools::abs(prev_t) <= std::max(tools::abs(T(a)) / prev_r / T(2), T(1)));
        return std::make_tuple(prev_s, prev_t, prev_r);
      }
    };
  }

  template <typename M, typename N>
  constexpr decltype(auto) extgcd(M&& m, N&& n) noexcept(noexcept(tools::detail::extgcd::impl<std::remove_cvref_t<M>, std::remove_cvref_t<N>>{}(std::forward<M>(m), std::forward<N>(n)))) {
    return tools::detail::extgcd::impl<std::remove_cvref_t<M>, std::remove_cvref_t<N>>{}(std::forward<M>(m), std::forward<N>(n));
  }
}

#endif
