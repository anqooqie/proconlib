#ifndef INSERT_OR_ASSIGN_HPP
#define INSERT_OR_ASSIGN_HPP

#include <utility>

namespace tools {
  template<typename Map, typename T>
  std::pair<typename Map::iterator, bool> insert_or_assign(Map& map, const typename Map::key_type& key, const T& value) {
    std::pair<typename Map::iterator, bool> pair = map.insert(std::make_pair(key, value));
    if (!pair.second) pair.first->second = value;
    return pair;
  }
}

#endif
