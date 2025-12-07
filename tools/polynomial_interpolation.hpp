#ifndef TOOLS_POLYNOMIAL_INTERPOLATION_HPP
#define TOOLS_POLYNOMIAL_INTERPOLATION_HPP

#include <type_traits>
#include <utility>
#include <cassert>
#include <vector>
#include "tools/polynomial.hpp"
#include "tools/is_prime.hpp"
#include "tools/ceil_log2.hpp"
#include "tools/pow2.hpp"

namespace tools {
  template <typename InputIterator>
  tools::polynomial<std::decay_t<decltype(std::declval<InputIterator>()->first)>> polynomial_interpolation(const InputIterator begin, const InputIterator end) {
    using M = std::decay_t<decltype(std::declval<InputIterator>()->first)>;
    using P = tools::polynomial<M>;
    static_assert(std::is_same_v<M, std::decay_t<decltype(std::declval<InputIterator>()->second)>>);
    assert(tools::is_prime(M::mod()));

    std::vector<M> x, y;
    for (auto it = begin; it != end; ++it) {
      x.push_back(it->first);
      y.push_back(it->second);
    }

#ifndef DEBUG
    {
      std::vector<int> z;
      for (const auto& x_i : x) z.push_back(x_i.val());
      std::sort(z.begin(), z.end());
      z.erase(std::unique(z.begin(), z.end()), z.end());
      assert(z.size() == x.size());
    }
#endif

    const int n = x.size();
    assert(n > 0);

    const auto h = tools::ceil_log2(n);
    std::vector<P> prods(tools::pow2(h) * 2);
    for (int i = 0; i < n; ++i) {
      prods[tools::pow2(h) + i] = P{-x[i], M(1)};
    }
    for (int i = n; i < tools::pow2(h); ++i) {
      prods[tools::pow2(h) + i] = P{M(1)};
    }
    for (int i = tools::pow2(h) - 1; i > 0; --i) {
      prods[i] = prods[i * 2] * prods[i * 2 + 1];
    }

    const auto gd_x = prods[1].derivative().multipoint_evaluation(x.begin(), x.end());

    std::vector<P> numerators(tools::pow2(h) * 2);
    for (int i = 0; i < n; ++i) {
      numerators[tools::pow2(h) + i] = P{y[i] / gd_x[i]};
    }
    for (int i = tools::pow2(h) - 1; i > 0; --i) {
      numerators[i] = numerators[i * 2] * prods[i * 2 + 1];
      numerators[i] += numerators[i * 2 + 1] * prods[i * 2];
    }

    return numerators[1];
  }
}

#endif
