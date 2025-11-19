#ifndef TOOLS_DETAIL_KTH_LARGEST_BY_ORACLE_HPP
#define TOOLS_DETAIL_KTH_LARGEST_BY_ORACLE_HPP

#include <cassert>
#include <cmath>
#include <concepts>
#include <numeric>
#include <type_traits>
#include <tuple>
#include <utility>

namespace tools {
  namespace detail {
    namespace kth_largest_by_oracle {
      template <bool largest, typename F>
      requires ::std::regular_invocable<F, long long>
            && ::std::assignable_from<long long&, ::std::invoke_result_t<F, long long>>
      long long impl(const long long k, const F& f, const long long l, const long long r) {
        assert(1 <= k && k <= f(largest ? l : r));
        assert(l <= r);

        long long ok, ng;
        ::std::tie(ok, ng) = largest ? ::std::make_pair(l - 1, r + 1) : ::std::make_pair(r + 1, l - 1);
        while (::std::abs(ng - ok) > 1) {
          const auto mid = ::std::midpoint(ok, ng);
          (::std::cmp_greater_equal(f(mid), k) ? ok : ng) = mid;
        }
        return ok;
      }
    }
  }
}

#endif
