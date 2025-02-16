#ifndef TOOLS_SPARSE_SEGTREE_HPP
#define TOOLS_SPARSE_SEGTREE_HPP

#include <variant>
#include "tools/lazy_sparse_segtree.hpp"

namespace tools {
  template <typename SM>
  using sparse_segtree = ::tools::lazy_sparse_segtree<
    SM,
    ::tools::detail::lazy_sparse_segtree::nop_monoid,
    ::tools::detail::lazy_sparse_segtree::nop_mapping<::std::monostate, typename SM::T>
  >;
}

#endif
