#ifndef TOOLS_COMMUTATIVE_MONOID_HPP
#define TOOLS_COMMUTATIVE_MONOID_HPP

#include "tools/monoid.hpp"

namespace tools {
  template <typename M>
  concept commutative_monoid = tools::monoid<M>;
}

#endif
