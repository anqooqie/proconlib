#ifndef TOOLS_MULTIVARIATE_CONVOLUTION_HPP
#define TOOLS_MULTIVARIATE_CONVOLUTION_HPP

#include <cassert>
#include <concepts>
#include <ranges>
#include <vector>
#include "atcoder/convolution.hpp"
#include "atcoder/modint.hpp"
#include "tools/ceil_log2.hpp"
#include "tools/pow2.hpp"

namespace tools {
  template <std::ranges::input_range R1, std::ranges::input_range R2, std::ranges::input_range R3>
  requires (
    std::same_as<std::ranges::range_value_t<R1>, std::ranges::range_value_t<R2>> &&
    atcoder::internal::is_static_modint<std::ranges::range_value_t<R1>>::value &&
    std::integral<std::ranges::range_value_t<R3>>
  )
  std::vector<std::ranges::range_value_t<R1>> multivariate_convolution(R1&& f, R2&& g, R3&& N) {
    using M = std::ranges::range_value_t<R1>;

    std::vector<int> P{1};
    for (auto&& N_i : N) {
      assert(N_i >= 0);
      if (N_i == 0) {
        return std::vector<M>{};
      }
      if (N_i > 1) {
        P.push_back(P.back() * N_i);
      }
    }

    const int K = P.size() - 1;

    std::vector<int> chi(P[K], 0);
    for (int i = 0; i < P[K]; ++i) {
      for (int k = 1; k < K; ++k) {
        chi[i] += i / P[k];
      }
      chi[i] %= K + 1;
    }

    const auto z = tools::pow2(tools::ceil_log2(2 * P[K] - 1));
    const auto iz = M(z).inv();

    auto F = std::vector(K + 1, std::vector(z, M::raw(0)));
    {
      int i = 0;
      for (auto&& f_i : f) {
        assert(i < P[K]);
        F[chi[i]][i] = f_i;
        ++i;
      }
      assert(i == P[K]);
    }
    auto G = std::vector(K + 1, std::vector(z, M::raw(0)));
    {
      int i = 0;
      for (auto&& g_i : g) {
        assert(i < P[K]);
        G[chi[i]][i] = g_i;
        ++i;
      }
      assert(i == P[K]);
    }

    for (auto&& F_k : F) atcoder::internal::butterfly(F_k);
    for (auto&& G_k : G) atcoder::internal::butterfly(G_k);

    auto H = std::vector(K + 1, std::vector(z, M::raw(0)));
    for (int k1 = 0; k1 <= K; ++k1) {
      for (int k2 = 0; k2 <= K; ++k2) {
        const auto k3 = (k1 + k2) % (K + 1);
        for (int i = 0; i < z; ++i) {
          H[k3][i] += F[k1][i] * G[k2][i];
        }
      }
    }

    for (auto&& H_k : H) atcoder::internal::butterfly_inv(H_k);
    std::vector<M> h(P[K]);
    for (int i = 0; i < P[K]; ++i) {
      h[i] = H[chi[i]][i] * iz;
    }

    return h;
  }
}

#endif
