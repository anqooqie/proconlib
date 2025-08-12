#ifndef TOOLS_ZERO_ONE_KNAPSACK_HPP
#define TOOLS_ZERO_ONE_KNAPSACK_HPP

#include <algorithm>
#include <array>
#include <cassert>
#include <iterator>
#include <limits>
#include <numeric>
#include <tuple>
#include <type_traits>
#include <utility>
#include <vector>
#include "tools/ceil.hpp"
#include "tools/chmax.hpp"
#include "tools/chmin.hpp"
#include "tools/less_by_get.hpp"
#include "tools/pow2.hpp"
#include "tools/safe_int.hpp"

namespace tools {
  template <typename T>
  class zero_one_knapsack {
    T m_W;
    ::std::vector<::std::pair<T, T>> m_items;

  public:
    zero_one_knapsack() = default;
    explicit zero_one_knapsack(const T W) : m_W(W) {
      assert(W >= 0);
    }

    int size() const {
      return this->m_items.size();
    }

    T capacity() const {
      return this->m_W;
    }

    int add_item(const T v, const T w) {
      assert(v >= 0);
      assert(w >= 0);
      this->m_items.emplace_back(v, w);
      return this->m_items.size() - 1;
    }

    const ::std::pair<T, T>& get_item(const int k) const & {
      assert(0 <= k && k < ::std::ssize(this->m_items));
      return this->m_items[k];
    }
    ::std::pair<T, T> get_item(const int k) && {
      assert(0 <= k && k < ::std::ssize(this->m_items));
      return ::std::move(this->m_items[k]);
    }

    const ::std::vector<::std::pair<T, T>>& items() const & {
      return this->m_items;
    }
    ::std::vector<::std::pair<T, T>> items() && {
      return ::std::move(this->m_items);
    }

