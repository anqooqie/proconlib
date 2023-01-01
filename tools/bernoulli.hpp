#ifndef TOOLS_BERNOULLI_HPP
#define TOOLS_BERNOULLI_HPP

#include <cassert>
#include "tools/fps.hpp"
#include "tools/is_prime.hpp"
#include "tools/fact_mod_cache.hpp"

namespace tools {
  template <typename M>
  ::tools::fps<M> bernoulli(const int n) {
    assert(::tools::is_prime(M::mod()));
    assert(0 <= n && n < M::mod());
    ::tools::fact_mod_cache<M> cache;

    tools::fps<M> f(n + 1);
    for (int i = 0; i <= n; ++i) {
      f[i] = cache.fact_inv(i + 1);
    }

    f = f.inv();

    for (int i = 0; i <= n; ++i) {
      f[i] *= cache.fact(i);
    }

    return f;
  }
}

#endif
