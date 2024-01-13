#ifndef TOOLS_STIRLING_1ST_HPP
#define TOOLS_STIRLING_1ST_HPP

#include <cassert>
#include <vector>
#include <iterator>
#include "tools/is_prime.hpp"
#include "tools/polynomial.hpp"
#include "tools/floor_log2.hpp"
#include "tools/ssize.hpp"
#include "tools/pow2.hpp"
#include "tools/fix.hpp"
#include "tools/fps.hpp"

namespace tools {
  template <typename M>
  ::tools::fps<M> stirling_1st(const int n) {
    assert(::tools::is_prime(M::mod()));
    assert(0 <= n && n < M::mod());

    ::std::vector<::tools::polynomial<M>> bases;
    if (n > 0) {
      bases.resize(::tools::floor_log2(n) + 1);
      bases[0] = ::tools::polynomial<M>{M(0), M(1)};
      for (int i = 1; i < ::tools::ssize(bases); ++i) {
        bases[i] = bases[i - 1] * bases[i - 1](::tools::polynomial<M>{M(-::tools::pow2(i - 1)), M(1)});
      }
    }

    const auto s = ::tools::fix([&](auto&& dfs, const int l, const int r) -> ::tools::polynomial<M> {
      if (l == r) return ::tools::polynomial<M>{M(1)};
      const auto block = ::tools::pow2(::tools::floor_log2(r - l));
      return block == r - l ? bases[::tools::floor_log2(r - l)](::tools::polynomial<M>{M(-l), M(1)}) : dfs(l, l + block) * dfs(l + block, r);
    })(0, n);

    return ::tools::fps<M>(s.pbegin(), ::std::next(s.pbegin(), n + 1));
  }
}

#endif
