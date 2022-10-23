#ifndef TOOLS_ZERO_ONE_KNAPSACK_HPP
#define TOOLS_ZERO_ONE_KNAPSACK_HPP

#include <vector>
#include <utility>
#include <cassert>
#include <cstddef>
#include <limits>
#include <iterator>
#include <algorithm>
#include <tuple>
#include <array>
#include <numeric>
#include "tools/chmax.hpp"
#include "tools/chmin.hpp"
#include "tools/less_by_get.hpp"
#include "tools/safe_int.hpp"
#include "tools/ceil.hpp"
#include "tools/pow2.hpp"

namespace tools {
  template <typename T>
  class zero_one_knapsack {
  private:
    T m_W;
    ::std::vector<::std::pair<T, T>> m_items;

  public:
    zero_one_knapsack() = default;
    zero_one_knapsack(const ::tools::zero_one_knapsack<T>&) = default;
    zero_one_knapsack(::tools::zero_one_knapsack<T>&&) = default;
    ~zero_one_knapsack() = default;
    ::tools::zero_one_knapsack<T>& operator=(const ::tools::zero_one_knapsack<T>&) = default;
    ::tools::zero_one_knapsack<T>& operator=(::tools::zero_one_knapsack<T>&&) = default;

    explicit zero_one_knapsack(const T W) : m_W(W) {
      assert(W >= 0);
    }

    ::std::size_t size() const {
      return this->m_items.size();
    }

    T capacity() const {
      return this->m_W;
    }

    ::std::size_t add_item(const T v, const T w) {
      assert(v >= 0);
      assert(w >= 0);
      this->m_items.emplace_back(v, w);
      return this->m_items.size() - 1;
    }

    ::std::pair<T, T> get_item(const ::std::size_t k) const {
      assert(k < this->m_items.size());
      return this->m_items[k];
    }

    const ::std::vector<::std::pair<T, T>>& items() const {
      return this->m_items;
    }

  private:
    ::std::pair<T, ::std::vector<::std::size_t>> solve_by_dp_maximizing_value() const {
      auto dp = ::std::vector(this->size() + 1, ::std::vector(this->m_W + 1, ::std::numeric_limits<T>::min()));
      dp[0][0] = 0;
      for (::std::size_t i = 1; i <= this->size(); ++i) {
        const auto [v, w] = this->m_items[i - 1];
        for (T j = 0; j <= this->m_W; ++j) {
          dp[i][j] = dp[i - 1][j];
          if (j >= w && dp[i - 1][j - w] >= 0) {
            ::tools::chmax(dp[i][j], dp[i - 1][j - w] + v);
          }
        }
      }

      ::std::pair<T, ::std::vector<::std::size_t>> res;
      auto& [answer, selected] = res;
      T left = ::std::distance(dp[this->size()].begin(), ::std::max_element(dp[this->size()].begin(), dp[this->size()].end()));
      answer = dp[this->size()][left];
      for (::std::size_t i = this->size(); i --> 0;) {
        const auto [v, w] = this->m_items[i];
        if (dp[i + 1][left] != dp[i][left]) {
          assert(left >= w);
          assert(dp[i + 1][left] == dp[i][left - w] + v);
          selected.push_back(i);
          left -= w;
        }
      }
      assert(left == 0);

      ::std::reverse(selected.begin(), selected.end());
      return res;
    }

    ::std::pair<T, ::std::vector<::std::size_t>> solve_by_dp_minimizing_weight() const {
      const auto max_V = ::std::accumulate(this->m_items.begin(), this->m_items.end(), static_cast<T>(0), [](const auto sum, const auto& item) { return sum + item.first; });
      auto dp = ::std::vector(this->size() + 1, ::std::vector(max_V + 1, ::std::numeric_limits<T>::max()));
      dp[0][0] = 0;
      for (::std::size_t i = 1; i <= this->size(); ++i) {
        const auto [v, w] = this->m_items[i - 1];
        for (T j = 0; j <= max_V; ++j) {
          dp[i][j] = dp[i - 1][j];
          if (j >= v && dp[i - 1][j - v] < ::std::numeric_limits<T>::max() && dp[i - 1][j - v] + w <= this->m_W) {
            ::tools::chmin(dp[i][j], dp[i - 1][j - v] + w);
          }
        }
      }

      ::std::pair<T, ::std::vector<::std::size_t>> res;
      auto& [answer, selected] = res;
      answer = ::std::distance(dp[this->size()].begin(), ::std::prev(::std::find_if(dp[this->size()].rbegin(), dp[this->size()].rend(), [](const auto w) { return w < ::std::numeric_limits<T>::max(); }).base()));
      T left = answer;
      for (::std::size_t i = this->size(); i --> 0;) {
        const auto [v, w] = this->m_items[i];
        if (dp[i + 1][left] != dp[i][left]) {
          assert(left >= v);
          assert(dp[i + 1][left] == dp[i][left - v] + w);
          selected.push_back(i);
          left -= v;
        }
      }
      assert(left == 0);

      ::std::reverse(selected.begin(), selected.end());
      return res;
    }

