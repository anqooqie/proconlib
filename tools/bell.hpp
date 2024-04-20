#ifndef TOOLS_BELL_HPP
#define TOOLS_BELL_HPP

#include <cassert>
#include <algorithm>
#include <vector>
#include <numeric>
#include <iterator>
#include "tools/is_prime.hpp"
#include "tools/stirling_2nd.hpp"
#include "tools/virtual_vector.hpp"
#include "tools/fact_mod_cache.hpp"
#include "tools/fps.hpp"

namespace tools {

  namespace bell {

    template <typename M>
    auto fixed_n(const int N, const int K) {
      assert(::tools::is_prime(M::mod()));
      assert(0 <= ::std::min(N, K) && ::std::min(N, K) < M::mod());

      const auto S_N = ::tools::stirling_2nd::fixed_n<M>(N, K);
      ::std::vector<M> B_N;
      ::std::partial_sum(S_N.begin(), ::std::next(S_N.begin(), ::std::min(N, K) + 1), ::std::back_inserter(B_N));

      return ::tools::virtual_vector(K + 1, [N, B_N](const int k) -> const M& {
        return B_N[::std::min(N, k)];
      });
    }

    template <typename M>
    ::std::vector<M> diagonal(const int N) {
      assert(::tools::is_prime(M::mod()));
      assert(0 <= N && N < M::mod());

      ::tools::fact_mod_cache<M> cache;
      ::tools::fps<M> f(N + 1);
      for (int i = 1; i <= N; ++i) f[i] = cache.fact_inv(i);
      f.exp_inplace();
      for (int n = 0; n <= N; ++n) f[n] *= cache.fact(n);

      return ::std::vector<M>(f.begin(), f.end());
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
