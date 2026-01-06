#ifndef TOOLS_LAZY_AVL_TREE_HPP
#define TOOLS_LAZY_AVL_TREE_HPP

#include <concepts>
#include <type_traits>
#include "tools/detail/avl_tree_impl.hpp"
#include "tools/monoid.hpp"

namespace tools {
  template <tools::monoid SM, tools::monoid FM, auto mapping, bool Reversible = false>
  requires std::invocable<decltype(mapping), typename FM::T, typename SM::T>
        && std::same_as<std::invoke_result_t<decltype(mapping), typename FM::T, typename SM::T>, typename SM::T>
  using lazy_avl_tree = tools::detail::avl_tree::avl_tree_impl<Reversible, SM, FM, mapping>;
}

#endif
