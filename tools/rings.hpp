#ifndef TOOLS_RINGS_HPP
#define TOOLS_RINGS_HPP

#include "tools/commutative_group.hpp"
#include "tools/groups.hpp"
#include "tools/monoid.hpp"
#include "tools/monoids.hpp"
#include "tools/semirings.hpp"

namespace tools {
  namespace rings {
    template <::tools::commutative_group A, ::tools::monoid M>
    using of = ::tools::semirings::of<A, M>;

    template <typename R>
    using plus_multiplies = ::tools::rings::of<::tools::groups::plus<R>, ::tools::monoids::multiplies<R>>;

    template <typename R>
    using xor_and = ::tools::rings::of<::tools::groups::bit_xor<R>, ::tools::monoids::bit_and<R>>;
  }
}

#endif
