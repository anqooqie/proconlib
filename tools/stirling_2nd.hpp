#ifndef TOOLS_STIRLING_2ND_HPP
#define TOOLS_STIRLING_2ND_HPP

#include <algorithm>
#include <cassert>
#include <ranges>
#include <vector>
#include "tools/fact_mod_cache.hpp"
#include "tools/fps.hpp"
#include "tools/is_prime.hpp"
#include "tools/pow_mod_cache.hpp"

namespace tools {

  namespace stirling_2nd {

    template <typename M>
    auto fixed_n(const int N, const int K) {
      assert(tools::is_prime(M::mod()));
      assert(0 <= std::min(N, K) && std::min(N, K) < M::mod());

      tools::fact_mod_cache<M> cache;
      tools::pow_mod_cache<M> pow_m1(-1);
      tools::fps<M> a, b;
      for (int i = 0; i <= std::min(N, K); ++i) {
        a.push_back(M(i).pow(N) * cache.fact_inv(i));
        b.push_back(pow_m1[i] * cache.fact_inv(i));
      }
      a.multiply_inplace(b);

      return std::views::iota(0, K + 1) | std::views::transform([N, a](const int k) -> const M& {
        static const auto zero = M::raw(0);
        return k <= N ? a[k] : zero;
      });
    }

    template <typename M>
    auto fixed_k(const int N, const int K) {
      assert(tools::is_prime(M::mod()));
      assert(N >= 0);
      assert(0 <= K && K < M::mod());
      assert(N - K + 1 < M::mod());

      tools::fps<M> f(std::max(0, N - K + 1));
      if (!f.empty()) {
        tools::fact_mod_cache<M> cache;
        for (int i = 0; i <= N - K; ++i) {
          f[i] = cache.fact_inv(i + 1);
        }
        f.pow_inplace(K);
        f *= cache.fact_inv(K);
        for (int n = K; n <= N; ++n) {
          f[n - K] *= cache.fact(n);
        }
      }

      return std::views::iota(0, N + 1) | std::views::transform([K, f](const int n) -> const M& {
        static const auto zero = M::raw(0);
        return n < K ? zero : f[n - K];
      });
    }

    template <typename M>
    auto diagonal(const int N) {
      assert(N >= 0);

      return std::views::iota(0, N + 1) | std::views::transform([](const int n) -> const M& {
        static const M one(1);
        return one;
      });
    }

    template <typename M>
    std::vector<std::vector<M>> all(const int N, const int K) {
      assert(N >= 0);
      assert(K >= 0);
      std::vector<std::vector<M>> S(N + 1);
      S[0].emplace_back(1);
      S[0].insert(S[0].end(), K, M::raw(0));
      for (int n = 1; n <= N; ++n) {
        S[n].resize(K + 1, M::raw(0));
        for (int k = 0; k <= std::min(n, K); ++k) {
          if (k > 0) S[n][k] += S[n - 1][k - 1];
          S[n][k] += M(k) * S[n - 1][k];
        }
      }
      return S;
    }
  }
}

#endif
