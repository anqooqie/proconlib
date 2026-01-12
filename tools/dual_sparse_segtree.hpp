#ifndef TOOLS_DUAL_SPARSE_SEGTREE_HPP
#define TOOLS_DUAL_SPARSE_SEGTREE_HPP

#include <variant>
#include "tools/lazy_sparse_segtree.hpp"
#include "tools/monoid.hpp"
#include "tools/nop_mapping.hpp"
#include "tools/nop_monoid.hpp"

namespace tools {
  template <tools::monoid FM>
  using dual_sparse_segtree = tools::lazy_sparse_segtree<tools::nop_monoid, FM, tools::nop_mapping<typename FM::T, std::monostate>>;
}

#endif
