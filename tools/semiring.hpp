#ifndef TOOLS_SEMIRING_HPP
#define TOOLS_SEMIRING_HPP

#include "tools/commutative_monoid.hpp"
#include "tools/monoid.hpp"

namespace tools {
  template <typename R>
  concept semiring = tools::commutative_monoid<typename R::add> && tools::monoid<typename R::mul> && std::same_as<typename R::add::T, typename R::mul::T>;
}

#endif
