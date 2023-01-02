#ifndef TOOLS_SPARSE_FPS_POW_HPP
#define TOOLS_SPARSE_FPS_POW_HPP

#include <cstddef>
#include <type_traits>
#include <utility>
#include <cassert>
#include <algorithm>
#include <iterator>
#include "tools/fps.hpp"
#include "tools/is_prime.hpp"
#include "tools/less_by_first.hpp"
#include "tools/ceil.hpp"
#include "tools/fact_mod_cache.hpp"

namespace tools {
  template <typename InputIterator>
  ::tools::fps<::std::decay_t<decltype(::std::declval<InputIterator>()->second)>> sparse_fps_pow(InputIterator begin, InputIterator end, const unsigned long long k, ::std::size_t n) {
    using M = ::std::decay_t<decltype(::std::declval<InputIterator>()->second)>;
    using F = ::tools::fps<M>;

    assert(::tools::is_prime(M::mod()));
    assert(n <= M::mod());
    assert(begin <= end);
    assert(::std::all_of(begin, end, [](const auto& pair) { return pair.first >= 0; }));
    assert(::std::is_sorted(begin, end, ::tools::less_by_first()));

    if (n == 0) {
      return F();
    }
    if (k == 0) {
      F res(n);
      res[0] = M(1);
      return res;
    }

    const auto offset = ::std::find_if(begin, end, [](const auto& pair) { return pair.second != M::raw(0); });
    if (offset == end) {
      return F(n);
    }
    if (::tools::ceil(n, k) <= static_cast<::std::size_t>(offset->first)) {
      return F(n);
    }

    F res(n - offset->first * k);
    const auto deg = [&](const auto& it) -> ::std::size_t { return it->first - offset->first; };

    ::tools::fact_mod_cache<M> cache;
    const auto ic = offset->second.inv();

    res[0] = offset->second.pow(k);
    for (::std::size_t i = 1; i < n - offset->first * k; ++i) {
      for (auto it = ::std::next(offset); it != end; ++it) {
        if (i < deg(it)) break;
        res[i] += (M(k) * M(deg(it)) - M(i - deg(it))) * it->second * res[i - deg(it)];
      }
      res[i] *= cache.inv(i) * ic;
    }

    res.insert(res.begin(), offset->first * k, M::raw(0));
    return res;
  }
}

#endif
