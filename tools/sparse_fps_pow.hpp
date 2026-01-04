#ifndef TOOLS_SPARSE_FPS_POW_HPP
#define TOOLS_SPARSE_FPS_POW_HPP

#include <algorithm>
#include <cassert>
#include <concepts>
#include <initializer_list>
#include <iterator>
#include <ranges>
#include <utility>
#include "tools/ceil.hpp"
#include "tools/cmp_less.hpp"
#include "tools/cmp_less_equal.hpp"
#include "tools/fact_mod_cache.hpp"
#include "tools/fps.hpp"
#include "tools/integral.hpp"
#include "tools/is_prime.hpp"
#include "tools/less_by_first.hpp"
#include "tools/modint.hpp"

namespace tools {
  template <std::ranges::input_range R>
  requires tools::integral<std::tuple_element_t<0, std::ranges::range_value_t<R>>>
        && tools::modint<std::tuple_element_t<1, std::ranges::range_value_t<R>>>
  tools::fps<std::tuple_element_t<1, std::ranges::range_value_t<R>>> sparse_fps_pow(R&& f, const unsigned long long k, const int n) {
    if constexpr (std::ranges::forward_range<R>) {
      using M = std::tuple_element_t<1, std::ranges::range_value_t<R>>;
      using F = tools::fps<M>;

      assert(tools::is_prime(M::mod()));
      assert(0 <= n && n <= M::mod());
      assert(std::ranges::all_of(f, [](const auto& pair) { return pair.first >= 0; }));
      assert(std::ranges::is_sorted(f, tools::less_by_first{}));

      if (n == 0) {
        return F();
      }
      if (k == 0) {
        F res(n);
        res[0] = M(1);
        return res;
      }

      const auto offset = std::ranges::find_if(f, [](const auto& pair) { return pair.second != M::raw(0); });
      if (offset == std::ranges::end(f)) {
        return F(n);
      }
      if (tools::cmp_less_equal(tools::ceil(n, k), offset->first)) {
        return F(n);
      }

      F res(n - offset->first * k);
      const auto deg = [&](const auto it) { return it->first - offset->first; };

      tools::fact_mod_cache<M> cache;
      const auto ic = offset->second.inv();

      res[0] = offset->second.pow(k);
      for (int i = 1; tools::cmp_less(i, n - offset->first * k); ++i) {
        for (auto it = std::next(offset); it != std::ranges::end(f); ++it) {
          if (tools::cmp_less(i, deg(it))) break;
          res[i] += (M(k) * M(deg(it)) - M(i - deg(it))) * it->second * res[i - deg(it)];
        }
        res[i] *= cache.inv(i) * ic;
      }

      res.insert(res.begin(), offset->first * k, M::raw(0));
      return res;
    } else {
      return tools::sparse_fps_pow(std::forward<R>(f), k, n);
    }
  }

  template <tools::integral I, tools::modint M>
  tools::fps<M> sparse_fps_pow(std::initializer_list<std::pair<I, M>> f, const unsigned long long k, const int n) {
    return tools::sparse_fps_pow(std::views::all(f), k, n);
  }

  template <std::ranges::input_range R1, std::ranges::input_range R2>
  requires tools::integral<std::tuple_element_t<0, std::ranges::range_value_t<R1>>>
        && tools::modint<std::tuple_element_t<1, std::ranges::range_value_t<R1>>>
        && tools::integral<std::tuple_element_t<0, std::ranges::range_value_t<R2>>>
        && std::same_as<std::tuple_element_t<1, std::ranges::range_value_t<R1>>, std::tuple_element_t<1, std::ranges::range_value_t<R2>>>
  tools::fps<std::tuple_element_t<1, std::ranges::range_value_t<R1>>> sparse_fps_pow(R1&& f, R2&& g, const unsigned long long k, const int n) {
    if constexpr (std::ranges::forward_range<R1> && std::ranges::forward_range<R2>) {
      using M = std::tuple_element_t<1, std::ranges::range_value_t<R1>>;
      using F = tools::fps<M>;

      assert(tools::is_prime(M::mod()));
      assert(0 <= n && n <= M::mod());
      assert(std::ranges::all_of(f, [](const auto& pair) { return pair.first >= 0; }));
      assert(std::ranges::is_sorted(f, tools::less_by_first{}));
      assert(!std::ranges::empty(g));
      assert(std::ranges::all_of(g, [](const auto& pair) { return pair.first >= 0; }));
      assert(std::ranges::is_sorted(g, tools::less_by_first{}));
      assert(std::ranges::begin(g)->first == 0);
      assert(std::ranges::begin(g)->second != M::raw(0));

      if (n == 0) {
        return F();
      }
      if (k == 0) {
        F res(n);
        res[0] = M(1);
        return res;
      }

      const auto f_offset = std::ranges::find_if(f, [](const auto& pair) { return pair.second != M::raw(0); });
      if (f_offset == std::ranges::end(f)) {
        return F(n);
      }
      if (tools::cmp_less_equal(tools::ceil(n, k), f_offset->first)) {
        return F(n);
      }

      F res(n - f_offset->first * k);
      const auto f_deg = [&](const auto it) { return it->first - f_offset->first; };

      tools::fact_mod_cache<M> cache;
      const auto ic = (f_offset->second * std::ranges::begin(g)->second).inv();

      res[0] = (f_offset->second / std::ranges::begin(g)->second).pow(k);
      for (int i = 1; tools::cmp_less(i, n - f_offset->first * k); ++i) {
        for (auto f_it = f_offset; f_it != std::ranges::end(f); ++f_it) {
          if (tools::cmp_less(i, f_deg(f_it))) break;
          for (auto g_it = std::next(std::ranges::begin(g), f_it == f_offset); g_it != std::ranges::end(g); ++g_it) {
            if (tools::cmp_less(i, f_deg(f_it) + g_it->first)) break;
            res[i] += (M(k) * (M(f_deg(f_it)) - M(g_it->first)) - M(i - f_deg(f_it) - g_it->first)) * f_it->second * g_it->second * res[i - f_deg(f_it) - g_it->first];
          }
        }
        res[i] *= cache.inv(i) * ic;
      }

      res.insert(res.begin(), f_offset->first * k, M::raw(0));
      return res;
    } else {
      return tools::sparse_fps_pow(std::forward<R1>(f), std::forward<R2>(g), k, n);
    }
  }

  template <tools::integral I1, tools::integral I2, tools::modint M>
  tools::fps<M> sparse_fps_pow(std::initializer_list<std::pair<I1, M>> f, std::initializer_list<std::pair<I2, M>> g, const unsigned long long k, const int n) {
    return tools::sparse_fps_pow(std::views::all(f), std::views::all(g), k, n);
  }
}

#endif
