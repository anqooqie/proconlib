#ifndef TOOLS_EXTEND_HASH_HPP
#define TOOLS_EXTEND_HASH_HPP

// WARNING:
// This file adds partial specializations for classes in std namespace, for convenience.
// Strictly speaking, it is not allowed in C++.
// It makes the program ill-formed to include this file, and may cause undefined behavior.

#include <cstddef>
#include <functional>
#include <tuple>
#include <utility>
#include "tools/tuple_hash.hpp"

namespace std {
  template <class T1, class T2>
  struct hash<std::pair<T1, T2>> {
    std::size_t operator()(const std::pair<T1, T2>& key) const {
      static const tools::tuple_hash<T1, T2> hasher;
      return hasher(std::make_tuple(key.first, key.second));
    }
  };

  template <class... Args>
  struct hash<std::tuple<Args...>> {
    std::size_t operator()(const std::tuple<Args...>& key) const {
      static const tools::tuple_hash<Args...> hasher;
      return hasher(key);
    }
  };
}

#endif
