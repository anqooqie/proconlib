#ifndef TOOLS_RESIZE_HPP
#define TOOLS_RESIZE_HPP

#include <vector>

// Source: https://koyumeishi.hatenablog.com/entry/2016/02/01/152426
// License: unknown
// Author: koyumeishi

namespace tools {
  template <class T, class Allocator, typename Head>
  void resize(::std::vector<T, Allocator>& vector, const Head& head) {
    vector.resize(head);
  }
  template <class T, class Allocator, typename Head, typename... Tail>
  void resize(::std::vector<T, Allocator>& vector, const Head& head, const Tail&... tail) {
    vector.resize(head);
    for (auto& child : vector) {
      ::tools::resize(child, tail...);
    }
  }
}

#endif
