#ifndef TOOLS_SUFFIX_ARRAY_HPP
#define TOOLS_SUFFIX_ARRAY_HPP

#include <algorithm>
#include <concepts>
#include <functional>
#include <initializer_list>
#include <iterator>
#include <limits>
#include <ranges>
#include <string>
#include <type_traits>
#include <utility>
#include <vector>
#include "atcoder/string.hpp"
#include "tools/chmin.hpp"
#include "tools/chmax.hpp"

namespace tools {
  class suffix_array {
  public:
    std::vector<std::pair<int, int>> sa;
    std::vector<int> lcpa;

    suffix_array() = default;
    template <std::ranges::input_range R>
    requires std::ranges::input_range<std::ranges::range_value_t<R>>
    && (
      std::same_as<std::ranges::range_value_t<std::ranges::range_value_t<R>>, char>
      || std::same_as<std::ranges::range_value_t<std::ranges::range_value_t<R>>, int>
      || std::same_as<std::ranges::range_value_t<std::ranges::range_value_t<R>>, unsigned int>
      || std::same_as<std::ranges::range_value_t<std::ranges::range_value_t<R>>, long long>
      || std::same_as<std::ranges::range_value_t<std::ranges::range_value_t<R>>, unsigned long long>
    )
    suffix_array(R&& r) {
      using Container = std::conditional_t<
        std::same_as<std::ranges::range_value_t<std::ranges::range_value_t<R>>, char>,
          std::string,
          std::vector<std::ranges::range_value_t<std::ranges::range_value_t<R>>>
      >;

      if (std::ranges::empty(r)) return;

      std::vector<Container> orig;
      for (auto&& r_i : r) {
        orig.push_back(std::forward<decltype(r_i)>(r_i) | std::ranges::to<Container>());
      }

      std::vector<int> offsets(orig.size());
      offsets[0] = 0;
      for (int i = 1; i < std::ssize(orig); ++i) {
        offsets[i] = offsets[i - 1] + orig[i - 1].size() + 1;
      }

      std::vector<int> concat;
      concat.reserve(offsets.back() + orig.back().size() + 1);
      int upper;
      if constexpr (std::same_as<Container, std::string>) {
        int lower = std::numeric_limits<int>::max();
        upper = std::numeric_limits<int>::min();
        for (const auto& s : orig) {
          for (const auto s_i : s) {
            tools::chmin(lower, s_i);
            tools::chmax(upper, s_i);
          }
        }

        for (const auto& s : orig) {
          for (const auto s_i : s) {
            concat.push_back(s_i + (lower == 0));
          }
          concat.push_back(0);
        }
        if (lower == 0) ++upper;
      } else {
        Container compress;
        compress.reserve(concat.size() - orig.size());
        for (const auto& s : orig) {
          std::ranges::copy(s, std::back_inserter(compress));
        }
        std::ranges::sort(compress);
        compress.erase(std::unique(compress.begin(), compress.end()), compress.end());

        for (const auto& s : orig) {
          for (const auto s_i : s) {
            concat.push_back(std::distance(compress.begin(), std::ranges::lower_bound(compress, s_i)) + 1);
          }
          concat.push_back(0);
        }

        upper = compress.size();
      }

      std::vector<int> belongs;
      belongs.reserve(concat.size());
      for (int i = 0; i < std::ssize(orig); ++i) {
        for (int j = 0; j <= std::ssize(orig[i]); ++j) {
          belongs.push_back(i);
        }
      }

      const auto concat_sa = atcoder::suffix_array(concat, upper);
      this->lcpa = atcoder::lcp_array(concat, concat_sa);
      this->sa.reserve(concat_sa.size());
      for (const auto ij : concat_sa) {
        const int i = belongs[ij];
        const int j = ij - offsets[i];
        this->sa.emplace_back(i, j);
      }

      for (int i = 0; i < std::ssize(this->lcpa); ++i) {
        tools::chmin(this->lcpa[i], orig[this->sa[i].first].size() - this->sa[i].second);
        tools::chmin(this->lcpa[i], orig[this->sa[i + 1].first].size() - this->sa[i + 1].second);
      }

      this->erase_if([&](const int i, const int j) {
        return j == std::ssize(orig[i]);
      });
    }
    template <std::ranges::input_range Container>
    requires std::same_as<std::ranges::range_value_t<Container>, char>
          || std::same_as<std::ranges::range_value_t<Container>, int>
          || std::same_as<std::ranges::range_value_t<Container>, unsigned int>
          || std::same_as<std::ranges::range_value_t<Container>, long long>
          || std::same_as<std::ranges::range_value_t<Container>, unsigned long long>
    suffix_array(std::initializer_list<Container> il) : suffix_array(std::views::all(il)) {
    }

    int erase_if(std::predicate<int, int> auto&& pred) {
      if (this->sa.empty()) return 0;

      const int N = this->sa.size();
      int erased = 0;

      int sa_vl = 0, lcpa_vl = 0;
      for (int sa_vr = 0, sa_al = 0, sa_ar = 0, lcpa_vr = 0; sa_al < N; sa_vl = sa_vr, sa_al = sa_ar, lcpa_vl = lcpa_vr) {
        const bool removes = std::invoke(pred, this->sa[sa_al].first, this->sa[sa_al].second);

        for (; sa_ar < N && removes == std::invoke(pred, this->sa[sa_ar].first, this->sa[sa_ar].second); ++sa_vr, ++sa_ar);
        if (sa_vl < sa_al) std::move(this->sa.begin() + sa_al, this->sa.begin() + sa_ar, this->sa.begin() + sa_vl);

        const auto lcpa_al = sa_al == 0 ? 0 : sa_al - removes;
        const auto lcpa_ar = std::min(sa_ar - !removes, N - 1);
        lcpa_vr = lcpa_vl + (lcpa_ar - lcpa_al);
        if (lcpa_vl < lcpa_al) std::move(this->lcpa.begin() + lcpa_al, this->lcpa.begin() + lcpa_ar, this->lcpa.begin() + lcpa_vl);

        if (removes) {
          erased += sa_vr - sa_vl;
          sa_vr = sa_vl;
          if (0 < sa_al && sa_ar < N) {
            this->lcpa[lcpa_vl] = *std::min_element(this->lcpa.begin() + lcpa_vl, this->lcpa.begin() + lcpa_vr);
            lcpa_vr = lcpa_vl + 1;
          } else {
            lcpa_vr = lcpa_vl;
          }
        }
      }

      this->sa.erase(this->sa.begin() + sa_vl, this->sa.end());
      this->lcpa.erase(this->lcpa.begin() + lcpa_vl, this->lcpa.end());

      return erased;
    }
  };
}

#endif
