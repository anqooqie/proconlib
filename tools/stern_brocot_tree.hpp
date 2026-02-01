#ifndef TOOLS_STERN_BROCOT_TREE_HPP
#define TOOLS_STERN_BROCOT_TREE_HPP

#include <algorithm>
#include <cassert>
#include <concepts>
#include <numeric>
#include <optional>
#include <ranges>
#include <tuple>
#include <utility>
#include <vector>
#include "tools/ceil.hpp"
#include "tools/cmp_equal.hpp"
#include "tools/cmp_less_equal.hpp"
#include "tools/gcd.hpp"
#include "tools/make_wider.hpp"
#include "tools/make_unsigned.hpp"
#include "tools/non_bool_integral.hpp"

namespace tools {
  template <tools::non_bool_integral T>
  requires tools::non_bool_integral<tools::make_wider_t<tools::make_unsigned_t<T>>>
  class stern_brocot_tree {
    using W = tools::make_wider_t<tools::make_unsigned_t<T>>;

    template <bool EncodePath>
    static std::conditional_t<EncodePath, std::vector<std::pair<char, T>>, std::tuple<T, T, T, T>> encode_path_impl(const T p, const T q) {
      assert(p > 0);
      assert(q > 0);
      assert(tools::gcd(p, q) == 1);

      [[maybe_unused]] std::vector<std::pair<char, T>> path;
      char last = p < q ? 'R' : 'L'; // sentinel
      W a = 0;
      W b = 1;
      W c = 1;
      W d = 1;
      W e = 1;
      W f = 0;
      while (!(tools::cmp_equal(c, p) && tools::cmp_equal(d, q))) {
        if (last == 'R') {
          assert(a * q < p * b); // a/b < p/q
          assert(p * d < c * q); // p/q < c/d
          assert(c * f < e * d); // c/d < e/f
          const auto k = tools::ceil(c * q - p * d, p * b - a * q);
          last = 'L';
          std::tie(c, d, e, f) = std::make_tuple(k * a + c, k * b + d, (k - 1) * a + c, (k - 1) * b + d);
          if constexpr (EncodePath) {
            path.emplace_back(last, T(k));
          }
        } else {
          assert(a * d < c * b); // a/b < c/d
          assert(c * q < p * d); // c/d < p/q
          assert(p * f < e * q); // p/q < e/f
          const auto k = tools::ceil(p * d - c * q, e * q - p * f);
          last = 'R';
          std::tie(a, b, c, d) = std::make_tuple(c + (k - 1) * e, d + (k - 1) * f, c + k * e, d + k * f); 
          if constexpr (EncodePath) {
            path.emplace_back(last, T(k));
          }
        }
      }

      if constexpr (EncodePath) {
        return path;
      } else {
        return {T(a), T(b), T(e), T(f)};
      }
    }

  public:
    stern_brocot_tree() = delete;

    static std::vector<std::pair<char, T>> encode_path(const T p, const T q) {
      return tools::stern_brocot_tree<T>::encode_path_impl<true>(p, q);
    }

    template <std::ranges::input_range R>
    requires std::same_as<std::remove_cvref_t<std::tuple_element_t<0, std::ranges::range_value_t<R>>>, char>
          && tools::non_bool_integral<std::tuple_element_t<1, std::ranges::range_value_t<R>>>
    static std::pair<T, T> decode_path(R&& path) {
      W a = 0;
      W b = 1;
      W c = 1;
      W d = 1;
      W e = 1;
      W f = 0;
      for (const auto& [direction, k] : path) {
        assert(direction == 'L' || direction == 'R');
        assert(k > 0);
        if (direction == 'L') {
          std::tie(c, d, e, f) = std::make_tuple(k * a + c, k * b + d, (k - 1) * a + c, (k - 1) * b + d);
        } else {
          std::tie(a, b, c, d) = std::make_tuple(c + (k - 1) * e, d + (k - 1) * f, c + k * e, d + k * f);
        }
      }
      assert(tools::cmp_less_equal(c, std::numeric_limits<T>::max()));
      assert(tools::cmp_less_equal(d, std::numeric_limits<T>::max()));
      return {T(c), T(d)};
    }

    static std::pair<T, T> lca(const T p, const T q, const T r, const T s) {
      assert(p > 0);
      assert(q > 0);
      assert(r > 0);
      assert(s > 0);
      assert(tools::gcd(p, q) == 1);
      assert(tools::gcd(r, s) == 1);

      const auto path1 = tools::stern_brocot_tree<T>::encode_path(p, q);
      const auto path2 = tools::stern_brocot_tree<T>::encode_path(r, s);

      std::vector<std::pair<char, T>> common_path;
      for (auto it1 = path1.begin(), it2 = path2.begin(); it1 != path1.end() && it2 != path2.end(); ++it1, ++it2) {
        if (*it1 != *it2) {
          if (it1->first == it2->first) {
            common_path.emplace_back(it1->first, std::min(it1->second, it2->second));
          }
          break;
        }
        common_path.push_back(*it1);
      }

      return tools::stern_brocot_tree<T>::decode_path(common_path);
    }

    static std::optional<std::pair<T, T>> ancestor(T d, const T p, const T q) {
      assert(d >= 0);
      assert(p > 0);
      assert(q > 0);
      assert(tools::gcd(p, q) == 1);

      std::vector<std::pair<char, T>> ancestor_path;
      for (const auto& [direction, k] : tools::stern_brocot_tree<T>::encode_path(p, q)) {
        if (d == 0) break;
        ancestor_path.emplace_back(direction, std::min(k, d));
        d -= std::min(k, d);
      }
      
      if (d > 0) return std::nullopt;
      return std::make_optional(tools::stern_brocot_tree<T>::decode_path(ancestor_path));
    }

    static std::tuple<T, T, T, T> range(const T p, const T q) {
      return tools::stern_brocot_tree<T>::encode_path_impl<false>(p, q);
    }
  };
}

#endif
