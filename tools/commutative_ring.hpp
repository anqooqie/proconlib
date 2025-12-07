#ifndef TOOLS_COMMUTATIVE_RING_HPP
#define TOOLS_COMMUTATIVE_RING_HPP

#include "tools/commutative_monoid.hpp"
#include "tools/ring.hpp"

namespace tools {
  template <typename R>
  concept commutative_ring = tools::ring<R> && tools::commutative_monoid<typename R::mul>;
}

#endif
