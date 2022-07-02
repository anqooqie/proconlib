#ifndef TOOLS_RESIZE_HPP
#define TOOLS_RESIZE_HPP

#include <vector>
#include <cstddef>
#include <array>
#include <cassert>

namespace tools {
  template <class T, class Allocator, typename Head>
  void resize(::std::vector<T, Allocator>& vector, const Head& head) {
    vector.resize(head);
  }
  template <class T, ::std::size_t N, typename Head>
  void resize(::std::array<T, N>& array, const Head& head) {
    assert(array.size() == static_cast<::std::size_t>(head));
  }

  template <class T, class Allocator, typename Head, typename... Tail>
  void resize(::std::vector<T, Allocator>& vector, const Head& head, const Tail&... tail);
  template <class T, ::std::size_t N, typename Head, typename... Tail>
  void resize(::std::array<T, N>& array, const Head& head, const Tail&... tail);

  template <class T, class Allocator, typename Head, typename... Tail>
  void resize(::std::vector<T, Allocator>& vector, const Head& head, const Tail&... tail) {
    vector.resize(head);
    for (auto& child : vector) {
      ::tools::resize(child, tail...);
    }
  }
  template <class T, ::std::size_t N, typename Head, typename... Tail>
  void resize(::std::array<T, N>& array, const Head& head, const Tail&... tail) {
    assert(array.size() == static_cast<::std::size_t>(head));
    for (auto& child : array) {
      ::tools::resize(child, tail...);
    }
  }
}

#endif
