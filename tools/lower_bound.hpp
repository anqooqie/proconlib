#ifndef TOOLS_LOWER_BOUND_HPP
#define TOOLS_LOWER_BOUND_HPP

#include <algorithm>
#include <functional>
#include <iterator>
#include <ranges>

namespace tools {

  template <
    ::std::random_access_iterator I,
    ::std::sentinel_for<I> S,
    typename Proj = ::std::identity,
    typename T = ::std::remove_cvref_t<::std::invoke_result_t<Proj&, ::std::iter_value_t<I>&>>,
    ::std::indirect_strict_weak_order<const T*, ::std::projected<I, Proj>> Comp = ::std::ranges::less
  >
  constexpr ::std::iter_difference_t<I> lower_bound(const I first, const S last, const T& value, const Comp comp = {}, const Proj proj = {}) {
    return ::std::ranges::distance(first, ::std::ranges::lower_bound(first, last, value, comp, proj));
  }

  template <
    ::std::ranges::random_access_range R,
    typename Proj = ::std::identity,
    typename T = ::std::remove_cvref_t<::std::invoke_result_t<Proj&, ::std::ranges::range_value_t<R>&>>,
    ::std::indirect_strict_weak_order<const T*, ::std::projected<::std::ranges::iterator_t<R>, Proj>> Comp = ::std::ranges::less
  >
  constexpr ::std::ranges::range_difference_t<R> lower_bound(R&& r, const T& value, const Comp comp = {}, const Proj proj = {}) {
    return ::std::ranges::distance(::std::ranges::begin(r), ::std::ranges::lower_bound(r, value, comp, proj));
  }
}

#endif
