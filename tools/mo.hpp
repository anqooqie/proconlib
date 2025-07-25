#ifndef TOOLS_MO_HPP
#define TOOLS_MO_HPP

#include <algorithm>
#include <cassert>
#include <cmath>
#include <concepts>
#include <iterator>
#include <tuple>
#include <vector>

namespace tools {
  template <bool IsRange = true>
  class mo {
    int m_bucket_size;
    ::std::vector<::std::tuple<int, int, int>> m_queries;

  public:
    mo() = default;
    template <bool SFINAE = IsRange> requires (SFINAE)
    mo(const int n, const int q) : m_bucket_size(::std::max<int>(1, ::std::round(n / ::std::sqrt(std::max(1, q))))) {
      this->m_queries.reserve(q);
    }
    template <bool SFINAE = !IsRange> requires (SFINAE)
    mo(const int m, const int n, const int q) : m_bucket_size(::std::max<int>(1, ::std::round(::std::sqrt(2.0 * m * n) / ::std::sqrt(std::max(1, q))))) {
      this->m_queries.reserve(q);
    }

    void add_query(const int l, const int r) {
      if constexpr (IsRange) {
        assert(0 <= l && l <= r);
      } else {
        assert(0 <= l);
        assert(0 <= r);
      }
      this->m_queries.emplace_back(this->m_queries.size(), l, r);
    }

    template <typename D, typename A, typename F, bool SFINAE = IsRange>
    requires (::std::invocable<D, int> && ::std::invocable<A, int> && ::std::invocable<F, int> && SFINAE)
    void run(const D& del, const A& add, const F& run_query) {
      this->run(add, del, del, add, run_query);
    }

    template <typename DL, typename IL, typename DR, typename IR, typename F>
    requires (::std::invocable<DL, int> && ::std::invocable<IL, int> && ::std::invocable<DR, int> && ::std::invocable<IR, int> && ::std::invocable<F, int>)
    void run(const DL& decrement_l, const IL& increment_l, const DR& decrement_r, const IR& increment_r, const F& run_query) {
      const auto comp1 = [&](const auto& a, const auto& b) {
        const auto bucket_a = ::std::get<1>(a) / this->m_bucket_size;
        const auto bucket_b = ::std::get<1>(b) / this->m_bucket_size;
        if (bucket_a != bucket_b) return bucket_a < bucket_b;
        if (bucket_a % 2 == 0) return ::std::get<2>(a) < ::std::get<2>(b);
        return ::std::get<2>(a) > ::std::get<2>(b);
      };
      const auto comp2 = [&](const auto& a, const auto& b) {
        const auto bucket_a = (::std::get<1>(a) + this->m_bucket_size / 2) / this->m_bucket_size;
        const auto bucket_b = (::std::get<1>(b) + this->m_bucket_size / 2) / this->m_bucket_size;
        if (bucket_a != bucket_b) return bucket_a < bucket_b;
        if (bucket_a % 2 == 0) return ::std::get<2>(a) < ::std::get<2>(b);
        return ::std::get<2>(a) > ::std::get<2>(b);
      };

      ::std::ranges::sort(this->m_queries, comp1);
      long long dist1 = 0;
      for (int q = 0; q + 1 < ::std::ssize(this->m_queries); ++q) {
        dist1 += ::std::abs(::std::get<1>(this->m_queries[q]) - ::std::get<1>(this->m_queries[q + 1]));
        dist1 += ::std::abs(::std::get<2>(this->m_queries[q]) - ::std::get<2>(this->m_queries[q + 1]));
      }

      ::std::ranges::sort(this->m_queries, comp2);
      long long dist2 = 0;
      for (int q = 0; q + 1 < ::std::ssize(this->m_queries); ++q) {
        dist2 += ::std::abs(::std::get<1>(this->m_queries[q]) - ::std::get<1>(this->m_queries[q + 1]));
        dist2 += ::std::abs(::std::get<2>(this->m_queries[q]) - ::std::get<2>(this->m_queries[q + 1]));
      }

      if (dist1 < dist2) {
        ::std::ranges::sort(this->m_queries, comp1);
      }

      int l = 0;
      int r = 0;
      for (const auto& [q, ql, qr] : this->m_queries) {
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
