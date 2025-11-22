#ifndef TOOLS_BINOMIAL_PRODUCT_HPP
#define TOOLS_BINOMIAL_PRODUCT_HPP

#include <algorithm>
#include <cassert>
#include <concepts>
#include <ranges>
#include <set>
#include <tuple>
#include <utility>
#include <vector>
#include "tools/ceil.hpp"
#include "tools/fact_mod_cache.hpp"
#include "tools/fps.hpp"
#include "tools/modint.hpp"
#include "tools/pow_mod_cache.hpp"

namespace tools {
  template <::std::ranges::input_range R>
  requires ::tools::modint<::std::tuple_element_t<0, ::std::ranges::range_value_t<R>>>
        && ::std::same_as<::std::tuple_element_t<1, ::std::ranges::range_value_t<R>>, ::std::tuple_element_t<0, ::std::ranges::range_value_t<R>>>
        && ::std::integral<::std::tuple_element_t<2, ::std::ranges::range_value_t<R>>>
        && ::std::integral<::std::tuple_element_t<3, ::std::ranges::range_value_t<R>>>
  auto binomial_product(R&& f, const int n) {
    using M = ::std::tuple_element_t<0, ::std::ranges::range_value_t<R>>;
    using F = ::tools::fps<M>;

    assert(n >= 0);
    assert(::std::ranges::all_of(::std::views::iota(2, ::std::max(2, n)), [](const auto i) { return M::mod() % i != 0; }));

    M multiplier(1);
    int offset = 0;
    ::std::vector<::std::tuple<M, int, int>> factors;
    for (const auto& [a, b, c, d] : f) {
      assert(c >= 0);
      assert(d >= 0);

      if (d == 0) {
        continue;
      }
      if (c == 0) {
        multiplier *= (a + b).pow(d);
        continue;
      }
      if (a.val() == 0) {
        if (d >= ::tools::ceil(n - offset, c)) {
          return F(n);
        }
        multiplier *= b.pow(d);
        offset += c * d;
        continue;
      }

      multiplier *= a.pow(d);      
      factors.emplace_back(b / a, c, d);
    }

    assert((factors | ::std::views::transform([](const auto& factor) { return ::std::get<1>(factor); }) | ::std::ranges::to<::std::set>()).size() == factors.size());

    ::tools::fact_mod_cache<M> cache;
    F res(n - offset);
    for (const auto& [b, c, d] : factors) {
      ::tools::pow_mod_cache<M> pow_b(b);
      for (int i = 1; c < ::tools::ceil(n - offset, i); ++i) {
        res[c * i] += M(i % 2 == 0 ? -d : d) * pow_b[i] * cache.inv(i);
      }
    }
    res.exp_inplace();
    res *= multiplier;
    res <<= offset;

    return res;
  }
}

#endif
