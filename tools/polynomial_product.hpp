#ifndef TOOLS_POLYNOMIAL_PRODUCT_HPP
#define TOOLS_POLYNOMIAL_PRODUCT_HPP

#include <concepts>
#include <functional>
#include <iterator>
#include <queue>
#include <ranges>
#include <utility>
#include <vector>
#include "tools/greater_by.hpp"
#include "tools/polynomial.hpp"
#include "tools/specialization_of.hpp"

namespace tools {
  template <::std::ranges::input_range R>
  requires (::tools::specialization_of<::std::ranges::range_value_t<R>, ::tools::polynomial>)
  ::std::ranges::range_value_t<R> polynomial_product(R&& f) {
    using P = ::std::ranges::range_value_t<R>;
    if constexpr (
      ::std::ranges::random_access_range<R> && (
        ::std::same_as<::std::ranges::range_reference_t<R>, P&> ||
        ::std::same_as<::std::ranges::range_reference_t<R>, const P&>
      )
    ) {
      if (::std::ranges::empty(f)) return ++P{};

      ::std::vector<P> cache;
      cache.reserve(::std::ranges::distance(f) - 1);
      const auto greater_by_size = ::tools::greater_by(&P::size);
      ::std::priority_queue<::std::reference_wrapper<const P>, ::std::vector<::std::reference_wrapper<const P>>, decltype(greater_by_size)> pq(greater_by_size);
      for (const auto& f_i : f) {
        pq.push(::std::cref(f_i));
      }

      while (pq.size() > 1) {
        const auto p = pq.top();
        pq.pop();
        const auto q = pq.top();
        pq.pop();
        cache.push_back(p.get() * q.get());
        pq.push(::std::cref(cache.back()));
      }

      return pq.top().get();
    } else {
      return ::tools::polynomial_product(::std::forward<R>(f) | ::std::ranges::to<::std::vector<P>>());
    }
  }
}

#endif
