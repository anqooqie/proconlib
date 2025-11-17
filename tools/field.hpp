#ifndef TOOLS_FIELD_HPP
#define TOOLS_FIELD_HPP

#include "tools/commutative_group.hpp"
#include "tools/commutative_ring.hpp"

namespace tools {
  template <typename F>
  concept field = ::tools::commutative_ring<F> && ::tools::commutative_group<typename F::mul>;
}

#endif
