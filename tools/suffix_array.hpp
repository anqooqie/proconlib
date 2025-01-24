#ifndef TOOLS_SUFFIX_ARRAY_HPP
#define TOOLS_SUFFIX_ARRAY_HPP

#include <vector>
#include <utility>
#include <type_traits>
#include <string>
#include <cstddef>
#include <limits>
#include <algorithm>
#include <iterator>
#include <initializer_list>
#include "atcoder/string.hpp"
#include "tools/chmin.hpp"
#include "tools/chmax.hpp"

namespace tools {

  class suffix_array {
  public:
    ::std::vector<::std::pair<int, int>> sa;
    ::std::vector<int> lcpa;

    suffix_array() = default;
    template <typename InputIterator>
    suffix_array(const InputIterator begin, const InputIterator end) {
      using Container = ::std::decay_t<decltype(*::std::declval<InputIterator>())>;
      static_assert(
        ::std::is_same_v<Container, ::std::string> ||
        ::std::is_same_v<Container, ::std::vector<int>> ||
        ::std::is_same_v<Container, ::std::vector<unsigned int>> ||
        ::std::is_same_v<Container, ::std::vector<long long>> ||
        ::std::is_same_v<Container, ::std::vector<unsigned long long>>
      );

      if (begin == end) return;

      ::std::vector<Container> orig(begin, end);

      ::std::vector<::std::size_t> offsets(orig.size());
      offsets[0] = 0;
      for (::std::size_t i = 1; i < orig.size(); ++i) {
        offsets[i] = offsets[i - 1] + orig[i - 1].size() + 1;
      }

      ::std::vector<int> concat;
      concat.reserve(offsets.back() + orig.back().size() + 1);
      int upper;
      if constexpr (::std::is_same_v<Container, ::std::string>) {
        int lower = ::std::numeric_limits<int>::max();
        upper = ::std::numeric_limits<int>::min();
        for (const auto& s : orig) {
          for (const auto s_i : s) {
            ::tools::chmin(lower, s_i);
            ::tools::chmax(upper, s_i);
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
          ::std::copy(s.begin(), s.end(), ::std::back_inserter(compress));
        }
        ::std::sort(compress.begin(), compress.end());
        compress.erase(::std::unique(compress.begin(), compress.end()), compress.end());

        for (const auto& s : orig) {
          for (const auto s_i : s) {
            concat.push_back(::std::distance(compress.begin(), ::std::lower_bound(compress.begin(), compress.end(), s_i)) + 1);
          }
          concat.push_back(0);
        }

        upper = compress.size();
      }

      ::std::vector<::std::size_t> belongs;
      belongs.reserve(concat.size());
      for (::std::size_t i = 0; i < orig.size(); ++i) {
        for (::std::size_t j = 0; j <= orig[i].size(); ++j) {
          belongs.push_back(i);
        }
      }

      const auto concat_sa = ::atcoder::suffix_array(concat, upper);
      this->lcpa = ::atcoder::lcp_array(concat, concat_sa);
      this->sa.reserve(concat_sa.size());
      for (const auto ij : concat_sa) {
        const int i = belongs[ij];
        const int j = ij - offsets[i];
        this->sa.emplace_back(i, j);
      }

      for (::std::size_t i = 0; i < this->lcpa.size(); ++i) {
        ::tools::chmin(this->lcpa[i], orig[this->sa[i].first].size() - this->sa[i].second);
        ::tools::chmin(this->lcpa[i], orig[this->sa[i + 1].first].size() - this->sa[i + 1].second);
      }

      this->erase_if([&](const int i, const int j) {
        return ::std::cmp_equal(j, orig[i].size());
      });
    }
    template <typename Container>
    suffix_array(const ::std::initializer_list<Container> il) : suffix_array(il.begin(), il.end()) {
    }

    template <typename Predicate>
    ::std::size_t erase_if(const Predicate pred) {
      if (this->sa.empty()) return 0;

      const auto N = this->sa.size();
      ::std::size_t erased = 0;

      ::std::size_t sa_vl = 0, lcpa_vl = 0;
      for (::std::size_t sa_vr = 0, sa_al = 0, sa_ar = 0, lcpa_vr = 0; sa_al < N; sa_vl = sa_vr, sa_al = sa_ar, lcpa_vl = lcpa_vr) {
        const bool removes = pred(this->sa[sa_al].first, this->sa[sa_al].second);

        for (; sa_ar < N && removes == pred(this->sa[sa_ar].first, this->sa[sa_ar].second); ++sa_vr, ++sa_ar);
        if (sa_vl < sa_al) ::std::move(this->sa.begin() + sa_al, this->sa.begin() + sa_ar, this->sa.begin() + sa_vl);

        const auto lcpa_al = sa_al == 0 ? 0 : sa_al - removes;
        const auto lcpa_ar = ::std::min(sa_ar - !removes, N - 1);
        lcpa_vr = lcpa_vl + (lcpa_ar - lcpa_al);
        if (lcpa_vl < lcpa_al) ::std::move(this->lcpa.begin() + lcpa_al, this->lcpa.begin() + lcpa_ar, this->lcpa.begin() + lcpa_vl);

        if (removes) {
          erased += sa_vr - sa_vl;
          sa_vr = sa_vl;
          if (0 < sa_al && sa_ar < N) {
            this->lcpa[lcpa_vl] = *::std::min_element(this->lcpa.begin() + lcpa_vl, this->lcpa.begin() + lcpa_vr);
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
