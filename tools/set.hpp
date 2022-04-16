#ifndef TOOLS_SET_HPP
#define TOOLS_SET_HPP

#include <functional>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/tag_and_trait.hpp>

namespace tools {
  template <typename Key, typename Compare = ::std::less<Key>>
  using set = ::__gnu_pbds::tree<Key, ::__gnu_pbds::null_type, Compare, ::__gnu_pbds::rb_tree_tag, ::__gnu_pbds::tree_order_statistics_node_update>;
}

#endif
