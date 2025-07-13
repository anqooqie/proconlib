#ifndef TOOLS_MULTISORT_HPP
#define TOOLS_MULTISORT_HPP

#include <algorithm>
#include <cassert>
#include <iterator>
#include <numeric>
#include <ranges>
#include <utility>
#include <vector>

namespace tools {
  namespace detail {
    namespace multisort {
      template <::std::ranges::random_access_range R>
      void sort(R&& r, const ::std::vector<int>& p) {
        ::std::vector<::std::ranges::range_value_t<R>> sorted_r(p.size());
        for (int i = 0; i < ::std::ssize(p); ++i) {
          sorted_r[i] = ::std::move(::std::ranges::begin(r)[p[i]]);
        }
        ::std::ranges::move(sorted_r, ::std::ranges::begin(r));
      }
    }
  }

  template <
    ::std::ranges::random_access_range R1,
    ::std::ranges::random_access_range R2,
    typename Comp
  > requires ::std::sortable<::std::vector<int>::iterator, Comp>
  void multisort(R1&& r1, R2&& r2, const Comp comp) {
    const int n = ::std::ranges::size(r1);
    assert(::std::ranges::ssize(r2) == n);

    ::std::vector<int> p(n);
    ::std::iota(p.begin(), p.end(), 0);
    ::std::ranges::sort(p, comp);

    ::tools::detail::multisort::sort(::std::forward<R1>(r1), p);
    ::tools::detail::multisort::sort(::std::forward<R2>(r2), p);
  }

  template <
    ::std::ranges::random_access_range R1,
    ::std::ranges::random_access_range R2,
    ::std::ranges::random_access_range R3,
    typename Comp
  > requires ::std::sortable<::std::vector<int>::iterator, Comp>
  void multisort(R1&& r1, R2&& r2, R3&& r3, const Comp comp) {
    const int n = ::std::ranges::size(r1);
    assert(::std::ranges::ssize(r2) == n);
    assert(::std::ranges::ssize(r3) == n);

    ::std::vector<int> p(n);
    ::std::iota(p.begin(), p.end(), 0);
    ::std::ranges::sort(p, comp);

    ::tools::detail::multisort::sort(::std::forward<R1>(r1), p);
    ::tools::detail::multisort::sort(::std::forward<R2>(r2), p);
    ::tools::detail::multisort::sort(::std::forward<R3>(r3), p);
  }

  template <
    ::std::ranges::random_access_range R1,
    ::std::ranges::random_access_range R2,
    ::std::ranges::random_access_range R3,
    ::std::ranges::random_access_range R4,
    typename Comp
  > requires ::std::sortable<::std::vector<int>::iterator, Comp>
  void multisort(R1&& r1, R2&& r2, R3&& r3, R4&& r4, const Comp comp) {
    const int n = ::std::ranges::size(r1);
    assert(::std::ranges::ssize(r2) == n);
    assert(::std::ranges::ssize(r3) == n);
    assert(::std::ranges::ssize(r4) == n);

    ::std::vector<int> p(n);
    ::std::iota(p.begin(), p.end(), 0);
    ::std::ranges::sort(p, comp);

    ::tools::detail::multisort::sort(::std::forward<R1>(r1), p);
    ::tools::detail::multisort::sort(::std::forward<R2>(r2), p);
    ::tools::detail::multisort::sort(::std::forward<R3>(r3), p);
    ::tools::detail::multisort::sort(::std::forward<R4>(r4), p);
  }

  template <
    ::std::ranges::random_access_range R1,
    ::std::ranges::random_access_range R2,
    ::std::ranges::random_access_range R3,
    ::std::ranges::random_access_range R4,
    ::std::ranges::random_access_range R5,
    typename Comp
  > requires ::std::sortable<::std::vector<int>::iterator, Comp>
  void multisort(R1&& r1, R2&& r2, R3&& r3, R4&& r4, R5&& r5, const Comp comp) {
    const int n = ::std::ranges::size(r1);
    assert(::std::ranges::ssize(r2) == n);
    assert(::std::ranges::ssize(r3) == n);
    assert(::std::ranges::ssize(r4) == n);
    assert(::std::ranges::ssize(r5) == n);

    ::std::vector<int> p(n);
    ::std::iota(p.begin(), p.end(), 0);
    ::std::ranges::sort(p, comp);

    ::tools::detail::multisort::sort(::std::forward<R1>(r1), p);
    ::tools::detail::multisort::sort(::std::forward<R2>(r2), p);
    ::tools::detail::multisort::sort(::std::forward<R3>(r3), p);
    ::tools::detail::multisort::sort(::std::forward<R4>(r4), p);
    ::tools::detail::multisort::sort(::std::forward<R5>(r5), p);
  }
}

#endif
