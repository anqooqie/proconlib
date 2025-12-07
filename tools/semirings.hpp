#ifndef TOOLS_SEMIRINGS_HPP
#define TOOLS_SEMIRINGS_HPP

#include "tools/commutative_monoid.hpp"
#include "tools/groups.hpp"
#include "tools/monoid.hpp"
#include "tools/monoids.hpp"

namespace tools {
  namespace semirings {
    template <tools::commutative_monoid A, tools::monoid M>
    struct of {
      using add = A;
      using mul = M;
    };

    template <typename R>
    using min_plus = tools::semirings::of<tools::monoids::min<R>, tools::groups::plus<R>>;

    template <typename R>
    using max_plus = tools::semirings::of<tools::monoids::max<R>, tools::groups::plus<R>>;

    template <typename R>
    using min_max = tools::semirings::of<tools::monoids::min<R>, tools::monoids::max<R>>;

    template <typename R>
    using max_min = tools::semirings::of<tools::monoids::max<R>, tools::monoids::min<R>>;
  }
}

#endif
