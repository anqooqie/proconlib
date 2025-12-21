#ifndef TOOLS_POW_HPP
#define TOOLS_POW_HPP

#include <cassert>
#include <cmath>
#include <concepts>
#include <type_traits>
#include <utility>
#include "tools/integral.hpp"
#include "tools/group.hpp"
#include "tools/monoid.hpp"
#include "tools/monoids.hpp"
#include "tools/square.hpp"

namespace tools {
  namespace detail::pow {
    template <typename X, typename E>
    struct impl {
      template <typename G = X>
      requires std::same_as<G, X> && tools::group<G>
      constexpr typename G::T operator()(const typename G::T& b, const E n) const
      noexcept(noexcept(G::e()) && noexcept(G::op(b, b)) && noexcept(G::inv(b)))
      requires tools::integral<E> {
        if (n < 0) return G::inv((*this)(b, -n));
        if (n == 0) return G::e();
        if (n % 2 == 0) return tools::square<G>((*this)(b, n / 2));
        return G::op((*this)(b, n - 1), b);
      }

      template <typename M = X>
      requires (std::same_as<M, X> && !tools::group<M> && tools::monoid<M>)
      constexpr typename M::T operator()(const typename M::T& b, const E n) const
      noexcept(noexcept(M::e()) && noexcept(M::op(b, b)))
      requires tools::integral<E> {
        assert(n >= 0);
        if (n == 0) return M::e();
        if (n % 2 == 0) return tools::square<M>((*this)(b, n / 2));
        return M::op((*this)(b, n - 1), b);
      }

      constexpr X operator()(const X& b, const E n) const
      noexcept(noexcept(impl<tools::monoids::multiplies<X>, E>{}(b, n)))
      requires (!tools::monoid<X> && tools::integral<E>) {
        return impl<tools::monoids::multiplies<X>, E>{}(b, n);
      }

      constexpr decltype(auto) operator()(const X& b, const E n) const
      noexcept(noexcept(std::pow(b, n)))
      requires (!tools::monoid<X> && !tools::integral<E>) {
        return std::pow(b, n);
      }
    };
  }

  template <typename X = void>
  constexpr decltype(auto) pow(auto&& b, auto&& n) noexcept(noexcept(tools::detail::pow::impl<std::conditional_t<std::same_as<X, void>, std::remove_cvref_t<decltype(b)>, X>, std::remove_cvref_t<decltype(n)>>{}(std::forward<decltype(b)>(b), std::forward<decltype(n)>(n)))) {
    return tools::detail::pow::impl<std::conditional_t<std::same_as<X, void>, std::remove_cvref_t<decltype(b)>, X>, std::remove_cvref_t<decltype(n)>>{}(std::forward<decltype(b)>(b), std::forward<decltype(n)>(n));
  }
}

#endif
