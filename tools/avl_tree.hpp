#ifndef TOOLS_AVL_TREE_HPP
#define TOOLS_AVL_TREE_HPP

#include "tools/detail/avl_tree_impl.hpp"

namespace tools {
  template <typename SM, bool Reversible = false>
  using avl_tree = tools::detail::avl_tree::avl_tree_impl<Reversible, SM>;
}

#endif
