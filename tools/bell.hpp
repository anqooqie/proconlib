#ifndef TOOLS_BELL_HPP
#define TOOLS_BELL_HPP

#include <cassert>
#include <algorithm>
#include <vector>
#include "tools/fps.hpp"
#include "tools/is_prime.hpp"
#include "tools/stirling_2nd.hpp"
#include "tools/fact_mod_cache.hpp"

namespace tools {

  namespace bell {

    template <typename M>
    ::tools::fps<M> fixed_n(const int N, const int K) {
      assert(::tools::is_prime(M::mod()));
      assert(0 <= ::std::min(N, K) && ::std::min(N, K) < M::mod());
      return ::tools::stirling_2nd::fixed_n<M>(N, K).divide_inplace(1, M(-1));
    }

    template <typename M>
    ::tools::fps<M> diagonal(const int N) {
      assert(::tools::is_prime(M::mod()));
      assert(0 <= N && N < M::mod());
      ::tools::fact_mod_cache<M> cache;
      ::tools::fps<M> f(N + 1);
      for (int i = 1; i <= N; ++i) f[i] = cache.fact_inv(i);
      f.exp_inplace();
      for (int n = 0; n <= N; ++n) f[n] *= cache.fact(n);
      return f;
    }

    template <typename M>
    ::std::vector<::std::vector<M>> all(const int N, const int K) {
      assert(N >= 0);
      assert(K >= 0);
      auto res = ::tools::stirling_2nd::all<M>(N, K);
      for (int n = 0; n <= N; ++n) {
        for (int k = 1; k <= K; ++k) {
          res[n][k] += res[n][k - 1];
        }
      }
      return res;
    }
  }
}

#endif
