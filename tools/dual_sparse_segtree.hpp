#ifndef TOOLS_DUAL_SPARSE_SEGTREE_HPP
#define TOOLS_DUAL_SPARSE_SEGTREE_HPP

#include <variant>
#include "tools/lazy_sparse_segtree.hpp"

namespace tools {
  template <typename FM>
  using dual_sparse_segtree = ::tools::lazy_sparse_segtree<
    ::tools::detail::lazy_sparse_segtree::nop_monoid,
    FM,
    ::tools::detail::lazy_sparse_segtree::nop_mapping<typename FM::T, ::std::monostate>
  >;
}

#endif