    ::std::pair<T, ::std::vector<::std::size_t>> solve_by_meet_in_the_middle() const {
      const auto f = [&](const ::std::size_t L, const ::std::size_t R) {
        ::std::vector<::std::tuple<::std::size_t, T, T>> res;
        res.emplace_back(0, 0, 0);
        for (::std::size_t i = L; i < R; ++i) {
          ::std::size_t n = res.size();
          for (::std::size_t j = 0; j < n && ::std::get<2>(res[j]) + this->m_items[i].second <= this->m_W; ++j) {
            res.emplace_back(::std::get<0>(res[j]) | (static_cast<::std::size_t>(1) << (i - L)), ::std::get<1>(res[j]) + this->m_items[i].first, ::std::get<2>(res[j]) + this->m_items[i].second);
          }
          ::std::inplace_merge(res.begin(), res.begin() + n, res.end(), ::tools::less_by_get<2>());
        }

        for (::std::size_t l = 0, r = 0; l < res.size(); l = r) {
          for (; r < res.size() && ::std::get<2>(res[l]) == ::std::get<2>(res[r]); ++r);
          ::std::iter_swap(res.begin() + l, ::std::max_element(res.begin() + l, res.begin() + r, ::tools::less_by_get<1>()));
        }

        ::std::size_t vl = 0;
        for (::std::size_t vr = 0, al = 0, ar = 0; al < res.size(); vl = vr, al = ar) {
          for (; ar < res.size() && ::std::get<1>(res[al]) >= ::std::get<1>(res[ar]); ++vr, ++ar);
          if (vl < al) ::std::move(res.begin() + al, res.begin() + ar, res.begin() + vl);
          vr = vl + 1;
        }
        res.erase(res.begin() + vl, res.end());

        return res;
      };

      const auto first_half = f(0, this->size() / 2);
      const auto second_half = f(this->size() / 2, this->size());

      ::std::pair<T, ::std::vector<::std::size_t>> res;
      auto& [answer, selected] = res;
      answer = ::std::numeric_limits<T>::min();
      ::std::pair<::std::size_t, ::std::size_t> selected_as_bitset;
      ::std::size_t r = second_half.size();
      for (const auto [state, v, w] : first_half) {
        for (; w + ::std::get<2>(second_half[r - 1]) > this->m_W; --r);
        if (::tools::chmax(answer, v + ::std::get<1>(second_half[r - 1]))) {
          selected_as_bitset = ::std::make_pair(state, ::std::get<0>(second_half[r - 1]));
        }
      }

      for (::std::size_t i = 0; i < this->size() / 2; ++i) {
        if (selected_as_bitset.first & (static_cast<::std::size_t>(1) << i)) {
          selected.push_back(i);
        }
      }
      for (::std::size_t i = this->size() / 2; i < this->size(); ++i) {
        if (selected_as_bitset.second & (static_cast<::std::size_t>(1) << (i - this->size() / 2))) {
          selected.push_back(i);
        }
      }

      return res;
    }

  public:
    ::std::pair<T, ::std::vector<::std::size_t>> query() const {
      using S = ::tools::safe_int<long long>;
      ::std::array<S, 3> complexities = {
        S(this->size()) * S(this->m_W),
        S(this->size()) * ::std::accumulate(this->m_items.begin(), this->m_items.end(), S(0), [](const auto sum, const auto& item) { return sum + S(item.first); }),
        ::tools::ceil(this->size(), 2) < ::std::numeric_limits<long long>::digits ? S(::tools::pow2<long long>(::tools::ceil(this->size(), 2))) : S::nan(),
      };
      for (auto& complexity : complexities) {
        if (complexity.is_nan()) complexity = S::infinity();
      }
      const auto min_complexity = *::std::min_element(complexities.begin(), complexities.end());
      if (complexities[0] == min_complexity) {
        return this->solve_by_dp_maximizing_value();
      } else if (complexities[1] == min_complexity) {
        return this->solve_by_dp_minimizing_weight();
      } else {
        return this->solve_by_meet_in_the_middle();
      }
    }
  };
}

#endif
