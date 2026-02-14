#ifndef TOOLS_XOR_BASIS_HPP
#define TOOLS_XOR_BASIS_HPP

#include <cassert>
#include <ranges>
#include <vector>
#include "tools/chmin.hpp"
#include "tools/integral.hpp"

// Source: https://twitter.com/noshi91/status/1200702280128856064
// License: unknown
// Author: noshi91

namespace tools {
  template <std::ranges::input_range R>
  requires tools::integral<std::ranges::range_value_t<R>>
  std::vector<std::ranges::range_value_t<R>> xor_basis(R&& a) {
    using T = std::ranges::range_value_t<R>;

    std::vector<T> basis;
    for (T e : a) {
      assert(e >= 0);
      for (const auto& b : basis) {
        tools::chmin(e, e ^ b);
      }
      if (e != 0) {
        basis.push_back(e);
      }
    }

    return basis;
  }
}

#endif
