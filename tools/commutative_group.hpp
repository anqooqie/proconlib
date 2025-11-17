#ifndef TOOLS_COMMUTATIVE_GROUP_HPP
#define TOOLS_COMMUTATIVE_GROUP_HPP

#include "tools/commutative_monoid.hpp"
#include "tools/group.hpp"

namespace tools {
  template <typename G>
  concept commutative_group = ::tools::group<G> && ::tools::commutative_monoid<G>;
}

#endif
