#ifndef TOOLS_MO_HPP
#define TOOLS_MO_HPP

#include <cstddef>
#include <vector>
#include <tuple>
#include <algorithm>
#include <cassert>
#include "tools/floor_sqrt.hpp"
#include "tools/ceil.hpp"
#include "tools/less_by_get.hpp"
#include "tools/greater_by_get.hpp"

namespace tools {
  class mo {
  private:
    ::std::size_t m_query_count;
    ::std::size_t m_bucket_size;
    ::std::vector<::std::vector<::std::tuple<::std::size_t, ::std::size_t, ::std::size_t>>> m_buckets;

  public:
    mo() = default;
    mo(const ::tools::mo&) = default;
    mo(::tools::mo&&) = default;
    ~mo() = default;
    ::tools::mo& operator=(const ::tools::mo&) = default;
    ::tools::mo& operator=(::tools::mo&&) = default;

    mo(const ::std::size_t n, const ::std::size_t q) :
      m_query_count(0),
      m_bucket_size(::std::clamp<::std::size_t>(::tools::floor_sqrt(3 * (n + 1) * (n + 1) / (2 * (q + 1))), 1, n + 1)),
      m_buckets(::tools::ceil(n + 1, this->m_bucket_size)) {
    }

    void add_query(const ::std::size_t l, const ::std::size_t r) {
      assert(l <= r);
      this->m_buckets[l / this->m_bucket_size].emplace_back(this->m_query_count, l, r);
      ++this->m_query_count;
    }

    template <typename AL, typename AR, typename DL, typename DR, typename F>
    void run(const AL& add_left, const AR& add_right, const DL& delete_left, const DR& delete_right, const F& run_query) {
      ::std::size_t l = 0;
      ::std::size_t r = 0;
      for (::std::size_t i = 0; i < this->m_buckets.size(); ++i) {
        if (i % 2 == 0) {
          ::std::sort(this->m_buckets[i].begin(), this->m_buckets[i].end(), ::tools::less_by_get<2>());
        } else {
          ::std::sort(this->m_buckets[i].begin(), this->m_buckets[i].end(), ::tools::greater_by_get<2>());
        }
        for (const auto& [qi, ql, qr] : this->m_buckets[i]) {
          for (; ql < l; --l) add_left(l - 1);
          for (; r < qr; ++r) add_right(r);
          for (; l < ql; ++l) delete_left(l);
          for (; qr < r; --r) delete_right(r - 1);
          run_query(qi);
        }
      }
    }
  };
}

#endif
