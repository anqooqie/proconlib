#ifndef TOOLS_UNORDERED_SET_HPP
#define TOOLS_UNORDERED_SET_HPP

#include <functional>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tag_and_trait.hpp>

namespace tools {
  template <typename Key, typename Hash = ::std::hash<Key>>
  using unordered_set = ::__gnu_pbds::gp_hash_table<Key, ::__gnu_pbds::null_type, Hash>;
}

#endif
