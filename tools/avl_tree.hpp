#ifndef TOOLS_AVL_TREE_HPP
#define TOOLS_AVL_TREE_HPP

#include <variant>
#include "tools/detail/avl_tree_impl.hpp"
#include "tools/monoid.hpp"
#include "tools/nop_mapping.hpp"
#include "tools/nop_monoid.hpp"

namespace tools {
  template <tools::monoid SM, bool Reversible = false>
  using avl_tree = tools::detail::avl_tree::avl_tree_impl<Reversible, SM, tools::nop_monoid, tools::nop_mapping<std::monostate, typename SM::T>>;
}

#endif
