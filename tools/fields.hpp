#ifndef TOOLS_FIELDS_HPP
#define TOOLS_FIELDS_HPP

#include "tools/commutative_group.hpp"
#include "tools/groups.hpp"
#include "tools/rings.hpp"

namespace tools {
  namespace fields {
    template <::tools::commutative_group A, ::tools::commutative_group M>
    using of = ::tools::rings::of<A, M>;

    template <typename F>
    using plus_multiplies = ::tools::fields::of<::tools::groups::plus<F>, ::tools::groups::multiplies<F>>;
  }
}

#endif
