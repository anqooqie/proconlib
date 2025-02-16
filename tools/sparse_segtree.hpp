#ifndef TOOLS_SPARSE_SEGTREE_HPP
#define TOOLS_SPARSE_SEGTREE_HPP

#include <variant>
#include "tools/lazy_sparse_segtree.hpp"
#include "tools/nop_mapping.hpp"
#include "tools/nop_monoid.hpp"

namespace tools {
  template <typename SM>
  using sparse_segtree = ::tools::lazy_sparse_segtree<SM, ::tools::nop_monoid, ::tools::nop_mapping<::std::monostate, typename SM::T>>;
}

#endif
