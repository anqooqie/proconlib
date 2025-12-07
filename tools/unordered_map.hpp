#ifndef TOOLS_UNORDERED_MAP_HPP
#define TOOLS_UNORDERED_MAP_HPP

#include <functional>
#include <utility>
#include <type_traits>
#include <ext/pb_ds/assoc_container.hpp>

namespace tools {

  template <typename Key, typename T, typename Hash = std::hash<Key>>
  class unordered_map : public ::__gnu_pbds::gp_hash_table<Key, T, Hash> {
  public:
    using ::__gnu_pbds::gp_hash_table<Key, T, Hash>::gp_hash_table;

    template <typename... Args>
    auto emplace(Args&&... args) {
      return this->insert(std::make_pair(std::forward<Args>(args)...));
    }

    template <typename M>
    auto insert_or_assign(const Key& k, M&& obj) {
      if (auto it = this->find(k); it != this->end()) {
        it->second = obj;
        return std::make_pair(it, false);
      } else {
        return this->emplace(k, obj);
      }
    }
  };
}

#endif
