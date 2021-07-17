#ifndef TOOLS_FILL_HPP
#define TOOLS_FILL_HPP

#include <vector>
#include <type_traits>
#include <algorithm>
#include <iterator>
#include "tools/is_range.hpp"

// Source: https://koyumeishi.hatenablog.com/entry/2016/02/01/152426
// License: unknown
// Author: koyumeishi

namespace tools {
  template <class T, class Allocator, typename V>
  auto fill(::std::vector<T, Allocator>& vector, const V& value) -> ::std::enable_if_t<!::tools::is_range<T>::value, void> {
    ::std::fill(::std::begin(vector), ::std::end(vector), value);
  }
  template <class T, class Allocator, typename V>
  auto fill(::std::vector<T, Allocator>& vector, const V& value) -> ::std::enable_if_t<::tools::is_range<T>::value, void> {
    for (auto& child : vector) {
      ::tools::fill(child, value);
    }
  }
}

#endif
