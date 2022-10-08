#ifndef TOOLS_GARNER_HPP
#define TOOLS_GARNER_HPP

#include <utility>
#include <vector>
#include <cstddef>
#include "tools/mod.hpp"
#include "tools/inv_mod.hpp"

// Source: https://qiita.com/drken/items/ae02240cd1f8edfc86fd
// License: unknown
// Author: drken

namespace tools {

  template <typename Iterator, typename ModType>
  ::std::pair<long long, long long> garner(const Iterator& begin, const Iterator& end, const ModType& mod) {
    ::std::vector<long long> b, m;
    for (auto it = begin; it != end; ++it) {
      b.push_back(::tools::mod(it->first, it->second));
      m.push_back(it->second);
    }

    auto lcm = 1LL;
    for (::std::size_t i = 0; i < b.size(); ++i) {
      (lcm *= m[i]) %= mod;
    }

    m.push_back(mod);
    ::std::vector<long long> coeffs(m.size(), 1);
    ::std::vector<long long> constants(m.size(), 0);
    for (::std::size_t k = 0; k < b.size(); ++k) {
      long long t = ::tools::mod((b[k] - constants[k]) * ::tools::inv_mod(coeffs[k], m[k]), m[k]);
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
