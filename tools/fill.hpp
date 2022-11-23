#ifndef TOOLS_FILL_HPP
#define TOOLS_FILL_HPP

#include <type_traits>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cstddef>
#include <array>
#include "tools/is_range.hpp"

namespace tools {
  template <class T, class Allocator, typename V>
  ::std::enable_if_t<!::tools::is_range_v<T>, void> fill(::std::vector<T, Allocator>& vector, const V& value) {
    ::std::fill(::std::begin(vector), ::std::end(vector), value);
  }
  template <class T, ::std::size_t N, typename V>
  ::std::enable_if_t<!::tools::is_range_v<T>, void> fill(::std::array<T, N>& array, const V& value) {
    ::std::fill(::std::begin(array), ::std::end(array), value);
  }

  template <class T, class Allocator, typename V>
  ::std::enable_if_t<::tools::is_range_v<T>, void> fill(::std::vector<T, Allocator>& vector, const V& value);
  template <class T, ::std::size_t N, typename V>
  ::std::enable_if_t<::tools::is_range_v<T>, void> fill(::std::array<T, N>& array, const V& value);

  template <class T, class Allocator, typename V>
  ::std::enable_if_t<::tools::is_range_v<T>, void> fill(::std::vector<T, Allocator>& vector, const V& value) {
    for (auto& child : vector) {
      ::tools::fill(child, value);
    }
  }
  template <class T, ::std::size_t N, typename V>
  ::std::enable_if_t<::tools::is_range_v<T>, void> fill(::std::array<T, N>& array, const V& value) {
    for (auto& child : array) {
      ::tools::fill(child, value);
    }
  }
}

#endif
