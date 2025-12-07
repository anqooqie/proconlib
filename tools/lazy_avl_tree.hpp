#ifndef TOOLS_LAZY_AVL_TREE_HPP
#define TOOLS_LAZY_AVL_TREE_HPP

#include "tools/detail/avl_tree_impl.hpp"

namespace tools {
  template <typename SM, typename FM, auto mapping, bool Reversible = false>
  using lazy_avl_tree = tools::detail::avl_tree::avl_tree_impl<Reversible, SM, FM, mapping>;
}

#endif
