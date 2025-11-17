#ifndef TOOLS_RING_HPP
#define TOOLS_RING_HPP

#include "tools/commutative_group.hpp"
#include "tools/semiring.hpp"

namespace tools {
  template <typename R>
  concept ring = ::tools::semiring<R> && ::tools::commutative_group<typename R::add>;
}

#endif
