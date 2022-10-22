#ifndef TOOLS_STIRLING_2ND_HPP
#define TOOLS_STIRLING_2ND_HPP

#include <cstddef>
#include <cassert>
#include "tools/fps.hpp"
#include "tools/is_prime.hpp"
#include "tools/fact_mod_cache.hpp"

namespace tools {
  template <typename M>
  ::tools::fps<M> stirling_2nd(const int n) {
    assert(::tools::is_prime(M::mod()));
    assert(0 <= n && n < M::mod());
    ::tools::fact_mod_cache<M> cache;
    ::tools::fps<M> a, b;
    for (int i = 0; i <= n; ++i) {
      a.push_back(M(i).pow(n) * cache.fact_inv(i));
      b.push_back(M(i % 2 == 0 ? 1 : -1) * cache.fact_inv(i));
    }
    return a.multiply_inplace(b);
  }
}

#endif
