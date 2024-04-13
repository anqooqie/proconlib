#ifndef TOOLS_STIRLING_1ST_HPP
#define TOOLS_STIRLING_1ST_HPP

#include <cassert>
#include <vector>
#include <iterator>
#include "tools/fps.hpp"
#include "tools/is_prime.hpp"
#include "tools/polynomial.hpp"
#include "tools/floor_log2.hpp"
#include "tools/ssize.hpp"
#include "tools/pow2.hpp"
#include "tools/fix.hpp"
#include "tools/fact_mod_cache.hpp"
#include "tools/pow_mod_cache.hpp"

namespace tools {

  namespace stirling_1st {

    template <typename M>
    ::tools::fps<M> fixed_n(const int N, const int K) {
      assert(::tools::is_prime(M::mod()));
      assert(0 <= N && N < M::mod());

      ::std::vector<::tools::polynomial<M>> bases;
      if (N > 0) {
        bases.resize(::tools::floor_log2(N) + 1);
        bases[0] = ::tools::polynomial<M>{M(0), M(1)};
        for (int i = 1; i < ::tools::ssize(bases); ++i) {
          bases[i] = bases[i - 1] * bases[i - 1](::tools::polynomial<M>{M(-::tools::pow2(i - 1)), M(1)});
        }
      }

      const auto s = ::tools::fix([&](auto&& dfs, const int l, const int r) -> ::tools::polynomial<M> {
        if (l == r) return ::tools::polynomial<M>{M(1)};
        const auto block = ::tools::pow2(::tools::floor_log2(r - l));
        return block == r - l ? bases[::tools::floor_log2(r - l)](::tools::polynomial<M>{M(-l), M(1)}) : dfs(l, l + block) * dfs(l + block, r);
      })(0, N);

      return ::tools::fps<M>(s.pbegin(), ::std::next(s.pbegin(), K + 1));
    }

    template <typename M>
    ::tools::fps<M> fixed_k(const int N, const int K) {
      assert(::tools::is_prime(M::mod()));
      assert(0 <= K && K < M::mod());
      assert(0 <= N && N < M::mod() + K - 1);
      if (N < K) return ::tools::fps<M>(N + 1, M::raw(0));

      ::tools::fact_mod_cache<M> cache;
      ::tools::pow_mod_cache<M> pow_m1(-1);
      ::tools::fps<M> f(N - K + 1);
      for (int i = 0; i <= N - K; ++i) {
        f[i] = cache.inv(i + 1);
      }
      f.pow_inplace(K);
      f *= cache.fact_inv(K);
      for (int n = K; n <= N; ++n) {
        f[n - K] *= cache.fact(n) * pow_m1[n + K];
      }
      f.insert(f.begin(), K, M::raw(0));
      return f;
    }

    template <typename M>
    ::tools::fps<M> diagonal(const int N) {
      assert(N >= 0);
      return ::tools::fps<M>(N + 1, M(1));
    }
  }
}

#endif
