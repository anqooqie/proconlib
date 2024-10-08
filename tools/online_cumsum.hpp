#ifndef TOOLS_ONLINE_CUMSUM_HPP
#define TOOLS_ONLINE_CUMSUM_HPP

#include <type_traits>
#include <vector>
#include <cstddef>
#include <cassert>
#include "tools/is_monoid.hpp"
#include "tools/group.hpp"
#include "tools/is_group.hpp"

namespace tools {
  template <typename X, bool Forward = true>
  class online_cumsum {
    using M = ::std::conditional_t<::tools::is_monoid_v<X>, X, ::tools::group::plus<X>>;
    using T = typename M::T;
    ::std::vector<T> m_vector;
    ::std::vector<T> m_cumsum;
    ::std::size_t m_processed;

  public:
    online_cumsum() : online_cumsum(0) {
    }
    online_cumsum(const ::std::size_t n) : m_vector(n, M::e()), m_cumsum(n + 1, M::e()), m_processed(Forward ? 0 : n) {
    }

    ::std::size_t size() const {
      return this->m_vector.size();
    }
    T& operator[](const ::std::size_t i) {
      assert(i < this->size());
      return this->m_vector[i];
    }

    auto begin() { return this->m_vector.begin(); }
    auto begin() const { return this->m_vector.begin(); }
    auto cbegin() const { return this->m_vector.cbegin(); }
    auto end() { return this->m_vector.end(); }
    auto end() const { return this->m_vector.end(); }
    auto cend() const { return this->m_vector.cend(); }
    auto rbegin() { return this->m_vector.rbegin(); }
    auto rbegin() const { return this->m_vector.rbegin(); }
    auto crbegin() const { return this->m_vector.crbegin(); }
    auto rend() { return this->m_vector.rend(); }
    auto rend() const { return this->m_vector.rend(); }
    auto crend() const { return this->m_vector.crend(); }

    T prod(const ::std::size_t l, const ::std::size_t r) {
      assert(l <= r && r <= this->size());
      if constexpr (Forward) {
        for (; this->m_processed < r; ++this->m_processed) {
          this->m_cumsum[this->m_processed + 1] = M::op(this->m_cumsum[this->m_processed], this->m_vector[this->m_processed]);
        }
        if constexpr (::tools::is_group_v<M>) {
          return M::op(M::inv(this->m_cumsum[l]), this->m_cumsum[r]);
        } else {
          assert(l == 0);
          return this->m_cumsum[r];
        }
      } else {
        for (; this->m_processed > l; --this->m_processed) {
          this->m_cumsum[this->m_processed - 1] = M::op(this->m_vector[this->m_processed - 1], this->m_cumsum[this->m_processed]);
        }
        if constexpr (::tools::is_group_v<M>) {
          return M::op(this->m_cumsum[l], M::inv(this->m_cumsum[r]));
        } else {
          assert(r == this->size());
          return this->m_cumsum[l];
        }
      }
    }
    template <typename Y = X>
    ::std::enable_if_t<!::tools::is_monoid_v<Y>, T> sum(const ::std::size_t l, const ::std::size_t r) {
      return this->prod(l, r);
    }
  };
}

#endif
