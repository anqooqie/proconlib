#ifndef TOOLS_TUPLE_HASH_HPP
#define TOOLS_TUPLE_HASH_HPP

#include <cstddef>
#include <tuple>
#include <limits>
#include <functional>
#include <tuple>
#include "tools/now.hpp"
#include "tools/hash_combine.hpp"

namespace tools {
  template <typename... Ts>
  struct tuple_hash {
    template <::std::size_t I = sizeof...(Ts) - 1>
    ::std::size_t operator()(const ::std::tuple<Ts...>& key) const {
      if constexpr (I == ::std::numeric_limits<::std::size_t>::max()) {
        static const ::std::size_t seed = ::tools::now();
        return seed;
      } else {
        ::std::size_t seed = this->operator()<I - 1>(key);
        ::tools::hash_combine(seed, ::std::get<I>(key));
        return seed;
      }
    }
  };
}

#endif
