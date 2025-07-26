#ifndef TOOLS_MO_HPP
#define TOOLS_MO_HPP

#include <algorithm>
#include <cassert>
#include <cmath>
#include <concepts>
#include <iterator>
#include <numeric>
#include <ranges>
#include <utility>
#include <vector>

namespace tools {
  class mo {
    ::std::vector<::std::pair<int, int>> m_queries;

    bool queries_are_intervals() const {
      return ::std::ranges::all_of(this->m_queries, [](const auto& query) { return query.first <= query.second; });
    }

  public:
    mo() = default;

    int add_query(const int l, const int r) {
      assert(l >= 0);
      assert(r >= 0);
      this->m_queries.emplace_back(l, r);
      return this->m_queries.size() - 1;
    }

    const ::std::pair<int, int>& get_query(const int q) const & {
      assert(0 <= q && q < ::std::ssize(this->m_queries));
      return this->m_queries[q];
    }
    ::std::pair<int, int> get_query(const int q) && {
      assert(0 <= q && q < ::std::ssize(this->m_queries));
      return ::std::move(this->m_queries[q]);
    }

    const ::std::vector<::std::pair<int, int>>& queries() const & {
      return this->m_queries;
    }
    ::std::vector<::std::pair<int, int>> queries() && {
      return ::std::move(this->m_queries);
    }

    template <typename D, typename A, typename F>
    requires (::std::invocable<D, int> && ::std::invocable<A, int> && ::std::invocable<F, int>)
    void run(const D& del, const A& add, const F& run_query) {
      assert(this->queries_are_intervals());
      this->run(add, del, del, add, run_query);
    }

    template <typename DL, typename IL, typename DR, typename IR, typename F>
    requires (::std::invocable<DL, int> && ::std::invocable<IL, int> && ::std::invocable<DR, int> && ::std::invocable<IR, int> && ::std::invocable<F, int>)
    void run(const DL& decrement_l, const IL& increment_l, const DR& decrement_r, const IR& increment_r, const F& run_query) {
      const int M = this->m_queries.empty() ? 0 : ::std::ranges::max(this->m_queries | ::std::views::transform(&::std::pair<int, int>::first));
      const int N = this->m_queries.empty() ? 0 : ::std::ranges::max(this->m_queries | ::std::views::transform(&::std::pair<int, int>::second));
      const int Q = this->m_queries.size();
      const int B = ::std::max<int>(1, ::std::round((this->queries_are_intervals() ? ::std::sqrt(M * (2.0 * N - M)) : ::std::sqrt(2.0 * M * N)) / ::std::sqrt(std::max(1, Q))));

      ::std::vector<int> ordered_queries1(Q);
      ::std::iota(ordered_queries1.begin(), ordered_queries1.end(), 0);
      ::std::ranges::sort(ordered_queries1, [&](const int q1, const int q2) {
        const auto& [l1, r1] = this->m_queries[q1];
        const auto& [l2, r2] = this->m_queries[q2];
        const auto bucket1 = l1 / B;
        const auto bucket2 = l2 / B;
        if (bucket1 != bucket2) return bucket1 < bucket2;
        if (bucket1 % 2 == 0) return r1 < r2;
        return r1 > r2;
      });
      long long dist1 = 0;
      for (int i = 0; i + 1 < Q; ++i) {
        dist1 += ::std::abs(this->m_queries[ordered_queries1[i]].first - this->m_queries[ordered_queries1[i + 1]].first);
        dist1 += ::std::abs(this->m_queries[ordered_queries1[i]].second - this->m_queries[ordered_queries1[i + 1]].second);
      }

      ::std::vector<int> ordered_queries2(Q);
      ::std::iota(ordered_queries2.begin(), ordered_queries2.end(), 0);
      ::std::ranges::sort(ordered_queries2, [&](const int q1, const int q2) {
        const auto& [l1, r1] = this->m_queries[q1];
        const auto& [l2, r2] = this->m_queries[q2];
        const auto bucket1 = (l1 + B / 2) / B;
        const auto bucket2 = (l2 + B / 2) / B;
        if (bucket1 != bucket2) return bucket1 < bucket2;
        if (bucket1 % 2 == 0) return r1 < r2;
        return r1 > r2;
      });
      long long dist2 = 0;
      for (int i = 0; i + 1 < Q; ++i) {
        dist2 += ::std::abs(this->m_queries[ordered_queries2[i]].first - this->m_queries[ordered_queries2[i + 1]].first);
        dist2 += ::std::abs(this->m_queries[ordered_queries2[i]].second - this->m_queries[ordered_queries2[i + 1]].second);
      }

      int l = 0;
      int r = 0;
      for (const auto q : (dist1 < dist2 ? ordered_queries1 : ordered_queries2)) {
        const auto& [ql, qr] = this->m_queries[q];
        for (; ql < l; --l) decrement_l(l - 1);
        for (; r < qr; ++r) increment_r(r);
        for (; l < ql; ++l) increment_l(l);
        for (; qr < r; --r) decrement_r(r - 1);
        run_query(q);
      }
    }
  };
}

#endif
