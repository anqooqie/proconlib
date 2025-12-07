#ifndef TOOLS_GROUP_HPP
#define TOOLS_GROUP_HPP

#include <concepts>
#include "tools/monoid.hpp"

namespace tools {
  template <typename G>
  concept group = tools::monoid<G> && requires(typename G::T x) {
    { G::inv(x) } -> std::same_as<typename G::T>;
  };
}

#endif
