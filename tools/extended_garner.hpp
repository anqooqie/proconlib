#ifndef TOOLS_EXTENDED_GARNER_HPP
#define TOOLS_EXTENDED_GARNER_HPP

#include <optional>
#include <utility>
#include <cstdint>
#include <vector>
#include <cstddef>
#include "tools/mod.hpp"
#include "tools/garner.hpp"

// Source: https://qiita.com/drken/items/ae02240cd1f8edfc86fd
// License: unknown
// Author: drken

namespace tools {

  template <typename Iterator, typename ModType>
  ::std::optional<::std::pair<long long, long long>> extended_garner(const Iterator& begin, const Iterator& end, const ModType& mod) {
    ::std::vector<::std::pair<long long, long long>> v;
    for (auto it = begin; it != end; ++it) {
      v.emplace_back(::tools::mod(it->first, it->second), it->second);
    }

    for (::std::size_t i = 0; i < v.size(); ++i) {
      for (::std::size_t j = 0; j < i; ++j) {
        long long g = ::std::gcd(v[i].second, v[j].second);

        if ((v[i].first - v[j].first) % g != 0) return ::std::nullopt;

        v[i].second /= g;
        v[j].second /= g;

        long long gi = ::std::gcd(v[i].second, g);
        long long gj = g / gi;

        do {
          g = ::std::gcd(gi, gj);
          gi *= g;
          gj /= g;
        } while (g != 1);

        v[i].second *= gi;
        v[j].second *= gj;

        v[i].first %= v[i].second;
        v[j].first %= v[j].second;
      }
    }

    return ::std::optional<::std::pair<long long, long long>>(::tools::garner(v.begin(), v.end(), mod));
  }

  template <typename M, typename Iterator>
  ::std::optional<::std::pair<M, M>> extended_garner(const Iterator& begin, const Iterator& end) {
    const auto result = ::tools::extended_garner(begin, end, M::mod());
    if (!result) return ::std::nullopt;
    return ::std::make_optional<::std::pair<M, M>>(M::raw(result->first), M::raw(result->second));
  }
}

#endif
