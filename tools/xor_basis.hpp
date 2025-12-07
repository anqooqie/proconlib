#ifndef TOOLS_XOR_BASIS_HPP
#define TOOLS_XOR_BASIS_HPP

#include <type_traits>
#include <vector>
#include "tools/chmin.hpp"

// Source: https://twitter.com/noshi91/status/1200702280128856064
// License: unknown
// Author: noshi91

namespace tools {
  template <typename InputIterator, typename OutputIterator>
  void xor_basis(const InputIterator& begin, const InputIterator& end, OutputIterator result) {
    using T = std::decay_t<decltype(*begin)>;

    std::vector<T> basis;
    for (auto it = begin; it != end; ++it) {
      T e = *it;
      for (const T& b : basis) {
        tools::chmin(e, e ^ b);
      }
      if (e != 0) {
        basis.push_back(e);
      }
    }

    for (const T& b : basis) {
      *result = b;
      ++result;
    }
  }
}

#endif
