#ifndef TOOLS_GARNER_HPP
#define TOOLS_GARNER_HPP

#include <utility>
#include <cstdint>
#include <vector>
#include <cstddef>
#include "tools/mod.hpp"
#include "tools/inv_mod.hpp"

// Source: https://qiita.com/drken/items/ae02240cd1f8edfc86fd
// License: unknown
// Author: drken

namespace tools {

  template <typename Iterator, typename ModType>
  ::std::pair<::std::int_fast64_t, ::std::int_fast64_t> garner(const Iterator& begin, const Iterator& end, const ModType& mod) {
    ::std::vector<::std::int_fast64_t> b, m;
    for (auto it = begin; it != end; ++it) {
      b.push_back(::tools::mod(it->first, it->second));
      m.push_back(it->second);
    }

    ::std::int_fast64_t lcm = 1;
    for (::std::size_t i = 0; i < b.size(); ++i) {
      (lcm *= m[i]) %= mod;
    }

    m.push_back(mod);
    ::std::vector<::std::int_fast64_t> coeffs(m.size(), 1);
    ::std::vector<::std::int_fast64_t> constants(m.size(), 0);
    for (::std::size_t k = 0; k < b.size(); ++k) {
      ::std::int_fast64_t t = ::tools::mod((b[k] - constants[k]) * ::tools::inv_mod(coeffs[k], m[k]), m[k]);
      for (::std::size_t i = k + 1; i < m.size(); ++i) {
        (constants[i] += t * coeffs[i]) %= m[i];
        (coeffs[i] *= m[k]) %= m[i];
      }
    }

    return ::std::make_pair(constants.back(), lcm);
  }

  template <typename M, typename Iterator>
  ::std::pair<M, M> garner(const Iterator& begin, const Iterator& end) {
    const auto [y, z] = ::tools::garner(begin, end, M::mod());
    return ::std::make_pair(M::raw(y), M::raw(z));
  }
}

#endif
