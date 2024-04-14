#ifndef TOOLS_TWELVEFOLD_WAY_HPP
#define TOOLS_TWELVEFOLD_WAY_HPP

#include <cassert>
#include <algorithm>
#include "tools/is_prime.hpp"
#include "tools/large_fact_mod_cache.hpp"
#include "tools/extended_lucas.hpp"
#include "tools/pow_mod_cache.hpp"
#include "tools/bell.hpp"
#include "tools/stirling_2nd.hpp"
#include "tools/partition_function.hpp"

namespace tools {
  template <bool labels_ball, bool labels_box>
  struct twelvefold_way {};

  template <>
  struct twelvefold_way<true, true> {
    template <typename M>
    static M at_most_1(const long long N, const long long K) {
      assert(N >= 0);
      assert(K >= 0);

      if (::tools::is_prime(M::mod())) {
        // O(sqrt(P log P) + sqrt(P / log P) log K)
        ::tools::large_fact_mod_cache<M> cache;
        return cache.permutation(K, N);
      } else {
        // O(M + (log M / log log M) log K)
        ::tools::extended_lucas<M> cache;
        return cache.permutation(K, N);
      }
    }

    template <typename M>
    static M unrestricted(const long long N, const long long K) {
      assert(N >= 0);
      assert(K >= 0);

      // O(log N)
      return M(K).pow(N);
    }

    template <typename M>
    static M at_least_1(const long long N, const long long K) {
      assert(N >= 0);
      assert(K >= 0);

      ::tools::pow_mod_cache<M> pow_m1(-1);
      if (::tools::is_prime(M::mod())) {
        // O(sqrt(P log P) + K (sqrt(P / log P) log K + log N))
        ::tools::large_fact_mod_cache<M> cache;
        auto res = M::raw(0);
        for (int i = 0; i <= K; ++i) {
          res += pow_m1[K - i] * cache.combination(K, i) * M(i).pow(N);
        }
        return res;
      } else {
        // O(M + K ((log M / log log M) log K + (log M / log log M)^2 + log N))
        ::tools::extended_lucas<M> cache;
        auto res = M::raw(0);
        for (int i = 0; i <= K; ++i) {
          res += pow_m1[K - i] * cache.combination(K, i) * M(i).pow(N);
        }
        return res;
      }
    }
  };

  template <>
  struct twelvefold_way<false, true> {
    template <typename M>
    static M at_most_1(const long long N, const long long K) {
      assert(N >= 0);
      assert(K >= 0);

      if (::tools::is_prime(M::mod())) {
        // O(sqrt(P log P) + sqrt(P / log P) log K)
        ::tools::large_fact_mod_cache<M> cache;
        return cache.combination(K, N);
      } else {
        // O(M + (log M / log log M) log K)
        ::tools::extended_lucas<M> cache;
        return cache.combination(K, N);
      }
    }

    template <typename M>
    static M unrestricted(const long long N, const long long K) {
      assert(N >= 0);
      assert(K >= 0);

      if (::tools::is_prime(M::mod())) {
        // O(sqrt(P log P) + sqrt(P / log P) log (N + K))
        ::tools::large_fact_mod_cache<M> cache;
        return cache.combination_with_repetition(K, N);
      } else {
        // O(M + (log M / log log M) log (N + K))
        ::tools::extended_lucas<M> cache;
        return cache.combination_with_repetition(K, N);
      }
    }

    template <typename M>
    static M at_least_1(const long long N, const long long K) {
      assert(N >= 0);
      assert(K >= 0);

      if (::tools::is_prime(M::mod())) {
        // O(sqrt(P log P) + sqrt(P / log P) log N)
        ::tools::large_fact_mod_cache<M> cache;
        return cache.binomial(N - 1, K - 1);
      } else {
        // O(M + (log M / log log M) log N)
        ::tools::extended_lucas<M> cache;
        return cache.binomial(N - 1, K - 1);
      }
    }
  };

  template <>
  struct twelvefold_way<true, false> {
    template <typename M>
    static M at_most_1(const long long N, const long long K) {
      assert(N >= 0);
      assert(K >= 0);

      // O(1)
      return M(N <= K);
    }

    template <typename M>
    static M unrestricted(const long long N, const long long K) {
      assert(N >= 0);
      assert(K >= 0);

      if (::tools::is_prime(M::mod()) && ::std::min(N, K) < M::mod()) {
        // O(min(N, K) log(min(N, K)) + K)
        return ::tools::bell::fixed_n<M>(N, K)[K];
      } else {
        // O(NK)
        return ::tools::bell::all<M>(N, K)[N][K];
      }
    }

    template <typename M>
    static M at_least_1(const long long N, const long long K) {
      assert(N >= 0);
      assert(K >= 0);

      if (::tools::is_prime(M::mod()) && ::std::min(N, K) < M::mod()) {
        // O(min(N, K) log(min(N, K)) + K)
        return ::tools::stirling_2nd::fixed_n<M>(N, K)[K];
      } else {
        // O(NK)
        return ::tools::stirling_2nd::all<M>(N, K)[N][K];
      }
    }
  };

  template <>
  struct twelvefold_way<false, false> {
    template <typename M>
    static M at_most_1(const long long N, const long long K) {
      assert(N >= 0);
      assert(K >= 0);

      // O(1)
      return M(N <= K);
    }

    template <typename M>
    static M unrestricted(const long long N, const long long K) {
      assert(N >= 0);
      assert(K >= 0);

      if (N == K) {
        // O(N log N)
        return ::tools::partition_function::diagonal<M>(N)[N];
      } else {
        // O(NK)
        return ::tools::partition_function::all<M>(N, K)[N][K];
      }
    }

    template <typename M>
    static M at_least_1(const long long N, const long long K) {
      assert(N >= 0);
      assert(K >= 0);

      if (N < K) return M::raw(0);

      if (N == 2 * K) {
        // O(K log K)
        return ::tools::partition_function::diagonal<M>(K)[K];
      } else {
        // O(K(N - K))
        return ::tools::partition_function::all<M>(N - K, K)[N - K][K];
      }
    }
  };
}

#endif