  private:
    template <bool Restore>
    ::std::conditional_t<Restore, ::std::pair<T, ::std::vector<int>>, T> solve_by_dp_maximizing_value() const {
      auto dp = ::std::vector(this->size() + 1, ::std::vector(this->m_W + 1, ::std::numeric_limits<T>::min()));
      dp[0][0] = 0;
      for (int i = 1; i <= this->size(); ++i) {
        const auto [v, w] = this->m_items[i - 1];
        for (T j = 0; j <= this->m_W; ++j) {
          dp[i][j] = dp[i - 1][j];
          if (j >= w && dp[i - 1][j - w] >= 0) {
            ::tools::chmax(dp[i][j], dp[i - 1][j - w] + v);
          }
        }
      }

      T left = ::std::distance(dp[this->size()].begin(), ::std::max_element(dp[this->size()].begin(), dp[this->size()].end()));
      T answer = dp[this->size()][left];

      if constexpr (Restore) {
        ::std::vector<int> selected;
        for (int i = this->size(); i --> 0;) {
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

        return ::std::make_pair(answer, selected);
      } else {
        return answer;
      }
    }

    template <bool Restore>
    ::std::conditional_t<Restore, ::std::pair<T, ::std::vector<int>>, T> solve_by_dp_minimizing_weight() const {
      const auto max_V = ::std::accumulate(this->m_items.begin(), this->m_items.end(), static_cast<T>(0), [](const auto sum, const auto& item) { return sum + item.first; });
      auto dp = ::std::vector(this->size() + 1, ::std::vector(max_V + 1, ::std::numeric_limits<T>::max()));
      dp[0][0] = 0;
      for (int i = 1; i <= this->size(); ++i) {
        const auto [v, w] = this->m_items[i - 1];
        for (T j = 0; j <= max_V; ++j) {
          dp[i][j] = dp[i - 1][j];
          if (j >= v && dp[i - 1][j - v] < ::std::numeric_limits<T>::max() && dp[i - 1][j - v] + w <= this->m_W) {
            ::tools::chmin(dp[i][j], dp[i - 1][j - v] + w);
          }
        }
      }

      T answer = ::std::distance(dp[this->size()].begin(), ::std::prev(::std::find_if(dp[this->size()].rbegin(), dp[this->size()].rend(), [](const auto w) { return w < ::std::numeric_limits<T>::max(); }).base()));
      if constexpr (Restore) {
        ::std::vector<int> selected;
        T left = answer;
        for (int i = this->size(); i --> 0;) {
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

        return ::std::make_pair(answer, selected);
      } else {
        return answer;
      }
    }

    template <bool Restore>
    ::std::conditional_t<Restore, ::std::pair<T, ::std::vector<int>>, T> solve_by_meet_in_the_middle() const {
      const auto f = [&](const int L, const int R) {
        ::std::vector<::std::tuple<int, T, T>> res;
        res.emplace_back(0, 0, 0);
        for (int i = L; i < R; ++i) {
          int n = res.size();
          for (int j = 0; j < n && ::std::get<2>(res[j]) + this->m_items[i].second <= this->m_W; ++j) {
            res.emplace_back(::std::get<0>(res[j]) | (static_cast<int>(1) << (i - L)), ::std::get<1>(res[j]) + this->m_items[i].first, ::std::get<2>(res[j]) + this->m_items[i].second);
          }
          ::std::inplace_merge(res.begin(), res.begin() + n, res.end(), ::tools::less_by_get<2>{});
        }

        for (int l = 0, r = 0; l < ::std::ssize(res); l = r) {
          for (; r < ::std::ssize(res) && ::std::get<2>(res[l]) == ::std::get<2>(res[r]); ++r);
          ::std::iter_swap(res.begin() + l, ::std::max_element(res.begin() + l, res.begin() + r, ::tools::less_by_get<1>{}));
        }

        int vl = 0;
        for (int vr = 0, al = 0, ar = 0; al < ::std::ssize(res); vl = vr, al = ar) {
          for (; ar < ::std::ssize(res) && ::std::get<1>(res[al]) >= ::std::get<1>(res[ar]); ++vr, ++ar);
          if (vl < al) ::std::move(res.begin() + al, res.begin() + ar, res.begin() + vl);
          vr = vl + 1;
        }
        res.erase(res.begin() + vl, res.end());

        return res;
      };

      const auto first_half = f(0, this->size() / 2);
      const auto second_half = f(this->size() / 2, this->size());

      T answer = ::std::numeric_limits<T>::min();
      ::std::pair<int, int> selected_as_bitset;
      int r = second_half.size();
      for (const auto& [state, v, w] : first_half) {
        for (; w + ::std::get<2>(second_half[r - 1]) > this->m_W; --r);
        if (::tools::chmax(answer, v + ::std::get<1>(second_half[r - 1]))) {
          if constexpr (Restore) {
            selected_as_bitset = ::std::make_pair(state, ::std::get<0>(second_half[r - 1]));
          }
        }
      }

      if constexpr (Restore) {
        ::std::vector<int> selected;
        for (int i = 0; i < this->size() / 2; ++i) {
          if (selected_as_bitset.first & (1 << i)) {
            selected.push_back(i);
          }
        }
        for (int i = this->size() / 2; i < this->size(); ++i) {
          if (selected_as_bitset.second & (1 << (i - this->size() / 2))) {
            selected.push_back(i);
          }
        }

        return ::std::make_pair(answer, selected);
      } else {
        return answer;
      }
    }

  public:
    template <bool Restore = false>
    ::std::conditional_t<Restore, ::std::pair<T, ::std::vector<int>>, T> query() const {
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
        return this->solve_by_dp_maximizing_value<Restore>();
      } else if (complexities[1] == min_complexity) {
        return this->solve_by_dp_minimizing_weight<Restore>();
      } else {
        return this->solve_by_meet_in_the_middle<Restore>();
      }
    }
  };
}

#endif
